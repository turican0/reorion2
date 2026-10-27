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
int sub_3CD21_131(unsigned int a1, int a2, int a3);
void sub_A432F_131(int a1, int a2, int a3, uint16_t *a4, uint16_t *a5, uint16_t *a6, uint16_t *a7, int a8);
int sub_5C510_131(int base, int16_t *a1);
void sub_12479_131(int a1, int a2, int a3, int a4, int a5, int a6);
int sub_D108B_131(int a1, int a2, int a3);
int16_t sub_92E72_131(void);
int sub_5AEF4_131(void);
void sub_B2542_131(int16_t *a1, int16_t *a2, int a3);
void sub_97A66_131(int a1);
int16_t sub_82809_131(int a1, char *a2);
void sub_E36DF_131(char *a1, int a2);
char *sub_E3616_131(char *result);
_BOOL1 sub_EB9C8_131(int a1, int a2, int a3);
/* Hooks that read the caller's frame or registers: called at the one call site with those values */
char Hook150_1E37E4(char r, int16_t *a1, int a2, uint8_t *a3);
int Hook150_1E40BC(int var14);
int Hook150_1E3F2E(int a1, int a2, int a3, int a4, int a5, int w);
void Hook150_1E24A8(void);
void Hook150_1E0DF8(uint8_t b);
int Hook150_1E3259(int r, int esi);
int Hook150_1E011D(int *var56);
void Hook150_1E0CD0(int cx);
int Hook150_1E4308(int16_t v66, int si);
int Hook150_1E2AE8(int a1, char *ecx);
/* call->call hooks at single call sites (the hooked call names the hook, marker "1.50 <site>") */
int16_t Hook150_1E1ED8(void);
int Hook150_1E1ECB(int handle);
char Hook150_1E0793(int a1, int a2, int a3, int a4, int a5, int a6);
int Hook150_1E25C8(int a1, int a2, int a3);
int Hook150_1E25B8(int a1, int a2, int a3);
int Hook150_1E0C0C(int a1, int a2, int a3);
int Hook150_1E0C69(int a1, int a2);
int Hook150_1E3E95(void);
int Hook150_1E19E2(int a1);
_BOOL1 Hook150_1E22FC(int a1, int a2);
int Hook150_1E17BD(int a1, int a2);
int Hook150_1E17C7(int a1, int a2);
int Hook150_1E0249(int a1, int a2, int a3, int a4);
_BOOL1 Hook150_1E1A7F(int a1);
void Hook150_1E16F3(int owner);
int Hook150_1E17F0(int16_t *a1, int16_t *a2);
int Hook150_1E1C4F(int done);
int Hook150_1E1C33(int rec);
int Hook150_1E1C76(int rec);
int Hook150_1E1CB2(void);
int Hook150_1E079A(int a1, int a2);
unsigned int Hook150_1E0238(uint8_t *a1, int a2);
int16_t Hook150_1E3D80(int a1);
void Hook150_1E1971(int a1, unsigned int a2, int a3);
int Hook150_1E1526(int a1, int a2, int a3, int a4);
int16_t Hook150_1E10F7(int a1, int a2, int a3);
unsigned int Hook150_1E10BF(uint8_t *a1, unsigned int a2);
int Hook150_1E01B0(int a1, int a2);
int Hook150_1E3488(int a1, int a2, int a3);
int Hook150_1E395F(uint8_t *a1, int a2, int a3);
int Hook150_1E373F(void);
unsigned int Hook150_1E41B8(unsigned int a1);
int Hook150_1EE553(int a1, int a2, int a3);
int Hook150_1E6F7F(int a1, int a2);
void Hook150_1E04DF(void);
int Hook150_1E38B2(int a1, unsigned int a2, int a3, int16_t *a4, int a5);
int Hook150_1E31F3(int a1);
int Hook150_1E30F6(void);
int Hook150_1E3103(int a1, int a2, int a3, int a4);
uint8_t *Hook150_Ecode(uint32_t addr);
void Hook150_1E0380(void);
int Hook150_1E12FB(int a1, int a2, int a3, int16_t *a4);
char Hook150_1E19B1(int a1, int a2, int ebx);
int Hook150_1E0A60(int value, int var5A);
int Hook150_1E0ADF(int a1);
int Hook150_1E0B25(int var5A);
int Hook150_1E1DF9(int a1, unsigned int a2, int di, int16_t *var1C);
_BOOL1 Hook150_1E1B8A(int a1);
int Hook150_1E2DF1(int a1, int a3);
int16_t Hook150_1FB7E3(int a1, int a2);
void Hook150_1E21E5(int a4);
int Hook150_1E1A24(int a1, int a2, int a3, int16_t *a4, int di);
int Hook150_1E1788(int a1, int a2, int a3, int16_t *a4, uint8_t *var4A);
_BOOL1 Hook150_1E1AAF(int a1, int di);
int Hook150_1E512C(int ebx);
void Hook150_1E1FF4(int a1, int a2, int a3, int *var);
void Hook150_1E20C4(int a1, int a2, int a3, int16_t *v16);
_BOOL1 Hook150_1E1B65(int a1);
int Hook150_1E4941(int a1, unsigned int a2);
int Hook150_1E495D(int a1, unsigned int a2);
void Hook150_1E1B41(int si, int ebx);
int Hook150_1E07A4(void);
int Hook150_1E0C29(int a1, int a2, int a3, int v20);
void Hook150_1E4971(int ebx);
int Hook150_1E4988(int a1, unsigned int a2);
int Hook150_1E0E59(int a1, unsigned int a2, int player, uint32_t flag);
int Hook150_1E1307(char *name, char *mode);
int Hook150_1E0A09(int a2);
int Hook150_1E415C(int a1, int a2);
int Hook150_1E4178(int a1, int a2);
char *Hook150_1E17D1(int a1, int a2, int a3, _WORD *a4, _BYTE *a5, int a6);
void Hook150_1E096A(int v23);
void Hook150_1E3719(int16_t *v65);
_BOOL1 Hook150_1E4D9E(void);
int Hook150_1E4B3B(int a1, int a2, int a3, int v78);
int Hook150_1E3A6B(int a2, uint16_t *a3);
int Hook150_1E3906(int a1, unsigned int a2, int a3, int16_t *a4, int a5, int ecx, int arg);
_BOOL1 Hook150_1E41EE(int a1, int a2);
char Hook150_1E4544(int a1);
_BOOL1 Hook150_1E507C(int a1);
int Hook150_1E3DB6(int a1, int a2);
unsigned int Hook150_1E4CFD(unsigned int a1, int v89);
int Hook150_1E4D69(int a1, int di);
uint8_t *Hook150_1E0F84(uint8_t *a1, uint8_t *a2, unsigned int a3, int v20);
int Hook150_1E4AB0(int a1, int a2, int si);
int Hook150_1E25A0(int a1);
int Hook150_1E05D8(int a, int x, int v8);
void Hook150_1E1019(void);
char Hook150_1E1EFC(void);
uint8_t *Hook150_1E10DC(uint8_t *a1, uint8_t *a2, unsigned int a3);
int Hook150_1E4561(int a1, int a2, int a3);
int16_t Hook150_1E23CA(int a1, int a2);
int16_t Hook150_1E23B5(int a1);
int Hook150_1E4346(int a1);
int Hook150_1E490B(int a1);
int Hook150_1E48F4(int a1);
struct PoolMemType;
struct PoolMemType *Hook150_1E0819(struct PoolMemType *a1, int a2);
int Hook150_1E1386(int a1, int a2, int a3, unsigned int a4);
int Hook150_1E04EA(void);
uint32_t *Hook150_1E1F26(int a1);
uint32_t *Hook150_1E1F37(int a1);
int Hook150_1E4C28(int a1, int a2, int a3, uint16_t *a4, int a5, uint8_t *a6, int a7);
int16_t Hook150_1E700F(void);
int Hook150_Mul8(int value, int mult, uint32_t addr);
int Hook150_1E18EF(int value, int var10);
void Hook150_1E07E8(uint32_t *ptr);
void Hook150_1E0802(uint32_t *ptr);
void Hook150_1E4BBB(void);
void Hook150_1E2A20(int player, int b);
int Hook150_1E1345(int player);
uint8_t Hook150_Byte(uint32_t addr);
void Dbg150(const char *fmt, ...);
void Hook150_1E2FE7(int al);
void Hook150_1E3193(void *rec, int a2);
int Hook150_1E053C(void);
int Hook150_1E2F08(int off);
_BOOL2 sub_2AED2_131(int a1, int a2);
void Hook150_1E0E28(int a1, int a4, int16_t *a2);
void Hook150_1E0DC1(int a1);
void Hook150_1E034A(int rec2, int i, int add);
int Hook150_1E8F5F(int a1, int a2);
void Hook150_1E2DE7(const char *s);
void Hook150_1E91DB(int a1);
void Hook150_1F9EC7(int rec);
int Hook150_1E9557(int ship, int target, int weapon);
int Hook150_1E966B(int ship, int target, int weapon);
int Hook150_1E8397(int ship, int target, int range);
int Hook150_1E42BC(void);
int Hook150_1E9377(int a1, int a2);
int Hook150_1E89BF(int rec);
void Hook150_1EAE8B(int a1);
void Hook150_1E8587(int a1);
void Hook150_1E2150(int b35, int16_t *dir, int16_t *diff);
void Hook150_1EA783(void);
void Hook150_1E4282(int ax);
int Hook150_1E300F(int off);
void Hook150_1E2A62(int value, int tech);
/* 1318A sub_13174: call sub_5E1E3 -> sub_1E0622 (the tech table rebuilt with byte 1E0621 set) */
void sub_1E0622(void);
/* 5E3EE sub_5E1E3: call sub_5DF0A -> sub_1E0638 (RACESTUF.LBX only while byte 1E0621 is set) */
int Hook150_1E0638(void);

#ifdef __cplusplus
}
#endif

#endif
