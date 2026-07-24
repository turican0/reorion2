#include "orion_common.h"

// Data declarations

char byte_10010[] = { 'I' }; // weak
_UNKNOWN loc_1193F; // weak
_UNKNOWN loc_12C00; // weak
char byte_13A3A[] = { '\x03' }; // weak
int16_t word_14A88 = 0; // weak
char byte_14A8A[] = { '\0' }; // weak
int16_t word_14A9A = 0; // weak
char byte_14A9C[] = { '\0' }; // weak
_UNKNOWN loc_14C05; // weak
// loc_16085 ODSTRANENO (vlna 10): nebyl to symbol, ale IDA false-positive
// z konstanty 90250 (0x1608A = "&loc_16085 + 5") - viz orion_part_01.c.
_UNKNOWN loc_186A0; // weak
_UNKNOWN loc_1D4BC; // weak
int16_t word_1DE96 = 1013; // weak
_UNKNOWN loc_20000; // weak
_UNKNOWN loc_2152F; // weak
_UNKNOWN loc_28800; // weak
_UNKNOWN loc_2D000; // weak
_UNKNOWN loc_30D40; // weak
int16_t word_3B83D = 0; // weak
int16_t word_3B83F = -12; // weak
int16_t word_3B841[] = { 8 }; // weak
int16_t word_3B843[] = { -6 }; // weak
int16_t word_3B845[] = { 15 }; // weak
int16_t word_3B847[] = { 0 }; // weak
int16_t word_3B849[] = { 8 }; // weak
int16_t word_3B84B[] = { 6 }; // weak
int16_t word_3B851[] = { -8 }; // weak
int16_t word_3B853[] = { 6 }; // weak
int16_t word_3B855[] = { -15 }; // weak
int16_t word_3B857[] = { 0 }; // weak
int16_t word_3B859[] = { -8 }; // weak
int16_t word_3B85B[] = { -6 }; // weak
int16_t word_3BA3D[] = { 12 }; // weak
int16_t word_3BA3F[] = { -12 }; // weak
int16_t word_3BA41[] = { 12 }; // weak
int16_t word_3BA43[] = { 12 }; // weak
int16_t word_3BA45[] = { -12 }; // weak
int16_t word_3BA47[] = { 12 }; // weak
int16_t word_3BA49[] = { -12 }; // weak
int16_t word_3BA4B[] = { -12 }; // weak
// loc_3E7FB/loc_40F0D ODSTRANENO (vlna 10): IDA false-positive z konstant
// 256000/266000 ("&loc_3E7FB + 5" / "&loc_40F0D + 3") - viz orion_part_01.c.
_UNKNOWN loc_61A80; // weak
//_UNKNOWN loc_63FFB; // weak
int dword_649E0[2] = { 167773440, 335548160 }; // weak
int dword_649F4[2] = { 167773440, 335548160 }; // weak
_UNKNOWN loc_70002; // weak
_UNKNOWN loc_7C830; // weak
_UNKNOWN loc_80000; // weak
int dword_80ACC[2] = { -707471917, -707406379 }; // weak
int dword_80AD4[2] = { -589636395, -589505316 }; // weak
int dword_80ADC[2] = { -640165420, -640034343 }; // weak
wchar_t asc_81BFC[3] = L"'!!"; // weak
int dword_81C04[15] = { 12, 10, 8, 2162727, 1572897, 1701736270, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // weak
wchar_t asc_81C68[3] = L"'!!"; // weak
int dword_81C78[2] = { 235670016, 370414096 }; // weak
int dword_81C88[4] = { 746093440, 2122555270, 235670016, 370414096 }; // weak
int dword_81C98[3] = { 12, 10, 8 }; // weak
wchar_t asc_81CA4[3] = L"'!!"; // weak
_UNKNOWN loc_81CAC; // weak
_UNKNOWN loc_81CB0; // weak
int dword_8BB3C[3] = { 286659602, 336535060, 85203233 }; // weak
wchar_t asc_8BB48[3] = L"'!!"; // weak
_UNKNOWN loc_925A6; // weak
_UNKNOWN loc_925AA; // weak
_UNKNOWN loc_9FFFD; // weak
int dword_A1C68[3] = { 524328, 1769498, 3080234 }; // weak
char byte_A659F = '\xB0'; // weak
int16_t word_A65BA = -13120; // weak
char byte_A65D5[3] = { 'P', 'W', 'W' }; // weak
int dword_A65F4[2] = { 131073, 196611 }; // weak
void (__noreturn *off_A6606)() = (void (__noreturn *)())&sub_10000; // weak (never called - see sub_10000 comment)
int16_t word_A6646 = 210; // weak
int16_t word_A6672 = 210; // weak
int16_t word_A669E = 210; // weak
int16_t word_A66CA = 210; // weak
int16_t word_A66F6 = 148; // weak
int16_t word_A6722 = 148; // weak
int16_t word_A674E = 89; // weak
int16_t word_A677A = 89; // weak
int16_t word_A67A6 = 200; // weak
int16_t word_A67D2 = 200; // weak
int16_t word_A67FE = 94; // weak
int16_t word_A682A = 94; // weak
int16_t word_A6856 = 68; // weak
int16_t word_A6882 = 68; // weak
int16_t word_A68AE = 146; // weak
int16_t word_A68DA = 146; // weak
int16_t word_A6906 = 169; // weak
int16_t word_A6932 = 169; // weak
int16_t word_A695E = 107; // weak
int16_t word_A698A = 201; // weak
int16_t word_A69B6 = 210; // weak
int16_t word_A69E2 = 210; // weak
int16_t word_AB756 = 0; // weak
int dword_B4D48[4] = { 16777216, 50332160, 83887104, 117442048 }; // weak
char byte_B4D5B = '\x06'; // weak
int dword_B4DC4[9] =
{
  16908287,
  16843007,
  -65536,
  33554432,
  -16580609,
  -16776448,
  3,
  65536,
  16711935
}; // weak
_UNKNOWN unk_B4E01; // weak
int dword_B6CB0[2] = { 28180941, 24969620 }; // weak
int dword_B6CC4[3] = { 1, 0, 0 }; // weak
int dword_B6CD0[2] = { 1, 0 }; // weak
char byte_BA6FB = 'Q'; // weak
int16_t word_BA71A = 21073; // weak
int dword_BA71C[24] =
{
  1448432723,
  1515804759,
  1583176795,
  1650548831,
  1717920867,
  1785292903,
  1852664939,
  1397903727,
  1465275732,
  1532647768,
  1600019804,
  1667391840,
  1734763876,
  1802135912,
  1869507948,
  201982219,
  370410005,
  503516447,
  404824087,
  69799466,
  741024296,
  874057523,
  839197493,
  3616054
}; // weak
int dword_BA784[18] =
{
  67437829,
  50660612,
  67372291,
  84017669,
  67306244,
  83951877,
  67240452,
  328451,
  17040640,
  50463745,
  262659,
  16974848,
  33686273,
  50331651,
  33620226,
  33554434,
  65793,
  256
}; // weak
int dword_BA7CC[36] =
{
  67437829,
  50660612,
  67372291,
  84017669,
  67306244,
  83951877,
  67240452,
  328451,
  17040640,
  50463745,
  262659,
  16974848,
  33686273,
  50331651,
  33620226,
  33554434,
  65793,
  256,
  -993606464,
  -1179142720,
  1599124919,
  97,
  251658240,
  17,
  1364197376,
  1431589714,
  1498961750,
  1566333786,
  1633705822,
  1701077858,
  1768449894,
  1835821930,
  1364422510,
  80238422,
  -1047986176,
  -768485751
}; // weak
_UNKNOWN loc_BCD8B; // weak
_UNKNOWN loc_BFFF4; // weak
int dword_C2220[4] = { 1459771138, 1459771138, 1459771138, 1459771138 }; // weak
int dword_C2234[7] =
{
  1610629376,
  -1627357184,
  -587153920,
  453049088,
  -402572799,
  -353637655,
  -1179142679
}; // weak
int16_t word_C5102 = -1; // weak
int dword_C6E40[3] = { 41633, -1600192512, 41633 }; // weak
char byte_CF38F[] = { '\x01' }; // weak
char byte_D575C[] = { '\x02' }; // weak
char byte_DD4B5[] = { '\x01' }; // weak
int16_t word_DD4BA = 6450; // weak
char byte_DD4C4[] = { '\xFC' }; // weak
char byte_DD4CC[] = { '\xF6' }; // weak
char byte_DD4CF[] = { '\x04' }; // weak
char byte_DD4D7[] = { '\xF6' }; // weak
char byte_DD4DC[] = { '\x05' }; // weak
char byte_DD4E1[3] = { '\x02', '\x04', '\x06' }; // weak
char byte_DD4E6[] = { '\0' }; // weak
char byte_DD4EB[] = { '\x19' }; // weak
char byte_DD4F5[3] = { '\x1E', '<', '\x1E' }; // weak
_UNKNOWN loc_E0002; // weak
_UNKNOWN loc_E1000; // weak
int16_t word_EA27A = 8739; // weak
_UNKNOWN loc_EB4BD; // weak
_UNKNOWN loc_EB4BF; // weak
int16_t word_EB4C3[] = { 118 }; // weak
int16_t word_EB4C5[] = { 464 }; // weak
int16_t word_EB4C7[] = { 242 }; // weak
_UNKNOWN locret_ED903; // weak
_UNKNOWN *off_EDB2D = &loc_93D66; // weak
// loc_F4240 ODSTRANENO (vlna 12): IDA false-positive z konstanty 1000000
// (0xF4240 - AIL mikrosekundy), viz orion_part_18.c/orion_part_23.c.
int dword_F594C[16] =
{
  1111704676,
  1044332609,
  976960573,
  909588537,
  842216501,
  774844465,
  707472429,
  606414375,
  539042339,
  454827295,
  387455258,
  320083222,
  252711186,
  185339150,
  117967114,
  50595078
}; // weak
_UNKNOWN loc_FFFF8; // weak
_UNKNOWN loc_100000; // weak
char byte_100A36[] = { '\0' }; // weak
_UNKNOWN loc_103428; // weak
char byte_10357B = '\x03';// weak
// extern _UNKNOWN _GETDS; weak
/* strstr: FLIRT rozpoznal jako staticky linkovanou CRT funkci, Hex-Rays ji ale nedekompiloval jako kod - pouziva se realna deklarace z <string.h> misto vlastni extern deklarace. */
 // weak
// dword_1276EC removed: was only a pusha/popa register-stash artifact inside
// sub_1276F0, which now returns its bit directly (see orion_part_19.c).
_UNKNOWN loc_1310FD; // weak
_UNKNOWN loc_1381E8; // weak
_UNKNOWN loc_13829B; // weak
_UNKNOWN loc_138350; // weak
char byte_138385[] = { '\0' }; // weak
int16_t word_138405[] = { 0 }; // weak
int dword_138CAC = 0; // weak
char byte_138F31[3] = { 'M', 'O', 'O' }; // weak
int dword_155104 = 1397753374; // weak
int16_t word_15510B = -26215; // weak
int16_t word_15511A = -26215; // weak
int dword_155120 = -1717986919; // weak
int16_t word_155136 = -26215; // weak
int16_t word_155140 = -26215; // weak
int16_t word_155147 = -26215; // weak
int dword_15B614[] = { 8 }; // weak
_UNKNOWN *off_15C810 = (_UNKNOWN *)0x46CB8; // weak
_UNKNOWN *off_15EEFC = &loc_E40C7; // weak
int (*off_1602F8[2])() = { &sub_1606F8, &sub_160709 }; // weak
int (*funcs_16213C[4])() = { &sub_161336, &sub_161357, &sub_16137B, &sub_1613A7 }; // weak
_UNKNOWN loc_164A90; // weak
_UNKNOWN loc_164DF0; // weak
_UNKNOWN loc_165600; // weak
_UNKNOWN loc_166540; // weak
_UNKNOWN loc_166880; // weak
_UNKNOWN loc_167084; // weak
_UNKNOWN loc_1671E0; // weak
char byte_168130 = '\0'; // weak
char byte_168131[3] = { '\0', '\0', '\0' }; // weak
_UNKNOWN loc_16845A; // weak
int dword_16853C = 0; // weak
char byte_168540 = '\0'; // weak
int dword_168694[603] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
}; // weak
char aMoxSet[8] = "MOX.SET"; // weak
char aSaveset[10] = "/saveset="; // weak
char aSaveset_0[9] = "/saveset"; // weak
char aSetTmp[8] = "set.tmp"; // weak
char aMaps[7] = "/maps="; // weak
char aSeed[7] = "/seed="; // weak
char aNolog[7] = "/nolog"; // weak
char aNet[6] = "/net="; // weak
char aQuickstart[12] = "/quickstart"; // weak
char aSkipintro[11] = "/skipintro"; // weak
char aMonsters[11] = "/monsters="; // weak
char aDate[6] = "/date"; // weak
char aMay222006_1[12] = "May 22 2006"; // weak
char aOrioncdIni[12] = "orioncd.ini"; // weak
char asc_17837F[2] = "\\"; // weak
char aDiplomatLbx[13] = "diplomat.lbx"; // weak
char aCannotLocateAl[48] = "Cannot locate all game files.  Please insert CD"; // weak
char aNowh[6] = "/nowh"; // weak
char byte_1783D3 = '\0'; // weak
char aNobh[6] = "/nobh"; // weak
char byte_1783DA = '\0'; // weak
char aNichtAlleSpiel[77] = "Nicht alle Spieldateien auffindbar. Bitte CD einlegen oder neu installieren."; // weak
char aVeuillezIns[] = "Veuillez ins"; // idb
_BYTE byte_178440[10] = { 47, 109, 105, 110, 115, 116, 97, 114, 116, 0 }; // weak
char byte_17844A = '\0'; // weak
char aGoodstart[11] = "/goodstart"; // weak
char byte_178456 = '\0'; // weak
char aNosplint[10] = "/nosplint"; // weak
char byte_178461 = '\0'; // weak
_BYTE byte_178463[11] = { 47, 104, 117, 103, 101, 115, 116, 97, 114, 116, 0 }; // weak
char byte_17846E = '\0'; // weak
char aRichstart[11] = "/richstart"; // weak
char byte_17847A = '\0'; // weak
char aPlanets[10] = "/planets="; // weak
char aNoSePuedeLocal[78] = "No se puede localizar todos los ficheros del juego.  Por favor mete el CD-ROM"; // weak
char aNoorion[9] = "/noorion"; // weak
_UNKNOWN unk_1784DD; // weak
char aNonRiescoATrov[34] = "Non riesco a trovare qualche file"; // weak
char aPicks[8] = "/picks="; // weak
char aOrioncdIniNotF[51] = "ORIONCD.INI not found. Please Re-Install Orion ][."; // weak
char aOrioncdIniNich[61] = "ORIONCD.INI nicht gefunden. Bitte Orion II neu installieren."; // weak
char aOrioncdIniIntr[] = "ORIONCD.INI introuvable. Veuillez r"; // idb
char aOrioncdIniNoSe[61] = "ORIONCD.INI no se ha encontrado. Vuelve a instalar Orion ][."; // weak
char aNonTrovoIlFile[62] = "Non trovo il file ORIONCD.INI. Bisogna reinstallare Orion II."; // weak
char aGam[5] = ".GAM"; // weak
char aRb[3] = "rb"; // weak
char aFileReadError[16] = "File read error"; // weak
char aSaveDGamIstUng[] = "SAVE%d.GAM ist ung"; // idb
char aWb[3] = "wb"; // weak
char aMoxSet_0[8] = "MOX.SET"; // weak
char aSettingsFileMo[46] = "Settings file (MOX.SET) is missing or invalid"; // weak
char aWb_0[3] = "wb"; // weak
char aMoxSet_1[8] = "mox.set"; // weak
char aUnableToOpenMo[23] = "Unable to open mox.set"; // weak
char aRacestufLbx[13] = "RACESTUF.LBX"; // weak
char aRacenameLbx[13] = "RACENAME.LBX"; // weak
char aBuffer0Lbx[12] = "BUFFER0.LBX"; // weak
char aGstarLbx[10] = "gstar.lbx"; // weak
char aRacestufLbx_0[13] = "RACESTUF.lbx"; // weak
_UNKNOWN unk_178A08; // weak
char aAntaroomLbx[13] = "antaroom.LBX"; // weak
char aAntarmsgLbx[13] = "antarmsg.LBX"; // weak
char byte_178A24 = '\0'; // weak
char aCouncilLbx[12] = "council.LBX"; // weak
char aCouncilLbx_0[12] = "council.lbx"; // weak
char aJimtextLbx[12] = "jimtext.lbx"; // weak
char aCouncmsgLbx[13] = "councmsg.lbx"; // weak
char byte_178A64 = '\0'; // weak
char aJimtext2Lbx[13] = "jimtext2.lbx"; // weak
char aDiplomatLbx_0[13] = "DIPLOMAT.LBX"; // weak
char aJimtextLbx_0[12] = "jimtext.lbx"; // weak
char aDipstarsLbx[13] = "dipstars.lbx"; // weak
char aDiplomseLbx[13] = "DIPLOMSE.LBX"; // weak
char aDiplomsgLbx[13] = "DIPLOMSG.LBX"; // weak
char aDiplomsfLbx[13] = "DIPLOMSF.LBX"; // weak
char aDiplomssLbx[13] = "DIPLOMSS.LBX"; // weak
char aDiplomsiLbx[13] = "DIPLOMSI.LBX"; // weak
char aDiplomspLbx[13] = "DIPLOMSP.LBX"; // weak
char aFwee[6] = "FWEE!"; // weak
char aAn[3] = "an"; // weak
wchar_t aAcg[4] = L"aCG\x1B"; // weak
char aEventsLbx[11] = "EVENTS.LBX"; // weak
_UNKNOWN unk_178B33; // weak
char aJimtextLbx_1[12] = "jimtext.lbx"; // weak
char aEventmsgLbx[13] = "EVENTMSG.LBX"; // weak
char aEventmsfLbx[13] = "EVENTMSF.LBX"; // weak
char aEventmssLbx[13] = "EVENTMSS.LBX"; // weak
char aEventmsiLbx[13] = "EVENTMSI.LBX"; // weak
char aEventmspLbx[13] = "EVENTMSP.LBX"; // weak
char aS_24[2] = "s"; // weak
char aJimtext2Lbx_0[13] = "jimtext2.lbx"; // weak
char asc_178B9D[2] = "\n"; // weak
char byte_178B9F[3] = { '\x1A', '0', '\0' }; // weak
_UNKNOWN unk_178BB0; // weak
char aStreamhdLbx[13] = "STREAMHD.LBX"; // weak
char aStreamLbx[11] = "STREAM.LBX"; // weak
char aLogoLbx[9] = "logo.LBX"; // weak
char aSimtexLbx[11] = "simtex.lbx"; // weak
char aIntroLbx[10] = "intro.lbx"; // weak
char aCombatLbx_0[11] = "combat.lbx"; // weak
char asc_178C4F[3] = "  "; // weak
char asc_178C52[2] = " "; // weak
char asc_178C54[3] = " x"; // weak
char asc_178C57[3] = " ("; // weak
char a360[4] = "360"; // weak
char asc_178C5E[2] = ")"; // weak
_UNKNOWN unk_178C80; // weak
_UNKNOWN unk_178C83; // weak
char aCombatLbx[11] = "Combat.lbx"; // weak
char aFlticonsLbx[13] = "flticons.lbx"; // weak
_UNKNOWN unk_178CA0; // weak
int16_t word_178CA1 = 65; // weak
int16_t word_178CA3 = 68; // weak
int16_t word_178CA5 = 73; // weak
int16_t word_178CA7 = 83; // weak
int16_t word_178CA9 = 70; // weak
int16_t word_178CAB = 82; // weak
int16_t word_178CAD = 66; // weak
int16_t word_178CAF = 76; // weak
char aCmbtsfxLbx_2[12] = "cmbtsfx.lbx"; // weak
char aCmbtmislLbx_0[13] = "cmbtmisl.lbx"; // weak
char aCombatLbx_3[11] = "combat.LBX"; // weak
char asc_178CD5[2] = "\x1B"; // weak
char asc_178CD8[11] = "          "; // weak
char asc_178CE3[3] = "\n\n"; // weak
_UNKNOWN *off_178CE6 = &loc_A0020; // weak
_UNKNOWN unk_178CEA; // weak
_UNKNOWN unk_178CEC; // weak
char byte_178CED[10] = { '\x18', 'B', '6', '\a', 'X', '1', '7', '5', '.', '\0' }; // weak
char byte_178CF7[47] =
{
  '\x18',
  'B',
  '7',
  '\n',
  '\x1A',
  '1',
  '\x18',
  'B',
  '0',
  '\a',
  'X',
  '8',
  '0',
  '.',
  '\x1A',
  '1',
  '\x18',
  'B',
  '3',
  '\a',
  'X',
  '2',
  '5',
  '5',
  '.',
  '\x1A',
  '0',
  '\n',
  '\x1A',
  '1',
  '\x18',
  'B',
  '1',
  '\a',
  'X',
  '8',
  '0',
  '.',
  '\x1A',
  '0',
  '\a',
  'X',
  '8',
  '2',
  '.',
  ' ',
  '\0'
}; // weak
char byte_178D26[21] =
{
  '\x1A',
  '1',
  '\x18',
  'B',
  '4',
  '\a',
  'X',
  '2',
  '5',
  '5',
  '.',
  '\x1A',
  '0',
  '\a',
  'X',
  '2',
  '5',
  '7',
  '.',
  ' ',
  '\0'
}; // weak
char aX48X223[] = "\n\aX48.-------\aX223.-------\n"; // idb
char aCmbtsfxLbx[12] = "cmbtsfx.lbx"; // weak
char aCombatLbx_1[11] = "combat.lbx"; // weak
char asc_178D8B[2] = " "; // weak
char aAntaran[8] = "Antaran"; // weak
char aAmoeba[7] = "Amoeba"; // weak
char aDragon[7] = "Dragon"; // weak
char aCrystal[8] = "Crystal"; // weak
char aAntares[8] = "Antares"; // weak
char aX35[6] = "\aX35."; // weak
char aX255[7] = "\aX255."; // weak
char asc_178DD6[2] = "\n"; // weak
char aX25[7] = "\aX+25."; // weak
char aX227[7] = "\aX227."; // weak
char aX21[7] = "\aX+21."; // weak
char aX18[6] = "\aX18."; // weak
char asc_178DF3[2] = "-"; // weak
char aX80[6] = "\aX80."; // weak
char aX120[7] = "\aX120."; // weak
char aX250[7] = "\aX250."; // weak
char aX312[7] = "\aX312."; // weak
char a1_0[2] = "1"; // weak
char asc_178E12[3] = "\n\n"; // weak
char byte_178E15[3] = { '\x1A', '2', '\0' }; // weak
_UNKNOWN unk_178E18; // weak
_BYTE byte_178E19[2] = { 91, 0 }; // weak
_BYTE byte_178E1B[2] = { 97, 0 }; // weak
_BYTE byte_178E1D[2] = { 115, 0 }; // weak
_BYTE byte_178E1F[2] = { 98, 0 }; // weak
_BYTE byte_178E21[2] = { 114, 0 }; // weak
_BYTE byte_178E23[2] = { 119, 0 }; // weak
_BYTE byte_178E25[2] = { 100, 0 }; // weak
_BYTE byte_178E27[2] = { 116, 0 }; // weak
_BYTE byte_178E29[2] = { 122, 0 }; // weak
_UNKNOWN *off_178E2B = &unk_1B004F; // weak
_BYTE byte_178E2F[5] = { 99, 0, 0, 0, 0 }; // weak
char aCombatLbx_2[11] = "combat.lbx"; // weak
char aCmbtmislLbx[13] = "cmbtmisl.lbx"; // weak
char aCmbtsfxLbx_1[12] = "cmbtsfx.lbx"; // weak
char aSphersfxLbx_0[13] = "sphersfx.lbx"; // weak
char aCmbtfgtrLbx[13] = "cmbtfgtr.lbx"; // weak
char aAntares_0[8] = "Antares"; // weak
char aCmbtplntLbx[13] = "cmbtplnt.lbx"; // weak
char aShipsLbx[10] = "ships.lbx"; // weak
char aKentext1Lbx[13] = "KENTEXT1.LBX"; // weak
char aKentextLbx[12] = "KENTEXT.LBX"; // weak
char aRacestufLbx_2[13] = "racestuf.lbx"; // weak
char aRaceoptLbx_0[12] = "RACEOPT.LBX"; // weak
char aPatch13Lbx_0[12] = "patch13.lbx"; // weak
char byte_178F21 = '\0'; // weak
char asc_178F22[2] = "."; // weak
char asc_178F24[2] = "%"; // weak
char aWb_1[3] = "wb"; // weak
char aLastraceRac_0[13] = "lastrace.rac"; // weak
char asc_178F36[2] = "\x1B"; // weak
char aA[2] = "a"; // weak
char aC[2] = "c"; // weak
char aRacestufLbx_1[13] = "RACESTUF.LBX"; // weak
char aRb_0[3] = "rb"; // weak
char aLastraceRac[13] = "lastrace.rac"; // weak
char aRaceselLbx[12] = "RACESEL.LBX"; // weak
char aPatch13Lbx[12] = "patch13.lbx"; // weak
int dword_178F71 = 3288881; // weak
int16_t word_178F75 = 49; // weak
_UNKNOWN unk_178F79; // weak
char aRaceoptLbx[12] = "RACEOPT.LBX"; // weak
char asc_178F88[2] = "\x1B"; // weak
_UNKNOWN unk_178F8A; // weak
char aRaceselLbx_0[12] = "racesel.lbx"; // weak
char aRacenameLbx_0[13] = "RACENAME.LBX"; // weak
char asc_178FA4[9] = "        "; // weak
char aTechnameLbx[13] = "techname.lbx"; // weak
char aTechHasTooMany[24] = " tech has too many apps"; // weak
_UNKNOWN unk_178FD8; // weak
char asc_178FD9[2] = "\x1B"; // weak
char aDefensive_0[10] = "Defensive"; // weak
char aOffensive_0[10] = "Offensive"; // weak
char aCurrentDefShip[34] = ">> current def ships (by size) : "; // weak
char aCurrentOffShip[34] = ">> current off ships (by size) : "; // weak
char aOffShipsDeploy[34] = ">> off ships deployed (by size): "; // weak
char aShipsBySize[31] = "-< ships (by size)          : "; // weak
char aShipsDeployedB[31] = "-< ships deployed (by size) : "; // weak
char asc_1791A9[2] = "*"; // weak
char asc_1791AB[5] = "    "; // weak
_UNKNOWN unk_1791B0; // weak
char asc_1791B1[2] = "\x1B"; // weak
char asc_1791B3[2] = "-"; // weak
char asc_1791B5[2] = "+"; // weak
char aB[2] = "B"; // weak
char aM[2] = "M"; // weak
char aO[2] = "O"; // weak
char aS_0[2] = "S"; // weak
char aA_0[2] = "A"; // weak
char a0[2] = "0"; // weak
char asc_1791D2[2] = " "; // weak
char asc_1791D4[3] = "\n\n"; // weak
char aAn_0[3] = "an"; // weak
char aA_2[2] = "a"; // weak
int dword_1791DC = 3159603; // weak
char byte_1791EB = '\0'; // weak
wchar_t aLb[3] = L"\x1BLB"; // weak
int16_t word_1791FF = 48; // weak
char aShipnameLbx[13] = "shipname.lbx"; // weak
char aS_1[2] = "s"; // weak
char asc_179219[2] = "-"; // weak
char asc_17921B[2] = "+"; // weak
char aSpecial[8] = "special"; // weak
int dword_17925F = 3159603; // weak
char aGertecdLbx[12] = "GERTECD.LBX"; // weak
char aFretecdLbx[12] = "FRETECD.LBX"; // weak
char aSpatecdLbx[12] = "SPATECD.LBX"; // weak
char aItatecdLbx[12] = "ITATECD.LBX"; // weak
char asc_1792A4[2] = "\x1B"; // weak
_UNKNOWN unk_1792A6; // weak
char asc_1792A7[2] = "-"; // weak
char asc_1792A9[2] = "+"; // weak
char aBuffer0Lbx_0[12] = "BUFFER0.LBX"; // weak
char aS_32[2] = "S"; // weak
_UNKNOWN unk_1792C8; // weak
_UNKNOWN *off_1792C9 = &unk_1B0041; // weak
_BYTE byte_1792CD[2] = { 45, 0 }; // weak
_BYTE byte_1792CF[2] = { 43, 0 }; // weak
_BYTE byte_1792D1[2] = { 44, 0 }; // weak
_BYTE byte_1792D3[2] = { 46, 0 }; // weak
_BYTE byte_1792D5[2] = { 82, 0 }; // weak
_BYTE byte_1792D7[2] = { 76, 0 }; // weak
_BYTE byte_1792D9[2] = { 85, 0 }; // weak
_BYTE byte_1792DB[2] = { 67, 0 }; // weak
char byte_1792DD[3] = { '\x1A', '0', '\0' }; // weak
_UNKNOWN unk_1792E8; // weak
char aTooManyShipsIn[23] = "Too many ships in list"; // weak
char asc_17931F[2] = "+"; // weak
char aWarningLbx[12] = "warning.lbx"; // weak
char asc_179340[2] = "\x1B"; // weak
char aConfirmLbx[12] = "confirm.lbx"; // weak
char aY[2] = "Y"; // weak
char aN[2] = "N"; // weak
int16_t word_179354 = 32; // weak
_UNKNOWN unk_179356; // weak
char aRelateGameCond[53] = "relate game conditions EXACTLY as they just happened"; // weak
char aBuffer0Lbx_1[12] = "BUFFER0.LBX"; // weak
char aRt_0[3] = "rt"; // weak
char aSeed_0[5] = "seed"; // weak
char aOrion[6] = "Orion"; // weak
char aFontsgLbx[11] = "fontsg.lbx"; // weak
char aFontsfLbx[11] = "fontsf.lbx"; // weak
char aFontsiLbx[11] = "fontsi.lbx"; // weak
char aFontssLbx[11] = "fontss.lbx"; // weak
char aWt[3] = "wt"; // weak
char aHerodataLbx[13] = "HERODATA.LBX"; // weak
char aHerodatgLbx[13] = "HERODATG.LBX"; // weak
char aHerodatfLbx[13] = "HERODATF.LBX"; // weak
char aHerodatsLbx[13] = "HERODATS.LBX"; // weak
char aHerodatiLbx[13] = "HERODATI.LBX"; // weak
char aBc[3] = "BC"; // weak
char aMc[3] = "MC"; // weak
char aStarnameLbx[13] = "starname.lbx"; // weak
char asc_17957D[2] = "."; // weak
char aRaceoptLbx_1[12] = "raceopt.lbx"; // weak
char asc_179595[2] = "L"; // weak
_UNKNOWN unk_179597; // weak
wchar_t aNsqoA[6] = L"NSQO\x1B""A"; // weak
char aInvalid[12] = "* INVALID *"; // weak
char aD_0[2] = "D"; // weak
char aC_0[2] = "C"; // weak
char aGam_0[5] = ".GAM"; // weak
char aAltF1[9] = "(ALT_F1)"; // weak
char aAltF2[9] = "(ALT_F2)"; // weak
char aAltF3[9] = "(ALT_F3)"; // weak
char aAltF5[9] = "(ALT_F5)"; // weak
char aAltF6[9] = "(ALT_F6)"; // weak
char aAltF7[9] = "(ALT_F7)"; // weak
char aAltF8[9] = "(ALT_F8)"; // weak
char aAltF1_0[9] = "(ALT-F1)"; // weak
char aAltF2_0[9] = "(ALT-F2)"; // weak
char aAltF3_0[9] = "(ALT-F3)"; // weak
char aAltF4[9] = "(ALT-F4)"; // weak
char aAltF5_0[9] = "(ALT-F5)"; // weak
char aAltF6_0[9] = "(ALT-F6)"; // weak
char aAltF7_0[9] = "(ALT-F7)"; // weak
char aAltF8_0[9] = "(ALT-F8)"; // weak
char aMainmenuLbx_0[13] = "MAINMENU.LBX"; // weak
char aC_1[2] = "C"; // weak
char aSaveGam[10] = "save?.gam"; // weak
wchar_t aLnmhq[6] = L"LNMHQ."; // weak
char aMainmenuLbx[13] = "MAINMENU.LBX"; // weak
char aS_4[2] = "S"; // weak
_UNKNOWN *off_1796B7 = &unk_1B0020; // weak
char aVer140b23[12] = "Ver 1.40b23"; // weak
char aGercrdtsLbx[13] = "GERCRDTS.LBX"; // weak
char aFrecrdtsLbx[13] = "FRECRDTS.LBX"; // weak
char aSpacrdtsLbx[13] = "SPACRDTS.LBX"; // weak
char aItacrdtsLbx[13] = "ITACRDTS.LBX"; // weak
char aBuffer0Lbx_2[12] = "BUFFER0.LBX"; // weak
char asc_179714[2] = "+"; // weak
_UNKNOWN unk_179716; // weak
char asc_179717[2] = "-"; // weak
char aG[2] = "G"; // weak
char aT[2] = "T"; // weak
char aC_2[2] = "C"; // weak
char aP[2] = "P"; // weak
char asc_179721[2] = "F"; // weak
char asc_179723[2] = "L"; // weak
char aR_0[2] = "R"; // weak
char aI[2] = "I"; // weak
char aQ[2] = "Q"; // weak
char aA_1[2] = "A"; // weak
_UNKNOWN *off_17972D = &unk_1B0057; // weak
char aStarbgLbx[11] = "STARBG.LBX"; // weak
char asc_1797AD[2] = "@"; // weak
char aRp[3] = "RP"; // weak
char aFp[3] = "FP"; // weak
char aPr[3] = "PR"; // weak
char aPi[3] = "PI"; // weak
char asc_1797E0[2] = "\x1B"; // weak
_BYTE byte_1797E2[2] = { 0, 0 }; // weak
char aStarbgLbx_0[11] = "starbg.lbx"; // weak
char aW[2] = "w"; // weak
char aNdataLbx[10] = "NDATA.LBX"; // weak
char aStarnameLbx_0[13] = "starname.lbx"; // weak
char aRaceoptLbx_2[12] = "raceopt.lbx"; // weak
char asc_179906[71] = "                                                                      "; // weak
char aMapTestDone[14] = "map test done"; // weak
char aDat[5] = ".dat"; // weak
char aDisplayLbx[12] = "display.lbx"; // weak
_UNKNOWN unk_179A78; // weak
char aInboxLbx[10] = "inbox.lbx"; // weak
_UNKNOWN unk_179AC2; // weak
char aWwwwwww[8] = "WWWWWWW"; // weak
char aBuffer0Lbx_7[12] = "BUFFER0.LBX"; // weak
wchar_t aDph[3] = L"DPH"; // weak
_UNKNOWN unk_179AEA; // weak
char asc_179AEB[2] = "X"; // weak
char aS_10[2] = "S"; // weak
_UNKNOWN *off_179AEF = &unk_1B0043; // weak
_BYTE byte_179AF3[2] = { 45, 0 }; // weak
_BYTE byte_179AF5[2] = { 43, 0 }; // weak
_BYTE byte_179AF7[2] = { 46, 0 }; // weak
char asc_179B1B[2] = " "; // weak
char byte_179B1D[3] = { '\x1A', '0', '\0' }; // weak
char aSkildescLbx[13] = "SKILDESC.LBX"; // weak
char aGerskllsLbx[13] = "GERSKLLS.LBX"; // weak
char aFreskllsLbx[13] = "FRESKLLS.LBX"; // weak
char aSpaskllsLbx[13] = "SPASKLLS.LBX"; // weak
char aItaskllsLbx[13] = "ITASKLLS.LBX"; // weak
_UNKNOWN unk_179B78; // weak
char a1_2[2] = "1"; // weak
char a2_2[2] = "2"; // weak
char a3[2] = "3"; // weak
char a4[2] = "4"; // weak
char a5[2] = "5"; // weak
char aC_4[2] = "C"; // weak
char aO_0[2] = "O"; // weak
char asc_179B87[2] = "-"; // weak
_UNKNOWN *off_179B89 = &unk_1B002B; // weak
_UNKNOWN unk_179B8D; // weak
_UNKNOWN unk_179B90; // weak
_UNKNOWN unk_179B92; // weak
char aScoreLbx[10] = "SCORE.LBX"; // weak
char asc_179BAA[2] = "\x1B"; // weak
int16_t word_179BCB = 46; // weak
_UNKNOWN unk_179BCD; // weak
char aHofM2[7] = "HOF.M2"; // weak
char aWb_2[3] = "wb"; // weak
_UNKNOWN unk_179BDA; // weak
char aC_3[2] = "C"; // weak
_UNKNOWN unk_179BE0; // weak
char aBuffer0Lbx_3[12] = "BUFFER0.LBX"; // weak
char asc_179C1C[2] = "\x1B"; // weak
_UNKNOWN unk_179C1E; // weak
char aBuffer0Lbx_4[12] = "BUFFER0.LBX"; // weak
char asc_179C33[2] = ")"; // weak
char aM2530[] = "\aM25,30."; // idb
char byte_179C5A[3] = { '\x1A', '1', '\0' }; // weak
_UNKNOWN *off_179C5D = (_UNKNOWN *)0xA6425; // weak
char byte_179C61[9] = { '\x1A', '0', '%', 's', '\x1A', '1', '0', '\n', '\0' }; // weak
char byte_179C6A[10] = { '\x1A', '0', '%', 's', '\x1A', '1', '%', 'd', '\n', '\0' }; // weak
char aM2527[9] = "\aM25,27."; // weak
char byte_179C7D[10] = { '\x1A', '0', '%', 's', '\x1A', '1', '-', '-', '\n', '\0' }; // weak
char aM2517[9] = "\aM25,17."; // weak
char byte_179C90[5] = { '\x1A', '0', '%', 's', '\0' }; // weak
char byte_179C95[7] = { '\x1A', '0', '%', 's', '\x1A', '1', '\0' }; // weak
char asc_179CA2[3] = ", "; // weak
char aRemapDrawNotSu[31] = "Remap draw not support bitmaps"; // weak
char aRemapDrawNotSu_0[30] = "Remap draw not support screen"; // weak
char aRemapDrawNotSu_1[27] = "Remap draw not support map"; // weak
char aRemapDrawNotSu_2[31] = "Remap draw not support bitmaps"; // weak
char aRemapDrawNotSu_3[30] = "Remap draw not support screen"; // weak
char aTextboxLbx[12] = "textbox.lbx"; // weak
char asc_179D48[2] = "\x1B"; // weak
char aGerHelpLbx[13] = "GER_HELP.LBX"; // weak
char aFreHelpLbx[13] = "FRE_HELP.LBX"; // weak
char aItaHelpLbx[13] = "ITA_HELP.LBX"; // weak
char aSpaHelpLbx[13] = "SPA_HELP.LBX"; // weak
char asc_179D88[2] = " "; // weak
_UNKNOWN unk_179D8A; // weak
_UNKNOWN unk_179D8D; // weak
_UNKNOWN unk_179D90; // weak
_BYTE byte_179D92[2] = { 101, 0 }; // weak
_UNKNOWN unk_179DC3; // weak
_UNKNOWN unk_179DC6; // weak
char aGstarLbx_0[10] = "gstar.lbx"; // weak
char aBuffer0Lbx_5[12] = "BUFFER0.LBX"; // weak
char aWho[4] = "Who"; // weak
char aRefitpupLbx[13] = "refitpup.LBX"; // weak
char asc_179DFD[2] = ":"; // weak
_UNKNOWN unk_179E03; // weak
_BYTE byte_179E06[2] = { 112, 0 }; // weak
wchar_t aFs[3] = L"fs "; // weak
char a1[3] = "\x1B""1"; // weak
char a2[3] = "\x1B""2"; // weak
char a0_0[3] = "\x1B""0"; // weak
_UNKNOWN unk_179E17; // weak
char a2_0[3] = "\x1B""2"; // weak
char asc_179E1C[3] = ", "; // weak
char aBuffer0Lbx_6[12] = "BUFFER0.LBX"; // weak
_UNKNOWN unk_179E6B; // weak
_UNKNOWN unk_179E6E; // weak
char aPiccola[8] = "Piccola"; // weak
char aMedia[6] = "Media"; // weak
char aEstringsLbx[13] = "estrings.lbx"; // weak
char aEstrgermLbx[13] = "estrGERM.lbx"; // weak
char aEstrfrenLbx[13] = "estrFREN.lbx"; // weak
char aEstrspanLbx[13] = "estrSPAN.lbx"; // weak
char aEstritalLbx[13] = "estrITAL.lbx"; // weak
char aEstrpoliLbx[13] = "estrPOLI.lbx"; // weak
char aYouBlewTheArra[24] = "you blew the array eric"; // weak
char aMaingermLbx[13] = "maingerm.lbx"; // weak
char aMaintextLbx[13] = "maintext.lbx"; // weak
char aMainfrenLbx[13] = "mainfren.lbx"; // weak
char aMainspanLbx[13] = "mainspan.lbx"; // weak
char aMainitalLbx[13] = "mainital.lbx"; // weak
char aMainpoliLbx[13] = "mainpoli.lbx"; // weak
_UNKNOWN unk_179F40; // weak
_UNKNOWN unk_179F43; // weak
_BYTE byte_179F46[2] = { 0, 0 }; // weak
char aAiTradeGoods[15] = "AI trade goods"; // weak
_UNKNOWN unk_179F5F; // weak
char aT1565[11] = "\aT+15,+65."; // weak
char byte_179F6E[3] = { '\x1A', '0', '\0' }; // weak
char asc_179F93[2] = "\r"; // weak
char asc_179FF1[21] = "-------------------\n"; // weak
_UNKNOWN *off_17A034 = (_UNKNOWN *)0xA7325; // weak
char aMultigmLbx[12] = "MULTIGM.LBX"; // weak
_UNKNOWN unk_17A061; // weak
char aS_21[2] = "S"; // weak
_UNKNOWN *off_17A06B = &unk_1B0043; // weak
_BYTE byte_17A06F[2] = { 78, 0 }; // weak
_BYTE byte_17A071[2] = { 77, 0 }; // weak
_BYTE byte_17A073[2] = { 85, 0 }; // weak
_BYTE byte_17A075[2] = { 72, 0 }; // weak
_BYTE byte_17A077[2] = { 84, 0 }; // weak
_BYTE byte_17A079[2] = { 76, 0 }; // weak
_BYTE byte_17A07B[2] = { 74, 0 }; // weak
char aEvanAxelrad[13] = "Evan Axelrad"; // weak
int dword_17A0BB = 5919809; // weak
char aMay222006[12] = "May 22 2006"; // weak
char aFseekModemFile[17] = "fseek modem_file"; // weak
char aFreadModemFile[17] = "fread modem_file"; // weak
char aFseekAheadMode[23] = "fseek ahead modem_file"; // weak
char aPLimitPDiff[17] = "p_limit < p_diff"; // weak
char aModemTmp[10] = "modem.tmp"; // weak
char aWb_3[3] = "wb"; // weak
char aRb_1[3] = "rb"; // weak
char aErrorDecodingB[25] = "error decoding broadcast"; // weak
_UNKNOWN unk_17A174; // weak
char aMyname[7] = "myname"; // weak
char aMay222006_0[12] = "May 22 2006"; // weak
char aCraziness[10] = "craziness"; // weak
char aAntares_1[8] = "Antares"; // weak
char aThisIsnTASingl[48] = "This isn't a single player game, cheeky monkey!"; // weak
char aFirst[6] = "first"; // weak
char aInfoLbx[9] = "INFO.LBX"; // weak
char asc_17A289[2] = "\x1B"; // weak
_UNKNOWN unk_17A28B; // weak
char aBilltextLbx[13] = "billtext.lbx"; // weak
char aAppPicsLbx[13] = "app_pics.lbx"; // weak
char aAppPicsLbx_0[13] = "APP_PICS.LBX"; // weak
char aBilltex2Lbx[13] = "billtex2.lbx"; // weak
char asc_17A2D8[2] = "-"; // weak
char asc_17A2DA[2] = "+"; // weak
char a1Bc[5] = "1 BC"; // weak
char a05Bc[7] = "0.5 BC"; // weak
char a05[5] = "-0.5"; // weak
char a1_1[3] = "+1"; // weak
char a2_1[3] = "+2"; // weak
char asc_17A2F9[2] = "^"; // weak
_BYTE byte_17A300[4] = { 0, 0, 0, 0 }; // weak
char aRacesLbx_0[10] = "races.lbx"; // weak
char aRacerprtLbx[13] = "racerprt.lbx"; // weak
char asc_17A31B[2] = "\n"; // weak
char aBilltextLbx_1[13] = "billtext.lbx"; // weak
char asc_17A32A[2] = "\x1B"; // weak
_UNKNOWN unk_17A32C; // weak
char aBilltextLbx_0[13] = "billtext.lbx"; // weak
char aBilltex2Lbx_0[13] = "billtex2.lbx"; // weak
char aRacesLbx[10] = "races.lbx"; // weak
char asc_17A354[2] = " "; // weak
char byte_17A356 = '\0'; // weak
char aRp_0[3] = "RP"; // weak
char aBc_0[3] = "BC"; // weak
char aFp_1[3] = "FP"; // weak
char aMc_0[3] = "MC"; // weak
char aPr_1[3] = "PR"; // weak
_UNKNOWN *off_17A37E = &unk_1B000D; // weak
_BYTE byte_17A382[2] = { 73, 0 }; // weak
wchar_t aRad[4] = L"RAD"; // weak
char aBilltextLbx_2[13] = "billtext.lbx"; // weak
_UNKNOWN unk_17A399; // weak
_UNKNOWN *off_17A39A = (_UNKNOWN *)0xD001B; // weak
int16_t word_17A3A0 = 94; // weak
_BYTE byte_17A3A2[2] = { 27, 0 }; // weak
_UNKNOWN unk_17A3A4; // weak
char aScienceLbx_0[12] = "SCIENCE.LBX"; // weak
char aBilltextLbx_3[13] = "billtext.lbx"; // weak
char aIRp[6] = "%i RP"; // weak
char aIFp[6] = "%i FP"; // weak
char aIPr[6] = "%i PR"; // weak
char aRp_1[4] = " RP"; // weak
char aFp_0[4] = " FP"; // weak
char aPr_0[4] = " PR"; // weak
char asc_17A3EA[2] = " "; // weak
char asc_17A3EC[2] = "^"; // weak
char aTurnsumLbx[12] = "turnsum.lbx"; // weak
_UNKNOWN unk_17A3FA; // weak
char asc_17A3FB[2] = "\x1B"; // weak
int16_t word_17A40A = 48; // weak
char aPcx[5] = ".PCX"; // weak
char aWb_4[3] = "wb"; // weak
char aMarkBlockStack[31] = "Mark Block Stack Size Exceeded"; // weak
char aMarkBlockStack_0[23] = "Mark Block Stack Empty"; // weak
char aAilError[11] = "AIL error\n"; // weak
char aOutOfMemory[15] = "Out of memory\n"; // weak
char aRb_2[3] = "rb"; // weak
char aLbx[5] = ".lbx"; // weak
char aErrorBadRectIn[36] = "ERROR: Bad Rect in Add_Hidden_Field"; // weak
_UNKNOWN unk_17A59C; // weak
char asc_17A59D[2] = "_"; // weak
char aYouExceededThe[44] = "You exceeded the max number of fields (150)"; // weak
char aPrintOnlyWorks[28] = "Print only works on bitmaps"; // weak
char aMouseDriverReq[25] = "Mouse Driver Required..."; // weak
char aYouMustRunVesa[23] = "You must run VESA.COM."; // weak
char aRb_3[3] = "rb"; // weak
char aEntry[9] = " [entry "; // weak
char asc_17A680[3] = "] "; // weak
char aCouldNotBeFoun[21] = " could not be found."; // weak
char aHasBeenCorrupt[21] = " has been corrupted."; // weak
char aHasAnImproperE[31] = " has an improper entry number."; // weak
char aFailedToReload[40] = " failed to reload. Allocation too small"; // weak
char aIsNotAnLbxFile[20] = " is not an LBX file"; // weak
char aExceedsNumberO[31] = " exceeds number of LBX entries"; // weak
char aHasAnIncorrect[30] = " has an incorrect record size"; // weak
char aExceedsNumberO_0[35] = " exceeds number of defined records"; // weak
char aVgaFileAnimati[53] = " Vga file animation frames cannot exceed 65536 bytes"; // weak
char asc_17A7E7[2] = "\\"; // weak
char aNotEnoughSpace[34] = "Not Enough Space For Buffer Space"; // weak
char aErrorCacheCorr[24] = "ERROR: Cache Corrupted!"; // weak
char aMaxBufferSegsW[28] = "max buffer segs went over.."; // weak
char aMaxFileBufferC[34] = "max file buffer count went over.."; // weak
char aRb_4[3] = "rb"; // weak
char aRefreshMaskCan[28] = "Refresh Mask can't be drawn"; // weak
char aScreenBackgrou[35] = "Screen Background can't be clipped"; // weak
char aScreenBackgrou_0[35] = "Screen Background can't be clipped"; // weak
char aRemapDrawNotSu_4[31] = "Remap draw not support bitmaps"; // weak
char aRemapDrawNotSu_5[30] = "Remap draw not support screen"; // weak
char aRemapDrawNotSu_6[27] = "Remap draw not support map"; // weak
char aRemapDrawNotSu_7[31] = "Remap draw not support bitmaps"; // weak
char aRemapDrawNotSu_8[30] = "Remap draw not support screen"; // weak
char aRb_5[3] = "rb"; // weak
char aFileAnimationF[31] = "File Animation Frame Too Large"; // weak
char aRefreshMaskCan_0[28] = "Refresh Mask can't be drawn"; // weak
char aTooManyFramesF[41] = "Too many frames for multi file animation"; // weak
char aFileAnimationF_0[31] = "File Animation Frame Too Large"; // weak
char aDifferentailFi[46] = "Differentail File Animation Can not be bitmap"; // weak
char aDifferentailFi_0[46] = "Differentail File Animation Can not be masked"; // weak
char aFileAnimationF_1[31] = "File Animation Frame Too Large"; // weak
char aDifferentailFi_1[47] = "Differentail File Animation Can not be glassed"; // weak
char aDifferentailFi_2[46] = "Differentail File Animation Can not be bitmap"; // weak
char aDifferentailFi_3[46] = "Differentail File Animation Can not be masked"; // weak
char aMax3FileAnimat[22] = "Max 3 file animations"; // weak
char aTooManyFramesF_0[41] = "Too many frames for multi file animation"; // weak
char aFileAnimationF_3[31] = "File Animation Frame Too Large"; // weak
char aTooManyFramesF_1[41] = "Too many frames for multi file animation"; // weak
char aNotEnoughSpace_0[44] = "Not Enough Space For Brighten Palette Block"; // weak
char aBrightenPerecn[45] = "Brighten perecnt needs to be between 0 - 100"; // weak
char aAddPictureToBi[46] = "Add_Picture_To_Bitmap targetmust be a bitmap."; // weak
char aGetPictureColo[45] = "Get_Picture_Color  Picture Must Have Palette"; // weak
char aErrorGetcolorC[44] = "Error: GetColor color_index is out of range"; // weak
char aRemappedPictur[35] = "Remapped Picture Must Have Palette"; // weak
char aCannotColorRep[35] = "Cannot color replace refresh mask."; // weak
char aShiftPaletteRa[41] = "Shift_Palette_Range() exceeds 256 colors"; // weak
char aTooManyColorsT[41] = "Too many colors to reduce from (Max 512)"; // weak
char aTooManyColorsT_0[39] = "Too many colors to reduce to (Max 256)"; // weak
char aPaletteReducti[45] = "Palette Reduction Pictures Must Have Palette"; // weak
char aTooManyColorsT_1[41] = "Too many colors to reduce from (Max 512)"; // weak
char aRB[4] = "r+b"; // weak
char aDriveSwapReqdT[36] = "Drive swap reqd too large for block"; // weak
char aInsufficientDi[33] = "Insufficient disk space for swap"; // weak
char aWb_6[3] = "wb"; // weak
char aTempTmp[9] = "TEMP.TMP"; // weak
char aErrorInSwapFil[19] = "Error in swap file"; // weak
char aRb_6[3] = "rb"; // weak
char aAtS01[8] = "AT S0=1"; // weak
char byte_17B0D8 = '\0'; // weak
char aNo[4] = "NO "; // weak
char aBusy[5] = "BUSY"; // weak
char aError[6] = "ERROR"; // weak
char aConnect[8] = "CONNECT"; // weak
char aUnableToSend[16] = "Unable to send."; // weak
char aLownetLog[11] = "lownet.log"; // weak
char aLownetLogError[19] = "\nLOWNET.LOG error\n"; // weak
_UNKNOWN unk_17B145; // weak
char aAilDebug[10] = "AIL_DEBUG"; // weak
char aAilSysDebug[14] = "AIL_SYS_DEBUG"; // weak
char aWT[4] = "w+t"; // weak
char a302[5] = "3.02"; // weak
char aSb16Dig[9] = "SB16.DIG"; // weak
char aSbproDig[10] = "SBPRO.DIG"; // weak
char aSblasterDig[13] = "SBLASTER.DIG"; // weak
char aTypeModemPacke[20] = "Type: MODEM_PACKET\n"; // weak
char aTypeModemRecei[26] = "Type: MODEM_RECEIVED_ACK\n"; // weak
char aTypeModemRecei_0[27] = "Type: MODEM_RECEIVED_NACK\n"; // weak
char aClearingBuffer[16] = "clearing buffer"; // weak
char aRkernelCom[12] = "rkernel.com"; // weak
char aRkernelComNotF[24] = "\nRKERNEL.COM not found\n"; // weak
char aMemoryReleaseE[22] = "Memory release error\n"; // weak
char aNetNetC[10] = "net\\net.c"; // weak
char aTempstationidN[38] = "tempstationid <= NET_MAXIMUM_STATIONS"; // weak
char a0_1[2] = "0"; // weak
char aErrorGettingLo[29] = "Error: Getting Local Address"; // weak
char aRb_7[3] = "rb"; // weak
char aCanTFindRkerne[24] = "Can't find rkernel.com\n"; // weak
char aErrorDpmiInt0x[37] = "Error: DPMI int 0x31 function 0x100\n"; // weak
char aNullBuffer[13] = "NULL buffer\n"; // weak
char aLbx_0[5] = ".LBX"; // weak
char aWb_7[3] = "wb"; // weak
int dword_17C21C = 5461057; // weak
_UNKNOWN unk_17C220; // weak
int dword_17C238 = 4478017; // weak
_UNKNOWN unk_17C240; // weak
_UNKNOWN unk_17C244; // weak
char aAtc[4] = "ATC"; // weak
char aAte[4] = "ATE"; // weak
char aAtf[4] = "ATF"; // weak
char aAth[4] = "ATH"; // weak
char aAtm[4] = "ATM"; // weak
char aAtq[4] = "ATQ"; // weak
char aAtx[4] = "ATX"; // weak
char aAtv[4] = "ATV"; // weak
_UNKNOWN unk_17C26C; // weak
char byte_17C270[4] = { '\0', '\0', '\0', '\0' }; // weak
_UNKNOWN unk_17C274; // weak
char byte_17C278[] = { '0' }; // weak
char aDriver[7] = "DRIVER"; // weak
char aDevice[7] = "DEVICE"; // weak
char aIoAddr[8] = "IO_ADDR"; // weak
char aIrq[4] = "IRQ"; // weak
char aDma8Bit[10] = "DMA_8_bit"; // weak
char aDma16Bit[11] = "DMA_16_bit"; // weak
char aAil3dig[8] = "AIL3DIG"; // weak
char aAil3mdi[8] = "AIL3MDI"; // weak
char aWdigIni[9] = "wDIG.INI"; // weak
char aFmt[5] = "fmt "; // weak
char aData[5] = "data"; // weak
char aCreative[9] = "Creative"; // weak
char aWave[5] = "WAVE"; // weak
char aForm[5] = "FORM"; // weak
char aECat[8] = "e; CAT "; // weak
char aAtexmid[8] = "ateXMID"; // weak
char aRmdiIni[9] = "rMDI.INI"; // weak
char aTimb[5] = "TIMB"; // weak
char aAtcrbrn[8] = "atCRBRN"; // weak
char aNotevnt[8] = "notEVNT"; // weak
char aFailureAllocat[30] = "Failure allocating context %d"; // weak
char aPortDumpNotSup[40] = "Port dump not supported for this driver"; // weak
_UNKNOWN unk_17C8CC; // weak
char byte_17C8D0[] = { 'N' }; // weak
char aD_15[2] = "d"; // weak
char aVecportTypeGre[30] = "vecPort type:  Greenleaf Fast"; // weak
char aFatalErrorInOu[27] = "Fatal error in OutputBit!\n"; // weak
char aFatalErrorInIn[26] = "Fatal error in InputBit!\n"; // weak
char aFatalError[14] = "Fatal error: "; // weak
char IsTable[256] =
{
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\n',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '8',
  '8',
  '8',
  '8',
  '8',
  '8',
  '8',
  '8',
  '8',
  '8',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  'X',
  'X',
  'X',
  'X',
  'X',
  'X',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  'H',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\f',
  '\x98',
  '\x98',
  '\x98',
  '\x98',
  '\x98',
  '\x98',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\x88',
  '\f',
  '\f',
  '\f',
  '\f',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
char byte_17CD98[6] = { '\x01', '\x02', '\x04', '\b', '\x10', ' ' }; // weak
_UNKNOWN unk_17CF00; // weak
_UNKNOWN unk_17CF0C; // weak
char byte_17CF18[10] = { '\0', '\x12', '7', '9', '\x1D', '\a', '\x16', '\x1C', '\n', 'J' }; // weak
char *off_17CF22 = "MULTIGM.LBX"; // weak
int16_t word_17CF38[] = { 3 }; // weak
_UNKNOWN unk_17CF4A; // weak
int16_t word_17CF82 = 1; // weak
char aCombatShips[13] = "combat ships"; // weak
char aColonyShip[96] =
{
  'C',
  'o',
  'l',
  'o',
  'n',
  'y',
  ' ',
  'S',
  'h',
  'i',
  'p',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'K',
  'o',
  'l',
  'o',
  'n',
  'i',
  'e',
  's',
  'c',
  'h',
  'i',
  'f',
  'f',
  '\0',
  '\0',
  '\0',
  'C',
  'o',
  'l',
  'o',
  'n',
  'i',
  'a',
  'l',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'N',
  'a',
  'v',
  'e',
  ' ',
  'C',
  'o',
  'l',
  'o',
  'n',
  'i',
  'a',
  '\0',
  '\0',
  '\0',
  '\0',
  'N',
  'a',
  'v',
  'e',
  ' ',
  'c',
  'o',
  'l',
  'o',
  'n',
  'i',
  'a',
  '\0',
  '\0',
  '\0',
  '\0',
  'C',
  'o',
  'l',
  'o',
  'n',
  'y',
  ' ',
  'S',
  'h',
  'i',
  'p',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
char aTransport[192] =
{
  'T',
  'r',
  'a',
  'n',
  's',
  'p',
  'o',
  'r',
  't',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'T',
  'r',
  'a',
  'n',
  's',
  'p',
  'o',
  'r',
  't',
  'e',
  'r',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'T',
  'r',
  'a',
  'n',
  's',
  'p',
  'o',
  'r',
  't',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'T',
  'r',
  'a',
  'n',
  's',
  'p',
  'o',
  'r',
  't',
  'e',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'N',
  'a',
  'v',
  'e',
  ' ',
  't',
  'r',
  'u',
  'p',
  'p',
  'a',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'T',
  'r',
  'a',
  'n',
  's',
  'p',
  'o',
  'r',
  't',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  't',
  'a',
  'n',
  'k',
  's',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'n',
  'o',
  't',
  ' ',
  'u',
  's',
  'e',
  'd',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
char aOutpostShip[96] =
{
  'O',
  'u',
  't',
  'p',
  'o',
  's',
  't',
  ' ',
  'S',
  'h',
  'i',
  'p',
  '\0',
  '\0',
  '\0',
  '\0',
  'A',
  'u',
  '|',
  'e',
  'n',
  'p',
  'o',
  's',
  't',
  'e',
  'n',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  'A',
  'v',
  'a',
  'n',
  't',
  'e',
  '-',
  'p',
  'o',
  's',
  't',
  'e',
  '\0',
  '\0',
  '\0',
  '\0',
  'P',
  'u',
  'e',
  's',
  't',
  'o',
  ' ',
  'A',
  'v',
  'a',
  'n',
  'z',
  'a',
  'd',
  'o',
  '\0',
  'N',
  'a',
  'v',
  'e',
  ' ',
  'a',
  'v',
  'a',
  'm',
  'p',
  'o',
  's',
  't',
  'o',
  '\0',
  '\0',
  'O',
  'u',
  't',
  'p',
  'o',
  's',
  't',
  ' ',
  'S',
  'h',
  'i',
  'p',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
int16_t word_17D16E[] = { 0 }; // weak
int16_t word_17D170[] = { 0 }; // weak
int16_t word_17D172[] = { 0 }; // weak
int16_t word_17D174[] = { 0 }; // weak
int16_t word_17D176[4] = { 50, 15, 15, 5 }; // weak
int16_t word_17D17E = 150; // weak
int16_t word_17D186 = 500; // weak
char byte_17D196[] = { '2' }; // weak
char byte_17D197[98] =
{
  '\x01',
  '2',
  '\x01',
  '2',
  '\x01',
  '2',
  '\x01',
  '2',
  '\x01',
  '\x14',
  '\x01',
  '\x14',
  '\x01',
  '\x14',
  '\x01',
  '\n',
  '\x01',
  '2',
  '\x01',
  '\x14',
  '\0',
  '\x05',
  '\x01',
  '\n',
  '\x01',
  '2',
  '\0',
  '2',
  '\0',
  '\n',
  '\x01',
  '\n',
  '\0',
  '2',
  '\x01',
  '\x14',
  '\0',
  '\x14',
  '\0',
  '\x05',
  '\0',
  '\x14',
  '\0',
  '2',
  '\x01',
  '\n',
  '\0',
  '\n',
  '\0',
  '\n',
  '\0',
  '\x14',
  '\0',
  '\x05',
  '\x01',
  '\x14',
  '\0',
  '\x05',
  '\x01',
  '\n',
  '\0',
  '\n',
  '\x01',
  '2',
  '\0',
  '2',
  '\0',
  '\n',
  '\x01',
  '\x05',
  '\x01',
  '\n',
  '\0',
  '\x05',
  '\0',
  '\x05',
  '\0',
  '2',
  '\0',
  '2',
  '\x01',
  '\x05',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
char byte_17D1F9[] = { '\0' }; // weak
char byte_17D1FA[] = { '\0' }; // weak
char byte_17D1FB[] = { '\0' }; // weak
char byte_17D1FC[29] =
{
  '\0',
  '\xCE',
  '2',
  'd',
  '\xFF',
  '\x02',
  '\x04',
  '\xFF',
  '\x01',
  '\x02',
  '\xFF',
  '\x01',
  '\x02',
  '\xFF',
  '\x01',
  '\x02',
  '\xEC',
  '\x19',
  '2',
  '\xEC',
  '\x14',
  '2',
  '\xF6',
  '\n',
  '\x14',
  '\xF6',
  '\n',
  '\x14',
  '\0'
}; // weak
int dword_17D219[] = { 1 }; // weak
char byte_17D21D[] = { '\0' }; // weak
int16_t word_17D21E[] = { 20 }; // weak
char byte_17D220[] = { '\x01' }; // weak
char byte_17D221[] = { '\x02' }; // weak
int dword_17D222 = 0; // weak
char *off_17D226 = "%d%%"; // weak
int dword_17D234 = 0; // weak
int dword_17D246 = 0; // weak
int dword_17D258 = 0; // weak
int dword_17D261 = 16; // weak
int dword_17D26A = 0; // weak
int dword_17D273 = 32; // weak
int dword_17D27C = 0; // weak
int dword_17D28E = 0; // weak
int dword_17D2A0 = 0; // weak
int dword_17D2A9 = 1; // weak
int dword_17D2B2 = 0; // weak
int dword_17D2C4 = 0; // weak
int dword_17D2CD = 64; // weak
int dword_17D2D6 = 0; // weak
int dword_17D2DF = 128; // weak
int dword_17D2E8 = 0; // weak
int dword_17D2FA = 0; // weak
int dword_17D30C = 0; // weak
int dword_17D31E = 0; // weak
int dword_17D330 = 0; // weak
int dword_17D342 = 0; // weak
int dword_17D354 = 0; // weak
int dword_17D366 = 0; // weak
int dword_17D378 = 0; // weak
int dword_17D38A = 0; // weak
int dword_17D39C = 0; // weak
int dword_17D3AE = 0; // weak
int dword_17D3C0 = 0; // weak
int dword_17D3D2 = 0; // weak
int dword_17D3E4 = 0; // weak
int dword_17D3F6 = 0; // weak
int dword_17D408 = 0; // weak
int dword_17D411 = 256; // weak
int dword_17D41A = 0; // weak
int dword_17D42C = 0; // weak
int dword_17D43E = 0; // weak
int dword_17D450 = 0; // weak
int dword_17D462 = 0; // weak
int dword_17D474 = 0; // weak
int dword_17D486 = 0; // weak
int dword_17D498 = 0; // weak
int dword_17D4AA = 0; // weak
int dword_17D4BC = 0; // weak
int dword_17D4CE = 0; // weak
int dword_17D4E0 = 0; // weak
int dword_17D4F2 = 0; // weak
int dword_17D504 = 0; // weak
int dword_17D516 = 0; // weak
int dword_17D528 = 0; // weak
int dword_17D53A = 0; // weak
int dword_17D54C = 0; // weak
int dword_17D55E = 0; // weak
int dword_17D570 = 0; // weak
int dword_17D582 = 0; // weak
int dword_17D594 = 0; // weak
int dword_17D5A6 = 0; // weak
int dword_17D5B8 = 0; // weak
int dword_17D5CA = 0; // weak
int dword_17D5DC = 0; // weak
char *off_17D5E0[21] =
{
  "+%d",
  "I",
  "II",
  "III",
  "IV",
  "V",
  "VI",
  "VII",
  "VIII",
  "IX",
  "X",
  "XI",
  "XII",
  "XIII",
  "XIV",
  "XV",
  "XVI",
  "XVII",
  "XVIII",
  "XIX",
  "XX"
}; // weak
char *off_17D5E4[20] =
{
  "I",
  "II",
  "III",
  "IV",
  "V",
  "VI",
  "VII",
  "VIII",
  "IX",
  "X",
  "XI",
  "XII",
  "XIII",
  "XIV",
  "XV",
  "XVI",
  "XVII",
  "XVIII",
  "XIX",
  "XX"
}; // weak
int16_t word_17D634 = 2; // weak
int16_t word_17D636 = 0; // weak
int16_t word_17D638 = 0; // weak
int16_t word_17D63A = 0; // weak
int16_t word_17D63C = 0; // weak
int16_t word_17D63E = 0; // weak
char byte_17D640[64] =
{
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
char byte_17D680[] = { '\0' }; // weak
char byte_17D6BC[50] =
{
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x04',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\x03',
  '\x02',
  '\x01',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x02',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03'
}; // weak
char byte_17D6EE[60] =
{
  '\x02',
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\0',
  '\x02',
  '\x02',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x01',
  '\x01',
  '\x02',
  '\x03',
  '\x02',
  '\x02',
  '\x01',
  '\x01',
  '\x02',
  '\x03',
  '\x02',
  '\x02',
  '\x02',
  '\x01',
  '\x02',
  '\x03',
  '\x03',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x02',
  '\x02',
  '\x03',
  '\x04',
  '\x03',
  '\x03',
  '\x02',
  '\x02',
  '\x03',
  '\x04',
  '\x04',
  '\x04',
  '\x03',
  '\x02',
  '\x04'
}; // weak
char byte_17D72A[55] =
{
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\x01',
  '\x01',
  '\0',
  '\x01',
  '\x01',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02'
}; // weak
char byte_17D761[30] =
{
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\x01',
  '\x02',
  '\x02',
  '\x03',
  '\x01',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x01',
  '\x02',
  '\x03',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x03'
}; // weak
char byte_17D77F[40] =
{
  '\x0F',
  '\x0F',
  '\n',
  '\x14',
  '7',
  '2',
  '\x0F',
  '\0',
  '\x19',
  '\x19',
  '\n',
  'F',
  '\x05',
  '\n',
  '\n',
  '\0',
  '\0',
  '\x05',
  '\n',
  '\b',
  '\0',
  '\0',
  '\n',
  '\x02',
  '\0',
  '\0',
  '\v',
  '\0',
  '\0',
  '\0',
  '\v',
  '\0',
  '\0',
  '\0',
  '\v',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\0'
}; // weak
char byte_17D7A7[40] =
{
  '\x0F',
  '\x0F',
  '\n',
  '\x14',
  '7',
  '2',
  '\x0F',
  '\0',
  '\x19',
  '\x19',
  '\n',
  'F',
  '\x05',
  '\n',
  '\n',
  '\0',
  '\0',
  '\x05',
  '\n',
  '\b',
  '\0',
  '\0',
  '\n',
  '\x02',
  '\0',
  '\0',
  '\v',
  '\0',
  '\0',
  '\0',
  '\v',
  '\0',
  '\0',
  '\0',
  '\v',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\0'
}; // weak
char byte_17D7CF[40] =
{
  '\x0F',
  '\x05',
  '\x05',
  '\x14',
  '(',
  '\x1E',
  '\b',
  '\0',
  '\x14',
  '\x14',
  '\b',
  '2',
  '\x19',
  '\x19',
  '\r',
  '\0',
  '\0',
  '\x14',
  '\r',
  '\x1E',
  '\0',
  '\0',
  '\r',
  '\0',
  '\0',
  '\0',
  '\r',
  '\0',
  '\0',
  '\0',
  '\r',
  '\0',
  '\0',
  '\0',
  '\n',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\0'
}; // weak
char byte_17D7F7[5] = { '\x01', '\x03', '\a', '\t', '\n' }; // weak
char byte_17D7FC[10] = { '\x02', '\x04', '\x05', '\a', '\n', '\x02', '\x04', '\x06', '\t', '\f' }; // weak
char byte_17D806[17] =
{
  '\x05',
  '\n',
  '\x0F',
  '\x14',
  '\x19',
  '\n',
  '\x14',
  '\x1E',
  '-',
  '\\',
  '`',
  'd',
  '\x01',
  '\x02',
  '\x03',
  '\x04',
  '\x05'
}; // weak
char byte_17D817[5] = { '\0', '\0', '\0', '\xF6', '\xEC' }; // weak
char byte_17D81C[8] = { '\0', '\0', '\0', '\x01', '\x01', '\x02', '\x02', '\x01' }; // weak
char byte_17D824 = '\x02'; // weak
char byte_17D825 = '\x03'; // weak
char byte_17D826 = '@'; // weak
char byte_17D832[12] =
{
  '@',
  '\x05',
  '\x03',
  '\x02',
  '\x03',
  '\x02',
  '\t',
  '\x04',
  '\x03',
  '\0',
  '\x05',
  '\0'
}; // weak
char byte_17D83E[21] =
{
  '\x14',
  '\n',
  '\x05',
  '\x19',
  '\x0F',
  '\x05',
  '\n',
  '\x10',
  '\x1E',
  '\n',
  '\x10',
  '\x15',
  ' ',
  '%',
  '\x1E',
  '\x01',
  '\x02',
  '\x03',
  '\x02',
  '\x04',
  '\x06'
}; // weak
int16_t word_17D853 = 1; // weak
int16_t word_17D855[9] = { 0, 0, -10, -20, -30, -40, -55, -70, -85 }; // weak
int16_t word_17D867[9] = { 0, 0, -10, -20, -30, -40, -50, -60, -65 }; // weak
_UNKNOWN unk_17D879; // weak
int16_t word_17D881[] = { 12 }; // weak
char aLanguageIni[13] = "language.ini"; // weak
int16_t word_17D8AC[] = { 41 }; // weak
int dword_17D8ED = 486548480; // weak
_UNKNOWN *off_17D904 = &unk_178A04; // weak
int16_t word_17D90C = 0; // weak
int16_t word_17D90E[4] = { 0, 0, 0, 0 }; // weak
int dword_17D916 = 0; // weak
char byte_17D91A[] = { '\0' }; // weak
int16_t word_17D998[] = { 0 }; // weak
int dword_17E06C = 0; // weak
_UNKNOWN *off_17E079 = &unk_178A04; // weak
int16_t word_17E07D = 0; // weak
int16_t word_17E07F = 0; // weak
char byte_17E082[] = { '\0' }; // weak
char byte_17E084[] = { '\x01' }; // weak
// PORT: Hex-Rays declared this as a single byte, but Debug/diss/Orion2.exe.asm
// shows byte_176085 is the START of a large table of 13-byte tech-tree records
// (`imul edx, 0Dh` in sub_5E1E3/readers - 13 * techId indexing), running
// uninterrupted up to the next real symbol `dword_176B2A` (== dword_17EB2A
// here, +0x8000 delta) - i.e. 0x176B2A-0x176085 = 0xAA5 = 2725 bytes. Sizing
// it to 1 byte let sub_5E1E3's table-init loops (`byte_17E085[13*techId] = flag`)
// write far past the end, corrupting the heap and crashing later inside CRT
// code (wave 23). off_17E0EE/off_17E7F0/off_17EA60 are separately-declared
// globals that are ALSO just offsets into this same original blob, but since
// this port keeps them as independent objects (not aliased into this array),
// only the flag-byte writes/reads (byte_17E085[13*idx]) need this array sized
// correctly; the full struct merge is a follow-up if other fields are needed.
char byte_17E085[2730] = { 0 }; // weak
_UNKNOWN *off_17E0EE = &unk_178A04; // weak
_UNKNOWN *off_17E7F0 = &unk_178A04; // weak
_UNKNOWN *off_17EA60 = &unk_178A04; // weak
int dword_17EB2A = 2686976; // weak
_UNKNOWN *off_17EB3D = &unk_178A04; // weak
// PORT (wave 23): Hex-Rays declared word_17EB43/17EEE6/17F63E/17F6A7/17F80D/
// 17FDF2/17FE76/17FFE8 as single int16 scalars, but sub_5E1E3 (and several
// other functions in orion_part_04.c) index them via raw byte-offset casts
// `*(int16_t*)((char*)&word_X + STRIDE*i)` with STRIDE 15-59 and i up to ~45 -
// i.e. each is really the head of a multi-record lookup table. The 1-element
// declaration let those reads run off the end into whatever followed in BSS,
// producing a garbage tech-tree index that was then used as a raw offset into
// byte_17E085 - the actual out-of-bounds WRITE that crashed (wave 23, see
// PROGRESS.md). Sized generously (1024 elements/2048 bytes, well above every
// STRIDE*maxIndex seen) to stop the overrun; the original content is zero for
// now (a data-fidelity gap - the exact tech-table values still need pulling
// from the original binary, this only fixes the crash).
int16_t word_17EB43[1024] = { 0 }; // weak
int dword_17EB45 = 0; // weak
int16_t word_17EB49 = 0; // weak
char byte_17EB4B[] = { '\x06' }; // weak
_UNKNOWN *off_17EB63 = &unk_178A04; // weak
int dword_17EBA4 = 150; // weak
_UNKNOWN *off_17EBAF = &unk_178A04; // weak
_UNKNOWN *off_17EBC2 = &unk_178A04; // weak
int dword_17EBDD = 1000; // weak
int dword_17EC16 = 200; // weak
_UNKNOWN *off_17EC21 = &unk_178A04; // weak
_UNKNOWN *off_17EC6D = &unk_178A04; // weak
_UNKNOWN *off_17EC93 = &unk_178A04; // weak
_UNKNOWN *off_17ECA6 = &unk_178A04; // weak
_UNKNOWN *off_17ECB9 = &unk_178A04; // weak
int dword_17ECC1 = 120; // weak
_UNKNOWN *off_17ECCC = &unk_178A04; // weak
_UNKNOWN *off_17ECDF = &unk_178A04; // weak
int dword_17ED0D = 200; // weak
_UNKNOWN *off_17ED2B = &unk_178A04; // weak
_UNKNOWN *off_17ED3E = &unk_178A04; // weak
int dword_17ED59 = 80; // weak
_UNKNOWN *off_17ED64 = &unk_178A04; // weak
_UNKNOWN *off_17ED77 = &unk_178A04; // weak
_UNKNOWN *off_17ED8A = &unk_178A04; // weak
int dword_17ED92 = 250; // weak
int dword_17EDA5 = 80; // weak
_UNKNOWN *off_17EDB0 = &unk_178A04; // weak
_UNKNOWN *off_17EDC3 = &unk_178A04; // weak
_UNKNOWN *off_17EDD6 = &unk_178A04; // weak
_UNKNOWN *off_17EDE9 = &unk_178A04; // weak
_UNKNOWN *off_17EE22 = &unk_178A04; // weak
int dword_17EE3D = 400; // weak
_UNKNOWN *off_17EE5B = &unk_178A04; // weak
_UNKNOWN *off_17EE6E = &unk_178A04; // weak
_UNKNOWN *off_17EEB1 = (_UNKNOWN *)0x30000; // weak
_UNKNOWN *off_17EEBA = &unk_178A04; // weak
_UNKNOWN *off_17EEE0 = &unk_178A04; // weak
int16_t word_17EEE6[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23)
int16_t word_17EEE8[6] = { 0, 0, 0, 0, 0, 0 }; // weak
int16_t word_17EEF4[] = { 0 }; // weak
int16_t word_17EF00 = 0; // weak
char byte_17EF0C[] = { '\0' }; // weak
int16_t word_17EF0D = 0; // weak
int16_t word_17EF44 = 20; // weak
int16_t word_17F0EB = 63; // weak
int16_t word_17F0ED = 12; // weak
int16_t word_17F178 = 82; // weak
int16_t word_17F3DB = 56; // weak
int16_t word_17F582 = 192; // weak
int dword_17F629 = 3; // weak
_UNKNOWN *off_17F638 = &unk_178A04; // weak
int16_t word_17F63E[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23)
char byte_17F641[] = { '\0' }; // weak
int16_t word_17F642 = -100; // weak
int16_t word_17F644 = 0; // weak
char byte_17F646[] = { '\0' }; // weak
_UNKNOWN *off_17F665 = &unk_178A04; // weak
char byte_17F698 = '\xC9'; // weak
char byte_17F69B = '\x1E'; // weak
_UNKNOWN *off_17F6A1 = &unk_178A04; // weak
int16_t word_17F6A7[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23)
int16_t word_17F6A9 = 0; // weak
int16_t word_17F6B5[6] = { 0, 0, 0, 0, 0, 0 }; // weak
int16_t word_17F6C1 = 0; // weak
int dword_17F7E7[] = { 2560 }; // weak
int dword_17F7EB[] = { 0 }; // weak
_UNKNOWN *off_17F803 = &unk_178A04; // weak
_UNKNOWN *off_17F807 = &unk_178A04; // weak
int16_t word_17F80B[] = { 0 }; // weak
int16_t word_17F80D[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23)
char byte_17F80F[] = { '\0' }; // weak
char byte_17F810[] = { '\xFF' }; // weak
int16_t word_17F811[] = { 0 }; // weak
int16_t word_17F813[] = { 0 }; // weak
int16_t word_17F815[] = { 0 }; // weak
int16_t word_17F817[] = { 0 }; // weak
int16_t word_17F819[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23; used with stride 14 in orion_part_04.c)
char byte_17F81C[] = { '\0' }; // weak
int16_t word_17F81D[] = { 0 }; // weak
int16_t word_17F983 = 4; // weak
int16_t word_17F985 = 32; // weak
_UNKNOWN *off_17FB13 = &unk_178A04; // weak
_UNKNOWN *off_17FB17 = &unk_178A04; // weak
int16_t word_17FB1D = 17; // weak
_UNKNOWN *off_17FB2F = &unk_178A04; // weak
_UNKNOWN *off_17FB33 = &unk_178A04; // weak
int16_t word_17FB39 = 83; // weak
_UNKNOWN *off_17FB4B = &unk_178A04; // weak
_UNKNOWN *off_17FB4F = &unk_178A04; // weak
int16_t word_17FB55 = 31; // weak
_UNKNOWN *off_17FB67 = &unk_178A04; // weak
_UNKNOWN *off_17FB6B = &unk_178A04; // weak
int16_t word_17FB71 = 66; // weak
int16_t word_17FC07 = 2; // weak
int16_t word_17FC09 = 24; // weak
int16_t word_17FC41 = 400; // weak
int16_t word_17FCE7 = 10; // weak
int16_t word_17FCE9 = 40; // weak
int dword_17FCFC = 1677798655; // weak
int dword_17FD00 = 419430400; // weak
_UNKNOWN *off_17FD0B = &unk_178A04; // weak
_UNKNOWN *off_17FD0F = &unk_178A04; // weak
char byte_17FD14[] = { '\0' }; // weak
int16_t word_17FD15 = 0; // weak
int16_t word_17FD17 = 0; // weak
_UNKNOWN *off_17FD1E = &unk_178A04; // weak
int16_t word_17FD26 = 100; // weak
_UNKNOWN *off_17FD2D = &unk_178A04; // weak
char byte_17FD32 = '\0'; // weak
int16_t word_17FD35 = -50; // weak
char byte_17FD41 = '\x01'; // weak
char byte_17FD50 = '\x01'; // weak
char byte_17FD5F = '\x01'; // weak
int16_t word_17FD62 = 25; // weak
char byte_17FD6E = '\x01'; // weak
char byte_17FD7D = '\x02'; // weak
int16_t word_17FD80 = 50; // weak
char byte_17FD8C = '\x02'; // weak
int16_t word_17FD8F = 100; // weak
int16_t word_17FD9E = 100; // weak
int16_t word_17FDAD = 25; // weak
char byte_17FDB9 = '\x01'; // weak
int16_t word_17FDBC = 25; // weak
char byte_17FDC8 = '\x01'; // weak
int16_t word_17FDCB = 25; // weak
int dword_17FDD6 = 19660813; // weak
int16_t word_17FDDA = 300; // weak
int16_t word_17FDE9 = 50; // weak
_UNKNOWN *off_17FDEC = &unk_178A04; // weak
int16_t word_17FDF2[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23)
int16_t word_17FDF4[] = { 0 }; // weak
int16_t word_17FE00[] = { 0 }; // weak
_UNKNOWN unk_17FE42; // weak
_UNKNOWN *off_17FE70 = &unk_178A04; // weak
int16_t word_17FE76[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23)
int16_t word_17FE78[] = { 0 }; // weak
int16_t word_17FE84[] = { 0 }; // weak
char byte_17FE90[] = { '\0' }; // weak
char byte_17FE92[4] = { '\0', '\0', '\0', '\0' }; // weak
char byte_17FE96[6] = { '\0', '\0', '\0', '\0', '\0', '\0' }; // weak
int16_t word_17FE9C[] = { 0 }; // weak
char byte_17FEEE = '\b'; // weak
int dword_17FFA6[] = { 219025168 }; // weak
_UNKNOWN *off_17FFB2 = &unk_178A04; // weak
_UNKNOWN *off_17FFD6 = &unk_178A04; // weak
int16_t word_17FFDE = 2; // weak
int16_t word_17FFE8[1024] = { 0 }; // weak (see word_17EB43 comment - wave 23)
int16_t word_17FFEA[] = { 0 }; // weak
_UNKNOWN *off_180014 = &unk_178A04; // weak
int dword_18001A[] = { 16711864 }; // weak
int16_t word_18001E[] = { 20 }; // weak
int16_t word_180020[] = { 25 }; // weak
char byte_180022[] = { '\x05' }; // weak
int16_t word_180024[] = { 4 }; // weak
int16_t word_180026[] = { 4 }; // weak
int16_t word_180028[] = { 1 }; // weak
int16_t word_18002A[] = { 2 }; // weak
int16_t word_18002C[] = { 1 }; // weak
int16_t word_18002E[] = { 1 }; // weak
int16_t word_180030[] = { 0 }; // weak
int16_t word_180032[] = { 0 }; // weak
int16_t word_180034[] = { 0 }; // weak
int16_t word_180036[] = { 50 }; // weak
int16_t word_180038[] = { 4 }; // weak
_UNKNOWN *off_18003A = &unk_178A04; // weak
_UNKNOWN *off_18003E = &unk_178A04; // weak
_UNKNOWN *off_1800EE = &unk_178A04; // weak
int16_t word_1800F8 = 300; // weak
int16_t word_1800FC = 60; // weak
int16_t word_1800FE = 60; // weak
int16_t word_18010E = -10; // weak
int16_t word_180110 = 100; // weak
_UNKNOWN *off_180112 = &unk_178A04; // weak
int16_t word_18011C = 600; // weak
int16_t word_180120 = 90; // weak
int16_t word_180122 = 90; // weak
int16_t word_180132 = -10; // weak
int16_t word_180134 = 200; // weak
_UNKNOWN *off_180136 = &unk_178A04; // weak
int16_t word_180140 = 1200; // weak
char byte_180142 = 'P'; // weak
int16_t word_180144 = 120; // weak
int16_t word_180146 = 120; // weak
int16_t word_180156 = -10; // weak
int16_t word_180158 = 500; // weak
_UNKNOWN *off_18015A = &unk_178A04; // weak
_UNKNOWN unk_180164; // weak
_UNKNOWN unk_180170; // weak
_UNKNOWN unk_180178; // weak
char byte_180184[] = { '\x02' }; // weak
char byte_180185[] = { '\a' }; // weak
char byte_180186[2208] =
{
  '\x02',
  '\b',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x1D',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x0F',
  '\x01',
  '\x0E',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\a',
  '\x01',
  '\x03',
  '\x02',
  '\x11',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\a',
  '\x02',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x02',
  '\x1D',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x1D',
  '\x01',
  '\x11',
  '\x01',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x06',
  '\0',
  '\0',
  '\x0F',
  '\x01',
  '\x0E',
  '\x01',
  '\a',
  '\x02',
  '\b',
  '\x02',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\x1E',
  '\x01',
  '\a',
  '\x02',
  '\x1D',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x02',
  '\b',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x02',
  '\b',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\x13',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\a',
  '\x02',
  '\x15',
  '\x01',
  '\x17',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\b',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\x17',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x13',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x06',
  '\x15',
  '\x01',
  '\x13',
  '\x01',
  '\0',
  '\x06',
  '\x02',
  '\x02',
  '\x03',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\a',
  '\x15',
  '\x01',
  '\x13',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x02',
  '\x04',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x04',
  '\x01',
  '\0',
  '\x06',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\x1D',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x13',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x04',
  '\x01',
  '\r',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x13',
  '\x01',
  '\x06',
  '\x02',
  '\r',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x15',
  '\x01',
  '\x06',
  '\x02',
  '\x17',
  '\x01',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x15',
  '\x01',
  '\x1D',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\a',
  '\x04',
  '\x01',
  '\x15',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\x1D',
  '\x01',
  '\x10',
  '\x01',
  '\x01',
  '\x02',
  '\0',
  '\0',
  '\x06',
  '\x04',
  '\x01',
  '\x13',
  '\x01',
  '\0',
  '\0',
  '\r',
  '\x01',
  '\x17',
  '\x01',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x03',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x10',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\t',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x03',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x04',
  '\x02',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\t',
  '\x01',
  '\a',
  '\x03',
  '\x1E',
  '\x01',
  '\x04',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\b',
  '\x01',
  '\x06',
  '\x03',
  '\x1D',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x06',
  '\b',
  '\x01',
  '\t',
  '\x01',
  '\a',
  '\x03',
  '\x06',
  '\x03',
  '\x1E',
  '\x01',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x0F',
  '\x01',
  '\x0E',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\r',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\n',
  '\0',
  '\x01',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\b',
  '\x01',
  '\x04',
  '\x02',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\b',
  '\x01',
  '\x13',
  '\x01',
  '\r',
  '\x01',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x05',
  '\b',
  '\x01',
  '\x13',
  '\x01',
  '\0',
  '\x06',
  '\x04',
  '\x02',
  '\x01',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\t',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x18',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x10',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x04',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x04',
  '\x02',
  '\x05',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x0E',
  '\x01',
  '\x0F',
  '\x01',
  '\x10',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x18',
  '\x01',
  '\t',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\f',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\v',
  '\x01',
  '\t',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x15',
  '\x01',
  '\x17',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\f',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x02',
  '\x03',
  '\x03',
  '\x03',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x15',
  '\x01',
  '\x17',
  '\x01',
  '\r',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\t',
  '\x01',
  '\x03',
  '\x03',
  '\x17',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x04',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\0',
  '\x06',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x13',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\x0E',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\x06',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x04',
  '\x02',
  '\0',
  '\x06',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\b',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x13',
  '\x01',
  '\x02',
  '\x02',
  '\x04',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x1C',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\0',
  '\0',
  '\x05',
  '\x02',
  '\x01',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\0',
  '\0',
  '\x1D',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\0',
  '\0',
  '\x1C',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x06',
  '\x02',
  '\x1C',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\x05',
  '\x02',
  '\x01',
  '\x02',
  '\x04',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\x04',
  '\x02',
  '\x02',
  '\x02',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x06',
  '\0',
  '\0',
  '\x13',
  '\x01',
  '\x02',
  '\x02',
  '\x03',
  '\x02',
  '\x06',
  '\x02',
  '\x11',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x13',
  '\x01',
  '\x06',
  '\x02',
  '\x1C',
  '\x01',
  '\b',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\t',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\x01',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x01',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\n',
  '\0',
  '\t',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x13',
  '\x01',
  '\t',
  '\x02',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\f',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x13',
  '\x01',
  '\v',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x15',
  '\x01',
  '\x02',
  '\x02',
  '\x03',
  '\x02',
  '\x04',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x15',
  '\x01',
  '\x17',
  '\x01',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x13',
  '\x01',
  '\x02',
  '\x02',
  '\f',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x13',
  '\x01',
  '\x15',
  '\x01',
  '\v',
  '\x01',
  '\x17',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x04',
  '\x15',
  '\x01',
  '\x13',
  '\x01',
  '\x17',
  '\x01',
  '\0',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x15',
  '\x01',
  '\x17',
  '\x01',
  '\x05',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x0F',
  '\x01',
  '\x0E',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x10',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x02',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x02',
  '\x0E',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x02',
  '\b',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x13',
  '\x01',
  '\x01',
  '\0',
  '\r',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\x06',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x03',
  '\x02',
  '\x04',
  '\x02',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x0F',
  '\x01',
  '\x0E',
  '\x01',
  '\x10',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x0F',
  '\x01',
  '\x0E',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x13',
  '\x01',
  '\x01',
  '\x02',
  '\x0E',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x05',
  '\x15',
  '\x01',
  '\a',
  '\x02',
  '\x03',
  '\x02',
  '\x0E',
  '\x01',
  '\x10',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x05',
  '\x02',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\x0E',
  '\x01',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\x0E',
  '\x01',
  '\x10',
  '\x01',
  '\x0F',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x03',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\x03',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\b',
  '\x15',
  '\x01',
  '\x13',
  '\x01',
  '\x03',
  '\x02',
  '\x04',
  '\x02',
  '\x0E',
  '\x01',
  '\x10',
  '\x01',
  '\x0F',
  '\x01',
  '\x01',
  '\x02',
  '\b',
  '\x13',
  '\x01',
  '\x02',
  '\x01',
  '\x01',
  '\x02',
  '\x0E',
  '\x01',
  '\x10',
  '\x01',
  '\x0F',
  '\x01',
  '\a',
  '\x02',
  '\x06',
  '\x02',
  '\a',
  '\x06',
  '\x02',
  '\a',
  '\x02',
  '\x11',
  '\x01',
  '\x02',
  '\x02',
  '\x0E',
  '\x01',
  '\x15',
  '\x01',
  '\x13',
  '\x01',
  '\0',
  '\0'
}; // weak
char byte_180A26[] = { '\x02' }; // weak
char byte_180A27[] = { '\a' }; // weak
char byte_180A28[648] =
{
  '\x03',
  '\b',
  '\x03',
  '\x01',
  '\a',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\0',
  '\x02',
  '\a',
  '\x03',
  '\x03',
  '\x03',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x03',
  '\b',
  '\x02',
  '\x01',
  '\a',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x03',
  '\x03',
  '\x03',
  '\x02',
  '\a',
  '\x03',
  '\x03',
  '\x03',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x06',
  '\x02',
  '\a',
  '\x03',
  '\x02',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x06',
  '\x03',
  '\b',
  '\x03',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\x02',
  '\x02',
  '\a',
  '\x03',
  '\x03',
  '\x03',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x04',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\x03',
  '\x03',
  '\x02',
  '\x02',
  '\b',
  '\x02',
  '\x03',
  '\x03',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x02',
  '\a',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\t',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\b',
  '\0',
  '\x03',
  '\x02',
  '\x02',
  '\b',
  '\0',
  '\x03',
  '\x02',
  '\x02',
  '\b',
  '\0',
  '\x03',
  '\x02',
  '\x01',
  '\t',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\x02',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\x06',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\t',
  '\0',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\x02',
  '\x01',
  '\x02',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\a',
  '\0',
  '\x03',
  '\x03',
  '\x02',
  '\a',
  '\x02',
  '\x03',
  '\x03',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\x02',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x01',
  '\x06',
  '\x02',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x02',
  '\a',
  '\x03',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\x03',
  '\x02',
  '\x03',
  '\x03',
  '\a',
  '\x02',
  '\x02',
  '\x03',
  '\x02',
  '\x02',
  '\0',
  '\x01',
  '\x03',
  '\x03',
  '\0',
  '\0'
}; // weak
_UNKNOWN unk_180CB0; // weak
_UNKNOWN unk_180CBC; // weak
_UNKNOWN unk_180CC4; // weak
int16_t word_180CCC[6] = { -50, -20, -20, 0, 20, 30 }; // weak
int16_t word_180CD8 = -70; // weak
int16_t word_180CDC[] = { 40 }; // weak
int16_t word_180CE8 = 50; // weak
int16_t word_180CF0[50] =
{
  1,
  2,
  3,
  3,
  4,
  5,
  2,
  0,
  0,
  0,
  -10,
  -50,
  -30,
  -20,
  0,
  20,
  0,
  0,
  0,
  0,
  -10,
  -50,
  -30,
  0,
  50,
  15,
  -30,
  0,
  0,
  0,
  -10,
  -50,
  -30,
  0,
  50,
  15,
  -30,
  0,
  0,
  0,
  5,
  5,
  10,
  30,
  40,
  50,
  1,
  0,
  0,
  0
}; // weak
int16_t word_180D54[40] =
{
  0,
  30,
  80,
  20,
  10,
  0,
  80,
  0,
  0,
  0,
  10,
  50,
  30,
  0,
  -50,
  -20,
  -40,
  0,
  0,
  0,
  80,
  100,
  80,
  70,
  90,
  30,
  90,
  0,
  0,
  0,
  60,
  100,
  70,
  50,
  30,
  0,
  100,
  0,
  0,
  0
}; // weak
int16_t word_180DB8[10] = { 100, 50, 50, 100, 50, 20, 0, 0, 0, 0 }; // weak
_UNKNOWN unk_180DCC; // weak
_UNKNOWN unk_180DD4; // weak
_UNKNOWN unk_180DDC; // weak
_UNKNOWN unk_180DE4; // weak
_UNKNOWN unk_180DF6; // weak
_UNKNOWN unk_180E0C; // weak
_UNKNOWN unk_180E16; // weak
_UNKNOWN unk_180E22; // weak
_UNKNOWN unk_180E30; // weak
_UNKNOWN unk_180E3E; // weak
_UNKNOWN unk_180E54; // weak
_UNKNOWN unk_180E62; // weak
_UNKNOWN unk_180E7C; // weak
char byte_180E84[36] =
{
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01'
}; // weak
_UNKNOWN unk_180EA8; // weak
int16_t word_180EB4 = -1; // weak
int16_t word_180EB6 = -1; // weak
int16_t word_180EB8 = -1; // weak
int16_t word_180EBA = -1; // weak
_UNKNOWN unk_180EBC; // weak
int16_t word_180EC8[6] = { 20, 30, 40, 50, 80, 100 }; // weak
char byte_180ED4[] = { '\0' }; // weak
int16_t word_18105C[10] = { 5, 10, 20, 5, 50, 40, 5, 0, 0, 0 }; // weak
int16_t word_181070[] = { 7 }; // weak
int16_t word_181080[8] = { -10, -5, -3, 0, 20, 20, -10, 0 }; // weak
char byte_181090[140] =
{
  '\x03',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x05',
  '\x05',
  '\x01',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x01',
  '\x01',
  '\0',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x02',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x03',
  '\x05',
  '\x05',
  '\x05',
  '\x03',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x05',
  '\x05',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x02',
  '\x02',
  '\0',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\x03',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x04',
  '\x05',
  '\x05',
  '\x05',
  '\x05',
  '\x05',
  '\x05',
  '\x05',
  '\x01',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x02',
  '\x03',
  '\x03',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x04',
  '\x05',
  '\x05',
  '\x05',
  '\x05',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
int16_t word_18111C[6] = { 29, 55, 22, 57, 28, 23 }; // weak
_UNKNOWN unk_181128; // weak
_UNKNOWN unk_18113C; // weak
_UNKNOWN unk_181150; // weak
_UNKNOWN unk_18115C; // weak
_UNKNOWN unk_18116C; // weak
_UNKNOWN unk_18118C; // weak
_UNKNOWN unk_181198; // weak
_UNKNOWN unk_1811A4; // weak
_UNKNOWN unk_1811C0; // weak
_UNKNOWN *off_1811C8 = (_UNKNOWN *)0x10026; // weak
int16_t word_1811DC[] = { 24 }; // weak
int16_t word_1811DE[] = { 0 }; // weak
_UNKNOWN unk_18120C; // weak
_UNKNOWN unk_181258; // weak
int16_t word_1812A4[6] = { 1, 2, 3, 5, 7, 10 }; // weak
int16_t word_1812B0[] = { -1 }; // weak
int16_t word_1812B2[] = { -1 }; // weak
int16_t word_1812B6[] = { 15 }; // weak
int16_t word_1812BE[] = { -1 }; // weak
int16_t word_1812C0[] = { -1 }; // weak
int16_t word_1812C2[] = { 85 }; // weak
int16_t word_1812C6[61] =
{
  0,
  10,
  0,
  -1,
  5,
  -1,
  -1,
  -1,
  -1,
  45,
  30,
  -1,
  10,
  15,
  0,
  -1,
  0,
  -1,
  -1,
  -1,
  10,
  30,
  30,
  -1,
  15,
  15,
  0,
  -1,
  5,
  -1,
  -1,
  -1,
  15,
  25,
  25,
  -1,
  15,
  15,
  0,
  -1,
  10,
  -1,
  -1,
  -1,
  15,
  25,
  20,
  -1,
  15,
  15,
  0,
  -1,
  15,
  -1,
  -1,
  -1,
  15,
  20,
  20,
  -1,
  15
}; // weak
int16_t word_181340[] = { -1 }; // weak
int16_t word_181346[] = { 15 }; // weak
int16_t word_18134C[] = { 45 }; // weak
int16_t word_181350[] = { -1 }; // weak
int16_t word_181352[] = { 40 }; // weak
int16_t word_181356[61] =
{
  0,
  10,
  -1,
  -1,
  5,
  -1,
  -1,
  40,
  -1,
  15,
  20,
  -1,
  10,
  15,
  -1,
  -1,
  0,
  -1,
  -1,
  35,
  -1,
  20,
  20,
  -1,
  10,
  15,
  -1,
  -1,
  5,
  -1,
  -1,
  35,
  -1,
  20,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  10,
  -1,
  -1,
  35,
  -1,
  15,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  15,
  -1,
  -1,
  30,
  -1,
  15,
  15,
  -1,
  10
}; // weak
int16_t word_1813D0[] = { -1 }; // weak
int16_t word_1813D6[] = { 15 }; // weak
int16_t word_1813DE[] = { 45 }; // weak
int16_t word_1813E0[] = { -1 }; // weak
int16_t word_1813E2[] = { 40 }; // weak
int16_t word_1813E6[61] =
{
  0,
  10,
  -1,
  -1,
  5,
  -1,
  -1,
  -1,
  40,
  15,
  20,
  -1,
  10,
  15,
  -1,
  -1,
  0,
  -1,
  -1,
  -1,
  35,
  20,
  20,
  -1,
  10,
  15,
  -1,
  -1,
  5,
  -1,
  -1,
  -1,
  35,
  20,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  10,
  -1,
  -1,
  -1,
  35,
  15,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  15,
  -1,
  -1,
  -1,
  30,
  15,
  15,
  -1,
  10
}; // weak
int16_t word_181460[] = { -1 }; // weak
int16_t word_181464[] = { -1 }; // weak
int16_t word_181466[] = { 15 }; // weak
int16_t word_18146E[] = { 85 }; // weak
int16_t word_181472[] = { -1 }; // weak
int16_t word_181474[] = { 0 }; // weak
int16_t word_181476[61] =
{
  0,
  10,
  -1,
  0,
  5,
  -1,
  -1,
  -1,
  75,
  -1,
  -1,
  0,
  10,
  15,
  -1,
  0,
  0,
  -1,
  -1,
  -1,
  65,
  -1,
  -1,
  10,
  10,
  15,
  -1,
  0,
  5,
  -1,
  -1,
  -1,
  50,
  -1,
  10,
  10,
  10,
  15,
  -1,
  0,
  10,
  -1,
  -1,
  -1,
  45,
  -1,
  10,
  10,
  10,
  15,
  -1,
  0,
  15,
  -1,
  -1,
  -1,
  40,
  -1,
  10,
  10,
  10
}; // weak
int16_t word_1814F0[] = { -1 }; // weak
int16_t word_1814F6[] = { 15 }; // weak
int16_t word_1814FC[] = { 85 }; // weak
int16_t word_181502[] = { -1 }; // weak
int16_t word_181504[] = { 0 }; // weak
int16_t word_181506[61] =
{
  0,
  10,
  -1,
  -1,
  5,
  -1,
  -1,
  65,
  -1,
  -1,
  5,
  5,
  10,
  15,
  -1,
  -1,
  0,
  -1,
  -1,
  60,
  -1,
  -1,
  10,
  5,
  10,
  15,
  -1,
  -1,
  5,
  -1,
  -1,
  55,
  -1,
  -1,
  10,
  5,
  10,
  15,
  -1,
  -1,
  10,
  -1,
  -1,
  45,
  -1,
  -1,
  15,
  5,
  10,
  15,
  -1,
  -1,
  15,
  -1,
  -1,
  40,
  -1,
  -1,
  15,
  5,
  10
}; // weak
int16_t word_181580[] = { -1 }; // weak
int16_t word_181586[] = { 15 }; // weak
int16_t word_18158A[] = { 50 }; // weak
int16_t word_181590[] = { -1 }; // weak
int16_t word_181592[] = { 35 }; // weak
int16_t word_181596[61] =
{
  0,
  10,
  -1,
  -1,
  5,
  -1,
  40,
  -1,
  -1,
  20,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  0,
  -1,
  35,
  -1,
  -1,
  20,
  20,
  -1,
  10,
  15,
  -1,
  -1,
  5,
  -1,
  30,
  -1,
  -1,
  20,
  20,
  -1,
  10,
  15,
  -1,
  -1,
  10,
  -1,
  25,
  -1,
  -1,
  20,
  20,
  -1,
  10,
  15,
  -1,
  -1,
  15,
  -1,
  20,
  -1,
  -1,
  20,
  20,
  -1,
  10
}; // weak
int16_t word_181610[] = { -1 }; // weak
int16_t word_181616[] = { 15 }; // weak
int16_t word_181618[] = { 60 }; // weak
int16_t word_181620[] = { -1 }; // weak
int16_t word_181622[] = { 25 }; // weak
int16_t word_181624[] = { 0 }; // weak
int16_t word_181626[135] =
{
  0,
  10,
  -1,
  -1,
  5,
  50,
  -1,
  -1,
  -1,
  15,
  10,
  0,
  10,
  15,
  -1,
  -1,
  0,
  45,
  -1,
  -1,
  -1,
  15,
  15,
  0,
  10,
  15,
  -1,
  -1,
  5,
  40,
  -1,
  -1,
  -1,
  15,
  15,
  0,
  10,
  15,
  -1,
  -1,
  10,
  35,
  -1,
  -1,
  -1,
  15,
  15,
  0,
  10,
  15,
  -1,
  -1,
  15,
  60,
  -1,
  -1,
  -1,
  0,
  0,
  0,
  10,
  -1,
  -1,
  -1,
  15,
  60,
  -1,
  -1,
  -1,
  -1,
  25,
  -1,
  0,
  10,
  -1,
  -1,
  5,
  50,
  -1,
  -1,
  -1,
  15,
  10,
  -1,
  10,
  15,
  -1,
  -1,
  0,
  45,
  -1,
  -1,
  -1,
  15,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  5,
  40,
  -1,
  -1,
  -1,
  15,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  10,
  35,
  -1,
  -1,
  -1,
  15,
  15,
  -1,
  10,
  15,
  -1,
  -1,
  15,
  30,
  -1,
  -1,
  -1,
  15,
  15,
  -1,
  10,
  0,
  0
}; // weak
char byte_181734[9] = { '\x02', '\x05', '\f', '\x1E', 'K', '\0', '\0', '\0', '\0' }; // weak
char byte_18173D[9] = { '\x04', '\x04', '\x03', '\x02', '\x02', '\0', '\0', '\0', '\0' }; // weak
char byte_181746[] = { '\0' }; // weak
char byte_181750 = '\x01'; // weak
char byte_181751 = '\x01'; // weak
char byte_181752 = '\x01'; // weak
char byte_181753 = '\x01'; // weak
char *off_18175C = "DESIGN.LBX"; // weak
int16_t word_181760 = 0; // weak
_UNKNOWN unk_181768; // weak
_UNKNOWN unk_1817FE; // weak
_UNKNOWN unk_181800; // weak
_UNKNOWN unk_181802; // weak
_UNKNOWN unk_181804; // weak
_UNKNOWN unk_181806; // weak
_UNKNOWN unk_181808; // weak
_UNKNOWN unk_18180A; // weak
_UNKNOWN unk_18180C; // weak
_UNKNOWN unk_18180E; // weak
_UNKNOWN unk_181810; // weak
_UNKNOWN unk_181862; // weak
_UNKNOWN *off_1818F8 = &loc_110177; // weak
_UNKNOWN unk_181B3C; // weak
_UNKNOWN *off_181C7C = &loc_90139; // weak
_UNKNOWN *off_181D1C = &loc_90139; // weak
_UNKNOWN unk_181F06; // weak
_UNKNOWN unk_181F60; // weak
char *off_181FE4 = "FLEET.LBX"; // weak
_UNKNOWN unk_181FE8; // weak
_UNKNOWN unk_182018; // weak
_UNKNOWN unk_182048; // weak
char byte_182078[8] = { 'o', 't', 'r', 't', 't', 't', 't', 't' }; // weak
_UNKNOWN unk_182080; // weak
_UNKNOWN unk_182088; // weak
_UNKNOWN unk_182098; // weak
char *off_1820B4 = "GAME.LBX"; // weak
char byte_1820B8 = '\0'; // weak
int16_t word_1820C0 = 0; // weak
int16_t word_1820C2 = 0; // weak
char aEinstein[9] = "EINSTEIN"; // weak
char aMoola[6] = "MOOLA"; // weak
char aMenlo[6] = "MENLO"; // weak
char aIseeall[8] = "ISEEALL"; // weak
char aScore[6] = "SCORE"; // weak
_UNKNOWN unk_182135; // weak
_UNKNOWN unk_18213D; // weak
char byte_182145 = '\x01'; // weak
char byte_182146 = '\0'; // weak
int16_t word_182153 = -1000; // weak
int16_t word_182155 = -1000; // weak
int16_t word_182157 = -1000; // weak
int16_t word_182159 = -1000; // weak
int16_t word_18215B = -1000; // weak
int16_t word_18215D = -1000; // weak
int16_t word_18215F = -1000; // weak
int16_t word_182163 = -1000; // weak
_UNKNOWN unk_182175; // weak
_UNKNOWN unk_1821B1; // weak
_UNKNOWN unk_1821CC; // weak
_UNKNOWN unk_182208; // weak
char byte_182244 = '\0'; // weak
char byte_182245 = '\0'; // weak
char byte_182246 = '\x01'; // weak
char byte_182247 = '\x01'; // weak
_UNKNOWN unk_182248; // weak
char *off_182278 = "OFFICER.LBX"; // weak
_UNKNOWN unk_18227C; // weak
_UNKNOWN unk_182284; // weak
_UNKNOWN unk_18228C; // weak
_UNKNOWN unk_182298; // weak
_UNKNOWN unk_1822A0; // weak
_UNKNOWN unk_1822A8; // weak
_UNKNOWN unk_1822B0; // weak
int16_t word_1822B8[] = { 0 }; // weak
int16_t word_1822BA[32] =
{
  55,
  109,
  164,
  219,
  274,
  329,
  383,
  479,
  1,
  0,
  0,
  0,
  639,
  479,
  14,
  8,
  0,
  35,
  416,
  472,
  1,
  0,
  0,
  0,
  639,
  479,
  2,
  0,
  0,
  35,
  416,
  472
}; // weak
char *off_1822FA = "PLNTSUM.LBX"; // weak
int dword_1822FE = 0; // weak
int dword_182302 = 0; // weak
int16_t word_182306 = 0; // weak
int16_t word_182308 = 0; // weak
int16_t word_18230A = 0; // weak
int16_t word_18230C = 0; // weak
void (__noreturn *off_18230E)() = (void (__noreturn *)())&sub_10000; // weak (never called - see sub_10000 comment)
char *off_182314 = "SCORE.LBX"; // weak
char aMoise[6] = "Moise"; // weak
char byte_1823E0[] = { '\n' }; // weak
char byte_1823E1 = '\x14'; // weak
char byte_1823E2 = '\x1E'; // weak
char byte_1823E3 = '('; // weak
char byte_1823E4 = '2'; // weak
char byte_1823E5 = '<'; // weak
char byte_1823E6 = 'F'; // weak
char byte_1823E7 = 'P'; // weak
char byte_1823E8 = 'Z'; // weak
char byte_1823E9 = 'd'; // weak
int16_t word_182433 = 0; // weak
char byte_182435 = '\xA0'; // weak
char byte_182436 = '\xC0'; // weak
char byte_182437 = '\xE0'; // weak
char byte_182438 = '\0'; // weak
int16_t word_182439 = -1; // weak
int16_t word_18243B = -1; // weak
char byte_18243D = '\0'; // weak
char byte_18243E = '\0'; // weak
char byte_18243F[] = { '\0' }; // weak
char byte_182440 = '\0'; // weak
char byte_182441[2] = { '\0', '\0' }; // weak
int dword_182443 = 0; // weak
int dword_18246B = 0; // weak
int dword_18246F = 0; // weak
int16_t word_182473 = 0; // weak
int16_t word_182475 = 15; // weak
char byte_182477[8] = { '\x19', '.', '?', 'L', 'u', '\x9B', '\xC1', '\xD7' }; // weak
int16_t word_18247F = 0; // weak
int16_t word_182481 = 0; // weak
int16_t word_182483 = 0; // weak
char byte_182485[4] = { '\x1D', '4', 'G', 'V' }; // weak
int16_t word_182489 = 0; // weak
int16_t word_18248B = 0; // weak
char byte_18248D = '\0'; // weak
int16_t word_18248E = 0; // weak
int dword_182490[] = { 7 }; // weak
int dword_1824E0[] = { 80 }; // weak
int dword_182530[] = { 110 }; // weak
int dword_1825D0[] = { 90 }; // weak
int dword_182620[] = { 115 }; // weak
int dword_1826C0[] = { 95 }; // weak
int dword_182710[] = { 150 }; // weak
int dword_182760 = 0; // weak
_UNKNOWN unk_182765; // weak
_UNKNOWN unk_182795; // weak
_UNKNOWN unk_1827A1; // weak
_UNKNOWN unk_1827AD; // weak
_UNKNOWN unk_1827B5; // weak
char byte_1827BD = '\0'; // weak
char byte_1827BE = '\0'; // weak
char byte_1827BF = '\0'; // weak
int16_t word_1827C0[6] = { -1, -1, -1, -1, -1, 0 }; // weak
int16_t word_1827CC = 0; // weak
int16_t word_1827CE[] = { -1 }; // weak
int16_t word_1827D0 = 0; // weak
_UNKNOWN unk_1827D2; // weak
int16_t word_18283A = 0; // weak
int16_t word_18283C[54] =
{
  -1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
}; // weak
int16_t word_1828A8 = 0; // weak
int16_t word_1828AA[] = { -1 }; // weak
int16_t word_1828AC[] = { -1 }; // weak
int16_t word_1828AE[5] = { -1, -1, -1, -1, 0 }; // weak
int16_t word_1828B8 = 0; // weak
int16_t word_1828BA = -1; // weak
int16_t word_1828BC = -1; // weak
int16_t word_1828BE = -1000; // weak
_UNKNOWN unk_1828C0; // weak
int16_t word_1828CC = 0; // weak
char byte_1828CE = '\x03'; // weak
char byte_1828CF = '\x03'; // weak
char byte_1828D0 = '\0'; // weak
int16_t word_1828D1 = -1; // weak
_UNKNOWN unk_1828D3; // weak
_UNKNOWN unk_182913; // weak
_UNKNOWN unk_182953; // weak
int16_t word_182974 = -1; // weak
char byte_182976 = '\0'; // weak
char byte_182978 = '\0'; // weak
char aColonyLbx[11] = "COLONY.LBX"; // weak
char aColony2Lbx[12] = "COLONY2.LBX"; // weak
char aColveggiLbx[13] = "COLVEGGI.LBX"; // weak
char aRaceiconLbx[13] = "RACEICON.LBX"; // weak
char aColpupsLbx[12] = "COLPUPS.LBX"; // weak
char aPlanetsLbx[12] = "PLANETS.LBX"; // weak
char aAmebafinLbx[13] = "AMEBAFIN.LBX"; // weak
char aBeamsLbx[10] = "BEAMS.LBX"; // weak
char aCmbtsfxLbx_0[12] = "CMBTSFX.LBX"; // weak
char aColbldgLbx[12] = "COLBLDG.LBX"; // weak
char aColgcbtLbx[12] = "COLGCBT.LBX"; // weak
char aColroadsLbx[13] = "COLROADS.LBX"; // weak
char aColsumLbx[11] = "COLSUM.LBX"; // weak
char aColsysdiLbx[13] = "COLSYSDI.LBX"; // weak
char aDimtvfinLbx[13] = "DIMTVFIN.LBX"; // weak
char aFireptsLbx[12] = "FIREPTS.LBX"; // weak
char aMainpupsLbx[13] = "MAINPUPS.LBX"; // weak
char aNewgameLbx[12] = "NEWGAME.LBX"; // weak
char aPlntdfinLbx[13] = "PLNTDFIN.LBX"; // weak
char aRaceoptLbx_3[12] = "RACEOPT.LBX"; // weak
char aSphersfxLbx[13] = "SPHERSFX.LBX"; // weak
int16_t word_182AB7 = -1; // weak
int16_t word_182AB9 = 0; // weak
char byte_182ABB = '\0'; // weak
int16_t word_182ABC = -1; // weak
int16_t word_182ABE = -1; // weak
int16_t word_182AC0 = -1; // weak
int16_t word_182AC2 = -1; // weak
int16_t word_182AC4 = -1; // weak
int16_t word_182AC6 = -1; // weak
char byte_182AC8 = '\0'; // weak
char byte_182AC9 = '\x01'; // weak
char byte_182ACA = '\x01'; // weak
char byte_182ACB = '\0'; // weak
int16_t word_182ACC = -1; // weak
char byte_182ACE = '\0'; // weak
int16_t word_182ACF[] = { -1000 }; // weak
int16_t word_182AD1 = -1000; // weak
int16_t word_182AD3 = -1000; // weak
int16_t word_182AD5 = -1000; // weak
int16_t word_182AD7 = -1000; // weak
int16_t word_182AD9 = -1000; // weak
int16_t word_182ADB = -1000; // weak
int16_t word_182ADD = -1000; // weak
int16_t word_182ADF = 0; // weak
int16_t word_182AE1 = 0; // weak
int16_t word_182AE3 = 0; // weak
int16_t word_182AE5 = 0; // weak
int16_t word_182AE7 = 0; // weak
int16_t word_182AE9 = 0; // weak
int16_t word_182AEB = 0; // weak
int16_t word_182AED = 0; // weak
int16_t word_182AEF = 0; // weak
int16_t word_182AF1 = 0; // weak
int16_t word_182AF3 = 0; // weak
int16_t word_182AF5 = 0; // weak
int16_t word_182AF7 = 0; // weak
int16_t word_182AF9[2] = { -1000, -1000 }; // weak
int dword_182AFD[] = { 0 }; // weak
int dword_182B01[] = { 0 }; // weak
int dword_182B05 = 0; // weak
int dword_182B15 = 0; // weak
int dword_182B19 = 0; // weak
int dword_182B1D = 0; // weak
int dword_182B2D = 0; // weak
int dword_182B31 = 0; // weak
int dword_182B35 = 0; // weak
int dword_182B8D[19] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // weak
int dword_182BD9 = 0; // weak
int dword_182BDD = 0; // weak
int dword_182BE1 = 0; // weak
int dword_182BE5 = 0; // weak
int dword_182BE9 = 0; // weak
int dword_182BED = 0; // weak
int dword_182C05 = 0; // weak
int dword_182C0D = 0; // weak
int16_t word_182C1D = -1; // weak
int16_t word_182C1F = -1; // weak
_UNKNOWN unk_182C26; // weak
_UNKNOWN unk_182C2E; // weak
_UNKNOWN unk_182C36; // weak
_UNKNOWN unk_182C3E; // weak
_UNKNOWN unk_182C46; // weak
_UNKNOWN unk_182C56; // weak
int dword_182C96 = -1; // weak
int16_t word_182C9A = -1; // weak
int16_t word_182C9C[] = { 316 }; // weak
int dword_182E24[] = { 316 }; // weak
int dword_182E2C[96] =
{
  225,
  461,
  153,
  428,
  96,
  401,
  50,
  379,
  10,
  361,
  -21,
  348,
  406,
  461,
  316,
  430,
  242,
  404,
  182,
  381,
  130,
  363,
  88,
  346,
  53,
  333,
  480,
  430,
  391,
  403,
  317,
  381,
  255,
  362,
  204,
  348,
  158,
  334,
  121,
  322,
  539,
  403,
  454,
  382,
  380,
  363,
  319,
  348,
  264,
  335,
  219,
  322,
  180,
  312,
  587,
  382,
  505,
  363,
  434,
  348,
  372,
  334,
  318,
  323,
  271,
  312,
  232,
  303,
  629,
  364,
  549,
  349,
  479,
  335,
  419,
  323,
  367,
  314,
  318,
  303,
  277,
  295,
  666,
  351,
  586,
  336,
  517,
  324,
  459,
  313,
  409,
  304,
  360,
  295,
  320,
  288
}; // weak
int16_t word_1830CC = 0; // weak
int16_t word_1830CE = 0; // weak
int16_t word_1830D0 = 0; // weak
int dword_1830D2 = 0; // weak
int dword_1830D6 = 0; // weak
int dword_1830DA = 0; // weak
int dword_1830DE = 0; // weak
int16_t word_1830E2 = -1; // weak
int16_t word_1830E4 = -1; // weak
int16_t word_1830E6 = -1000; // weak
int16_t word_1830E8 = 0; // weak
int16_t word_1830EA = 0; // weak
int16_t word_1830EC = 0; // weak
int16_t word_1830EE = 0; // weak
int16_t word_1830F0 = 0; // weak
int16_t word_1830F2 = 0; // weak
int16_t word_1830F4 = 0; // weak
int16_t word_1830F6 = 0; // weak
int16_t word_1830F8 = 0; // weak
int16_t word_1830FA = 0; // weak
int16_t word_1830FC = 0; // weak
int16_t word_1830FE = 0; // weak
int16_t word_183100 = 0; // weak
int16_t word_183102 = 0; // weak
int16_t word_183104 = 0; // weak
int dword_183106[] = { 0 }; // weak
int dword_18310A = 0; // weak
int dword_18310E = 0; // weak
int dword_183112 = 0; // weak
int dword_183116 = 0; // weak
int dword_18311A = 0; // weak
int dword_18311E = 0; // weak
int dword_183122 = 0; // weak
int dword_183126 = 0; // weak
int dword_18312A = 0; // weak
int dword_18312E = 0; // weak
int dword_183132[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // weak
int16_t word_18315A = 0; // weak
int16_t word_18315C = 0; // weak
char byte_18315F = '\0'; // weak
char byte_183160[36] =
{
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x01'
}; // weak
char byte_183184 = '\0'; // weak
int dword_183188 = 0; // weak
int dword_18318C = 0; // weak
int dword_183190 = 0; // weak
int dword_183194 = 0; // weak
char byte_183198 = '\0'; // weak
char byte_18319C = '\0'; // weak
char byte_18319D = '\n'; // weak
char byte_18319E = '\0'; // weak
int16_t word_18319F = 0; // weak
int16_t word_1831A1 = 0; // weak
char byte_1831A4 = '\0'; // weak
char byte_1831A5 = '\0'; // weak
int16_t word_1831A8 = 0; // weak
int16_t word_1831AC = -1; // weak
char byte_1831AE = '\0'; // weak
int16_t word_1831B0 = -1; // weak
int dword_1831B2 = 0; // weak
char byte_1831B6 = '\0'; // weak
_UNKNOWN unk_1831B7; // weak
int16_t word_1831C0 = 0; // weak
int16_t word_1831C2 = 0; // weak
char byte_1831C4 = '\x01'; // weak
char byte_1831C5 = '\0'; // weak
int16_t word_1831C6 = -1; // weak
int16_t word_1831C8 = 0; // weak
char byte_1831CA = '\0'; // weak
char byte_1831CB = '\0'; // weak
int16_t word_1831CC = 0; // weak
int16_t word_1831CE = -1; // weak
int16_t word_1831D0 = -1; // weak
int16_t word_1831D4 = 15; // weak
int16_t word_1831D6 = 5; // weak
int dword_1831DC = 0; // weak
int dword_1831E0 = 0; // weak
int dword_1831E4 = 0; // weak
int dword_1831E8 = 0; // weak
int dword_1831EC = 0; // weak
_UNKNOWN unk_1831F0; // weak
int16_t word_18348E = 551; // weak
int dword_183550 = 0; // weak
_UNKNOWN *off_183554 = &unk_1A8B34; // weak
_UNKNOWN *off_183558 = &unk_1A74B4; // weak
int (*funcs_DDFF0[3])() = { &sub_DE0C6, &sub_DED47, &sub_DFE77 }; // weak
int dword_183568 = 0; // weak
char byte_18356C = '\0'; // weak
int dword_18356D = 0; // weak
char byte_183571 = '\0'; // weak
int dword_183572 = 0; // weak
char byte_183576 = '\0'; // weak
char byte_183578 = '\0'; // weak
char byte_183579 = '\0'; // weak
_UNKNOWN unk_183580; // weak
char a1200[5] = "1200"; // weak
char byte_183608 = '\0'; // weak
char byte_183609 = '\0'; // weak
char byte_18360A = '\0'; // weak
int dword_18360C[30] =
{
  0,
  1,
  3,
  6,
  12,
  22,
  36,
  62,
  102,
  172,
  292,
  492,
  812,
  1372,
  2372,
  3972,
  6372,
  9972,
  10400,
  10800,
  11200,
  11600,
  12000,
  12400,
  12800,
  13200,
  13600,
  14000,
  14400,
  14800
}; // weak
char byte_183684[7] = { '\0', '\x01', '\x01', '\x01', '\x02', '\x03', '\x03' }; // weak
_UNKNOWN unk_1836A0; // weak
_UNKNOWN unk_1836B4; // weak
_UNKNOWN unk_1836B8; // weak
_UNKNOWN unk_1836BC; // weak
_UNKNOWN unk_1836C8; // weak
_UNKNOWN unk_1836CC; // weak
_UNKNOWN unk_1836D0; // weak
_UNKNOWN unk_1836F0; // weak
_UNKNOWN unk_18386C; // weak
_UNKNOWN unk_18386E; // weak
char *off_183871[21] =
{
  "th",
  "st",
  "nd",
  "rd",
  "th",
  "th",
  "th",
  "th",
  "th",
  "th",
  "zeroeth",
  "first",
  "second",
  "third",
  "fourth",
  "fifth",
  "sixth",
  "seventh",
  "eighth",
  "ninth",
  "tenth"
}; // weak
char *off_183899[11] =
{
  "zeroeth",
  "first",
  "second",
  "third",
  "fourth",
  "fifth",
  "sixth",
  "seventh",
  "eighth",
  "ninth",
  "tenth"
}; // weak
char aFrtxyshvpimoc[16] = "FRTXYSHVPIMOC^="; // weak
char a1234567890[14] = "1234567890+- "; // weak
int16_t word_1838F7 = 0; // weak
int16_t word_1838F9[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // weak
char byte_18390D[8] = { '\x05', '\a', '\n', '\v', '\x0E', '\x13', '\0', '\0' }; // weak
char byte_183915[9] = { '\x01', '\x02', '\x04', '\b', '\f', '\r', '\x10', ' ', '\x1D' }; // weak
char byte_18391E[26] =
{
  '\x01',
  '\x03',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x03',
  '\x01',
  '\0',
  '\0',
  '\0',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x03',
  '\x01',
  '\x03',
  '\0',
  '\0',
  '\0'
}; // weak
_UNKNOWN *off_183B0E = &unk_183938; // weak
_UNKNOWN unk_183B1E; // weak
char byte_183B24 = '\xB9'; // weak
_UNKNOWN unk_183B26; // weak
_UNKNOWN unk_183B2E; // weak
char byte_183B36 = '\xB2'; // weak
_UNKNOWN *off_183B77 = &unk_183B46; // weak
_UNKNOWN *off_183BCB = &unk_183B93; // weak
_UNKNOWN unk_183BE7; // weak
char byte_183C27[] = { '\x15' }; // weak
char byte_183C28[9] = { '2', '\x15', 'M', '\x15', 'f', '\x15', '\x80', '\x15', '\x9A' }; // weak
int16_t word_183C31[] = { 216 }; // weak
int16_t word_183C33[7] = { 427, 318, 427, 373, 427, 438, 427 }; // weak
_UNKNOWN unk_183C41; // weak
int16_t word_183C63[34] =
{
  218,
  60,
  425,
  413,
  -20045,
  -19279,
  -19790,
  -20302,
  -20048,
  15361,
  25600,
  26626,
  -19712,
  -20047,
  -19788,
  -19790,
  -20304,
  433,
  114,
  612,
  254,
  -20045,
  -19279,
  -19790,
  -20302,
  -20048,
  2049,
  25601,
  -25342,
  -19711,
  -20047,
  -19788,
  -19790,
  -20304
}; // weak
int16_t word_183CA7[34] =
{
  223,
  60,
  410,
  230,
  -20045,
  -19279,
  -19790,
  -20302,
  -23632,
  15361,
  24064,
  -6654,
  -19712,
  -20047,
  -19788,
  -19790,
  -20304,
  223,
  243,
  410,
  413,
  -20045,
  -19279,
  -19790,
  -20302,
  -23632,
  -3327,
  24064,
  -25342,
  -19711,
  -20047,
  -19788,
  -19790,
  -20304
}; // weak
int16_t word_183CEB[8] = { 218, 60, 612, 414, -20045, -19279, -19790, -20302 }; // weak
_UNKNOWN unk_183CFC; // weak
int16_t word_183D40[17] =
{
  218,
  60,
  610,
  86,
  -20045,
  -19279,
  -19790,
  -20302,
  -9552,
  23808,
  25088,
  -24574,
  -19711,
  -20047,
  -19788,
  -19790,
  -20304
}; // weak
int16_t word_183D62[8] = { 218, 60, 613, 86, -20045, -19279, -19790, -20302 }; // weak
_UNKNOWN unk_183D73; // weak
char byte_183D95[10] = { '\a', '\x03', '\x03', '\x03', '\x03', '\x05', '\x03', '\x03', '\x03', '\x03' }; // weak
int16_t word_183D9F[] = { 233 }; // weak
int16_t word_183E0D[4] = { 9164, 8374, 6952, 12640 }; // weak
_UNKNOWN unk_183E15; // weak
int16_t word_183E55 = 0; // weak
int16_t word_183E57[] = { 226 }; // weak
int16_t word_183E5F[] = { 64 }; // weak
_UNKNOWN unk_183EA3; // weak
int dword_183EB9 = 0; // weak
_UNKNOWN *off_183ECF = &unk_183B1E; // weak
_UNKNOWN unk_183EE7; // weak
char byte_183EFC = '\0'; // weak
int dword_183EFD = 0; // weak
_UNKNOWN unk_183F3A; // weak
char byte_183F42 = '\0'; // weak
_UNKNOWN unk_183F43; // weak
char byte_183F64[26] =
{
  'J',
  'H',
  'D',
  'B',
  '>',
  '<',
  '8',
  '6',
  '2',
  '0',
  ',',
  '*',
  '&',
  '$',
  ' ',
  '\x1E',
  '\x1A',
  '\x18',
  '\x14',
  '\x12',
  '\x0E',
  '\f',
  '\b',
  '\x06',
  '\x02',
  '\0'
}; // weak
char byte_183F7E[17] =
{
  '\t',
  '\x15',
  '!',
  '-',
  '9',
  'E',
  'Q',
  ']',
  'k',
  'w',
  '\x83',
  '\x8F',
  '\x9B',
  '\xA7',
  '\xB3',
  '\xBF',
  '\xFF'
}; // weak
_UNKNOWN unk_183F8F; // weak
int16_t word_183FF1[] = { 21 }; // weak
int16_t word_183FF3[13] = { 49, 21, 156, 21, 262, 21, 369, 544, 50, 544, 157, 544, 262 }; // weak
int16_t word_18400D[] = { 105 }; // weak
int16_t word_18400F[13] = { 49, 105, 155, 105, 262, 105, 370, 528, 49, 528, 156, 528, 261 }; // weak
int16_t word_184029[7] = { 96, 96, 96, 96, 520, 520, 520 }; // weak
int16_t word_184037[] = { 125 }; // weak
int16_t word_184039[13] = { 50, 125, 157, 125, 262, 125, 366, 333, 50, 333, 157, 333, 262 }; // weak
int16_t word_184053[] = { 121 }; // weak
int16_t word_184055[] = { 98 }; // weak
int16_t word_18406F[] = { 120 }; // weak
int16_t word_184071[] = { 126 }; // weak
int16_t word_18408B = 332; // weak
int16_t word_18408D = 392; // weak
int16_t word_18408F = 613; // weak
int16_t word_184091 = 415; // weak
int16_t word_184093 = 24; // weak
int dword_184095 = 0; // weak
int16_t word_184099 = 0; // weak
int16_t word_18409B = 0; // weak
int16_t word_18409D = 186; // weak
int16_t word_18409F = 24; // weak
int16_t word_1840A1 = 25; // weak
int (*off_1840A3)() = &sub_10CDC1; // weak
_UNKNOWN unk_1840A7; // weak
_UNKNOWN unk_1840AF; // weak
char byte_1840B7[8] = { 'C', '\x8B', '\x93', '&', '=', '_', 'j', '/' }; // weak
char byte_1840BF[8] = { 'F', '\x8A', '\x95', '#', ';', '`', 'n', '1' }; // weak
char byte_1840C7[9] = { 'H', 'a', '\x96', '\x1A', '9', 't', '\x9E', 'I', '\0' }; // weak
char aScienceLbx[12] = "SCIENCE.LBX"; // weak
char aSrRScLbx[13] = "SR_R?_SC.LBX"; // weak
_UNKNOWN unk_18413C; // weak
_UNKNOWN unk_184144; // weak
int16_t word_18414C[6] = { 6, 21, 37, 60, 85, 100 }; // weak
int16_t word_184158[6] = { 6, 20, 37, 58, 85, 100 }; // weak
int16_t word_184164[5] = { 373, 349, 320, 283, 239 }; // weak
int16_t word_18416E[5] = { 203, 179, 149, 113, 69 }; // weak
char aTechselLbx[12] = "TECHSEL.LBX"; // weak
char aF3[] = "\aF3."; // idb
int dword_1841B5[8] = { 1966256, 2032019, 8847536, 8847763, 15728816, 15729043, 22741168, 22741395 }; // weak
int dword_1841D5[8] = { 1966175, 2031938, 8847455, 8847682, 15728735, 15728962, 22741087, 22741314 }; // weak
int16_t word_1841F5[4] = { 0, 34, 49, 64 }; // weak
int16_t word_1841FD[4] = { 33, 48, 63, 78 }; // weak
int16_t word_184205[5] = { 19, 34, 49, 64, 79 }; // weak
int16_t word_18420F[8] = { 205, 6, 205, 6, 205, 6, 205, 6 }; // weak
int16_t word_18421F[] = { 21 }; // weak
int16_t word_184221[15] = { 30, 248, 31, 21, 135, 248, 135, 21, 240, 248, 240, 21, 347, 248, 347 }; // weak
char byte_18423F[8] = { '\x04', '\x02', '\x06', '\b', '\a', '\x01', '\x03', '\x05' }; // weak
_UNKNOWN unk_184247; // weak
_UNKNOWN unk_18426F; // weak
int16_t word_184297 = 0; // weak
int dword_1842AD = 0; // weak
char byte_1842BE = '\xFF'; // weak
char aNrqqqrrsnutstt[17] = "nrqqqrrsnutsttuv"; // weak
_UNKNOWN unk_184324; // weak
int dword_18433A = 0; // weak
char *off_184350[5] =
{
  "nrqqqrrsnutsttuv",
  "nrqqqrrsnutsttuv",
  "nrqqqrrsnutsttuv",
  "nrqqqrrsnutsttuv",
  "nrqqqrrsnutsttuv"
}; // weak
int16_t flagMemPoolReady_184374 = 0; // weak
int dword_184378 = 0; // weak
int dword_184380 = 0; // weak
int dword_184384 = 0; // weak
int dword_184388 = 0; // weak
int dword_18438C = 0; // weak
int dword_184394 = 0; // weak
int dword_184398 = 0; // weak
int dword_18439C = 0; // weak
int dword_1843A0 = 0; // weak
char byte_1843A4 = '\x7F'; // weak
char byte_1843A5 = '@'; // weak
char byte_1843A6 = '\x7F'; // weak
int dword_1843A7 = 127; // weak
int dword_1843AB = 0; // weak
char aSoundLbx[10] = "sound.lbx"; // weak
char aMusicLbx[10] = "music.lbx"; // weak
char aStreamLbx_0[11] = "stream.lbx"; // weak
int dword_184427 = 0; // weak
int dword_18442B = 0; // weak
int dword_18442F = 0; // weak
int dword_184433 = 0; // weak
int dword_184437 = 0; // weak
int dword_18443B = 0; // weak
int dword_18443F = 0; // weak
int dword_184443 = 0; // weak
int dword_184447 = 0; // weak
int dword_18444B = 100; // weak
int dword_18444F = -1; // weak
int dword_184453 = 1; // weak
int dword_184457 = 0; // weak
int dword_18445B = 0; // weak
int dword_184460 = 0; // weak
char aTooManyFields[16] = "Too many fields"; // weak
char byte_184474 = '\0'; // weak
int16_t word_184475 = 3; // weak
char byte_184479 = '\x01'; // weak
int dword_18447A = -1; // weak
int16_t word_18447E = 250; // weak
_UNKNOWN *off_184480 = &unk_1B0848; // weak
_UNKNOWN *off_184484 = &unk_1B0848; // weak
int (*dword_184488)(_DWORD) = NULL; // weak
int16_t word_18448C = 0; // weak
int dword_18448E = -65536; // weak
int dword_184492 = -65535; // weak
_UNKNOWN *off_184496 = (_UNKNOWN *)0x20000; // weak (was &loc_20000 - see sub_10000 comment, same false-positive-address class)
_UNKNOWN unk_18449A; // weak
_UNKNOWN unk_1844A4; // weak
int16_t word_1844A6 = 0; // weak
int16_t word_1844A8 = 1; // weak
int16_t word_1844B0 = 0; // weak
_UNKNOWN *off_1844B2 = &loc_E0000; // weak
int16_t word_1844B6 = 180; // weak
int dword_1844C2 = 0; // weak
int dword_1844C6 = 0; // weak
int16_t word_1844CA = 0; // weak
int16_t word_1844CC = 0; // weak
int dword_1844CE = -65536; // weak
int16_t word_1844D8 = 0; // weak
int16_t word_1844DA = 0; // weak
int16_t word_1844DC = 0; // weak
int16_t word_1844DE = 0; // weak
int16_t word_1844E0 = 0; // weak
int16_t word_1844E2 = 0; // weak
int16_t word_1844E4 = 1; // weak
int dword_1844E6 = 1; // weak
char byte_1844EC[] = { '\0' }; // weak
int16_t word_18450C = 0; // weak
int16_t word_18450E = 0; // weak
int dword_184510 = 1; // weak
int dword_184514 = 0; // weak
int16_t word_184518 = 1; // weak
int dword_18451A = 0; // weak
int16_t word_18451E = 0; // weak
int16_t word_184520 = 0; // weak
_UNKNOWN unk_184522; // weak
int16_t word_18452A = 0; // weak
int16_t word_18452C = 0; // weak
int64_t qword_184530 = 2748779069440LL; // weak
// VLNA 11: drive "_UNKNOWN unk_184538" (= char!) - vyska obrazovky
// (200/240/480 dle rezimu, viz sub_1248AB). Jako char se 480 orezalo na
// -32 a soucin vyska*sirka vysel -20480 -> "Insufficient Memory!" pri
// alokaci VGA bufferu. Puvodni sirka dat: 4 bajty (0x184538..0x18453C).
int32_t screenHeight_184538; // weak
int dword_18453C = 307200; // weak
int dword_184540 = 0; // weak
char byte_184544[50] =
{
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
int dword_184576 = 0; // weak
int dword_184580 = 0; // weak
char *off_1845D4 = "Resource deadlock would occur"; // weak
int16_t word_1845D8 = 0; // weak
int16_t word_1845DA = 0; // weak
int dword_1845DC = 0; // weak
int dword_1845E0 = 0; // weak
int dword_1845E8 = 0; // weak
int dword_1845EC = -1; // weak
int dword_1845F0 = 0; // weak
int dword_1845F4 = 0; // weak
int dword_184608 = 0; // weak
int16_t word_184612 = 0; // weak
int16_t word_184614 = 0; // weak
int16_t word_184616 = 0; // weak
int16_t word_18462A = 0; // weak
int dword_18464C = 0; // weak
int dword_184650 = 1; // weak
char byte_184654 = '\0'; // weak
int dword_184668 = 0; // weak
int dword_18466C = 0; // weak
int16_t word_184670[] = { 0 }; // weak
int16_t word_184672[] = { -1 }; // weak
int16_t word_184674[] = { 0 }; // weak
int16_t word_184676[] = { 1 }; // weak
int16_t word_184678[] = { -1 }; // weak
int16_t word_18467A[] = { -1 }; // weak
int16_t word_18467C[] = { -1 }; // weak
int16_t word_18467E[] = { 1 }; // weak
int16_t word_184680[] = { -1 }; // weak
int16_t word_184682[] = { -2 }; // weak
int16_t word_184684[] = { -1 }; // weak
int16_t word_184686[181] =
{
  2,
  -1,
  -1,
  0,
  1,
  -1,
  0,
  -1,
  1,
  -2,
  -1,
  -1,
  2,
  -1,
  0,
  1,
  0,
  -1,
  0,
  0,
  1,
  1,
  1,
  -1,
  -1,
  -1,
  0,
  1,
  1,
  -1,
  1,
  0,
  1,
  -2,
  1,
  1,
  2,
  -1,
  0,
  0,
  1,
  -1,
  1,
  1,
  1,
  -2,
  1,
  2,
  1,
  1,
  0,
  -1,
  1,
  1,
  1,
  0,
  1,
  2,
  1,
  -1,
  2,
  1,
  0,
  -1,
  0,
  1,
  0,
  0,
  1,
  -1,
  1,
  1,
  -1,
  1,
  -1,
  0,
  1,
  1,
  0,
  1,
  1,
  2,
  -1,
  1,
  2,
  0,
  -1,
  0,
  1,
  1,
  -1,
  1,
  1,
  1,
  -2,
  1,
  2,
  1,
  1,
  0,
  -1,
  1,
  0,
  1,
  -1,
  2,
  1,
  1,
  -2,
  1,
  0,
  -1,
  0,
  1,
  0,
  0,
  -1,
  -1,
  -1,
  1,
  1,
  1,
  0,
  -1,
  -1,
  1,
  -1,
  0,
  -1,
  2,
  -1,
  -1,
  -2,
  1,
  0,
  -1,
  -1,
  -1,
  -1,
  1,
  -1,
  2,
  -1,
  -1,
  -2,
  -1,
  0,
  1,
  -1,
  -1,
  -1,
  0,
  -1,
  -2,
  -1,
  1,
  -2,
  -1,
  0,
  1,
  0,
  -1,
  0,
  0,
  -1,
  1,
  -1,
  -1,
  1,
  -1,
  1,
  0,
  -1,
  -1,
  0,
  -1,
  -1,
  -2,
  1,
  -1,
  -2
}; // weak
int16_t word_1847F0[] = { 0 }; // weak
int16_t word_1847F2[] = { 1 }; // weak
int16_t word_1847F4[] = { 0 }; // weak
int16_t word_1847F6[] = { -1 }; // weak
int16_t word_1847F8[] = { 1 }; // weak
int16_t word_1847FA[] = { -1 }; // weak
int16_t word_1847FC[] = { 1 }; // weak
int16_t word_1847FE[] = { 1 }; // weak
int16_t word_184800[] = { 1 }; // weak
int16_t word_184802[] = { 2 }; // weak
int16_t word_184804[] = { 1 }; // weak
int16_t word_184806[181] =
{
  -2,
  0,
  -1,
  1,
  1,
  1,
  0,
  1,
  -1,
  1,
  -2,
  2,
  1,
  -1,
  0,
  1,
  0,
  1,
  0,
  0,
  -1,
  1,
  1,
  -1,
  -1,
  -1,
  -1,
  1,
  0,
  1,
  -1,
  0,
  -1,
  -1,
  -2,
  2,
  -1,
  -1,
  -1,
  1,
  0,
  -1,
  -1,
  1,
  -1,
  -1,
  -2,
  2,
  -1,
  1,
  -1,
  -1,
  0,
  -1,
  -1,
  0,
  -1,
  1,
  -2,
  -2,
  -1,
  1,
  0,
  -1,
  0,
  -1,
  0,
  0,
  -1,
  -1,
  1,
  1,
  -1,
  0,
  -1,
  -1,
  1,
  -1,
  0,
  -1,
  -1,
  -1,
  -2,
  -2,
  1,
  0,
  1,
  0,
  -1,
  -1,
  -1,
  -1,
  1,
  -1,
  2,
  -1,
  -2,
  0,
  1,
  -1,
  -1,
  -1,
  0,
  -1,
  1,
  -1,
  2,
  -2,
  -1,
  1,
  0,
  -1,
  0,
  -1,
  0,
  0,
  1,
  -1,
  -1,
  1,
  1,
  1,
  1,
  -1,
  0,
  -1,
  1,
  0,
  1,
  1,
  2,
  -2,
  1,
  0,
  1,
  -1,
  0,
  -1,
  1,
  1,
  1,
  2,
  1,
  -2,
  1,
  -1,
  1,
  1,
  0,
  1,
  1,
  0,
  1,
  -1,
  2,
  2,
  1,
  -1,
  0,
  1,
  0,
  1,
  0,
  0,
  1,
  1,
  -1,
  -1,
  1,
  0,
  1,
  1,
  -1,
  1,
  0,
  1,
  1,
  1,
  2,
  2,
  -1
}; // weak
int dword_18497C = 0; // weak
char byte_184980 = '\0'; // weak
int dword_184984 = 0; // weak
int dword_184988 = 0; // weak
int16_t word_18498C = 0; // weak
int dword_18498E = 0; // weak
int16_t word_184992 = 0; // weak
int dword_184994 = 0; // weak
int dword_184998 = 0; // weak
int dword_18499C = 1; // weak
int dword_1849A0 = 0; // weak
int dword_1849A4 = 0; // weak
int dword_1849A8 = 0; // weak
int dword_1849AC = 0; // weak
int16_t word_1849B0 = 0; // weak
int dword_1849B2 = 0; // weak
int dword_1849B6 = 0; // weak
int dword_1849BA = 0; // weak
int dword_1849BE = 0; // weak
int dword_1849C2 = 0; // weak
int dword_1849C6 = 1; // weak
int dword_1849CA = 0; // weak
int dword_1849CE = 0; // weak
int dword_1849D2 = 0; // weak
int dword_1849D6 = 0; // weak
int dword_1849DA = 0; // weak
int dword_1849DE = 0; // weak
int dword_1849E2 = 0; // weak
int dword_1849E6 = 0; // weak
int16_t word_1849EE = 0; // weak
int dword_184A00 = 0; // weak
int dword_184A04 = 0; // weak
char byte_184A22 = '\0'; // weak
int16_t word_184A34 = 0; // weak
int dword_184A54 = 0; // weak
int dword_184A58 = 15; // weak
int dword_184A5C[19] = { 0, 0, 0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 9, 10, 11, 12, 13, 14 }; // weak
int dword_184AA8[19] = { 0, 2, 4, 6, 8, 10, 11, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // weak
_UNKNOWN unk_184AF4; // weak
int dword_184B00[4096] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  268435457,
  268435457,
  268435457,
  268435457,
  268435457,
  268435457,
  268435457,
  268435457,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  268435457,
  268435457,
  268505089,
  269553921,
  269553921,
  268505089,
  268435457,
  268435457,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17830144,
  286331152,
  286331152,
  286331152,
  286331152,
  17895680,
  1118208,
  65536,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  65536,
  1118208,
  17895680,
  286331152,
  17895680,
  1118208,
  65536,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  1118464,
  286261521,
  286261521,
  286261521,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  17895696,
  286331153,
  286331153,
  17895696,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  1118464,
  1118464,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286261521,
  285212689,
  285212689,
  285212689,
  286261521,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  0,
  0,
  0,
  0,
  0,
  1118464,
  17826064,
  16777232,
  16777232,
  17826064,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69904,
  4368,
  69648,
  1114128,
  17895424,
  285217024,
  285217024,
  285217024,
  285217024,
  17895424,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  17826064,
  17826064,
  17826064,
  17826064,
  1118464,
  69632,
  17895696,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895697,
  17825809,
  17895697,
  17825809,
  17825809,
  17825809,
  17825809,
  17826065,
  286261521,
  286261520,
  285212672,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  285282321,
  1118464,
  286261521,
  1118464,
  285282321,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  268435456,
  285212672,
  286261248,
  286326784,
  286330880,
  286331152,
  286330880,
  286326784,
  286261248,
  285212672,
  268435456,
  0,
  0,
  0,
  0,
  0,
  16,
  272,
  4368,
  69904,
  1118480,
  286331152,
  1118480,
  69904,
  4368,
  272,
  16,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  17895696,
  69632,
  69632,
  69632,
  17895696,
  1118464,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  0,
  17826064,
  17826064,
  0,
  0,
  0,
  0,
  0,
  0,
  17895697,
  285282321,
  285282321,
  285282321,
  17895441,
  69649,
  69649,
  69649,
  69649,
  69649,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  17825792,
  1118208,
  17830144,
  285212944,
  285212944,
  17830144,
  1118208,
  4352,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  286331152,
  286331152,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  17895696,
  69632,
  69632,
  69632,
  17895696,
  1118464,
  69632,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  17895696,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  17895696,
  1118464,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  4352,
  286331152,
  4352,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1114112,
  17825792,
  286331152,
  17825792,
  1114112,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285212672,
  285212672,
  285212672,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1052672,
  17830144,
  286331152,
  17830144,
  1052672,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  65536,
  1118208,
  1118208,
  17895680,
  17895680,
  286331152,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  286331152,
  17895680,
  17895680,
  1118208,
  1118208,
  65536,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  1118464,
  1118464,
  69632,
  69632,
  69632,
  0,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  17826064,
  17826064,
  17826064,
  1048832,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17830144,
  17830144,
  286331152,
  17830144,
  17830144,
  17830144,
  286331152,
  17830144,
  17830144,
  0,
  0,
  0,
  0,
  69632,
  69632,
  17895680,
  285212944,
  285212688,
  285212672,
  17895680,
  272,
  272,
  268435728,
  285212944,
  17895680,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  285212688,
  285212944,
  4352,
  69632,
  1114112,
  17825792,
  285212944,
  268435728,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  17830144,
  1118208,
  17891600,
  285282560,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  1114112,
  1114112,
  1114112,
  17825792,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4352,
  69632,
  1114112,
  1114112,
  1114112,
  1114112,
  1114112,
  1114112,
  69632,
  4352,
  0,
  0,
  0,
  0,
  0,
  0,
  1114112,
  69632,
  4352,
  4352,
  4352,
  4352,
  4352,
  4352,
  69632,
  1114112,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17826064,
  1118464,
  286331153,
  1118464,
  17826064,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  17895696,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  69632,
  1114112,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  16,
  272,
  4352,
  69632,
  1114112,
  17825792,
  285212672,
  268435456,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285217040,
  285282576,
  286327056,
  286261520,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118208,
  17895424,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  272,
  4352,
  69632,
  1114112,
  17825792,
  285212672,
  285212944,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  272,
  272,
  1118464,
  272,
  272,
  272,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  4352,
  69888,
  1118464,
  17830144,
  285217024,
  286331152,
  4352,
  4352,
  4352,
  69904,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  285212672,
  285212672,
  285212672,
  286331136,
  272,
  272,
  272,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17825792,
  285212672,
  285212672,
  286331136,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  285212944,
  272,
  272,
  4352,
  69632,
  1114112,
  1114112,
  1114112,
  1114112,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  17895696,
  272,
  272,
  272,
  4352,
  17895424,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  0,
  0,
  0,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  0,
  0,
  0,
  69632,
  69632,
  1114112,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  272,
  4352,
  69632,
  1114112,
  17825792,
  1114112,
  69632,
  4352,
  272,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  0,
  0,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17825792,
  1114112,
  69632,
  4352,
  272,
  4352,
  69632,
  1114112,
  17825792,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  4352,
  69632,
  69632,
  69632,
  0,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285282576,
  285282576,
  285282576,
  285282560,
  285212672,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  285212944,
  285212944,
  286331152,
  285212944,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  286331136,
  17826064,
  17826064,
  17826064,
  17895680,
  17826064,
  17826064,
  17826064,
  17826064,
  286331136,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  17826064,
  285212688,
  285212672,
  285212672,
  285212672,
  285212672,
  285212688,
  17826064,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  286330880,
  17830144,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17830144,
  286330880,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  17826064,
  17825808,
  17829888,
  17895424,
  17829888,
  17825792,
  17825808,
  17826064,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  17826064,
  17825808,
  17829888,
  17895424,
  17829888,
  17825792,
  17825792,
  17825792,
  286326784,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  17826064,
  285212688,
  285212672,
  285212672,
  285282576,
  285212944,
  285212944,
  17826064,
  1118224,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  285212944,
  285212944,
  285212944,
  286331152,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  69904,
  4352,
  4352,
  4352,
  4352,
  4352,
  285217024,
  285217024,
  285217024,
  17895424,
  0,
  0,
  0,
  0,
  0,
  0,
  286261520,
  17826064,
  17826064,
  17830144,
  17895424,
  17895424,
  17830144,
  17826064,
  17826064,
  286261520,
  0,
  0,
  0,
  0,
  0,
  0,
  286326784,
  17825792,
  17825792,
  17825792,
  17825792,
  17825792,
  17825792,
  17825808,
  17826064,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  286265616,
  286331152,
  286331152,
  285278480,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  286261520,
  286327056,
  286331152,
  285282576,
  285217040,
  285212944,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  286331136,
  17826064,
  17826064,
  17826064,
  17895680,
  17825792,
  17825792,
  17825792,
  17825792,
  286326784,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285278480,
  285282576,
  17895680,
  4352,
  4368,
  0,
  0,
  0,
  0,
  286331136,
  17826064,
  17826064,
  17826064,
  17895680,
  17830144,
  17826064,
  17826064,
  17826064,
  286261520,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  17825792,
  1118208,
  4352,
  272,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  17895696,
  16846864,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17830144,
  1118208,
  65536,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  285212944,
  285212944,
  285212944,
  285278480,
  285278480,
  285278480,
  286331152,
  286265616,
  17830144,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  285212944,
  17830144,
  17895680,
  1118208,
  1118208,
  17895680,
  17830144,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  17826064,
  17826064,
  17826064,
  17826064,
  1118464,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  285212944,
  268435728,
  4352,
  69632,
  1114112,
  17825792,
  285212688,
  285212944,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  1114112,
  1114112,
  1114112,
  1114112,
  1114112,
  1114112,
  1114112,
  1114112,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  268435456,
  285212672,
  286261248,
  17891328,
  1118208,
  69888,
  4368,
  272,
  16,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  4352,
  4352,
  4352,
  4352,
  4352,
  4352,
  4352,
  4352,
  1118464,
  0,
  0,
  0,
  0,
  65536,
  1118208,
  17830144,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  0,
  0,
  1114112,
  1114112,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895424,
  4352,
  17895680,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  286261248,
  17825792,
  17825792,
  17895424,
  17830144,
  17826064,
  17826064,
  17826064,
  17826064,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212672,
  285212672,
  285212672,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  69888,
  4352,
  4352,
  1118464,
  17830144,
  285217024,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  286331152,
  285212672,
  285212672,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  17826048,
  17825792,
  286326784,
  17825792,
  17825792,
  17825792,
  17825792,
  286326784,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17891600,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  17895680,
  4352,
  285217024,
  17895424,
  0,
  0,
  0,
  286261248,
  17825792,
  17825792,
  17830144,
  17891600,
  17826064,
  17826064,
  17826064,
  17826064,
  286261520,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  0,
  1118208,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  272,
  272,
  0,
  4368,
  272,
  272,
  272,
  272,
  272,
  272,
  17826064,
  17826064,
  1118464,
  0,
  0,
  0,
  286261248,
  17825792,
  17825792,
  17826064,
  17830144,
  17895424,
  17895424,
  17830144,
  17826064,
  286261520,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286265600,
  286331152,
  285278480,
  285278480,
  285278480,
  285278480,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285282560,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285282560,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17895680,
  17825792,
  17825792,
  286326784,
  0,
  0,
  0,
  0,
  0,
  0,
  17891600,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  17895680,
  4352,
  4352,
  69904,
  0,
  0,
  0,
  0,
  0,
  0,
  285282560,
  17891600,
  17826064,
  17825792,
  17825792,
  17825792,
  286326784,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  17825792,
  1118208,
  4352,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  65536,
  1114112,
  1114112,
  286331136,
  1114112,
  1114112,
  1114112,
  1114112,
  1114384,
  69888,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  1118464,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  285212944,
  285278480,
  285278480,
  285278480,
  286331152,
  17830144,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  17830144,
  1118208,
  1118208,
  1118208,
  17830144,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895696,
  272,
  4352,
  286330880,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  285217024,
  69632,
  1114112,
  17825792,
  285212944,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  4368,
  69632,
  69632,
  69632,
  17891328,
  69632,
  69632,
  69632,
  69632,
  4368,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  69632,
  69632,
  0,
  69632,
  69632,
  69632,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  17891328,
  69632,
  69632,
  69632,
  4368,
  69632,
  69632,
  69632,
  69632,
  17891328,
  0,
  0,
  0,
  0,
  0,
  0,
  17891600,
  285282560,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  65536,
  1118208,
  17830144,
  285212944,
  285212944,
  285212944,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  17826064,
  285212688,
  285212672,
  285212672,
  285212672,
  285212688,
  17826064,
  1118464,
  4352,
  272,
  17895680,
  0,
  0,
  0,
  0,
  285217024,
  0,
  0,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  4352,
  69632,
  1114112,
  0,
  17895680,
  285212944,
  286331152,
  285212672,
  285212672,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  65536,
  1118208,
  17830144,
  0,
  17895424,
  4352,
  17895680,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  285217024,
  0,
  0,
  17895424,
  4352,
  17895680,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  17825792,
  1114112,
  69632,
  0,
  17895424,
  4352,
  17895680,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  1118208,
  0,
  17895424,
  4352,
  17895680,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118464,
  17826064,
  17825792,
  17825792,
  17826064,
  1118464,
  4352,
  272,
  1118464,
  0,
  0,
  0,
  0,
  65536,
  1118208,
  17830144,
  0,
  17895680,
  285212944,
  286331152,
  285212672,
  285212672,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  0,
  0,
  17895680,
  285212944,
  286331152,
  285212672,
  285212672,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  17825792,
  1114112,
  69632,
  0,
  17895680,
  285212944,
  286331152,
  285212672,
  285212672,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  17826064,
  0,
  0,
  1118208,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  69632,
  1118464,
  17826064,
  0,
  1118208,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  17825792,
  1114112,
  69632,
  0,
  1118208,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  285212944,
  0,
  65536,
  1118208,
  17830144,
  285212944,
  285212944,
  286331152,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  1118208,
  0,
  1118208,
  17830144,
  285212944,
  285212944,
  286331152,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  69632,
  1114112,
  17825792,
  0,
  286331152,
  17826064,
  17825792,
  17895680,
  17825792,
  17825792,
  17826064,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17830144,
  286331152,
  269549584,
  1114128,
  17895696,
  285282304,
  285282304,
  17830160,
  0,
  0,
  0,
  0,
  0,
  0,
  1118480,
  17830144,
  285217024,
  285217024,
  286331152,
  285217024,
  285217024,
  285217024,
  285217024,
  285217040,
  0,
  0,
  0,
  0,
  0,
  65536,
  1118208,
  17830144,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  17825792,
  1114112,
  69632,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  1114112,
  17895424,
  285217024,
  0,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  17825792,
  1114112,
  69632,
  0,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  285212944,
  0,
  0,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895696,
  272,
  4352,
  17895424,
  0,
  0,
  285212944,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  285212944,
  0,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  1118464,
  17826064,
  17825792,
  17825792,
  17825792,
  17826064,
  1118464,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  17826048,
  17825792,
  286326784,
  17825792,
  17825792,
  17825792,
  17825792,
  286261520,
  286331136,
  0,
  0,
  0,
  0,
  0,
  0,
  17826064,
  17826064,
  1118464,
  69632,
  17895696,
  69632,
  17895696,
  69632,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  286330880,
  285217024,
  285217024,
  286330880,
  285212928,
  285217024,
  285282576,
  285217024,
  285217024,
  285217024,
  285212944,
  0,
  0,
  0,
  0,
  0,
  4368,
  69649,
  69632,
  69632,
  69632,
  17895696,
  69632,
  69632,
  69632,
  69632,
  69632,
  285282304,
  17891328,
  0,
  0,
  0,
  69632,
  1114112,
  17825792,
  0,
  17895424,
  4352,
  17895680,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  4352,
  69632,
  1114112,
  0,
  1118208,
  69632,
  69632,
  69632,
  69632,
  69632,
  1118464,
  0,
  0,
  0,
  0,
  0,
  69632,
  1114112,
  17825792,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  69632,
  1114112,
  17825792,
  0,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  285217024,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  17891600,
  285282560,
  0,
  285282560,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  0,
  0,
  0,
  0,
  17891600,
  285282560,
  0,
  285212944,
  286261520,
  286327056,
  286331152,
  285282576,
  285217040,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  0,
  1118464,
  17830144,
  17830144,
  1118480,
  0,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  17830144,
  1118208,
  0,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1114112,
  1114112,
  0,
  1114112,
  1114112,
  17825792,
  285212672,
  285212944,
  285212944,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  285212672,
  285212672,
  285212672,
  285212672,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  272,
  272,
  272,
  272,
  0,
  0,
  0,
  0,
  0,
  0,
  285212672,
  285212672,
  285212688,
  285212944,
  285217024,
  69632,
  1114112,
  17825792,
  285282560,
  268435728,
  4352,
  69632,
  1118480,
  0,
  0,
  0,
  285212672,
  285212672,
  285212688,
  285212944,
  285217024,
  69632,
  1114112,
  17826064,
  285217040,
  268505360,
  1118480,
  272,
  272,
  0,
  0,
  0,
  0,
  69632,
  69632,
  0,
  69632,
  69632,
  69632,
  1118464,
  1118464,
  1118464,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1114384,
  17830144,
  285282304,
  17830144,
  1114384,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  285282304,
  17830144,
  1114384,
  17830144,
  285282304,
  0,
  0,
  0,
  0,
  0,
  0,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  16843009,
  269488144,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  286330880,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  286330880,
  69632,
  286330880,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286327056,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  0,
  0,
  0,
  0,
  0,
  286330880,
  69632,
  286330880,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286327056,
  272,
  286327056,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  0,
  0,
  0,
  0,
  0,
  286331152,
  272,
  286327056,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286327056,
  272,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  69632,
  69632,
  69632,
  286330880,
  69632,
  286330880,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286330880,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69905,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69905,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  286331153,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69905,
  69632,
  69905,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114385,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114385,
  1114112,
  1118481,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118481,
  1114112,
  1114385,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286327057,
  0,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  0,
  286327057,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114385,
  1114112,
  1114385,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  0,
  0,
  0,
  0,
  0,
  286331153,
  0,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286327057,
  0,
  286327057,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  69632,
  69632,
  69632,
  69632,
  69632,
  286331153,
  0,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  0,
  286331153,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1118481,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  69632,
  69632,
  69632,
  69905,
  69632,
  69905,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69905,
  69632,
  69905,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118481,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  286331153,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  1114384,
  69632,
  69632,
  69632,
  69632,
  69632,
  286331153,
  69632,
  286331153,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  286330880,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69905,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  286326784,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  4369,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17891600,
  285282560,
  285282304,
  285282304,
  285282304,
  285282560,
  17891600,
  0,
  0,
  0,
  0,
  0,
  0,
  17895424,
  285217024,
  285217024,
  285217024,
  285282304,
  285217024,
  285212944,
  285212944,
  285212944,
  285217024,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  285212944,
  285212944,
  285212672,
  285212672,
  285212672,
  285212672,
  285212672,
  285212672,
  285212672,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  17830144,
  17830144,
  17830144,
  17830144,
  17830144,
  17830144,
  17830144,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  285212944,
  17825792,
  1114112,
  69632,
  1114112,
  17825792,
  285212944,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  285282304,
  285282304,
  285282304,
  285282304,
  285282304,
  17891328,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17826064,
  17826064,
  17826064,
  17826064,
  17826064,
  17895680,
  17825792,
  17825792,
  285212672,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17891600,
  285282560,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  69632,
  1118464,
  17826064,
  17826064,
  17826064,
  1118464,
  69632,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  285212944,
  285212944,
  286331152,
  285212944,
  285212944,
  17830144,
  1118208,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  285212944,
  285212944,
  285212944,
  17830144,
  17830144,
  17830144,
  17830144,
  286265616,
  0,
  0,
  0,
  0,
  0,
  0,
  69904,
  1114112,
  69632,
  4352,
  1118480,
  17826064,
  17826064,
  17826064,
  17826064,
  1118464,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895696,
  285282321,
  285282321,
  285282321,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17,
  272,
  17895696,
  285282321,
  285282321,
  286326801,
  17895696,
  17825792,
  285212672,
  0,
  0,
  0,
  0,
  0,
  0,
  69888,
  1114112,
  17825792,
  17825792,
  17895680,
  17825792,
  17825792,
  17825792,
  1114112,
  69888,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  285212944,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  286331152,
  0,
  0,
  286331152,
  0,
  0,
  286331152,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  17895696,
  69632,
  69632,
  0,
  0,
  286331153,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1114112,
  69632,
  4352,
  272,
  4352,
  69632,
  1114112,
  0,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4352,
  69632,
  1114112,
  17825792,
  1114112,
  69632,
  4352,
  0,
  17895696,
  0,
  0,
  0,
  0,
  0,
  0,
  4368,
  69649,
  69649,
  69649,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  69632,
  285282304,
  285282304,
  285282304,
  17891328,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  0,
  17895696,
  0,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17891600,
  285282560,
  0,
  17891600,
  285282560,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1118208,
  17830144,
  17830144,
  1118208,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  69632,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4369,
  4352,
  4352,
  4352,
  4352,
  4352,
  286265600,
  17830144,
  17830144,
  1118464,
  69888,
  0,
  0,
  0,
  0,
  0,
  285282304,
  17830144,
  17830144,
  17830144,
  17830144,
  17830144,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17891328,
  285282304,
  1114112,
  17825792,
  285216768,
  286330880,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  17895680,
  17895680,
  17895680,
  17895680,
  17895680,
  17895680,
  17895680,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
}; // weak
char byte_188B00[576] =
{
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x02',
  '\0',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x01',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x02',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\xFF',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
char byte_188D40[56] =
{
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\x15',
  '\0',
  '\x15',
  '*',
  '\x15',
  '*',
  '*',
  '\0',
  '*',
  '\x15',
  '\x15',
  '\0',
  '\x15',
  '*',
  '\x15',
  '\x15',
  '\0',
  '\x15',
  '\0',
  '\x15',
  '?',
  '\x15',
  '?',
  '?',
  '\x15',
  '\x15',
  '\0',
  '\0',
  '?',
  '\0',
  '\0',
  '*',
  '\x15',
  '\0',
  '?',
  '*',
  '\0',
  '\x15',
  '\x15',
  '\x15',
  '?',
  '?',
  '*',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0'
}; // weak
int16_t word_188D78 = 0; // weak
int dword_188D7A = 0; // weak
int dword_188D7E = 0; // weak
int16_t word_188D82 = 0; // weak
int dword_188D84 = 0; // weak
int dword_188D8C = 0; // weak
int dword_188D90 = 0; // weak
char byte_188D94 = '\0'; // weak
char byte_188D95 = '\0'; // weak
char byte_188D96 = '\0'; // weak
int dword_188D97 = 0; // weak
int dword_188D9B = 0; // weak
int dword_188DBE = 0; // weak
int dword_188DC2 = 0; // weak
char byte_188DCB = '\0'; // weak
int dword_188DD2 = 0; // weak
int dword_188FBC = 0; // weak
int dword_188FC0 = 0; // weak
int dword_188FC4 = 0; // weak
int16_t word_188FC8 = 0; // weak
int16_t word_188FCE = 0; // weak
int dword_188FD4 = 0; // weak
int dword_188FD8 = 0; // weak
int dword_188FDC = 0; // weak
int dword_188FE0 = 0; // weak
int dword_188FE4 = 0; // weak
int dword_188FE8 = 0; // weak
int dword_188FEC = 0; // weak
int dword_188FF0 = 0; // weak
int dword_188FF4 = 0; // weak
int dword_188FF8 = 0; // weak
int dword_188FFC = 0; // weak
int dword_189000 = 0; // weak
int dword_189004 = 0; // weak
int dword_189008 = 0; // weak
int dword_18900C = 0; // weak
int dword_189010 = 0; // weak
int dword_189014 = 0; // weak
int dword_189018 = 0; // weak
int dword_18901C = 0; // weak
int dword_189020 = 0; // weak
int dword_189024 = 19088426; // weak
int dword_18913C = 0; // weak
int dword_189140 = 0; // weak
int dword_189144 = 0; // weak
int dword_189148 = 0; // weak
int dword_18914C = 0; // weak
int dword_189154 = 0; // weak
int dword_189158 = 0; // weak
int dword_18915C = 0; // weak
int dword_189160 = 0; // weak
int (*dword_189164)(_DWORD, _DWORD) = NULL; // weak
int (*dword_189168)(_DWORD) = NULL; // weak
int (*dword_18916C)(_DWORD) = NULL; // weak
int (*dword_189170)(_DWORD, _DWORD, _DWORD) = NULL; // weak
int dword_189174 = 0; // weak
char byte_1896F8 = '\0'; // weak
char byte_1896F9 = '\0'; // weak
int dword_1896FA = 0; // weak
int dword_1896FE = 0; // weak
int dword_189702 = 0; // weak
int16_t word_189708 = 0; // weak
int dword_18970E = 0; // weak
char byte_189712 = '\0'; // weak
char byte_189713 = '\0'; // weak
int dword_189714 = 0; // weak
int dword_189718 = 0; // weak
int16_t word_18971C = 0; // weak
int dword_1897C0 = 0; // weak
char *off_1897C4 = "OK"; // weak
int (*dword_1897C8)(_DWORD) = NULL; // weak
int dword_1897CC = 65535; // weak
int dword_1897D0 = 1050; // weak
int dword_1897D4 = 1050; // weak
int dword_1897D8[8] = { 1016, 760, 1000, 744, 0, 0, 0, 0 }; // weak
int dword_1897F8[8] = { 1016, 760, 12832, 12840, 16928, 16936, 21024, 21032 }; // weak
int dword_189818[8] = { 12, 11, 12, 11, 0, 0, 0, 0 }; // weak
int dword_189838[8] = { 12, 11, 11, 11, 11, 11, 11, 11 }; // weak
char byte_189858 = 'A'; // weak
int dword_18985C = 1; // weak
int dword_189860 = 0; // weak
int (*off_189864)(_DWORD) = &nmalloc; // weak
int (*off_189868)(_DWORD) = &nfree; // weak
int dword_18986C[] = { 0 }; // weak
int dword_1898AC[] = { 0 }; // weak
int dword_1898E8 = 0; // weak
int dword_1898EC[] = { 0 }; // weak
int dword_18992C[] = { 0 }; // weak
int dword_18996C[] = { 0 }; // weak
int dword_1899A8 = 0; // weak
int dword_1899AC[] = { 0 }; // weak
int dword_1899EC = 0; // weak
int16_t word_1899F0 = 0; // weak
int dword_1899F2 = 0; // weak
int dword_1899F6 = 0; // weak
int dword_1899FA = 0; // weak
int dword_1899FE = 0; // weak
int dword_189A02 = 0; // weak
int16_t word_189A06 = 0; // weak
int dword_189A08 = 0; // weak
int dword_189A0C = 0; // weak
int dword_189A10 = 0; // weak
_UNKNOWN unk_189A14; // weak
int16_t word_18A414 = 0; // weak
int dword_18A418 = 0; // weak
int dword_18A41C = 0; // weak
int dword_18A420 = 0; // weak
char byte_18A424[128] =
{
  '\0',
  '\x02',
  '\x04',
  '\x06',
  '\b',
  '\n',
  '\f',
  '\x0E',
  '\x10',
  '\x12',
  '\x14',
  '\x16',
  '\x18',
  '\x1A',
  '\x1C',
  '\x1E',
  ' ',
  '\"',
  '$',
  '&',
  '(',
  '*',
  ',',
  '.',
  '0',
  '2',
  '4',
  '6',
  '8',
  ':',
  '<',
  '>',
  '@',
  'B',
  'D',
  'F',
  'H',
  'J',
  'L',
  'N',
  'P',
  'R',
  'T',
  'V',
  'X',
  'Z',
  '\\',
  '^',
  '`',
  'b',
  'd',
  'f',
  'h',
  'j',
  'l',
  'n',
  'p',
  'r',
  't',
  'v',
  'x',
  'z',
  '|',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80',
  '\x80'
}; // weak
int dword_18A4A4 = 0; // weak
int dword_18A4A8 = 0; // weak
int dword_18A4AC = 0; // weak
char aSample[7] = "SAMPLE"; // weak
int dword_18A530 = 0; // weak
int dword_18A534 = 0; // weak
char aTimb_0[5] = "TIMB"; // weak
char byte_18A542 = '\xFF'; // weak
char byte_18A543 = '\xFF'; // weak
int dword_18A544 = 0; // weak
void (*off_18A54C)(void) = &_no_support_loaded; // weak
int (*dword_18A5AC)(_DWORD) = NULL; // weak
int dword_18A5B0 = 0; // weak
char (*off_18A5B8)() = &sub_15C730; // weak
int dword_18A600 = 0; // weak
int dword_18A604 = 0; // weak
int dword_18A608 = 0; // weak
int dword_18A60C = 0; // weak
_DWORD dword_18A610 = 0; // weak
int dword_18A614 = 0; // weak
int dword_18A618 = 0; // weak
int dword_18A61C = 0; // weak
_DWORD dword_18A620 = 0; // weak
int dword_18A624 = 0; // weak
int dword_18A628 = 0; // weak
int dword_18A62C = 0; // weak
_DWORD dword_18A630 = 0; // weak
_DWORD dword_18A640 = 0; // weak
int dword_18A644 = 0; // weak
int dword_18A648 = 0; // weak
int dword_18A64C = 0; // weak
int dword_18A650 = 0; // weak
int dword_18A654 = 0; // weak
int dword_18A658 = 0; // weak
int dword_18A65C = 0; // weak
int dword_18A660 = 0; // weak
int dword_18A664 = 0; // weak
int dword_18A668 = 0; // weak
int dword_18A66C = 0; // weak
int dword_18A670 = 0; // weak
int dword_18A674 = 0; // weak
int dword_18A678 = 0; // weak
int dword_18A680 = 0; // weak
int dword_18A684 = 0; // weak
int dword_18A688 = 0; // weak
int dword_18A68C = 0; // weak
int dword_18A690 = 0; // weak
int dword_18A694 = 0; // weak
int dword_18A698 = 0; // weak
int (*dword_18A69C)(_DWORD) = NULL; // weak
int dword_18A6A0 = 0; // weak
int dword_18A6A4 = 0; // weak
int dword_18A6A8 = 0; // weak
int dword_18A6AC = 0; // weak
int dword_18A6B0 = 0; // weak
int dword_18A6B4 = 0; // weak
char byte_18A6C0 = '\0'; // weak
int dword_18A6D0 = 0; // weak
int dword_18A6E0 = 1; // weak
int16_t word_18A7E0 = 0; // weak
int16_t word_18A7E2 = 0; // weak
int16_t word_18A7E4 = 0; // weak
int dword_18A7F0 = 0; // weak
int dword_18A7F4 = 0; // weak
int dword_18A7F8 = 0; // weak
int dword_18A7FC = 0; // weak
int (*funcs_164C45[256])() =
{
  &sub_165760,
  &sub_16576C,
  &sub_165778,
  &sub_165784,
  &sub_165790,
  &sub_1657A0,
  &sub_1657B0,
  &sub_1657C0,
  &sub_1657D0,
  &sub_1657DC,
  &sub_1657E8,
  &sub_1657F4,
  &sub_165800,
  &sub_165810,
  &sub_165820,
  &sub_165830,
  &sub_165840,
  &sub_16584C,
  &sub_165858,
  &sub_165868,
  &sub_165874,
  &sub_165884,
  &sub_165894,
  &sub_1658A4,
  &sub_1658B4,
  &sub_1658C0,
  &sub_1658CC,
  &sub_1658D8,
  &sub_1658E4,
  &sub_1658F4,
  &sub_165904,
  &sub_165914,
  &sub_165924,
  &sub_165930,
  &sub_165940,
  &sub_16594C,
  &sub_165958,
  &sub_165968,
  &sub_165978,
  &sub_165988,
  &sub_165998,
  &sub_1659A4,
  &sub_1659B0,
  &sub_1659BC,
  &sub_1659C8,
  &sub_1659D8,
  &sub_1659E8,
  &sub_1659F8,
  &sub_165A08,
  &sub_165A14,
  &sub_165A20,
  &sub_165A2C,
  &sub_165A38,
  &sub_165A48,
  &sub_165A58,
  &sub_165A68,
  &sub_165A78,
  &sub_165A84,
  &sub_165A90,
  &sub_165A9C,
  &sub_165AA8,
  &sub_165AB8,
  &sub_165AC8,
  &sub_165AD8,
  &sub_165AE8,
  &sub_165AF8,
  &sub_165B08,
  &sub_165B18,
  &sub_165B28,
  &sub_165B34,
  &sub_165B40,
  &sub_165B50,
  &sub_165B5C,
  &sub_165B68,
  &sub_165B74,
  &sub_165B80,
  &sub_165B8C,
  &sub_165B9C,
  &sub_165BAC,
  &sub_165BBC,
  &sub_165BCC,
  &sub_165BDC,
  &sub_165BEC,
  &sub_165BFC,
  &sub_165C0C,
  &sub_165C18,
  &sub_165C20,
  &sub_165C2C,
  &sub_165C38,
  &sub_165C44,
  &sub_165C50,
  &sub_165C58,
  &sub_165C64,
  &sub_165C74,
  &sub_165C84,
  &sub_165C94,
  &sub_165CA4,
  &sub_165CB4,
  &sub_165CC4,
  &sub_165CD4,
  &sub_165CE4,
  &sub_165CF4,
  &sub_165D00,
  &sub_165D0C,
  &sub_165D1C,
  &sub_165D2C,
  &sub_165D38,
  &sub_165D44,
  &sub_165D54,
  &sub_165D64,
  &sub_165D74,
  &sub_165D84,
  &sub_165D94,
  &sub_165DA4,
  &sub_165DB4,
  &sub_165DC4,
  &sub_165DD4,
  &sub_165DE0,
  &sub_165DEC,
  &sub_165DFC,
  &sub_165E08,
  &sub_165E14,
  &sub_165E20,
  &sub_165E2C,
  &sub_165E38,
  &sub_165E48,
  &sub_165E58,
  &sub_165E68,
  &sub_165E78,
  &sub_165E84,
  &sub_165E90,
  &sub_165E9C,
  &sub_165EA8,
  &sub_165EB4,
  &sub_165EC0,
  &sub_165ED0,
  &sub_165EDC,
  &sub_165EE4,
  &sub_165EF0,
  &sub_165EF8,
  &sub_165F00,
  &sub_165F0C,
  &sub_165F18,
  &sub_165F24,
  &sub_165F30,
  &sub_165F3C,
  &sub_165F4C,
  &sub_165F58,
  &sub_165F64,
  &sub_165F74,
  &sub_165F80,
  &sub_165F8C,
  &sub_165F9C,
  &sub_165FA8,
  &sub_165FB4,
  &sub_165FC0,
  &sub_165FCC,
  &sub_165FD8,
  &sub_165FE8,
  &sub_165FF4,
  &sub_166000,
  &sub_16600C,
  &sub_166018,
  &sub_166024,
  &sub_166030,
  &sub_16603C,
  &sub_166044,
  &sub_166050,
  &sub_16605C,
  &sub_166064,
  &sub_166070,
  &sub_166078,
  &sub_166080,
  &sub_16608C,
  &sub_166098,
  &sub_1660A4,
  &sub_1660B0,
  &sub_1660BC,
  &sub_1660C8,
  &sub_1660D4,
  &sub_1660E0,
  &sub_1660EC,
  &sub_1660F8,
  &sub_166108,
  &sub_166114,
  &sub_16611C,
  &sub_166128,
  &sub_166130,
  &sub_166138,
  &sub_166144,
  &sub_166150,
  &sub_16615C,
  &sub_166168,
  &sub_166178,
  &sub_166188,
  &sub_166198,
  &sub_1661A8,
  &sub_1661B8,
  &sub_1661C8,
  &sub_1661D8,
  &sub_1661E8,
  &sub_1661F4,
  &sub_166200,
  &sub_16620C,
  &sub_166218,
  &sub_166224,
  &sub_166230,
  &sub_16623C,
  &sub_166248,
  &sub_166258,
  &sub_166268,
  &sub_166278,
  &sub_166288,
  &sub_166298,
  &sub_1662A8,
  &sub_1662B8,
  &sub_1662C8,
  &sub_1662D4,
  &sub_1662E0,
  &sub_1662EC,
  &sub_1662F8,
  &sub_166304,
  &sub_166310,
  &sub_166320,
  &sub_16632C,
  &sub_16633C,
  &sub_16634C,
  &sub_16635C,
  &sub_16636C,
  &sub_16637C,
  &sub_16638C,
  &sub_16639C,
  &sub_1663AC,
  &sub_1663B8,
  &sub_1663C4,
  &sub_1663D0,
  &sub_1663DC,
  &sub_1663E8,
  &sub_1663F8,
  &sub_166404,
  &sub_166410,
  &sub_166420,
  &sub_166430,
  &sub_166440,
  &sub_166450,
  &sub_166460,
  &sub_166470,
  &sub_166480,
  &sub_166490,
  &sub_16649C,
  &sub_1664A8,
  &sub_1664B4,
  &sub_1664C0,
  &sub_1664CC,
  &sub_1664D8,
  &sub_1664E4
}; // weak
int dword_18AC00 = 0; // weak
int dword_18AC04 = 0; // weak
int dword_18AC08 = 0; // weak
int dword_18AC0C = 0; // weak
int dword_18AC10 = 0; // weak
int dword_18AC14 = 0; // weak
int dword_18AC20 = 0; // weak
int dword_18AC24 = 0; // weak
int dword_18AC28 = 0; // weak
int dword_18AC2C = 0; // weak
int dword_18AC30 = 0; // weak
int16_t word_18AC72 = 0; // weak
int16_t word_18AC74 = 0; // weak
int16_t word_18AC76 = 0; // weak
int16_t word_18AC78 = 0; // weak
int dword_18AC7A = 0; // weak
int dword_18AC7E = 0; // weak
int16_t word_18AC82 = 0; // weak
int16_t word_18AC84 = 0; // weak
int dword_18AC86 = 0; // weak
int dword_18AC8A = 0; // weak
int dword_18AC8E = 16777215; // weak
int16_t word_18AC92 = -1; // weak
int dword_18AC94 = 0; // weak
int dword_18AC98 = 0; // weak
int dword_18AC9C = 0; // weak
int dword_18ACA0 = 0; // weak
int dword_18ACA4 = 0; // weak
int dword_18ACA8 = 0; // weak
int dword_18ACAC = 0; // weak
int dword_18ACB0 = 0; // weak
int dword_18ACB4 = 0; // weak
int dword_18ACBC = 0; // weak
int dword_18ACC0 = 380; // weak
int dword_18ACCC = 0; // weak
int dword_18ACD0 = 0; // weak
int (*off_18ACD4[2])() = { &sub_15E2F0, &sub_15E330 }; // weak
int (*off_18ACD8)() = &sub_15E330; // weak
int dword_18ACDC = 1; // weak
int dword_18ACE0 = 0; // weak
int16_t word_18ACE4 = 0; // weak
int16_t word_18ACE6 = 0; // weak
int dword_18ACE8 = 0; // weak
int dword_18ACEC = 0; // weak
int dword_18ACF0 = -1; // weak
int dword_18ACF4 = -1; // weak
int dword_18ACF8 = -1; // weak
int dword_18ACFC = -1; // weak
int dword_18AD28 = 0; // weak
int dword_18AD2C = 0; // weak
int dword_18AD30 = 0; // weak
int dword_18AD34 = 0; // weak
int dword_18AD38 = 0; // weak
int64_t qword_18AD3C = 0LL; // weak
int dword_18AD44 = 0; // weak
void (__noreturn *off_18AD48)() = &_terminate; // weak
int dword_18AD4C = 0; // weak
int dword_18AD50 = 1; // weak
char byte_18AD54 = '\x02'; // weak
char byte_18AD58 = '\0'; // weak
int dword_18AD5C = -1; // weak
int dword_18AD60 = 1; // weak
int dword_18AD64 = 0; // weak
int dword_18AD68 = -1; // weak
int dword_18AD6C = 0; // weak
int dword_18AD70 = 0; // weak
int16_t word_18ADA8 = 0; // weak
_UNKNOWN unk_18ADB4; // weak
double dbl_18ADBE = 1.7976931348623157e308; // weak
float flt_18ADC6 = 3.4028235e38; // weak
char byte_18AFD0 = '\0'; // weak
_UNKNOWN *off_18B018 = &loc_168636; // weak
char byte_18B040[6] = { '\xBC', '\x9A', 'x', 'V', '4', '\x12' }; // weak
_UNKNOWN *off_18B04A = (_UNKNOWN *)0x1684C2; // weak
_UNKNOWN unk_18B072; // weak
int16_t word_18B074 = 0; // weak
int16_t word_18B090[40] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
}; // weak
int16_t word_18B0E0[40] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
}; // weak
int dword_18B130[40] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
}; // weak
int16_t word_18B1D0[] = { 0 }; // weak
int16_t word_18B1E0[] = { 0 }; // weak
int16_t word_18B1F0[] = { 0 }; // weak
int16_t word_18B200[] = { 0 }; // weak
int16_t word_18B210[] = { 0 }; // weak
int16_t word_18B220[] = { 0 }; // weak
int dword_18B230[6] = { 0, 0, 0, 0, 0, 0 }; // weak
int dword_18B248[] = { 0 }; // weak
int dword_18B260[] = { 0 }; // weak
int dword_18B264 = 0; // weak
int dword_18B268 = 0; // weak
int dword_18B26C = 0; // weak
int dword_18B270 = 0; // weak
int dword_18B274 = 0; // weak
int dword_18B278 = 0; // weak
int dword_18B27C = 0; // weak
int dword_18B280 = 0; // weak
int dword_18B284 = 0; // weak
int dword_18B288 = 0; // weak
int dword_18B28C = 0; // weak
int dword_18B290 = 0; // weak
int dword_18B294 = 0; // weak
int dword_18B298 = 0; // weak
int dword_18B29C = 0; // weak
int dword_18B2A0 = 0; // weak
int dword_18B2A4 = 0; // weak
int dword_18B2A8[960] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  
}; // weak
char byte_18C1A8[2048]; // weak
int16_t word_18C9A8[4979]; // weak
int16_t word_18F08E[529]; // weak
int dword_18F4B0[]; // weak
int dword_18F4B4; // weak
int dword_18F4B8; // weak
int dword_18F4BC; // weak
int dword_18F4C0[]; // weak
int16_t word_18F500[]; // weak
int16_t word_18F510[300]; // weak
int dword_18F768[112]; // weak
int dword_18F928[8]; // weak
int dword_18F948[8]; // weak
int dword_18F968; // weak
int dword_18F96C; // weak
int dword_18F970; // weak
int dword_18F974; // weak
int dword_18F978; // weak
int dword_18F97C; // weak
int dword_18F980; // weak
int dword_18F984; // weak
int dword_18F988; // weak
int dword_18F98C; // weak
int dword_18F990[]; // weak
int dword_18F994; // weak
int dword_18F998; // weak
int dword_18F99C; // weak
int dword_18F9A0; // weak
int dword_18F9A4; // weak
int dword_18F9A8; // weak
int dword_18F9AC; // weak
int dword_18F9B0; // weak
int dword_18F9B4; // weak
int dword_18F9B8[]; // weak
int dword_18F9BC; // weak
int dword_18F9C0; // weak
int dword_18F9C4; // weak
int dword_18F9C8; // weak
int dword_18F9CC; // weak
int dword_18F9D0; // weak
int dword_18F9D4; // weak
int dword_18F9D8; // weak
int dword_18F9DC; // weak
int dword_18F9E0; // weak
int dword_18F9E4; // weak
int dword_18F9E8; // weak
int dword_18F9EC; // weak
int dword_18F9F0; // weak
int dword_18F9F4; // weak
int dword_18FEF8[32]; // weak
int16_t word_18FF78; // weak
int16_t word_190178[72]; // weak
int16_t word_190208[72]; // weak
int dword_190298[]; // weak
int dword_1902A4[45]; // weak
int dword_190358[54]; // weak
int dword_190430[]; // weak
int dword_190434; // weak
int dword_190438; // weak
int dword_19043C; // weak
int dword_190440; // weak
int dword_190444; // weak
int dword_190448[]; // weak
int dword_19044C; // weak
int dword_190450; // weak
int dword_190454; // weak
int dword_190458; // weak
int dword_19045C; // weak
int16_t word_190460; // weak
int16_t word_190462; // weak
int dword_190464; // weak
int16_t word_190468; // weak
int16_t word_19046A; // weak
int16_t word_19046C; // weak
int16_t word_19046E; // weak
int dword_190470[6]; // weak
char byte_190488[]; // weak
int16_t word_190490[3]; // weak
int16_t word_190496; // weak
int dword_190498[]; // weak
int dword_1904A0; // weak
int dword_1904C8[]; // weak
int dword_1904D0; // weak
int dword_1904D8[8]; // weak
int dword_1904F8[8]; // weak
int dword_190518[32]; // weak
int dword_190598[24]; // weak
int dword_1905F8[32]; // weak
int dword_190678[4]; // weak
int dword_190688[10]; // weak
int dword_1906B0[]; // weak
int16_t word_1906C0[]; // weak
int16_t word_1906C2[]; // weak
int16_t word_1906C4[]; // weak
int16_t word_1906C6[]; // weak
int16_t word_1906C8[]; // weak
int16_t word_1906CA[3427]; // weak
int dword_192190[31]; // weak
int dword_19220C; // weak
int dword_192210[]; // weak
int dword_192214; // weak
int dword_192218; // weak
int dword_19221C; // weak
int dword_192220; // weak
int dword_192224; // weak
int dword_192228[]; // weak
int dword_19222C; // weak
int dword_192230; // weak
int dword_192234; // weak
int dword_192238; // weak
int dword_19223C; // weak
int dword_192240; // weak
int dword_192244; // weak
int16_t word_192248[500]; // weak
int dword_192630[]; // weak
int dword_192634; // weak
int dword_192638; // weak
int dword_19263C; // weak
int dword_192640; // weak
int dword_192644[]; // weak
int dword_192648; // weak
int dword_19264C; // weak
int dword_192650; // weak
int dword_192654; // weak
int dword_192658; // weak
int dword_19265C; // weak
int dword_192660; // weak
int dword_192664; // weak
int dword_192668; // weak
int dword_19266C; // weak
int dword_192670; // weak
int dword_192674; // weak
int dword_192678; // weak
int dword_19267C; // weak
int dword_192680; // weak
int dword_192688; // weak
int dword_19268C; // weak
int dword_192694; // weak
int dword_192698; // weak
int dword_19269C[39]; // weak
int16_t word_192738[10]; // weak
int dword_19274C; // weak
int16_t word_192750[6]; // weak
int dword_19275C; // weak
int dword_192760; // weak
int dword_192764[5]; // weak
int dword_192778; // weak
int dword_19277C; // weak
int dword_192780; // weak
int dword_192784; // weak
int dword_192788; // weak
int dword_19278C[4]; // weak
int dword_19279C; // weak
int dword_1927A0; // weak
int dword_1927A4; // weak
int dword_1927A8; // weak
int dword_1927B0[5]; // weak
int dword_1927C4; // weak
int dword_1927C8; // weak
int dword_1927CC; // weak
int dword_1927D0; // weak
int dword_1927D4; // weak
int dword_1927D8; // weak
int dword_1927DC; // weak
int dword_1927E0; // weak
int dword_1927E4; // weak
int dword_1927E8; // weak
int dword_1927EC; // weak
int dword_1927F0; // weak
int dword_1927F4; // weak
int dword_1927F8; // weak
int dword_1927FC; // weak
int dword_192800; // weak
int dword_192804; // weak
int dword_192808; // weak
int dword_19280C; // weak
int dword_192810; // weak
int dword_192814; // weak
int dword_192818; // weak
int dword_19281C; // weak
int dword_192820; // weak
int dword_192824; // weak
int dword_192828; // weak
int dword_19282C; // weak
int dword_192830; // weak
int dword_192838; // weak
int dword_19283C; // weak
int dword_192840; // weak
int dword_192844; // weak
int dword_192848; // weak
int dword_19284C; // weak
int dword_192850; // weak
int dword_192854; // weak
int dword_192858; // weak
int dword_19285C; // weak
int dword_192860; // weak
int dword_192864; // weak
int dword_19286C; // weak
int dword_192870; // weak
int dword_192874; // weak
int dword_192878; // weak
int dword_19287C; // weak
int dword_192880; // weak
int dword_192884; // weak
int dword_192888; // weak
int dword_19288C; // weak
int dword_1928A4; // weak
int dword_1928A8; // weak
int dword_1928AC; // weak
int dword_1928C4; // weak
int dword_1928DC; // weak
int dword_19291C[]; // weak
int dword_192928; // weak
int dword_19292C; // weak
int dword_192944; // weak
int dword_192948; // weak
int dword_19294C; // weak
int dword_192950; // weak
int dword_192954; // weak
int16_t word_19296C[]; // weak
int16_t word_19296E[209]; // weak
int16_t word_192B10[]; // weak
int16_t word_192B12; // weak
int dword_192B14; // weak
int dword_192B18; // weak
int dword_192B1C; // weak
int dword_192B20; // weak
int dword_192B24; // weak
int dword_192B28; // weak
int dword_192B2C; // weak
int dword_192B30; // weak
int dword_192B34; // weak
int dword_192B38; // weak
int dword_192B3C; // weak
int dword_192B40; // weak
int dword_192B44; // weak
int dword_192B48; // weak
int dword_192B4C; // weak
int dword_192B50; // weak
int dword_192B58; // weak
int dword_192B5C; // weak
int dword_192B60; // weak
int dword_192B64; // weak
int dword_192B68; // weak
int dword_192B6C; // weak
int dword_192B70[7]; // weak
int dword_192B8C[15]; // weak
int dword_192BC8; // weak
int dword_192BD8; // weak
int dword_192BE0[]; // weak
int dword_192BE4; // weak
int dword_192BE8; // weak
int dword_192BEC; // weak
int dword_192BF0; // weak
int dword_192BF4[]; // weak
int dword_192BF8; // weak
int dword_192BFC; // weak
int dword_192C00; // weak
int dword_192C04; // weak
int dword_192C08[]; // weak
int dword_192C0C; // weak
int dword_192C10; // weak
int dword_192C14; // weak
int dword_192C18; // weak
int dword_192C1C; // weak
int dword_192C20; // weak
int dword_192C24; // weak
int dword_192C28; // weak
int dword_192C2C; // weak
int dword_192C30; // weak
int dword_192C34; // weak
int dword_192C38; // weak
int dword_192C3C; // weak
int dword_192C40; // weak
int dword_192C44; // weak
int dword_192C48; // weak
int dword_192C4C; // weak
int dword_192C50; // weak
int dword_192C54; // weak
int dword_192C58; // weak
int dword_192C5C; // weak
int dword_192C60; // weak
int dword_192C64; // weak
int dword_192C68; // weak
int dword_192C6C; // weak
int dword_192C70; // weak
int dword_192C74[]; // weak
int dword_192C78; // weak
int dword_192C7C; // weak
int16_t word_192C80[]; // weak
int16_t word_192C82[]; // weak
int16_t word_192C84[]; // weak
int16_t word_192C86[]; // weak
int16_t word_192C88[]; // weak
int16_t word_192C8A; // weak
int16_t word_192C8C; // weak
int16_t word_192C8E; // weak
int16_t word_192C90; // weak
int16_t word_192C92; // weak
int16_t word_192C94; // weak
int16_t word_192C96; // weak
int16_t word_192C98; // weak
int16_t word_192C9A; // weak
int16_t word_192C9C; // weak
int16_t word_192C9E; // weak
int16_t word_192CA0; // weak
int16_t word_192CA2; // weak
int16_t word_192CA4; // weak
int16_t word_192CA6; // weak
int16_t word_192CA8; // weak
int16_t word_192CAA; // weak
int16_t word_192CAC; // weak
int16_t word_192CAE; // weak
int16_t word_192CB0; // weak
int16_t word_192CB2; // weak
int16_t word_192CB4; // weak
int16_t word_192CB6; // weak
int16_t word_192CB8; // weak
int16_t word_192CBA; // weak
int16_t word_192CBC; // weak
int16_t word_192CBE; // weak
int16_t word_192CC0; // weak
int16_t word_192CC2; // weak
int16_t word_192CC4; // weak
int16_t word_192CC6; // weak
int16_t word_192CC8; // weak
int16_t word_192CCA; // weak
int16_t word_192CCC; // weak
int16_t word_192CCE; // weak
int16_t word_192CD0; // weak
int16_t word_192CD2; // weak
int16_t word_192CD4; // weak
int16_t word_192CD6; // weak
int16_t word_192CD8; // weak
int16_t word_192CDA; // weak
int16_t word_192CDC; // weak
int16_t word_192CDE; // weak
int16_t word_192CE0; // weak
int16_t word_192CE2; // weak
int16_t word_192CE4; // weak
int16_t word_192CE6; // weak
int16_t word_192CE8; // weak
int16_t word_192CEA; // weak
int16_t word_192CEC; // weak
int16_t word_192CEE; // weak
int16_t word_192CF0; // weak
int16_t word_192CF2; // weak
int16_t word_192CF4; // weak
int16_t word_192CF6; // weak
int16_t word_192CF8; // weak
int16_t word_192CFA; // weak
int16_t word_192CFC; // weak
int16_t word_192CFE; // weak
int16_t word_192D00; // weak
int16_t word_192D02; // weak
int16_t word_192D04; // weak
int16_t word_192D06; // weak
int16_t word_192D08; // weak
int16_t word_192D0A; // weak
int16_t word_192D0C; // weak
int16_t word_192D0E; // weak
int16_t word_192D10; // weak
int16_t word_192D12; // weak
int16_t word_192D14; // weak
int16_t word_192D16; // weak
int16_t word_192D20; // weak
int16_t word_192D2A; // weak
int16_t word_192D34; // weak
int16_t word_192D3E; // weak
int16_t word_192D48; // weak
int16_t word_192D52; // weak
int16_t word_192D5C; // weak
int16_t word_192D66; // weak
int16_t word_192D70; // weak
int16_t word_192D7A; // weak
int16_t word_192D84; // weak
int16_t word_192D8E; // weak
int16_t word_192D98; // weak
int16_t word_192DA2; // weak
int16_t word_192DAC; // weak
int16_t word_192DB6; // weak
int16_t word_192DB8; // weak
int16_t word_192DBA; // weak
int16_t word_192DBC; // weak
int16_t word_192DBE; // weak
int16_t word_192DC0; // weak
int16_t word_192DC2; // weak
int16_t word_192DC4; // weak
int16_t word_192DC6; // weak
int16_t word_192DC8; // weak
int16_t word_192DCA; // weak
int16_t word_192DCC; // weak
int16_t word_192DCE; // weak
int16_t word_192DD0; // weak
int16_t word_192DD2; // weak
int16_t word_192DD4; // weak
int16_t word_192DD6; // weak
int16_t word_192DD8; // weak
int16_t word_192DDA; // weak
int16_t word_192DDC; // weak
int16_t word_192DDE; // weak
int16_t word_192DE0; // weak
int16_t word_192DE2; // weak
int16_t word_192DE4; // weak
int16_t word_192DE6; // weak
int16_t word_192DE8; // weak
int16_t word_192DEA; // weak
int16_t word_192DEC; // weak
int16_t word_192DEE; // weak
int16_t word_192DF0; // weak
int16_t word_192DF2; // weak
int16_t word_192DF4; // weak
int16_t word_192DF6; // weak
int16_t word_192DF8; // weak
int16_t word_192DFA; // weak
int16_t word_192DFC; // weak
int16_t word_192DFE; // weak
int16_t word_192E00; // weak
int16_t word_192E02; // weak
int16_t word_192E04; // weak
int dword_192E7C; // weak
char byte_192E80[]; // weak
int dword_192E84; // weak
int dword_192E88; // weak
int dword_192E8C; // weak
int dword_192E90; // weak
int dword_192EC4; // weak
char byte_192ECC[]; // weak
int dword_192ED0; // weak
int dword_192ED4; // weak
int dword_192ED8; // weak
int dword_192EE4; // weak
int dword_192EE8; // weak
int dword_192EEC; // weak
int dword_192EF0; // weak
int dword_192EF4; // weak
int dword_192EF8; // weak
int dword_192F00; // weak
int dword_192F08; // weak
int dword_192F10; // weak
int dword_192FD8; // weak
int16_t word_192FDC[]; // weak
int16_t word_192FDE[]; // weak
int16_t word_192FE0[]; // weak
int16_t word_192FE2[]; // weak
int16_t word_192FE4[]; // weak
int16_t word_192FE6[]; // weak
int16_t word_192FE8[]; // weak
int16_t word_192FEA[]; // weak
int16_t word_192FEC[]; // weak
int16_t word_192FEE[]; // weak
int16_t word_192FF0[]; // weak
int16_t word_192FF2[]; // weak
int16_t word_192FF4[]; // weak
int16_t word_192FF6[]; // weak
int16_t word_192FF8; // weak
int16_t word_192FFC; // weak
int16_t word_192FFE; // weak
int16_t word_193014; // weak
int16_t word_193016; // weak
int16_t word_193018; // weak
int16_t word_19301A; // weak
int16_t word_19301C; // weak
int16_t word_19301E; // weak
int16_t word_193022; // weak
int16_t word_193024; // weak
int16_t word_193026; // weak
int16_t word_193028; // weak
int16_t word_19302A; // weak
int16_t word_19302C; // weak
int16_t word_19302E; // weak
int16_t word_193030; // weak
int16_t word_193038; // weak
int16_t word_19303A; // weak
int16_t word_19303E; // weak
int16_t word_193040; // weak
int16_t word_193042; // weak
int16_t word_193044; // weak
int16_t word_193046; // weak
int16_t word_193048; // weak
int16_t word_19304A; // weak
int16_t word_19304C; // weak
int dword_193068; // weak
int dword_19306C; // weak
int dword_193070; // weak
int dword_193080; // weak
int dword_1930A8; // weak
int dword_1930BC; // weak
int dword_1930D4; // weak
int dword_1930D8; // weak
int dword_1930DC; // weak
int dword_1930E0; // weak
int dword_1930E8; // weak
int dword_1930EC; // weak
int dword_1930F8; // weak
int dword_1930FC; // weak
int dword_193100; // weak
int dword_193104; // weak
int dword_193108; // weak
int dword_19310C; // weak
int dword_193110; // weak
int dword_193114; // weak
int dword_193118; // weak
int dword_19311C; // weak
int dword_193120; // weak
int dword_193124; // weak
int dword_193128; // weak
int dword_19312C; // weak
int dword_193130; // weak
int dword_193134; // weak
int dword_193138; // weak
int dword_19313C; // weak
int dword_193140; // weak
int dword_193144; // weak
int dword_193148; // weak
int dword_19314C; // weak
int dword_193150; // weak
int dword_193154; // weak
int dword_193158; // weak
int dword_19315C; // weak
int dword_193160; // weak
int dword_193164; // weak
int dword_193168; // weak
int dword_19316C; // weak
int dword_193170; // weak
int dword_193174; // weak
int dword_193178; // weak
int dword_193184; // weak
int dword_193188; // weak
int dword_193190; // weak
int dword_193194[6]; // weak
int16_t word_1931AC[]; // weak
int16_t word_1931AE; // weak
int16_t word_1931B0; // weak
int16_t word_1931B2; // weak
int16_t word_1931B4; // weak
int16_t word_1931B6; // weak
int dword_1931B8; // weak
int16_t word_1931BC[]; // weak
int16_t word_1931BE[]; // weak
int16_t word_1931C0[]; // weak
int16_t word_1931C2[]; // weak
int dword_1931C4[43]; // weak
int dword_193270; // weak
int dword_193274; // weak
int dword_193278; // weak
int dword_19327C; // weak
int dword_193280; // weak
int dword_193284; // weak
int dword_193288; // weak
int dword_19328C; // weak
int dword_193290; // weak
int dword_193294; // weak
int dword_193298; // weak
int dword_19329C; // weak
int dword_1932A0; // weak
int dword_1932A4; // weak
int dword_1932A8; // weak
int dword_1932AC; // weak
int dword_1932B0; // weak
int dword_1932B4; // weak
int dword_1932B8; // weak
int dword_1932BC; // weak
int dword_1932C0; // weak
int dword_1932C4; // weak
int dword_1932C8; // weak
int dword_1932CC; // weak
int dword_1932D0; // weak
int dword_1932D4; // weak
int dword_1932E0[11]; // weak
int dword_19330C[57]; // weak
int dword_1933F0; // weak
int dword_1933F4; // weak
int dword_1933F8[]; // weak
int dword_19340C; // weak
int dword_193410; // weak
int dword_193414; // weak
char byte_19341C[16500]; // weak
int dword_197490[62]; // weak
int dword_197588[11]; // weak
int dword_1975B4; // weak
int dword_1975B8; // weak
int dword_1975BC; // weak
int dword_1975C0; // weak
int dword_1975C4; // weak
int dword_1975C8; // weak
int dword_1975CC; // weak
int dword_1975D0; // weak
int16_t word_1975D4; // weak
int16_t word_1975D6; // weak
char byte_1975D8[2496]; // weak
int dword_197F98; // weak
int dword_197F9C; // weak
int dword_197FA0[]; // weak
int dword_197FA4; // weak
int dword_197FA8; // weak
int dword_197FAC; // weak
int dword_197FB0; // weak
int dword_197FB4; // weak
int dword_197FB8; // weak
_UNKNOWN unk_197FBC; // weak
int16_t word_197FBD; // weak
int16_t word_197FBF; // weak
int16_t word_197FC1; // weak
int16_t word_197FC3; // weak
int dword_199150[]; // weak
int dword_199154; // weak
int dword_199158; // weak
int dword_19915C; // weak
int dword_199160; // weak
int dword_199164; // weak
int dword_199168; // weak
int dword_19916C; // weak
int dword_199170; // weak
int16_t word_199174; // weak
int16_t word_199176; // weak
int16_t word_199178; // weak
int16_t word_19917A[4]; // weak
int16_t word_199182; // weak
int16_t word_19918A[]; // weak
int16_t word_19918C[9]; // weak
int16_t word_19919E[9]; // weak
char byte_1991B0; // weak
int dword_1991B1; // weak
char byte_1991B5; // weak
int16_t word_1991B6[]; // weak
int16_t word_1991B8; // weak
int16_t word_1991BA; // weak
int16_t word_1991D2; // weak
int16_t word_1991D4[5]; // weak
int16_t word_1991DE[5]; // weak
int16_t word_1991E8[15]; // weak
int16_t word_199206[15]; // weak
int16_t word_199224[15]; // weak
int16_t word_199242[9]; // weak
int16_t word_199254[42]; // weak
char byte_1992A8; // weak
char byte_1992A9; // weak
char byte_1992AA; // weak
char byte_1992AC; // weak
char byte_1992AD; // weak
char byte_1992AE; // weak
char byte_1992B1; // weak
char byte_1992B5; // weak
int16_t word_1992B6; // weak
int16_t word_1992B8; // weak
int16_t word_1992BA; // weak
int16_t word_1992BC; // weak
int16_t word_1992BE; // weak
int16_t word_1992C0[]; // weak
int16_t word_1992C2; // weak
int16_t word_1992C4; // weak
int16_t word_1992C6; // weak
int16_t word_1992C8; // weak
int16_t word_1992D4[10]; // weak
int16_t word_1992E8[5]; // weak
char byte_1992F2[10]; // weak
int16_t word_1992FC[462]; // weak
//char byte_199699[19]; // weak
TypeSaveSlotInfo_199699 saveSlotInfo_199699[10];
//int16_t word_1996AC[9]; // weak
//char byte_1996BE[333]; // weak
char byte_19980B[37]; // weak
int16_t word_199830; // weak
int16_t word_199832; // weak
int16_t word_199834; // weak
int16_t word_199836; // weak
int16_t word_199838; // weak
int16_t word_19983A; // weak
int16_t word_19983C; // weak
int16_t word_199840; // weak
int16_t word_199842; // weak
int16_t word_199844; // weak
int16_t word_199846; // weak
int16_t word_199848; // weak
int16_t word_19984C; // weak
int16_t word_19984E; // weak
int16_t word_199850; // weak
int16_t word_199852; // weak
int16_t word_199854; // weak
int16_t word_199856; // weak
int16_t word_19985C; // weak
int16_t word_19985E; // weak
int16_t word_199860; // weak
int16_t word_199862; // weak
int16_t word_199864; // weak
int16_t word_199866; // weak
int16_t word_199876; // weak
int16_t word_199878; // weak
int16_t word_19987A; // weak
int16_t word_19987C; // weak
int16_t word_19987E; // weak
int16_t word_199880; // weak
int16_t word_199882; // weak
int16_t word_199884; // weak
int16_t word_199886; // weak
int16_t word_199888; // weak
int16_t word_19988A; // weak
int16_t word_19988C; // weak
int16_t word_19988E; // weak
int16_t word_199890; // weak
int16_t word_199892; // weak
int16_t word_199894; // weak
int16_t word_199896; // weak
int16_t word_199898; // weak
int16_t word_19989A; // weak
int16_t word_19989C; // weak
int16_t word_19989E; // weak
int16_t word_1998A0; // weak
int16_t word_1998A2; // weak
int16_t word_1998A4; // weak
int16_t word_1998A6; // weak
int16_t word_1998A8; // weak
int16_t word_1998AA; // weak
int16_t word_1998AC; // weak
int16_t word_1998AE; // weak
int16_t word_1998B0; // weak
int16_t word_1998B2; // weak
int16_t word_1998B4; // weak
int16_t word_1998B6; // weak
int16_t word_1998B8; // weak
int16_t word_1998BA; // weak
int16_t word_1998BC; // weak
int16_t word_1998BE; // weak
int16_t word_1998C0; // weak
int16_t word_1998C2; // weak
int16_t word_1998C4; // weak
int16_t word_1998C6; // weak
int16_t word_1998C8; // weak
int16_t word_1998CA; // weak
int16_t word_1998CC; // weak
int16_t word_1998CE; // weak
int16_t word_1998D0; // weak
int16_t word_1998D2; // weak
int16_t word_1998D4; // weak
int16_t word_1998D6; // weak
int16_t word_1998D8; // weak
int16_t word_1998DA; // weak
int16_t word_1998DC; // weak
int16_t word_1998DE; // weak
int16_t word_1998E0; // weak
int16_t word_1998E2; // weak
int16_t word_1998E4; // weak
int16_t word_1998E6; // weak
int16_t word_1998E8; // weak
int16_t word_1998EA; // weak
int16_t word_1998EC; // weak
int16_t word_1998EE; // weak
int16_t word_1998F0; // weak
int16_t word_1998F2; // weak
int16_t word_1998F4; // weak
int16_t word_1998F6; // weak
int16_t word_1998F8; // weak
int16_t word_1998FA; // weak
int16_t word_1998FC; // weak
int16_t word_1998FE; // weak
int16_t word_199900; // weak
int16_t word_199902; // weak
int16_t word_199904; // weak
int16_t word_199906; // weak
int16_t word_199908; // weak
int16_t word_19990A; // weak
int16_t word_19990C; // weak
int16_t word_19990E; // weak
int16_t word_199910; // weak
int16_t word_199912; // weak
int16_t word_19991A; // weak
int16_t word_19991C; // weak
int16_t word_19992A; // weak
int16_t word_19992C; // weak
int16_t word_19992E; // weak
int16_t word_199930; // weak
int16_t word_199932; // weak
int16_t word_199934; // weak
_UNKNOWN unk_19994A; // weak
int16_t word_19994C; // weak
int16_t word_19994E; // weak
int16_t word_199950; // weak
int16_t word_199954; // weak
int16_t word_199956; // weak
int16_t word_19995A; // weak
int16_t word_19995C; // weak
int16_t word_19995E; // weak
int16_t word_199960; // weak
int16_t word_199962; // weak
int16_t word_199964; // weak
int16_t word_199966; // weak
int16_t word_199968; // weak
int16_t word_19996A; // weak
int16_t word_19996E; // weak
int16_t word_199970; // weak
int16_t word_199972; // weak
int16_t word_199974; // weak
int16_t word_199976; // weak
int16_t word_19997A; // weak
int16_t word_19997C; // weak
int16_t word_19997E; // weak
int16_t word_199980; // weak
int16_t word_199982; // weak
int16_t word_199984; // weak
int16_t word_199986; // weak
int16_t word_199988; // weak
int16_t word_19998A; // weak
int16_t word_19998C; // weak
int16_t word_19998E; // weak
int16_t word_199990; // weak
int16_t word_199992; // weak
int16_t word_199994; // weak
int16_t word_199996; // weak
int16_t word_199998; // weak
int16_t word_19999A; // weak
int16_t word_19999C; // weak
int16_t word_19999E; // weak
int16_t word_1999A0; // weak
int16_t word_1999A2; // weak
int16_t word_1999A4; // weak
int16_t word_1999A6; // weak
int16_t word_1999A8; // weak
int16_t word_1999AA; // weak
int16_t word_1999AC; // weak
_UNKNOWN unk_1999AE; // weak
_UNKNOWN unk_1999B0; // weak
int16_t word_1999B2; // weak
_UNKNOWN unk_1999B6; // weak
int16_t word_1999B8; // weak
int16_t word_1999BA; // weak
int16_t word_1999BC; // weak
int16_t word_1999BE; // weak
int16_t word_1999C0; // weak
int16_t word_1999C2; // weak
int16_t word_1999C4; // weak
int16_t word_1999C6; // weak
int16_t word_1999C8; // weak
int16_t word_1999CA; // weak
int16_t word_1999CC; // weak
int16_t word_1999CE; // weak
int16_t word_1999D0; // weak
int16_t word_1999D4; // weak
int16_t word_1999D6; // weak
int16_t word_1999D8; // weak
int16_t word_1999DA; // weak
int16_t word_1999DC; // weak
int16_t word_1999DE; // weak
int16_t word_1999E0; // weak
int16_t word_1999E2; // weak
int16_t word_1999E4; // weak
int16_t word_1999E6; // weak
int16_t word_1999E8; // weak
int16_t word_1999EA; // weak
int16_t word_1999EC; // weak
int16_t word_1999EE; // weak
_UNKNOWN unk_1999F0; // weak
int16_t word_1999F2; // weak
int16_t word_1999F4; // weak
int16_t word_1999F6; // weak
int16_t word_1999F8; // weak
int16_t word_1999FC; // weak
int16_t word_1999FE; // weak
int16_t word_199A00; // weak
int16_t word_199A02; // weak
int16_t word_199A04; // weak
int16_t word_199A06; // weak
int16_t word_199A08; // weak
int16_t word_199A0A; // weak
int16_t word_199A0C; // weak
int16_t word_199A0E; // weak
int16_t word_199A10; // weak
char byte_199A12[30]; // weak
int16_t word_199A30; // weak
char byte_199A32; // weak
char byte_199A36; // weak
char byte_199A37; // weak
char byte_199A38; // weak
int16_t word_199A39; // weak
int16_t word_199A3B[4]; // weak
char byte_199A43; // weak
char byte_199A44; // weak
char byte_199A45; // weak
int16_t word_199A46; // weak
int16_t word_199A48; // weak
int16_t word_199A4A; // weak
int16_t word_199A4D; // weak
char byte_199A5D; // weak
char byte_199A5E[6]; // weak
int16_t word_199A64; // weak
char byte_199A66[]; // weak
char byte_199A67[]; // weak
int16_t word_199A68; // weak
int16_t word_199A6A; // weak
char byte_199A6C[]; // weak
char byte_199A6D[]; // weak
char byte_199A6E[78]; // weak
int16_t word_199ABC; // weak
char byte_199ABE; // weak
int16_t word_199ABF; // weak
char byte_199AC1; // weak
char byte_199AC2; // weak
char byte_199AC4[6]; // weak
char byte_199ACA[8]; // weak
int16_t word_199AD2; // weak
int16_t word_199AD4; // weak
int16_t word_199AD6; // weak
int16_t word_199ADC; // weak
int16_t word_199ADE; // weak
int16_t word_199B10; // weak
int16_t word_199B12; // weak
int16_t word_199B14; // weak
int16_t word_199B46; // weak
char byte_199B4A; // weak
char byte_199B4B[15]; // weak
_BYTE byte_199B5A[2]; // weak
char byte_199B5C; // weak
char byte_199B5F; // weak
int16_t word_199B60; // weak
char byte_199BA2[]; // weak
char byte_199BA3[9]; // weak
int16_t word_199BAC; // weak
int16_t word_199BAE; // weak
int16_t word_199BB0; // weak
int16_t word_199BB2; // weak
int16_t word_199BB4; // weak
int16_t word_199BB8; // weak
int16_t word_199BBA; // weak
int16_t word_199BBC; // weak
int dword_199BBE; // weak
int dword_199BC2; // weak
char byte_199BC6; // weak
char byte_199BC7; // weak
char byte_199BC8; // weak
char byte_199BC9; // weak
char byte_199BCA; // weak
char byte_199BCB; // weak
char byte_199BCC; // weak
int16_t word_199BCD; // weak
char byte_199BCF[4]; // weak
int16_t word_199BD3; // weak
char byte_199BD5; // weak

// State/settings block 0x199BDC..0x199E05 (553 B) - see TypeStateBlock_199BDC
// in orion_common.h (wave 18). Replaces ~52 individual IDA globals.
TypeStateBlock_199BDC stateBlock_199BDC;
char byte_199E05[63]; // weak
char byte_199E44[126]; // weak
char byte_199EC2[]; // weak
char byte_199EC3; // weak
char byte_199EC4; // weak
char byte_199EC5; // weak
char byte_199EC6; // weak
int16_t word_199EC7; // weak
int16_t word_199EC9; // weak
int16_t word_199ECB; // weak
int16_t word_199ECD; // weak
char byte_199ECF; // weak
int16_t word_199ED0; // weak
int16_t word_199ED2; // weak
int16_t word_199ED6; // weak
int16_t word_199ED8; // weak
int16_t word_199EDA; // weak
int16_t word_199EDC; // weak
int16_t word_199EDE; // weak
int16_t word_199EE0; // weak
int16_t word_199EE2; // weak
char byte_199EE8; // weak
char byte_199EEA; // weak
char byte_199EED; // weak
char byte_199EEF; // weak
char byte_199EF1; // weak
char byte_199EF2; // weak
char byte_199EF3; // weak
char byte_199EF4; // weak
char byte_199EF5; // weak
char byte_199EF6; // weak
char byte_199EF7; // weak
char byte_199EF9; // weak
char byte_199EFA; // weak
char byte_199EFB; // weak
char byte_199EFC; // weak
char byte_199EFE; // weak
char byte_199F00; // weak
char byte_199F01; // weak
char byte_199F02; // weak
char byte_199F03; // weak
char byte_199F04; // weak
char byte_199F05; // weak
char byte_199F06; // weak
char byte_199F07; // weak
char byte_199F08; // weak
char byte_199F09; // weak
char byte_199F0A; // weak
char byte_199F0C; // weak
char byte_199F0D; // weak
char byte_199F0E; // weak
char byte_199F0F; // weak
char byte_199F10; // weak
char byte_199F11; // weak
char byte_199F13; // weak
char byte_199F14; // weak
char byte_199F15; // weak
char byte_199F16; // weak
char byte_199F17; // weak
char byte_199F18; // weak
char byte_199F19; // weak
char byte_199F1A; // weak
char byte_199F1B; // weak
char byte_199F1C; // weak
char byte_199F1D; // weak
char byte_199F1E; // weak
char byte_199F1F; // weak
char byte_199F20; // weak
char byte_199F21; // weak
char byte_199F23; // weak
char byte_199F26; // weak
char byte_199F28; // weak
char byte_199F29; // weak
char byte_199F2A; // weak
char byte_199F2B; // weak
char byte_199F2C; // weak
char byte_199F2D; // weak
char byte_199F2F; // weak
char byte_199F30; // weak
char byte_199F31; // weak
char byte_199F32; // weak
char byte_199F33; // weak
char byte_199F34; // weak
char byte_199F35; // weak
char byte_199F36; // weak
char byte_199F37; // weak
char byte_199F38; // weak
char byte_199F39; // weak
char byte_199F3A; // weak

char byte_19A004; // weak
char byte_19A005; // weak
char byte_19A006; // weak
char byte_19A007; // weak
int dword_19A00C; // weak
int dword_19A010; // weak
int dword_19A014; // weak
int dword_19A018; // weak
int16_t word_19A01C; // weak
int16_t word_19A01E; // weak
int16_t word_19A020[]; // weak
int16_t word_19A022[]; // weak
char byte_19A030[40]; // weak
int dword_19A058[]; // weak
int dword_19A05C; // weak
int dword_19A060[]; // weak
int dword_19A080[]; // weak
char byte_19A0A0[20]; // weak
int16_t word_19A0B4; // weak
int16_t word_19A0B6; // weak
int dword_19A0B8; // weak
int dword_19A0BC; // weak
int dword_19A0C0; // weak
int dword_19A0C4; // weak
int16_t word_19A0C8[]; // weak
int16_t word_19A0CA; // weak
int dword_19A0CC; // weak
int dword_19A0D0; // weak
int16_t word_19A0D4; // weak
int16_t word_19A0D6; // weak
char byte_19A0D8[]; // weak
char byte_19A0D9; // weak
char byte_19A0DA; // weak
char byte_19A0DB; // weak
char byte_19A0DC; // weak
char byte_19A0DD; // weak
char byte_19A0DE; // weak
int16_t word_19A0E0; // weak
int16_t word_19A0E2; // weak
int16_t word_19A0E4; // weak
int dword_19A0E8[]; // weak
int dword_19A0EC; // weak
int dword_19A0F0; // weak
int dword_19A0F4; // weak
int dword_19A0F8; // weak
int dword_19A0FC; // weak
int16_t word_19A100[72]; // weak
char byte_19A190; // weak
char byte_19A191; // weak
int16_t word_19A192; // weak
int16_t word_19A194; // weak
int16_t word_19A196; // weak
int dword_19A198; // weak
int dword_19A19C; // weak
int dword_19A1A0[]; // weak
int dword_19A1A4; // weak
int dword_19A1A8; // weak
int dword_19A1AC; // weak
int dword_19A1B0; // weak
int dword_19A1B4; // weak
int dword_19A1B8; // weak
int dword_19A1BC[]; // weak
int dword_19A1C0; // weak
int dword_19A1C4; // weak
int dword_19A1C8; // weak
int dword_19A1CC; // weak
int dword_19A1D0; // weak
int dword_19A1D4; // weak
int dword_19A1D8; // weak
int dword_19A1DC; // weak
int dword_19A1E0; // weak
int dword_19A1E4; // weak
int dword_19A1E8[]; // weak
int dword_19A1EC; // weak
int dword_19A1F0; // weak
int dword_19A1F4; // weak
int dword_19A1F8; // weak
int dword_19A1FC; // weak
int dword_19A200[]; // weak
int dword_19A204; // weak
int dword_19A208; // weak
int dword_19A20C; // weak
int dword_19A210; // weak
int dword_19A214; // weak
int dword_19A218; // weak
int dword_19A21C[]; // weak
int dword_19A220; // weak
int dword_19A224; // weak
int dword_19A228; // weak
int dword_19A22C[]; // weak
int dword_19A230; // weak
int dword_19A234; // weak
int dword_19A238; // weak
int dword_19A23C; // weak
int dword_19A240; // weak
int dword_19A244; // weak
int dword_19A248[]; // weak
int dword_19A24C; // weak
int dword_19A250; // weak
int dword_19A254; // weak
int dword_19A258; // weak
int dword_19A25C; // weak
int dword_19A260; // weak
int dword_19A264; // weak
int dword_19A268; // weak
int dword_19A26C[]; // weak
int dword_19A270; // weak
int dword_19A274; // weak
int dword_19A278; // weak
int dword_19A27C; // weak
int dword_19A280; // weak
int dword_19A284; // weak
int dword_19A288; // weak
int dword_19A28C; // weak
int dword_19A290; // weak
int dword_19A294; // weak
int dword_19A298; // weak
int dword_19A29C; // weak
int dword_19A2A0; // weak
int dword_19A2A4; // weak
int dword_19A2A8; // weak
int dword_19A2AC; // weak
int dword_19A2B0; // weak
int dword_19A2B4; // weak
int dword_19A2B8; // weak
int dword_19A2BC; // weak
int dword_19A2C0; // weak
int dword_19A2C4; // weak
int dword_19A2C8; // weak
int dword_19A2CC; // weak
int dword_19A2D0; // weak
int dword_19A2D4; // weak
int dword_19A2D8; // weak
char byte_19A2DC[212]; // weak
char byte_19A3B0[212]; // weak
int16_t byte_19A484[50]; // weak
int dword_19A4E8; // weak
char byte_19A4EC; // weak
char byte_19A550[100]; // weak
int16_t word_19A5B4[]; // weak
int16_t word_19A5B6[]; // weak
int16_t word_19A5B8[]; // weak
int16_t word_19A5BA[]; // weak
int16_t word_19A5BC[]; // weak
char byte_19A64A; // weak
char byte_19A744[50]; // weak
char byte_19A776[50]; // weak
char byte_19A7A8; // weak
int16_t word_19AA34; // weak
int16_t word_19AA36; // weak
int16_t word_19AA3A; // weak
int16_t word_19AA3C; // weak
int16_t word_19AA3E; // weak
int16_t word_19AA40; // weak
int16_t word_19AA42; // weak
int16_t word_19AA44; // weak
int16_t word_19AA46; // weak
int16_t word_19AA48; // weak
int16_t word_19AA4A; // weak
int16_t word_19AA4C; // weak
int16_t word_19AA4E; // weak
int16_t word_19AA50; // weak
int16_t word_19AA52; // weak
int16_t word_19AA54; // weak
int16_t word_19AA56; // weak
int16_t word_19AA58; // weak
int16_t word_19AA5A; // weak
int16_t word_19AA5C; // weak
char byte_19AA5E[5]; // weak
char byte_19AA63; // weak
char byte_19AA64; // weak
char byte_19AA65; // weak
char byte_19AA66; // weak
char byte_19AA67; // weak
char byte_19AA68; // weak
char byte_19AA69; // weak
int dword_19AA6C; // weak
int dword_19AA70; // weak
_UNKNOWN unk_19AA74; // weak
int dword_19ABA0; // weak
char byte_19ABA4[]; // weak
char byte_19ABA5[]; // weak
char byte_19ABA6[]; // weak
int16_t word_19ABA7; // weak
int16_t word_19ABA9; // weak
int16_t word_19ABAB; // weak
char byte_19ABB6; // weak
char byte_19ABB7; // weak
int16_t word_19ABB9; // weak
char byte_19ABF6; // weak
char byte_19AC22; // weak
char byte_19AC23; // weak
int16_t word_19AC25; // weak
char byte_19AC34; // weak
char byte_19AC35; // weak
int16_t word_19AC37; // weak
char byte_19AC3D; // weak
char byte_19AC3E; // weak
int16_t word_19AC40; // weak
char byte_19AC50; // weak
char byte_19AC7C; // weak
char byte_19AC7D; // weak
int16_t word_19AC7F; // weak
char byte_19AC85; // weak
char byte_19AC86; // weak
int16_t word_19AC88; // weak
char byte_19AC8F; // weak
char byte_19ACA9; // weak
char byte_19ACAA; // weak
char byte_19ACB2; // weak
char byte_19ACB3; // weak
int16_t word_19ACB5; // weak
int16_t word_19ACB7; // weak
char byte_19ACBC; // weak
int16_t word_19ACC0; // weak
char byte_19ACC4; // weak
char byte_19ACC5; // weak
char byte_19ACCD; // weak
char byte_19ACCE; // weak
char byte_19ACD6; // weak
char byte_19ACD7; // weak
int16_t word_19ACD9; // weak
char byte_19ACDF; // weak
char byte_19ACE0; // weak
int16_t word_19ACE2; // weak
int dword_19ACE8; // weak
int16_t word_19ACEC; // weak
char byte_19ACEF; // weak
char byte_19ACF0; // weak
_UNKNOWN unk_19ACF3; // weak
int16_t word_19ACF4; // weak
char byte_19ACF7[]; // weak
int dword_19ACF8; // weak
char byte_19ACFC[1051]; // weak
int dword_19B117; // weak
char byte_19B11B[]; // weak
int dword_19B11C; // weak
char byte_19B120[1056]; // weak
int16_t word_19B540; // weak
char byte_19B544[]; // weak
char byte_19B545; // weak
char byte_19B546; // weak
char byte_19B547; // weak
char byte_19B548; // weak
char byte_19B549; // weak
char byte_19B54A; // weak
char byte_19B54B; // weak
int dword_19B554; // weak
int dword_19B558; // weak
int dword_19B55C; // weak
int dword_19B560; // weak
int dword_19B564; // weak
int (*dword_19B568)(void); // weak
int16_t word_19B56C; // weak
int16_t word_19B56E; // weak
int16_t word_19B570; // weak
int dword_19B574; // weak
int16_t word_19B578; // weak
char byte_19B57C; // weak
int16_t word_19B580; // weak
int16_t word_19B582; // weak
char byte_19B584; // weak
char byte_19B587; // weak
int dword_19B588[64]; // weak
char byte_19B688[]; // weak
char byte_19B689; // weak
char byte_19B68A; // weak
int dword_19B690; // weak
int16_t word_19B694[]; // weak
int16_t word_19B696; // weak
int16_t word_19B6A6; // weak
int16_t word_19B6A8[16]; // weak
int16_t word_19B6C8[]; // weak
int16_t word_19B6CA[5]; // weak
int dword_19B6D4; // weak
int dword_19B6D8; // weak
int16_t word_19B6DC[]; // weak
int16_t word_19B6DE; // weak
int16_t word_19B6E6; // weak
int16_t word_19B6E8; // weak
int16_t word_19B6EC; // weak
int16_t word_19B6EE; // weak
int16_t word_19B6F0; // weak
int16_t word_19B6F2; // weak
int16_t word_19B6F4; // weak
int16_t word_19B6F6; // weak
int dword_19B70C; // weak
int dword_19B710; // weak
int16_t word_19B714[41]; // weak
int16_t word_19B766; // weak
int16_t word_19B768; // weak
int16_t word_19B76A; // weak
int16_t word_19B76C; // weak
int16_t word_19B76E; // weak
int16_t word_19B770; // weak
int16_t word_19B772[25]; // weak
int dword_19B7A4[13]; // weak
int dword_19B7D8; // weak
int dword_19B7DC[13]; // weak
int dword_19B810; // weak
char byte_19B814[8]; // weak
int dword_19B81C; // weak
int16_t word_19B820[3]; // weak
int16_t word_19B826; // weak
_UNKNOWN unk_19B83A; // weak
int dword_19B840; // weak
char byte_19B848[14]; // weak
int16_t word_19B856; // weak
int16_t word_19B858; // weak
int16_t word_19B85A; // weak
_UNKNOWN unk_19B85C; // weak
int dword_19B86C; // weak
int dword_19B870; // weak
int dword_19B874; // weak
int dword_19B878; // weak
int dword_19B87C; // weak
int16_t word_19B880; // weak
int dword_19B884; // weak
int dword_19B888; // weak
int dword_19B88C; // weak
int dword_19B890; // weak
int dword_19B894; // weak
char byte_19B89A; // weak
char byte_19B89C[200]; // weak
int16_t word_19B964; // weak
int16_t word_19B966; // weak
int16_t word_19B968; // weak
int16_t word_19B96A; // weak
int16_t word_19B96C; // weak
int16_t word_19B96E; // weak
int16_t word_19B970; // weak
int16_t word_19B972; // weak
int16_t word_19B974; // weak
int16_t word_19B976; // weak
int16_t word_19B978; // weak
int16_t word_19B97A; // weak
int16_t word_19B97C; // weak
int16_t word_19B97E; // weak
char byte_19B980[5]; // weak
char byte_19B985[15]; // weak
char byte_19B994; // weak
char byte_19B995; // weak
int dword_19B998; // weak
int dword_19B99C; // weak
int dword_19B9A0; // weak
int dword_19B9A4; // weak
int dword_19B9A8; // weak
char byte_19B9AC[6]; // weak
int16_t word_19B9B2; // weak
int16_t word_19B9B4; // weak
int16_t word_19B9B6; // weak
char byte_19B9B8; // weak
char byte_19B9B9; // weak
char byte_19B9BA; // weak
_UNKNOWN unk_19B9BC; // weak
_UNKNOWN unk_19BA34; // weak
int16_t word_19BA38[78]; // weak
_UNKNOWN unk_19BAD4; // weak
_UNKNOWN unk_19BB4C; // weak
_UNKNOWN unk_19BB4E; // weak
_UNKNOWN unk_19BB50; // weak
_UNKNOWN unk_19BB52; // weak
_UNKNOWN unk_19BB54; // weak
_WORD word_19BC14[60]; // weak
int dword_19BC8C; // weak
_UNKNOWN unk_19BC90; // weak
int16_t word_19BC94[163]; // weak
_UNKNOWN unk_19BD44; // weak
_UNKNOWN unk_19BD46; // weak
_UNKNOWN unk_19BD48; // weak
_UNKNOWN unk_19BD4A; // weak
_UNKNOWN unk_19BD4C; // weak
_UNKNOWN unk_19BDDA; // weak
_UNKNOWN unk_19BE34; // weak
int16_t word_19BE74; // weak
int16_t word_19BE78; // weak
int16_t word_19BE7E; // weak
int16_t word_19BE82; // weak
int16_t word_19BEB6; // weak
int16_t word_19BEB8; // weak
char byte_19BEBC; // weak
int dword_19BEC0; // weak
int dword_19BEC4; // weak
int16_t word_19BEC8; // weak
int16_t word_19BECA; // weak
int16_t word_19BECC; // weak
int16_t word_19BECE; // weak
char byte_19BED0; // weak
char byte_19BED1; // weak
int dword_19BED4; // weak
int (*dword_19BED8)(void); // weak
int dword_19BEDC[]; // weak
int dword_19BEE0; // weak
int dword_19BEE4; // weak
_UNKNOWN unk_19BEE8; // weak
int16_t word_19BEFA; // weak
int16_t word_19BEFC; // weak
int16_t word_19BEFE; // weak
int16_t word_19BF00; // weak
int16_t word_19BF02; // weak
int16_t word_19BF04; // weak
int16_t word_19BF06; // weak
_UNKNOWN unk_19BF0C; // weak
int16_t word_19BFC0; // weak
char byte_19BFC4; // weak
int16_t word_19BFC8[8]; // weak
int dword_19BFD8; // weak
int dword_19BFE0; // weak
int dword_19BFE4; // weak
char byte_19BFE8[6]; // weak
char byte_19BFEE[6]; // weak
char byte_19BFF4[6]; // weak
char byte_19BFFA[6]; // weak
char byte_19C000[6]; // weak
char byte_19C006[6]; // weak
char byte_19C00C[5]; // weak
_UNKNOWN unk_19C011; // weak
char byte_19C012[6]; // weak
char byte_19C018[6]; // weak
char byte_19C01E[6]; // weak
char byte_19C024[6]; // weak
char byte_19C02A[10]; // weak
int dword_19C034; // weak
int dword_19C038; // weak
int dword_19C044; // weak
int16_t word_19C048[10]; // weak
int16_t word_19C05C; // weak
int16_t word_19C060; // weak
char byte_19C062; // weak
char byte_19C064; // weak
char byte_19C066; // weak
char byte_19C068; // weak
char byte_19C06A; // weak
int dword_19C06C; // weak
int dword_19C070; // weak
int dword_19C074; // weak
int dword_19C078; // weak
int dword_19C07C; // weak
int dword_19C080; // weak
int dword_19C084; // weak
int dword_19C088; // weak
int dword_19C08C; // weak
int dword_19C090; // weak
int16_t word_19C094; // weak
int16_t word_19C096; // weak
int16_t word_19C098; // weak
char byte_19C09A; // weak
char byte_19C09D; // weak
char byte_19C09E; // weak
int16_t word_19C0A0[]; // weak
int16_t word_19C0A2[]; // weak
int16_t word_19C0A4[30]; // weak
int16_t word_19C0E0[]; // weak
int16_t word_19C0E2[]; // weak
int16_t word_19C0E4[]; // weak
int16_t word_19C0E6[29]; // weak
char byte_19C120[]; // weak
int dword_19C128[8]; // weak
char byte_19C148[]; // weak
int dword_19C150; // weak
int16_t word_19C154; // weak
int16_t word_19C158; // weak
int16_t word_19C15A; // weak
int16_t word_19C15C; // weak
int16_t word_19C15E; // weak
int16_t word_19C160; // weak
int16_t word_19C162; // weak
int16_t word_19C164; // weak
int16_t word_19C166; // weak
int16_t word_19C168; // weak
int16_t word_19C16A; // weak
int16_t word_19C16E; // weak
int16_t word_19C170; // weak
int16_t word_19C172; // weak
int16_t word_19C174; // weak
int16_t word_19C176; // weak
int16_t word_19C178; // weak
int16_t word_19C17A; // weak
int16_t word_19C17C; // weak
int16_t word_19C17E; // weak
int16_t word_19C180; // weak
int16_t word_19C182; // weak
int16_t word_19C184; // weak
int16_t word_19C186; // weak
int16_t word_19C188; // weak
int16_t word_19C18A; // weak
int16_t word_19C18C; // weak
char byte_19C18E; // weak
char byte_19C18F; // weak
char byte_19C190; // weak
char byte_19C191; // weak
char byte_19C192; // weak
char byte_19C193; // weak
char byte_19C194; // weak
char byte_19C195; // weak
char byte_19C196; // weak
char byte_19C197; // weak
char byte_19C198; // weak
char byte_19C199; // weak
char byte_19C19A; // weak
char byte_19C19B; // weak
char byte_19C19C; // weak
char byte_19C19D; // weak
char byte_19C19E; // weak
char byte_19C19F; // weak
char byte_19C1A0; // weak
char byte_19C1A1; // weak
char byte_19C1A2; // weak
int16_t word_19C204; // weak
int16_t word_19C206; // weak
int16_t word_19C208; // weak
int16_t word_19C20A; // weak
int dword_19C20C[17]; // weak
int dword_19C250[27]; // weak
int dword_19C2BC; // weak
int dword_19C2C0; // weak
int dword_19C2C4; // weak
int dword_19C2CC; // weak
int dword_19C2D0; // weak
_UNKNOWN unk_19C2D4; // weak
int dword_19C2E0; // weak
int dword_19C2E4; // weak
int dword_19C2E8; // weak
int16_t word_19C2EC; // weak
int16_t word_19C2EE; // weak
int16_t word_19C2F0; // weak
int16_t word_19C2F2; // weak
char byte_19C2F4[36]; // weak
char byte_19C318; // weak
char byte_19C319; // weak
char byte_19C31A; // weak
char byte_19C31C[]; // weak
char byte_19C31D; // weak
char byte_19C31E; // weak
char byte_19C31F; // weak
char byte_19C320; // weak
char byte_19C321; // weak
char byte_19C322; // weak
char byte_19C323; // weak
char byte_19C324; // weak
int dword_19C330; // weak
int dword_19C334; // weak
_UNKNOWN unk_19C338; // weak
char byte_19C340; // weak
char byte_19C348[59]; // weak
char byte_19C383; // weak
int16_t word_19C384; // weak
char byte_19C386; // weak
int16_t word_19C387; // weak
int16_t word_19C389; // weak
int16_t word_19C38B; // weak
int16_t word_19C38D; // weak
int16_t word_19C38F; // weak
int16_t word_19C391; // weak
int16_t word_19C393; // weak
int16_t word_19C395; // weak
int16_t word_19C397; // weak
int16_t word_19C399; // weak
int16_t word_19C39B; // weak
char byte_19C39D[99]; // weak
char byte_19C400; // weak
int16_t word_19C401; // weak
int16_t word_19C403; // weak
int16_t word_19C408[5]; // weak
int16_t word_19C412[35]; // weak
int dword_19C458; // weak
int dword_19C45C[27]; // weak
int dword_19C4C8; // weak
int dword_19C4CC[27]; // weak
int16_t word_19C538; // weak
int16_t word_19C53A; // weak
int16_t word_19C53C; // weak
int16_t word_19C53E; // weak
int16_t word_19C540; // weak
char byte_19C542; // weak
char byte_19C543; // weak
char byte_19C544; // weak
char byte_19C545; // weak
char byte_19C546; // weak
char byte_19C547; // weak
char byte_19C548; // weak
char byte_19C54C[72]; // weak
int dword_19C594; // weak
int dword_19C598; // weak
int dword_19C59C; // weak
int dword_19C5A0; // weak
int dword_19C5A4; // weak
int16_t word_19C5AA; // weak
int16_t word_19C5AC; // weak
int16_t word_19C5AE; // weak
int16_t word_19C5B0; // weak
char byte_19C5B2[45]; // weak
char byte_19C5DF; // weak
char byte_19C5E0; // weak
char byte_19C5E1; // weak
char byte_19C5E2; // weak
char byte_19C5E3; // weak
char byte_19C5E4; // weak
char byte_19C5E5; // weak
char byte_19C5E7; // weak
char byte_19C5E8; // weak
char byte_19C5E9; // weak
char byte_19C5EA; // weak
int16_t word_19C5FC; // weak
char byte_19C5FE[200]; // weak
int16_t word_19C6C6[]; // weak
int16_t word_19C6C8[9]; // weak
int16_t word_19C6DA[]; // weak
int16_t word_19C6DC[9]; // weak
char byte_19C6EE[]; // weak
char byte_19C6EF[9]; // weak
char byte_19C6F8[28]; // weak
char byte_19C714[]; // weak
int dword_19C7C0; // weak
int16_t word_19C7C4; // weak
char byte_19C7C6[15]; // weak
char byte_19C7D5[15]; // weak
char byte_19C7E4[15]; // weak
char byte_19C7F3[15]; // weak
int16_t word_19C802[8]; // weak
char byte_19C813[2561]; // weak
int dword_19D214; // weak
int dword_19D218; // weak
int dword_19D21C; // weak
int dword_19D220; // weak
int dword_19D224; // weak
char byte_19D228[260]; // weak
char byte_19D32C; // weak
char byte_19D32D; // weak
char byte_19D32F; // weak
_UNKNOWN unk_19D330; // weak
int dword_19D354; // weak
int (*dword_19D358)(void); // weak
int16_t word_19D35C; // weak
int16_t word_19D35E; // weak
int16_t word_19D360; // weak
int16_t word_19D364; // weak
int16_t word_19D366; // weak
char byte_19D36A; // weak
int dword_19D36B; // weak
int dword_19D390; // weak
int dword_19D410; // weak
int dword_19D510[43]; // weak
int dword_19D5BC; // weak
int dword_19D5C0; // weak
int16_t word_19D5D4; // weak
int16_t word_19D5D6; // weak
int16_t word_19D5D8; // weak
int16_t word_19D5DA; // weak
int16_t word_19D5DC; // weak
int16_t word_19D5DE; // weak
char byte_19D5E0[444]; // weak
int16_t word_19D79C[40]; // weak
int16_t word_19D7EC[40]; // weak
int16_t word_19D83C[40]; // weak
int dword_19D88C[40]; // weak
int dword_19D92C[40]; // weak
int dword_19D9CC[40]; // weak
char byte_19DA6C[800]; // weak
int dword_19DD8C; // weak
int dword_19DD90; // weak
int dword_19DD94; // weak
int dword_19DD98[]; // weak
int dword_19DD9C; // weak
int dword_19DDA0; // weak
int dword_19DDA4; // weak
int dword_19DDA8; // weak
int dword_19DDAC; // weak
int dword_19DDB0; // weak
int16_t word_19DDB4[54]; // weak
int16_t word_19DE20[54]; // weak
int dword_19DE8C; // weak
int16_t word_19DE90; // weak
int16_t word_19DE92; // weak
int16_t word_19DE94; // weak
int16_t word_19DE96; // weak
int16_t word_19DE98; // weak
int16_t word_19DE9A; // weak
int16_t word_19DE9C; // weak
int16_t word_19DE9E; // weak
int16_t word_19DEA0; // weak
int16_t word_19DEA2; // weak
int16_t word_19DEA4; // weak
int16_t word_19DEA6; // weak
int16_t word_19DEA8; // weak
int16_t word_19DEAA; // weak
int16_t word_19DEAC; // weak
int dword_19DEB0; // weak
int dword_19DEB4; // weak
int dword_19DEB8; // weak
int16_t word_19DEBC; // weak
int16_t word_19DEBE; // weak
int dword_19DEC0; // weak
int16_t word_19DEC4; // weak
int16_t word_19DEC6; // weak
int16_t word_19DEC8; // weak
char byte_19DECA[]; // weak
int16_t word_19DECB; // weak
char byte_19DECD[]; // weak
char byte_19DECE[370]; // weak
int16_t word_19E040[]; // weak
int16_t word_19E044[]; // weak
int16_t word_19E046[]; // weak
int16_t word_19E048[632]; // weak
_UNKNOWN unk_19E538; // weak
_UNKNOWN unk_19E562; // weak
_UNKNOWN unk_19E564; // weak
int16_t word_19E574[4]; // weak
char byte_19E57C[]; // weak
char byte_19E57D[]; // weak
char byte_19E57E[]; // weak
char byte_19E57F[]; // weak
char byte_19E580[1396]; // weak
int dword_19EAF4[]; // weak
int dword_19EAF8[]; // weak
int dword_19EAFC[]; // weak
int dword_19EB00[]; // weak
int dword_19EB04[]; // weak
int dword_19EB08; // weak
int dword_19EB0C; // weak
int dword_19EB10; // weak
int dword_19EB14; // weak
int dword_19EB18; // weak
int dword_19EB1C; // weak
int dword_19EB20; // weak
int dword_19EB24; // weak
int dword_19EB28; // weak
int dword_19EB2C; // weak
int dword_19EB30; // weak
int dword_19EB34; // weak
int dword_19EB38; // weak
int dword_19EB3C; // weak
int dword_19EB40; // weak
int dword_19EB44; // weak
int dword_19EB48; // weak
int dword_19EB4C; // weak
int dword_19EB50; // weak
int dword_19EB54; // weak
int dword_19EB58; // weak
int dword_19EB5C; // weak
int dword_19EB60; // weak
int dword_19EB64; // weak
int dword_19EB68; // weak
int dword_19EB6C; // weak
int dword_19EB70; // weak
int dword_19EB74; // weak
int dword_19EB78; // weak
int dword_19EB7C; // weak
int dword_19EB80; // weak
int dword_19EB84; // weak
int dword_19EB88; // weak
int dword_19EB8C; // weak
int dword_19EB90; // weak
int16_t word_19EB94[]; // weak
int16_t word_19EB96[]; // weak
char byte_19EB99[]; // weak
char byte_19EB9A[]; // weak
char byte_19EB9B[]; // weak
char byte_19EB9C[]; // weak
char byte_19EBA0[]; // weak
int dword_19EBA1; // weak
char byte_19EF81[]; // weak
char byte_19EF82[]; // weak
char byte_19EF84[]; // weak
char byte_19EF88[988]; // weak
int dword_19F364; // weak
int dword_19F368; // weak
int dword_19F36C; // weak
int dword_19F378; // weak
int dword_19F37C; // weak
int16_t word_19F380; // weak
int16_t word_19F382; // weak
int16_t word_19F384; // weak
int16_t word_19F386; // weak
int16_t word_19F388; // weak
int dword_19F38C; // weak
int dword_19F390; // weak
int dword_19F394; // weak
int dword_19F398; // weak
int dword_19F39C; // weak
int16_t word_19F3A0; // weak
int16_t word_19F71C[70]; // weak
int dword_19F7A8; // weak
int dword_19F7B0; // weak
int dword_19F7B4; // weak
int dword_19F7B8; // weak
int dword_19F7BC; // weak
int dword_19F7C0; // weak
int dword_19F7C4; // weak
int dword_19F7C8; // weak
int dword_19F7CC; // weak
int16_t word_19F7D4[42]; // weak
int dword_19F828; // weak
int dword_19F82C; // weak
_UNKNOWN unk_19F888; // weak
int16_t word_19F984[12]; // weak
int16_t word_19F99C[]; // weak
int16_t word_19F99E[8]; // weak
int16_t word_19F9AE; // weak
int16_t word_19F9BA[]; // weak
int16_t word_19F9C0[5]; // weak
int16_t word_19F9CA[5]; // weak
_WORD word_19F9D4[3]; // weak
int16_t word_19F9DA[3]; // weak
int16_t word_19F9E0[]; // weak
int16_t word_19F9E8; // weak
int16_t word_19F9EA[2]; // weak
int16_t word_19F9EE; // weak
int16_t word_19F9F0; // weak
int16_t word_19F9FA; // weak
int16_t word_19F9FC; // weak
int16_t word_19F9FE; // weak
int16_t word_19FA00; // weak
int16_t word_19FA02; // weak
int16_t word_19FA04; // weak
int16_t word_19FA06[6]; // weak
int16_t word_19FA12; // weak
int dword_19FA14; // weak
int dword_19FA18; // weak
int (*dword_19FA1C)(void); // weak
int dword_19FA20; // weak
int16_t word_19FA26; // weak
int16_t word_19FA28; // weak
int dword_19FA2C[]; // weak
int dword_19FA30; // weak
int dword_19FA34; // weak
int dword_19FA38; // weak
int dword_19FA3C; // weak
int dword_19FA40; // weak
int dword_19FA44; // weak
int dword_19FA48; // weak
int dword_19FA4C; // weak
int dword_19FA50; // weak
int dword_19FA54; // weak
int dword_19FA58; // weak
int dword_19FA5C; // weak
int dword_19FA60; // weak
int dword_19FA64; // weak
int dword_19FA68; // weak
int dword_19FA6C; // weak
int dword_19FA70; // weak
int dword_19FA74; // weak
int dword_19FA78; // weak
int dword_19FA7C; // weak
int dword_19FA80; // weak
int dword_19FA84; // weak
int dword_19FA88; // weak
int dword_19FA8C; // weak
int dword_19FA90; // weak
int dword_19FA94; // weak
int dword_19FA98; // weak
int dword_19FA9C; // weak
int dword_19FAA0; // weak
int dword_19FAA4; // weak
int dword_19FAA8; // weak
int dword_19FAAC; // weak
int dword_19FAB0; // weak
int dword_19FAB4; // weak
int dword_19FAB8; // weak
_UNKNOWN unk_19FABC; // weak
int16_t word_1A0494[10]; // weak
_UNKNOWN unk_1A04A8; // weak
int16_t word_1A04E4[10]; // weak
int16_t word_1A04F8[30]; // weak
int16_t word_1A0534[9]; // weak
int16_t word_1A0546; // weak
int16_t word_1A0548[10]; // weak
_UNKNOWN unk_1A055C; // weak
int16_t word_1A0598[10]; // weak
int16_t word_1A05AC; // weak
int16_t word_1A0694[8]; // weak
int16_t word_1A06A4; // weak
int16_t word_1A06A6; // weak
int16_t word_1A06A8; // weak
int16_t word_1A06AA; // weak
_UNKNOWN unk_1A06AC; // weak
_WORD word_1A08A4[6]; // weak
int dword_1A08B0; // weak
int16_t word_1A08B4[6]; // weak
int16_t word_1A08C0[12]; // weak
_WORD word_1A08D8[6]; // weak
int16_t word_1A08E4[]; // weak
int (*dword_1A08F0)(void); // weak
_DWORD dword_1A08F4; // weak
int dword_1A08F8; // weak
int dword_1A08FC; // weak
int16_t word_1A0904[]; // weak
int16_t word_1A0906[]; // weak
int16_t word_1A0908[]; // weak
int dword_1A090A; // weak
int16_t word_1A09FE; // weak
int16_t word_1A0A00; // weak
int16_t word_1A0A02; // weak
int16_t word_1A0A04; // weak
int16_t word_1A0A06; // weak
int16_t word_1A0A08; // weak
int dword_1A0A0A; // weak
int16_t word_1A0A0E; // weak
int dword_1A0A10; // weak
char byte_1A0A14[556]; // weak
int dword_1A0C40[]; // weak
int dword_1A0C60; // weak
int16_t word_1A0C64[]; // weak
int16_t word_1A0C66[]; // weak
int16_t word_1A0C68[]; // weak
int dword_1A0C6A[]; // weak
char byte_1A0C6E[]; // weak
char byte_1A0C6F[1189]; // weak
int dword_1A1114; // weak
int dword_1A1118; // weak
int dword_1A1120; // weak
int dword_1A1124; // weak
int dword_1A112C; // weak
int dword_1A1130; // weak
int dword_1A1134; // weak
int dword_1A1138; // weak
int dword_1A113C; // weak
int dword_1A1140; // weak
int dword_1A1144; // weak
int dword_1A1148; // weak
int dword_1A114C; // weak
int dword_1A1150; // weak
int dword_1A1154; // weak
int dword_1A1158; // weak
int dword_1A115C; // weak
int dword_1A1160; // weak
int dword_1A1164; // weak
int dword_1A1168; // weak
int dword_1A116C; // weak
int dword_1A1170; // weak
int dword_1A1174; // weak
int dword_1A1178; // weak
int dword_1A117C; // weak
int dword_1A1180; // weak
int dword_1A1184; // weak
int dword_1A1188; // weak
int dword_1A118C; // weak
int dword_1A1190; // weak
int dword_1A1194; // weak
int dword_1A1198; // weak
int dword_1A119C; // weak
int dword_1A11A0; // weak
int dword_1A11A4; // weak
int dword_1A11A8; // weak
int dword_1A11AC; // weak
int (*dword_1A11B0)(void); // weak
int dword_1A11B4; // weak
int dword_1A11B8; // weak
int (*dword_1A11BC)(void); // weak
int dword_1A11C0; // weak
int16_t word_1A11C4; // weak
int16_t word_1A11C6; // weak
int16_t word_1A11C8; // weak
int16_t word_1A11CA; // weak
int16_t word_1A11CE; // weak
int16_t word_1A11D0; // weak
int16_t word_1A11D2; // weak
int16_t word_1A11D4; // weak
int16_t word_1A11D6; // weak
int16_t word_1A11D8; // weak
int16_t word_1A11DA; // weak
int16_t word_1A11DC; // weak
int16_t word_1A11DE; // weak
int16_t word_1A11E0; // weak
int16_t word_1A11E2; // weak
int16_t word_1A11E4; // weak
int16_t word_1A11E6; // weak
int16_t word_1A11E8; // weak
int16_t word_1A11EA; // weak
int16_t word_1A11EC; // weak
int16_t word_1A11EE; // weak
int16_t word_1A11F0; // weak
int16_t word_1A11F2; // weak
int16_t word_1A11F4; // weak
int16_t word_1A11F6; // weak
_UNKNOWN unk_1A11F8; // weak
int16_t word_1A122E; // weak
int16_t word_1A1230; // weak
int16_t word_1A1232; // weak
int16_t word_1A1234; // weak
int16_t word_1A1236; // weak
int16_t word_1A1238; // weak
int16_t word_1A123A; // weak
int16_t word_1A123C; // weak
int16_t word_1A123E; // weak
int16_t word_1A1240; // weak
int dword_1A1244; // weak
int dword_1A1248; // weak
int dword_1A124C[4]; // weak
char byte_1A125C[]; // weak
char byte_1A125D; // weak
char byte_1A125E; // weak
char byte_1A125F; // weak
int dword_1A1260[]; // weak
int dword_1A1264[4]; // weak
int dword_1A1274; // weak
int dword_1A1278; // weak
int dword_1A127C; // weak
int dword_1A1280; // weak
int dword_1A1284; // weak
int dword_1A1288; // weak
int dword_1A128C; // weak
int dword_1A1290; // weak
int dword_1A1294; // weak
int dword_1A1298; // weak
int dword_1A129C; // weak
int dword_1A12A0; // weak
int dword_1A12A4; // weak
_UNKNOWN unk_1A12A8; // weak
int dword_1A12BC; // weak
int dword_1A12C0; // weak
int dword_1A12C4; // weak
int dword_1A12C8; // weak
int dword_1A12CC; // weak
int dword_1A12D0; // weak
int dword_1A12D4[]; // weak
int dword_1A12D8[5]; // weak
int dword_1A12EC; // weak
int dword_1A12F0; // weak
int dword_1A12F4; // weak
int dword_1A12F8; // weak
int dword_1A12FC[]; // weak
int dword_1A1300[]; // weak
int dword_1A1310[]; // weak
int dword_1A1314[6]; // weak
int dword_1A132C[]; // weak
int dword_1A1330[3]; // weak
int16_t word_1A133C; // weak
int16_t word_1A133E; // weak
int16_t word_1A1340; // weak
int16_t word_1A1342; // weak
int16_t word_1A1346; // weak
int16_t word_1A1348; // weak
int16_t word_1A134A; // weak
int16_t word_1A134C; // weak
int dword_1A1354; // weak
int16_t word_1A1358; // weak
int16_t word_1A135A; // weak
int16_t word_1A135C; // weak
int16_t word_1A135E; // weak
int16_t word_1A1360; // weak
int16_t word_1A1362; // weak
int16_t word_1A1364; // weak
int16_t word_1A1366; // weak
int dword_1A1368; // weak
int16_t word_1A136C; // weak
_UNKNOWN unk_1A1370; // weak
// PORT (wave 23): Hex-Rays sized this at 368 (the gap to the next BSS symbol
// dword_1A6B38), but sub_CDF65's string-table loader (orion_part_13.c) writes
// index 0..0x32Bh (811) unconditionally - confirmed in Debug/diss/Orion2.exe.asm
// (`cmp eax, 32Ch` in sub_CDF65). Both this array and dword_1A6B38 are `dd ?`
// (uninitialized BSS) in the original - the 368 "boundary" was just the next
// symbol IDA happened to find, not a real limit. Sized to the real 812 needed.
int dword_1A6578[812]; // weak
// PORT (wave 23): sub_CDF65 (orion_part_13.c) treats this as a POINTER
// (`v6 = (_DWORD*)dword_1A6B38; *v6 = ...`) and copies a 13-byte localized LBX
// filename (e.g. "MAINTEXT.LBX\0") into `*v6` via four chunked int/byte writes.
// Declared as a scalar int (always 0), this always wrote through a NULL
// pointer - crashed here once the earlier array-overflow bugs upstream of it
// stopped masking this path. This global IS the destination buffer itself
// (never read back anywhere else in the game - dead/write-only data even in
// the original, per its single XREF in Debug/diss/Orion2.exe.asm), so it needs
// to be the buffer's own storage, not a pointer variable pointing elsewhere.
char dword_1A6B38[16]; // weak
int dword_1A6F88; // weak
int (*dword_1A722C[2])(void); // weak
char byte_1A7234[]; // weak
char byte_1A7235[]; // weak
char byte_1A7236[22]; // weak
char byte_1A724C[8]; // weak
int dword_1A7254[]; // weak
char byte_1A7274[]; // weak
char byte_1A7275[15]; // weak
char byte_1A7284[]; // weak
char byte_1A7285[15]; // weak
int dword_1A7294[]; // weak
int dword_1A72B8[]; // weak
int dword_1A72BC; // weak
int dword_1A72C0[]; // weak
int dword_1A72C4[]; // weak
int dword_1A72C8[99]; // weak
int dword_1A7454[]; // weak
int dword_1A7458[]; // weak
int dword_1A745C[22]; // weak
_UNKNOWN unk_1A8B34; // weak
int dword_1AA1B4; // weak
int dword_1AA1B8; // weak
int dword_1AA1BC; // weak
int dword_1AA1C0; // weak
int dword_1AA1C4; // weak
int dword_1AA1C8; // weak
int dword_1AA1CC; // weak
int dword_1AA1D0; // weak
int dword_1AA1D4; // weak
int dword_1AA1D8; // weak
int dword_1AA1DC; // weak
int dword_1AA1E0; // weak
int dword_1AA1E4; // weak
int dword_1AA1E8; // weak
int dword_1AA1EC; // weak
int dword_1AA1F0; // weak
int dword_1AA1F4; // weak
int dword_1AA1F8; // weak
int dword_1AA1FC; // weak
int dword_1AA200; // weak
int dword_1AA204; // weak
int dword_1AA208; // weak
int dword_1AA20C; // weak
int dword_1AA210; // weak
int dword_1AA214; // weak
int16_t word_1AA218; // weak
int dword_1AA21C; // weak
int dword_1AA220; // weak
int dword_1AA224; // weak
int dword_1AA228; // weak
int dword_1AA22C; // weak
int dword_1AA230; // weak
int16_t word_1AA234; // weak
int16_t word_1AA236; // weak
int16_t word_1AA238; // weak
int16_t word_1AA23A; // weak
int dword_1AA23C; // weak
int dword_1AA240; // weak
int dword_1AA244; // weak
int dword_1AA248; // weak
int16_t word_1AA24C; // weak
int16_t word_1AA24E; // weak
int dword_1AA250; // weak
int dword_1AA254; // weak
int dword_1AA258; // weak
int dword_1AA25C; // weak
int dword_1AA260; // weak
int dword_1AA264; // weak
int dword_1AA268; // weak
int dword_1AA26C; // weak
int dword_1AA270; // weak
int dword_1AA274; // weak
int dword_1AA278; // weak
int dword_1AA27C; // weak
int dword_1AA280; // weak
int dword_1AA284; // weak
int dword_1AA288; // weak
int dword_1AA28C; // weak
int dword_1AA290; // weak
int dword_1AA294; // weak
int dword_1AA298; // weak
int dword_1AA29C; // weak
int dword_1AA2A0; // weak
int dword_1AA2A4; // weak
int dword_1AA2A8; // weak
int dword_1AA2AC; // weak
int dword_1AA2B0; // weak
int dword_1AA2B4; // weak
int dword_1AA2B8; // weak
int dword_1AA2BC; // weak
int dword_1AA2C0; // weak
int dword_1AA2C4; // weak
int dword_1AA2C8; // weak
int dword_1AA2CC; // weak
int dword_1AA2D0; // weak
int dword_1AA2D4; // weak
int dword_1AA2D8; // weak
int dword_1AA2DC; // weak
int dword_1AA2E0; // weak
int dword_1AA2E4; // weak
int dword_1AA2E8; // weak
int dword_1AA2EC; // weak
int dword_1AA2F0; // weak
int dword_1AA2F4; // weak
int dword_1AA2F8; // weak
int dword_1AA2FC; // weak
int dword_1AA300; // weak
int dword_1AA304; // weak
int dword_1AA308; // weak
int dword_1AA30C; // weak
int dword_1AA310; // weak
int dword_1AA314; // weak
int dword_1AA318; // weak
int dword_1AA31C; // weak
int dword_1AA320; // weak
int dword_1AA324; // weak
int dword_1AA328; // weak
int dword_1AA32C; // weak
int dword_1AA330; // weak
int dword_1AA334; // weak
int dword_1AA338; // weak
int dword_1AA33C; // weak
int dword_1AA340; // weak
char byte_1AA344; // weak
_UNKNOWN unk_1AA345; // weak
char byte_1AA358[10]; // weak
char byte_1AA362[10]; // weak
char byte_1AA36C[12]; // weak
int dword_1AA378; // weak
int dword_1AA37C; // weak
int16_t word_1AA380[5]; // weak
int16_t word_1AA38A[]; // weak
int16_t word_1AA38C[15]; // weak
int16_t word_1AA3AA; // weak
int dword_1AA3AC; // weak
int dword_1AA3B0; // weak
int dword_1AA3B4; // weak
int dword_1AA3B8; // weak
int dword_1AA3BC; // weak
int dword_1AA3C0; // weak
int dword_1AA3C4; // weak
int dword_1AA3C8; // weak
int dword_1AA3CC; // weak
int dword_1AA3D0; // weak
int dword_1AA3D4; // weak
int dword_1AA3D8; // weak
int dword_1AA3DC; // weak
int dword_1AA3E0; // weak
int dword_1AA3E4; // weak
int16_t word_1AA3E8; // weak
int dword_1AA3EC; // weak
int dword_1AA3F0; // weak
int dword_1AA3F4[]; // weak
int dword_1AA3F8; // weak
int dword_1AA3FC; // weak
int dword_1AA400; // weak
int dword_1AA404[]; // weak
int dword_1AA408; // weak
char byte_1AA40C[8]; // weak
_BYTE byte_1AA414[1800]; // weak
char byte_1AAB1C[8]; // weak
char byte_1AAB24[8]; // weak
int dword_1AAB2C; // weak
int dword_1AAB30; // weak
int dword_1AAB34; // weak
int dword_1AAB38; // weak
int dword_1AAB3C; // weak
int dword_1AAB40; // weak
int dword_1AAB44; // weak
int dword_1AAB48[]; // weak
int dword_1AAB4C; // weak
int dword_1AAB50; // weak
int dword_1AAB54; // weak
int dword_1AAB58; // weak
int dword_1AAB5C[]; // weak
int dword_1AAB60; // weak
int dword_1AAB64; // weak
int dword_1AAB68; // weak
int dword_1AAB6C; // weak
int dword_1AAB70[]; // weak
int dword_1AAB74; // weak
int dword_1AAB78; // weak
int dword_1AAB7C; // weak
int dword_1AAB80; // weak
int dword_1AAB84; // weak
int dword_1AAB88; // weak
int dword_1AAB8C; // weak
int dword_1AAB90; // weak
int dword_1AAB94; // weak
int dword_1AAB98; // weak
int dword_1AAB9C; // weak
int dword_1AABA0; // weak
int dword_1AABA4; // weak
int dword_1AABA8; // weak
int dword_1AABAC; // weak
int dword_1AABB0; // weak
int dword_1AABB4; // weak
int dword_1AABB8; // weak
int dword_1AABBC; // weak
int dword_1AABC0; // weak
int dword_1AABC4; // weak
int dword_1AABC8; // weak
int dword_1AABCC; // weak
int dword_1AABD0; // weak
int dword_1AABD4; // weak
int dword_1AABD8; // weak
int dword_1AABDC; // weak
int dword_1AABE0; // weak
int dword_1AABE4; // weak
int dword_1AABE8; // weak
int dword_1AABEC; // weak
int dword_1AABF0; // weak
int dword_1AABF4; // weak
int dword_1AABF8; // weak
int dword_1AABFC; // weak
int dword_1AAC00; // weak
int dword_1AAC04; // weak
int dword_1AAC08; // weak
int dword_1AAC0C; // weak
int dword_1AAC10; // weak
int dword_1AAC14; // weak
int dword_1AAC18; // weak
int dword_1AAC1C; // weak
int dword_1AAC20; // weak
int dword_1AAC24; // weak
int dword_1AAC28; // weak
int dword_1AAC2C; // weak
int dword_1AAC30; // weak
int dword_1AAC34; // weak
int dword_1AAC38; // weak
int dword_1AAC3C; // weak
int dword_1AAC40; // weak
int dword_1AAC44; // weak
int dword_1AAC48; // weak
int dword_1AAC4C; // weak
int dword_1AAC50; // weak
char byte_1AAC54; // weak
_UNKNOWN unk_1AACB4; // weak
char byte_1AAE9F; // weak
int dword_1AAEA4; // weak
int dword_1AAEA8; // weak
int dword_1AAEAC; // weak
int dword_1AAEB0; // weak
int dword_1AAEB4; // weak
int dword_1AAEB8; // weak
int dword_1AAEBC; // weak
int dword_1AAEC0; // weak
int dword_1AAEC4; // weak
int dword_1AAEC8; // weak
char byte_1AAECC; // weak
char byte_1AAED5[30]; // weak
_UNKNOWN unk_1AAEF3; // weak
_UNKNOWN unk_1AAF11; // weak
_UNKNOWN unk_1AAF2F; // weak
char byte_1AAF57; // weak
char byte_1AAF58; // weak
int dword_1AAF59; // weak
char byte_1AAF5D; // weak
int16_t word_1AAF5E; // weak
char byte_1AAF60[]; // weak
int16_t word_1AAF68; // weak
int dword_1AAF6A; // weak
int16_t word_1AAF6E; // weak
int16_t word_1AAF70; // weak
int dword_1AAF72; // weak
char byte_1AAF76[8]; // weak
char byte_1AAF7E[]; // weak
char byte_1AAF7F[7]; // weak
int16_t word_1AAF86; // weak
char byte_1AAF88[]; // weak
char byte_1AAF89; // weak
char byte_1AAF8A[]; // weak
char byte_1AAF8B[]; // weak
char byte_1AAF8C[]; // weak
int16_t word_1AAF8D[]; // weak
int16_t word_1AAF8F[]; // weak
int16_t word_1AAF91[]; // weak
char byte_1AAF94[]; // weak
char byte_1AAF95[]; // weak
char byte_1AAF96[142]; // weak
char byte_1AB024; // weak
char byte_1AB03F; // weak
char byte_1AB040; // weak
int16_t word_1AB041; // weak
int16_t word_1AB043; // weak
int16_t word_1AB045; // weak
_BYTE algn_1AB047; // weak
char byte_1AB048; // weak
char byte_1AB04A; // weak
char byte_1AB04B; // weak
int dword_1AB04C; // weak
char byte_1AB050; // weak
char byte_1AB051; // weak
char byte_1AB052; // weak
char byte_1AB053; // weak
char byte_1AB054; // weak
char byte_1AB055[8]; // weak
char byte_1AB05D[9]; // weak
char byte_1AB066; // weak
char byte_1AB067; // weak
char byte_1AB068; // weak
char byte_1AB069; // weak
char byte_1AB06A[8]; // weak
char byte_1AB072[8]; // weak
char byte_1AB07A[8]; // weak
int16_t byte_1AB082[2]; // weak
char byte_1AB087; // weak
_UNKNOWN unk_1AB089; // weak
char byte_1AB08B[8]; // weak
char byte_1AB093; // weak
char byte_1AB094[8]; // weak
int16_t word_1AB09C; // weak
char byte_1AB09E; // weak
char byte_1AB09F[8]; // weak
char byte_1AB0A7[8]; // weak
char byte_1AB0AF[8]; // weak
char byte_1AB0B7[8]; // weak
char byte_1AB0BF; // weak
char byte_1AB0C0; // weak
char byte_1AB0C1; // weak
char byte_1AB0CB; // weak
char byte_1AB0CC; // weak
char byte_1AB0CD; // weak
char byte_1AB0CE; // weak
int dword_1AB0CF; // weak
int dword_1AB0D3; // weak
int dword_1AB0D7; // weak
int dword_1AB0DB; // weak
char byte_1AB0DF; // weak
int dword_1AB0E0; // weak
int dword_1AB0E4; // weak
int dword_1AB0E8; // weak
int dword_1AB0EC; // weak
int dword_1AB0F0; // weak
int dword_1AB0F4; // weak
int dword_1AB0F8; // weak
int dword_1AB0FC; // weak
int dword_1AB100; // weak
int dword_1AB104; // weak
int dword_1AB108; // weak
int16_t word_1AB10C; // weak
int16_t word_1AB10E; // weak
int16_t word_1AB110; // weak
int16_t word_1AB112; // weak
int16_t word_1AB114; // weak
int16_t word_1AB116; // weak
int16_t word_1AB118; // weak
int16_t word_1AB11A; // weak
int16_t word_1AB11C; // weak
int16_t word_1AB11E; // weak
int16_t word_1AB120; // weak
int16_t word_1AB122; // weak
char byte_1AB124[8]; // weak
int dword_1AB12C; // weak
int dword_1AB130; // weak
int dword_1AB134; // weak
int dword_1AB138; // weak
int dword_1AB13C; // weak
int dword_1AB140; // weak
int dword_1AB144; // weak
int dword_1AB148; // weak
char byte_1AB14C[]; // weak
int16_t word_1AB14D; // weak
char byte_1AB14F[]; // weak
char byte_1AB358[426]; // weak
int16_t word_1AB502; // weak
_UNKNOWN unk_1AB504; // weak
char byte_1AB50D; // weak
char byte_1AB50E; // weak
char byte_1AB50F; // weak
char byte_1AB510[6500]; // weak
char byte_1ACE74; // weak
int16_t word_1ACE78[]; // weak
int16_t word_1ACE7A[]; // weak
_BYTE byte_1ACE98[32]; // weak
int16_t word_1ACEB8; // weak
int16_t word_1ACEBA; // weak
int dword_1ACEBC[]; // weak
// PORT (wave 23b, x64 fix): these six hold ADDRESSES of local stack buffers
// from sub_104C31's "edit field" parser context (orion_part_17.c ~1300-1353:
// dword_1ACF14=&v19, dword_1ACF08=v15, dword_1ACF00=v16, dword_1ACEFC/1ACF04
// =v18, dword_1ACF0C=&v17), then read back byte-offset-into-struct style
// (`*(WORD*)(dword_1ACF14+N)`) by dozens of functions across the whole file.
// Declared `int` they truncated a real 64-bit stack address on x64 (the
// stack, unlike the LAA:NO-constrained heap, is NOT guaranteed under 4GB) -
// crashed in sub_12760B reading through a garbage (sign-extended -1) pointer.
// Widened to intptr_t; every existing `dword_X + N` / `(T*)dword_X` usage
// keeps compiling unchanged since intptr_t supports the same arithmetic.
intptr_t dword_1ACEFC; // weak
intptr_t dword_1ACF00; // weak
intptr_t dword_1ACF04; // weak
intptr_t dword_1ACF08; // weak
intptr_t dword_1ACF0C; // weak
intptr_t dword_1ACF10; // weak
intptr_t dword_1ACF14; // weak
int16_t word_1ACF18; // weak
int16_t word_1ACF1A; // weak
int16_t word_1ACF1C; // weak
int16_t word_1ACF1E; // weak
int dword_1ACF20[16]; // weak
char byte_1ACF60[]; // weak
int (*dword_1ACF70)(_DWORD, _DWORD, _DWORD); // weak
char byte_1ACF74; // weak
char byte_1ACF75; // weak
int16_t word_1ACF76; // weak
_UNKNOWN unk_1ACF78; // weak
char byte_1ACF97[]; // weak
char byte_1ACF98[16]; // weak
_UNKNOWN unk_1ACFA8; // weak
_UNKNOWN unk_1ACFAC; // weak
_UNKNOWN unk_1ACFB0; // weak
_UNKNOWN unk_1ACFB4; // weak
int16_t word_1ACFB5; // weak
int dword_1ACFB7; // weak
char byte_1ACFBB; // weak
char byte_1ACFBC; // weak
int dword_1ACFC0[]; // weak
int dword_1ACFE0; // weak
int dword_1ACFE4; // weak
int dword_1ACFE8; // weak
int16_t word_1ACFEC[]; // weak
int16_t word_1ACFEE[]; // weak
int16_t word_1ACFF0[]; // weak
int16_t word_1ACFF2[]; // weak
int16_t word_1ACFF4[]; // weak
int dword_1AD1E0; // weak
int dword_1AD1E4; // weak
int dword_1AD1E8; // weak
int dword_1AD1EC; // weak
int dword_1AD1F0; // weak
int16_t word_1AD1F4; // weak
int16_t word_1AD1F6; // weak
int16_t word_1AD1F8; // weak
int16_t word_1AD1FA; // weak
int16_t word_1AD1FC; // weak
int16_t word_1AD1FE; // weak
int16_t word_1AD200; // weak
int16_t word_1AD202; // weak
int16_t word_1AD204; // weak
char byte_1AD206; // weak
char byte_1AD207; // weak
char byte_1AD208; // weak
char byte_1AD209; // weak
char byte_1AD20C[120]; // weak
char byte_1AD284[80]; // weak
char byte_1AD2D4[80]; // weak
int dword_1AD324; // weak
int dword_1AD328; // weak
int dword_1AD32C; // weak
int dword_1AD330; // weak
char byte_1AD334[100]; // weak
int dword_1AD398; // weak
int dword_1AD39C; // weak
char byte_1AD3A0[100]; // weak
char byte_1AD404[20]; // weak
char byte_1AD418[20]; // weak
char byte_1AD42C[20]; // weak
char byte_1AD440[20]; // weak
char byte_1AD454[30]; // weak
char byte_1AD472[30]; // weak
int16_t word_1AD490; // weak
int16_t word_1AD492; // weak
char byte_1AD494[15]; // weak
char byte_1AD4A3[15]; // weak
char byte_1AD4B2[15]; // weak
char byte_1AD4C1[15]; // weak
char byte_1AD4D0[15]; // weak
char byte_1AD4DF[15]; // weak
char byte_1AD4EE[15]; // weak
char byte_1AD4FD[15]; // weak
char byte_1AD50C[15]; // weak
char byte_1AD51B[15]; // weak
char byte_1AD52A[15]; // weak
char byte_1AD539[15]; // weak
char byte_1AD548[15]; // weak
char byte_1AD557[15]; // weak
char byte_1AD566[15]; // weak
char byte_1AD575[15]; // weak
char byte_1AD584[15]; // weak
char byte_1AD593; // weak
char byte_1AD594; // weak
char byte_1AD595; // weak
int dword_1AD598; // weak
char byte_1AD59C[8]; // weak
_UNKNOWN unk_1AD5A4; // weak
_UNKNOWN unk_1AD5AC; // weak
_UNKNOWN unk_1AD5B4; // weak
char byte_1AD5CC[20]; // weak
char byte_1AD5E0[20]; // weak
char byte_1AD5F4[20]; // weak
char byte_1AD608[20]; // weak
char byte_1AD61C[20]; // weak
char byte_1AD630[20]; // weak
char byte_1AD644[20]; // weak
char byte_1AD658[20]; // weak
char byte_1AD66C[20]; // weak
char byte_1AD680[20]; // weak
int dword_1AD694; // weak
int dword_1AD698; // weak
int dword_1AD69C; // weak
_UNKNOWN unk_1AD6A0; // weak
int16_t word_1AD6B2; // weak
int16_t word_1AD6B4; // weak
int16_t word_1AD6B6; // weak
int16_t word_1AD6B8; // weak
char byte_1AD6BA; // weak
char byte_1AD6BB; // weak
int dword_1AD6BC; // weak
char byte_1AD6C0; // weak
int dword_1AD6C4[]; // weak
int dword_1AD6C8[79]; // weak
int dword_1AD804; // weak
int dword_1AD808; // weak
int dword_1AD80C; // weak
int dword_1AD810; // weak
int dword_1AD814; // weak
int dword_1AD818; // weak
int dword_1AD81C; // weak
int dword_1AD820; // weak
int dword_1AD824; // weak
_UNKNOWN unk_1AD828; // weak
int16_t word_1AD83E; // weak
int16_t word_1AD840; // weak
int dword_1AD842; // weak
_UNKNOWN unk_1AD846; // weak
_UNKNOWN unk_1AD854; // weak
char byte_1AE054[80]; // weak
// vlna 12: tentativni "int dword_1AE0A4[]" nevytvarel definici (LNK2001
// po odstraneni duplikatu z link_stubs.c). V puvodnich datech ma symbol
// 4 bajty (0x1AE0A4..0x1AE0A8). DECOMP_TODO: pouziva se i s indexem
// [v3]/[v10] (streamovani zvukovych samplu, sub_113xxx) - presna sirka
// se doresi az se zvukovou vlnou (kod ted nebezi, zvuk je vypnuty).
int dword_1AE0A4[1]; // weak
int dword_1AE0A8; // weak
// VLNA 12: blok 0x1AE0AC..0x1AE5D4 = tabulka 33 zvukovych slotu po 40 B
// (10 int) - sub_111F3E ji nuluje memset(..., 1320) a kod k ni pristupuje
// striden "dword_1AE0XX[10 * slot]" pres NEKOLIK ruznych symbolu zaroven
// (dword_1AE0AC=+0, ...B0=+4, ...B4=+8, byte_1AE0B8=+0xC, ...C8=+0x1C,
// ...CC=+0x20, ...D0=+0x24; navic aliasy pres &dword_1AE0AC[10*i] a
// v2[8]). Jako oddelene C promenne se NEPREKRYVALY -> zapisy si stouply
// na sousedni globaly (pad v sub_111F3E). Jeden souvisly backing blok +
// prekryvova makra v orion_common.h zachovavaji puvodni layout presne.
// dword_1AE0D8 (+0x2C) a dword_1AE0F8 (+0x4C) jsou pole slotu 0 a 1.
uint8_t soundSlots_1AE0AC[1320]; // weak
int16_t word_1AE5D4[2086]; // weak
// VLNA 12: drive "_UNKNOWN unk_1AF620" (= 1 bajt!) - AIL/zvukova struktura,
// hra ji nuluje memset(&unk_1AF620, 0, 4172) a predava do sub_13AE74/
// sub_13AFD2. 4172 = 0x104C = presne vzdalenost k dalsimu symbolu
// (0x1B066C - 0x1AF620), takze jde o souvisly 4172bajtovy blok. Jako
// 1bajtova promenna memset prepisoval sousedni globaly -> pad/abort
// v sub_111F3E jeste pred nactenim fontu.
uint8_t unk_1AF620[4172]; // weak
int dword_1B066C; // weak
int dword_1B0670[17]; // weak
int dword_1B06B4[17]; // weak
int dword_1B06F8; // weak
int dword_1B06FC; // weak
int16_t word_1B0700; // weak
char byte_1B0704[8]; // weak
char byte_1B070C[8]; // weak
char byte_1B0714[7]; // weak
char byte_1B071B[]; // weak
char byte_1B071C[]; // weak
char byte_1B071D[]; // weak
char byte_1B071E[254]; // weak
int dword_1B081C; // weak
int dword_1B0820; // weak
int dword_1B0824; // weak
int dword_1B0828; // weak
int dword_1B082C; // weak
int dword_1B0830; // weak
int dword_1B0834; // weak
int dword_1B0838; // weak
int (*dword_1B0840)(void); // weak
int (*dword_1B0844)(void); // weak
int dword_1B3E02; // weak
int16_t word_1B3E06; // weak
int16_t word_1B3E08; // weak
int dword_1B3E0A; // weak
int16_t word_1B3E0E; // weak
int dword_1B3E10; // weak
int dword_1B3E14; // weak
char byte_1B3E18; // weak
char byte_1B3E1B; // weak
char byte_1B3E1C; // weak
char byte_1B3E1D; // weak
char unk_1B3E20[84]; // vlna 15: filename buffer (0x1B3E20..0x1B3E74), drive _UNKNOWN/1B
int dword_1B3E74; // weak
int dword_1B3E78; // weak
// Font data block 0x1B3E7C..0x1B61D8 (9052 bytes) - wave 20.
// sub_120526 loads the whole 9052-byte font record into byte_1B3E7C with
// sub_12779E(byte_1B3E7C, v4, 0x235C). IDA had split the block into ~21
// individually used globals (byte_1B3E7C was even declared char[6]), so that
// copy overflowed and wiped everything after it - including dword_1B3E78
// (font sub-pool), which then crashed sub_1205E6/sub_126CEB with a NULL pool.
// One contiguous backing buffer keeps the original layout; every old symbol
// name is mapped onto its exact offset by the macros in orion_common.h.
char fontBlock_1B3E7C[9052]; // weak
// unk_1B5030/unk_1B5418 ODSTRANENO (vlna 10): IDA false-positive z konstant
// 1790000/1791000 (velikost zvukoveho bufferu + prah) - viz orion_part_01.c.
char byte_1B61D8[]; // weak
int dword_1B61E0; // weak
int dword_1B61E4; // weak
int dword_1B61E8; // weak
int dword_1B91EC; // weak
int dword_1B91F0; // weak
int dword_1B91F4; // weak
int dword_1B91F8; // weak
int dword_1B9204; // weak
int (*dword_1B9208)(_DWORD, _DWORD, _DWORD, _DWORD); // weak
int (*dword_1B920C)(_DWORD); // weak
int (*dword_1B9210)(_DWORD); // weak
int16_t word_1B921A; // weak
int16_t word_1B921C; // weak
int16_t word_1B921E; // weak
int16_t word_1B9220; // weak
int dword_1B9222; // weak
int16_t word_1B9226; // weak
int16_t word_1B9228; // weak
char byte_1B922A; // weak
int dword_1B9E34; // weak
_UNKNOWN unk_1B9E38; // weak
_UNKNOWN unk_1BA0A8; // weak
char byte_1BA318[]; // weak
char byte_1BA319[]; // weak
char byte_1BA31A[]; // weak
char byte_1BA31B[61]; // weak
char byte_1BA358[4092]; // weak
char byte_1BB354[]; // weak
char byte_1BB355[]; // weak
char byte_1BB356[]; // weak
char byte_1BB357[]; // weak
// VLNA 15: puvodne "char byte_1BB358[]" (nedokoncene pole). sub_1205E6
// do nej kopiruje 1024 bajtu (paletova/barevna tabulka 0x1BB358..0x1BB758).
// IDA cely 1024B usek rozsekala na desitky jednotlivych symbolu (byte_1BB359,
// 35B[318], 499, 49B[253]...), takze kopie by prepisovala sousedni globaly
// -> pad. Standalone 1024B buffer prepis zastavi. DECOMP_TODO: jednotlive
// byte_1BB35x/49x/59x/61x/65x symboly do nej zatim NEaliasuji (paletova data
// se pres ne necti) - plny overlay az bude potreba barevna presnost.
char byte_1BB358[1024]; // weak
char byte_1BB359[]; // weak
char byte_1BB35A[]; // weak
char byte_1BB35B[318]; // weak
char byte_1BB499[]; // weak
char byte_1BB49A[]; // weak
char byte_1BB49B[253]; // weak
_UNKNOWN unk_1BB598; // weak
char byte_1BB599[]; // weak
char byte_1BB59A[]; // weak
char byte_1BB59B[126]; // weak
char byte_1BB619[]; // weak
char byte_1BB61A[]; // weak
char byte_1BB61B[61]; // weak
char byte_1BB658[]; // weak
char byte_1BB659[]; // weak
char byte_1BB65A[]; // weak
char byte_1BB65B[190]; // weak
char byte_1BB719[63]; // weak
char byte_1BB758[]; // weak
char byte_1BB759[254]; // weak
_UNKNOWN unk_1BB857; // weak
int dword_1BB880; // weak
int dword_1BB884; // weak
int (*dword_1BB888)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // weak
int (*dword_1BB88C)(void); // weak
int dword_1BB890; // weak
int (*dword_1BB894)(void); // weak
int (*dword_1BB898)(_DWORD); // weak
int (*dword_1BB89C)(void); // weak
int (*dword_1BB8A0)(_DWORD); // weak
int (*dword_1BB8A4)(_DWORD); // weak
int (*dword_1BB8A8)(_DWORD); // weak
int dword_1BB8AC; // weak
int dword_1BB8B0; // weak
int dword_1BB8B8; // weak
int dword_1BB8BC; // weak
int dword_1BB8C0; // weak
char byte_1BB8C4[28]; // weak
// REGS union buffer 0x1BB8E0..0x1BB8FC (28 bytes) - wave 19. int386 (INT 33h
// mouse, INT 10h) writes back the full register set (24 bytes) to &dword_1BB8E0.
// IDA split the union into separate 4-byte globals (eax/ebx/ecx/edx at +0/+4/+8/
// +C, edi at +0x14) which the port packs consecutively, so the 24-byte write
// overflowed neighbouring globals (e.g. zeroed dword_1BB8FC / dword_1BB8C0).
// One contiguous buffer keeps the exact union layout; old names map via macros.
int regsBlock_1BB8E0[7]; // weak
int dword_1BB8FC; // weak
int dword_1BB900; // weak
int dword_1BB904; // weak
int dword_1BB908; // weak
int dword_1BB90C; // weak
// Overlay: dword_1BB910 + dword_1BB914 are one contiguous 65-int array in the
// original (0x1BB910..0x1BBA13). See orion_common.h for why they must not be
// split. dword_1BB910/dword_1BB914 are now macros onto this backing array.
int screenPtrs_1BB910[65]; // weak
int dword_1BBA14; // weak
int dword_1BBA18; // weak
int16_t word_1BBA1C[6]; // weak
int dword_1BBA28; // weak
int dword_1BBA2C; // weak
int16_t word_1BBA30; // weak
int dword_1BBA34; // weak
int dword_1BBA38; // weak
int16_t word_1BBA3C; // weak
int dword_1BBA3E; // weak
int dword_1BBA42; // weak
int dword_1BBA46; // weak
int dword_1BBA4A; // weak
int dword_1BBA4E; // weak
int dword_1BBA52; // weak
int16_t word_1BBA56; // weak
int16_t word_1BBA58; // weak
int16_t word_1BBA5C; // weak
int16_t word_1BBA5E; // weak
_UNKNOWN unk_1BBA60; // weak
int16_t word_1BBA62; // weak
int dword_1BBA64; // weak
int16_t word_1BBA68; // weak
// VLNA 12: blok 0x1BBA6A..0x1BC26C = cache LBX hlavicky (2048 B nacitane
// pres "fread(&unk_1BBA6C, 2048, ...)" v sub_127233 a spol.) + 2 bajty
// pred ni (byte_1BBA6B flag; "(int)unk_1BBA6A >> 16" cte pocet zaznamu =
// word na 0x1BBA6C). Symboly uvnitr: word_1BBA6E (+4 od zacatku bloku) =
// LBX magic 0xFEAD, dword_1BBA74/78 (+0x0A/+0x0E) = tabulka offsetu
// zaznamu. Jako oddelene promenne fread nikdy nenaplnil word_1BBA6E ->
// "fonts.lbx [entry 0] is not an LBX file". Prekryvova makra v
// orion_common.h drzi puvodni layout.
uint8_t lbxHeader_1BBA6A[2050]; // weak
int dword_1BC26C; // weak
// vlna 12: drive _UNKNOWN (1 bajt) - buffer jmena aktualne otevreneho LBX
// (strcpy nazvu "fonts.lbx" apod. v sub_127233); 16 B = vzdalenost k
// dalsimu symbolu dword_1BC280.
char unk_1BC270[16]; // weak
int dword_1BC280; // weak
int dword_1BC284; // weak
int dword_1BC288; // weak
int dword_1BC28C; // weak
int16_t word_1BC290; // weak
int16_t word_1BC294; // weak
int dword_1BC296; // weak
int16_t word_1BC29A; // weak
_UNKNOWN unk_1BC29C; // weak
_UNKNOWN unk_1BC2A0; // weak
int dword_1BC2A4; // weak
int dword_1BC2A8; // weak
int dword_1BC2AC[10]; // weak
int dword_1BC2D4; // weak
int dword_1BC2D8; // weak
// Puvodni INT 9 (klavesnice) vektor ulozeny pred instalaci vlastniho
// handleru - 6 bajtu na adrese 1BC2DC (dword offset + word segment),
// IDA je mylne typovala jako ukazatel na funkci. Viz InstallKeyboardIsr_12C420/RestoreKeyboardIsr_12C493
// v orion_part_20.c a struct DosFarPointer v hexrays_compat.h/port_dos.h.
struct DosFarPointer savedKeyboardVector_1BC2DC; // weak
char byte_1BC2E2; // weak
char byte_1BC2E3; // weak
char byte_1BC2E4; // weak
int dword_1BC2E8; // weak
int dword_1BC310[3]; // weak
int dword_1BC31C; // weak
int dword_1BC320; // weak
int dword_1BC324; // weak
int dword_1BC328; // weak
int dword_1BC32C[3]; // weak
int dword_1BC338; // weak
int dword_1BC33C[3]; // weak
int dword_1BC348[3]; // weak
int dword_1BC354; // weak
int dword_1BC358; // weak
int dword_1BC35C; // weak
int dword_1BC360; // weak
int dword_1BC364; // weak
int dword_1BC368; // weak
int dword_1BC36C; // weak
int dword_1BC370; // weak
int dword_1BC374; // weak
int dword_1BC378; // weak
int dword_1BC37C; // weak
int dword_1BC380; // weak
int dword_1BC384; // weak
int dword_1BC388; // weak
char byte_1BC38C; // weak
_UNKNOWN unk_1BC390; // weak
int dword_1BC790; // weak
int dword_1BC794; // weak
int dword_1BC798; // weak
char byte_1BC79C[]; // weak
char byte_1BC79E; // weak
char byte_1BC79F; // weak
char byte_1BC7A0; // weak
char byte_1BC89B[]; // weak
char byte_1BC89C[]; // weak
char byte_1BC89D[2047]; // weak
int dword_1BD09C; // weak
char byte_1BD0A0[]; // weak
char byte_1BD0AA[166]; // weak
int dword_1BD150; // weak
char byte_1BD154[510]; // weak
int dword_1BD352[]; // weak
int16_t word_1BD356[]; // weak
int16_t word_1BD358[]; // weak
char byte_1BD35A[]; // weak
char byte_1BD35B[]; // weak
char byte_1BD35C[]; // weak
char byte_1BD35D[]; // weak
char byte_1BD35E[]; // weak
char byte_1BD35F[3059]; // weak
int16_t word_1BDF52[]; // weak
int16_t word_1BDF54[]; // weak
int16_t word_1BDF56[511]; // weak
_UNKNOWN unk_1BE354; // weak
char byte_1BE355[]; // weak
char byte_1BE356[]; // weak
char byte_1BE357[2045]; // weak
int dword_1BEB54; // weak
int dword_1BF358; // weak
int dword_1BF35C; // weak
int (*dword_1BF388)(_DWORD, _DWORD, _DWORD, _DWORD); // weak
char byte_1BF38C; // weak
_DWORD dword_1BF390[3]; // weak
_UNKNOWN unk_1BF39C; // weak
char byte_1BF590[2698]; // weak
char byte_1C0590[256]; // weak
int dword_1C0690[128]; // weak
char byte_1C0890[128]; // weak
char byte_1C0910[128]; // weak
int (*dword_1C0990)(_DWORD, _DWORD, _DWORD, _DWORD); // weak
_DWORD dword_1C0994[3]; // weak
_UNKNOWN unk_1C09A0; // weak
int16_t word_1C0AF4[4]; // weak
int16_t word_1C0AFC[3]; // weak
_UNKNOWN unk_1C0B02; // weak
int16_t word_1C0B04[3]; // weak
_UNKNOWN unk_1C0B0A; // weak
int16_t word_1C0B0C[3]; // weak
int dword_1C0B12; // weak
int dword_1C0BDA; // weak
int dword_1C0CA2; // weak
int dword_1C0D6A; // weak
_UNKNOWN unk_1C0E32; // weak
int16_t word_1C0E34; // weak
int dword_1C0E38; // weak
int dword_1C0E3C; // weak
int dword_1C0E40; // weak
int dword_1C0E44; // weak
int dword_1C0E48; // weak
int dword_1C0E4C; // weak
int dword_1C0E50; // weak
int dword_1C0E54; // weak
int dword_1C0E58; // weak
char byte_1C0E5C[24]; // weak
char byte_1C0E74; // weak
_UNKNOWN unk_1C0E7C; // weak
int dword_1C3C10; // weak
int dword_1C3C18; // weak
int dword_1C3C1C; // weak
char byte_1C3C22[6]; // weak
int (*dword_1C3C30)(_DWORD); // weak
int (*dword_1C3C34)(_DWORD); // weak
int (*dword_1C3C38)(_DWORD); // weak
int (*dword_1C3C3C)(_DWORD); // weak
int dword_1C3C48; // weak
int dword_1C3C4C; // weak
int dword_1C3C50; // weak
int dword_1C3C54; // weak
_UNKNOWN unk_1C3C58; // weak
int dword_1C3C5C; // weak
int (*dword_1C3C68)(_DWORD, _DWORD, _DWORD); // weak
int dword_1C3C6C; // weak
int dword_1C3C70; // weak
int dword_1C3C78; // weak
int dword_1C3C7C; // weak
int dword_1C3C80; // weak
int16_t word_1C3C84; // weak
char byte_1C3C88; // weak
int dword_1C3C92; // weak
int16_t word_1C3C96; // weak
char byte_1C3C98; // weak
char byte_1C3C99; // weak
int dword_1C3C9A; // weak
int dword_1C3C9E; // weak
int dword_1C3CA2; // weak
int dword_1C3CA6; // weak
int16_t word_1C3CAA; // weak
int dword_1C3CAC; // weak
int dword_1C3CB0; // weak
int dword_1C3CB4; // weak
int dword_1C3CB8; // weak
int dword_1C3CBC; // weak
int dword_1C3CC0; // weak
int dword_1C3CC4; // weak
int dword_1C3CC8; // weak
int dword_1C3CCC; // weak
int dword_1C3CD0; // weak
int dword_1C3CD4; // weak
int dword_1C3CD8; // weak
int dword_1C3CE0; // weak
int dword_1C40E4; // weak
int16_t word_1C40E8; // weak
int dword_1C40EA; // weak
char byte_1C40EE; // weak
_UNKNOWN unk_1C40F0; // weak
char byte_1C8358[100]; // weak
int dword_1C83BC; // weak
int dword_1C9400[]; // weak
char byte_1C9440; // weak
int dword_1C9540[]; // weak
int dword_1C9544; // weak
int dword_1C9548; // weak
int dword_1C954C; // weak
int dword_1C9550; // weak
int dword_1C9554; // weak
int dword_1C9558; // weak
int dword_1C955C; // weak
int dword_1C9560; // weak
int dword_1C9564; // weak
int dword_1C9568; // weak
int dword_1C956C; // weak
int dword_1C9570; // weak
int dword_1C9574; // weak
int dword_1C9578; // weak
int dword_1C957C; // weak
int dword_1C9580; // weak
int dword_1C9584; // weak
_UNKNOWN unk_1C9588; // weak
int dword_1C95A0; // weak
_UNKNOWN unk_1C95A4; // weak
_WORD word_1C95D8[2]; // weak
int16_t word_1C95DC; // weak
int16_t word_1C95DE; // weak
int dword_1C95E4; // weak
int dword_1C95E8; // weak
int dword_1C95EC; // weak
int dword_1C95F0; // weak
int dword_1C95F4; // weak
int dword_1C95F8; // weak
int dword_1C95FC; // weak
int dword_1C9600; // weak
int dword_1C9604; // weak
int dword_1C9608; // weak
int dword_1C960C; // weak
int dword_1C9610; // weak
int dword_1C9614; // weak
int dword_1C9618; // weak
int dword_1C961C; // weak
int dword_1C9620; // weak
int dword_1C9624; // weak
_UNKNOWN unk_1C9628; // weak
_UNKNOWN unk_1C962C; // weak
uint8_t byte_1C962D[515]; // weak
int (*dword_1C9830)(_DWORD); // weak
char byte_1C9836[6]; // weak
int dword_1C9840; // weak
int dword_1C9844[256]; // weak
int dword_1C9C44; // weak
int16_t word_1C9C48; // weak
int16_t word_1C9C4A; // weak
_UNKNOWN unk_1C9C4C; // weak
char byte_1C9C4D; // weak
int dword_1C9C70; // weak
int dword_1C9C74; // weak
int dword_1C9CAC; // weak
int dword_1C9CB2; // weak
int dword_1C9CB6; // weak
int dword_1C9CC0; // weak
int16_t word_1C9CC4; // weak
int dword_1C9CCA; // weak
int dword_1C9CCE; // weak
char byte_1C9CD2; // weak


