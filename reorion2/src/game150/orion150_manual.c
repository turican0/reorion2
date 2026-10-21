/* Wave 185: hand written parts of the 1.50 patch block - functions Hex-Rays could not decompile and the
   ones rewritten on the official Lua API. A function here (with its //----- (ADDR) marker) is skipped by
   tools/compare/gen150.py. */
#include "orion150.h"

void PortDebug_Message(const char *msg);
int sprintf(char *buf, const char *fmt, ...);

/* stub of a function that still works on the Lua internals of ORION150.EXE (orion150_lua_pending.c) */
void Lua150_Pending(uint32_t addr)
{
  static uint32_t seen[64];
  static int n;
  char buf[96];
  int i;

  for ( i = 0; i < n; ++i )
    if ( seen[i] == addr )
      return;
  if ( n < 64 )
    seen[n++] = addr;
  sprintf(buf, "1.50: Lua function 0x%X is not ported yet", (unsigned)addr);
  PortDebug_Message(buf);
}
