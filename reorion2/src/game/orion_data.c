#include "orion_common.h"

// Data declarations

/* vlna 117: TABULKA ZAKLADU BAREVNE RAMPY, indexovana rasou hrace
   (`byte_10010[*(uint8_t *)(dword_197F98 + 3753*hrac + 38)]`).
   V portu tu byl JEN PRVNI BAJT ('I' = 0x49), takze kazda rasa != 0
   cetla za koncem pole - popisky hvezd, lodi a dalsi texty mely barvu
   podle smeti. Skutecny obsah z obrazu hry (Orion2.exe.lst, cseg01:10010:
   `db 49h` / `db 62h, 6Eh, 20h` / `dd 552D943Eh`), za nim uz zacina kod
   funkce main_ na 0x10018, takze pole ma prave 8 polozek.
   Kontrola: rasa 6 -> 0x2D = 45 -> rampa 46/51, presne jako dosbox. */
char byte_10010[8] = { 0x49, 0x62, 0x6E, 0x20, 0x3E, 0x94, 0x2D, 0x55 }; // weak
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
// VLNA 89c: NENI to retezec, ale tabulka CTYR int16_t (velikost hvezdneho
// spritu podle urovne priblizeni, index = sub_79917()). asm 0x81C68:
//   text "UTF-16LE", 27h,'!!'   -> 27 00 21 00 21 00
//   dw 18h                      -> 18 00
// tedy 8 B = { 0x27, 0x21, 0x21, 0x18 } = { 39, 33, 33, 24 }, ktere
// sub_83BF9 kopiruje pres `movsd movsd` do lokalky. Jako wchar_t[3] mel port
// jen SEST bajtu, takze ctvrta polozka (nejvetsi priblizeni) cetla mimo pole
// a hvezdy se na te urovni centrovaly podle smeti.
int16_t asc_81C68[4] = { 0x27, 0x21, 0x21, 0x18 }; // weak
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
/* PORT (vlna 126): tabulka "produkce na delnika podle bohatosti nerostu".
   V obraze hry (cseg01:000DD4B5) je `db 1 / dw 302h / db 5, 8`, tedy PET
   polozek { 1, 2, 3, 5, 8 } = Ultra Poor, Poor, Abundant, Rich, Ultra Rich.
   V portu byla jednoprvkova, takze `byte_DD4B5[2]` (Abundant) a `[3]` (Rich)
   cetly mimo pole - na PLANETS vychazelo 8 a 0 misto 3 a 5.
   Indexuje se na ctyrech mistech (sub_9A2BA, sub_D27A7, sub_D2CAE). */
char byte_DD4B5[5] = { 1, 2, 3, 5, 8 };
int16_t word_DD4BA = 6450; // weak
char byte_DD4C4[] = { '\xFC' }; // weak
char byte_DD4CC[] = { '\xF6' }; // weak
char byte_DD4CF[] = { '\x04' }; // weak
char byte_DD4D7[] = { '\xF6' }; // weak
char byte_DD4DC[] = { '\x05' }; // weak
/* PORT (vlna 126): tabulky v kodovem segmentu, ktere IDA zkratila.
   Obsah nacten primo z obrazu hry: tools/compare/dumpdata.py 0xDD4E1 32
   (mapovani soubor = cseg01 + 0x85654). Vsechny se INDEXUJI, takze
   zkraceni znamenalo cteni mimo pole. */
char byte_DD4E1[5] = { 2, 4, 6, 8, 10 };   /* velikost planety -> pocet (sub_DEE1B) */
char byte_DD4E6[5] = { 0, 0, 1, 2, 3 };   /* obtiznost -> bonus (sub_E03F1, index byte_199CB0) */
char byte_DD4EB[10] = { 25, 25, 25, 25, 25, 25, 40, 60, 80, 100 };   /* klima -> obyvatelnost v % (sub_E0A18, index 0..9) */
char byte_DD4F5[8] = { 30, 60, 30, 60, 60, 120, 12, 16 };   /* sub_E3456 */
_UNKNOWN loc_E0002; // weak
_UNKNOWN loc_E1000; // weak
int16_t word_EA27A = 8739; // weak
_UNKNOWN loc_EB4BD; // weak
_UNKNOWN loc_EB4BF; // weak
int16_t word_EB4C3[] = { 118 }; // weak
/* vlna 131: polomery sesti obeznych drah, (x, y) po dvojicich. V obraze je to
   souvislych 12 slov (0xEB4C5..0xEB4DD, dal uz je kod - `56 57` = push esi/edi);
   IDA pojmenovala jen prvni dve a zbytek nechala jako `db`/`dd` bez jmena,
   takze `word_EB4C5[2*a2]` cetlo pro drahy 1-5 mimo pole a planety se
   v pohledu na soustavu shlukly do stredu. word_EB4C7 je pohled na +1. */
int16_t word_EB4C5[12] = { 464, 242, 704, 372, 949, 502, 1199, 632, 1423, 751, 1650, 873 };
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
/* vlna 130: bonus spionaze podle typu vlady. V obraze osm bajtu
   (0x100A36..0x100A3D, dalsi symbol je sub_100A3E): 00 00 0A 0F F6 F6 0F 0F.
   IDA vypsala jen prvni `db 0` a zbytek schovala do `align 4` + `dd` + `dup`,
   takze v portu byla tabulka jednoprvkova a "AGENT: 10%" vychazelo 0 %. */
char byte_100A36[8] = { 0, 0, 10, 15, -10, -10, 15, 15 };
_UNKNOWN loc_103428; // weak
// PORT (vlna 65): NENI to jeden bajt, ale TABULKA 9 kodu zarovnani, kterou
// `sub_1035AF` prohledava (`v12 = byte_10357B; ... *(_WORD *)v12 == v10`) a
// podle poradi nalezene polozky vybira kreslici rutinu (switch nad `v11`;
// v asm je to jump table `jpt_103649` s 9 polozkami).
// asm: `byte_10357B db 3 / dd 1080208h, 3080008h, 1000200h / db 3 dup(0)`,
// tedy bajty 03 08 02 08 01 08 00 08 03 00 02 00 01 00 00 00, coz po dvojicich
// da kody 0x0803, 0x0802, 0x0801, 0x0800, 0x0003, 0x0002, 0x0001, 0x0000.
// S jednim bajtem se hledalo ve smeti, nikdy to nesedlo a switch skoncil na
// `case 0` = NEKRESLI NIC. Proto zustavaly popisky v rameccich NEW GAME
// prazdne - styl 0x0002 (vycentrovany text) je v tabulce az sesty.
char byte_10357B[16] = { 3, 8, 2, 8, 1, 8, 0, 8, 3, 0, 2, 0, 1, 0, 0, 0 }; // weak
// extern _UNKNOWN _GETDS; weak
/* strstr: FLIRT rozpoznal jako staticky linkovanou CRT funkci, Hex-Rays ji ale nedekompiloval jako kod - pouziva se realna deklarace z <string.h> misto vlastni extern deklarace. */
 // weak
// dword_1276EC removed: was only a pusha/popa register-stash artifact inside
// sub_1276F0, which now returns its bit directly (see orion_part_19.c).
_UNKNOWN loc_1310FD; // weak
_UNKNOWN loc_1381E8; // weak
_UNKNOWN loc_138350; // weak
char byte_138385[] = { '\0' }; // weak
/* vlna 131: sinus s pevnou radovou carkou, sin(deg) * 65536 pro 0..89 stupnu
   (0x138405..0x1384B9; hodnota pro 90, 180 a 270 se v sub_138615 resi zvlast).
   IDA vypsala jen prvni nulu, takze vsechny uhly krome nuly davaly 0 a planety
   na obrazovce LEADERS se nakupily do stredu misto na sve obezne drahy.
   Typ je uint16_t - kod hodnoty stejne cte pres `(uint16_t)`. */
uint16_t word_138405[90] =
{
  0, 1144, 2287, 3430, 4572, 5712, 6850, 7987, 9121, 10252,
  11380, 12505, 13626, 14742, 15855, 16962, 18064, 19161, 20252, 21336,
  22415, 23486, 24550, 25607, 26656, 27697, 28729, 29753, 30767, 31772,
  32768, 33754, 34729, 35693, 36647, 37590, 38521, 39441, 40348, 41243,
  42126, 42995, 43852, 44695, 45525, 46341, 47143, 47930, 48703, 49461,
  50203, 50931, 51643, 52339, 53020, 53684, 54332, 54963, 55578, 56175,
  56756, 57319, 57865, 58393, 58903, 59396, 59870, 60326, 60764, 61183,
  61584, 61966, 62328, 62672, 62997, 63303, 63589, 63856, 64104, 64332,
  64540, 64729, 64898, 65048, 65177, 65287, 65376, 65446, 65496, 65526,
};
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
// VLNA 26: IDA tyto dve tabulky orizla na 2 a 4 polozky, ale indexuji se
// priznakem dword_18AD28, ktery nabyva 0..0x7F. V EXE zabiraji souvisly
// blok 0x1602F8..0x1606F8 = presne 2x128 dwordu (dalsi je uz sub_1606F8).
// Prevzato 1:1 z asm dumpu; prazdna mista jsou v originalu opravdu nulova.
int (*off_1602F8[128])() = {
  (int (*)())&sub_1606F8, (int (*)())&sub_160709, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  (int (*)())&sub_160715, (int (*)())&sub_160734, (int (*)())&sub_160748, (int (*)())&sub_160767,
  0, 0, 0, 0,
  (int (*)())&sub_16077B, (int (*)())&sub_160798, (int (*)())&sub_1607AA, (int (*)())&sub_1607C7,
  0, 0, 0, 0,
  (int (*)())&sub_1607D9, (int (*)())&sub_1607ED, 0, 0,
  (int (*)())&sub_1607FC, (int (*)())&sub_160812, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  (int (*)())&sub_160823, (int (*)())&sub_160844, (int (*)())&sub_16085A, (int (*)())&sub_16087B,
  (int (*)())&sub_160891, (int (*)())&sub_1608B6, (int (*)())&sub_1608D0, (int (*)())&sub_1608F5,
  (int (*)())&sub_16090F, (int (*)())&sub_160932, (int (*)())&sub_16094A, (int (*)())&sub_16096D,
  (int (*)())&sub_160985, (int (*)())&sub_1609AC, (int (*)())&sub_1609C8, (int (*)())&sub_1609EF,
  (int (*)())&sub_160A0B, (int (*)())&sub_160A38, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  (int (*)())&sub_160A60, (int (*)())&sub_160AB9, (int (*)())&sub_160B07, (int (*)())&sub_160B60,
  0, 0, 0, 0,
  (int (*)())&sub_160BAE, (int (*)())&sub_160C05, (int (*)())&sub_160C51, (int (*)())&sub_160CA8,
  0, 0, 0, 0,
  (int (*)())&sub_160CF4, (int (*)())&sub_160D24, 0, 0,
  (int (*)())&sub_160D4F, (int (*)())&sub_160D81, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  (int (*)())&sub_160DAE, (int (*)())&sub_160E09, (int (*)())&sub_160E59, (int (*)())&sub_160EB4,
  (int (*)())&sub_160F04, (int (*)())&sub_160F63, (int (*)())&sub_160FB7, (int (*)())&sub_161016,
  (int (*)())&sub_16106A, (int (*)())&sub_1610C7, (int (*)())&sub_161119, (int (*)())&sub_161176,
  (int (*)())&sub_1611C8, (int (*)())&sub_161229, (int (*)())&sub_16127F, (int (*)())&sub_1612E0,
};

int (*funcs_16213C[128])() = {
  (int (*)())&sub_161336, (int (*)())&sub_161357, (int (*)())&sub_16137B, (int (*)())&sub_1613A7,
  0, 0, (int (*)())&sub_1613D9, (int (*)())&sub_161405,
  (int (*)())&sub_161437, (int (*)())&sub_16145B, (int (*)())&sub_161482, (int (*)())&sub_1614B0,
  0, 0, (int (*)())&sub_1614E4, (int (*)())&sub_161512,
  (int (*)())&sub_161546, (int (*)())&sub_161562, (int (*)())&sub_161581, (int (*)())&sub_1615A2,
  0, 0, (int (*)())&sub_1615C9, (int (*)())&sub_1615EA,
  (int (*)())&sub_161611, (int (*)())&sub_161630, (int (*)())&sub_161652, (int (*)())&sub_161675,
  0, 0, (int (*)())&sub_16169E, (int (*)())&sub_1616C1,
  (int (*)())&sub_1616EA, (int (*)())&sub_161716, (int (*)())&sub_161745, (int (*)())&sub_16177F,
  0, 0, (int (*)())&sub_1617BF, (int (*)())&sub_1617F9,
  (int (*)())&sub_161839, (int (*)())&sub_16186B, (int (*)())&sub_1618A0, (int (*)())&sub_1618DC,
  0, 0, (int (*)())&sub_16191E, (int (*)())&sub_16195A,
  (int (*)())&sub_16199C, (int (*)())&sub_1619C3, (int (*)())&sub_1619ED, (int (*)())&sub_161A1C,
  0, 0, (int (*)())&sub_161A51, (int (*)())&sub_161A80,
  (int (*)())&sub_161AB5, (int (*)())&sub_161AE2, (int (*)())&sub_161B12, (int (*)())&sub_161B43,
  0, 0, (int (*)())&sub_161B7A, (int (*)())&sub_161BAB,
  (int (*)())&sub_161BE2, (int (*)())&sub_161BFE, (int (*)())&sub_161C24, (int (*)())&sub_161C45,
  0, 0, (int (*)())&sub_161C70, (int (*)())&sub_161C91,
  (int (*)())&sub_161CBC, (int (*)())&sub_161CDB, (int (*)())&sub_161D04, (int (*)())&sub_161D26,
  0, 0, (int (*)())&sub_161D52, (int (*)())&sub_161D74,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  (int (*)())&sub_161DA0, (int (*)())&sub_161DC7, (int (*)())&sub_161DF8, (int (*)())&sub_161E27,
  0, 0, (int (*)())&sub_161E60, (int (*)())&sub_161E8F,
  (int (*)())&sub_161EC8, (int (*)())&sub_161EF5, (int (*)())&sub_161F2C, (int (*)())&sub_161F5C,
  0, 0, (int (*)())&sub_161F96, (int (*)())&sub_161FC6,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
};
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
char aMay222006_1[12] = "May 22 2006"; // weak
char aNowh[6] = "/nowh"; // weak
char aNobh[6] = "/nobh"; // weak
char aVeuillezIns[] = "Veuillez ins"; // idb
char aGoodstart[11] = "/goodstart"; // weak
char aNosplint[10] = "/nosplint"; // weak
char aRichstart[11] = "/richstart"; // weak
char aPlanets[10] = "/planets="; // weak
char aNoorion[9] = "/noorion"; // weak
char aPicks[8] = "/picks="; // weak
wchar_t aAcg[4] = L"aCG\x1B"; // weak
char a360[4] = "360"; // weak
/* PORT (vlna 73): v asm je to retezec ", " (db 2Ch, 20h, 0) - oddelovac,
   ktery sub_5C20E vklada mezi polozky popisu rasy. Jako prazdny _UNKNOWN
   se polozky slepovaly ("Ship Defense:0Artifacts Home World"). */
char a0[2] = "0"; // weak
wchar_t aLb[3] = L"\x1BLB"; // weak
wchar_t aNsqoA[6] = L"NSQO\x1B""A"; // weak
wchar_t aLnmhq[6] = L"LNMHQ."; // weak
char aVer140b23[12] = "Ver 1.40b23"; // weak
wchar_t aDph[3] = L"DPH"; // weak
char a3[2] = "3"; // weak
char a4[2] = "4"; // weak
char a5[2] = "5"; // weak
   /* vlna 140: znacka u hvezdy - outpost i kolonie */
   /* vlna 140: znacka u hvezdy - outpost */
   /* vlna 140: znacka u hvezdy - kolonie */
// VLNA 89: 0x179E00 a 0x179E03 jsou DVA TRIBAJTOVE RETEZCE s ridicim kodem
// 1Ah (prepnuti barvy textu): 1A '1' 00 a 1A '0' 00. V portu unk_179E00 uplne
// chybel a unk_179E03 byl prazdny _UNKNOWN, takze sub_C26F4 predaval do
// sprintf %s ukazatel na neinicializovany bajt. Bajty z Orion2.exe.asm.
wchar_t aFs[3] = L"fs "; // weak
char a1[3] = "\x1B""1"; // weak
char a2[3] = "\x1B""2"; // weak
char aMay222006[12] = "May 22 2006"; // weak
char aMay222006_0[12] = "May 22 2006"; // weak
char a05[5] = "-0.5"; // weak
wchar_t aRad[4] = L"RAD"; // weak
char a302[5] = "3.02"; // weak
/* PORT (vlna 26, na zadost uzivatele): puvodne "wDIG.INI" - slitina dvou
   retezcu, [0]='w' je fopen MOD (zapis!) a &[1] je jmeno souboru. Aby se
   originalni DIG.INI v adresari hry nemohl prepsat, jmeno ukazuje na
   _fake variantu. Zvukovy driver se stejne nenacita - nahradni DIG_DRIVER
   staví PortSound_CreateDigDriver(), viz orion_part_21.c/sub_140979. */
char aWdigIni[14] = "wDIG_fake.INI"; // weak
/* PORT (vlna 26): totez pro hudebni config - viz aWdigIni vyse. */
char aRmdiIni[14] = "rMDI_fake.INI"; // weak
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
/* PORT (vlna 26 pokr. 41): TABULKA OBLASTI KURZORU pro sub_123E6C.
   Kazda polozka ma 12 bajtu: {tvar, 0, x0, y0, x1, y1} - sub_123EA7 v ni
   hleda oblast, ve ktere lezi kurzor, a vezme z ni CISLO TVARU; sub_12439D
   pak kresli jen kdyz je tvar > 0. IDA z techto tabulek udelala jednobajtove
   `_UNKNOWN`, takze se cetly nuly/smeti -> tvar vzdy 0 a kurzor se NIKDY
   nenakreslil (misto nej se jen posouval ulozeny kus pozadi).
   Bajty jsou doslova z EXE (Debug/diss/Orion2.exe.asm). */
char *off_17CF22 = "MULTIGM.LBX"; // weak
// PORT (vlna 73): 17D1F9..17D218 je JEDNA souvisla 32bajtova tabulka - v asm
// jdou byte_1751F9, byte_1751FA, byte_1751FB a byte_1751FC[29] tesne za sebou.
// sub_5BD97 z ni cte jako byte_17D1F9[3*atribut + hodnota] cisla do popisu
// rasy; dokud byl byte_17D1F9 jen jeden nulovy bajt, vypisovaly se same nuly
// (zmereno: "Ship Defense:0" misto "Ship Defense:+50").
// byte_17D1FA/FB/FC jsou ted makra na offsety do teto tabulky.
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
// PORT (vlna 83): TABULKA POCTU PLANET, 10 radku (hod kostkou 1..10) krat
// 6 typu hvezdy. V portu to byl JEDEN nulovy bajt, takze `sub_8C527` vracela
// pro skoro kazdou hvezdu 0 planet, `sub_8E280` nemela co zapsat do pole
// satelitu a hra skoncila vlastni hlaskou "Found no satellites after 3_MIN
// enforcement". Bajty vytazene z Debug/diss/Orion2.exe.lst
// (0x17D680..0x17D6BB, dalsi symbol je byte_17D6BC).
// VLNA 89i: tabulka ma DESET polozek, ne osm. `sub_8BFA3` ji indexuje typem
// planety (`byte_17D81C[planeta[+8]]`), a ten je 0..9 - viz SAVE10.GAM, kde
// pole +8 zaznamu planety ma rozsah 0..9. V .lst na 0x17581C nasleduje
// `db 0,0,0,1,1,2,2,1` a hned za tim byte_175824 = 2 a byte_175825 = 3, tedy
// fyzicky jedno desetiprvkove pole; IDA ho oriznula na osm a posledni dve
// polozky pojmenovala zvlast. Cteni indexu 8/9 pak v portu spadlo na
// byte_17D826 (0x40), takze planeta[+11] vychazela az 64 misto 0..3.
   /* vlna 122: barevna rampa z obrazu hry */
// PORT (vlna 59): pole nazvu v tabulce zaznamu po 23 bajtech. sub_5DF0A do
// nej pise ukazatele na retezce z TECHNAME.LBX vyrazem
// `*(int *)((char *)&dword_17D8ED + v4) = v7` pro v4 = 46, 69, ... 1909,
// tedy skoro 2 kB ZA konec skalaru. Prepisovalo to sousedni globaly (mimo
// jine `byte_199CAE` = jazyk) - viz komentar u word_17D90E.
// PORT (vlna 59): NENI to ctyrprvkove pole, ale ZACATEK tabulky zaznamu po
// 23 bajtech - sub_5E1E3 do ni pise `*(int16_t *)((char *)&word_17D90E[v23]
// + 23 * techId) = v21`. V asm blok bezi od 0x17590E az k dalsimu skutecnemu
// symbolu dword_17606C (jmena dword_175916 / byte_17591A / word_175998 uvnitr
// jsou jen odkazy do jeho stredu), tedy 0x17E06C - 0x17D90E = 0x75E = 1886 B
// = 23 * 82 zaznamu. Se ctyrmi prvky zapisy odchazely DALEKO za konec a
// prepisovaly sousedni globaly - mimo jine `byte_199CAE` (jazyk). Zmereno
// kontrolnimi body: pred sub_5E1E3 je jazyk 0, po nem 81/108/110/112/244/252
// (= hodnoty citace v21). Clamp `>= 6 -> 0` to vetsinou zamaskoval, ale kdyz
// smeti padlo do 0..5, hra sahla po cizim jazyce a spadla na chybejicim
// HISTRNGS.LBX / HFSTRNGS.LBX (asi 1 beh ze 6).
// PORT (vlna 80): STROM TECHNOLOGII - JEDEN souvisly blok 0x17E06C..0x17EB3C
// (13 B hlavicka + 212 zaznamu po 13 B). Do teto vlny byl v portu rozsekany na
// sedm promennych a hlavne CELY VYNULOVANY - obsah se nikdy neprenesl. Kvuli
// tomu `sub_5E1E3` nemel co zapsat do `word_17D90E` a `sub_5E55F` pak volal
// `sub_1247A0(0)` -> deleni nulou hned po vyberu barvy vlajky.
//
// Bajty vytazene z `Debug/diss/Orion2.exe.lst` (listing MA u kazdeho radku
// adresu, takze slo presne dopocitat i mista, kde IDA vypsala dvojici
// id+slot jako `dd offset jpt_D01BF+0A8h` misto cisla - hodnota je adresa
// toho navesti). Kontrola: pole +4 vyslo u vsech 212 zaznamu rovno jejich
// poradi 0..211 a pole +6 (slot) je v rozsahu 0..74 s jedinou -1, presne jak
// to `sub_5E1E3` ceka (`!= -1 && != 74`).
//
// Ukazatel na nazev (+0) je tu jen jako staticky placeholder 0x00170A04 -
// za behu ho prepisuje `sub_5DF0A`. Na x64 se 8bajtovy ukazatel do
// 13bajtoveho zaznamu nevejde, takze nazvy drzi dal samostatne
// `off_17E079` / `off_17E0EE` / `off_17E7F0` / `off_17EA60` (stejne rozbite
// jako pred touhle vlnou - viz PROGRESS.md, vlna 80).
// vlna 80: ukazatele na nazvy technologii zustavaji MIMO `techBlk_17E06C`
// (na x64 maji 8 B, do 13bajtoveho zaznamu se nevejdou).
// wave 179: off_17E079 / off_17E0EE / off_17E7F0 / off_17EA60 are macros into
// techBlk_17E06C (orion_common.h).
// VLNA 89d: 0x17EB2A je zacatek tabulky 19bajtovych zaznamu technologii;
// na +0 kazdeho zaznamu je CTYRBAJTOVY ukazatel na nazev, ktery za behu plni
// sub_5DF0A (orion_part_04.c) smyckou `for (j = 0; j != 931; ...) j += 19`,
// tedy 49 zaznamu od dword_17EB2A. Ctenari ale indexuji od off_17EB3D, coz je
// 0x17EB2A + 19, tedy zaznam c. 1. V originale je to jeden souvisly blok,
// v portu to byly DVA ruzne objekty - ctenari dostavali smeti (zmereno: do
// %s v sub_C3111 sel ukazatel -1 a hra padla uvnitr sprintf).
// Na x64 se 8bajtovy ukazatel do 19bajtoveho kroku nevejde, takze stejne jako
// u nazvu technologii (vlna 80) a velikosti lodi (vlna 81) drzime ukazatele
// v POSTRANNIM poli. Index = bajtovy offset od &off_17EB3D deleny 19, plus 1.
char *techName_17EB2A[64]; // weak
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
/* vlna 153: v originale je tohle POLE ZAZNAMU po 28 bajtech
   (asm `imul eax, 1Ch` + `mov esi, off_177803[eax]`), ne jediny ukazatel.
   IDA pojmenovala jen dva sloty prvniho zaznamu, takze port mel jen dva
   ukazatele a cteni `*(&off_17F803 + 7 * i)` slo mimo ne. Vsech 34 polozek
   v te oblasti ukazuje na tentyz prazdny retezec (`unk_170A04` = nulovy
   bajt) a nikdo do tabulky nezapisuje, takze staci vyplnit jim cele pole. */
#define OFF_PRAZDNY8   &unk_178A04, &unk_178A04, &unk_178A04, &unk_178A04, \
                       &unk_178A04, &unk_178A04, &unk_178A04, &unk_178A04
#define OFF_PRAZDNY64  OFF_PRAZDNY8, OFF_PRAZDNY8, OFF_PRAZDNY8, OFF_PRAZDNY8, \
                       OFF_PRAZDNY8, OFF_PRAZDNY8, OFF_PRAZDNY8, OFF_PRAZDNY8
_UNKNOWN *off_17F803[256] = { OFF_PRAZDNY64, OFF_PRAZDNY64, OFF_PRAZDNY64, OFF_PRAZDNY64 }; // weak
_UNKNOWN *off_17F807[256] = { OFF_PRAZDNY64, OFF_PRAZDNY64, OFF_PRAZDNY64, OFF_PRAZDNY64 }; // weak
// PORT (vlna 81): NAZVY VELIKOSTI LODI. V originale jsou to dva 4bajtove
// ukazatele UVNITR 36bajtoveho zaznamu (+0 a +4, zaznamy 1..9), ktere za behu
// plni `sub_5DF0A` z retezcoveho blobu. Na x64 ma ukazatel 8 B, takze
// - zapis `*(_UNKNOWN **)((char *)&off_180014 + i4 + 2) = v35` prepisoval
//   navic 4 sousedni bajty zaznamu a
// - cteni `*(&off_18003A + 9 * i)` se posouvalo po 8 B misto po 36 B a mimo
//   objekt `off_18003A` (ktery je v portu samostatna promenna).
// Dusledek: `sub_57871` volal `strcpy` z adresy 0xC8 a hra padla hned po
// dokonceni generovani vesmiru (zmereno: SEH 0xC0000005, cteni z 0xC8).
// Reseni: ukazatele se drzi v postrannich polich, krok 36 B tim odpada.
// Zapisove smycky i vsech 15 ctecich mist jsou prepsana na indexy.
char *shipSizeNameA_18003A[9]; // +0 zaznamu 1..9
char *shipSizeNameB_18003E[9]; // +4 zaznamu 1..9
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
char *off_18175C = "DESIGN.LBX"; // weak
char *off_181FE4 = "FLEET.LBX"; // weak
   /* vlna 122: barevna rampa z obrazu hry */
char *off_1820B4 = "GAME.LBX"; // weak
char *off_182278 = "OFFICER.LBX"; // weak
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 136: barevna rampa fontu z obrazu hry */
   /* vlna 136: barevna rampa fontu z obrazu hry */
   /* vlna 136: barevna rampa fontu z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 136: barevna rampa fontu z obrazu hry */
/* PORT (vlna 125): v originale je tohle JEDNA souvisla tabulka - `word_17A2B8 dw 0`
   a hned za ni `word_17A2BA[32]`. `sub_9BF70` indexuje OBE cislem radku:
   `word_1822B8[v69]` je horni okraj radku (+39) a `word_1822BA[v69]` spodni,
   takze prvek i+1 prvni tabulky musi byt prvek i te druhe. V portu bylo
   `word_1822B8[] = { 0 }`, tedy JEDNOPRVKOVE pole - uz radek 1 cetl mimo a
   vsechny radky na obrazovce PLANETS se kreslily na stejne y.
   Zmereno zespoda: sonda na `sub_1210FD` v dosboxu i v portu vede do
   `sub_9BF70`, y radku vychazi z teto tabulky. */
/* word_1822BA je druhy prvek te same tabulky - viz orion_common.h */
char *off_1822FA = "PLNTSUM.LBX"; // weak
/* PORT (vlna 127): v originale jsou to DVA nezavisle 16bitove priznaky
   (`DISPLAY RESTRICTIONS` na obrazovce PLANETS - tlacitka na y=266 a y=358);
   v obraze hry jsou oba nulove. IDA je slepila do jednoho ctyrbajtoveho
   symbolu a v portu z toho vznikl UKAZATEL NA FUNKCI - na x64 osm bajtu,
   inicializovany adresou sub_10000. Cteni `(_WORD)off_18230E` tedy vracelo
   spodni pulku te adresy, tedy nenulu, a filtr "No Enemy Presence" byl
   natrvalo zapnuty. */
char *off_182314 = "SCORE.LBX"; // weak
// PORT (vlna 58): NENI to sesti bajtovy retezec, ale TABULKA 10 jmen po 20
// bajtech (jen prvni je predvyplnene "Moise", zbytek je v originale nulovy).
// sub_9F540 (Hall of Fame) do ni indexuje `&aMoise[20 * idx]` pro idx az 8 a
// dela mezi sloty `strcpy` - s [6] to cetlo a PSALO daleko za konec.
// Velikost overena vzdalenosti k dalsimu symbolu v asm
// (aMoise -> byte_1823E0 = 200 bajtu = 10 * 20).
// Vlna 58: tabulka ma v originale VSECH 10 vychozich jmen (overeno
// vypisem bajtu z Debug/diss/Orion2.exe.asm: 200 B, 63 nenulovych,
// 10 slotu po 20 B). Puvodne tu bylo jen "Moise" a zbytek nuly,
// takze se HALL OF FAME vykreslila s prazdnym sloupcem jmen.
/* vlna 134: procenta ztmaveni pro deset urovni stinu planety (sub_A5050),
   v obraze souvislych 10 bajtu 0A 14 1E 28 32 3C 46 50 5A 64. IDA vypsala
   prvni jako jednoprvkove pole a zbylych devet jako samostatne skalary,
   takze `byte_1823E0[uroven]` cetlo pro uroven>0 mimo pole.
   byte_1823E1..E9 jsou ted makra do nej (orion_common.h). */
   /* vlna 122: barevna rampa z obrazu hry */
/* PORT (vlna 121): SEST BAREVNYCH RAMP TEXTU byla kazda jen JEDEN nulovy bajt.
   `sub_120BB5`/`sub_120CCB` z nich kopiruji 8 B do `byte_1B3E88` (a odtud se
   po stinovem pruchodu obnovuje `byte_1B3E7C`), takze VSECHEN text kresleny
   pres ne mel barvu 0 = cernou na cernem podkladu - "prazdne" spodni panely
   na COLONIES. Obsah je primo z obrazu hry (Orion2.exe.asm, cseg01:0017AC26
   a dal; C jmeno = asm + 0x8000). Kazda rampa ma 8 polozek, unk_182C46 dve
   a unk_182C56 osm - hranice dava az dalsi symbol dword_182C96. */
   /* vlna 122: barevna rampa z obrazu hry */
_UNKNOWN *off_183554 = &unk_1A8B34; // weak
_UNKNOWN *off_183558 = &unk_1A74B4; // weak
int (*funcs_DDFF0[3])() = { &sub_DE0C6, &sub_DED47, &sub_DFE77 }; // weak
char a1200[5] = "1200"; // weak
/* PORT (vlna 123): styly oken obrazovky INFO. Kazdy blok ma DESET bajtu
   a sub_103990 (a jeho sest dvojcat) ho kopiruje pres `movsd/movsd/movsw`
   do unk_1836B4. IDA z toho udelala tri jednobajtova prirazeni a ze sesti
   dvojcat NO-OP JUMPOUTy, takze se styl okna nikdy neprepnul.
   Data primo z obrazu hry (dseg02:0017B6A0 a dal, C jmeno = asm + 0x8000). */
   /* cil kopie */
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
char a1234567890[14] = "1234567890+- "; // weak
// wave 179: Tech Review category lists (id, flags: 04 heading in billtex2.lbx,
// 02 technology, 08 end) and the table off_183B0E that sub_108611 indexes.
uint8_t *off_183B0E[4] = { unk_183938, unk_1839AC, unk_183A16, unk_183A6E }; // weak
/* PORT (vlna 122): datovy blok obrazovky INFO. V portu z nej byly same
   jednobajtove/ctyrbajtove pahyly:
     - `unk_183B1E/26/2E/3E` jsou OSMIBAJTOVE BAREVNE RAMPY (jdou do
       `sub_120BB5`/`sub_120D79`, ktere z nich ctou 8 B),
     - `off_183B77` a `off_183BCB` jsou TABULKY SEDMI CTYRBAJTOVYCH UKAZATELU
       (asm: `dd offset unk_17BB46` a dalsich sest), ne jeden ukazatel;
       `sub_107214` je indexuje `(char *)&off_183B77 + 4*i`, takze uz prvek 1
       cetl mimo a `sub_10A064` sahala na adresu 0 - pad na INFO.
   Obsah primo z obrazu hry (dseg02:0017BB1E a dal, C jmeno = asm + 0x8000).
   `byte_183B24` a `byte_183B36` zustavaji samostatne - ctou se jen jako
   skalary a maji spravnou hodnotu. */
char *off_183B77[7] = { unk_183B46, unk_183B4D, unk_183B54, unk_183B5B,
                        unk_183B62, unk_183B69, unk_183B70 };
char *off_183BCB[7] = { unk_183B93, unk_183B9B, unk_183BA3, unk_183BAB,
                        unk_183BB3, unk_183BBB, unk_183BC3 };
/* vlna 129: v obraze hry je souvisla tabulka peti dvojic (x, y) pro tlacitka
   na obrazovce INFO (sub_106CAC): 15 32 15 4D 15 66 15 80 15 9A. IDA ji
   rozsekala na jednoprvkovy byte_183C27 a byte_183C28[9], takze
   `byte_183C27[2*i]` (x) cetlo mimo pole - tlacitka mela x 21, 40, 8, 26, 27
   misto petkrat 21. byte_183C28 je proto uz jen makro na +1 (orion_common.h).
   Hranici dava dalsi symbol word_183C31 na +10 (v obraze D8 00 = 216). */
// wave 179: one table of (x, y) pairs for the Tech Review buttons;
// word_183C33 is a macro for word_183C31 + 1 (orion_common.h).
/* PORT (vlna 123): CTYRI zaznamy po 17 B pro sub_109E01 (ramecky a jejich
   barvy na obrazovce INFO). V portu to byl jeden nulovy bajt, takze zeleny
   panel nedostal svuj odstin (179/177/177) a zustal po vypnu z sub_129130
   (178/179/179). Data z obrazu hry, dseg02:0017BCFC. */
/* vlna 123: zaznam ma 17 B, ne 16 - posledni bajt (0xB0) chybel */
/* vlna 123: DVA zaznamy po 17 B, dseg02:0017BD73 */
// wave 179: row tables of the first INFO descriptor (block_183E15 +8/+12/+16),
// measured with DUMPMEM at the entry of sub_106CAC. IDA shows the first dword
// of off_183DC9 as `dd offset unk_1B8000`, but the game holds 0x001B0000 there:
// no relocation, just the words 0 and 27.
   /* vlna 122: barevna rampa z obrazu hry */
/* vlna 130: dalsi souvisla tabulka sedmi dvojic (x, y), rozsekana IDA na
   jednoprvkovy word_183FF1 a word_183FF3[13]. Hranici dava word_18400D na +28. */
/* vlna 130: v obraze je jedna souvisla tabulka sedmi dvojic (x, y).
   IDA ji rozsekala na jednoprvkovy word_18400D a word_18400F[13],
   takze `word_18400D[2*i]` cetlo mimo pole. word_18400F je uz jen
   makro na +1 (orion_common.h). */
/* vlna 130: v obraze je jedna souvisla tabulka sedmi dvojic (x, y).
   IDA ji rozsekala na jednoprvkovy word_184037 a word_184039[13],
   takze `word_184037[2*i]` cetlo mimo pole. word_184039 je uz jen
   makro na +1 (orion_common.h). */
/* vlna 130: v obraze je jedna souvisla tabulka sedmi dvojic (x, y).
   IDA ji rozsekala na jednoprvkovy word_184053 a word_184055[13],
   takze `word_184053[2*i]` cetlo mimo pole. word_184055 je uz jen
   makro na +1 (orion_common.h). */
/* vlna 130: v obraze je jedna souvisla tabulka sedmi dvojic (x, y).
   IDA ji rozsekala na jednoprvkovy word_18406F a word_184071[13],
   takze `word_18406F[2*i]` cetlo mimo pole. word_184071 je uz jen
   makro na +1 (orion_common.h). */
int (*off_1840A3)() = &sub_10CDC1; // weak
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
   /* vlna 122: barevna rampa z obrazu hry */
_UNKNOWN *off_184480 = unk_1B0848; // weak
_UNKNOWN *off_184484 = unk_1B0848; // weak
int (*dword_184488)(_DWORD) = NULL; // weak
_UNKNOWN *off_184496 = (_UNKNOWN *)0x20000; // weak (was &loc_20000 - see sub_10000 comment, same false-positive-address class)
// PORT (vlna 63): NENI to ukazatel, ale obycejna 32bitova promenna s dvema
// 16bitovymi pulkami. V asm je to `off_17C4B2 dd offset loc_E0000`, jenze
// `loc_E0000` je KONSTANTA 0xE0000, ne adresa (stejna past jako `loc_FFFF8`
// ve vlne 25q - polozka katalogu "konstanta jako navesti").
// Pouziti to potvrzuje: `LOWORD(off_1844B2) = 1/0` (priznak),
// `HIWORD(off_1844B2) = result`, `SHIWORD(off_1844B2)` (hodnota).
// Dusledek chyby: `(_WORD)off_1844B2` = dolni pulka ADRESY stubu, tedy skoro
// vzdy nenulova -> `if ((_WORD)off_1844B2) break;` ukoncilo vlacec� smycku
// `while (sub_124075())` v sub_11CEF5 HNED na prvni iteraci. Ovladaci prvek
// se proto ohlasil znovu a znovu po celou dobu drzeni tlacitka (zmereno:
// 71 ohlaseni a 76 posunu hodnoty na JEDNO kliknuti).
// U spravne hodnoty 0xE0000 je dolni pulka 0, takze se smycka nepreursi.
/* PORT (vlna 26 pokr. 41): stejna 12bajtova tabulka oblasti kurzoru jako
   unk_17CF00 & spol. (viz komentar tam), jen se plni az za behu - sub_123491
   do ni ulozi rozmery obrazovky. IDA z ni udelala 1bajtovy `_UNKNOWN` plus
   dve samostatne promenne word_18452A/word_18452C, coz jsou ve skutecnosti
   jeji pole +8 (x1) a +10 (y1); v portu na sebe nemusely navazovat. */
// PORT (vlna 26 pokr. 41): zabrana proti opakovanemu vstupu do obsluzne
// rutiny myshi (asm: "cmp dword ptr unk_17C52E, 1" v sub_1236D1). IDA ji
// mezi globaly vubec nevytvorila. V originale je to dword na 0x18452E, ktery
// dvema hornimi bajty zasahuje do qword_184530 - tam jsou ale trvale nuly
// (uzitecna cast te promenne zacina az na +4, viz WORD2/SHIDWORD pouziti),
// takze samostatna promenna je s originalem shodna.
int64_t qword_184530 = 2748779069440LL; // weak
// VLNA 11: drive "_UNKNOWN unk_184538" (= char!) - vyska obrazovky
// (200/240/480 dle rezimu, viz sub_1248AB). Jako char se 480 orezalo na
// -32 a soucin vyska*sirka vysel -20480 -> "Insufficient Memory!" pri
// alokaci VGA bufferu. Puvodni sirka dat: 4 bajty (0x184538..0x18453C).
char *off_1845D4 = "Resource deadlock would occur"; // weak
int (*dword_189164)(_DWORD, _DWORD) = NULL; // weak
int (*dword_189168)(_DWORD) = NULL; // weak
int (*dword_18916C)(_DWORD) = NULL; // weak
int (*dword_189170)(_DWORD, _DWORD, _DWORD) = NULL; // weak
char *off_1897C4 = "OK"; // weak
int (*dword_1897C8)(_DWORD) = NULL; // weak
int (*off_189864)(_DWORD) = &nmalloc; // weak
int (*off_189868)(_DWORD) = &nfree; // weak
void (*off_18A54C)(void) = &_no_support_loaded; // weak
int (*dword_18A5AC)(_DWORD) = NULL; // weak
char (*off_18A5B8)() = &sub_15C730; // weak
// PORT (wave 25h): dword_18A610/614/618/61C/620/624/628/62C/630/640/644/
// 648/64C (plus unk_18A610, an alias for the same address under a
// different decompiler-guessed name) were 13 separate 4-byte globals -
// IDA named each one because different code reads/writes specific byte
// offsets within what is actually ONE contiguous 64-byte (16-dword) block
// in the original data segment (confirmed: qmemcpy(dest, block18A610, 0x40)
// at orion_part_25.c reads all 64 bytes as a single unit, and the
// addresses are exactly 4/16 bytes apart with no other symbols between
// them up to dword_18A650, a confirmed-unrelated function-pointer table).
// As separate C globals there is no guarantee of contiguous, gap-free
// layout (the compiler/linker is free to reorder/pad them) - the qmemcpy
// read that assumed otherwise fed garbage adjacent-memory bytes into a
// self-referential pointer table (sub_167320), causing an access
// violation. Fixed by merging them into this single backing array; every
// call site now indexes block18A610[] directly (index = old byte offset
// / 4) instead of using the old per-symbol names.
uint32_t block18A610[16] = {0}; // weak
int (*dword_18A69C)(_DWORD) = NULL; // weak
// PORT (wave 25n): the Smacker bit-reader's "currently loaded, partially
// consumed word" (the value shifted 1 bit at a time alongside byte_18A6C0's
// bit-count) is ANOTHER register that survives across sub_164600/sub_164200/
// sub_1642A0 call boundaries in the original asm - same class of bug as the
// bitstream cursor (a5) fixed in wave 25m, just the sibling register. The
// decompiler modeled it as a plain by-value parameter/local in each function,
// silently discarding the leftover bits every time control returned to a
// caller. Promoted to a global exactly like byte_18A6C0 (its constant
// companion) so every read/consume site shares the same persistent state.
unsigned int g_smkBitAccum = 0; // weak
// PORT (wave 25o): sub_167320's per-frame block/pixel decoder shares ONE
// continuous bitstream+accumulator (asm ebp=word, esi=cursor) across a
// dispatch trampoline: sub_167320 decodes a "what kind of block is this"
// symbol using dword_18A60C's tree, then does `jmp dword_18A650[ecx*4]` into
// one of sub_1664F0/sub_166830/sub_167040/sub_167190 (or their 164A40-family
// siblings), which consume MORE bits from the SAME accumulator/cursor to
// decode pixel values, then `JUMPOUT(0x1675C0)` back into sub_167320's own
// body to decode the next block-type symbol - a raw-jmp code-sharing trick
// with no direct C equivalent. Hex-Rays modeled the jmp-with-register-state
// as if each target were a real function taking the accumulator/cursor as
// by-value parameters (a2/a4), which is only correct for a SINGLE hop - it
// silently drops the continuation, resetting state on every trip through the
// "loop". These two globals are the shared, persistent registers (separate
// bitstream session from g_smkBitAccum's tree-init use, but same treatment).
unsigned int g_smkFrameAccum = 0; // weak
unsigned int *g_smkFrameCursor = 0; // weak
// PORT (wave 25o): the third register in the same trampoline - asm edi, the
// "current output write position" (block18A610-tree leaf pixel/motion data
// gets written through it). Confirmed via dosbox-x DUMPREGS at loc_167694
// (0x38B694) vs sub_1664F0's entry (0x38A4F0): eax/ecx/edx differ (scratch),
// but esi/ebp/edi are IDENTICAL across the jmp - all three are persistent
// registers threaded through the whole per-frame decode trampoline, not
// fresh per-call values. Seeded once in sub_167320 from `*(a3+4)` (confirmed:
// asm `mov eax,[edi+4]` right before `mov edi,eax` at loc_1675B9).
_DWORD *g_smkFrameOutput = 0; // weak
// PORT (wave 25o): the decoded block-type symbol register (asm eax) is
// ALSO persistent across Smk167320_DecodeBlockTypeAndDispatch calls - the
// original only ever does `LOWORD(v19) = ...` (asm `mov ax, ...`) when
// combining a freshly-decoded value with the swap-table lookup, leaving the
// HIGH word untouched from whatever eax held before (seeded once from
// `*(a3+4)` at the very start of sub_167320, alongside g_smkFrameOutput).
// Splitting the block-type decoder into its own function turned this into
// a fresh (uninitialized-high-word) local each call, producing wildly wrong
// symbol values from the second call onward. Promoted to a global for the
// same reason as g_smkFrameAccum/Cursor/Output.
int g_smkBlockTypeSymbol = 0; // weak
// PORT (wave 25p): IDA declared this as a single dword (`dd 1`), but the
// original reads it as `dword_1826E0[(v19&0xFC)]` (0..252, i.e. up to 64
// entries) - the raw disassembly right after the `dd 1` shows
// `db 2,0,0,0 / db 3,0,0,0 / db 4,0,0,0 ...`, a plain little-endian dword
// sequence 1,2,3,4,... that IDA never grouped into a named array because
// nothing referenced entries 1+ by a symbol, only via computed indexing.
// A single `int` here meant every index other than 0 read whatever
// happened to sit next in THIS port's data segment (a different, unrelated
// global) - harmless for simple 2-color content (block-type symbols that
// only ever produced index 0), but produced garbage step counts for
// richer content (the space/nebula cinematic), causing sparse/grid-pattern
// corrupted blocks. The sequence itself is trivial (array[k] = k+1), so
// just spelled out as a real 64-entry array instead of pointer overrun.
// PORT (wave 25r): the LAST FIVE entries are NOT 60..64 - the run lengths
// jump to powers of two. Wave 25p reconstructed this table from the start of
// the asm data (`dd 1` followed by raw `db 2,0,0,0 / 3,0,0,0 / ...` bytes
// IDA never grouped into an array) and extrapolated a plain 1..64 ramp; only
// the first 59 entries actually follow it. The asm data really ends
// `... 3Ah, 3Bh, 80h, (0,1,0,0), (0,2,0,0), (0,4,0,0), (0,8,0,0)` =
// 58, 59, 128, 256, 512, 1024, 2048 - i.e. the standard Smacker block-run
// table. CONFIRMED at runtime too: dosbox `DUMPREGS` at sub_167190's entry
// (runtime 0x38B190) shows edx (= this lookup's result, stored into
// dword_18A664) taking the values 2048/2048/512/128/59/5 for symbols whose
// indices are 63/63/61/59/58/4.
// Why this mattered so much: dword_18A664 is the block RUN LENGTH - how many
// blocks the handler fills before the frame is done. Capping it at 64 instead
// of up to 2048 meant a frame that the original finishes in 6 blocks never
// finished in the port, which kept feeding the decoder past the end of the
// frame's data: the port ran 1230592 dispatch blocks where the original ran
// 1769, and the surplus garbage symbols showed up as block types 1 and 3
// being ~6-9x over-represented versus the original's histogram.
int block18A6E0[64] = {
    1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,
   13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,
   25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,
   37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,
   49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
  128, 256, 512, 1024, 2048
}; // weak
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
int (*off_18ACD4[2])() = { &sub_15E2F0, &sub_15E330 }; // weak
int (*off_18ACD8)() = &sub_15E330; // weak
MixStepBlock g_mixStepBlock = { 0, 0 }; // viz orion_common.h
void (__noreturn *off_18AD48)() = &_terminate; // weak
double dbl_18ADBE = 1.7976931348623157e308; // weak
float flt_18ADC6 = 3.4028235e38; // weak
_UNKNOWN *off_18B018 = &loc_168636; // weak
_UNKNOWN *off_18B04A = (_UNKNOWN *)0x1684C2; // weak
// PORT (vlna 85): TABULKA SPRITU HVEZD - 12 hvezd po 4 polozkach.
// V originale jsou to 4bajtove sloty s ukazateli (`dword_188298` a
// `dword_1882A4` = tyz blok, jen o 12 B dal). V portu byl blok rozdeleny na
// dva symboly, `dword_190298` mel neurcitou velikost a `link_stubs.c` k nemu
// mel jeste duplicitni skalar - `sub_EB9C8` pak cetla NULL a padala.
// Na x64 se 8bajtovy ukazatel do 4bajtoveho slotu nevejde, takze je z toho
// rovnou pole UKAZATELU; vsechna tri pristupova mista indexuji po prvcich
// (`4*hvezda + varianta`), takze zmena kroku nicemu nevadi.
void *dword_190298[48]; // weak
/* vlna 85: makro do dword_190298 (+3 prvky) */
// PORT (vlna 103): CELY blok zaznamu o 12 B zacina uz na 0x1906C0, ne az na
// 0x1906C8. Vlna 85 srovnala jen `word_1906C8`/`word_1906CA`, ale kod
// indexuje `6 * i` i u prvnich ctyr poli (`word_1906C2[6 * v0]` = id lodi,
// `word_1906C6[6 * v0]` = typ), takze pro i > 0 letely mimo jednoprvkove pole.
// Projevilo se to na obrazovce FLEETS: `sub_737A2` kreslila sprite lodi na
// souradnice z takoveho cteni (zmereno brzdou v sub_14852C: x=-10,
// y = kazdy beh jina - naposledy -6281).
// Rozsah z asm: 0x1886C0 az 0x18A190 (dalsi symbol dword_18A190), tedy
// 6864 B = 3432 slov. `word_1906C2/C4/C6/C8/CA` jsou makra do nej.
// PORT (vlna 85): SOUVISLY BLOK pozic hvezd na mape, zaznam 12 B
// (`word_1906C8[6*i]` = x, `word_1906CA[6*i]` = y). IDA ho rozdelila na dva
// symboly 2 B od sebe; `word_1906CA` uz mel spravnych 3427 prvku, ale
// `word_1906C8` zustal neurcity (1 prvek) a v `link_stubs.c` byl navic
// jako FUNKCE. Zapis `word_1906C8[6*i]` proto letel mimo.
/* vlna 103: `word_1906C8` je ted makro do `word_1906C0` (+4 slova). */
/* vlna 85: makro do word_1906C8 (+2 B) - viz orion_common.h */
// PORT (vlna 73): tri souvisle bloky, ktere IDA rozdelila na skalary.
// Rozvrzeni z asm: 18A190 + 4*31 = 18A20C (dword_19220C je prvek 31),
// 18A210..18A224 je sest dwordu a 18A228..18A244 osm dwordu (vsechny je
// plni sub_CE0E5 za sebou retezci 623..628 a 636..643).
// Plnici smycka pro dword_192190 v sub_1D6DE jde do 32, takze zapis
// posledniho prvku koncil mimo pole; dword_192228 se indexuje typem
// vlady rasy (0..7) a mel jen jeden prvek - to shodilo strcpy v
// sub_5BD97 pri vypisu popisu rasy.
// PORT (vlna 58): 0x192630..0x192680 je JEDNA souvisla tabulka 20
// ukazatelu na retezce; sub_CE0E5 ji plni po sobe jdoucimi zapisy
// (asm sub_CE0E5+1BD az +2CB) a ctenari do ni indexuji jak pres
// dword_192630[i], tak pres dword_192644[i] (= offset 5). IDA ji
// rozsekala na 20 samostatnych globalu, takze v portu vracelo
// dword_192630[i] pro i>0 nulu -> strcpy z NULL v sub_9F540
// (pad HALL OF FAME). Ostatni jmena jsou makra v orion_common.h.
uint8_t* dword_192B18; // weak
/* vlna 154: drzi UKAZATEL z alokatoru (asm cseg01:00072A7B `mov dword_18AB24, eax`),
   ne cislo. Jako `int` se na x64 adresa orizla na 32 bitu a vsechna cteni
   `*(_WORD *)(dword_192B24 + 13 * i + N)` sla mimo - pad pri RELOCATE.
   Rozsireno na intptr_t stejne jako dword_1ACEFC a spol. ve vlne 23b. */
intptr_t dword_192B24; // weak
PoolMemType* dword_192EE8; // weak
PoolMemType* dword_192EF4; // weak
// PORT (vlna 88): blok zacina uz TADY, ne az u `word_192FDE` (vlna 85 ho
// zacinala o 2 B pozdeji). Je to 5 ZAZNAMU PO 28 B = 140 B
// (0x192FDC..0x193067) - `sub_797DD` dela `memset(word_192FDC, 0, 140)` a
// ulozena hra `fread(word_192FDC, 28, 5, ...)`. Jako jednoprvkove pole to
// pretekalo a v portu pritom prepsalo horni pulku `dword_192FD8`
// (hvezdne datum), takze se na mape zobrazovalo -3053.-6 misto 3500.0
// (0x88B8 = 35000, po prepsani 0xFFFF88B8 = -30536).
/* vlna 88: makro do word_192FDC (+2 B) - viz vyse */
/* vlna 156: prvek 2 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 3 bloku word_192FDC - makro v orion_common.h */
/* vlna 85: pole +6 tehoz zaznamu - makro do word_192FDE (viz orion_common.h) */
/* vlna 85: pole +8 tehoz zaznamu - makro do word_192FDE */
/* vlna 156: prvek 6 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 7 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 8 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 9 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 10 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 11 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 12 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 13 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 14 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 16 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 17 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 28 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 29 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 30 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 31 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 32 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 33 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 35 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 36 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 37 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 38 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 39 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 40 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 41 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 42 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 46 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 47 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 49 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 50 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 51 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 52 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 53 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 54 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 55 bloku word_192FDC - makro v orion_common.h */
/* vlna 156: prvek 56 bloku word_192FDC - makro v orion_common.h */
uint8_t* dword_193068; // weak
uint8_t* dword_19306C; // weak
uint8_t* dword_1930D4; // weak
uint8_t* dword_193178; // weak
/* vlna 116: SOUVISLE POLE, ne sest skalaru. Adresy 1931AC/AE/B0/B2/B4/B6
   jdou po dvou bajtech a `dword_1931B8` za nimi blok ukoncuje, takze je to
   pole o 6 prvcich. Jsou to VELIKOSTI SPRITU hvezd {33,29,25,23,21,17}
   (plni je sub_6xxxx / sub_1xxxx) a kod je indexuje `word_1931AC[typ]`.
   Dokud to byly skalary, cetl se jen prvek 0 a hvezdy typu >0 se
   necentrovaly - kreslily se o polovinu velikosti vpravo dolu. */
/* vlna 132: 0x1931BC..0x193270 je JEDNA tabulka 15 zaznamu po 12 bajtech
   (180 B - potvrzuje to `memset(&word_1931BC, 0, 180)` v orion_part_10.c).
   IDA z ni udelala pet prekryvajicich se pohledu, ctyri jednoprvkove:
     word_1931BC[6*i] -> +0,  word_1931BE[6*i] -> +2,  word_1931C0[6*i] -> +4,
     word_1931C2[6*i] -> +6,  dword_1931C4[3*i] -> +8.
   `word_1931C2[6*i] > -1` je test platnosti zaznamu, takze se cetlo mimo pole
   a sub_A3BC4 nenakreslila ikonu flotily v pohledu na soustavu (LEADERS). */
// PORT (vlna 86): SEZNAM LODI - 500 zaznamu po 5 B (0x1975D4..0x197F97,
// dalsi symbol je dword_197F98). Zaznam: int16 id planety, int16 dalsi
// v seznamu, byte priznak. Kod indexuje pres `(char *)&word_1975D4 + 5*i`
// a `byte_1975D8[5*i]`. V portu byly prvni dva symboly SKALARY, takze cteni
// pro i > 0 slo mimo a hra hlasila vlastni kontrolou
// "Memory Corruption! val == ..., ship_id == ..." (sub_77FF5, ktera prave
// overuje rozsah 0..499).
uint8_t* dword_197F98; // weak
uint8_t* dword_197F9C; // weak
// PORT (vlna 159): 500 ZAZNAMU PO 9 B (0x197FBC..), zaznam je
// bajt + ctyri int16. Port sam to prozrazuje: `memset(&unk_197FBC, 0, 4500)`
// v orion_part_05.c. Kod indexuje pres `(char *)&word_197FC3 + 9 * i`.
// IDA pojmenovala jen pet poli PRVNIHO zaznamu a zbytek nechala jako
// nepojmenovane bajty, takze cteni pro i > 0 slo mimo - pad v sub_77FF5
// pri otevirani panelu flotily. Stejny vzor jako blk_1975D4 (vlna 86).
PoolMemHeader* dword_19916C; // weak
// PORT (vlna 85): pet po sobe jdoucich int16 (0x1992C0..0x1992C9), ktere
// `sub_792C3` cte jako `word_1992C0[i]` pro i<5. IDA je rozsekala na pet
// skalaru a link_stubs.c mel jeste duplicitni definici.
/* vlna 85: makro do word_1992C0 */
/* vlna 85: makro do word_1992C0 */
/* vlna 85: makro do word_1992C0 */
/* vlna 85: makro do word_1992C0 */
//char byte_199699[19]; // weak
TypeSaveSlotInfo_199699 saveSlotInfo_199699[11];   /* vlna 111: 11 slotu (0..10) - kod indexuje [1+i] pro i=0..9 */
//int16_t word_1996AC[9]; // weak
//char byte_1996BE[333]; // weak
/* vlna 111: byte_19980B JE slot 10 (rozsekany souvisly blok) - viz makro v orion_common.h */
// PORT (vlna 85): PET ZAZNAMU PO 3 B (0x199BCD..0x199BDB): int16 + byte.
// `sub_792C3` do nich pise pres `(char *)&word_199BCD + 3*i` a
// `byte_199BCF[3*i]` pro i<5.
/* vlna 85: makro do blk_199BCD */
/* vlna 85: makro do blk_199BCD */
/* vlna 85: makro do blk_199BCD */

// State/settings block 0x199BDC..0x199E05 (553 B) - see TypeStateBlock_199BDC
// in orion_common.h (wave 18). Replaces ~52 individual IDA globals.
/* vlna 134: centrovaci odsazeni spritu planety podle velikostni tridy 0..4
   (plni sub_6xxxx: 19, 20, 22, 22, 24). IDA vypsala prvni jako jednoprvkove
   pole a zbyle ctyri jako samostatne skalary, takze `byte_199EC2[velikost]`
   cetlo pro velikost>0 mimo pole a planeta se v pohledu na soustavu kreslila
   posunuta. byte_199EC3..EC6 jsou ted makra do nej. */
/* vlna 135: 0x199EC7..0x199ED0 je JEDEN devitibajtovy blok - sub_86188 ho
   maze jednim `memset(&word_199EC7, -1, 9)`. IDA z nej udelala pet
   samostatnych symbolu, takze v portu memset prepisoval sedm bajtu
   v sousednim objektu (naposledy byte_199EC2 - odsazeni stredu spritu
   planety -> pad v sub_147F3E pri kresleni LEADERS).
   word_199EC7/EC9/ECB/ECD a byte_199ECF jsou ted pohledy do nej. */
/* vlna 157: 0x199ED0 je ZACATEK STRUKTURY posuvniku (v originale si jeji adresu bere sub_6FF08 a sub_A00F1 z ni cte az +27), ne skalar. */
int16_t word_199ED0_block[15]; // weak - 30 B, makra viz orion_common.h
/* vlna 157: bajt 2 struktury word_199ED0_block */
/* vlna 157: bajt 6 struktury word_199ED0_block */
/* vlna 157: bajt 8 struktury word_199ED0_block */
/* vlna 157: bajt 10 struktury word_199ED0_block */
/* vlna 157: bajt 12 struktury word_199ED0_block */
/* vlna 157: bajt 14 struktury word_199ED0_block */
/* vlna 157: bajt 16 struktury word_199ED0_block */
/* vlna 157: bajt 18 struktury word_199ED0_block */
/* vlna 157: bajt 24 struktury word_199ED0_block */
/* vlna 157: bajt 26 struktury word_199ED0_block */

uint8_t* dword_19A00C; // weak
int (*dword_19B568)(void); // weak
// PORT (vlna 73): 19B688..19B68F je osmibajtova barevna rampa pisma
// (v asm byte_193688/89/8A a pak `align 10h` az k dword_193690).
// sub_5A3BC ji plni smyckou az do indexu 7, takze jako jednobajtovy
// symbol koncil zapis mimo a nadpisy na obrazovce vlastnosti rasy se
// kreslily sedive misto zelene.
// PORT (vlna 74): 19B6A8..19B707 je JEDNA oblast 48 wordu. `sub_5AAD4`
// zapisuje do `word_19B6A8` 22 id prvku (vnejsi smycka `while (v15 < 64)`
// probehne jen jednou, protoze pocet ve `v31` je 22 a `v15` uz zacina na
// ~46), takze indexy 16..21 lezi az v oblasti, kterou IDA pojmenovala
// `word_19B6C8`. Jako dve oddelena pole zapis pretekal do sousedniho
// symbolu - zmereno: `word_19B694` melo po `sub_5AAD4` hodnoty
// 52 53 54 55 56 57 (id prvku) misto vyberu vlastnosti 0 0 0 0 0 3.
// Dusledek: v prvnich dvou sloupcich obrazovky vlastnosti rasy se
// nekreslila zaskrtavatka.
// PORT (vlna 73): obe pole maji 14 prvku, ne 13. IDA odstepila posledni prvek
// jako samostatny symbol (dword_19B7D8 = dword_19B7A4[13], dword_19B810 =
// dword_19B7DC[13]) - v asm je 1937A4 + 52 = 1937D8 a 1937DC + 52 = 193810.
// Plnici smycka v sub_5BC74 jde do 14, takze zapis indexu 13 koncil mimo pole
// a tlacitko CUSTOM nemelo obrazek (na obrazovce vyberu rasy chybelo).
// PORT (vlna 67): pole ma 14 prvku, ne 3. sub_5C510 ho na dvou mistech nuluje
// smyckou pres indexy 0..13 (asm: `mov word_193820[ebx*2], 0 / cmp ax, 0Eh`),
// takze blok je 0x19B820..0x19B83C. IDA ho orezala na 3 prvky, protoze na
// 0x19B826 nasla dalsi jmeno - to je ale prvek [3] tehoz pole; a `unk_19B83A`
// je prvek [13] (kurzor, predava se jako `&unk_19B83A` do sub_11523B).
// S tremi prvky zapis pretekl a chytil ho az RangeChecks pri ACCEPT v NEW GAME.
// PORT (vlna 75): 19B85C..19B86B je 16bajtovy buffer (v asm `unk_19385C`
// nasledovany 15 db az k dword_19386C) - jmeno naposledy ulozene vlastni
// rasy. `sub_5BC74` do nej dela `fread(..., 15, 1, ...)`; jako jednobajtovy
// _UNKNOWN to prepsalo sousedni promenne, mimo jine `word_19B85A` (index
// zvyraznene rasy), a hra pak sahla na neexistujici polozku RACESEL.LBX.
// Projevi se to az kdyz existuje LASTRACE.RAC.
int (*dword_19BED8)(void); // weak
/* vlna 155: v originale je tohle POLE (`; int dword_193EDC[]`, zapisuje do nej
   sub_7743A) a `dword_193EE0` / `dword_193EE4` jsou jeho prvky [1] a [2] -
   IDA jim jen dala vlastni jmena, protoze se ctou zvlast (u obou jsou pouze
   cteci xrefy). Port mel `int dword_19BEDC[];`, coz je v C NEUPLNY TYP a
   dokonci se na JEDEN prvek, takze zapisy `dword_19BEDC[1]` a `[2]` sly mimo
   a oba sousedni globaly zustaly nenaplnene -> pad v sub_12B753 pri QUIT.
   Aliasy jsou udelane stejne jako u `word_1906C2` v orion_common.h. */
/* vlna 119: SOUVISLA 8BAJTOVA BAREVNA RAMPA, ne osm skalaru. Stavi ji
   `sub_8E5C5` (`memset(byte_19C31C, 0, 8)` + zapis [0] a [1..7]) a pak
   prepisuje jednotlive polozky pres jmena +1..+7 (`byte_19C31E = ...`).
   Dokud to byly samostatne promenne, ty prepisy do rampy VUBEC NESLY -
   napr. index 2 zustal na `top` misto `min(top, base+1)`, takze titulek
   dialogu mel barvu 24 misto 19. */
// PORT (vlna 81): DVE OSMIBAJTOVE BAREVNE RAMPY, ne dva jednotlive bajty.
// V asm je `unk_194338` osm bajtu (0x194338..0x19433F) a hned za nim
// `byte_194340` dalsich osm (do `align 8` pred `byte_194348`). Obe se plni
// pres `qmemcpy(..., 8u)` a predavaji do `sub_120BB5` jako rampa odstinu
// textu. Jako JEDEN bajt z nich vykreslovac cetl sedm bajtu smeti - text
// v poli dialogu "Enter Ruler Name" proto vychazel CERNY (index 0),
// zatimco original ho kresli svetle sedy (172,172,172). Zmereno
// porovnanim snimku portu a dosboxu ve stejnem bode.
// PORT (vlna 58): 0x19C5FC..0x19C7C0 je JEDEN 452bajtovy zaznam Hall of
// Fame - hra ho cte i zapisuje vcelku (`fread/fwrite(&word_19C5FC, 452, 1)`,
// `memset(..., 452)`, `qmemcpy(..., 0x1C4)`). IDA ho rozsekala na 9
// globalu a vetsinu z nich orezala na jeden prvek, takze `byte_19C6EE[i]`
// vracelo pro i>=4 smeti (zmereno: 239, 244, 244 misto 0..4) a jedno jmeno
// bylo poskozene. Rozlozeni: +0 magic, +2 jmena 10x20, +202 skore 10x2,
// +222 rasa 10x2, +242 obtiznost 10x1, +252 nazev rasy 10x20.
// PORT (vlna 58): ctyri nazvy obtiznosti po 15 B lezi za sebou a
// sub_9EE43 do nich indexuje `&unk_19C7C6 + 15 * idx`. `unk_19C7C6` byl
// pritom v portu SAMOSTATNY jednobajtovy _UNKNOWN (stejna past jako
// unk_1AE5D4 ve vlne 54: dve jmena IDA pro tutez adresu), takze treti
// sloupec tabulky zustaval prazdny. Souvisly blok + makra nize.
// Poznamka: `idx` muze byt 0..4 (v12 % 5), pate slovo uz v originale
// zasahuje do nasledujiciho symbolu - proto 75 B, aby to nebylo UB.
// vlna 58: PATY slot tabulky obtiznosti (sub_9F286 do nej dela
// `strcpy(word_19C802, sub_CDF5C(328))`), lezi tesne za byte_19C7F3 -
// proto je ted makro do bloku byte_19C7C6, ne samostatne pole.
int (*dword_19D358)(void); // weak
int (*dword_19FA1C)(void); // weak
// VLNA 89e: seznam zobrazenych kolonii ma DESET prvku, ne devet. Smycky
// v sub_C3D34 pracuji s indexy 0..9 (`do { word_1A0534[v2] = -1; } while (v1
// < 10)` i `if (word_1A0534[v3] != -1) ... while (++v3 < 10)`), a prvek 9 lezi
// presne na 0x1A0546, coz je `word_1A0546` (asm: word_198534 + 2*9 =
// word_198546). Jako [9] + samostatny skalar zapisovala clear-smycka mimo pole
// a `word_1A0546` nikdy nedostalo -1, ktere na nej sub_C4562 testuje.
uint8_t *dword_1A08B0; // weak  /* vlna 89: skutecny ukazatel, viz orion_common.h */
int (*dword_1A08F0)(void); // weak
// PORT (vlna 58): 0x1A09FE az 0x1A0C40 je JEDNO pole zaznamu po 23 bajtech
// (aktivni oblasti okna - souradnice, ukazatel na text, kurzor). Hex-Rays z
// nej udelala 10 samostatnych globalu, ale VSECHNA pristupova mista v
// orion_part_13.c indexuji pres `(char*)&pole + 23*i`, takze v portu se od
// i>=1 cetlo/psalo mimo. Potvrzeno v asm (sub_C68C4: `imul esi, 17h` a
// `word_1989FE[esi]`, `byte_198A14[esi]`) a take memsetem v sub_C6A0C
// (`memset(&word_1A09FE, 0, 575)` = 25 zaznamu * 23 B). Jmena poli jsou ted
// prekryvova makra nad timhle blokem - viz orion_common.h.
int (*dword_1A11B0)(void); // weak
int (*dword_1A11BC)(void); // weak
// PORT (vlna 66): 0x1A125C..0x1A1274 je JEDEN souvisly blok. Prvnich OSM
// bajtu je BAREVNA RAMPA FONTU - `sub_120BB5(font, a2)` z nich plni
// `byte_1B3E7C[0..7]` (barvy jednotlivych urovni glyfu) a volajici mu
// predavaji prave `&byte_1A125C`. V portu byl `byte_1A125C` jednoprvkovy,
// dalsi tri bajty samostatne globaly a bajty 4..7 patrily uz `dword_1A1260`,
// takze se osmibajtove cteni skladalo ze smeti -> TEXT MEL SPATNOU BARVU
// (popisky v NEW GAME vychazely ruzove, index palety 161, misto zelene 123).
// Ze jde o souvislou tabulku, potvrzuje i sub_31F25 (orion_part_02.c), ktere
// tech osm bajtu plni po sobe volanimi sub_133DE1.
// Zbytek bloku (0x1A1260..0x1A1274) je tabulka ukazatelu z vlny 58.
// dword_1A1260 je ted makro do colorBlock_1A125C (vlna 66).
// PORT (wave 24): Hex-Rays declared this as a single-byte placeholder
// (`_UNKNOWN` = `char`), but sub_CDF65 (orion_part_13.c) reads the
// localized "estrings.lbx" record DIRECTLY into it via sub_126C91's mode-3
// path (destination buffer supplied by the caller, no fresh allocation) with
// an explicit 21000-byte size argument at every one of its 6 call sites (one
// per language). A 1-byte buffer receiving an LBX record up to ~21000 bytes
// overflowed massively into whatever followed it in BSS - traced empirically
// (checkpoint bisection) to flipping byte_19A005 from 1 to 0 mid-write,
// which in turn made the main menu (sub_816F2) skip its one-time init
// (sub_81ABE, which sets dword_19C08C) and read that global uninitialized ->
// crash in sub_12A478. Almost certainly also corrupts other neighbors in a
// real build (dword_1A6578, dword_1A6B38, ... - the very buffers sub_CDF65
// itself sets up right after this call). Sized to the 21000 the call sites
// already specify.
// PORT (wave 23): Hex-Rays sized this at 368 (the gap to the next BSS symbol
// dword_1A6B38), but sub_CDF65's string-table loader (orion_part_13.c) writes
// index 0..0x32Bh (811) unconditionally - confirmed in Debug/diss/Orion2.exe.asm
// (`cmp eax, 32Ch` in sub_CDF65). Both this array and dword_1A6B38 are `dd ?`
// (uninitialized BSS) in the original - the 368 "boundary" was just the next
// symbol IDA happened to find, not a real limit. Sized to the real 812 needed.
// PORT (wave 23): sub_CDF65 (orion_part_13.c) treats this as a POINTER
// (`v6 = (_DWORD*)dword_1A6B38; *v6 = ...`) and copies a 13-byte localized LBX
// filename (e.g. "MAINTEXT.LBX\0") into `*v6` via four chunked int/byte writes.
// Declared as a scalar int (always 0), this always wrote through a NULL
// pointer - crashed here once the earlier array-overflow bugs upstream of it
// stopped masking this path. This global IS the destination buffer itself
// (never read back anywhere else in the game - dead/write-only data even in
// the original, per its single XREF in Debug/diss/Orion2.exe.asm), so it needs
// to be the buffer's own storage, not a pointer variable pointing elsewhere.
int (*dword_1A722C[2])(void); // weak
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
int (*dword_1ACF70)(_DWORD, _DWORD, _DWORD); // weak
   /* vlna 122: barevna rampa (v obrazu neinicializovana) */
   /* vlna 122: barevna rampa (v obrazu neinicializovana) */
/* PORT (vlna 26 pokr. 43): DTA (Disk Transfer Area) pro DOS FINDFIRST/FINDNEXT.
   `unknown_libname_1/2` do ni zapisuji celych 43 bajtu (struct DosDta), ale IDA
   z nej udelala jednobajtovy `_UNKNOWN` plus ctyri samostatne promenne, ktere
   jsou ve skutecnosti JEJI POLE: +0x16 cas, +0x18 datum, +0x1A velikost,
   +0x1E jmeno. V portu tedy kazde hledani souboru prepsalo 42 bajtu sousednich
   globalu - zmereno hlidacem v PortDebug_Checkpoint, ze takhle prisel o obsah
   `dword_1B06FC` (buffer pro hlavicku LBX) a hra pak pri kliknuti v menu
   spadla ve `fread`. Vytknuto do jedne struktury, at je rozlozeni jiste. */
struct DosDta unk_1AD828; // weak
/* PORT (vlna 26 pokr. 46): hlavicka STREAM.LBX. `sub_113765` do ni cte
   `fread(&unk_1AD854, 2048, 1, ...)`, ale IDA z nej udelala jednobajtovy
   `_UNKNOWN` -> kazde spusteni hudby menu prepsalo 2047 bajtu sousednich
   globalu. Skutecna velikost je 0x800 = 2048 B (vzdalenost k dalsimu
   symbolu byte_1AE054: 0x1AE054 - 0x1AD854). Stejna trida chyby jako u
   DTA `unk_1AD828` o par radku vyse. */
// vlna 12: tentativni "int dword_1AE0A4[]" nevytvarel definici (LNK2001
// po odstraneni duplikatu z link_stubs.c). V puvodnich datech ma symbol
// 4 bajty (0x1AE0A4..0x1AE0A8). DECOMP_TODO: pouziva se i s indexem
// [v3]/[v10] (streamovani zvukovych samplu, sub_113xxx) - presna sirka
// se doresi az se zvukovou vlnou (kod ted nebezi, zvuk je vypnuty).
/* PORT (vlna 26 pokr. 50): DVA ukazatele na pul-buffery audio streamu.
   `sub_1131F0` je indexuje `dword_1AE0A4[v3]` / `[v10]`, kde v3/v10 je index
   pul-bufferu (0/1) vraceny z `sub_141A76` - v originale tedy jde o jedno
   dvouprvkove pole na 0x1AE0A4 (prvek [1] = 0x1AE0A8). Port mel pole o
   JEDNOM prvku a druhy ukazatel jako samostatnou promennou, takze
   `dword_1AE0A4[1]` sahalo MIMO pole a `fread` pak cetl do smeti ->
   poruseni haldy a tichy `abort()` (navratovy kod 3) hned po rozjeti hudby
   menu. Puvodni poznamka u teto promenne to predpovidala: "pouziva se i s
   indexem [v3]/[v10] ... presna sirka se doresi az se zvukovou vlnou". */
// VLNA 12: blok 0x1AE0AC..0x1AE5D4 = tabulka 33 zvukovych slotu po 40 B
// (10 int) - sub_111F3E ji nuluje memset(..., 1320) a kod k ni pristupuje
// striden "dword_1AE0XX[10 * slot]" pres NEKOLIK ruznych symbolu zaroven
// (dword_1AE0AC=+0, ...B0=+4, ...B4=+8, byte_1AE0B8=+0xC, ...C8=+0x1C,
// ...CC=+0x20, ...D0=+0x24; navic aliasy pres &dword_1AE0AC[10*i] a
// v2[8]). Jako oddelene C promenne se NEPREKRYVALY -> zapisy si stouply
// na sousedni globaly (pad v sub_111F3E). Jeden souvisly backing blok +
// prekryvova makra v orion_common.h zachovavaji puvodni layout presne.
// dword_1AE0D8 (+0x2C) a dword_1AE0F8 (+0x4C) jsou pole slotu 0 a 1.
// VLNA 12: drive "_UNKNOWN unk_1AF620" (= 1 bajt!) - AIL/zvukova struktura,
// hra ji nuluje memset(&unk_1AF620, 0, 4172) a predava do sub_13AE74/
// sub_13AFD2. 4172 = 0x104C = presne vzdalenost k dalsimu symbolu
// (0x1B066C - 0x1AF620), takze jde o souvisly 4172bajtovy blok. Jako
// 1bajtova promenna memset prepisoval sousedni globaly -> pad/abort
// v sub_111F3E jeste pred nactenim fontu.
/* PORT (vlna 126): v originale je tohle JEDEN editacni buffer 0x1B071B..0x1B081B
   (257 B, hned za nim uz je dword_1B081C). IDA ho rozsekala na ctyri symboly
   po jednom bajtu. Widget textoveho pole s nimi pracuje SOUCASNE a spoleha na
   to, ze na sebe navazuji: `byte_1B071C[k]` cte znak a `byte_1B071B[k] = 0`
   ukonci retezec o znak driv (backspace / smazani kurzoru "_"). V portu to byly
   samostatne objekty, takze se koncova nula zapisovala jinam a v ulozenem jmenu
   hvezdy zustal kurzor - odtud "Trilar_" misto "Trilar" na PLANETS i COLONIES. */
int (*dword_1B0840)(void); // weak
int (*dword_1B0844)(void); // weak
// Font data block 0x1B3E7C..0x1B61D8 (9052 bytes) - wave 20.
// sub_120526 loads the whole 9052-byte font record into byte_1B3E7C with
// sub_12779E(byte_1B3E7C, v4, 0x235C). IDA had split the block into ~21
// individually used globals (byte_1B3E7C was even declared char[6]), so that
// copy overflowed and wiped everything after it - including dword_1B3E78
// (font sub-pool), which then crashed sub_1205E6/sub_126CEB with a NULL pool.
// One contiguous backing buffer keeps the original layout; every old symbol
// name is mapped onto its exact offset by the macros in orion_common.h.
// unk_1B5030/unk_1B5418 ODSTRANENO (vlna 10): IDA false-positive z konstant
// 1790000/1791000 (velikost zvukoveho bufferu + prah) - viz orion_part_01.c.
int (*dword_1B9208)(_DWORD, _DWORD, _DWORD, _DWORD); // weak
int (*dword_1B920C)(_DWORD); // weak
int (*dword_1B9210)(_DWORD); // weak
// VLNA 89: 0x1BA318..0x1BA357 je JEDEN souvisly blok 64 B = 16 zaznamu po 4 B
// (pruhlednost/barva prekryvu). asm: `cmp byte_1B2318[eax], 0` s eax = 4*j,
// j < 16. IDA z nej udelala byte_1BA318[1] + byte_1BA319[1] + byte_1BA31A[1]
// + byte_1BA31B[61], takze `byte_1BA318[4*j]` pro j>0 cetlo mimo objekt.
// ZMERENO: sub_133237 pak volalo sub_1338C9 s a1 = 139 misto <= 63, coz
// v sub_1338C9 dalo `dword_1BB914[129]` = daleko za 65prvkovou tabulkou kosu.
// VLNA 89: 4096, ne 4092 - indexuje se `byte_1BA358[256 * j + i]` pro j < 16
// a i < 256, tedy az na prvek 4095. Blok konci az na 0x1BB358 (paleta).
// VLNA 15: puvodne "char byte_1BB358[]" (nedokoncene pole). sub_1205E6
// do nej kopiruje 1024 bajtu (paletova/barevna tabulka 0x1BB358..0x1BB758).
// IDA cely 1024B usek rozsekala na desitky jednotlivych symbolu (byte_1BB359,
// 35B[318], 499, 49B[253]...), takze kopie by prepisovala sousedni globaly
// -> pad. Standalone 1024B buffer prepis zastavi. DECOMP_TODO: jednotlive
// byte_1BB35x/49x/59x/61x/65x symboly do nej zatim NEaliasuji (paletova data
// se pres ne necti) - plny overlay az bude potreba barevna presnost.
// VLNA 15 DECOMP_TODO vyreseno: byte_1BB358 je pole 256 zaznamu po 4 bajtech
// [flag, R, G, B] (viz sub_132A11/sub_132AF8 - "active flag" + 6bit VGA RGB).
// byte_1BB359/35A/35B jsou presne tyto R/G/B kanaly na bajtovem offsetu
// +1/+2/+3 od byte_1BB358 (IDA je kvuli stride-4 pristupu rozsekala na
// samostatne symboly - viz komentar vyse). Bez tohoto aliasovani zapisovaly
// VSECHNY zapisy barev (sub_132A11 pro SMK/fade paletu, i desitky dalsich
// mist v orion_part_10/18/19/20/21) do trech osamocenych, nikdy ctenych
// bufferu - do skutecneho, na obrazovku nahravaneho bufferu (byte_1BB358) se
// tak dostal jen flag bajt, nikdy skutecna barva.
char* byte_1BB359 = byte_1BB358 + 1;
char* byte_1BB35A = byte_1BB358 + 2;
char* byte_1BB35B = byte_1BB358 + 3;
// VLNA 89: 0x1BB758..0x1BB87F je JEDEN souvisly blok (dalsi symbol je az
// dword_1BB880), tedy 296 B - setridena tabulka indexu palety, kterou plni
// sub_13372A. IDA z nej udelala byte_1BB758[1] + byte_1BB759[254] +
// unk_1BB857, takze `byte_1BB758[i]` pro i>0 a `byte_1BB759[j] = byte_1BB758[j]`
// sahaly mimo objekt a tabulka vysla jako smeti. unk_1BB857 lezi na +255 a je
// to KONCOVA zaslepka (dword_1BBA14 = &unk_1BB857 = polozka 64 tabulky kosu).
int (*dword_1BB888)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // weak
int (*dword_1BB88C)(void); // weak
int (*dword_1BB894)(void); // weak
int (*dword_1BB898)(_DWORD); // weak
int (*dword_1BB89C)(void); // weak
int (*dword_1BB8A0)(_DWORD); // weak
int (*dword_1BB8A4)(_DWORD); // weak
int (*dword_1BB8A8)(_DWORD); // weak
// REGS union buffer 0x1BB8E0..0x1BB8FC (28 bytes) - wave 19. int386 (INT 33h
// mouse, INT 10h) writes back the full register set (24 bytes) to &dword_1BB8E0.
// IDA split the union into separate 4-byte globals (eax/ebx/ecx/edx at +0/+4/+8/
// +C, edi at +0x14) which the port packs consecutively, so the 24-byte write
// overflowed neighbouring globals (e.g. zeroed dword_1BB8FC / dword_1BB8C0).
// One contiguous buffer keeps the exact union layout; old names map via macros.
// Overlay: dword_1BB910 + dword_1BB914 are one contiguous array in the
// original. See orion_common.h for why they must not be split.
// dword_1BB910/dword_1BB914 are now macros onto this backing array.
// VLNA 89: rozsireno z [65] na [66] - `dword_1BB914[64]` (= 0x1BBA14) je
// dword_1BBA14, koncova zaslepka tabulky kosu. sub_1338C9 ji cte pokazde,
// kdyz mu horni mez vyjde 64 (`if (v8 >= 53) v8 = 64;`), takze jako
// samostatny global se cetlo mimo pole.
// VLNA 12: blok 0x1BBA6A..0x1BC26C = cache LBX hlavicky (2048 B nacitane
// pres "fread(&unk_1BBA6C, 2048, ...)" v sub_127233 a spol.) + 2 bajty
// pred ni (byte_1BBA6B flag; "(int)unk_1BBA6A >> 16" cte pocet zaznamu =
// word na 0x1BBA6C). Symboly uvnitr: word_1BBA6E (+4 od zacatku bloku) =
// LBX magic 0xFEAD, dword_1BBA74/78 (+0x0A/+0x0E) = tabulka offsetu
// zaznamu. Jako oddelene promenne fread nikdy nenaplnil word_1BBA6E ->
// "fonts.lbx [entry 0] is not an LBX file". Prekryvova makra v
// orion_common.h drzi puvodni layout.
// vlna 12: drive _UNKNOWN (1 bajt) - buffer jmena aktualne otevreneho LBX
// (strcpy nazvu "fonts.lbx" apod. v sub_127233); 16 B = vzdalenost k
// dalsimu symbolu dword_1BC280.
// Puvodni INT 9 (klavesnice) vektor ulozeny pred instalaci vlastniho
// handleru - 6 bajtu na adrese 1BC2DC (dword offset + word segment),
// IDA je mylne typovala jako ukazatel na funkci. Viz InstallKeyboardIsr_12C420/RestoreKeyboardIsr_12C493
// v orion_part_20.c a struct DosFarPointer v decomp_compat.h/port_dos.h.
struct DosFarPointer savedKeyboardVector_1BC2DC; // weak
/* vlna 130: 0x1BD352..0x1BDF52 je JEDNA tabulka 256 zaznamu po 12 bajtech.
   IDA z ni udelala osm prekryvajicich se pohledu, z toho sedm jednoprvkovych;
   `dword_1BD352[3*a2]` tak cetlo mimo pole a `sub_139D7E` pak psala
   `byte_1BD154[i] = 1` s nesmyslnym `i` - odtud jednicky v palete, prepsane
   AIL handly a pady na LEADERS (nalezeno hardwarovym watchpointem).
   Rozlozeni zaznamu je videt primo z indexace v kodu:
     dword_1BD352[3*i] -> +0 (dword),  word_1BD356[6*i] -> +4,
     word_1BD358[6*i]  -> +6,          byte_1BD35A..F[12*i] -> +8 az +13.
   Pohledy jsou ted makra v orion_common.h. */
/* vlna 130: 0x1BDF52..0x1BE354 = 513 slov; word_1BDF52/54/56 se indexuji
   TYMZ `i`, takze jsou to tri sousedni prvky jedne tabulky. */
/* vlna 133: 0x1BE354..0x1BEB54 je JEDEN blok 512 zaznamu po 4 bajtech
   [priznak, R, G, B] - zdroj podpalety, kterou sub_13AC01 kopiruje do
   herni palety (`sub_13AC01(192, 64)` = 64 barev na indexy 192-255).
   IDA z nej udelala unk_1BE354 + dve JEDNOPRVKOVA pole + byte_1BE357[2045],
   takze `byte_1BE355[4*i]` a `byte_1BE356[4*i]` cetly pro i>0 mimo pole.
   Dusledek: paleta 192-255 byla v portu jina nez v originale (zmereno
   DUMPMEM proti dosboxu) a planety v pohledu na soustavu se kreslily tmave. */
int (*dword_1BF388)(_DWORD, _DWORD, _DWORD, _DWORD); // weak
int (*dword_1C0990)(_DWORD, _DWORD, _DWORD, _DWORD); // weak
int (*dword_1C3C30)(_DWORD); // weak
int (*dword_1C3C34)(_DWORD); // weak
int (*dword_1C3C38)(_DWORD); // weak
int (*dword_1C3C3C)(_DWORD); // weak
int (*dword_1C3C68)(_DWORD, _DWORD, _DWORD); // weak
int (*dword_1C9830)(_DWORD); // weak
/* vlna 112: deklarovane v orion_common.h, ale nikdy nedefinovane - v kodu se
   objevuji jen v komentarich (zasobnik ovladace mysi, sub_19 kolem r. 4383).
   Definice doplnena, aby prosla watch tabulka srovnavaciho harnessu. */

// PORT (vlna 26 pokr. 15): mixerove rutiny maji registrovou konvenci a vraci
// posunuty zdrojovy (ESI) i cilovy (EDI) ukazatel; IDA je otypovala jako cdecl
// vracejici jen EAX, takze se posun ztracel. ZAMERNE az tady, aby se nerozbila
// souvislost bloku 0x18AD28..0x18AD48 (`sub_1622BF` bere ten rozsah vcelku).
_BYTE *g_mixSrcAfter = 0;
_DWORD *g_mixDstAfter = 0;


