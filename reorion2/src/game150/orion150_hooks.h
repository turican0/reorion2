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
/* a byte of the game code 1.50 rewrites at run time (an immediate operand): from the ccode image,
   the 1.31 value without the patch */
int Hook150_CodeByte(uint32_t addr, int value131);
/* 1E33D1: word_19990E = sub_74F51(word_192248[word_1999D8]), word_199960 = -1 (after sub_82DFF) */
void Hook150_1E33D1(void);
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
int16_t sub_56BFA_131(int a1);
int sub_E401D_131(int a1, int a2, int a3);
int8_t sub_E0C9B_131(int a1, int a2);
_BOOL1 sub_FED77_131(char *a1, int a2, int a3);
int16_t sub_56A78_131(int a1);
void sub_13FD9_131(int a1, unsigned int a2);
void sub_E7CDB_131(int16_t *a1, int a2, uint16_t *a3, uint16_t *a4);
void sub_B230D_131(int a1, int a2);
void sub_74502_131(void);
int sub_63E4C_131(void);
int sub_112399_131(int a1);
int sub_DFDC6_131(int a1, int a2, int a3);
int sub_DEC95_131(int a1, int a2, int a3);
int sub_2C129_131(int a1, int a2);
int sub_CD435_131(int16_t *a1);
uint32_t *sub_126F3B_131(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6, int a7);
uint32_t *sub_12816C_131(int a1, int a2, int a3, int *a4);
uint32_t *sub_126CEB_131(int a1, int a2, int a3, int a4);
int sub_127233_131(int a1, int a2, int a3, int a4);
int sub_13AD33_131(int16_t *a1, int a2);
void sub_98282_131(int a1, int a2, int a3);
int sub_980DB_131(int a1, int a2, uint16_t *a3);
int16_t sub_82DFF_131(int16_t *a1, int16_t *a2, int a3);
void sub_FC470_131(int a1, int a2, int a3, int a4);
int sub_47939_131(int a1, int a2, int a3, int a4, int a29, int a30, int a31);
_BOOL1 sub_132646_131(int a1, int a2, int a3);
int16_t sub_8E280_131(int a1);
char sub_C4343_131(int16_t *a1, int16_t *a2, int a3);
void sub_ED8BF_131(int a1);
void sub_ECBF7_131(int a1, int a2);
void sub_EAAA1_131(int a1, int a2, int a3);
void sub_E9927_131(uint8_t *a1);
void sub_E4B5F_131(int a1, int a2);
void sub_C2E4D_131(void);
char sub_BA5DA_131(int a1, int a2, int a3);
int sub_B094C_131(void);
void sub_8BC39_131(int a1);
void sub_85FF2_131(int a1);
void sub_7B631_131(void);
char sub_79AE8_131(int a1);
int sub_7585D_131(int a1);
void sub_755D2_131(void);
void sub_745A5_131(int a1, int a2);
void sub_5D953_131(void);
void sub_459E7_131(int a1, int a2);
void sub_44EA4_131(int a1);
int sub_3E7A9_131(int a1, uint16_t *a2);
int sub_35C3A_131(int result);
int sub_35821_131(int a1, int a2, int a3, int a4);
void sub_10DC12_131(int a1, int a2, int a3, int16_t *a4);
char sub_1088A0_131(int a1, int a2, unsigned int a3);
/* 1318A sub_13174: call sub_5E1E3 -> sub_1E0622 (the tech table rebuilt with byte 1E0621 set) */
void sub_1E0622(void);
/* 5E3EE sub_5E1E3: call sub_5DF0A -> sub_1E0638 (RACESTUF.LBX only while byte 1E0621 is set) */
int Hook150_1E0638(void);

#ifdef __cplusplus
}
#endif

#endif
