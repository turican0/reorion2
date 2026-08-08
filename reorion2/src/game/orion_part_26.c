#include "orion_common.h"

/* Adresni rozsah: 0x16615C - 0x1694D9  (98 funkci) */

// PORT (wave 25r): per-call trace of the 3 hand-ported dispatch handlers
// (sub_166830/167040/167190), correlated against dosbox DUMPREGS at the
// same logical point (loc_1675C0, runtime 0x38B5C0 = "back at dispatch
// after a handler returns"). Env-gated so it's zero-cost when unset.
// Writes to a FILE instead of stderr (REORION2_TRACE) because this fires
// far too often for the console/checkpoint path.
// NOTE: this file (like the rest of the decompiled game code) has fopen/
// fclose/fprintf/fflush #define'd to the int-handle-based PortFile_* wrappers
// (see decomp_compat.h) - use those directly rather than real FILE* stdio.
static void Smk_TraceHandlerCall(int handlerIndex, int a1, const void* outBefore, const void* outAfter)
{
  static int handle = 0;
  static int tried = 0;
  static long long callNo = 0;
  if (!tried)
  {
    tried = 1;
    {
      const char* path = getenv("REORION2_HANDLER_TRACE");
      if (path)
        handle = PortFile_Open(path, "w");
    }
  }
  if (handle <= 0)
    return;
  ++callNo;
  PortFile_Printf(handle, "%lld idx=%d a1=%d before=%p after=%p\n", callNo, handlerIndex, a1, outBefore, outAfter);
  if ((callNo % 256) == 0)
    PortFile_Flush(handle);
}

// PORT (wave 25r): bitstream state at the TOP of the block-type decoder -
// the exact point the original re-enters at loc_1675C0 (runtime 0x38B5C0).
// Logged for EVERY block so the sequence can be diffed 1:1 against a dosbox
// `DUMPREGS cond=eip:0x38B5C0 repeat=always` capture. esi (cursor) and the
// remaining-bit count are what a bit-miscounting handler corrupts first,
// so the first line where they disagree names the guilty preceding block.
static void Smk_TraceDispatchEntry(const void* cursor, unsigned int accum, int bitsLeft,
                                   const void* out)
{
  static int handle = 0;
  static int tried = 0;
  static long long blockNo = 0;
  if (!tried)
  {
    tried = 1;
    {
      const char* path = getenv("REORION2_DISPATCH_TRACE");
      if (path)
        handle = PortFile_Open(path, "w");
    }
  }
  if (handle <= 0)
    return;
  ++blockNo;
  PortFile_Printf(handle, "%lld cursor=%p accum=%08X bits=%d out=%p g660=%d g664=%d g668=%d g670=%d g674=%d g684=%d g688=%d\n",
                  blockNo, cursor, accum, bitsLeft, out,
                  dword_18A660, dword_18A664, dword_18A668, dword_18A670,
                  dword_18A674, dword_18A684, dword_18A688);
  if ((blockNo % 256) == 0)
    PortFile_Flush(handle);
}

// PORT (wave 25r-3): replacement for the funcs_164C45[256] jump table.
//
// Those 256 tiny generated functions (sub_165760..sub_1664E4) each return
// TWO 32-bit values - EAX **and EBX** - which the caller stores into two
// consecutive framebuffer rows:
//     call funcs_164C45[eax*4] / mov [edi],eax / add edi,stride
//                               / mov [edi],ebx
// IDA could only model one return value, so in the decompiled sub_1664F0
// the EBX rows came out as `v22` - a stale `int *` left over from the
// move-to-front cache update just above - and the EAX rows were truncated
// (95 of the 256 functions were typed `int16_t`/`char`, dropping 2 or 3 of
// their 4 pixels). Net effect: every other framebuffer row got a POINTER
// written into it as pixel data, and the other rows kept only half their
// pixels - exactly the dotted/checkerboard green artifact seen over the
// cinematic scene, with raw pointer dwords (e.g. 0x06918DD0) visible in a
// framebuffer dump.
//
// Semantics derived from the asm and verified against indices 0/1/2/3
// (sub_165760/16576C/165778/165784): the caller sets edx to HIWORD(v18)
// duplicated into both halves, so DL and DH are the block's two colours,
// and the table index is a bit mask selecting between them:
//     eax = pixels 0..3, ebx = pixels 4..7, pixel k = (index>>k)&1 ? dh : dl
// i.e. the standard Smacker 2-colour ("mono") block: BYTE0(v18) and
// BYTE1(v18) supply the 16 bits for the 16 pixels of one 4x4 block, and
// BYTE2/BYTE3(v18) supply the two colours. Generating the pixels directly
// makes all 256 generated functions dead code for this path.
static void Smk_ExpandMonoRows(unsigned int index, unsigned int edxVal,
                               unsigned int *outEax, unsigned int *outEbx)
{
  unsigned int dl = edxVal & 0xFFu;
  unsigned int dh = (edxVal >> 8) & 0xFFu;
  unsigned int a = 0, b = 0;
  int k;

  for ( k = 0; k < 4; ++k )
    a |= (((index >> k) & 1u) ? dh : dl) << (8 * k);
  for ( k = 4; k < 8; ++k )
    b |= (((index >> k) & 1u) ? dh : dl) << (8 * (k - 4));

  *outEax = a;
  *outEbx = b;
}

//----- (0016615C) --------------------------------------------------------
int16_t sub_16615C(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (00166168) --------------------------------------------------------
int16_t sub_166168(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (00166178) --------------------------------------------------------
int sub_166178(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166188) --------------------------------------------------------
int sub_166188(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00166198) --------------------------------------------------------
int sub_166198(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(__ROR4__(v2, 8), 16);
}


//----- (001661A8) --------------------------------------------------------
char sub_1661A8(int a1, int a2)
{
  return a2;
}


//----- (001661B8) --------------------------------------------------------
int sub_1661B8(int a1, int a2)
{
  return __ROR4__(a2, 24);
}


//----- (001661C8) --------------------------------------------------------
int16_t sub_1661C8(int a1, int a2)
{
  return a2;
}


//----- (001661D8) --------------------------------------------------------
int16_t sub_1661D8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = __ROR4__(a2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (001661E8) --------------------------------------------------------
int16_t sub_1661E8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001661F4) --------------------------------------------------------
int16_t sub_1661F4(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (00166200) --------------------------------------------------------
int sub_166200(int a1, int a2)
{
  return a2;
}


//----- (0016620C) --------------------------------------------------------
char sub_16620C( int a1)
{
  return a1;
}


//----- (00166218) --------------------------------------------------------
int sub_166218(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00166224) --------------------------------------------------------
int sub_166224(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00166230) --------------------------------------------------------
int sub_166230(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (0016623C) --------------------------------------------------------
int16_t sub_16623C(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = result;
  return result;
}


//----- (00166248) --------------------------------------------------------
int16_t sub_166248(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (00166258) --------------------------------------------------------
int sub_166258(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166268) --------------------------------------------------------
int sub_166268(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00166278) --------------------------------------------------------
int sub_166278(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166288) --------------------------------------------------------
int sub_166288(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (00166298) --------------------------------------------------------
int sub_166298(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (001662A8) --------------------------------------------------------
char sub_1662A8(int a1, int a2)
{
  return a2;
}


//----- (001662B8) --------------------------------------------------------
int sub_1662B8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (001662C8) --------------------------------------------------------
int16_t sub_1662C8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001662D4) --------------------------------------------------------
int16_t sub_1662D4(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (001662E0) --------------------------------------------------------
int sub_1662E0(int a1, int a2)
{
  return a2;
}


//----- (001662EC) --------------------------------------------------------
char sub_1662EC( int a1)
{
  return a1;
}


//----- (001662F8) --------------------------------------------------------
char sub_1662F8(int a1, int a2)
{
  return a2;
}


//----- (00166304) --------------------------------------------------------
int sub_166304(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (00166310) --------------------------------------------------------
int sub_166310(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00166320) --------------------------------------------------------
int16_t sub_166320(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


//----- (0016632C) --------------------------------------------------------
int16_t sub_16632C(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (0016633C) --------------------------------------------------------
int sub_16633C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (0016634C) --------------------------------------------------------
int sub_16634C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (0016635C) --------------------------------------------------------
int sub_16635C(int a1, int a2)
{
  int v2; // eax

  HIWORD(v2) = HIWORD(a2);
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (0016636C) --------------------------------------------------------
int sub_16636C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 8);
}


//----- (0016637C) --------------------------------------------------------
int sub_16637C(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (0016638C) --------------------------------------------------------
char sub_16638C(int a1, int a2)
{
  return a2;
}


//----- (0016639C) --------------------------------------------------------
int sub_16639C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (001663AC) --------------------------------------------------------
int16_t sub_1663AC(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (001663B8) --------------------------------------------------------
int16_t sub_1663B8(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = HIBYTE(a2);
  HIBYTE(result) = a2;
  return result;
}


//----- (001663C4) --------------------------------------------------------
int sub_1663C4(int a1, int a2)
{
  return a2;
}


//----- (001663D0) --------------------------------------------------------
char sub_1663D0( int a1)
{
  return a1;
}


//----- (001663DC) --------------------------------------------------------
int16_t sub_1663DC(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = a2;
  return result;
}


//----- (001663E8) --------------------------------------------------------
int sub_1663E8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (001663F8) --------------------------------------------------------
int sub_1663F8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (00166404) --------------------------------------------------------
char sub_166404( int a1)
{
  return a1;
}


//----- (00166410) --------------------------------------------------------
int16_t sub_166410(int a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  int16_t result; // ax

  v2 = a2;
  v3 = a2;
  LOBYTE(v3) = BYTE1(a2);
  BYTE1(v2) = a2;
  LOBYTE(result) = __ROR4__(v2, 16);
  HIBYTE(result) = (uint16_t)__ROR4__(v3, 8) >> 8;
  return result;
}


//----- (00166420) --------------------------------------------------------
int sub_166420(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 24);
}


//----- (00166430) --------------------------------------------------------
int sub_166430(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  BYTE1(v2) = a2;
  return __ROR4__(v2, 16);
}


//----- (00166440) --------------------------------------------------------
int sub_166440(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = (uint16_t)__ROR4__(v2, 8) >> 8;
  return __ROR4__(v2, 24);
}


//----- (00166450) --------------------------------------------------------
char sub_166450(int a1, int a2)
{
  int v2; // ebx

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return (uint16_t)__ROR4__(v2, 8) >> 8;
}


//----- (00166460) --------------------------------------------------------
int sub_166460(int a1, int a2)
{
  return __ROR4__(a2, 8);
}


//----- (00166470) --------------------------------------------------------
char sub_166470(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return (uint16_t)__ROR4__(v2, 8) >> 8;
}


//----- (00166480) --------------------------------------------------------
int sub_166480(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 24);
}


//----- (00166490) --------------------------------------------------------
int16_t sub_166490(int a1, int a2)
{
  int16_t result; // ax

  LOBYTE(result) = a2;
  HIBYTE(result) = a2;
  return result;
}


//----- (0016649C) --------------------------------------------------------
int16_t sub_16649C(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  BYTE1(v2) = (uint16_t)__ROR4__(v2, 8) >> 8;
  return v2;
}


//----- (001664A8) --------------------------------------------------------
int sub_1664A8(int a1, int a2)
{
  return a2;
}


//----- (001664B4) --------------------------------------------------------
char sub_1664B4( int a1)
{
  return a1;
}


//----- (001664C0) --------------------------------------------------------
char sub_1664C0(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return (uint16_t)__ROR4__(v2, 8) >> 8;
}


//----- (001664CC) --------------------------------------------------------
int sub_1664CC(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 8);
}


//----- (001664D8) --------------------------------------------------------
int sub_1664D8(int a1, int a2)
{
  int v2; // eax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  return __ROR4__(v2, 16);
}


//----- (001664E4) --------------------------------------------------------
int16_t sub_1664E4(int a1, int a2)
{
  int v2; // eax
  int16_t result; // ax

  v2 = a2;
  LOBYTE(v2) = BYTE1(a2);
  LOBYTE(result) = __ROR4__(v2, 8);
  HIBYTE(result) = BYTE1(a2);
  return result;
}


// PORT (wave 25o): the other three dispatch slots in this quadrant
// (sub_166830/sub_167040/sub_167190) and the entire other quadrant
// (sub_164A40/sub_164DA0/sub_167040/sub_1655B0, selected when
// dword_18A6A8 is set) and the raw-asm loc_* variants (dword_18A6AC set)
// were never ported from assembly - link_stubs.c stubs them as `return 0;`.
// Route them here instead of calling the broken stubs so a hit is visible
// in the trace instead of silently producing wrong pixels or crashing.
static SmkFrameStatus SmkDispatch_NotImplemented(const char *label, int dispatch_index)
{
  PortDebug_Checkpoint(label, dispatch_index);
  return SmkFrame_Done;
}

// PORT (wave 25o): extracted from sub_167320's `loc_1675C0` (Debug/diss/
// Orion2.exe.asm 0x1675C0-0x167694) - decodes the next "what kind of block"
// Huffman symbol from the dword_18A60C tree and dispatches to the handler
// selected by its low 2 bits. In the original this is inlined into
// sub_167320 and re-entered via a raw `jmp` from sub_1664F0/sub_164A40/etc
// after each one finishes a block (JUMPOUT(0x1675C0)) - ported here as a
// real function returning SmkFrame_Continue/SmkFrame_Done so sub_167320 can
// drive it with a real loop instead of a one-way jump. Uses the persistent
// g_smkFrameAccum/g_smkFrameCursor globals (wave 25n/25o) instead of by-value
// parameters, since the accumulator/cursor must survive across every hop.
SmkFrameStatus Smk167320_DecodeBlockTypeAndDispatch(void)
{
  unsigned int v20; // edx
  unsigned int v21; // ebp
  unsigned int v22; // ecx
  unsigned int v23; // ebp
  char v24; // al
  unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // edx
  char v30; // cf
  int v31; // edx
  int v32; // edx
  int *v33; // ebx
  int *v34; // ecx
  int v35; // edx
  int dispatch_index;

  // PORT (wave 25r): see Smk_TraceDispatchEntry - this is loc_1675C0.
  Smk_TraceDispatchEntry((const void *)g_smkFrameCursor, g_smkFrameAccum,
                         (int)(uint8_t)byte_18A6C0, (const void *)g_smkFrameOutput);

  if ( (uint8_t)byte_18A6C0 > 8u )
  {
    v27 = *(_DWORD *)(dword_18A60C + 4 * (uint8_t)g_smkFrameAccum);
    v23 = g_smkFrameAccum >> v27;
    v24 = byte_18A6C0 - v27;
    v25 = (unsigned int *)(dword_18A6A4 + (v27 >> 8));
    v26 = *v25;
    if ( (_WORD)dword_18A6D0 != (uint16_t)*v25 )
      goto LABEL_31;
  }
  else
  {
    // PORT (wave 25o): asm `mov edx,[esi]; add esi,2` - a fresh dword read
    // through the PERSISTENT cursor, advanced by 2 bytes (a sliding 16-bit
    // top-up window), NOT a reset to a fixed offset from sub_167320's `a1`
    // parameter as the pre-25o decompiled C incorrectly had it (that only
    // happened to be right on the very first pass through this code, before
    // it was known to be re-entered in a loop).
    v20 = *g_smkFrameCursor;
    g_smkFrameCursor = (unsigned int *)((char *)g_smkFrameCursor + 2);
    v21 = g_smkFrameAccum | (v20 << (byte_18A6C0 - 1));
    v22 = *(_DWORD *)(dword_18A60C + 4 * (uint8_t)v21);
    v23 = v21 >> v22;
    v24 = byte_18A6C0 + 16 - v22;
    v25 = (unsigned int *)(dword_18A6A4 + (v22 >> 8));
    v26 = *v25;
    if ( (_WORD)dword_18A6D0 != (uint16_t)*v25 )
      goto LABEL_31;
  }
  do
  {
    v28 = v26 >> 13;
    if ( !--v24 )
    {
      v23 = *g_smkFrameCursor++;
      v24 = 32;
    }
    v29 = 0xFFFF8u & v28;
    v30 = v23 & 1;
    v23 >>= 1;
    if ( !v30 )
      v29 = 4;
    v25 = (unsigned int *)((char *)v25 + v29);
    v26 = *v25;
  }
  while ( (_WORD)dword_18A6D0 == (uint16_t)*v25 );
LABEL_31:
  v31 = __ROR4__(v26, 16);
  byte_18A6C0 = v24;
  g_smkFrameAccum = v23;
  LOWORD(g_smkBlockTypeSymbol) = v31;
  v32 = __ROR4__(v31, 16);
  if ( *(_DWORD *)block18A610[13] != v32 )
  {
    dword_18A678 = g_smkBlockTypeSymbol;
    g_smkBlockTypeSymbol = *(_DWORD *)block18A610[13];
    v33 = (int *)block18A610[14];
    *(_DWORD *)block18A610[13] = v32;
    v34 = (int *)block18A610[15];
    v35 = *v33;
    *v33 = g_smkBlockTypeSymbol;
    // PORT (wave 25r-7): the asm restores the WHOLE saved eax here
    // (`mov eax, dword_182678`, sub_167320 just before loc_167694) - the
    // decompiler emitted a LOBYTE assignment, so the upper 24 bits kept the
    // old cache[0] entry that was parked in eax during the move-to-front
    // swap. Since sub_167190 takes its fill colour from BYTE1 of this symbol
    // (`mov al,ah`), every block decoded through the swap path was filled
    // with the wrong colour - measured: the cinematic's first frame filled
    // its first 2048-block run with 0 instead of 10 (32768 pixels, all
    // "10 -> 0"), because that one call went through the swap.
    g_smkBlockTypeSymbol = dword_18A678;
    *v34 = v35;
  }
  dword_18A664 = block18A6E0[(g_smkBlockTypeSymbol & 0xFC) >> 2];
  dispatch_index = g_smkBlockTypeSymbol & 3;
  // PORT (wave 25p): throttled - this fires per decoded symbol (millions of
  // times during a stuck/looping decode) and was flooding the trace.
  {
    static unsigned s_dispatchCallCount = 0;
    if ( (++s_dispatchCallCount % 5000) == 1 )
    {
      PortDebug_Checkpoint("dispatch.calls_so_far", (int)s_dispatchCallCount);
      PortDebug_Checkpoint("dispatch.block_type_symbol", g_smkBlockTypeSymbol);
      PortDebug_Checkpoint("dispatch.index", dispatch_index);
      PortDebug_Checkpoint("dispatch.byte_18A6C0", (unsigned char)byte_18A6C0);
      PortDebug_CheckpointPtr("dispatch.g_smkFrameCursor", (void*)g_smkFrameCursor);
      PortDebug_Checkpoint("dispatch.g_smkFrameAccum", (int)g_smkFrameAccum);
      PortDebug_CheckpointPtr("dispatch.g_smkFrameOutput", (void*)g_smkFrameOutput);
    }
  }

  if ( dword_18A6AC & 1 )
    return SmkDispatch_NotImplemented("dispatch.UNIMPLEMENTED_raw_asm_quadrant", dispatch_index);
  if ( dword_18A6A8 )
  {
    // sub_164A40/sub_164DA0/sub_167040/sub_1655B0 quadrant - not confirmed
    // live for any video seen so far (byte_a3plus1 was 0), left unported.
    switch ( dispatch_index )
    {
      case 0: return SmkDispatch_NotImplemented("dispatch.UNIMPLEMENTED_164A40", dispatch_index);
      case 1: return SmkDispatch_NotImplemented("dispatch.UNIMPLEMENTED_164DA0", dispatch_index);
      case 2: return SmkDispatch_NotImplemented("dispatch.UNIMPLEMENTED_167040", dispatch_index);
      default: return SmkDispatch_NotImplemented("dispatch.UNIMPLEMENTED_1655B0", dispatch_index);
    }
  }
  // PORT (wave 25o fix): confirmed via Debug/diss/Orion2.exe.asm
  // (sub_167320 loc_167694 / sub_1664F0+0) that the dispatch targets'
  // "a1" parameter is EDX, not EAX - `mov edx,dword_1826E0[edx]; mov
  // dword_182664,edx; jmp dword_182650[ecx*4]` leaves edx (== the value
  // just stored into dword_18A664) live at the jump, and sub_1664F0's
  // very first instruction is `add dword_1827F4, edx`. Passing the
  // decoded symbol itself (g_smkBlockTypeSymbol, "eax") here instead was
  // wrong and produced huge values that blew out the coverage-marking loop.
  {
    // PORT (wave 25r): per-call trace, see Smk_TraceHandlerCall above.
    void *before = (void *)g_smkFrameOutput;
    SmkFrameStatus st;
    switch ( dispatch_index )
    {
      case 0: st = sub_1664F0(dword_18A664); break;
      case 1: st = sub_166830(dword_18A664); break; // PORT (wave 25q): ported from asm
      case 2: st = sub_167040(dword_18A664); break; // PORT (wave 25q): ported from asm
      default: st = sub_167190(dword_18A664); break; // PORT (wave 25q): ported from asm
    }
    Smk_TraceHandlerCall(dispatch_index, dword_18A664, before, (void *)g_smkFrameOutput);
    return st;
  }
}


// PORT (wave 25q): helpers for sub_166830. One symbol decoded from the
// 12-bit-indexed tree dword_18A608 (asm loc_166880..loc_16691C), and the
// 3-slot move-to-front cache update on block18A610[9..11]
// (asm dword_182634/638/63C). Structure is the same traversal shape as
// sub_1664F0's, only the lookup threshold (0x0C), mask (0xFFF), tree and
// cache slots differ.
static unsigned int Smk166830_DecodeSymbol(void)
{
  unsigned char al = (unsigned char)byte_18A6C0;
  unsigned int ebx = (unsigned int)dword_18A6D0;
  unsigned int ecx;
  unsigned int edx;

  if ( al <= 0x0Cu )
  {
    unsigned char cl = al - 1;
    edx = *g_smkFrameCursor;
    g_smkFrameCursor = (unsigned int *)((char *)g_smkFrameCursor + 2);
    edx = (edx << cl) | g_smkFrameAccum;
    g_smkFrameAccum = edx;
    edx &= 0xFFFu;
    al += 0x10;
    ecx = *(unsigned int *)(uintptr_t)((unsigned int)dword_18A608 + 4 * edx);
    g_smkFrameAccum >>= (unsigned char)ecx;
    al -= (unsigned char)ecx;
    ecx = (ecx >> 8) + (unsigned int)dword_18A6A4;
    edx = *(unsigned int *)(uintptr_t)ecx;
  }
  else
  {
    edx = g_smkFrameAccum & 0xFFFu;
    ecx = *(unsigned int *)(uintptr_t)((unsigned int)dword_18A608 + 4 * edx);
    g_smkFrameAccum >>= (unsigned char)ecx;
    al -= (unsigned char)ecx;
    ecx = (ecx >> 8) + (unsigned int)dword_18A6A4;
    edx = *(unsigned int *)(uintptr_t)ecx;
  }
  while ( (uint16_t)ebx == (uint16_t)edx ) // loc_1668F5
  {
    unsigned int step = edx >> 13;
    unsigned int bit;
    if ( --al == 0 )
    {
      g_smkFrameAccum = *g_smkFrameCursor++;
      al = 32;
    }
    step &= 0xFFFF8u;
    bit = g_smkFrameAccum & 1; // asm: `shr ebp,1` sets CF from the old bit 0
    g_smkFrameAccum >>= 1;
    if ( !bit )
      step = 4;
    ecx += step;
    edx = *(unsigned int *)(uintptr_t)ecx;
  }
  byte_18A6C0 = (char)al;
  return edx;
}

static void Smk166830_UpdateCache(unsigned int leaf)
{
  int *p9 = (int *)(uintptr_t)block18A610[9];
  if ( *p9 != (int)leaf )
  {
    int *p10 = (int *)(uintptr_t)block18A610[10];
    int *p11 = (int *)(uintptr_t)block18A610[11];
    int old9 = *p9;
    int old10 = *p10;
    *p9 = (int)leaf;
    *p10 = old9;
    *p11 = old10;
  }
}


//----- (00166830) --------------------------------------------------------
// PORT (wave 25q): the last unported block handler, from
// Debug/diss/Orion2.exe.asm (sub_166830, asm lines 548962-549735). Was a
// `return 0;` stub; reached 387x per intro run once the rotate fix made block
// types vary, which is what still left holes in the cinematic scene.
// The 773 asm lines are an UNROLLED loop: 4 groups of
// [decode symbol -> cache update] x2 -> `mov [edi], eax` -> row step, then
// the usual block/strip bookkeeping and shared tail. Verified by counting
// references: 16x dword_182608 (= 8 logical traversals, each listed twice for
// its refill/no-refill arms), 8x the cache triple, 4x `mov [edi], eax`,
// 3x `add edi, dword_182660` + 1x `sub edi, dword_18266C`.
// The two traversals of a pair differ only in how they feed EAX:
//   first  (asm loc_16691C): `mov eax, edx`  -> EAX = the whole leaf
//   second (asm loc_1669EC): `mov ax, dx` after ror -> only EAX's low word is
//                            replaced by the leaf's HIGH word
// so the stored dword ends up as (HIWORD(leaf1) << 16) | HIWORD(leaf2).
SmkFrameStatus sub_166830(int a1)
{
  unsigned int ecx;
  unsigned int ebx;
  unsigned int eax = 0;
  int k;
  _DWORD *edi = g_smkFrameOutput;

  dword_18A7F4 += a1;
  ecx = (unsigned int)dword_18A7F4;
  if ( (unsigned int)dword_18A7F0 <= ecx ) // asm: `ja short loc_166880`
  {
    ebx = (unsigned int)dword_18A7F0;
    ecx = (ecx + 15) >> 4;
    ebx >>= 4;
    if ( ebx != ecx )
    {
      uint8_t *p = (uint8_t *)(uintptr_t)((unsigned int)dword_18A7F8 + ebx);
      uint8_t *e = (uint8_t *)(uintptr_t)((unsigned int)dword_18A7F8 + ecx);
      do
        *p++ = 1;
      while ( p != e );
    }
    dword_18A7F0 = (int)(ecx << 4);
  }

LABEL_166880:
  for ( ;; )
  {
    for ( k = 0; k < 4; ++k )
    {
      unsigned int leaf;

      leaf = Smk166830_DecodeSymbol();
      Smk166830_UpdateCache(leaf);
      eax = leaf; // asm loc_16691C: `mov eax, edx`

      leaf = Smk166830_DecodeSymbol();
      Smk166830_UpdateCache(leaf);
      eax = (eax & 0xFFFF0000u) | (leaf >> 16); // asm loc_1669EC: `mov ax, dx`

      *edi = (int)eax;
      if ( k < 3 )
        edi = (_DWORD *)((char *)edi + dword_18A660);
    }
    edi = (_DWORD *)((char *)edi - dword_18A66C);

    if ( --dword_18A668 != 0 )
    {
      if ( --dword_18A664 != 0 )
        continue;
      g_smkFrameOutput = edi;
      return SmkFrame_Continue;
    }
    // loc_166F60
    if ( --dword_18A670 == 0 )
      break; // -> loc_166F90 (tail)
    edi = (_DWORD *)((char *)edi + dword_18A688);
    // loc_166F6E
    dword_18A668 = dword_18A674;
    if ( --dword_18A664 != 0 )
      continue;
    g_smkFrameOutput = edi;
    return SmkFrame_Continue;
  }

  // loc_166F90
  if ( (dword_18A6AC & 1) == 0 )
  {
    g_smkFrameOutput = edi;
    return SmkFrame_Done;
  }
  for ( ;; )
  {
    int base;
    uint16_t w;
    uint16_t *p;

    // loc_166FA1
    base = dword_18A6A0;
    w = *(uint16_t *)(uintptr_t)base;
    if ( w > 0xFFFEu )
    {
      g_smkFrameOutput = edi;
      return SmkFrame_Done;
    }
    if ( w == 0xFFFDu )
    {
      sub_164920(base);
    }
    else
    {
      if ( w < 0xFFFDu )
        dword_18A69C(w); // loc_166FD0
      // loc_166FD6
      p = (uint16_t *)(uintptr_t)(base + 2);
      dword_18A660 = p[0];
      dword_18A674 = p[1];
      dword_18A668 = dword_18A674;
      dword_18A66C = p[2];
      dword_18A684 = p[3];
      dword_18A688 = p[4];
      p += 5;
      dword_18A670 = p[2];
      edi = (_DWORD *)(uintptr_t)*(uint32_t *)p;
      dword_18A6A0 = (int)(p + 3);
    }
    // loc_167023
    if ( dword_18A670 == 0 )
      continue;
    // asm: `pop eax; jmp loc_166F6E`
    dword_18A668 = dword_18A674;
    if ( --dword_18A664 == 0 )
    {
      g_smkFrameOutput = edi;
      return SmkFrame_Continue;
    }
    goto LABEL_166880;
  }
}


//----- (00167190) --------------------------------------------------------
// PORT (wave 25q): solid-fill block handler, ported from
// Debug/diss/Orion2.exe.asm (sub_167190, asm lines 549868-550002). Was a
// `return 0;` stub; reached 24x per intro run once the rotate fix made block
// types vary. Same register mapping as sub_167040/sub_1664F0.
// Notes verified against the asm:
//   * loc_1671E0 (`mov al,ah / mov ecx,eax / shl eax,10h / mov ax,cx`) builds
//     the fill dword by replicating BYTE1 of the block-type symbol (the value
//     the dispatcher left in EAX = g_smkBlockTypeSymbol) into all four bytes.
//   * the body writes FOUR rows of `ecx` dwords (4x `rep stosd`) stepping by
//     `dword_18A660 - 4*ecx` between rows, then backs up by dword_18A684.
//   * the coverage-marking span writes 1 here (sub_167040 writes 0) and
//     rounds up (`add ecx, 0Fh`) before the shift.
SmkFrameStatus sub_167190(int a1)
{
  unsigned int ecx;
  unsigned int ebx;
  unsigned int edx_cnt = 0;
  unsigned int fill;
  unsigned int b;
  int row;
  _DWORD *edi = g_smkFrameOutput;

  dword_18A7F4 += a1;
  ecx = (unsigned int)dword_18A7F4;
  if ( (unsigned int)dword_18A7F0 <= ecx ) // asm: `ja short loc_1671E0`
  {
    ebx = (unsigned int)dword_18A7F0;
    ecx = (ecx + 15) >> 4;
    ebx >>= 4;
    if ( ebx != ecx )
    {
      uint8_t *p = (uint8_t *)(uintptr_t)((unsigned int)dword_18A7F8 + ebx);
      uint8_t *e = (uint8_t *)(uintptr_t)((unsigned int)dword_18A7F8 + ecx);
      do
        *p++ = 1;
      while ( p != e );
    }
    dword_18A7F0 = (int)(ecx << 4);
  }

  // loc_1671E0
  b = ((unsigned int)g_smkBlockTypeSymbol >> 8) & 0xFFu;
  fill = b | (b << 8) | (b << 16) | (b << 24);

  // PORT (wave 25r-7): the cinematic's first frame is 6 solid-fill runs
  // (2048+2048+512+128+59+5 = 4800 blocks = the whole 120x40 rect). The port
  // loses exactly the FIRST 2048-block run, so log what each call actually
  // gets and writes.
  {
    extern unsigned g_blitCount;
    if ( g_blitCount >= 80 && g_blitCount <= 82 )
    {
      PortDebug_Checkpoint("167190.blit", (int)g_blitCount);
      PortDebug_Checkpoint("167190.a1", a1);
      PortDebug_Checkpoint("167190.run_18A664", dword_18A664);
      PortDebug_Checkpoint("167190.rowleft_18A668", dword_18A668);
      PortDebug_Checkpoint("167190.rows_18A670", dword_18A670);
      PortDebug_Checkpoint("167190.fillbyte", (int)b);
      PortDebug_Checkpoint("167190.symbol", g_smkBlockTypeSymbol);
    }
  }

LABEL_1671EA:
  for ( ;; )
  {
    unsigned int k;

    ecx = (unsigned int)dword_18A668;
    if ( (unsigned int)dword_18A664 < ecx )
      ecx = (unsigned int)dword_18A664;
    // loc_1671FE
    ebx = (unsigned int)dword_18A660 - 4 * ecx;
    edx_cnt = ecx;
    for ( row = 0; row < 4; ++row )
    {
      for ( k = 0; k < edx_cnt; ++k )
        *edi++ = fill; // rep stosd
      if ( row < 3 )
        edi = (_DWORD *)((char *)edi + ebx);
    }
    edi = (_DWORD *)((char *)edi - dword_18A684);

    dword_18A668 -= (int)edx_cnt;
    if ( dword_18A668 == 0 )
    {
      // loc_167240
      if ( --dword_18A670 == 0 )
        break; // -> loc_167270 (tail)
      edi = (_DWORD *)((char *)edi + dword_18A688);
      // loc_16724E
      dword_18A664 -= (int)edx_cnt;
      dword_18A668 = dword_18A674;
      if ( dword_18A664 != 0 )
        continue;
      g_smkFrameOutput = edi;
      return SmkFrame_Continue;
    }
    dword_18A664 -= (int)edx_cnt;
    if ( dword_18A664 != 0 )
      continue;
    g_smkFrameOutput = edi;
    return SmkFrame_Continue;
  }

  // loc_167270
  if ( (dword_18A6AC & 1) == 0 )
  {
    g_smkFrameOutput = edi;
    return SmkFrame_Done;
  }
  for ( ;; )
  {
    int base;
    uint16_t w;
    uint16_t *p;

    // loc_167281
    base = dword_18A6A0;
    w = *(uint16_t *)(uintptr_t)base;
    if ( w > 0xFFFEu )
    {
      g_smkFrameOutput = edi;
      return SmkFrame_Done;
    }
    if ( w == 0xFFFDu )
    {
      sub_164920(base);
    }
    else
    {
      if ( w < 0xFFFDu )
        dword_18A69C(w); // loc_1672B0
      // loc_1672B6
      p = (uint16_t *)(uintptr_t)(base + 2);
      dword_18A660 = p[0];
      dword_18A674 = p[1];
      dword_18A668 = dword_18A674;
      dword_18A66C = p[2];
      dword_18A684 = p[3];
      dword_18A688 = p[4];
      p += 5;
      dword_18A670 = p[2];
      edi = (_DWORD *)(uintptr_t)*(uint32_t *)p;
      dword_18A6A0 = (int)(p + 3);
    }
    // loc_167303
    if ( dword_18A670 == 0 )
      continue;
    // asm: `pop eax; jmp loc_16724E`
    dword_18A664 -= (int)edx_cnt;
    dword_18A668 = dword_18A674;
    if ( dword_18A664 == 0 )
    {
      g_smkFrameOutput = edi;
      return SmkFrame_Continue;
    }
    goto LABEL_1671EA;
  }
}


//----- (00167040) --------------------------------------------------------
// PORT (wave 25q): block-type handler ported from Debug/diss/Orion2.exe.asm
// (sub_167040, asm lines 549745-549858). It was a `return 0;` stub in
// link_stubs.c. Once the __ROL4__/__ROR4__ no-op stubs were fixed the decoder
// finally produces varied block types, and this handler is reached 641x per
// intro run - so until now most of the cinematic's blocks were silently
// skipped (nothing decoded, no bitstream consumed).
// Register mapping follows the already-ported sibling sub_1664F0:
//   edx = a1 (run length, the value the dispatcher left in dword_18A664)
//   edi = g_smkFrameOutput (persistent output cursor)
//   JUMPOUT(0x1675C0) -> SmkFrame_Continue, JUMPOUT(0x1676C0) -> SmkFrame_Done
SmkFrameStatus sub_167040(int a1)
{
  int edx = a1;
  unsigned int ecx;
  unsigned int eax;
  _DWORD *edi = g_smkFrameOutput;

  dword_18A7F4 += edx;
  ecx = (unsigned int)dword_18A7F4;
  eax = (unsigned int)dword_18A7F0;
  if ( eax <= ecx ) // asm: `ja short loc_167084` skips when above
  {
    ecx >>= 4;
    eax >>= 4;
    if ( eax < ecx )
    {
      // Coverage-marking span. NOTE: sub_1664F0's equivalent writes 1 here,
      // this one writes 0 - verified against the asm (`mov byte ptr [eax], 0`).
      uint8_t *p = (uint8_t *)(uintptr_t)((unsigned int)dword_18A7F8 + eax);
      uint8_t *e = (uint8_t *)(uintptr_t)((unsigned int)dword_18A7F8 + ecx);
      do
        *p++ = 0;
      while ( p != e );
    }
    dword_18A7F0 = (int)(ecx << 4);
  }

  for ( ;; )
  {
    // loc_167084
    ecx = (unsigned int)dword_18A668;
    if ( (unsigned int)edx < ecx )
      ecx = (unsigned int)edx;
    // loc_167090
    edi = (_DWORD *)((char *)edi + 4 * ecx);
    dword_18A668 -= (int)ecx;
    if ( dword_18A668 )
    {
      edx -= (int)ecx;
      if ( edx )
        continue;
      g_smkFrameOutput = edi;
      return SmkFrame_Continue;
    }
    // loc_1670B0
    if ( --dword_18A670 )
    {
      edi = (_DWORD *)((char *)edi + dword_18A688);
      // loc_1670BE
      dword_18A668 = dword_18A674;
      edx -= (int)ecx;
      if ( edx )
        continue;
      g_smkFrameOutput = edi;
      return SmkFrame_Continue;
    }
    // loc_1670E0
    if ( (dword_18A6AC & 1) == 0 )
    {
      g_smkFrameOutput = edi;
      return SmkFrame_Done;
    }
    for ( ;; )
    {
      int base;
      uint16_t w;
      uint16_t *p;

      // loc_1670F1
      base = dword_18A6A0;
      w = *(uint16_t *)(uintptr_t)base;
      if ( w > 0xFFFEu ) // 0xFFFF -> loc_1676C0
      {
        g_smkFrameOutput = edi;
        return SmkFrame_Done;
      }
      if ( w == 0xFFFDu )
      {
        sub_164920(base); // asm: `push offset loc_167173; jmp sub_164920`
      }
      else
      {
        if ( w < 0xFFFDu )
          dword_18A69C(w); // loc_167120
        // loc_167126 - reload the per-strip geometry from the frame table
        p = (uint16_t *)(uintptr_t)(base + 2);
        dword_18A660 = p[0];
        dword_18A674 = p[1];
        dword_18A668 = dword_18A674;
        dword_18A66C = p[2];
        dword_18A684 = p[3];
        dword_18A688 = p[4];
        p += 5;
        dword_18A670 = p[2];
        // 32-bit stored pointer - widen explicitly (x64 pointer-width class)
        edi = (_DWORD *)(uintptr_t)*(uint32_t *)p;
        dword_18A6A0 = (int)(p + 3);
      }
      // loc_167173
      if ( dword_18A670 == 0 )
        continue;
      // asm: `pop eax; jmp loc_1670BE`
      dword_18A668 = dword_18A674;
      edx -= (int)ecx;
      if ( edx == 0 )
      {
        g_smkFrameOutput = edi;
        return SmkFrame_Continue;
      }
      break; // -> loc_167084
    }
  }
}


//----- (001664F0) --------------------------------------------------------
// PORT (wave 25o): a2 (accumulator)/a3 (output write pointer)/a4 (cursor)
// were by-value parameters modeling asm ebp/edi/esi at the moment
// sub_167320 jumps here - confirmed via dosbox-x DUMPREGS (loc_167694 vs
// this function's entry) that all three are IDENTICAL across the jump,
// i.e. persistent registers, not fresh values. They're now the shared
// g_smkFrameAccum/g_smkFrameOutput/g_smkFrameCursor globals (see
// Smk167320_DecodeBlockTypeAndDispatch). `JUMPOUT(0x1675C0)` (asm: jump
// back into sub_167320's block-type decoder to process the next block) and
// `JUMPOUT(0x1676C0)` (asm: jump to sub_167320's own epilogue - the whole
// per-frame decode is done) were previously no-ops (see decomp_compat.h),
// silently falling through to an unconditional early return - replaced
// with real SmkFrameStatus returns so the caller's loop behaves correctly.
SmkFrameStatus sub_1664F0(int a1)
{
  unsigned int v4; // ecx
  _BYTE *v5; // ebx
  _BYTE *v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // ebp
  unsigned int v9; // ecx
  unsigned int v10; // ebp
  char v11; // al
  unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edx
  char v17; // cf
  int v18; // eax
  int *v19; // ebx
  int *v20; // ecx
  int v21; // edx
  int *v22; // ebx
  unsigned int v23; // edx
  unsigned int v24; // ebp
  unsigned int v25; // ecx
  char v26; // al
  unsigned int *v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // edx
  int v32; // edx
  int v33; // edx
  int v34; // eax
  _DWORD *v35; // ecx
  int v36; // edx
  int v37; // edx
  uint8_t v38; // ch
  int v39; // eax
  int **v40; // edi
  _DWORD *v41; // edi
  _DWORD *v42; // eax
  int **v43; // edi
  int v44; // edi
  uint16_t *v46; // edi

  dword_18A7F4 += a1;
  if ( dword_18A7F0 <= (unsigned int)dword_18A7F4 )
  {
    v4 = (unsigned int)(dword_18A7F4 + 15) >> 4;
    if ( (unsigned int)dword_18A7F0 >> 4 != v4 )
    {
      v5 = (_BYTE *)(dword_18A7F8 + ((unsigned int)dword_18A7F0 >> 4));
      v6 = (_BYTE *)(dword_18A7F8 + v4);
      do
        *v5++ = 1;
      while ( v5 != v6 );
      v4 = (unsigned int)&v6[-dword_18A7F8];
    }
    dword_18A7F0 = 16 * v4;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      if ( (uint8_t)byte_18A6C0 > 0xAu )
      {
        v14 = *(_DWORD *)(dword_18A604 + 4 * (g_smkFrameAccum & 0x3FF));
        v10 = g_smkFrameAccum >> v14;
        v11 = byte_18A6C0 - v14;
        v12 = (unsigned int *)(dword_18A6A4 + (v14 >> 8));
        v13 = *v12;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v12 )
          goto LABEL_16;
      }
      else
      {
        v7 = *g_smkFrameCursor;
        g_smkFrameCursor = (unsigned int *)((char *)g_smkFrameCursor + 2);
        v8 = g_smkFrameAccum | (v7 << (byte_18A6C0 - 1));
        v9 = *(_DWORD *)(dword_18A604 + 4 * (v8 & 0x3FF));
        v10 = v8 >> v9;
        v11 = byte_18A6C0 + 16 - v9;
        v12 = (unsigned int *)(dword_18A6A4 + (v9 >> 8));
        v13 = *v12;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v12 )
          goto LABEL_16;
      }
      do
      {
        v15 = v13 >> 13;
        if ( !--v11 )
        {
          v10 = *g_smkFrameCursor++;
          v11 = 32;
        }
        v16 = 0xFFFF8u & v15;
        v17 = v10 & 1;
        v10 >>= 1;
        if ( !v17 )
          v16 = 4;
        v12 = (unsigned int *)((char *)v12 + v16);
        v13 = *v12;
      }
      while ( (_WORD)dword_18A6D0 == (uint16_t)*v12 );
LABEL_16:
      byte_18A6C0 = v11;
      HIWORD(v18) = HIWORD(v13);
      if ( *(_DWORD *)block18A610[5] != v13 )
      {
        dword_18A678 = v13;
        v18 = *(_DWORD *)block18A610[5];
        v19 = (int *)block18A610[6];
        *(_DWORD *)block18A610[5] = v13;
        v20 = (int *)block18A610[7];
        v21 = *v19;
        *v19 = v18;
        HIWORD(v18) = HIWORD(dword_18A678);
        *v20 = v21;
      }
      v22 = (int *)dword_18A6D0;
      if ( (uint8_t)byte_18A6C0 > 0xBu )
      {
        v29 = *(_DWORD *)(dword_18A600 + 4 * (v10 & 0x7FF));
        g_smkFrameAccum = v10 >> v29;
        v26 = byte_18A6C0 - v29;
        v27 = (unsigned int *)(dword_18A6A4 + (v29 >> 8));
        v28 = *v27;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v27 )
          goto LABEL_27;
      }
      else
      {
        v23 = *g_smkFrameCursor;
        g_smkFrameCursor = (unsigned int *)((char *)g_smkFrameCursor + 2);
        v24 = v10 | (v23 << (byte_18A6C0 - 1));
        v25 = *(_DWORD *)(dword_18A600 + 4 * (v24 & 0x7FF));
        g_smkFrameAccum = v24 >> v25;
        v26 = byte_18A6C0 + 16 - v25;
        v27 = (unsigned int *)(dword_18A6A4 + (v25 >> 8));
        v28 = *v27;
        if ( (_WORD)dword_18A6D0 != (uint16_t)*v27 )
          goto LABEL_27;
      }
      do
      {
        v30 = v28 >> 13;
        if ( !--v26 )
        {
          g_smkFrameAccum = *g_smkFrameCursor++;
          v26 = 32;
        }
        v31 = 0xFFFF8u & v30;
        v17 = g_smkFrameAccum & 1;
        g_smkFrameAccum >>= 1;
        if ( !v17 )
          v31 = 4;
        v27 = (unsigned int *)((char *)v27 + v31);
        v28 = *v27;
      }
      while ( (_WORD)dword_18A6D0 == (uint16_t)*v27 );
LABEL_27:
      {
        static unsigned s_leafCount = 0;
        static unsigned s_nonzeroHiCount = 0;
        static unsigned s_lastLeaf = 0;
        ++s_leafCount;
        if ( (v28 >> 16) != 0 ) ++s_nonzeroHiCount;
        s_lastLeaf = v28;
        if ( (s_leafCount % 200003) == 1 )
        {
          PortDebug_Checkpoint("1664F0.leaf.count", (int)s_leafCount);
          PortDebug_Checkpoint("1664F0.leaf.nonzeroHi", (int)s_nonzeroHiCount);
          PortDebug_Checkpoint("1664F0.leaf.last", (int)s_lastLeaf);
          s_nonzeroHiCount = 0;
        }
      }
      v32 = __ROR4__(v28, 16);
      byte_18A6C0 = v26;
      LOWORD(v18) = v32;
      v33 = __ROR4__(v32, 16);
      if ( *(_DWORD *)block18A610[1] != v33 )
      {
        dword_18A678 = v18;
        v34 = *(_DWORD *)block18A610[1];
        v22 = (int *)block18A610[2];
        *(_DWORD *)block18A610[1] = v33;
        v35 = (_DWORD *)block18A610[3];
        v36 = *v22;
        *v22 = v34;
        v18 = dword_18A678;
        *v35 = v36;
      }
      HIWORD(v37) = HIWORD(v18);
      v38 = BYTE1(v18);
      LOWORD(v37) = __ROR4__(v18, 16);
      // PORT (wave 25r-3): was two truncated funcs_164C45[] calls whose EBX
      // half IDA had modeled as the stale `v22` cache pointer - see
      // Smk_ExpandMonoRows above for the asm evidence and the derivation.
      {
        unsigned int rowEax0, rowEbx0, rowEax1, rowEbx1;

        Smk_ExpandMonoRows((uint8_t)v18, (unsigned int)v37, &rowEax0, &rowEbx0);
        Smk_ExpandMonoRows((uint8_t)v38, (unsigned int)v37, &rowEax1, &rowEbx1);

        *g_smkFrameOutput = rowEax0;
        v40 = (int **)((char *)g_smkFrameOutput + dword_18A660);
        *(unsigned int *)v40 = rowEbx0;
        v41 = (int **)((char *)v40 + dword_18A660);
        *(unsigned int *)v41 = rowEax1;
        v43 = (int **)((char *)v41 + dword_18A660);
        *(unsigned int *)v43 = rowEbx1;
      }
      g_smkFrameOutput = (_DWORD *)((char *)v43 - dword_18A66C);
      if ( !--dword_18A668 )
        break;
      if ( !--dword_18A664 )
        goto LABEL_44;
    }
    if ( !--dword_18A670 )
      break;
    g_smkFrameOutput = (_DWORD *)((char *)g_smkFrameOutput + dword_18A688);
LABEL_34:
    dword_18A668 = dword_18A674;
    if ( !--dword_18A664 )
LABEL_44:
      return SmkFrame_Continue;
  }
  if ( (dword_18A6AC & 1) == 0 )
    goto LABEL_45;
  while ( 2 )
  {
    v44 = dword_18A6A0;
    LOWORD(v42) = *(_WORD *)dword_18A6A0;
    if ( *(_WORD *)dword_18A6A0 < 0xFFFDu )
    {
      dword_18A69C(v42);
LABEL_42:
      v46 = (uint16_t *)(v44 + 2);
      dword_18A660 = *v46;
      dword_18A674 = v46[1];
      dword_18A668 = dword_18A674;
      dword_18A66C = v46[2];
      dword_18A684 = v46[3];
      dword_18A688 = v46[4];
      v46 += 5;
      dword_18A670 = v46[2];
      v42 = *(_DWORD **)v46;
      dword_18A6A0 = (int)(v46 + 3);
      g_smkFrameOutput = v42;
      if ( dword_18A670 )
        goto LABEL_34;
      continue;
    }
    break;
  }
  if ( (_WORD)v42 == 0xFFFE )
    goto LABEL_42;
  if ( (_WORD)v42 == 0xFFFF )
LABEL_45:
    return SmkFrame_Done;
  sub_164920(dword_18A6A0);
  return SmkFrame_Done;
}
// 16673E: control flows out of bounds to 1675C0
// 16678A: control flows out of bounds to 1676C0
// 1666FC: variable 'v39' is possibly undefined
// 16671A: variable 'v42' is possibly undefined
// 18A600: using guessed type int dword_18A600;
// 18A604: using guessed type int dword_18A604;
// 18A660: using guessed type int dword_18A660;
// 18A664: using guessed type int dword_18A664;
// 18A668: using guessed type int dword_18A668;
// 18A66C: using guessed type int dword_18A66C;
// 18A670: using guessed type int dword_18A670;
// 18A674: using guessed type int dword_18A674;
// 18A678: using guessed type int dword_18A678;
// 18A684: using guessed type int dword_18A684;
// 18A688: using guessed type int dword_18A688;
// 18A69C: using guessed type int (*dword_18A69C)(_DWORD);
// 18A6A0: using guessed type int dword_18A6A0;
// 18A6A4: using guessed type int dword_18A6A4;
// 18A6AC: using guessed type int dword_18A6AC;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A6D0: using guessed type int dword_18A6D0;
// 18A7F0: using guessed type int dword_18A7F0;
// 18A7F4: using guessed type int dword_18A7F4;
// 18A7F8: using guessed type int dword_18A7F8;
// 18A800: using guessed type int (*funcs_164C45[256])();


//----- (00167320) --------------------------------------------------------
_BYTE *sub_167320(unsigned int *a1, int a2, int a3)
{
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  int v5; // ecx
  int v9; // edx
  unsigned int v13; // ebp
  unsigned int *v14; // esi
  int v15; // eax
  int v16; // edi
  _BYTE *result; // eax
  uint16_t *v18; // edi
  int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // ebp
  unsigned int v22; // ecx
  unsigned int v23; // ebp
  char v24; // al
  unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // edx
  char v30; // cf
  int v31; // edx
  int v32; // edx
  int *v33; // ebx
  int *v34; // ecx
  int v35; // edx
  int v36; // [esp-18h] [ebp-18h]

  dword_18A6A4 = a2;
  v3 = (_DWORD *)(a2 + 29716);
  LOWORD(dword_18A6D0) = *(_DWORD *)(a2 + 29712);
  v4 = &block18A610[0];
  v5 = 4;
  // PORT (wave 25j): asm is a plain `lodsd/stosd` copy loop (4 groups of 4
  // 32-bit dwords each) with a self-referential backpatch (`mov [eax],edx`
  // - the 2nd/3rd/4th dword of each group is a stored 32-bit value that
  // also doubles as the address to write the group's 1st ("self") value
  // into). The decompiler represented the walking cursor as `_DWORD **v7`
  // and read through it with `*v7++` - on x86 sizeof(_DWORD*)==4 so this
  // coincidentally matched the intended 4-byte stride and the intended
  // 32-bit-value read, but on x64 sizeof(_DWORD**)==8: `v7++` skips 8
  // bytes instead of 4 (misaligning every read after the first), and
  // `*v7` dereferences 8 bytes instead of 4 (pulling in an unrelated
  // adjacent dword as the pointer's high half). Rewritten with explicit
  // uint32_t indexing so every read is exactly 4 bytes, matching lodsd,
  // and the stored 32-bit values are only widened to pointers at the
  // point they're actually dereferenced as backpatch targets.
  do
  {
    uint32_t g0 = v3[0];
    uint32_t g1 = v3[1];
    uint32_t g2 = v3[2];
    uint32_t g3 = v3[3];
    v9 = g0;
    v4[0] = g0;
    v4[1] = g1;
    v4[2] = g2;
    v4[3] = g3;
    *(_DWORD *)(uintptr_t)g1 = v9;
    *(_DWORD *)(uintptr_t)g2 = v9;
    *(_DWORD *)(uintptr_t)g3 = v9;
    v3 += 4;
    v4 += 4;
    --v5;
  }
  while ( v5 );
  dword_18A600 = a2 + 16;
  dword_18A604 = a2 + 8208;
  dword_18A608 = a2 + 12304;
  dword_18A60C = a2 + 28688;
  {
    /* PORT (wave 25q): one-shot dump of the playback lookup tables built by
       sub_164590, for byte-exact comparison against the original. */
    static int s_dumpedPlay = 0;
    int k;
    if ( !s_dumpedPlay )
    {
      s_dumpedPlay = 1;
      for ( k = 0; k < 16; ++k )
        PortDebug_Checkpoint("167320.playtree600", *(int *)(dword_18A600 + 4 * k));
      PortDebug_Checkpoint("167320.playtree.a2", a2);
    }
  }
  v13 = *a1;
  v14 = a1 + 1;
  byte_18A6C0 = 33;
  dword_18A6AC = !(*(_BYTE *)a3 & 1);
  PortDebug_Checkpoint("167320.dword_18A6AC", dword_18A6AC);
  PortDebug_Checkpoint("167320.byte_a3plus1", *(_BYTE *)(a3 + 1));
  if ( (*(_BYTE *)(a3 + 1) & 1) != 0 )
  {
    if ( (dword_18A6AC & 1) != 0 )
    {
      dword_18A650 = (int)&loc_164A90;
      dword_18A654 = (int)&loc_164DF0;
      dword_18A658 = (int)&loc_167084;
      dword_18A65C = (int)&loc_165600;
    }
    else
    {
      dword_18A650 = (int)sub_164A40;
      dword_18A654 = (int)sub_164DA0;
      dword_18A658 = (int)sub_167040;
      dword_18A65C = (int)sub_1655B0;
    }
    dword_18A6A8 = 1;
  }
  else
  {
    if ( (dword_18A6AC & 1) != 0 )
    {
      dword_18A650 = (int)&loc_166540;
      dword_18A654 = (int)&loc_166880;
      dword_18A658 = (int)&loc_167084;
      dword_18A65C = (int)&loc_1671E0;
    }
    else
    {
      dword_18A650 = (int)sub_1664F0;
      dword_18A654 = (int)sub_166830;
      dword_18A658 = (int)sub_167040;
      dword_18A65C = (int)sub_167190;
    }
    dword_18A6A8 = 0;
  }
  if ( (dword_18A6AC & 1) == 0 )
  {
    dword_18A674 = *(_DWORD *)(a3 + 8);
    dword_18A668 = dword_18A674;
    dword_18A670 = *(_DWORD *)(a3 + 12);
    dword_18A66C = *(_DWORD *)(a3 + 16);
    dword_18A684 = *(_DWORD *)(a3 + 20);
    dword_18A660 = *(_DWORD *)(a3 + 24);
    dword_18A688 = *(_DWORD *)(a3 + 28);
    v19 = *(_DWORD *)(a3 + 4);
    {
      static unsigned s_167320EntryCount = 0;
      ++s_167320EntryCount;
      PortDebug_Checkpoint("167320.strides.n", (int)s_167320EntryCount);
      PortDebug_Checkpoint("167320.strides.674", dword_18A674);
      PortDebug_Checkpoint("167320.strides.670", dword_18A670);
      PortDebug_Checkpoint("167320.strides.66C", dword_18A66C);
      PortDebug_Checkpoint("167320.strides.684", dword_18A684);
      PortDebug_Checkpoint("167320.strides.660", dword_18A660);
      PortDebug_Checkpoint("167320.strides.688", dword_18A688);
    }
    *(_DWORD *)(a3 + 32) = 0;
    *(_DWORD *)(a3 + 44) = 0;
    *(_DWORD *)(a3 + 48) = 0;
    dword_18A7F8 = a3 + 56;
    dword_18A7F4 = 0;
    dword_18A7F0 = 0;
    // PORT (wave 25o): seed the shared per-frame decode trampoline state -
    // see g_smkFrame*/Smk167320_DecodeBlockTypeAndDispatch. The original's
    // `jmp dword_18A650[ecx*4]` never returns to this stack frame; the
    // replacement loop calls the (now-real) dispatch chain until it signals
    // completion, then falls through to loc_1676CF's epilogue below (the
    // dword_18A6AC==0 completion path - writes one completion byte).
    g_smkFrameAccum = v13;
    g_smkFrameCursor = v14;
    g_smkFrameOutput = (_DWORD *)(uintptr_t)v19;
    // PORT (wave 25o): eax (v19) itself is seeded here too - the block-type
    // decoder only ever does `mov ax,...` (LOWORD writes), relying on the
    // rest of eax already holding this same value from this point on.
    g_smkBlockTypeSymbol = v19;
    PortDebug_Checkpoint("167320.seed.g_smkFrameAccum", g_smkFrameAccum);
    PortDebug_CheckpointPtr("167320.seed.g_smkFrameCursor", (void*)g_smkFrameCursor);
    PortDebug_Checkpoint("167320.seed.byte_18A6C0", (unsigned char)byte_18A6C0);
    PortDebug_CheckpointPtr("167320.seed.a1raw", (void*)a1);
    PortDebug_CheckpointPtr("167320.seed.g_smkFrameOutput", (void*)g_smkFrameOutput);
    // PORT (wave 25r-6): in the ORIGINAL this pointer lands inside the linear
    // VESA framebuffer - edi=0x46B094 with framebuf=0x452044, i.e. exactly
    // base+102480 = base + (160*640+80), the video rect's origin. Log the
    // port's framebuffer base and the offset so the two can be compared.
    PortDebug_CheckpointPtr("167320.seed.fbBase", (void*)PortVga_Framebuffer());
    PortDebug_Checkpoint("167320.seed.outMinusFb",
                         (int)((char *)g_smkFrameOutput - (char *)PortVga_Framebuffer()));
    PortDebug_Checkpoint("167320.seed.outMinus1BB904",
                         (int)((char *)g_smkFrameOutput - (char *)(uintptr_t)dword_1BB904));
    PortDebug_Checkpoint("167320.seed.outMinus1BB90C",
                         (int)((char *)g_smkFrameOutput - (char *)(uintptr_t)dword_1BB90C));
    PortDebug_Checkpoint("167320.seed.outMinus1BB8FC",
                         (int)((char *)g_smkFrameOutput - (char *)(uintptr_t)dword_1BB8FC));
    // PORT (wave 25r-7): the decoder's target address is baked into the frame
    // table by sub_14AA40 from whatever dword_1BB904 was at CONFIG time. If
    // the primary/secondary pair swaps afterwards, the video keeps writing to
    // the stale surface and a later secondary<->primary copy wipes part of
    // the freshly decoded frame - which is what 2048 unwritten blocks
    // (32768 px, all "10 -> 0") on the cinematic's first frame look like.
    { extern unsigned g_blitCount;
      PortDebug_Checkpoint("167320.seed.blit", (int)g_blitCount);
      PortDebug_Checkpoint("167320.seed.target_primary",
                           (char *)g_smkFrameOutput - (char *)(uintptr_t)dword_1BB90C == 102480);
      PortDebug_Checkpoint("167320.seed.target_secondary",
                           (char *)g_smkFrameOutput - (char *)(uintptr_t)dword_1BB8FC == 102480); }
    PortDebug_CheckpointPtr("167320.seed.a2", (void*)(uintptr_t)a2);
    PortDebug_CheckpointPtr("167320.seed.a3", (void*)(uintptr_t)a3);
    while ( Smk167320_DecodeBlockTypeAndDispatch() == SmkFrame_Continue )
      ;
    result = (_BYTE *)(dword_18A7F8 + ((unsigned int)dword_18A7F0 >> 4));
    *result = 0;
    return result;
  }
  // PORT (wave 25k): a3+4 is a plain 32-bit stored function-pointer value
  // (see the `*(_DWORD*)(a3+4)` read a few lines up, and the whole family
  // of `*(_DWORD*)(a3+N)` reads around it) - `*(int(**)(_DWORD))(a3+4)`
  // dereferences it as a native (8-byte on x64) pointer-to-pointer,
  // pulling in the adjacent `a3+8` dword as the address's high half and
  // producing a garbage function pointer that crashes on call. Same bug
  // class as the rest of this file, fixed by reading the 32-bit value and
  // widening it explicitly.
  dword_18A69C = (int (*)(_DWORD))(uintptr_t)*(_DWORD *)(a3 + 4);
  PortDebug_Checkpoint("167320.a3.raw", a3);
  PortDebug_Checkpoint("167320.a3plus4.raw", *(_DWORD *)(a3 + 4));
  PortDebug_CheckpointPtr("167320.dword_18A69C", (void*)dword_18A69C);
  v15 = *(uint16_t *)(a3 + 8);
  dword_18A680 = v15;
  dword_18A6A0 = a3 + 10;
  v36 = v15;
  while ( 1 )
  {
    v16 = dword_18A6A0;
    LOWORD(v15) = *(_WORD *)dword_18A6A0;
    if ( *(_WORD *)dword_18A6A0 < 0xFFFDu )
    {
      dword_18A69C(v15);
      goto LABEL_19;
    }
    if ( (_WORD)v15 != 0xFFFE )
      break;
LABEL_19:
    v18 = (uint16_t *)(v16 + 2);
    dword_18A660 = *v18;
    dword_18A674 = v18[1];
    dword_18A668 = dword_18A674;
    dword_18A66C = v18[2];
    dword_18A684 = v18[3];
    dword_18A688 = v18[4];
    v18 += 5;
    dword_18A670 = v18[2];
    v15 = *(_DWORD *)v18;
    dword_18A6A0 = (int)(v18 + 3);
    if ( dword_18A670 )
    {
      g_smkBlockTypeSymbol = (g_smkBlockTypeSymbol & 0xFFFF) | (HIWORD(v36) << 16);
      // PORT (wave 25o): this is the dword_18A6AC==1 sibling of the
      // seeded-loop replacement below - NOT confirmed live by any video
      // observed so far (dword_18A6AC was 0 every time checked), so the
      // g_smkFrameOutput seed here is a best-effort guess (asm never
      // reassigns edi in this branch, so it should still hold whatever it
      // was left as - unverified). Flagged so a hit is visible in the trace.
      PortDebug_Checkpoint("167320.UNVERIFIED_dword_18A6AC_eq_1_path", dword_18A6AC);
      g_smkFrameAccum = v13;
      g_smkFrameCursor = v14;
      while ( Smk167320_DecodeBlockTypeAndDispatch() == SmkFrame_Continue )
        ;
      if ( (dword_18A6AC & 1) != 0 )
        return (_BYTE *)v36;
      result = (_BYTE *)(dword_18A7F8 + ((unsigned int)dword_18A7F0 >> 4));
      *result = 0;
      return result;
    }
  }
  if ( (_WORD)v15 != 0xFFFF )
    return (_BYTE *)sub_164920(dword_18A6A0);
  if ( (dword_18A6AC & 1) != 0 )
    return (_BYTE *)v36;
  result = (_BYTE *)(dword_18A7F8 + ((unsigned int)dword_18A7F0 >> 4));
  *result = 0;
  return result;
}
// 164DA0: using guessed type int sub_164DA0();
// 1655B0: using guessed type int sub_1655B0();
// 166830: using guessed type int sub_166830();
// 167040: using guessed type int sub_167040();
// 167190: using guessed type int sub_167190();
// 18A600: using guessed type int dword_18A600;
// 18A604: using guessed type int dword_18A604;
// 18A608: using guessed type int dword_18A608;
// 18A60C: using guessed type int dword_18A60C;
// 18A650: using guessed type int dword_18A650;
// 18A654: using guessed type int dword_18A654;
// 18A658: using guessed type int dword_18A658;
// 18A65C: using guessed type int dword_18A65C;
// 18A660: using guessed type int dword_18A660;
// 18A664: using guessed type int dword_18A664;
// 18A668: using guessed type int dword_18A668;
// 18A66C: using guessed type int dword_18A66C;
// 18A670: using guessed type int dword_18A670;
// 18A674: using guessed type int dword_18A674;
// 18A678: using guessed type int dword_18A678;
// 18A680: using guessed type int dword_18A680;
// 18A684: using guessed type int dword_18A684;
// 18A688: using guessed type int dword_18A688;
// 18A69C: using guessed type int (*dword_18A69C)(_DWORD);
// 18A6A0: using guessed type int dword_18A6A0;
// 18A6A4: using guessed type int dword_18A6A4;
// 18A6A8: using guessed type int dword_18A6A8;
// 18A6AC: using guessed type int dword_18A6AC;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A6D0: using guessed type int dword_18A6D0;
// 18A6E0: using guessed type int dword_18A6E0;
// 18A7F0: using guessed type int dword_18A7F0;
// 18A7F4: using guessed type int dword_18A7F4;
// 18A7F8: using guessed type int dword_18A7F8;


//----- (001676F0) --------------------------------------------------------
void sub_1676F0(unsigned int *a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // ebp
  unsigned int *v7; // esi
  _BOOL1 v8; // cf
  unsigned int v9; // ebp
  unsigned int v10; // ebp
  unsigned int v11; // ebp
  unsigned int v12; // ebp
  _BYTE *v13; // edi
  int v14; // edx
  char v15; // bl
  unsigned int v16; // ebp
  char v17; // al
  char v18; // cl
  char v19; // al
  unsigned int v20; // ebp
  char i2; // cl
  int *v22; // edx
  int i3; // eax
  unsigned int v24; // ebp
  unsigned int v25; // ebp
  _WORD *v26; // edi
  int v27; // edx
  char v28; // bl
  unsigned int v29; // ebp
  char v30; // al
  char v31; // cl
  char v32; // al
  unsigned int v33; // ebp
  int16_t v34; // ax
  char v35; // bl
  unsigned int v36; // ebp
  char v37; // cl
  char v38; // al
  unsigned int v39; // ebp
  int16_t mm; // cx
  int *v41; // edx
  int nn; // eax
  int *v43; // edx
  int i1; // eax
  unsigned int v45; // ebp
  unsigned int v46; // ebp
  unsigned int v47; // ebp
  _WORD *v48; // edi
  int v49; // edx
  char v50; // bl
  unsigned int v51; // ebp
  char v52; // al
  char v53; // cl
  char v54; // al
  unsigned int v55; // ebp
  int16_t v56; // ax
  char v57; // bl
  unsigned int v58; // ebp
  char v59; // cl
  char v60; // al
  unsigned int v61; // ebp
  int16_t ii; // cx
  int *v63; // edx
  int jj; // eax
  int *v65; // edx
  int kk; // eax
  unsigned int v67; // ebp
  unsigned int v68; // ebp
  unsigned int v69; // ebp
  unsigned int v70; // ebp
  int v71; // eax
  _DWORD *v72; // edi
  int v73; // edx
  char v74; // bl
  unsigned int v75; // ebp
  char v76; // al
  char v77; // cl
  char v78; // al
  unsigned int v79; // ebp
  char v80; // bl
  unsigned int v81; // ebp
  char v82; // cl
  char v83; // al
  unsigned int v84; // ebp
  int v85; // eax
  char v86; // bl
  unsigned int v87; // ebp
  char v88; // al
  char v89; // cl
  char v90; // al
  unsigned int v91; // ebp
  char v92; // bl
  unsigned int v93; // ebp
  char v94; // cl
  char v95; // al
  unsigned int v96; // ebp
  int i; // ecx
  int *v98; // edx
  int j; // eax
  int *v100; // edx
  int k; // eax
  int v102; // ecx
  int *v103; // edx
  int m; // eax
  int *v105; // edx
  int n; // eax

  dword_18AC20 = a2;
  dword_18AC24 = a3;
  dword_18AC28 = a4;
  dword_18AC2C = a5;
  dword_18AC30 = a6;
  {
    // PORT (vlna 26): dekomprese audia. Do vlny 26 se NIKDY nevolala, takze
    // je to cerstve spusteny kod - hlidame i NAVRAT, protoze trace konci
    // hned po prvni audio davce (podezreni na zacykleni uvnitr).
    static unsigned s_entryCount = 0;
    ++s_entryCount;
    if ( (s_entryCount % 50) == 1 )
    {
      PortDebug_Checkpoint("1676F0.entry.n", (int)s_entryCount);
      PortDebug_Checkpoint("1676F0.entry.a2", a2);
      PortDebug_Checkpoint("1676F0.entry.a4", a4);
      PortDebug_Checkpoint("1676F0.entry.a5", a5);
      PortDebug_Checkpoint("1676F0.entry.a6", a6);
    }
  }
  byte_18A6C0 = 0;
  v6 = *a1;
  v7 = a1 + 1;
  byte_18A6C0 = 32;
  v8 = v6 & 1;
  v9 = v6 >> 1;
  if ( v8 )
  {
    if ( !--byte_18A6C0 )
    {
      v9 = *v7;
      v7 = a1 + 2;
      byte_18A6C0 = 32;
    }
    v8 = v9 & 1;
    v10 = v9 >> 1;
    if ( v8 )
    {
      if ( !--byte_18A6C0 )
      {
        v10 = *v7++;
        byte_18A6C0 = 32;
      }
      v8 = v10 & 1;
      v45 = v10 >> 1;
      if ( v8 )
      {
        if ( !--byte_18A6C0 )
        {
          v45 = *v7++;
          byte_18A6C0 = 32;
        }
        v67 = v45 >> 1;
        dword_18A68C = dword_18AC24;
        // PORT (wave 25n): sub_164200 now consumes/reloads the persistent
        // g_smkBitAccum global internally - seed it with the locally-tracked
        // carry value before each call and read it back afterward instead of
        // trusting the pre-call local (which the call may have invalidated).
        g_smkBitAccum = v67;
        sub_164200((unsigned int *)dword_18AC24, &v7);
        if ( !--byte_18A6C0 )
        {
          g_smkBitAccum = *v7++;
          byte_18A6C0 = 32;
        }
        v68 = g_smkBitAccum >> 1;
        dword_18A690 = dword_18AC24 + 2048;
        g_smkBitAccum = v68;
        sub_164200((unsigned int *)(dword_18AC24 + 2048), &v7);
        if ( !--byte_18A6C0 )
        {
          g_smkBitAccum = *v7++;
          byte_18A6C0 = 32;
        }
        v69 = g_smkBitAccum >> 1;
        dword_18A694 = dword_18AC24 + 4096;
        g_smkBitAccum = v69;
        sub_164200((unsigned int *)(dword_18AC24 + 4096), &v7);
        if ( !--byte_18A6C0 )
        {
          g_smkBitAccum = *v7++;
          byte_18A6C0 = 32;
        }
        v70 = g_smkBitAccum >> 1;
        dword_18A698 = dword_18AC24 + 6144;
        g_smkBitAccum = v70;
        sub_164200((unsigned int *)(dword_18AC24 + 6144), &v7);
        // PORT (wave 25n): the code below consumes further bits directly out
        // of the accumulator via the `(uint8_t)byte_18A6C0 < 9u` idiom
        // (no separate reload-check step) - it must read the persistent
        // g_smkBitAccum (as left behind by the 4th sub_164200 call above),
        // not the stale pre-call local `v70`.
        if ( dword_18AC20 )
        {
          v72 = (_DWORD *)dword_18AC30;
          v73 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v73 = dword_18AC28 + v73 - dword_18AC2C;
          dword_18A7FC = v73;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v77 = byte_18A6C0;
            byte_18A6C0 += 24;
            v78 = g_smkBitAccum;
            --v77;
            v79 = *v7;
            v76 = (*v7++ << v77) | v78;
            v75 = v79 >> ~(v77 - 9);
          }
          else
          {
            v74 = g_smkBitAccum;
            byte_18A6C0 -= 8;
            v75 = g_smkBitAccum >> 8;
            v76 = v74;
          }
          BYTE1(v71) = v76;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v82 = byte_18A6C0;
            byte_18A6C0 += 24;
            v83 = v75;
            --v82;
            v84 = *v7;
            LOBYTE(v71) = (*v7++ << v82) | v83;
            v81 = v84 >> ~(v82 - 9);
          }
          else
          {
            v80 = v75;
            byte_18A6C0 -= 8;
            v81 = v75 >> 8;
            LOBYTE(v71) = v80;
          }
          v85 = v71 << 16;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v89 = byte_18A6C0;
            byte_18A6C0 += 24;
            v90 = v81;
            --v89;
            v91 = *v7;
            v88 = (*v7++ << v89) | v90;
            v87 = v91 >> ~(v89 - 9);
          }
          else
          {
            v86 = v81;
            byte_18A6C0 -= 8;
            v87 = v81 >> 8;
            v88 = v86;
          }
          BYTE1(v85) = v88;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v94 = byte_18A6C0;
            byte_18A6C0 += 24;
            v95 = v87;
            --v94;
            v96 = *v7;
            LOBYTE(v85) = (*v7++ << v94) | v95;
            v93 = v96 >> ~(v94 - 9);
          }
          else
          {
            v92 = v87;
            byte_18A6C0 -= 8;
            v93 = v87 >> 8;
            LOBYTE(v85) = v92;
          }
          for ( i = v85; ; i = __ROR4__(v102, 16) )
          {
            *v72++ = i;
            if ( (_DWORD *)dword_18A7FC == v72 )
              break;
            if ( (_DWORD *)dword_18AC2C == v72 )
              v72 = (_DWORD *)dword_18AC28;
            v98 = (int *)dword_18A68C;
            for ( j = *(_DWORD *)dword_18A68C; *v98 >= 0; j = *v98 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                j = 4;
              v98 = (int *)((char *)v98 + j);
            }
            v8 = __CFADD__((_BYTE)j, (_BYTE)i);
            LOBYTE(i) = j + i;
            BYTE1(i) += v8;
            v100 = (int *)dword_18A690;
            for ( k = *(_DWORD *)dword_18A690; *v100 >= 0; k = *v100 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                k = 4;
              v100 = (int *)((char *)v100 + k);
            }
            BYTE1(i) += k;
            v102 = __ROR4__(i, 16);
            v103 = (int *)dword_18A694;
            for ( m = *(_DWORD *)dword_18A694; *v103 >= 0; m = *v103 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                m = 4;
              v103 = (int *)((char *)v103 + m);
            }
            v8 = __CFADD__((_BYTE)m, (_BYTE)v102);
            LOBYTE(v102) = m + v102;
            BYTE1(v102) += v8;
            v105 = (int *)dword_18A698;
            for ( n = *(_DWORD *)dword_18A698; *v105 >= 0; n = *v105 )
            {
              if ( !--byte_18A6C0 )
              {
                v93 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v93 & 1;
              v93 >>= 1;
              if ( !v8 )
                n = 4;
              v105 = (int *)((char *)v105 + n);
            }
            BYTE1(v102) += n;
          }
        }
      }
      else
      {
        if ( !--byte_18A6C0 )
        {
          v45 = *v7++;
          byte_18A6C0 = 32;
        }
        v46 = v45 >> 1;
        dword_18A68C = dword_18AC24;
        // PORT (wave 25n): see the matching block above - sub_164200 reads
        // and reloads the persistent g_smkBitAccum global itself now.
        g_smkBitAccum = v46;
        sub_164200((unsigned int *)dword_18AC24, &v7);
        if ( !--byte_18A6C0 )
        {
          g_smkBitAccum = *v7++;
          byte_18A6C0 = 32;
        }
        v47 = g_smkBitAccum >> 1;
        dword_18A690 = dword_18AC24 + 2048;
        g_smkBitAccum = v47;
        sub_164200((unsigned int *)(dword_18AC24 + 2048), &v7);
        if ( dword_18AC20 )
        {
          v48 = (_WORD *)dword_18AC30;
          v49 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v49 = dword_18AC28 + v49 - dword_18AC2C;
          dword_18A7FC = v49;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v53 = byte_18A6C0;
            byte_18A6C0 += 24;
            v54 = g_smkBitAccum;
            --v53;
            v55 = *v7;
            v52 = (*v7++ << v53) | v54;
            v51 = v55 >> ~(v53 - 9);
          }
          else
          {
            v50 = g_smkBitAccum;
            byte_18A6C0 -= 8;
            v51 = g_smkBitAccum >> 8;
            v52 = v50;
          }
          HIBYTE(v56) = v52;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v59 = byte_18A6C0;
            byte_18A6C0 += 24;
            v60 = v51;
            --v59;
            v61 = *v7;
            LOBYTE(v56) = (*v7++ << v59) | v60;
            v58 = v61 >> ~(v59 - 9);
          }
          else
          {
            v57 = v51;
            byte_18A6C0 -= 8;
            v58 = v51 >> 8;
            LOBYTE(v56) = v57;
          }
          for ( ii = v56; ; HIBYTE(ii) += kk )
          {
            *v48++ = ii;
            if ( (_WORD *)dword_18A7FC == v48 )
              break;
            if ( (_WORD *)dword_18AC2C == v48 )
              v48 = (_WORD *)dword_18AC28;
            v63 = (int *)dword_18A68C;
            for ( jj = *(_DWORD *)dword_18A68C; *v63 >= 0; jj = *v63 )
            {
              if ( !--byte_18A6C0 )
              {
                v58 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v58 & 1;
              v58 >>= 1;
              if ( !v8 )
                jj = 4;
              v63 = (int *)((char *)v63 + jj);
            }
            LOBYTE(ii) = jj + ii;
            v65 = (int *)dword_18A690;
            for ( kk = *(_DWORD *)dword_18A690; *v65 >= 0; kk = *v65 )
            {
              if ( !--byte_18A6C0 )
              {
                v58 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v58 & 1;
              v58 >>= 1;
              if ( !v8 )
                kk = 4;
              v65 = (int *)((char *)v65 + kk);
            }
          }
        }
      }
    }
    else
    {
      if ( !--byte_18A6C0 )
      {
        v10 = *v7++;
        byte_18A6C0 = 32;
      }
      v8 = v10 & 1;
      v11 = v10 >> 1;
      if ( v8 )
      {
        if ( !--byte_18A6C0 )
        {
          v11 = *v7++;
          byte_18A6C0 = 32;
        }
        v24 = v11 >> 1;
        dword_18A68C = dword_18AC24;
        // PORT (wave 25n): see the matching block above - sub_164200 reads
        // and reloads the persistent g_smkBitAccum global itself now.
        g_smkBitAccum = v24;
        sub_164200((unsigned int *)dword_18AC24, &v7);
        if ( !--byte_18A6C0 )
        {
          g_smkBitAccum = *v7++;
          byte_18A6C0 = 32;
        }
        v25 = g_smkBitAccum >> 1;
        dword_18A690 = dword_18AC24 + 2048;
        g_smkBitAccum = v25;
        sub_164200((unsigned int *)(dword_18AC24 + 2048), &v7);
        if ( dword_18AC20 )
        {
          v26 = (_WORD *)dword_18AC30;
          v27 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v27 = dword_18AC28 + v27 - dword_18AC2C;
          dword_18A7FC = v27;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v31 = byte_18A6C0;
            byte_18A6C0 += 24;
            v32 = g_smkBitAccum;
            --v31;
            v33 = *v7;
            v30 = (*v7++ << v31) | v32;
            v29 = v33 >> ~(v31 - 9);
          }
          else
          {
            v28 = g_smkBitAccum;
            byte_18A6C0 -= 8;
            v29 = g_smkBitAccum >> 8;
            v30 = v28;
          }
          HIBYTE(v34) = v30;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v37 = byte_18A6C0;
            byte_18A6C0 += 24;
            v38 = v29;
            --v37;
            v39 = *v7;
            LOBYTE(v34) = (*v7++ << v37) | v38;
            v36 = v39 >> ~(v37 - 9);
          }
          else
          {
            v35 = v29;
            byte_18A6C0 -= 8;
            v36 = v29 >> 8;
            LOBYTE(v34) = v35;
          }
          for ( mm = v34; ; HIBYTE(mm) += i1 )
          {
            *v26++ = mm;
            if ( (_WORD *)dword_18A7FC == v26 )
              break;
            if ( (_WORD *)dword_18AC2C == v26 )
              v26 = (_WORD *)dword_18AC28;
            v41 = (int *)dword_18A68C;
            for ( nn = *(_DWORD *)dword_18A68C; *v41 >= 0; nn = *v41 )
            {
              if ( !--byte_18A6C0 )
              {
                v36 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v36 & 1;
              v36 >>= 1;
              if ( !v8 )
                nn = 4;
              v41 = (int *)((char *)v41 + nn);
            }
            v8 = __CFADD__((_BYTE)nn, (_BYTE)mm);
            LOBYTE(mm) = nn + mm;
            HIBYTE(mm) += v8;
            v43 = (int *)dword_18A690;
            for ( i1 = *(_DWORD *)dword_18A690; *v43 >= 0; i1 = *v43 )
            {
              if ( !--byte_18A6C0 )
              {
                v36 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v36 & 1;
              v36 >>= 1;
              if ( !v8 )
                i1 = 4;
              v43 = (int *)((char *)v43 + i1);
            }
          }
        }
      }
      else
      {
        if ( !--byte_18A6C0 )
        {
          v11 = *v7++;
          byte_18A6C0 = 32;
        }
        v12 = v11 >> 1;
        dword_18A68C = dword_18AC24;
        // PORT (wave 25n): see the matching block above - sub_164200 reads
        // and reloads the persistent g_smkBitAccum global itself now.
        g_smkBitAccum = v12;
        sub_164200((unsigned int *)dword_18AC24, &v7);
        if ( dword_18AC20 )
        {
          v13 = (_BYTE *)dword_18AC30;
          v14 = dword_18AC30 + dword_18AC20;
          if ( dword_18AC2C < (unsigned int)(dword_18AC30 + dword_18AC20) )
            v14 = dword_18AC28 + v14 - dword_18AC2C;
          dword_18A7FC = v14;
          if ( (uint8_t)byte_18A6C0 < 9u )
          {
            v18 = byte_18A6C0;
            byte_18A6C0 += 24;
            v19 = g_smkBitAccum;
            --v18;
            v20 = *v7;
            v17 = (*v7++ << v18) | v19;
            v16 = v20 >> ~(v18 - 9);
          }
          else
          {
            v15 = g_smkBitAccum;
            byte_18A6C0 -= 8;
            v16 = g_smkBitAccum >> 8;
            v17 = v15;
          }
          for ( i2 = v17; ; i2 += i3 )
          {
            *v13++ = i2;
            if ( (_BYTE *)dword_18A7FC == v13 )
              break;
            if ( (_BYTE *)dword_18AC2C == v13 )
              v13 = (_BYTE *)dword_18AC28;
            v22 = (int *)dword_18A68C;
            for ( i3 = *(_DWORD *)dword_18A68C; *v22 >= 0; i3 = *v22 )
            {
              if ( !--byte_18A6C0 )
              {
                v16 = *v7++;
                byte_18A6C0 = 32;
              }
              v8 = v16 & 1;
              v16 >>= 1;
              if ( !v8 )
                i3 = 4;
              v22 = (int *)((char *)v22 + i3);
            }
          }
        }
      }
    }
  }
  PortDebug_Checkpoint("1676F0.RETURNED", 1);
}
// 167D64: variable 'v71' is possibly undefined
// 18A68C: using guessed type int dword_18A68C;
// 18A690: using guessed type int dword_18A690;
// 18A694: using guessed type int dword_18A694;
// 18A698: using guessed type int dword_18A698;
// 18A6C0: using guessed type char byte_18A6C0;
// 18A7FC: using guessed type int dword_18A7FC;
// 18AC20: using guessed type int dword_18AC20;
// 18AC24: using guessed type int dword_18AC24;
// 18AC28: using guessed type int dword_18AC28;
// 18AC2C: using guessed type int dword_18AC2C;
// 18AC30: using guessed type int dword_18AC30;


//----- (00167F20) --------------------------------------------------------
unsigned int sub_167F20(int a1, int a2)
{
  return ((unsigned int)(a2 * a1) >> 8) + 32;
}


//----- (00167F40) --------------------------------------------------------
int sub_167F40(int a1, unsigned int *a2)
{
  _WORD *v2; // edi
  unsigned int v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  int result; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx

  // PORT (wave 25r-8): dirty-rect iterator over the just-decoded frame.
  // sub_14A2D0 (and through it sub_132869's sub_138CEE marking) yields
  // NOTHING if this returns 0 on the first call - measured symptom: during
  // the cinematic the video rect is marked dirty only once (blit 82), so the
  // decoded frames never reach the screen even though the back buffer is
  // pixel-perfect.
  {
    extern unsigned g_blitCount;
    if ( g_blitCount >= 82 && g_blitCount <= 85 )
    {
      PortDebug_Checkpoint("167F40.blit", (int)g_blitCount);
      PortDebug_Checkpoint("167F40.done32", *(uint8_t *)(uintptr_t)(a1 + 32));
      PortDebug_Checkpoint("167F40.f33", *(uint8_t *)(uintptr_t)(a1 + 33));
      PortDebug_Checkpoint("167F40.f34", *(uint8_t *)(uintptr_t)(a1 + 34));
      PortDebug_Checkpoint("167F40.n36", *(int *)(uintptr_t)(a1 + 36));
      PortDebug_Checkpoint("167F40.n40", *(int *)(uintptr_t)(a1 + 40));
      PortDebug_Checkpoint("167F40.n44", *(int *)(uintptr_t)(a1 + 44));
      PortDebug_Checkpoint("167F40.n48", *(int *)(uintptr_t)(a1 + 48));
      // Coverage array at a1+56: handlers mark it (sub_1664F0/sub_167190
      // write 1, sub_167040 writes 0) and this iterator skips zero bytes.
      { const uint8_t *cov = (const uint8_t *)(uintptr_t)(a1 + 56);
        int nz = 0, i; for ( i = 0; i < 320; ++i ) if ( cov[i] ) ++nz;
        PortDebug_Checkpoint("167F40.cov_nonzero_of_320", nz);
        PortDebug_Checkpoint("167F40.cov_byte0", cov[0]); }
    }
  }

  if ( *(_BYTE *)(a1 + 32) )
    return 0;
  // PORT (wave 25p): a1+52 is a plain 32-bit stored pointer value (same
  // family as the rest of this file) - `*(_WORD**)` dereferences it as a
  // native 8-byte pointer on x64, pulling in the adjacent a1+56 dword as
  // the high half and producing a garbage (0xFFFFFFFF‘xxxxxxxx) pointer.
  v2 = (_WORD *)(uintptr_t)*(_DWORD *)(a1 + 52);
  if ( *(_BYTE *)(a1 + 33) )
  {
    v8 = *(_DWORD *)(a1 + 48);
    if ( *(_DWORD *)(a1 + 40) > v8 )
    {
      a2[1] = v8;
      *a2 = 0;
      v3 = *(_DWORD *)(a1 + 44);
      if ( *(_DWORD *)(a1 + 36) <= v3 )
      {
        v9 = *(_DWORD *)(a1 + 36);
        a2[2] = v9;
        *(_DWORD *)(a1 + 44) = v3 - v9;
        *(_DWORD *)(a1 + 48) += 4;
      }
      else
      {
        *(_BYTE *)(a1 + 33) = 0;
        a2[2] = v3;
        if ( *v2 )
          goto LABEL_14;
      }
      a2[3] = 4;
      return 1;
    }
    goto LABEL_27;
  }
  if ( !*(_BYTE *)(a1 + 34) )
  {
    v2 = (_WORD *)(a1 + 56);
    *(_BYTE *)(a1 + 34) = 1;
  }
  v3 = *(_DWORD *)(a1 + 44);
  v4 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a1 + 40) <= v4 )
  {
LABEL_27:
    *(_BYTE *)(a1 + 32) = 1;
    return 0;
  }
  if ( !*(_BYTE *)v2 )
  {
    while ( !*(_BYTE *)v2 )
    {
      v2 = (_WORD *)((char *)v2 + 1);
      for ( v3 += 64; *(_DWORD *)(a1 + 36) <= v3; v3 -= *(_DWORD *)(a1 + 36) )
      {
        v4 += 4;
        if ( *(_DWORD *)(a1 + 40) <= v4 )
          goto LABEL_27;
      }
    }
    *(_DWORD *)(a1 + 48) = v4;
  }
  *a2 = v3;
  a2[1] = v4;
  a2[3] = 4;
  a2[2] = 0;
LABEL_14:
  while ( 1 )
  {
    v5 = v3 + 64;
    if ( *(_DWORD *)(a1 + 36) <= v3 + 64 )
      break;
    v2 = (_WORD *)((char *)v2 + 1);
    v3 += 64;
    a2[2] += 64;
    if ( !*(_BYTE *)v2 )
    {
      *(_DWORD *)(a1 + 44) = v5;
      goto LABEL_20;
    }
  }
  v6 = v5 - *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a1 + 44) = v6;
  if ( v6 )
    *(_BYTE *)(a1 + 33) = 1;
  a2[2] += 64 - v6;
  *(_DWORD *)(a1 + 48) += 4;
  v2 = (_WORD *)((char *)v2 + 1);
LABEL_20:
  result = 1;
  *(_DWORD *)(a1 + 52) = v2;
  return result;
}


//----- (00168060) --------------------------------------------------------
int sub_168060(int a1, _BYTE *a2)
{
  int v2; // ebx
  int16_t v3; // cx
  int *v4; // esi
  int i; // ecx
  int v6; // eax
  int *v7; // esi
  int j; // ecx
  int v9; // eax
  int result; // eax
  int *v11; // esi
  int k; // ecx

  v2 = 0;
  LOWORD(dword_18A6D0) = *(_WORD *)(a1 + 29712);
  LOBYTE(v3) = *a2;
  HIBYTE(v3) = *a2;
  *(_WORD *)(a1 + 29734) = v3;
  *(_WORD *)(a1 + 29750) = v3;
  v4 = (int *)(*(_DWORD *)a1 + a1 + 29800);
  for ( i = *(_DWORD *)(a1 + 4) >> 2; i; --i )
  {
    v6 = *v4++;
    if ( (_WORD)dword_18A6D0 != (_WORD)v6 )
    {
      LOBYTE(v2) = v6;
      LOBYTE(v6) = a2[v2];
      LOBYTE(v2) = BYTE1(v6);
      BYTE1(v6) = a2[v2];
      *((_WORD *)v4 - 1) = v6;
    }
  }
  v7 = (int *)(*(_DWORD *)(a1 + 4) + *(_DWORD *)a1 + a1 + 29800);
  for ( j = *(_DWORD *)(a1 + 8) >> 2; j; --j )
  {
    v9 = *v7++;
    if ( (_WORD)dword_18A6D0 != (_WORD)v9 )
    {
      LOBYTE(v2) = v9;
      LOBYTE(v9) = a2[v2];
      LOBYTE(v2) = BYTE1(v9);
      BYTE1(v9) = a2[v2];
      *((_WORD *)v7 - 1) = v9;
    }
  }
  result = *(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 4) + *(_DWORD *)a1;
  v11 = (int *)(result + a1 + 29800);
  for ( k = *(_DWORD *)(a1 + 12) >> 2; k; --k )
  {
    result = *v11++;
    if ( (_WORD)dword_18A6D0 != (_WORD)result && (result & 3) == 3 )
    {
      LOBYTE(v2) = BYTE1(result);
      BYTE1(result) = a2[v2];
      *((_BYTE *)v11 - 1) = BYTE1(result);
    }
  }
  return result;
}
// 18A6D0: using guessed type int dword_18A6D0;


//----- (00168541) --------------------------------------------------------
int sub_168541()
{
  _enable();
  return 0;
}


//----- (00168545) --------------------------------------------------------
int sub_168545()
{
  _disable();
  return 0;
}


//----- (00168549) --------------------------------------------------------
int sub_168549(int a1)
{
  uint8_t v1; // al

  v1 = hr_inbyte(a1);
  return (uint8_t)nullsub_22(v1, a1);
}
// 168692: using guessed type int nullsub_22(_DWORD, _DWORD);


//----- (00168560) --------------------------------------------------------
int sub_168560(int a1, int a2)
{
  hr_outbyte(a1, a2);
  return (uint8_t)nullsub_22(a2, a1);
}
// 168692: using guessed type int nullsub_22(_DWORD, _DWORD);


//----- (00168577) --------------------------------------------------------
char sub_168577(int a1, int a2)
{
  uint16_t v3; // dx
  int16_t v4; // cx
  _BOOL1 v5; // cc
  int16_t v6; // cx
  uint16_t v7; // dx
  uint8_t v8; // al
  int v9; // eax
  uint8_t v10; // al
  uint16_t v11; // dx

  _enable();
  do
  {
    v3 = *MK_FP(a2, a1 + 14);
    v4 = *MK_FP(a2, a1 + 18);
    v5 = v4 < *MK_FP(a2, a1 + 22);
    v6 = v4 - *MK_FP(a2, a1 + 22);
    if ( v5 )
      v6 += 1024;
    while ( 1 )
    {
      v7 = v3 + 5;
      v8 = hr_inbyte(v7);
      v9 = nullsub_22(v8, v7);
      v3 = v7 - 5;
      *MK_FP(a2, a1 + 30) = v9 | *MK_FP(a2, a1 + 30);
      LOBYTE(v9) = v9 & 1;
      if ( !(_BYTE)v9 )
        break;
      v10 = hr_inbyte(v3);
      if ( v6 < 1023 )
      {
        *MK_FP(a2, a1 + *MK_FP(a2, a1 + 18) + 58) = v10;
        *MK_FP(a2, a1 + 18) = *MK_FP(a2, a1 + 18) + 1;
        *MK_FP(a2, a1 + 18) = *MK_FP(a2, a1 + 18) & 0x3FF;
        ++v6;
      }
    }
    if ( v6 > 768 )
    {
      v11 = v3 + 4;
      LOBYTE(v9) = hr_inbyte(v11);
      LOBYTE(v9) = ~*MK_FP(a2, a1 + 34) & nullsub_22(v9, v11);
      hr_outbyte(v11, v9);
    }
    a1 = *MK_FP(a2, a1);
  }
  while ( a1 );
  return v9;
}
// 168692: using guessed type int nullsub_22(_DWORD, _DWORD);


//----- (001685E9) --------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void sub_1685E9(int a1)
{
  int v1; // esi
  int v2; // [esp-14h] [ebp-2Ch]
  int v3; // [esp-10h] [ebp-28h]

  __ES__ = *(_WORD *)&byte_18B040[4];
  v1 = a1 + *(_DWORD *)byte_18B040;
  v3 = *(_DWORD *)(a1 + *(_DWORD *)byte_18B040 + 42);
  v2 = *(_DWORD *)(a1 + *(_DWORD *)byte_18B040 + 46);
  ++*(_DWORD *)(v1 + 54);
  VCALL(v1 + 10, void (*)(_DWORD, _DWORD))(*(_DWORD *)(v1 + 20), *(uint16_t *)(v1 + 24));
  if ( (_WORD)v2 )
    hr_outbyte(v2, 0x20u);
  if ( (_WORD)v3 )
    hr_outbyte(v3, 0x20u);
  /* __asm: iret */ DECOMP_TODO("inline asm");
}
// 168635: positive sp value 4 has been found
// 168635: control flows out of bounds to 168636


//----- (00169020) --------------------------------------------------------
int sub_169020(int result, int a2, int a3)
{
  if ( a3 == 1 )
    result -= 66154;
  return result;
}


//----- (001690CF) --------------------------------------------------------
int sub_1690CF(int a1, int a2)
{
  int v3; // [esp-4h] [ebp-4h]

  v3 = a1;
  if ( *(_BYTE *)(a1 + 37828) == 1 )
    a1 = sub_1690F9(a1, 5, (uint16_t *)(a1 - 128918), a2);
  sub_1690F9(a1, 23, (uint16_t *)(a1 - 128908), a2);
  return v3;
}


//----- (001690F9) --------------------------------------------------------
int sub_1690F9(int a1, int a2, uint16_t *a3, int a4)
{
  int v4; // eax
  char v6; // [esp-1Ch] [ebp-20h]
  int v7; // [esp-18h] [ebp-1Ch]
  uint16_t *v8; // [esp-14h] [ebp-18h]
  int v9; // [esp-10h] [ebp-14h]

  BYTE1(a2) = *(_BYTE *)(a1 + 6656);
  v4 = *(_DWORD *)a1;
  do
  {
    v9 = a2;
    v8 = a3;
    do
    {
      v7 = v4;
      v6 = a2;
      sub_E4204(v4, *a3, a4);
      v4 = v7;
      ++a3;
      LOBYTE(a2) = a2 - 1;
    }
    while ( v6 != 1 );
    v4 = v7 + 3753;
    a3 = v8;
    a2 = v9;
    BYTE1(a2) = BYTE1(v9) - 1;
  }
  while ( BYTE1(v9) != 1 );
  return a1;
}


//----- (0016915C) --------------------------------------------------------
int sub_16915C(int result, int a2)
{
  *(_BYTE *)(result + 108) = HIBYTE(a2);
  if ( *(_BYTE *)(result + 100) != 5 )
    *(_BYTE *)(result + 100) = a2;
  return result;
}


//----- (00169169) --------------------------------------------------------
int sub_169169(int a1, int a2)
{
  int v3; // [esp-8h] [ebp-Ch]

  v3 = 5 * a2;
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 2500) + 129 * *(int16_t *)(a1 + v3 - 4) + 100) == 5 )
    *(_BYTE *)(v3 + a1) = 0;
  return 5 * a2;
}


//----- (001691A0) --------------------------------------------------------
void sub_1691A0()
{
  if ( !*(_BYTE *)GetGameFlagsTable_F4B81() )
    sub_7BBBC();
}


//----- (001691E7) --------------------------------------------------------
int sub_1691E7(int *a1, int a2)
{
  int v3; // eax

  v3 = (int)a1 - 7454;
  if ( *(_BYTE *)(v3 - 129003) == 0xFF )
    sub_1690F9(v3, 3, (uint16_t *)(v3 - 128982), a2);
  if ( *((_BYTE *)a1 - 137176) == 1 )
    sub_1692E4((int)a1 - 7454, a2);
  return sub_124820(*a1);
}


//----- (00169245) --------------------------------------------------------
void sub_169245()
{
  char v0; // bl
  int v1; // eax
  _BYTE *v2; // [esp-Ch] [ebp-Ch]

  sub_1691A0();
  v2 = GetGameFlagsTable_F4B81();
  v0 = v2[2] | v2[740] & 2 | v2[731] & 4;
  v1 = sub_16945B((int)v2);
  *(_BYTE *)(v1 + 14) = v0;
  *(_BYTE *)(v1 + 13) = 0;
}


//----- (001692A2) --------------------------------------------------------
_BOOL1 sub_1692A2( int a1, int a2, _BYTE *a3)
{
  _BOOL1 result; // al

  if ( (*(_BYTE *)(*(_DWORD *)((char *)GetGameFlagsTable_F4B81() + 109455) + 14) & 4) == 0 )
    return sub_17847(a1, a2, a3);
  sub_17847(a1, a2, a3);
  result = (char)a3;
  a3[4] = 0;
  return result;
}


//----- (001692C7) --------------------------------------------------------
void sub_1692C7( int a1, int a2, int a3)
{
  if ( (*(_BYTE *)(*(_DWORD *)((char *)GetGameFlagsTable_F4B81() + 109455) + 14) & 4) != 0 )
    *(_BYTE *)(a3 + 40) = 0;
  sub_1C417(a1, a2);
}


//----- (001692E4) --------------------------------------------------------
int sub_1692E4(int a1, int a2)
{
  char v2; // dh
  int v3; // eax
  int v5; // [esp-4h] [ebp-4h]

  v5 = sub_1690CF(a1, a2);
  v2 = *(_BYTE *)(v5 + 6656);
  v3 = *(_DWORD *)v5;
  do
  {
    *(_WORD *)(v3 + 199) = 771;
    *(_WORD *)(v3 + 216) = 770;
    v3 += 3753;
    --v2;
  }
  while ( v2 );
  return v5;
}


//----- (0016933A) --------------------------------------------------------
int sub_16933A( int a1)
{
  int v1; // eax
  _BYTE *v2; // eax
  int v4; // [esp-4h] [ebp-4h]

  LOBYTE(v1) = sub_8C4D3(a1);
  v4 = v1;
  v2 = GetGameFlagsTable_F4B81();
  if ( v2[620] )
    v2[137776] = 0;
  return v4;
}
// 16933F: variable 'v1' is possibly undefined


//----- (0016937A) --------------------------------------------------------
// PORT (vlna 61): zapnuti zaskrtavatka. Dekompilat sem dosadil dva vyrazy
// tvaru "GetGameFlagsTable_F4B81() + obri konstanta". Ten getter vraci
// `&unk_1784DD`, coz je v portu JEDEN BAJT, takze se cetlo 109455 resp.
// 136183 bajtu za nim -> pad na adrese 0x0000000E pri kliknuti na
// TACTICAL COMBAT. Adresni aritmetika je pritom jednoznacna a vede na
// skutecne symboly:
//     0x1784DD + 109455 = 0x19306C  -> dword_19306C
//     0x1784DD + 136183 = 0x1998D4  -> word_1998D4
// (druhy vyraz IDA navic zkomolila na `!= 136183`, coz da 0/1 - v originale
// to je adresa, ne porovnani).
// POZOR: tuhle funkci NELZE overit proti asm - Debug/diss/Orion2.exe.asm
// i .lst konci u sub_1685E9, tenhle rozsah uz nepokryvaji. Logicka struktura
// je proto ponechana presne tak, jak ji dala IDA; opraveny jsou jen ty dva
// pristupy do pameti.
void sub_16937A(char *a1)
{
  *(_WORD *)a1 = (dword_19306C[14] & 2) == 0 || a1 != (char *)&word_1998D4;
  JUMPOUT(0x11E68A);   /* skok zpet do sub_11CEF5, ktery hned za volanim vraci */
}
// 1693A5: control flows out of bounds to 11E68A


//----- (001693B6) --------------------------------------------------------
int sub_1693B6()
{
  int v0; // eax
  char *v1; // eax
  int result; // eax
  int v3; // [esp-4h] [ebp-4h]

  LOWORD(v0) = sub_798D2();
  v3 = v0;
  if ( (*((_BYTE *)GetGameFlagsTable_F4B81() + 2) & 1) != 0 )
  {
    v1 = (char *)GetGameFlagsTable_F4B81();
    *(_WORD *)((char *)&loc_2152F + (_DWORD)v1) = 1011;
    *(_WORD *)(v1 + 136493) = 800;
    *(_WORD *)(v1 + 136373) = 15;
    *(_WORD *)(v1 + 136387) = 20;
    *(_WORD *)(v1 + 136385) = 3;
    *(_WORD *)(v1 + 136351) = 3;
    return v3;
  }
  else
  {
    result = (uint16_t)v3;
    switch ( (int16_t)v3 )
    {
      case 0:
        word_199A0C = 506;
        word_199A0A = 400;
        word_199992 = 10;
        word_1999A0 = 10;
        word_19997C = 0;
        word_19999E = 0;
        break;
      case 1:
        word_199A0C = 759;
        word_199A0A = 600;
        word_199992 = 15;
        word_1999A0 = 15;
        word_19997C = 1;
        word_19999E = 1;
        break;
      case 2:
        word_199A0C = 1012;
        word_199A0A = 800;
        word_199992 = 20;
        word_1999A0 = 20;
        word_19999E = 2;
        word_19997C = 2;
        break;
      case 3:
        word_199A0C = 1518;
        word_199A0A = 1200;
        word_199992 = 30;
        word_1999A0 = 30;
        word_19997C = 3;
        word_19999E = 3;
        break;
      default:
        result = v3;
        break;
    }
  }
  return result;
}
// 1693BB: variable 'v0' is possibly undefined
// 19997C: using guessed type int16_t word_19997C;
// 199992: using guessed type int16_t word_199992;
// 19999E: using guessed type int16_t word_19999E;
// 1999A0: using guessed type int16_t word_1999A0;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;


//----- (00169410) --------------------------------------------------------
int sub_169410(int a1, int a2)
{
  GetGameFlagsTable_F4B81();
  return sub_12479(a1, a2);
}
// 12479: using guessed type _DWORD sub_12479(_DWORD, _DWORD);


//----- (0016945B) --------------------------------------------------------
int sub_16945B(int a1)
{
  return *(_DWORD *)(a1 + 109455);
}


//----- (0016946E) --------------------------------------------------------
void sub_16946E()
{
  GetGameFlagsTable_F4B81();
}


//----- (0016948F) --------------------------------------------------------
void sub_16948F()
{
  if ( (*(_BYTE *)(*(_DWORD *)((char *)GetGameFlagsTable_F4B81() + 109455) + 14) & 8) != 0 )
    *(_DWORD *)((char *)GetGameFlagsTable_F4B81() + 41713) = -65537;
}


//----- (001694B7) --------------------------------------------------------
// Returns destBase + 4*offset, clamped so the span [4*offset, 4*offset+4*len)
// stays inside the 307200-byte (640x480) visible framebuffer; on overflow the
// offset is clamped to 0 (start of buffer).
//
// PORT: the original was a thunk that read its destination base from
// a register the single caller (sub_125D4F) had loaded. Hex-Rays modeled that
// register as "*(a3-4)" where a3 = &savedregs = ebp+0, i.e. it read *(ebp-4) of
// the CALLER's frame - an uninitialized stack slot (debug fill 0xCCCCCCCC),
// which then flowed into sub_1276BD as a garbage destination pointer. The base
// is now passed explicitly by the caller (destBase) instead of scavenged off
// the stack.
unsigned int sub_1694B7(int offset, int len, int destBase)
{
  unsigned int byteOff = 4 * offset;
  if ( byteOff >= 0x4B000 || len < 0 || (int)(byteOff + 4 * len) >= 307200 )
    byteOff = 0;
  return destBase + byteOff;
}


//----- (001694B9) --------------------------------------------------------
void sub_1694B9( int a1)
{
  sub_4A4E4(a1);
  sub_4A5CE();
}


//----- (001694D9) --------------------------------------------------------
// Copies a3 dwords a2 -> a1, clamped to stay inside the visible framebuffer.
// PORT: the original clamped to the 0xA0000..0xBFFFC VGA window: out-of-range
// a1 was snapped to `&loc_BFFF4 + 8` (= 0xBFFFC, the last valid address) and the
// length forced to 1. In the port the framebuffer is a heap buffer far above
// 0xBFFFC, so a1 was ALWAYS >= 0xBFFFC and every write went to the 1-byte BSS
// symbol loc_BFFF4 instead of the screen — the sub_125814 dirty-span updates
// were silently dropped (missing/torn frames) and loc_BFFF4's neighbours got
// corrupted. Clamp against the real framebuffer [fb, fb+640*480) instead.
void *sub_1694D9(void *a1, void *a2, int a3)
{
  void *v4 = a1;
  unsigned char *fb = PortVga_Framebuffer();
  unsigned char *fbEnd = fb + 640 * 480;
  unsigned char *dst = (unsigned char *)a1;

  if ( dst < fb || dst >= fbEnd )
    return v4; // fully outside the framebuffer -> drop (was: snap to loc_BFFF4)
  if ( a3 > 0 && dst + 4 * a3 > fbEnd )
    a3 = (int)(fbEnd - dst) / 4; // clamp length to the framebuffer end
  if ( a3 > 0 )
    qmemcpy(a1, a2, 4 * a3);
  return v4;
}

// nfuncs=5399 queued=5098 decompiled=5098 lumina nreq=0 worse=0 better=0
// error "There were 35 decompilation failure(s) on 5098 function(s)"

