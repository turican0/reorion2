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
/* 1318A sub_13174: call sub_5E1E3 -> sub_1E0622 (the tech table rebuilt with byte 1E0621 set) */
void sub_1E0622(void);
/* 5E3EE sub_5E1E3: call sub_5DF0A -> sub_1E0638 (RACESTUF.LBX only while byte 1E0621 is set) */
int Hook150_1E0638(void);

#ifdef __cplusplus
}
#endif

#endif
