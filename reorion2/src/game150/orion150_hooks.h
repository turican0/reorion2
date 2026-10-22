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

/* 1318A sub_13174: call sub_5E1E3 -> sub_1E0622 (the tech table rebuilt with byte 1E0621 set) */
void sub_1E0622(void);
/* 5E3EE sub_5E1E3: call sub_5DF0A -> sub_1E0638 (RACESTUF.LBX only while byte 1E0621 is set) */
int Hook150_1E0638(void);

#ifdef __cplusplus
}
#endif

#endif
