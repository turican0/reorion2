// port_rec.h - deterministic game record / replay (wave 183), see port_rec.cpp.
#ifndef PORT_REC_H
#define PORT_REC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    PORTREC_MOUSE = 0,   // ComputeVirtualMouse: x | y << 12 | buttons << 24
    PORTREC_KEY = 1,     // PortInput_PollKeyPress
    PORTREC_TICK = 2,    // PortDos_BiosTick
    PORTREC_MS = 3,      // AIL ms counter sub_149B10 / sub_149B30
    PORTREC_WAIT = 4,    // clock of PortVga_WaitSliced
    PORTREC_AUDIOQ = 5,  // SDL audio queue depth
    PORTREC_FTIME = 6,   // file date << 16 | time
    PORTREC_TIME = 7,    // time() of the game code (PortRec_Time)
};

void PortRec_Init(void);
uint32_t PortRec_Value(int src, uint32_t live);
int PortRec_Replaying(void);
int PortRec_FastReplay(void);
void PortRec_Tick(void);
void PortRec_Flush(void);
void PortRec_Sync(void);
void PortRec_OnFileWritten(const char* path);

#ifdef __cplusplus
}
#endif

#endif
