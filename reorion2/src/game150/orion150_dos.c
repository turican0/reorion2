/* Wave 185: DOS services the 1.50 block calls inline (int 21h). Kept apart from the game headers, whose
   macros redirect the C library. */
#include <stdint.h>
#include <time.h>

/* int 21h AH=2Ch GET CURRENT TIME: CH = hour, CL = minute, DH = second, DL = hundredths */
void Dos150_GetTime(uint16_t *cx, uint16_t *dx)
{
  time_t t = time(0);
  struct tm *lt = localtime(&t);
  int hs = (int)(clock() * 100 / CLOCKS_PER_SEC % 100);

  *cx = (uint16_t)((lt->tm_hour << 8) | lt->tm_min);
  *dx = (uint16_t)((lt->tm_sec << 8) | hs);
}
