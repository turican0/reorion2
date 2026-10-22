/* Wave 185: hooks of the 1.50 patch the 1.31 game functions call (orion150_hooks.h). */
#include "orion150.h"
#include "orion150_hooks.h"

int g_orion150;

//----- (001E0638) --------------------------------------------------------
/* cmp byte 1E0621, 1 / jz sub_5DF0A / retn: the caller runs sub_5DF0A only when this returns 1 */
int Hook150_1E0638(void)
{
  return ecode[0x1E0621 - 0x1E0000] == 1;
}
