/* Wave 185: hooks of the 1.50 patch the 1.31 game functions call (orion150_hooks.h). */
#include "orion150.h"
#include "orion150_hooks.h"

#define ESEG150(a) (eseg + (a) - 0x22A600)
#define EINT150(a) ((int)(intptr_t)ESEG150(a))

void Dos150_GetTime(uint16_t *cx, uint16_t *dx);
void PortDebug_Message(const char *msg);

int g_orion150;

//----- (001E0824) --------------------------------------------------------
/* mov al, byte 23DDD5 / mov byte_19A006, al before call sub_107E6 */
char Hook150_MonstersSetting(void)
{
  return *ESEG150(0x23DDD5);
}

//----- (001E2BDA) --------------------------------------------------------
/* call sub_1205E6 / mov byte 23F9E3, 1 (read by sub_1EB84B) */
void Hook150_VideoReady(void)
{
  *ESEG150(0x23F9E3) = 1;
}

//----- (001E2BA8) --------------------------------------------------------
/* 1E2BA8: edx = 1 for the return addresses 86BAE, 103DF, 108C9, 109FE, then 1FEA6F: an internal error
   (dl = 0) ends through sub_1ECCDF; a normal end logs "exiting normally, bye!", releases the config,
   closes ORION2.LOG and exits with the message (sub_1EB84B) */
void Hook150_Exit(char *msg, int normal)
{
  uint16_t cx, dx;

  PortDebug_Message(msg);
  if ( !normal )
    sub_1ECCDF(0, 1, EINT150(0x246DB8), (int)(intptr_t)msg, 0);   /* "MOO2 internal error:\n%s" */
  Dos150_GetTime(&cx, &dx);
  sub_1EC907(0, EINT150(0x251F8D), cx >> 8, cx & 0xFF, dx >> 8, dx & 0xFF);
  sub_1FB983(0, 0, 0, 0, 0);
  if ( !*ESEG150(0x2407BE) )
    sub_1E5643();
  sub_1EB84B((int64_t)(uint32_t)(uintptr_t)msg << 32, (int64_t)0, 0, 0, 0, (char *)0);
}

//----- (001E0638) --------------------------------------------------------
/* cmp byte 1E0621, 1 / jz sub_5DF0A / retn: the caller runs sub_5DF0A only when this returns 1 */
int Hook150_1E0638(void)
{
  return ecode[0x1E0621 - 0x1E0000] == 1;
}
