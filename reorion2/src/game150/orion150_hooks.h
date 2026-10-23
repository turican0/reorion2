/* Wave 185: the hooks of the 1.50 patch inside the 1.31 game functions. ORION150.EXE replaces calls and
   instructions of the game code (hooks.tsv, funcdiff.tsv); the port calls these functions at those sites
   while g_orion150 is set (REORION2_150=1), otherwise the game runs as 1.31.
   GOAL: a first step only - rewrite them as plain game code later (see tools/compare/gen150.py). */
#ifndef ORION150_HOOKS_H
#define ORION150_HOOKS_H

#ifdef __cplusplus
extern "C" {
#endif

extern int g_orion150;

/* 1009B main__0: call sub_107E6 -> sub_1E0824 (/monsters= default from the config, sub_1E6B83 after) */
char Hook150_MonstersSetting(void);
int sub_1E6B83(int a1);
/* 10125 main__0: call sub_1205E6 -> sub_1E2BDA (byte 23F9E3: the exit restores the video mode) */
void Hook150_VideoReady(void);
/* every former call of sub_126487 -> sub_16957E (1E2BA8, 1FEA6F): normal = the four ends of a normal run */
void Hook150_Exit(char *msg, int normal);
/* address in the 1.50 block data (0x22A600..) */
uint8_t *Hook150_Eseg(uint32_t addr);
/* text of the draw calls: NULL / "" -> "", one letter -> lower case (sub_1E02A2, 1E02CE, 1E028A, 1E02E6,
   1E02FE). No effect, so not wired: 1E0276 (sub_114C72) and 1E02BA (sub_1146FD) drop the result,
   1E0316 (sub_11C83D) rewrites stack argument 7, which the function never reads */
char *sub_1E6D6F(char *result);
unsigned int sub_11438B_131(int a1, int a2, int a3, int a4, uint8_t *a5, int a6);

/* The 1.31 bodies of the game functions 1.50 hooks at every call: the wrapper (same name, orion150_hooks.c)
   runs the hook, the block and the unhooked call sites call these */
int sub_12C2C6_131(int result);
char sub_6F11C_131(int a1);
int sub_E0B4F_131(int16_t *a1, int a2);
int sub_E0C1D_131(char *a1, int a2);
int sub_93D4B_131(int a1, int a2);
int16_t sub_E938C_131(int a1, int a2, int a3, int a4, uint8_t *a5, int a6);
int sub_6E1A0_131(int a1, int *a2);
char sub_34454_131(int a1, uint16_t *a2, uint16_t *a3);
int16_t sub_B1E19_131(int a1, int a2);
int sub_3E095_131(unsigned int a1, int a2, int a3, int a4);
char sub_11BE4_131(void);
/* 1318A sub_13174: call sub_5E1E3 -> sub_1E0622 (the tech table rebuilt with byte 1E0621 set) */
void sub_1E0622(void);
/* 5E3EE sub_5E1E3: call sub_5DF0A -> sub_1E0638 (RACESTUF.LBX only while byte 1E0621 is set) */
int Hook150_1E0638(void);

#ifdef __cplusplus
}
#endif

#endif
