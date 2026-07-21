#include "orion_common.h"

/* Adresni rozsah: 0x12B501 - 0x13D97D  (200 funkci) */

//----- (0012B501) --------------------------------------------------------
int __fastcall sub_12B501(int result)
{
  int v1; // [esp+0h] [ebp-34h]
  int i; // [esp+4h] [ebp-30h]
  int v3; // [esp+8h] [ebp-2Ch]
  int v4; // [esp+Ch] [ebp-28h]
  int v5; // [esp+14h] [ebp-20h]
  int v6; // [esp+1Ch] [ebp-18h]
  int v7; // [esp+20h] [ebp-14h]
  uint8_t v8; // [esp+30h] [ebp-4h]

  v1 = result;
  v3 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v6 = *(uint8_t *)(v3 + v1);
    v7 = *(uint8_t *)(v3 + v1 + 1);
    v4 = 0;
    v3 += 2;
    if ( v7 )
    {
      dword_1BB8A4(i + 5 * (dword_1BBA64 >> 16));
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
// 1BB8A4: using guessed type int (__fastcall *dword_1BB8A4)(_DWORD);
// 1BB904: using guessed type int dword_1BB904;
// 1BBA64: using guessed type int dword_1BBA64;


//----- (0012B634) --------------------------------------------------------
void sub_12B634()
{
  word_1845D8 = 1;
}
// 1845D8: using guessed type int16_t word_1845D8;


//----- (0012B65C) --------------------------------------------------------
void sub_12B65C()
{
  word_1845D8 = 0;
}
// 1845D8: using guessed type int16_t word_1845D8;


//----- (0012B6D4) --------------------------------------------------------
bool __fastcall sub_12B6D4(int a1)
{
  dword_1BC2A8 = a1;
  return (*(_BYTE *)(a1 + 11) & 4) != 0;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012B726) --------------------------------------------------------
int __fastcall sub_12B726(int result)
{
  *(_WORD *)(result + 4) = 0;
  return result;
}


//----- (0012B753) --------------------------------------------------------
int __fastcall sub_12B753(int a1, int a2)
{
  int result; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = a2;
  if ( *(int *)(a1 + 4) >> 16 <= a2 )
    v4 = (*(int *)(a1 + 4) >> 16) - 1;
  result = v4;
  *(_WORD *)(a1 + 4) = v4;
  return result;
}


//----- (0012B79D) --------------------------------------------------------
int __fastcall sub_12B79D(int a1)
{
  int result; // eax

  dword_1BC2A8 = a1;
  result = *(_BYTE *)(a1 + 11) & 0x10;
  if ( result )
    return sub_12AE00();
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012B7E1) --------------------------------------------------------
int __fastcall sub_12B7E1(int result, int a2, _WORD *a3)
{
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // [esp+8h] [ebp-24h]
  int16_t v8; // [esp+1Ch] [ebp-10h]
  int16_t v9; // [esp+20h] [ebp-Ch]
  int16_t v10; // [esp+24h] [ebp-8h]
  int v11; // [esp+28h] [ebp-4h]

  v10 = result;
  dword_1BC2A8 = (int)a3;
  HIWORD(v3) = HIWORD(result);
  LOWORD(v3) = *a3 + result;
  v11 = v3 - 1;
  HIWORD(v4) = HIWORD(a2);
  LOWORD(v4) = a3[1] + a2;
  v8 = v4 - 1;
  v9 = 0;
  if ( *(int *)((char *)&off_1845D4 + 2) >> 16 == 1 )
  {
    if ( (int16_t)result > (int16_t)dword_1BBA4E )
      return result;
    result = a2;
    if ( (int16_t)a2 > (int16_t)dword_1BBA52 )
      return result;
    result = v11;
    if ( (int16_t)v11 < SHIWORD(dword_1BBA4A) )
      return result;
    result = v4 - 1;
    if ( v8 < SHIWORD(dword_1BBA4E) )
      return result;
    if ( v10 < SHIWORD(dword_1BBA4A)
      || (int16_t)a2 < SHIWORD(dword_1BBA4E)
      || (int16_t)v11 > (int16_t)dword_1BBA4E
      || v8 > (int16_t)dword_1BBA52 )
    {
      v9 = 1;
      if ( (int16_t)v11 > (int16_t)dword_1BBA4E )
        LOWORD(v11) = dword_1BBA4E;
      if ( v8 > (int16_t)dword_1BBA52 )
        v8 = dword_1BBA52;
    }
  }
  v5 = dword_1BC2A8;
  v6 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16) + 12);
  if ( v9 )
  {
    if ( !word_1845DA )
    {
      if ( dword_1BBA28 >= 2 )
      {
        v5 = (int16_t)a2;
        sub_138CEE(v10, (int16_t)a2, (int16_t)v11, v8);
      }
      switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
      {
        case 0:
          sub_12BC0B(v10, a2, v6);
          break;
        case 1:
          sub_126487(aRemapDrawNotSu_7, v5);
        case 2:
          sub_126487(aRemapDrawNotSu_8, v5);
        case 3:
          sub_126487(aRemapDrawNotSu_6, v5);
        default:
          break;
      }
    }
  }
  else
  {
    if ( dword_1BBA28 >= 2 )
    {
      v5 = (int16_t)a2;
      sub_138CEE(v10, (int16_t)a2, (int16_t)v11, v8);
    }
    switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
    {
      case 0:
        sub_12BAEB(v10, a2, v6);
        break;
      case 1:
        sub_126487(aRemapDrawNotSu_4, v5);
      case 2:
        sub_126487(aRemapDrawNotSu_5, v5);
      case 3:
        sub_126487(aRemapDrawNotSu_6, v5);
      default:
        break;
    }
  }
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
// 1845D4: using guessed type char *off_1845D4;
// 1845DA: using guessed type int16_t word_1845DA;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012BAEB) --------------------------------------------------------
int __fastcall sub_12BAEB( int a1, int a2, int a3)
{
  int result; // eax
  int16_t v4; // ax
  int v5; // [esp+0h] [ebp-50h]
  int v6; // [esp+4h] [ebp-4Ch]
  int v7; // [esp+14h] [ebp-3Ch]
  int v8; // [esp+1Ch] [ebp-34h]
  int v9; // [esp+24h] [ebp-2Ch]
  int v10; // [esp+30h] [ebp-20h]
  int16_t v11; // [esp+38h] [ebp-18h]
  int16_t v12; // [esp+4Ch] [ebp-4h]

  v12 = *(_WORD *)(dword_1BC2A8 + 2);
  v8 = *(uint16_t *)(a3 + 2);
  v9 = a1 + (v8 + a2) * *(int *)((char *)&dword_184532 + 2);
  v7 = v9;
  v6 = 2;
  while ( 1 )
  {
    result = v12;
    if ( v12 <= v8 )
      break;
    v11 = *(_WORD *)(a3 + 2 * v6);
    v4 = *(_WORD *)(a3 + 2 * v6 + 2);
    v6 += 2;
    if ( v11 )
    {
      v7 += v4;
      v5 = 2 * v6;
      v10 = v11 + v7;
      while ( v7 < v10 )
      {
        *(_BYTE *)(v7 + dword_1BB904) = byte_1BC79C[*(uint8_t *)(v5 + a3)];
        ++v5;
        ++v7;
      }
      v6 += (v11 + 1) / 2;
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


//----- (0012BC0B) --------------------------------------------------------
int __fastcall sub_12BC0B( int a1, int a2, int a3)
{
  int16_t v3; // ax
  int result; // eax
  int16_t v5; // ax
  int v6; // [esp+0h] [ebp-74h]
  int v7; // [esp+4h] [ebp-70h]
  int v8; // [esp+Ch] [ebp-68h]
  int v9; // [esp+10h] [ebp-64h]
  int v10; // [esp+10h] [ebp-64h]
  int v11; // [esp+14h] [ebp-60h]
  int v12; // [esp+18h] [ebp-5Ch]
  int v13; // [esp+1Ch] [ebp-58h]
  int v14; // [esp+20h] [ebp-54h]
  int v15; // [esp+20h] [ebp-54h]
  int16_t v16; // [esp+40h] [ebp-34h]
  int16_t v17; // [esp+44h] [ebp-30h]
  int16_t v18; // [esp+48h] [ebp-2Ch]
  int16_t v19; // [esp+4Ch] [ebp-28h]
  int16_t v20; // [esp+50h] [ebp-24h]
  int16_t v21; // [esp+54h] [ebp-20h]
  int16_t v22; // [esp+58h] [ebp-1Ch]
  int16_t v23; // [esp+5Ch] [ebp-18h]
  int16_t v24; // [esp+60h] [ebp-14h]
  int16_t v25; // [esp+6Ch] [ebp-8h]

  v25 = *(_WORD *)dword_1BC2A8;
  if ( a1 < SHIWORD(dword_1BBA4A) )
  {
    v16 = HIWORD(dword_1BBA4A) - a1;
    v17 = HIWORD(dword_1BBA4A);
  }
  else
  {
    v16 = 0;
    v17 = a1;
  }
  if ( a2 < SHIWORD(dword_1BBA4E) )
  {
    v18 = HIWORD(dword_1BBA4E) - a2;
    v19 = HIWORD(dword_1BBA4E);
  }
  else
  {
    v18 = 0;
    v19 = a2;
  }
  if ( (int16_t)(v25 + a1 - 1) >= (int16_t)dword_1BBA4E )
    v20 = dword_1BBA4E - v17 + 1;
  else
    v20 = v25 + a1 - v17;
  if ( (int16_t)(*(_WORD *)(dword_1BC2A8 + 2) + a2 - 1) >= (int16_t)dword_1BBA52 )
    v21 = dword_1BBA52 - v19 + 1;
  else
    v21 = *(_WORD *)(dword_1BC2A8 + 2) + a2 - v19;
  v9 = *(uint16_t *)(a3 + 2);
  v7 = a1 + v19 * *(int *)((char *)&dword_184532 + 2);
  v8 = v7;
  v13 = 2;
  while ( v18 > v9 )
  {
    v3 = *(_WORD *)(a3 + 2 * v13);
    if ( v3 )
      v13 += (v3 + 1) / 2;
    else
      v9 += *(uint16_t *)(a3 + 2 * v13 + 2);
    v13 += 2;
  }
  if ( v18 < v9 )
  {
    v7 += *(int *)((char *)&dword_184532 + 2) * (v9 - v18);
    v8 = v7;
  }
  v10 = v9 - v18;
  v11 = v16 + v7;
  v6 = v20 + v16 + v7;
  while ( 1 )
  {
    result = v21;
    if ( v21 <= v10 )
      break;
    v24 = *(_WORD *)(a3 + 2 * v13);
    v5 = *(_WORD *)(a3 + 2 * v13 + 2);
    v13 += 2;
    if ( v24 )
    {
      v8 += v5;
      v12 = 2 * v13;
      v14 = v24 + v8;
      if ( v8 < v6 )
      {
        if ( v8 < v11 )
        {
          v22 = v11 - v8;
          if ( (int16_t)(v11 - v8) > v24 )
            v22 = v24;
          v12 += v22;
          v8 += v22;
        }
        v23 = v6 - v8;
        if ( v8 + (int16_t)(v6 - v8) >= v14 )
          v23 = v14 - v8;
        v15 = v23 + v8;
        while ( v8 < v15 )
        {
          *(_BYTE *)(v8 + dword_1BB904) = byte_1BC79C[*(uint8_t *)(v12 + a3)];
          ++v12;
          ++v8;
        }
      }
      v13 += (v24 + 1) / 2;
    }
    else
    {
      v10 += v5;
      v7 += 640 * v5;
      v8 = v7;
      v11 = v16 + v7;
      v6 = v20 + v16 + v7;
    }
  }
  return result;
}
// 184532: using guessed type int dword_184532;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012C117) --------------------------------------------------------
int __fastcall sub_12C117(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v6; // [esp+Ch] [ebp-34h]
  int i; // [esp+10h] [ebp-30h]
  int v8; // [esp+14h] [ebp-2Ch]
  int v9; // [esp+18h] [ebp-28h]
  int v10; // [esp+20h] [ebp-20h]
  int v11; // [esp+24h] [ebp-1Ch]
  uint8_t *v12; // [esp+28h] [ebp-18h]
  int v13; // [esp+30h] [ebp-10h]

  v8 = 0;
  v11 = dword_1BB904;
  dword_1BD09C = (int)byte_1BC89C;
  result = sub_1380E0(a3, a4);
  for ( i = 0; i < 5; ++i )
  {
    v6 = *(_DWORD *)(a1 + 4 * v8);
    v13 = *(_DWORD *)(a1 + 4 * v8 + 4);
    v9 = i << 16;
    v8 += 2;
    while ( v13 || v6 )
    {
      v9 += 4 * v6;
      v10 = v13 + v8;
      while ( v8 < v10 && v9 < 307200 )
      {
        v12 = (uint8_t *)(4 * v8 + a1);
        *(_BYTE *)(v9 + v11) = a2 + *(_BYTE *)(*v12 + dword_1BD09C);
        *(_BYTE *)(v9 + v11 + 1) = a2 + *(_BYTE *)(v12[1] + dword_1BD09C);
        *(_BYTE *)(v9 + v11 + 2) = a2 + *(_BYTE *)(dword_1BD09C + v12[2]);
        *(_BYTE *)(v9 + v11 + 3) = a2 + *(_BYTE *)(dword_1BD09C + v12[3]);
        v9 += 4;
        ++v8;
      }
      v6 = *(_DWORD *)(a1 + 4 * v8);
      v13 = *(_DWORD *)(a1 + 4 * v8 + 4);
      v8 += 2;
    }
    result = i;
  }
  return result;
}
// 1BB904: using guessed type int dword_1BB904;
// 1BD09C: using guessed type int dword_1BD09C;


//----- (0012C2A0) --------------------------------------------------------
void sub_12C2A0()
{
  dword_1845DC = PortDos_BiosTick(); // vlna 15: drive MEMORY[0x46C] (BIOS tick)
}
// 1845DC: using guessed type int dword_1845DC;


//----- (0012C2C6) --------------------------------------------------------
int __fastcall sub_12C2C6(int result)
{
  // Cekej `result` BIOS ticku od posledniho snapshotu (sub_12C2A0). VLNA 15:
  // drive busy-wait na MEMORY[0x46C] - v portu mrtvy stub (nekonecna smycka).
  // Ted realny cas pres PortDos_BiosTick + prubezne vykreslovani, aby byla
  // animace videt a okno reagovalo.
  while ( (int)(PortDos_BiosTick() - dword_1845DC) < result )
    PortVga_WaitVsync();
  return result;
}
// 1845DC: using guessed type int dword_1845DC;


//----- (0012C2E1) --------------------------------------------------------
int sub_12C2E1()
{
  int v1; // [esp+0h] [ebp-8h]

  v1 = dword_1BC2AC[(uint8_t)byte_1BC2E3++];
  byte_1BC2E3 = (uint8_t)byte_1BC2E3 % 10;
  byte_1BC2E4 = byte_1BC2E3 != byte_1BC2E2;
  return v1;
}
// 1BC2AC: using guessed type int dword_1BC2AC[10];
// 1BC2E2: using guessed type char byte_1BC2E2;
// 1BC2E3: using guessed type char byte_1BC2E3;
// 1BC2E4: using guessed type char byte_1BC2E4;


//----- (0012C35B) --------------------------------------------------------
int sub_12C35B()
{
  return dword_1BC2AC[(uint8_t)byte_1BC2E3];
}
// 1BC2AC: using guessed type int dword_1BC2AC[10];
// 1BC2E3: using guessed type char byte_1BC2E3;


//----- (0012C392) --------------------------------------------------------
char sub_12C392()
{
  if ( byte_1BC2E4 != 1 )
    return 0;
  byte_1BC2E4 = 0;
  return 1;
}
// 1BC2E4: using guessed type char byte_1BC2E4;


//----- (0012C3D3) --------------------------------------------------------
_BOOL1 sub_12C3D3()
{
  return *(_WORD *)dword_1BC2D8 != *(_WORD *)dword_1BC2D4;
}
// 1BC2D4: using guessed type int dword_1BC2D4;
// 1BC2D8: using guessed type int dword_1BC2D8;


//----- (0012C420) --------------------------------------------------------
// Instalace vlastniho klavesnicoveho INT 9 handleru (KeyboardIsr_12C4D8): mezi
// CLI/STI (sub_144A46/48 = _disable/_enable) si ulozi puvodni vektor do
// savedKeyboardVector_1BC2DC a nastavi svuj. Puvodni dekompilat pristupoval
// k ulozenemu vektoru pres rucni bytove offsety do promenne mylne typovane
// jako ukazatel na funkci - vytknuto do struktury DosFarPointer (offset +
// segment, viz port_dos.h), jinak by "*(_DWORD *)byte_1BC2DC" pri obnove
// v RestoreKeyboardIsr_12C493 DEREFERENCOVALO hodnotu misto cteni ulozenych bajtu.
// Artefakt dekompilace: segmentova cast puvodniho vektoru prisla z DX
// (48bit navratova hodnota _dos_getvect v DX:EAX), ktery dekompiler
// ztotoznil s parametrem a2 - zapis "segment = a2" je proto ponechan
// 1:1 dle puvodniho kodu.
// 1050/1052 (0x41A/0x41C) jsou adresy hlavy/ocasu klavesniceho bufferu
// v BIOS data area - viz DECOMP_TODO u sub_12C3D3.
void __fastcall InstallKeyboardIsr_12C420(int a1, int a2)
{
  sub_144A46();
  savedKeyboardVector_1BC2DC.offset = dos_getvect(9);
  savedKeyboardVector_1BC2DC.segment = (uint16_t)a2;
  dos_setvect(9, 9, (unsigned int)(uintptr_t)KeyboardIsr_12C4D8, __CS__);
  dword_1BC2D8 = 1050;
  dword_1BC2D4 = 1052;
  sub_144A48();
}
// 1BC2D4: using guessed type int dword_1BC2D4;
// 1BC2D8: using guessed type int dword_1BC2D8;


//----- (0012C493) --------------------------------------------------------
// Obnova puvodniho INT 9 vektoru ulozeneho v InstallKeyboardIsr_12C420 - vola se pri
// ukonceni hry (atexit retez sub_113DBD v orion_part_18.c).
void RestoreKeyboardIsr_12C493()
{
  sub_144A46();
  dos_setvect(9, 9, savedKeyboardVector_1BC2DC.offset, savedKeyboardVector_1BC2DC.segment);
  sub_144A48();
}


//----- (0012C4D8) --------------------------------------------------------
void __noreturn KeyboardIsr_12C4D8()
{
  ((void (__noreturn *)(void))_GETDS)();
}
// 1BC2DC: invalid function type '?' has been ignored
// 1BC2D4: using guessed type int dword_1BC2D4;
// 1BC2D8: using guessed type int dword_1BC2D8;
// 1BC2DC: savedKeyboardVector_1BC2DC (puvodne guessed ukazatel na funkci)
// 1BC2E2: using guessed type char byte_1BC2E2;
// 1BC2E4: using guessed type char byte_1BC2E4;


//----- (0012C574) --------------------------------------------------------
int sub_12C574()
{
  while ( !sub_12C392() )
    ;
  return (uint8_t)sub_12C2E1();
}


//----- (0012C5AE) --------------------------------------------------------
int sub_12C5AE()
{
  int v1; // [esp+0h] [ebp-8h]

  if ( sub_12C392() != 1 )
    return 0;
  v1 = sub_12C2E1();
  if ( (_WORD)v1 == 0xE00D )
    return 7181;
  return v1;
}


//----- (0012C607) --------------------------------------------------------
int __fastcall sub_12C607(int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  _BYTE v6[68]; // [esp+0h] [ebp-88h] BYREF
  int v7; // [esp+44h] [ebp-44h]
  int v8; // [esp+64h] [ebp-24h]
  int v9; // [esp+70h] [ebp-18h]
  int v10; // [esp+74h] [ebp-14h]
  int v11; // [esp+7Ch] [ebp-Ch]

  v7 = a1;
  v11 = a2;
  dword_1BC31C = dword_1B06FC;
  if ( (a2 & 0x8000u) != 0 )
    sub_1273DC(v7, 4u, (int16_t)v11, a4);
  if ( *(int *)((char *)&dword_1845DC + 2) >> 16 == 1 )
  {
    fclose(dword_1BC338);
    dword_1BC338 = 0;
  }
      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    dword_1BC338 = fopen(v7, aRb);
  if ( !dword_1BC338 )
  {
    if ( !byte_184544[0] )
      sub_1273DC(v7, 1u, (int16_t)v11, a4);
    strcpy(v6, byte_184544);
    strcat(v6, v7);
        // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    dword_1BC338 = fopen(v6, aRb);
    if ( !dword_1BC338 )
      sub_1273DC(v7, 1u, (int16_t)v11, a4);
  }
  LOWORD(dword_1845E0) = 1;
  v4 = dword_1BC338;
  fread(dword_1BC31C, 2052, 1, dword_1BC338);
  if ( *(uint16_t *)(dword_1BC31C + 2) != 65197 )
    sub_1273DC(v7, 7u, (int16_t)v11, v4);
  if ( (int16_t)v11 >= *(int16_t *)dword_1BC31C )
    sub_1273DC(v7, 8u, (int16_t)v11, v4);
  v9 = *(_DWORD *)(4 * (int16_t)v11 + dword_1BC31C + 8);
  v8 = *(_DWORD *)(dword_1BC31C + 4 * (int16_t)v11 + 12);
  v10 = v8 - v9;
  dword_1BC328 = v9;
  dword_1BC354 = v8;
  dword_1BC2E8 = v8 - v9;
  // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
  // Hex-Rays artefakt jako jinde. LBX archiv vzor (viz orion_part_19.c):
  // prave spocitany zacatecni offset zaznamu se seekuje pred fread.
  fseek(dword_1BC338, v9, SEEK_SET);
  return fread(dword_1BC31C, 0x2000, 1, dword_1BC338);
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 13F220: using guessed type int __fastcall strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 1845DC: using guessed type int dword_1845DC;
// 1845E0: using guessed type int dword_1845E0;
// 1B06FC: using guessed type int dword_1B06FC;
// 1BC2E8: using guessed type int dword_1BC2E8;
// 1BC31C: using guessed type int dword_1BC31C;
// 1BC328: using guessed type int dword_1BC328;
// 1BC338: using guessed type int dword_1BC338;
// 1BC354: using guessed type int dword_1BC354;


//----- (0012C7CC) --------------------------------------------------------
int sub_12C7CC()
{
  _DWORD *v0; // edx
  int v1; // edx
  int result; // eax
  int64_t v3; // [esp+0h] [ebp-34h]
  char *v4 = 0; // [esp+8h] [ebp-2Ch]
  int v5; // [esp+14h] [ebp-20h]
  int v6; // [esp+24h] [ebp-10h]

  dword_1BC2A8 = dword_1B06FC;
  if ( (*(_BYTE *)(dword_1B06FC + 11) & 0x10) != 0 )
    sub_12AE00();
  v0 = (_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  v6 = v0[1] - *v0;
  if ( sub_110C29(dword_1BC324) < v6 )
    sub_126487(aFileAnimationF, (int)v0);
  v5 = dword_1BC324;
  // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
  // Hex-Rays artefakt jako jinde. LBX archiv vzor (viz orion_part_19.c):
  // prave spocitany zacatecni offset zaznamu se seekuje pred fread.
  fseek(dword_1BC338, *v0, SEEK_SET);
  v1 = v6;
  fread(v5, v6, 1, dword_1BC338);
  if ( dword_1BBA28 >= 2 )
  {
    v1 = 0;
    sub_138CEE(0, 0, *(int16_t *)dword_1BC2A8 - 1, (*(int *)dword_1BC2A8 >> 16) - 1);
  }
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
  {
    switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
    {
      case 0:
        sub_12ACA4(0, 0, v5);
        break;
      case 1:
        sub_12AEC0(0, 0, v5);
        break;
      case 2:
        if ( dword_1BBA42 >> 16 == 1 )
          sub_12B501(v5);
        else
          sub_12B3E0(v5);
        if ( dword_1BBA28 >= 2 )
          sub_138CEE(0, 0, 639, 479);
        break;
      case 3:
        sub_126487(aRefreshMaskCan_0, v1);
      default:
        break;
    }
  }
  else
  {
    LOBYTE(v3) = *(_BYTE *)(dword_1BC2A8 + 11) & 3;
    switch ( (char)v3 )
    {
      case 0:
        sub_14852C(0, 0, v5); // wave 20: args recovered from original asm (x=0,y=0,data=v5)
        break;
      case 1:
        sub_1485B3(0, 0, (char *)(intptr_t)v5); // wave 20
        break;
      case 2:
        if ( dword_1BBA42 >> 16 == 1 )
          sub_12B2D9(v5);
        else
          sub_12AFCC(v5);
        if ( dword_1BBA28 >= 2 )
          sub_138CEE(0, 0, 639, 479);
        break;
      case 3:
        sub_126487(aRefreshMaskCan_0, v1);
      default:
        break;
    }
  }
  ++*(_WORD *)(dword_1BC2A8 + 4);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x20) != 0 )
  {
    result = dword_1BC2A8;
    if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
    {
      if ( *(uint8_t *)(dword_1BC2A8 + 8) + 1 == *(int *)(dword_1BC2A8 + 4) >> 16 )
      {
        result = dword_1BC2A8;
        *(_WORD *)(dword_1BC2A8 + 4) = 0;
      }
      else
      {
        result = dword_1BC2A8;
        *(_WORD *)(dword_1BC2A8 + 4) = *(uint8_t *)(dword_1BC2A8 + 8);
      }
    }
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
  return result;
}
// 12C9DA: variable 'v3' is possibly undefined
// 12C9DA: variable 'v4' is possibly undefined
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 1B06FC: using guessed type int dword_1B06FC;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BC2A8: using guessed type int dword_1BC2A8;
// 1BC324: using guessed type int dword_1BC324;
// 1BC328: using guessed type int dword_1BC328;
// 1BC338: using guessed type int dword_1BC338;


//----- (0012CAD6) --------------------------------------------------------
int __fastcall sub_12CAD6( int a1)
{
  int v1; // edx
  _DWORD *v2; // edx
  int v3; // edx
  int result; // eax
  int v5; // [esp+14h] [ebp-20h]
  int v6; // [esp+20h] [ebp-14h]

  v1 = 2730 * a1;
  dword_1BC2A8 = v1 + dword_1B06FC;
  if ( *(int *)(v1 + dword_1B06FC + 4) >> 16 >= 678 )
    sub_126487(aTooManyFramesF, v1);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x10) != 0 )
    sub_12AE00();
  v2 = (_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  v5 = v2[1] - *v2;
  if ( sub_110C29(dword_1BC324) < v5 )
    sub_126487(aFileAnimationF_0, (int)v2);
  v6 = dword_1BC324;
  // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
  // Hex-Rays artefakt jako jinde. LBX archiv vzor (viz orion_part_19.c):
  // prave spocitany zacatecni offset zaznamu se seekuje pred fread.
  fseek(dword_1BC310[a1], *v2, SEEK_SET);
  v3 = v5;
  fread(v6, v5, 1, dword_1BC310[a1]);
  if ( dword_1BBA28 >= 2 )
  {
    v3 = 0;
    sub_138CEE(0, 0, *(int16_t *)dword_1BC2A8 - 1, (*(int *)dword_1BC2A8 >> 16) - 1);
  }
  switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
  {
    case 0:
      sub_12A914(0, 0, v6);
      break;
    case 1:
      sub_126487(aDifferentailFi, v3);
    case 2:
      sub_126487(aDifferentailFi_0, v3);
    case 3:
      sub_126487(aRefreshMaskCan_0, v3);
    default:
      break;
  }
  ++*(_WORD *)(dword_1BC2A8 + 4);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x20) != 0 )
  {
    result = dword_1BC2A8;
    if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
    {
      if ( *(uint8_t *)(dword_1BC2A8 + 8) + 1 == *(int *)(dword_1BC2A8 + 4) >> 16 )
      {
        result = dword_1BC2A8;
        *(_WORD *)(dword_1BC2A8 + 4) = 0;
      }
      else
      {
        result = dword_1BC2A8;
        *(_WORD *)(dword_1BC2A8 + 4) = *(uint8_t *)(dword_1BC2A8 + 8);
      }
    }
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
  return result;
}
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 1B06FC: using guessed type int dword_1B06FC;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BC2A8: using guessed type int dword_1BC2A8;
// 1BC310: using guessed type int dword_1BC310[3];
// 1BC324: using guessed type int dword_1BC324;


//----- (0012CD2D) --------------------------------------------------------
int sub_12CD2D()
{
  _DWORD *v0; // edx
  int result; // eax
  int v2; // [esp+18h] [ebp-1Ch]
  int v3; // [esp+20h] [ebp-14h]
  int v4; // [esp+24h] [ebp-10h]

  v2 = dword_1BBA28;
  dword_1BBA28 = 2;
  dword_1BC2A8 = dword_1B06FC;
  if ( (*(int *)(dword_1B06FC + 2) >> 16) + 1 == *(int *)(dword_1B06FC + 4) >> 16 )
    dword_1BBA28 = v2;
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x10) != 0 )
    sub_12AE00();
  v0 = (_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  v3 = v0[1] - *v0;
  if ( sub_110C29(dword_1BC324) < v3 )
    sub_126487(aFileAnimationF_1, (int)v0);
  v4 = dword_1BC324;
  // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
  // Hex-Rays artefakt jako jinde. LBX archiv vzor (viz orion_part_19.c):
  // prave spocitany zacatecni offset zaznamu se seekuje pred fread.
  fseek(dword_1BC338, *v0, SEEK_SET);
  fread(v4, v3, 1, dword_1BC338);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 8) != 0 )
    sub_126487(aDifferentailFi_1, v3);
  switch ( *(_BYTE *)(dword_1BC2A8 + 11) & 3 )
  {
    case 0:
      sub_12A914(0, 0, v4);
      break;
    case 1:
      sub_126487(aDifferentailFi_2, v3);
    case 2:
      sub_126487(aDifferentailFi_3, v3);
    case 3:
      sub_126487(aRefreshMaskCan_0, v3);
    default:
      break;
  }
  ++*(_WORD *)(dword_1BC2A8 + 4);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x20) != 0 )
  {
    if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
    {
      if ( *(uint8_t *)(dword_1BC2A8 + 8) + 1 == *(int *)(dword_1BC2A8 + 4) >> 16 )
        *(_WORD *)(dword_1BC2A8 + 4) = 0;
      else
        *(_WORD *)(dword_1BC2A8 + 4) = *(uint8_t *)(dword_1BC2A8 + 8);
    }
  }
  else if ( *(_WORD *)(dword_1BC2A8 + 4) >= *(_WORD *)(dword_1BC2A8 + 6) )
  {
    *(_WORD *)(dword_1BC2A8 + 4) = *(_WORD *)(dword_1BC2A8 + 6) - 1;
  }
  result = v2;
  dword_1BBA28 = v2;
  return result;
}
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 1B06FC: using guessed type int dword_1B06FC;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BC2A8: using guessed type int dword_1BC2A8;
// 1BC324: using guessed type int dword_1BC324;
// 1BC328: using guessed type int dword_1BC328;
// 1BC338: using guessed type int dword_1BC338;


//----- (0012D1C5) --------------------------------------------------------
int __fastcall sub_12D1C5(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  _BYTE v7[96]; // [esp+0h] [ebp-8Ch] BYREF
  int v8; // [esp+60h] [ebp-2Ch]
  int v9; // [esp+64h] [ebp-28h]
  int v10; // [esp+68h] [ebp-24h]
  int v11; // [esp+74h] [ebp-18h]
  int v12; // [esp+7Ch] [ebp-10h]
  int v13; // [esp+80h] [ebp-Ch]

  v8 = a1;
  v12 = a2;
  v13 = a3;
  if ( (int16_t)a3 >= 3 )
    sub_126487(aMax3FileAnimat, a2);
  dword_1BC31C = 2730 * (int16_t)v13 + dword_1B06FC;
  if ( (v12 & 0x8000u) != 0 )
    sub_1273DC(v8, 4u, (int16_t)v12, a4);
  if ( *(int *)((char *)&dword_1845E0 + 2 * (int16_t)v13) >> 16 == 1 )
    fclose(dword_1BC310[(int16_t)v13]);
  dword_1BC310[(int16_t)v13] = fopen(v8, aRb_5);
  if ( !dword_1BC310[(int16_t)v13] )
  {
    if ( !byte_184544[0] )
      sub_1273DC(v8, 1u, (int16_t)v12, a4);
    strcpy(v7, byte_184544);
    strcat(v7, v8);
    v4 = fopen(v7, aRb_5);
    dword_1BC310[(int16_t)v13] = v4;
    if ( !dword_1BC310[(int16_t)v13] )
      sub_1273DC(v8, 1u, (int16_t)v12, a4);
  }
  *((_WORD *)&dword_1845E0 + (int16_t)v13 + 1) = 1;
  v5 = dword_1BC310[(int16_t)v13];
  fread(dword_1BC31C, 2052, 1, v5);
  if ( *(uint16_t *)(dword_1BC31C + 2) != 65197 )
    sub_1273DC(v8, 7u, (int16_t)v12, v5);
  if ( (int16_t)v12 >= *(int16_t *)dword_1BC31C )
    sub_1273DC(v8, 8u, (int16_t)v12, v5);
  v9 = *(_DWORD *)(dword_1BC31C + 4 * (int16_t)v12 + 8);
  v10 = *(_DWORD *)(dword_1BC31C + 4 * (int16_t)v12 + 12);
  v11 = v10 - v9;
  dword_1BC348[(int16_t)v13] = v9;
  dword_1BC32C[(int16_t)v13] = v10;
  dword_1BC33C[(int16_t)v13] = v11;
  // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
  // Hex-Rays artefakt jako jinde. LBX archiv vzor (viz orion_part_19.c):
  // prave spocitany zacatecni offset zaznamu se seekuje pred fread.
  fseek(dword_1BC310[(int16_t)v13], v9, SEEK_SET);
  return fread(dword_1BC31C, 2730, 1, dword_1BC310[(int16_t)v13]);
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 13F220: using guessed type int __fastcall strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 1845E0: using guessed type int dword_1845E0;
// 1B06FC: using guessed type int dword_1B06FC;
// 1BC310: using guessed type int dword_1BC310[3];
// 1BC31C: using guessed type int dword_1BC31C;
// 1BC32C: using guessed type int dword_1BC32C[3];
// 1BC33C: using guessed type int dword_1BC33C[3];
// 1BC348: using guessed type int dword_1BC348[3];


//----- (0012D408) --------------------------------------------------------
int __fastcall sub_12D408( int a1)
{
  int v1; // edx
  _DWORD *v2; // edx
  int v3; // edx
  int result; // eax
  int64_t v5; // [esp+0h] [ebp-34h]
  char *v6; // [esp+8h] [ebp-2Ch]
  int v7; // [esp+14h] [ebp-20h]
  int v8; // [esp+20h] [ebp-14h]

  v1 = 2730 * a1;
  dword_1BC2A8 = v1 + dword_1B06FC;
  if ( *(int *)(v1 + dword_1B06FC + 4) >> 16 >= 678 )
    sub_126487(aTooManyFramesF_0, v1);
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x10) != 0 )
    sub_12AE00();
  HIDWORD(v5) = dword_1BC2A8 + 12;
  v2 = (_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  v7 = v2[1] - *v2;
  if ( sub_110C29(dword_1BC324) < v7 )
    sub_126487(aFileAnimationF_3, (int)v2);
  v8 = dword_1BC324;
  // DECOMP_TODO (vyreseno ve vlne 07): fseek() melo 0 parametru - stejny
  // Hex-Rays artefakt jako jinde. LBX archiv vzor (viz orion_part_19.c):
  // prave spocitany zacatecni offset zaznamu se seekuje pred fread.
  fseek(dword_1BC310[a1], *v2, SEEK_SET);
  v3 = v7;
  fread(v8, v7, 1, dword_1BC310[a1]);
  if ( dword_1BBA28 >= 2 )
  {
    v3 = 0;
    sub_138CEE(0, 0, *(int16_t *)dword_1BC2A8 - 1, (*(int *)dword_1BC2A8 >> 16) - 1);
  }
  LOBYTE(v5) = *(_BYTE *)(dword_1BC2A8 + 11) & 3;
  switch ( (char)v5 )
  {
    case 0:
      sub_14852C(0, 0, v8); // wave 20: args recovered from original asm (x=0,y=0,data=v8)
      break;
    case 1:
      sub_1485B3(0, 0, (char *)(intptr_t)v8); // wave 20
      break;
    case 2:
      if ( dword_1BBA42 >> 16 == 1 )
        sub_12B2D9(v8);
      else
        sub_12AFCC(v8);
      if ( dword_1BBA28 >= 2 )
        sub_138CEE(0, 0, 639, 479);
      break;
    case 3:
      sub_126487(aRefreshMaskCan_0, v3);
    default:
      break;
  }
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
// 12D59E: variable 'v5' is possibly undefined
// 12D59E: variable 'v6' is possibly undefined
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 1B06FC: using guessed type int dword_1B06FC;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA42: using guessed type int dword_1BBA42;
// 1BC2A8: using guessed type int dword_1BC2A8;
// 1BC310: using guessed type int dword_1BC310[3];
// 1BC324: using guessed type int dword_1BC324;


//----- (0012D6B2) --------------------------------------------------------
int __fastcall sub_12D6B2(int a1)
{
  int v1; // eax
  int result; // eax
  int v3; // [esp+0h] [ebp-4h]

  v3 = a1;
  dword_1BC320 = dword_1B06FC;
  if ( (int16_t)a1 >= *(int16_t *)(dword_1B06FC + 6) )
  {
    HIWORD(v1) = HIWORD(dword_1BC320);
    LOWORD(v1) = *(_WORD *)(dword_1BC320 + 6);
    v3 = v1 - 1;
  }
  result = v3;
  *(_WORD *)(dword_1BC320 + 4) = v3;
  return result;
}
// 1B06FC: using guessed type int dword_1B06FC;
// 1BC320: using guessed type int dword_1BC320;


//----- (0012D70B) --------------------------------------------------------
int16_t sub_12D70B()
{
  dword_1BC320 = dword_1B06FC;
  return *(_WORD *)(dword_1B06FC + 4);
}
// 1B06FC: using guessed type int dword_1B06FC;
// 1BC320: using guessed type int dword_1BC320;


//----- (0012D745) --------------------------------------------------------
int16_t __fastcall sub_12D745( int a1)
{
  dword_1BC320 = 2730 * a1 + dword_1B06FC;
  return *(_WORD *)(dword_1BC320 + 4);
}
// 1B06FC: using guessed type int dword_1B06FC;
// 1BC320: using guessed type int dword_1BC320;


//----- (0012D78E) --------------------------------------------------------
int sub_12D78E()
{
  int result; // eax

  result = dword_1BB8FC;
  dword_1BC324 = dword_1BB8FC;
  return result;
}
// 1BB8FC: using guessed type int dword_1BB8FC;
// 1BC324: using guessed type int dword_1BC324;


//----- (0012D7B7) --------------------------------------------------------
int __fastcall sub_12D7B7(int result)
{
  dword_1BC324 = result;
  return result;
}
// 1BC324: using guessed type int dword_1BC324;


//----- (0012D7E3) --------------------------------------------------------
int __fastcall sub_12D7E3(int a1)
{
  int result; // eax

  dword_1BC2A8 = 2730 * a1 + dword_1B06FC;
  if ( *(int *)(2730 * a1 + dword_1B06FC + 4) >> 16 >= 678 )
    sub_126487(aTooManyFramesF_1, 2730 * a1);
  result = *(_BYTE *)(dword_1BC2A8 + 11) & 0x10;
  if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 0x10) != 0 )
    return sub_12AE00();
  return result;
}
// 1B06FC: using guessed type int dword_1B06FC;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012D88F) --------------------------------------------------------
int __fastcall sub_12D88F( int a1, int a2)
{
  int v2; // eax
  int result; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = a2;
  dword_1BC320 = 2730 * a1 + dword_1B06FC;
  if ( (int16_t)a2 >= *(int16_t *)(2730 * a1 + dword_1B06FC + 6) )
  {
    HIWORD(v2) = HIWORD(dword_1BC320);
    LOWORD(v2) = *(_WORD *)(dword_1BC320 + 6);
    v4 = v2 - 1;
  }
  result = v4;
  *(_WORD *)(dword_1BC320 + 4) = v4;
  return result;
}
// 1B06FC: using guessed type int dword_1B06FC;
// 1BC320: using guessed type int dword_1BC320;


//----- (0012D8F5) --------------------------------------------------------
int __fastcall sub_12D8F5( int a1, int a2, int a3)
{
  int result; // eax

  sub_12D943(a1, a2, (_WORD *)a3);
  result = a3 + 16;
  sub_127678((char *)(a3 + 16), a1 * a2, 0);
  return result;
}


//----- (0012D943) --------------------------------------------------------
int __fastcall sub_12D943( int a1, int a2, _WORD *a3)
{
  int result; // eax

  dword_1BC2A8 = (int)a3;
  *a3 = a1;
  *(_WORD *)(dword_1BC2A8 + 2) = a2;
  *(_WORD *)(dword_1BC2A8 + 4) = 0;
  *(_WORD *)(dword_1BC2A8 + 6) = 1;
  *(_BYTE *)(dword_1BC2A8 + 8) = 0;
  *(_BYTE *)(dword_1BC2A8 + 9) = 0;
  *(_BYTE *)(dword_1BC2A8 + 10) = 0;
  *(_BYTE *)(dword_1BC2A8 + 11) = 1;
  result = dword_1BC2A8;
  *(_DWORD *)(dword_1BC2A8 + 12) = 16;
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012DAA4) --------------------------------------------------------
int __fastcall sub_12DAA4( int a1, int a2)
{
  return 4 * ((a1 * a2 + 19 - (__CFSHL__((a1 * a2 + 19) >> 31, 2) + 4 * ((a1 * a2 + 19) >> 31))) >> 2);
}


//----- (0012DAFC) --------------------------------------------------------
int __fastcall sub_12DAFC(int a1)
{
  char v1; // dl
  int result; // eax

  dword_1BC2A8 = a1;
  v1 = *(_BYTE *)(a1 + 11) | 8;
  result = dword_1BC2A8;
  *(_BYTE *)(dword_1BC2A8 + 11) = v1;
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012DFB2) --------------------------------------------------------
_BYTE *__fastcall sub_12DFB2(int a1, int16_t *a2, int a3)
{
  _BYTE *v5; // [esp+18h] [ebp-28h]
  int16_t v6; // [esp+2Ch] [ebp-14h]
  int16_t v7; // [esp+30h] [ebp-10h]

  dword_1BC2A8 = (int)a2;
  v6 = *a2;
  v7 = a2[1];
  v5 = (char *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6];
  if ( a3 && a3 != 1 )
  {
    if ( a2 == (int16_t *)a1 )
    {
      return sub_1478C3(v5, v6, v7);
    }
    else
    {
      sub_12D943(v6, v7, (_WORD *)a1);
      return (_BYTE *)sub_1478EF((int)v5, v6, v7, (char *)(a1 + 16));
    }
  }
  else if ( a2 == (int16_t *)a1 )
  {
    return sub_14787E(v5, v6, v7);
  }
  else
  {
    sub_12D943(v6, v7, (_WORD *)a1);
    return sub_1478A6(v5, v6, v7, a1 + 16);
  }
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012E0B2) --------------------------------------------------------
_BYTE *__fastcall sub_12E0B2(int a1, int16_t *a2)
{
  _BYTE *v4; // [esp+8h] [ebp-18h]
  int16_t v5; // [esp+18h] [ebp-8h]
  int16_t v6; // [esp+1Ch] [ebp-4h]

  dword_1BC2A8 = (int)a2;
  v5 = *a2;
  v6 = a2[1];
  v4 = (char *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6];
  sub_12D943(*a2, v6, (_WORD *)a1);
  return sub_12779E((_BYTE *)(a1 + 16), v4, v6 * v5);
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012E148) --------------------------------------------------------
char *__fastcall sub_12E148(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // [esp+10h] [ebp-24h] BYREF
  int16_t v7[6]; // [esp+14h] [ebp-20h] BYREF
  int v8; // [esp+20h] [ebp-14h] BYREF
  int16_t v9[4]; // [esp+24h] [ebp-10h] BYREF
  int v10; // [esp+2Ch] [ebp-8h]
  int v11; // [esp+30h] [ebp-4h]

  *(_DWORD *)v9 = a1;
  *(_DWORD *)v7 = a2;
  v6 = a3;
  v8 = a4;
  if ( (int16_t)a3 < (int16_t)a1 )
  {
    sub_133111(v9, (int16_t *)&v6);
    sub_133111(v7, (int16_t *)&v8);
  }
  v10 = v6 - *(_DWORD *)v9 + 1;
  v11 = v8 - *(_DWORD *)v7 + 1;
  sub_12D943(v6 - v9[0] + 1, v11, (_WORD *)a5);
  return sub_14791B(
           (char *)(dword_1BB904 + v9[0] + HIDWORD(qword_184530) * v7[0]),
           (int16_t)v10,
           (int16_t)v11,
           (char *)(a5 + 16));
}
// 184530: using guessed type int64_t qword_184530;
// 1BB904: using guessed type int dword_1BB904;


//----- (0012E1E0) --------------------------------------------------------
int __fastcall sub_12E1E0( int a1, int a2, int16_t *a3, int a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-38h]
  int v6; // [esp+14h] [ebp-28h]
  int v7; // [esp+18h] [ebp-24h]
  int16_t v8; // [esp+20h] [ebp-1Ch]
  int i; // [esp+24h] [ebp-18h]
  int16_t v10; // [esp+28h] [ebp-14h]
  int16_t v11; // [esp+2Ch] [ebp-10h]
  int16_t j; // [esp+30h] [ebp-Ch]
  char v13; // [esp+34h] [ebp-8h]

  dword_1BC2A8 = (int)a3;
  v11 = *a3;
  v8 = a3[1];
  if ( *a3 + a1 <= 24 )
  {
    v10 = 0;
  }
  else
  {
    v10 = a1 + *a3 - 24;
    v11 = 24 - a1;
  }
  if ( a3[1] + a2 > 24 )
    v8 = 24 - a2;
  v6 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  v5 = 0;
  v7 = a1 + 24 * a2;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= v8 )
      break;
    for ( j = 0; j < v11; ++j )
    {
      v13 = *(_BYTE *)(v5 + v6);
      if ( v13 )
        *(_BYTE *)(v7 + dword_1BB900 + 576 * a4) = v13;
      ++v5;
      ++v7;
    }
    v5 += v10;
    v7 += 24 - v11;
  }
  return result;
}
// 1BB900: using guessed type int dword_1BB900;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012E332) --------------------------------------------------------
char *__fastcall sub_12E332( int a1)
{
  char *result; // eax

  result = (char *)(dword_1BB900 + 576 * a1);
  sub_127678(result, 0x240u, 0);
  return result;
}
// 1BB900: using guessed type int dword_1BB900;


//----- (0012E374) --------------------------------------------------------
int __fastcall sub_12E374(int16_t *a1, int16_t *a2, int a3, int a4)
{
  int result; // eax
  int v6; // [esp+Ch] [ebp-34h]
  int v7; // [esp+10h] [ebp-30h]
  int v8; // [esp+14h] [ebp-2Ch]
  int v9; // [esp+24h] [ebp-1Ch]
  _BYTE *v10; // [esp+28h] [ebp-18h]
  int v11; // [esp+2Ch] [ebp-14h]
  int16_t v12; // [esp+30h] [ebp-10h]
  int16_t v13; // [esp+34h] [ebp-Ch]
  int16_t v14; // [esp+38h] [ebp-8h]
  int16_t v15; // [esp+3Ch] [ebp-4h]

  v14 = a3;
  v13 = a4;
  dword_1BC2A8 = (int)a2;
  v15 = *a2;
  v12 = a2[1];
  v6 = a3 * *a2 / 100;
  v9 = v12 * a4 / 100;
  if ( v6 <= 0 || v9 <= 0 )
    return sub_12D943(1, 1, a1);
  v11 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  if ( a2 == a1 )
  {
    v10 = (_BYTE *)(dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16)));
  }
  else
  {
    sub_12D943(v6, v9, a1);
    v10 = a1 + 8;
  }
  v7 = a3;
  v8 = a4;
  if ( a3 < 100 && a4 > 100 )
    v14 = 100;
  if ( v14 > 100 && a4 < 100 )
    v13 = 100;
  if ( v14 > 100 || v13 > 100 )
    sub_147935(v11, v14, v13, (int)v10, v15, v12, v6, v9);
  if ( a3 > 100 )
    v7 = 100;
  if ( a4 > 100 )
    v8 = 100;
  if ( v7 < 100 || v8 < 100 )
    sub_147A12(v11, v14, v13, v10, v15, v12, v6, v9);
  result = (int)a2;
  if ( a2 == a1 )
  {
    *(_WORD *)dword_1BC2A8 = v6;
    result = v12 * a4 / 100;
    *(_WORD *)(dword_1BC2A8 + 2) = v9;
  }
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012E550) --------------------------------------------------------
int16_t *__fastcall sub_12E550(int16_t *a1, int16_t *a2, int a3)
{
  int16_t *result; // eax
  int *v5; // [esp+Ch] [ebp-18h]
  int *v6; // [esp+10h] [ebp-14h]
  int16_t v7; // [esp+1Ch] [ebp-8h]
  int16_t v8; // [esp+20h] [ebp-4h]

  dword_1BC2A8 = (int)a2;
  v7 = *a2;
  v8 = a2[1];
  v5 = (int *)((char *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6]);
  if ( a2 == a1 )
  {
    v6 = (int *)((char *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6]);
  }
  else
  {
    sub_12D943(v7, v8, a1);
    v6 = (int *)(a1 + 8);
  }
  if ( a3 < 100 )
  {
    if ( a3 )
    {
      return (int16_t *)sub_147ABC(v5, a3, v6, v7, v8);
    }
    else
    {
      result = a2;
      if ( a2 != a1 )
        return (int16_t *)sub_12779E(v6, v5, v8 * v7);
    }
  }
  else
  {
    result = a1;
    sub_127678((char *)a1, v8 * v7, 0);
  }
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012E64F) --------------------------------------------------------
char __fastcall sub_12E64F(int16_t *a1, int16_t *a2, int a3, int a4)
{
  uint8_t *v6; // [esp+Ch] [ebp-1Ch]
  _BYTE *v7; // [esp+10h] [ebp-18h]
  int16_t v8; // [esp+24h] [ebp-4h]

  dword_1BC2A8 = (int)a2;
  v8 = *a2;
  v6 = (uint8_t *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6];
  if ( a2 == a1 )
  {
    v7 = (char *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6];
  }
  else
  {
    sub_12D943(v8, a2[1], a1);
    v7 = a1 + 8;
    sub_12E0B2((int)a1, a2);
  }
  if ( a4 )
    return sub_147C6A(v6, a3, v7, v8);
  else
    return sub_147B89((char *)v6, a3, v7, v8);
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012E8D4) --------------------------------------------------------
char __fastcall sub_12E8D4(int16_t *a1, int16_t *a2, int a3)
{
  char *v5; // [esp+Ch] [ebp-18h]
  _BYTE *v6; // [esp+10h] [ebp-14h]
  int16_t v7; // [esp+1Ch] [ebp-8h]
  int16_t v8; // [esp+20h] [ebp-4h]

  dword_1BC2A8 = (int)a2;
  v7 = *a2;
  v8 = a2[1];
  v5 = (char *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6];
  if ( a2 == a1 )
  {
    v6 = (char *)a2 + *(_DWORD *)&a2[2 * (*(int *)(a2 + 1) >> 16) + 6];
  }
  else
  {
    sub_12D943(v7, a2[1], a1);
    v6 = a1 + 8;
    sub_12E0B2((int)a1, a2);
  }
  return sub_147E23(v5, (int)&byte_1BA358[256 * a3], v6, v7, v8);
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012E9A1) --------------------------------------------------------
_DWORD *__fastcall sub_12E9A1(int a1, int a2, int a3)
{
  int v3; // edx
  _DWORD *result; // eax
  int v5; // edx
  int j; // [esp+Ch] [ebp-30h]
  int i; // [esp+10h] [ebp-2Ch]
  int v9; // [esp+18h] [ebp-24h]
  int v10; // [esp+20h] [ebp-1Ch] BYREF
  int v11; // [esp+24h] [ebp-18h] BYREF
  int v12; // [esp+28h] [ebp-14h] BYREF
  char v13; // [esp+2Ch] [ebp-10h]
  char v14[4]; // [esp+30h] [ebp-Ch] BYREF
  char v15[4]; // [esp+34h] [ebp-8h] BYREF
  char v16[4]; // [esp+38h] [ebp-4h] BYREF

  v13 = a3;
  byte_1BC38C = a3;
  v3 = (a3 << 8) + 4;
  result = sub_110D3C(a1, v3);
  dword_1845E8 = (int)result;
  if ( !result )
    sub_126487(aNotEnoughSpace_0, v3);
  for ( i = 0; i < 256; ++i )
  {
    v5 = (uint8_t)byte_1BB35A[4 * i];
    sub_132137(byte_1BB359[4 * i], v5, byte_1BB35B[4 * i], &v12, &v11, &v10);
    for ( j = 0; v13 > j; ++j )
    {
      if ( *(char *)(j + a2) < 0 || *(char *)(j + a2) > 100 )
        sub_126487(aBrightenPerecn, v5);
      v9 = v11 * 10 * *(char *)(j + a2) / 1000 + v11;
      if ( v9 > 1000 )
        v9 = 1000;
      sub_13234E(v12, v9, v10, v14, v15, v16);
      v5 = sub_1338C9(v14[0], v15[0], v16[0]);
      *(_BYTE *)(dword_1845E8 + i + (j << 8)) = v5;
    }
    sub_1131F0(v13, v5);
    result = (_DWORD *)i;
  }
  return result;
}
// 1845E8: using guessed type int dword_1845E8;
// 1BC38C: using guessed type char byte_1BC38C;


//----- (0012EB23) --------------------------------------------------------
char __fastcall sub_12EB23(int a1, int a2, _WORD *a3, int *a4, unsigned int a5)
{
  int v5; // eax
  int v8; // [esp+18h] [ebp-5Ch]
  int v9; // [esp+24h] [ebp-50h]
  int v10; // [esp+3Ch] [ebp-38h]
  int v11; // [esp+40h] [ebp-34h]
  int v12; // [esp+44h] [ebp-30h]
  int v13; // [esp+44h] [ebp-30h]
  int v14; // [esp+48h] [ebp-2Ch]
  char *v15; // [esp+4Ch] [ebp-28h]
  int v16; // [esp+50h] [ebp-24h]
  int v17; // [esp+54h] [ebp-20h]
  char *v18; // [esp+58h] [ebp-1Ch]
  char *v19; // [esp+60h] [ebp-14h]
  char *v20; // [esp+60h] [ebp-14h]
  char *v21; // [esp+68h] [ebp-Ch]
  int16_t v22; // [esp+6Ch] [ebp-8h]
  int16_t v23; // [esp+70h] [ebp-4h]

  dword_1BC358 = a5;
  dword_1BC2A8 = (int)a4;
  v10 = *(int16_t *)a4;
  v11 = *a4 >> 16;
  v19 = (char *)a4 + a4[(*(int *)((char *)a4 + 2) >> 16) + 3];
  if ( a1 >= 0 || (v5 = -a1, -a1 < v10) )
  {
    if ( a2 >= 0 || (v5 = -a2, -a2 < v11) )
    {
      v15 = (char *)a4 + a4[(*(int *)((char *)a4 + 2) >> 16) + 3];
      if ( a1 >= 0 && a2 >= 0 )
      {
        v18 = (char *)a4 + a4[(*(int *)((char *)a4 + 2) >> 16) + 3];
      }
      else if ( a1 >= 0 )
      {
        v18 = &v19[v10 * -a2];
      }
      else
      {
        v18 = a2 >= 0 ? &v19[-a1] : &v19[v10 * -a2 - a1];
      }
      dword_1BC2A8 = (int)a3;
      v23 = *a3;
      LOWORD(v5) = a3[1];
      v22 = v5;
      v20 = (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6];
      if ( (int16_t)v5 >= a2 )
      {
        LOBYTE(v5) = *a3;
        if ( v23 >= a1 )
        {
          if ( a1 < 0 && a2 < 0 )
          {
            v21 = (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6];
          }
          else if ( a1 < 0 )
          {
            v21 = &v20[a2 * v23];
          }
          else if ( a2 < 0 )
          {
            v21 = &v20[a1];
          }
          else
          {
            v21 = &v20[a1 + a2 * v23];
          }
          if ( a1 >= 0 )
            v12 = 0;
          else
            v12 = -a1;
          if ( v10 + a1 > v23 )
            v12 += v10 + a1 - v23;
          v9 = v12;
          if ( a1 < 0 )
            v13 = 0;
          else
            v13 = a1;
          if ( v10 + a1 < v23 )
            v13 += v23 - a1 - v10;
          if ( a1 >= 0 )
            v14 = a1;
          else
            v14 = 0;
          if ( v10 + a1 >= v23 )
            v16 = v23;
          else
            v16 = v10 + a1;
          if ( a2 >= 0 )
            v8 = a2;
          else
            v8 = 0;
          if ( v10 + a2 >= v22 )
            v17 = v22;
          else
            v17 = v11 + a2;
          if ( v18 < v15 )
            v18 = v15;
          if ( v21 < (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6] )
            v21 = (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6];
          LOBYTE(v5) = sub_147F7B(v18, v9, v13, v21, v16 - v14, v17 - v8);
        }
      }
    }
  }
  return v5;
}
// 12EB23: could not find valid save-restore pair for ebx
// 1BC2A8: using guessed type int dword_1BC2A8;
// 1BC358: using guessed type int dword_1BC358;


//----- (0012EEE7) --------------------------------------------------------
int __fastcall sub_12EEE7(int16_t *a1, int16_t *a2, int a3, int a4)
{
  int v6; // [esp+Ch] [ebp-20h]
  int v7; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h]
  int16_t v9; // [esp+24h] [ebp-8h]
  int16_t v10; // [esp+28h] [ebp-4h]

  v8 = sub_12484C();
  dword_1BC2A8 = (int)a2;
  v9 = *a2;
  v10 = a2[1];
  v6 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  if ( a2 == a1 )
  {
    v7 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
  }
  else
  {
    sub_12D943(v9, v10, a1);
    v7 = (int)(a1 + 8);
    sub_12E0B2((int)a1, a2);
  }
  sub_147E9F(v6, a4, a3, v7, v9, v10);
  return sub_124820(v8);
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012EFBD) --------------------------------------------------------
char __fastcall sub_12EFBD(int a1, int a2, _WORD *a3, int *a4, int a5)
{
  int16_t v5; // ax
  int v8; // [esp+10h] [ebp-5Ch]
  int v9; // [esp+14h] [ebp-58h]
  int v10; // [esp+18h] [ebp-54h]
  int v11; // [esp+1Ch] [ebp-50h]
  int v12; // [esp+34h] [ebp-38h]
  int v13; // [esp+38h] [ebp-34h]
  int v14; // [esp+3Ch] [ebp-30h]
  int v15; // [esp+3Ch] [ebp-30h]
  int v16; // [esp+40h] [ebp-2Ch]
  char *v17; // [esp+44h] [ebp-28h]
  int v18; // [esp+48h] [ebp-24h]
  int v19; // [esp+4Ch] [ebp-20h]
  char *v20; // [esp+50h] [ebp-1Ch]
  char *v21; // [esp+58h] [ebp-14h]
  char *v22; // [esp+58h] [ebp-14h]
  char *v23; // [esp+60h] [ebp-Ch]
  int16_t v24; // [esp+64h] [ebp-8h]
  int16_t v25; // [esp+68h] [ebp-4h]

  dword_1BC2A8 = (int)a4;
  v12 = *(int16_t *)a4;
  v13 = *a4 >> 16;
  v21 = (char *)a4 + a4[(*(int *)((char *)a4 + 2) >> 16) + 3];
  v17 = v21;
  if ( a1 >= 0 && a2 >= 0 )
  {
    v20 = (char *)a4 + a4[(*(int *)((char *)a4 + 2) >> 16) + 3];
  }
  else if ( a1 >= 0 )
  {
    v20 = &v21[v12 * -a2];
  }
  else if ( a2 >= 0 )
  {
    v20 = &v21[-a1];
  }
  else
  {
    v20 = &v21[v12 * -a2 - a1];
  }
  dword_1BC2A8 = (int)a3;
  v25 = *a3;
  v5 = a3[1];
  v24 = v5;
  v22 = (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6];
  if ( v5 >= a2 )
  {
    LOBYTE(v5) = *a3;
    if ( v25 >= a1 )
    {
      if ( a1 < 0 && a2 < 0 )
      {
        v23 = (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6];
      }
      else if ( a1 < 0 )
      {
        v23 = &v22[a2 * v25];
      }
      else if ( a2 < 0 )
      {
        v23 = &v22[a1];
      }
      else
      {
        v23 = &v22[a1 + a2 * v25];
      }
      if ( a1 >= 0 )
        v14 = 0;
      else
        v14 = -a1;
      if ( v12 + a1 > v25 )
        v14 += v12 + a1 - v25;
      v11 = v14;
      if ( a1 < 0 )
        v15 = 0;
      else
        v15 = a1;
      if ( v12 + a1 < v25 )
        v15 += v25 - a1 - v12;
      if ( a1 >= 0 )
        v16 = a1;
      else
        v16 = 0;
      if ( v12 + a1 >= v25 )
        v18 = v25;
      else
        v18 = v12 + a1;
      v9 = v18 - v16;
      if ( a2 >= 0 )
        v8 = a2;
      else
        v8 = 0;
      if ( v12 + a2 >= v24 )
        v19 = v24;
      else
        v19 = v13 + a2;
      v10 = v19 - v8;
      if ( a5 == 1 )
      {
        if ( v20 < v17 )
          v20 = v17;
        if ( v23 < v22 )
          v23 = (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6];
        LOBYTE(v5) = sub_147FDF(v20, v11, v15, v23, v9, v10);
      }
      else
      {
        if ( v20 < v17 )
          v20 = v17;
        if ( v23 < v22 )
          v23 = (char *)a3 + *(_DWORD *)&a3[2 * (*(int *)(a3 + 1) >> 16) + 6];
        LOBYTE(v5) = sub_147F3E(v20, v11, v15, v23, v9, v10);
      }
    }
  }
  return v5;
}
// 12EFBD: could not find valid save-restore pair for ebx
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012F2A2) --------------------------------------------------------
int __fastcall sub_12F2A2(int16_t *a1, int a2, int a3)
{
  dword_1BC2A8 = (int)a1;
  return sub_14801C(
           (int *)(dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16))),
           a2,
           a3,
           *a1,
           a1[1]);
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012F498) --------------------------------------------------------
char __fastcall sub_12F498(int16_t *a1, int a2, int a3, int a4, int a5)
{
  int i; // [esp+30h] [ebp-4Ch]
  char *v7; // [esp+4Ch] [ebp-30h]
  int16_t v8; // [esp+74h] [ebp-8h]
  int16_t v9; // [esp+78h] [ebp-4h]

  dword_1BC2A8 = (int)a1;
  v8 = *a1;
  v9 = a1[1];
  v7 = (char *)(dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16)));
  dword_1BD09C = (int)byte_1BC89C;
  sub_1380E0(a3, a5);
  for ( i = 0; i < 256; ++i )
    *(_BYTE *)(i + dword_1BD09C) = *(_BYTE *)(a4 + *(uint8_t *)(i + dword_1BD09C));
  return sub_147E61(v7, dword_1BD09C, v8, v8, v9);
}
// 1BC2A8: using guessed type int dword_1BC2A8;
// 1BD09C: using guessed type int dword_1BD09C;


//----- (0012F578) --------------------------------------------------------
int __fastcall sub_12F578(int a1, int a2)
{
  int result; // eax
  int16_t v3; // ax
  int v5; // [esp+8h] [ebp-A4h]
  int i; // [esp+28h] [ebp-84h]
  int v7; // [esp+68h] [ebp-44h]
  int v8; // [esp+70h] [ebp-3Ch]
  int v9; // [esp+74h] [ebp-38h]
  int v10; // [esp+80h] [ebp-2Ch]
  int v11; // [esp+84h] [ebp-28h]
  int v12; // [esp+8Ch] [ebp-20h]
  int16_t v13; // [esp+90h] [ebp-1Ch]
  int16_t v14; // [esp+94h] [ebp-18h]
  int v15; // [esp+A4h] [ebp-8h]
  int16_t v16; // [esp+A8h] [ebp-4h]

  dword_1BC2A8 = a2;
  v13 = *(_WORD *)a2;
  v14 = *(_WORD *)(a2 + 2);
  sub_12D8F5(*(_WORD *)a2, v14, a1);
  dword_1BC2A8 = a2;
  if ( (*(_BYTE *)(a2 + 11) & 3) == 1 )
    return (int)sub_12779E(
                  (_BYTE *)(a1 + 16),
                  (_BYTE *)(dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16))),
                  v14 * v13);
  if ( *(_BYTE *)(dword_1BC2A8 + 9) )
    v15 = *(uint8_t *)(dword_1BC2A8 + 9)
        * ((*(int *)(dword_1BC2A8 + 2) >> 16)
         / *(uint8_t *)(dword_1BC2A8 + 9));
  else
    LOWORD(v15) = 0;
  for ( i = (int16_t)v15; ; ++i )
  {
    result = *(int *)(dword_1BC2A8 + 2) >> 16;
    if ( result < i )
      break;
    v7 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * i);
    v5 = *(uint16_t *)(v7 + 2);
    v8 = v13 * v5;
    v10 = v8;
    v12 = 2;
    while ( v14 > v5 )
    {
      v16 = *(_WORD *)(v7 + 2 * v12);
      v3 = *(_WORD *)(v7 + 2 * v12 + 2);
      v12 += 2;
      if ( v16 )
      {
        v10 += v3;
        v9 = 2 * v12;
        v11 = v16 + v10;
        while ( v10 < v11 )
        {
          *(_BYTE *)(v10 + a1 + 16) = *(_BYTE *)(v9 + v7);
          ++v9;
          ++v10;
        }
        v12 += (v16 + 1) / 2;
      }
      else
      {
        v5 += v3;
        v8 += v3 * v13;
        v10 = v8;
      }
    }
  }
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012F7E6) --------------------------------------------------------
int __fastcall sub_12F7E6(int result, int a2, int16_t *a3, int16_t *a4)
{
  int16_t v4; // ax
  int16_t v5; // ax
  int v6; // [esp+4h] [ebp-F8h]
  int i; // [esp+10h] [ebp-ECh]
  int v8; // [esp+10h] [ebp-ECh]
  int v9; // [esp+10h] [ebp-ECh]
  int v10; // [esp+20h] [ebp-DCh]
  int j; // [esp+28h] [ebp-D4h]
  int v12; // [esp+34h] [ebp-C8h]
  int v13; // [esp+38h] [ebp-C4h]
  int v14; // [esp+70h] [ebp-8Ch]
  int v15; // [esp+74h] [ebp-88h]
  int v16; // [esp+78h] [ebp-84h]
  int v17; // [esp+7Ch] [ebp-80h]
  int v18; // [esp+7Ch] [ebp-80h]
  int v19; // [esp+80h] [ebp-7Ch]
  int v20; // [esp+88h] [ebp-74h]
  int v21; // [esp+88h] [ebp-74h]
  int v22; // [esp+94h] [ebp-68h]
  int v23; // [esp+94h] [ebp-68h]
  int v24; // [esp+98h] [ebp-64h]
  int v25; // [esp+A0h] [ebp-5Ch]
  int v26; // [esp+A8h] [ebp-54h]
  int16_t v27; // [esp+B8h] [ebp-44h]
  int v28; // [esp+BCh] [ebp-40h]
  int16_t v29; // [esp+D0h] [ebp-2Ch]
  int16_t v30; // [esp+D4h] [ebp-28h]
  int16_t v31; // [esp+D8h] [ebp-24h]
  int v32; // [esp+E8h] [ebp-14h]
  int v33; // [esp+ECh] [ebp-10h]
  int16_t v34; // [esp+F0h] [ebp-Ch]
  int16_t v35; // [esp+F4h] [ebp-8h]
  int16_t v36; // [esp+F8h] [ebp-4h]

  v28 = result;
  dword_1BC2A8 = (int)a4;
  v12 = *a4;
  v13 = *(int *)a4 >> 16;
  if ( (*((_BYTE *)a4 + 11) & 3) != 1 )
    sub_126487(aAddPictureToBi, a2);
  dword_1BC2A8 = (int)a3;
  v27 = *a3;
  v29 = *a3 + result - 1;
  v30 = a3[1] + a2 - 1;
  result = (int16_t)result;
  if ( (int16_t)v28 < v12 )
  {
    result = (int16_t)a2;
    if ( (int16_t)a2 < v13 && v29 >= 0 && v30 >= 0 )
    {
      v16 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
      if ( (v28 & 0x8000u) != 0 )
      {
        v32 = -v28;
        v10 = 0;
      }
      else
      {
        LOWORD(v32) = 0;
        v10 = (int16_t)v28;
      }
      if ( (a2 & 0x8000u) != 0 )
      {
        v33 = -a2;
        v34 = 0;
      }
      else
      {
        LOWORD(v33) = 0;
        v34 = a2;
      }
      if ( v29 >= v12 - 1 )
        v35 = v12 - v10;
      else
        v35 = *a3 + v28 - v10;
      if ( v30 >= v13 - 1 )
        v36 = v13 - v34;
      else
        v36 = a3[1] + a2 - v34;
      if ( (*(_BYTE *)(dword_1BC2A8 + 11) & 3) == 1 )
      {
        v17 = (int16_t)v33 * v27 + (int16_t)v32;
        v22 = v12 * v34 + v10;
        for ( i = 0; ; ++i )
        {
          result = v36;
          if ( v36 <= i )
            break;
          for ( j = 0; v35 > j; ++j )
          {
            if ( *(_BYTE *)(v17 + v16) )
              *((_BYTE *)a4 + v22 + 16) = *(_BYTE *)(v17 + v16);
            ++v17;
            ++v22;
          }
          v17 += v27 - v35;
          v22 += v12 - v35;
        }
      }
      else
      {
        v6 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (*(int *)(dword_1BC2A8 + 2) >> 16));
        v8 = *(uint16_t *)(v6 + 2);
        v24 = (int16_t)v28 + v34 * v12;
        v23 = v24;
        v19 = 2;
        while ( (int16_t)v33 > v8 )
        {
          v4 = *(_WORD *)(v6 + 2 * v19);
          if ( v4 )
            v19 += (v4 + 1) / 2;
          else
            v8 += *(uint16_t *)(v6 + 2 * v19 + 2);
          v19 += 2;
        }
        if ( (int16_t)v33 < v8 )
        {
          v24 += v12 * (v8 - (int16_t)v33);
          v23 = v24;
        }
        v9 = v8 - (int16_t)v33;
        v14 = (int16_t)v32 + v24;
        v15 = v35 + (int16_t)v32 + v24;
        while ( 1 )
        {
          result = v36;
          if ( v36 <= v9 )
            break;
          v31 = *(_WORD *)(v6 + 2 * v19);
          v5 = *(_WORD *)(v6 + 2 * v19 + 2);
          v19 += 2;
          if ( v31 )
          {
            v23 += v5;
            v18 = 2 * v19;
            v20 = v31 + v23;
            if ( v23 < v15 )
            {
              if ( v23 < v14 )
              {
                v26 = v14 - v23;
                if ( v31 < v14 - v23 )
                  v26 = v31;
                v18 += v26;
                v23 += v26;
              }
              v25 = v15 - v23;
              if ( v15 >= v20 )
                v25 = v20 - v23;
              v21 = v25 + v23;
              while ( v23 < v21 )
              {
                *((_BYTE *)a4 + v23 + 16) = *(_BYTE *)(v18 + v6);
                ++v18;
                ++v23;
              }
            }
            v19 += (v31 + 1) / 2;
          }
          else
          {
            v9 += v5;
            v24 += v12 * v5;
            v23 = v24;
            v14 = (int16_t)v32 + v24;
            v15 = v35 + (int16_t)v32 + v24;
          }
        }
      }
    }
  }
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0012FDFF) --------------------------------------------------------
int __fastcall sub_12FDFF( int a1, int a2, int a3,
        int16_t *a4,
        int16_t *a5,
        int16_t *a6,
        int16_t *a7,
        int16_t *a8,
        int16_t *a9,
        int16_t *a10,
        int16_t *a11)
{
  int16_t v11; // bx
  int16_t v12; // bx
  int16_t v13; // bx
  int16_t v14; // bx
  int16_t v15; // bx
  int16_t v16; // bx
  int16_t v17; // bx
  int v18; // ebx
  int result; // eax
  int v21; // [esp+10h] [ebp-20h]
  int v22; // [esp+14h] [ebp-1Ch]
  int16_t v23; // [esp+2Ch] [ebp-4h]
  int16_t v24; // [esp+2Ch] [ebp-4h]
  int16_t v25; // [esp+2Ch] [ebp-4h]
  int16_t v26; // [esp+2Ch] [ebp-4h]

  v21 = *a4 + a2 / 2;
  v22 = *a5 + a3 / 2;
  *a6 = a2 + *a4 - 1;
  *a7 = *a5;
  *a8 = a2 + *a4 - 1;
  *a9 = a3 + *a5 - 1;
  *a10 = *a4;
  *a11 = a3 + *a5 - 1;
  v23 = *a4;
  v11 = sub_138776(a1, *a4 - (int16_t)v21) + v21;
  *a4 = v11 - sub_138615(a1, *a5 - (int16_t)v22);
  v12 = sub_138776(a1, *a5 - (int16_t)v22) + v22;
  *a5 = sub_138615(a1, v23 - (int16_t)v21) + v12;
  v24 = *a6;
  v13 = sub_138776(a1, *a6 - (int16_t)v21) + v21;
  *a6 = v13 - sub_138615(a1, *a7 - (int16_t)v22);
  v14 = sub_138776(a1, *a7 - (int16_t)v22) + v22;
  *a7 = sub_138615(a1, v24 - (int16_t)v21) + v14;
  v25 = *a8;
  v15 = sub_138776(a1, *a8 - (int16_t)v21) + v21;
  *a8 = v15 - sub_138615(a1, *a9 - (int16_t)v22);
  v16 = sub_138776(a1, *a9 - (int16_t)v22) + v22;
  *a9 = sub_138615(a1, v25 - (int16_t)v21) + v16;
  v26 = *a10;
  v17 = sub_138776(a1, *a10 - (int16_t)v21) + v21;
  *a10 = v17 - sub_138615(a1, *a11 - (int16_t)v22);
  v18 = sub_138776(a1, *a11 - (int16_t)v22) + v22;
  result = sub_138615(a1, v26 - (int16_t)v21);
  *a11 = result + v18;
  return result;
}


//----- (00130098) --------------------------------------------------------
int __fastcall sub_130098(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int16_t v6; // ax
  int v7; // [esp+0h] [ebp-88h]
  int v8; // [esp+4h] [ebp-84h]
  int v9; // [esp+8h] [ebp-80h]
  int v10; // [esp+Ch] [ebp-7Ch]
  int v11; // [esp+10h] [ebp-78h]
  int v12; // [esp+14h] [ebp-74h]
  int v13; // [esp+18h] [ebp-70h]
  int v14; // [esp+1Ch] [ebp-6Ch]
  int j; // [esp+20h] [ebp-68h] BYREF
  int i; // [esp+24h] [ebp-64h] BYREF
  int v17; // [esp+28h] [ebp-60h] BYREF
  int v18; // [esp+2Ch] [ebp-5Ch] BYREF
  int v19; // [esp+30h] [ebp-58h]
  int v20; // [esp+34h] [ebp-54h]
  int v21; // [esp+38h] [ebp-50h]
  int v22; // [esp+3Ch] [ebp-4Ch]
  int v23; // [esp+40h] [ebp-48h]
  int v24; // [esp+44h] [ebp-44h]
  int v25; // [esp+48h] [ebp-40h]
  int v26; // [esp+4Ch] [ebp-3Ch]
  int *v27; // [esp+50h] [ebp-38h]
  int v28; // [esp+54h] [ebp-34h]
  int v29; // [esp+58h] [ebp-30h]
  int v30; // [esp+5Ch] [ebp-2Ch]
  int v31; // [esp+60h] [ebp-28h]
  _BYTE *v32; // [esp+64h] [ebp-24h]
  int v33; // [esp+68h] [ebp-20h]
  int v34; // [esp+6Ch] [ebp-1Ch]
  int v35; // [esp+70h] [ebp-18h]
  int v36; // [esp+74h] [ebp-14h]
  int v37; // [esp+78h] [ebp-10h]
  int v38; // [esp+7Ch] [ebp-Ch]
  uint8_t v39; // [esp+80h] [ebp-8h]
  char v40; // [esp+84h] [ebp-4h]

  v38 = a1;
  v35 = a2;
  v36 = a3;
  v37 = a4;
  v11 = 639;
  v12 = 479;
  v13 = 0;
  v14 = 0;
  v33 = dword_1BB904;
  v25 = sub_134C92(
          ((int16_t)a3 - (int16_t)a1) * ((int16_t)a3 - (int16_t)a1)
        + ((int16_t)v37 - (int16_t)a2) * ((int16_t)v37 - (int16_t)a2));
  v27 = (int *)a5;
  v28 = a5 + 12;
  v34 = *(uint8_t *)(a5 + 12 + (*(int *)(a5 + 2) >> 16)) + a5;
  v40 = *(_BYTE *)(a5 + 11) & 8;
  if ( (_WORD)v38 != (_WORD)a3 || (result = v35, (_WORD)v35 != (_WORD)v37) )
  {
    v19 = ((int16_t)v36 + (int16_t)v38) / 2;
    v20 = ((int16_t)v35 + (int16_t)v37) / 2;
    v21 = v19 - *(int16_t *)v27 / 2;
    v22 = v20 - (*v27 >> 16) / 2;
    v23 = *(int16_t *)v27 / 2 + v19;
    v24 = (*v27 >> 16) / 2 + v20;
    while ( v23 - v21 >= *(int16_t *)v27 )
      --v23;
    while ( v24 - v22 >= *v27 >> 16 )
      --v24;
    v6 = sub_1384B9((int16_t)v36 - (int16_t)v38, (int16_t)v37 - (int16_t)v35);
    v31 = -v6;
    v29 = v21 - (v25 - *(int16_t *)v27) / 2;
    v30 = (v25 - *(int16_t *)v27) / 2 + v23;
    v26 = 100 * v25 / *(int16_t *)v27;
    j = v29 - v19;
    i = v22 - v20;
    sub_1387B2(-v6, &j, &i);
    j += v19;
    i += v20;
    if ( j < 639 )
      v11 = j;
    if ( i < 479 )
      v12 = i;
    if ( j > 0 )
      v13 = j;
    if ( i > 0 )
      v14 = i;
    j = v29 - v19;
    i = v24 - v20;
    sub_1387B2(v31, &j, &i);
    j += v19;
    i += v20;
    if ( j < v11 )
      v11 = j;
    if ( i < v12 )
      v12 = i;
    if ( j > v13 )
      v13 = j;
    if ( i > v14 )
      v14 = i;
    j = v30 - v19;
    i = v22 - v20;
    sub_1387B2(v31, &j, &i);
    j += v19;
    i += v20;
    if ( j < v11 )
      v11 = j;
    if ( i < v12 )
      v12 = i;
    if ( j > v13 )
      v13 = j;
    if ( i > v14 )
      v14 = i;
    j = v30 - v19;
    i = v24 - v20;
    sub_1387B2(v31, &j, &i);
    j += v19;
    i += v20;
    if ( j < v11 )
      v11 = j;
    if ( i < v12 )
      v12 = i;
    if ( j > v13 )
      v13 = j;
    if ( i > v14 )
      v14 = i;
    j = v29 - v19;
    i = v22 - v20;
    sub_1387B2(-(int16_t)v31, &j, &i);
    j += v19;
    i += v20;
    if ( j < v11 )
      v11 = j;
    if ( i < v12 )
      v12 = i;
    if ( j > v13 )
      v13 = j;
    if ( i > v14 )
      v14 = i;
    j = v29 - v19;
    i = v24 - v20;
    sub_1387B2(-(int16_t)v31, &j, &i);
    j += v19;
    i += v20;
    if ( j < v11 )
      v11 = j;
    if ( i < v12 )
      v12 = i;
    if ( j > v13 )
      v13 = j;
    if ( i > v14 )
      v14 = i;
    j = v30 - v19;
    i = v22 - v20;
    sub_1387B2(-(int16_t)v31, &j, &i);
    j += v19;
    i += v20;
    if ( j < v11 )
      v11 = j;
    if ( i < v12 )
      v12 = i;
    if ( j > v13 )
      v13 = j;
    if ( i > v14 )
      v14 = i;
    j = v30 - v19;
    i = v24 - v20;
    sub_1387B2(-(int16_t)v31, &j, &i);
    j += v19;
    i += v20;
    if ( j < v11 )
      v11 = j;
    if ( i < v12 )
      v12 = i;
    if ( j > v13 )
      v13 = j;
    if ( i > v14 )
      v14 = i;
    if ( dword_1BBA4A >> 16 >= v11 )
      v10 = dword_1BBA4A >> 16;
    else
      v10 = v11;
    if ( dword_1BBA4E >> 16 >= v12 )
      v9 = dword_1BBA4E >> 16;
    else
      v9 = v12;
    if ( *(int *)((char *)&dword_1BBA4A + 2) >> 16 <= v13 )
      v8 = *(int *)((char *)&dword_1BBA4A + 2) >> 16;
    else
      v8 = v13;
    if ( *(int *)((char *)&dword_1BBA4E + 2) >> 16 <= v14 )
      v7 = *(int *)((char *)&dword_1BBA4E + 2) >> 16;
    else
      v7 = v14;
    sub_138CEE(v10, v9, v8, v7);
    if ( v40 )
    {
      for ( i = v9; ; ++i )
      {
        result = i;
        if ( i > v7 )
          break;
        for ( j = v10; j <= v8; ++j )
        {
          v17 = j - v19;
          v18 = i - v20;
          sub_1387B2(v31, &v17, &v18);
          v17 += v19;
          v18 += v20;
          if ( v17 >= v29 && v17 <= v30 && v18 >= v22 && v18 <= v24 )
          {
            v17 = 100 * (v17 - v19) / v26 + v19;
            v39 = *(_BYTE *)(v17 + v34 + *(int16_t *)v27 * (v18 - v22) - v21);
            if ( v39 )
            {
              if ( v39 >= 0xF0u )
              {
                v32 = (_BYTE *)(v33 + 640 * i + j);
                *v32 = byte_1AB358[256 * v39 + (uint8_t)*v32];
              }
              else
              {
                *(_BYTE *)(j + v33 + 640 * i) = v39;
              }
            }
          }
        }
      }
    }
    else
    {
      for ( i = v9; ; ++i )
      {
        result = i;
        if ( i > v7 )
          break;
        for ( j = v10; j <= v8; ++j )
        {
          v17 = j - v19;
          v18 = i - v20;
          sub_1387B2(v31, &v17, &v18);
          v17 += v19;
          v18 += v20;
          if ( v17 >= v29 && v17 <= v30 && v18 >= v22 && v18 <= v24 )
          {
            v17 = 100 * (v17 - v19) / v26 + v19;
            v39 = *(_BYTE *)(v17 + v34 + *(int16_t *)v27 * (v18 - v22) - v21);
            if ( v39 )
              *(_BYTE *)(j + v33 + 640 * i) = v39;
          }
        }
      }
    }
  }
  return result;
}
// 1BB904: using guessed type int dword_1BB904;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;


//----- (001308A1) --------------------------------------------------------
int __fastcall sub_1308A1(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9, int a10, int a11)
{
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int16_t v16; // [esp+0h] [ebp-4Ch] BYREF
  _WORD v17[3]; // [esp+2h] [ebp-4Ah]
  int64_t v18; // [esp+8h] [ebp-44h] BYREF
  _WORD v19[4]; // [esp+10h] [ebp-3Ch] BYREF
  _WORD v20[4]; // [esp+18h] [ebp-34h] BYREF
  int v21; // [esp+20h] [ebp-2Ch]
  int v22; // [esp+24h] [ebp-28h]
  int v23; // [esp+28h] [ebp-24h]
  int v24; // [esp+2Ch] [ebp-20h]
  int i; // [esp+30h] [ebp-1Ch]
  int j; // [esp+34h] [ebp-18h]
  int v27; // [esp+38h] [ebp-14h]
  int v28; // [esp+3Ch] [ebp-10h]
  int v29; // [esp+40h] [ebp-Ch]
  int v30; // [esp+44h] [ebp-8h]
  int v31; // [esp+48h] [ebp-4h]

  v22 = a1;
  v23 = a2;
  v21 = a3;
  v24 = a4;
  v28 = a1;
  v30 = a1;
  if ( (int16_t)a3 < (int16_t)a1 )
    v28 = v21;
  if ( (int16_t)v21 > (int16_t)v30 )
    v30 = v21;
  if ( (int16_t)a5 < (int16_t)v28 )
    v28 = a5;
  if ( (int16_t)a5 > (int16_t)v30 )
    v30 = a5;
  if ( (int16_t)a7 < (int16_t)v28 )
    v28 = a7;
  if ( (int16_t)a7 > (int16_t)v30 )
    v30 = a7;
  v29 = v23;
  v31 = v23;
  if ( (int16_t)v24 < (int16_t)v23 )
    v29 = v24;
  if ( (int16_t)v24 > (int16_t)v31 )
    v31 = v24;
  if ( (int16_t)a6 < (int16_t)v29 )
    v29 = a6;
  if ( (int16_t)a6 > (int16_t)v31 )
    v31 = a6;
  if ( (int16_t)a8 < (int16_t)v29 )
    v29 = a8;
  if ( (int16_t)a8 > (int16_t)v31 )
    v31 = a8;
  HIWORD(v11) = HIWORD(v28);
  if ( (int16_t)v28 < SHIWORD(dword_1BBA4A) )
  {
    LOWORD(v11) = HIWORD(dword_1BBA4A);
    v28 = v11;
  }
  HIWORD(v12) = HIWORD(v30);
  if ( (int16_t)v30 > (int16_t)dword_1BBA4E )
  {
    LOWORD(v12) = dword_1BBA4E;
    v30 = v12;
  }
  HIWORD(v13) = HIWORD(v29);
  if ( (int16_t)v29 < SHIWORD(dword_1BBA4E) )
  {
    LOWORD(v13) = HIWORD(dword_1BBA4E);
    v29 = v13;
  }
  HIWORD(v14) = HIWORD(v31);
  if ( (int16_t)v31 > (int16_t)dword_1BBA52 )
  {
    LOWORD(v14) = dword_1BBA52;
    v31 = v14;
  }
  if ( dword_1BBA28 >= 2 )
    sub_138CEE((int16_t)v28, (int16_t)v29, (int16_t)v30, (int16_t)v31);
  v16 = v22;
  LOWORD(v18) = v23;
  v19[0] = 0;
  v20[0] = 0;
  v17[0] = v21;
  WORD1(v18) = v24;
  v19[1] = a11 - 1;
  v20[1] = 0;
  v17[1] = a5;
  WORD2(v18) = a6;
  v19[2] = a11 - 1;
  v20[2] = a10 - 1;
  v17[2] = a7;
  HIWORD(v18) = a8;
  v19[3] = 0;
  v20[3] = a10 - 1;
  for ( i = 0; (int16_t)i < 3; ++i )
  {
    for ( j = 0; (int16_t)j < 3; ++j )
    {
      if ( v19[(int16_t)j - 3] >= v19[(int16_t)j - 4] )
      {
        if ( v19[(int16_t)j - 3] == v19[(int16_t)j - 4] && (int16_t)v17[(int16_t)j] < v17[(int16_t)j - 1] )
        {
          sub_133111(&v19[(int16_t)j - 3], &v19[(int16_t)j - 4]);
          sub_133111(&v17[(int16_t)j], &v17[(int16_t)j - 1]);
          sub_133111(&v19[(int16_t)j + 1], &v19[(int16_t)j]);
          sub_133111(&v20[(int16_t)j + 1], &v20[(int16_t)j]);
        }
      }
      else
      {
        sub_133111(&v19[(int16_t)j - 3], &v19[(int16_t)j - 4]);
        sub_133111(&v17[(int16_t)j], &v17[(int16_t)j - 1]);
        sub_133111(&v19[(int16_t)j + 1], &v19[(int16_t)j]);
        sub_133111(&v20[(int16_t)j + 1], &v20[(int16_t)j]);
      }
    }
  }
  if ( (_WORD)v18 == WORD1(v18) )
  {
    sub_130E33(0, 2, 1, 3, v18, (int)&v16, (int)&v18, (int)v19, (int)v20);
    return sub_1311D5(SWORD2(qword_184530), dword_1BB904, HIWORD(v18) - WORD1(v18) + 1, v18, a9, a11);
  }
  else if ( WORD1(v18) == WORD2(v18) )
  {
    sub_130E33(0, 1, 0, 2, v18, (int)&v16, (int)&v18, (int)v19, (int)v20);
    v27 = *(_DWORD *)((char *)&v18 + 2) - v18 + 1;
    sub_1311D5(SWORD2(qword_184530), dword_1BB904, v27, v18, a9, a11);
    sub_130E33(1, 3, 2, 3, SWORD1(v18), (int)&v16, (int)&v18, (int)v19, (int)v20);
    return sub_1311D5(SWORD2(qword_184530), dword_1BB904, HIWORD(v18) - WORD1(v18) + 1, SWORD1(v18), a9, a11);
  }
  else
  {
    sub_130E33(0, 1, 0, 2, v18, (int)&v16, (int)&v18, (int)v19, (int)v20);
    v27 = *(_DWORD *)((char *)&v18 + 2) - v18 + 1;
    sub_1311D5(SWORD2(qword_184530), dword_1BB904, v27, v18, a9, a11);
    sub_130E33(1, 3, 0, 2, SWORD1(v18), (int)&v16, (int)&v18, (int)v19, (int)v20);
    v27 = HIDWORD(v18) - *(_DWORD *)((char *)&v18 + 2) + 1;
    sub_1311D5(SWORD2(qword_184530), dword_1BB904, v27, SWORD1(v18), a9, a11);
    sub_130E33(1, 3, 2, 3, SWORD2(v18), (int)&v16, (int)&v18, (int)v19, (int)v20);
    return sub_1311D5(SWORD2(qword_184530), dword_1BB904, HIWORD(v18) - WORD2(v18) + 1, SWORD2(v18), a9, a11);
  }
}
// 184530: using guessed type int64_t qword_184530;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (00130E33) --------------------------------------------------------
int __fastcall sub_130E33(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // eax
  int result; // eax
  int v11; // [esp+4h] [ebp-18h]
  int v12; // [esp+8h] [ebp-14h]
  int v13; // [esp+Ch] [ebp-10h] BYREF
  int v14; // [esp+10h] [ebp-Ch] BYREF
  int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h] BYREF

  v16 = a1;
  v14 = a2;
  v15 = a3;
  v13 = a4;
  if ( (_WORD)a1 == (_WORD)a3 )
  {
    if ( *(_WORD *)(a6 + 2 * (int16_t)v13) < *(_WORD *)(a6 + 2 * (int16_t)v14) )
    {
      sub_133111((int16_t *)&v16, (int16_t *)&v15);
      sub_133111((int16_t *)&v14, (int16_t *)&v13);
    }
  }
  else if ( *(_WORD *)(a6 + 2 * (int16_t)v15) < *(_WORD *)(a6 + 2 * (int16_t)v16) )
  {
    sub_133111((int16_t *)&v16, (int16_t *)&v15);
    sub_133111((int16_t *)&v14, (int16_t *)&v13);
  }
  v11 = *(int16_t *)(a7 + 2 * (int16_t)v14) - *(int16_t *)(a7 + 2 * (int16_t)v16);
  dword_1BC374 = ((*(int16_t *)(a8 + 2 * (int16_t)v14) - *(int16_t *)(a8 + 2 * (int16_t)v16)) << 16) / v11;
  dword_1BC380 = ((*(int16_t *)(2 * (int16_t)v14 + a9) - *(int16_t *)(a9 + 2 * (int16_t)v16)) << 16) / v11;
  dword_1BC378 = ((*(int16_t *)(2 * (int16_t)v14 + a6) - *(int16_t *)(a6 + 2 * (int16_t)v16)) << 16) / v11;
  if ( *(_WORD *)(a7 + 2 * (int16_t)v16) == a5 )
  {
    dword_1BC364 = *(int16_t *)(a8 + 2 * (int16_t)v16);
    dword_1BC368 = *(int16_t *)(a9 + 2 * (int16_t)v16);
    v9 = *(int16_t *)(a6 + 2 * (int16_t)v16);
  }
  else
  {
    dword_1BC364 = (dword_1BC374 * (a5 - *(int16_t *)(a7 + 2 * (int16_t)v16))
                  + (*(int16_t *)(a8 + 2 * (int16_t)v16) << 16)) >> 16;
    dword_1BC368 = (dword_1BC380 * (a5 - *(int16_t *)(a7 + 2 * (int16_t)v16))
                  + (*(int16_t *)(a9 + 2 * (int16_t)v16) << 16)) >> 16;
    v9 = ((a5 - *(int16_t *)(a7 + 2 * (int16_t)v16)) * dword_1BC378 + (*(int16_t *)(a6 + 2 * (int16_t)v16) << 16)) >> 16;
  }
  dword_1BC370 = v9;
  v12 = *(int16_t *)(a7 + 2 * (int16_t)v13) - *(int16_t *)(a7 + 2 * (int16_t)v15);
  dword_1BC360 = ((*(int16_t *)(a8 + 2 * (int16_t)v13) - *(int16_t *)(a8 + 2 * (int16_t)v15)) << 16) / v12;
  dword_1BC388 = ((*(int16_t *)(2 * (int16_t)v13 + a9) - *(int16_t *)(a9 + 2 * (int16_t)v15)) << 16) / v12;
  dword_1BC36C = ((*(int16_t *)(2 * (int16_t)v13 + a6) - *(int16_t *)(a6 + 2 * (int16_t)v15)) << 16) / v12;
  if ( *(_WORD *)(a7 + 2 * (int16_t)v15) == a5 )
  {
    dword_1BC37C = *(int16_t *)(a8 + 2 * (int16_t)v15);
    dword_1BC35C = *(int16_t *)(a9 + 2 * (int16_t)v15);
    result = *(int16_t *)(a6 + 2 * (int16_t)v15);
  }
  else
  {
    dword_1BC37C = (dword_1BC360 * (a5 - *(int16_t *)(a7 + 2 * (int16_t)v15))
                  + (*(int16_t *)(a8 + 2 * (int16_t)v15) << 16)) >> 16;
    dword_1BC35C = (dword_1BC388 * (a5 - *(int16_t *)(a7 + 2 * (int16_t)v15))
                  + (*(int16_t *)(a9 + 2 * (int16_t)v15) << 16)) >> 16;
    result = ((a5 - *(int16_t *)(a7 + 2 * (int16_t)v15)) * dword_1BC36C + (*(int16_t *)(a6 + 2 * (int16_t)v15) << 16)) >> 16;
  }
  dword_1BC384 = result;
  return result;
}
// 1BC35C: using guessed type int dword_1BC35C;
// 1BC360: using guessed type int dword_1BC360;
// 1BC364: using guessed type int dword_1BC364;
// 1BC368: using guessed type int dword_1BC368;
// 1BC36C: using guessed type int dword_1BC36C;
// 1BC370: using guessed type int dword_1BC370;
// 1BC374: using guessed type int dword_1BC374;
// 1BC378: using guessed type int dword_1BC378;
// 1BC37C: using guessed type int dword_1BC37C;
// 1BC380: using guessed type int dword_1BC380;
// 1BC384: using guessed type int dword_1BC384;
// 1BC388: using guessed type int dword_1BC388;


//----- (001311D5) --------------------------------------------------------
int __fastcall sub_1311D5( int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int v7; // [esp+0h] [ebp-5Ch]
  int v8; // [esp+0h] [ebp-5Ch]
  int v9; // [esp+8h] [ebp-54h]
  int v10; // [esp+8h] [ebp-54h]
  int v11; // [esp+8h] [ebp-54h]
  int v12; // [esp+Ch] [ebp-50h]
  int v13; // [esp+Ch] [ebp-50h]
  int v14; // [esp+10h] [ebp-4Ch]
  int v15; // [esp+14h] [ebp-48h]
  int v16; // [esp+18h] [ebp-44h]
  int v17; // [esp+24h] [ebp-38h]
  int v18; // [esp+24h] [ebp-38h]
  int v19; // [esp+28h] [ebp-34h]
  int v20; // [esp+2Ch] [ebp-30h]
  int v21; // [esp+30h] [ebp-2Ch]
  int v22; // [esp+38h] [ebp-24h]
  int16_t v23; // [esp+3Ch] [ebp-20h]
  int j; // [esp+44h] [ebp-18h]
  int i; // [esp+44h] [ebp-18h]
  int16_t v27; // [esp+4Ch] [ebp-10h]
  int16_t v28; // [esp+4Ch] [ebp-10h]
  int16_t v29; // [esp+4Ch] [ebp-10h]
  int16_t v30; // [esp+54h] [ebp-8h]
  int16_t v31; // [esp+58h] [ebp-4h]

  v23 = a3;
  v9 = a4 * a1 + dword_1BC370;
  v20 = 0;
  v21 = (dword_1BC384 - dword_1BC370) << 16;
  v14 = dword_1BC364 << 16;
  v19 = dword_1BC368 << 16;
  v15 = (dword_1BC37C << 16) + 32000;
  v16 = (dword_1BC35C << 16) + 32000;
  if ( word_1845D8 )
  {
    if ( a4 >= SHIWORD(dword_1BBA4E) )
      v31 = 0;
    else
      v31 = HIWORD(dword_1BBA4E) - a4;
    if ( a3 + a4 > *(int *)((char *)&dword_1BBA4E + 2) >> 16 )
      v23 = dword_1BBA52 - a4;
    for ( i = 0; ; ++i )
    {
      result = i;
      if ( (int16_t)i >= v23 )
        break;
      v13 = v9;
      v11 = (v20 >> 16) + v9;
      v28 = ((unsigned int)(v21 - v20) >> 16) + 1;
      if ( (int16_t)i >= v31 )
      {
        v22 = (v20 + (dword_1BC370 << 16)) >> 16;
        if ( (int16_t)((unsigned int)(v20 + (dword_1BC370 << 16)) >> 16) >= SHIWORD(dword_1BBA4A) )
          v30 = 0;
        else
          v30 = HIWORD(dword_1BBA4A) - v22;
        if ( v28 == 1 )
        {
          v18 = 0;
          v8 = 0;
        }
        else
        {
          v18 = (v15 - v14) / (v28 - 1);
          v8 = (v16 - v19) / (v28 - 1);
        }
        if ( v28 + (int16_t)v22 > *(int *)((char *)&dword_1BBA4A + 2) >> 16 )
          v28 = dword_1BBA4E - v22;
        v29 = v28 - v30;
        if ( v29 > 0 )
          sub_13165C(v29, a6, v30 * v18 + v14, v30 * v8 + v19, v15, v16, v11 + v30, a2, a5, v18, v8);
      }
      v20 += dword_1BC378;
      v21 += dword_1BC36C;
      v14 += dword_1BC374;
      v15 += dword_1BC360;
      v19 += dword_1BC380;
      v16 += dword_1BC388;
      v9 = a1 + v13;
    }
  }
  else
  {
    for ( j = 0; ; ++j )
    {
      result = j;
      if ( (int16_t)j >= a3 )
        break;
      v12 = v9;
      v10 = (v20 >> 16) + v9;
      v27 = ((unsigned int)(v21 - v20) >> 16) + 1;
      if ( v27 == 1 )
      {
        v17 = 0;
        v7 = 0;
      }
      else
      {
        v17 = (v15 - v14) / (v27 - 1);
        v7 = (v16 - v19) / (v27 - 1);
      }
      sub_13165C(v27, a6, v14, v19, v15, v16, v10, a2, a5, v17, v7);
      v20 += dword_1BC378;
      v21 += dword_1BC36C;
      v14 += dword_1BC374;
      v15 += dword_1BC360;
      v19 += dword_1BC380;
      v16 += dword_1BC388;
      v9 = a1 + v12;
    }
  }
  return result;
}
// 1845D8: using guessed type int16_t word_1845D8;
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;
// 1BC35C: using guessed type int dword_1BC35C;
// 1BC360: using guessed type int dword_1BC360;
// 1BC364: using guessed type int dword_1BC364;
// 1BC368: using guessed type int dword_1BC368;
// 1BC36C: using guessed type int dword_1BC36C;
// 1BC370: using guessed type int dword_1BC370;
// 1BC374: using guessed type int dword_1BC374;
// 1BC378: using guessed type int dword_1BC378;
// 1BC37C: using guessed type int dword_1BC37C;
// 1BC380: using guessed type int dword_1BC380;
// 1BC384: using guessed type int dword_1BC384;
// 1BC388: using guessed type int dword_1BC388;


//----- (00131528) --------------------------------------------------------
_WORD *__fastcall sub_131528(_WORD *a1, int16_t *a2, int16_t *a3, _WORD *a4, _WORD *a5)
{
  _WORD *result; // eax
  int16_t v6; // [esp+18h] [ebp-1Ch]
  int16_t v7; // [esp+1Ch] [ebp-18h]
  int16_t v8; // [esp+20h] [ebp-14h]
  int16_t j; // [esp+24h] [ebp-10h]
  int16_t i; // [esp+28h] [ebp-Ch]
  int16_t v11; // [esp+2Ch] [ebp-8h]
  int16_t v12; // [esp+30h] [ebp-4h]

  dword_1BC2A8 = (int)a1;
  v6 = *a1;
  v12 = a1[1];
  *a2 = 1000;
  *a3 = 1000;
  v8 = 0;
  v7 = 0;
  v11 = 0;
  for ( i = 0; i < v12; ++i )
  {
    for ( j = 0; j < v6; ++j )
    {
      if ( *((_BYTE *)a1 + v11 + 16) )
      {
        if ( j < *a2 )
          *a2 = j;
        if ( i < *a3 )
          *a3 = i;
        if ( v8 < j )
          v8 = j;
        if ( v7 < i )
          v7 = i;
      }
      ++v11;
    }
  }
  *a5 = v7 - *a3 + 1;
  result = a4;
  *a4 = v8 - *a2 + 1;
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0013165C) --------------------------------------------------------
void __fastcall sub_13165C( int a1, int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  unsigned int v11; // [esp+8h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-14h]
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+44h] [ebp+24h]

  if ( a10 < 0 )
    v11 = (unsigned int)sub_10000 - (uint16_t)a3;
  else
    v11 = (uint16_t)a3;
  if ( a11 < 0 )
    v13 = (unsigned int)sub_10000 - (uint16_t)a4;
  else
    v13 = (uint16_t)a4;
  v12 = (a4 >> 16) * a2 + (a3 >> 16);
  if ( a10 >= 0 )
  {
    if ( a11 >= 0 )
      sub_148086(v13, v11, (_BYTE *)(v12 + a9), a1, a10, a11, (_BYTE *)(a7 + a8), a2);
    else
      sub_14810A(v13, v11, (_BYTE *)(v12 + a9), a1, a10, -a11, (_BYTE *)(a7 + a8), a2);
  }
  else
  {
    v14 = -a10;
    if ( a11 >= 0 )
      sub_1480C8(v13, v11, (_BYTE *)(v12 + a9), a1, v14, a11, (_BYTE *)(a7 + a8), a2);
    else
      sub_14814C(v13, v11, (_BYTE *)(v12 + a9), a1, v14, -a11, (_BYTE *)(a7 + a8), a2);
  }
}
// 10000: using guessed type void __noreturn sub_10000();


//----- (001318D4) --------------------------------------------------------
int __fastcall sub_1318D4( int a1, int a2)
{
  int result; // eax
  int i; // [esp+0h] [ebp-Ch]

  for ( i = a1; ; ++i )
  {
    result = a2;
    if ( a2 < i )
      break;
    byte_1BB358[4 * i] = 1;
  }
  return result;
}


//----- (00131922) --------------------------------------------------------
int __fastcall sub_131922( int a1, int a2)
{
  int result; // eax
  int i; // [esp+0h] [ebp-Ch]

  for ( i = a1; ; ++i )
  {
    result = a2;
    if ( a2 < i )
      break;
    byte_1BB358[4 * i] = 0;
  }
  return result;
}


//----- (00131970) --------------------------------------------------------
void *sub_131970()
{
  return sub_1276AE(&unk_1BC390, byte_1BB358, 0x400u);
}


//----- (001319A3) --------------------------------------------------------
int sub_1319A3()
{
  sub_1276AE(byte_1BB358, &unk_1BC390, 0x400u);
  return sub_1318D4(0, 255);
}


//----- (001319E4) --------------------------------------------------------
int __fastcall sub_1319E4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // eax
  int i; // [esp+14h] [ebp-14h]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= a2 )
      break;
    byte_1BB358[4 * a1 + 4 * i] = 1;
    byte_1BB359[4 * a1 + 4 * i] = i * (a6 - a3) / (a2 - 1) + a3;
    byte_1BB35A[4 * a1 + 4 * i] = i * (a7 - a4) / (a2 - 1) + a4;
    byte_1BB35B[4 * a1 + 4 * i] = i * (a8 - a5) / (a2 - 1) + a5;
  }
  return result;
}


//----- (00131ACB) --------------------------------------------------------
char __fastcall sub_131ACB( int a1, int a2, int a3, int a4, int a5)
{
  int v5; // edx
  char result; // al

  byte_1BA318[4 * a1] = a5;
  byte_1BA319[4 * a1] = a2;
  byte_1BA31B[4 * a1] = a4;
  v5 = 4 * a1;
  result = a3;
  byte_1BA31A[v5] = a3;
  return result;
}


//----- (00131B34) --------------------------------------------------------
void sub_131B34()
{
  dword_1845EC = -1;
}
// 1845EC: using guessed type int dword_1845EC;


//----- (00131B5D) --------------------------------------------------------
char __fastcall sub_131B5D(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  char result; // al
  unsigned int v9; // [esp+0h] [ebp-2Ch]
  int v10; // [esp+4h] [ebp-28h]
  int v11; // [esp+8h] [ebp-24h]
  int v12; // [esp+Ch] [ebp-20h]
  int v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h] BYREF
  int v17; // [esp+20h] [ebp-Ch] BYREF
  int v18; // [esp+24h] [ebp-8h] BYREF
  int v19; // [esp+28h] [ebp-4h]

  v19 = a1;
  v16 = a2;
  v18 = a3;
  v17 = a4;
  v10 = a5 - (int16_t)a2;
  v11 = a6 - (int16_t)a3;
  v15 = a7 - (int16_t)a4;
  if ( v10 < 0 )
    v10 = (int16_t)a2 - a5;
  if ( v11 < 0 )
    v11 = (int16_t)a3 - a6;
  if ( v15 < 0 )
    v15 = (int16_t)a4 - a7;
  dword_1BC794 = a8;
  v9 = 2;
  if ( v10 >= v11 && v10 >= v15 )
  {
    v9 = 0;
  }
  else if ( v11 >= v10 && v11 >= v15 )
  {
    v9 = 1;
  }
  if ( dword_1845EC == -1 )
  {
    dword_1845EC = 0;
    if ( v9 )
    {
      if ( v9 <= 1 )
        dword_1BC790 = (int16_t)v18;
      else
        dword_1BC790 = (int16_t)v17;
    }
    else
    {
      dword_1BC790 = (int16_t)v16;
    }
  }
  if ( v9 )
  {
    if ( v9 <= 1 )
    {
      LOBYTE(v14) = dword_1BC790;
      v12 = (int16_t)v16 + (a5 - (int16_t)v16) * (dword_1BC790 - (int16_t)v18) / (a6 - (int16_t)v18);
      v13 = (int16_t)v17 + (a7 - (int16_t)v17) * (dword_1BC790 - (int16_t)v18) / (a6 - (int16_t)v18);
    }
    else
    {
      LOBYTE(v13) = dword_1BC790;
      v14 = (int16_t)v18 + (a6 - (int16_t)v18) * (dword_1BC790 - (int16_t)v17) / (a7 - (int16_t)v17);
      v12 = (int16_t)v16 + (a5 - (int16_t)v16) * (dword_1BC790 - (int16_t)v17) / (a7 - (int16_t)v17);
    }
  }
  else
  {
    LOBYTE(v12) = dword_1BC790;
    v14 = (int16_t)v18 + (a6 - (int16_t)v18) * (dword_1BC790 - (int16_t)v16) / (a5 - (int16_t)v16);
    v13 = (int16_t)v17 + (a7 - (int16_t)v17) * (dword_1BC790 - (int16_t)v16) / (a5 - (int16_t)v16);
  }
  if ( v9 )
  {
    if ( v9 <= 1 )
      sub_131E6B((int16_t *)&v18, &a6);
    else
      sub_131E6B((int16_t *)&v17, &a7);
  }
  else
  {
    sub_131E6B((int16_t *)&v16, &a5);
  }
  sub_132F27(v19, (uint8_t)v12, (uint8_t)v14, (uint8_t)v13);
  byte_1BB359[4 * (int16_t)v19] = v12;
  byte_1BB35A[4 * (int16_t)v19] = v14;
  result = v13;
  byte_1BB35B[4 * (int16_t)v19] = v13;
  return result;
}
// 131C27: conditional instruction was optimized away because %var_2C.4==2
// 131C64: conditional instruction was optimized away because %var_2C.4==2
// 131DEC: conditional instruction was optimized away because %var_2C.4==2
// 1845EC: using guessed type int dword_1845EC;
// 1BC790: using guessed type int dword_1BC790;
// 1BC794: using guessed type int dword_1BC794;


//----- (00131E6B) --------------------------------------------------------
int __fastcall sub_131E6B(int16_t *a1, int16_t *a2)
{
  int result; // eax

  if ( dword_1845EC )
  {
    if ( *a2 <= *a1 )
    {
      dword_1BC790 += dword_1BC794;
      result = *a2;
      if ( result < dword_1BC790 )
      {
        result = *a2 - 1;
        dword_1BC790 = result;
        dword_1845EC = 0;
      }
    }
    else
    {
      dword_1BC790 -= dword_1BC794;
      result = *a1;
      if ( result > dword_1BC790 )
      {
        result = *a1 + 1;
        dword_1BC790 = result;
        dword_1845EC = 0;
      }
    }
  }
  else if ( *a2 <= *a1 )
  {
    dword_1BC790 -= dword_1BC794;
    result = *a1;
    if ( result > dword_1BC790 )
    {
      result = *a1 + 1;
      dword_1BC790 = result;
      dword_1845EC = 1;
    }
  }
  else
  {
    dword_1BC790 += dword_1BC794;
    result = *a2;
    if ( result < dword_1BC790 )
    {
      result = *a2 - 1;
      dword_1BC790 = result;
      dword_1845EC = 1;
    }
  }
  return result;
}
// 1845EC: using guessed type int dword_1845EC;
// 1BC790: using guessed type int dword_1BC790;
// 1BC794: using guessed type int dword_1BC794;


//----- (00131F7B) --------------------------------------------------------
int sub_131F7B()
{
  int64_t v1; // [esp+0h] [ebp-1Ch]
  int v2; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]

  HIDWORD(v1) = 0;
  while ( SHIDWORD(v1) < 256 )
  {
    while ( !byte_1BB358[4 * HIDWORD(v1)] && SHIDWORD(v1) < 256 )
      ++HIDWORD(v1);
    if ( SHIDWORD(v1) < 256 )
    {
      v2 = 1;
      for ( i = HIDWORD(v1) + 1; byte_1BB358[4 * i] && i < 256; ++i )
        ++v2;
      if ( v2 >= 128 )
        v2 = 128;
      sub_132B27();
      sub_132AF8(v1, SHIDWORD(v1));
      HIDWORD(v1) += v2;
    }
  }
  return sub_131922(0, 255);
}
// 132040: variable 'v1' is possibly undefined


//----- (00132065) --------------------------------------------------------
_DWORD *__fastcall sub_132065(int a1)
{
  return sub_110D3C(a1, 4160);
}


//----- (0013209C) --------------------------------------------------------
_BYTE *__fastcall sub_13209C(_BYTE *a1)
{
  sub_12779E(a1, byte_1BA358, 0x1000u);
  return sub_12779E(a1 + 4096, byte_1BA318, 0x40u);
}


//----- (001320E9) --------------------------------------------------------
_BYTE *__fastcall sub_1320E9(_BYTE *a1)
{
  sub_12779E(byte_1BA358, a1, 0x1000u);
  return sub_12779E(byte_1BA318, a1 + 4096, 0x40u);
}


//----- (00132137) --------------------------------------------------------
int __fastcall sub_132137( unsigned int a1, unsigned int a2, unsigned int a3, int *a4, int *a5, int *a6)
{
  int64_t v6; // rtt
  int result; // eax
  int v8; // [esp+0h] [ebp-38h]
  int v9; // [esp+4h] [ebp-34h]
  int v10; // [esp+8h] [ebp-30h]
  int v11; // [esp+Ch] [ebp-2Ch]
  int v12; // [esp+1Ch] [ebp-1Ch]
  int v13; // [esp+20h] [ebp-18h]
  int v14; // [esp+24h] [ebp-14h]
  int v15; // [esp+28h] [ebp-10h]

  LODWORD(v6) = 1000 * a1;
  HIDWORD(v6) = a1 / 0x20C49Cu;
  v12 = v6 / 63;
  LODWORD(v6) = 1000 * a2;
  HIDWORD(v6) = a2 / 0x20C49Cu;
  v13 = v6 / 63;
  LODWORD(v6) = 1000 * a3;
  HIDWORD(v6) = a3 / 0x20C49Cu;
  v14 = v6 / 63;
  if ( v12 >= v13 )
    v11 = v12;
  else
    v11 = v13;
  if ( v14 >= v11 )
    v10 = v14;
  else
    v10 = v11;
  if ( v12 <= v13 )
    v9 = v12;
  else
    v9 = v13;
  if ( v14 <= v9 )
    v8 = v14;
  else
    v8 = v9;
  *a5 = (v8 + v10) / 2;
  if ( v10 == v8 )
  {
    *a6 = 0;
    result = (int)a4;
    *a4 = -1;
  }
  else
  {
    if ( *a5 > 500 )
      *a6 = 1000 * (v10 - v8) / (2000 - v10 - v8);
    else
      *a6 = 1000 * (v10 - v8) / (v8 + v10);
    v15 = v10 - v8;
    if ( v12 == v10 )
    {
      *a4 = 1000 * (v13 - v14) / v15;
    }
    else if ( v13 == v10 )
    {
      *a4 = 1000 * (v14 - v12) / v15 + 2000;
    }
    else if ( v14 == v10 )
    {
      *a4 = 1000 * (v12 - v13) / v15 + 4000;
    }
    *a4 *= 60;
    if ( *a4 < 0 )
      *a4 += 360;
    result = *a4 / 1000;
    *a4 = result;
  }
  return result;
}


//----- (0013234E) --------------------------------------------------------
char __fastcall sub_13234E(int a1, int a2, int a3, char *a4, char *a5, char *a6)
{
  char result; // al
  char v7; // dl
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  if ( a2 > 500 )
    v9 = a3 + a2 - a3 * a2 / 1000;
  else
    v9 = a2 * (a3 + 1000) / 1000;
  v10 = 2 * a2 - v9;
  if ( a3 )
  {
    *a4 = sub_132461(v10, v9, a1 + 120);
    *a5 = sub_132461(v10, v9, a1);
    v7 = sub_132461(v10, v9, a1 - 120);
    result = (char)a6;
    *a6 = v7;
  }
  else
  {
    if ( a1 == -1 )
    {
      *a6 = 63 * a2 / 1000;
      *a5 = *a6;
      result = *a5;
    }
    else
    {
      *a6 = 0;
      *a5 = *a6;
      result = (char)a4;
    }
    *a4 = *a5;
  }
  return result;
}


//----- (00132461) --------------------------------------------------------
char __fastcall sub_132461(int a1, int a2, int a3)
{
  int v4; // [esp+8h] [ebp-14h]

  if ( a3 <= 360 )
    v4 = a3 + (a3 < 0 ? 0x168 : 0);
  else
    v4 = a3 - 360;
  if ( v4 < 60 )
    return 63 * (a1 + (a2 - a1) * (1000 * v4 / 60) / 1000) / 1000;
  if ( v4 < 180 )
    return 63 * a2 / 1000;
  if ( v4 >= 240 )
    return 63 * a1 / 1000;
  return 63 * (a1 + (a2 - a1) * (1000 * (240 - v4) / 60) / 1000) / 1000;
}


//----- (0013259F) --------------------------------------------------------
int __stdcall sub_13259F(int a1)
{
  int v2; // [esp+0h] [ebp-10h]
  uint8_t v4; // [esp+Ch] [ebp-4h]

  if ( !a1 )
    return 0;
  if ( a1 == -1 )
    v2 = 0;
  else
    v2 = nmalloc(a1 + 16);
  v4 = 16 - (v2 & 0xF);
  *(_BYTE *)(v4 + v2 - 1) = v4;
  return v4 + v2;
}
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);


//----- (00132614) --------------------------------------------------------
int __stdcall sub_132614(int a1)
{
  return nfree(a1 - *(uint8_t *)(a1 - 1));
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);


//----- (00132646) --------------------------------------------------------
_BOOL1 __fastcall sub_132646(int a1, int a2, int a3)
{
  _DWORD v4[25]; // [esp+0h] [ebp-78h] BYREF
  int v5; // [esp+64h] [ebp-14h]
  int v6; // [esp+68h] [ebp-10h]
  int v7; // [esp+6Ch] [ebp-Ch]
  char v8; // [esp+70h] [ebp-8h]

  v5 = a1;
  v8 = a2;
  v6 = a3;
  strcpy(v4, a1);
  sub_149890(0x3Cu, dword_184388);
  if ( v8 == 1 )
    v7 = 1040448;
  else
    v7 = 0;
  v7 |= v6;
  dword_1845F0 = (int)sub_14BC40(0xFFFFFFFF, v7, v4);
  if ( !dword_1845F0 )
  {
    if ( !byte_184544[0] )
      return 0;
    strcpy(v4, byte_184544);
    strcat(v4, v5);
    dword_1845F0 = (int)sub_14BC40(0xFFFFFFFF, v7, v4);
  }
  if ( dword_1845F0 && v8 == 1 )
    sub_14A1C0((void (__noreturn *)())0x8000, (void (__noreturn *)())0x8000, 1, dword_1845F0);
  return dword_1845F0 != 0;
}
// 13F220: using guessed type int __fastcall strcat(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 184388: using guessed type int dword_184388;
// 1845F0: using guessed type int dword_1845F0;


//----- (00132762) --------------------------------------------------------
int sub_132762()
{
  if ( dword_1845F0 )
    return *(_DWORD *)(dword_1845F0 + 8);
  else
    return 0;
}
// 1845F0: using guessed type int dword_1845F0;


//----- (001327A3) --------------------------------------------------------
int sub_1327A3()
{
  if ( dword_1845F0 )
    return *(_DWORD *)(dword_1845F0 + 4);
  else
    return 0;
}
// 1845F0: using guessed type int dword_1845F0;


//----- (001327E4) --------------------------------------------------------
int sub_1327E4()
{
  if ( dword_1845F0 )
    return *(_DWORD *)(dword_1845F0 + 12);
  else
    return 0;
}
// 1845F0: using guessed type int dword_1845F0;


//----- (00132825) --------------------------------------------------------
int sub_132825()
{
  if ( dword_1845F0 )
    return *(_DWORD *)(dword_1845F0 + 880);
  else
    return 0;
}
// 1845F0: using guessed type int dword_1845F0;


//----- (00132869) --------------------------------------------------------
void __fastcall sub_132869(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-8h]

  v6 = a1;
  if ( dword_1845F0 )
  {
    do
      a1 = sub_14A090(a1, a2, a3, a4, (_DWORD *)dword_1845F0);
    while ( a1 );
    if ( *(_DWORD *)(dword_1845F0 + 104) )
      sub_132A11();
    sub_14AA40(0, dword_1BB904, *(_DWORD *)(dword_1845F0 + 8), 640, a2, v6, dword_1845F0);
    v5 = sub_14B4D0(v4, a2, a3, a4, dword_1845F0);
    while ( sub_14A2D0(v5, a2, a3, a4, 0, dword_1845F0) )
    {
      a4 = *(_DWORD *)(dword_1845F0 + 896) + *(_DWORD *)(dword_1845F0 + 888);
      a3 = *(_DWORD *)(dword_1845F0 + 892) + *(_DWORD *)(dword_1845F0 + 884);
      a2 = *(_DWORD *)(dword_1845F0 + 888);
      sub_138CEE(*(_DWORD *)(dword_1845F0 + 884), a2, a3, a4);
      v5 = dword_1845F0;
      if ( !*(_DWORD *)(dword_1845F0 + 884) )
      {
        v5 = dword_1845F0;
        if ( !*(_DWORD *)(dword_1845F0 + 888) )
        {
          v5 = dword_1845F0;
          a2 = *(_DWORD *)(dword_1845F0 + 892);
          if ( a2 == *(_DWORD *)(dword_1845F0 + 4) )
          {
            v5 = dword_1845F0;
            a2 = *(_DWORD *)(dword_1845F0 + 896);
            if ( a2 == *(_DWORD *)(dword_1845F0 + 8) )
            {
              v5 = *(_DWORD *)(dword_1845F0 + 880) + 1;
              dword_1845F4 = v5;
            }
          }
        }
      }
    }
    if ( *(_DWORD *)(dword_1845F0 + 12) - 1 != *(_DWORD *)(dword_1845F0 + 880) )
      sub_14B200(dword_1845F0);
  }
}
// 1328E0: variable 'v4' is possibly undefined
// 1845F0: using guessed type int dword_1845F0;
// 1845F4: using guessed type int dword_1845F4;
// 1BB904: using guessed type int dword_1BB904;


//----- (001329D4) --------------------------------------------------------
void sub_1329D4()
{
  if ( dword_1845F0 )
  {
    sub_14B8B0(dword_1845F0);
    dword_1845F0 = 0;
  }
}
// 1845F0: using guessed type int dword_1845F0;


//----- (00132A11) --------------------------------------------------------
int sub_132A11()
{
  int result; // eax
  char *v1; // eax
  int i; // [esp+0h] [ebp-8h]
  char *v3; // [esp+4h] [ebp-4h]

  result = dword_1845F0 + 138;
  v3 = (char *)(dword_1845F0 + 138);
  for ( i = 10; i < 246; ++i )
  {
    byte_1BB358[4 * i] = 1;
    byte_1BB359[4 * i] = *v3;
    byte_1BB35A[4 * i] = v3[1];
    v1 = v3 + 2;
    v3 += 3;
    byte_1BB35B[4 * i] = *v1;
    result = i;
  }
  return result;
}
// 1845F0: using guessed type int dword_1845F0;


//----- (00132AA4) --------------------------------------------------------
// VLNA 13: dekompilace teto funkce SELHALA ("could not find valid
// save-restore pair") a Hex-Rays vypustil telo jako "while(1);" s
// __noreturn - coz (a) byla nekonecna smycka v portu a (b) zpusobilo
// URIZNUTI zbytku volajici RunGameAndExit_113D47 (vse za volanim
// dekompiler zahodil jako nedosazitelne, vcetne volani MouseInit
// sub_123491 a normalniho navratu!).
// Skutecne telo ZISKANO Z BEZICIHO ORIGINALU (DOSBox DUMPMEM na
// runtime 0x356AA4, viz PROGRESS.md vlna 13) a disassemblovano:
//   pushal
//   ; pockej na hranu BIOS ticku (dword na 0x46C, 18.2 Hz)
//   L0: ebx = [0x46C]
//   L1: eax = [0x46C]; cmp eax,ebx; je L1
//   ; kalibrace: pocitej 255-nasobna cteni pameti behem JEDNOHO ticku
//   ebx = [0x46C]; edx = 0
//   L2: ecx = 255
//   L3: eax = [dword_1845F8]; loop L3
//       edx++; eax = [0x46C]; cmp eax,ebx; je L2
//   ; vysledek edx je v TETO verzi binarky ZAHOZEN (mov edx,1500 ho
//   ; prepise) a OBE vetve jb zapisuji totez -> jediny efekt funkce:
//   dword_1BC798 = 0
//   popal; ret            ; <- funkce se NORMALNE VRACI
// Port: cekani na BIOS tick nema smysl (MEMORY[0x46C] je stub a presne
// tady se beh zasekaval) - zustava jen skutecny efekt.
void CalibrateCpuTick_132AA4()
{
  dword_1BC798 = 0; // 0 = "pouzivej cekani na vertical retrace" (viz sub_132B27)
}
// 1BC798: using guessed type int dword_1BC798;


//----- (00132AF8) --------------------------------------------------------
int64_t __fastcall sub_132AF8(int64_t a1, int a2)
{
  unsigned int *v2; // esi
  int v4; // ebx
  uint16_t v5; // dx
  uint16_t v6; // dx
  unsigned int v7; // eax

  v2 = (unsigned int *)a1;
  v4 = HIDWORD(a1);
  hr_outbyte(0x3C6u, 0xFFu);
  v5 = 968;
  do
  {
    _disable();
    hr_outbyte(v5, v4);
    v6 = v5 + 1;
    v7 = *v2++;
    v7 >>= 8;
    hr_outbyte(v6, v7);
    v7 >>= 8;
    hr_outbyte(v6, v7);
    hr_outbyte(v6, BYTE1(v7));
    _enable();
    v5 = v6 - 1;
    ++v4;
    --a2;
  }
  while ( a2 );
  return a1;
}
// 132AF8: could not find valid save-restore pair for ebx


//----- (00132B27) --------------------------------------------------------
// Cekani na VGA vertical retrace (port 0x3DA, bit 8), pokud je zapnute
// (dword_1BC798 == 0, nastavuje CalibrateCpuTick_132AA4). VLNA 13: v
// portu zadny VGA port neni (hr_inbyte stub vracel 0 -> druha smycka by
// cekala donekonecna) - misto toho se snimek vykresli pres SDL3 a herni
// smycka se taktuje na ~70 Hz, viz PortVga_WaitVsync v port_vga.cpp.
// Puvodni telo (overeno i v ASM originalu, DUMPMEM vlna 13):
//   do v0 = in(0x3DA); while (v0 & 8);   // pockej na KONEC retrace
//   do v1 = in(0x3DA); while (!(v1 & 8)); // pockej na ZACATEK retrace
void sub_132B27()
{
  if ( !dword_1BC798 )
    PortVga_WaitVsync();
}
// 1BC798: using guessed type int dword_1BC798;


//----- (00132B41) --------------------------------------------------------
// Bezpodminecna varianta cekani na vertical retrace - viz sub_132B27
// (stejna nahrada, vlna 13).
void sub_132B41()
{
  PortVga_WaitVsync();
}


//----- (00132C80) --------------------------------------------------------
int __fastcall sub_132C80(int a1)
{
  uint16_t v1; // dx
  uint8_t *v2; // esi
  int v3; // ecx
  uint16_t v4; // dx
  uint8_t v5; // bh
  uint8_t v6; // al
  uint8_t *v7; // esi
  uint8_t v8; // al
  uint8_t v9; // al
  uint16_t v10; // dx
  int v11; // ecx
  uint16_t v12; // dx
  uint8_t v13; // bh
  uint8_t v14; // al
  uint8_t *v15; // esi
  uint8_t v16; // al
  uint8_t v17; // al
  _BYTE *v18; // edi
  int v19; // ecx

  dword_184608 = a1;
  LOWORD(dword_184608) = 100 - a1;
  hr_outbyte(0x3C6u, 0xFFu);
  sub_132B41();
  v1 = 968;
  v2 = (uint8_t *)dword_1BB880;
  v3 = 128;
  do
  {
    _disable();
    hr_outbyte(v1, 0x80 - v3);
    v4 = v1 + 1;
    v5 = dword_184608;
    LOWORD(v2) = (_WORD)v2 + 1;
    v6 = *v2;
    v7 = v2 + 1;
    hr_outbyte(v4, (uint16_t)((uint8_t)dword_184608 * v6) / 0x64u);
    v8 = *v7++;
    hr_outbyte(v4, (uint16_t)(v5 * v8) / 0x64u);
    v9 = *v7;
    v2 = v7 + 1;
    hr_outbyte(v4, (uint16_t)(v5 * v9) / 0x64u);
    _enable();
    v1 = v4 - 1;
    --v3;
  }
  while ( v3 );
  sub_132B27();
  v10 = 968;
  v11 = 128;
  do
  {
    _disable();
    hr_outbyte(v10, -(char)v11);
    v12 = v10 + 1;
    v13 = dword_184608;
    LOWORD(v2) = (_WORD)v2 + 1;
    v14 = *v2;
    v15 = v2 + 1;
    hr_outbyte(v12, (uint16_t)((uint8_t)dword_184608 * v14) / 0x64u);
    v16 = *v15++;
    hr_outbyte(v12, (uint16_t)(v13 * v16) / 0x64u);
    v17 = *v15;
    v2 = v15 + 1;
    hr_outbyte(v12, (uint16_t)(v13 * v17) / 0x64u);
    _enable();
    v10 = v12 - 1;
    --v11;
  }
  while ( v11 );
  v18 = (_BYTE *)dword_1BB880;
  v19 = 256;
  do
  {
    *v18 = 1;
    v18 += 4;
    --v19;
  }
  while ( v19 );
  return a1;
}
// 184608: using guessed type int dword_184608;
// 1BB880: using guessed type int dword_1BB880;


//----- (00132F27) --------------------------------------------------------
char __fastcall sub_132F27( int a1, int a2, int a3, int a4)
{
  char result; // al

  word_18462A = a1;
  word_184612 = a2;
  word_184616 = a3;
  word_184614 = a4;
  hr_outbyte(0x3C8u, a1);
  hr_outbyte(0x3C9u, word_184612);
  hr_outbyte(0x3C9u, word_184616);
  result = word_184614;
  hr_outbyte(0x3C9u, word_184614);
  return result;
}
// 184612: using guessed type int16_t word_184612;
// 184614: using guessed type int16_t word_184614;
// 184616: using guessed type int16_t word_184616;
// 18462A: using guessed type int16_t word_18462A;


//----- (00132F5C) --------------------------------------------------------
int __fastcall sub_132F5C(int a1)
{
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i + a1;
    if ( !*(_BYTE *)(i + a1) )
      break;
    if ( *(uint8_t *)(i + a1) >= 0x61u && *(uint8_t *)(i + a1) <= 0x7Fu )
      *(_BYTE *)(i + a1) -= 32;
  }
  return result;
}


//----- (00132FCD) --------------------------------------------------------
int __fastcall sub_132FCD(int a1)
{
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = i + a1;
    if ( !*(_BYTE *)(i + a1) )
      break;
    if ( *(uint8_t *)(i + a1) >= 0x41u && *(uint8_t *)(i + a1) <= 0x5Au )
      *(_BYTE *)(i + a1) += 32;
  }
  return result;
}


//----- (0013303E) --------------------------------------------------------
int __fastcall sub_13303E(int a1)
{
  int result; // eax
  int i; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]
  int k; // [esp+Ch] [ebp-4h]

  for ( i = 0; *(_BYTE *)(i + a1) == 32; ++i )
    ;
  strcpy(a1, i + a1);
  for ( j = 0; ; ++j )
  {
    result = j + a1;
    if ( !*(_BYTE *)(j + a1) )
      break;
  }
  for ( k = j - 1; k >= 0; --k )
  {
    result = *(uint8_t *)(k + a1);
    if ( result != 32 )
      break;
    result = k + a1;
    *(_BYTE *)(k + a1) = 0;
  }
  return result;
}
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);


//----- (001330D2) --------------------------------------------------------
int __fastcall sub_1330D2(int *a1, int *a2)
{
  int result; // eax
  int v3; // [esp+8h] [ebp-4h]

  v3 = *a1;
  *a1 = *a2;
  result = v3;
  *a2 = v3;
  return result;
}


//----- (00133111) --------------------------------------------------------
int16_t __fastcall sub_133111(int16_t *a1, int16_t *a2)
{
  int16_t result; // ax

  result = *a1;
  *a1 = *a2;
  *a2 = result;
  return result;
}


//----- (00133154) --------------------------------------------------------
char __fastcall sub_133154(char *a1, char *a2)
{
  char result; // al
  char v3; // [esp+8h] [ebp-4h]

  v3 = *a1;
  *a1 = *a2;
  result = v3;
  *a2 = v3;
  return result;
}


//----- (001331D2) --------------------------------------------------------
_BYTE *__fastcall sub_1331D2( int a1, int a2, int a3, int a4)
{
  _BYTE *result; // eax

  result = (_BYTE *)(a4 - 1);
  if ( a1 < (int)result )
    return sub_12779E((_BYTE *)(a2 + a3 * a1), (_BYTE *)(a2 + (a1 + 1) * a3), (a4 - a1 - 1) * a3);
  return result;
}


//----- (00133237) --------------------------------------------------------
char sub_133237()
{
  char result; // al
  uint64_t v1; // rax
  int i; // [esp+0h] [ebp-20h]
  int j; // [esp+4h] [ebp-1Ch]

  byte_1BA318[0] = 50;
  byte_1BA319[0] = 0;
  byte_1BA31A[0] = 0;
  byte_1BA31B[0] = 0;
  result = sub_13372A();
  for ( i = 0; i < 256; ++i )
  {
    for ( j = 0; j < 16; ++j )
    {
      if ( byte_1BA318[4 * j] && byte_1BA318[4 * j] != 100 )
      {
        v1 = __PAIR64__(
               (100 - (uint8_t)byte_1BA318[4 * j]) * (unsigned int)(uint8_t)byte_1BB35B[4 * i],
               ((uint8_t)byte_1BA318[4 * j] * (uint8_t)byte_1BA31A[4 * j]
              + (100 - (uint8_t)byte_1BA318[4 * j]) * (uint8_t)byte_1BB35A[4 * i])
             / 100);
        byte_1BA358[256 * j + i] = sub_1338C9(
                                     ((uint8_t)byte_1BA318[4 * j] * (uint8_t)byte_1BA319[4 * j]
                                    + (100 - (uint8_t)byte_1BA318[4 * j]) * (uint8_t)byte_1BB359[4 * i])
                                   / 100,
                                     v1,
                                     ((uint8_t)byte_1BA318[4 * j] * (uint8_t)byte_1BA31B[4 * j]
                                    + HIDWORD(v1))
                                   / 100);
      }
      else
      {
        if ( !byte_1BA318[4 * j] )
          byte_1BA358[256 * j + i] = i;
        if ( byte_1BA318[4 * j] == 100 )
          byte_1BA358[256 * j + i] = sub_1338C9(byte_1BA319[4 * j], byte_1BA31A[4 * j], byte_1BA31B[4 * j]);
      }
    }
    result = i;
  }
  return result;
}


//----- (0013372A) --------------------------------------------------------
char sub_13372A()
{
  char result; // al
  int i; // [esp+0h] [ebp-14h]
  int j; // [esp+0h] [ebp-14h]
  int k; // [esp+0h] [ebp-14h]
  int m; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  char v7; // [esp+10h] [ebp-4h]
  char v8; // [esp+10h] [ebp-4h]

  v5 = 0;
  while ( v5 != 255 )
  {
    v7 = 0;
    v6 = v5;
    for ( i = 0; i < v5 && v7 != 1; ++i )
    {
      if ( (uint8_t)byte_1BB359[4 * (uint8_t)byte_1BB758[i]] > (uint8_t)byte_1BB359[4 * v5] )
      {
        v6 = i;
        v7 = 1;
      }
    }
    if ( v6 == v5 )
    {
      result = v5;
      byte_1BB758[v6] = v5++;
    }
    else
    {
      for ( j = v5; j >= v6; --j )
        byte_1BB759[j] = byte_1BB758[j];
      result = v5;
      byte_1BB758[v6] = v5++;
    }
  }
  dword_1BB914[0] = (int)byte_1BB758;
  for ( k = 1; k < 64; ++k )
  {
    v8 = 0;
    for ( m = 0; m < 256 && v8 != 1; ++m )
    {
      if ( (uint8_t)byte_1BB359[4 * (uint8_t)byte_1BB758[m]] == k )
      {
        v8 = 1;
        dword_1BB914[k] = (int)&byte_1BB758[m];
      }
    }
    if ( !v8 )
      dword_1BB914[k] = dword_1BB910[k];
    result = k;
  }
  dword_1BBA14 = (int)&unk_1BB857;
  return result;
}
// 1BB910: using guessed type int dword_1BB910[];
// 1BB914: using guessed type int dword_1BB914[64];
// 1BBA14: using guessed type int dword_1BBA14;


//----- (001338C9) --------------------------------------------------------
int __fastcall sub_1338C9( unsigned int a1, unsigned int a2, unsigned int a3)
{
  int v4; // [esp+200h] [ebp-60h]
  int v5; // [esp+204h] [ebp-5Ch]
  int j; // [esp+208h] [ebp-58h]
  int v7; // [esp+214h] [ebp-4Ch]
  int v8; // [esp+218h] [ebp-48h]
  int v9; // [esp+21Ch] [ebp-44h]
  int i; // [esp+224h] [ebp-3Ch]
  int v11; // [esp+228h] [ebp-38h]
  int v12; // [esp+22Ch] [ebp-34h]
  int v13; // [esp+230h] [ebp-30h]
  int v14; // [esp+234h] [ebp-2Ch]
  int v15; // [esp+238h] [ebp-28h]
  int v16; // [esp+23Ch] [ebp-24h]

  v11 = a1;
  v8 = a1;
  v4 = a2;
  v5 = a2;
  v15 = a3;
  v13 = a3;
  for ( i = 0; i < 25; ++i )
  {
    if ( v11 <= 10 )
      v11 = 0;
    else
      v11 -= 10;
    if ( v8 >= 53 )
      v8 = 64;
    else
      v8 += 10;
    if ( v4 <= 10 )
      v4 = 0;
    else
      v4 -= 10;
    if ( v5 >= 53 )
      v5 = 63;
    else
      v5 += 10;
    if ( v15 <= 10 )
      v15 = 0;
    else
      v15 -= 10;
    if ( v13 >= 53 )
      v13 = 63;
    else
      v13 += 10;
    v14 = 13000;
    v16 = -1;
    for ( j = 0; (int16_t)(LOWORD(dword_1BB914[v8]) - LOWORD(dword_1BB914[v11])) > j; ++j )
    {
      if ( (uint8_t)byte_1BB35A[4 * *(uint8_t *)(j + dword_1BB914[v11])] >= v4
        && (uint8_t)byte_1BB35A[4 * *(uint8_t *)(j + dword_1BB914[v11])] <= v5
        && (uint8_t)byte_1BB35B[4 * *(uint8_t *)(j + dword_1BB914[v11])] >= v15
        && (uint8_t)byte_1BB35B[4 * *(uint8_t *)(j + dword_1BB914[v11])] <= v13 )
      {
        v7 = (uint8_t)byte_1BB359[4 * *(uint8_t *)(j + dword_1BB914[v11])] - a1;
        v12 = (uint8_t)byte_1BB35A[4 * *(uint8_t *)(j + dword_1BB914[v11])] - a2;
        v9 = (uint8_t)byte_1BB35B[4 * *(uint8_t *)(j + dword_1BB914[v11])] - a3;
        if ( v9 * v9 + v12 * v12 + v7 * v7 < v14 )
        {
          if ( *(_BYTE *)(j + dword_1BB914[v11]) )
          {
            v14 = v9 * v9 + v12 * v12 + v7 * v7;
            v16 = *(uint8_t *)(j + dword_1BB914[v11]);
          }
        }
      }
    }
    if ( v16 != -1 )
      return v16;
  }
  return 0;
}
// 133927: conditional instruction was optimized away because %var_8.1==0
// 1BB914: using guessed type int dword_1BB914[64];


//----- (00133BAE) --------------------------------------------------------
_BYTE *__fastcall sub_133BAE(int a1, int a2, _BYTE *a3, _BYTE *a4, _BYTE *a5)
{
  int v5; // edx
  _BYTE *result; // eax
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h]

  dword_1BC2A8 = a1;
  if ( (*(_BYTE *)(a1 + 11) & 0x10) == 0 )
    sub_126487(aGetPictureColo, a2);
  v5 = 4 * (*(int *)(dword_1BC2A8 + 4) >> 16);
  dword_1BC2A4 = v5 + dword_1BC2A8 + 16;
  v8 = *(int16_t *)(v5 + dword_1BC2A8 + 16);
  v10 = v5 + dword_1BC2A8 + 16 + 4;
  if ( v8 > a2 || (v5 = *(int *)dword_1BC2A4 >> 16, v5 + *(int16_t *)dword_1BC2A4 <= a2) )
    sub_126487(aErrorGetcolorC, v5);
  v9 = 4 * (a2 - v8);
  *a3 = *(_BYTE *)(v9 + v10 + 1);
  *a4 = *(_BYTE *)(v9 + v10 + 2);
  result = a5;
  *a5 = *(_BYTE *)(v9 + v10 + 3);
  return result;
}
// 1BC2A4: using guessed type int dword_1BC2A4;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00133C9C) --------------------------------------------------------
int __fastcall sub_133C9C(int a1, int a2)
{
  dword_1BC2A8 = a1;
  if ( (*(_BYTE *)(a1 + 11) & 0x10) == 0 )
    sub_126487(aRemappedPictur, a2);
  dword_1BC2A4 = 4 * (*(int *)(dword_1BC2A8 + 4) >> 16) + dword_1BC2A8 + 16;
  return sub_133D16(dword_1BC2A4 + 4, (int)byte_1BC79C);
}
// 1BC2A4: using guessed type int dword_1BC2A4;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (00133D16) --------------------------------------------------------
int __fastcall sub_133D16(int a1, int a2)
{
  int result; // eax
  int i; // [esp+10h] [ebp-10h]
  int j; // [esp+10h] [ebp-10h]

  sub_13372A();
  for ( i = 0; i < 256; ++i )
    *(_BYTE *)(i + a2) = i;
  for ( j = 0; ; ++j )
  {
    result = *(int *)dword_1BC2A4 >> 16;
    if ( result <= j )
      break;
    *(_BYTE *)(a2 + j + *(int16_t *)dword_1BC2A4) = sub_1338C9(
                                                      *(_BYTE *)(4 * j + a1 + 1),
                                                      *(_BYTE *)(4 * j + a1 + 2),
                                                      *(_BYTE *)(4 * j + a1 + 3));
  }
  return result;
}
// 1BC2A4: using guessed type int dword_1BC2A4;


//----- (00133DE1) --------------------------------------------------------
char __fastcall sub_133DE1( unsigned int a1)
{
  return byte_1BC79C[a1];
}


//----- (0013432D) --------------------------------------------------------
int16_t __fastcall sub_13432D(int16_t *a1, int16_t *a2, int a3, int a4, int a5)
{
  int v5; // eax
  int16_t *v7; // [esp+0h] [ebp-1Ch]
  int16_t v9; // [esp+10h] [ebp-Ch]
  int16_t v10; // [esp+14h] [ebp-8h]
  int16_t v11; // [esp+18h] [ebp-4h]

  v7 = a1;
  if ( a5 > 0 )
  {
    if ( *a1 != a3 || (LOWORD(a1) = *a2, *a2 != a4) )
    {
      v9 = a3 - *v7;
      v10 = a4 - *a2;
      v5 = abs(v9);
      if ( v5 <= 255 && (int)abs(v10) <= 255 )
        v11 = sub_1384B9(v9, v10);
      else
        v11 = sub_1384B9(v9 / 2, v10 / 2);
      if ( *v7 >= a3 )
      {
        *v7 += sub_138776(v11, a5);
        if ( *v7 < a3 )
          *v7 = a3;
      }
      else
      {
        *v7 += sub_138776(v11, a5);
        if ( *v7 > a3 )
          *v7 = a3;
      }
      if ( *a2 >= a4 )
      {
        *a2 += sub_138615(v11, a5);
        LOWORD(a1) = *a2;
        if ( *a2 < a4 )
        {
          LOWORD(a1) = a4;
          *a2 = a4;
        }
      }
      else
      {
        *a2 += sub_138615(v11, a5);
        LOWORD(a1) = *a2;
        if ( *a2 > a4 )
        {
          LOWORD(a1) = a4;
          *a2 = a4;
        }
      }
    }
  }
  return (int16_t)a1;
}
// 14D139: using guessed type int64_t __fastcall abs(_DWORD);


//----- (001344B0) --------------------------------------------------------
int16_t __fastcall sub_1344B0(int16_t *a1, int16_t *a2, int a3, int a4, int a5, int a6, int a7)
{
  int16_t *v8; // [esp+0h] [ebp-1Ch]
  int16_t v9; // [esp+10h] [ebp-Ch]
  int16_t v10; // [esp+14h] [ebp-8h]

  v8 = a1;
  if ( a7 > 0 )
  {
    if ( *a1 != a5 || (LOWORD(a1) = *a2, *a2 != a6) )
    {
      v9 = a5 - a3;
      if ( (int16_t)(a5 - a3) < 0 )
        v9 = a3 - a5;
      v10 = a6 - a4;
      if ( (int16_t)(a6 - a4) < 0 )
        v10 = a4 - a6;
      if ( v9 <= v10 )
      {
        if ( a6 <= a4 )
        {
          *a2 -= a7;
          if ( *a2 < a6 )
            *a2 = a6;
        }
        else
        {
          *a2 += a7;
          if ( *a2 > a6 )
            *a2 = a6;
        }
        LOWORD(a1) = (a5 - a3) * (*a2 - a4) / (a6 - a4) + a3;
        *v8 = (int16_t)a1;
      }
      else
      {
        if ( a5 <= a3 )
        {
          *v8 -= a7;
          if ( *v8 < a5 )
            *v8 = a5;
        }
        else
        {
          *v8 += a7;
          if ( *v8 > a5 )
            *v8 = a5;
        }
        LOWORD(a1) = (a6 - a4) * (*v8 - a3) / (a5 - a3) + a4;
        *a2 = (int16_t)a1;
      }
    }
  }
  return (int16_t)a1;
}


//----- (00134637) --------------------------------------------------------
int __fastcall sub_134637( int a1, int a2, int a3, int a4)
{
  int16_t v5; // [esp+10h] [ebp-10h]
  int16_t v6; // [esp+14h] [ebp-Ch]

  v5 = a3 - a1;
  v6 = a4 - a2;
  if ( (int16_t)(a3 - a1) < 0 )
    v5 = a1 - a3;
  if ( v6 < 0 )
    v6 = a2 - a4;
  if ( v5 <= v6 )
    return v6 + v5 / 2;
  else
    return v5 + v6 / 2;
}


//----- (00134C92) --------------------------------------------------------
int __fastcall sub_134C92(unsigned int a1)
{
  int v2; // [esp+8h] [ebp-Ch]
  int v3; // [esp+Ch] [ebp-8h]

  if ( a1 >= 0xFFFE0001 )
    return 0xFFFF;
  if ( a1 > 0xFFFF )
  {
    v2 = 256;
    v3 = 0xFFFF;
  }
  else
  {
    v2 = 0;
    v3 = 256;
  }
  do
  {
    if ( (v3 + v2) / 2 * ((v3 + v2) / 2) > a1 )
      v3 = (v3 + v2) / 2;
    else
      v2 = (v3 + v2) / 2;
  }
  while ( v2 + 1 < v3 );
  return v2;
}


//----- (00134D2D) --------------------------------------------------------
int __fastcall sub_134D2D(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  _BYTE *v6; // [esp+0h] [ebp-48h] BYREF
  int v7; // [esp+4h] [ebp-44h] BYREF
  int v8; // [esp+8h] [ebp-40h] BYREF
  int16_t v9[4]; // [esp+Ch] [ebp-3Ch] BYREF
  int v10; // [esp+14h] [ebp-34h]
  int v11; // [esp+18h] [ebp-30h]
  int v12; // [esp+1Ch] [ebp-2Ch] BYREF
  int v13; // [esp+20h] [ebp-28h]
  int v14; // [esp+24h] [ebp-24h]
  int v15; // [esp+28h] [ebp-20h]
  int v16; // [esp+2Ch] [ebp-1Ch]
  int v17; // [esp+30h] [ebp-18h]
  int v18; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  int j; // [esp+3Ch] [ebp-Ch]
  int v21; // [esp+40h] [ebp-8h]
  int v22; // [esp+44h] [ebp-4h]

  v8 = a1;
  v7 = a2;
  *(_DWORD *)v9 = a3;
  v12 = a4;
  if ( word_1845D8 != 1
    || (result = (int16_t)sub_135357((int16_t *)&v8, (int16_t *)&v7, v9, (int16_t *)&v12), (int16_t)result != 1) )
  {
    if ( (int16_t)v7 > (int16_t)v12 )
    {
      sub_133111((int16_t *)&v7, (int16_t *)&v12);
      sub_133111((int16_t *)&v8, v9);
    }
    v6 = (_BYTE *)((int16_t)v7 * HIDWORD(qword_184530) + (int16_t)v8 + dword_1BB904);
    v14 = *(_DWORD *)v9 - v8;
    if ( (int16_t)(v9[0] - v8) >= 0 )
    {
      v13 = 1;
    }
    else
    {
      v13 = -1;
      v14 = -v14;
    }
    v15 = v12 - v7;
    if ( (_WORD)v14 )
    {
      if ( (_WORD)v15 )
      {
        if ( (_WORD)v14 == (_WORD)v15 )
        {
          for ( i = 0; ; ++i )
          {
            result = i;
            if ( (int16_t)i > (int16_t)v14 )
              break;
            *v6 = a5;
            v6 += HIDWORD(qword_184530) + (int16_t)v13;
          }
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v8 >= v9[0] )
            {
              for ( i = v7; ; ++i )
              {
                result = i;
                if ( (int16_t)i > (int16_t)v12 )
                  break;
                sub_125E13((int16_t)v8 - ((int16_t)i - (int16_t)v7), (int16_t)i);
              }
            }
            else
            {
              for ( i = v7; ; ++i )
              {
                result = i;
                if ( (int16_t)i > (int16_t)v12 )
                  break;
                sub_125E13((int16_t)i - (int16_t)v7 + (int16_t)v8, (int16_t)i);
              }
            }
          }
        }
        else if ( (int16_t)v14 < (int16_t)v15 )
        {
          v16 = (int16_t)v15 / (int16_t)v14;
          v10 = 2 * ((int16_t)v15 % (int16_t)v14);
          v11 = 2 * v14;
          v22 = (int16_t)v15 % (int16_t)v14 - 2 * (int16_t)v14;
          v17 = ((int16_t)v16 >> 1) + 1;
          v18 = v17;
          if ( !(_WORD)v10 && (v16 & 1) == 0 )
            --v17;
          if ( (v16 & 1) != 0 )
            v22 += v14;
          sub_135806(&v6, v13, v17, a5);
          if ( dword_1BBA28 >= 2 )
          {
            for ( i = 0; (int16_t)i < (int16_t)v17; ++i )
              sub_125E13((int16_t)v8, (int16_t)v7 + (int16_t)i);
            v7 += v17;
            v8 += v13;
          }
          for ( i = 0; (int16_t)i < (int16_t)v14 - 1; ++i )
          {
            v21 = v16;
            v22 += v10;
            if ( (int16_t)v22 > 0 )
            {
              ++v21;
              v22 -= v11;
            }
            sub_135806(&v6, v13, v21, a5);
            if ( dword_1BBA28 >= 2 )
            {
              for ( j = 0; (int16_t)j < (int16_t)v21; ++j )
                sub_125E13((int16_t)v8, (int16_t)v7 + (int16_t)j);
              v7 += v21;
              v8 += v13;
            }
          }
          result = (int)sub_135806(&v6, v13, v18, a5);
          if ( dword_1BBA28 >= 2 )
          {
            for ( i = 0; (int16_t)i < (int16_t)v18; ++i )
              sub_125E13((int16_t)v8, (int16_t)v7 + (int16_t)i);
            v7 += v18;
            result = v13;
            v8 += v13;
          }
        }
        else
        {
          v16 = (int16_t)v14 / (int16_t)v15;
          v10 = 2 * ((int16_t)v14 % (int16_t)v15);
          v11 = 2 * v15;
          v22 = (int16_t)v14 % (int16_t)v15 - 2 * (int16_t)v15;
          v17 = ((int16_t)v16 >> 1) + 1;
          v18 = v17;
          if ( !(_WORD)v10 && (v16 & 1) == 0 )
            --v17;
          if ( (v16 & 1) != 0 )
            v22 += v15;
          sub_13579C(&v6, v13, v17, a5);
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v13 <= 0 )
            {
              sub_138CEE((int16_t)v8 - (int16_t)v17, (int16_t)v7, (int16_t)v8, (int16_t)v7);
              v8 -= v17;
            }
            else
            {
              sub_138CEE((int16_t)v8, (int16_t)v7, (int16_t)v17 + (int16_t)v8, (int16_t)v7);
              v8 += v17;
            }
            ++v7;
          }
          for ( i = 0; (int16_t)i < (int16_t)v15 - 1; ++i )
          {
            v21 = v16;
            v22 += v10;
            if ( (int16_t)v22 > 0 )
            {
              ++v21;
              v22 -= v11;
            }
            sub_13579C(&v6, v13, v21, a5);
            if ( dword_1BBA28 >= 2 )
            {
              if ( (int16_t)v13 <= 0 )
              {
                sub_138CEE((int16_t)v8 - (int16_t)v21, (int16_t)v7, (int16_t)v8, (int16_t)v7);
                v8 -= v21;
              }
              else
              {
                sub_138CEE((int16_t)v8, (int16_t)v7, (int16_t)v21 + (int16_t)v8, (int16_t)v7);
                v8 += v21;
              }
              ++v7;
            }
          }
          result = (int)sub_13579C(&v6, v13, v18, a5);
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v13 <= 0 )
              return sub_138CEE((int16_t)v8 - (int16_t)v18, (int16_t)v7, (int16_t)v8, (int16_t)v7);
            else
              return sub_138CEE((int16_t)v8, (int16_t)v7, (int16_t)v18 + (int16_t)v8, (int16_t)v7);
          }
        }
      }
      else
      {
        for ( i = 0; ; ++i )
        {
          result = i;
          if ( (int16_t)i > (int16_t)v14 )
            break;
          *v6 = a5;
          v6 += (int16_t)v13;
        }
        if ( dword_1BBA28 >= 2 )
        {
          if ( v9[0] < (int16_t)v8 )
            sub_133111((int16_t *)&v8, v9);
          return sub_138CEE((int16_t)v8, (int16_t)v7, v9[0], (int16_t)v7);
        }
      }
    }
    else
    {
      for ( i = 0; ; ++i )
      {
        result = i;
        if ( (int16_t)i > (int16_t)v15 )
          break;
        *v6 = a5;
        v6 += HIDWORD(qword_184530);
      }
      if ( dword_1BBA28 >= 2 )
      {
        for ( i = v7; ; ++i )
        {
          result = i;
          if ( (int16_t)i > (int16_t)v12 )
            break;
          sub_125E13((int16_t)v8, (int16_t)i);
        }
      }
    }
  }
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00135357) --------------------------------------------------------
int __fastcall sub_135357(int16_t *a1, int16_t *a2, int16_t *a3, int16_t *a4)
{
  int v5; // [esp+10h] [ebp-24h]
  int16_t v6; // [esp+14h] [ebp-20h]
  int16_t v7; // [esp+14h] [ebp-20h]
  int16_t v8; // [esp+14h] [ebp-20h]
  int16_t v9; // [esp+18h] [ebp-1Ch]
  int16_t v10; // [esp+18h] [ebp-1Ch]
  int16_t v11; // [esp+18h] [ebp-1Ch]
  int v12; // [esp+28h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-Ch]
  int v14; // [esp+2Ch] [ebp-8h]
  int v15; // [esp+2Ch] [ebp-8h]

  v5 = 0;
  if ( *a1 == *a3 )
  {
    if ( *a1 >= SHIWORD(dword_1BBA4A) && *a3 <= (int16_t)dword_1BBA4E )
    {
      if ( *a4 < *a2 )
      {
        v9 = *a4;
        *a4 = *a2;
        *a2 = v9;
      }
      if ( *a4 >= SHIWORD(dword_1BBA4E) && *a2 <= (int16_t)dword_1BBA52 )
      {
        if ( *a2 < SHIWORD(dword_1BBA4E) )
          *a2 = HIWORD(dword_1BBA4E);
        if ( *a4 > (int16_t)dword_1BBA52 )
          *a4 = dword_1BBA52;
      }
      else
      {
        v5 = 1;
      }
    }
    else
    {
      v5 = 1;
    }
  }
  else
  {
    if ( *a3 < *a1 )
    {
      v6 = *a3;
      *a3 = *a1;
      *a1 = v6;
      v10 = *a4;
      *a4 = *a2;
      *a2 = v10;
    }
    v14 = *a4 - *a2;
    v12 = *a3 - *a1;
    if ( *a1 < SHIWORD(dword_1BBA4A) )
    {
      *a2 += v14 * ((dword_1BBA4A >> 16) - *a1) / v12;
      *a1 = HIWORD(dword_1BBA4A);
    }
    if ( *a1 <= *a3 )
    {
      if ( *a3 > (int16_t)dword_1BBA4E )
      {
        *a4 = *a2 + v14 * ((*(int *)((char *)&dword_1BBA4A + 2) >> 16) - *a1) / v12;
        *a3 = dword_1BBA4E;
      }
      if ( *a3 < *a1 )
        v5 = 1;
    }
    else
    {
      v5 = 1;
    }
  }
  if ( *a2 == *a4 )
  {
    if ( *a2 >= SHIWORD(dword_1BBA4E) && *a4 <= (int16_t)dword_1BBA52 )
    {
      if ( *a3 < *a1 )
      {
        v7 = *a3;
        *a3 = *a1;
        *a1 = v7;
      }
      if ( *a3 >= SHIWORD(dword_1BBA4A) && *a1 <= (int16_t)dword_1BBA4E )
      {
        if ( *a1 < SHIWORD(dword_1BBA4A) )
          *a1 = HIWORD(dword_1BBA4A);
        if ( *a3 > (int16_t)dword_1BBA4E )
          *a3 = dword_1BBA4E;
      }
      else
      {
        return 1;
      }
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( *a4 < *a2 )
    {
      v11 = *a4;
      *a4 = *a2;
      *a2 = v11;
      v8 = *a3;
      *a3 = *a1;
      *a1 = v8;
    }
    v13 = *a3 - *a1;
    v15 = *a4 - *a2;
    if ( *a2 < SHIWORD(dword_1BBA4E) )
    {
      *a1 += v13 * ((dword_1BBA4E >> 16) - *a2) / v15;
      *a2 = HIWORD(dword_1BBA4E);
    }
    if ( *a2 <= *a4 )
    {
      if ( *a4 > (int16_t)dword_1BBA52 )
      {
        *a3 = *a1 + v13 * ((*(int *)((char *)&dword_1BBA4E + 2) >> 16) - *a2) / v15;
        *a4 = dword_1BBA52;
      }
      if ( *a4 < *a2 )
        return 1;
    }
    else
    {
      return 1;
    }
  }
  return v5;
}
// 1BBA4A: using guessed type int dword_1BBA4A;
// 1BBA4E: using guessed type int dword_1BBA4E;
// 1BBA52: using guessed type int dword_1BBA52;


//----- (0013579C) --------------------------------------------------------
_BYTE *__fastcall sub_13579C(_BYTE **a1, int a2, int a3, int a4)
{
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v7; // [esp+8h] [ebp-10h]

  v7 = *a1;
  for ( i = 0; a3 > i; ++i )
  {
    *v7 = a4;
    v7 += a2;
  }
  result = &v7[*(int *)((char *)&dword_184532 + 2)];
  *a1 = &v7[*(int *)((char *)&dword_184532 + 2)];
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (00135806) --------------------------------------------------------
_BYTE *__fastcall sub_135806(_BYTE **a1, int a2, int a3, int a4)
{
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v7; // [esp+8h] [ebp-10h]

  v7 = *a1;
  for ( i = 0; a3 > i; ++i )
  {
    *v7 = a4;
    v7 += *(int *)((char *)&dword_184532 + 2);
  }
  result = &v7[a2];
  *a1 = result;
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (00135870) --------------------------------------------------------
int __fastcall sub_135870(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  _BYTE *v7; // [esp+0h] [ebp-48h] BYREF
  int v8; // [esp+4h] [ebp-44h] BYREF
  int v9; // [esp+8h] [ebp-40h] BYREF
  int16_t v10[4]; // [esp+Ch] [ebp-3Ch] BYREF
  int v11; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h] BYREF
  int v13; // [esp+1Ch] [ebp-2Ch]
  int v14; // [esp+20h] [ebp-28h]
  int v15; // [esp+24h] [ebp-24h]
  int v16; // [esp+28h] [ebp-20h]
  int v17; // [esp+2Ch] [ebp-1Ch]
  int v18; // [esp+30h] [ebp-18h]
  int v19; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  int j; // [esp+3Ch] [ebp-Ch]
  int v22; // [esp+40h] [ebp-8h]
  int v23; // [esp+44h] [ebp-4h]

  v8 = a1;
  v12 = a2;
  *(_DWORD *)v10 = a3;
  v9 = a4;
  if ( word_1845D8 != 1
    || (result = (int16_t)sub_135357((int16_t *)&v8, (int16_t *)&v12, v10, (int16_t *)&v9), (int16_t)result != 1) )
  {
    if ( (int16_t)v12 > (int16_t)v9 )
    {
      sub_133111((int16_t *)&v12, (int16_t *)&v9);
      sub_133111((int16_t *)&v8, v10);
    }
    v7 = (_BYTE *)((int16_t)v12 * HIDWORD(qword_184530) + (int16_t)v8 + dword_1BB904);
    v15 = *(_DWORD *)v10 - v8;
    if ( (int16_t)(v10[0] - v8) >= 0 )
    {
      v14 = 1;
    }
    else
    {
      v14 = -1;
      v15 = -v15;
    }
    v16 = v9 - v12;
    if ( (_WORD)v15 )
    {
      if ( (_WORD)v16 )
      {
        if ( (_WORD)v15 == (_WORD)v16 )
        {
          for ( i = 0; ; ++i )
          {
            result = i;
            if ( (int16_t)i > (int16_t)v15 )
              break;
            *v7 = *(_BYTE *)(a5 + (a6++ & 7));
            v7 += HIDWORD(qword_184530) + (int16_t)v14;
          }
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v8 >= v10[0] )
            {
              for ( i = v12; ; ++i )
              {
                result = i;
                if ( (int16_t)i > (int16_t)v9 )
                  break;
                sub_125E13((int16_t)v8 - ((int16_t)i - (int16_t)v12), (int16_t)i);
              }
            }
            else
            {
              for ( i = v12; ; ++i )
              {
                result = i;
                if ( (int16_t)i > (int16_t)v9 )
                  break;
                sub_125E13((int16_t)i - (int16_t)v12 + (int16_t)v8, (int16_t)i);
              }
            }
          }
        }
        else if ( (int16_t)v15 < (int16_t)v16 )
        {
          v17 = (int16_t)v16 / (int16_t)v15;
          v11 = 2 * ((int16_t)v16 % (int16_t)v15);
          v23 = 2 * v15;
          v13 = (int16_t)v16 % (int16_t)v15 - 2 * (int16_t)v15;
          v18 = ((int16_t)v17 >> 1) + 1;
          v19 = v18;
          if ( !(_WORD)v11 && (v17 & 1) == 0 )
            --v18;
          if ( (v17 & 1) != 0 )
            v13 += v15;
          sub_135F5D(&v7, v14, v18, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            for ( i = 0; (int16_t)i < (int16_t)v18; ++i )
              sub_125E13((int16_t)v8, (int16_t)v12 + (int16_t)i);
            v12 += v18;
            v8 += v14;
          }
          for ( i = 0; (int16_t)i < (int16_t)v15 - 1; ++i )
          {
            v22 = v17;
            v13 += v11;
            if ( (int16_t)v13 > 0 )
            {
              ++v22;
              v13 -= v23;
            }
            sub_135F5D(&v7, v14, v22, a5, &a6);
            if ( dword_1BBA28 >= 2 )
            {
              for ( j = 0; (int16_t)j < (int16_t)v22; ++j )
                sub_125E13((int16_t)v8, (int16_t)v12 + (int16_t)j);
              v12 += v22;
              v8 += v14;
            }
          }
          result = (int)sub_135F5D(&v7, v14, v19, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            for ( i = 0; (int16_t)i < (int16_t)v19; ++i )
              sub_125E13((int16_t)v8, (int16_t)v12 + (int16_t)i);
            v12 += v19;
            result = v14;
            v8 += v14;
          }
        }
        else
        {
          v17 = (int16_t)v15 / (int16_t)v16;
          v11 = 2 * ((int16_t)v15 % (int16_t)v16);
          v23 = 2 * v16;
          v13 = (int16_t)v15 % (int16_t)v16 - 2 * (int16_t)v16;
          v18 = ((int16_t)v17 >> 1) + 1;
          v19 = v18;
          if ( !(_WORD)v11 && (v17 & 1) == 0 )
            --v18;
          if ( (v17 & 1) != 0 )
            v13 += v16;
          sub_135EDD(&v7, v14, v18, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v14 <= 0 )
            {
              sub_138CEE((int16_t)v8 - (int16_t)v18, (int16_t)v12, (int16_t)v8, (int16_t)v12);
              v8 -= v18;
            }
            else
            {
              sub_138CEE((int16_t)v8, (int16_t)v12, (int16_t)v18 + (int16_t)v8, (int16_t)v12);
              v8 += v18;
            }
            ++v12;
          }
          for ( i = 0; (int16_t)i < (int16_t)v16 - 1; ++i )
          {
            v22 = v17;
            v13 += v11;
            if ( (int16_t)v13 > 0 )
            {
              ++v22;
              v13 -= v23;
            }
            sub_135EDD(&v7, v14, v22, a5, &a6);
            if ( dword_1BBA28 >= 2 )
            {
              if ( (int16_t)v14 <= 0 )
              {
                sub_138CEE((int16_t)v8 - (int16_t)v22, (int16_t)v12, (int16_t)v8, (int16_t)v12);
                v8 -= v22;
              }
              else
              {
                sub_138CEE((int16_t)v8, (int16_t)v12, (int16_t)v22 + (int16_t)v8, (int16_t)v12);
                v8 += v22;
              }
              ++v12;
            }
          }
          result = (int)sub_135EDD(&v7, v14, v19, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v14 <= 0 )
              return sub_138CEE((int16_t)v8 - (int16_t)v19, (int16_t)v12, (int16_t)v8, (int16_t)v12);
            else
              return sub_138CEE((int16_t)v8, (int16_t)v12, (int16_t)v19 + (int16_t)v8, (int16_t)v12);
          }
        }
      }
      else
      {
        for ( i = 0; ; ++i )
        {
          result = i;
          if ( (int16_t)i > (int16_t)v15 )
            break;
          *v7 = *(_BYTE *)(a5 + (a6++ & 7));
          v7 += (int16_t)v14;
        }
        if ( dword_1BBA28 >= 2 )
        {
          if ( v10[0] < (int16_t)v8 )
            sub_133111((int16_t *)&v8, v10);
          return sub_138CEE((int16_t)v8, (int16_t)v12, v10[0], (int16_t)v12);
        }
      }
    }
    else
    {
      for ( i = 0; ; ++i )
      {
        result = i;
        if ( (int16_t)i > (int16_t)v16 )
          break;
        *v7 = *(_BYTE *)(a5 + (a6++ & 7));
        v7 += HIDWORD(qword_184530);
      }
      if ( dword_1BBA28 >= 2 )
      {
        for ( i = v12; ; ++i )
        {
          result = i;
          if ( (int16_t)i > (int16_t)v9 )
            break;
          sub_125E13((int16_t)v8, (int16_t)i);
        }
      }
    }
  }
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00135EDD) --------------------------------------------------------
_BYTE *__fastcall sub_135EDD(_BYTE **a1, int a2, int a3, int a4, _WORD *a5)
{
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v8; // [esp+Ch] [ebp-Ch]

  v8 = *a1;
  for ( i = 0; a3 > i; ++i )
  {
    *v8 = *(_BYTE *)(a4 + ((*a5)++ & 7));
    v8 += a2;
  }
  result = &v8[*(int *)((char *)&dword_184532 + 2)];
  *a1 = &v8[*(int *)((char *)&dword_184532 + 2)];
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (00135F5D) --------------------------------------------------------
_BYTE *__fastcall sub_135F5D(_BYTE **a1, int a2, int a3, int a4, _WORD *a5)
{
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v8; // [esp+Ch] [ebp-Ch]

  v8 = *a1;
  for ( i = 0; a3 > i; ++i )
  {
    *v8 = *(_BYTE *)(a4 + ((*a5)++ & 7));
    v8 += *(int *)((char *)&dword_184532 + 2);
  }
  result = &v8[a2];
  *a1 = result;
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (00136631) --------------------------------------------------------
_BYTE *__fastcall sub_136631(_BYTE **a1, int a2, int a3, int a4, int a5)
{
  _BYTE *v5; // edx
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v9; // [esp+8h] [ebp-10h]

  v5 = *a1;
  *v5 = a5;
  v9 = &v5[a2];
  for ( i = 1; a3 > i; ++i )
  {
    *v9 = a4;
    v9 += a2;
  }
  result = &v9[*(int *)((char *)&dword_184532 + 2)];
  *a1 = &v9[*(int *)((char *)&dword_184532 + 2)];
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (001366AC) --------------------------------------------------------
_BYTE *__fastcall sub_1366AC(_BYTE **a1, int a2, int a3, int a4, int a5)
{
  _BYTE *v5; // edx
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v9; // [esp+8h] [ebp-10h]

  v5 = *a1;
  *v5 = a5;
  v9 = &v5[*(int *)((char *)&dword_184532 + 2)];
  for ( i = 1; a3 > i; ++i )
  {
    *v9 = a4;
    v9 += *(int *)((char *)&dword_184532 + 2);
  }
  result = &v9[a2];
  *a1 = result;
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (00136728) --------------------------------------------------------
int __fastcall sub_136728( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // eax
  int j; // [esp+0h] [ebp-1Ch]
  int i; // [esp+4h] [ebp-18h]
  char v12; // [esp+18h] [ebp-4h]

  sub_1368D8(a6, a7, a8);
  for ( i = 0; ; ++i )
  {
    result = a5;
    if ( a5 <= i )
      break;
    sub_136A2F(i + a1, i + a2, a1 + a3 - 1 - i, i + a2, (int)byte_1BC89C, 0);
    sub_136A2F(a1 + a3 - 1 - i, i + a2, a1 + a3 - 1 - i, a2 + a4 - 1 - i, (int)byte_1BC89C, a3);
    for ( j = 0; j < 511; ++j )
    {
      v12 = byte_1BC89C[j];
      byte_1BC89C[j] = byte_1BC89C[1022 - j];
      byte_1BC89C[1022 - j] = v12;
    }
    sub_136A2F(i + a1, i + a2, i + a1, a4 + a2 - 1 - i, (int)byte_1BC89C, a3 + a4);
    sub_136A2F(i + a1, a2 + a4 - 1 - i, a1 + a3 - 1 - i, a2 + a4 - 1 - i, (int)byte_1BC89C, a3 + a3 + a4);
  }
  return result;
}


//----- (001368D8) --------------------------------------------------------
int __fastcall sub_1368D8(int a1, int a2, int a3)
{
  char v3; // al
  int v5; // [esp+0h] [ebp-24h]
  int i; // [esp+8h] [ebp-1Ch]
  int j; // [esp+8h] [ebp-1Ch]
  char v8; // [esp+14h] [ebp-10h]
  char v9; // [esp+18h] [ebp-Ch]
  char v10; // [esp+1Ch] [ebp-8h]
  char v11; // [esp+20h] [ebp-4h]

  v5 = sub_12484C();
  byte_1BC89C[0] = a2 & 7;
  v3 = sub_1247A0(4u);
  v8 = v3 - 1;
  if ( v3 == 1 )
    v9 = -1;
  else
    v9 = 1;
  for ( i = 1; i < 1023; ++i )
  {
    v11 = byte_1BC89B[i];
    if ( sub_1247A0(4u) == 1 )
    {
      v8 = 1 - v8;
      if ( v8 )
        v9 = 1;
      else
        v9 = -1;
    }
    v10 = v11;
    if ( sub_1247A0(4u) == 1 )
    {
      v10 = v9 + v11;
      if ( sub_1247A0(4u) == 1 )
      {
        v10 += v9;
        if ( sub_1247A0(4u) == 1 )
          v10 += v9;
      }
    }
    if ( v10 < 0 )
      v10 = 0;
    if ( v10 > 7 )
      v10 = 7;
    byte_1BC89C[i] = v10;
  }
  for ( j = 1; j < 1023; ++j )
    byte_1BC89C[j] = *(_BYTE *)(a3 + (uint8_t)byte_1BC89C[j]);
  return sub_124820(v5);
}


//----- (00136A2F) --------------------------------------------------------
int __fastcall sub_136A2F(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  _BYTE *v7; // [esp+0h] [ebp-48h] BYREF
  int v8; // [esp+4h] [ebp-44h] BYREF
  int v9; // [esp+8h] [ebp-40h] BYREF
  int16_t v10[4]; // [esp+Ch] [ebp-3Ch] BYREF
  int v11; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h] BYREF
  int v13; // [esp+1Ch] [ebp-2Ch]
  int v14; // [esp+20h] [ebp-28h]
  int v15; // [esp+24h] [ebp-24h]
  int v16; // [esp+28h] [ebp-20h]
  int v17; // [esp+2Ch] [ebp-1Ch]
  int v18; // [esp+30h] [ebp-18h]
  int v19; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  int j; // [esp+3Ch] [ebp-Ch]
  int v22; // [esp+40h] [ebp-8h]
  int v23; // [esp+44h] [ebp-4h]

  v8 = a1;
  v12 = a2;
  *(_DWORD *)v10 = a3;
  v9 = a4;
  if ( word_1845D8 != 1
    || (result = (int16_t)sub_135357((int16_t *)&v8, (int16_t *)&v12, v10, (int16_t *)&v9), (int16_t)result != 1) )
  {
    if ( (int16_t)v12 > (int16_t)v9 )
    {
      sub_133111((int16_t *)&v12, (int16_t *)&v9);
      sub_133111((int16_t *)&v8, v10);
    }
    v7 = (_BYTE *)((int16_t)v12 * HIDWORD(qword_184530) + (int16_t)v8 + dword_1BB904);
    v15 = *(_DWORD *)v10 - v8;
    if ( (int16_t)(v10[0] - v8) >= 0 )
    {
      v14 = 1;
    }
    else
    {
      v14 = -1;
      v15 = -v15;
    }
    v16 = v9 - v12;
    if ( (_WORD)v15 )
    {
      if ( (_WORD)v16 )
      {
        if ( (_WORD)v15 == (_WORD)v16 )
        {
          for ( i = 0; ; ++i )
          {
            result = i;
            if ( (int16_t)i > (int16_t)v15 )
              break;
            *v7 = *(_BYTE *)(a5 + (a6++ & 0x3FF));
            v7 += HIDWORD(qword_184530) + (int16_t)v14;
          }
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v8 >= v10[0] )
            {
              for ( i = v12; ; ++i )
              {
                result = i;
                if ( (int16_t)i > (int16_t)v9 )
                  break;
                sub_125E13((int16_t)v8 - ((int16_t)i - (int16_t)v12), (int16_t)i);
              }
            }
            else
            {
              for ( i = v12; ; ++i )
              {
                result = i;
                if ( (int16_t)i > (int16_t)v9 )
                  break;
                sub_125E13((int16_t)i - (int16_t)v12 + (int16_t)v8, (int16_t)i);
              }
            }
          }
        }
        else if ( (int16_t)v15 < (int16_t)v16 )
        {
          v17 = (int16_t)v16 / (int16_t)v15;
          v11 = 2 * ((int16_t)v16 % (int16_t)v15);
          v23 = 2 * v15;
          v13 = (int16_t)v16 % (int16_t)v15 - 2 * (int16_t)v15;
          v18 = ((int16_t)v17 >> 1) + 1;
          v19 = v18;
          if ( !(_WORD)v11 && (v17 & 1) == 0 )
            --v18;
          if ( (v17 & 1) != 0 )
            v13 += v15;
          sub_137121(&v7, v14, v18, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            for ( i = 0; (int16_t)i < (int16_t)v18; ++i )
              sub_125E13((int16_t)v8, (int16_t)v12 + (int16_t)i);
            v12 += v18;
            v8 += v14;
          }
          for ( i = 0; (int16_t)i < (int16_t)v15 - 1; ++i )
          {
            v22 = v17;
            v13 += v11;
            if ( (int16_t)v13 > 0 )
            {
              ++v22;
              v13 -= v23;
            }
            sub_137121(&v7, v14, v22, a5, &a6);
            if ( dword_1BBA28 >= 2 )
            {
              for ( j = 0; (int16_t)j < (int16_t)v22; ++j )
                sub_125E13((int16_t)v8, (int16_t)v12 + (int16_t)j);
              v12 += v22;
              v8 += v14;
            }
          }
          result = (int)sub_137121(&v7, v14, v19, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            for ( i = 0; (int16_t)i < (int16_t)v19; ++i )
              sub_125E13((int16_t)v8, (int16_t)v12 + (int16_t)i);
            v12 += v19;
            result = v14;
            v8 += v14;
          }
        }
        else
        {
          v17 = (int16_t)v15 / (int16_t)v16;
          v11 = 2 * ((int16_t)v15 % (int16_t)v16);
          v23 = 2 * v16;
          v13 = (int16_t)v15 % (int16_t)v16 - 2 * (int16_t)v16;
          v18 = ((int16_t)v17 >> 1) + 1;
          v19 = v18;
          if ( !(_WORD)v11 && (v17 & 1) == 0 )
            --v18;
          if ( (v17 & 1) != 0 )
            v13 += v16;
          sub_1370A3(&v7, v14, v18, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v14 <= 0 )
            {
              sub_138CEE((int16_t)v8 - (int16_t)v18, (int16_t)v12, (int16_t)v8, (int16_t)v12);
              v8 -= v18;
            }
            else
            {
              sub_138CEE((int16_t)v8, (int16_t)v12, (int16_t)v18 + (int16_t)v8, (int16_t)v12);
              v8 += v18;
            }
            ++v12;
          }
          for ( i = 0; (int16_t)i < (int16_t)v16 - 1; ++i )
          {
            v22 = v17;
            v13 += v11;
            if ( (int16_t)v13 > 0 )
            {
              ++v22;
              v13 -= v23;
            }
            sub_1370A3(&v7, v14, v22, a5, &a6);
            if ( dword_1BBA28 >= 2 )
            {
              if ( (int16_t)v14 <= 0 )
              {
                sub_138CEE((int16_t)v8 - (int16_t)v22, (int16_t)v12, (int16_t)v8, (int16_t)v12);
                v8 -= v22;
              }
              else
              {
                sub_138CEE((int16_t)v8, (int16_t)v12, (int16_t)v22 + (int16_t)v8, (int16_t)v12);
                v8 += v22;
              }
              ++v12;
            }
          }
          result = (int)sub_1370A3(&v7, v14, v19, a5, &a6);
          if ( dword_1BBA28 >= 2 )
          {
            if ( (int16_t)v14 <= 0 )
              return sub_138CEE((int16_t)v8 - (int16_t)v19, (int16_t)v12, (int16_t)v8, (int16_t)v12);
            else
              return sub_138CEE((int16_t)v8, (int16_t)v12, (int16_t)v19 + (int16_t)v8, (int16_t)v12);
          }
        }
      }
      else
      {
        for ( i = 0; ; ++i )
        {
          result = i;
          if ( (int16_t)i > (int16_t)v15 )
            break;
          *v7 = *(_BYTE *)(a5 + (a6++ & 0x3FF));
          v7 += (int16_t)v14;
        }
        if ( dword_1BBA28 >= 2 )
        {
          if ( v10[0] < (int16_t)v8 )
            sub_133111((int16_t *)&v8, v10);
          return sub_138CEE((int16_t)v8, (int16_t)v12, v10[0], (int16_t)v12);
        }
      }
    }
    else
    {
      for ( i = 0; ; ++i )
      {
        result = i;
        if ( (int16_t)i > (int16_t)v16 )
          break;
        *v7 = *(_BYTE *)(a5 + (a6++ & 0x3FF));
        v7 += HIDWORD(qword_184530);
      }
      if ( dword_1BBA28 >= 2 )
      {
        for ( i = v12; ; ++i )
        {
          result = i;
          if ( (int16_t)i > (int16_t)v9 )
            break;
          sub_125E13((int16_t)v8, (int16_t)i);
        }
      }
    }
  }
  return result;
}
// 184530: using guessed type int64_t qword_184530;
// 1845D8: using guessed type int16_t word_1845D8;
// 1BB904: using guessed type int dword_1BB904;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (001370A3) --------------------------------------------------------
_BYTE *__fastcall sub_1370A3(_BYTE **a1, int a2, int a3, int a4, _WORD *a5)
{
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v8; // [esp+Ch] [ebp-Ch]

  v8 = *a1;
  for ( i = 0; a3 > i; ++i )
  {
    *v8 = *(_BYTE *)(a4 + ((*a5)++ & 0x3FF));
    v8 += a2;
  }
  result = &v8[*(int *)((char *)&dword_184532 + 2)];
  *a1 = &v8[*(int *)((char *)&dword_184532 + 2)];
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (00137121) --------------------------------------------------------
_BYTE *__fastcall sub_137121(_BYTE **a1, int a2, int a3, int a4, _WORD *a5)
{
  _BYTE *result; // eax
  int i; // [esp+4h] [ebp-14h]
  _BYTE *v8; // [esp+Ch] [ebp-Ch]

  v8 = *a1;
  for ( i = 0; a3 > i; ++i )
  {
    *v8 = *(_BYTE *)(a4 + ((*a5)++ & 0x3FF));
    v8 += *(int *)((char *)&dword_184532 + 2);
  }
  result = &v8[a2];
  *a1 = result;
  return result;
}
// 184532: using guessed type int dword_184532;


//----- (0013719F) --------------------------------------------------------
int __fastcall sub_13719F(int a1, int a2, int a3)
{
  int result; // eax
  int16_t v4; // ax
  uint8_t v5; // [esp+0h] [ebp-8Ch]
  int v6; // [esp+Ch] [ebp-80h]
  int v7; // [esp+24h] [ebp-68h]
  int v8; // [esp+24h] [ebp-68h]
  int v9; // [esp+24h] [ebp-68h]
  int v10; // [esp+38h] [ebp-54h]
  int v11; // [esp+40h] [ebp-4Ch]
  int k; // [esp+48h] [ebp-44h]
  int n; // [esp+48h] [ebp-44h]
  int j; // [esp+4Ch] [ebp-40h]
  int v15; // [esp+54h] [ebp-38h]
  int v16; // [esp+58h] [ebp-34h]
  int16_t v17; // [esp+6Ch] [ebp-20h]
  int16_t v18; // [esp+74h] [ebp-18h]
  int i; // [esp+78h] [ebp-14h]
  int16_t v20; // [esp+7Ch] [ebp-10h]
  int16_t v21; // [esp+7Ch] [ebp-10h]
  int16_t v22; // [esp+7Ch] [ebp-10h]
  int16_t m; // [esp+80h] [ebp-Ch]

  dword_1BC2A8 = a1;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= *(int16_t *)(dword_1BC2A8 + 6) )
      break;
    v6 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (int16_t)i);
    v5 = *(_BYTE *)(dword_1BC2A8 + 11) & 3;
    switch ( v5 )
    {
      case 0u:
        v17 = *(_WORD *)(dword_1BC2A8 + 2);
        v11 = *(uint16_t *)(v6 + 2);
        v15 = 2;
        while ( v17 > v11 )
        {
          v20 = *(_WORD *)(v6 + 2 * v15);
          v4 = *(_WORD *)(v6 + 2 * v15 + 2);
          v15 += 2;
          if ( v20 )
          {
            v7 = 2 * v15;
            for ( j = 0; v20 > j; ++j )
            {
              if ( *(uint8_t *)(v7 + v6) == a2 )
                *(_BYTE *)(v7 + v6) = a3;
              ++v7;
            }
            v15 += (v20 + 1) / 2;
          }
          else
          {
            v11 += v4;
          }
        }
        break;
      case 1u:
        v10 = (*(int *)dword_1BC2A8 >> 16) * *(int16_t *)dword_1BC2A8;
        for ( k = 0; k < v10; ++k )
        {
          if ( *(_BYTE *)(k + v6) == (_BYTE)a2 )
            *(_BYTE *)(k + v6) = a3;
        }
        break;
      case 2u:
        v8 = 0;
        for ( m = 0; m < 5; ++m )
        {
          v18 = *(_WORD *)(v8 + v6);
          v21 = *(_WORD *)(v8 + v6 + 4);
          v8 += 8;
          while ( v21 || v18 )
          {
            v16 = v8 + v6;
            v22 = 4 * v21;
            for ( n = 0; v22 > n; ++n )
            {
              if ( *(uint8_t *)(n + v16) == a2 )
                *(_BYTE *)(n + v16) = a3;
            }
            v9 = v22 + v8;
            v18 = *(_WORD *)(v9 + v6);
            v21 = *(_WORD *)(v9 + v6 + 4);
            v8 = v9 + 8;
          }
        }
        break;
      case 3u:
        sub_1376CF(v5, dword_1BC2A8);
      default:
        continue;
    }
  }
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (0013743E) --------------------------------------------------------
int __fastcall sub_13743E(int a1, int a2)
{
  int result; // eax
  int16_t v3; // ax
  uint8_t v4; // [esp+0h] [ebp-88h]
  int v5; // [esp+8h] [ebp-80h]
  int v6; // [esp+20h] [ebp-68h]
  int v7; // [esp+34h] [ebp-54h]
  int v8; // [esp+3Ch] [ebp-4Ch]
  int k; // [esp+44h] [ebp-44h]
  int n; // [esp+44h] [ebp-44h]
  int v11; // [esp+50h] [ebp-38h]
  int v12; // [esp+54h] [ebp-34h]
  int v13; // [esp+54h] [ebp-34h]
  int v14; // [esp+54h] [ebp-34h]
  int j; // [esp+58h] [ebp-30h]
  int16_t v16; // [esp+68h] [ebp-20h]
  int16_t v17; // [esp+70h] [ebp-18h]
  int i; // [esp+74h] [ebp-14h]
  int16_t v19; // [esp+78h] [ebp-10h]
  int16_t v20; // [esp+78h] [ebp-10h]
  int16_t v21; // [esp+78h] [ebp-10h]
  int16_t m; // [esp+7Ch] [ebp-Ch]

  dword_1BC2A8 = a1;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= *(int16_t *)(dword_1BC2A8 + 6) )
      break;
    v5 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (int16_t)i);
    v4 = *(_BYTE *)(dword_1BC2A8 + 11) & 3;
    switch ( v4 )
    {
      case 0u:
        v16 = *(_WORD *)(dword_1BC2A8 + 2);
        v8 = *(uint16_t *)(v5 + 2);
        v6 = 2;
        while ( v16 > v8 )
        {
          v19 = *(_WORD *)(v5 + 2 * v6);
          v3 = *(_WORD *)(v5 + 2 * v6 + 2);
          v6 += 2;
          if ( v19 )
          {
            v12 = 2 * v6;
            for ( j = 0; v19 > j; ++j )
            {
              if ( *(_BYTE *)(v12 + v5) )
                *(_BYTE *)(v12 + v5) = a2;
              ++v12;
            }
            v6 += (v19 + 1) / 2;
          }
          else
          {
            v8 += v3;
          }
        }
        break;
      case 1u:
        v7 = (*(int *)dword_1BC2A8 >> 16) * *(int16_t *)dword_1BC2A8;
        for ( k = 0; k < v7; ++k )
        {
          if ( *(_BYTE *)(k + v5) )
            *(_BYTE *)(k + v5) = a2;
        }
        break;
      case 2u:
        v13 = 0;
        for ( m = 0; m < 5; ++m )
        {
          v17 = *(_WORD *)(v13 + v5);
          v20 = *(_WORD *)(v13 + v5 + 4);
          v13 += 8;
          while ( v20 || v17 )
          {
            v11 = v13 + v5;
            v21 = 4 * v20;
            for ( n = 0; v21 > n; ++n )
            {
              if ( *(_BYTE *)(n + v11) )
                *(_BYTE *)(n + v11) = a2;
            }
            v14 = v21 + v13;
            v17 = *(_WORD *)(v14 + v5);
            v20 = *(_WORD *)(v14 + v5 + 4);
            v13 = v14 + 8;
          }
        }
        break;
      case 3u:
        sub_1376CF(v4, dword_1BC2A8);
      default:
        continue;
    }
  }
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (001376CF) --------------------------------------------------------
void __fastcall __noreturn sub_1376CF(int a1, int a2)
{
  sub_126487(aCannotColorRep, a2);
}


//----- (00137D86) --------------------------------------------------------
int __fastcall sub_137D86(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int16_t v5; // ax
  uint8_t v6; // [esp+0h] [ebp-98h]
  int v7; // [esp+10h] [ebp-88h]
  int v8; // [esp+28h] [ebp-70h]
  int v9; // [esp+28h] [ebp-70h]
  int v10; // [esp+28h] [ebp-70h]
  int j; // [esp+2Ch] [ebp-6Ch]
  int v12; // [esp+40h] [ebp-58h]
  int v13; // [esp+48h] [ebp-50h]
  int k; // [esp+50h] [ebp-48h]
  int n; // [esp+50h] [ebp-48h]
  int v16; // [esp+54h] [ebp-44h]
  int v17; // [esp+58h] [ebp-40h]
  int16_t v18; // [esp+68h] [ebp-30h]
  int i; // [esp+70h] [ebp-28h]
  int16_t v20; // [esp+74h] [ebp-24h]
  int16_t v21; // [esp+74h] [ebp-24h]
  int16_t v22; // [esp+74h] [ebp-24h]
  int16_t v23; // [esp+78h] [ebp-20h]
  int16_t v24; // [esp+78h] [ebp-20h]
  int16_t v25; // [esp+78h] [ebp-20h]
  int16_t v26; // [esp+7Ch] [ebp-1Ch]
  int16_t v27; // [esp+84h] [ebp-14h]
  int16_t m; // [esp+8Ch] [ebp-Ch]

  v27 = a4 + a3 - 1;
  dword_1BC2A8 = a1;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= *(int16_t *)(dword_1BC2A8 + 6) )
      break;
    v7 = dword_1BC2A8 + *(_DWORD *)(dword_1BC2A8 + 12 + 4 * (int16_t)i);
    v6 = *(_BYTE *)(dword_1BC2A8 + 11) & 3;
    switch ( v6 )
    {
      case 0u:
        v18 = *(_WORD *)(dword_1BC2A8 + 2);
        v13 = *(uint16_t *)(v7 + 2);
        v17 = 2;
        while ( v18 > v13 )
        {
          v23 = *(_WORD *)(v7 + 2 * v17);
          v5 = *(_WORD *)(v7 + 2 * v17 + 2);
          v17 += 2;
          if ( v23 )
          {
            v8 = 2 * v17;
            for ( j = 0; v23 > j; ++j )
            {
              if ( *(_BYTE *)(v8 + v7) )
              {
                v20 = *(uint8_t *)(v8 + v7);
                if ( v20 >= a3 && v20 <= v27 )
                  *(_BYTE *)(v8 + v7) = *(_BYTE *)(a2 + *(uint8_t *)(v8 + v7) - a3);
              }
              ++v8;
            }
            v17 += (v23 + 1) / 2;
          }
          else
          {
            v13 += v5;
          }
        }
        break;
      case 1u:
        v12 = (*(int *)dword_1BC2A8 >> 16) * *(int16_t *)dword_1BC2A8;
        for ( k = 0; k < v12; ++k )
        {
          if ( *(_BYTE *)(k + v7) )
          {
            v21 = *(uint8_t *)(k + v7);
            if ( v21 >= a3 && v21 <= v27 )
              *(_BYTE *)(k + v7) = *(_BYTE *)(a2 + *(uint8_t *)(k + v7) - a3);
          }
        }
        break;
      case 2u:
        v9 = 0;
        for ( m = 0; m < 5; ++m )
        {
          v26 = *(_WORD *)(v9 + v7);
          v24 = *(_WORD *)(v9 + v7 + 4);
          v9 += 8;
          while ( v24 || v26 )
          {
            v16 = v9 + v7;
            v25 = 4 * v24;
            for ( n = 0; v25 > n; ++n )
            {
              if ( *(_BYTE *)(n + v16) )
              {
                v22 = *(uint8_t *)(n + v16);
                if ( v22 >= a3 && v22 <= v27 )
                  *(_BYTE *)(n + v16) = *(_BYTE *)(a2 + *(uint8_t *)(n + v16) - a3);
              }
            }
            v10 = v25 + v9;
            v26 = *(_WORD *)(v10 + v7);
            v24 = *(_WORD *)(v10 + v7 + 4);
            v9 = v10 + 8;
          }
        }
        break;
      case 3u:
        sub_1376CF(v6, dword_1BC2A8);
      default:
        continue;
    }
  }
  return result;
}
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (001380E0) --------------------------------------------------------
int __fastcall sub_1380E0(int result, int a2)
{
  int i; // [esp+0h] [ebp-10h]
  int16_t v3; // [esp+8h] [ebp-8h]

  v3 = result;
  dword_1BD09C = (int)&byte_1BC89C;
  for ( i = 0; i < 256; ++i )
  {
    *(_BYTE *)(i + dword_1BD09C) = (uint8_t)(byte_1BB35A[4 * i]
                                                   + byte_1BB359[4 * i]
                                                   + ((int)(uint8_t)byte_1BB35B[4 * i] >> 1))
                                 * v3
                                 / 158;
    if ( a2 == 1 )
      *(_BYTE *)(i + dword_1BD09C) = v3 - 1 - *(_BYTE *)(i + dword_1BD09C);
    result = i;
  }
  return result;
}
// 1BC89C: using guessed type char byte_1BC89C;
// 1BD09C: using guessed type int dword_1BD09C;


//----- (001381B5) --------------------------------------------------------
int __fastcall sub_1381B5(int a1, int a2)
{
  int v2; // edx
  int result; // eax

  dword_1BC2A8 = a1;
  v2 = 4 * (*(int *)(a1 + 4) >> 16);
  dword_1BC2A4 = v2 + a1 + 16;
  if ( a2 + (*(int *)(v2 + a1 + 16) >> 16) > 256 )
    sub_126487(aShiftPaletteRa, v2);
  result = a2;
  *(_WORD *)dword_1BC2A4 = a2;
  return result;
}
// 1BC2A4: using guessed type int dword_1BC2A4;
// 1BC2A8: using guessed type int dword_1BC2A8;


//----- (001382BF) --------------------------------------------------------
int64_t __fastcall sub_1382BF( int a1, int a2, int a3, int a4, int a5)
{
  int64_t v6; // [esp+0h] [ebp-14h]
  int64_t v7; // [esp+0h] [ebp-14h]

  HIDWORD(v6) = a2;
  dword_1BD09C = (int)byte_1BC89C;
  sub_1380E0((int16_t)a2, a5);
  LODWORD(v6) = 0;
  while ( (int)v6 < 256 )
  {
    *(_BYTE *)(v6 + dword_1BD09C) += a1;
    LODWORD(v6) = v6 + 1;
  }
  sub_1481C2(v6);
  sub_1380E0(a4, a5);
  LODWORD(v7) = 0;
  while ( (int)v7 < 256 )
  {
    *(_BYTE *)(v7 + dword_1BD09C) += a3;
    LODWORD(v7) = v7 + 1;
  }
  return sub_1481C2(v7);
}
// 138378: variable 'v7' is possibly undefined
// 1BB904: using guessed type int dword_1BB904;
// 1BD09C: using guessed type int dword_1BD09C;


//----- (001384B9) --------------------------------------------------------
int __fastcall sub_1384B9(int a1, int a2)
{
  int v2; // eax
  int v4; // [esp+10h] [ebp-14h]
  int v5; // [esp+14h] [ebp-10h]
  int v6; // [esp+18h] [ebp-Ch]
  int v7; // [esp+1Ch] [ebp-8h]
  int v8; // [esp+1Ch] [ebp-8h]

  v5 = a1;
  v6 = a2;
  if ( a1 )
  {
    if ( a2 )
    {
      if ( a1 >= 0 )
      {
        if ( a2 >= 0 )
        {
          v4 = 0;
        }
        else
        {
          v5 = -a2;
          v6 = a1;
          v4 = 270;
        }
      }
      else if ( a2 >= 0 )
      {
        v5 = a2;
        v6 = -a1;
        v4 = 90;
      }
      else
      {
        v5 = -a1;
        v6 = -a2;
        v4 = 180;
      }
      if ( v5 == v6 )
      {
        v8 = 45;
      }
      else if ( v5 >= v6 )
      {
        v8 = (uint8_t)byte_138385[(v6 << 7) / (unsigned int)v5];
      }
      else
      {
        v2 = (v5 << 7) / (unsigned int)v6;
        LOWORD(v2) = (uint8_t)byte_138385[v2];
        v8 = 90 - v2;
      }
      v7 = v4 + v8;
      if ( (int16_t)v7 == 360 )
        return 0;
    }
    else if ( a1 >= 0 )
    {
      return 0;
    }
    else
    {
      return 180;
    }
  }
  else if ( a2 >= 0 )
  {
    if ( a2 <= 0 )
      return 0;
    else
      return 90;
  }
  else
  {
    return 270;
  }
  return v7;
}


//----- (00138615) --------------------------------------------------------
int __fastcall sub_138615( int a1, int a2)
{
  int v4; // [esp+4h] [ebp-Ch]
  int16_t v5; // [esp+Ch] [ebp-4h]

  v5 = a1;
  v4 = a2;
  if ( a2 < 0 )
  {
    v4 = -a2;
    v5 = a1 + 180;
  }
  if ( v5 < 360 )
  {
    for ( ; v5 < 0; v5 += 360 )
      ;
  }
  else
  {
    do
      v5 -= 360;
    while ( v5 >= 360 );
  }
  if ( v5 >= 180 )
  {
    if ( v5 >= 270 )
    {
      if ( v5 == 270 )
        return -v4;
      else
        return -((v4 * (unsigned int)(uint16_t)word_138405[360 - v5] + 0x8000) >> 16);
    }
    else
    {
      return -((v4 * (unsigned int)*((uint16_t *)&loc_13829B + v5 + 1) + 0x8000) >> 16);
    }
  }
  else if ( v5 >= 90 )
  {
    if ( v5 == 90 )
      return v4;
    else
      return (v4 * (unsigned int)(uint16_t)word_138405[180 - v5] + 0x8000) >> 16;
  }
  else
  {
    return (v4 * (unsigned int)(uint16_t)word_138405[v5] + 0x8000) >> 16;
  }
}
// 138405: using guessed type int16_t word_138405[];


//----- (00138776) --------------------------------------------------------
int __fastcall sub_138776( int a1, int a2)
{
  return sub_138615(a1 + 90, a2);
}


//----- (001387B2) --------------------------------------------------------
int __fastcall sub_1387B2( int a1, int *a2, int *a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-30h]
  int v5; // [esp+4h] [ebp-2Ch]
  int v6; // [esp+8h] [ebp-28h]
  int v7; // [esp+Ch] [ebp-24h]
  int v8; // [esp+10h] [ebp-20h]
  int v9; // [esp+1Ch] [ebp-14h]
  int v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch]
  int v12; // [esp+28h] [ebp-8h]
  int16_t v13; // [esp+2Ch] [ebp-4h]

  v13 = a1;
  v10 = 0;
  if ( a1 < 360 )
  {
    if ( a1 < 0 )
    {
      do
        v13 += 360;
      while ( v13 < 0 );
    }
  }
  else
  {
    do
      v13 -= 360;
    while ( v13 >= 360 );
  }
  if ( v13 >= 180 )
  {
    if ( v13 >= 270 )
    {
      if ( v13 == 270 )
      {
        v6 = *a3;
        *a3 = *a2;
        *a3 = -*a3;
        result = v6;
        *a2 = v6;
        v10 = 1;
      }
      else
      {
        v9 = -(uint16_t)word_138405[360 - v13] * *a2;
        v8 = -(uint16_t)word_138405[360 - v13] * *a3;
        v11 = *(uint16_t *)((char *)&loc_1381E8 + 2 * v13 + 1) * *a2;
        result = *(uint16_t *)((char *)&loc_1381E8 + 2 * v13 + 1) * *a3;
        v12 = result;
      }
    }
    else if ( v13 == 180 )
    {
      *a2 = -*a2;
      result = -*a3;
      *a3 = result;
      v10 = 1;
    }
    else
    {
      v9 = -*((uint16_t *)&loc_13829B + v13 + 1) * *a2;
      v8 = -*((uint16_t *)&loc_13829B + v13 + 1) * *a3;
      v11 = -(uint16_t)word_138405[270 - v13] * *a2;
      result = -(uint16_t)word_138405[270 - v13] * *a3;
      v12 = result;
    }
  }
  else
  {
    result = v13;
    if ( v13 >= 90 )
    {
      if ( v13 == 90 )
      {
        v7 = -*a3;
        *a3 = *a2;
        result = v7;
        *a2 = v7;
        v10 = 1;
      }
      else
      {
        v9 = (uint16_t)word_138405[180 - v13] * *a2;
        v8 = (uint16_t)word_138405[180 - v13] * *a3;
        v11 = -*(uint16_t *)((char *)&loc_138350 + 2 * v13 + 1) * *a2;
        result = -*(uint16_t *)((char *)&loc_138350 + 2 * v13 + 1) * *a3;
        v12 = result;
      }
    }
    else if ( v13 )
    {
      v9 = (uint16_t)word_138405[v13] * *a2;
      v8 = (uint16_t)word_138405[v13] * *a3;
      v11 = (uint16_t)word_138405[90 - v13] * *a2;
      result = (uint16_t)word_138405[90 - v13] * *a3;
      v12 = result;
    }
    else
    {
      v10 = 1;
    }
  }
  if ( !v10 )
  {
    v5 = v11 - v8;
    v4 = v12 + v9;
    if ( v11 - v8 >= 0 )
    {
      *a2 = (unsigned int)(v5 + 0x8000) >> 16;
    }
    else
    {
      *a2 = (unsigned int)(0x8000 - v5) >> 16;
      *a2 = -*a2;
    }
    result = (int)a3;
    if ( v4 >= 0 )
    {
      *a3 = (unsigned int)(v4 + 0x8000) >> 16;
    }
    else
    {
      *a3 = (unsigned int)(0x8000 - v4) >> 16;
      *a3 = -*a3;
    }
  }
  return result;
}
// 138B13: variable 'v11' is possibly undefined
// 138B13: variable 'v8' is possibly undefined
// 138B1C: variable 'v12' is possibly undefined
// 138B1C: variable 'v9' is possibly undefined
// 138405: using guessed type int16_t word_138405[];


//----- (00138C34) --------------------------------------------------------
void sub_138C34()
{
  /* __asm: int     10h; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA BIOS - CPU VIDEO MEMORY CONTROL */ DECOMP_TODO("inline asm");
}


//----- (00138C58) --------------------------------------------------------
void sub_138C58()
{
  /* __asm: int     10h; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA BIOS - CPU VIDEO MEMORY CONTROL */ DECOMP_TODO("inline asm");
}


//----- (00138C87) --------------------------------------------------------
void sub_138C87()
{
  /* __asm: int     10h; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA BIOS 1.1 - GET/SET DISPLAY START */ DECOMP_TODO("inline asm");
}
// 1BBA64: using guessed type int dword_1BBA64;


//----- (00138CB0) --------------------------------------------------------
// write access to memory has been detected, the output may be wrong!
int __fastcall sub_138CB0(int a1, int a2)
{
  unsigned int v2; // ett

  /* __asm: int     10h; - VIDEO - VESA SuperVGA BIOS -  VESA SuperVGA BIOS - CPU VIDEO MEMORY CONTROL */ DECOMP_TODO("inline asm");
  LOWORD(v2) = a2;
  HIWORD(v2) = a2;
  word_1BBA30 = v2 / (uint16_t)word_1BBA5C;
  dword_138CAC = (uint16_t)(v2 / (uint16_t)word_1BBA5C);
  return 0;
}
// 138CD4: write access to memory at 138CAC has been detected
// 138CAC: using guessed type int dword_138CAC;
// 1BBA30: using guessed type int16_t word_1BBA30;
// 1BBA5C: using guessed type int16_t word_1BBA5C;


//----- (00138CE0) --------------------------------------------------------
// PORT (vlna 21): kopie "a3 << 10" bajtu (kilobajty!) mezi obrazovymi
// buffery. DIAG: zalogovat prva volani a KAZDE volani s nulovym ukazatelem
// (hlaseno "result=0, a2=0xCD..."); nulove kopirovani preskocit misto padu
// 300KB memcpy na NULL - checkpoint prozradi volajiciho drive nez crash.
void *__fastcall sub_138CE0(void *result, void *a2, int a3)
{
  static int diagCalls;
  if ( diagCalls < 3 )
  {
    ++diagCalls;
    PortDebug_Checkpoint("138CE0.dst", (int)(intptr_t)result);
    PortDebug_Checkpoint("138CE0.src", (int)(intptr_t)a2);
    PortDebug_Checkpoint("138CE0.kb", a3);
  }
  if ( !result || !a2 )
  {
    PortDebug_Checkpoint("138CE0.NULL_PTR_dst", (int)(intptr_t)result);
    PortDebug_Checkpoint("138CE0.NULL_PTR_src", (int)(intptr_t)a2);
    return result;
  }
  qmemcpy(result, a2, a3 << 10);
  return result;
}


//----- (00138CEE) --------------------------------------------------------
int __fastcall sub_138CEE(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // eax
  unsigned int v5; // ebx
  int16_t *v6; // edi
  int16_t *v7; // esi
  _WORD *v8; // edi
  int16_t *v9; // edi
  _WORD *v10; // edi
  int16_t *v11; // edi
  _WORD *v12; // esi
  int16_t *v13; // esi
  int v15; // [esp-20h] [ebp-20h]

  v15 = a1;
  if ( a1 < 0 )
  {
    a1 = 0;
  }
  else if ( a1 > 639 )
  {
    a1 = 639;
  }
  if ( a2 < 0 )
  {
    a2 = 0;
  }
  else if ( a2 > 479 )
  {
    a2 = 479;
  }
  if ( a3 < 0 )
  {
    a3 = 0;
  }
  else if ( a3 > 639 )
  {
    a3 = 639;
  }
  if ( a4 < 0 )
  {
    a4 = 0;
  }
  else if ( a4 > 479 )
  {
    a4 = 479;
  }
  v4 = (unsigned int)a1 >> 2;
  v5 = (unsigned int)a3 >> 2;
  v6 = (int16_t *)(dword_1BB908 + 4 * a2);
  v7 = (int16_t *)(dword_1BB8C0 + 4 * a2);
  if ( (_WORD)dword_1BBA28 == 2 )
  {
    while ( a2 <= a4 )
    {
      ++a2;
      if ( *v6 == -1 )
      {
        *v6 = v4;
        v8 = v6 + 1;
        *v8 = v5;
        v6 = v8 + 1;
      }
      else
      {
        if ( *v6 >= (int16_t)v4 )
          *v6 = v4;
        v9 = v6 + 1;
        if ( *v9 <= (int16_t)v5 )
          *v9 = v5;
        v6 = v9 + 1;
      }
    }
  }
  else
  {
    while ( a2 <= a4 )
    {
      ++a2;
      if ( *v6 == -1 )
      {
        *v6 = v4;
        v10 = v6 + 1;
        *v10 = v5;
        v6 = v10 + 1;
      }
      else
      {
        if ( *v6 >= (int16_t)v4 )
          *v6 = v4;
        v11 = v6 + 1;
        if ( *v11 <= (int16_t)v5 )
          *v11 = v5;
        v6 = v11 + 1;
      }
      if ( *v7 == -1 )
      {
        *v7 = v4;
        v12 = v7 + 1;
        *v12 = v5;
        v7 = v12 + 1;
      }
      else
      {
        if ( *v7 >= (int16_t)v4 )
          *v7 = v4;
        v13 = v7 + 1;
        if ( *v13 <= (int16_t)v5 )
          *v13 = v5;
        v7 = v13 + 1;
      }
    }
  }
  return v15;
}
// 1BB8C0: using guessed type int dword_1BB8C0;
// 1BB908: using guessed type int dword_1BB908;
// 1BBA28: using guessed type int dword_1BBA28;


//----- (00138F3B) --------------------------------------------------------
int __fastcall sub_138F3B(int a1, int a2, int (__fastcall *a3)(_DWORD, _DWORD, _DWORD, _DWORD), int a4)
{
  dword_1BD150 = a1;
  if ( a1 )
  {
    if ( a1 == 1 || a1 == 2 )
      return sub_13CC5B(a4, a3, (int)a3, a4);
    else
      return 0;
  }
  else if ( dword_18464C )
  {
    return 1;
  }
  else
  {
    /* __asm: int     2Fh; - Multiplex - Novell NetWare - LOW-LEVEL API (IPX) INSTALLATION CHECK */ DECOMP_TODO("inline asm");
    return 0;
  }
}
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 18464C: using guessed type int dword_18464C;
// 184650: using guessed type int dword_184650;
// 1BD150: using guessed type int dword_1BD150;


//----- (00139062) --------------------------------------------------------
int sub_139062()
{
  int result=0; // eax

  if ( dword_1BD150 )
  {
    if ( dword_1BD150 == 1 || dword_1BD150 == 2 )
      return sub_13CCC5();
  }
  else if ( dword_18464C )
  {
    result = sub_14DF7A();
    dword_18464C = 0;
  }
  return result;
}
// 18464C: using guessed type int dword_18464C;
// 1BD150: using guessed type int dword_1BD150;


//----- (001390BB) --------------------------------------------------------
void __fastcall sub_1390BB(int a1, int a2, int a3)
{
  if ( !dword_18466C )
  {
    dword_18466C = 1;
    if ( dword_1BD150 )
    {
      if ( dword_1BD150 == 1 || dword_1BD150 == 2 )
        sub_14EDD9(a1, a2, a3);
    }
    else if ( dword_18464C )
    {
      sub_14E02A(a1, a2, a3);
    }
    dword_18466C = 0;
  }
}
// 18464C: using guessed type int dword_18464C;
// 18466C: using guessed type int dword_18466C;
// 1BD150: using guessed type int dword_1BD150;


//----- (00139127) --------------------------------------------------------
int sub_139127()
{
  return dword_1849A0;
}
// 1849A0: using guessed type int dword_1849A0;


//----- (00139153) --------------------------------------------------------
int __fastcall sub_139153(int a1, int a2, int a3, unsigned int a4)
{
  if ( dword_1BD150 )
  {
    if ( dword_1BD150 == 1 || dword_1BD150 == 2 )
    {
      sub_14EA6E(a1, a2, a3, a4);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else if ( dword_18464C )
  {
    while ( dword_1849A0 )
      sub_1390BB(a1, a2, a3);
    sub_14E069(a3, a4, a1, 101, 2, a2);
    return 1;
  }
  else
  {
    return 0;
  }
}
// 139153: could not find valid save-restore pair for ebx
// 13919B: variable 'a1' is possibly undefined
// 18464C: using guessed type int dword_18464C;
// 1849A0: using guessed type int dword_1849A0;
// 1BD150: using guessed type int dword_1BD150;


//----- (00139294) --------------------------------------------------------
int __fastcall sub_139294(_BYTE *a1)
{
  int v3; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]

  v3 = 0;
  v4 = dword_1C40EA;
  if ( dword_1BD150 )
  {
    if ( dword_1BD150 == 1 || dword_1BD150 == 2 )
    {
      if ( a1 )
      {
        *a1 = word_189708;
        a1[1] = byte_1BF38C;
      }
      return 2;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    while ( v4 )
    {
      if ( !strcmp(v4 + 2, &byte_184654) )
      {
        if ( a1 )
          a1[v3] = *(_BYTE *)v4;
        ++v3;
      }
      v4 = *(_DWORD *)(v4 + 30);
    }
    return v3;
  }
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 189708: using guessed type int16_t word_189708;
// 1BD150: using guessed type int dword_1BD150;
// 1BF38C: using guessed type char byte_1BF38C;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (00139358) --------------------------------------------------------
void sub_139358()
{
  word_189708 = 2;
  byte_1BF38C = 1;
}
// 189708: using guessed type int16_t word_189708;
// 1BF38C: using guessed type char byte_1BF38C;


//----- (00139387) --------------------------------------------------------
void sub_139387()
{
  word_189708 = 1;
  byte_1BF38C = 2;
}
// 189708: using guessed type int16_t word_189708;
// 1BF38C: using guessed type char byte_1BF38C;


//----- (00139447) --------------------------------------------------------
int sub_139447()
{
  return (uint16_t)word_189708;
}
// 189708: using guessed type int16_t word_189708;


//----- (00139476) --------------------------------------------------------
int sub_139476()
{
  char v1; // [esp+0h] [ebp-2Ch]
  _BYTE v2[20]; // [esp+4h] [ebp-28h] BYREF
  int i; // [esp+18h] [ebp-14h]
  int j; // [esp+1Ch] [ebp-10h]
  int v5; // [esp+20h] [ebp-Ch]
  int v6; // [esp+24h] [ebp-8h]
  int v7; // [esp+28h] [ebp-4h]

  v6 = dword_1C40EA;
  dword_184668 = 0;
  while ( v6 )
  {
    v5 = 0;
    for ( i = 0; i < dword_184668; ++i )
    {
      if ( !strcmp(&byte_1BD0A0[11 * i], v6 + 2) )
      {
        v5 = 1;
        byte_1BD0AA[11 * i] = *(_BYTE *)(v6 + 1);
      }
    }
    if ( !v5 && strcmp(byte_138F31, v6 + 2) && (*(_BYTE *)(v6 + 1) & 1) != 0 )
    {
      strcpy(&byte_1BD0A0[11 * dword_184668], v6 + 2);
      byte_1BD0AA[11 * dword_184668++] = *(_BYTE *)(v6 + 1);
    }
    v6 = *(_DWORD *)(v6 + 30);
  }
  for ( i = 0; i < dword_184668; ++i )
  {
    for ( j = i + 1; j < dword_184668; ++j )
    {
      if ( stricmp(&byte_1BD0A0[11 * i], &byte_1BD0A0[11 * j]) > 0 )
      {
        strcpy(v2, &byte_1BD0A0[11 * i]);
        v1 = byte_1BD0AA[11 * i];
        strcpy(&byte_1BD0A0[11 * i], &byte_1BD0A0[11 * j]);
        byte_1BD0AA[11 * i] = byte_1BD0AA[11 * j];
        strcpy(&byte_1BD0A0[11 * j], v2);
        byte_1BD0AA[11 * j] = v1;
      }
    }
  }
  v7 = dword_184668;
  return dword_184668;
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 13C896: using guessed type int __fastcall stricmp(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 184668: using guessed type int dword_184668;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (00139659) --------------------------------------------------------
int sub_139659()
{
  sub_139476();
  return dword_184668;
}
// 184668: using guessed type int dword_184668;


//----- (0013968A) --------------------------------------------------------
char *__fastcall sub_13968A(int a1)
{
  sub_139476();
  if ( a1 >= 0 && a1 < dword_184668 )
    return &byte_1BD0A0[11 * a1];
  byte_1BD0A0[11 * dword_184668] = 0;
  return &byte_1BD0A0[11 * dword_184668];
}
// 184668: using guessed type int dword_184668;


//----- (0013974F) --------------------------------------------------------
int __fastcall sub_13974F(int a1)
{
  int i; // [esp+Ch] [ebp-Ch]
  uint8_t *v4; // [esp+10h] [ebp-8h]

  v4 = (uint8_t *)dword_1C40EA;
  sub_139476();
  for ( i = 0; ; ++i )
  {
    if ( i >= dword_184668 )
      return 0;
    if ( !strcmp(a1, &byte_1BD0A0[11 * i]) )
      break;
  }
  if ( (byte_1BD0AA[11 * i] & 1) == 0 )
    return 0;
  while ( v4 )
  {
    if ( *v4 == word_189708 )
      strcpy(v4 + 2, a1);
    v4 = *(uint8_t **)(v4 + 30);
  }
  strcpy(&byte_184654, a1);
  return 1;
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 184668: using guessed type int dword_184668;
// 189708: using guessed type int16_t word_189708;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0013982D) --------------------------------------------------------
int __fastcall sub_13982D(int a1, int a2, int a3, int a4, int a5)
{
  int i; // [esp+10h] [ebp-Ch]
  uint8_t *v7; // [esp+14h] [ebp-8h]

  v7 = (uint8_t *)dword_1C40EA;
  sub_139476();
  for ( i = 0; i < dword_184668; ++i )
  {
    if ( !strcmp(a2, &byte_1BD0A0[11 * i]) )
      return 0;
  }
  strcpy(&byte_184654, a2);
  while ( v7 )
  {
    if ( *v7 == word_189708 )
      strcpy(v7 + 2, a2);
    v7 = *(uint8_t **)(v7 + 30);
  }
  return 1;
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 184668: using guessed type int dword_184668;
// 189708: using guessed type int16_t word_189708;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0013998F) --------------------------------------------------------
void __fastcall sub_13998F(int a1, int a2)
{
  if ( !byte_184654 )
    exit(1, a2);
  if ( (dword_184650 & 1) != 0 )
    ++dword_184650;
}
// 184650: using guessed type int dword_184650;
// 184654: using guessed type char byte_184654;


//----- (00139AF3) --------------------------------------------------------
int __fastcall sub_139AF3(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int16_t v6; // [esp+10h] [ebp-28h]
  int i; // [esp+14h] [ebp-24h]
  int16_t v8; // [esp+1Ch] [ebp-1Ch]

  if ( a3 > 512 )
    sub_126487(aTooManyColorsT, a2);
  if ( a4 > 256 )
    sub_126487(aTooManyColorsT_0, a2);
  sub_13A7CC(a1, a3);
  while ( (uint16_t)dword_1BEB54 < a4 )
  {
    v6 = sub_13A84F();
    if ( v6 == -1 )
      break;
    v8 = sub_13A711(v6);
    sub_13A4A9(
      a1,
      (int)&word_1BDF54[dword_1BD352[3 * v6] >> 16],
      word_1BD356[6 * v6] - HIWORD(dword_1BD352[3 * v6]) + 1,
      v8);
    sub_139D7E(a1, v6, v8);
  }
  for ( i = 0; (int16_t)i < (int)(uint16_t)dword_1BEB54; ++i )
  {
    *(_BYTE *)(a1 + 4 * ((int16_t)i + a2)) = 1;
    *(_BYTE *)(a1 + 4 * ((int16_t)i + a2) + 1) = ((uint8_t)byte_1BD35A[12 * (int16_t)i]
                                                + (uint8_t)byte_1BD35B[12 * (int16_t)i])
                                               / 2;
    *(_BYTE *)(a1 + 4 * (a2 + (int16_t)i) + 2) = ((uint8_t)byte_1BD35D[12 * (int16_t)i]
                                                + (uint8_t)byte_1BD35C[12 * (int16_t)i])
                                               / 2;
    *(_BYTE *)(a1 + 4 * ((int16_t)i + a2) + 3) = ((uint8_t)byte_1BD35E[12 * (int16_t)i]
                                                + (uint8_t)byte_1BD35F[12 * (int16_t)i])
                                               / 2;
  }
  while ( 1 )
  {
    result = i;
    if ( (int16_t)i >= a4 )
      break;
    *(_BYTE *)(a1 + 4 * ((int16_t)i + a2)) = 1;
    *(_BYTE *)(a1 + 4 * (a2 + (int16_t)i) + 1) = *(_BYTE *)(a1 + 4 * ((int16_t)i + a2) - 3);
    *(_BYTE *)(a1 + 4 * ((int16_t)i + a2) + 2) = *(_BYTE *)(a1 + 4 * ((int16_t)i + a2) - 2);
    *(_BYTE *)(a1 + 4 * (a2 + (int16_t)i) + 3) = *(_BYTE *)(4 * ((int16_t)i + a2) + a1 - 1);
    ++i;
  }
  return result;
}
// 1BD352: using guessed type int dword_1BD352[];
// 1BD356: using guessed type int16_t word_1BD356[];
// 1BDF54: using guessed type int16_t word_1BDF54[];
// 1BEB54: using guessed type int dword_1BEB54;


//----- (00139D7E) --------------------------------------------------------
int __fastcall sub_139D7E(int a1, int a2, unsigned int a3)
{
  int result; // eax
  int v5; // [esp+8h] [ebp-24h]
  int n; // [esp+8h] [ebp-24h]
  uint16_t v7; // [esp+14h] [ebp-18h]
  uint16_t k; // [esp+18h] [ebp-14h]
  uint16_t i; // [esp+18h] [ebp-14h]
  uint16_t j; // [esp+18h] [ebp-14h]
  uint16_t m; // [esp+18h] [ebp-14h]
  uint8_t v12; // [esp+24h] [ebp-8h]
  uint8_t v13; // [esp+24h] [ebp-8h]
  uint8_t v14; // [esp+24h] [ebp-8h]
  uint8_t v15; // [esp+28h] [ebp-4h]
  uint8_t v16; // [esp+28h] [ebp-4h]
  uint8_t v17; // [esp+28h] [ebp-4h]

  if ( a3 )
  {
    if ( a3 <= 1u )
    {
      for ( i = HIWORD(dword_1BD352[3 * a2]); i <= *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16; ++i )
      {
        if ( i == dword_1BD352[3 * a2] >> 16 )
        {
          byte_1BD154[i] = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF56[i] + 2)
                         - *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[i] + 2);
        }
        else if ( i == *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16 )
        {
          byte_1BD154[i] = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[i] + 2)
                         - *(_BYTE *)(4 * (uint16_t)word_1BDF52[i] + a1 + 2);
        }
        else
        {
          v13 = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[i] + 2)
              - *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF52[i] + 2);
          v16 = *(_BYTE *)(4 * (uint16_t)word_1BDF56[i] + a1 + 2)
              - *(_BYTE *)(4 * (uint16_t)word_1BDF54[i] + a1 + 2);
          if ( v13 < v16 )
            byte_1BD154[i] = v16;
          else
            byte_1BD154[i] = v13;
        }
        if ( !byte_1BD154[i] )
          byte_1BD154[i] = 1;
      }
    }
    else if ( a3 == 2 )
    {
      for ( j = HIWORD(dword_1BD352[3 * a2]); j <= *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16; ++j )
      {
        if ( j == dword_1BD352[3 * a2] >> 16 )
        {
          byte_1BD154[j] = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF56[j] + 3)
                         - *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[j] + 3);
        }
        else if ( j == *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16 )
        {
          byte_1BD154[j] = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[j] + 3)
                         - *(_BYTE *)(4 * (uint16_t)word_1BDF52[j] + a1 + 3);
        }
        else
        {
          v14 = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[j] + 3)
              - *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF52[j] + 3);
          v17 = *(_BYTE *)(4 * (uint16_t)word_1BDF56[j] + a1 + 3)
              - *(_BYTE *)(4 * (uint16_t)word_1BDF54[j] + a1 + 3);
          if ( v14 < v17 )
            byte_1BD154[j] = v17;
          else
            byte_1BD154[j] = v14;
        }
        if ( !byte_1BD154[j] )
          byte_1BD154[j] = 1;
      }
    }
  }
  else
  {
    for ( k = HIWORD(dword_1BD352[3 * a2]); k <= *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16; ++k )
    {
      if ( k == dword_1BD352[3 * a2] >> 16 )
      {
        byte_1BD154[k] = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF56[k] + 1)
                       - *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[k] + 1);
      }
      else if ( k == *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16 )
      {
        byte_1BD154[k] = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[k] + 1)
                       - *(_BYTE *)(4 * (uint16_t)word_1BDF52[k] + a1 + 1);
      }
      else
      {
        v12 = *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF54[k] + 1)
            - *(_BYTE *)(a1 + 4 * (uint16_t)word_1BDF52[k] + 1);
        v15 = *(_BYTE *)(4 * (uint16_t)word_1BDF56[k] + a1 + 1)
            - *(_BYTE *)(4 * (uint16_t)word_1BDF54[k] + a1 + 1);
        if ( v12 < v15 )
          byte_1BD154[k] = v15;
        else
          byte_1BD154[k] = v12;
      }
      if ( !byte_1BD154[k] )
        byte_1BD154[k] = 1;
    }
  }
  v5 = 0;
  for ( m = HIWORD(dword_1BD352[3 * a2]); m <= *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16; ++m )
    v5 += (uint8_t)byte_1BD154[m];
  v7 = HIWORD(dword_1BD352[3 * a2]);
  for ( n = v5 / 2 - (uint8_t)byte_1BD154[v7];
        n > 0 && v7 < *(int *)((char *)&dword_1BD352[3 * a2] + 2) >> 16;
        n -= (uint8_t)byte_1BD154[v7] )
  {
    ++v7;
  }
  HIWORD(dword_1BD352[3 * (uint16_t)dword_1BEB54]) = v7 + 1;
  word_1BD356[6 * (uint16_t)dword_1BEB54] = word_1BD356[6 * a2];
  word_1BD358[6 * (uint16_t)dword_1BEB54] = word_1BD358[6 * a2] + 1;
  word_1BD356[6 * a2] = v7;
  ++word_1BD358[6 * a2];
  sub_13A993((int)&dword_1BD352[3 * a2] + 2, a1);
  result = sub_13A993((int)&dword_1BD352[3 * (uint16_t)dword_1BEB54] + 2, a1);
  LOWORD(dword_1BEB54) = dword_1BEB54 + 1;
  return result;
}
// 1BD352: using guessed type int dword_1BD352[];
// 1BD356: using guessed type int16_t word_1BD356[];
// 1BD358: using guessed type int16_t word_1BD358[];
// 1BDF52: using guessed type int16_t word_1BDF52[];
// 1BDF54: using guessed type int16_t word_1BDF54[];
// 1BDF56: using guessed type int16_t word_1BDF56[511];
// 1BEB54: using guessed type int dword_1BEB54;


//----- (0013A4A9) --------------------------------------------------------
int __fastcall sub_13A4A9(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int n; // [esp+14h] [ebp-Ch]
  int i; // [esp+14h] [ebp-Ch]
  int k; // [esp+14h] [ebp-Ch]
  int16_t ii; // [esp+18h] [ebp-8h]
  int16_t j; // [esp+18h] [ebp-8h]
  int16_t m; // [esp+18h] [ebp-8h]
  int16_t v12; // [esp+1Ch] [ebp-4h]
  int16_t v13; // [esp+1Ch] [ebp-4h]
  int16_t v14; // [esp+1Ch] [ebp-4h]

  result = a4;
  if ( (_WORD)a4 )
  {
    if ( (uint16_t)a4 <= 1u )
    {
      v13 = 1;
      for ( i = 0; ; ++i )
      {
        result = i;
        if ( (int16_t)i >= a3 )
          break;
        result = v13;
        if ( v13 != 1 )
          break;
        v13 = 0;
        for ( j = 0; j < a3 - 1; ++j )
        {
          if ( *(_BYTE *)(a1 + 4 * *(int16_t *)(a2 + 2 * j) + 2) > *(_BYTE *)(4 * (*(int *)(a2 + 2 * j) >> 16) + a1 + 2) )
          {
            sub_133111((int16_t *)(a2 + 2 * j), (int16_t *)(2 * j + 2 + a2));
            v13 = 1;
          }
        }
      }
    }
    else if ( (_WORD)a4 == 2 )
    {
      v14 = 1;
      for ( k = 0; ; ++k )
      {
        result = k;
        if ( (int16_t)k >= a3 )
          break;
        result = v14;
        if ( v14 != 1 )
          break;
        v14 = 0;
        for ( m = 0; m < a3 - 1; ++m )
        {
          if ( *(_BYTE *)(a1 + 4 * *(int16_t *)(a2 + 2 * m) + 3) > *(_BYTE *)(4 * (*(int *)(a2 + 2 * m) >> 16) + a1 + 3) )
          {
            sub_133111((int16_t *)(a2 + 2 * m), (int16_t *)(2 * m + 2 + a2));
            v14 = 1;
          }
        }
      }
    }
  }
  else
  {
    v12 = 1;
    for ( n = 0; ; ++n )
    {
      result = n;
      if ( (int16_t)n >= a3 )
        break;
      result = v12;
      if ( v12 != 1 )
        break;
      v12 = 0;
      for ( ii = 0; ii < a3 - 1; ++ii )
      {
        if ( *(_BYTE *)(a1 + 4 * *(int16_t *)(a2 + 2 * ii) + 1) > *(_BYTE *)(4 * (*(int *)(a2 + 2 * ii) >> 16) + a1 + 1) )
        {
          sub_133111((int16_t *)(a2 + 2 * ii), (int16_t *)(2 * ii + 2 + a2));
          v12 = 1;
        }
      }
    }
  }
  return result;
}


//----- (0013A711) --------------------------------------------------------
int __fastcall sub_13A711( int a1)
{
  uint8_t v3; // [esp+8h] [ebp-Ch]
  uint8_t v4; // [esp+Ch] [ebp-8h]
  uint8_t v5; // [esp+10h] [ebp-4h]

  v3 = byte_1BD35B[12 * a1] - byte_1BD35A[12 * a1];
  v4 = byte_1BD35F[12 * a1] - byte_1BD35E[12 * a1];
  v5 = byte_1BD35D[12 * a1] - byte_1BD35C[12 * a1];
  if ( v3 >= v5 && v3 >= v4 )
    return 0;
  if ( v5 >= v3 && v5 >= v4 )
    return 1;
  return 2;
}


//----- (0013A7CC) --------------------------------------------------------
int __fastcall sub_13A7CC(int a1, int a2)
{
  int result; // eax
  int16_t i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < a2; ++i )
    word_1BDF54[i] = i;
  HIWORD(dword_1BD352[0]) = 0;
  word_1BD356[0] = a2 - 1;
  word_1BD358[0] = 0;
  result = sub_13A993((int)dword_1BD352 + 2, a1);
  LOWORD(dword_1BEB54) = 1;
  return result;
}
// 1BD352: using guessed type int dword_1BD352[];
// 1BD356: using guessed type int16_t word_1BD356[];
// 1BD358: using guessed type int16_t word_1BD358[];
// 1BDF54: using guessed type int16_t word_1BDF54[];
// 1BEB54: using guessed type int dword_1BEB54;


//----- (0013A84F) --------------------------------------------------------
int sub_13A84F()
{
  int i; // [esp+4h] [ebp-1Ch]
  int v2; // [esp+8h] [ebp-18h]
  int16_t v3; // [esp+Ch] [ebp-14h]
  uint8_t v4; // [esp+14h] [ebp-Ch]
  uint8_t v5; // [esp+18h] [ebp-8h]
  uint8_t v6; // [esp+1Ch] [ebp-4h]

  v2 = -1;
  v3 = 0;
  for ( i = 0; (int16_t)i < (int)(uint16_t)dword_1BEB54; ++i )
  {
    if ( HIWORD(dword_1BD352[3 * (int16_t)i]) != word_1BD356[6 * (int16_t)i] && word_1BD358[6 * (int16_t)i] < 30000 )
    {
      v6 = byte_1BD35B[12 * (int16_t)i] - byte_1BD35A[12 * (int16_t)i];
      v5 = byte_1BD35F[12 * (int16_t)i] - byte_1BD35E[12 * (int16_t)i];
      v4 = byte_1BD35D[12 * (int16_t)i] - byte_1BD35C[12 * (int16_t)i];
      if ( v6 > v3 )
      {
        v3 = v6;
        v2 = i;
      }
      if ( v4 > v3 )
      {
        v3 = v4;
        v2 = i;
      }
      if ( v5 > v3 )
      {
        v3 = v5;
        v2 = i;
      }
    }
  }
  return v2;
}
// 1BD352: using guessed type int dword_1BD352[];
// 1BD356: using guessed type int16_t word_1BD356[];
// 1BD358: using guessed type int16_t word_1BD358[];
// 1BEB54: using guessed type int dword_1BEB54;


//----- (0013A993) --------------------------------------------------------
int __fastcall sub_13A993(int a1, int a2)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-14h]
  int16_t v5; // [esp+Ch] [ebp-10h]
  uint8_t v6; // [esp+10h] [ebp-Ch]
  uint8_t v7; // [esp+14h] [ebp-8h]
  uint8_t v8; // [esp+18h] [ebp-4h]

  v3 = a1;
  *(_BYTE *)(a1 + 6) = -1;
  *(_BYTE *)(a1 + 7) = 0;
  *(_BYTE *)(a1 + 8) = -1;
  *(_BYTE *)(a1 + 9) = 0;
  *(_BYTE *)(a1 + 10) = -1;
  *(_BYTE *)(a1 + 11) = 0;
  LOWORD(a1) = *(_WORD *)a1;
  for ( i = a1; ; ++i )
  {
    result = i;
    if ( (int16_t)i > *(int16_t *)(v3 + 2) )
      break;
    v5 = word_1BDF54[(int16_t)i];
    v7 = *(_BYTE *)(a2 + 4 * v5 + 1);
    if ( v7 < *(_BYTE *)(v3 + 6) )
      *(_BYTE *)(v3 + 6) = v7;
    if ( v7 > *(_BYTE *)(v3 + 7) )
      *(_BYTE *)(v3 + 7) = v7;
    v8 = *(_BYTE *)(a2 + 4 * v5 + 2);
    if ( v8 < *(_BYTE *)(v3 + 8) )
      *(_BYTE *)(v3 + 8) = v8;
    if ( v8 > *(_BYTE *)(v3 + 9) )
      *(_BYTE *)(v3 + 9) = v8;
    v6 = *(_BYTE *)(a2 + 4 * v5 + 3);
    if ( v6 < *(_BYTE *)(v3 + 10) )
      *(_BYTE *)(v3 + 10) = v6;
    if ( v6 > *(_BYTE *)(v3 + 11) )
      *(_BYTE *)(v3 + 11) = v6;
  }
  return result;
}
// 1BDF54: using guessed type int16_t word_1BDF54[];


//----- (0013AAC1) --------------------------------------------------------
void sub_13AAC1()
{
  HIWORD(dword_1BEB54) = 0;
}
// 1BEB54: using guessed type int dword_1BEB54;


//----- (0013AAE9) --------------------------------------------------------
int __fastcall sub_13AAE9(int a1, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  dword_1BC2A8 = a1;
  if ( (*(_BYTE *)(a1 + 11) & 0x10) == 0 )
    sub_126487(aPaletteReducti, a2);
  dword_1BC2A4 = 4 * (*(int *)(dword_1BC2A8 + 4) >> 16) + dword_1BC2A8 + 16;
  v4 = dword_1BC2A4 + 4;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= *(int16_t *)(dword_1BC2A4 + 2) )
      break;
    byte_1BE355[4 * (dword_1BEB54 >> 16)] = *(_BYTE *)(v4 + (int16_t)(4 * i) + 1);
    byte_1BE356[4 * (dword_1BEB54 >> 16)] = *(_BYTE *)(v4 + (int16_t)(4 * i) + 2);
    v3 = 4 * (dword_1BEB54 >> 16);
    byte_1BE357[v3] = *(_BYTE *)(v4 + (int16_t)(4 * i) + 3);
    ++HIWORD(dword_1BEB54);
    if ( dword_1BEB54 >> 16 >= 512 )
      sub_126487(aTooManyColorsT_1, v3);
  }
  return result;
}
// 1BC2A4: using guessed type int dword_1BC2A4;
// 1BC2A8: using guessed type int dword_1BC2A8;
// 1BEB54: using guessed type int dword_1BEB54;


//----- (0013AC01) --------------------------------------------------------
int __fastcall sub_13AC01( int a1, int a2)
{
  int result; // eax
  int i; // [esp+8h] [ebp-4h]

  if ( SHIWORD(dword_1BEB54) > a2 )
    sub_139AF3((int)&unk_1BE354, 0, SHIWORD(dword_1BEB54), a2);
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( (int16_t)i >= a2 )
      break;
    byte_1BB358[4 * (int16_t)i + 4 * a1] = 1;
    byte_1BB359[4 * (int16_t)i + 4 * a1] = byte_1BE355[4 * (int16_t)i];
    byte_1BB35A[4 * (int16_t)i + 4 * a1] = byte_1BE356[4 * (int16_t)i];
    byte_1BB35B[4 * (int16_t)i + 4 * a1] = byte_1BE357[4 * (int16_t)i];
  }
  return result;
}
// 1BEB54: using guessed type int dword_1BEB54;


//----- (0013AD33) --------------------------------------------------------
int __fastcall sub_13AD33(int16_t *a1, int a2)
{
  int result; // eax
  int i; // [esp+8h] [ebp-8h]
  _DWORD *v5; // [esp+Ch] [ebp-4h]

  memset(a1, 0, 4172);
  *((_DWORD *)a1 + 2) = fopen(a2, aRB);
  result = (int)a1;
  if ( *((_DWORD *)a1 + 2) )
  {
    fread(a1, 8, 1, *((_DWORD *)a1 + 2));
    if ( (uint16_t)a1[1] == 65197 )
    {
      fread(a1 + 1026, 510, 4, *((_DWORD *)a1 + 2));
      v5 = a1 + 1028;
      *((_DWORD *)a1 + 3) = *((_DWORD *)a1 + 513);
      for ( i = 1; *a1 + 1 > i; ++i )
      {
        *(_DWORD *)&a1[4 * i + 6] = *v5;
        *(_DWORD *)&a1[4 * i + 4] = *v5++ - *(_DWORD *)&a1[4 * i + 2];
      }
      return strcpy(a1 + 2046, a2);
    }
    else
    {
      fclose(*((_DWORD *)a1 + 2));
      result = (int)a1;
      *((_DWORD *)a1 + 2) = 0;
    }
  }
  return result;
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 13F37F: using guessed type int __fastcall strcpy(_DWORD, _DWORD);


//----- (0013AE74) --------------------------------------------------------
int __fastcall sub_13AE74(int a1)
{
  if ( *(_DWORD *)(a1 + 8) )
    fclose(*(_DWORD *)(a1 + 8));
  return memset(a1, 0, 4172);
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);


//----- (0013AEBB) --------------------------------------------------------
int __fastcall sub_13AEBB(int result, int a2, int a3)
{
  int v3; // edx
  char v4[40]; // [esp+0h] [ebp-34h] BYREF
  int16_t *v5; // [esp+28h] [ebp-Ch]
  int v6; // [esp+2Ch] [ebp-8h]
  int v7; // [esp+30h] [ebp-4h]

  v5 = (int16_t *)result;
  v7 = a2;
  v6 = a3;
  if ( result )
  {
    result = (int)v5;
    if ( *((_DWORD *)v5 + 2) )
    {
      v3 = v7 + 1;
      if ( v7 + 1 > *v5 )
      {
        sprintf(v4, "ERROR: Play_Sound(%d)", v7);
        sub_126487(v4, v3);
      }
      // DECOMP_TODO - NIZKA JISTOTA (vlna 07): fseek() melo 0 parametru.
      // Tabulka velikosti zaznamu je jasne na "v5[4*v7+8]" (DWORD, cteno
      // pres int16_t* indexovani). Hypoteza: jde o prokladanou tabulku
      // {offset,size} DWORD paru (bezny format), takze offset by byl o
      // 4 bajty (2 int16_t jednotky) driv - "v5[4*v7+6]". NEOVERENO -
      // spatny odhad zpusobi prehrani spatneho zvuku, ne pad, ale
      // potrebuje potvrzeni pred oznacenim za hotove.
      fseek(*((_DWORD *)v5 + 2), *(_DWORD *)&v5[4 * v7 + 6], SEEK_SET);
      return fread(v6, *(_DWORD *)&v5[4 * v7 + 8], 1, *((_DWORD *)v5 + 2));
    }
  }
  return result;
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (0013AFD2) --------------------------------------------------------
int __fastcall sub_13AFD2(int a1, int a2)
{
  return *(_DWORD *)(a1 + 8 * a2 + 16);
}


//----- (0013B009) --------------------------------------------------------
int __fastcall sub_13B009(int a1, int a2)
{
  return *(_DWORD *)(a1 + 8 * a2 + 12);
}


//----- (0013B9BD) --------------------------------------------------------
int __fastcall sub_13B9BD(int a1, int a2)
{
  int v2; // edx
  int result; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+10h] [ebp-4h]

  v5 = a2 + 12;
  dword_1BF35C = a2 + 24;
  dword_1BF358 = a1;
  v2 = a2 + 24;
  if ( v2 > *(_DWORD *)(a1 - 12 + 4) )
    sub_126487(aDriveSwapReqdT, v2);
  if ( GetFreeDiskSpace_111763() < dword_1BF35C )
    sub_126487(aInsufficientDi, v2);
  v6 = fopen(aTempTmp, aWb_6);
  if ( !v6 )
    sub_126487(aErrorInSwapFil, (int)aWb_6);
  fwrite(a1 - 12, dword_1BF35C, 1, v6);
  fclose(v6);
  result = v5;
  *(_DWORD *)(a1 - 12 + 4) = v5;
  return result;
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 1BF358: using guessed type int dword_1BF358;
// 1BF35C: using guessed type int dword_1BF35C;


//----- (0013BA86) --------------------------------------------------------
int sub_13BA86()
{
  int v1; // [esp+4h] [ebp-Ch]
  int v2; // [esp+Ch] [ebp-4h]

  v1 = dword_1BF358;
  v2 = fopen(aTempTmp, aRb_6);
  if ( !v2 )
    sub_126487(aErrorInSwapFil, (int)aRb_6);
  fread(v1 - 12, dword_1BF35C, 1, v2);
  return fclose(v2);
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 1BF358: using guessed type int dword_1BF358;
// 1BF35C: using guessed type int dword_1BF35C;


//----- (0013BAFB) --------------------------------------------------------
int __fastcall sub_13BAFB( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10,
        int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19)
{
  int64_t v19; // rax
  int16_t v23; // [esp+10h] [ebp-40h]
  int16_t v24; // [esp+14h] [ebp-3Ch]
  char v25; // [esp+18h] [ebp-38h]
  int16_t v26; // [esp+1Ch] [ebp-34h]
  int16_t v27; // [esp+20h] [ebp-30h]
  int v28; // [esp+24h] [ebp-2Ch]
  int16_t v29; // [esp+48h] [ebp-8h]
  int16_t v30; // [esp+4Ch] [ebp-4h]

  if ( a10 == 1 )
  {
    v25 = a5 + 1;
    LOBYTE(v26) = a5;
    if ( a12 == 1 )
    {
      v25 = a5 + 4;
      v26 = a5 + 1;
      if ( (int16_t)(a5 + 4) > a6 )
        v25 = a6;
      if ( v26 > a6 )
        LOBYTE(v26) = a6;
    }
    sub_12972D(a3, a4, a5 + a16);
    sub_12972D(a3, a4 - 1, v25);
    sub_12972D(a3, a4 + 1, v25);
    sub_12972D(a3 - 1, a4, v25);
    sub_12972D(a3 + 1, a4, v25);
    sub_12972D(a3 - 1, a4 - 1, v26);
    sub_12972D(a3 - 1, a4 + 1, v26);
    sub_12972D(a3 + 1, a4 - 1, v26);
    sub_12972D(a3 + 1, a4 + 1, v26);
    if ( !a13 )
    {
      sub_12972D(a1, a2, a5 + a16);
      sub_12972D(a1, a2 - 1, v25);
      sub_12972D(a1, a2 + 1, v25);
      sub_12972D(a1 - 1, a2, v25);
      sub_12972D(a1 + 1, a2, v25);
      sub_12972D(a1 - 1, a2 - 1, v26);
      sub_12972D(a1 - 1, a2 + 1, v26);
      sub_12972D(a1 + 1, a2 - 1, v26);
      sub_12972D(a1 + 1, a2 + 1, v26);
    }
  }
  abs(a3 - a1);
  v19 = abs(a4 - a2);
  if ( SHIDWORD(v19) <= (int)v19 )
  {
    v29 = 1;
    v30 = 0;
  }
  else
  {
    v29 = 0;
    v30 = 1;
  }
  v24 = a19 + a5;
  v23 = a18 - a19;
  if ( a12 == 1 )
    v23 += 3;
  if ( !a15 )
  {
    sub_13BEC4(a1 - v29, a2 - v30, a3 - v29, a4 - v30, v24, v23, a7, a8 / 2, a5, a5 + a6 - 1, 0, a14, a9, 0);
    sub_13BEC4(v29 + a1, v30 + a2, v29 + a3, v30 + a4, v24, v23, a7, a8 / 2, a5, a5 + a6 - 1, 0, a14, a9, 0);
  }
  LOWORD(v28) = a17 + a5;
  v27 = a16 - a17;
  if ( !a13 )
  {
    v28 = (int16_t)v28 + ((3 * v27 - (__CFSHL__((3 * v27) >> 31, 2) + 4 * ((3 * v27) >> 31))) >> 2);
    v27 = 0;
  }
  return sub_13BEC4(a1, a2, a3, a4, v28, v27, a7, a8, a5, a5 + a6 - 1, a13, a14, a9, a12);
}
// 14D139: using guessed type int64_t __fastcall abs(_DWORD);


//----- (0013BEC4) --------------------------------------------------------
int __fastcall sub_13BEC4( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10,
        int a11, int a12, int a13, int a14)
{
  int v15; // [esp+0h] [ebp-4Ch]
  int v16; // [esp+4h] [ebp-48h]
  int v17; // [esp+8h] [ebp-44h]
  int v18; // [esp+14h] [ebp-38h]
  int v19; // [esp+1Ch] [ebp-30h]
  int v20; // [esp+20h] [ebp-2Ch]
  int v21; // [esp+24h] [ebp-28h]
  int v22; // [esp+28h] [ebp-24h]
  unsigned int v23; // [esp+34h] [ebp-18h]
  int j; // [esp+38h] [ebp-14h]
  int i; // [esp+38h] [ebp-14h]
  int k; // [esp+38h] [ebp-14h]
  int m; // [esp+38h] [ebp-14h]
  int ii; // [esp+38h] [ebp-14h]
  int n; // [esp+38h] [ebp-14h]
  int jj; // [esp+38h] [ebp-14h]

  v21 = sub_12484C();
  v23 = 2 * a8 + 1;
  v19 = a3 - a1;
  v16 = a4 - a2;
  if ( v19 < 0 )
    v19 = a1 - a3;
  if ( v16 < 0 )
    v16 = a2 - a4;
  if ( v19 <= v16 )
    v15 = v16 + 1;
  else
    v15 = v19 + 1;
  v20 = (a6 << 16) / v15;
  v17 = 32000 / v15;
  LOBYTE(v22) = 0;
  if ( a4 >= a2 )
  {
    for ( i = 0; i <= v15; ++i )
    {
      byte_1BC89D[i] = v22 + BYTE2(v17) + a5;
      v17 += v20;
      if ( (int)sub_1247A0(0x64u) >= a7 )
        LOBYTE(v22) = 0;
      else
        v22 = sub_1247A0(v23) - a8;
    }
    byte_1BC89C[0] = a5;
    byte_1BC89C[v15] = a6 + a5 - 1;
  }
  else
  {
    for ( j = 0; j <= v15; ++j )
    {
      byte_1BC89D[v15 - j] = v22 + BYTE2(v17) + a5;
      v17 += v20;
      if ( (int)sub_1247A0(0x64u) >= a7 )
        LOBYTE(v22) = 0;
      else
        v22 = sub_1247A0(v23) - a8;
    }
    byte_1BC89C[v15] = a5;
    byte_1BC89C[0] = a6 + a5 - 1;
  }
  if ( a12 == 1 )
  {
    for ( k = a13 % 8; v15 + 2 > k; k += 8 )
      byte_1BC89C[k] += 3;
  }
  for ( m = 0; v15 + 2 > m; ++m )
  {
    if ( (uint8_t)byte_1BC89C[m] < a9 )
      byte_1BC89C[m] = a9;
    if ( (uint8_t)byte_1BC89C[m] > a10 )
      byte_1BC89C[m] = a10;
  }
  if ( a14 )
  {
    if ( a4 < a2 )
    {
      for ( n = 0; n <= 5; ++n )
        byte_1BC89D[n] += 3 / a14;
    }
    else if ( v15 > 5 )
    {
      for ( ii = 0; ii <= 5; ++ii )
        byte_1BC89B[v15 - ii] += 3 / a14;
    }
  }
  v18 = a6 + a5;
  for ( jj = 0; v15 + 2 > jj; ++jj )
  {
    if ( (uint8_t)byte_1BC89C[jj] > v18 )
      byte_1BC89C[jj] = v18;
  }
  sub_136A2F(a1, a2, a3, a4, (int)byte_1BC89C, 0);
  return sub_124820(v21);
}


//----- (0013C22C) --------------------------------------------------------
int __fastcall sub_13C22C( int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9,
        int a10, int a11, int a12, int a13, int a14,
        int a15, int a16, int a17, int a18, int a19, int a20, int a21)
{
  int16_t v23; // [esp+20h] [ebp-54h]
  int v24; // [esp+24h] [ebp-50h]
  int16_t v25; // [esp+28h] [ebp-4Ch]
  int16_t v26; // [esp+28h] [ebp-4Ch]
  int16_t v27; // [esp+2Ch] [ebp-48h]
  int16_t v28; // [esp+2Ch] [ebp-48h]
  int16_t v29; // [esp+30h] [ebp-44h]
  int16_t v30; // [esp+30h] [ebp-44h]
  int16_t v31; // [esp+34h] [ebp-40h]
  int16_t v32; // [esp+34h] [ebp-40h]
  int16_t v33; // [esp+38h] [ebp-3Ch]
  int16_t v34; // [esp+38h] [ebp-3Ch]
  int16_t v35; // [esp+3Ch] [ebp-38h]
  int16_t v36; // [esp+3Ch] [ebp-38h]
  int16_t v37; // [esp+40h] [ebp-34h]
  int16_t v38; // [esp+40h] [ebp-34h]
  int16_t v39; // [esp+44h] [ebp-30h]
  int16_t v40; // [esp+44h] [ebp-30h]
  int16_t v41; // [esp+48h] [ebp-2Ch]
  int16_t v42; // [esp+4Ch] [ebp-28h]
  int16_t v43; // [esp+50h] [ebp-24h]
  int16_t v44; // [esp+54h] [ebp-20h]
  int16_t v45; // [esp+58h] [ebp-1Ch]
  int16_t v46; // [esp+5Ch] [ebp-18h]
  int16_t v47; // [esp+60h] [ebp-14h]
  int16_t v48; // [esp+64h] [ebp-10h]
  int v49; // [esp+70h] [ebp-4h]

  v49 = 2 * ((int16_t)(360 - sub_1384B9(a3 - a1, a4 - a2) + 11) % 360) / 45;
  if ( (int16_t)v49 <= 15 )
  {
    if ( (v49 & 0x8000u) != 0 )
      LOWORD(v49) = 0;
  }
  else
  {
    LOWORD(v49) = 15;
  }
  if ( a11 == 1 )
  {
    v25 = a1;
    v29 = a2;
    v33 = word_184680[12 * (int16_t)v49] + a3;
    v37 = word_184682[12 * (int16_t)v49] + a4;
    v27 = a1;
    v31 = a2;
  }
  else
  {
    v25 = word_184800[12 * (int16_t)v49] + a1;
    v29 = word_184802[12 * (int16_t)v49] + a2;
    v33 = word_184680[12 * (int16_t)v49] + a3;
    v37 = word_184682[12 * (int16_t)v49] + a4;
    v27 = word_184804[12 * (int16_t)v49] + a1;
    v31 = word_184806[12 * (int16_t)v49] + a2;
  }
  v35 = word_184684[12 * (int16_t)v49] + a3;
  v39 = word_184686[12 * (int16_t)v49] + a4;
  sub_13BEC4(v25, v29, v33, v37, a21 + a5, a20 - a21, a7, a8 / 2, a5, a6 + a5 - 1, 0, a14, a9, 0);
  sub_13BEC4(v27, v31, v35, v39, a21 + a5, a20 - a21, a7, a8 / 2, a5, a6 + a5 - 1, 0, a14, a9, 0);
  if ( a11 == 1 )
  {
    v26 = a1;
    v30 = a2;
    v34 = word_184670[12 * (int16_t)v49] + a3;
    v38 = word_184672[12 * (int16_t)v49] + a4;
    v28 = a1;
    v32 = a2;
    v36 = word_184674[12 * (int16_t)v49] + a3;
    v40 = word_184676[12 * (int16_t)v49] + a4;
    v41 = a1;
    v43 = a2;
    v42 = word_184678[12 * (int16_t)v49] + a3;
    v44 = word_18467A[12 * (int16_t)v49] + a4;
    v45 = a1;
    v47 = a2;
  }
  else
  {
    v26 = word_1847F0[12 * (int16_t)v49] + a1;
    v30 = word_1847F2[12 * (int16_t)v49] + a2;
    v34 = word_184670[12 * (int16_t)v49] + a3;
    v38 = word_184672[12 * (int16_t)v49] + a4;
    v28 = word_1847F4[12 * (int16_t)v49] + a1;
    v32 = word_1847F6[12 * (int16_t)v49] + a2;
    v36 = word_184674[12 * (int16_t)v49] + a3;
    v40 = word_184676[12 * (int16_t)v49] + a4;
    v41 = word_1847F8[12 * (int16_t)v49] + a1;
    v43 = word_1847FA[12 * (int16_t)v49] + a2;
    v42 = word_184678[12 * (int16_t)v49] + a3;
    v44 = word_18467A[12 * (int16_t)v49] + a4;
    v45 = word_1847FC[12 * (int16_t)v49] + a1;
    v47 = word_1847FE[12 * (int16_t)v49] + a2;
  }
  v46 = word_18467C[12 * (int16_t)v49] + a3;
  v48 = word_18467E[12 * (int16_t)v49] + a4;
  sub_13BEC4(v26, v30, v34, v38, a19 + a5, a18 - a19, a7, a8 / 2, a5, a6 + a5 - 1, 0, a14, a9, a12);
  sub_13BEC4(v28, v32, v36, v40, a19 + a5, a18 - a19, a7, a8 / 2, a5, a6 + a5 - 1, 0, a14, a9, a12);
  sub_13BEC4(v41, v43, v42, v44, a19 + a5, a18 - a19, a7, a8 / 2, a5, a6 + a5 - 1, 0, a14, a9, a12);
  sub_13BEC4(v45, v47, v46, v48, a19 + a5, a18 - a19, a7, a8 / 2, a5, a6 + a5 - 1, 0, a14, a9, a12);
  LOWORD(v24) = a17 + a5;
  v23 = a16 - a17;
  if ( !a13 )
  {
    v24 = (int16_t)v24 + ((3 * v23 - (__CFSHL__((3 * v23) >> 31, 2) + 4 * ((3 * v23) >> 31))) >> 2);
    v23 = 0;
  }
  return sub_13BEC4(a1, a2, a3, a4, v24, v23, a7, a8, a5, a6 + a5 - 1, a13, a14, a9, a12);
}
// 184670: using guessed type int16_t word_184670[];
// 184672: using guessed type int16_t word_184672[];
// 184674: using guessed type int16_t word_184674[];
// 184676: using guessed type int16_t word_184676[];
// 184678: using guessed type int16_t word_184678[];
// 18467A: using guessed type int16_t word_18467A[];
// 18467C: using guessed type int16_t word_18467C[];
// 18467E: using guessed type int16_t word_18467E[];
// 184680: using guessed type int16_t word_184680[];
// 184682: using guessed type int16_t word_184682[];
// 184684: using guessed type int16_t word_184684[];
// 184686: using guessed type int16_t word_184686[181];
// 1847F0: using guessed type int16_t word_1847F0[];
// 1847F2: using guessed type int16_t word_1847F2[];
// 1847F4: using guessed type int16_t word_1847F4[];
// 1847F6: using guessed type int16_t word_1847F6[];
// 1847F8: using guessed type int16_t word_1847F8[];
// 1847FA: using guessed type int16_t word_1847FA[];
// 1847FC: using guessed type int16_t word_1847FC[];
// 1847FE: using guessed type int16_t word_1847FE[];
// 184800: using guessed type int16_t word_184800[];
// 184802: using guessed type int16_t word_184802[];
// 184804: using guessed type int16_t word_184804[];
// 184806: using guessed type int16_t word_184806[181];


//----- (0013CC5B) --------------------------------------------------------
int __fastcall sub_13CC5B(int a1, int (__fastcall *a2)(_DWORD, _DWORD, _DWORD, _DWORD), int a3, int a4)
{
  int v4; // eax

  if ( !sub_13D1C7(a1) )
    return 0;
  LOBYTE(v4) = sub_14E8B0(0x8000, (int)a2, a3, a4);
  if ( !v4 )
    return 0;
  dword_1BF388 = a2;
  byte_184980 = 1;
  return 1;
}
// 13CC99: variable 'v4' is possibly undefined
// 184980: using guessed type char byte_184980;
// 1BF388: using guessed type int (__fastcall *dword_1BF388)(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (0013CCC5) --------------------------------------------------------
int sub_13CCC5()
{
  int result; // eax

  if ( byte_184980 )
  {
    sub_14E961();
    return sub_13D266();
  }
  return result;
}
// 184980: using guessed type char byte_184980;


//----- (0013CDA5) --------------------------------------------------------
int sub_13CDA5()
{
  if ( !dword_18497C )
    return 0;
  word_189708 = 2;
  byte_1BF38C = 1;
  sub_1523FC(dword_18497C, aAtS01);
  return 1;
}
// 18497C: using guessed type int dword_18497C;
// 189708: using guessed type int16_t word_189708;
// 1BF38C: using guessed type char byte_1BF38C;


//----- (0013CE01) --------------------------------------------------------
bool __fastcall sub_13CE01(int a1, int a2, int a3, int a4)
{
  int v4; // edx

  word_189708 = 1;
  byte_1BF38C = 2;
  if ( !dword_18497C )
    return 0;
  sub_1523FC(dword_18497C, (char *)a1);
  sub_1523D8(10000, 0);
  sub_1523FC(dword_18497C, (char *)(a1 + 30));
  sub_1523D8(10000, 0);
  if ( *(_BYTE *)(a1 + 130) == 1 )
  {
    v4 = 0;
    sub_151FD4(dword_18497C, 0);
  }
  else
  {
    v4 = 1;
    sub_151FD4(dword_18497C, 1u);
  }
  sub_1527B0(dword_18497C, v4, a3, a4);
  return !sub_151FF8(dword_18497C, (char *)(a1 + 90));
}
// 18497C: using guessed type int dword_18497C;
// 189708: using guessed type int16_t word_189708;
// 1BF38C: using guessed type char byte_1BF38C;


//----- (0013CED8) --------------------------------------------------------
int __fastcall sub_13CED8(_BYTE *a1, int a2, int a3)
{
  int result; // eax
  int v5; // [esp+10h] [ebp-8h]

  v5 = j___clock(a1, a2, a3);
  for ( *a1 = byte_17B0D8; ; *a1 = byte_17B0D8 )
  {
    sub_152690(dword_18497C, 60000, (int)a1, 80);
    strupr(a1);
    result = ((int (__fastcall *)(_BYTE *, char *))strstr)(a1, aNo);
    if ( result )
      break;
    result = ((int (__fastcall *)(_BYTE *, char *))strstr)(a1, aBusy);
    if ( result )
      break;
    result = ((int (__fastcall *)(_BYTE *, char *))strstr)(a1, aError);
    if ( result )
      break;
    if ( sub_13CFDD() || ((int (__fastcall *)(_BYTE *, char *))strstr)(a1, aConnect) )
    {
      result = (int)a1;
      *a1 = byte_17B0D8;
      return result;
    }
    if ( (unsigned int)j___clock(0, aConnect, a1) - v5 >= 0x1770 )
    {
      result = (int)a1;
      *a1 = byte_17B0D8;
      return result;
    }
  }
  return result;
}
// 13CF18: conditional instruction was optimized away because %var_C.4==0
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 13EE59: using guessed type int __fastcall strupr(_DWORD);
// 17B0D8: using guessed type char byte_17B0D8;
// 18497C: using guessed type int dword_18497C;


//----- (0013CFDD) --------------------------------------------------------
bool sub_13CFDD()
{
  return dword_18497C && sub_1527F4(dword_18497C);
}
// 18497C: using guessed type int dword_18497C;


//----- (0013D0F1) --------------------------------------------------------
int __fastcall sub_13D0F1(char *a1)
{
  if ( !dword_18497C )
    return 0;
  sub_13D190(0x2Bu);
  sub_13D190(0x2Bu);
  sub_13D190(0x2Bu);
  sub_1523D8(10000, 0);
  sub_1523FC(dword_18497C, a1);
  sub_1523D8(10000, 0);
  sub_1523FC(dword_18497C, a1 + 30);
  sub_1523D8(10000, 0);
  return 1;
}
// 18497C: using guessed type int dword_18497C;


//----- (0013D190) --------------------------------------------------------
int __fastcall sub_13D190( unsigned int a1)
{
  return (*(int (__fastcall **)(int, _DWORD))(dword_18497C + 35))(dword_18497C, a1);
}
// 18497C: using guessed type int dword_18497C;


//----- (0013D1C7) --------------------------------------------------------
int __fastcall sub_13D1C7(int a1)
{
  sub_152840(10240, 10240);
  *(_BYTE *)(a1 + 8) = 78;
  *(_DWORD *)(a1 + 9) = 8;
  *(_DWORD *)(a1 + 13) = 1;
  dword_18497C = (int)sub_153BD8(
                        *(_DWORD *)a1,
                        *(_DWORD *)(a1 + 4),
                        *(_BYTE *)(a1 + 8),
                        *(_DWORD *)(a1 + 9),
                        *(_DWORD *)(a1 + 13));
  if ( !*(_DWORD *)(dword_18497C + 14) )
    return 1;
  dword_18497C = 0;
  return 0;
}
// 18497C: using guessed type int dword_18497C;


//----- (0013D266) --------------------------------------------------------
int sub_13D266()
{
  int result; // eax

  if ( dword_18497C )
  {
    result = (*(int (__fastcall **)(int))(dword_18497C + 39))(dword_18497C);
    dword_18497C = 0;
  }
  return result;
}
// 18497C: using guessed type int dword_18497C;


//----- (0013D2A6) --------------------------------------------------------
int __fastcall sub_13D2A6( unsigned int a1)
{
  if ( !a1 )
    return 0;
  dword_184988 = nmalloc(a1);
  dword_1849D2 = nmalloc(a1);
  if ( !dword_184988 )
    return 0;
  word_18498C = a1;
  dword_184984 = 1;
  memset(&dword_1C0690, 0, 512);
  sub_13D75B();
  sub_13D805();
  return 1;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 13CB78: using guessed type int __fastcall nmalloc(_DWORD);
// 184984: using guessed type int dword_184984;
// 184988: using guessed type int dword_184988;
// 18498C: using guessed type int16_t word_18498C;
// 1849D2: using guessed type int dword_1849D2;
// 1C0690: using guessed type int dword_1C0690;


//----- (0013D344) --------------------------------------------------------
int sub_13D344()
{
  int result; // eax

  if ( dword_184988 )
    result = nfree(dword_184988);
  if ( dword_1849D2 )
    result = nfree(dword_1849D2);
  word_18498C = 0;
  dword_184984 = 0;
  return result;
}
// 13CAF6: using guessed type int __fastcall nfree(_DWORD);
// 184984: using guessed type int dword_184984;
// 184988: using guessed type int dword_184988;
// 18498C: using guessed type int16_t word_18498C;
// 1849D2: using guessed type int dword_1849D2;


//----- (0013D39C) --------------------------------------------------------
int __fastcall sub_13D39C(int a1)
{
  bool v2; // [esp+0h] [ebp-14h]
  int v4; // [esp+8h] [ebp-Ch]
  uint8_t *i; // [esp+Ch] [ebp-8h]

  v4 = 1;
  for ( i = (uint8_t *)dword_1C40EA; i; i = *(uint8_t **)(i + 30) )
  {
    if ( *i != word_189708 && !strcmp(i + 2, &byte_184654) )
    {
      v2 = v4 && byte_1BF590[16 * a1 + *i];
      v4 = v2;
    }
  }
  return v4;
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 189708: using guessed type int16_t word_189708;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0013D44F) --------------------------------------------------------
int __fastcall sub_13D44F(int a1)
{
  int i; // [esp+4h] [ebp-10h]
  int j; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-Ch]
  uint8_t *v7; // [esp+Ch] [ebp-8h]

  v7 = (uint8_t *)dword_1C40EA;
  if ( a1 == 0x7FFF )
  {
    for ( i = 0; ; ++i )
    {
      if ( i >= dword_1849DE )
        return 1;
      v5 = 0;
      while ( v7 )
      {
        if ( byte_1C0910[i] == *v7 )
        {
          v5 = 1;
          break;
        }
        v7 = *(uint8_t **)(v7 + 30);
      }
      if ( !v5 )
        break;
    }
    return 0;
  }
  else if ( a1 == 32766 )
  {
    for ( j = 0; ; ++j )
    {
      if ( j >= dword_1849DE )
        return 1;
      v6 = 0;
      while ( v7 )
      {
        if ( !strcmp(v7 + 2, &byte_184654) && byte_1C0910[j] == *v7 )
        {
          v6 = 1;
          break;
        }
        v7 = *(uint8_t **)(v7 + 30);
      }
      if ( !v6 )
        break;
    }
    return 0;
  }
  else
  {
    while ( v7 )
    {
      if ( !strcmp(v7 + 2, &byte_184654) && *v7 == a1 )
        return 1;
      v7 = *(uint8_t **)(v7 + 30);
    }
    return 0;
  }
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 1849DE: using guessed type int dword_1849DE;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0013D5CB) --------------------------------------------------------
int __fastcall sub_13D5CB(int a1, int a2, int a3)
{
  int64_t v3; // rax
  int64_t v4; // rax
  int v7; // [esp+4h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-8h]

  v7 = 0;
  v8 = dword_1849C2;
  v3 = j___clock(dword_1849C2, a2, a3);
  if ( (int)v3 >= dword_1849CE )
  {
    v4 = j___clock(v3, HIDWORD(v3), a3);
    dword_1849CE = v4 + 2;
    if ( !sub_13D44F(dword_184994) )
    {
      sub_13D75B();
      sub_126487(aUnableToSend, SHIDWORD(v4));
    }
    do
    {
      if ( !sub_13D39C(dword_1849C2) )
      {
        sub_13DE7E(dword_1849C2, dword_184994, word_1849B0);
        ++v7;
      }
      if ( dword_1849B2 - 1 == dword_1849C2 )
        dword_1849C2 = 0;
      else
        ++dword_1849C2;
      LODWORD(v3) = dword_1849C2;
      if ( dword_1849C2 == v8 && !v7 )
        break;
      LODWORD(v3) = v7;
    }
    while ( v7 < a1 );
    if ( !v7 )
      LODWORD(v3) = sub_13DE7E(0, dword_184994, word_1849B0);
  }
  else
  {
    dword_1849C6 = 1;
  }
  return v3;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 184994: using guessed type int dword_184994;
// 1849B0: using guessed type int16_t word_1849B0;
// 1849B2: using guessed type int dword_1849B2;
// 1849C2: using guessed type int dword_1849C2;
// 1849C6: using guessed type int dword_1849C6;
// 1849CE: using guessed type int dword_1849CE;


//----- (0013D6D8) --------------------------------------------------------
int __fastcall sub_13D6D8(int a1, int a2, int a3)
{
  int v3; // eax
  int64_t v4; // rax

  if ( dword_1849A0 && dword_1849C6 )
  {
    dword_1849C6 = 0;
    v3 = sub_13D5CB(10, a2, a3);
    LODWORD(v4) = j___clock(v3, a2, a3) + 40;
    dword_1849B6 = v4;
  }
  else
  {
    v4 = j___clock(a1, a2, a3);
    if ( (unsigned int)v4 > dword_1849B6 )
    {
      if ( dword_1849A0 )
        LODWORD(v4) = sub_13D5CB(5, SHIDWORD(v4), a3);
      LODWORD(v4) = j___clock(v4, HIDWORD(v4), a3) + 40;
      dword_1849B6 = v4;
    }
  }
  return v4;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 1849A0: using guessed type int dword_1849A0;
// 1849B6: using guessed type int dword_1849B6;
// 1849C6: using guessed type int dword_1849C6;


//----- (0013D75B) --------------------------------------------------------
int sub_13D75B()
{
  int result; // eax

  dword_18498E = 0;
  word_184992 = 0;
  dword_184994 = 0;
  dword_184998 = 0;
  dword_1849A0 = 0;
  dword_1849B2 = 0;
  dword_1849C2 = 0;
  memset(&byte_1C0890, 0, 128);
  result = memset(byte_1BF590, 0, 4096);
  ++dword_18499C;
  dword_1849CE = 0;
  dword_1849D6 = 0;
  dword_1849C6 = 1;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 18498E: using guessed type int dword_18498E;
// 184992: using guessed type int16_t word_184992;
// 184994: using guessed type int dword_184994;
// 184998: using guessed type int dword_184998;
// 18499C: using guessed type int dword_18499C;
// 1849A0: using guessed type int dword_1849A0;
// 1849B2: using guessed type int dword_1849B2;
// 1849C2: using guessed type int dword_1849C2;
// 1849C6: using guessed type int dword_1849C6;
// 1849CE: using guessed type int dword_1849CE;
// 1849D6: using guessed type int dword_1849D6;
// 1C0890: using guessed type char byte_1C0890;


//----- (0013D805) --------------------------------------------------------
int sub_13D805()
{
  dword_1849A4 = 0;
  dword_1849A8 = 0;
  dword_1849BE = 0;
  dword_1849CA = 0;
  dword_1849DA = 0;
  return memset(&byte_1C0590, 0, 256);
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 1849A4: using guessed type int dword_1849A4;
// 1849A8: using guessed type int dword_1849A8;
// 1849BE: using guessed type int dword_1849BE;
// 1849CA: using guessed type int dword_1849CA;
// 1849DA: using guessed type int dword_1849DA;
// 1C0590: using guessed type char byte_1C0590;


//----- (0013D867) --------------------------------------------------------
int __fastcall sub_13D867( unsigned int a1, int a2, int a3)
{
  int64_t v3; // rax
  char v5; // [esp+0h] [ebp-14h]

  if ( a3 )
  {
    v3 = j___clock(a1, a2, a3);
    if ( (int)v3 < dword_1849CA )
      return v3;
    dword_1849CA = j___clock((_BYTE)v3, HIDWORD(v3), a3) + 2;
  }
  LOBYTE(dword_1BF390[2]) = word_189708;
  dword_1BF390[0] = a2;
  if ( a3 )
    v5 = -1;
  else
    v5 = dword_1849DA;
  HIBYTE(dword_1BF390[2]) = v5;
  memcpy(&unk_1BF39C, &byte_1C0590, 256);
  LODWORD(v3) = sub_14E069((int)dword_1BF390, 260, a1, 1983, 1, 0);
  return v3;
}
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 13F35A: using guessed type int __fastcall memcpy(_DWORD, _DWORD, _DWORD);
// 1849CA: using guessed type int dword_1849CA;
// 1849DA: using guessed type int dword_1849DA;
// 189708: using guessed type int16_t word_189708;
// 1BF390: using guessed type _DWORD dword_1BF390[3];
// 1C0590: using guessed type char byte_1C0590;


//----- (0013D919) --------------------------------------------------------
int sub_13D919()
{
  int v1; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  v1 = 0;
  for ( i = dword_1C40EA; i; i = *(_DWORD *)(i + 30) )
  {
    if ( !strcmp(i + 2, &byte_184654) )
      ++v1;
  }
  return v1;
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 1C40EA: using guessed type int dword_1C40EA;


//----- (0013D97D) --------------------------------------------------------
bool sub_13D97D()
{
  bool v1; // [esp+0h] [ebp-14h]
  bool v2; // [esp+4h] [ebp-10h]
  uint8_t *v3; // [esp+8h] [ebp-Ch]
  int v4; // [esp+Ch] [ebp-8h]

  v3 = (uint8_t *)dword_1C40EA;
  v4 = 1;
  if ( dword_184994 == 0x7FFF )
  {
    while ( v3 )
    {
      if ( *v3 != word_189708 )
      {
        v2 = v4 && byte_1C0890[*v3];
        v4 = v2;
      }
      v3 = *(uint8_t **)(v3 + 30);
    }
    return v4;
  }
  else if ( dword_184994 == 32766 )
  {
    while ( v3 )
    {
      if ( !strcmp(v3 + 2, &byte_184654) && *v3 != word_189708 )
      {
        v1 = v4 && byte_1C0890[*v3];
        v4 = v1;
      }
      v3 = *(uint8_t **)(v3 + 30);
    }
    return v4;
  }
  else
  {
    return byte_1C0890[dword_184994] != 0;
  }
}
// 138B90: using guessed type int __fastcall strcmp(_DWORD, _DWORD);
// 184654: using guessed type char byte_184654;
// 184994: using guessed type int dword_184994;
// 189708: using guessed type int16_t word_189708;
// 1C40EA: using guessed type int dword_1C40EA;


