#include "orion_common.h"

/* Adresni rozsah: 0x10057 - 0x23563  (200 funkci) */

//----- (00010057) --------------------------------------------------------
void __usercall __noreturn GameMain_10057(int a1, intptr_t a2, int16_t *a3)
{
  // DECOMP_TODO: docasny bezpecny placeholder (misto puvodni neinicializovane
  // promenne - stejna trida chyby jako u ParseCommandLine_107E6/vlna 02).
  // Presny puvodni vyznam (pravdepodobne navratova hodnota nejakeho volani,
  // viz PROGRESS.md "dalsi krok") je porad nedoreseny - 0 jen zarucuje
  // deterministicke chovani mist toho nedefinovaneho.
  int v3 = 0; // eax
  int v4; // eax
  _BYTE v5[32]; // [esp+6Ch] [ebp+3Eh] BYREF
  char v6[16]; // [esp+9Ch] [ebp+6Eh] BYREF

  PortDebug_Checkpoint("GameMain_10057.enter", a1);
  byte_199F19 = -1;
  byte_199F36 = 1;
  word_1999EC = 1;
  word_1999EA = 20;
  word_1999EE = 20;
  byte_19A006 = -1;
  // a1/a2 jsou tady porad nedotcene argc/argv teto funkce (GameMain_10057) -
  // presne ty hodnoty, ktere ParseCommandLine_107E6 drive cetla z
  // neinicializovanych promennych. Viz DECOMP_TODO u ParseCommandLine_107E6.
  ParseCommandLine_107E6(a1, (char**)a2);
  PortDebug_Checkpoint("GameMain.after_ParseCmdLine", 0);
  sub_FE8BE(v3, a1, a2, a3);
  PortDebug_Checkpoint("GameMain.after_FE8BE", 0);
  MarkMemPoolReady_110B34();
  PortDebug_Checkpoint("GameMain.after_MarkPoolReady", 0);
  // DECOMP_TODO (vyreseno ve vlne 06): puvodni vyraz "(int)&loc_63FFB + 5"
  // vypadal jako smysluplna adresa, ale podle asm dumpu je "loc_63FFB"
  // navesti UPROSTRED FUNKCE sub_63FF0 (presne 5 bajtu za jejim zacatkem,
  // hned za prologem "push esi/edi; enter 48h,0; push eax/edx/ebx; mov
  // ch,cl") - a "+5" z toho navesti vede jeste o 5 bajtu dal, doprostred
  // OPERANDU nasledujici instrukce "mov edx, dword_192FD8" (na posledni
  // bajt jeji 4bajtove adresy). To neni zadny smysluplny kod/data cil.
  // Ve skutecnosti jde o typicky IDA false-positive: puvodni C kod tu mel
  // proste 32bit celociselnou konstantu 0x64000 (= 0x63FFB + 5 = 409600 =
  // 400 KB), ale protoze tahle hodnota nahodou padne do rozsahu adres
  // nahraneho programu, IDA ji automaticky prevedla na "offset nejblizsi
  // znamy symbol + delta" misto aby ji nechala jako prosty cislo. Overeno
  // hexadecimalnim souctem (0x63FFB + 5 = 0x64000) - PoolAlloc_110B89
  // bere prvni parametr jako POCET BAJTU k alokaci (viz jeho definice),
  // takze 0x64000 (400 KB) je smysluplna velikost jednorazove alokovaneho
  // pool bufferu, ne adresa k dereferenci.
  dword_19916C = (int)PoolAlloc_110B89(0x64000, (int)v5);
  PortDebug_Checkpoint("GameMain.pool64000.done", dword_19916C != 0);
  v4 = FindMoxSetPath_1114D7(aMoxSet, v5);
  if ( v4 )
  {
    LoadSettingsFile_11C39(v4);
    if ( word_199CBE != 130 )
      LoadOrResetSettings_12227();
  }
  else
  {
    InitDefaultSettings_127E1();
  }
  LoadLanguageSetting_10C2F();
  GetFontsLbxName_7AA33(v6);
  SelectResourceModule_111959(dword_19916C);
  PortDebug_Checkpoint("GameMain.beforeRunGame", 0);
  RunGameAndExit_113D47(4, v6);
}
// 100A0: variable 'v3' is possibly undefined
// 12479: using guessed type _DWORD __stdcall sub_12479(_DWORD, _DWORD);
// 586D3: using guessed type int __fastcall nullsub_3(_DWORD);
// 18FF78: using guessed type int16_t word_18FF78;
// 19327C: using guessed type int dword_19327C;
// 197F98: using guessed type int dword_197F98;
// 19916C: using guessed type int dword_19916C;
// 19999C: using guessed type int16_t word_19999C;
// 1999EA: using guessed type int16_t word_1999EA;
// 1999EC: using guessed type int16_t word_1999EC;
// 1999EE: using guessed type int16_t word_1999EE;
// 199A08: using guessed type int16_t word_199A08;
// 199CAE: using guessed type char byte_199CAE;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199CBE: using guessed type int16_t word_199CBE;
// 199F05: using guessed type char byte_199F05;
// 199F19: using guessed type char byte_199F19;
// 199F34: using guessed type char byte_199F34;
// 199F36: using guessed type char byte_199F36;
// 199F3A: using guessed type char byte_199F3A;
// 19A004: using guessed type char byte_19A004;
// 19A005: using guessed type char byte_19A005;
// 19A006: using guessed type char byte_19A006;
// 19A007: using guessed type char byte_19A007;


//----- (0001049B) --------------------------------------------------------
void __usercall sub_1049B(int a1, int a2, int a3, int a4, int a5, char *a6)
{
  int v6; // esi
  int16_t v7; // kr02_2

  v6 = 0;
  while ( !v6 )
  {
    word_199A0E = 0;
    v7 = HIWORD(a1);
    a1 = (uint16_t)word_199A08;
    switch ( word_199A08 )
    {
      case 0:
        sub_86188(a6);
        byte_199F19 = 0;
        break;
      case 1:
        sub_C058A(a4, (int16_t *)a6);
        byte_199F19 = 1;
        break;
      case 3:
        sub_6B9B2(a3, a4, (int16_t *)a6);
        byte_199F19 = 3;
        break;
      case 4:
        sub_73980((uint16_t)word_199A08, (int16_t *)a6, 0);
        byte_199F19 = 4;
        break;
      case 6:
        sub_10ACBA((int16_t *)a6);
        byte_199F19 = 6;
        break;
      case 7:
        v6 = 1;
        break;
      case 8:
        sub_8012F((uint16_t)word_199A08, a2);
        byte_199F19 = 8;
        break;
      case 9:
        sub_106CAC((int16_t)a6);
        byte_199F19 = 9;
        break;
      case 10:
        sub_816F2(a2, a3, a4, (int16_t *)a6);
        byte_199F19 = 10;
        break;
      case 12:
        a1 = sub_13870((uint16_t)word_199A08, a2, a3, a4, a5, (int16_t *)a6, 0);
        byte_199F19 = 12;
        break;
      case 13:
        if ( byte_199F3A )
        {
          word_199A10 = 15;
          sub_CD435((int16_t *)a6);
        }
        else
        {
          sub_CD435((int16_t *)a6);
          if ( (_WORD)a1 )
          {
            a3 = (uint8_t)byte_199CB1;
            a4 = (uint8_t)byte_199CB3;
            a2 = (uint8_t)byte_199CB2;
            a1 = sub_169410((uint8_t)byte_199CB4, (uint8_t)byte_199CB5);
          }
          else
          {
            word_199A08 = 10;
          }
        }
        byte_199F19 = 13;
        break;
      case 14:
        sub_9F286(-1, a2, a4, a3);
        word_199A08 = 10;
        byte_199F19 = 14;
        break;
      case 15:
        sub_F4D99((int16_t *)a6);
        byte_199F19 = 15;
        break;
      case 16:
        sub_628E2((int16_t *)a6);
        byte_199F19 = 16;
        break;
      case 17:
        sub_F3AE4((int16_t *)a6);
        byte_199F19 = 17;
        break;
      case 18:
        a1 = nullsub_4((uint16_t)word_199A08);
        byte_199F19 = 18;
        break;
      case 20:
        sub_C4562(a3, (int16_t *)a6, 0);
        byte_199F19 = 20;
        break;
      case 21:
        sub_FB7E5((int16_t *)a6);
        if ( (_BYTE)a1 )
          word_199A08 = 39;
        byte_199F19 = 21;
        break;
      case 22:
        LOBYTE(a1) = sub_FAEDB((int16_t *)a6);
        goto LABEL_31;
      case 25:
        sub_B4041(a4, (int16_t *)a6);
        byte_199F19 = 25;
        break;
      case 28:
        sub_8AB6D();
        byte_199F19 = 28;
        word_199A08 = word_199A10;
        break;
      case 29:
        sub_94C1D((uint16_t)word_199A08, a4, (int16_t *)a6, 0);
        byte_199F19 = 29;
        break;
      case 30:
        sub_8B2DE();
        byte_199F19 = 30;
        break;
      case 31:
        a1 = sub_8A97A((int16_t *)a6);
        byte_199F19 = 31;
        break;
      case 32:
        sub_9D252();
        byte_199F19 = 32;
        break;
      case 33:
        a1 = sub_B9802(a2, a3, (int16_t *)a6);
        byte_199F19 = 33;
        break;
      case 34:
        a1 = sub_8B7A5((int16_t *)a6);
        byte_199F19 = 34;
        break;
      case 35:
        sub_8B519();
        byte_199F19 = 35;
        break;
      case 36:
        sub_10DBCE(a4, (int16_t *)a6);
        byte_199F19 = 36;
        break;
      case 37:
        sub_FC470((uint16_t)word_199A08, a2, a4, a3);
        break;
      case 39:
        sub_8B956((int16_t *)a6);
        byte_199F19 = 39;
        break;
      case 40:
        sub_10FB02();
        byte_199F19 = 40;
        break;
      case 41:
        sub_FB27B((int16_t *)a6);
LABEL_31:
        if ( (_BYTE)a1 )
          word_199A08 = 39;
        byte_199F19 = 22;
        break;
      case 43:
        sub_8BAB9((int16_t *)a6);
        byte_199F19 = 43;
        break;
      default:
        HIWORD(a1) = v7;
        break;
    }
  }
}
// 105AF: variable 'a1' is possibly undefined
// 79C1C: using guessed type int __fastcall nullsub_4(_DWORD);
// 199A08: using guessed type int16_t word_199A08;
// 199A0E: using guessed type int16_t word_199A0E;
// 199A10: using guessed type int16_t word_199A10;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199F19: using guessed type char byte_199F19;
// 199F3A: using guessed type char byte_199F3A;


//----- (0001077D) --------------------------------------------------------
int __usercall sub_1077D(int a1, int a2, int a3, int16_t *a4)
{
  sub_FE8BE(a1, a2, a3, a4);
  return sub_124ECB();
}


//----- (000107AF) --------------------------------------------------------
_DWORD *__fastcall sub_107AF(_DWORD *result)
{
  *result = dword_1B0840;
  return result;
}
// 1B0840: using guessed type int dword_1B0840;


//----- (000107BA) --------------------------------------------------------
int __fastcall sub_107BA(int *a1)
{
  int result; // eax

  result = *a1;
  dword_1B0840 = result;
  return result;
}
// 1B0840: using guessed type int dword_1B0840;


//----- (000107C2) --------------------------------------------------------
int (**__fastcall sub_107C2(int (**result)(void)))(void)
{
  if ( *result )
    return (int (**)(void))(*result)();
  return result;
}


//----- (000107CA) --------------------------------------------------------
int sub_107CA()
{
  IsMemPoolReady_110B5C();
  if ( dword_19327C )
    return sub_124820(dword_19327C);
  else
    return sub_124878();
}
// 19327C: using guessed type int dword_19327C;


//----- (000107E6) --------------------------------------------------------
// DECOMP_TODO (opraveno ve vlne 02): puvodni dekompilace mela signaturu
// "void sub_107E6()" bez parametru, ale telo funkce pouzivalo dve promenne
// (puvodne v13/v14), ktere nikde nebyly nastaveny - Hex-Rays k nim hlasil
// "variable is possibly undefined" a ve Visual Studiu to pri behu spadne na
// "Run-Time Check Failure #3". Skutecny duvod: jde o klasicky Hex-Rays
// artefakt, kdy volajici (GameMain_10057) preda argc/argv dale beze zmeny
// v temze registru, ve kterem je sam prijal - zadna instrukce MOV tedy
// neexistuje a dekompilator to nedokazal rozpoznat jako predavany parametr.
// Assembly hodnoty tam ale REALNE jsou (argc/argv z main()), takze
// zpristupneni jako explicitni parametry NEMENI chovani, jen opravuje
// chybny popis funkce a odstranuje UB (cteni neinicializovane pameti).
//
// DECOMP_TODO (vyreseno ve vlne 05): puvodni kod tu jeste pocital zvlastni
// ukazatel "cheatFlagsBuffer_v0 = &stackAnchor_v16 - 67" a predaval ho (jako
// "(int)cheatFlagsBuffer_v0") do vsech volani MarkCheatPatternFlag_F4FD5.
// Tenhle vyraz zavisel na PRESNEM stack frame puvodniho Watcom prekladace -
// po prekompilovani modernim kompilatorem uz vypocitava nesmyslnou adresu
// (jiny layout lokalnich promennych), coz zpusobovalo Access Violation pri
// prvnim volani MarkCheatPatternFlag_F4FD5 (viz obrazek v zadani). Presny
// puvodni bytovy posun se nepodarilo overit, ale funkcne je jednoznacne, ze
// MarkCheatPatternFlag_F4FD5 ma - stejne jako vsech pet sousednich
// "strstr(currentArg_v17, ...)" kontrol o par radku vyse a nize ve stejne
// smycce - hledat vzor v PRAVE ZPRACOVAVANEM ARGUMENTU prikazove radky.
// Proto se ted primo predava "currentArg_v17".
void ParseCommandLine_107E6(int argCount_a1, char** argValues_a2)
{
  int argIndex_v1;              // ecx - index prochazeneho argv[]
  int saveSlotNumber_v2;        // eax - cislo save slotu ze "SAVESET=N"
  int64_t sprintfResult_v6;     // rax - pouzit jen kvuli SHIDWORD() nize (viz TODO)
  int64_t logMessagePacked_v8;  // rax - pouzit jen kvuli HIDWORD/LODWORD trik (viz TODO)
  int picksCount_v9;            // eax - z "PICKS=N", povoleny rozsah 10..14
  int planetsCount_v10;         // eax - z "PLANETS=N", povoleny rozsah 2..5
  _BYTE* gameFlagsTable_v11;    // [esp-Ch] [ebp-42h] - spolecna tabulka nastaveni (viz GetGameFlagsTable_F4B81)
  char messageBuffer_v15[46];   // [esp+8h] [ebp-2Eh] BYREF
  char currentArg_v17[80];      // [esp+58h] [ebp+22h] BYREF - aktualne zpracovavany argv[i]
  char nosavesPrefix_v18[12];   // [esp+A8h] [ebp+72h] BYREF
  char statsPrefix_v19[8];      // [esp+B4h] [ebp+7Eh] BYREF

  byte_19A007 = 0;
  byte_19A004 = 0;
  dword_19327C = 0;
  byte_199F2A = 0;
  strcpy(nosavesPrefix_v18, "/nosaves=");
  word_1999E4 = 0;
  word_1999E0 = 0;
  argIndex_v1 = 0;
  strcpy(statsPrefix_v19, "/stats=");
  while ( 1 )
  {
    // DECOMP_TODO (vyreseno ve vlne 05): tady byvalo "JUMPOUT(0x103DF);",
    // ktere je v hexrays_compat.h definovane jako NO-OP (viz komentar tam) -
    // takze kdyz doslo vsech argumentu bez nalezeni "/saveset", kod bez
    // navratu SPADL DAL na "strcpy(currentArg_v17, argValues_a2[argIndex_v1])"
    // s argIndex_v1 == argCount_a1, tedy cteni argv[argc], ktere je podle
    // standardu vzdy NULL - strcpy(dest, NULL) je jisty pad. Puvodni
    // disassembly komentar ("control flows out of bounds to 103DF") + fakt,
    // ze cilova adresa lezi MIMO rozpoznane telo funkce, odpovida tomu, ze
    // asembler tu jen skakal primo na epilog/ret teto (void) funkce -
    // funkcne tedy jde o predcasny navrat, nahrazeno primym "return;".
    if ( (int16_t)argIndex_v1 >= argCount_a1 )
      return;
    strcpy(currentArg_v17, argValues_a2[argIndex_v1]);
    if ( strstr(currentArg_v17, aSaveset) )
      break;
    if ( !strstr(currentArg_v17, aMaps) )
    {
      if ( strstr(currentArg_v17, aSeed) )
      {
        dword_19327C = sub_10A0E(aSeed, currentArg_v17);
      }
      else if ( strstr(currentArg_v17, aNolog) )
      {
        byte_1AB093 = 1;
      }
      else if ( !strstr(currentArg_v17, aNet)
             && !strstr(currentArg_v17, nosavesPrefix_v18)
             && !strstr(currentArg_v17, statsPrefix_v19)
             && !strstr(currentArg_v17, aQuickstart) )
      {
        // DECOMP_TODO: MarkCheatPatternFlag_F4FD5(vzor, text) hleda "vzor" v
        // "text" a pokud ho najde, nastavi bajt hned za koncem retezce "vzor"
        // v pameti na -1 (0xFF) - jde o dobovy trik, kdy je priznakovy bajt
        // ulozeny bezprostredne za textovym literalem v pameti (viz DECOMP_TODO
        // primo u MarkCheatPatternFlag_F4FD5 - krehke pod modernim linkerem).
        // Nazvy vzoru (NOWH, NOBH, NOORION, GOODSTART, RICHSTART, NOSPLINT...)
        // odpovidaji cheat/debug prepinacum Master of Orion - presny vyznam
        // kazdeho priznaku (kdo ho cte) se doresi az v dalsi vlne.
        MarkCheatPatternFlag_F4FD5(aNowh, currentArg_v17);
        MarkCheatPatternFlag_F4FD5(aNobh, currentArg_v17);
        MarkCheatPatternFlag_F4FD5(aNoorion, currentArg_v17);
        MarkCheatPatternFlag_F4FD5((char*)byte_178440, currentArg_v17);
        MarkCheatPatternFlag_F4FD5(aGoodstart, currentArg_v17);
        MarkCheatPatternFlag_F4FD5((char*)byte_178463, currentArg_v17);
        MarkCheatPatternFlag_F4FD5(aRichstart, currentArg_v17);
        MarkCheatPatternFlag_F4FD5(aNosplint, currentArg_v17);
        // GetGameFlagsTable_F4B81() je cisty getter (vraci porad stejnou globalni
        // adresu &unk_1784DD) - puvodni kod ho volal 2x zbytecne (v11 i v12 mely
        // vzdy stejnou hodnotu), takze staci jedno volani/jedna promenna.
        gameFlagsTable_v11 = (_BYTE*)GetGameFlagsTable_F4B81();
        MarkCheatPatternFlag_F4FD5((char*)(gameFlagsTable_v11 + 712), currentArg_v17);
        MarkCheatPatternFlag_F4FD5((char*)(gameFlagsTable_v11 + 721), currentArg_v17);
        MarkCheatPatternFlag_F4FD5((char*)(gameFlagsTable_v11 + 732), currentArg_v17);
        MarkCheatPatternFlag_F4FD5((char*)(gameFlagsTable_v11 + 610), currentArg_v17);
        MarkCheatPatternFlag_F4FD5((char*)(gameFlagsTable_v11 + 621), currentArg_v17);
        if ( MarkCheatPatternFlag_F4FD5(aPicks, currentArg_v17) )
        {
          picksCount_v9 = sub_10A0E(aPicks, currentArg_v17);
          if ( picksCount_v9 < 10 || picksCount_v9 >= 15 )
            aPicks[0] = 10;
          else
            aPicks[0] = picksCount_v9;
        }
        if ( MarkCheatPatternFlag_F4FD5(aPlanets, currentArg_v17) )
        {
          planetsCount_v10 = sub_10A0E(aPlanets, currentArg_v17);
          if ( planetsCount_v10 < 2 || planetsCount_v10 >= 6 )
            aPlanets[0] = 2;
          else
            aPlanets[0] = planetsCount_v10;
        }
        if ( strstr(currentArg_v17, aSkipintro) )
        {
          byte_19A004 = 1;
        }
        else if ( strstr(currentArg_v17, aMonsters) )
        {
          byte_19A006 = sub_10A0E(aMonsters, currentArg_v17);
        }
        else
        {
          // DECOMP_TODO: puvodni kod predem uklada HIDWORD(logMessagePacked_v8)
          // = aDate jeste PRED samotnym testem strstr - klasicky pripad, kdy
          // Hex-Rays predstira 64bit navratovou hodnotu funkce (tady sprintf),
          // aby simuloval "par registru" (eax:edx), pricemz LODWORD/HIDWORD
          // pak drzi dva ruzne 32bit ukazatele (zpravu a "kod"/kontext) pro
          // nasledne volani sub_126487(zprava, kod). Zachovano 1:1.
          HIDWORD(logMessagePacked_v8) = (int)aDate;
          if ( strstr(currentArg_v17, aDate) )
          {
            // DECOMP_TODO (vyreseno ve vlne 05): puvodni "goto LABEL_26;"
            // skakal primo na zaverecne volani sub_126487 na konci funkce
            // (viz tail nize) a presoskocil tak celou logiku pro nacitani
            // save souboru. Protoze je LABEL_26 pouzity jen na tomto jednom
            // miste a je to posledni prikaz funkce, nahrazeno primym
            // zavolanim + return - identicke chovani, bez goto/navesti.
            LODWORD(logMessagePacked_v8) = (int)aMay222006_1;
            sub_126487((char *)logMessagePacked_v8, SHIDWORD(logMessagePacked_v8));
            return;
          }
        }
      }
    }
    ++argIndex_v1;
  }
  saveSlotNumber_v2 = sub_10A0E(aSaveset_0, currentArg_v17);
  sprintf(messageBuffer_v15, "SAVE%d.GAM", (int16_t)saveSlotNumber_v2);
  if ( !FindMoxSetPath_1114D7(messageBuffer_v15, messageBuffer_v15) )
  {
    sprintfResult_v6 = sprintf(messageBuffer_v15, "Unable to open SAVE%d.GAM", (int16_t)saveSlotNumber_v2);
    sub_126487(messageBuffer_v15, SHIDWORD(sprintfResult_v6));
  }
  sub_10E2F((int16_t)(saveSlotNumber_v2 - 1), (int)messageBuffer_v15, saveSlotNumber_v2 - 1, argIndex_v1);
  if ( (uint8_t)sub_11F11((int16_t)saveSlotNumber_v2, (int)aSetTmp) )
    logMessagePacked_v8 = sprintf(messageBuffer_v15, "settings from SAVE%d.GAM saved to SET.TMP", (int16_t)saveSlotNumber_v2);
  else
    logMessagePacked_v8 = sprintf(messageBuffer_v15, "Unable to convert settings saved in SAVE%d.GAM", (int16_t)saveSlotNumber_v2);
  LODWORD(logMessagePacked_v8) = (int)messageBuffer_v15;
  sub_126487((char *)logMessagePacked_v8, SHIDWORD(logMessagePacked_v8));
}
// 178440: using guessed type _BYTE[10];
// 178463: using guessed type _BYTE[11];
// 19327C: using guessed type int dword_19327C;
// 1999E0: using guessed type int16_t word_1999E0;
// 1999E4: using guessed type int16_t word_1999E4;
// 199F2A: using guessed type char byte_199F2A;
// 19A004: using guessed type char byte_19A004;
// 19A006: using guessed type char byte_19A006;
// 19A007: using guessed type char byte_19A007;
// 1AB093: using guessed type char byte_1AB093;


//----- (00010A0E) --------------------------------------------------------
int __fastcall sub_10A0E(char *a1, char *a2)
{
  int16_t v3; // dx
  int16_t i; // si
  int v5; // edi
  char v6; // al
  _BYTE v8[200]; // [esp+0h] [ebp-C8h] BYREF

  v3 = 0;
  for ( i = strlen(a1); i < strlen(a2) && v3 <= 199; ++i )
  {
    v5 = v3++;
    v6 = a2[i];
    v8[v5] = v6;
  }
  v8[v3] = 0;
  return atoi(v8);
}
// 126622: using guessed type int __fastcall atoi(_DWORD);


//----- (00010A72) --------------------------------------------------------
int sub_10A72()
{
  int64_t v0; // rax
  int v1; // ecx
  unsigned int v2; // kr04_4
  int16_t v3; // cx
  int v4; // eax
  char *v5; // edi
  _BYTE v7[100]; // [esp+0h] [ebp-4Ah] BYREF
  _BYTE v8[99]; // [esp+64h] [ebp+1Ah] BYREF
  char v9; // [esp+C7h] [ebp+7Dh] BYREF
  char v10[80]; // [esp+C8h] [ebp+7Eh] BYREF
  _BYTE v11[80]; // [esp+118h] [ebp+CEh] BYREF

  HIDWORD(v0) = v10;
  if ( !FindMoxSetPath_1114D7(aOrioncdIni, v10) )
  {
    if ( byte_199CAE )
    {
      switch ( byte_199CAE )
      {
        case 1:
          v0 = sprintf(v8, aOrioncdIniNich);
          break;
        case 2:
          v0 = sprintf(v8, aOrioncdIniIntr);
          break;
        case 3:
          v0 = sprintf(v8, aOrioncdIniNoSe);
          break;
        case 4:
          v0 = sprintf(v8, aNonTrovoIlFile);
          break;
      }
    }
    else
    {
      v0 = sprintf(v8, aOrioncdIniNotF);
    }
    LODWORD(v0) = v8;
LABEL_34:
    sub_126487((char *)v0, SHIDWORD(v0));
  }
      // DECOMP_TODO (castecne vyreseno ve vlne 06): chybel mod parametr - v okoli se nenaslo jednoznacne fread/fwrite, takze "aRb" je bezpecny odhad (needela zadnou zapisovou vedlejsi ucinek jako by mohl "wb"), potrebuje overit.
    v1 = fopen(aOrioncdIni, aRb);
  fgets(v10, 60, v1, v1);
  fclose(v1);
  v10[60] = 0;
  v2 = strlen(v10) + 1;
  v3 = v2 - 1;
  if ( v10[(int16_t)(v2 - 1) - 1] == 13 )
  {
    v3 = v2 - 2;
    v10[(int16_t)(v2 - 1) - 1] = 0;
  }
  v4 = v3;
  if ( v10[v3 - 1] == 10 )
  {
    --v3;
    v10[v4 - 1] = 0;
  }
  sub_127593((int)v10);
  if ( v10[v3 - 1] != 92 )
  {
    v5 = &v9;
    do
      ++v5;
    while ( *v5 );
    strcpy(v5, asc_17837F);
  }
  sprintf(v11, "%sdiplomat.lbx", v10);
  LODWORD(v0) = FindMoxSetPath_1114D7(aDiplomatLbx, v10);
  if ( !(_DWORD)v0 )
  {
    v0 = __PAIR64__(v10, FindMoxSetPath_1114D7(v11, v10));
    if ( !(_DWORD)v0 )
    {
      if ( byte_199CAE )
      {
        switch ( byte_199CAE )
        {
          case 1:
            v0 = sprintf(v7, aNichtAlleSpiel);
            break;
          case 2:
            v0 = sprintf(v7, aVeuillezIns);
            break;
          case 3:
            v0 = sprintf(v7, aNoSePuedeLocal);
            break;
          case 4:
            v0 = sprintf(v7, aNonRiescoATrov);
            break;
        }
      }
      else
      {
        v0 = sprintf(v7, aCannotLocateAl);
      }
      LODWORD(v0) = v7;
      goto LABEL_34;
    }
  }
  return v0;
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 126911: using guessed type int __fastcall fgets(_DWORD, _DWORD, _DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 199CAE: using guessed type char byte_199CAE;


//----- (00010C2F) --------------------------------------------------------
int LoadLanguageSetting_10C2F()
{
  int result; // eax
  int v1; // ecx
  char v2; // cl
  char v3[80]; // [esp+0h] [ebp-A0h] BYREF
  _BYTE v4[80]; // [esp+50h] [ebp-50h] BYREF

  result = FindMoxSetPath_1114D7(aLanguageIni, v4);
  if ( result )
  {
        // DECOMP_TODO (castecne vyreseno ve vlne 06): chybel mod parametr - v okoli se nenaslo jednoznacne fread/fwrite, takze "aRb" je bezpecny odhad (needela zadnou zapisovou vedlejsi ucinek jako by mohl "wb"), potrebuje overit.
    v1 = fopen(aLanguageIni, aRb);
    fgets(v3, 60, v1, v1);
    fclose(v1);
    result = sub_12760B(v3);
    v2 = result;
    if ( (uint16_t)result >= 6u )
      v2 = 0;
    byte_199CAE = v2;
  }
  else
  {
    byte_199CAE = 0;
  }
  byte_199CAE = 0;
  return result;
}
// 126911: using guessed type int __fastcall fgets(_DWORD, _DWORD, _DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 199CAE: using guessed type char byte_199CAE;


//----- (00010CB5) --------------------------------------------------------
_BYTE *__fastcall sub_10CB5(int a1, int a2)
{
  signed int v2; // edx
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _BYTE *result; // eax

  // DECOMP_TODO (vyreseno ve vlne 10): puvodni vyrazy "(int)&unk_1B5030",
  // "(int)&loc_16085 + 5", "(int)&loc_3E7FB + 5" a "(int)&loc_40F0D + 3"
  // jsou stejny IDA false-positive jako 0x64000 ve vlne 06: 32bit KONSTANTY
  // velikosti alokaci, ktere nahodou padly do rozsahu adres programu, takze
  // je IDA prevedla na "offset symbol + delta". Hodnoty prevedene zpet jsou
  // presna kulata cisla (1790000 / 90250 / 256000 / 266000) a 90250 =
  // 361*250 presne odpovida smycce cteni 250 zaznamu po 361 bajtech v
  // sub_10E2F nize. OVERENO ZA BEHU originalu v upravenem DOSBox-X
  // (DUMPREGS testovaci body, viz PROGRESS.md vlna 10): hra pri startu
  // skutecne vola PoolAlloc_110B89 postupne s EAX = 1790000, 30000, 1000,
  // 6120, 30024, 90250 a 256000 presne na techto volacich mistech
  // (runtime EIP = IDA adresa + 0x224000).
  PortDebug_Checkpoint("sub_10CB5.enter", a1);
  dword_192EF4 = (int)PoolAlloc_110B89(1790000, a2);
  dword_193178 = (int)PoolAlloc_110B89(30000, a2);
  dword_19A00C = (int)PoolAlloc_110B89(1000, a2);
  dword_1930D4 = (int)PoolAlloc_110B89(6120, 6120);
  sub_127776((_BYTE *)dword_1930D4, 0x17E8u);
  dword_197F98 = (int)PoolAlloc_110B89(30024, 30024);
  sub_127776((_BYTE *)dword_197F98, 0x7548u);
  dword_192B18 = (int)PoolAlloc_110B89(90250, 90250);
  v2 = sub_127776((_BYTE *)dword_192B18, 90250u);
  if ( sub_127880() )
  {
    dword_192EF0 = 0;
    v3 = sub_1279AF(1525000, v2);
    dword_193170 = 1525000;
LABEL_6:
    dword_193174 = (int)v3;
    goto LABEL_7;
  }
  // v2 = volna pamet v bajtech (sub_110F89 vraci KiB, hra nasobi 1000);
  // prah 1791000 = velikost hlavniho zvukoveho bufferu 1790000 + rezerva.
  // Za behu originalu (32MB stroj) tudy proslo v2 = 0x188AB70 (~25.7 MB)
  // -> vetev s PoolAlloc(256000) nize, presne dle tohoto kodu.
  v2 = 1000 * sub_110F89();
  PortDebug_Checkpoint("sub_10CB5.availBytes", v2);
  if ( v2 <= 1791000 )
  {
    dword_192EF0 = 0;
    dword_193170 = 1000 * (sub_110F89() - 50);
    v3 = sub_1279AF(dword_193170, v2);
    goto LABEL_6;
  }
  v4 = PoolAlloc_110B89(256000, v2);
  v2 -= 266000;
  dword_192EF0 = (int)v4;
  dword_193174 = (int)sub_1279AF(v2, v2);
  dword_193170 = v2;
LABEL_7:
  dword_192EE8 = (int)sub_110C62(10240, v2);
  dword_193068 = (int)sub_110C62(20, 20);
  sub_127776((_BYTE *)dword_193068, 0x14u);
  dword_19306C = (int)sub_110C62(8136, 8136);
  sub_127776((_BYTE *)dword_19306C, 0x1FC8u);
  dword_197F9C = (int)sub_110C62(64500, 64500);
  sub_127776((_BYTE *)dword_197F9C, 0xFBF4u);
  result = sub_110C62(3953, 3953);
  dword_1930DC = (int)result;
  sub_127776(result, 0xF71u);
  return result;
}
// 192B18: using guessed type int dword_192B18;
// 192EE8: using guessed type int dword_192EE8;
// 192EF0: using guessed type int dword_192EF0;
// 192EF4: using guessed type int dword_192EF4;
// 193068: using guessed type int dword_193068;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 193170: using guessed type int dword_193170;
// 193174: using guessed type int dword_193174;
// 193178: using guessed type int dword_193178;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 19A00C: using guessed type int dword_19A00C;


//----- (00010E2F) --------------------------------------------------------
char __fastcall sub_10E2F(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  char *v5; // edi
  char *v6; // edi
  int v7; // eax
  int v8; // eax
  int16_t *v9; // edi
  int v10; // esi
  int v12; // eax
  int v13; // eax
  int16_t *v14; // edi
  char *v15; // eax
  int v16; // eax
  int i; // edi
  int v18; // eax
  int v19; // eax
  int j; // edi
  int v21; // eax
  int v22; // eax
  int k; // edi
  int v24; // eax
  int v25; // eax
  int m; // edi
  int v27; // eax
  int n; // edi
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // edx
  int v35; // eax
  int v36; // eax
  _BYTE *v37; // eax
  int v38; // eax
  int v39; // esi
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // edx
  int v45; // edx
  int v46; // esi
  int ii; // eax
  int16_t v48; // [esp+0h] [ebp-64Ah]
  _BYTE v49[1000]; // [esp+4h] [ebp-646h] BYREF
  _BYTE v50[218]; // [esp+3ECh] [ebp-25Eh] BYREF
  int v51; // [esp+4C6h] [ebp-184h]
  _BYTE v52[120]; // [esp+618h] [ebp-32h] BYREF
  char v53[19]; // [esp+690h] [ebp+46h] BYREF
  char v54; // [esp+6A3h] [ebp+59h] BYREF
  int16_t v55[10]; // [esp+6A4h] [ebp+5Ah] BYREF
  int v56; // [esp+6B8h] [ebp+6Eh] BYREF
  int v57; // [esp+6BCh] [ebp+72h] BYREF
  int v58; // [esp+6C0h] [ebp+76h]
  int v59; // [esp+6C4h] [ebp+7Ah]
  int v60; // [esp+6C8h] [ebp+7Eh]

  sub_7A795();
  v59 = v48;
  v58 = v48 + 1;
  v4 = itoa(v58, v53, 10, a4);
  strcpy((char *)v55, "SAVE");
  v5 = &v54;
  do
    ++v5;
  while ( *v5 );
  strcpy(v5, v53);
  v6 = &v54;
  do
    ++v6;
  while ( *v6 );
  strcpy(v6, aGam);
  sub_FE8BE(v4, (int)aRb, 10, v55);
  nullsub_14(v7);
  v60 = 0;
      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v8 = fopen(v55, aRb);
  v9 = (int16_t *)v8;
  v10 = v8;
  if ( !v8 )
  {
    _wcpp_1_unwind_leave(0, 0, aFileReadError);
    sub_6497C();
    return 0;
  }
  fread(&v56, 4, 1, v8);
  if ( v56 != 224 )
  {
    if ( byte_199CAE )
    {
      switch ( byte_199CAE )
      {
        case 1:
          sprintf(v52, aSaveDGamIstUng, v58);
          break;
        case 2:
          sprintf(v52, "SAUVEGARDER%d.GAM n'est pas valide!", v58);
          break;
        case 3:
          sprintf(v52, "#SAVE%d.GAM no es v<lido!", v58);
          break;
        case 4:
          sprintf(v52, "Il file SAVE%d.GAM non > valido!8", v58);
          break;
      }
    }
    else
    {
      sprintf(v52, "SAVE%d.GAM is invalid! Try another save slot or start a NEW game", v58);
    }
    sub_77433(v52);
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    return 0;
  }
  sub_8F855();
  if ( v48 >= 9 )
    v12 = 9;
  else
    v12 = v59;
  fread(&saveSlotInfo_199699[v12], sizeof(TypeSaveSlotInfo_199699), 1, v9);
  fread(&dword_192FD8, 4, 1, v10);
  fread(&byte_199F3A, 1, 1, v10);
  fread(v50, 553, 1, v10);
  v13 = fread(&v57, 4, 1, v10);
  sub_FE8BE(v13, 4, 1, v9);
  v14 = 0;
  fread(&word_199996, 2, 1, v10);
  do
  {
    v15 = (char *)v14 + dword_192B18;
    v14 = (int16_t *)((char *)v14 + 361);
    v16 = fread(v15, 361, 1, v10);
  }
  // 90250 = 361*250: konec bufferu dword_192B18 (250 zaznamu po 361 B),
  // v14 je bezici bytovy offset - viz vlna 10 (drive "(char*)&loc_16085+5").
  while ( v14 != (int16_t *)90250 );
  sub_FE8BE(v16, 361, 1, v14);
  fread(&word_1999A2, 2, 1, v10);
  for ( i = 0; i != 6120; i += 17 )
  {
    v18 = i + dword_1930D4;
    v19 = fread(v18, 17, 1, v10);
  }
  sub_FE8BE(v19, 17, 1, (int16_t *)0x17E8);
  fread(&word_19999A, 2, 1, v10);
  for ( j = 0; j != 8136; j += 113 )
  {
    v21 = j + dword_19306C;
    v22 = fread(v21, 113, 1, v10);
  }
  sub_FE8BE(v22, 113, 1, (int16_t *)0x1FC8);
  for ( k = 0; k != 3953; k += 59 )
  {
    v24 = k + dword_1930DC;
    v25 = fread(v24, 59, 1, v10);
  }
  sub_FE8BE(v25, 59, 1, (int16_t *)0xF71);
  fread(&word_199998, 2, 1, v10);
  for ( m = 0; m != 30024; m += 3753 )
  {
    v27 = m + dword_197F98;
    fread(v27, 3753, 1, v10);
  }
  fread(&word_199994, 2, 1, v10);
  for ( n = 0; n != 64500; n += 129 )
  {
    v29 = n + dword_197F9C;
    fread(v29, 129, 1, v10);
  }
  fread(word_192FDC, 28, 5, v10);
  fread(word_1992E8, 2, 5, v10);
  fread(&word_19999C, 2, 1, v10);
  fread(&word_1999A0, 2, 1, v10);
  fread(&word_19997C, 2, 1, v10);
  fread(&byte_199F0A, 1, 1, v10);
  fread(&word_199A0C, 2, 1, v10);
  v30 = fread(&word_199A0A, 2, 1, v10);
  sub_FE8BE(v30, 2, 1, (int16_t *)0xFBF4);
  fread(&unk_1999F0, 2, 1, v10);
  fread(dword_193068, 20, 1, v10);
  fread(&byte_199F0D, 1, 1, v10);
  if ( !dword_192EF0 )
    byte_199F0D = 0;
  v31 = fread(&word_17D634, 12, 1, v10);
  sub_FE8BE(v31, 12, 1, (int16_t *)0xFBF4);
  fread(&word_1AB502, 2, 1, v10);
  fread(byte_1AB14C, 950, 1, v10);
  fread(&byte_1AB50D, 1, 1, v10);
  fread(byte_1AB124, 8, 1, v10);
  fread(&unk_1AB504, 9, 1, v10);
  v32 = fread(byte_19ABA4, 9, 36, v10);
  sub_FE8BE(v32, 9, 36, (int16_t *)0xFBF4);
  fread(&unk_1AA414, 18, 100, v10);
  fread(byte_1AA40C, 1, 8, v10);
  fread(byte_1AAB24, 1, 8, v10);
  fread(byte_1AAB1C, 1, 8, v10);
  fread(&byte_1AB50F, 1, 1, v10);
  fread(&byte_1AB50E, 1, 1, v10);
  fread(&word_19A0E2, 2, 1, v10);
  v33 = fread(&word_19A0E4, 2, 1, v10);
  sub_FE8BE(v33, 2, 1, (int16_t *)0xFBF4);
  fread(&unk_19994A, 2, 1, v10);
  fread(&unk_1999B6, 2, 1, v10);
  fread(&word_1999E4, 2, 1, v10);
  fread(&dword_19ACE8, 4, 1, v10);
  fread(&word_19ACEC, 2, 1, v10);
  fread(&word_199174, 66, 1, v10);
  fread(&word_199992, 2, 1, v10);
  fread(&word_19998C, 2, 1, v10);
  fread(&word_199990, 2, 1, v10);
  v34 = 1000 - (int16_t)v60;
  fread(v49, v34, 1, v10);
  v35 = fclose(v10);
  sub_1279F(v35);
  v36 = sub_124820(v57);
  sub_FE8BE(v36, v34, 1, (int16_t *)0xFBF4);
  v37 = sub_103421();
  sub_FE8BE((int)v37, v34, 1, (int16_t *)0xFBF4);
  if ( byte_199F0D )
    sub_8DA07(v34, 1, (int16_t *)0xFBF4);
  sub_8A4C4();
  LOWORD(v38) = sub_918D5(2);
  if ( (_WORD)v38 )
    LOWORD(v38) = sub_71A17();
  nullsub_12(v38);
  byte_199CAF = v50[211];
  byte_199CB0 = v50[212];
  byte_199CB1 = v50[213];
  byte_199CB2 = v50[214];
  byte_199CB3 = v50[215];
  byte_199CB4 = v50[216];
  byte_199CB5 = v50[217];
  dword_199CB6 = v51;
  byte_199BDE = v50[2];
  v39 = 0;
  sub_78E67();
  nullsub_14(v40);
  v41 = sub_8A503();
  v42 = nullsub_14(v41);
  sub_7AB13(v42, v34);
  do
  {
    v43 = v39 + dword_197F98;
    if ( *(_WORD *)(v39 + dword_197F98 + 46) )
    {
      v44 = *(uint16_t *)(v43 + 46);
      *(_WORD *)(v43 + 46) = 0;
      *(_DWORD *)(v43 + 491) = v44;
    }
    v39 += 3753;
  }
  while ( v39 != 30024 );
  v45 = 0;
  v46 = 0;
  while ( v45 < word_199998 )
  {
    for ( ii = 0; ii < word_199998; *(_BYTE *)(v46 + dword_197F98 + ii + 2198) = -1 )
      ++ii;
    v46 += 3753;
    ++v45;
  }
  sub_7A7CF();
  sub_FE8C8(dword_192ED4, v45);
  return 1;
}
// 10E56: variable 'v48' is possibly undefined
// 10E9E: variable 'v4' is possibly undefined
// 10EA3: variable 'v7' is possibly undefined
// 114FF: variable 'v38' is possibly undefined
// 11573: variable 'v40' is possibly undefined
// 77433: using guessed type int __fastcall sub_77433(_DWORD);
// E5407: using guessed type int __fastcall nullsub_12(_DWORD);
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 17D634: using guessed type int16_t word_17D634;
// 192B18: using guessed type int dword_192B18;
// 192ED4: using guessed type int dword_192ED4;
// 192EF0: using guessed type int dword_192EF0;
// 192FD8: using guessed type int dword_192FD8;
// 192FDC: using guessed type int16_t word_192FDC[];
// 193068: using guessed type int dword_193068;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199174: using guessed type int16_t word_199174;
// 1992E8: using guessed type int16_t word_1992E8[5];
// 19997C: using guessed type int16_t word_19997C;
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;
// 199992: using guessed type int16_t word_199992;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999A0: using guessed type int16_t word_1999A0;
// 1999A2: using guessed type int16_t word_1999A2;
// 1999E4: using guessed type int16_t word_1999E4;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 199BDE: using guessed type char byte_199BDE;
// 199CAE: using guessed type char byte_199CAE;
// 199CAF: using guessed type char byte_199CAF;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199CB6: using guessed type int dword_199CB6;
// 199F0A: using guessed type char byte_199F0A;
// 199F0D: using guessed type char byte_199F0D;
// 199F3A: using guessed type char byte_199F3A;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19A0E4: using guessed type int16_t word_19A0E4;
// 19ACE8: using guessed type int dword_19ACE8;
// 19ACEC: using guessed type int16_t word_19ACEC;
// 1AB502: using guessed type int16_t word_1AB502;
// 1AB50D: using guessed type char byte_1AB50D;
// 1AB50E: using guessed type char byte_1AB50E;
// 1AB50F: using guessed type char byte_1AB50F;


//----- (0001160B) --------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __fastcall sub_1160B(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  char *v5; // edi
  char *v6; // edi
  int16_t *v7; // edi
  _DWORD *v8; // eax
  char *v9; // esi
  char *v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int16_t v25; // [esp+0h] [ebp-41Ah]
  _BYTE v26[999]; // [esp+4h] [ebp-416h] BYREF
  char v27; // [esp+3EBh] [ebp-2Fh] BYREF
  char v28[119]; // [esp+3ECh] [ebp-2Eh] BYREF
  char v29; // [esp+463h] [ebp+49h] BYREF
  char v30[20]; // [esp+464h] [ebp+4Ah] BYREF
  char v31[20]; // [esp+478h] [ebp+5Eh] BYREF
  int v32; // [esp+48Ch] [ebp+72h] BYREF
  int v33; // [esp+490h] [ebp+76h] BYREF
  int v34; // [esp+494h] [ebp+7Ah]
  int v35; // [esp+498h] [ebp+7Eh]

  v33 = sub_12484C();
  memset(v26, 0, 1000);
  sub_7A795();
  v34 = v25;
  v4 = itoa(v25 + 1, v31, 10, a4);
  strcpy(v30, "SAVE");
  v5 = &v29;
  do
    ++v5;
  while ( *v5 );
  strcpy(v5, v31);
  v6 = &v29;
  do
    ++v6;
  while ( *v6 );
  strcpy(v6, aGam);
  nullsub_14(v4);
  v35 = 0;
  v7 = (int16_t *)fopen(v30, aWb);
  if ( v7 )
  {
    v32 = 224;
    sub_8F855();
    fwrite(&v32, 4, 1, v7);
    if ( v25 >= 9 )
      v11 = 9;
    else
      v11 = v34;
    fwrite(&saveSlotInfo_199699[v11], sizeof(TypeSaveSlotInfo_199699), 1, v7);
    fwrite(&dword_192FD8, 4, 1, v7);
    fwrite(&byte_199F3A, 1, 1, v7);
    v12 = fwrite(&byte_199BDC, 553, 1, v7);
    sub_FE8BE(v12, 553, 1, v7);
    fwrite(&v33, 4, 1, v7);
    fwrite(&word_199996, 2, 1, v7);
    v13 = fwrite(dword_192B18, 361, 250, v7);
    sub_FE8BE(v13, 361, 250, v7);
    fwrite(&word_1999A2, 2, 1, v7);
    v14 = fwrite(dword_1930D4, 17, 360, v7);
    sub_FE8BE(v14, 17, 360, v7);
    fwrite(&word_19999A, 2, 1, v7);
    v15 = fwrite(dword_19306C, 113, 72, v7);
    sub_FE8BE(v15, 113, 72, v7);
    v16 = fwrite(dword_1930DC, 59, 67, v7);
    sub_FE8BE(v16, 59, 67, v7);
    fwrite(&word_199998, 2, 1, v7);
    v17 = fwrite(dword_197F98, 3753, 8, v7);
    sub_FE8BE(v17, 3753, 8, v7);
    fwrite(&word_199994, 2, 1, v7);
    v18 = fwrite(dword_197F9C, 129, 500, v7);
    sub_FE8BE(v18, 129, 500, v7);
    fwrite(word_192FDC, 28, 5, v7);
    fwrite(word_1992E8, 2, 5, v7);
    fwrite(&word_19999C, 2, 1, v7);
    fwrite(&word_1999A0, 2, 1, v7);
    v19 = fwrite(&word_19997C, 2, 1, v7);
    sub_FE8BE(v19, 2, 1, v7);
    fwrite(&byte_199F0A, 1, 1, v7);
    fwrite(&word_199A0C, 2, 1, v7);
    fwrite(&word_199A0A, 2, 1, v7);
    fwrite(&unk_1999F0, 2, 1, v7);
    fwrite(dword_193068, 20, 1, v7);
    fwrite(&byte_199F0D, 1, 1, v7);
    v20 = fwrite(&word_17D634, 12, 1, v7);
    sub_FE8BE(v20, 12, 1, v7);
    fwrite(&word_1AB502, 2, 1, v7);
    fwrite(byte_1AB14C, 950, 1, v7);
    fwrite(&byte_1AB50D, 1, 1, v7);
    fwrite(byte_1AB124, 8, 1, v7);
    fwrite(&unk_1AB504, 9, 1, v7);
    v21 = fwrite(byte_19ABA4, 9, 36, v7);
    sub_FE8BE(v21, 9, 36, v7);
    fwrite(&unk_1AA414, 18, 100, v7);
    fwrite(byte_1AA40C, 1, 8, v7);
    fwrite(byte_1AAB24, 1, 8, v7);
    fwrite(byte_1AAB1C, 1, 8, v7);
    fwrite(&byte_1AB50F, 1, 1, v7);
    v22 = fwrite(&byte_1AB50E, 1, 1, v7);
    sub_FE8BE(v22, 1, 1, v7);
    fwrite(&word_19A0E2, 2, 1, v7);
    fwrite(&word_19A0E4, 2, 1, v7);
    fwrite(&unk_19994A, 2, 1, v7);
    fwrite(&unk_1999B6, 2, 1, v7);
    fwrite(&word_1999E4, 2, 1, v7);
    fwrite(&dword_19ACE8, 4, 1, v7);
    fwrite(&word_19ACEC, 2, 1, v7);
    v23 = fwrite(&word_199174, 66, 1, v7);
    sub_FE8BE(v23, 66, 1, v7);
    fwrite(&word_199992, 2, 1, v7);
    fwrite(&word_19998C, 2, 1, v7);
    fwrite(&word_199990, 2, 1, v7);
    fwrite(v26, 1000 - (int16_t)v35, 1, v7);
    fclose(v7);
    LOWORD(v24) = sub_7A7CF();
    nullsub_14(v24);
    sub_11BE4();
  }
  else
  {
    strcpy(v28, "Error saving game.\n");
    v8 = sub_129C88();
    v9 = (char *)strerror(*v8);
    v10 = &v27;
    do
      ++v10;
    while ( *v10 );
    strcpy(v10, v9);
    sub_77423((int)v28);
  }
  JUMPOUT(0x115FE);
}
// 116E4: control flows out of bounds to 115FE
// 11789: bad sp value at call
// 11BC4: bad sp value at call
// 1164C: variable 'v25' is possibly undefined
// 11691: variable 'v4' is possibly undefined
// 11BD5: variable 'v24' is possibly undefined
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 129C94: using guessed type int __fastcall strerror(_DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 17D634: using guessed type int16_t word_17D634;
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 192FDC: using guessed type int16_t word_192FDC[];
// 193068: using guessed type int dword_193068;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199174: using guessed type int16_t word_199174;
// 1992E8: using guessed type int16_t word_1992E8[5];
// 19997C: using guessed type int16_t word_19997C;
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;
// 199992: using guessed type int16_t word_199992;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;
// 1999A0: using guessed type int16_t word_1999A0;
// 1999A2: using guessed type int16_t word_1999A2;
// 1999E4: using guessed type int16_t word_1999E4;
// 199A0A: using guessed type int16_t word_199A0A;
// 199A0C: using guessed type int16_t word_199A0C;
// 199BDC: using guessed type char byte_199BDC;
// 199F0A: using guessed type char byte_199F0A;
// 199F0D: using guessed type char byte_199F0D;
// 199F3A: using guessed type char byte_199F3A;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19A0E4: using guessed type int16_t word_19A0E4;
// 19ACE8: using guessed type int dword_19ACE8;
// 19ACEC: using guessed type int16_t word_19ACEC;
// 1AB502: using guessed type int16_t word_1AB502;
// 1AB50D: using guessed type char byte_1AB50D;
// 1AB50E: using guessed type char byte_1AB50E;
// 1AB50F: using guessed type char byte_1AB50F;


//----- (00011BE4) --------------------------------------------------------
char sub_11BE4()
{
  int v0; // eax
  int v1; // esi
  int v2; // eax

  ((void (*)(void))nullsub_14)();
  v0 = fopen(aMoxSet_0, aWb);
  v1 = v0;
  if ( !v0 )
    return 0;
  fwrite(&byte_199BDC, 553, 1, v0);
  v2 = fclose(v1);
  nullsub_14(v2);
  fclose(v1);
  return 1;
}
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 199BDC: using guessed type char byte_199BDC;


//----- (00011C39) --------------------------------------------------------
char __fastcall LoadSettingsFile_11C39(int a1)
{
  int v1; // eax
  int v2; // esi
  int v3; // eax

  nullsub_14(a1);
  v1 = fopen(aMoxSet_0, "rb");
  v2 = v1;
  if ( v1 )
  {
    fread(&byte_199BDC, 553, 1, v1);
    v3 = fclose(v2);
    nullsub_14(v3);
  }
  return sub_7A06C();
}
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 199BDC: using guessed type char byte_199BDC;


//----- (00011C83) --------------------------------------------------------
void sub_11C83()
{
  int v0; // ecx
  char *v1; // edi
  char *v2; // edi
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // [esp+0h] [ebp-30h] BYREF
  char v8[16]; // [esp+4h] [ebp-2Ch] BYREF
  char v9[8]; // [esp+14h] [ebp-1Ch] BYREF
  char *v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h] BYREF
  _DWORD *v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v14 = 0;
  while ( 1 )
  {
    v0 = (int16_t)v14;
    itoa((int16_t)v14 + 1, v9, 10, (int16_t)v14);
    strcpy(v8, "SAVE");
    v1 = (char *)&v7 + 3;
    do
      ++v1;
    while ( *v1 );
    strcpy(v1, v9);
    v2 = (char *)&v7 + 3;
    do
      ++v2;
    while ( *v2 );
    strcpy(v2, aGam);
    v3 = 37 * v0;
    v4 = access(v8, 0);
    v12 = (_DWORD *)(4 * v0 + v7);
    v10 = &saveSlotInfo_199699[v0];
    if ( v4 )
    {
      strcpy(&saveSlotInfo_199699[v3/37], sub_7A990(0x184u));
      *v12 = -1;
    }
    else
    {
          // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v5 = fopen(v8, aRb);
      v6 = v5;
      v13 = v5;
      if ( v5 )
      {
        fread(&v11, 4, 1, v5);
        fread(v10, 37, 1, v6);
        fread(v12, 4, 1, v6);
        if ( v11 == 224 )
        {
          if ( (_WORD)v14 == 9 )
          {
            strcpy(&saveSlotInfo_199699[v3/37], "(Auto Save)");
          }
          else if ( !saveSlotInfo_199699[1 + v0].name[0])
          {
            strcpy(&saveSlotInfo_199699[1 + v3].name[0], "<< no description >>");
          }
        }
        else
        {
          *v12 = -1;
          strcpy(v10, sub_7A990(0x184u));
        }
        fclose(v13);
      }
    }
    if ( (int16_t)++v14 >= 10 )
      JUMPOUT(0x11605);
  }
}
// 11DFF: control flows out of bounds to 11605
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129E6B: using guessed type int __fastcall access(_DWORD, _DWORD);


//----- (00011E04) --------------------------------------------------------
char __fastcall sub_11E04(int a1)
{
  int v1; // eax
  int v2; // esi
  int v4; // [esp+0h] [ebp-8h] BYREF
  char v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  v1 = fopen(a1, aRb);
  v2 = v1;
  if ( v1 )
  {
    fread(&v4, 4, 1, v1);
    if ( v4 == 224 )
      v5 = 1;
    fclose(v2);
  }
  return v5;
}
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (00011E56) --------------------------------------------------------
void __fastcall sub_11E56(int a1)
{
  int v1; // ecx
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = 0;
  v1 = fopen(a1, aRb);
  if ( v1 )
  {
    // DECOMP_TODO (vyreseno ve vlne 07): fseek melo jen 1 (nesouvisejici)
    // parametr - stejny Hex-Rays artefakt jako u fopen (vlna 06). Vzor je
    // ve vsech 4 fseek volanich v tomto souboru identicky: seek na zacatek
    // souboru hned po fopen(), pred fread() se stejnym handle - takze zde
    // fseek(v1, 0, SEEK_SET).
    if ( !fseek(v1, 0, SEEK_SET) )
      fread(&v2, 4, 1, v1);
    fclose(v1);
  }
  JUMPOUT(0x11E50);
}
// 11EA3: control flows out of bounds to 11E50
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129EE8: using guessed type int __cdecl fseek(_DWORD);


//----- (00011EAE) --------------------------------------------------------
int __fastcall sub_11EAE( int a1, int a2)
{
  int v2; // eax
  int v3; // esi
  _DWORD v5[4]; // [esp+0h] [ebp-10h] BYREF

  sprintf(v5, "SAVE%d.GAM", a1 + 1);
  v2 = fopen(v5, aRb);
  v3 = v2;
  if ( v2 )
  {
    // DECOMP_TODO (vyreseno ve vlne 07): stejny vzor jako vyse - seek na
    // zacatek pred cteni 553bajtove struktury nastaveni (srovnej s
    // sub_11F11 nize, ktery cte stejnych 553 bajtu stejnym zpusobem).
    fseek(v3, 0, SEEK_SET);
    fread(a2, 553, 1, v3);
    v2 = fclose(v3);
    LOBYTE(v2) = 1;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  return nullsub_1(v2);
}
// 11F10: using guessed type int __fastcall nullsub_1(_DWORD);
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129EE8: using guessed type int __cdecl fseek(_DWORD);


//----- (00011F11) --------------------------------------------------------
int __fastcall sub_11F11( int a1, int a2)
{
  int v4; // esi
  char v5; // dl
  int v6; // eax
  int v7; // edi
  _BYTE v8[556]; // [esp+0h] [ebp-240h] BYREF
  char v9[16]; // [esp+22Ch] [ebp-14h] BYREF
  char v10; // [esp+23Ch] [ebp-4h]

  sprintf(v9, "SAVE%d.GAM", a1);
  v10 = 1;
      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v4 = fopen(v9, aRb);
  if ( v4 )
  {
    // DECOMP_TODO (vyreseno ve vlne 07): stejny vzor - seek na zacatek
    // pred cteni 553bajtove struktury nastaveni.
    fseek(v4, 0, SEEK_SET);
    fread(v8, 553, 1, v4);
    fclose(v4);
        // DECOMP_TODO (castecne vyreseno ve vlne 06): chybel mod parametr - v okoli se nenaslo jednoznacne fread/fwrite, takze "aRb" je bezpecny odhad (needela zadnou zapisovou vedlejsi ucinek jako by mohl "wb"), potrebuje overit.
    v6 = fopen(a2, aRb);
    v7 = v6;
    if ( v6 )
    {
      fwrite(v8, 553, 1, v4);
      v6 = fclose(v7);
    }
    else
    {
      v10 = 0;
    }
    v5 = v10;
  }
  else
  {
    _wcpp_1_unwind_leave(0, 2, "Cannot locate %s!", v9);
    v5 = 0;
    sub_6497C();
  }
  LOBYTE(v6) = v5;
  return nullsub_1(v6);
}
// 11F0F: variable 'v6' is possibly undefined
// 11F10: using guessed type int __fastcall nullsub_1(_DWORD);
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);


//----- (00011FCC) --------------------------------------------------------
void __fastcall sub_11FCC( int a1)
{
  int v1; // ecx
  _DWORD v2[4]; // [esp+0h] [ebp-14h] BYREF
  char v3[4]; // [esp+10h] [ebp-4h] BYREF

  v3[0] = -1;
  sprintf(v2, "SAVE%d.GAM", a1 + 1);
  v1 = fopen(v2, aRb);
  if ( v1 )
  {
    // DECOMP_TODO (vyreseno ve vlne 07): stejny vzor - seek na zacatek
    // pred cteni 1 bajtu.
    if ( !fseek(v1, 0, SEEK_SET) )
      fread(v3, 1, 1, v1);
    JUMPOUT(0x11E46);
  }
  JUMPOUT(0x11E4D);
}
// 12028: control flows out of bounds to 11E46
// 11FFF: control flows out of bounds to 11E4D
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 12685D: using guessed type int __fastcall fopen(_DWORD, _DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129EE8: using guessed type int __cdecl fseek(_DWORD);


//----- (0001202D) --------------------------------------------------------
char sub_1202D()
{
  return 0;
}


//----- (00012030) --------------------------------------------------------
void sub_12030()
{
  int v0; // edx
  int v1; // eax
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  _BYTE v7[556]; // [esp+0h] [ebp-54h] BYREF
  char v8; // [esp+22Ch] [ebp+1D8h]

  v0 = (int)aRb;
  v8 = 0;
      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v1 = fopen(aMoxSet_0, aRb);
  v2 = v1;
  if ( v1 )
  {
    fread(v7, 553, 1, v1);
    v0 = (int)aWb;
    v3 = fclose(v2);
    v4 = nullsub_14(v3);
    qmemcpy(v7, &byte_199BDC, 0xD3u);
    nullsub_14(v4);
    v8 = 1;
        // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v5 = fopen(aMoxSet_0, aWb);
    v6 = v5;
    if ( v5 )
    {
      v0 = 553;
      fwrite(v7, 553, 1, v5);
      fclose(v6);
    }
    else
    {
      v8 = 0;
    }
  }
  if ( !v8 )
    sub_126487(aSettingsFileMo, v0);
  JUMPOUT(0x11604);
}
// 120F5: control flows out of bounds to 11604
// FE8BD: using guessed type int __fastcall nullsub_14(_DWORD);
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 1288DB: using guessed type int __fastcall fread(_DWORD, _DWORD, _DWORD, _DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 199BDC: using guessed type char byte_199BDC;


//----- (00012175) --------------------------------------------------------
int64_t sub_12175()
{
  int v1; // [esp-4h] [ebp-24h]
  char v2[32]; // [esp+0h] [ebp-20h] BYREF

  v2[0] = 0;
  switch ( byte_199F3A )
  {
    case 0:
      strcpy(v2, "Single Player");
      break;
    case 1:
      v1 = (int16_t)sub_121F0();
      sprintf(v2, "%d Human, Hot Seat", v1);
      break;
    case 2:
      sprintf(v2, "%d Human, Network", (uint8_t)byte_1AAF5D);
      break;
    case 3:
      strcpy(v2, "Modem");
      break;
    default:
      return sprintf(byte_19980B, "%s Auto Save", v2);
  }
  return sprintf(byte_19980B, "%s Auto Save", v2);
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 199F3A: using guessed type char byte_199F3A;
// 1AAF5D: using guessed type char byte_1AAF5D;


//----- (000121F0) --------------------------------------------------------
int sub_121F0()
{
  int v0; // edx
  int16_t i; // bx
  int v2; // eax

  v0 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    v2 = dword_197F98 + 3753 * i;
    if ( *(_BYTE *)(v2 + 40) == 100 && !*(_BYTE *)(v2 + 36) )
      ++v0;
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00012227) --------------------------------------------------------
char LoadOrResetSettings_12227()
{
  int v0; // eax
  char v1; // bl
  int v2; // eax

  v0 = fopen(aMoxSet_0,"rb");
  v1 = 0;
  if ( !v0 || (v2 = fclose(v0), LoadSettingsFile_11C39(v2), word_199CBE = 130, LOBYTE(v0) = sub_11BE4(), !(_BYTE)v0) )
    v1 = 1;
  if ( v1 )
    LOBYTE(v0) = InitDefaultSettings_127E1();
  return v0;
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 199CBE: using guessed type int16_t word_199CBE;


//----- (00012268) --------------------------------------------------------
void sub_12268()
{
  int v0; // edx
  int v1; // eax

  memset(dword_197F9C, 0, 64500);
  word_199994 = 0;
  do
  {
    v0 = 129 * word_199994;
    v1 = dword_197F9C;
    *(_BYTE *)(v0 + dword_197F9C + 100) = 5;
    *(_WORD *)(v0 + v1 + 101) = -1;
    ++word_199994;
    *(_WORD *)(v0 + v1 + 116) = -1;
  }
  while ( word_199994 < 500 );
  word_199994 = 0;
  sub_10011B();
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (000122CC) --------------------------------------------------------
char sub_122CC()
{
  char result; // al
  unsigned int v1; // ecx
  int16_t v2; // si
  int16_t v3; // di
  uint8_t *v4; // eax
  int16_t i; // cx
  char v6; // [esp+0h] [ebp-4h]

  result = dword_19306C;
  v6 = 0;
  v1 = dword_19306C + 113 * word_19999A;
  while ( v1 > dword_19306C )
  {
    v1 -= 113;
    if ( *(_BYTE *)(v1 + 40) == 9 )
    {
      v2 = sub_1247A0(5u) + 9;
      v3 = sub_7C94E((int)(v1 - dword_19306C) / 113);
      *(_BYTE *)(dword_197F9C + 129 * word_199994 + 99) = 8;
      sub_A16BF(v2, (int)(v1 - dword_19306C) / 113, 0);
      *(_BYTE *)(v1 + 40) = *(_BYTE *)(v1 + 100);
      v4 = (uint8_t *)(17 * v3 + dword_1930D4);
      *(_BYTE *)(v1 + 100) = 0;
      result = sub_7C9EE(v4, v2);
    }
  }
  for ( i = 0; i < word_19999A && !v6; ++i )
  {
    result = dword_19306C;
    if ( *(_BYTE *)(113 * i + dword_19306C + 40) == 11 )
    {
      *(_BYTE *)(dword_197F9C + 129 * word_199994 + 99) = 8;
      v6 = 1;
      result = sub_A16BF(9, i, 0);
    }
  }
  return result;
}
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 19999A: using guessed type int16_t word_19999A;


//----- (000123CE) --------------------------------------------------------
void sub_123CE()
{
  int16_t i; // cx
  int v1; // eax
  int v2; // edx
  int16_t v3; // [esp+0h] [ebp-4h] BYREF

  for ( i = 0; i < word_19999A; ++i )
  {
    v1 = 0;
    do
    {
      v2 = (int16_t)v1++;
      *(_BYTE *)(v2 + 113 * i + dword_19306C + 23) = -1;
    }
    while ( (int16_t)v1 < 8 );
    sub_7862B(i, word_19999C, &v3);
  }
}
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;
// 19999C: using guessed type int16_t word_19999C;


//----- (0001241A) --------------------------------------------------------
int sub_1241A()
{
  int result; // eax
  int v1; // edx

  memset(dword_192B18, 0, 90250); // cely buffer 250x361 B, viz vlna 10
  word_199996 = 0;
  do
  {
    result = 361 * word_199996;
    v1 = dword_192B18;
    *(_WORD *)(dword_192B18 + result + 2) = -1;
    *(_BYTE *)(v1 + result) = -1;
    ++word_199996;
    *(_WORD *)(v1 + result + 4) = -1;
  }
  while ( word_199996 < 250 );
  word_199996 = 0;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 199996: using guessed type int16_t word_199996;


//----- (00012479) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=170)) - nutno dohledat rucne v IDA @ 0x12520 */
_DWORD __stdcall sub_12479(_DWORD _p0, _DWORD _p1)
{
  DECOMP_TODO("call analysis failed (funcsize=170)");
}


//----- (0001279F) --------------------------------------------------------
unsigned int __fastcall sub_1279F(int a1)
{
  int v1; // eax
  unsigned int result; // eax

  word_19998C = 0;
  word_199990 = 0;
  word_199A08 = 39;
  word_19A0E0 = -1;
  nullsub_3(a1);
  v1 = sub_792C3();
  nullsub_10(v1);
  result = sub_10206E();
  word_199A0E = 0;
  return result;
}
// 586D3: using guessed type int __fastcall nullsub_3(_DWORD);
// C5E9F: using guessed type int __fastcall nullsub_10(_DWORD);
// 19998C: using guessed type int16_t word_19998C;
// 199990: using guessed type int16_t word_199990;
// 199A08: using guessed type int16_t word_199A08;
// 199A0E: using guessed type int16_t word_199A0E;
// 19A0E0: using guessed type int16_t word_19A0E0;


//----- (000127E1) --------------------------------------------------------
int InitDefaultSettings_127E1()
{
  int i; // eax
  uint64_t v1; // rax

  memset(&byte_199BDC, 0, 553);
  byte_199BDC = 1;
  byte_199BDD = 1;
  byte_199BDE = 1;
  byte_199BDF = 0;
  byte_199BE0 = 0;
  byte_199BE1 = 1;
  byte_199BE2 = 1;
  byte_199BE3 = 0;
  byte_199BE4 = 1;
  byte_199BE5 = 1;
  byte_199BE6 = 0;
  byte_199BE7 = 1;
  byte_199BE8 = 0;
  byte_199BE9 = 0;
  byte_199BEA = 0;
  byte_199BEB = 0;
  byte_199BED = 1;
  byte_199BEE = 50;
  byte_199BEF = 1;
  byte_199BF0 = 50;
  byte_199CAF = 1;
  word_199CBE = 130;
  byte_199BF1 = -1;
  byte_199CB0 = 0;
  byte_199CB1 = 5;
  byte_199CB2 = 1;
  byte_199CB3 = 1;
  byte_199CB4 = 1;
  byte_199CB5 = 1;
  byte_199C90 = 0;
  byte_199C91 = 0;
  byte_199C92 = 1;
  byte_199C93 = 0;
  byte_199C94 = 0;
  word_199CBC = 1;
  word_199CBA = 2;
  /*for (i = 0; i != 370; byte_199699[i] = 0)
    i += 37;*/
  for (int slot = 0; slot < 10; slot++)
    saveSlotInfo_199699[slot].name[0] = 0;
  v1 = j___clock(370, 0, 10);
  sprintf(&byte_199BF3, "MOX-%d", (unsigned int)(v1 % 0xA));
  sub_F46E7();
  return sub_12937();
}
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 129FE4: using guessed type int64_t __fastcall j___clock(_DWORD, _DWORD, _DWORD);
// 199BDC: using guessed type char byte_199BDC;
// 199BDD: using guessed type char byte_199BDD;
// 199BDE: using guessed type char byte_199BDE;
// 199BDF: using guessed type char byte_199BDF;
// 199BE0: using guessed type char byte_199BE0;
// 199BE1: using guessed type char byte_199BE1;
// 199BE2: using guessed type char byte_199BE2;
// 199BE3: using guessed type char byte_199BE3;
// 199BE4: using guessed type char byte_199BE4;
// 199BE5: using guessed type char byte_199BE5;
// 199BE6: using guessed type char byte_199BE6;
// 199BE7: using guessed type char byte_199BE7;
// 199BE8: using guessed type char byte_199BE8;
// 199BE9: using guessed type char byte_199BE9;
// 199BEA: using guessed type char byte_199BEA;
// 199BEB: using guessed type char byte_199BEB;
// 199BED: using guessed type char byte_199BED;
// 199BEE: using guessed type char byte_199BEE;
// 199BEF: using guessed type char byte_199BEF;
// 199BF0: using guessed type char byte_199BF0;
// 199BF1: using guessed type char byte_199BF1;
// 199BF3: using guessed type char byte_199BF3;
// 199C90: using guessed type char byte_199C90;
// 199C91: using guessed type char byte_199C91;
// 199C92: using guessed type char byte_199C92;
// 199C93: using guessed type char byte_199C93;
// 199C94: using guessed type char byte_199C94;
// 199CAF: using guessed type char byte_199CAF;
// 199CB0: using guessed type char byte_199CB0;
// 199CB1: using guessed type char byte_199CB1;
// 199CB2: using guessed type char byte_199CB2;
// 199CB3: using guessed type char byte_199CB3;
// 199CB4: using guessed type char byte_199CB4;
// 199CB5: using guessed type char byte_199CB5;
// 199CBA: using guessed type int16_t word_199CBA;
// 199CBC: using guessed type int16_t word_199CBC;
// 199CBE: using guessed type int16_t word_199CBE;


//----- (00012937) --------------------------------------------------------
int sub_12937()
{
  int v0; // esi

      // DECOMP_TODO (vyreseno ve vlne 06): chybel mod parametr (Hex-Rays artefakt, viz PROGRESS.md) - dopocitan z pouziti (fread/fwrite/fprintf nize).
    v0 = fopen(aMoxSet_1, aWb);
  if ( !v0 )
    sub_126487(aUnableToOpenMo, (int)aWb_0);
  fwrite(&byte_199BDC, 553, 1, v0);
  fflush(v0);
  return fclose(v0);
}
// 12697A: using guessed type int __fastcall fclose(_DWORD);
// 129CAB: using guessed type int __fastcall fwrite(_DWORD, _DWORD, _DWORD, _DWORD);
// 129FE9: using guessed type int __fastcall fflush(_DWORD);
// 199BDC: using guessed type char byte_199BDC;


//----- (00012983) --------------------------------------------------------
void __usercall sub_12983(int16_t *a1)
{
  int v1; // ebx
  int v2; // esi
  int v3; // edx
  int16_t *v4; // edi
  int v5; // ebx
  _DWORD *v6; // eax
  int v7; // eax
  _BYTE *v8; // eax
  int16_t v9; // dx
  int16_t j; // ax
  int v11; // eax
  _BYTE *v12; // edx
  _BYTE *v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // esi
  _BYTE *v17; // eax
  int v18; // ebx
  int v19; // eax
  int16_t k; // cx
  int16_t v21; // si
  int16_t m; // ax
  int v23; // edi
  int v24; // eax
  int16_t v25; // ax
  int16_t *v26; // edi
  char v27; // al
  int v28; // eax
  int n; // edx
  int v30; // eax
  char *v31; // eax
  int ii; // eax
  int v33; // ecx
  int v34; // eax
  int16_t v35; // ax
  int v36; // eax
  int v37; // eax
  int v38; // ebx
  int v39; // edx
  int v40; // eax
  int v41; // eax
  int16_t *v42; // [esp-4h] [ebp-14h]
  int16_t *v43; // [esp-4h] [ebp-14h]
  int v44; // [esp+4h] [ebp-Ch]
  int16_t v45; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v1 = dword_192EE8;
  LOWORD(v2) = 1;
  dword_19B7DC[0] = (int)sub_126BDD((int)aRacestufLbx, 7, dword_192EE8, 0, 1u, 31);
  sub_FE8BE(dword_19B7DC[0], 7, v1, a1);
  do
  {
    v3 = 7;
    v4 = (int16_t *)(int16_t)v2;
    v5 = dword_192EE8;
    v6 = sub_126C37((int)aRacestufLbx, 7, dword_192EE8, (int16_t)v2, 1u, 31);
    LOWORD(v2) = v2 + 1;
    dword_19B7DC[(_DWORD)v4] = (int)v6;
    sub_FE8BE((int)v6, 7, v5, v4);
  }
  while ( (int16_t)v2 < 13 );
  sub_FE8BE(v7, 7, v5, v4);
  for ( i = 0; (int16_t)i < word_199998; ++i )
  {
    v8 = (_BYTE *)(dword_197F98 + 3753 * (int16_t)i);
    if ( v8[40] == 100 )
    {
      v3 = (int)(v8 + 2207);
      v5 = 31;
      sub_12779E(v8 + 2238, v8 + 2207, 0x1Fu);
    }
    else
    {
      do
      {
        v9 = 1;
        v45 = sub_1247A0(0xDu) - 1;
        for ( j = 0; j < (int16_t)i && v9; ++j )
        {
          if ( *(uint8_t *)(dword_197F98 + 3753 * j + 37) == v45 )
            v9 = 0;
        }
      }
      while ( !v9 );
      v44 = 3753 * (int16_t)i;
      v11 = v44 + dword_197F98;
      *(_BYTE *)(v11 + 37) = v45;
      v42 = (int16_t *)(v11 + 21);
      strcpy((char *)(v11 + 21), (char *)dword_192630[v45]);
      sub_12779E((_BYTE *)(v44 + dword_197F98 + 2207), (_BYTE *)dword_19B7DC[v45], 0x1Fu);
      v12 = (_BYTE *)dword_19B7DC[v45];
      v13 = sub_12779E((_BYTE *)(v44 + dword_197F98 + 2238), v12, 0x1Fu);
      sub_FE8BE((int)v13, (int)v12, 31, v42);
      v14 = sub_150FB((int16_t)i);
      sub_FE8BE(v14, (int)v12, 31, v42);
      v15 = 1;
      v16 = v44 + dword_197F98 + 2207;
      do
      {
        v17 = (_BYTE *)(v16 + (int16_t)v15);
        if ( *v17 )
          *v17 = byte_17D1F9[3 * (int16_t)v15 + (char)*v17];
        else
          *v17 = 0;
        v18 = (int16_t)v15;
        v19 = (int16_t)v15 + dword_197F98 + 3753 * (int16_t)i;
        if ( *(_BYTE *)(v19 + 2238) )
        {
          v18 = 3 * (int16_t)v15;
          LOBYTE(v18) = byte_17D1F9[*(char *)(v19 + 2238) + v18];
          *(_BYTE *)(v19 + 2238) = v18;
        }
        else
        {
          *(_BYTE *)(v19 + 2238) = 0;
        }
        ++v15;
      }
      while ( (int16_t)v15 < 10 );
      sub_FE8BE(v19, v15, v18, v42);
      for ( k = sub_1247A0(8u) - 1; ; k = v15 )
      {
        v21 = 0;
        for ( m = 0; m < (int16_t)i; ++m )
        {
          v18 = 3753 * m;
          HIWORD(v15) = HIWORD(dword_197F98);
          LOWORD(v15) = *(uint8_t *)(dword_197F98 + v18 + 38);
          if ( (_WORD)v15 == k )
            v21 = 1;
        }
        if ( !v21 )
          break;
        v18 = 8;
        v15 = (k + 1) % 8;
      }
      v23 = 3753 * (int16_t)i;
      v24 = dword_197F98;
      *(_BYTE *)(v23 + dword_197F98 + 38) = k;
      sub_FE8BE(v24, v15, v18, (int16_t *)v23);
      sub_1112EC(dword_192ED4, v15);
      v25 = sub_1247A0(8u);
      v5 = dword_192ED4;
      v3 = 0;
      v2 = (int)sub_126C37((int)aRacenameLbx, 0, dword_192ED4, (int16_t)(8 * v45 + v25 - 1), 1u, 20);
      sub_FE8BE(v2, 0, v5, (int16_t *)v23);
      sub_1113CC(dword_192ED4, 0);
      v26 = (int16_t *)(dword_197F98 + v23 + 1);
      v43 = v26;
      do
      {
        v27 = *(_BYTE *)v2++;
        *(_BYTE *)v26 = v27;
        v26 = (int16_t *)((char *)v26 + 1);
      }
      while ( v27 );
      v4 = v43;
    }
  }
  sub_FE8BE(i, v3, v5, v4);
  v28 = sub_589D6();
  sub_FE8BE(v28, v3, v5, v4);
  for ( n = 0; (int16_t)n < word_199998; ++n )
  {
    v4 = (int16_t *)(3753 * (int16_t)n);
    v30 = (int)v4 + dword_197F98;
    *(_BYTE *)(v30 + 1441) = -1;
    *(_BYTE *)(v30 + 1438) = -1;
    *(_BYTE *)((int16_t)n + v30 + 1412) = 1;
    *(_BYTE *)(v30 + 45) = 0;
    *(_DWORD *)(v30 + 50) = 50;
    sub_FE8BE(v30, n, v5, v4);
    v31 = (char *)v4 + dword_197F98;
    v31[(int16_t)n + 3671] = 0;
    v31[3679] = 79;
    v31[3680] = 0;
    *((_WORD *)v31 + 27) = 0;
    for ( ii = 0; (int16_t)ii < word_199998; ++ii )
    {
      v33 = 4 * (int16_t)ii + 3753 * (int16_t)n + dword_197F98;
      v5 = dword_192FD8;
      *(_DWORD *)(v33 + 553) = dword_192FD8;
    }
    sub_FE8BE(ii, n, v5, v4);
    sub_5E55F(n);
    sub_FE8BE(v34, n, v5, v4);
    sub_54FBF(n);
    sub_5709F(n);
    v2 = 10 * v35;
    HIWORD(v5) = HIWORD(dword_197F98);
    v36 = dword_197F98 + 3753 * (int16_t)n;
    LOWORD(v5) = *(int16_t *)((char *)word_17FFEA + v2);
    *(_WORD *)(v36 + 804) = v5;
  }
  v37 = word_19999C;
  v38 = dword_197F98;
  v39 = dword_197F98 + 3753 * word_19999C;
  *(_BYTE *)(v39 + word_19999C + 1412) = 1;
  sub_FE8BE(v37, v39, v38, v4);
  sub_7AC71();
  sub_FE8BE(v40, v39, v38, v4);
  v41 = sub_4D78E(v2);
  sub_FE8BE(v41, v39, v38, v4);
  JUMPOUT(0x123C7);
}
// 12D70: control flows out of bounds to 123C7
// 129E7: variable 'v7' is possibly undefined
// 12CF7: variable 'v34' is possibly undefined
// 12D0A: variable 'v35' is possibly undefined
// 12D61: variable 'v40' is possibly undefined
// 17FFEA: using guessed type int16_t word_17FFEA[];
// 192630: using guessed type int dword_192630[];
// 192ED4: using guessed type int dword_192ED4;
// 192EE8: using guessed type int dword_192EE8;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 19B7DC: using guessed type int dword_19B7DC[13];


//----- (00012D75) --------------------------------------------------------
int __fastcall sub_12D75(int a1, int a2, int a3)
{
  int16_t v3; // si
  int16_t v4; // di
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int i; // edx
  int result; // eax
  int v10; // [esp+0h] [ebp-4h]

  v3 = a1;
  v4 = a2;
  v10 = 361 * a1;
  memset(361 * a1 + dword_192B18, 0, 361);
  v5 = dword_1930D4 + 17 * a2;
  v6 = v10 + dword_192B18;
  *(_WORD *)v5 = v3;
  *(_WORD *)(v6 + 4) = -1;
  *(_WORD *)(v6 + 2) = v4;
  *(_BYTE *)v6 = a3;
  v7 = dword_19306C + 113 * *(uint8_t *)(v5 + 2);
  *(_BYTE *)(v7 + 51) |= 1 << a3;
  for ( i = 0; i != 14; *(_WORD *)(i + v10 + dword_192B18 + 275) = -1 )
  {
    i += 2;
    result = v10 + dword_192B18;
  }
  *(_BYTE *)(result + 303) = 4;
  *(_WORD *)(result + 291) = -1;
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (00012E08) --------------------------------------------------------
int __fastcall sub_12E08( int a1, int a2)
{
  char *v2; // eax
  char *v3; // edi
  int v4; // eax
  char v5; // bl
  int v6; // eax
  int v7; // edx
  int16_t v8; // bx
  int v9; // eax
  int16_t v10; // dx
  char v11; // dl
  int v12; // eax
  int v13; // ebx
  int v14; // edx
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // ebx
  int v19; // edx
  int v20; // eax
  int v21; // ebx
  char v22; // dl
  char v23; // dl
  int result; // eax
  char v26[8]; // [esp+4h] [ebp-8h] BYREF

  itoa(word_199994, v26, 10, a2);
  v2 = (char *)(dword_197F9C + 129 * word_199994);
  strcpy(v2, "Ship No:");
  v3 = v2 - 1;
  do
    ++v3;
  while ( *v3 );
  strcpy(v3, v26);
  v4 = dword_197F9C + 129 * word_199994;
  *(_BYTE *)(v4 + 100) = 0;
  *(_WORD *)(v4 + 101) = a2;
  *(_BYTE *)(v4 + 99) = a1;
  v5 = sub_1247A0(5u);
  v6 = dword_197F9C + 129 * word_199994;
  *(_BYTE *)(v6 + 16) = v5 - 1;
  v7 = dword_19306C + 113 * a2;
  *(_WORD *)(v6 + 103) = *(_WORD *)(v7 + 15);
  *(_WORD *)(v6 + 105) = *(_WORD *)(v7 + 17);
  v8 = sub_1247A0(0x79u);
  v9 = 129 * word_199994 + dword_197F9C;
  *(_WORD *)(v9 + 114) = v8 - 1;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 2237) )
  {
    if ( *(int16_t *)(v9 + 114) <= 20 )
      v10 = 20;
    else
      v10 = *(_WORD *)(v9 + 114);
    *(_WORD *)(dword_197F9C + 129 * word_199994 + 114) = v10;
  }
  v11 = sub_75999(*(_WORD *)(dword_197F9C + 129 * word_199994 + 114), dword_197F9C);
  v12 = 129 * word_199994;
  v13 = dword_197F9C;
  *(_BYTE *)(dword_197F9C + v12 + 18) = 1;
  *(_BYTE *)(v13 + v12 + 19) = 2;
  *(_BYTE *)(v13 + v12 + 21) = 1;
  *(_BYTE *)(v13 + v12 + 22) = 1;
  *(_WORD *)(v13 + v12 + 116) = -1;
  *(_WORD *)(v13 + v12 + 28) = 3;
  *(_BYTE *)(v13 + v12 + 30) = 3;
  *(_BYTE *)(v13 + v12 + 32) = 1;
  *(_WORD *)(v13 + v12 + 33) = 64;
  *(_WORD *)(v13 + v12 + 36) = 14;
  *(_BYTE *)(v13 + v12 + 38) = 5;
  *(_BYTE *)(v13 + v12 + 43) = 5;
  *(_BYTE *)(v13 + v12 + 40) = 15;
  *(_WORD *)(v13 + v12 + 41) = 0;
  *(_BYTE *)(v13 + v12 + 113) = v11;
  v14 = 2;
  do
  {
    v15 = 129 * word_199994 + dword_197F9C;
    v16 = (int16_t)v14;
    *(_WORD *)(v15 + 8 * (int16_t)v14 + 28) = 0;
    *(_BYTE *)(v15 + 8 * (int16_t)v14 + 30) = 0;
    *(_BYTE *)(v15 + 8 * (int16_t)v14++ + 32) = 1;
    *(_WORD *)(v15 + 8 * v16 + 33) = 64;
  }
  while ( (int16_t)v14 < 8 );
  v17 = 0;
  do
  {
    v18 = (int16_t)v17++;
    *(_BYTE *)(dword_197F9C + 129 * word_199994 + v18 + 23) = 0;
  }
  while ( (int16_t)v17 < 5 );
  v19 = 0;
  do
  {
    v20 = dword_197F9C + 129 * word_199994;
    v21 = (int16_t)v19++;
    *(_BYTE *)(v21 + v20 + 118) = 0;
  }
  while ( (int16_t)v19 < 5 );
  *(_WORD *)(v20 + 123) = 0;
  *(_WORD *)(v20 + 125) = 0;
  v22 = 8 * *(_BYTE *)(v20 + 16);
  v23 = sub_1247A0(8u) - 1 + v22;
  result = 129 * word_199994++;
  *(_BYTE *)(dword_197F9C + result + 92) = v23;
  return result;
}
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (0001307F) --------------------------------------------------------
void sub_1307F()
{
  _DWORD *v0; // eax
  int16_t *v1; // edi
  int16_t v2; // si
  int v3; // edx
  int v4; // ebx
  int v5; // eax
  int v6; // [esp-4h] [ebp-18h]
  _DWORD v7[5]; // [esp+0h] [ebp-14h] BYREF

  sub_7AAD3(v7);
  v0 = sub_126BDD((int)v7, 0, dword_192ED4, 0, 0x43u, 59);
  v6 = dword_1930DC;
  qmemcpy((void *)dword_1930DC, v0, 0xF71u);
  v1 = (int16_t *)v6;
  v2 = 0;
  while ( 1 )
  {
    switch ( v2 )
    {
      case ')':
        sub_93EB2((_DWORD *)(dword_1930DC + 2461), (_DWORD *)(dword_1930DC + 2457), 2, 5, 1);
        break;
      case '4':
        sub_93EB2((_DWORD *)(dword_1930DC + 3110), (_DWORD *)(dword_1930DC + 3106), 1, 5, 1);
        break;
      case 'A':
        *(_BYTE *)(dword_1930DC + 3881) = sub_1247A0(0x66u) - 1;
        *(_BYTE *)(dword_1930DC + 3882) = sub_1247A0(0x66u) + 101;
        break;
    }
    v3 = 59 * v2;
    v4 = sub_946B7(v2);
    v5 = dword_1930DC;
    ++v2;
    *(_WORD *)(v3 + dword_1930DC + 50) = v4;
    sub_FE8BE(v5, v3, v4, v1);
    if ( v2 >= 67 )
      JUMPOUT(0x123C7);
  }
}
// 1316F: control flows out of bounds to 123C7
// 192ED4: using guessed type int dword_192ED4;
// 1930DC: using guessed type int dword_1930DC;


//----- (00013174) --------------------------------------------------------
int __usercall sub_13174(int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v3 = sub_131C2(a3);
  sub_FE8BE(v3, a1, a2, a3);
  v4 = sub_BBC16();
  sub_FE8BE(v4, a1, a2, a3);
  sub_5E1E3(v5, a1, a2, a3);
  sub_FE8BE(v6, a1, a2, a3);
  v7 = sub_111499(dword_192EF4);
  dword_192ED4 = (int)sub_110D3C(dword_192EF4, v7 - 12);
  return memset(dword_192ED4 + 12, 0, 20);
}
// 1318A: variable 'v5' is possibly undefined
// 1318F: variable 'v6' is possibly undefined
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 192ED4: using guessed type int dword_192ED4;
// 192EF4: using guessed type int dword_192EF4;


//----- (000131C2) --------------------------------------------------------
int __usercall sub_131C2(int16_t *a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // ebx
  int16_t v9; // cx
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // esi
  _DWORD *v14; // eax
  int v15; // esi
  int v16; // ebx
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // ecx
  int v21; // edi
  _DWORD *v22; // eax
  int v23; // ecx
  int v24; // esi
  int16_t v25; // si
  int v26; // ecx
  _DWORD *v27; // eax
  int v28; // edi
  int16_t i; // [esp+0h] [ebp-8h]
  int v31; // [esp+4h] [ebp-4h]

  sub_111499(dword_192EF4);
  dword_192EEC = (int)sub_126B42((int)aBuffer0Lbx, 1, dword_192EF4);
  dword_192E7C = (int)sub_126B42((int)aBuffer0Lbx, 2, dword_192EF4);
  dword_192F10 = (int)sub_126B42((int)aBuffer0Lbx, 3, dword_192EF4);
  dword_1932C8 = (int)sub_126B42((int)aBuffer0Lbx, 4, dword_192EF4);
  dword_192ED8 = (int)sub_126B42((int)aBuffer0Lbx, 5, dword_192EF4);
  dword_192EF8 = (int)sub_126B42((int)aBuffer0Lbx, 6, dword_192EF4);
  dword_192F00 = (int)sub_126B42((int)aBuffer0Lbx, 7, dword_192EF4);
  dword_1932A8 = (int)sub_126B42((int)aBuffer0Lbx, 8, dword_192EF4);
  dword_192E8C = (int)sub_126B42((int)aBuffer0Lbx, 9, dword_192EF4);
  dword_192EC4 = (int)sub_126B42((int)aBuffer0Lbx, 10, dword_192EF4);
  dword_19340C = (int)sub_126B42((int)aBuffer0Lbx, 11, dword_192EF4);
  dword_1933F0 = (int)sub_126B42((int)aBuffer0Lbx, 12, dword_192EF4);
  v1 = 0;
  do
  {
    v2 = 0;
    do
      ++v2;
    while ( (int16_t)v2 < 4 );
    ++v1;
  }
  while ( (int16_t)v1 < 4 );
  v3 = 0;
  do
    ++v3;
  while ( (int16_t)v3 < 8 );
  v4 = 0;
  do
    ++v4;
  while ( (int16_t)v4 < 8 );
  sub_111499(dword_192EF4);
  v5 = 0;
  do
    ++v5;
  while ( (int16_t)v5 < 5 );
  v6 = dword_192EF4;
  dword_193080 = (int)sub_126B42((int)aBuffer0Lbx, 82, dword_192EF4);
  sub_FE8BE(dword_193080, 82, v6, a1);
  sub_111499(dword_192EF4);
  dword_1930A8 = 0;
  dword_193294 = (int)sub_126B42((int)aBuffer0Lbx, 58, dword_192EF4);
  v7 = sub_126B42((int)aBuffer0Lbx, 59, dword_192EF4);
  v8 = dword_192EF4;
  dword_1932A4 = (int)v7;
  dword_19328C = (int)sub_126B42((int)aBuffer0Lbx, 60, dword_192EF4);
  sub_FE8BE(dword_19328C, 61, v8, a1);
  dword_193284 = (int)sub_126B42((int)aBuffer0Lbx, 61, dword_192EF4);
  dword_1932A0 = (int)sub_126B42((int)aBuffer0Lbx, 62, dword_192EF4);
  dword_1932C0 = (int)sub_126B42((int)aBuffer0Lbx, 63, dword_192EF4);
  dword_193290 = (int)sub_126B42((int)aBuffer0Lbx, 64, dword_192EF4);
  dword_1932B4 = (int)sub_126B42((int)aBuffer0Lbx, 65, dword_192EF4);
  dword_193278 = (int)sub_126B42((int)aBuffer0Lbx, 66, dword_192EF4);
  dword_1932C4 = (int)sub_126B42((int)aBuffer0Lbx, 67, dword_192EF4);
  dword_19329C = (int)sub_126B42((int)aBuffer0Lbx, 68, dword_192EF4);
  dword_1932B8 = (int)sub_126B42((int)aBuffer0Lbx, 69, dword_192EF4);
  dword_193280 = (int)sub_126B42((int)aBuffer0Lbx, 70, dword_192EF4);
  dword_193288 = (int)sub_126B42((int)aBuffer0Lbx, 71, dword_192EF4);
  v9 = 205;
  dword_1931B8 = (int)sub_126B42((int)aBuffer0Lbx, 72, dword_192EF4);
  v10 = 0;
  sub_111499(dword_192EF4);
  do
  {
    v11 = 0;
    do
    {
      ++v11;
      ++v9;
    }
    while ( (int16_t)v11 < 4 );
    ++v10;
  }
  while ( (int16_t)v10 < 8 );
  v12 = 0;
  do
  {
    ++v12;
    ++v9;
  }
  while ( (int16_t)v12 < 4 );
  for ( i = 0; i < 6; ++i )
  {
    v31 = 0;
    do
    {
      v13 = (int16_t)v31;
      v14 = sub_126B42((int)aBuffer0Lbx, v9, dword_192EF4);
      ++v31;
      v15 = 16 * i + 4 * v13;
      v16 = dword_192EF4;
      v17 = v9;
      *(int *)((char *)dword_190518 + v15) = (int)v14;
      ++v9;
      *(int *)((char *)dword_190598 + v15) = (int)sub_126B42((int)aBuffer0Lbx, v17, v16);
    }
    while ( (int16_t)v31 < 4 );
  }
  sub_111499(dword_192EF4);
  v18 = 0;
  do
  {
    v19 = 0;
    do
      ++v19;
    while ( (int16_t)v19 < 6 );
    ++v18;
  }
  while ( (int16_t)v18 < 6 );
  v20 = 0;
  do
    ++v20;
  while ( (int16_t)v20 < 21 );
  word_19996E = 33;
  word_199954 = 33;
  v21 = 1;
  sub_FE8BE(v18, v17, v16, (int16_t *)1);
  v23 = 0;
  do
  {
    sub_FE8BE((int)v22, v17, v16, (int16_t *)v21);
    v16 = dword_192EF4;
    v17 = (int16_t)v21;
    v22 = sub_126B42((int)aGstarLbx, (int16_t)v21, dword_192EF4);
    v24 = (int16_t)v23;
    ++v21;
    ++v23;
    dword_197490[v24] = (int)v22;
  }
  while ( (int16_t)v23 < 11 );
  v25 = 265;
  v26 = 0;
  dword_19D214 = (int)sub_110D3C(dword_192EF4, 220);
  do
  {
    v27 = sub_126B42((int)aBuffer0Lbx, v25, dword_192EF4);
    v28 = (int16_t)v26;
    ++v25;
    ++v26;
    dword_19C128[v28] = (int)v27;
  }
  while ( (int16_t)v26 < 8 );
  return sub_111499(dword_192EF4);
}
// 135D7: variable 'v22' is possibly undefined
// 190518: using guessed type int dword_190518[32];
// 190598: using guessed type int dword_190598[24];
// 192E7C: using guessed type int dword_192E7C;
// 192E8C: using guessed type int dword_192E8C;
// 192EC4: using guessed type int dword_192EC4;
// 192ED8: using guessed type int dword_192ED8;
// 192EEC: using guessed type int dword_192EEC;
// 192EF4: using guessed type int dword_192EF4;
// 192EF8: using guessed type int dword_192EF8;
// 192F00: using guessed type int dword_192F00;
// 192F10: using guessed type int dword_192F10;
// 193080: using guessed type int dword_193080;
// 1930A8: using guessed type int dword_1930A8;
// 1931B8: using guessed type int dword_1931B8;
// 193278: using guessed type int dword_193278;
// 193280: using guessed type int dword_193280;
// 193284: using guessed type int dword_193284;
// 193288: using guessed type int dword_193288;
// 19328C: using guessed type int dword_19328C;
// 193290: using guessed type int dword_193290;
// 193294: using guessed type int dword_193294;
// 19329C: using guessed type int dword_19329C;
// 1932A0: using guessed type int dword_1932A0;
// 1932A4: using guessed type int dword_1932A4;
// 1932A8: using guessed type int dword_1932A8;
// 1932B4: using guessed type int dword_1932B4;
// 1932B8: using guessed type int dword_1932B8;
// 1932C0: using guessed type int dword_1932C0;
// 1932C4: using guessed type int dword_1932C4;
// 1932C8: using guessed type int dword_1932C8;
// 1933F0: using guessed type int dword_1933F0;
// 19340C: using guessed type int dword_19340C;
// 197490: using guessed type int dword_197490[62];
// 199954: using guessed type int16_t word_199954;
// 19996E: using guessed type int16_t word_19996E;
// 19C128: using guessed type int dword_19C128[8];
// 19D214: using guessed type int dword_19D214;


//----- (00013652) --------------------------------------------------------
int sub_13652()
{
  int v0; // ebx
  _DWORD *v1; // esi
  int result; // eax
  _BYTE *v3; // edx
  int v4; // ecx

  v0 = 1;
  v1 = sub_126AFD((int)aRacestufLbx_0, (int16_t)((uint8_t)byte_199CAE + 8), dword_19A00C);
  dword_192190[0] = (int)v1;
  result = 0;
  do
  {
    while ( *((_BYTE *)v1 + (int16_t)result) )
      ++result;
    while ( 1 )
    {
      v3 = (char *)v1 + (int16_t)result;
      if ( *v3 )
        break;
      ++result;
    }
    v4 = (int16_t)v0++;
    dword_192190[v4] = (int)v3;
  }
  while ( (int16_t)v0 < 32 );
  return result;
}
// 192190: using guessed type int dword_192190[31];
// 199CAE: using guessed type char byte_199CAE;
// 19A00C: using guessed type int dword_19A00C;


//----- (000136B3) --------------------------------------------------------
int16_t __usercall sub_136B3(
        int a1,
        int a2,
        int a3,
        int a4,
        int16_t *a5, int a6)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int i; // edx
  int16_t result; // ax

  if ( (uint8_t)byte_199F3A <= 1u )
  {
    a1 = 1;
    sub_1191CA((int)nullsub_15, 1);
  }
  sub_EEB3A();
  if ( byte_199CAF && !byte_1991B0 )
    sub_63D92((int16_t)a5);
  sub_DCBB0();
  sub_D3D34(v6, (uint16_t)a5);
  sub_1FFED();
  sub_1FD80();
  sub_5090C();
  sub_252A7(a4);
  sub_4DD6B();
  sub_D7439();
  v8 = sub_CFCB6(v7, a1, a3, a5);
  sub_D6F67(v8, a5);
  sub_DBB29(a5);
  sub_E67F6();
  sub_DCA69();
  sub_EDF92((uint16_t)a5);
  sub_FD81C();
  sub_101E77();
  sub_FFEEA();
  sub_10192B();
  sub_E4F49(a5);
  sub_E3FDC((uint16_t)a5);
  sub_E4DC9();
  sub_D574D(v9, a1);
  sub_E9D62(a2, a5);
  sub_2230A(a6);
  sub_14A27();
  sub_206A2((uint16_t)a5);
  sub_ED8BF((uint16_t)a5);
  sub_E2B31(v10, (uint16_t)a5);
  sub_E5097();
  v11 = sub_FF212();
  sub_E2B31(v11, (uint16_t)a5);
  sub_10011B();
  sub_92FDA();
  sub_934CF((uint16_t)a5);
  sub_ED44A();
  sub_580F5();
  v12 = sub_E64F4();
  sub_EB192(v12);
  sub_50B57();
  sub_10087D();
  sub_4EB06();
  sub_4DAB2();
  if ( !byte_199F3A && !byte_1ACE74 )
    sub_168AF(a5);
  for ( i = 0; i < word_199998; ++i )
    sub_97A66(i);
  sub_EF827();
  if ( !IsMemPoolReady_110B5C() )
    sub_92C87();
  result = sub_10208A();
  ++dword_192FD8;
  if ( !byte_19C196 )
    return sub_123E6C((int)&unk_17CF00, 1);
  return result;
}
// 136ED: variable 'v6' is possibly undefined
// 13710: variable 'v7' is possibly undefined
// 13751: variable 'v9' is possibly undefined
// 1376F: variable 'v10' is possibly undefined
// FE8D4: using guessed type int __fastcall nullsub_15(_DWORD, _DWORD);
// 192FD8: using guessed type int dword_192FD8;
// 1991B0: using guessed type char byte_1991B0;
// 199998: using guessed type int16_t word_199998;
// 199CAF: using guessed type char byte_199CAF;
// 199F3A: using guessed type char byte_199F3A;
// 19C196: using guessed type char byte_19C196;
// 1ACE74: using guessed type char byte_1ACE74;


//----- (00013822) --------------------------------------------------------
void __fastcall sub_13822(int a1, int a2, int a3, int a4)
{
  uint8_t v4; // al

  v4 = 4;
  if ( byte_199F3A == 2 || byte_199F3A == 3 )
    v4 = 1;
  if ( byte_199BE7 )
  {
    if ( !(dword_192FD8 % v4) )
    {
      strcpy(byte_19980B, "(Auto Save)");
      sub_1160B(9, 0, v4, a4);
    }
  }
}
// 192FD8: using guessed type int dword_192FD8;
// 199BE7: using guessed type char byte_199BE7;
// 199F3A: using guessed type char byte_199F3A;


//----- (00013870) --------------------------------------------------------
int __usercall sub_13870(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int16_t *a6, int a7)
{
  int v7; // eax
  int v8; // eax
  int16_t v9; // bx
  unsigned int v10; // ebx
  int result; // eax
  int v12; // edx

  if ( (uint8_t)byte_199F3A <= 1u )
    sub_13822(a1, a2, a4, a3);
  sub_78E67();
  sub_136B3(a2, a3, a4, a5, a6, a7);
  word_199A08 = word_199A10;
  if ( byte_199F3A != 2 && byte_199F3A != 3 && !byte_1ACE74 )
  {
    if ( (int16_t)sub_E505E() < 1 )
    {
      sub_C5BB9();
      sub_124D41();
      LOBYTE(v7) = sub_128C32(0, 0, 639, 479, 0);
      sub_1077D(v7, 0, 639, a6);
      sub_124DEC();
      sub_124C08();
LABEL_8:
      sub_C6762();
LABEL_9:
      v8 = word_19999C;
LABEL_10:
      sub_9F712(v8, a6);
      word_199A08 = 10;
      goto LABEL_20;
    }
    if ( (int16_t)sub_E502A() <= 1 )
    {
      v9 = sub_139E8();
      sub_C5BB9();
      sub_C671B();
      v8 = v9;
      goto LABEL_10;
    }
    if ( word_19A0E0 != -1 )
    {
      if ( word_19A0E0 == word_19999C )
        goto LABEL_9;
      goto LABEL_8;
    }
    v10 = 3753 * word_199998 + dword_197F98;
    while ( v10 > dword_197F98 )
    {
      v10 -= 3753;
      if ( *(_BYTE *)(v10 + 496) )
      {
        sub_119281();
        sub_C673D();
        sub_9F712((int16_t)((int)(v10 - dword_197F98) / 3753), a6);
        word_199A08 = 10;
      }
    }
  }
LABEL_20:
  for ( result = 0; (int16_t)result < word_199998; ++result )
  {
    v12 = 3753 * (int16_t)result;
    *(_BYTE *)(v12 + dword_197F98 + 45) = 0;
  }
  word_1999E2 = -1;
  return result;
}
// 138F6: variable 'v7' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 1999E2: using guessed type int16_t word_1999E2;
// 199A08: using guessed type int16_t word_199A08;
// 199A10: using guessed type int16_t word_199A10;
// 199F3A: using guessed type char byte_199F3A;
// 19A0E0: using guessed type int16_t word_19A0E0;
// 1ACE74: using guessed type char byte_1ACE74;


//----- (000139E8) --------------------------------------------------------
int sub_139E8()
{
  int v0; // ebx
  int i; // edx
  int v2; // eax

  v0 = -1;
  if ( word_19A0E0 == -1 )
  {
    for ( i = 0; (int16_t)i < word_199998; ++i )
    {
      v2 = 3753 * (int16_t)i + dword_197F98;
      if ( *(_BYTE *)(v2 + 496) || !*(_BYTE *)(v2 + 36) )
        v0 = i;
    }
  }
  else
  {
    LOWORD(v0) = word_19A0E0;
  }
  return v0;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19A0E0: using guessed type int16_t word_19A0E0;


//----- (00013A3D) --------------------------------------------------------
int64_t __fastcall sub_13A3D( int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  char *v8; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // ecx
  int v15; // ebx
  int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // ebx
  char v21; // al
  int v22; // eax
  _BOOL1 v23; // zf
  _BOOL1 v24; // zf
  int v25; // esi
  int v26; // eax
  int v27; // ecx
  int v28; // edx
  int v31; // [esp+Ch] [ebp-18h]
  int v32; // [esp+10h] [ebp-14h]
  int v33; // [esp+14h] [ebp-10h]
  int16_t v34; // [esp+18h] [ebp-Ch]
  char v35; // [esp+1Ch] [ebp-8h]

  v3 = word_199996;
  v4 = 361 * word_199996++;
  v34 = 0;
  memset(dword_192B18 + v4, 0, 361);
  if ( byte_182978 )
  {
    _wcpp_1_unwind_leave(0, 0, "INITING HOMEWORLD ph:%d pl:%d num:%d", a1, a2, word_199996);
    sub_6497C();
  }
  sub_12D75(v3, a1, a2);
  sub_BB16A(v3);
  v5 = dword_1930D4 + 17 * a1;
  v6 = 113 * *(uint8_t *)(v5 + 2) + dword_19306C;
  v7 = 361 * v3;
  *(_BYTE *)(v6 + 51) |= 1 << a2;
  v8 = (char *)(361 * v3 + dword_192B18);
  v8[226] = *(_BYTE *)(v5 + 8);
  v32 = (int16_t)sub_E0C1D(v8, a2);
  if ( byte_199CB5 == 2 )
  {
    v9 = 6 * v32 * (*(char *)(dword_197F98 + 3753 * a2 + 2208) + 300) / 3000;
    v10 = v7 + dword_192B18;
    *(_BYTE *)(v7 + dword_192B18 + 10) = v9;
    if ( v32 <= 8 )
      *(_BYTE *)(v10 + 10) = (v32 + (uint8_t)v9) / 2;
    v11 = dword_192B18 + 361 * v3;
    if ( !*(_BYTE *)(v11 + 10) )
      *(_BYTE *)(v11 + 10) = 1;
    if ( a3 )
    {
      v12 = dword_192B18 + 361 * v3;
      if ( *(_BYTE *)(v12 + 10) < 8u )
        *(_BYTE *)(v12 + 10) = 8;
    }
  }
  else
  {
    *(_BYTE *)(v7 + dword_192B18 + 10) = 8;
  }
  v13 = 0;
  v33 = 0;
  v14 = 361 * v3;
  while ( 1 )
  {
    v18 = v14 + dword_192B18;
    if ( v13 >= *(uint8_t *)(v14 + dword_192B18 + 10) )
      break;
    if ( !*(_BYTE *)(dword_1930D4 + 17 * a1 + 11) || *(_BYTE *)(3753 * a2 + dword_197F98 + 2225) )
    {
      v16 = v14 + dword_192B18 + v33;
      *(_WORD *)(v16 + 12) &= 0xFE7Fu;
      *(_DWORD *)(v16 + 12) |= (((uint8_t)(v13 % 2) + 1) & 3) << 7;
    }
    else
    {
      v15 = v18 + v33;
      *(_WORD *)(v15 + 12) &= 0xFE7Fu;
      *(_DWORD *)(v15 + 12) |= ((v13 % 3) & 3) << 7;
    }
    v17 = v33 + v14 + dword_192B18;
    *(_BYTE *)(v17 + 12) &= 0xF0u;
    *(_DWORD *)(v17 + 12) |= a2 & 0xF;
    *(_BYTE *)(v17 + 12) &= 0x8Fu;
    ++v13;
    *(_DWORD *)(v17 + 12) |= 16 * (a2 & 7);
    v33 += 4;
    *(_BYTE *)(v17 + 13) &= 0xF9u;
    *(_BYTE *)(v17 + 13) |= 2u;
  }
  memset(v18 + 310, 0, 49);
  if ( *(char *)(dword_197F98 + 3753 * *(char *)(v14 + dword_192B18) + 2207) < 6 && a3 )
    sub_13FD9(v3, 9u);
  v35 = 0;
  v19 = 0;
  v31 = 361 * v3;
  do
  {
    v20 = word_17D8AC[v19];
    if ( !word_17D8AC[v19]
      || (uint8_t)byte_13A3A[(uint8_t)byte_199CB5] <= v34
      || 3 * v34 / 2 >= *(uint8_t *)(v31 + dword_192B18 + 10) )
    {
      v35 = 1;
      goto LABEL_56;
    }
    sub_E11BC((char *)(v31 + dword_192B18), v20);
    if ( v21 )
    {
      v22 = 1;
      if ( v20 < 0x15 )
      {
        if ( v20 < 0xA )
        {
          if ( v20 != 5 )
            goto LABEL_54;
          goto LABEL_51;
        }
        if ( v20 > 0xA )
        {
          if ( v20 < 0xD )
            goto LABEL_54;
          if ( v20 <= 0xD )
            goto LABEL_51;
          v23 = v20 == 20;
LABEL_39:
          if ( !v23 )
            goto LABEL_54;
          LOBYTE(v22) = *(char *)(dword_197F98 + 3753 * a2 + 2207) / 2 != 3;
LABEL_53:
          v22 = (uint8_t)v22;
          goto LABEL_54;
        }
      }
      else
      {
        if ( v20 <= 0x15 )
        {
LABEL_49:
          v24 = *(_BYTE *)(3753 * a2 + dword_197F98 + 2225) == 0;
LABEL_50:
          LOBYTE(v22) = v24;
          goto LABEL_53;
        }
        if ( v20 >= 0x20 )
        {
          if ( v20 > 0x20 )
          {
            if ( v20 < 0x25 || v20 > 0x25 && v20 != 43 )
            {
LABEL_54:
              if ( v22 )
              {
                ++v34;
                sub_13FD9(v3, v20);
              }
              goto LABEL_56;
            }
            goto LABEL_49;
          }
LABEL_51:
          v24 = *(_BYTE *)(dword_197F98 + 3753 * a2 + 2230) == 0;
          goto LABEL_50;
        }
        if ( v20 < 0x19 )
          goto LABEL_54;
        if ( v20 > 0x19 )
        {
          v23 = v20 == 31;
          goto LABEL_39;
        }
      }
      LOBYTE(v22) = *(uint8_t *)(v31 + dword_192B18 + 10) < v32;
      goto LABEL_53;
    }
LABEL_56:
    ++v19;
  }
  while ( !v35 );
  if ( byte_199CB5 == 1 && a3 )
  {
    *(_BYTE *)(dword_197F9C + 129 * word_199994 + 99) = a2;
    sub_AF7B4(a2, 0, v3);
    *(_BYTE *)(dword_197F9C + 129 * word_199994 + 99) = a2;
    sub_AF7B4(a2, 0, v3);
    *(_BYTE *)(129 * word_199994 + dword_197F9C + 99) = a2;
    sub_564CD(a2, dword_197F98 + 3753 * a2 + 1301);
    sub_AF7B4(a2, 5, v3);
  }
  v25 = 361 * v3;
  v26 = v25 + dword_192B18;
  v27 = dword_1930D4;
  *(_BYTE *)(v26 + 221) = *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(v25 + dword_192B18 + 2) + 11);
  *(_BYTE *)(v26 + 224) = *(_BYTE *)(v27 + 17 * *(int16_t *)(v26 + 2) + 13);
  v28 = 17 * *(int16_t *)(v26 + 2);
  v26 += 231;
  *(_BYTE *)(v26 - 5) = *(_BYTE *)(v27 + v28 + 8);
  *(_WORD *)(v26 + 73) = 3;
  memset(v26, 0, 8);
  return (unsigned int)memset(v25 + dword_192B18 + 239, 0, 4);
}
// 13D21: variable 'v21' is possibly undefined
// FE8D5: using guessed type int _wcpp_1_unwind_leave(_DWORD, _DWORD, char *, ...);
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 17D8AC: using guessed type int16_t word_17D8AC[];
// 182978: using guessed type char byte_182978;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;
// 199996: using guessed type int16_t word_199996;
// 199CB5: using guessed type char byte_199CB5;


//----- (00013FA7) --------------------------------------------------------
int __fastcall sub_13FA7( int a1, int a2)
{
  int v2; // eax

  v2 = sub_13A3D(a1, a2, 1);
  return nullsub_2(v2);
}
// 13FB7: using guessed type int __fastcall nullsub_2(_DWORD);


//----- (00013FB8) --------------------------------------------------------
void sub_13FB8()
{
  JUMPOUT(0x13FB1);
}
// 13FBF: control flows out of bounds to 13FB1


//----- (00013FD9) --------------------------------------------------------
void __fastcall sub_13FD9( int a1, unsigned int a2)
{
  char *v4; // ebx
  int v5; // eax
  int v6; // eax
  int16_t v7; // dx
  int16_t v8; // ax
  uint8_t *v9; // edx
  int16_t *v10; // eax
  char v11; // al
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  char v18; // al
  int v19; // edx
  char v20; // al
  int v21; // eax
  int v22; // eax
  char *v23; // eax
  int v24; // eax
  char *v25; // eax
  int v26; // eax
  int v27; // [esp+8h] [ebp-3Ch]
  int v28; // [esp+Ch] [ebp-38h]
  int v29; // [esp+10h] [ebp-34h]
  int v30; // [esp+14h] [ebp-30h]
  int v31; // [esp+1Ch] [ebp-28h]
  int v32; // [esp+20h] [ebp-24h]
  int v33; // [esp+24h] [ebp-20h]
  int v34; // [esp+28h] [ebp-1Ch]
  int v35; // [esp+2Ch] [ebp-18h]
  int v36; // [esp+30h] [ebp-14h]
  int16_t v37; // [esp+34h] [ebp-10h]
  char v38; // [esp+38h] [ebp-Ch]
  char v39; // [esp+3Ch] [ebp-8h]
  char v40; // [esp+40h] [ebp-4h]

  v4 = (char *)(dword_192B18 + 361 * a1);
  v39 = 1;
  v38 = 0;
  v40 = 0;
  v35 = 3753 * *v4 + dword_197F98;
  if ( a2 < 0x17u )
  {
    if ( a2 >= 0xBu )
    {
      if ( a2 <= 0xBu )
      {
        v5 = dword_19306C
           + 113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + 2);
        *(_BYTE *)(v5 + 53) &= ~(1 << *v4);
        goto LABEL_95;
      }
      if ( a2 < 0xEu )
      {
        if ( a2 != 13 )
          goto LABEL_95;
        if ( v4[342] )
        {
          v21 = dword_17EDA5;
          v4[342] = 0;
          *(_DWORD *)(v35 + 50) += v21;
        }
        sub_B206F(a1, 32);
        if ( v4[315] )
        {
          v22 = dword_17EBA4;
          v4[315] = 0;
          *(_DWORD *)(v35 + 50) += v22;
        }
        v7 = 5;
        v8 = a1;
      }
      else
      {
        if ( a2 <= 0xEu )
          goto LABEL_94;
        if ( a2 < 0x11u )
          goto LABEL_95;
        if ( a2 > 0x11u )
        {
          if ( a2 == 22 )
          {
            v23 = (char *)(dword_192B18 + 361 * a1);
            v4[309] = 0;
            v24 = (int16_t)sub_ED5E7(v23);
            if ( (int16_t)v24 > 4 )
              v24 = 4;
            if ( *((int16_t *)v4 + 152) < v24 )
              *((_WORD *)v4 + 152) = v24;
          }
          goto LABEL_95;
        }
        v6 = dword_1930D4 + 17 * *((int16_t *)v4 + 1);
        if ( v4[226] == 8 )
        {
          *(_BYTE *)(v6 + 8) = 9;
          *(_BYTE *)(v6 + 11) += byte_17D825 - byte_17D824;
        }
        v7 = 44;
        v8 = a1;
        v39 = 0;
      }
      sub_B206F(v8, v7);
      goto LABEL_95;
    }
    if ( a2 < 3u )
    {
      if ( a2 == 2 )
      {
        v25 = (char *)(361 * a1 + dword_192B18);
        v4[308] = 0;
        v26 = (int16_t)sub_ED674(v25);
        if ( (int16_t)v26 > 2 )
          v26 = 2;
        if ( *((int16_t *)v4 + 153) < v26 )
          *((_WORD *)v4 + 153) = v26;
      }
      goto LABEL_95;
    }
    if ( a2 <= 3u )
    {
LABEL_94:
      v38 = 1;
      goto LABEL_95;
    }
    if ( a2 < 8u )
      goto LABEL_95;
    if ( a2 > 8u )
    {
      if ( a2 == 9 )
      {
        *(_WORD *)(dword_197F98 + 3753 * *v4 + 41) = *((_WORD *)v4 + 1);
        v27 = word_199996;
        v31 = 361 * word_199996;
        while ( v27 > 0 )
        {
          --v27;
          v31 -= 361;
          if ( a1 != v27 && *(_BYTE *)(v31 + dword_192B18) == *v4 )
            sub_B206F(v27, 9);
        }
      }
      goto LABEL_95;
    }
LABEL_76:
    v4[350] = 0;
    sub_B206F(a1, 40);
    goto LABEL_77;
  }
  if ( a2 <= 0x17u )
  {
    v4[334] = 0;
    sub_B206F(a1, 24);
    goto LABEL_80;
  }
  if ( a2 < 0x28u )
  {
    if ( a2 >= 0x1Au )
    {
      if ( a2 > 0x1Cu )
      {
        if ( a2 == 37 )
        {
          v12 = dword_1930D4;
          ++*(_BYTE *)(dword_1930D4 + 17 * *((int16_t *)v4 + 1) + 11);
          v39 = 0;
          *(_BYTE *)(v12 + 17 * *((int16_t *)v4 + 1) + 16) |= 2u;
        }
        goto LABEL_95;
      }
LABEL_78:
      v40 = 1;
      goto LABEL_95;
    }
    if ( a2 != 24 )
      goto LABEL_95;
LABEL_80:
    v4[338] = 0;
    sub_B206F(a1, 28);
    goto LABEL_78;
  }
  if ( a2 <= 0x28u )
  {
LABEL_77:
    v38 = 1;
    goto LABEL_78;
  }
  if ( a2 < 0x2Cu )
  {
    if ( a2 > 0x29u )
    {
      if ( a2 != 42 )
        goto LABEL_95;
      goto LABEL_78;
    }
    v4[318] = 0;
    sub_B206F(a1, 8);
    goto LABEL_76;
  }
  if ( a2 <= 0x2Cu )
  {
    v36 = *((int16_t *)v4 + 1);
    v9 = (uint8_t *)(dword_1930D4 + 17 * v36);
    v37 = (uint8_t)v4[226];
    switch ( v4[226] )
    {
      case 2:
        v10 = (int16_t *)(113 * v9[2] + dword_19306C);
        if ( v10[37] == v36 || v10[38] == v36 )
        {
          v9[8] = 3;
        }
        else if ( v10[40] == v36 || v10[41] == v36 )
        {
          v9[8] = 4;
        }
        else
        {
          v9[8] = (sub_1247A0(2u) != 1) + 3;
        }
        break;
      case 3:
        v9[8] = 7;
        break;
      case 4:
        v9[8] = 6;
        break;
      case 5:
      case 6:
      case 7:
        v9[8] = 8;
        break;
      default:
        break;
    }
    v39 = 0;
    v11 = byte_17D81C[v9[8]] - byte_17D81C[v37];
    ++v9[12];
    v9[11] += v11;
    goto LABEL_95;
  }
  if ( a2 <= 0x2Du )
    goto LABEL_94;
  if ( a2 == 48 )
  {
    v28 = -1;
    v32 = 5;
    v29 = 113 * *(uint8_t *)(dword_1930D4 + 17 * *((int16_t *)v4 + 1) + 2) + dword_19306C;
    v30 = v29 + 10;
    while ( v32 > 0 )
    {
      v30 -= 2;
      v14 = *(int16_t *)(v30 + 74);
      --v32;
      if ( v14 != -1 && *(_BYTE *)(dword_1930D4 + 17 * v14 + 4) == 2 )
      {
        v34 = 4;
        v28 = *(int16_t *)(v30 + 74);
        break;
      }
    }
    if ( v28 == -1 )
    {
      v33 = 5;
      v13 = v29 + 10;
      while ( v33 > 0 )
      {
        --v33;
        v15 = *(int16_t *)(v13 + 72);
        v13 -= 2;
        if ( v15 != -1 && *(_BYTE *)(dword_1930D4 + 17 * v15 + 4) == 1 )
        {
          v34 = 3;
          v28 = v15;
          break;
        }
      }
    }
    if ( v28 != -1 )
    {
      v16 = 17 * v28;
      v17 = dword_1930D4;
      *(_BYTE *)(v16 + dword_1930D4 + 4) = 3;
      *(_BYTE *)(v16 + v17 + 6) = 1;
      *(_BYTE *)(v16 + v17 + 7) = 0;
      *(_BYTE *)(v16 + v17 + 5) = v34;
      *(_BYTE *)(v16 + v17 + 8) = 2;
      v18 = sub_1247A0(3u);
      v19 = dword_1930D4;
      *(_BYTE *)(v16 + dword_1930D4 + 10) = 2;
      *(_BYTE *)(v16 + v19 + 11) = 0;
      *(_BYTE *)(v16 + v19 + 9) = v18 - 1;
      *(_BYTE *)(v16 + v19 + 12) = 0;
      *(_BYTE *)(v16 + v19 + 13) = byte_17D7FC[v34];
      v20 = byte_17D806[v34];
      *(_BYTE *)(v16 + v19 + 16) = 0;
      *(_BYTE *)(v16 + v19 + 14) = v20;
    }
    v39 = 0;
  }
LABEL_95:
  if ( v39 )
    v4[(int16_t)a2 + 310] = 1;
  if ( v38 )
  {
    sub_E5296((_BYTE *)(113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(361 * a1 + dword_192B18 + 2) + 2)
                      + dword_19306C));
    if ( a2 == 45 )
      sub_10041C(*v4);
  }
  if ( v40 )
    *(_BYTE *)(dword_19306C
             + 113 * *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + 2)
             + 54) = 0;
}
// 143D9: variable 'v34' is possibly undefined
// 17D824: using guessed type char byte_17D824;
// 17D825: using guessed type char byte_17D825;
// 17EBA4: using guessed type int dword_17EBA4;
// 17EDA5: using guessed type int dword_17EDA5;
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199996: using guessed type int16_t word_199996;


//----- (000145EA) --------------------------------------------------------
void __usercall sub_145EA( int a1, unsigned int a2, int a3)
{
  int v5; // edx
  char *v6; // eax
  _BOOL1 v7; // zf
  int j; // esi
  int v9; // eax
  int v10; // edx
  int i; // ebx
  int v12; // eax
  int v13; // esi

  v5 = a1;
  v6 = (char *)(dword_192B18 + 361 * a1);
  v6[(int16_t)a2 + 310] = 0;
  if ( a2 >= 0xFu )
  {
    if ( a2 > 0xFu )
    {
      if ( a2 < 0x1Cu )
      {
        if ( a2 < 0x16u )
          goto LABEL_38;
        if ( a2 <= 0x16u )
        {
          for ( i = 0; (int16_t)i < 7; ++i )
          {
            v12 = *(int16_t *)(361 * a1 + dword_192B18 + 2 * (int16_t)i + 277);
            if ( v12 <= -100 && *(_BYTE *)(-129 * (v12 + 100) + dword_197F9C + 17) == 2 )
              sub_B1E19(a1, i--);
          }
LABEL_38:
          JUMPOUT(0x145E4);
        }
        if ( a2 > 0x18u )
          goto LABEL_38;
      }
      else if ( a2 > 0x1Cu )
      {
        if ( a2 < 0x28u )
          goto LABEL_38;
        if ( a2 > 0x29u )
        {
          v7 = a2 == 45;
          goto LABEL_8;
        }
LABEL_20:
        for ( j = 0; (int16_t)j < 7; ++j )
        {
          v9 = *(int16_t *)(2 * (int16_t)j + dword_192B18 + 361 * a1 + 277);
          if ( v9 <= -100 && *(_BYTE *)(-129 * (v9 + 100) + dword_197F9C + 16) >= 2u )
            sub_B1E19(a1, j--);
        }
LABEL_26:
        v10 = 361 * a1;
        sub_E5296((_BYTE *)(dword_19306C
                          + 113 * *(uint8_t *)(17 * *(int16_t *)(v10 + dword_192B18 + 2) + dword_1930D4 + 2)));
        if ( a2 == 45 )
          sub_10041C(*(char *)(v10 + dword_192B18));
        goto LABEL_38;
      }
      if ( *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * a1 + 2) + 8) < 2u )
        sub_B206F(a1, 44);
    }
    v13 = 361 * a1;
    sub_E1CED((char *)(v13 + dword_192B18));
    sub_EC97C((char *)(v13 + dword_192B18));
    sub_E2A70(a1, a3);
    goto LABEL_38;
  }
  if ( a2 < 8u )
  {
    v7 = a2 == 3;
  }
  else
  {
    if ( a2 <= 8u )
      goto LABEL_20;
    if ( a2 <= 9u )
    {
      sub_ECB65(*v6, v5);
      goto LABEL_38;
    }
    v7 = a2 == 14;
  }
LABEL_8:
  if ( !v7 )
    goto LABEL_38;
  goto LABEL_26;
}
// 14640: control flows out of bounds to 145E4
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (000147D7) --------------------------------------------------------
int __fastcall sub_147D7(int a1)
{
  if ( byte_199BED )
    return sub_112399(a1);
  else
    return 0;
}
// 199BED: using guessed type char byte_199BED;


//----- (000147E7) --------------------------------------------------------
int __fastcall sub_147E7( int a1)
{
  int v2; // ecx
  int16_t v3; // ax
  int v4; // esi
  char v5; // cl
  int result; // eax

  v2 = 129 * a1;
  v3 = 0;
  v4 = 0;
  do
  {
    if ( word_17D176[4 * v3] <= *(int16_t *)(dword_197F9C + 129 * a1 + 114) )
      ++v3;
    ++v4;
  }
  while ( (int16_t)v4 < 4 );
  if ( *(_BYTE *)(3753 * *(char *)(v2 + dword_197F9C + 99) + dword_197F98 + 2237) )
    ++v3;
  if ( v3 <= 5 )
    v5 = v3;
  else
    v5 = 5;
  result = dword_197F9C;
  *(_BYTE *)(129 * a1 + dword_197F9C + 113) = v5;
  return result;
}
// 17D176: using guessed type int16_t word_17D176[4];
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;


//----- (0001487A) --------------------------------------------------------
void __fastcall sub_1487A( int a1)
{
  int v2; // eax
  int16_t v3; // si
  int16_t i; // dx
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  int16_t v8; // [esp+0h] [ebp-4h]

  v2 = dword_197F9C + 129 * a1;
  if ( !*(_BYTE *)(v2 + 100) )
  {
    v3 = *(char *)(v2 + 99);
    v8 = *(_WORD *)(v2 + 101);
    for ( i = 0; i < 5; ++i )
    {
      v5 = *(int16_t *)(dword_19306C + 113 * v8 + 2 * i + 74);
      if ( v5 > -1 )
      {
        v6 = *(int16_t *)(dword_1930D4 + 17 * v5);
        if ( v6 > -1 )
        {
          v7 = (char *)(361 * v6 + dword_192B18);
          if ( *v7 == v3 )
          {
            if ( v7[348] )
              ++*(_WORD *)(dword_197F9C + 129 * a1 + 114);
          }
        }
      }
    }
  }
  JUMPOUT(0x14874);
}
// 14910: control flows out of bounds to 14874
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F9C: using guessed type int dword_197F9C;


//----- (00014915) --------------------------------------------------------
int __fastcall sub_14915(int a1)
{
  int16_t i; // di
  int result; // eax
  int16_t v3; // dx
  int v4; // ecx
  char v5; // al
  int16_t v6; // bx
  char v7; // al
  int16_t v9; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 67; ++i )
  {
    result = dword_1930DC + 59 * i;
    v3 = *(char *)(result + 58);
    if ( *(_BYTE *)(result + 35) == 1 && *(char *)(result + 57) >= 0 && !*(_BYTE *)(result + 55) )
    {
      v4 = *(char *)(result + 58);
      if ( v4 > -1 && v3 < 8 )
      {
        v9 = 0;
        sub_9469E();
        if ( v5 )
        {
          v6 = 22;
        }
        else
        {
          sub_9469E();
          if ( !v7 )
            goto LABEL_12;
          v6 = 23;
        }
        v9 = sub_94BB2(v4, i, v6);
LABEL_12:
        result = a1 + 2 * v3;
        if ( v9 > *(int16_t *)result )
          *(_WORD *)result = v9;
        continue;
      }
    }
  }
  return result;
}
// 14983: variable 'v5' is possibly undefined
// 1499C: variable 'v7' is possibly undefined
// 1930DC: using guessed type int dword_1930DC;


//----- (000149D5) --------------------------------------------------------
int __fastcall sub_149D5( int a1, int a2)
{
  int v4; // edx
  int v5; // eax

  v4 = a1;
  sub_1487A(a1);
  v5 = a2 + *(int16_t *)(dword_197F9C + 129 * v4 + 114) + 1;
  if ( v5 > word_17D186 )
    LOWORD(v5) = word_17D186;
  *(_WORD *)(129 * a1 + dword_197F9C + 114) = v5;
  return sub_147E7(a1);
}
// 17D186: using guessed type int16_t word_17D186;
// 197F9C: using guessed type int dword_197F9C;


//----- (00014A27) --------------------------------------------------------
unsigned int sub_14A27()
{
  int16_t v0; // cx
  unsigned int result; // eax
  int16_t v2; // ax
  _WORD v3[8]; // [esp+0h] [ebp-10h] BYREF

  memset(v3, 0, sizeof(v3));
  v0 = 0;
  sub_14915((int)v3);
  do
  {
    result = dword_197F9C + 129 * v0;
    if ( *(char *)(result + 100) < 5 )
    {
      result = *(char *)(result + 99);
      if ( result < 8 )
      {
        v2 = sub_77FF5(v0);
        result = sub_149D5(v0, v3[v2]);
      }
    }
    ++v0;
  }
  while ( v0 < 500 );
  return result;
}
// 129C70: using guessed type int __fastcall memset(_DWORD, _DWORD, _DWORD);
// 197F9C: using guessed type int dword_197F9C;


//----- (00014AAC) --------------------------------------------------------
int __usercall sub_14AAC( int a1, int16_t *a2)
{
  int16_t v3; // si
  unsigned int v4; // edx
  int v5; // eax
  int v6; // eax

  sub_11C2F0();
  sub_1196F7();
  sub_1172FC();
  sub_128BE7();
  sub_12B65C();
  sub_123E6C((int)&unk_180164, 1);
  sub_24677(120, -1, 1);
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
  sub_11C2F0();
  sub_124C08();
  sub_107AF(&dword_19ABA0);
  sub_119281();
  sub_11C2F0();
  sub_14C83();
  sub_14D7C(1 - a1);
  v3 = 0;
  sub_1191CA((int)sub_14BFD, 2);
  while ( !v3 )
  {
    sub_12C2A0();
    sub_11C2F0();
    v4 = sub_11438B(0, 0, 639, 479, &unk_178A08, 0);
    if ( (uint16_t)sub_1171AB(v4, v4, 639, 479) == (_WORD)v4 || (LOBYTE(v5) = sub_12C392(), v5 == 1) )
      v3 = 1;
    if ( !v3 )
    {
      v6 = sub_14BFD();
      sub_1077D(v6, v4, 639, a2);
      sub_12C2C6(2);
    }
  }
  byte_199F2D = 1;
  sub_119281();
  sub_11C2F0();
  sub_12D78E();
  sub_123E6C((int)&unk_180164, 1);
  sub_2484F();
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
  sub_FE8C8(dword_192ED4, 1);
  return sub_107BA(&dword_19ABA0);
}
// 14B82: variable 'v5' is possibly undefined
// 192ED4: using guessed type int dword_192ED4;
// 199F2D: using guessed type char byte_199F2D;
// 19ABA0: using guessed type int dword_19ABA0;


//----- (00014BFD) --------------------------------------------------------
int sub_14BFD()
{
  sub_124D41();
  sub_120DED(250, 250);
  if ( byte_199BE2 == 1 )
    sub_12CD2D();
  sub_120DED(0, 250);
  sub_120D79(4, (int)&unk_180170);
  sub_103952(550, dword_19A014, 550);
  sub_103915(2);
  return sub_24677(120, -1, 1);
}
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 103952: using guessed type int __fastcall sub_103952(_DWORD, _DWORD, _DWORD);
// 199BE2: using guessed type char byte_199BE2;
// 19A014: using guessed type int dword_19A014;


//----- (00014C83) --------------------------------------------------------
int16_t sub_14C83()
{
  _DWORD *v0; // ecx
  int v1; // eax
  _DWORD *v2; // eax

  dword_19A010 = (int)sub_110CEE(dword_192ED4, 917);
  v0 = sub_126B42((int)aAntaroomLbx, 0, dword_192ED4);
  sub_12E332(0);
  sub_12D8F5(30, 30, dword_19A010);
  sub_12F578(dword_19A010, (int)v0);
  sub_124D41();
  sub_12B79D((int)v0);
  sub_1318D4(0, 255);
  sub_128C32(0, 0, 639, 479, 0);
  dword_19A014 = (int)sub_110D3C(dword_192ED4, 210);
  v1 = sub_111499(dword_192ED4);
  v2 = sub_110D3C(dword_192ED4, v1 - 100);
  sub_12D7B7((int)v2);
  sub_124C08();
  sub_12C607((int)aAntaroomLbx, 1, 639, 0);
  sub_124D41();
  sub_12C7CC();
  sub_131F7B();
  sub_124DEC();
  sub_12E1E0(0, 0, (int16_t *)dword_19A010, 0);
  return sub_123E6C((int)&unk_17CF00, 1);
}
// 192ED4: using guessed type int dword_192ED4;
// 19A010: using guessed type int dword_19A010;
// 19A014: using guessed type int dword_19A014;


//----- (00014D7C) --------------------------------------------------------
char __fastcall sub_14D7C( int a1)
{
  int16_t v2; // ax
  char result; // al
  char v4[200]; // [esp+0h] [ebp-C8h] BYREF

  v2 = sub_1247A0(4u);
  sub_126C91((int)aAntarmsgLbx, (int16_t)(v2 - 1 + 8 * (uint8_t)byte_199CAE + 4 * a1), (int)v4, 0, 1u, 200);
  strcpy((char *)dword_19A014, v4);
  return result;
}
// 199CAE: using guessed type char byte_199CAE;
// 19A014: using guessed type int dword_19A014;


//----- (00014DF7) --------------------------------------------------------
void __fastcall sub_14DF7(int a1, int a2, int a3)
{
  int64_t v5; // rax
  _BOOL1 v6; // cf
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int v10; // eax

  sub_127969();
  sub_124D41();
  sub_113C28(25);
  if ( a3 == 1 )
  {
    sub_15085(4);
    sub_123E6C((int)&unk_180178, 1);
  }
  else
  {
    sub_107AF(&dword_19A018);
    sub_119281();
    sub_124C08();
    sub_1172FC();
    sub_11E718();
    sub_124DEC();
  }
  sub_124C9B();
  sub_1191CA((int)sub_150E5, 0);
  sub_11C2F0();
  sub_1196F7();
  sub_128AB6(0, 0, 639, 479);
  sub_12B634();
  sub_113A4E();
  sub_132646(a1, byte_199BEF, a2);
  word_19A01E = (640 - sub_1327A3()) / 2;
  v5 = 480 - sub_132762();
  if ( ((unsigned int)&loc_100000 & a2) != 0 )
  {
    v6 = __CFSHL__(HIDWORD(v5), 2);
    HIDWORD(v5) *= 4;
    LODWORD(v5) = (int)(v5 - (v6 + HIDWORD(v5))) >> 2;
  }
  else
  {
    LODWORD(v5) = (int)v5 / 2;
  }
  word_19A01C = v5;
  if ( a3 == 1 )
  {
    sub_124D41();
    sub_128C32(0, 0, 639, 479, 0);
    sub_124ECB();
    sub_128C32(0, 0, 639, 479, 0);
    HIDWORD(v5) = word_19A01C;
    sub_132869(word_19A01E, word_19A01C, 639, 479);
    sub_131F7B();
    sub_132C80(100);
    sub_124ECB();
    sub_C5B94(100);
    sub_15085(3);
  }
  v7 = sub_1327E4();
  v8 = 0;
  while ( !(_WORD)v8 )
  {
    LOBYTE(v9) = sub_12C392();
    if ( v9 == 1 )
    {
      sub_12C2E1();
      v8 = 1;
    }
    if ( sub_124075() )
      v8 = 1;
    sub_124D41();
    sub_132869(word_19A01E, word_19A01C, v8, v7);
    v10 = sub_124ECB();
    sub_FE8BE(v10);
    HIDWORD(v5) = (int16_t)v7;
    if ( (int16_t)sub_132825() == (int16_t)v7 - 1 )
      v8 = 1;
  }
  sub_119281();
  if ( a3 == 1 )
  {
    sub_15085(4);
    sub_124D41();
    HIDWORD(v5) = 0;
    sub_128C32(0, 0, 639, 479, 0);
    sub_124ECB();
    sub_C5B94(0);
    sub_C5B85(10);
    sub_C5BB9();
  }
  sub_1329D4();
  dword_193174 = (int)sub_1279AF(dword_193170, SHIDWORD(v5));
  sub_FE8BE(dword_193174);
  word_180EB4 = -1;
  sub_2484F();
  if ( !a3 )
  {
    word_19994C = 1;
    sub_107BA(&dword_19A018);
  }
  sub_124C08();
}
// 14F9B: variable 'v9' is possibly undefined
// FE8BE: using guessed type int __fastcall sub_FE8BE(_DWORD);
// 180EB4: using guessed type int16_t word_180EB4;
// 193170: using guessed type int dword_193170;
// 193174: using guessed type int dword_193174;
// 19994C: using guessed type int16_t word_19994C;
// 199BEF: using guessed type char byte_199BEF;
// 19A018: using guessed type int dword_19A018;
// 19A01C: using guessed type int16_t word_19A01C;
// 19A01E: using guessed type int16_t word_19A01E;


//----- (00015085) --------------------------------------------------------
int16_t __fastcall sub_15085( int a1)
{
  int16_t result; // ax
  int16_t v2; // bx
  int16_t v3; // dx
  _BOOL1 v4; // zf

  if ( a1 == 3 )
  {
    result = sub_C5BB0();
    v2 = -10;
    v3 = 100;
    v4 = result == 0;
  }
  else
  {
    result = sub_C5BB0();
    v2 = 10;
    v3 = 0;
    v4 = result == 100;
  }
  if ( !v4 )
  {
    do
    {
      if ( (uint16_t)v3 < 0x64u )
        sub_132C80(v3);
      v3 += v2;
    }
    while ( v3 != 110 && v3 != -10 );
    return sub_131922(0, 255);
  }
  return result;
}


//----- (000150E5) --------------------------------------------------------
void __fastcall sub_150E5(int a1, int a2, int a3, int a4)
{
  sub_132869(word_19A01E, word_19A01C, a3, a4);
}
// 19A01C: using guessed type int16_t word_19A01C;
// 19A01E: using guessed type int16_t word_19A01E;


//----- (000150FB) --------------------------------------------------------
int __fastcall sub_150FB(int result)
{
  int16_t v1; // bx
  int v2; // eax
  int v3; // esi
  int16_t v4; // dx
  int16_t v5; // di
  int v6; // eax
  char v7; // cl
  int v8; // eax
  int16_t i; // dx
  int v10; // eax
  int16_t v11; // [esp+Ch] [ebp-8h]
  int16_t v12; // [esp+10h] [ebp-4h]

  v1 = result;
  if ( (uint8_t)byte_199CB0 >= 3u )
  {
    v2 = 3753 * (int16_t)result + dword_197F98;
    v3 = v2 + 2207;
    v12 = *(uint8_t *)(v2 + 37);
    v11 = (uint8_t)byte_199CB0 - 3;
    v4 = 0;
    v5 = sub_1247A0(3u) - 1;
    while ( 1 )
    {
      v8 = 170 * v12 + 85 * v11 + 17 * v5;
      if ( v4 >= (uint8_t)byte_180184[v8] )
        break;
      v6 = 2 * v4 + v8;
      v7 = byte_180186[v6];
      *(_BYTE *)(v3 + (uint8_t)byte_180185[v6]) = v7;
      ++v4;
      *(_BYTE *)((uint8_t)byte_180185[v6] + 3753 * v1 + dword_197F98 + 2238) = v7;
    }
    for ( i = 0; ; ++i )
    {
      result = 25 * v11 + 50 * v12 + 5 * v5;
      if ( i >= (uint8_t)byte_180A26[result] )
        break;
      v10 = 2 * i + result;
      *(_BYTE *)((uint8_t)byte_180A27[v10] + dword_197F98 + 3753 * v1 + 2238) = byte_180A28[v10];
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (00015239) --------------------------------------------------------
void __usercall sub_15239(int16_t *a1)
{
  sub_1196F7();
  sub_1172FC();
  sub_128BE7();
  sub_12B65C();
  sub_123E6C((int)&unk_180CB0, 1);
  sub_24677(119, -1, 1);
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
  sub_117174(1);
  sub_11C2F0();
  sub_124C08();
  sub_107AF(&dword_19ABA0);
  sub_119281();
  sub_11C2F0();
  sub_156D4((int)a1);
  word_19A0E2 = 1;
  byte_19A0DE = 0;
  word_19A0C8[0] = 0;
  word_19A0CA = 0;
  sub_1191CA((int)sub_15421, 2);
  while ( byte_19A0DE != 99 )
  {
    sub_15BE9();
    sub_153A0();
    switch ( byte_19A0DE )
    {
      case 0:
        byte_19A0DE = 1;
        break;
      case 1:
        byte_19A0DE = 2;
        break;
      case 4:
      case 5:
      case 6:
        byte_19A0DE = 99;
        break;
      default:
        break;
    }
    if ( byte_19A0DE == 2 )
    {
      sub_15EBC();
      sub_15DF8();
      sub_1660B(a1);
    }
  }
  sub_119281();
  sub_11C2F0();
  byte_1AB124[word_19999C] = 1;
  sub_12D78E();
  sub_2484F();
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
  sub_FE8C8(dword_192ED4, (int)&byte_199F28);
  sub_107BA(&dword_19ABA0);
  sub_8F1C4((void (__fastcall *)(int, int))sub_84555, &byte_199F28, 0);
}
// 192ED4: using guessed type int dword_192ED4;
// 19999C: using guessed type int16_t word_19999C;
// 199F28: using guessed type char byte_199F28;
// 19A0C8: using guessed type int16_t word_19A0C8[];
// 19A0CA: using guessed type int16_t word_19A0CA;
// 19A0DE: using guessed type char byte_19A0DE;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19ABA0: using guessed type int dword_19ABA0;


//----- (000153A0) --------------------------------------------------------
void sub_153A0()
{
  _BOOL2 v0; // si
  unsigned int v1; // edx
  int v2; // eax

  sub_1191CA((int)sub_15421, 2);
  v0 = 0;
  while ( !v0 )
  {
    sub_12C2A0();
    sub_11C2F0();
    v1 = sub_11438B(0, 0, 639, 479, &byte_178A24, 0);
    v0 = (uint16_t)sub_1171AB(v1, v1, 639, 479) == (uint16_t)v1;
    if ( !v0 )
    {
      sub_15421();
      sub_1077D(v2, v1, 639, 0);
      sub_12C2C6(2);
    }
  }
  sub_11C2F0();
  sub_119281();
  JUMPOUT(0x156CE);
}
// 1541C: control flows out of bounds to 156CE
// 15401: variable 'v2' is possibly undefined
// 178A24: using guessed type char byte_178A24;


//----- (00015421) --------------------------------------------------------
void sub_15421()
{
  int v0; // ebx
  int v1; // edx
  char *v2; // esi
  int64_t v3; // rax
  int16_t v4; // si
  int v5; // eax
  int v6; // ebx
  int16_t v7; // ax
  int16_t v8; // cx
  int v9; // edx
  int16_t i; // si
  int16_t *v11; // edi
  int v12; // ebx
  int v13; // eax
  char v14[40]; // [esp+0h] [ebp-50h] BYREF
  _WORD v15[6]; // [esp+28h] [ebp-28h]
  _WORD v16[6]; // [esp+34h] [ebp-1Ch]
  int v17; // [esp+40h] [ebp-10h]
  int v18; // [esp+44h] [ebp-Ch]
  int v19; // [esp+48h] [ebp-8h]
  int v20; // [esp+4Ch] [ebp-4h]

  v15[0] = 44;
  v15[1] = 520;
  v15[2] = 143;
  v15[3] = 444;
  v15[4] = 215;
  v15[5] = 377;
  v16[0] = 96;
  v16[1] = 100;
  v16[2] = 148;
  v16[3] = 149;
  v16[4] = 169;
  v16[5] = 168;
  sub_124D41();
  sub_120DED(0, 0);
  if ( byte_199BE2 == 1 )
  {
    sub_12D408(0);
    if ( !sub_12D745(0) )
      sub_12D88F(0, 1);
  }
  v20 = 0;
  sub_120DED(0, 0);
  v17 = 30;
  sub_120D79(2, (int)&unk_180CBC);
  do
  {
    v0 = (int16_t)v20;
    v1 = (int16_t)v20;
    if ( word_19A0C8[v1] >= 1 )
    {
      if ( word_19A0C8[(int16_t)v20] >= 2 )
        v2 = (char *)dword_19A0CC;
      else
        v2 = (char *)dword_19A0BC;
      strcpy(v14, v2);
      sub_24D4C(v14, (uint8_t)byte_19A0D8[v0], word_19A0C8[v1], 40);
    }
    else
    {
      strcpy(v14, (char *)dword_19A0B8);
      sub_24D30();
    }
    ++v20;
    sub_1212B3(v17, 30, (int)v14);
    v17 += 421;
  }
  while ( (int16_t)v20 < 2 );
  v3 = sprintf(v14, "%d %s", word_19A0D6, (char *)dword_19A0D0);
  v4 = 0;
  v5 = sub_1210FD(320, SWORD2(v3), (int)v14);
  while ( v4 < (uint8_t)byte_19A0DB )
  {
    if ( (byte_19A0DE == 2 || byte_19A0DE == 3) && byte_19A0DA == (uint8_t)byte_19A030[v4] )
    {
      v6 = dword_19A060[v4];
      v7 = v16[v4];
      v8 = v15[v4];
    }
    else
    {
      v9 = v4;
      v6 = dword_19A080[v4];
      v7 = v16[v9];
      v8 = v15[v9];
    }
    v5 = sub_12A478(v8, v7, v6);
    ++v4;
  }
  v18 = 115;
  for ( i = 0; i < 2; ++i )
  {
    v11 = (int16_t *)i;
    v12 = dword_19A058[i];
    LOWORD(v5) = *(_WORD *)(v12 + 4);
    v19 = v5;
    sub_12A478(v18, 225, v12);
    v5 = (uint8_t)byte_19A0D8[i];
    if ( byte_19A0DA != v5 )
      v5 = sub_12B753(dword_19A058[i], (int16_t)v19);
    v18 += 205;
  }
  sub_120DED(0, 0);
  sub_120D79(4, (int)&unk_180CBC);
  sub_103952(550, dword_19A0C4, 550);
  sub_103915(2);
  v13 = sub_24677(119, -1, 1);
  sub_FE8BE(v13, -1, 1, v11);
}
// 24D4C: using guessed type int __fastcall sub_24D4C(_DWORD, _DWORD, _DWORD, _DWORD);
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 103952: using guessed type int __fastcall sub_103952(_DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 199BE2: using guessed type char byte_199BE2;
// 19A058: using guessed type int dword_19A058[];
// 19A060: using guessed type int dword_19A060[];
// 19A080: using guessed type int dword_19A080[];
// 19A0B8: using guessed type int dword_19A0B8;
// 19A0BC: using guessed type int dword_19A0BC;
// 19A0C4: using guessed type int dword_19A0C4;
// 19A0C8: using guessed type int16_t word_19A0C8[];
// 19A0CC: using guessed type int dword_19A0CC;
// 19A0D0: using guessed type int dword_19A0D0;
// 19A0D6: using guessed type int16_t word_19A0D6;
// 19A0DA: using guessed type char byte_19A0DA;
// 19A0DB: using guessed type char byte_19A0DB;
// 19A0DE: using guessed type char byte_19A0DE;


//----- (000156D4) --------------------------------------------------------
void __usercall sub_156D4(int a1)
{
  _DWORD *v1; // esi
  int v2; // eax
  int16_t v3; // bx
  int16_t i; // cx
  int v5; // ebx
  int16_t j; // cx
  int v7; // edx
  int16_t k; // cx
  int16_t m; // cx
  int v10; // esi
  int16_t v11; // ax
  int16_t v12; // ax
  int v13; // edi
  int ii; // ebx
  int v15; // eax
  int v16; // edx
  int16_t n; // cx
  int v18; // eax
  int jj; // ecx
  int v20; // eax
  int16_t v21; // ax
  _DWORD *v22; // eax
  int v23; // eax
  _DWORD *v24; // eax
  void *v25; // eax
  int v26; // eax

  dword_19A0C0 = (int)sub_110CEE(dword_192ED4, 917);
  v1 = sub_126B42((int)aCouncilLbx, 0, dword_192ED4);
  sub_12E332(0);
  sub_12D8F5(30, 30, dword_19A0C0);
  sub_12F578(dword_19A0C0, (int)v1);
  sub_124D41();
  sub_12B79D((int)v1);
  sub_1318D4(0, 255);
  sub_128C32(0, 0, 639, 479, 0);
  v2 = sub_12E1E0(0, 0, (int16_t *)dword_19A0C0, 0);
  v3 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    v2 = 3753 * i;
    if ( !*(_BYTE *)(dword_197F98 + v2 + 36) )
    {
      a1 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)i + 166) % 10;
      v2 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)i + 166) / 10;
      if ( a1 )
        ++v2;
      if ( (int16_t)v2 > v3 )
      {
        v3 = v2;
        byte_19A0D8[0] = i;
      }
    }
  }
  v5 = 0;
  for ( j = 0; j < word_199998; ++j )
  {
    v2 = 3753 * j;
    if ( !*(_BYTE *)(dword_197F98 + v2 + 36) )
    {
      LOWORD(v2) = (uint8_t)byte_19A0D8[0];
      if ( j != (uint8_t)byte_19A0D8[0] )
      {
        a1 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)j + 166) % 10;
        v2 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)j + 166) / 10;
        if ( a1 )
          ++v2;
        if ( (int16_t)v2 > (int16_t)v5 )
        {
          v5 = v2;
          byte_19A0D9 = j;
        }
      }
    }
  }
  byte_19A0DB = 0;
  v7 = dword_197F98;
  for ( k = 0; k < word_199998; ++k )
  {
    v2 = 3753 * k;
    if ( !*(_BYTE *)(v7 + v2 + 36) )
    {
      LOWORD(v2) = (uint8_t)byte_19A0D8[0];
      if ( k != (uint8_t)byte_19A0D8[0] )
      {
        LOWORD(v2) = (uint8_t)byte_19A0D9;
        if ( k != (uint8_t)byte_19A0D9 )
        {
          v2 = (uint8_t)byte_19A0DB++;
          byte_19A030[v2] = k;
        }
      }
    }
  }
  sub_FE8BE(v2, v7, v5, (int16_t *)a1);
  word_19A0D6 = 0;
  for ( m = 0; m < (uint8_t)byte_19A0DB; ++m )
  {
    v10 = m;
    v11 = sub_15B90(byte_19A030[m]);
    word_19A0D6 += v11;
    word_19A020[v10] = v11;
  }
  v12 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19A0D8[0] + 166) / 10;
  if ( *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19A0D8[0] + 166) % 10 )
    ++v12;
  word_19A0B4 = v12;
  word_19A0D6 += v12;
  v13 = 10;
  ii = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19A0D9 + 166) % 10;
  v15 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19A0D9 + 166) / 10;
  v16 = ii;
  if ( ii )
    ++v15;
  word_19A0B6 = v15;
  word_19A0D6 += v15;
  for ( n = 0; n < (uint8_t)byte_19A0DB; ++n )
  {
    for ( ii = 0; ; ++ii )
    {
      v15 = (uint8_t)byte_19A0DB - 1;
      if ( (int16_t)ii >= v15 )
        break;
      v18 = (int16_t)ii;
      LOWORD(v16) = word_19A020[v18];
      if ( (int16_t)v16 < word_19A022[v18] )
      {
        sub_133111(&word_19A020[v18], &word_19A020[v18 + 1]);
        v16 = (int)&byte_19A030[(int16_t)ii + 1];
        sub_133154(&byte_19A030[(int16_t)ii], (char *)v16);
      }
    }
  }
  for ( jj = 0; ; ++jj )
  {
    LOWORD(v15) = (uint8_t)byte_19A0DB;
    if ( (int16_t)jj >= (uint8_t)byte_19A0DB )
      break;
    HIWORD(v20) = HIWORD(dword_197F98);
    LOWORD(v20) = *(uint8_t *)(3753 * (uint8_t)byte_19A030[(int16_t)jj] + dword_197F98 + 37);
    v20 *= 6;
    v13 = jj + v20 + 80;
    v21 = jj + v20 + 2;
    if ( (_WORD)jj )
      v22 = sub_126B42((int)aCouncilLbx_0, v21, dword_192ED4);
    else
      v22 = sub_126AFD((int)aCouncilLbx_0, v21, dword_192ED4);
    ii = dword_192ED4;
    v16 = (int16_t)v13;
    dword_19A060[(int16_t)jj] = (int)v22;
    v15 = (int)sub_126B42((int)aCouncilLbx_0, (int16_t)v13, ii);
    dword_19A080[(int16_t)jj] = v15;
  }
  sub_FE8BE(v15, v16, ii, (int16_t *)v13);
  dword_19A058[0] = (int)sub_126B42(
                           (int)aCouncilLbx_0,
                           (int16_t)(2
                                   * *(uint8_t *)(3753 * (uint8_t)byte_19A0D8[0] + dword_197F98 + 37)
                                   + 158),
                           dword_192ED4);
  dword_19A05C = (int)sub_126B42(
                        (int)aCouncilLbx_0,
                        (int16_t)(2 * *(uint8_t *)(dword_197F98 + 3753 * (uint8_t)byte_19A0D9 + 37) + 159),
                        dword_192ED4);
  dword_19A0B8 = (int)sub_110D3C(dword_192ED4, 30);
  dword_19A0BC = (int)sub_110D3C(dword_192ED4, 30);
  dword_19A0CC = (int)sub_110D3C(dword_192ED4, 30);
  dword_19A0D0 = (int)sub_110D3C(dword_192ED4, 30);
  dword_19A0C4 = (int)sub_110D3C(dword_192ED4, 210);
  v23 = sub_111499(dword_192ED4);
  v24 = sub_110D3C(dword_192ED4, v23 - 100);
  sub_12D7B7((int)v24);
  sub_124C08();
  sub_12D1C5((int)aCouncilLbx, 1, 0, jj);
  sub_124D41();
  sub_12D408(0);
  v25 = sub_124DEC();
  sub_FE8BE((int)v25, 1, 0, (int16_t *)v13);
  sub_123E6C((int)&unk_17CF00, 1);
  LOBYTE(v26) = sub_1695A();
  sub_FE8BE(v26, 1, 0, (int16_t *)v13);
  byte_19A0DA = -1;
  JUMPOUT(0x156CE);
}
// 15B8B: control flows out of bounds to 156CE
// 15B7F: variable 'v26' is possibly undefined
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19A020: using guessed type int16_t word_19A020[];
// 19A022: using guessed type int16_t word_19A022[];
// 19A058: using guessed type int dword_19A058[];
// 19A05C: using guessed type int dword_19A05C;
// 19A060: using guessed type int dword_19A060[];
// 19A080: using guessed type int dword_19A080[];
// 19A0B4: using guessed type int16_t word_19A0B4;
// 19A0B6: using guessed type int16_t word_19A0B6;
// 19A0B8: using guessed type int dword_19A0B8;
// 19A0BC: using guessed type int dword_19A0BC;
// 19A0C0: using guessed type int dword_19A0C0;
// 19A0C4: using guessed type int dword_19A0C4;
// 19A0CC: using guessed type int dword_19A0CC;
// 19A0D0: using guessed type int dword_19A0D0;
// 19A0D6: using guessed type int16_t word_19A0D6;
// 19A0D9: using guessed type char byte_19A0D9;
// 19A0DA: using guessed type char byte_19A0DA;
// 19A0DB: using guessed type char byte_19A0DB;


//----- (00015B90) --------------------------------------------------------
int __fastcall sub_15B90( unsigned int a1)
{
  int v1; // ecx
  int result; // eax

  v1 = *(int16_t *)(3753 * a1 + dword_197F98 + 166) % 10;
  result = *(int16_t *)(3753 * a1 + dword_197F98 + 166) / 10;
  if ( v1 )
    ++result;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (00015BE9) --------------------------------------------------------
void sub_15BE9()
{
  int v0; // edx
  int v1; // ebx
  int v2; // edx
  char *v3; // edi
  _DWORD v4[20]; // [esp+0h] [ebp-50h] BYREF

  switch ( byte_19A0DE )
  {
    case 0:
      v0 = 15;
      goto LABEL_3;
    case 1:
      sub_249F9(aJimtextLbx, 16, (char *)dword_19A0C4, 200);
      sub_24DF0();
      break;
    case 2:
      sub_249F9(aJimtextLbx, 17, (char *)dword_19A0C4, 200);
      v1 = word_19A0D4;
      v2 = (uint8_t)byte_19A0D8[(uint8_t)byte_19A0DD];
      goto LABEL_6;
    case 3:
      sub_249F9(aJimtextLbx, 18, (char *)dword_19A0C4, 200);
      v1 = word_19A0D4;
      v2 = byte_19A0DA;
LABEL_6:
      sub_24D4C(dword_19A0C4, v2, v1, 200);
      break;
    case 4:
      sub_249F9(aJimtextLbx, 19, (char *)dword_19A0C4, 200);
      sub_24D30();
      break;
    case 5:
      v0 = 20;
LABEL_3:
      sub_249F9(aJimtextLbx, v0, (char *)dword_19A0C4, 200);
      break;
    case 6:
      sub_249F9(aJimtextLbx, 21, (char *)dword_19A0C4, 200);
      if ( word_19A0E2 == 2 )
      {
        sub_249F9(aJimtextLbx, 22, (char *)v4, 80);
        sub_24D30();
        v4[0] = dword_19A0C4;
        v3 = (char *)(dword_19A0C4 - 1);
        do
          ++v3;
        while ( *v3 );
        strcpy(v3, (char *)v4);
      }
      break;
    default:
      break;
  }
  JUMPOUT(0x156CD);
}
// 15C02: control flows out of bounds to 156CD
// 24D4C: using guessed type int __fastcall sub_24D4C(_DWORD, _DWORD, _DWORD, _DWORD);
// 19A0C4: using guessed type int dword_19A0C4;
// 19A0D4: using guessed type int16_t word_19A0D4;
// 19A0D9: using guessed type char byte_19A0D9;
// 19A0DA: using guessed type char byte_19A0DA;
// 19A0DD: using guessed type char byte_19A0DD;
// 19A0DE: using guessed type char byte_19A0DE;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (00015DF8) --------------------------------------------------------
int sub_15DF8()
{
  int v0; // eax
  int v1; // eax
  int result; // eax
  int v3; // kr00_4

  v0 = (2 * word_19A0D6 + 2) / 3;
  if ( word_19A0C8[0] >= v0 )
  {
    byte_19A0DD = 0;
    byte_19A0DE = 4;
    if ( (uint8_t)byte_19A0D8[0] == word_19999C )
    {
LABEL_3:
      word_19A0E2 = 2;
      goto LABEL_9;
    }
    goto LABEL_4;
  }
  if ( word_19A0CA >= v0 )
  {
    byte_19A0DD = 1;
    byte_19A0DE = 4;
    if ( (uint8_t)byte_19A0D9 == word_19999C )
      goto LABEL_3;
LABEL_4:
    word_19A0E2 = 3;
    goto LABEL_9;
  }
  byte_19A0DE = 5;
LABEL_9:
  sub_15BE9();
  sub_153A0();
  LOBYTE(v1) = byte_19A0DE;
  v3 = v1;
  result = (uint8_t)byte_19A0DE;
  switch ( byte_19A0DE )
  {
    case 0:
      byte_19A0DE = 1;
      break;
    case 1:
      byte_19A0DE = 2;
      break;
    case 4:
    case 5:
    case 6:
      byte_19A0DE = 99;
      break;
    default:
      result = v3;
      break;
  }
  return result;
}
// 15E93: variable 'v1' is possibly undefined
// 19999C: using guessed type int16_t word_19999C;
// 19A0C8: using guessed type int16_t word_19A0C8[];
// 19A0CA: using guessed type int16_t word_19A0CA;
// 19A0D6: using guessed type int16_t word_19A0D6;
// 19A0D9: using guessed type char byte_19A0D9;
// 19A0DD: using guessed type char byte_19A0DD;
// 19A0DE: using guessed type char byte_19A0DE;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (00015EBC) --------------------------------------------------------
void sub_15EBC()
{
  int16_t i; // cx
  int16_t v1; // ax
  int16_t v2; // si
  _BOOL2 v3; // di
  int16_t v4; // ax
  int16_t v5; // bx
  uint8_t v6; // al

  for ( i = 0; i < (uint8_t)byte_19A0DB; ++i )
  {
    v1 = (uint8_t)byte_19A030[i];
    if ( v1 != word_19999C && v1 != (uint8_t)byte_19A0D8[0] && v1 != (uint8_t)byte_19A0D9 )
    {
      v2 = (uint8_t)byte_19A030[i];
      v3 = sub_16021((uint8_t)byte_19A0D8[0], v2, (uint8_t)byte_19A0D9);
      v4 = sub_16021((uint8_t)byte_19A0D9, v2, (uint8_t)byte_19A0D8[0]);
      if ( v3 )
      {
        LOBYTE(v4) = v4 != 1;
      }
      else if ( v4 )
      {
        LOBYTE(v4) = 2;
      }
      v5 = word_19A020[i];
      byte_19A0DA = byte_19A030[i];
      word_19A0D4 = v5;
      sub_161E4(v4, byte_19A0DA);
    }
  }
  if ( (uint8_t)byte_19A0D8[0] != word_19999C )
  {
    word_19A0D4 = word_19A0B4;
    byte_19A0DA = byte_19A0D8[0];
    sub_161E4(word_19A0B4 != 0, byte_19A0D8[0]);
  }
  if ( (uint8_t)byte_19A0D9 != word_19999C )
  {
    if ( word_19A0B6 )
      v6 = 2;
    else
      v6 = 0;
    word_19A0D4 = word_19A0B6;
    byte_19A0DA = byte_19A0D9;
    sub_161E4(v6, byte_19A0D9);
  }
  sub_1633C();
  JUMPOUT(0x156CE);
}
// 1601C: control flows out of bounds to 156CE
// 19999C: using guessed type int16_t word_19999C;
// 19A020: using guessed type int16_t word_19A020[];
// 19A0B4: using guessed type int16_t word_19A0B4;
// 19A0B6: using guessed type int16_t word_19A0B6;
// 19A0D4: using guessed type int16_t word_19A0D4;
// 19A0D9: using guessed type char byte_19A0D9;
// 19A0DA: using guessed type char byte_19A0DA;
// 19A0DB: using guessed type char byte_19A0DB;


//----- (00016021) --------------------------------------------------------
_BOOL2 __fastcall sub_16021( int a1, int a2, int a3)
{
  int v6; // ebx
  char *v7; // eax
  int v8; // edx
  int v10; // [esp+0h] [ebp-Ch]

  v6 = dword_197F98 + 3753 * a2;
  v10 = a1;
  v7 = (char *)(v6 + a1);
  if ( v7[1575] < 4 )
  {
    if ( v7[1575] == 2 )
    {
      LOWORD(v8) = 200;
    }
    else
    {
      LOWORD(v8) = 2 * v7[2030] + v7[1751] + v7[1559] - 20 * *(_WORD *)(v6 + 2 * v10 + 2087);
      if ( *(char *)(a3 + v6 + 1575) >= 4 )
        LOWORD(v8) = v8 + 100;
      if ( sub_78398() == a1 )
        LOWORD(v8) = v8 + 40;
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 2227) == 1 )
        LOWORD(v8) = v8 + 40;
      if ( *(_BYTE *)(3753 * a1 + dword_197F98 + 2226) == 1 )
        LOWORD(v8) = v8 - 100;
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 479) == 3 )
        LOWORD(v8) = v8 + 30;
      if ( *(char *)(dword_197F98 + 3753 * a2 + 3697) == a1 )
        LOWORD(v8) = v8 + 50;
      if ( *(_BYTE *)(a1 + 3753 * a2 + dword_197F98 + 1575) == 1 )
        LOWORD(v8) = v8 + 50;
      if ( *(_BYTE *)(a1 + 3753 * a2 + dword_197F98 + 1583) )
        LOWORD(v8) = v8 + 25;
      if ( *(_BYTE *)(a1 + dword_197F98 + 3753 * a2 + 1591) )
        LOWORD(v8) = v8 + 25;
      if ( *(_BYTE *)(dword_197F98 + 3753 * a1 + 40) == 100 && (uint8_t)byte_199CB0 > 2u )
        v8 = 6 * (int16_t)v8 / ((uint8_t)byte_199CB0 + 6);
    }
  }
  else
  {
    LOWORD(v8) = -1;
  }
  return (int)sub_1247A0(0xC8u) <= (int16_t)v8;
}
// 197F98: using guessed type int dword_197F98;
// 199CB0: using guessed type char byte_199CB0;


//----- (000161E4) --------------------------------------------------------
void __fastcall sub_161E4( unsigned int a1, unsigned int a2)
{
  int v2; // ebx
  int v3; // esi
  char v4; // al

  if ( a1 )
  {
    if ( a1 <= 1u )
    {
      byte_19A0DE = 2;
      word_19A0C8[0] += word_19A0D4;
      byte_19A0DD = 0;
      sub_4E3B5(24, a2, (uint8_t)byte_19A0D8[0], 16, 0, 0);
      sub_4E3B5(-12, a2, (uint8_t)byte_19A0D9, 9, 0, 0);
      v2 = 3753 * a2;
      v3 = dword_197F98;
      v4 = byte_19A0D8[0];
    }
    else
    {
      if ( a1 != 2 )
        goto LABEL_9;
      byte_19A0DE = 2;
      word_19A0CA += word_19A0D4;
      byte_19A0DD = 1;
      sub_4E3B5(24, a2, (uint8_t)byte_19A0D9, 16, 0, 0);
      v3 = 3753 * a2;
      sub_4E3B5(-12, a2, (uint8_t)byte_19A0D8[0], 9, 0, 0);
      v2 = dword_197F98;
      v4 = byte_19A0D9;
    }
    *(_BYTE *)(v3 + v2 + 3697) = v4;
  }
  else
  {
    byte_19A0DE = 3;
    sub_4E3B5(-6, a2, (uint8_t)byte_19A0D9, 0, 0, 0);
    sub_4E3B5(-6, a2, (uint8_t)byte_19A0D8[0], 0, 0, 0);
    *(_BYTE *)(dword_197F98 + 3753 * a2 + 3697) = -1;
  }
LABEL_9:
  sub_15BE9();
  sub_153A0();
}
// 197F98: using guessed type int dword_197F98;
// 19A0C8: using guessed type int16_t word_19A0C8[];
// 19A0CA: using guessed type int16_t word_19A0CA;
// 19A0D4: using guessed type int16_t word_19A0D4;
// 19A0D9: using guessed type char byte_19A0D9;
// 19A0DD: using guessed type char byte_19A0DD;
// 19A0DE: using guessed type char byte_19A0DE;


//----- (0001633C) --------------------------------------------------------
void sub_1633C()
{
  int v0; // ecx
  int16_t v1; // ax
  char v2; // dl
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  uint16_t v7; // ax
  int v8; // eax
  char v9; // dl
  char v10[25]; // [esp+0h] [ebp-1Eh] BYREF
  char v11[25]; // [esp+19h] [ebp-5h] BYREF
  char v12[50]; // [esp+32h] [ebp+14h] BYREF
  char v13[48]; // [esp+64h] [ebp+46h] BYREF
  _BYTE v14[4]; // [esp+94h] [ebp+76h] BYREF
  int v15; // [esp+98h] [ebp+7Ah] BYREF
  int16_t v16; // [esp+9Ch] [ebp+7Eh]

  sub_1191CA((int)sub_15421, 2);
  v0 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)word_19999C + 166) % 10;
  v1 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)word_19999C + 166) / 10;
  v16 = 0;
  if ( v0 )
    ++v1;
  word_19A0D4 = v1;
  v2 = byte_178A24;
  byte_19A0DA = word_19999C;
  v3 = 0;
  do
  {
    v4 = 25 * (int16_t)v3++;
    v10[v4] = v2;
  }
  while ( (int16_t)v3 < 4 );
  sub_249F9(aJimtextLbx, 23, v13, 45);
  sub_24E08(v13, word_19A0D4, 45);
  if ( (uint8_t)byte_19A0D8[0] == word_19999C )
    sub_249F9(aJimtextLbx, 24, v10, 25);
  else
    sprintf(v10, "  %s", (char *)(dword_197F98 + 3753 * (uint8_t)byte_19A0D8[0] + 1));
  if ( (uint8_t)byte_19A0D9 == word_19999C )
    sub_249F9(aJimtextLbx, 24, v11, 25);
  else
    sprintf(v11, "  %s", (char *)(3753 * (uint8_t)byte_19A0D9 + dword_197F98 + 1));
  sub_249F9(aJimtextLbx, 25, v12, 25);
  v5 = 0;
  do
  {
    v6 = (int16_t)v5++;
    v14[v6] = 1;
  }
  while ( (int16_t)v5 < 4 );
  sub_120DED(0, 0);
  sub_120BB5(4, (int)&unk_180CBC);
  sub_120EB9((int)&unk_180CC4);
  sub_120E24(4);
  *(_BYTE *)dword_19A0C4 = byte_178A24;
  v15 = 0;
  v7 = sub_11C4C1(214, 388, 180, (int)v13, v10, 25, (int16_t *)&v15, (int)v14, 17, 0, 0, 0, 0);
  if ( !v7 )
  {
    byte_19A0DC = byte_19A0D8[0];
    v8 = dword_197F98 + 3753 * byte_19A0DA;
    v9 = byte_19A0D8[0];
    v16 = 1;
LABEL_18:
    *(_BYTE *)(v8 + 3697) = v9;
    goto LABEL_21;
  }
  if ( v7 <= 1u )
  {
    byte_19A0DC = byte_19A0D9;
    v8 = dword_197F98 + 3753 * byte_19A0DA;
    v9 = byte_19A0D9;
    v16 = 2;
    goto LABEL_18;
  }
  if ( v7 == 2 )
  {
    v16 = 0;
    *(_BYTE *)(3753 * byte_19A0DA + dword_197F98 + 3697) = -1;
  }
LABEL_21:
  sub_161E4(v16, word_19999C);
  sub_11C2F0();
  sub_119281();
  byte_19A0DA = -1;
}
// 24E08: using guessed type int __fastcall sub_24E08(_DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 178A24: using guessed type char byte_178A24;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19A0C4: using guessed type int dword_19A0C4;
// 19A0D4: using guessed type int16_t word_19A0D4;
// 19A0D9: using guessed type char byte_19A0D9;
// 19A0DA: using guessed type char byte_19A0DA;
// 19A0DC: using guessed type char byte_19A0DC;


//----- (0001660B) --------------------------------------------------------
int16_t __usercall sub_1660B(int16_t *a1)
{
  int v1; // eax
  int v2; // ecx
  int16_t v3; // ax
  int16_t v4; // ax
  char v5; // al
  int16_t i; // bx
  char v8[25]; // [esp+0h] [ebp-12h] BYREF
  char v9[75]; // [esp+19h] [ebp+7h] BYREF
  char v10[40]; // [esp+64h] [ebp+52h] BYREF
  _BYTE v11[4]; // [esp+8Ch] [ebp+7Ah] BYREF
  int v12; // [esp+90h] [ebp+7Eh] BYREF

  sub_1191CA((int)sub_15421, 2);
  if ( word_19A0E2 != 1 )
  {
    *(_BYTE *)dword_19A0C4 = byte_178A24;
    sub_120DED(0, 0);
    sub_120BB5(4, (int)&unk_180CBC);
    sub_120EB9((int)&unk_180CC4);
    sub_120E24(4);
    sub_249F9(aJimtextLbx, 26, v8, 25);
    sub_249F9(aJimtextLbx, 27, v9, 25);
    sub_249F9(aJimtextLbx, 28, v10, 40);
    v9[25] = byte_178A24;
    v1 = 0;
    do
    {
      v2 = (int16_t)v1++;
      v11[v2] = 1;
    }
    while ( (int16_t)v1 < 4 );
    v12 = 0;
    v3 = sub_11C4C1(214, 388, 180, (int)v10, v8, 25, (int16_t *)&v12, (int)v11, 17, 0, 0, 0, 0);
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        byte_19A0DE = 6;
        if ( word_19A0E2 == 2 )
        {
          if ( (uint8_t)byte_19A0D8[0] == word_19999C )
            v5 = byte_19A0D9;
          else
            v5 = byte_19A0D8[0];
        }
        else
        {
          v5 = byte_19A0D8[(uint8_t)byte_19A0DD];
        }
        byte_19A0DC = v5;
        sub_15BE9();
        sub_153A0();
        switch ( byte_19A0DE )
        {
          case 0:
            byte_19A0DE = 1;
            break;
          case 1:
            byte_19A0DE = 2;
            break;
          case 4:
          case 5:
          case 6:
            byte_19A0DE = 99;
            break;
          default:
            break;
        }
        for ( i = 0; i < word_199998; ++i )
        {
          if ( i != (uint8_t)byte_19A0DC
            && i != word_19999C
            && !*(_BYTE *)(dword_197F98 + 3753 * i + 36)
            && sub_E4CD2(i, (uint8_t)byte_19A0DC) )
          {
            sub_E4D06(i, (uint8_t)byte_19A0DC);
          }
        }
        sub_E4DC9();
        sub_519AC((uint8_t)byte_19A0DC, word_19999C);
        sub_5175B((uint8_t)byte_19A0DC, word_19999C);
        sub_51C02((uint8_t)byte_19A0DC, word_19999C);
        sub_5138E((uint8_t)byte_19A0DC, word_19999C);
        sub_51078((uint8_t)byte_19A0DC, word_19999C);
      }
    }
    else
    {
      v4 = (uint8_t)byte_19A0D8[(uint8_t)byte_19A0DD];
      byte_19A0DE = 99;
      word_19A0E0 = v4;
      if ( v4 == word_19999C )
      {
        sub_169C9(a1);
        sub_C66BD();
      }
      *(_BYTE *)(dword_197F98 + 3753 * word_19A0E0 + 497) = 1;
    }
  }
  sub_119281();
  return sub_11C2F0();
}
// 178A24: using guessed type char byte_178A24;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 19A0C4: using guessed type int dword_19A0C4;
// 19A0D9: using guessed type char byte_19A0D9;
// 19A0DC: using guessed type char byte_19A0DC;
// 19A0DD: using guessed type char byte_19A0DD;
// 19A0DE: using guessed type char byte_19A0DE;
// 19A0E0: using guessed type int16_t word_19A0E0;
// 19A0E2: using guessed type int16_t word_19A0E2;


//----- (000168AF) --------------------------------------------------------
int __usercall sub_168AF(int16_t *a1)
{
  int16_t v1; // dx
  int16_t v2; // bx
  int16_t i; // ax
  int16_t j; // ax
  int result; // eax
  int v6; // eax

  v1 = 0;
  v2 = 0;
  for ( i = 0; i < word_199998; ++i )
  {
    if ( !*(_BYTE *)(3753 * i + dword_197F98 + 36) )
      ++v1;
  }
  for ( j = 0; j < word_19999A; ++j )
  {
    if ( *(char *)(dword_19306C + 113 * j + 20) != -1 )
      ++v2;
  }
  result = dword_192FD8 - 35000;
  if ( dword_192FD8 - 35000 >= 25 && (result >= word_19A0E4 || !word_19A0E2) && v1 > 2 )
  {
    result = word_19999A / 2;
    if ( v2 >= result )
    {
      sub_15239(a1);
      LOWORD(v6) = dword_192FD8;
      result = v6 - 34975;
      word_19A0E4 = result;
    }
  }
  return result;
}
// 16949: variable 'v6' is possibly undefined
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19A0E4: using guessed type int16_t word_19A0E4;


//----- (0001695A) --------------------------------------------------------
char sub_1695A()
{
  sub_249F9(aJimtextLbx, 11, (char *)dword_19A0B8, 30);
  sub_249F9(aJimtextLbx, 12, (char *)dword_19A0BC, 30);
  sub_249F9(aJimtextLbx, 13, (char *)dword_19A0CC, 30);
  return sub_249F9(aJimtextLbx, 14, (char *)dword_19A0D0, 30);
}
// 19A0B8: using guessed type int dword_19A0B8;
// 19A0BC: using guessed type int dword_19A0BC;
// 19A0CC: using guessed type int dword_19A0CC;
// 19A0D0: using guessed type int dword_19A0D0;


//----- (000169C9) --------------------------------------------------------
int16_t __usercall sub_169C9(int16_t *a1)
{
  int v1; // eax
  int v2; // edx
  int16_t v3; // ax
  int16_t i; // bx
  int16_t result; // ax

  v1 = 0;
  do
  {
    v2 = (int16_t)v1++;
    byte_19A0A0[v2] = -1;
  }
  while ( (int16_t)v1 < 20 );
  sub_1191CA((int)sub_16AD2, 2);
  v3 = (uint8_t)byte_19A0D8[byte_19A0DD == 0];
  for ( i = 0; ; ++i )
  {
    sub_16A3F(v3, 0, a1);
    result = (uint8_t)byte_19A0DB;
    if ( i >= (uint8_t)byte_19A0DB )
      break;
    byte_19A030[i] += 100;
    v3 = (uint8_t)byte_19A030[i] - 100;
  }
  return result;
}
// 19A0DB: using guessed type char byte_19A0DB;
// 19A0DD: using guessed type char byte_19A0DD;


//----- (00016A3F) --------------------------------------------------------
void __usercall sub_16A3F( int a1, int a2, int16_t *a3)
{
  int v4; // edx
  _BOOL2 v5; // si
  unsigned int v6; // edx
  int v7; // eax

  sub_16BFC();
  v4 = (int16_t)(*(uint8_t *)(3753 * a1 + dword_197F98 + 37) + 184);
  v5 = 0;
  sub_12D1C5((int)aCouncilLbx, v4, 1, a2);
  while ( !v5 )
  {
    sub_12C2A0();
    sub_11C2F0();
    v6 = sub_11438B(0, 0, 639, 479, &byte_178A24, 0);
    v5 = (uint16_t)sub_1171AB(v6, v6, 639, 479) == (uint16_t)v6;
    if ( !v5 )
    {
      sub_16AD2(a3);
      sub_1077D(v7, v6, 639, a3);
      sub_12C2C6(2);
    }
  }
  JUMPOUT(0x16338);
}
// 16A7C: control flows out of bounds to 16338
// 16AC1: variable 'v7' is possibly undefined
// 178A24: using guessed type char byte_178A24;
// 197F98: using guessed type int dword_197F98;


//----- (00016AD2) --------------------------------------------------------
void __usercall sub_16AD2(int16_t *a1)
{
  int16_t i; // cx
  int v2; // eax
  _WORD v3[6]; // [esp+0h] [ebp-18h]
  _WORD v4[6]; // [esp+Ch] [ebp-Ch]

  v3[0] = 44;
  v3[1] = 520;
  v3[2] = 143;
  v3[3] = 444;
  v3[4] = 215;
  v3[5] = 377;
  v4[0] = 96;
  v4[1] = 100;
  v4[2] = 148;
  v4[3] = 149;
  v4[4] = 169;
  v4[5] = 168;
  sub_124D41();
  sub_120DED(0, 0);
  if ( byte_199BE2 == 1 )
  {
    sub_12D408(0);
    if ( !sub_12D745(0) )
      sub_12D88F(0, 1);
    sub_12D408(1);
  }
  for ( i = 0; i < (uint8_t)byte_19A0DB; ++i )
  {
    if ( (uint8_t)byte_19A030[i] < 0x64u )
      sub_12A478(v3[i], v4[i], dword_19A080[i]);
  }
  sub_120DED(0, 0);
  sub_120D79(4, (int)&unk_180CBC);
  sub_103952(550, dword_19A0C4, 550);
  sub_103915(2);
  v2 = sub_24677(119, -1, 1);
  sub_FE8BE(v2, -1, 1, a1);
}
// 103915: using guessed type _DWORD __stdcall sub_103915(int16_t);
// 103952: using guessed type int __fastcall sub_103952(_DWORD, _DWORD, _DWORD);
// 199BE2: using guessed type char byte_199BE2;
// 19A080: using guessed type int dword_19A080[];
// 19A0C4: using guessed type int dword_19A0C4;
// 19A0DB: using guessed type char byte_19A0DB;


//----- (00016BFC) --------------------------------------------------------
_DWORD *sub_16BFC()
{
  int16_t v0; // dx

  do
    v0 = sub_1247A0(0xEu) - 1;
  while ( byte_19A0A0[v0] != -1 );
  byte_19A0A0[v0] = v0;
  return sub_126C91((int)aCouncmsgLbx, (int16_t)(14 * (uint8_t)byte_199CAE + v0), dword_19A0C4, 0, 1u, 200);
}
// 199CAE: using guessed type char byte_199CAE;
// 19A0C4: using guessed type int dword_19A0C4;


//----- (00016C4E) --------------------------------------------------------
void __usercall sub_16C4E( int a1, int16_t *a2)
{
  int16_t v3; // ax
  int v4; // edx
  char v5; // al

  word_19AA44 = -1;
  word_19AA52 = 0;
  sub_1196F7();
  sub_1172FC();
  sub_128BE7();
  sub_12B65C();
  sub_123E6C((int)&unk_180E62, 1);
  sub_119281();
  sub_11C2F0();
  word_19AA36 = -1;
  word_19AA48 = 0;
  byte_19AA66 = a1;
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
  sub_117174(1);
  sub_11C2F0();
  sub_124C08();
  sub_119281();
  if ( (int16_t)sub_50FDF(word_19999C, (uint8_t)byte_19AA66) <= -100 || word_19A0E2 == 2 || word_19A0E2 == 3 )
  {
    v3 = (*(_BYTE *)((uint8_t)byte_19AA66 + dword_197F98 + 3753 * word_19999C + 1575) < 4) + 126;
    byte_19AA65 = 0;
  }
  else
  {
    v3 = (*(char *)(3753 * word_19999C + dword_197F98 + (uint8_t)byte_19AA66 + 1559) < -12) + 128;
    byte_19AA65 = 1;
  }
  word_19AA40 = v3;
  v4 = dword_197F98;
  if ( *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) != 100 && (uint8_t)byte_199F3A >= 2u )
    byte_19AA65 = 1;
  if ( (uint8_t)byte_199F3A >= 2u
    && (v4 = 3753 * (uint8_t)byte_19AA66, *(_BYTE *)(v4 + dword_197F98 + 40) == 100) )
  {
    if ( byte_1AB066 == 1 )
    {
      byte_19AA67 = word_19999C;
      v5 = byte_1AB04A;
    }
    else
    {
      byte_19AA67 = byte_1AB04A;
      v5 = word_19999C;
    }
    byte_19AA68 = v5;
    byte_19AA65 = 1;
    LOBYTE(byte_19A484[0]) = byte_178A64;
    sub_17C07();
    sub_1DEF8(a2);
  }
  else
  {
    sub_17C07();
    if ( byte_19AA65 == 1 )
    {
      v4 = dword_197F98;
      if ( *(_BYTE *)(dword_197F98 + 3753 * word_19999C + 2226) == 1
        || *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 2226) == 1 )
      {
        v4 = (uint8_t)byte_19AA66;
        sub_17227(word_19999C, (uint8_t)byte_19AA66, 0, a2);
      }
      else
      {
        sub_1758C(a2);
      }
    }
    else
    {
      sub_19919(a2);
    }
  }
  word_180EB4 = -1;
  sub_2484F();
  sub_119281();
  sub_11C2F0();
  sub_12D78E();
  sub_FE8C8(dword_192ED4, v4);
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
}
// 17C07: using guessed type int sub_17C07(void);
// 178A64: using guessed type char byte_178A64;
// 180EB4: using guessed type int16_t word_180EB4;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19A484: using guessed type int16_t byte_19A484[50];
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA44: using guessed type int16_t word_19AA44;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA52: using guessed type int16_t word_19AA52;
// 19AA65: using guessed type char byte_19AA65;
// 19AA66: using guessed type char byte_19AA66;
// 19AA67: using guessed type char byte_19AA67;
// 19AA68: using guessed type char byte_19AA68;
// 1AB04A: using guessed type char byte_1AB04A;
// 1AB066: using guessed type char byte_1AB066;


//----- (00016F00) --------------------------------------------------------
int __fastcall sub_16F00(int a1, int a2, int a3, int a4)
{
  char v4; // bl
  int v5; // eax
  int v6; // edx
  int16_t *v7; // edi
  int v8; // ebx
  int v9; // edx
  unsigned int v10; // kr0C_4
  int v11; // eax
  int v13[24]; // [esp+0h] [ebp-7Ch] BYREF
  int16_t v14; // [esp+60h] [ebp-1Ch]
  int16_t v15; // [esp+64h] [ebp-18h]
  int16_t v16; // [esp+68h] [ebp-14h]
  int v17; // [esp+6Ch] [ebp-10h]
  int v18; // [esp+78h] [ebp-4h]

  sub_124D41();
  if ( word_19994C == 1 )
  {
    sub_17B51();
    sub_17BB2(1, a2, a3, a4);
  }
  if ( byte_19AA65 )
  {
    if ( byte_199BE2 == 1 )
    {
      sub_12CD2D();
      if ( !sub_12D70B() )
        sub_12D6B2(1);
    }
  }
  sub_120DED(0, 248);
  sub_120D79(4, (int)&unk_180DCC);
  if ( word_19AA40 != word_19AA36 )
  {
    if ( word_19AA40 < 1000 )
    {
      word_19AA36 = word_19AA40;
      sub_1D565(
        v13[0],
        v13[1],
        v13[2],
        v13[3],
        v13[4],
        v13[5],
        v13[6],
        v13[7],
        v13[8],
        v13[9],
        v13[10],
        v13[11],
        v13[12],
        v13[13],
        v13[14],
        v13[15],
        v13[16],
        v13[17],
        v13[18],
        v13[19],
        v13[20],
        v13[21],
        v13[22],
        (char *)v13[23],
        v14,
        v15,
        v16,
        v17);
    }
    else
    {
      word_19AA40 = 0;
      word_19AA36 = 0;
    }
  }
  LOWORD(v18) = (int16_t)sub_103CAF(470, (int)&byte_19A64A) / 2;
  sub_103BC4(0x50u, 440 - v18, 470, (int)&byte_19A64A, 2);
  switch ( *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 38) )
  {
    case 0:
      LOWORD(v18) = 243;
      break;
    case 1:
      LOWORD(v18) = 240;
      break;
    case 2:
      LOWORD(v18) = 253;
      break;
    case 3:
      LOWORD(v18) = 227;
      break;
    case 4:
      LOWORD(v18) = 245;
      break;
    case 5:
      LOWORD(v18) = 235;
      break;
    case 6:
      LOWORD(v18) = 244;
      break;
    case 7:
      LOWORD(v18) = 241;
      break;
    default:
      break;
  }
  v4 = v18;
  v5 = 0;
  do
  {
    v6 = (int16_t)v5++;
    *((_BYTE *)v13 + v6) = v4;
  }
  while ( (int16_t)v5 < 8 );
  LOBYTE(v13[0]) = 0;
  sub_120DED(0, 0);
  sub_120CCB(4, (int)v13);
  if ( *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) == 100 )
  {
    strcpy((char *)v13, (char *)dword_19A2A0);
    v7 = (int16_t *)v13;
    sub_24D4C(v13, (uint8_t)byte_19AA66, (int16_t)((uint8_t)byte_19AA66 + 1), 120);
  }
  else
  {
    strcpy((char *)v13, (char *)dword_19A298);
    v7 = (int16_t *)v13;
    sub_24D30();
  }
  v8 = (int)v13;
  v9 = 10;
  sub_1210FD(320, 10, (int)v13);
  if ( (uint8_t)byte_199F3A >= 2u )
  {
    v9 = dword_197F98;
    if ( *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) == 100 )
    {
      v10 = strlen(byte_19A550) + 1;
      v7 = (int16_t *)&byte_19A550[v10];
      if ( v10 != 1 )
      {
        sub_120DED(248, 248);
        sub_120CCB(4, (int)&unk_180DCC);
        v8 = (int)v13;
        sprintf(v13, "%s sez: %s", (char *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 1), byte_19A550);
        v9 = 29;
        sub_1210FD(320, 29, (int)v13);
      }
    }
  }
  v11 = word_19AA44;
  if ( word_19AA44 != -1 )
  {
    v8 = 1;
    v9 = -1;
    v11 = sub_24677((int16_t)(word_19AA44 + 100), -1, 1);
  }
  sub_FE8BE(v11, v9, v8, v7);
  if ( word_19AA48 == 1 )
    sub_11C817();
  return sub_120DED(248, 248);
}
// 24D4C: using guessed type int __fastcall sub_24D4C(_DWORD, _DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19999C: using guessed type int16_t word_19999C;
// 199BE2: using guessed type char byte_199BE2;
// 199F3A: using guessed type char byte_199F3A;
// 19A298: using guessed type int dword_19A298;
// 19A2A0: using guessed type int dword_19A2A0;
// 19A64A: using guessed type char byte_19A64A;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA44: using guessed type int16_t word_19AA44;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA65: using guessed type char byte_19AA65;
// 19AA66: using guessed type char byte_19AA66;


//----- (00017227) --------------------------------------------------------
int16_t __usercall sub_17227( int a1, int a2, int a3, int16_t *a4)
{
  int v4; // ecx
  int v5; // esi
  int16_t v6; // cx
  char *v7; // esi
  char *v8; // edi
  void *v9; // edx
  int16_t v10; // ax
  int16_t v11; // cx
  char *v12; // esi
  char *v13; // edi
  int16_t v14; // ax
  int16_t v15; // dx
  uint16_t v16; // dx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int16_t *v22; // [esp-4h] [ebp-28h]
  int16_t *v23; // [esp-4h] [ebp-28h]
  _BYTE v26[16]; // [esp+8h] [ebp-1Ch] BYREF
  int v27; // [esp+18h] [ebp-Ch]
  int v28; // [esp+1Ch] [ebp-8h] BYREF
  char v29; // [esp+20h] [ebp-4h]

  v29 = a3;
  v27 = 0;
  while ( !(_WORD)v27 )
  {
    v4 = 0;
    do
    {
      v5 = (int16_t)v4++;
      v26[v5] = 1;
    }
    while ( (int16_t)v4 < 5 );
    if ( *(char *)(a2 + dword_197F98 + 3753 * a1 + 1575) < 4 )
      v26[0] = 0;
    else
      v26[1] = 0;
    v26[2] = sub_E4CD2(a1, a2);
    if ( v29 || (int16_t)sub_50FDF(a1, a2) > -100 )
    {
      if ( word_19AA48 == 1 )
        v27 = 1;
      sub_1191CA((int)sub_16F00, 2);
      sub_117174(1);
      sub_120DED(0, 248);
      sub_120D79(4, (int)&unk_180DCC);
      sub_120EB9((int)&unk_180DD4);
      sub_120F07((int)&unk_180DDC);
      sub_120E24(4);
      if ( v29 == 1 )
      {
        v6 = 0;
        do
        {
          v7 = (char *)dword_19A0E8[v6];
          v8 = &byte_19A744[50 * v6++];
          v22 = (int16_t *)v8;
          strcpy(v8, v7);
          a4 = v22;
        }
        while ( v6 < 6 );
        v9 = &unk_180E16;
        v10 = 6;
      }
      else
      {
        v11 = 0;
        do
        {
          v12 = (char *)dword_19A1E8[v11];
          v13 = &byte_19A744[50 * v11++];
          v23 = (int16_t *)v13;
          strcpy(v13, v12);
          a4 = v23;
        }
        while ( v11 < 5 );
        v9 = &unk_180E0C;
        v10 = 5;
      }
      sub_1FC13(v10, (int)v9);
      v28 = 0;
      v14 = sub_11C4C1(10, 118, 245, dword_19A2D4, byte_19A744, 50, (int16_t *)&v28, (int)v26, 17, 0, 0, 0, 0);
      v15 = v14;
      if ( v29 == 1 && v14 == 3 )
        v15 = 5;
      v16 = v15 + 1;
      switch ( v16 )
      {
        case 0u:
        case 4u:
        case 5u:
          v27 = 1;
          if ( v29 == 1 )
          {
            byte_19A190 = a1;
            byte_19A191 = a2;
            word_19AA48 = 1;
            word_19A194 = 130;
            v17 = *(int16_t *)(dword_197F98 + 3753 * a2 + 43);
            word_19A196 = -1;
            v18 = sub_F6816(v17, 2000, (int)&byte_19A190, 8u);
            sub_FE8BE(v18, 2000, (int)&byte_19A190, a4);
          }
          break;
        case 1u:
          byte_19A64A = byte_178A64;
          word_19AA36 = -1;
          a4 = (int16_t *)sub_19997(a1, a2, 3u);
          sub_524C3(a1, a2);
          if ( (_WORD)a4 == 1 )
            sub_524FB(a1, a2);
          break;
        case 2u:
          v19 = sub_179F4(a4);
          if ( (_WORD)v19 == 1 )
          {
            v27 = v19;
            sub_19919(a4);
            word_19AA48 = 1;
          }
          break;
        case 3u:
          sub_1D0F8(a4);
          if ( (_WORD)v20 == 1 )
          {
            v27 = v20;
            word_19AA48 = 1;
          }
          break;
        case 6u:
          sub_200C3((int16_t *)a2, a1, 245, v16);
          if ( word_19AA48 == 1 )
            v27 = 1;
          break;
        default:
          continue;
      }
    }
    else
    {
      if ( word_19AA40 != word_19AA36 )
        sub_19919(a4);
      word_19AA40 = 130;
      v27 = 1;
      sub_19919(a4);
    }
  }
  sub_1191CA((int)sub_16F00, 2);
  return sub_117174(1);
}
// 1750F: variable 'v20' is possibly undefined
// 178A64: using guessed type char byte_178A64;
// 197F98: using guessed type int dword_197F98;
// 19A0E8: using guessed type int dword_19A0E8[];
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19A1E8: using guessed type int dword_19A1E8[];
// 19A2D4: using guessed type int dword_19A2D4;
// 19A64A: using guessed type char byte_19A64A;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA48: using guessed type int16_t word_19AA48;


//----- (0001758C) --------------------------------------------------------
void __usercall sub_1758C(int16_t *a1)
{
  int v1; // eax
  int v2; // edx
  int16_t v3; // dx
  char *v4; // esi
  char *v5; // edi
  int v6; // eax
  int v7; // eax
  int16_t *v8; // [esp-4h] [ebp-1Ch]
  _BYTE v9[16]; // [esp+0h] [ebp-18h] BYREF
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h] BYREF

  v10 = 0;
  if ( *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) != 100 )
    sub_26D19(word_19999C, (uint8_t)byte_19AA66, &word_19AA4C, (int)byte_19A2DC, (int)byte_19A3B0);
  while ( !(_WORD)v10 )
  {
    v1 = 0;
    do
    {
      v2 = (int16_t)v1++;
      v9[v2] = 1;
    }
    while ( (int16_t)v1 < 9 );
    sub_1692A2(word_19999C, (uint8_t)byte_19AA66, v9);
    if ( (int16_t)sub_50FDF(word_19999C, (uint8_t)byte_19AA66) > -100 )
    {
      sub_1191CA((int)sub_16F00, 2);
      sub_117174(1);
      v3 = 0;
      do
      {
        v4 = (char *)dword_19A248[v3];
        v5 = &byte_19A744[50 * v3++];
        v8 = (int16_t *)v5;
        strcpy(v5, v4);
        a1 = v8;
      }
      while ( v3 < 9 );
      sub_120DED(0, 248);
      sub_120D79(4, (int)&unk_180DCC);
      sub_120EB9((int)&unk_180DD4);
      sub_120F07((int)&unk_180DDC);
      sub_120E24(4);
      sub_1FC13(9, (int)&unk_180DE4);
      v11 = 0;
      switch ( (uint16_t)sub_11C4C1(
                                   10,
                                   118,
                                   245,
                                   dword_19A2D4,
                                   byte_19A744,
                                   50,
                                   (int16_t *)&v11,
                                   (int)v9,
                                   17,
                                   0,
                                   0,
                                   0,
                                   0) )
      {
        case 0xFFFF:
        case 7u:
          v10 = 1;
          continue;
        case 0u:
          byte_19A64A = byte_178A64;
          sub_17D5B(word_19999C, (uint8_t)byte_19AA66);
          continue;
        case 1u:
          byte_19A64A = byte_178A64;
          sub_180D4(word_19999C, (uint8_t)byte_19AA66);
          continue;
        case 2u:
          byte_19A64A = byte_178A64;
          sub_18B79();
          continue;
        case 3u:
          byte_19A64A = byte_178A64;
          sub_194C5();
          continue;
        case 4u:
          byte_19A64A = byte_178A64;
          sub_1CB4D(word_19999C, (uint8_t)byte_19AA66);
          continue;
        case 5u:
          v6 = sub_179F4(a1);
          if ( (_WORD)v6 != 1 )
            continue;
          v10 = v6;
          break;
        case 6u:
          sub_1D0F8(a1);
          if ( (_WORD)v7 == 1 )
            v10 = v7;
          continue;
        default:
          continue;
      }
    }
    else
    {
      if ( word_19AA40 != word_19AA36 )
        sub_19919(a1);
      word_19AA40 = 130;
      v10 = 1;
    }
    sub_19919(a1);
  }
  sub_1191CA((int)sub_16F00, 2);
  sub_117174(1);
  JUMPOUT(0x17204);
}
// 17842: control flows out of bounds to 17204
// 1781B: variable 'v7' is possibly undefined
// 178A64: using guessed type char byte_178A64;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19A248: using guessed type int dword_19A248[];
// 19A2D4: using guessed type int dword_19A2D4;
// 19A64A: using guessed type char byte_19A64A;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA4C: using guessed type int16_t word_19AA4C;
// 19AA66: using guessed type char byte_19AA66;


//----- (00017847) --------------------------------------------------------
_BOOL1 __fastcall sub_17847( int a1, int a2, _BYTE *a3)
{
  int v3; // ecx
  _BYTE *v4; // eax
  _BOOL1 result; // al
  int16_t v6; // [esp+0h] [ebp+76h]
  int16_t v7; // [esp+4h] [ebp+7Ah]
  _DWORD v8[212]; // [esp+8h] [ebp+7Eh] BYREF
  int v9; // [esp+358h] [ebp+3CEh]
  int16_t v10; // [esp+35Ch] [ebp+3D2h] BYREF

  if ( *(char *)(a2 + dword_197F98 + 3753 * a1 + 1575) < 4 )
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) == 100 )
    {
      v9 = v7;
      word_19AA4C = 0;
      sub_27094(v6, v7, 0, 0xC343CB00, byte_19A2DC, v8, &v10, 1);
      if ( v10 > 0 )
        sub_27094(v9, v6, 0, 0xC343CB00, byte_19A2DC, v8, &word_19AA4C, 1);
    }
    a3[4] = 0;
    if ( word_19AA4C > 0 )
      a3[4] = 1;
  }
  else
  {
    a3[1] = 0;
    a3[5] = 0;
    a3[2] = 0;
    a3[4] = 0;
  }
  v3 = 3753 * v7 + dword_197F98;
  v4 = (_BYTE *)(v3 + v6);
  a3[1] = 0;
  if ( v4[1583] == 1 || v4[1591] == 1 || *(int16_t *)(v3 + 2 * v6 + 1599) > 0 || v4[1575] == 1 || v4[1575] == 2 )
    a3[1] = 1;
  if ( !(uint16_t)sub_5265E(v7, v6, 7u)
    && !(uint16_t)sub_5265E(v7, v6, 8u)
    && !(uint16_t)sub_5265E(v7, v6, 3u)
    && !(uint16_t)sub_5265E(v7, v6, 1u)
    && !(uint16_t)sub_5265E(v7, v6, 2u) )
  {
    *a3 = 0;
  }
  a3[6] = 0;
  result = sub_E4CD2(v7, v6);
  if ( result )
    a3[6] = 1;
  return result;
}
// 178BF: variable 'v7' is possibly undefined
// 178D2: variable 'v6' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 19AA4C: using guessed type int16_t word_19AA4C;


//----- (000179F4) --------------------------------------------------------
int __usercall sub_179F4(int16_t *a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax
  int16_t v5; // [esp+0h] [ebp+76h]
  int16_t v6; // [esp+4h] [ebp+7Ah]
  char v7[400]; // [esp+8h] [ebp+7Eh] BYREF
  char v8[80]; // [esp+198h] [ebp+20Eh] BYREF

  sub_1FD06(614);
  sub_249F9(aJimtext2Lbx, 59, v7, 40);
  sub_249F9(aJimtext2Lbx, 60, v8, 80);
  v1 = 0;
  if ( (int16_t)sub_19DE8(1, (int)v7, 1, (int)v8) != -1 )
  {
    v1 = 1;
    if ( *(_BYTE *)(3753 * v5 + dword_197F98 + 40) == 100 )
    {
      if ( byte_199F3A == 1 )
      {
        sub_1B881(v6);
        sub_18596();
        sub_19919(a1);
        sub_1B881(v5);
      }
      else
      {
        byte_19A190 = v6;
        byte_19A191 = v5;
        word_19A196 = word_19AA40;
        word_19A192 = 0;
        v2 = *(int16_t *)(dword_197F98 + 3753 * v5 + 43);
        word_19A194 = 1002;
        v3 = sub_F6816(v2, 2000, (int)&byte_19A190, 8u);
        sub_FE8BE(v3, 2000, (int)&byte_19A190, a1);
      }
      word_19AA40 = 160;
    }
    else
    {
      sub_536BC(v6, v5, &word_19AA40);
    }
    sub_51078(v6, v5);
    sub_524C3(v6, v5);
  }
  return v1;
}
// 17A5F: variable 'v5' is possibly undefined
// 17A93: variable 'v6' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (00017B51) --------------------------------------------------------
void *sub_17B51()
{
  int16_t v0; // ax

  v0 = 2 * *(uint8_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 37);
  word_19994C = 0;
  sub_12C607((int)aDiplomatLbx_0, (int16_t)(v0 + 13), 639, 479);
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  sub_12C7CC();
  return sub_124DEC();
}
// 197F98: using guessed type int dword_197F98;
// 19994C: using guessed type int16_t word_19994C;
// 19AA66: using guessed type char byte_19AA66;


//----- (00017BB2) --------------------------------------------------------
int __fastcall sub_17BB2(int a1, int a2, int a3, int a4)
{
  int16_t v4; // bx
  int result; // eax

  v4 = a1;
  sub_12C607(
    (int)aDiplomatLbx_0,
    (int16_t)(2 * *(uint8_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 37) + 14),
    a1,
    a4);
  result = sub_12D6B2(v4 == 0);
  if ( !byte_199BE2 )
    return sub_12CD2D();
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199BE2: using guessed type char byte_199BE2;
// 19AA66: using guessed type char byte_19AA66;


//----- (00017C07) --------------------------------------------------------
/* DECOMP_TODO: dekompilace selhala (call analysis failed (funcsize=67)) - nutno dohledat rucne v IDA @ 0x17C32 */
int sub_17C07(void)
{
  DECOMP_TODO("call analysis failed (funcsize=67)");
}


//----- (00017D1D) --------------------------------------------------------
int sub_17D1D()
{
  sub_124D41();
  sub_12CD2D();
  return sub_24677((int16_t)(word_19AA44 + 100), -1, 1);
}
// 19AA44: using guessed type int16_t word_19AA44;


//----- (00017D5B) --------------------------------------------------------
void __fastcall sub_17D5B( int a1, int a2)
{
  int v2; // eax
  int v3; // ecx
  int16_t v4; // cx
  char *v5; // esi
  char *v6; // edi
  int16_t v7; // di
  int16_t v8; // bx
  int16_t v9; // ax
  _BYTE v11[16]; // [esp+8h] [ebp-18h] BYREF
  int v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h] BYREF

  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    v11[v3] = 1;
  }
  while ( (int16_t)v2 < 7 );
  v11[0] = sub_5265E(a1, a2, 7u);
  v11[1] = sub_5265E(a1, a2, 8u);
  v11[2] = sub_5265E(a1, a2, 3u);
  v11[3] = sub_5265E(a1, a2, 1u);
  v11[4] = sub_5265E(a1, a2, 2u);
  sub_1191CA((int)sub_16F00, 2);
  v4 = 0;
  sub_117174(1);
  do
  {
    v5 = (char *)dword_19A1A0[v4];
    v6 = &byte_19A744[50 * v4++];
    strcpy(v6, v5);
  }
  while ( v4 < 7 );
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  sub_1FC13(7, (int)&unk_180E22);
  v7 = 0;
  v13 = 0;
  switch ( (uint16_t)sub_11C4C1(
                               10,
                               118,
                               245,
                               dword_19A19C,
                               byte_19A744,
                               50,
                               (int16_t *)&v13,
                               (int)v11,
                               17,
                               0,
                               0,
                               0,
                               0) )
  {
    case 0u:
      word_19AA36 = -1;
      v7 = sub_19997(a1, a2, 7u);
      sub_524C3(a1, a2);
      *(_WORD *)(2 * a2 + dword_197F98 + 3753 * a1 + 1695) -= 20;
      if ( v7 == 1 )
        sub_5223F(a1, a2);
      break;
    case 1u:
      word_19AA36 = -1;
      v7 = sub_19997(a1, a2, 8u);
      sub_524C3(a1, a2);
      *(_WORD *)(2 * a2 + dword_197F98 + 3753 * a1 + 1695) -= 20;
      if ( v7 == 1 )
        sub_52150(a1, a2);
      break;
    case 2u:
      word_19AA36 = -1;
      v7 = sub_19997(a1, a2, 3u);
      sub_524C3(a1, a2);
      v12 = 3753 * a1;
      *(_WORD *)(2 * a2 + v12 + dword_197F98 + 1727) -= 20;
      if ( v7 == 1 )
        sub_524FB(a1, a2);
      break;
    case 3u:
      word_19AA36 = -1;
      v7 = sub_19997(a1, a2, 1u);
      sub_524C3(a1, a2);
      *(_WORD *)(3753 * a1 + dword_197F98 + 2 * a2 + 1679) -= 20;
      if ( v7 == 1 )
      {
        v8 = 1;
        v9 = a1;
        goto LABEL_18;
      }
      break;
    case 4u:
      word_19AA36 = -1;
      v7 = sub_19997(a1, a2, 2u);
      sub_524C3(a1, a2);
      *(_WORD *)(3753 * a1 + dword_197F98 + 2 * a2 + 1679) -= 20;
      if ( v7 == 1 )
      {
        v8 = 2;
        v9 = a1;
LABEL_18:
        sub_5232E(v9, a2, v8);
      }
      break;
    default:
      break;
  }
  if ( v7 == 1 && *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) != 100 )
    sub_26D19(a1, a2, &word_19AA4C, (int)&byte_19A2DC, (int)&byte_19A3B0);
}
// 197F98: using guessed type int dword_197F98;
// 19A19C: using guessed type int dword_19A19C;
// 19A1A0: using guessed type int dword_19A1A0[];
// 19A2DC: using guessed type char byte_19A2DC;
// 19A3B0: using guessed type char byte_19A3B0;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA4C: using guessed type int16_t word_19AA4C;


//----- (000180D4) --------------------------------------------------------
void __fastcall sub_180D4( int a1, int a2)
{
  int v2; // eax
  int v3; // edx
  int16_t v4; // dx
  char *v5; // esi
  char *v6; // edi
  int16_t *v7; // edi
  int16_t v8; // dx
  int16_t v9; // ax
  uint16_t v10; // bx
  int16_t *v11; // [esp-4h] [ebp-20h]
  _BYTE v14[16]; // [esp+8h] [ebp-14h] BYREF
  int v15; // [esp+18h] [ebp-4h] BYREF

  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    v14[v3] = 0;
  }
  while ( (int16_t)v2 < 7 );
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1583) == 1 )
    v14[0] = 1;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1591) == 1 )
    v14[1] = 1;
  if ( *(int16_t *)(3753 * a1 + dword_197F98 + 2 * a2 + 1599) > 0 )
    v14[2] = 1;
  if ( *(_BYTE *)(3753 * a1 + dword_197F98 + a2 + 1575) == 1 )
    v14[3] = 1;
  if ( *(_BYTE *)(a2 + dword_197F98 + 3753 * a1 + 1575) == 2 )
    v14[4] = 1;
  v14[5] = 1;
  sub_1191CA((int)sub_16F00, 2);
  sub_117174(1);
  v4 = 0;
  do
  {
    v5 = (char *)dword_19A200[v4];
    v6 = &byte_19A744[50 * v4++];
    v11 = (int16_t *)v6;
    strcpy(v6, v5);
    v7 = v11;
  }
  while ( v4 < 7 );
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  sub_1FC13(7, (int)&unk_180E30);
  v15 = 0;
  switch ( (uint16_t)sub_11C4C1(
                               10,
                               118,
                               245,
                               dword_19A1FC,
                               byte_19A744,
                               50,
                               (int16_t *)&v15,
                               (int)v14,
                               17,
                               0,
                               0,
                               0,
                               0) )
  {
    case 0u:
      v8 = a2;
      v9 = a1;
      v10 = 7;
      goto LABEL_17;
    case 1u:
      v8 = a2;
      v9 = a1;
      v10 = 8;
      goto LABEL_17;
    case 2u:
      v9 = a1;
      v8 = a2;
      word_19AA36 = -1;
      if ( *(_WORD *)(dword_197F98 + 3753 * a1 + 2 * a2 + 1599) == 1 )
        v10 = 9;
      else
        v10 = 10;
      goto LABEL_24;
    case 3u:
      v8 = a2;
      v9 = a1;
      v10 = 1;
LABEL_17:
      word_19AA36 = -1;
      goto LABEL_24;
    case 4u:
      v8 = a2;
      v9 = a1;
      v10 = 2;
      word_19AA36 = -1;
LABEL_24:
      sub_18309(v9, v8, v10, v7);
      break;
    default:
      break;
  }
  JUMPOUT(0x17F39);
}
// 1826D: control flows out of bounds to 17F39
// 197F98: using guessed type int dword_197F98;
// 19A1FC: using guessed type int dword_19A1FC;
// 19A200: using guessed type int dword_19A200[];
// 19AA36: using guessed type int16_t word_19AA36;


//----- (00018309) --------------------------------------------------------
void __usercall sub_18309( int a1, int a2, unsigned int a3, int16_t *a4)
{
  int v4; // eax
  int v5; // eax

  if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) == 100 )
  {
    if ( byte_199F3A == 1 )
    {
      sub_1B881(a1);
      sub_1883A(a2, a3);
      word_19AA40 = 0;
      word_19AA36 = 0;
      sub_19919(a4);
      sub_1B881(a2);
    }
    else
    {
      byte_19A190 = a1;
      byte_19A191 = a2;
      word_19A196 = word_19AA40;
      word_19A194 = 1001;
      v4 = *(int16_t *)(dword_197F98 + 3753 * a2 + 43);
      word_19A192 = a3;
      v5 = sub_F6816(v4, 2000, (int)&byte_19A190, 8u);
      sub_FE8BE(v5, 2000, (int)&byte_19A190, a4);
    }
  }
  if ( a3 < 7u )
  {
    if ( !a3 )
      return;
    if ( a3 <= 1u )
    {
      sub_5138E(a1, a2);
      if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) != 100 )
        goto LABEL_26;
    }
    else
    {
      if ( a3 != 2 )
        return;
      sub_5138E(a1, a2);
      if ( *(_BYTE *)(dword_197F98 + 3753 * a2 + 40) != 100 )
      {
LABEL_26:
        sub_533F4(a1, a2, &word_19AA40);
        return;
      }
    }
    word_19AA40 = 153;
    return;
  }
  if ( a3 <= 7u )
  {
    sub_519AC(a1, a2);
    if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 40) == 100 )
      word_19AA40 = 156;
    else
      sub_5356C(a1, a2, &word_19AA40);
  }
  else if ( a3 <= 8u )
  {
    sub_5175B(a1, a2);
    if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 40) == 100 )
      word_19AA40 = 158;
    else
      sub_534C9(a1, a2, &word_19AA40);
  }
  else if ( a3 <= 0xAu )
  {
    sub_51C02(a1, a2);
    if ( *(_BYTE *)(3753 * a2 + dword_197F98 + 40) == 100 )
      word_19AA40 = 171;
    else
      sub_5360F(a1, a2, &word_19AA40);
  }
}
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (00018560) --------------------------------------------------------
void sub_18560()
{
  sub_249F9(aJimtext2Lbx, 13, &byte_19A64A, 250);
  sub_24D30();
}
// 19A64A: using guessed type char byte_19A64A;


//----- (00018596) --------------------------------------------------------
void sub_18596()
{
  JUMPOUT(0x18575);
}
// 185AB: control flows out of bounds to 18575


//----- (000185BD) --------------------------------------------------------
void __fastcall sub_185BD( int a1, int a2, int a3)
{
  switch ( a2 )
  {
    case 1:
      sub_249F9(aJimtext2Lbx, 18, &byte_19A64A, 250);
      a3 = (int16_t)a3;
      goto LABEL_8;
    case 2:
      sub_249F9(aJimtext2Lbx, 15, &byte_19A64A, 250);
      if ( (_WORD)a3 == 1 )
        a3 = 5;
      else
        a3 = 10;
LABEL_8:
      sub_24D4C(&byte_19A64A, a1, a3, 250);
      break;
    case 3:
      sub_249F9(aJimtext2Lbx, 16, &byte_19A64A, 250);
      sub_24D83();
      break;
    case 4:
      sub_249F9(aJimtext2Lbx, 17, &byte_19A64A, 250);
      sub_24D6A();
      break;
    default:
      return;
  }
}
// 24D4C: using guessed type int __fastcall sub_24D4C(_DWORD, _DWORD, _DWORD, _DWORD);
// 19A64A: using guessed type char byte_19A64A;


//----- (000186D3) --------------------------------------------------------
void __fastcall sub_186D3( int a1, int a2, int a3)
{
  int v4; // edx
  int v5; // ebx
  int v6; // edx

  switch ( a3 )
  {
    case 0:
      v4 = 19;
      goto LABEL_3;
    case 1:
      v4 = 20;
      goto LABEL_3;
    case 2:
      v4 = 21;
LABEL_3:
      sub_249F9(aJimtext2Lbx, v4, &byte_19A64A, 250);
      sub_24DF0();
      return;
    case 3:
      sub_249F9(aJimtext2Lbx, 22, &byte_19A64A, 250);
      v5 = 5;
      goto LABEL_7;
    case 4:
      sub_249F9(aJimtext2Lbx, 22, &byte_19A64A, 250);
      v5 = 10;
LABEL_7:
      sub_24D4C(&byte_19A64A, a1, v5, 250);
      return;
    case 5:
      v6 = 23;
      goto LABEL_13;
    case 6:
      sub_249F9(aJimtext2Lbx, 24, &byte_19A64A, 250);
      sub_24D83();
      return;
    case 7:
      sub_249F9(aJimtext2Lbx, 25, &byte_19A64A, 250);
      sub_24D6A();
      return;
    case 8:
      v6 = 26;
LABEL_13:
      sub_249F9(aJimtext2Lbx, v6, &byte_19A64A, 250);
      sub_24D30();
      break;
    default:
      return;
  }
}
// 24D4C: using guessed type int __fastcall sub_24D4C(_DWORD, _DWORD, _DWORD, _DWORD);
// 19A64A: using guessed type char byte_19A64A;


//----- (0001883A) --------------------------------------------------------
void __fastcall sub_1883A(int a1, unsigned int a2)
{
  int v2; // edx

  if ( a2 >= 7u )
  {
    if ( a2 <= 7u )
    {
      v2 = 27;
    }
    else if ( a2 <= 8u )
    {
      v2 = 28;
    }
    else
    {
      if ( a2 > 0xAu )
        return;
      v2 = 29;
    }
LABEL_15:
    sub_249F9(aJimtext2Lbx, v2, &byte_19A64A, 250);
    sub_24D30();
    return;
  }
  if ( !a2 )
    return;
  if ( a2 <= 1u )
  {
    v2 = 30;
    goto LABEL_15;
  }
  if ( a2 == 2 )
  {
    v2 = 31;
    goto LABEL_15;
  }
}
// 19A64A: using guessed type char byte_19A64A;


//----- (000188E0) --------------------------------------------------------
char __fastcall sub_188E0(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // edx
  char result; // al

  if ( a3 >= 7u )
  {
    if ( a3 <= 7u )
    {
      if ( a4 == 3 )
        v4 = 32;
      else
        v4 = 33;
    }
    else if ( a3 <= 8u )
    {
      if ( a4 == 3 )
        v4 = 34;
      else
        v4 = 35;
    }
    else
    {
      if ( a3 > 0xAu )
        return result;
      if ( a4 == 3 )
        v4 = 36;
      else
        v4 = 37;
    }
    return sub_249F9(aJimtext2Lbx, v4, &byte_19A64A, 250);
  }
  if ( a3 )
  {
    if ( a3 <= 1u )
    {
      if ( a4 == 3 )
        v4 = 38;
      else
        v4 = 39;
      return sub_249F9(aJimtext2Lbx, v4, &byte_19A64A, 250);
    }
    if ( a3 == 2 )
    {
      if ( a4 == 3 )
        v4 = 40;
      else
        v4 = 41;
      return sub_249F9(aJimtext2Lbx, v4, &byte_19A64A, 250);
    }
  }
  return result;
}
// 19A64A: using guessed type char byte_19A64A;


//----- (000189EC) --------------------------------------------------------
char __fastcall sub_189EC( unsigned int a1)
{
  int v1; // edx

  if ( a1 >= 3u )
  {
    if ( a1 <= 3u )
    {
      v1 = 66;
    }
    else if ( a1 < 8u )
    {
      if ( a1 != 7 )
        return a1;
      v1 = 42;
    }
    else if ( a1 <= 8u )
    {
      v1 = 43;
    }
    else
    {
      if ( a1 > 0xAu )
        return a1;
      v1 = 44;
    }
    goto LABEL_17;
  }
  if ( a1 )
  {
    if ( a1 <= 1u )
      v1 = 45;
    else
      v1 = 46;
LABEL_17:
    LOBYTE(a1) = sub_249F9(aJimtext2Lbx, v1, &byte_19A64A, 250);
  }
  return a1;
}
// 19A64A: using guessed type char byte_19A64A;


//----- (00018A97) --------------------------------------------------------
int __fastcall sub_18A97(int a1, int a2, int a3)
{
  sub_249F9(aJimtext2Lbx, 47, &byte_19A64A, 250);
  return sub_24DC5(a3, 250);
}
// 24DC5: using guessed type _DWORD __stdcall sub_24DC5(int16_t, int16_t);
// 19A64A: using guessed type char byte_19A64A;


//----- (00018AE2) --------------------------------------------------------
int sub_18AE2()
{
  sub_249F9(aJimtext2Lbx, 48, &byte_19A64A, 250);
  return sub_24D9C(250);
}
// 24D9C: using guessed type _DWORD __stdcall sub_24D9C(int16_t);
// 19A64A: using guessed type char byte_19A64A;


//----- (00018B27) --------------------------------------------------------
void sub_18B27()
{
  JUMPOUT(0x18A89);
}
// 18B39: control flows out of bounds to 18A89


//----- (00018B3E) --------------------------------------------------------
void sub_18B3E()
{
  JUMPOUT(0x18A89);
}
// 18B50: control flows out of bounds to 18A89


//----- (00018B79) --------------------------------------------------------
void sub_18B79()
{
  int v0; // eax
  int v1; // edx
  int v2; // eax
  int16_t v3; // ax
  int16_t v4; // dx
  char *v5; // esi
  char *v6; // edi
  char v7; // al
  int v8; // edi
  int64_t v9; // rax
  int v10; // edi
  int16_t v11; // si
  int16_t v12; // dx
  int16_t v13; // bx
  int16_t v14; // cx
  int16_t v15; // ax
  int64_t v16; // rax
  int64_t v17; // rax
  int16_t v18; // si
  int v19; // esi
  int v20; // edi
  int v21; // eax
  char *v22; // [esp-4h] [ebp-5C6h]
  int v23; // [esp+0h] [ebp-5C2h]
  int16_t v24; // [esp+0h] [ebp-5C2h]
  int v25; // [esp+4h] [ebp-5BEh]
  int16_t v26; // [esp+4h] [ebp-5BEh]
  int v27[13]; // [esp+8h] [ebp-5BAh] BYREF
  hr_int128_t v28; // [esp+3Ch] [ebp-586h]
  int64_t v29; // [esp+4Ch] [ebp-576h]
  int64_t v30; // [esp+54h] [ebp-56Eh]
  int64_t v31; // [esp+5Ch] [ebp-566h]
  int v32; // [esp+64h] [ebp-55Eh]
  int v33; // [esp+68h] [ebp-55Ah]
  int v34; // [esp+6Ch] [ebp-556h]
  int64_t v35; // [esp+70h] [ebp-552h]
  _QWORD v36[50]; // [esp+358h] [ebp-26Ah] BYREF
  char v37[88]; // [esp+4E8h] [ebp-DAh] BYREF
  int v38; // [esp+540h] [ebp-82h] BYREF
  char v39[40]; // [esp+5BCh] [ebp-6h] BYREF
  _BYTE v40[3]; // [esp+5E4h] [ebp+22h] BYREF
  char v41; // [esp+5E7h] [ebp+25h]
  char v42; // [esp+5E8h] [ebp+26h]
  char v43; // [esp+5E9h] [ebp+27h]
  char v44; // [esp+5EAh] [ebp+28h]
  char v45; // [esp+5EBh] [ebp+29h]
  char v46; // [esp+5ECh] [ebp+2Ah]
  char v47; // [esp+5EDh] [ebp+2Bh]
  _BYTE v48[12]; // [esp+5F4h] [ebp+32h] BYREF
  _BYTE v49[12]; // [esp+600h] [ebp+3Eh] BYREF
  _BYTE v50[12]; // [esp+60Ch] [ebp+4Ah] BYREF
  int16_t v51; // [esp+618h] [ebp+56h] BYREF
  int16_t v52; // [esp+61Ch] [ebp+5Ah] BYREF
  int16_t v53; // [esp+620h] [ebp+5Eh] BYREF
  int v54; // [esp+624h] [ebp+62h]
  int v55; // [esp+628h] [ebp+66h]
  int v56; // [esp+62Ch] [ebp+6Ah]
  int16_t v57; // [esp+630h] [ebp+6Eh] BYREF
  int16_t v58; // [esp+634h] [ebp+72h] BYREF
  int v59; // [esp+638h] [ebp+76h]
  int v60; // [esp+63Ch] [ebp+7Ah]
  int v61; // [esp+640h] [ebp+7Eh] BYREF

  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    v40[v1] = 0;
  }
  while ( (int16_t)v0 < 11 );
  sub_1A44D(v25, v23, 5u, &v51, (int)v49);
  if ( v51 > 0 )
    v40[0] = 1;
  if ( !byte_199F3A )
  {
    sub_1A44D(v25, v23, 3u, &v58, (int)v50);
    if ( v58 > 0 )
      v40[1] = 1;
  }
  sub_1A44D(v25, v23, 2u, &v57, (int)v48);
  if ( v57 > 0 )
    v40[2] = 1;
  v2 = dword_197F98 + 3753 * (int16_t)v23 + 2 * (int16_t)v25;
  v41 = 1;
  v42 = 1;
  if ( *(int16_t *)(v2 + 1599) > 0 || *(int16_t *)(3753 * (int16_t)v25 + dword_197F98 + 2 * (int16_t)v23 + 1599) > 0 )
    goto LABEL_15;
  if ( *(_WORD *)(v2 + 1599) == 1 )
  {
    v41 = 0;
    goto LABEL_16;
  }
  if ( *(_WORD *)(v2 + 1599) == 2 )
  {
LABEL_15:
    v41 = 0;
    v42 = 0;
  }
LABEL_16:
  v43 = 1;
  sub_27094(v25, v23, 0, 0xC343CB00, v37, v27, &v52, 1);
  if ( v52 > 0 )
    v44 = 1;
  sub_1692C7(v23, v25, (int)&v38);
  if ( v3 == 1 )
    v45 = 1;
  if ( sub_1009C3((int16_t)v23, v25) == 1 )
    v46 = 1;
  v47 = 1;
  sub_1191CA((int)sub_16F00, 2);
  sub_117174(1);
  v4 = 0;
  do
  {
    v5 = (char *)dword_19A1BC[v4];
    v6 = &byte_19A744[50 * v4++];
    v22 = v6;
    do
    {
      v7 = *v5++;
      *v6++ = v7;
    }
    while ( v7 );
    v8 = (int)v22;
  }
  while ( v4 < 11 );
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  sub_1FC13(11, (int)&unk_180E3E);
  v61 = 0;
  switch ( (uint16_t)sub_11C4C1(
                               10,
                               118,
                               245,
                               dword_19A228,
                               byte_19A744,
                               50,
                               (int16_t *)&v61,
                               (int)v40,
                               17,
                               0,
                               0,
                               0,
                               0) )
  {
    case 0u:
      WORD2(v9) = 0;
      while ( SWORD2(v9) < v51 )
        v9 = sprintf(
               &v36[5 * SWORD2(v9)],
               "  %s",
               (char *)(3753 * (uint8_t)v49[SWORD2(v9)] + dword_197F98 + 1));
      sub_249F9(aJimtextLbx_0, 71, v39, 40);
      v59 = sub_19DE8(v51, (int)v36, 1, (int)v39);
      if ( (int16_t)v59 != -1 )
      {
        word_19AA36 = -1;
        if ( *(_BYTE *)(3753 * (int16_t)v23 + dword_197F98 + 40) == 100 )
          sub_1B5B8(v25, v23, (uint8_t)v49[(int16_t)v59], 0, v8, (int16_t)v5, &v53);
        else
          sub_539D9(v25, v23, 0, (uint8_t)v49[(int16_t)v59], &v53, &word_19AA40);
        v10 = (int16_t)v23;
        v11 = v25;
        sub_524C3(v25, v23);
        if ( v53 == 1 )
        {
          v12 = v23;
          v13 = 0;
          v14 = (uint8_t)v49[(int16_t)v59];
          goto LABEL_36;
        }
      }
      break;
    case 1u:
      WORD2(v16) = 0;
      while ( SWORD2(v16) < v58 )
        v16 = sprintf(
                &v36[5 * SWORD2(v16)],
                "  %s",
                (char *)(dword_197F98 + 3753 * (uint8_t)v50[SWORD2(v16)] + 1));
      sub_249F9(aJimtextLbx_0, 72, v39, 40);
      v60 = sub_19DE8(v58, (int)v36, 1, (int)v39);
      if ( (int16_t)v60 != -1 )
      {
        word_19AA36 = -1;
        if ( *(_BYTE *)(3753 * (int16_t)v23 + dword_197F98 + 40) == 100 )
          sub_1B5B8(v25, v23, (uint8_t)v50[(int16_t)v60], 1, v8, (int16_t)v5, &v53);
        else
          sub_539D9(v25, v23, 1, (uint8_t)v50[(int16_t)v60], &v53, &word_19AA40);
        v10 = (int16_t)v25;
        sub_524C3(v25, v23);
        if ( v53 == 1 )
        {
          v13 = 1;
          v12 = v23;
          v14 = (uint8_t)v50[(int16_t)v60];
          goto LABEL_46;
        }
      }
      break;
    case 2u:
      WORD2(v17) = 0;
      while ( SWORD2(v17) < v57 )
        v17 = sprintf(
                &v36[5 * SWORD2(v17)],
                "  %s",
                (char *)(dword_197F98 + 3753 * (uint8_t)v48[SWORD2(v17)] + 1));
      sub_249F9(aJimtextLbx_0, 73, v39, 40);
      v54 = sub_19DE8(v57, (int)v36, 1, (int)v39);
      if ( (int16_t)v54 != -1 )
      {
        word_19AA36 = -1;
        if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v23 + 40) == 100 )
          sub_1B5B8(v25, v23, (uint8_t)v48[(int16_t)v54], 2, v8, (int16_t)v5, &v53);
        else
          sub_539D9(v25, v23, 2, (uint8_t)v48[(int16_t)v54], &v53, &word_19AA40);
        v10 = (int16_t)v25;
        sub_524C3(v25, v23);
        if ( v53 == 1 )
        {
          v13 = 2;
          v12 = v23;
          v14 = (uint8_t)v48[(int16_t)v54];
          goto LABEL_46;
        }
      }
      break;
    case 3u:
      word_19AA36 = -1;
      if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v23 + 40) == 100 )
        sub_1B5B8(v25, v23, 0, 3, v8, (int16_t)v5, &v53);
      else
        sub_539D9(v25, v23, 3, 0, &v53, &word_19AA40);
      v10 = (int16_t)v23;
      v18 = v25;
      sub_524C3(v25, v23);
      if ( v53 == 1 )
      {
        v13 = 3;
        goto LABEL_61;
      }
      break;
    case 4u:
      word_19AA36 = -1;
      if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v23 + 40) == 100 )
        sub_1B5B8(v25, v23, 0, 4, v8, (int16_t)v5, &v53);
      else
        sub_539D9(v25, v23, 4, 0, &v53, &word_19AA40);
      v10 = (int16_t)v23;
      v18 = v25;
      sub_524C3(v25, v23);
      if ( v53 == 1 )
      {
        v13 = 4;
        goto LABEL_61;
      }
      break;
    case 5u:
      word_19AA36 = -1;
      if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v23 + 40) == 100 )
        sub_1B5B8(v25, v23, 0, 5, v8, (int16_t)v5, &v53);
      else
        sub_539D9(v25, v23, 5, 0, &v53, &word_19AA40);
      sub_524C3(v25, v23);
      break;
    case 6u:
      v19 = (int16_t)v23;
      v20 = (int16_t)v25;
      v55 = sub_19F26(
              v52,
              0,
              v23,
              v25,
              v27[0],
              v27[1],
              v27[2],
              v27[3],
              v27[4],
              v27[5],
              v27[6],
              v27[7],
              v27[8],
              v27[9],
              v27[10],
              v27[11],
              v27[12],(int)LODWORD(v28),
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35);
      if ( (int16_t)v55 != -1 )
      {
        word_19AA36 = -1;
        if ( *(_BYTE *)(dword_197F98 + 3753 * v19 + 40) == 100 )
          sub_1B5B8(v20, v19, (uint8_t)v37[(int16_t)v55], 6, v20, v19, &v53);
        else
          sub_539D9(v20, v19, 6, (uint8_t)v37[(int16_t)v55], &v53, &word_19AA40);
        v10 = v24;
        v11 = v26;
        sub_524C3(v26, v24);
        if ( v53 == 1 )
        {
          v13 = 6;
          v12 = v24;
          v14 = (uint8_t)v37[(int16_t)v55];
LABEL_36:
          v15 = v11;
          goto LABEL_62;
        }
      }
      break;
    case 7u:
      v21 = sub_1C479(v23, v25, 1);
      v56 = v21;
      if ( (int16_t)v21 != -1 )
      {
        word_19AA36 = -1;
        if ( *(_BYTE *)(3753 * (int16_t)v23 + dword_197F98 + 40) == 100 )
          sub_1B5B8(v25, v23, v21, 7, (int16_t)v25, v23, &v53);
        else
          sub_539D9(v25, v23, 7, v21, &v53, &word_19AA40);
        v10 = (int16_t)v25;
        sub_524C3(v25, v23);
        if ( v53 == 1 )
        {
          v14 = v56;
          v13 = 7;
          v12 = v23;
LABEL_46:
          v15 = v10;
          goto LABEL_62;
        }
      }
      break;
    case 8u:
      word_19AA36 = -1;
      if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v23 + 40) == 100 )
        sub_1B5B8(v25, v23, 0, 8, v8, (int16_t)v5, &v53);
      else
        sub_539D9(v25, v23, 8, 0, &v53, &word_19AA40);
      v10 = (int16_t)v23;
      v18 = v25;
      sub_524C3(v25, v23);
      if ( v53 == 1 )
      {
        v13 = 8;
LABEL_61:
        v12 = v10;
        v15 = v18;
        v14 = 0;
LABEL_62:
        sub_1B487(v15, v12, v14, v13, v10);
      }
      break;
    default:
      return;
  }
}
// 18BB4: variable 'v25' is possibly undefined
// 18BB4: variable 'v23' is possibly undefined
// 18CE0: variable 'v3' is possibly undefined
// 19340: variable 'v24' is possibly undefined
// 19347: variable 'v26' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A1BC: using guessed type int dword_19A1BC[];
// 19A228: using guessed type int dword_19A228;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (000194C5) --------------------------------------------------------
void sub_194C5()
{
  int v0; // eax
  int v1; // ebx
  int v2; // ebx
  int16_t v3; // ax
  int16_t v4; // bx
  char *v5; // esi
  char *v6; // edi
  int16_t v7; // si
  int v8; // edi
  int16_t v9; // cx
  int16_t v10; // bx
  int16_t v11; // dx
  int16_t v12; // ax
  int v13; // esi
  int16_t v14; // ax
  int v15; // ebx
  uint16_t v16; // dx
  int v17; // eax
  int16_t v18; // si
  int v19; // [esp+0h] [ebp-3C6h]
  int v20; // [esp+4h] [ebp-3C2h]
  int v21[13]; // [esp+8h] [ebp-3BEh] BYREF
  hr_int128_t v22; // [esp+3Ch] [ebp-38Ah]
  int64_t v23; // [esp+4Ch] [ebp-37Ah]
  int64_t v24; // [esp+54h] [ebp-372h]
  int64_t v25; // [esp+5Ch] [ebp-36Ah]
  int v26; // [esp+64h] [ebp-362h]
  int v27; // [esp+68h] [ebp-35Eh]
  int v28; // [esp+6Ch] [ebp-35Ah]
  int64_t v29; // [esp+70h] [ebp-356h]
  char v30[212]; // [esp+358h] [ebp-6Eh] BYREF
  char v31; // [esp+42Ch] [ebp+66h] BYREF
  char v32; // [esp+42Dh] [ebp+67h]
  char v33; // [esp+42Eh] [ebp+68h]
  char v34; // [esp+42Fh] [ebp+69h]
  char v35; // [esp+430h] [ebp+6Ah]
  char v36; // [esp+431h] [ebp+6Bh]
  int v37; // [esp+43Ch] [ebp+76h] BYREF
  int v38; // [esp+440h] [ebp+7Ah] BYREF
  int v39; // [esp+444h] [ebp+7Eh]

  v0 = 0;
  do
  {
    v1 = (int16_t)v0++;
    *(&v31 + v1) = 0;
  }
  while ( (int16_t)v0 < 7 );
  v31 = 1;
  v32 = 1;
  if ( *(int16_t *)(dword_197F98 + 3753 * (int16_t)v19 + 2 * (int16_t)v20 + 1599) <= 0 )
  {
    v2 = 2 * (int16_t)v19 + 3753 * (int16_t)v20 + dword_197F98;
    if ( *(int16_t *)(v2 + 1599) <= 0 )
    {
      if ( *(_WORD *)(v2 + 1599) == 1 )
      {
        v31 = 0;
LABEL_9:
        v38 = 0;
        sub_27094(v19, v20, 0, 0xC343CB00, v30, v21, (int16_t *)&v38, 1);
        if ( (int16_t)v38 > 0 )
          v33 = 1;
        sub_1C417(v20, v19);
        if ( v3 == 1 )
          v34 = 1;
        if ( *(int *)(dword_197F98 + 3753 * (int16_t)v20 + 50) > 100 )
          v35 = 1;
        v36 = 1;
        sub_1191CA((int)sub_16F00, 2);
        v4 = 0;
        sub_117174(1);
        do
        {
          v5 = (char *)dword_19A22C[v4];
          v6 = &byte_19A744[50 * v4++];
          strcpy(v6, v5);
        }
        while ( v4 < 7 );
        sub_120BB5(4, (int)&unk_180DCC);
        sub_120EB9((int)&unk_180DD4);
        sub_120F07((int)&unk_180DDC);
        sub_120E24(4);
        sub_1FC13(7, (int)&unk_180E54);
        v37 = 0;
        switch ( (uint16_t)sub_11C4C1(
                                     10,
                                     118,
                                     245,
                                     dword_19A198,
                                     byte_19A744,
                                     50,
                                     (int16_t *)&v37,
                                     (int)&v31,
                                     17,
                                     0,
                                     0,
                                     0,
                                     0) )
        {
          case 0u:
            v7 = v19;
            v8 = (int16_t)v20;
            word_19AA36 = -1;
            sub_52049(v20, v19, 1);
            if ( *(_BYTE *)(3753 * (int16_t)v19 + dword_197F98 + 40) == 100 )
            {
              v9 = 1;
              v10 = 2;
              v11 = v19;
              v12 = v20;
LABEL_20:
              sub_1B724(v12, v11, v9, v10, (int16_t *)v8);
              goto LABEL_38;
            }
            sub_53723(v20, v19, 2, 1, &word_19AA40);
            break;
          case 1u:
            v7 = v19;
            v8 = (int16_t)v20;
            word_19AA36 = -1;
            sub_52049(v20, v19, 2);
            if ( *(_BYTE *)(3753 * (int16_t)v19 + dword_197F98 + 40) == 100 )
            {
              v9 = 2;
              v11 = v19;
              v12 = v20;
              v10 = 2;
              goto LABEL_20;
            }
            sub_53723(v20, v19, 2, 2, &word_19AA40);
            break;
          case 2u:
            v13 = (int16_t)v19;
            v8 = (int16_t)v20;
            v14 = sub_19F26(
                    (int16_t)v38,
                    0,
                    v19,
                    v20,
                    v21[0],
                    v21[1],
                    v21[2],
                    v21[3],
                    v21[4],
                    v21[5],
                    v21[6],
                    v21[7],
                    v21[8],
                    v21[9],
                    v21[10],
                    v21[11],
                    v21[12],(int)LODWORD(v22),
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29);
            v15 = v14;
            if ( v14 == -1 )
              goto LABEL_30;
            v16 = (uint8_t)v30[v14];
            word_19AA36 = -1;
            sub_E4204(3753 * v13 + dword_197F98, v16, v8);
            if ( *(_BYTE *)(3753 * v13 + dword_197F98 + 40) == 100 )
            {
              v11 = v13;
              v12 = v8;
              v9 = (uint8_t)v30[v15];
              v10 = 3;
              goto LABEL_20;
            }
            sub_53723(v8, v13, 3, (uint8_t)v30[v15], &word_19AA40);
            sub_276E6(v13, v8, 1);
            sub_26D19(v8, v13, &word_19AA4C, (int)&byte_19A2DC, (int)&byte_19A3B0);
            goto LABEL_38;
          case 3u:
            v17 = sub_1C479(v20, byte_19AA66, 0);
            v39 = v17;
            if ( (int16_t)v17 == -1 )
            {
LABEL_30:
              byte_19A64A = byte_178A64;
            }
            else
            {
              word_19AA36 = -1;
              if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)v19 + 40) == 100 )
              {
                sub_1B724(v20, v19, v17, 4, (int16_t *)(int16_t)v19);
              }
              else
              {
                sub_53723(v20, v19, 4, v17, &word_19AA40);
                sub_276E6(v19, v20, 1);
              }
              v18 = v39;
              if ( sub_E4A09((int16_t)v39, (int16_t)v20, (int16_t)v19) == 1 )
                sub_E4AB3(v18, v20, v19);
            }
            goto LABEL_38;
          case 4u:
            sub_1D237(v20, v19, 1);
            goto LABEL_38;
          default:
            goto LABEL_38;
        }
        sub_276E6(v7, v8, 1);
LABEL_38:
        JUMPOUT(0x1919A);
      }
      if ( *(_WORD *)(v2 + 1599) != 2 )
        goto LABEL_9;
    }
  }
  v31 = 0;
  v32 = 0;
  goto LABEL_9;
}
// 19690: control flows out of bounds to 1919A
// 194E6: variable 'v19' is possibly undefined
// 19500: variable 'v20' is possibly undefined
// 195A3: variable 'v3' is possibly undefined
// 178A64: using guessed type char byte_178A64;
// 197F98: using guessed type int dword_197F98;
// 19A198: using guessed type int dword_19A198;
// 19A22C: using guessed type int dword_19A22C[];
// 19A2DC: using guessed type char byte_19A2DC;
// 19A3B0: using guessed type char byte_19A3B0;
// 19A64A: using guessed type char byte_19A64A;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA4C: using guessed type int16_t word_19AA4C;
// 19AA66: using guessed type char byte_19AA66;


//----- (00019919) --------------------------------------------------------
void __usercall sub_19919(int16_t *a1)
{
  _BOOL2 v1; // si
  unsigned int v2; // edx
  int v3; // eax
  int v4; // eax

  sub_1191CA((int)sub_16F00, 2);
  sub_1196F7();
  v1 = 0;
  while ( !v1 )
  {
    sub_12C2A0();
    sub_11C2F0();
    v2 = sub_11438B(0, 0, 639, 479, &byte_178A64, 0);
    v3 = sub_1171AB(v2, v2, 639, 479);
    v1 = (_WORD)v3 == (uint16_t)v2;
    if ( (_WORD)v3 != (_WORD)v2 )
    {
      v4 = sub_16F00(v3, v2, 639, 479);
      sub_1077D(v4, v2, 639, a1);
      sub_12C2C6(2);
    }
  }
  sub_11C2F0();
  sub_119281();
}
// 178A64: using guessed type char byte_178A64;


//----- (00019997) --------------------------------------------------------
int __fastcall sub_19997(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int v4; // eax
  int16_t v5; // cx
  int16_t v7; // [esp+0h] [ebp-20h]
  int v8; // [esp+4h] [ebp-1Ch]
  int16_t v9; // [esp+8h] [ebp-18h] BYREF
  int16_t v10; // [esp+Ch] [ebp-14h] BYREF
  int16_t v11; // [esp+10h] [ebp-10h] BYREF
  uint16_t v12; // [esp+14h] [ebp-Ch] BYREF
  int16_t v13; // [esp+18h] [ebp-8h] BYREF
  int v14; // [esp+1Ch] [ebp-4h]

  LOWORD(a1) = word_19AA40;
  v14 = a1;
  if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)a2 + 40) == 100 )
    v3 = sub_1B06B(v7, a2, a3, (int16_t *)a2);
  else
    v3 = sub_5272D((int16_t)a2, v7, a3, &word_19AA40, &v9, &v12, &v11, &v10, &v13);
  if ( !(_WORD)v3 || (_WORD)v3 == 3 )
  {
    if ( (_WORD)v3 )
      v8 = 1;
    else
      v8 = v3;
  }
  else
  {
    if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)a2 + 40) == 100 )
      sub_1BD5B(v7, a2);
    else
      v4 = sub_19B78(v9, v12, v11, v10, v13);
    if ( (_WORD)v4 == 1 )
    {
      v8 = v4;
      if ( a3 < 3u )
      {
        if ( a3 )
        {
          if ( a3 <= (uint16_t)v4 )
            word_19AA40 = 131;
          else
            word_19AA40 = 132;
        }
      }
      else if ( a3 <= 3u )
      {
        word_19AA40 = 135;
      }
      else if ( a3 >= 7u )
      {
        if ( a3 <= 7u )
        {
          word_19AA40 = 133;
        }
        else if ( a3 == 8 )
        {
          word_19AA40 = 134;
        }
      }
    }
    else
    {
      v8 = 0;
      word_19AA40 = 138;
    }
  }
  if ( *(_BYTE *)(dword_197F98 + 3753 * (int16_t)a2 + 40) == 100 )
  {
    if ( (_WORD)v8 == 1 )
    {
      v5 = 3;
      a2 = (int16_t)a2;
    }
    else
    {
      a2 = (int16_t)a2;
      v5 = 0;
    }
    sub_188E0(v7, a2, a3, v5);
  }
  else
  {
    sub_2755F(a2, v7, &word_19AA40);
  }
  if ( word_19AA40 == (_WORD)v14 )
    word_19AA40 = 138;
  return v8;
}
// 199ED: variable 'v7' is possibly undefined
// 19A62: variable 'v4' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (00019B78) --------------------------------------------------------
int __fastcall sub_19B78( int a1, unsigned int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int16_t v8; // cx
  char *v9; // esi
  char *v10; // edi
  int v11; // edi
  int16_t v12; // ax
  int v14; // ebx
  char *v15; // [esp-4h] [ebp-50h]
  char v20[40]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE v21[16]; // [esp+38h] [ebp-14h] BYREF
  int v22; // [esp+48h] [ebp-4h] BYREF

  v5 = 0;
  do
  {
    v6 = (int16_t)v5++;
    v21[v6] = 1;
  }
  while ( (int16_t)v5 < 3 );
  if ( sub_1247A0(2u) == 1 )
    v7 = 74;
  else
    v7 = 75;
  sub_249F9(aJimtextLbx_0, v7, v20, 40);
  sub_11C2F0();
  sub_1191CA((int)sub_16F00, 2);
  sub_1196F7();
  v8 = 0;
  sub_117174(1);
  do
  {
    v9 = (char *)dword_19A21C[v8];
    v10 = &byte_19A744[50 * v8++];
    v15 = v10;
    strcpy(v10, v9);
    v11 = (int)v15;
  }
  while ( v8 < 3 );
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  v22 = 0;
  v12 = sub_11C4C1(10, 118, 245, (int)v20, byte_19A744, 50, (int16_t *)&v22, (int)v21, 17, 0, 0, 0, 0);
  if ( v12 == -1 || v12 == 1 )
    return 0;
  switch ( a1 )
  {
    case 1:
      v14 = dword_197F98;
      *(_DWORD *)(dword_197F98 + 3753 * word_19999C + 50) -= a3;
      *(_DWORD *)(v14 + 3753 * (uint8_t)byte_19AA66 + 50) += a3;
      break;
    case 2:
      if ( sub_E4A09(a4, word_19999C, (uint8_t)byte_19AA66) == 1 )
        sub_E4AB3(a4, word_19999C, (uint8_t)byte_19AA66);
      break;
    case 3:
      *(_WORD *)(dword_197F98 + 3753 * word_19999C + 2 * (uint8_t)byte_19AA66 + 1599) = a5;
      break;
    case 4:
      sub_E4204(dword_197F98 + 3753 * (uint8_t)byte_19AA66, a2, v11);
      break;
    default:
      return 1;
  }
  return 1;
}
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19A21C: using guessed type int dword_19A21C[];
// 19AA66: using guessed type char byte_19AA66;


//----- (00019D5F) --------------------------------------------------------
int __fastcall sub_19D5F(int a1, int a2, _WORD *a3, int a4)
{
  int v4; // eax
  int v5; // edx
  int64_t v6; // rax
  _BYTE *v7; // esi
  int16_t v9; // [esp+0h] [ebp-3AEh]
  int16_t v10; // [esp+4h] [ebp-3AAh]
  _DWORD v11[212]; // [esp+8h] [ebp-3A6h] BYREF
  char v12[212]; // [esp+358h] [ebp-56h] BYREF
  int v13; // [esp+42Ch] [ebp+7Eh] BYREF

  v4 = 0;
  do
  {
    v5 = (int16_t)v4++;
    *(_BYTE *)(v5 + a4) = 0;
  }
  while ( (int16_t)v4 < 10 );
  sub_DCAEE(v10);
  sub_27094(v9, v10, 0, 0xC343CB00, v12, v11, (int16_t *)&v13, 1);
  if ( (int16_t)v13 > 10 )
    v13 = 10;
  v6 = (unsigned int)v13;
  *a3 = v13;
  while ( SWORD2(v6) < (int16_t)v13 )
  {
    LODWORD(v6) = SWORD2(v6);
    v7 = (_BYTE *)(a4 + SWORD2(v6));
    LOBYTE(v6) = v12[SWORD2(v6)];
    ++WORD2(v6);
    *v7 = v6;
  }
  return v6;
}
// 19D8A: variable 'v10' is possibly undefined
// 19DAE: variable 'v9' is possibly undefined


//----- (00019DE8) --------------------------------------------------------
int __fastcall sub_19DE8( int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // edx
  int16_t v6; // dx
  char *v7; // esi
  char *v8; // edi
  int v9; // eax
  char v10; // dl
  int result; // eax
  int16_t v13; // [esp+8h] [ebp-18h]
  _BYTE v14[16]; // [esp+Ch] [ebp-14h] BYREF
  int v15; // [esp+1Ch] [ebp-4h] BYREF

  v13 = a1;
  if ( a1 > 8 )
    v13 = 8;
  v4 = 0;
  do
  {
    v5 = (int16_t)v4++;
    v14[v5] = 1;
  }
  while ( (int16_t)v4 < 10 );
  sub_11C2F0();
  sub_1191CA((int)sub_16F00, 2);
  sub_1FD06(694);
  v6 = 0;
  sub_117174(1);
  while ( v6 < v13 )
  {
    v7 = (char *)(a2 + 40 * v6);
    v8 = &byte_19A744[50 * v6++];
    strcpy(v8, v7);
  }
  if ( a3 == 1 )
  {
    sub_249F9(aJimtextLbx_0, 46, &byte_19A744[50 * v13], 50);
    v9 = 50 * (v13 + 1);
    v10 = byte_178A64;
  }
  else
  {
    v9 = 50 * v13;
    v10 = byte_178A64;
    --v13;
  }
  byte_19A744[v9] = v10;
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  v15 = 0;
  result = sub_11C4C1(10, 118, 245, a4, byte_19A744, 50, (int16_t *)&v15, (int)v14, 17, 0, 0, 0, 0);
  if ( (int16_t)result == -1 || (_WORD)result == v13 )
    return -1;
  return result;
}
// 178A64: using guessed type char byte_178A64;


//----- (00019F26) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge sub_19F26(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        hr_int128_t a18,
        int64_t a19,
        int64_t a20,
        int64_t a21,
        int a22,
        int a23,
        int a24,
        int64_t a25)
{
  int v25; // edx
  int v26; // edi
  int16_t i; // si
  uint8_t *v28; // ebx
  char *v29; // eax
  int v30; // ecx
  int v31; // ebx
  char *v32; // edi
  int v33; // edx
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // ebx
  int v39; // [esp+76h] [ebp-62h]
  int v40; // [esp+7Ah] [ebp-5Eh]
  int16_t v41; // [esp+7Eh] [ebp-5Ah]
  char v42[40]; // [esp+82h] [ebp-56h] BYREF
  char v43[40]; // [esp+AAh] [ebp-2Eh] BYREF
  char v44[6]; // [esp+D2h] [ebp-6h] BYREF

  if ( BYTE6(a25) == 1 )
    *(_DWORD *)((char *)&a21 + 2) = 8;
  else
    *(_DWORD *)((char *)&a21 + 2) = 11;
  *(_DWORD *)((char *)&a18 + 10) = *(_DWORD *)((char *)&a25 + 2);
  sub_11C2F0();
  sub_1191CA((int)sub_16F00, 2);
  sub_117174(1);
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  sub_249F9(aJimtextLbx_0, 76, v43, 40);
  *(_DWORD *)((char *)&a20 + 2) = 0;
  sub_249F9(aJimtextLbx_0, 77, v42, 40);
  if ( BYTE6(a25) == 1 )
    v25 = 70;
  else
    v25 = 46;
  sub_249F9(aJimtextLbx_0, v25, v44, 40);
  *(_DWORD *)((char *)&a18 + 14) = 0;
  while ( !HIWORD(a18) )
  {
    v36 = 0;
    do
    {
      v37 = (int16_t)v36++;
      *((_BYTE *)&a13 + v37 + 2) = 1;
    }
    while ( (int16_t)v36 < 15 );
    *(_DWORD *)((char *)&a19 + 2) = -1;
    *(_DWORD *)((char *)&a18 + 2) = -1;
    strcpy(byte_19A744, v43);
    HIWORD(a5) = -1;
    if ( WORD1(a20) )
    {
      v26 = 1;
      *(_DWORD *)((char *)&a19 + 2) = 0;
    }
    else
    {
      v26 = 0;
    }
    if ( SWORD1(a21) + SWORD1(a20) < SWORD5(a18) )
    {
      *(_DWORD *)((char *)&a20 + 6) = v26 + *(_DWORD *)((char *)&a21 + 2);
      *(_DWORD *)((char *)&a18 + 2) = v26 + *(_DWORD *)((char *)&a21 + 2);
    }
    else
    {
      *(_DWORD *)((char *)&a20 + 6) = *(_DWORD *)((char *)&a18 + 10) - *(_DWORD *)((char *)&a20 + 2);
    }
    for ( i = 0; i < SHIWORD(a20); ++i )
    {
      v28 = (uint8_t *)(i + SWORD1(a20) + v39);
      v29 = sub_10F7A1(*v28, v41);
      v30 = (int16_t)v26 + i;
      sprintf(&byte_19A744[50 * v30], "  %s", v29);
      *((_WORD *)&a5 + v30 + 1) = *v28;
    }
    if ( SWORD1(a18) != -1 )
    {
      v31 = SHIWORD(a20);
      v32 = &byte_19A744[50 * SHIWORD(a20)];
      ++*(_DWORD *)((char *)&a20 + 6);
      strcpy(v32, v42);
      *((_WORD *)&a5 + v31 + 1) = -1;
    }
    if ( !WORD1(a19) && SWORD1(a18) == -1 )
      ++*(_DWORD *)((char *)&a20 + 6);
    v33 = SHIWORD(a20) + 1;
    strcpy(&byte_19A744[50 * SHIWORD(a20)], v44);
    byte_19A744[50 * v33] = byte_178A64;
    *((_WORD *)&a5 + v33) = 613;
    sub_120E24(4);
    sub_1FC13(HIWORD(a20) + 2, (int)&a5 + 2);
    *(_DWORD *)((char *)&a18 + 6) = 0;
    v34 = sub_11C4C1(10, 118, 245, v40, byte_19A744, 50, (int16_t *)&a18 + 3, (int)&a13 + 2, 17, 0, 0, 0, 0);
    if ( (int16_t)v34 == -1 || (_WORD)v34 == HIWORD(a20) )
    {
      *(_DWORD *)((char *)&a19 + 6) = -1;
      *(_DWORD *)((char *)&a18 + 14) = -1;
    }
    else if ( (_WORD)v34 == WORD1(a19) )
    {
      *(_DWORD *)((char *)&a20 + 2) -= *(_DWORD *)((char *)&a21 + 2);
    }
    else if ( (_WORD)v34 == WORD1(a18) )
    {
      *(_DWORD *)((char *)&a20 + 2) += *(_DWORD *)((char *)&a21 + 2);
    }
    else
    {
      *(_DWORD *)((char *)&a18 + 14) = -1;
      v35 = *(_DWORD *)((char *)&a20 + 2) + v34;
      if ( SWORD1(a19) != -1 )
        --v35;
      *(_DWORD *)((char *)&a19 + 6) = v35;
    }
  }
  return *(_DWORD *)((char *)&a19 + 6);
}
// 1A003: inconsistent variable size for '^158.16'
// 1A163: inconsistent variable size for '^158.16'
// 1A188: inconsistent variable size for '^158.16'
// 1A15C: inconsistent variable size for '^168.8'
// 1A19B: inconsistent variable size for '^168.8'
// 1A1F1: inconsistent variable size for '^168.8'
// 1A033: inconsistent variable size for '^170.8'
// 1A03D: inconsistent variable size for '^170.8'
// 1A0A6: inconsistent variable size for '^170.8'
// 1A0CA: inconsistent variable size for '^170.8'
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 178A64: using guessed type char byte_178A64;


//----- (0001A1FD) --------------------------------------------------------
int __fastcall sub_1A1FD( int a1, int a2, int a3, int a4)
{
  int16_t v4; // ax
  int v5; // edi
  int v6; // eax
  int result; // eax
  char v8[40]; // [esp+0h] [ebp-4Ch] BYREF
  _BYTE v9[16]; // [esp+28h] [ebp-24h] BYREF
  int v10; // [esp+38h] [ebp-14h]
  int v11; // [esp+3Ch] [ebp-10h] BYREF
  int16_t v12; // [esp+40h] [ebp-Ch]
  int v13; // [esp+44h] [ebp-8h]
  int16_t v14; // [esp+48h] [ebp-4h]

  v14 = a2;
  v12 = a3;
  v13 = a4;
  word_199A08 = 6;
  byte_182ACE = 1;
  byte_199F0A = 0;
  v10 = dword_192ED0;
  word_199960 = a1;
  dword_192ED0 = dword_19A2B4;
  byte_19AA63 = a2;
  byte_19AA64 = a3;
  word_19AA34 = a1;
  sub_1CA7C(a1, a2, &word_19AA3E, &word_19AA3A, (int)byte_19AA5E);
  sub_E5B69(a2, word_199960);
  word_19AA42 = v4;
  sub_249F9(aJimtext2Lbx, 56, (char *)dword_19A2AC, 30);
  sub_24E08(dword_19A2AC, word_19AA42, 30);
  sub_249F9(aJimtext2Lbx, 58, (char *)dword_19A2C8, 35);
  v5 = 0;
  sub_24E27();
  do
  {
    v6 = (int16_t)v5++;
    v9[v6] = 1;
  }
  while ( (int16_t)v5 < 10 );
  sub_249F9(aJimtextLbx_0, 75, v8, 40);
  if ( (_WORD)v13 == 1 )
    sub_186D3(v12, v14, 7);
  else
    sub_249F9(aJimtextLbx_0, 78, &byte_19A64A, 250);
  sub_249F9(aJimtextLbx_0, 79, byte_19A744, 50);
  sub_249F9(aJimtextLbx_0, 80, byte_19A776, 50);
  byte_19A7A8 = byte_178A64;
  sub_11C2F0();
  sub_1191CA((int)sub_1A42D, 2);
  sub_117174(1);
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  v11 = 0;
  result = sub_11C4C1(10, 102, 245, (int)v8, byte_19A744, 50, (int16_t *)&v11, (int)v9, 17, 0, 0, 0, 0);
  dword_192ED0 = v10;
  byte_182ACE = 0;
  if ( (int16_t)result == -1 || (_WORD)result == 1 )
    return -1;
  return result;
}
// 1A291: variable 'v4' is possibly undefined
// 24E08: using guessed type int __fastcall sub_24E08(_DWORD, _DWORD, _DWORD);
// 178A64: using guessed type char byte_178A64;
// 182ACE: using guessed type char byte_182ACE;
// 192ED0: using guessed type int dword_192ED0;
// 199960: using guessed type int16_t word_199960;
// 199A08: using guessed type int16_t word_199A08;
// 199F0A: using guessed type char byte_199F0A;
// 19A2AC: using guessed type int dword_19A2AC;
// 19A2B4: using guessed type int dword_19A2B4;
// 19A2C8: using guessed type int dword_19A2C8;
// 19A64A: using guessed type char byte_19A64A;
// 19A7A8: using guessed type char byte_19A7A8;
// 19AA34: using guessed type int16_t word_19AA34;
// 19AA3A: using guessed type int16_t word_19AA3A;
// 19AA3E: using guessed type int16_t word_19AA3E;
// 19AA42: using guessed type int16_t word_19AA42;
// 19AA63: using guessed type char byte_19AA63;
// 19AA64: using guessed type char byte_19AA64;


//----- (0001A42D) --------------------------------------------------------
void __usercall sub_1A42D(int a1, int a2, int a3, int a4, int a5)
{
  sub_16F00(a1, a2, a4, a3);
  sub_1C873(a5);
  sub_1C8D9(word_19AA34, word_19AA3E);
}
// 19AA34: using guessed type int16_t word_19AA34;
// 19AA3E: using guessed type int16_t word_19AA3E;


//----- (0001A44D) --------------------------------------------------------
void __fastcall sub_1A44D( int a1, int a2, unsigned int a3, _WORD *a4, int a5)
{
  int v6; // ebx
  int16_t i; // dx
  int v8; // edi
  int v9; // eax

  v6 = a1;
  *a4 = 0;
  for ( i = 0; ; ++i )
  {
    if ( i >= word_199998 )
      JUMPOUT(0x19D59);
    if ( i != a2 && i != a1 )
    {
      v8 = 3753 * i + dword_197F98;
      v9 = v8 + a2;
      if ( *(_BYTE *)(v9 + 1412) == 1 && *(_BYTE *)(v6 + v8 + 1412) == 1 )
      {
        if ( a3 < 3u )
        {
          if ( a3 == 2 && *(_BYTE *)(v9 + 1575) == 2 )
          {
LABEL_18:
            *(_BYTE *)(a5 + (int16_t)(*a4)++) = i;
            continue;
          }
        }
        else if ( a3 <= 3u )
        {
          if ( *(_BYTE *)(v9 + 1575) == 4 || *(_BYTE *)(v9 + 1575) == 5 )
            goto LABEL_18;
        }
        else if ( a3 == 5 && *(char *)(v9 + 1575) < 4 )
        {
          goto LABEL_18;
        }
      }
    }
  }
}
// 1A502: control flows out of bounds to 19D59
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0001A507) --------------------------------------------------------
int __usercall sub_1A507(int16_t *a1, int a2)
{
  int16_t i; // bx
  int result; // eax

  for ( i = 0; i < word_199998; ++i )
  {
    if ( i != word_19999C )
    {
      if ( *(_BYTE *)(word_19999C + dword_197F98 + 3753 * i + 1623) )
        sub_1AFA6(i, 0, a1, a2);
      result = dword_197F98 + 3753 * word_19999C;
      *(_BYTE *)(i + result + 1623) = 0;
    }
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (0001ABBE) --------------------------------------------------------
int __fastcall sub_1ABBE( int a1, int a2)
{
  int v2; // edi
  int v3; // esi
  int16_t v4; // ax
  int v5; // edx
  int result; // eax

  v2 = a2;
  v3 = a1;
  v4 = sub_1247A0(0xDu);
  sub_4E3B5((int16_t)(v4 + 11), v3, a2, 0, 0, 0);
  v5 = dword_197F98;
  result = dword_197F98 + 3753 * v3;
  *(_BYTE *)(v2 + result + 1823) = 0;
  *(_BYTE *)(3753 * v2 + v5 + v3 + 1823) = 0;
  return result;
}
// 197F98: using guessed type int dword_197F98;


//----- (0001AC12) --------------------------------------------------------
int __usercall sub_1AC12(int16_t *a1)
{
  int v1; // eax
  int v2; // edx
  int v3; // esi
  int v4; // eax
  int v5; // ecx
  int i; // eax
  int v7; // eax
  int v8; // eax
  int v10[15]; // [esp+0h] [ebp-490h] BYREF
  hr_int128_t v11; // [esp+3Ch] [ebp-454h]
  int64_t v12; // [esp+4Ch] [ebp-444h]
  int64_t v13; // [esp+54h] [ebp-43Ch]
  int64_t v14; // [esp+5Ch] [ebp-434h]
  int v15; // [esp+64h] [ebp-42Ch]
  int v16; // [esp+68h] [ebp-428h]
  int v17; // [esp+6Ch] [ebp-424h]
  int64_t v18; // [esp+70h] [ebp-420h]
  char v19[212]; // [esp+350h] [ebp-140h] BYREF
  char v20[80]; // [esp+424h] [ebp-6Ch] BYREF
  _BYTE v21[16]; // [esp+474h] [ebp-1Ch] BYREF
  int16_t v22; // [esp+484h] [ebp-Ch] BYREF
  int v23; // [esp+488h] [ebp-8h] BYREF
  int v24; // [esp+48Ch] [ebp-4h]

  v1 = 0;
  do
  {
    v2 = (int16_t)v1++;
    v21[v2] = 1;
  }
  while ( (int16_t)v1 < 10 );
  sub_1196F7();
  v24 = -1000;
  sub_249F9(aJimtextLbx_0, 74, v20, 80);
  v3 = 1;
  if ( (uint16_t)word_19AA40 >= 0x61u )
  {
    if ( (uint16_t)word_19AA40 > 0x64u
      && ((uint16_t)word_19AA40 < 0x66u || (uint16_t)word_19AA40 > 0x6Au && word_19AA40 != 125) )
    {
      goto LABEL_14;
    }
LABEL_13:
    sub_249F9(aJimtextLbx_0, 79, byte_19A744, 50);
    v3 = 1;
    sub_249F9(aJimtextLbx_0, 80, byte_19A776, 50);
    byte_19A7A8 = 0;
    goto LABEL_14;
  }
  if ( (uint16_t)word_19AA40 >= 0x1Cu
    && ((uint16_t)word_19AA40 <= 0x24u
     || (uint16_t)word_19AA40 >= 0x53u && (uint16_t)word_19AA40 <= 0x56u) )
  {
    goto LABEL_13;
  }
LABEL_14:
  sub_1191CA((int)sub_16F00, 2);
  sub_117174(1);
  v23 = 1;
  sub_120BB5(4, (int)&unk_180DCC);
  sub_120EB9((int)&unk_180DD4);
  sub_120F07((int)&unk_180DDC);
  sub_120E24(4);
  sub_1FD06(694);
  if ( word_19AA40 == 101 )
  {
    sub_27094(
      word_19999C,
      (uint8_t)byte_19AA66,
      0,
      *(_DWORD *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 4 * word_19999C + 1935),
      v19,
      v10,
      &v22,
      1);
    sub_249F9(aJimtextLbx_0, 81, v20, 80);
    v3 = -1;
    v4 = sub_19F26(
           v22,
           1,
           v10[0],
           v10[1],
           v10[2],
           v10[3],
           v10[4],
           v10[5],
           v10[6],
           v10[7],
           v10[8],
           v10[9],
           v10[10],
           v10[11],
           v10[12],
           v10[13],
           v10[14],(int)LODWORD(v11),
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18);
    v5 = v4;
    v24 = -1;
    if ( (int16_t)v4 != -1 )
    {
      sub_E4204(dword_197F98 + 3753 * word_19999C, (uint8_t)v19[(int16_t)v4], (int)a1);
      sub_E4204(
        dword_197F98 + 3753 * (uint8_t)byte_19AA66,
        *(uint8_t *)(word_19999C + dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 1967),
        (int)a1);
    }
  }
  else if ( word_19AA40 == 125 )
  {
    sub_11C2F0();
    for ( i = sub_11438B(0, 0, 639, 479, &byte_178A64, 0); !(uint16_t)sub_1171AB(i, 0, 639, 479); i = sub_12C2C6(2) )
    {
      sub_12C2A0();
      v8 = sub_16F00(v7, 0, 639, 479);
      sub_1077D(v8, 0, 639, a1);
    }
    v5 = 1;
  }
  else
  {
    v5 = sub_11C4C1(10, 118, 245, (int)v20, byte_19A744, 50, (int16_t *)&v23, (int)v21, 17, 0, 0, 0, 0);
  }
  if ( (int16_t)v5 == -1 )
    v5 = v3;
  if ( (_WORD)v5 == (_WORD)v24 )
    return -1;
  return v5;
}
// 1AE47: variable 'v7' is possibly undefined
// 178A64: using guessed type char byte_178A64;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19A7A8: using guessed type char byte_19A7A8;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA66: using guessed type char byte_19AA66;


//----- (0001AEB5) --------------------------------------------------------
void __fastcall sub_1AEB5( int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  int16_t v6; // bx
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // [esp+0h] [ebp-4h]

  v2 = a1;
  v3 = a2;
  v10 = 3753 * a1;
  v4 = dword_197F98 + v10;
  v5 = dword_197F98 + v10 + a2;
  if ( *(_BYTE *)(v5 + 1887) )
  {
    if ( *(_BYTE *)(v5 + 1887) == 1 )
      v6 = 1;
    else
      v6 = 2;
    sub_52049(v2, v3, v6);
  }
  else
  {
    v7 = 3753 * v3 + dword_197F98;
    if ( *(_BYTE *)(v5 + 1895) )
    {
      sub_E4204(v7, *(uint8_t *)(v5 + 1895), 3753 * v3);
    }
    else
    {
      v8 = v4 + 2 * v3;
      if ( *(_WORD *)(v8 + 1911) )
      {
        *(_DWORD *)(v7 + 50) += *(int16_t *)(v8 + 1911);
        *(_DWORD *)(v4 + 50) -= *(int16_t *)(v8 + 1911);
        if ( *(int *)(v4 + 50) < 1 )
          *(_DWORD *)(v4 + 50) = 0;
      }
      else
      {
        v9 = *(int16_t *)(v8 + 1975);
        if ( v9 != -1 && sub_E4A09(v9, v2, v3) == 1 )
          sub_E4AB3(*(_WORD *)(2 * v3 + v10 + dword_197F98 + 1975), v2, v3);
      }
    }
  }
  JUMPOUT(0x17F39);
}
// 1AEF7: control flows out of bounds to 17F39
// 197F98: using guessed type int dword_197F98;


//----- (0001AFA0) --------------------------------------------------------
int __fastcall sub_1AFA0(__int16 a1, __int16 a2)
{
  return sub_1AFA6(a1, 1, a2);
}
// 1AFA6: using guessed type int __fastcall sub_1AFA6(_DWORD, _DWORD);


//----- (0001AFA6) --------------------------------------------------------
int __usercall sub_1AFA6( int a1, int a2, /*int16_t *a3,*/ int a4)
{
  _BOOL2 v4; // ax
  int16_t v5; // ax
  int16_t v6; // ax
  int16_t v7; // ax
  int16_t v8; // bx
  int v9; // edx
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  char v13; // bl
  int result; // eax
  int v15; // edx
  int16_t v16; // ax

  v13 = a1;
  result = 3753 * a1;
  if ( *(_BYTE *)(dword_197F98 + result + 36) != 1 )
  {
    sub_1196F7();
    sub_1172FC();
    sub_128BE7();
    sub_12B65C();
    sub_123E6C((int)&unk_180E62, 1);
    sub_107AF(&dword_19ABA0);
    sub_119281();
    sub_11C2F0();
    word_19AA36 = -1;
    byte_19AA66 = v13;
    sub_C5B94(0);
    sub_C5B85(10);
    sub_C5BB9();
    sub_117174(1);
    sub_11C2F0();
    sub_124C08();
    sub_119281();
    byte_19AA65 = 1;
    if ( a2 == 1 )
    {
      v15 = dword_197F98;
      v16 = *(uint8_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 1993);
    }
    else
    {
      v15 = 3753 * (uint8_t)byte_19AA66 + dword_197F98;
      v16 = *(uint8_t *)(v15 + word_19999C + 1623);
    }
    word_19AA40 = v16;
    sub_17C07();
    if ( word_19AA40 >= 83 && word_19AA40 <= 85
      || word_19AA40 >= 97 && word_19AA40 <= 104
      || word_19AA40 == 125
      || word_19AA40 == 86
      || word_19AA40 == 105
      || word_19AA40 == 106
      || word_19AA40 >= 28 && word_19AA40 <= 36 )
    {
      v15 = 3753 * word_19999C + dword_197F98;
      a4 = word_19AA40;
      v4 = *(char *)(v15 + (uint8_t)byte_19AA66 + 1559) < -12;
      byte_19AA65 = 2;
      word_19AA40 = v4 + 128;
    }
    if ( byte_19AA65 == 1 )
    {
      sub_19919(a3);
      if ( (uint16_t)word_19AA40 >= 0x39u )
      {
        if ( (uint16_t)word_19AA40 > 0x3Au )
        {
          if ( (uint16_t)word_19AA40 < 0x60u || (uint16_t)word_19AA40 > 0x60u && word_19AA40 != 107 )
            goto LABEL_85;
          v15 = word_19999C;
          v7 = (uint8_t)byte_19AA66;
          goto LABEL_68;
        }
        v15 = (uint8_t)byte_19AA66;
        v6 = word_19999C;
        goto LABEL_64;
      }
      if ( (uint16_t)word_19AA40 < 0x30u || (uint16_t)word_19AA40 > 0x33u )
        goto LABEL_85;
      sub_519AC(word_19999C, (uint8_t)byte_19AA66);
      sub_5175B(word_19999C, (uint8_t)byte_19AA66);
      sub_51C02(word_19999C, (uint8_t)byte_19AA66);
      goto LABEL_26;
    }
    if ( *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) != 100 )
      sub_19919(a3);
    word_19AA40 = a4;
    if ( !(uint16_t)sub_1AC12(a3) )
    {
      v15 = word_19999C;
      sub_276E6((uint8_t)byte_19AA66, word_19999C, 1);
      if ( (uint16_t)word_19AA40 >= 0x63u )
      {
        if ( (uint16_t)word_19AA40 <= 0x63u )
        {
          v15 = (uint8_t)byte_19AA66;
          sub_5223F(word_19999C, (uint8_t)byte_19AA66);
          goto LABEL_85;
        }
        if ( (uint16_t)word_19AA40 >= 0x67u )
        {
          if ( (uint16_t)word_19AA40 > 0x67u )
          {
            if ( (uint16_t)word_19AA40 < 0x69u )
            {
              v15 = *(char *)(word_19999C + dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 1927);
              v5 = word_19999C;
              goto LABEL_27;
            }
            if ( (uint16_t)word_19AA40 > 0x6Au )
              goto LABEL_85;
LABEL_67:
            word_19AA40 = 38;
            sub_19919(a3);
            sub_1ABBE(word_19999C, (uint8_t)byte_19AA66);
            v15 = (uint8_t)byte_19AA66;
            v7 = word_19999C;
LABEL_68:
            sub_1AEB5(v7, v15);
            goto LABEL_85;
          }
          sub_1AEB5((uint8_t)byte_19AA66, word_19999C);
          v10 = 3753 * (uint8_t)byte_19AA66;
          v9 = dword_197F98;
LABEL_63:
          v15 = *(char *)(word_19999C + v9 + v10 + 1927);
          v6 = word_19999C;
LABEL_64:
          sub_51078(v6, v15);
          goto LABEL_85;
        }
        if ( (uint16_t)word_19AA40 < 0x65u )
        {
          v15 = (uint8_t)byte_19AA66;
          sub_52150(word_19999C, (uint8_t)byte_19AA66);
          goto LABEL_85;
        }
        if ( (uint16_t)word_19AA40 > 0x65u )
        {
          v9 = 3753 * (uint8_t)byte_19AA66;
          v10 = dword_197F98;
          goto LABEL_63;
        }
LABEL_85:
        sub_113C28(10);
        sub_119281();
        sub_107BA(&dword_19ABA0);
        sub_11C2F0();
        sub_12D78E();
        sub_FE8C8(dword_192ED4, v15);
        sub_C5B94(0);
        sub_C5B85(10);
        sub_C5BB9();
        word_180EB4 = -1;
        return sub_2484F();
      }
      if ( (uint16_t)word_19AA40 < 0x55u )
      {
        if ( (uint16_t)word_19AA40 < 0x53u )
        {
          if ( (uint16_t)word_19AA40 < 0x1Cu || (uint16_t)word_19AA40 > 0x24u )
            goto LABEL_85;
          goto LABEL_67;
        }
        if ( (uint16_t)word_19AA40 > 0x53u )
        {
          sub_1AEB5(word_19999C, (uint8_t)byte_19AA66);
          sub_524FB(word_19999C, (uint8_t)byte_19AA66);
          v15 = (uint8_t)byte_19AA66;
          sub_1ABBE(word_19999C, (uint8_t)byte_19AA66);
          goto LABEL_85;
        }
      }
      else
      {
        if ( (uint16_t)word_19AA40 > 0x55u )
        {
          if ( (uint16_t)word_19AA40 >= 0x61u )
          {
            if ( (uint16_t)word_19AA40 <= 0x61u )
              v8 = 1;
            else
              v8 = 2;
            v15 = (uint8_t)byte_19AA66;
            sub_5232E(word_19999C, (uint8_t)byte_19AA66, v8);
            goto LABEL_85;
          }
          if ( word_19AA40 != 86 )
            goto LABEL_85;
          v15 = *(char *)(3753 * (uint8_t)byte_19AA66 + dword_197F98 + word_19999C + 1927);
          sub_51078(word_19999C, v15);
          word_19AA40 = 88;
LABEL_84:
          sub_19919(a3);
          goto LABEL_85;
        }
        sub_1AEB5((uint8_t)byte_19AA66, word_19999C);
      }
      v15 = (uint8_t)byte_19AA66;
      sub_524FB(word_19999C, (uint8_t)byte_19AA66);
      goto LABEL_85;
    }
    v15 = word_19999C;
    sub_276E6((uint8_t)byte_19AA66, word_19999C, 0);
    if ( (uint16_t)word_19AA40 < 0x68u )
    {
      if ( (uint16_t)word_19AA40 < 0x1Cu )
        goto LABEL_85;
      if ( (uint16_t)word_19AA40 <= 0x24u )
      {
        sub_519AC(word_19999C, (uint8_t)byte_19AA66);
        sub_5175B(word_19999C, (uint8_t)byte_19AA66);
        sub_51C02(word_19999C, (uint8_t)byte_19AA66);
        v15 = (uint8_t)byte_19AA66;
        sub_5138E(word_19999C, (uint8_t)byte_19AA66);
        word_19AA40 = 37;
      }
      else
      {
        if ( word_19AA40 != 86 )
          goto LABEL_85;
        v15 = (uint8_t)byte_19AA66;
        sub_5138E(word_19999C, (uint8_t)byte_19AA66);
        word_19AA40 = 87;
      }
    }
    else
    {
      if ( (uint16_t)word_19AA40 <= 0x68u )
      {
LABEL_26:
        v15 = (uint8_t)byte_19AA66;
        v5 = word_19999C;
LABEL_27:
        sub_5138E(v5, v15);
        goto LABEL_85;
      }
      if ( (uint16_t)word_19AA40 <= 0x69u )
      {
        v15 = (uint8_t)byte_19AA66;
        sub_4E3B5(-50, (uint8_t)byte_19AA66, word_19999C, 0, 0, 0);
        word_19AA40 = 37;
      }
      else
      {
        if ( word_19AA40 != 106 )
          goto LABEL_85;
        v11 = word_19999C;
        v12 = dword_197F98 + 3753 * (uint8_t)byte_19AA66;
        v15 = v12 + 2 * word_19999C;
        if ( *(int16_t *)(v15 + 2103) != -1 )
        {
          LOWORD(v15) = *(_WORD *)(v15 + 2103);
          *(_WORD *)(v12 + 1991) = v15;
          LOBYTE(v15) = *(_BYTE *)(v11 + v12 + 2183);
          *(_BYTE *)(v12 + 1993) = v15;
          goto LABEL_85;
        }
        v15 = word_19999C;
        sub_51078((uint8_t)byte_19AA66, word_19999C);
        word_19AA40 = 179;
      }
    }
    goto LABEL_84;
  }
  return result;
}
// 17C07: using guessed type int sub_17C07(void);
// 180EB4: using guessed type int16_t word_180EB4;
// 192ED4: using guessed type int dword_192ED4;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA65: using guessed type char byte_19AA65;
// 19AA66: using guessed type char byte_19AA66;
// 19ABA0: using guessed type int dword_19ABA0;


//----- (0001B06B) --------------------------------------------------------
int __usercall sub_1B06B( int a1, int a2, unsigned int a3, int16_t *a4)
{
  int v4; // edx
  int v5; // eax
  int v6; // eax

  if ( a3 < 3u )
  {
    if ( a3 )
    {
      if ( a3 <= 1u )
        word_19AA40 = 97;
      else
        word_19AA40 = 98;
    }
  }
  else if ( a3 <= 3u )
  {
    word_19AA40 = 83;
  }
  else if ( a3 >= 7u )
  {
    if ( a3 <= 7u )
    {
      word_19AA40 = 99;
    }
    else if ( a3 == 8 )
    {
      word_19AA40 = 100;
    }
  }
  if ( byte_199F3A == 1 )
  {
    sub_1B881(a1);
    v4 = sub_1B1A7(a1, a2, a3);
    sub_1B881(a2);
  }
  else
  {
    byte_19A190 = a1;
    byte_19A191 = a2;
    word_19A196 = word_19AA40;
    word_19A192 = a3;
    v5 = *(int16_t *)(3753 * a2 + dword_197F98 + 43);
    word_19A194 = 1000;
    v6 = sub_F6816(v5, 2000, (int)&byte_19A190, 8u);
    sub_FE8BE(v6, 2000, (int)&byte_19A190, a4);
    sub_1F34B();
    word_19A196 = -1;
    do
    {
      v4 = a1;
      sub_1EDE9(a2, a1, 8, (unsigned int)&byte_19A190, a4);
    }
    while ( word_19A196 == -1 && !word_19AA48 );
    if ( word_19AA48 == 1 )
      word_19A196 = 0;
    LOWORD(v4) = word_19A196;
  }
  return v4;
}
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA48: using guessed type int16_t word_19AA48;


//----- (0001B1A7) --------------------------------------------------------
int __fastcall sub_1B1A7(int a1, int a2, unsigned int a3)
{
  int v3; // edi
  int16_t v4; // ax
  int16_t v5; // ax
  int16_t v7; // [esp+0h] [ebp-2h]
  int16_t v8; // [esp+4h] [ebp+2h]
  char v9[40]; // [esp+8h] [ebp+6h] BYREF
  char v10[40]; // [esp+30h] [ebp+2Eh] BYREF
  char v11[320]; // [esp+58h] [ebp+56h] BYREF
  char v12[40]; // [esp+198h] [ebp+196h] BYREF
  int v13; // [esp+1C0h] [ebp+1BEh]

  sub_249F9(aJimtextLbx_0, 79, v9, 40);
  v13 = 2;
  sub_249F9(aJimtextLbx_0, 80, v10, 40);
  v11[0] = byte_178A64;
  v3 = 0;
  sub_1B35A(v8, v7);
  if ( v4 == 1 )
  {
    v13 = 3;
    sub_249F9(aJimtextLbx_0, 82, v11, 40);
  }
  word_19AA40 = 0;
  word_19AA36 = 0;
  v11[40] = byte_178A64;
  sub_189EC(a3);
  sub_1196F7();
  sub_249F9(aJimtextLbx_0, 74, v12, 40);
  v5 = sub_19DE8(v13, (int)v9, 0, (int)v12);
  if ( (_WORD)v13 == 2 && v5 == -1 )
    v5 = 1;
  if ( (_WORD)v13 == 3 && v5 == -1 )
    v5 = 2;
  if ( v5 )
  {
    if ( (uint16_t)v5 <= 1u )
    {
      word_19AA40 = 138;
      return 0;
    }
    else if ( v5 == 2 )
    {
      return 1;
    }
  }
  else
  {
    v3 = 3;
    if ( a3 < 3u )
    {
      if ( a3 )
      {
        if ( a3 <= 1u )
          word_19AA40 = 131;
        else
          word_19AA40 = 132;
      }
    }
    else if ( a3 <= 3u )
    {
      word_19AA40 = 135;
    }
    else if ( a3 >= 7u )
    {
      if ( a3 <= 7u )
      {
        word_19AA40 = 133;
      }
      else if ( a3 == 8 )
      {
        word_19AA40 = 134;
      }
    }
  }
  return v3;
}
// 1B202: variable 'v8' is possibly undefined
// 1B202: variable 'v7' is possibly undefined
// 1B20B: variable 'v4' is possibly undefined
// 178A64: using guessed type char byte_178A64;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (0001B35A) --------------------------------------------------------
void __fastcall sub_1B35A( int a1, int a2)
{
  int v2; // esi
  int16_t v3; // ax
  _BYTE v4[12]; // [esp+0h] [ebp-10h] BYREF
  int16_t v5; // [esp+Ch] [ebp-4h] BYREF

  v2 = a1;
  sub_1C417(a1, a2);
  if ( v3 != 1 )
    sub_19D5F(v2, a2, &v5, (int)v4);
  JUMPOUT(0x17F39);
}
// 1B396: control flows out of bounds to 17F39
// 1B375: variable 'v3' is possibly undefined
// 197F98: using guessed type int dword_197F98;


//----- (0001B3B5) --------------------------------------------------------
int __fastcall sub_1B3B5( int a1, int a2, int a3, int a4)
{
  int v4; // esi
  char v6[40]; // [esp+0h] [ebp-1B8h] BYREF
  char v7[360]; // [esp+28h] [ebp-190h] BYREF
  char v8[40]; // [esp+190h] [ebp-28h] BYREF

  v4 = 0;
  if ( a3 != 7 )
  {
    sub_249F9(aJimtextLbx_0, 79, v6, 40);
    sub_249F9(aJimtextLbx_0, 80, v7, 40);
    v7[40] = byte_178A64;
    sub_1196F7();
    sub_249F9(aJimtext2Lbx, 0, v8, 40);
    if ( (uint16_t)sub_19DE8(2, (int)v6, 0, (int)v8) )
      return v4;
    return 1;
  }
  if ( (int16_t)sub_1A1FD(a4, a1, a2, 1) != -1 )
    return 1;
  return v4;
}
// 178A64: using guessed type char byte_178A64;


//----- (0001B487) --------------------------------------------------------
void __usercall sub_1B487( int a1, int a2, int a3, int a4, int a5)
{
  int16_t v7; // bx
  int v8; // ecx
  int16_t v9; // si
  char v10; // bl

  switch ( a4 )
  {
    case 0:
      *(_BYTE *)(a3 + 3753 * a2 + dword_197F98 + 2199) = 0;
      break;
    case 1:
      *(_BYTE *)(a3 + dword_197F98 + 3753 * a2 + 2199) = 1;
      break;
    case 2:
      *(_BYTE *)(a3 + 3753 * a2 + dword_197F98 + 2199) = 2;
      break;
    case 3:
      v7 = 1;
      goto LABEL_6;
    case 4:
      v7 = 2;
LABEL_6:
      sub_52049(a2, a1, v7);
      break;
    case 6:
      sub_E4204(3753 * a1 + dword_197F98, a3, a5);
      break;
    case 7:
      v8 = a1;
      v9 = a3;
      if ( sub_E4A09(a3, a2, v8) == 1 )
        sub_E4AB3(v9, a2, v8);
      break;
    case 8:
      v10 = sub_1247A0(0x32u) + 10;
      *(_BYTE *)(a1 + 3753 * a2 + dword_197F98 + 2062) = sub_1247A0(0x32u) + v10;
      break;
    default:
      return;
  }
}
// 197F98: using guessed type int dword_197F98;


//----- (0001B5B8) --------------------------------------------------------
void __userpurge sub_1B5B8( int a1, int a2, int a3, int a4,
        int a5, int a6,
        _WORD *a7)
{
  int16_t v7; // ax
  int v8; // eax
  int v9; // eax

  switch ( a4 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      a6 = 169;
      a5 = 168;
      break;
    default:
      break;
  }
  if ( byte_199F3A == 1 )
  {
    word_19AA36 = word_19AA40;
    sub_186D3(a1, a2, a4);
    sub_1B881(a1);
    v7 = sub_1B3B5(a2, a1, a4, a3);
    word_19AA36 = -1;
    *a7 = v7;
    if ( v7 == 1 )
      word_19AA40 = a6;
    else
      word_19AA40 = a5;
    sub_1B881(a2);
  }
  else
  {
    byte_19A190 = a1;
    byte_19A191 = a2;
    word_19A192 = a4;
    word_19A196 = a3;
    v8 = *(int16_t *)(dword_197F98 + 3753 * a2 + 43);
    word_19A194 = 1005;
    v9 = sub_F6816(v8, 2000, (int)&byte_19A190, 8u);
    sub_FE8BE(v9, 2000, (int)&byte_19A190, (int16_t *)a5);
    sub_1F34B();
    word_19A196 = -1;
    do
      sub_1EDE9(a2, a1, 8, (unsigned int)&byte_19A190, (int16_t *)a5);
    while ( word_19A196 == -1 && !word_19AA48 );
    if ( word_19AA48 == 1 )
      word_19A196 = 0;
    *a7 = word_19A196;
  }
  JUMPOUT(0x19D59);
}
// 1B663: control flows out of bounds to 19D59
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA48: using guessed type int16_t word_19AA48;


//----- (0001B724) --------------------------------------------------------
void __usercall sub_1B724( int a1, int a2, int a3, int a4, int16_t *a5)
{
  int v6; // ebx
  int v7; // ecx
  int v8; // eax
  int v9; // eax

  if ( byte_199F3A == 1 )
  {
    v6 = a3;
    word_19AA36 = word_19AA40;
    v7 = a1;
    sub_185BD(a1, a4, v6);
    sub_1B881(v7);
    sub_19919(a5);
    sub_1B881(a2);
  }
  else
  {
    word_19A196 = a3;
    byte_19A190 = a1;
    word_19A192 = a4;
    byte_19A191 = a2;
    v8 = *(int16_t *)(3753 * a2 + dword_197F98 + 43);
    word_19A194 = 1004;
    v9 = sub_F6816(v8, 2000, (int)&byte_19A190, 8u);
    sub_FE8BE(v9, 2000, (int)&byte_19A190, a5);
  }
  switch ( a4 )
  {
    case 1:
      word_19AA40 = 163;
      break;
    case 2:
      word_19AA40 = 162;
      break;
    case 3:
      word_19AA40 = 161;
      break;
    case 4:
      word_19AA40 = 164;
      break;
    default:
      return;
  }
}
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (0001B7FB) --------------------------------------------------------
_BOOL2 sub_1B7FB()
{
  char v1[40]; // [esp+0h] [ebp-1B8h] BYREF
  char v2[360]; // [esp+28h] [ebp-190h] BYREF
  char v3[40]; // [esp+190h] [ebp-28h] BYREF

  sub_249F9(aJimtextLbx_0, 79, v1, 40);
  sub_249F9(aJimtextLbx_0, 80, v2, 40);
  v2[40] = byte_178A64;
  sub_249F9(aJimtext2Lbx, 1, v3, 40);
  sub_1196F7();
  return (uint16_t)sub_19DE8(2, (int)v1, 0, (int)v3) == 0;
}
// 178A64: using guessed type char byte_178A64;


//----- (0001B881) --------------------------------------------------------
int __fastcall sub_1B881(int a1)
{
  int v2; // ecx
  int v3; // edx

  sub_123E6C((int)&unk_180E62, 1);
  sub_119281();
  sub_11C2F0();
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
  v2 = 3753 * (int16_t)a1;
  sub_1B92E((int16_t *)(int16_t)a1);
  sub_12C607((int)aDiplomatLbx_0, (int16_t)(2 * *(uint8_t *)(v2 + dword_197F98 + 37) + 13), a1, v2);
  sub_124D41();
  sub_12C7CC();
  sub_124DEC();
  v3 = (int16_t)(2 * *(uint8_t *)(v2 + dword_197F98 + 37) + 14);
  byte_19AA66 = a1;
  sub_12C607((int)aDiplomatLbx_0, v3, a1, v2);
  sub_123E6C((int)&unk_17CF00, 1);
  return sub_12CD2D();
}
// 197F98: using guessed type int dword_197F98;
// 19AA66: using guessed type char byte_19AA66;


//----- (0001B92E) --------------------------------------------------------
void __fastcall sub_1B92E(int16_t *a1)
{
  _DWORD *v2; // esi
  int v3; // esi
  int v4; // ebx
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // esi
  _DWORD *v8; // edx
  int v9; // eax
  int v10; // esi
  _DWORD *v11; // edx
  int v12; // eax
  int v13; // esi
  _DWORD *v14; // edx
  int v15; // eax
  int v16; // esi
  _DWORD *v17; // edx
  int v18; // eax
  int v19; // esi
  _DWORD *v20; // edx
  int v21; // eax
  int v22; // esi
  _DWORD *v23; // edx
  int v24; // eax
  int v25; // esi
  _DWORD *v26; // edx
  int v27; // eax
  int v28; // esi
  _DWORD *v29; // edx
  int v30; // eax
  int v31; // esi
  _DWORD *v32; // edx
  int v33; // eax
  _DWORD *v34; // eax
  int v35; // eax

  dword_19A2D0 = (int)sub_110CEE(dword_192ED4, 917);
  v2 = sub_126B42((int)aDiplomatLbx_0, *(uint8_t *)(dword_197F98 + 3753 * (int16_t)a1 + 37), dword_192ED4);
  sub_12E332(0);
  sub_12D8F5(30, 30, dword_19A2D0);
  sub_12F578(dword_19A2D0, (int)v2);
  sub_124D41();
  sub_128C32(0, 0, 639, 479, 0);
  sub_12B79D((int)v2);
  sub_133237();
  sub_1318D4(0, 255);
  sub_128C32(0, 0, 639, 479, 0);
  sub_12E1E0(0, 0, (int16_t *)dword_19A2D0, 0);
  v3 = 0;
  dword_19A2B4 = (int)sub_126B42((int)aDipstarsLbx, 0, dword_192ED4);
  do
  {
    v4 = dword_192ED4;
    v5 = sub_126B42((int)aDipstarsLbx, (int16_t)(v3 + 1), dword_192ED4);
    v6 = (int16_t)v3++;
    dword_1932E0[v6] = (int)v5;
  }
  while ( (int16_t)v3 < 11 );
  v7 = 0;
  dword_19A2D4 = (int)sub_110D3C(dword_192ED4, 30);
  do
  {
    v8 = sub_110D3C(dword_192ED4, 40);
    v9 = (int16_t)v7++;
    dword_19A248[v9] = (int)v8;
  }
  while ( (int16_t)v7 < 9 );
  v10 = 0;
  do
  {
    v11 = sub_110D3C(dword_192ED4, 40);
    v12 = (int16_t)v10++;
    dword_19A26C[v12] = (int)v11;
  }
  while ( (int16_t)v10 < 11 );
  v13 = 0;
  do
  {
    v14 = sub_110D3C(dword_192ED4, 30);
    v15 = (int16_t)v13++;
    dword_19A1E8[v15] = (int)v14;
  }
  while ( (int16_t)v13 < 5 );
  v16 = 0;
  do
  {
    v17 = sub_110D3C(dword_192ED4, 30);
    v18 = (int16_t)v16++;
    dword_19A0E8[v18] = (int)v17;
  }
  while ( (int16_t)v16 < 6 );
  v19 = 0;
  dword_19A19C = (int)sub_110D3C(dword_192ED4, 40);
  do
  {
    v20 = sub_110D3C(dword_192ED4, 30);
    v21 = (int16_t)v19++;
    dword_19A1A0[v21] = (int)v20;
  }
  while ( (int16_t)v19 < 7 );
  v22 = 0;
  dword_19A1FC = (int)sub_110D3C(dword_192ED4, 30);
  do
  {
    v23 = sub_110D3C(dword_192ED4, 40);
    v24 = (int16_t)v22++;
    dword_19A200[v24] = (int)v23;
  }
  while ( (int16_t)v22 < 7 );
  v25 = 0;
  dword_19A228 = (int)sub_110D3C(dword_192ED4, 30);
  do
  {
    v26 = sub_110D3C(dword_192ED4, 40);
    v27 = (int16_t)v25++;
    dword_19A1BC[v27] = (int)v26;
  }
  while ( (int16_t)v25 < 11 );
  v28 = 0;
  dword_19A198 = (int)sub_110D3C(dword_192ED4, 30);
  do
  {
    v29 = sub_110D3C(dword_192ED4, 30);
    v30 = (int16_t)v28++;
    dword_19A22C[v30] = (int)v29;
  }
  while ( (int16_t)v28 < 7 );
  v31 = 0;
  do
  {
    v32 = sub_110D3C(dword_192ED4, 20);
    v33 = (int16_t)v31++;
    dword_19A21C[v33] = (int)v32;
  }
  while ( (int16_t)v31 < 3 );
  dword_19A2BC = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2A4 = (int)sub_110D3C(dword_192ED4, 20);
  dword_19A2AC = (int)sub_110D3C(dword_192ED4, 30);
  dword_19A29C = (int)sub_110D3C(dword_192ED4, 30);
  dword_19A2C8 = (int)sub_110D3C(dword_192ED4, 35);
  dword_19A2A0 = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A298 = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2C0 = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2A8 = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2B0 = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2CC = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2C4 = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2B8 = (int)sub_110D3C(dword_192ED4, 40);
  dword_19A2D8 = (int)sub_110D3C(dword_192ED4, 20);
  dword_19A4E8 = (int)sub_110D3C(dword_192ED4, 20);
  v34 = sub_110D3C(dword_192ED4, (int)&loc_7C830);
  v35 = sub_12D7B7((int)v34);
  sub_1F37C(v35, (int)&loc_7C830, v4, a1);
  word_19AA3C = *(uint8_t *)(dword_197F98 + 3753 * (int16_t)a1 + 37) + 1;
  word_19AA44 = -1;
  word_19AA46 = sub_1247A0(3u) + 13;
  JUMPOUT(0x17205);
}
// 1BD56: control flows out of bounds to 17205
// 192ED4: using guessed type int dword_192ED4;
// 1932E0: using guessed type int dword_1932E0[11];
// 197F98: using guessed type int dword_197F98;
// 19A0E8: using guessed type int dword_19A0E8[];
// 19A198: using guessed type int dword_19A198;
// 19A19C: using guessed type int dword_19A19C;
// 19A1A0: using guessed type int dword_19A1A0[];
// 19A1BC: using guessed type int dword_19A1BC[];
// 19A1E8: using guessed type int dword_19A1E8[];
// 19A1FC: using guessed type int dword_19A1FC;
// 19A200: using guessed type int dword_19A200[];
// 19A21C: using guessed type int dword_19A21C[];
// 19A228: using guessed type int dword_19A228;
// 19A22C: using guessed type int dword_19A22C[];
// 19A248: using guessed type int dword_19A248[];
// 19A26C: using guessed type int dword_19A26C[];
// 19A298: using guessed type int dword_19A298;
// 19A29C: using guessed type int dword_19A29C;
// 19A2A0: using guessed type int dword_19A2A0;
// 19A2A4: using guessed type int dword_19A2A4;
// 19A2A8: using guessed type int dword_19A2A8;
// 19A2AC: using guessed type int dword_19A2AC;
// 19A2B0: using guessed type int dword_19A2B0;
// 19A2B4: using guessed type int dword_19A2B4;
// 19A2B8: using guessed type int dword_19A2B8;
// 19A2BC: using guessed type int dword_19A2BC;
// 19A2C0: using guessed type int dword_19A2C0;
// 19A2C4: using guessed type int dword_19A2C4;
// 19A2C8: using guessed type int dword_19A2C8;
// 19A2CC: using guessed type int dword_19A2CC;
// 19A2D0: using guessed type int dword_19A2D0;
// 19A2D4: using guessed type int dword_19A2D4;
// 19A2D8: using guessed type int dword_19A2D8;
// 19A4E8: using guessed type int dword_19A4E8;
// 19AA3C: using guessed type int16_t word_19AA3C;
// 19AA44: using guessed type int16_t word_19AA44;
// 19AA46: using guessed type int16_t word_19AA46;


//----- (0001BD5B) --------------------------------------------------------
void __fastcall sub_1BD5B( int a1, int a2)
{
  int v2; // edi
  int16_t v3; // ax
  char *v4; // ebx
  char *v5; // ebx
  int v6; // edi
  int v7; // edx
  int64_t v8; // rax
  int v9; // eax
  int v10; // eax
  int16_t v11; // cx
  int16_t i; // cx
  int v13; // ebx
  char *v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // ebx
  char *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // esi
  int64_t v24; // rax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // edx
  int v29; // eax
  int16_t v30; // [esp+0h] [ebp-204h]
  int16_t v31; // [esp+0h] [ebp-204h]
  int16_t v32; // [esp+4h] [ebp-200h]
  int16_t v33; // [esp+4h] [ebp-200h]
  char v34[400]; // [esp+8h] [ebp-1FCh] BYREF
  char v35[40]; // [esp+198h] [ebp-6Ch] BYREF
  _BYTE v36[12]; // [esp+1C0h] [ebp-44h] BYREF
  int v37; // [esp+1CCh] [ebp-38h]
  int v38; // [esp+1D0h] [ebp-34h]
  int v39; // [esp+1D4h] [ebp-30h]
  int v40; // [esp+1D8h] [ebp-2Ch]
  int v41; // [esp+1DCh] [ebp-28h]
  int v42; // [esp+1E0h] [ebp-24h]
  int v43; // [esp+1E4h] [ebp-20h]
  int v44; // [esp+1E8h] [ebp-1Ch]
  int v45; // [esp+1ECh] [ebp-18h]
  int v46; // [esp+1F0h] [ebp-14h]
  int v47; // [esp+1F4h] [ebp-10h]
  int v48; // [esp+1F8h] [ebp-Ch]
  int v49; // [esp+1FCh] [ebp-8h]
  int v50; // [esp+200h] [ebp-4h] BYREF

  v32 = a1;
  v30 = a2;
  byte_19AA69 = 0;
  v46 = -10;
  v45 = -10;
  v44 = -10;
  sub_249F9(aJimtext2Lbx, 51, &byte_19A64A, 250);
  sub_24D30();
  v2 = 0;
  sub_1C417(v32, a2);
  if ( v3 == 1 )
  {
    v2 = 1;
    sub_249F9(aJimtext2Lbx, 52, v34, 40);
    v46 = 0;
  }
  sub_19D5F(v32, a2, &v50, (int)v36);
  if ( (int16_t)v50 > 0 )
  {
    v45 = v2;
    v4 = &v34[40 * (int16_t)v2++];
    sub_249F9(aJimtext2Lbx, 53, v4, 40);
  }
  if ( *(int *)(dword_197F98 + 3753 * v32 + 50) > 100 )
  {
    v44 = v2;
    v5 = &v34[40 * (int16_t)v2];
    LOWORD(v2) = v2 + 1;
    sub_249F9(aJimtext2Lbx, 64, v5, 40);
  }
  v42 = (int16_t)v2;
  v34[40 * (int16_t)v2] = byte_178A64;
  if ( (int16_t)v2 > 0 )
  {
    sub_1196F7();
    sub_249F9(aJimtext2Lbx, 54, v35, 40);
    v49 = sub_19DE8(v42, (int)v34, 1, (int)v35);
    if ( (_WORD)v49 == (_WORD)v46 )
    {
      v6 = v32;
      v7 = sub_1C479(v32, byte_19AA66, 0);
      v49 = v7;
      v37 = (int16_t)v7;
      if ( (int16_t)v7 != -1 )
      {
        v43 = v7;
        v8 = sprintf(v34, "  %s", (char *)(dword_19306C + 113 * (int16_t)v7));
        if ( byte_199F3A == 1 )
        {
          v39 = v30;
          sub_1B881(v30);
          v49 = sub_1A1FD(v37, v6, v39, 0);
          if ( (int16_t)v49 != -1 && sub_E4A09(v37, v6, v39) == 1 )
            sub_E4AB3(v37, v6, v39);
        }
        else
        {
          byte_19A190 = v32;
          byte_19A191 = v30;
          word_19A196 = word_19AA40;
          word_19A192 = WORD2(v8);
          v9 = *(int16_t *)(3753 * v30 + dword_197F98 + 43);
          word_19A194 = 1007;
          v10 = sub_F6816(v9, 2000, (int)&byte_19A190, 8u);
          sub_FE8BE(v10, 2000, (int)&byte_19A190, (int16_t *)v6);
          sub_1F34B();
          word_19A196 = -1;
          do
            sub_1EDE9(v30, v32, 8, (unsigned int)&byte_19A190, (int16_t *)v6);
          while ( word_19A196 == -1 && !word_19AA48 );
          if ( word_19AA48 == 1 )
            word_19A196 = 0;
          if ( word_19A196 == 1 )
          {
            v11 = v43;
            v41 = v30;
            if ( sub_E4A09((int16_t)v43, v32, v30) == 1 )
              sub_E4AB3(v11, v32, v41);
          }
        }
      }
    }
    if ( (_WORD)v49 == (_WORD)v45 )
    {
      if ( (int16_t)v50 > 8 )
        v50 = 8;
      for ( i = 0; i < (int16_t)v50; ++i )
      {
        v13 = 40 * i;
        v14 = sub_10F7A1((uint8_t)v36[i], word_19999C);
        sprintf(&v34[v13], "  %s", v14);
      }
      v15 = sub_19DE8(v50, (int)v34, 1, dword_19A198);
      v16 = (int16_t)v15;
      v49 = v15;
      if ( (int16_t)v15 != -1 )
      {
        LOWORD(v15) = (uint8_t)v36[(int16_t)v15];
        v17 = v32;
        v47 = v15;
        v18 = sub_10F7A1((uint8_t)v36[v16], v32);
        sprintf(v34, "  %s", v18);
        if ( byte_199F3A == 1 )
        {
          sub_1B881(v17);
          sub_249F9(aJimtext2Lbx, 9, v35, 40);
          v49 = sub_19DE8(1, (int)v34, 1, (int)v35);
          if ( (int16_t)v49 != -1 )
            sub_E4204(3753 * v30 + dword_197F98, v47, v16);
          sub_1B881(v30);
        }
        else
        {
          byte_19A190 = v32;
          byte_19A191 = v30;
          word_19A192 = v47;
          word_19A196 = word_19AA40;
          v19 = *(int16_t *)(3753 * v30 + dword_197F98 + 43);
          word_19A194 = 1008;
          v20 = sub_F6816(v19, 2000, (int)&byte_19A190, 8u);
          sub_FE8BE(v20, 2000, (int)&byte_19A190, (int16_t *)v16);
          word_19A196 = -1;
          sub_1F34B();
          do
            sub_1EDE9(v30, v32, 8, (unsigned int)&byte_19A190, (int16_t *)v16);
          while ( word_19A196 == -1 && !word_19AA48 );
          if ( word_19AA48 == 1 )
            word_19A196 = 0;
          if ( word_19A196 == 1 )
            sub_E4204(dword_197F98 + 3753 * v30, v47, v16);
        }
      }
    }
    if ( (_WORD)v49 == (_WORD)v44 )
    {
      v21 = v32;
      v40 = v30;
      sub_1D237(v32, v30, 0);
      v48 = v22;
      if ( (int16_t)v22 > 0 )
      {
        v23 = (int16_t)v22;
        v24 = sprintf(v34, "  %d BC", (int16_t)v22);
        v38 = 3753 * v40;
        if ( byte_199F3A == 1 )
        {
          sub_1B881(v21);
          sub_249F9(aJimtext2Lbx, 9, v35, 40);
          if ( (int16_t)sub_19DE8(1, (int)v34, 1, (int)v35) != -1 )
          {
            v25 = dword_197F98;
            *(_DWORD *)(3753 * v21 + dword_197F98 + 50) -= v23;
            *(_DWORD *)(v38 + v25 + 50) += v23;
          }
          sub_1B881(v31);
        }
        else
        {
          word_19A192 = WORD2(v24);
          byte_19A190 = v33;
          byte_19A191 = v31;
          word_19A196 = word_19AA40;
          v26 = *(int16_t *)(v38 + dword_197F98 + 43);
          word_19A194 = 1013;
          v27 = sub_F6816(v26, 2000, (int)&byte_19A190, 8u);
          sub_FE8BE(v27, 2000, (int)&byte_19A190, (int16_t *)v21);
          word_19A196 = -1;
          sub_1F34B();
          do
            sub_1EDE9(v31, v33, 8, (unsigned int)&byte_19A190, (int16_t *)v21);
          while ( word_19A196 == -1 && !word_19AA48 );
          if ( word_19AA48 == 1 )
            word_19A196 = 0;
          if ( word_19A196 == 1 )
          {
            v28 = dword_197F98;
            v29 = (int16_t)v48;
            *(_DWORD *)(dword_197F98 + 3753 * v33 + 50) -= (int16_t)v48;
            *(_DWORD *)(v28 + 3753 * v31 + 50) += v29;
          }
        }
      }
    }
  }
  JUMPOUT(0x17F39);
}
// 1C412: control flows out of bounds to 17F39
// 1BDC8: variable 'v3' is possibly undefined
// 1BF31: variable 'v30' is possibly undefined
// 1BF8C: variable 'v32' is possibly undefined
// 1C290: variable 'v22' is possibly undefined
// 1C31F: variable 'v31' is possibly undefined
// 1C348: variable 'v33' is possibly undefined
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 178A64: using guessed type char byte_178A64;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19A198: using guessed type int dword_19A198;
// 19A64A: using guessed type char byte_19A64A;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA66: using guessed type char byte_19AA66;
// 19AA69: using guessed type char byte_19AA69;


//----- (0001C417) --------------------------------------------------------
void __fastcall sub_1C417( int a1, int a2)
{
  char v2; // cl
  int16_t v3; // di
  int16_t i; // si

  v2 = a1;
  v3 = 0;
  for ( i = 0; i < word_19999A && v3 < 3; ++i )
  {
    if ( (((int)*(uint8_t *)(113 * i + dword_19306C + 56) >> v2) & 1) != 0 && sub_E4A09(i, a1, a2) == 1 )
      ++v3;
  }
  JUMPOUT(0x17F39);
}
// 1C474: control flows out of bounds to 17F39
// 19306C: using guessed type int dword_19306C;
// 19999A: using guessed type int16_t word_19999A;


//----- (0001C479) --------------------------------------------------------
int __fastcall sub_1C479( int a1, int a2, int a3)
{
  int16_t v3; // ax
  int v4; // edx
  int v5; // esi
  int16_t v6; // di
  int v7; // edx
  int v8; // ecx
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  int16_t *v12; // edi
  char *v13; // eax
  int16_t v14; // ax
  int16_t v15; // ax
  int v16; // eax
  int v19; // [esp+10h] [ebp-1Ch]
  int v20; // [esp+14h] [ebp-18h] BYREF
  int v21; // [esp+18h] [ebp-14h] BYREF
  char *v22; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  unsigned int v24; // [esp+24h] [ebp-8h]
  int v25; // [esp+28h] [ebp-4h]

  v19 = dword_192ED0;
  word_199A08 = 6;
  dword_192ED0 = dword_19A2B4;
  byte_182ACE = 1;
  byte_19AA63 = a1;
  byte_199F0A = 0;
  byte_19AA64 = a2;
  if ( a3 == 1 )
    v3 = 609;
  else
    v3 = 616;
  sub_1FD06(v3);
  sub_11C2F0();
  sub_1191CA((int)sub_1C7E8, 2);
  if ( a3 == 1 )
    v4 = 63;
  else
    v4 = 55;
  sub_249F9(aJimtext2Lbx, v4, &byte_19A64A, 250);
  v23 = -1;
  sub_24DF0();
  v5 = 0;
  v6 = 0;
  word_19AA34 = -1;
  sub_11C2F0();
  while ( v6 < word_19999A )
  {
    sub_911D5(v6, 10, 171, 180, 110, 0, 0, 1, &v21, &v20);
    v7 = v6++;
    word_19A100[v7] = sub_11438B(v21, v20, v21 + 5, v20 + 5, &byte_178A64, 0);
  }
  v8 = 162;
  v9 = 157;
  v10 = 139;
  v24 = sub_11438B(15, 139, 157, 162, &byte_178A64, 0);
  while ( !(_WORD)v5 )
  {
    sub_12C2A0();
    word_19AA34 = -1;
    v12 = (int16_t *)sub_1171AB(v11, v10, v9, v8);
    v13 = sub_114177();
    word_199960 = -1;
    word_19AA34 = (int16_t)v13;
    if ( (int16_t)v13 <= 0 )
      goto LABEL_19;
    if ( (_WORD)v13 == (_WORD)v24 )
    {
      word_19AA34 = 1000;
    }
    else
    {
      if ( (int16_t)v13 < word_19A100[0]
        || (v10 = word_19999A, (int16_t)v13 > *((int16_t *)&dword_19A0FC + word_19999A + 1))
        || (v10 = a1,
            v8 = (int)&word_19AA3A,
            v9 = (int)&word_19AA3E,
            sub_1CA7C((int16_t)((_WORD)v13 - 1), a1, &word_19AA3E, &word_19AA3A, (int)byte_19AA5E),
            (_WORD)v13 != a1) )
      {
LABEL_19:
        word_19AA34 = -1;
        goto LABEL_20;
      }
      word_199960 = word_19AA34 - 1;
      sub_E5B69(a1, word_19AA34 - 1);
      word_19AA42 = v14;
      sub_249F9(aJimtext2Lbx, 56, (char *)dword_19A2AC, 30);
      v8 = 35;
      sub_24E08(dword_19A2AC, word_19AA42, 30);
      sub_249F9(aJimtext2Lbx, 58, (char *)dword_19A2C8, 35);
      v9 = 35;
      v10 = word_199960;
      sub_24E27();
    }
LABEL_20:
    if ( (_WORD)v12 == (_WORD)v24 || word_19AA48 == 1 )
      v5 = 1;
    if ( (_WORD)v12 && !(_WORD)v5 )
    {
      word_19AA34 = -1;
      v25 = v5;
      v22 = (char *)v12 - 1;
      while ( 1 )
      {
        v13 = (char *)v25;
        if ( (int16_t)v25 >= word_19999A || (_WORD)v5 )
          break;
        v10 = (int16_t)v25;
        if ( (_WORD)v12 == word_19A100[(int16_t)v25] )
        {
          v10 = a1;
          v8 = (int)&word_19AA3A;
          v9 = (int)&word_19AA3E;
          sub_1CA7C((int16_t)v22, a1, &word_19AA3E, &word_19AA3A, (int)byte_19AA5E);
          if ( v15 == a1 )
          {
            v9 = (uint8_t)byte_19AA64;
            v10 = (uint8_t)byte_19AA63;
            if ( sub_E4A09((int16_t)v12 - 1, (uint8_t)byte_19AA63, (uint8_t)byte_19AA64) == 1
              && word_19AA3E == -1 )
            {
              v5 = 1;
              v23 = v25;
            }
          }
        }
        ++v25;
      }
    }
    if ( !(_WORD)v5 )
    {
      sub_1C7E8((int)v13, v10, v8, v9, 0);
      sub_1077D(v16, v10, v9, v12);
      sub_12C2C6(2);
    }
  }
  sub_11C2F0();
  sub_119281();
  byte_182ACE = 0;
  dword_192ED0 = v19;
  return v23;
}
// 1C5EB: variable 'v11' is possibly undefined
// 1C666: variable 'v13' is possibly undefined
// 1C694: variable 'v14' is possibly undefined
// 1C75D: variable 'v15' is possibly undefined
// 1C7B3: variable 'v16' is possibly undefined
// 24E08: using guessed type int __fastcall sub_24E08(_DWORD, _DWORD, _DWORD);
// 178A64: using guessed type char byte_178A64;
// 182ACE: using guessed type char byte_182ACE;
// 192ED0: using guessed type int dword_192ED0;
// 199960: using guessed type int16_t word_199960;
// 19999A: using guessed type int16_t word_19999A;
// 199A08: using guessed type int16_t word_199A08;
// 199F0A: using guessed type char byte_199F0A;
// 19A0FC: using guessed type int dword_19A0FC;
// 19A100: using guessed type int16_t word_19A100[72];
// 19A2AC: using guessed type int dword_19A2AC;
// 19A2B4: using guessed type int dword_19A2B4;
// 19A2C8: using guessed type int dword_19A2C8;
// 19A64A: using guessed type char byte_19A64A;
// 19AA34: using guessed type int16_t word_19AA34;
// 19AA3A: using guessed type int16_t word_19AA3A;
// 19AA3E: using guessed type int16_t word_19AA3E;
// 19AA42: using guessed type int16_t word_19AA42;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA63: using guessed type char byte_19AA63;
// 19AA64: using guessed type char byte_19AA64;


//----- (0001C7E8) --------------------------------------------------------
void __usercall sub_1C7E8(int a1, int a2, int a3, int a4, int a5)
{
  sub_16F00(a1, a2, a4, a3);
  sub_1C873(a5);
  sub_120CCB(4, (int)&unk_180DCC);
  sub_1212B3(10, 117, dword_19A2BC);
  if ( word_19AA34 == 1000 )
  {
    sub_120CCB(4, (int)&unk_180DD4);
    word_19AA34 = -1;
  }
  sub_1212B3(18, 141, dword_19A2A4);
  if ( word_19AA34 != -1 )
    sub_1C8D9(word_19AA34 - 1, word_19AA3E);
}
// 19A2A4: using guessed type int dword_19A2A4;
// 19A2BC: using guessed type int dword_19A2BC;
// 19AA34: using guessed type int16_t word_19AA34;
// 19AA3E: using guessed type int16_t word_19AA3E;


//----- (0001C873) --------------------------------------------------------
void __usercall sub_1C873( int a1)
{
  sub_1297C3(9, 170, 182, 112, 1, 251);
  sub_1298DE(10, 171, 190, 280);
  sub_90C4F(171, 10, a1, 180, 110, 0, 0, 0, 0, 4, 0);
}


//----- (0001C8D9) --------------------------------------------------------
void __fastcall sub_1C8D9( int a1, int a2)
{
  void *v3; // edx
  char *v4; // edi
  void *v5; // edx
  int v6; // ecx
  int v7; // eax
  int64_t v8; // rax
  char *v9; // edi
  char *v10; // [esp-4h] [ebp-64h] BYREF
  char v11[80]; // [esp+0h] [ebp-60h] BYREF
  int v12; // [esp+50h] [ebp-10h]
  int v13; // [esp+54h] [ebp-Ch]
  int v14; // [esp+58h] [ebp-8h]
  int v15; // [esp+5Ch] [ebp-4h]

  v14 = a2;
  v13 = 0;
  if ( (int16_t)a2 == -1 )
  {
    v3 = &unk_180DCC;
  }
  else
  {
    v3 = &unk_180DDC;
    v13 = 1;
  }
  sub_120CCB(4, (int)v3);
  v10 = v11;
  strcpy(v11, (char *)dword_19A2C8);
  if ( !sub_E4A09(a1, (uint8_t)byte_19AA63, (uint8_t)byte_19AA64) )
  {
    sub_120CCB(4, (int)&unk_180DDC);
    v13 = 1;
    v10 = v11;
    v4 = (char *)&v10 + 3;
    do
      ++v4;
    while ( *v4 );
    strcpy(v4, (char *)dword_19A2A8);
  }
  sub_1212B3(10, 287, (int)v11);
  if ( (int16_t)v14 == -1 && (_WORD)v13 != 1 )
    v5 = &unk_180DCC;
  else
    v5 = &unk_180DDC;
  sub_120CCB(3, (int)v5);
  v6 = 32;
  sub_1212B3(10, 309, dword_19A2AC);
  v12 = 0;
  v15 = 323;
  while ( (int16_t)v12 < word_19AA3A )
  {
    v7 = dword_1930D4 + 17 * (uint8_t)byte_19AA5E[(int16_t)v12];
    v8 = sprintf(
           v11,
           "%s, %s",
           (char *)dword_192BE0[*(uint8_t *)(v7 + 5)],
           (char *)dword_18F990[*(uint8_t *)(v7 + 8)]);
    if ( (uint8_t)byte_19AA5E[HIDWORD(v8)] == (_WORD)v14 )
    {
      v10 = v11;
      v9 = (char *)&v10 + 3;
      do
        ++v9;
      while ( *v9 );
      strcpy(v9, (char *)dword_19A29C);
    }
    ++v12;
    sub_1212B3(10, v15, (int)v11);
    v6 += 14;
    v15 += 14;
  }
  JUMPOUT(0x17F39);
}
// 1CA77: control flows out of bounds to 17F39
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 18F990: using guessed type int dword_18F990[];
// 192BE0: using guessed type int dword_192BE0[];
// 1930D4: using guessed type int dword_1930D4;
// 19A29C: using guessed type int dword_19A29C;
// 19A2A8: using guessed type int dword_19A2A8;
// 19A2AC: using guessed type int dword_19A2AC;
// 19A2C8: using guessed type int dword_19A2C8;
// 19AA3A: using guessed type int16_t word_19AA3A;
// 19AA63: using guessed type char byte_19AA63;
// 19AA64: using guessed type char byte_19AA64;


//----- (0001CA7C) --------------------------------------------------------
void __fastcall sub_1CA7C(int a1, int a2, _WORD *a3, int16_t *a4, int a5)
{
  int v6; // edx
  char *v7; // edx
  int16_t v8; // [esp+0h] [ebp-14h]
  int16_t v9; // [esp+Ch] [ebp-8h]
  int16_t i; // [esp+10h] [ebp-4h]

  *a3 = -1;
  *a4 = 0;
  if ( (((int)*(uint8_t *)(dword_19306C + 113 * v8 + 56) >> a2) & 1) != 0 )
  {
    for ( i = 0; i < 5; ++i )
    {
      v9 = *(_WORD *)(113 * v8 + dword_19306C + 2 * i + 74);
      if ( v9 != -1 )
      {
        v6 = *(int16_t *)(dword_1930D4 + 17 * v9);
        if ( v6 != -1 )
        {
          v7 = (char *)(dword_192B18 + 361 * v6);
          if ( *v7 == a2 )
          {
            *(_BYTE *)(a5 + *a4) = v9;
            if ( v7[319] )
              *a3 = v9;
            ++*a4;
          }
        }
      }
    }
  }
  JUMPOUT(0x19D59);
}
// 1CB48: control flows out of bounds to 19D59
// 1CA87: variable 'v8' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;


//----- (0001CB4D) --------------------------------------------------------
void __fastcall sub_1CB4D(int a1, int a2)
{
  int v2; // eax
  int v3; // edx
  int16_t i; // dx
  char *v5; // esi
  char *v6; // edi
  int v7; // esi
  int v8; // edi
  int v9; // edx
  int16_t v10; // ax
  int v11; // edx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int16_t *v16; // edi
  int16_t v17; // si
  int v18; // eax
  int v19; // eax
  int v20; // ebx
  int v22; // [esp+0h] [ebp-534h]
  int v24; // [esp+4h] [ebp-530h]
  int v25; // [esp+8h] [ebp-52Ch] BYREF
  int v26; // [esp+Ch] [ebp-528h]
  int v27; // [esp+10h] [ebp-524h]
  int v28; // [esp+14h] [ebp-520h]
  int v29; // [esp+18h] [ebp-51Ch]
  int v30; // [esp+1Ch] [ebp-518h]
  int v31; // [esp+20h] [ebp-514h]
  int v32; // [esp+24h] [ebp-510h]
  int v33; // [esp+28h] [ebp-50Ch]
  int v34; // [esp+2Ch] [ebp-508h]
  int v35; // [esp+30h] [ebp-504h]
  int v36; // [esp+34h] [ebp-500h]
  int v37; // [esp+38h] [ebp-4FCh]
  hr_int128_t v38; // [esp+3Ch] [ebp-4F8h]
  int64_t v39; // [esp+4Ch] [ebp-4E8h]
  int64_t v40; // [esp+54h] [ebp-4E0h]
  int64_t v41; // [esp+5Ch] [ebp-4D8h]
  int v42; // [esp+64h] [ebp-4D0h]
  int v43; // [esp+68h] [ebp-4CCh]
  int v44; // [esp+6Ch] [ebp-4C8h]
  int64_t v45; // [esp+70h] [ebp-4C4h]
  _QWORD v46[50]; // [esp+358h] [ebp-1DCh] BYREF
  char v47[56]; // [esp+4E8h] [ebp-4Ch] BYREF
  int v48; // [esp+520h] [ebp-14h]
  int v49; // [esp+524h] [ebp-10h]
  int v50; // [esp+528h] [ebp-Ch]
  int v51; // [esp+52Ch] [ebp-8h]
  int v52; // [esp+530h] [ebp-4h]

  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    v47[v3 + 40] = 1;
  }
  while ( (int16_t)v2 < 15 );
  for ( i = 0; i < 3; ++i )
  {
    v5 = (char *)dword_19A21C[i];
    v6 = (char *)&v46[5 * i];
    strcpy(v6, v5);
  }
  v50 = 0;
  if ( word_19AA4C <= 0 )
    goto LABEL_28;
  v7 = (int16_t)a2;
  v8 = (int16_t)a1;
  sub_249F9(aJimtext2Lbx, 3, v47, 40);
  HIWORD(v9) = (int16_t)a2 >> 15;
  v10 = sub_19F26(
          word_19AA4C,
          0,
          a2,
          a1,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,(int)LODWORD(v38),
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45);
  if ( v10 != -1 )
  {
    LOWORD(v9) = (uint8_t)byte_19A2DC[v10];
    v52 = v9;
    v11 = dword_197F98 + 3753 * v7;
    if ( *(_BYTE *)(v11 + 40) == 100 )
    {
      if ( byte_199F3A == 1 )
      {
        sub_1B881(v8);
        v49 = (int16_t)v52;
        sub_18AE2();
        sub_249F9(aJimtext2Lbx, 4, v47, 40);
        sub_27094(v7, v8, 0, 0xC343CB00, byte_19A2DC, &v25, &word_19AA4C, 1);
        v12 = sub_19F26(
                word_19AA4C,
                0,
                v22,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,(int)LODWORD(v38),
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45);
        sub_1B881(v7);
        if ( (int16_t)v12 == -1 )
          goto LABEL_25;
        LOWORD(v12) = (uint8_t)byte_19A2DC[(int16_t)v12];
        v51 = v12;
        sub_18A97(v7, v8, v49);
        sub_249F9(aJimtext2Lbx, 5, v47, 40);
        if ( (int16_t)sub_19DE8(2, (int)v46, 0, (int)v47) != -1 )
          goto LABEL_11;
        goto LABEL_12;
      }
      word_19A194 = 1009;
      byte_19A190 = v24;
      byte_19A191 = v22;
      word_19A192 = v52;
      v13 = *(int16_t *)(v11 + 43);
      word_19A196 = 0;
      v14 = sub_F6816(v13, 2000, (int)&byte_19A190, 8u);
      sub_FE8BE(v14, 2000, (int)&byte_19A190, (int16_t *)v8);
      sub_1F34B();
      word_19A196 = -2;
      do
        sub_1EDE9(v22, v24, 8, (unsigned int)&byte_19A190, (int16_t *)v8);
      while ( word_19A196 == -2 && !word_19AA48 );
      if ( word_19AA48 == 1 )
        word_19A196 = -1;
      v15 = word_19A196;
      if ( word_19A196 == -1 )
        goto LABEL_25;
      LOWORD(v15) = word_19A196;
      v51 = v15;
      v16 = (int16_t *)(3753 * (int16_t)v22);
      sub_18A97((int16_t)v22, (int16_t)v24, v52);
      sub_249F9(aJimtext2Lbx, 5, v47, 40);
      v17 = sub_19DE8(2, (int)v46, 0, (int)v47);
      byte_19A190 = v24;
      word_19A194 = 1010;
      byte_19A191 = v22;
      word_19A196 = v51;
      v18 = *(int16_t *)((char *)v16 + dword_197F98 + 43);
      word_19A192 = v17;
      v19 = sub_F6816(v18, 2000, (int)&byte_19A190, 8u);
      sub_FE8BE(v19, 2000, (int)&byte_19A190, v16);
      if ( v17 == -1 )
      {
LABEL_12:
        sub_18B3E();
        goto LABEL_25;
      }
LABEL_11:
      sub_18B27();
      v50 = 1;
      goto LABEL_25;
    }
    if ( byte_19A3B0[v10] )
    {
      LOWORD(v11) = (uint8_t)byte_19A3B0[v10];
      v51 = v11;
      sub_18A97(v7, v8, v52);
      sub_249F9(aJimtext2Lbx, 5, v47, 40);
      if ( (int16_t)sub_19DE8(2, (int)v46, 0, (int)v47) != -1 )
        goto LABEL_11;
      byte_19A64A = byte_178A64;
    }
    else
    {
      word_19AA36 = -1;
      word_19AA40 = 174;
      sub_2755F(v7, v8, &word_19AA40);
    }
  }
LABEL_25:
  if ( (_WORD)v50 == 1 )
  {
    sub_4E3B5(12, v24, v22, 0, 0, 0);
    v20 = 3753 * (int16_t)v22;
    v48 = 3753 * (int16_t)v24;
    sub_E4204(v48 + dword_197F98, v52, (int16_t)v24);
    sub_E4204(v20 + dword_197F98, v51, (int16_t)v24);
    if ( *(_BYTE *)(v20 + dword_197F98 + 40) != 100 )
    {
      sub_26D19(v24, v22, &word_19AA4C, (int)byte_19A2DC, (int)byte_19A3B0);
      sub_524C3(v24, v22);
      *(_WORD *)(v48 + dword_197F98 + 2 * (int16_t)v22 + 1711) -= 20;
    }
  }
LABEL_28:
  JUMPOUT(0x17F39);
}
// 1CFAC: control flows out of bounds to 17F39
// 1CC90: variable 'v22' is possibly undefined
// 1CC90: variable 'v24' is possibly undefined
// 178A64: using guessed type char byte_178A64;
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19A21C: using guessed type int dword_19A21C[];
// 19A64A: using guessed type char byte_19A64A;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA4C: using guessed type int16_t word_19AA4C;


//----- (0001CFB1) --------------------------------------------------------
int __userpurge sub_1CFB1( int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        hr_int128_t a26,
        int a27,
        int a28,
        int a29,
        int64_t a30)
{
  int v30; // esi
  int16_t i; // di
  unsigned int v33; // ebx
  int16_t j; // dx
  _WORD *v35; // eax
  int v36; // eax
  int v37; // [esp+6Eh] [ebp-7E6h]
  int v38; // [esp+72h] [ebp-7E2h]
  int16_t v39; // [esp+76h] [ebp-7DEh]
  int16_t v40; // [esp+7Ah] [ebp-7DAh]
  _DWORD v41[212]; // [esp+7Eh] [ebp-7D6h] BYREF
  _DWORD v42[212]; // [esp+3CEh] [ebp-486h] BYREF
  char v43[212]; // [esp+71Eh] [ebp-136h] BYREF
  char v44[98]; // [esp+7F2h] [ebp-62h] BYREF

  v30 = 0;
  if ( (int16_t)sub_DCAEE(a1) < 1 )
    return 0;
  sub_27094(a1, v40, 0, 0xC343CB00, v44, v42, (int16_t *)&a26 + 1, 1);
  if ( SWORD1(a26) < 1 )
    return 0;
  if ( SWORD1(a26) > 10 )
    *(_DWORD *)((char *)&a26 + 2) = 10;
  for ( i = 0; i < SWORD1(a26); ++i )
  {
    v33 = v42[i];
    sub_27094(v40, v39, v33, 0xC343CB00, v43, v41, (int16_t *)&a26 + 3, 1);
    if ( SWORD3(a26) > 10 )
      *(_DWORD *)((char *)&a26 + 6) = 10;
    if ( SWORD3(a26) > 0 )
    {
      *(_WORD *)(2 * (int16_t)v30 + v38) = WORD3(a26);
      for ( j = 0; j < SWORD3(a26); ++j )
      {
        LOWORD(v33) = (uint8_t)v43[j];
        *(_DWORD *)((char *)&a26 + 10) = v33;
        v35 = (_WORD *)(*(_DWORD *)((char *)&a30 + 2) + 20 * (int16_t)v30 + 2 * j);
        *v35 = v33;
      }
      v36 = 2 * (int16_t)v30++;
      *(_WORD *)(v37 + v36) = (uint8_t)v44[i];
    }
  }
  return v30;
}
// 1CFF8: variable 'v40' is possibly undefined
// 1D04A: variable 'v39' is possibly undefined
// 1D06F: variable 'v38' is possibly undefined
// 1D0B5: variable 'v37' is possibly undefined


//----- (0001D0F8) --------------------------------------------------------
void __usercall sub_1D0F8(int16_t *a1)
{
  int v1; // eax
  int v2; // eax
  int16_t v3; // [esp+0h] [ebp+76h]
  int16_t v4; // [esp+4h] [ebp+7Ah]
  char v5[400]; // [esp+8h] [ebp+7Eh] BYREF
  char v6[80]; // [esp+198h] [ebp+20Eh] BYREF

  sub_1FD06(612);
  sub_249F9(aJimtext2Lbx, 6, v5, 40);
  sub_249F9(aJimtext2Lbx, 7, v6, 80);
  if ( (int16_t)sub_19DE8(1, (int)v5, 1, (int)v6) != -1 )
  {
    if ( sub_E4CD2(v4, v3) )
      sub_E4D06(v4, v3);
    if ( *(_BYTE *)(dword_197F98 + 3753 * v3 + 40) == 100 )
    {
      if ( byte_199F3A == 1 )
      {
        sub_1B881(v4);
        sub_18560();
        sub_19919(a1);
        sub_1B881(v3);
      }
      else
      {
        byte_19A190 = v4;
        byte_19A191 = v3;
        word_19A192 = 0;
        word_19A196 = word_19AA40;
        v1 = *(int16_t *)(3753 * v3 + dword_197F98 + 43);
        word_19A194 = 1003;
        v2 = sub_F6816(v1, 2000, (int)&byte_19A190, 8u);
        sub_FE8BE(v2, 2000, (int)&byte_19A190, a1);
      }
    }
  }
  JUMPOUT(0x17B44);
}
// 1D1D2: control flows out of bounds to 17B44
// 1D16D: variable 'v4' is possibly undefined
// 1D16B: variable 'v3' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (0001D237) --------------------------------------------------------
void __fastcall sub_1D237( int a1, int a2, int a3)
{
  char v3; // dl
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int16_t i; // dx
  int v9; // edi
  int64_t v10; // rax
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  char v17[40]; // [esp+8h] [ebp-60h] BYREF
  int16_t v18; // [esp+30h] [ebp-38h]
  int16_t v19; // [esp+32h] [ebp-36h]
  int16_t v20; // [esp+34h] [ebp-34h]
  int16_t v21; // [esp+36h] [ebp-32h]
  int16_t v22; // [esp+38h] [ebp-30h]
  _BYTE v23[16]; // [esp+44h] [ebp-24h] BYREF
  int v24; // [esp+54h] [ebp-14h]
  int v25; // [esp+58h] [ebp-10h] BYREF
  int v26; // [esp+5Ch] [ebp-Ch]
  int v27; // [esp+60h] [ebp-8h]
  char v28; // [esp+64h] [ebp-4h]

  v28 = a3;
  v26 = -1;
  v3 = byte_178A64;
  sub_1FD06(615);
  v4 = 0;
  do
  {
    v23[(int16_t)v4] = 1;
    v5 = 50 * (int16_t)v4++;
    byte_19A744[v5] = v3;
  }
  while ( (int16_t)v4 < 15 );
  v6 = *(_DWORD *)(3753 * a1 + dword_197F98 + 50);
  if ( v6 > 32000 )
    v6 = 32000;
  v7 = 20 * (v6 / 20);
  if ( (int16_t)v7 >= 100 )
  {
    v18 = 20 * ((int16_t)v7 / 5 / 20);
    v19 = 20 * ((int16_t)(2 * (int16_t)v7 / 5u) / 20);
    v20 = 20 * ((int16_t)(3 * (int16_t)v7 / 5u) / 20);
    v21 = 20 * ((int16_t)(4 * (int16_t)v7 / 5u) / 20);
    v27 = 5;
    v22 = 20 * ((int16_t)v7 / 20);
  }
  else
  {
    v18 = 20;
    v19 = 40;
    v20 = 60;
    v21 = 80;
    v22 = 100;
    v27 = (int16_t)v7 / 20;
  }
  for ( i = 0; i < (int16_t)v27; i = WORD2(v10) + 1 )
  {
    v9 = i;
    v10 = sprintf(&byte_19A744[50 * i], "  %d BC", *(&v18 + i));
    if ( *(&v18 + v9) > *(_DWORD *)(dword_197F98 + 3753 * a1 + 50) )
      v23[v9] = 0;
  }
  sub_249F9(aJimtextLbx_0, 46, &byte_19A744[50 * (int16_t)v27], 40);
  sub_249F9(aJimtext2Lbx, 8, v17, 40);
  v25 = 0;
  v11 = sub_11C4C1(10, 118, 245, (int)v17, byte_19A744, 50, (int16_t *)&v25, (int)v23, 17, 0, 0, 0, 0);
  if ( (int16_t)v11 > -1 && (int16_t)v11 < (int16_t)v27 )
  {
    v12 = 2 * (int16_t)v11;
    LOWORD(v11) = *(int16_t *)((char *)&v18 + v12);
    v26 = v11;
    if ( v28 == 1 )
    {
      v13 = dword_197F98;
      *(_DWORD *)(dword_197F98 + 3753 * a1 + 50) -= (int16_t)v26;
      v24 = a2;
      v14 = 3753 * a2;
      *(_DWORD *)(v13 + v14 + 50) += *(int16_t *)((char *)&v18 + v12);
      word_19AA36 = -1;
      if ( *(_BYTE *)(v13 + v14 + 40) == 100 )
      {
        sub_1B724(a1, v24, *(int16_t *)((char *)&v18 + v12), 1, (int16_t *)a1);
      }
      else
      {
        sub_53723(a1, v24, 1, *(int16_t *)((char *)&v18 + v12), &word_19AA40);
        if ( *(int16_t *)((char *)&v18 + v12) >= 5 * (dword_192FD8 - 35000) )
          sub_276E6(v24, a1, 1);
      }
    }
  }
  JUMPOUT(0x1C7E0);
}
// 1D499: control flows out of bounds to 1C7E0
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 178A64: using guessed type char byte_178A64;
// 192FD8: using guessed type int dword_192FD8;
// 197F98: using guessed type int dword_197F98;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (0001D565) --------------------------------------------------------
int16_t __cdecl sub_1D565(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        char *a24, int a25, int a26, int a27,
        int a28)
{
  _BYTE *v28; // ecx
  char v29; // al
  char *v30; // esi
  char *v31; // esi
  int16_t v32; // ax
  int v33; // eax
  _BYTE *v34; // esi
  int v35; // eax
  char *v36; // edi
  char *v37; // esi
  int v38; // eax
  int v39; // eax
  int v40; // edx
  int v41; // eax
  char *v42; // eax
  int v43; // eax
  int v44; // eax
  char *v45; // edi
  char *v46; // esi
  char *v47; // edi
  char *v48; // edi
  uint8_t v49; // al
  int v50; // edx
  int v51; // ebx
  int v52; // eax
  int v53; // edx
  int v54; // eax
  int v55; // eax
  char *v56; // edi
  int v57; // esi
  char v58; // al
  char *v59; // edi
  int16_t result; // ax
  char *v61; // [esp-14h] [ebp-14ACh]

  STACK[0x29A4] = 0;
  *v28 = 0;
  v29 = byte_199CAE;
  STACK[0x2968] = *(_DWORD *)aDiplomseLbx;
  STACK[0x296C] = *(_DWORD *)&aDiplomseLbx[4];
  STACK[0x2970] = *(_DWORD *)&aDiplomseLbx[8];
  LOBYTE(STACK[0x2974]) = aDiplomseLbx[12];
  switch ( v29 )
  {
    case 1:
      v30 = aDiplomsgLbx;
      goto LABEL_7;
    case 2:
      v30 = aDiplomsfLbx;
      goto LABEL_7;
    case 3:
      v30 = aDiplomssLbx;
      goto LABEL_7;
    case 4:
      v30 = aDiplomsiLbx;
      goto LABEL_7;
    case 5:
      v30 = aDiplomspLbx;
LABEL_7:
      STACK[0x2968] = *(_DWORD *)v30;
      v31 = v30 + 4;
      STACK[0x296C] = *(_DWORD *)v31;
      v31 += 4;
      STACK[0x2970] = *(_DWORD *)v31;
      LOBYTE(STACK[0x2974]) = v31[4];
      break;
    default:
      break;
  }
  v32 = a27;
  if ( a27 == 20
    || a27 == 22
    || a27 == 29
    || a27 == 31
    || a27 == 40
    || a27 == 42
    || a27 == 49
    || a27 == 51
    || a27 == 58
    || a27 == 60
    || a27 == 72
    || a27 == 74
    || a27 == 143
    || a27 == 145
    || a27 == 106 )
  {
    v32 = a27 - 1;
  }
  sub_126C91((int)&STACK[0x2968], v32, (int)&a28, 0, 1u, 5202);
  v33 = 200 * (int16_t)(sub_1247A0(BYTE1(a28)) - 1);
  STACK[0x29A8] = 0;
  STACK[0x299C] = (unsigned int)&a28 + v33 + 2;
  while ( 1 )
  {
    v34 = (_BYTE *)(STACK[0x299C] + SLOWORD(STACK[0x29A8]));
    if ( !*v34 )
      break;
    switch ( *v34 )
    {
      case 0x80:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v35 = a26;
        goto LABEL_28;
      case 0x81:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v38 = a26;
        goto LABEL_30;
      case 0x82:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v38 = a25;
        goto LABEL_30;
      case 0x83:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v35 = a25;
        goto LABEL_28;
      case 0x84:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v41 = a26;
        goto LABEL_34;
      case 0x85:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v41 = a25;
LABEL_34:
        v36 = a24;
        v42 = sub_1DE17((_BYTE *)(dword_197F98 + 3753 * v41 + 21));
        goto LABEL_35;
      case 0x86:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v43 = *(int16_t *)(3753 * a25 + dword_197F98 + 2 * a26 + 1663);
        goto LABEL_38;
      case 0x87:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v38 = *(char *)(3753 * a25 + dword_197F98 + a26 + 1927);
LABEL_30:
        v39 = 3753 * v38;
        v40 = dword_197F98;
        goto LABEL_89;
      case 0x88:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v40 = 3753 * *(char *)(dword_197F98 + 3753 * a25 + a26 + 1927);
        v39 = dword_197F98;
        goto LABEL_89;
      case 0x89:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v36 = a24;
        v42 = sub_10F7A1(*(uint8_t *)(a26 + 3753 * a25 + dword_197F98 + 1967), a25);
LABEL_35:
        v37 = v42;
        goto LABEL_90;
      case 0x8A:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        if ( *(_BYTE *)(dword_197F98 + 3753 * a25 + a26 + 1575) == 1
          || *(_BYTE *)(3753 * a25 + dword_197F98 + a26 + 1575) == 2 )
        {
          v44 = *(char *)(a26 + dword_197F98 + 3753 * a25 + 1575);
          goto LABEL_45;
        }
        if ( *(_BYTE *)(3753 * a25 + dword_197F98 + a26 + 1583) )
        {
          v45 = a24;
          v46 = (char *)dword_19A2C4;
          goto LABEL_46;
        }
        if ( !*(_BYTE *)(a26 + dword_197F98 + 3753 * a25 + 1591) )
          goto LABEL_49;
        v45 = a24;
        v46 = (char *)dword_19A2B8;
        goto LABEL_46;
      case 0x8B:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v35 = *(char *)(3753 * a25 + dword_197F98 + a26 + 1927);
LABEL_28:
        v36 = a24;
        v37 = (char *)(dword_197F98 + 3753 * v35 + 1);
        goto LABEL_90;
      case 0x8C:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        switch ( *(_BYTE *)(3753 * a25 + dword_197F98 + a26 + 1767) )
        {
          case 1:
            v50 = 75;
            goto LABEL_64;
          case 2:
            v50 = 76;
            goto LABEL_64;
          case 3:
            v50 = 77;
            goto LABEL_64;
          case 4:
            v50 = 78;
LABEL_64:
            v46 = (char *)&STACK[0x2968];
            v45 = a24;
            sub_249F9(aJimtext2Lbx, v50, (char *)&STACK[0x2968], 40);
            break;
          default:
            v46 = aFwee;
            v45 = a24;
            break;
        }
        goto LABEL_46;
      case 0x8D:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v36 = a24;
        v37 = *(char **)((char *)&off_17EB3D + 19 * *(int16_t *)(3753 * a25 + dword_197F98 + 2 * a26 + 1647));
        goto LABEL_90;
      case 0x8E:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        if ( byte_199CAE )
          sprintf(&STACK[0x2968], "%d,%d", dword_192FD8 / 10, dword_192FD8 % 10);
        else
          sprintf(&STACK[0x2968], "%d.%d", dword_192FD8 / 10, dword_192FD8 % 10);
        v37 = (char *)&STACK[0x2968];
        v36 = a24;
        goto LABEL_90;
      case 0x8F:
        v48 = a24;
        a24[SLOWORD(STACK[0x29A4])] = 0;
        goto LABEL_93;
      case 0x90:
      case 0x95:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v51 = 3753 * a25 + dword_197F98;
        STACK[0x29A0] = 3753 * a25;
        v52 = v51 + a26;
        if ( *(_BYTE *)(v52 + 1887) )
        {
          strcpy((char *)&STACK[0x2968], (char *)dword_19A2CC);
          if ( *(_BYTE *)(a26 + STACK[0x29A0] + dword_197F98 + 1887) == 1 )
            v53 = 5;
          else
            v53 = 10;
          sub_24E08(&STACK[0x2968], v53, 40);
          goto LABEL_80;
        }
        if ( *(_BYTE *)(v52 + 1895) )
        {
          v45 = a24;
          v46 = sub_10F7A1(*(uint8_t *)(v52 + 1895), a25);
        }
        else
        {
          v54 = v51 + 2 * a26;
          if ( *(_WORD *)(v54 + 1911) )
          {
            sprintf(&STACK[0x2968], "%d BC", *(int16_t *)(v54 + 1911));
LABEL_80:
            v46 = (char *)&STACK[0x2968];
            v45 = a24;
            goto LABEL_46;
          }
          if ( *(int16_t *)(v54 + 1975) == -1 )
            goto LABEL_49;
          sub_249F9(aJimtext2Lbx, 58, (char *)&STACK[0x2968], 50);
          v45 = a24;
          v46 = (char *)&STACK[0x2968];
          sub_24E27();
        }
LABEL_46:
        v47 = (char *)(v45 - 1);
        do
          ++v47;
        while ( *v47 );
        strcpy(v47, v46);
LABEL_49:
        v48 = a24;
LABEL_93:
        STACK[0x29A4] = strlen(v48);
LABEL_97:
        ++STACK[0x29A8];
        break;
      case 0x91:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v40 = dword_197F98;
        v55 = *(char *)(dword_197F98 + 3753 * a25 + a26 + 1927);
        goto LABEL_88;
      case 0x92:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v49 = *(_BYTE *)(dword_197F98 + 3753 * a25 + a26 + 1759);
        if ( v49 < 7u )
          goto LABEL_60;
        if ( v49 <= 7u )
        {
          v45 = a24;
          v46 = (char *)dword_19A2C4;
        }
        else if ( v49 == 8 )
        {
          v45 = a24;
          v46 = (char *)dword_19A2B8;
        }
        else
        {
LABEL_60:
          v44 = *(char *)(a26 + dword_197F98 + 3753 * a25 + 1759);
LABEL_45:
          v45 = a24;
          v46 = (char *)dword_199150[v44];
        }
        goto LABEL_46;
      case 0x93:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v43 = *(int16_t *)(3753 * a25 + dword_197F98 + 2 * a26 + 1663);
LABEL_38:
        v36 = a24;
        v37 = (char *)(113 * v43 + dword_19306C);
        goto LABEL_90;
      case 0x94:
        a24[SLOWORD(STACK[0x29A4])] = 0;
        v40 = dword_197F98;
        v55 = *(char *)(dword_197F98 + 3753 * a25 + a26 + 2038);
LABEL_88:
        v39 = 3753 * v55;
LABEL_89:
        v36 = a24;
        v37 = (char *)(v40 + v39 + 21);
LABEL_90:
        v61 = v36;
        v56 = (char *)(v36 - 1);
        do
          ++v56;
        while ( *v56 );
        strcpy(v56, v37);
        v48 = v61;
        goto LABEL_93;
      default:
        v57 = SLOWORD(STACK[0x29A4]);
        v58 = *(_BYTE *)(STACK[0x299C] + SLOWORD(STACK[0x29A8]));
        ++STACK[0x29A4];
        a24[v57] = v58;
        goto LABEL_97;
    }
  }
  a24[SLOWORD(STACK[0x29A4])] = 0;
  if ( a27 == 20
    || a27 == 22
    || a27 == 29
    || a27 == 31
    || a27 == 40
    || a27 == 42
    || a27 == 49
    || a27 == 51
    || a27 == 58
    || a27 == 60
    || a27 == 72
    || a27 == 74
    || a27 == 143
    || a27 == 145 )
  {
    v59 = (char *)(a24 - 1);
    do
      ++v59;
    while ( *v59 );
    strcpy(v59, (char *)dword_19A2C0);
  }
  if ( (_BYTE)a28 )
    result = word_19AA3C;
  else
    result = word_19AA46;
  if ( result != word_19AA44 )
    word_19AA44 = result;
  return result;
}
// 1D58A: variable 'v28' is possibly undefined
// 24E08: using guessed type int __fastcall sub_24E08(_DWORD, _DWORD, _DWORD);
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 17EB3D: using guessed type _UNKNOWN *off_17EB3D;
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 197F98: using guessed type int dword_197F98;
// 199150: using guessed type int dword_199150[];
// 199CAE: using guessed type char byte_199CAE;
// 19A2B8: using guessed type int dword_19A2B8;
// 19A2C0: using guessed type int dword_19A2C0;
// 19A2C4: using guessed type int dword_19A2C4;
// 19A2CC: using guessed type int dword_19A2CC;
// 19AA3C: using guessed type int16_t word_19AA3C;
// 19AA44: using guessed type int16_t word_19AA44;
// 19AA46: using guessed type int16_t word_19AA46;


//----- (0001DE17) --------------------------------------------------------
char *__fastcall sub_1DE17(_BYTE *a1)
{
  if ( byte_199CAE )
    return &byte_178A64;
  if ( *a1 == 65
    || *a1 == 97
    || *a1 == 69
    || *a1 == 101
    || *a1 == 73
    || *a1 == 105
    || *a1 == 79
    || *a1 == 111
    || *a1 == 85
    || *a1 == 117 )
  {
    return aAn;
  }
  return (char *)aAcg;
}
// 178A64: using guessed type char byte_178A64;
// 178B20: using guessed type wchar_t aAcg[4];
// 199CAE: using guessed type char byte_199CAE;


//----- (0001DEF8) --------------------------------------------------------
void __usercall sub_1DEF8(int16_t *a1)
{
  int v1; // ecx
  unsigned int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int16_t v9; // dx
  char *v10; // esi
  char *v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  _BOOL1 v15; // zf
  int16_t v16; // si
  int v17; // eax
  int16_t v18; // ax
  int v19; // eax
  int v20; // edx
  int v21; // eax
  char *v22; // eax
  int16_t v23; // ax
  int v24; // edx
  int16_t v25; // dx
  int16_t v26; // ax
  int16_t v27; // si
  int v28; // eax
  int v29; // eax
  int16_t v30; // ax
  int v31; // edx
  int16_t *v32; // [esp-4h] [ebp-5FCh]
  int v33[15]; // [esp+0h] [ebp-5F8h] BYREF
  hr_int128_t v34; // [esp+3Ch] [ebp-5BCh]
  int64_t v35; // [esp+4Ch] [ebp-5ACh]
  int64_t v36; // [esp+54h] [ebp-5A4h]
  int64_t v37; // [esp+5Ch] [ebp-59Ch]
  int v38; // [esp+64h] [ebp-594h]
  int v39; // [esp+68h] [ebp-590h]
  int v40; // [esp+6Ch] [ebp-58Ch]
  int64_t v41; // [esp+70h] [ebp-588h]
  _BYTE v42[400]; // [esp+350h] [ebp-2A8h] BYREF
  char v43[212]; // [esp+4E0h] [ebp-118h] BYREF
  char v44[40]; // [esp+5B4h] [ebp-44h] BYREF
  _BYTE v45[16]; // [esp+5DCh] [ebp-1Ch] BYREF
  int16_t v46; // [esp+5ECh] [ebp-Ch] BYREF
  int v47; // [esp+5F0h] [ebp-8h] BYREF
  int v48; // [esp+5F4h] [ebp-4h]

  byte_19AA69 = 0;
  word_19AA5A = 10;
  word_19AA58 = 141;
  word_19AA56 = 300;
  word_19AA5C = 50;
  word_19AA36 = 0;
  byte_19A4EC = byte_178A64;
  byte_19A64A = byte_178A64;
  word_19AA40 = 0;
  if ( (uint8_t)byte_19AA67 == word_19999C )
  {
    sub_1F34B();
    byte_19A190 = byte_19AA68;
    v1 = 8;
    byte_19A191 = byte_19AA67;
    v2 = (unsigned int)&byte_19A190;
    word_19A194 = 1012;
    v3 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA68 + 43);
    word_19A196 = -1;
    v4 = sub_F6816(v3, 2000, (int)&byte_19A190, 8u);
    sub_FE8BE(v4, 2000, (int)&byte_19A190, a1);
    do
      sub_1F12F(8, (int)&byte_19A190, a1);
    while ( !word_19AA52 );
  }
  else
  {
    sub_1F34B();
    byte_19A190 = byte_19AA67;
    v1 = 8;
    byte_19A191 = byte_19AA68;
    v2 = (unsigned int)&byte_19A190;
    word_19A194 = 1012;
    v5 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 43);
    word_19A196 = -1;
    v6 = sub_F6816(v5, 2000, (int)&byte_19A190, 8u);
    sub_FE8BE(v6, 2000, (int)&byte_19A190, a1);
    do
      sub_1F12F(8, (int)&byte_19A190, a1);
    while ( !word_19AA52 );
  }
  v48 = 0;
  word_19AA36 = 0;
  byte_19A64A = byte_178A64;
  word_19AA40 = 0;
  if ( (uint8_t)byte_19AA67 != word_19999C )
    sub_1F34B();
  sub_117174(1);
  while ( !(_WORD)v48 && !word_19AA48 )
  {
    sub_1191CA((int)sub_16F00, 2);
    if ( (uint8_t)byte_19AA67 == word_19999C )
    {
      byte_19AA69 = 0;
      if ( *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 2226) == 1
        || *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA68 + 2226) == 1 )
      {
        v2 = 1;
        sub_17227((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, 1, a1);
      }
      else
      {
        v7 = 0;
        do
        {
          v8 = (int16_t)v7++;
          v45[v8] = 1;
        }
        while ( (int16_t)v7 < 11 );
        sub_17847((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, v45);
        v9 = 0;
        do
        {
          v10 = (char *)dword_19A26C[v9];
          v11 = &byte_19A744[50 * v9++];
          v32 = (int16_t *)v11;
          strcpy(v11, v10);
          a1 = v32;
        }
        while ( v9 < 11 );
        sub_120BB5(4, (int)&unk_180DCC);
        sub_120EB9((int)&unk_180DD4);
        sub_120F07((int)&unk_180DDC);
        sub_120E24(4);
        sub_1FC13(11, (int)&unk_180DF6);
        v2 = 245;
        v1 = dword_19A2D4;
        v47 = 0;
        switch ( (uint16_t)sub_11C4C1(
                                     10,
                                     118,
                                     245,
                                     dword_19A2D4,
                                     byte_19A744,
                                     50,
                                     (int16_t *)&v47,
                                     (int)v45,
                                     17,
                                     0,
                                     0,
                                     0,
                                     0) )
        {
          case 0xFFFF:
          case 9u:
            byte_19A190 = byte_19AA67;
            byte_19A191 = byte_19AA68;
            v48 = 1;
            word_19A194 = 130;
            v1 = 8;
            v2 = (unsigned int)&byte_19A190;
            v12 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA68 + 43);
            word_19A196 = -1;
            v13 = sub_F6816(v12, 2000, (int)&byte_19A190, 8u);
            sub_FE8BE(v13, 2000, (int)&byte_19A190, a1);
            break;
          case 0u:
            byte_19A64A = byte_178A64;
            sub_17D5B((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            byte_19AA69 = 0;
            word_19AA40 = 0;
            word_19AA36 = 0;
            break;
          case 1u:
            byte_19A64A = byte_178A64;
            sub_180D4((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            word_19AA36 = 0;
            word_19AA40 = 0;
            byte_19A64A = byte_178A64;
            break;
          case 2u:
            byte_19A64A = byte_178A64;
            sub_18B79();
            break;
          case 3u:
            byte_19A64A = byte_178A64;
            sub_194C5();
            break;
          case 4u:
            byte_19A64A = byte_178A64;
            sub_1CB4D((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            break;
          case 5u:
            if ( (uint16_t)sub_179F4(a1) == 1 )
              sub_19919(a1);
            break;
          case 6u:
            sub_1D0F8(a1);
            if ( (_WORD)v14 == 1 )
              v48 = v14;
            break;
          case 7u:
            sub_200C3((int16_t *)(uint8_t)byte_19AA68, (uint8_t)byte_19AA67, 245, v1);
            if ( word_19AA48 == 1 )
              v48 = 1;
            break;
          case 8u:
            sub_1ED17(a1);
            sub_1F34B();
            break;
          default:
            break;
        }
      }
      sub_11C2F0();
    }
    else
    {
      if ( !byte_19AA69 )
        sub_11C2F0();
      if ( word_19AA48 == 1 )
        v48 = 1;
      if ( word_19AA40 == word_19AA36 || word_19AA40 == 128 )
      {
        sub_1EDE9((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, v1, v2, a1);
      }
      else
      {
        v1 = 14;
        a1 = &word_1DE96;
        byte_19AA69 = 0;
        do
        {
          if ( !v1 )
            break;
          v15 = *a1++ == word_19AA40;
          --v1;
        }
        while ( !v15 );
        switch ( v1 )
        {
          case 0:
            continue;
          case 1:
            if ( !word_19AA48 )
              sub_19919(a1);
            v48 = 1;
            continue;
          case 2:
            word_19AA40 = word_19A196;
            word_19AA4E = word_19A192;
            v16 = sub_1B1A7((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, word_19A192);
            word_19AA36 = word_19AA40;
            byte_19A190 = byte_19AA67;
            byte_19A191 = byte_19AA68;
            word_19A194 = word_19AA40;
            v1 = 8;
            a1 = (int16_t *)dword_197F98;
            v2 = (unsigned int)&byte_19A190;
            word_19A196 = v16;
            v17 = sub_F6816(
                    *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 43),
                    2000,
                    (int)&byte_19A190,
                    8u);
            sub_FE8BE(v17, 2000, (int)&byte_19A190, a1);
            word_19AA40 = 0;
            word_19AA36 = 0;
            if ( (uint16_t)v16 < 2u )
              goto LABEL_87;
            if ( v16 == 3 )
              sub_1F17D();
            continue;
          case 3:
            word_19AA40 = word_19A196;
            sub_1883A((uint8_t)byte_19AA67, word_19A192);
            if ( (uint16_t)word_19A192 < 7u )
            {
              if ( word_19A192 && (uint16_t)word_19A192 <= 2u )
                sub_5138E((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            }
            else if ( (uint16_t)word_19A192 <= 7u )
            {
              sub_519AC((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            }
            else if ( (uint16_t)word_19A192 <= 8u )
            {
              sub_5175B((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            }
            else if ( (uint16_t)word_19A192 <= 0xAu )
            {
              sub_51C02((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            }
            goto LABEL_56;
          case 4:
            sub_18596();
            word_19AA40 = 0;
            word_19AA36 = 0;
            sub_51078((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
            continue;
          case 5:
            word_19AA40 = 0;
            word_19AA36 = 0;
            v48 = 1;
            sub_18560();
            sub_19919(a1);
            continue;
          case 6:
            word_19AA40 = 0;
            v2 = word_19A196;
            word_19AA36 = 0;
            sub_185BD((uint8_t)byte_19AA67, word_19A192, word_19A196);
            word_19AA40 = 0;
            word_19AA36 = 0;
            switch ( word_19A192 )
            {
              case 1:
                v31 = dword_197F98;
                v2 = word_19A196;
                *(_DWORD *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 50) -= word_19A196;
                *(_DWORD *)(v31 + 3753 * (uint8_t)byte_19AA68 + 50) += word_19A196;
                break;
              case 2:
                v2 = word_19A196;
                sub_52049((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, word_19A196);
                break;
              case 3:
                v2 = dword_197F98;
                sub_E4204(dword_197F98 + 3753 * (uint8_t)byte_19AA68, word_19A196, (int)a1);
                break;
              case 4:
                v2 = (uint8_t)byte_19AA68;
                if ( sub_E4A09(word_19A196, (uint8_t)byte_19AA67, (uint8_t)byte_19AA68) == 1 )
                {
                  v2 = (uint8_t)byte_19AA68;
                  sub_E4AB3(word_19A196, (uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
                }
                break;
              default:
                continue;
            }
            continue;
          case 7:
            word_19AA40 = 0;
            word_19AA36 = 0;
            sub_186D3((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, word_19A192);
            v26 = sub_1B3B5((uint8_t)byte_19AA68, (uint8_t)byte_19AA67, word_19A192, word_19A196);
            word_19AA40 = 168;
            v27 = v26;
            if ( v26 == 1 )
            {
              sub_1B487((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, word_19A196, word_19A192, (int)a1);
              word_19AA40 = 169;
            }
            word_19AA36 = word_19AA40;
            byte_19A190 = byte_19AA67;
            byte_19A191 = byte_19AA68;
            word_19A194 = word_19AA40;
            v1 = 8;
            v2 = (unsigned int)&byte_19A190;
            v28 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 43);
            word_19A196 = v27;
            goto LABEL_86;
          case 8:
            word_19AA40 = word_19AA36;
            if ( (int16_t)sub_1A1FD(word_19A192, (uint8_t)byte_19AA67, (uint8_t)byte_19AA68, 0) == -1 )
            {
              sub_1F34B();
              v18 = 0;
            }
            else
            {
              if ( sub_E4A09(word_19A192, (uint8_t)byte_19AA67, (uint8_t)byte_19AA68) == 1 )
                sub_E4AB3(word_19A192, (uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
              sub_1F17D();
              v18 = 1;
            }
            word_19A196 = v18;
            v19 = 3753 * (uint8_t)byte_19AA67;
            byte_19A190 = byte_19AA67;
            byte_19A191 = byte_19AA68;
            word_19A194 = word_19AA40;
            goto LABEL_54;
          case 9:
            word_19AA40 = word_19AA36;
            v22 = sub_10F7A1(word_19A192, (uint8_t)byte_19AA67);
            sprintf(v42, "  %s", v22);
            sub_249F9(aJimtext2Lbx, 9, v44, 40);
            if ( (int16_t)sub_19DE8(1, (int)v42, 1, (int)v44) == -1 )
            {
              sub_1F34B();
              v23 = 0;
            }
            else
            {
              sub_E4204(3753 * (uint8_t)byte_19AA68 + dword_197F98, word_19A192, (int)a1);
              sub_1F17D();
              v23 = 1;
            }
            byte_19A190 = byte_19AA67;
            byte_19A191 = byte_19AA68;
            word_19A194 = word_19AA40;
            v20 = 3753 * (uint8_t)byte_19AA67;
            word_19A196 = v23;
            v19 = dword_197F98;
            goto LABEL_55;
          case 10:
            word_19AA40 = 0;
            word_19AA36 = 0;
            sub_18AE2();
            word_19AA4A = word_19A192;
            sub_249F9(aJimtext2Lbx, 4, v44, 40);
            sub_27094((uint8_t)byte_19AA68, (uint8_t)byte_19AA67, 0, 0xC343CB00, v43, v33, &v46, 1);
            v30 = sub_19F26(
                    v46,
                    0,
                    v33[0],
                    v33[1],
                    v33[2],
                    v33[3],
                    v33[4],
                    v33[5],
                    v33[6],
                    v33[7],
                    v33[8],
                    v33[9],
                    v33[10],
                    v33[11],
                    v33[12],
                    v33[13],
                    v33[14],(int)LODWORD(v34),
                    v35,
                    v36,
                    v37,
                    v38,
                    v39,
                    v40,
                    v41);
            byte_19A190 = byte_19AA67;
            byte_19A191 = byte_19AA68;
            word_19A194 = word_19AA40;
            if ( v30 >= 0 )
              v30 = (uint8_t)v43[v30];
            word_19A196 = v30;
            v1 = 8;
            v2 = (unsigned int)&byte_19A190;
            v28 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 43);
LABEL_86:
            v29 = sub_F6816(v28, 2000, (int)&byte_19A190, 8u);
            sub_FE8BE(v29, 2000, (int)&byte_19A190, a1);
LABEL_87:
            sub_1F34B();
            continue;
          case 11:
            word_19AA40 = 0;
            word_19AA36 = 0;
            if ( word_19A192 == -1 )
            {
              sub_18B3E();
            }
            else
            {
              sub_E4204(dword_197F98 + 3753 * (uint8_t)byte_19AA67, word_19AA4A, (int)a1);
              v2 = dword_197F98;
              sub_E4204(dword_197F98 + 3753 * (uint8_t)byte_19AA68, word_19A196, (int)a1);
              sub_18B27();
            }
            goto LABEL_56;
          case 12:
            word_19AA40 = 0;
            word_19AA36 = 0;
            sprintf(&byte_19A64A, &byte_178A64);
            continue;
          case 13:
            word_19AA40 = word_19AA36;
            sprintf(v42, "  %d BC", word_19A192);
            sub_249F9(aJimtext2Lbx, 9, v44, 40);
            if ( (int16_t)sub_19DE8(1, (int)v42, 1, (int)v44) == -1 )
            {
              sub_1F34B();
              v25 = 0;
            }
            else
            {
              v24 = dword_197F98;
              *(_DWORD *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 50) -= word_19A192;
              *(_DWORD *)(v24 + 3753 * (uint8_t)byte_19AA68 + 50) += word_19A192;
              sub_1F17D();
              v25 = 1;
            }
            byte_19A190 = byte_19AA67;
            byte_19A191 = byte_19AA68;
            word_19A194 = word_19AA40;
            v19 = 3753 * (uint8_t)byte_19AA67;
            word_19A196 = v25;
LABEL_54:
            v20 = dword_197F98;
LABEL_55:
            v1 = 8;
            v2 = (unsigned int)&byte_19A190;
            v21 = sub_F6816(*(int16_t *)(v20 + v19 + 43), 2000, (int)&byte_19A190, 8u);
            sub_FE8BE(v21, 2000, (int)&byte_19A190, a1);
LABEL_56:
            word_19AA40 = 0;
            word_19AA36 = 0;
            break;
        }
      }
    }
  }
  JUMPOUT(0x17204);
}
// 1E5BC: control flows out of bounds to 17204
// 1E352: variable 'v14' is possibly undefined
// 1DE96: using guessed type int16_t word_1DE96;
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 178A64: using guessed type char byte_178A64;
// 197F98: using guessed type int dword_197F98;
// 19999C: using guessed type int16_t word_19999C;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19A26C: using guessed type int dword_19A26C[];
// 19A2D4: using guessed type int dword_19A2D4;
// 19A4EC: using guessed type char byte_19A4EC;
// 19A64A: using guessed type char byte_19A64A;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA4A: using guessed type int16_t word_19AA4A;
// 19AA4E: using guessed type int16_t word_19AA4E;
// 19AA52: using guessed type int16_t word_19AA52;
// 19AA56: using guessed type int16_t word_19AA56;
// 19AA58: using guessed type int16_t word_19AA58;
// 19AA5A: using guessed type int16_t word_19AA5A;
// 19AA5C: using guessed type int16_t word_19AA5C;
// 19AA67: using guessed type char byte_19AA67;
// 19AA68: using guessed type char byte_19AA68;
// 19AA69: using guessed type char byte_19AA69;


//----- (0001ED17) --------------------------------------------------------
void __usercall sub_1ED17(int16_t *a1)
{
  char v1; // al
  int v2; // eax
  int v3; // eax

  v1 = byte_19AA67;
  byte_19AA67 = byte_19AA68;
  byte_19AA68 = v1;
  byte_19A190 = byte_19AA67;
  byte_19A191 = v1;
  word_19AA36 = -1;
  word_19A194 = 1011;
  v2 = *(int16_t *)(dword_197F98 + 3753 * (uint8_t)byte_19AA67 + 43);
  word_19A196 = -1;
  v3 = sub_F6816(v2, 2000, (int)&byte_19A190, 8u);
  sub_FE8BE(v3, 2000, (int)&byte_19A190, a1);
  word_19AA40 = 0;
  word_19AA36 = 0;
}
// 197F98: using guessed type int dword_197F98;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA67: using guessed type char byte_19AA67;
// 19AA68: using guessed type char byte_19AA68;


//----- (0001ED9C) --------------------------------------------------------
void __usercall sub_1ED9C( int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // eax

  byte_19A190 = a1;
  word_19A194 = 1012;
  byte_19A191 = a2;
  v3 = *(int16_t *)(dword_197F98 + 3753 * a1 + 43);
  word_19A196 = -1;
  v4 = sub_F6816(v3, 2000, (int)&byte_19A190, 8u);
  sub_FE8BE(v4, 2000, (int)&byte_19A190, a3);
}
// 197F98: using guessed type int dword_197F98;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;


//----- (0001EDE9) --------------------------------------------------------
void __usercall sub_1EDE9( int a1, int a2, int a3, unsigned int a4, int16_t *a5)
{
  int16_t v5; // si
  unsigned int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  sub_1191CA((int)sub_1F0BC, 2);
  sub_12C2A0();
  if ( byte_19AA69 )
    goto LABEL_6;
  word_19AA54 = -1000;
  sub_11C2F0();
  sub_1FD06(694);
  a3 = 188;
  v5 = sub_11438B(15, 139, 157, 162, &aAcg[1], 0);
  a4 = sub_11438B(15, 165, 157, 188, &aAcg[2], 0);
  v6 = sub_114C72(&aAcg[3], 165);
  v7 = sub_1171AB(v6, v6, a4, 188);
  a5 = (int16_t *)v7;
  if ( (_WORD)v7 == (_WORD)a4 || (_WORD)v7 == (_WORD)v6 )
  {
    byte_19A190 = a1;
    byte_19A191 = a2;
    word_19A194 = 1006;
    a3 = 8;
    a4 = (unsigned int)&byte_19A190;
    v8 = *(int16_t *)(3753 * a1 + dword_197F98 + 43);
    v6 = 2000;
    word_19A196 = -1;
    v9 = sub_F6816(v8, 2000, (int)&byte_19A190, 8u);
    sub_FE8BE(v9, 2000, (int)&byte_19A190, a5);
    word_19AA48 = 1;
  }
  if ( (_WORD)a5 == v5 )
  {
LABEL_6:
    v6 = a2;
    LOBYTE(v7) = sub_1EF5B(a1, a2, a4, a3);
  }
  v10 = sub_1F0BC(v7, v6, a4, a3);
  if ( byte_19AA69 == 1 )
  {
    v6 = word_19AA58;
    a4 = (int16_t)(word_19AA56 + word_19AA5A);
    LOBYTE(v10) = sub_1298DE(word_19AA5A, word_19AA58, a4, word_19AA5C + word_19AA58 - 1);
  }
  sub_1077D(v10, v6, a4, a5);
  sub_12C2C6(2);
  sub_1191CA((int)sub_16F00, 2);
  JUMPOUT(0x17F39);
}
// 1EF56: control flows out of bounds to 17F39
// 1EEF6: variable 'v7' is possibly undefined
// 1EF38: variable 'v10' is possibly undefined
// 178B20: using guessed type wchar_t aAcg[4];
// 197F98: using guessed type int dword_197F98;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA54: using guessed type int16_t word_19AA54;
// 19AA56: using guessed type int16_t word_19AA56;
// 19AA58: using guessed type int16_t word_19AA58;
// 19AA5A: using guessed type int16_t word_19AA5A;
// 19AA5C: using guessed type int16_t word_19AA5C;
// 19AA69: using guessed type char byte_19AA69;


//----- (0001EF5B) --------------------------------------------------------
char __fastcall sub_1EF5B( int a1, int a2, int a3, int a4)
{
  uint16_t v5; // ax
  int v6; // eax

  if ( byte_19AA69 )
  {
    if ( word_19AA48 == 1 )
      byte_19AA69 = 0;
    v5 = sub_1171AB(a1, a2, a1, a4);
    if ( word_19AA48 == 1 )
      byte_19AA69 = 0;
    if ( v5 == word_19AA54 || v5 == word_19AA50 )
    {
      sub_11C2F0();
      byte_19AA69 = 0;
      strcpy((char *)byte_19A484, &byte_19A4EC);
      v6 = sub_F6816(*(int16_t *)(dword_197F98 + 3753 * a1 + 43), 2100, (int)byte_19A484, 0x64u);
      sub_FE8BE(v6, 2100, (int)byte_19A484, byte_19A484);
      LOBYTE(v5) = byte_178A64;
      LOBYTE(byte_19A484[0]) = byte_178A64;
    }
  }
  else
  {
    sub_1FD06(694);
    sub_11C2F0();
    byte_19AA69 = 1;
    sub_120CCB(4, (int)&unk_180DCC);
    byte_19A4EC = byte_178A64;
    byte_1B071C[0] = byte_178A64;
    word_19AA50 = sub_11438B(0, 0, 639, 479, &byte_178A64, 0);
    v5 = (uint16_t)sub_115BEA(
                             word_19AA5A,
                             word_19AA58,
                             word_19AA56 - 20,
                             word_19AA5C,
                             (int)&byte_19A4EC,
                             80,
                             0,
                             0,
                             41,
                             0);
    word_1844CA = 1;
    dword_1844C6 = 0;
    byte_1B3E18 = 1;
    word_19AA54 = v5;
    HIWORD(dword_1844CE) = v5;
  }
  return v5;
}
// 178A64: using guessed type char byte_178A64;
// 1844C6: using guessed type int dword_1844C6;
// 1844CA: using guessed type int16_t word_1844CA;
// 1844CE: using guessed type int dword_1844CE;
// 197F98: using guessed type int dword_197F98;
// 19A484: using guessed type int16_t byte_19A484[50];
// 19A4EC: using guessed type char byte_19A4EC;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA50: using guessed type int16_t word_19AA50;
// 19AA54: using guessed type int16_t word_19AA54;
// 19AA56: using guessed type int16_t word_19AA56;
// 19AA58: using guessed type int16_t word_19AA58;
// 19AA5A: using guessed type int16_t word_19AA5A;
// 19AA5C: using guessed type int16_t word_19AA5C;
// 19AA69: using guessed type char byte_19AA69;
// 1B3E18: using guessed type char byte_1B3E18;


//----- (0001F0BC) --------------------------------------------------------
int __fastcall sub_1F0BC(int a1, int a2, int a3, int a4)
{
  int16_t v4; // dx
  int16_t v5; // ax
  int v6; // ebx

  sub_16F00(a1, a2, a3, a4);
  sub_120CCB(4, (int)&unk_180DCC);
  if ( byte_19AA69 )
  {
    v4 = 117;
    v5 = 10;
    v6 = dword_19A2B0;
  }
  else
  {
    sub_1212B3(10, 117, dword_19A2D8);
    sub_1212B3(10, 141, dword_19A288);
    v4 = 166;
    v5 = 18;
    v6 = dword_19A4E8;
  }
  return sub_1212B3(v5, v4, v6);
}
// 19A288: using guessed type int dword_19A288;
// 19A2B0: using guessed type int dword_19A2B0;
// 19A2D8: using guessed type int dword_19A2D8;
// 19A4E8: using guessed type int dword_19A4E8;
// 19AA69: using guessed type char byte_19AA69;


//----- (0001F12F) --------------------------------------------------------
int __usercall sub_1F12F(int a1, int a2, int16_t *a3)
{
  int v3; // eax
  int v4; // eax

  word_19AA36 = 0;
  word_19AA40 = 0;
  sub_1191CA((int)sub_1F0BC, 2);
  sub_12C2A0();
  LOWORD(v3) = sub_11C2F0();
  v4 = sub_16F00(v3, 2, a2, a1);
  sub_1077D(v4, 2, a2, a3);
  sub_12C2C6(2);
  return sub_1191CA((int)sub_16F00, 2);
}
// 1F15A: variable 'v3' is possibly undefined
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (0001F17D) --------------------------------------------------------
char sub_1F17D()
{
  int16_t v0; // bx

  if ( (uint16_t)word_19AA4E < 3u )
  {
    if ( word_19AA4E )
    {
      if ( (uint16_t)word_19AA4E <= 1u )
        v0 = 1;
      else
        v0 = 2;
      sub_5232E((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, v0);
    }
  }
  else if ( (uint16_t)word_19AA4E <= 3u )
  {
    sub_524FB((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
  }
  else if ( (uint16_t)word_19AA4E >= 7u )
  {
    if ( (uint16_t)word_19AA4E <= 7u )
    {
      sub_5223F((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
    }
    else if ( word_19AA4E == 8 )
    {
      sub_52150((uint8_t)byte_19AA67, (uint8_t)byte_19AA68);
    }
  }
  return sub_188E0((uint8_t)byte_19AA67, (uint8_t)byte_19AA68, word_19AA4E, 3);
}
// 19AA4E: using guessed type int16_t word_19AA4E;
// 19AA67: using guessed type char byte_19AA67;
// 19AA68: using guessed type char byte_19AA68;


//----- (0001F230) --------------------------------------------------------
char __fastcall sub_1F230(int a1, unsigned int a2, int a3, int a4)
{
  char result; // al

  if ( a2 >= 0x7D0u && a2 < 0xBB8u )
  {
    if ( a2 == 2000 )
    {
      byte_19A484[0] = byte_178A64;
      byte_19A550[0] = byte_178A64;
      byte_19A190 = *(_BYTE *)a4;
      byte_19A191 = *(_BYTE *)(a4 + 1);
      word_19A194 = *(_WORD *)(a4 + 4);
      word_19A196 = *(_WORD *)(a4 + 6);
      word_19A192 = *(_WORD *)(a4 + 2);
      if ( (uint16_t)word_19A194 < 0x3F3u )
      {
        if ( word_19A194 == 1006 )
        {
          word_19AA48 = 1;
          return result;
        }
      }
      else if ( (uint16_t)word_19A194 <= 0x3F3u )
      {
        word_19A194 = 0;
        word_19AA40 = 0;
        word_19AA36 = 0;
        result = sprintf(&byte_19A64A, &byte_178A64);
      }
      else
      {
        if ( (uint16_t)word_19A194 <= 0x3F4u )
        {
          word_19AA52 = 1;
          return result;
        }
        if ( word_19A194 == 1014 )
          return result;
      }
      word_19AA40 = word_19A194;
      byte_19AA67 = byte_19A190;
      byte_19AA68 = byte_19A191;
    }
    else if ( a2 == 2100 )
    {
      strcpy(&byte_19A550, (char *)a4);
    }
  }
  return result;
}
// 1265F2: using guessed type _DWORD sprintf(_DWORD, char *, ...);
// 178A64: using guessed type char byte_178A64;
// 19A190: using guessed type char byte_19A190;
// 19A191: using guessed type char byte_19A191;
// 19A192: using guessed type int16_t word_19A192;
// 19A194: using guessed type int16_t word_19A194;
// 19A196: using guessed type int16_t word_19A196;
// 19A484: using guessed type char byte_19A484;
// 19A550: using guessed type char byte_19A550;
// 19A64A: using guessed type char byte_19A64A;
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;
// 19AA48: using guessed type int16_t word_19AA48;
// 19AA52: using guessed type int16_t word_19AA52;
// 19AA67: using guessed type char byte_19AA67;
// 19AA68: using guessed type char byte_19AA68;


//----- (0001F34B) --------------------------------------------------------
void sub_1F34B()
{
  word_19AA40 = 0;
  word_19AA36 = 0;
  JUMPOUT(0x1857A);
}
// 1F377: control flows out of bounds to 1857A
// 19AA36: using guessed type int16_t word_19AA36;
// 19AA40: using guessed type int16_t word_19AA40;


//----- (0001F37C) --------------------------------------------------------
void __usercall sub_1F37C(int a1, int a2, int a3, int16_t *a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  int v21; // ebx
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // ebx
  int v26; // eax
  int v27; // ebx
  int v28; // eax
  int v29; // ebx
  int v30; // eax
  int v31; // ebx
  int v32; // eax
  int v33; // ebx
  int v34; // eax
  int v35; // ebx
  int v36; // eax
  int v37; // ebx
  int v38; // eax
  int v39; // ebx
  int v40; // eax
  int v41; // ebx
  int v42; // eax
  int v43; // ebx
  int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // ebx
  int v48; // eax
  int v49; // ebx
  int v50; // eax
  int v51; // ebx
  int v52; // eax
  int v53; // ebx
  int v54; // eax
  int v55; // ebx
  int v56; // eax
  int16_t *v57; // [esp+0h] [ebp-4h]
  int16_t *v58; // [esp+0h] [ebp-4h]

  sub_FE8BE(a1, a2, a3, a4);
  sub_249F9(aJimtextLbx_0, 30, (char *)dword_19A2D4, 30);
  sub_249F9(aJimtextLbx_0, 31, (char *)dword_19A248, 30);
  v4 = dword_19A24C;
  LOBYTE(v5) = sub_249F9(aJimtextLbx_0, 32, (char *)dword_19A24C, 30);
  sub_FE8BE(v5, 32, v4, a4);
  sub_249F9(aJimtextLbx_0, 33, (char *)dword_19A250, 30);
  v6 = dword_19A254;
  LOBYTE(v7) = sub_249F9(aJimtextLbx_0, 34, (char *)dword_19A254, 30);
  sub_FE8BE(v7, 34, v6, a4);
  sub_249F9(aJimtextLbx_0, 35, (char *)dword_19A258, 30);
  v8 = dword_19A25C;
  LOBYTE(v9) = sub_249F9(aJimtextLbx_0, 36, (char *)dword_19A25C, 30);
  sub_FE8BE(v9, 36, v8, a4);
  sub_249F9(aJimtextLbx_0, 37, (char *)dword_19A260, 30);
  v10 = dword_19A264;
  sub_249F9(aJimtextLbx_0, 38, (char *)dword_19A264, 30);
  v11 = dword_19A268;
  LOBYTE(v10) = byte_178A64;
  *(_BYTE *)dword_19A268 = byte_178A64;
  sub_FE8BE(v11, 38, v10, a4);
  strcpy((char *)dword_19A26C, (char *)dword_19A248);
  strcpy((char *)dword_19A270, (char *)dword_19A24C);
  strcpy((char *)dword_19A274, (char *)dword_19A250);
  strcpy((char *)dword_19A278, (char *)dword_19A254);
  strcpy((char *)dword_19A27C, (char *)dword_19A258);
  strcpy((char *)dword_19A280, (char *)dword_19A25C);
  strcpy((char *)dword_19A284, (char *)dword_19A260);
  sub_249F9(aJimtext2Lbx, 65, (char *)dword_19A288, 40);
  sub_249F9(aJimtextLbx_0, 39, (char *)dword_19A28C, 40);
  strcpy((char *)dword_19A290, (char *)dword_19A264);
  *(_BYTE *)dword_19A294 = byte_178A64;
  v12 = dword_19A1E8;
  sub_249F9(aJimtextLbx_0, 43, (char *)dword_19A1E8, 30);
  strcpy((char *)dword_19A1EC, (char *)dword_19A25C);
  strcpy((char *)dword_19A1F0, (char *)dword_19A260);
  v57 = (int16_t *)dword_19A1F4;
  strcpy((char *)dword_19A1F4, (char *)dword_19A264);
  v13 = dword_19A1F8;
  LOBYTE(v12) = byte_178A64;
  *(_BYTE *)dword_19A1F8 = byte_178A64;
  sub_FE8BE(v13, 43, v12, v57);
  strcpy((char *)dword_19A0E8, (char *)dword_19A1E8);
  strcpy((char *)dword_19A0EC, (char *)dword_19A25C);
  strcpy((char *)dword_19A0F0, (char *)dword_19A260);
  strcpy((char *)dword_19A0F4, (char *)dword_19A288);
  v58 = (int16_t *)dword_19A0F8;
  strcpy((char *)dword_19A0F8, (char *)dword_19A264);
  v14 = dword_19A0FC;
  LOBYTE(v12) = byte_178A64;
  *(_BYTE *)dword_19A0FC = byte_178A64;
  sub_FE8BE(v14, 40, v12, v58);
  sub_249F9(aJimtextLbx_0, 40, (char *)dword_19A19C, 40);
  sub_249F9(aJimtextLbx_0, 41, (char *)dword_19A1A0, 30);
  v15 = dword_19A1A4;
  LOBYTE(v16) = sub_249F9(aJimtextLbx_0, 42, (char *)dword_19A1A4, 30);
  sub_FE8BE(v16, 42, v15, v58);
  sub_249F9(aJimtextLbx_0, 43, (char *)dword_19A1A8, 30);
  v17 = dword_19A1AC;
  LOBYTE(v18) = sub_249F9(aJimtextLbx_0, 44, (char *)dword_19A1AC, 30);
  sub_FE8BE(v18, 44, v17, v58);
  sub_249F9(aJimtextLbx_0, 45, (char *)dword_19A1B0, 30);
  v19 = dword_19A1B4;
  sub_249F9(aJimtextLbx_0, 46, (char *)dword_19A1B4, 30);
  v20 = dword_19A1B8;
  LOBYTE(v19) = byte_178A64;
  *(_BYTE *)dword_19A1B8 = byte_178A64;
  sub_FE8BE(v20, 47, v19, v58);
  v21 = dword_19A1FC;
  LOBYTE(v22) = sub_249F9(aJimtextLbx_0, 47, (char *)dword_19A1FC, 30);
  sub_FE8BE(v22, 47, v21, v58);
  sub_249F9(aJimtextLbx_0, 48, (char *)dword_19A200, 40);
  v23 = dword_19A204;
  LOBYTE(v24) = sub_249F9(aJimtextLbx_0, 49, (char *)dword_19A204, 40);
  sub_FE8BE(v24, 49, v23, v58);
  sub_249F9(aJimtextLbx_0, 50, (char *)dword_19A208, 40);
  v25 = dword_19A20C;
  LOBYTE(v26) = sub_249F9(aJimtextLbx_0, 51, (char *)dword_19A20C, 40);
  sub_FE8BE(v26, 51, v25, v58);
  sub_249F9(aJimtextLbx_0, 52, (char *)dword_19A210, 40);
  v27 = dword_19A214;
  sub_249F9(aJimtextLbx_0, 46, (char *)dword_19A214, 40);
  v28 = dword_19A218;
  LOBYTE(v27) = byte_178A64;
  *(_BYTE *)dword_19A218 = byte_178A64;
  sub_FE8BE(v28, 53, v27, v58);
  v29 = dword_19A228;
  LOBYTE(v30) = sub_249F9(aJimtextLbx_0, 53, (char *)dword_19A228, 30);
  sub_FE8BE(v30, 53, v29, v58);
  sub_249F9(aJimtextLbx_0, 54, (char *)dword_19A1BC, 40);
  v31 = dword_19A1C0;
  LOBYTE(v32) = sub_249F9(aJimtextLbx_0, 55, (char *)dword_19A1C0, 40);
  sub_FE8BE(v32, 55, v31, v58);
  v33 = dword_19A1C4;
  LOBYTE(v34) = sub_249F9(aJimtextLbx_0, 56, (char *)dword_19A1C4, 40);
  sub_FE8BE(v34, 56, v33, v58);
  sub_249F9(aJimtextLbx_0, 57, (char *)dword_19A1C8, 40);
  v35 = dword_19A1CC;
  LOBYTE(v36) = sub_249F9(aJimtextLbx_0, 58, (char *)dword_19A1CC, 40);
  sub_FE8BE(v36, 58, v35, v58);
  sub_249F9(aJimtextLbx_0, 59, (char *)dword_19A1D0, 40);
  v37 = dword_19A1D4;
  LOBYTE(v38) = sub_249F9(aJimtextLbx_0, 60, (char *)dword_19A1D4, 40);
  sub_FE8BE(v38, 60, v37, v58);
  sub_249F9(aJimtextLbx_0, 61, (char *)dword_19A1D8, 40);
  v39 = dword_19A1DC;
  LOBYTE(v40) = sub_249F9(aJimtextLbx_0, 62, (char *)dword_19A1DC, 40);
  sub_FE8BE(v40, 62, v39, v58);
  v41 = dword_19A1E0;
  sub_249F9(aJimtextLbx_0, 46, (char *)dword_19A1E0, 35);
  v42 = dword_19A1E4;
  LOBYTE(v41) = byte_178A64;
  *(_BYTE *)dword_19A1E4 = byte_178A64;
  sub_FE8BE(v42, 63, v41, v58);
  sub_249F9(aJimtextLbx_0, 63, (char *)dword_19A198, 30);
  v43 = dword_19A22C;
  LOBYTE(v44) = sub_249F9(aJimtextLbx_0, 64, (char *)dword_19A22C, 30);
  sub_FE8BE(v44, 64, v43, v58);
  sub_249F9(aJimtextLbx_0, 65, (char *)dword_19A230, 30);
  v45 = dword_19A234;
  LOBYTE(v46) = sub_249F9(aJimtextLbx_0, 66, (char *)dword_19A234, 30);
  sub_FE8BE(v46, 66, v45, v58);
  v47 = dword_19A238;
  LOBYTE(v48) = sub_249F9(aJimtextLbx_0, 67, (char *)dword_19A238, 30);
  sub_FE8BE(v48, 67, v47, v58);
  sub_249F9(aJimtextLbx_0, 68, (char *)dword_19A23C, 30);
  sub_249F9(aJimtextLbx_0, 46, (char *)dword_19A240, 30);
  *(_BYTE *)dword_19A244 = byte_178A64;
  sub_249F9(aJimtextLbx_0, 69, (char *)dword_19A21C, 20);
  v49 = dword_19A220;
  sub_249F9(aJimtextLbx_0, 70, (char *)dword_19A220, 20);
  v50 = dword_19A224;
  LOBYTE(v49) = byte_178A64;
  *(_BYTE *)dword_19A224 = byte_178A64;
  sub_FE8BE(v50, 2, v49, v58);
  v51 = dword_19A2BC;
  LOBYTE(v52) = sub_249F9(aJimtext2Lbx, 2, (char *)dword_19A2BC, 40);
  sub_FE8BE(v52, 2, v51, v58);
  sub_249F9(aJimtextLbx_0, 46, (char *)dword_19A2A4, 20);
  v53 = dword_19A2AC;
  LOBYTE(v54) = sub_249F9(aJimtext2Lbx, 56, (char *)dword_19A2AC, 30);
  sub_FE8BE(v54, 56, v53, v58);
  sub_249F9(aJimtext2Lbx, 57, (char *)dword_19A29C, 30);
  sub_249F9(aJimtext2Lbx, 58, (char *)dword_19A2C8, 35);
  sub_249F9(aJimtext2Lbx, 67, (char *)dword_19A2A0, 40);
  sub_249F9(aJimtext2Lbx, 68, (char *)dword_19A298, 40);
  sub_249F9(aJimtext2Lbx, 69, (char *)dword_19A2C0, 40);
  sub_249F9(aJimtext2Lbx, 70, (char *)dword_19A2A8, 40);
  sub_249F9(aJimtext2Lbx, 71, (char *)dword_19A2B0, 40);
  sub_249F9(aJimtext2Lbx, 72, (char *)dword_19A2CC, 40);
  sub_249F9(aJimtext2Lbx, 73, (char *)dword_19A2C4, 40);
  sub_249F9(aJimtext2Lbx, 74, (char *)dword_19A2B8, 40);
  sub_249F9(aJimtext2Lbx, 10, (char *)dword_19A2D8, 20);
  v55 = dword_19A4E8;
  LOBYTE(v56) = sub_249F9(aJimtext2Lbx, 11, (char *)dword_19A4E8, 20);
  sub_FE8BE(v56, 11, v55, v58);
  JUMPOUT(0x17205);
}
// 1FC0E: control flows out of bounds to 17205
// 1F3D1: variable 'v5' is possibly undefined
// 1F40A: variable 'v7' is possibly undefined
// 1F443: variable 'v9' is possibly undefined
// 1F6B8: variable 'v16' is possibly undefined
// 1F6F1: variable 'v18' is possibly undefined
// 1F756: variable 'v22' is possibly undefined
// 1F78F: variable 'v24' is possibly undefined
// 1F7C8: variable 'v26' is possibly undefined
// 1F82D: variable 'v30' is possibly undefined
// 1F866: variable 'v32' is possibly undefined
// 1F885: variable 'v34' is possibly undefined
// 1F8BE: variable 'v36' is possibly undefined
// 1F8F7: variable 'v38' is possibly undefined
// 1F930: variable 'v40' is possibly undefined
// 1F995: variable 'v44' is possibly undefined
// 1F9CE: variable 'v46' is possibly undefined
// 1F9ED: variable 'v48' is possibly undefined
// 1FA93: variable 'v52' is possibly undefined
// 1FACC: variable 'v54' is possibly undefined
// 1FC09: variable 'v56' is possibly undefined
// 178A64: using guessed type char byte_178A64;
// 19A0E8: using guessed type int dword_19A0E8;
// 19A0EC: using guessed type int dword_19A0EC;
// 19A0F0: using guessed type int dword_19A0F0;
// 19A0F4: using guessed type int dword_19A0F4;
// 19A0F8: using guessed type int dword_19A0F8;
// 19A0FC: using guessed type int dword_19A0FC;
// 19A198: using guessed type int dword_19A198;
// 19A19C: using guessed type int dword_19A19C;
// 19A1A0: using guessed type int dword_19A1A0;
// 19A1A4: using guessed type int dword_19A1A4;
// 19A1A8: using guessed type int dword_19A1A8;
// 19A1AC: using guessed type int dword_19A1AC;
// 19A1B0: using guessed type int dword_19A1B0;
// 19A1B4: using guessed type int dword_19A1B4;
// 19A1B8: using guessed type int dword_19A1B8;
// 19A1BC: using guessed type int dword_19A1BC;
// 19A1C0: using guessed type int dword_19A1C0;
// 19A1C4: using guessed type int dword_19A1C4;
// 19A1C8: using guessed type int dword_19A1C8;
// 19A1CC: using guessed type int dword_19A1CC;
// 19A1D0: using guessed type int dword_19A1D0;
// 19A1D4: using guessed type int dword_19A1D4;
// 19A1D8: using guessed type int dword_19A1D8;
// 19A1DC: using guessed type int dword_19A1DC;
// 19A1E0: using guessed type int dword_19A1E0;
// 19A1E4: using guessed type int dword_19A1E4;
// 19A1E8: using guessed type int dword_19A1E8;
// 19A1EC: using guessed type int dword_19A1EC;
// 19A1F0: using guessed type int dword_19A1F0;
// 19A1F4: using guessed type int dword_19A1F4;
// 19A1F8: using guessed type int dword_19A1F8;
// 19A1FC: using guessed type int dword_19A1FC;
// 19A200: using guessed type int dword_19A200;
// 19A204: using guessed type int dword_19A204;
// 19A208: using guessed type int dword_19A208;
// 19A20C: using guessed type int dword_19A20C;
// 19A210: using guessed type int dword_19A210;
// 19A214: using guessed type int dword_19A214;
// 19A218: using guessed type int dword_19A218;
// 19A21C: using guessed type int dword_19A21C;
// 19A220: using guessed type int dword_19A220;
// 19A224: using guessed type int dword_19A224;
// 19A228: using guessed type int dword_19A228;
// 19A22C: using guessed type int dword_19A22C;
// 19A230: using guessed type int dword_19A230;
// 19A234: using guessed type int dword_19A234;
// 19A238: using guessed type int dword_19A238;
// 19A23C: using guessed type int dword_19A23C;
// 19A240: using guessed type int dword_19A240;
// 19A244: using guessed type int dword_19A244;
// 19A248: using guessed type int dword_19A248;
// 19A24C: using guessed type int dword_19A24C;
// 19A250: using guessed type int dword_19A250;
// 19A254: using guessed type int dword_19A254;
// 19A258: using guessed type int dword_19A258;
// 19A25C: using guessed type int dword_19A25C;
// 19A260: using guessed type int dword_19A260;
// 19A264: using guessed type int dword_19A264;
// 19A268: using guessed type int dword_19A268;
// 19A26C: using guessed type int dword_19A26C;
// 19A270: using guessed type int dword_19A270;
// 19A274: using guessed type int dword_19A274;
// 19A278: using guessed type int dword_19A278;
// 19A27C: using guessed type int dword_19A27C;
// 19A280: using guessed type int dword_19A280;
// 19A284: using guessed type int dword_19A284;
// 19A288: using guessed type int dword_19A288;
// 19A28C: using guessed type int dword_19A28C;
// 19A290: using guessed type int dword_19A290;
// 19A294: using guessed type int dword_19A294;
// 19A298: using guessed type int dword_19A298;
// 19A29C: using guessed type int dword_19A29C;
// 19A2A0: using guessed type int dword_19A2A0;
// 19A2A4: using guessed type int dword_19A2A4;
// 19A2A8: using guessed type int dword_19A2A8;
// 19A2AC: using guessed type int dword_19A2AC;
// 19A2B0: using guessed type int dword_19A2B0;
// 19A2B8: using guessed type int dword_19A2B8;
// 19A2BC: using guessed type int dword_19A2BC;
// 19A2C0: using guessed type int dword_19A2C0;
// 19A2C4: using guessed type int dword_19A2C4;
// 19A2C8: using guessed type int dword_19A2C8;
// 19A2CC: using guessed type int dword_19A2CC;
// 19A2D4: using guessed type int dword_19A2D4;
// 19A2D8: using guessed type int dword_19A2D8;
// 19A4E8: using guessed type int dword_19A4E8;


//----- (0001FC13) --------------------------------------------------------
void __fastcall sub_1FC13( int a1, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int16_t v6; // si
  int16_t v7; // bx
  int v8; // ecx
  int v9; // edi
  int v10; // edx
  int v11; // eax
  int v13; // [esp+4h] [ebp-4h]

  sub_1196F7();
  if ( (uint8_t)byte_199F3A < 2u || *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) != 100 )
  {
    LOWORD(v3) = sub_122259();
    v4 = v3;
    LOWORD(v5) = sub_122286();
    v6 = 0;
    v7 = a1 - 1;
    v13 = v4 + v5;
    v8 = v4 + v5 + 118;
    while ( v6 < v7 )
    {
      v9 = v6;
      v10 = 5 * v6;
      word_19A5B6[v10] = 10;
      word_19A5BA[v10] = 255;
      word_19A5B8[v10] = v8;
      word_19A5BC[v10] = v8 + sub_122259();
      ++v6;
      v8 += v13;
      word_19A5B4[v10] = *(_WORD *)(a2 + 2 * v9);
    }
    v11 = 5 * v7;
    word_19A5B6[v11] = 0;
    word_19A5B8[v11] = 0;
    word_19A5BA[v11] = 639;
    word_19A5BC[v11] = 479;
    word_19A5B4[v11] = 694;
    sub_1196B8((int)word_19A5B4, v7 + 1);
  }
  JUMPOUT(0x17F39);
}
// 1FD01: control flows out of bounds to 17F39
// 1FC62: variable 'v3' is possibly undefined
// 1FC78: variable 'v5' is possibly undefined
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A5B4: using guessed type int16_t word_19A5B4[];
// 19A5B6: using guessed type int16_t word_19A5B6[];
// 19A5B8: using guessed type int16_t word_19A5B8[];
// 19A5BA: using guessed type int16_t word_19A5BA[];
// 19A5BC: using guessed type int16_t word_19A5BC[];
// 19AA66: using guessed type char byte_19AA66;


//----- (0001FD06) --------------------------------------------------------
int __fastcall sub_1FD06( int a1)
{
  int result; // eax

  sub_1196F7();
  if ( (uint8_t)byte_199F3A < 2u
    || (result = *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) == 100,
        *(_BYTE *)(dword_197F98 + 3753 * (uint8_t)byte_19AA66 + 40) != 100) )
  {
    word_19A5B6[0] = 0;
    word_19A5B8[0] = 0;
    word_19A5BA[0] = 639;
    word_19A5B4[0] = a1;
    word_19A5BC[0] = 479;
    return sub_1196B8((int)&word_19A5B4, 1);
  }
  return result;
}
// 197F98: using guessed type int dword_197F98;
// 199F3A: using guessed type char byte_199F3A;
// 19A5B4: using guessed type int16_t word_19A5B4;
// 19A5B6: using guessed type int16_t word_19A5B6;
// 19A5B8: using guessed type int16_t word_19A5B8;
// 19A5BA: using guessed type int16_t word_19A5BA;
// 19A5BC: using guessed type int16_t word_19A5BC;
// 19AA66: using guessed type char byte_19AA66;


//----- (0001FD80) --------------------------------------------------------
void sub_1FD80()
{
  int16_t i; // si
  int16_t j; // di
  int v2; // eax
  int v3; // eax
  int v4; // edx
  int v5; // ebx
  int v6; // ebx
  int v7; // [esp+0h] [ebp-18h] BYREF
  int v8; // [esp+4h] [ebp-14h]
  int v9; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF

  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_199998; ++j )
    {
      v8 = i;
      v10 = 3753 * i;
      if ( *(_BYTE *)(v10 + dword_197F98 + 36)
        || *(_BYTE *)(v10 + dword_197F98 + 40) == 100
        || sub_233FA()
        || (v9 = j, v2 = dword_197F98 + 3753 * j, *(_BYTE *)(v2 + 40) != 100)
        || i == j
        || *(_BYTE *)(v2 + 36)
        || (v3 = v9 + dword_197F98 + v10, *(_BYTE *)(v3 + 1412) != 1)
        || *(_BYTE *)(v3 + 1429) != 1 )
      {
        v6 = 3753 * i + dword_197F98;
        *(_WORD *)(v6 + 2 * j + 2103) = -1;
        *(_WORD *)(v6 + 2 * j + 2119) = 0;
        *(_DWORD *)(v6 + 4 * j + 2135) = 0;
      }
      else
      {
        v12 = -1;
        v11 = 0;
        v7 = 0;
        sub_DBC5C(v8, v9, 100, (int16_t *)&v12, &v11, &v7);
        v4 = v9;
        v5 = v10 + dword_197F98;
        *(_WORD *)(v5 + 2 * v9 + 2103) = v12;
        *(_WORD *)(v5 + 2 * v4 + 2119) = v11;
        *(_DWORD *)(v5 + 4 * v4 + 2135) = v7;
      }
    }
  }
  JUMPOUT(0x17204);
}
// 1FED8: control flows out of bounds to 17204
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (0001FEF5) --------------------------------------------------------
void sub_1FEF5()
{
  int16_t i; // bx
  int16_t v1; // si
  int v2; // edx
  int v3; // eax

  for ( i = 0; i < word_199998; ++i )
  {
    v1 = i;
    while ( ++v1 < word_199998 )
    {
      if ( i != v1 && !*(_BYTE *)(dword_197F98 + 3753 * v1 + 36) && !*(_BYTE *)(dword_197F98 + 3753 * i + 36) )
      {
        v2 = 3753 * word_19999C + dword_197F98;
        if ( *(_BYTE *)(v2 + v1 + 1412) == 1 || *(_BYTE *)(v2 + i + 1412) == 1 )
        {
          v3 = v1 + 3753 * i + dword_197F98;
          if ( *(_BYTE *)(v3 + 1871) != *(_BYTE *)(v3 + 1575) )
          {
            switch ( *(_BYTE *)(v3 + 1575) )
            {
              case 1:
                sub_EF817();
                break;
              case 2:
                sub_EF80F();
                break;
              case 3:
                sub_EF807();
                break;
              case 4:
              case 5:
              case 6:
                sub_EF7FD(i, v1);
                break;
              default:
                continue;
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x17204);
}
// 1FFE8: control flows out of bounds to 17204
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;


//----- (0001FFED) --------------------------------------------------------
void sub_1FFED()
{
  int16_t i; // cx
  int16_t j; // bx
  int v2; // edi
  uint8_t v3; // al

  for ( i = 0; i < word_199998; ++i )
  {
    for ( j = 0; j < word_199998; ++j )
    {
      if ( i != j && !*(_BYTE *)(dword_197F98 + 3753 * j + 36) )
      {
        v2 = 3753 * i + dword_197F98;
        if ( !*(_BYTE *)(v2 + 36) )
        {
          v3 = *(_BYTE *)(j + v2 + 2199);
          if ( v3 )
          {
            if ( v3 <= 1u )
            {
              sub_524FB(i, j);
            }
            else if ( v3 == 2 )
            {
              sub_5138E(i, j);
            }
            else
            {
              *(_BYTE *)(dword_197F98 + 3753 * i + j + 2199) = -1;
            }
          }
          else
          {
            sub_51078(i, j);
          }
          *(_BYTE *)(3753 * i + dword_197F98 + j + 2199) = -1;
        }
      }
    }
  }
  JUMPOUT(0x17205);
}
// 200BE: control flows out of bounds to 17205
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (000200C3) --------------------------------------------------------
char __fastcall sub_200C3(int16_t *a1, int a2, int a3, int a4)
{
  char result; // al
  int v7; // edx
  int v8; // eax

  do
  {
    sub_12C2A0();
    result = sub_1EF5B((int16_t)a1, a2, a3, a4);
    if ( byte_19AA69 == 1 )
    {
      sub_1192D1();
      sub_120CCB(4, (int)&unk_180DCC);
      sub_1212B3(10, 117, dword_19A2B0);
      a4 = (int16_t)(word_19AA5C + word_19AA58 - 1);
      v7 = word_19AA58;
      a3 = (int16_t)(word_19AA56 + word_19AA5A);
      LOBYTE(v8) = sub_1298DE(word_19AA5A, word_19AA58, a3, a4);
      sub_1077D(v8, v7, a3, a1);
      result = sub_12C2C6(2);
    }
  }
  while ( byte_19AA69 == 1 );
  return result;
}
// 20141: variable 'v8' is possibly undefined
// 19A2B0: using guessed type int dword_19A2B0;
// 19AA56: using guessed type int16_t word_19AA56;
// 19AA58: using guessed type int16_t word_19AA58;
// 19AA5A: using guessed type int16_t word_19AA5A;
// 19AA5C: using guessed type int16_t word_19AA5C;
// 19AA69: using guessed type char byte_19AA69;


//----- (00020162) --------------------------------------------------------
_BOOL1 __fastcall sub_20162( int a1)
{
  return a1 >= 83 && a1 <= 85
      || a1 >= 97 && a1 <= 104
      || a1 == 125
      || a1 == 86
      || a1 == 105
      || a1 == 106
      || a1 >= 28 && a1 <= 36;
}


//----- (000201A4) --------------------------------------------------------
int sub_201A4()
{
  int v0; // edx
  int result; // eax

  word_19ACEC = 0;
  v0 = 0;
  dword_19ACE8 = dword_192FD8;
  do
  {
    result = 9 * (int16_t)v0;
    byte_19ABA4[result] = -1;
    byte_19ABA5[result] = 0;
    byte_19ABA6[result] = 0;
    *(int16_t *)((char *)&word_19ABA7 + result) = -1;
    *(int16_t *)((char *)&word_19ABA9 + result) = -1;
    ++v0;
    *(int16_t *)((char *)&word_19ABAB + result) = -1;
  }
  while ( (int16_t)v0 < 36 );
  return result;
}
// 192FD8: using guessed type int dword_192FD8;
// 19ABA7: using guessed type int16_t word_19ABA7;
// 19ABA9: using guessed type int16_t word_19ABA9;
// 19ABAB: using guessed type int16_t word_19ABAB;
// 19ACE8: using guessed type int dword_19ACE8;
// 19ACEC: using guessed type int16_t word_19ACEC;


//----- (000201F9) --------------------------------------------------------
int sub_201F9()
{
  int result; // eax
  _BOOL2 v1; // dx

  result = dword_192FD8 / 20;
  if ( !(dword_192FD8 % 20) )
  {
    v1 = 0;
    for ( result = 0; (int16_t)result < 36 && !v1; ++result )
      v1 = byte_19ABA5[9 * (int16_t)result] == 0;
    if ( !v1 )
      return sub_201A4();
  }
  return result;
}
// 192FD8: using guessed type int dword_192FD8;


//----- (0002023F) --------------------------------------------------------
int sub_2023F()
{
  int v0; // edx
  int16_t i; // bx

  v0 = 0;
  for ( i = 0; i < 36 && !(_WORD)v0; ++i )
  {
    if ( byte_19ABA5[9 * i] == 4 || byte_19ABA5[9 * i] == 6 || byte_19ABA5[9 * i] == 5 )
      v0 = 1;
  }
  return v0;
}


//----- (0002027E) --------------------------------------------------------
int __usercall sub_2027E(int a1)
{
  int v1; // edx

  byte_19ACF0 = 0;
  v1 = 0;
  do
  {
    if ( byte_19ABA5[9 * (int16_t)v1] == 4 || byte_19ABA5[9 * (int16_t)v1] == 6 || byte_19ABA5[9 * (int16_t)v1] == 5 )
      sub_21371((int16_t)v1, a1);
    ++v1;
  }
  while ( (int16_t)v1 < 36 );
  if ( byte_19ACF0 )
  {
    sub_119281();
    sub_11C2F0();
    sub_12D78E();
    if ( byte_199BE5 == 1 )
    {
      sub_C5B94(0);
      sub_C5B85(10);
      sub_C5BB9();
    }
    sub_2484F();
    byte_199F2D = 1;
    sub_FE8C8(dword_192ED4, v1);
    sub_107BA(&dword_19ABA0);
  }
  byte_199F2D = 1;
  return sub_201F9();
}
// 192ED4: using guessed type int dword_192ED4;
// 199BE5: using guessed type char byte_199BE5;
// 199F2D: using guessed type char byte_199F2D;
// 19ABA0: using guessed type int dword_19ABA0;
// 19ACF0: using guessed type char byte_19ACF0;


//----- (0002031D) --------------------------------------------------------
int sub_2031D()
{
  sub_1196F7();
  sub_1172FC();
  sub_128BE7();
  sub_12B65C();
  sub_119281();
  sub_11C2F0();
  sub_123E6C((int)&unk_180EA8, 1);
  sub_24677(118, -1, 1);
  sub_C5B94(0);
  sub_C5B85(10);
  sub_C5BB9();
  sub_117174(1);
  sub_11C2F0();
  sub_124C08();
  sub_107AF(&dword_19ABA0);
  sub_119281();
  sub_20538();
  sub_1191CA((int)sub_20460, 2);
  sub_120DED(0, 248);
  return sub_120D79(4, (int)&unk_180E7C);
}
// 19ABA0: using guessed type int dword_19ABA0;


//----- (000203CB) --------------------------------------------------------
_DWORD *__fastcall sub_203CB( int a1)
{
  sub_11127C(dword_192ED4);
  dword_19AA70 = (int)sub_126B42((int)aEventsLbx, (int16_t)(a1 + 2), dword_192ED4);
  return sub_1112B4(dword_192ED4);
}
// 192ED4: using guessed type int dword_192ED4;
// 19AA70: using guessed type int dword_19AA70;


//----- (00020400) --------------------------------------------------------
void __usercall sub_20400(int16_t *a1)
{
  _BOOL2 v1; // si
  unsigned int v2; // edx
  int16_t v3; // ax
  int v4; // eax

  v1 = 0;
  while ( !v1 )
  {
    sub_12C2A0();
    sub_11C2F0();
    v2 = sub_11438B(0, 0, 639, 479, &unk_178B33, 0);
    v3 = sub_1171AB(v2, v2, 639, 479);
    v1 = v3 == (int16_t)v2;
    if ( v3 != (_WORD)v2 )
    {
      v4 = sub_20460();
      sub_1077D(v4, v2, 639, a1);
      sub_12C2C6(2);
    }
  }
}


//----- (00020460) --------------------------------------------------------
int sub_20460()
{
  int16_t v0; // ax
  int16_t v1; // dx

  sub_124D41();
  if ( byte_199BE2 == 1 )
  {
    sub_12CD2D();
    if ( !sub_12D70B() )
      sub_12D6B2(1);
  }
  if ( byte_19ACEF == 1 )
  {
    if ( dword_19AA70 )
      sub_12A478(320, 14, dword_19AA70);
    v0 = sub_103CAF(550, (int)&unk_19AA74);
    v1 = v0;
    if ( v0 <= 60 )
    {
      if ( v0 > 18 )
        v1 = v0 - 4;
    }
    else
    {
      v1 = v0 + 14;
    }
    sub_103BC4(0x37u, 445 - v1 / 2, 550, (int)&unk_19AA74, 2);
  }
  else
  {
    byte_19ACEF = 1;
    if ( dword_19AA70 )
      sub_12B79D(dword_19AA70);
  }
  return sub_24677(118, -1, 1);
}
// 199BE2: using guessed type char byte_199BE2;
// 19AA70: using guessed type int dword_19AA70;
// 19ACEF: using guessed type char byte_19ACEF;


//----- (00020538) --------------------------------------------------------
int16_t sub_20538()
{
  _DWORD *v0; // ecx
  _DWORD *v1; // eax

  dword_19AA6C = (int)sub_110CEE(dword_192ED4, 917);
  v0 = sub_126B42((int)aEventsLbx, 0, dword_192ED4);
  sub_12E332(0);
  sub_12D8F5(30, 30, dword_19AA6C);
  sub_12F578(dword_19AA6C, (int)v0);
  byte_19ACEF = 1;
  v1 = sub_110D3C(dword_192ED4, 320000);
  sub_12D7B7((int)v1);
  sub_124D41();
  sub_12B79D((int)v0);
  sub_1318D4(0, 255);
  sub_128C32(0, 0, 639, 479, 0);
  sub_12C607((int)aEventsLbx, 1, 639, 479);
  sub_124D41();
  sub_12C7CC();
  sub_124DEC();
  sub_12E1E0(0, 0, (int16_t *)dword_19AA6C, 0);
  return sub_123E6C((int)&unk_17CF00, 1);
}
// 192ED4: using guessed type int dword_192ED4;
// 19AA6C: using guessed type int dword_19AA6C;
// 19ACEF: using guessed type char byte_19ACEF;


//----- (000206A2) --------------------------------------------------------
void __usercall sub_206A2(int a1)
{
  int16_t i; // si
  int v2; // eax
  int16_t v3; // dx
  int16_t v4; // ax
  int v5; // eax
  _BOOL1 v6; // zf
  int16_t v7; // bx
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  char v14; // dl
  int v15; // eax
  char v16; // cl
  int v17; // ebx
  char v18; // al
  signed int v19; // edx
  int16_t j; // dx
  int v21; // eax
  int16_t v22; // ax
  int v23; // eax
  int16_t v24; // dx
  int v25; // edx
  int v26; // eax
  int16_t v27; // dx
  int16_t v28; // ax
  int16_t k; // cx
  int v30; // eax
  int16_t v31; // ax
  int16_t v32; // bx
  int v33; // eax
  int16_t m; // bx
  int v35; // eax
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int16_t n; // dx
  int v40; // eax
  int v41; // eax
  int v42; // edx
  char v43; // al

  if ( byte_19AC50 == 4 )
    byte_19AC50 = 3;
  for ( i = 0; i < 36; ++i )
  {
    if ( byte_19ABA5[9 * i] == 5 )
      byte_19ABA5[9 * i] = 3;
    if ( byte_19ABA5[9 * i] == 4 || byte_19ABA5[9 * i] == 6 )
      byte_19ABA5[9 * i] = 2;
    if ( byte_19ABA5[9 * i] == 1 || byte_19ABA5[9 * i] == 2 )
    {
      if ( byte_19ABA5[9 * i] == 1 )
        byte_19ABA5[9 * i] = 6;
      switch ( i )
      {
        case 0:
          sub_E4204(dword_197F98 + 3753 * byte_19ABA4[9 * i], *(int16_t *)((char *)&word_19ABA7 + 9 * i), a1);
          if ( *(int16_t *)((char *)&word_19ABA9 + 9 * i) )
            sub_E4204(3753 * byte_19ABA4[9 * i] + dword_197F98, *(int16_t *)((char *)&word_19ABA9 + 9 * i), a1);
          goto LABEL_54;
        case 1:
          v2 = dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i);
          v3 = *(uint8_t *)(v2 + 8);
          *(_BYTE *)(v2 + 8) = 8;
          *(_BYTE *)(v2 + 11) += byte_17D81C[*(uint8_t *)(v2 + 8)] - byte_17D81C[v3];
          if ( *(int16_t *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i)) != -1 )
          {
            sub_E2A70(*(_WORD *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i)), a1);
            sub_B206F(*(_WORD *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i)), 44);
          }
          goto LABEL_54;
        case 2:
          if ( byte_19ABA5[9 * i] == 6 )
            continue;
          sub_23B28(*(uint8_t *)(dword_1930D4
                                       + 17
                                       * *(int16_t *)(361 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + dword_192B18 + 2)
                                       + 2));
          *(int16_t *)((char *)&word_19ABA9 + 9 * i) -= v4;
          if ( *(int16_t *)((char *)&word_19ABA9 + 9 * i) <= 0 )
            goto LABEL_22;
          if ( --byte_19ABA6[9 * i] <= 0 )
          {
            sub_23780(*(int16_t *)((char *)&word_19ABA7 + 9 * i));
LABEL_22:
            byte_19ABA5[9 * i] = 5;
          }
          if ( sub_1247A0(0x14u) != 1 )
            continue;
          v5 = 9 * i;
          v6 = *(int16_t *)((char *)&word_19ABAB + v5) == *(int16_t *)((char *)&word_19ABA9 + v5);
          goto LABEL_25;
        case 3:
          v7 = sub_1247A0(0x32u) + 50;
          if ( v7 > *(_DWORD *)(3753 * byte_19ABA4[9 * i] + dword_197F98 + 491) )
            v7 = *(_WORD *)(dword_197F98 + 3753 * byte_19ABA4[9 * i] + 491);
          v8 = 9 * i;
          v9 = 3753 * byte_19ABA4[v8];
          v10 = dword_197F98;
          *(int16_t *)((char *)&word_19ABA7 + v8) = v7;
          *(int16_t *)((char *)&word_19ABA9 + v8) = *(uint8_t *)(v10 + v9 + 801);
          *(_DWORD *)(v10 + 3753 * byte_19ABA4[v8] + 491) -= v7;
          goto LABEL_93;
        case 4:
          sub_4E3B5(-100, byte_19ABA4[9 * i], *(int16_t *)((char *)&word_19ABA7 + 9 * i), 0, 0, 0);
          goto LABEL_54;
        case 5:
          sub_4E3B5(100, byte_19ABA4[9 * i], *(int16_t *)((char *)&word_19ABA7 + 9 * i), 0, 0, 0);
          goto LABEL_54;
        case 6:
          v11 = dword_197F98 + 3753 * byte_19ABA4[9 * i];
          *(_DWORD *)(v11 + 50) += *(int16_t *)((char *)&word_19ABA7 + 9 * i);
          goto LABEL_54;
        case 7:
          byte_19ABA5[9 * i] = 5;
          sub_238A8(*(int16_t *)((char *)&word_19ABA7 + 9 * i), &byte_19ABA4[9 * i + 5], &byte_19ABA4[9 * i + 7]);
          if ( *(int16_t *)((char *)&word_19ABA9 + 9 * i) < 1 && *(int16_t *)((char *)&word_19ABAB + 9 * i) < 1 )
          {
            byte_19ABA5[9 * i] = 0;
            byte_19ABA4[9 * i] = -1;
          }
          sub_E2A70(*(int16_t *)((char *)&word_19ABA7 + 9 * i), a1);
          continue;
        case 8:
          if ( *(int16_t *)(129 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + dword_197F9C + 116) != -1 )
          {
            *(int16_t *)((char *)&word_19ABA9 + 9 * i) = *(_WORD *)(129 * *(int16_t *)((char *)&word_19ABA7 + 9 * i)
                                                                  + dword_197F9C
                                                                  + 116);
            sub_941C6(*(_WORD *)(dword_197F9C + 129 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + 116), a1);
          }
          v12 = 9 * i;
          sub_A163A(*(int16_t *)((char *)&word_19ABA7 + v12), a1);
          goto LABEL_41;
        case 9:
          if ( byte_19ABA5[9 * i] == 2 )
            goto LABEL_43;
          continue;
        case 10:
          if ( *(int16_t *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i)) == -1 )
            goto LABEL_54;
          sub_23833(*(_WORD *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i)));
          LOWORD(v13) = *(_WORD *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i));
          goto LABEL_53;
        case 11:
          if ( *(uint8_t *)(17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + dword_1930D4 + 10) - 1 <= 0 )
            v14 = 0;
          else
            v14 = *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + 10) - 1;
          v15 = 9 * i;
          v16 = v14;
          goto LABEL_52;
        case 12:
          if ( *(uint8_t *)(17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + dword_1930D4 + 10) + 2 <= 4 )
            v18 = *(_BYTE *)(17 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + dword_1930D4 + 10) + 2;
          else
            v18 = 4;
          v16 = v18;
          v15 = 9 * i;
LABEL_52:
          v17 = dword_1930D4;
          *(_BYTE *)(17 * *(int16_t *)((char *)&word_19ABA7 + v15) + dword_1930D4 + 10) = v16;
          v13 = *(int16_t *)(v17 + 17 * *(int16_t *)((char *)&word_19ABA7 + v15));
          if ( v13 != -1 )
LABEL_53:
            sub_E2A70(v13, a1);
          goto LABEL_54;
        case 14:
          if ( byte_19ABA5[9 * i] != 6 )
          {
            v19 = (int16_t)(100 * *(int16_t *)((char *)&word_19ABA9 + 9 * i) / *(int16_t *)((char *)&word_19ABAB + 9 * i));
            if ( (int)sub_1247A0(0x64u) <= v19 )
            {
              for ( j = 0; j < word_199998; ++j )
              {
                if ( (((int)*(uint8_t *)(113 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + dword_19306C + 56) >> j)
                    & 1) != 0 )
                {
                  v21 = dword_197F98 + 3753 * j;
                  if ( *(int16_t *)(v21 + 54) > 0 )
                    --*(_WORD *)(v21 + 54);
                }
              }
            }
            v12 = 9 * i;
            sub_23B28(*(int16_t *)((char *)&word_19ABA7 + v12));
            *(int16_t *)((char *)&word_19ABA9 + v12) -= v22;
            if ( *(int16_t *)((char *)&word_19ABA9 + v12) <= 0 )
LABEL_41:
              byte_19ABA5[v12] = 5;
          }
          continue;
        case 15:
          v23 = dword_197F98 + 3753 * byte_19ABA4[9 * i];
          *(_DWORD *)(v23 + 50) -= *(int16_t *)((char *)&word_19ABA9 + 9 * i);
          if ( *(int *)(dword_197F98 + 3753 * byte_19ABA4[9 * i] + 50) < 0 )
            *(_DWORD *)(3753 * byte_19ABA4[9 * i] + dword_197F98 + 50) = 0;
          goto LABEL_54;
        case 16:
          if ( byte_19ABA5[9 * i] == 6 )
            continue;
          *(int16_t *)((char *)&word_19ABA9 + 9 * i) -= sub_23B64(*(int16_t *)((char *)&word_19ABA7 + 9 * i));
          sub_E2A70(*(int16_t *)((char *)&word_19ABA7 + 9 * i), a1);
          if ( *(int16_t *)((char *)&word_19ABA9 + 9 * i) <= 0 )
            byte_19ABA5[9 * i] = 5;
          if ( byte_19ABA6[9 * i] > 4 && sub_1247A0(0x14u) == 1 )
            byte_19ABA5[9 * i] = 4;
          goto LABEL_126;
        case 17:
          if ( byte_19ABA5[9 * i] != 2 )
            continue;
          sub_E2A70(*(int16_t *)((char *)&word_19ABA7 + 9 * i), a1);
LABEL_43:
          if ( byte_19ABA6[9 * i] > 4 && sub_1247A0(0x14u) == 1 )
            byte_19ABA5[9 * i] = 5;
          goto LABEL_124;
        case 18:
          v24 = *(uint8_t *)(dword_197F98 + 3753 * byte_19ABA4[9 * i] + 801);
          *(int16_t *)((char *)&word_19ABA7 + 9 * i) = v24;
          sub_E4410(dword_197F98 + 3753 * byte_19ABA4[9 * i], v24, 1, a1);
          v25 = dword_197F98;
          *(_DWORD *)(dword_197F98 + 3753 * byte_19ABA4[9 * i] + 491) = 0;
          *(_BYTE *)(v25 + 3753 * byte_19ABA4[9 * i] + 801) = 0;
          goto LABEL_54;
        case 19:
          if ( byte_19ABA5[9 * i] != 6 )
            goto LABEL_81;
          v27 = *(int16_t *)((char *)&word_19ABA7 + 9 * i);
          v28 = 10;
          goto LABEL_84;
        case 20:
          if ( byte_19ABA5[9 * i] != 6 )
            goto LABEL_81;
          v27 = *(int16_t *)((char *)&word_19ABA7 + 9 * i);
          v28 = 11;
          goto LABEL_84;
        case 21:
          if ( byte_19ABA5[9 * i] == 6 )
          {
            v27 = *(int16_t *)((char *)&word_19ABA7 + 9 * i);
            v28 = 12;
            goto LABEL_84;
          }
LABEL_81:
          if ( byte_19ABA6[9 * i] <= 4 )
            goto LABEL_92;
          v26 = 9 * i;
          goto LABEL_91;
        case 22:
          v26 = 9 * i;
          if ( byte_19ABA5[v26] != 6 )
            goto LABEL_90;
          v27 = *(int16_t *)((char *)&word_19ABA7 + 9 * i);
          v28 = 13;
          goto LABEL_84;
        case 23:
          v26 = 9 * i;
          if ( byte_19ABA5[v26] == 6 )
          {
            v27 = *(int16_t *)((char *)&word_19ABA7 + 9 * i);
            v28 = 14;
LABEL_84:
            sub_A16BF(v28, v27, 1u);
          }
          else
          {
LABEL_90:
            if ( byte_19ABA6[v26] > 4 )
LABEL_91:
              byte_19ABA5[v26] = 5;
LABEL_92:
            v8 = 9 * i;
            if ( *(int16_t *)((char *)&word_19ABA9 + v8) != -1 )
LABEL_93:
              byte_19ABA5[v8] = 5;
          }
          break;
        case 24:
          if ( byte_19ABA5[9 * i] == 6 )
            continue;
          for ( k = 0; k < 5; ++k )
          {
            v30 = *(int16_t *)(dword_19306C + 113 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + 2 * k + 74);
            if ( v30 != -1 )
            {
              v31 = *(_WORD *)(dword_1930D4 + 17 * v30);
              v32 = v31;
              if ( v31 != -1 )
              {
                *(int16_t *)((char *)&word_19ABA9 + 9 * i) -= sub_23B64(v31);
                sub_E2A70(v32, a1);
              }
            }
          }
          v33 = 9 * i;
          if ( *(int16_t *)((char *)&word_19ABA9 + v33) <= 0 )
            goto LABEL_111;
          if ( --byte_19ABA6[9 * i] <= 0 )
          {
            for ( m = 0; m < 5; ++m )
            {
              v35 = *(int16_t *)(113 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + dword_19306C + 2 * m + 74);
              if ( v35 != -1 )
              {
                v36 = 17 * v35;
                v37 = dword_1930D4;
                *(_BYTE *)(dword_1930D4 + v36 + 8) = 1;
                v38 = *(int16_t *)(v37 + v36);
                if ( v38 != -1 )
                  sub_DCDAC((char *)(dword_192B18 + 361 * v38), -1);
              }
            }
            v33 = 9 * i;
LABEL_111:
            byte_19ABA5[v33] = 5;
          }
          if ( sub_1247A0(0x14u) == 1 )
          {
            v5 = 9 * i;
            v6 = byte_19ABA5[v5] == 5;
LABEL_25:
            if ( !v6 )
              byte_19ABA5[v5] = 4;
          }
          continue;
        case 25:
          if ( byte_19ABA5[9 * i] != 2 )
            continue;
          for ( n = 0; n < 5; ++n )
          {
            v40 = *(int16_t *)(dword_19306C + 113 * *(int16_t *)((char *)&word_19ABA7 + 9 * i) + 2 * n + 74);
            if ( v40 != -1 )
            {
              v41 = *(int16_t *)(dword_1930D4 + 17 * v40);
              if ( v41 != -1 )
                sub_E2A70(v41, a1);
            }
          }
          v42 = 9 * i;
LABEL_121:
          if ( byte_19ABA6[v42] > 4 && sub_1247A0(0x14u) == 1 )
            byte_19ABA5[v42] = 5;
LABEL_124:
          if ( byte_19ABA6[9 * i] > 20 )
            byte_19ABA5[9 * i] = 5;
          goto LABEL_126;
        case 26:
          if ( byte_19ABA5[9 * i] != 2 )
            continue;
          if ( byte_19ABA6[9 * i] > 4 && sub_1247A0(0x14u) == 1 )
            byte_19ABA5[9 * i] = 5;
          if ( byte_19ABA6[9 * i] > 20 )
            byte_19ABA5[9 * i] = 5;
          if ( byte_19ABA5[9 * i] != 5 )
          {
            sub_100618(byte_19ABA4[9 * i], a1);
            sub_22D57(byte_180E84[i]);
            byte_19ABA4[9 * i] = v43;
          }
LABEL_126:
          ++byte_19ABA6[9 * i];
          continue;
        case 27:
          v42 = 9 * i;
          if ( byte_19ABA5[v42] != 2 )
            continue;
          goto LABEL_121;
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
LABEL_54:
          v8 = 9 * i;
          goto LABEL_93;
        default:
          continue;
      }
    }
  }
}
// 20893: variable 'v4' is possibly undefined
// 20D7F: variable 'v22' is possibly undefined
// 212B3: variable 'v43' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 197F9C: using guessed type int dword_197F9C;
// 199998: using guessed type int16_t word_199998;
// 19ABA7: using guessed type int16_t word_19ABA7;
// 19ABA9: using guessed type int16_t word_19ABA9;
// 19ABAB: using guessed type int16_t word_19ABAB;
// 19AC50: using guessed type char byte_19AC50;


//----- (00021371) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall sub_21371(int a1, int a2)
{
  uint16_t v2; // bx
  int v3; // edx
  int16_t v4; // si
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edx
  char v11; // al
  _BOOL1 v12; // cc
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  char v19; // al
  int v20; // eax
  int v21; // eax
  int v22; // eax
  char v23; // al
  int v24; // eax
  int v25; // eax
  char v26; // al
  int v27; // eax
  int v28; // edx
  int16_t v29; // si
  int16_t v30; // si
  hr_int128_t v31; // [esp-28h] [ebp-80h]
  int v32; // [esp+0h] [ebp-58h] BYREF
  int v33; // [esp+4h] [ebp-54h]
  hr_int128_t v34; // [esp+8h] [ebp-50h]
  int64_t v35; // [esp+18h] [ebp-40h]
  int v36; // [esp+20h] [ebp-38h]
  int v37; // [esp+24h] [ebp-34h]
  int v38; // [esp+28h] [ebp-30h]
  int v39; // [esp+2Ch] [ebp-2Ch]
  int v40; // [esp+30h] [ebp-28h]
  int v41; // [esp+34h] [ebp-24h]
  int v42; // [esp+38h] [ebp-20h]
  int v43; // [esp+3Ch] [ebp-1Ch]
  int v44; // [esp+40h] [ebp-18h]
  int v45; // [esp+44h] [ebp-14h]
  int v46; // [esp+48h] [ebp-10h]
  int v47; // [esp+4Ch] [ebp-Ch]
  int v48; // [esp+50h] [ebp-8h]
  int64_t var4; // [esp+54h] [ebp-4h] OVERLAPPED

  v2 = a1;
  v3 = 9 * (int16_t)a1;
  v42 = a1;
  LOWORD(a1) = byte_19ABA4[v3];
  v4 = -1;
  v39 = a1;
  v5 = v2;
  switch ( v2 )
  {
    case 0u:
      v6 = 9 * (int16_t)v2;
      LOWORD(v6) = *(int16_t *)((char *)&word_19ABA7 + v6);
      v40 = v6;
      v4 = 0;
      v47 = 0;
      if ( *(int16_t *)((char *)&word_19ABA9 + 9 * (int16_t)v2) )
      {
        v7 = 9 * (int16_t)v2;
        LOWORD(v7) = *(int16_t *)((char *)&word_19ABA9 + v7);
        v4 = 1;
        v47 = v7;
      }
      goto LABEL_97;
    case 1u:
      HIWORD(v8) = HIWORD(dword_1930D4);
      LOWORD(v8) = *(_WORD *)(17 * *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2) + dword_1930D4);
      v4 = 0;
      v46 = v8;
      goto LABEL_97;
    case 2u:
      v9 = 9 * (int16_t)v2;
      LOWORD(v9) = *(int16_t *)((char *)&word_19ABA7 + v9);
      v46 = v9;
      LOWORD(a2) = byte_19ABA6[9 * (int16_t)v2];
      v10 = 100
          * (*(int16_t *)((char *)&word_19ABAB + 9 * (int16_t)v2) - *(int16_t *)((char *)&word_19ABA9 + 9 * (int16_t)v2));
      v38 = *(int16_t *)((char *)&word_19ABAB + 9 * (int16_t)v2);
      LODWORD(var4) = v10 / v38;
      v11 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v11 >= 5u )
      {
        if ( (uint8_t)v11 > 5u )
          goto LABEL_7;
        v12 = *(int16_t *)((char *)&word_19ABA9 + 9 * (int16_t)v2) <= 0;
LABEL_13:
        if ( !v12 )
        {
LABEL_28:
          v4 = 3;
          goto LABEL_97;
        }
        goto LABEL_86;
      }
      if ( v11 == 4 )
      {
        v4 = 1;
        if ( !*(int16_t *)((char *)&word_19ABA9 + 9 * (int16_t)v2) )
          v4 = -1;
      }
      goto LABEL_97;
    case 3u:
      v13 = 9 * (int16_t)v2;
      a2 = v13;
      v4 = 0;
      LOWORD(v13) = *(int16_t *)((char *)&word_19ABA9 + v13);
      LOWORD(a2) = *(int16_t *)((char *)&word_19ABA7 + a2);
      goto LABEL_16;
    case 4u:
      v14 = 9 * (int16_t)v2;
      goto LABEL_18;
    case 5u:
      v14 = 9 * (int16_t)v2;
      a2 = 100;
LABEL_18:
      LOWORD(v14) = *(int16_t *)((char *)&word_19ABA7 + v14);
      v4 = 0;
      v44 = v14;
      goto LABEL_97;
    case 6u:
      v15 = 9 * (int16_t)v2;
      v4 = 0;
      a2 = v15;
      LOWORD(v15) = byte_19ABA4[v15];
      LOWORD(a2) = *(int16_t *)((char *)&word_19ABA7 + a2);
      goto LABEL_96;
    case 7u:
      v16 = 9 * (int16_t)v2;
      LOWORD(v16) = *(int16_t *)((char *)&word_19ABA7 + v16);
      v46 = v16;
      v17 = 9 * (int16_t)v2;
      a2 = v17;
      v4 = 0;
      LOWORD(v17) = *(int16_t *)((char *)&word_19ABAB + v17);
      LOWORD(a2) = *(int16_t *)((char *)&word_19ABA9 + a2);
      LODWORD(var4) = v17;
      if ( (int16_t)a2 < 1 )
      {
        v4 = 1;
        a2 = v17;
      }
      goto LABEL_97;
    case 8u:
      v4 = 0;
      if ( *(int16_t *)((char *)&word_19ABA9 + 9 * (int16_t)v2) != -1 )
      {
        v18 = 9 * (int16_t)v2;
        LOWORD(v18) = *(int16_t *)((char *)&word_19ABA9 + v18);
        v4 = 1;
        v41 = v18;
      }
      goto LABEL_97;
    case 9u:
      v19 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v19 < 5u )
        goto LABEL_97;
      if ( (uint8_t)v19 > 5u )
        goto LABEL_27;
      goto LABEL_86;
    case 0xAu:
      v5 = 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2);
      LOWORD(v5) = *(uint8_t *)(dword_1930D4 + v5 + 2);
      goto LABEL_30;
    case 0xBu:
      v20 = 9 * (int16_t)v2;
      LOWORD(v20) = byte_19ABA4[v20];
      v45 = v20;
      goto LABEL_33;
    case 0xCu:
LABEL_33:
      v21 = 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2);
      LOWORD(v21) = *(uint8_t *)(dword_1930D4 + v21 + 2);
      v48 = v21;
      v4 = 0;
      LOWORD(a2) = *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2) + 10);
      goto LABEL_97;
    case 0xEu:
      v22 = 9 * (int16_t)v2;
      LOWORD(v22) = *(int16_t *)((char *)&word_19ABA7 + v22);
      v48 = v22;
      v23 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v23 < 5u )
        goto LABEL_97;
      if ( (uint8_t)v23 > 5u )
        goto LABEL_36;
      goto LABEL_86;
    case 0xFu:
      v5 = 9 * (int16_t)v2;
      a2 = v5;
      v4 = 0;
      LOWORD(v5) = *(int16_t *)((char *)&word_19ABA7 + v5);
      LOWORD(a2) = *(int16_t *)((char *)&word_19ABA9 + a2);
      goto LABEL_31;
    case 0x10u:
      v24 = 9 * (int16_t)v2;
      LOWORD(v24) = *(int16_t *)((char *)&word_19ABA7 + v24);
      v46 = v24;
      a2 = 9 * (int16_t)v2;
      v11 = byte_19ABA5[a2];
      LOWORD(a2) = *(int16_t *)((char *)&word_19ABA9 + a2);
      if ( (uint8_t)v11 < 5u )
        goto LABEL_42;
      if ( (uint8_t)v11 > 5u )
        goto LABEL_7;
      goto LABEL_86;
    case 0x11u:
      v25 = 9 * (int16_t)v2;
      LOWORD(v25) = *(int16_t *)((char *)&word_19ABA7 + v25);
      v46 = v25;
      v23 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v23 < 5u )
        goto LABEL_97;
      if ( (uint8_t)v23 <= 5u )
        goto LABEL_86;
LABEL_36:
      if ( v23 == 6 )
        goto LABEL_37;
      goto LABEL_97;
    case 0x12u:
      v13 = 9 * (int16_t)v2;
      LOWORD(v13) = *(int16_t *)((char *)&word_19ABA7 + v13);
      v4 = 0;
LABEL_16:
      v43 = v13;
      goto LABEL_97;
    case 0x13u:
      v26 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v26 < 5u )
      {
        if ( v26 == 4 && *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2) != -1 )
        {
          v5 = 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2);
          LOWORD(v5) = *(uint8_t *)(dword_1930D4 + v5 + 2);
          v4 = 3;
LABEL_31:
          v48 = v5;
        }
        goto LABEL_97;
      }
      if ( (uint8_t)v26 > 5u )
        goto LABEL_50;
      goto LABEL_57;
    case 0x14u:
      v26 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v26 >= 5u )
      {
        if ( (uint8_t)v26 > 5u )
          goto LABEL_50;
LABEL_57:
        if ( *(int16_t *)((char *)&word_19ABA9 + 9 * (int16_t)v2) == -1 )
        {
LABEL_86:
          v4 = 2;
          goto LABEL_97;
        }
LABEL_43:
        v4 = 1;
        goto LABEL_97;
      }
      if ( v26 != 4 )
        goto LABEL_97;
LABEL_63:
      if ( *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2) == -1 )
        goto LABEL_97;
      v27 = 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2);
      v28 = dword_1930D4;
      break;
    case 0x15u:
      v26 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v26 < 5u )
        goto LABEL_69;
      if ( (uint8_t)v26 > 5u )
        goto LABEL_50;
      goto LABEL_57;
    case 0x16u:
      v26 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v26 >= 5u )
      {
        if ( (uint8_t)v26 > 5u )
          goto LABEL_50;
        goto LABEL_57;
      }
LABEL_69:
      if ( v26 != 4 || *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2) == -1 )
        goto LABEL_97;
      v28 = 17 * *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2);
      v27 = dword_1930D4;
      break;
    case 0x17u:
      v26 = byte_19ABA5[9 * (int16_t)v2];
      if ( (uint8_t)v26 < 4u )
      {
        if ( v26 != 3 )
          goto LABEL_97;
        goto LABEL_57;
      }
      if ( (uint8_t)v26 > 4u )
      {
LABEL_50:
        if ( v26 == 6 )
        {
          *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2) = -1;
          goto LABEL_37;
        }
LABEL_97:
        if ( v4 != -1 )
        {
          if ( byte_199BE5 == 1 )
          {
            if ( byte_19ACF0 )
            {
              dword_19AA70 = 0;
              sub_1247A0(4u);
              sub_21B6D(
                0,
                0,
                0,
                0,
                0,
                0,
                (int)&unk_19AA74,
                v32,
                v33,(int)LODWORD(v34),
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                var4);
              byte_19ACEF = 0;
            }
            else
            {
              sub_2031D();
              dword_19AA70 = 0;
              sub_1247A0(4u);
              sub_21B6D(
                0,
                0,
                0,
                0,
                0,
                0,
                (int)&unk_19AA74,
                v32,
                v33,(int)LODWORD(v34),
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                var4);
            }
            sub_20400((int16_t *)a2);
          }
          ++byte_19ACF0;
          if ( byte_199BE5 == 1 )
            sub_203CB(v42);
          HIDWORD(v31) = (int16_t)v45;
          DWORD2(v31) = (int16_t)v43;
          DWORD1(v31) = (int16_t)v39;
          LODWORD(v31) = (int16_t)var4;
          sub_21B6D((int)LODWORD(v31),
            (int16_t)v41,
            (int16_t)v44,
            (int16_t)v48,
            (int16_t)v40,
            (int16_t)v47,
            (int)&unk_19AA74,
            v32,
            v33,(int)LODWORD(v34),
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            var4);
          byte_19ACEF = 0;
          if ( byte_199BE5 == 1 )
          {
            sub_20400((int16_t *)a2);
          }
          else
          {
            sub_249F9(aJimtextLbx_1, 29, (char *)&v32, 40);
            sub_87698((int)&v32, (int)&unk_19AA74, (int16_t *)a2);
            sub_11C2F0();
          }
        }
        JUMPOUT(0x23D99);
      }
      goto LABEL_63;
    case 0x18u:
      LOWORD(v5) = *(int16_t *)((char *)&word_19ABA7 + v3);
      v48 = v5;
      LOWORD(v5) = *(int16_t *)((char *)&word_19ABA9 + v3);
      LODWORD(var4) = v5;
      v11 = byte_19ABA5[v3];
      LOWORD(a2) = byte_19ABA6[v3];
      if ( (uint8_t)v11 >= 5u )
      {
        if ( (uint8_t)v11 > 5u )
        {
LABEL_7:
          if ( v11 != 6 )
            goto LABEL_97;
LABEL_37:
          v4 = 0;
          goto LABEL_97;
        }
        v12 = (int16_t)var4 <= 0;
        goto LABEL_13;
      }
LABEL_42:
      if ( v11 != 4 )
        goto LABEL_97;
      goto LABEL_43;
    case 0x19u:
      LOWORD(v5) = *(int16_t *)((char *)&word_19ABA7 + v3);
      v48 = v5;
      goto LABEL_84;
    case 0x1Au:
    case 0x1Bu:
LABEL_84:
      v19 = byte_19ABA5[v3];
      if ( (uint8_t)v19 < 5u )
        goto LABEL_97;
      if ( (uint8_t)v19 <= 5u )
        goto LABEL_86;
LABEL_27:
      if ( v19 == 6 )
        goto LABEL_28;
      goto LABEL_97;
    case 0x1Cu:
      LOWORD(a2) = *(int16_t *)((char *)&word_19ABA7 + v3);
      LOWORD(v5) = *(int16_t *)((char *)&word_19ABA9 + v3);
LABEL_30:
      v4 = 0;
      goto LABEL_31;
    case 0x1Du:
    case 0x21u:
      goto LABEL_94;
    case 0x1Eu:
      v4 = *(int16_t *)((char *)&word_19ABA9 + v3);
      if ( v4 > 3 )
        v4 = 3;
      a2 = 9 * (int16_t)v2;
      LOWORD(a2) = *(int16_t *)((char *)&word_19ABA7 + a2);
      goto LABEL_97;
    case 0x1Fu:
      v4 = *(int16_t *)((char *)&word_19ABA9 + v3);
      a2 = 0;
      goto LABEL_97;
    case 0x20u:
      v15 = sub_1247A0(4u);
      v29 = v15;
      LOWORD(v15) = byte_19ABA4[v3];
      v4 = v29 - 1;
      goto LABEL_96;
    case 0x22u:
      LOWORD(v5) = *(int16_t *)((char *)&word_19ABA7 + v3);
      v44 = v5;
LABEL_94:
      v4 = sub_1247A0(4u) - 1;
      goto LABEL_97;
    case 0x23u:
      v15 = sub_1247A0(4u);
      v30 = v15;
      LOWORD(v15) = *(int16_t *)((char *)&word_19ABA7 + v3);
      v4 = v30 - 1;
LABEL_96:
      v45 = v15;
      goto LABEL_97;
    default:
      goto LABEL_97;
  }
  LOWORD(v27) = *(uint8_t *)(v28 + v27 + 2);
  v48 = v27;
  v4 = 3;
  *(int16_t *)((char *)&word_19ABA7 + 9 * (int16_t)v2) = -1;
  goto LABEL_97;
}
// 21AC6: control flows out of bounds to 23D99
// 21371: variables would overlap: ^7C.8 and stkvar "__saved_registers" ^80.24(special frame member)
// 1930D4: using guessed type int dword_1930D4;
// 199BE5: using guessed type char byte_199BE5;
// 19AA70: using guessed type int dword_19AA70;
// 19ABA7: using guessed type int16_t word_19ABA7;
// 19ABA9: using guessed type int16_t word_19ABA9;
// 19ABAB: using guessed type int16_t word_19ABAB;
// 19ACEF: using guessed type char byte_19ACEF;
// 19ACF0: using guessed type char byte_19ACF0;


//----- (00021B6D) --------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge sub_21B6D(
        hr_int128_t a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        hr_int128_t a10,
        int64_t a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int64_t a25)
{
  char *v25; // esi
  char *v26; // esi
  unsigned int v27; // ecx
  char *v28; // edi
  char *v29; // esi
  int v30; // eax
  _BOOL1 v31; // zf
  int v32; // edx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // esi
  int v37; // eax
  char *v38; // edi
  char *v39; // edi
  int v40; // edi
  char *v41; // edi
  _BYTE *v42; // edi
  char *v43; // edi
  int v44; // edi
  char *v45; // esi
  char *v46; // edi
  _BYTE *v47; // edx
  char v48; // al
  int v49; // eax
  char *v50; // edi
  int16_t v51; // bx
  int16_t i; // di
  int v53; // eax
  int v54; // eax
  int16_t j; // di
  int16_t k; // si
  int v57; // eax
  char *v58; // edi
  int16_t v59; // cx
  int v60; // edi
  int64_t v61; // rax
  char *v62; // edi
  char *v63; // edi
  char *v65; // [esp-14h] [ebp-1C8h]
  int v66; // [esp-14h] [ebp-1C8h]
  _BYTE *v67; // [esp-14h] [ebp-1C8h]
  int v68; // [esp-14h] [ebp-1C8h]
  int16_t v69; // [esp+4Ah] [ebp-16Ah]
  int16_t v70; // [esp+4Eh] [ebp-166h]
  int16_t v71; // [esp+52h] [ebp-162h]
  int16_t v72; // [esp+56h] [ebp-15Eh]
  _BYTE v73[300]; // [esp+5Ah] [ebp-15Ah] BYREF
  _DWORD v74[11]; // [esp+186h] [ebp-2Eh] BYREF

  *(_DWORD *)((char *)&a11 + 6) = 0;
  **(_BYTE **)((char *)&a25 + 2) = 0;
  strcpy((char *)&a1 + 2, "EVENTMSE.LBX");
  switch ( byte_199CAE )
  {
    case 1:
      v25 = aEventmsgLbx;
      goto LABEL_7;
    case 2:
      v25 = aEventmsfLbx;
      goto LABEL_7;
    case 3:
      v25 = aEventmssLbx;
      goto LABEL_7;
    case 4:
      v25 = aEventmsiLbx;
      goto LABEL_7;
    case 5:
      v25 = aEventmspLbx;
LABEL_7:
      *(_DWORD *)((char *)&a1 + 2) = *(_DWORD *)v25;
      v26 = v25 + 4;
      *(_DWORD *)((char *)&a1 + 6) = *(_DWORD *)v26;
      v26 += 4;
      *(_DWORD *)((char *)&a1 + 10) = *(_DWORD *)v26;
      BYTE14(a1) = v26[4];
      break;
    default:
      break;
  }
  v27 = 0;
  *(_DWORD *)((char *)&a10 + 14) = 0;
  sub_126C91((int)&a1 + 2, (int16_t)(v71 + 4 * v72), (int)v73, 0, 1u, 300);
  while ( SHIWORD(a10) < 300 && v73[SHIWORD(a10)] )
  {
    switch ( v73[SHIWORD(a10)] )
    {
      case 0x80:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v28 = *(char **)((char *)&a25 + 2);
        v29 = (char *)sub_77B28(*(_WORD *)(dword_192B18 + 361 * v70 + 2));
        goto LABEL_34;
      case 0x81:
        v29 = (char *)&a1 + 2;
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v30 = v69;
        goto LABEL_12;
      case 0x82:
        v29 = (char *)&a1 + 2;
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v30 = SHIWORD(a16);
LABEL_12:
        v28 = *(char **)((char *)&a25 + 2);
        itoa(v30, (char *)&a1 + 2, 10, v27);
        goto LABEL_34;
      case 0x83:
        if ( v69 > 1 )
          goto LABEL_17;
        v31 = v69 == 0;
        goto LABEL_16;
      case 0x84:
        if ( SHIWORD(a16) > 1 )
          goto LABEL_17;
        v31 = HIWORD(a16) == 0;
LABEL_16:
        if ( !v31 )
          goto LABEL_62;
LABEL_17:
        if ( byte_199CAE )
          goto LABEL_62;
        v29 = aS_24;
        v28 = *(char **)((char *)&a25 + 2);
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        goto LABEL_34;
      case 0x85:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v32 = 3753 * SHIWORD(a17);
        v33 = dword_197F98;
        goto LABEL_22;
      case 0x86:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v34 = SHIWORD(a18);
        goto LABEL_24;
      case 0x87:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v34 = v69;
LABEL_24:
        v28 = *(char **)((char *)&a25 + 2);
        v29 = *(char **)((char *)&off_17D904 + 23 * v34);
        goto LABEL_34;
      case 0x88:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v28 = *(char **)((char *)&a25 + 2);
        v29 = (char *)(3753 * SHIWORD(a19) + dword_197F98 + 1);
        goto LABEL_34;
      case 0x89:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v35 = 59 * SHIWORD(a20);
        v36 = dword_1930DC;
        goto LABEL_27;
      case 0x8A:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v33 = 3753 * SHIWORD(a21);
        v32 = dword_197F98;
LABEL_22:
        v28 = *(char **)((char *)&a25 + 2);
        v29 = (char *)(v32 + v33 + 21);
        goto LABEL_34;
      case 0x8B:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v35 = 113 * SHIWORD(a22);
        v36 = dword_19306C;
LABEL_27:
        v28 = *(char **)((char *)&a25 + 2);
        v29 = (char *)(v35 + v36);
        goto LABEL_34;
      case 0x8C:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v28 = *(char **)((char *)&a25 + 2);
        v29 = (char *)dword_192BF4[v69];
        goto LABEL_34;
      case 0x8D:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v37 = SHIWORD(a23);
        goto LABEL_33;
      case 0x8E:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        v37 = SHIWORD(a24);
LABEL_33:
        v28 = *(char **)((char *)&a25 + 2);
        v29 = *(char **)((char *)&off_17E079 + 13 * v37);
LABEL_34:
        v65 = v28;
        v38 = (char *)(v28 - 1);
        do
          ++v38;
        while ( *v38 );
        strcpy(v38, v29);
        v39 = v65;
        goto LABEL_54;
      case 0x8F:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        if ( HIWORD(a17) != word_19999C )
        {
          v40 = *(_DWORD *)((char *)&a25 + 2);
          sub_249F9(aJimtext2Lbx_0, 61, (char *)&a1 + 2, 30);
          v66 = v40;
          v41 = (char *)(v40 - 1);
          do
            ++v41;
          while ( *v41 );
          strcpy(v41, (char *)&a1 + 2);
          if ( !HIWORD(a11) )
            *(_BYTE *)(v66 + 1) -= 32;
        }
        goto LABEL_53;
      case 0x90:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        if ( HIWORD(a17) == word_19999C )
        {
          v42 = *(_BYTE **)((char *)&a25 + 2);
          sub_249F9(aJimtext2Lbx_0, 62, (char *)&a1 + 2, 30);
          v67 = v42;
          v43 = v42 - 1;
          do
            ++v43;
          while ( *v43 );
          strcpy(v43, (char *)&a1 + 2);
          if ( !HIWORD(a11) )
            *v67 -= 32;
          goto LABEL_53;
        }
        if ( a17 < 0 )
          goto LABEL_53;
        v44 = *(_DWORD *)((char *)&a25 + 2);
        v45 = (char *)(3753 * SHIWORD(a17) + dword_197F98 + 21);
        goto LABEL_50;
      case 0x91:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        if ( HIWORD(a21) == word_19999C )
          goto LABEL_53;
        v45 = (char *)&a1 + 2;
        v44 = *(_DWORD *)((char *)&a25 + 2);
        sub_249F9(aJimtext2Lbx_0, 61, (char *)&a1 + 2, 30);
        goto LABEL_50;
      case 0x92:
        *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
        if ( HIWORD(a21) == word_19999C )
        {
          v45 = (char *)&a1 + 2;
          v44 = *(_DWORD *)((char *)&a25 + 2);
          sub_249F9(aJimtext2Lbx_0, 62, (char *)&a1 + 2, 30);
        }
        else
        {
          if ( a21 < 0 )
            goto LABEL_53;
          v44 = *(_DWORD *)((char *)&a25 + 2);
          v45 = (char *)(3753 * SHIWORD(a21) + dword_197F98 + 21);
        }
LABEL_50:
        v46 = (char *)(v44 - 1);
        do
          ++v46;
        while ( *v46 );
        strcpy(v46, v45);
LABEL_53:
        v39 = *(char **)((char *)&a25 + 2);
LABEL_54:
        v27 = strlen(v39);
        *(_DWORD *)((char *)&a11 + 6) = v27;
LABEL_62:
        ++*(_DWORD *)((char *)&a10 + 14);
        break;
      default:
        v47 = (_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11));
        v48 = v73[SHIWORD(a10)];
        ++*(_DWORD *)((char *)&a11 + 6);
        *v47 = v48;
        goto LABEL_62;
    }
  }
  *(_BYTE *)(*(_DWORD *)((char *)&a25 + 2) + SHIWORD(a11)) = 0;
  LOBYTE(v49) = v72 - 2;
  if ( v72 == 33 )
  {
    v50 = (char *)(*(_DWORD *)((char *)&a25 + 2) - 1);
    do
      ++v50;
    while ( *v50 );
    strcpy(v50, asc_178B9D);
    if ( !v71 )
      sub_E2671((int)v74);
    v51 = 0;
    for ( i = 0; i < word_199998; ++i )
    {
      v53 = dword_197F98 + 3753 * i;
      if ( !*(_BYTE *)(v53 + 36) )
      {
        *((_WORD *)&a6 + v51 + 1) = i;
        switch ( v71 )
        {
          case 0:
            v54 = v74[i];
            goto LABEL_77;
          case 1:
            v54 = *(int16_t *)(v53 + 166);
            goto LABEL_77;
          case 2:
            v54 = *(_DWORD *)(v53 + 548);
            goto LABEL_77;
          case 3:
            v54 = sub_2223D(i);
LABEL_77:
            v74[v51 + 8] = v54;
            break;
          default:
            break;
        }
        ++v51;
      }
    }
    for ( j = 0; j < v51; ++j )
    {
      for ( k = 0; k < v51 - 1; ++k )
      {
        v57 = k;
        if ( v74[v57 + 8] < v74[v57 + 9] )
        {
          *(_DWORD *)((char *)&a10 + 2) = &v74[v57 + 9];
          sub_1330D2(&v74[v57 + 8], *(int **)((char *)&a10 + 2));
          *(_DWORD *)((char *)&a10 + 2) = (char *)&a6 + 2;
          sub_133111((int16_t *)&a6 + k + 1, (int16_t *)&a6 + k + 2);
        }
      }
    }
    v58 = (char *)(*(_DWORD *)((char *)&a25 + 2) - 1);
    do
      ++v58;
    while ( *v58 );
    strcpy(v58, byte_178B9F);
    if ( byte_199BE5 == 1 )
      *(_DWORD *)((char *)&a11 + 2) = 120;
    else
      *(_DWORD *)((char *)&a11 + 2) = 10;
    *(_DWORD *)((char *)&a10 + 6) = 125;
    v59 = WORD1(a11);
    if ( v51 > 6 )
      v51 = 6;
    *(_DWORD *)((char *)&a10 + 10) = 0;
    v60 = *(_DWORD *)((char *)&a25 + 2);
    while ( v51 > SWORD5(a10) )
    {
      v61 = sprintf(
              (char *)&a1 + 2,
              "\aX%d.%d. %s",
              v59,
              SWORD5(a10) + 1,
              (char *)(dword_197F98 + 3753 * *((int16_t *)&a6 + SWORD5(a10) + 1) + 21));
      v68 = v60;
      v62 = (char *)(v60 - 1);
      do
        ++v62;
      while ( *v62 );
      strcpy(v62, (char *)&a1 + 2);
      v60 = v68;
      v49 = SHIDWORD(v61) / 3;
      if ( SHIDWORD(v61) % 3 )
      {
        v59 += WORD3(a10);
      }
      else
      {
        v59 = WORD1(a11);
        v63 = (char *)(v68 - 1);
        do
          ++v63;
        while ( *v63 );
        strcpy(v63, asc_178B9D);
        v60 = v68;
      }
      ++*(_DWORD *)((char *)&a10 + 10);
    }
  }
  return v49;
}
// 21C02: inconsistent variable size for '^218.16'
// 22029: inconsistent variable size for '^218.16'
// 21B7A: inconsistent variable size for '^228.8'
// 21F69: inconsistent variable size for '^228.8'
// 22024: inconsistent variable size for '^228.8'
// 1265F2: using guessed type int64_t sprintf(_DWORD, char *, ...);
// 1288C0: using guessed type int __fastcall itoa(_DWORD, _DWORD, _DWORD, _DWORD);
// 17D904: using guessed type _UNKNOWN *off_17D904;
// 17E079: using guessed type _UNKNOWN *off_17E079;
// 192B18: using guessed type int dword_192B18;
// 192BF4: using guessed type int dword_192BF4[];
// 19306C: using guessed type int dword_19306C;
// 1930DC: using guessed type int dword_1930DC;
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 19999C: using guessed type int16_t word_19999C;
// 199BE5: using guessed type char byte_199BE5;
// 199CAE: using guessed type char byte_199CAE;


//----- (0002223D) --------------------------------------------------------
int __fastcall sub_2223D( int a1)
{
  int v2; // edx
  int16_t i; // bx
  int v4; // eax

  v2 = 0;
  for ( i = 0; i < word_199994; ++i )
  {
    v4 = dword_197F9C + 129 * i;
    if ( *(char *)(v4 + 99) == a1 && *(char *)(v4 + 100) <= 1 )
      v2 += *(uint8_t *)(v4 + 16) + 1;
  }
  return v2;
}
// 197F9C: using guessed type int dword_197F9C;
// 199994: using guessed type int16_t word_199994;


//----- (0002230A) --------------------------------------------------------
void __usercall sub_2230A( int a1)
{
  int v1; // eax
  _BOOL2 v2; // cx
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  int16_t v7; // cx
  int16_t i; // di
  int16_t v9; // ax
  int16_t v10; // ax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int16_t v14; // ax
  int16_t v15; // ax
  int16_t v16; // ax
  int16_t v17; // ax
  int16_t v18; // ax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int16_t v22; // ax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  unsigned int v27; // eax
  int16_t v28; // ax
  int v29; // eax
  _BOOL1 v30; // cc
  int v31; // eax
  int16_t v32; // dx
  int16_t v33; // ax
  int16_t v34; // ax
  int16_t v35; // ax
  int16_t v36; // ax
  int v37; // edx
  int16_t v38; // ax
  int v39; // edx
  unsigned int v40; // eax
  unsigned int v41; // edx
  int16_t v42; // ax
  int16_t v43; // ax
  int16_t v44; // ax
  char v45; // al
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int16_t v49; // dx
  int16_t v50; // ax
  int v51; // eax
  char v52; // [esp+0h] [ebp-2Ch] BYREF
  int v53; // [esp+1h] [ebp-2Bh]
  int v54; // [esp+5h] [ebp-27h]
  _WORD v55[2]; // [esp+Ch] [ebp-20h] BYREF
  unsigned int v56; // [esp+10h] [ebp-1Ch]
  int v57; // [esp+14h] [ebp-18h]
  int v58; // [esp+18h] [ebp-14h]
  int16_t v59; // [esp+1Ch] [ebp-10h]
  int16_t v60; // [esp+20h] [ebp-Ch] BYREF
  int v61; // [esp+24h] [ebp-8h]
  int v62; // [esp+28h] [ebp-4h]

  sub_245C4();
  sub_24511();
  v58 = v1;
  v2 = 0;
  if ( (int16_t)v1 != -1 )
    v2 = dword_192FD8 - 35000 >= 50;
  if ( byte_199BDE == 1 && !v2 )
  {
    if ( dword_192FD8 < dword_19ACE8
      || dword_192FD8 - 35000 < 50
      || (v3 = dword_192FD8 - dword_19ACE8, dword_192FD8 - dword_19ACE8 < 0) )
    {
      v3 = 0;
    }
    if ( word_19ACEC < 5 )
    {
      ++word_19ACEC;
      v3 = 0;
    }
    switch ( byte_199CB0 )
    {
      case 0:
        v4 = v3 / 2;
        goto LABEL_18;
      case 1:
        v5 = 2 * v3;
        v6 = 3;
        goto LABEL_14;
      case 2:
        v4 = (3 * v3 - (__CFSHL__((3 * v3) >> 31, 2) + 4 * ((3 * v3) >> 31))) >> 2;
        goto LABEL_18;
      case 3:
        v5 = 4 * v3;
        v6 = 5;
LABEL_14:
        v4 = v5 / v6;
        goto LABEL_18;
      case 4:
        v4 = 5 * v3 / 6;
LABEL_18:
        v3 = v4;
        break;
      default:
        break;
    }
    if ( (int)sub_1247A0(0x200u) <= v3 )
      v2 = 1;
  }
  if ( !v2 )
LABEL_174:
    JUMPOUT(0x23D99);
  v7 = -1;
  for ( i = 0; ; ++i )
  {
    if ( i >= 5 || v7 != -1 )
    {
      sub_23563();
      if ( sub_1247A0(0x28u) == 1 && dword_192FD8 - 35000 > 50 && !word_19A0E2 )
      {
        byte_19ACBC = 6;
        word_19ACC0 = sub_1247A0(4u) - 1;
      }
      goto LABEL_174;
    }
    v7 = sub_1247A0(0x1Du) - 1;
    if ( !byte_199CB0 && !byte_180E84[v7] )
    {
      v7 = -1;
      continue;
    }
    if ( !byte_19ABA5[9 * v7] )
    {
      v59 = -1;
      if ( (int16_t)v58 == -1 )
      {
        if ( v7 == 9 )
          goto LABEL_34;
        if ( v7 == 24 )
          goto LABEL_34;
        sub_22D57(byte_180E84[v7]);
        v59 = v9;
        if ( v9 != -1 )
          goto LABEL_34;
      }
      else if ( byte_180E84[v7] == 1 )
      {
        v59 = v58;
        goto LABEL_34;
      }
    }
    v7 = -1;
LABEL_34:
    if ( dword_192FD8 - 35000 < 200 && (v7 == 2 || v7 == 24) )
      v7 = -1;
    if ( v7 == 2 && !sub_233FA() )
      v7 = -1;
    if ( dword_192FD8 - 35000 < 100 && v7 == 19 && !sub_233FA() )
      v7 = -1;
    if ( dword_192FD8 - 35000 < 150 && v7 == 22 && !sub_233FA() )
      v7 = -1;
    if ( dword_192FD8 - 35000 < 200 && v7 == 20 && !sub_233FA() )
      v7 = -1;
    if ( dword_192FD8 - 35000 < 250 && v7 == 23 && !sub_233FA() )
      v7 = -1;
    if ( dword_192FD8 - 35000 < 300 && v7 == 21 && !sub_233FA() )
      v7 = -1;
    if ( !v7 )
    {
      sub_58853(v59, (int)v55, &v60);
      if ( v60 < 1 )
        v7 = -1;
    }
    if ( v7 == 15 && *(int *)(3753 * v59 + dword_197F98 + 50) < 100 )
      v7 = -1;
    if ( v7 == 1 )
    {
      sub_2310C(v59);
      a1 = v10;
      if ( v10 == -1 )
        v7 = -1;
    }
    if ( v7 == 4 || v7 == 5 )
    {
      v11 = v59;
      sub_23B7D(v59);
      v57 = v12;
      if ( (int16_t)v12 == -1 || *(char *)(dword_197F98 + 3753 * v11 + (int16_t)v12 + 1575) >= 4 )
        v7 = -1;
    }
    if ( v7 == 8 )
    {
      sub_23CED(v59);
      v62 = v13;
      if ( (int16_t)v13 == -1 )
        v7 = -1;
    }
    if ( v7 == 10 )
    {
      if ( *(_BYTE *)(dword_197F98 + 3753 * v59 + 2230) == 1 || (sub_231B4(v59), a1 = v14, v14 == -1) )
        v7 = -1;
    }
    if ( v7 == 11 )
    {
      sub_2325E(v59);
      a1 = v15;
      if ( v15 == -1 )
        v7 = -1;
    }
    if ( v7 == 12 )
    {
      sub_232BB(v59);
      a1 = v16;
      if ( v16 == -1 )
        v7 = -1;
    }
    if ( v7 == 14 && *(int16_t *)(dword_197F98 + 3753 * v59 + 54) < 4 )
      v7 = -1;
    if ( v7 == 13 )
      v7 = -1;
    if ( v7 == 16 )
    {
      sub_23DA0(v59);
      a1 = v17;
      if ( v17 == -1 )
        goto LABEL_99;
      if ( byte_19AC3E == 2 && v17 == word_19AC40 )
        v7 = -1;
      if ( (int16_t)sub_23E60(v17) != -1 )
LABEL_99:
        v7 = -1;
    }
    if ( v7 == 17 )
    {
      v18 = sub_23D44(v59);
      a1 = v18;
      if ( v18 == -1 )
        goto LABEL_108;
      if ( byte_19AC35 == 2 && v18 == word_19AC37 )
        v7 = -1;
      if ( (int16_t)sub_23E60(v18) != -1 )
        v7 = -1;
      HIWORD(v19) = HIWORD(dword_192B18);
      v20 = dword_192B18 + 361 * a1;
      LOWORD(v19) = *(uint8_t *)(v20 + 10);
      v21 = 17 * *(int16_t *)(v20 + 2);
      v61 = v19;
      sub_E0B4F((int16_t *)(dword_1930D4 + v21), v59);
      if ( v22 == (_WORD)v61 )
LABEL_108:
        v7 = -1;
    }
    if ( v7 == 28 )
    {
      sub_100519(v59, (int)&v52);
      if ( !v52 )
        v7 = -1;
    }
    if ( v7 == 26 || v7 == 27 )
    {
      sub_23CED(v59);
      v62 = v23;
      if ( (int16_t)v23 == -1 )
        v7 = -1;
    }
    if ( v7 != -1 )
    {
      v24 = 9 * v7;
      byte_19ABA5[v24] = 1;
      byte_19ABA6[v24] = -1;
      *(int16_t *)((char *)&word_19ABA7 + v24) = -1;
      v25 = dword_192FD8;
      *(int16_t *)((char *)&word_19ABA9 + v24) = -1;
      dword_19ACE8 = v25;
      *(int16_t *)((char *)&word_19ABAB + v24) = -1;
      word_19ACEC = 0;
      byte_19ABA4[v24] = v59;
      v26 = (uint16_t)v7;
      switch ( v7 )
      {
        case 0:
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v55[0];
          *(int16_t *)((char *)&word_19ABA9 + 9 * v7) = 0;
          if ( v60 <= 1 )
            continue;
          v24 = 9 * v7;
          LOWORD(v27) = v55[1];
          goto LABEL_120;
        case 1:
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = *(_WORD *)(dword_192B18 + 361 * a1 + 2);
          continue;
        case 2:
          sub_23DA0(v59);
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v28;
          if ( *(int16_t *)((char *)&word_19ABA7 + 9 * v7) == -1
            || (int16_t)sub_23E60(*(int16_t *)((char *)&word_19ABA7 + 9 * v7)) != -1 )
          {
            goto LABEL_131;
          }
          *(int16_t *)((char *)&word_19ABA9 + 9 * v7) = 10 * ((uint8_t)byte_199CB0 + sub_1247A0(5u) + 10);
          *(int16_t *)((char *)&word_19ABAB + 9 * v7) = *(int16_t *)((char *)&word_19ABA9 + 9 * v7);
          byte_19ABA6[9 * v7] = sub_1247A0(5u) + 10 - byte_199CB0;
          continue;
        case 3:
          v30 = *(_DWORD *)(dword_197F98 + 3753 * v59 + 491) < 10;
          goto LABEL_135;
        case 4:
        case 5:
          v31 = 9 * v7;
          v32 = v57;
          goto LABEL_138;
        case 6:
          v32 = 100 * ((dword_192FD8 - 35000) / 20) + 100;
          v31 = 9 * v7;
          goto LABEL_138;
        case 7:
          sub_23DA0(v59);
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v33;
          if ( *(int16_t *)((char *)&word_19ABA7 + 9 * v7) == -1 )
            goto LABEL_136;
          continue;
        case 8:
          v31 = 9 * v7;
          v32 = v62;
          goto LABEL_138;
        case 9:
          byte_19ABA6[9 * v7] = 0;
          continue;
        case 10:
          v24 = 9 * v7;
          v34 = *(_WORD *)(361 * a1 + dword_192B18 + 2);
          goto LABEL_145;
        case 11:
        case 12:
          v31 = 9 * v7;
          v32 = *(_WORD *)(361 * a1 + dword_192B18 + 2);
LABEL_138:
          *(int16_t *)((char *)&word_19ABA7 + v31) = v32;
          continue;
        case 13:
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v62;
          *(int16_t *)((char *)&word_19ABA9 + 9 * v7) = v57;
          continue;
        case 14:
          sub_23BEC(v59);
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v35;
          if ( v35 == -1 || (int16_t)sub_242FC(v35) != -1 )
            goto LABEL_131;
          v36 = sub_2448F(*(int16_t *)((char *)&word_19ABA7 + 9 * v7));
          *(int16_t *)((char *)&word_19ABA9 + 9 * v7) = v36;
          *(int16_t *)((char *)&word_19ABAB + 9 * v7) = v36;
          v30 = v36 < 1;
LABEL_135:
          if ( !v30 )
            continue;
LABEL_136:
          byte_19ABA5[9 * v7] = 0;
LABEL_159:
          v29 = 9 * v7;
          goto LABEL_132;
        case 15:
          v37 = v59;
          sub_23BEC(v59);
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v38;
          if ( v38 == -1 )
            goto LABEL_152;
          v39 = dword_197F98 + 3753 * v37;
          v56 = sub_1247A0(0x15u) + 29;
          v40 = v56 * *(_DWORD *)(v39 + 50);
          v56 = 100;
          v27 = v40 / 0x64;
          goto LABEL_120;
        case 16:
          LOWORD(v26) = (uint8_t)byte_199CB0;
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = a1;
          v61 = 2 * v26;
          v41 = sub_1247A0(8u) + 2 * v26;
          v42 = v41 * sub_23B64(*(int16_t *)((char *)&word_19ABA7 + 9 * v7));
          *(int16_t *)((char *)&word_19ABA9 + 9 * v7) = v42;
          *(int16_t *)((char *)&word_19ABAB + 9 * v7) = v42;
          if ( v42 < 1 )
          {
LABEL_152:
            byte_19ABA5[9 * v7] = 0;
            byte_19ABA4[9 * v7] = -1;
          }
          continue;
        case 17:
          byte_19ABA6[9 * v7] = 0;
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = a1;
          continue;
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
          sub_23BEC(v59);
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v43;
          if ( v43 == -1 )
          {
            byte_19ABA5[9 * v7] = 0;
            byte_19ABA4[9 * v7] = -1;
          }
          goto LABEL_159;
        case 24:
          sub_23A5F();
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v44;
          if ( v44 == -1 || (int16_t)sub_242FC(v44) != -1 )
            goto LABEL_131;
          v45 = sub_1247A0(5u);
          *(int16_t *)((char *)&word_19ABA9 + 9 * v7) = 0;
          i = 0;
          byte_19ABA6[9 * v7] = v45 + 10 - byte_199CB0;
          do
          {
            v46 = *(int16_t *)(2 * i + dword_19306C + 113 * *(int16_t *)((char *)&word_19ABA7 + 9 * v7) + 74);
            if ( v46 != -1 )
            {
              v47 = *(int16_t *)(dword_1930D4 + 17 * v46);
              if ( v47 != -1 )
                *(int16_t *)((char *)&word_19ABA9 + 9 * v7) += sub_23B64(v47);
            }
            ++i;
          }
          while ( i < 5 );
          v48 = 9 * v7;
          v49 = *(int16_t *)((char *)&word_19ABA9 + v48) * byte_19ABA6[v48];
          *(int16_t *)((char *)&word_19ABA9 + v48) = v49;
          *(int16_t *)((char *)&word_19ABAB + v48) = v49;
          continue;
        case 25:
          sub_23BEC(v59);
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v50;
          v51 = *(int16_t *)((char *)&word_19ABA7 + 9 * v7);
          byte_19ABA6[9 * v7] = 0;
          if ( v51 != -1 && (int16_t)sub_242FC(v51) == -1 )
            continue;
LABEL_131:
          v29 = 9 * v7;
          byte_19ABA5[v29] = 0;
LABEL_132:
          byte_19ABA4[v29] = -1;
          break;
        case 26:
          byte_19ABA6[9 * v7] = 0;
          continue;
        case 27:
          byte_19ABA5[9 * v7] = 3;
          v34 = v62;
          byte_19ABA6[9 * v7] = 0;
LABEL_145:
          *(int16_t *)((char *)&word_19ABA7 + v24) = v34;
          continue;
        case 28:
          *(int16_t *)((char *)&word_19ABA7 + 9 * v7) = v53;
          LOWORD(v27) = v54;
LABEL_120:
          *(int16_t *)((char *)&word_19ABA9 + v24) = v27;
          continue;
        default:
          continue;
      }
    }
  }
}
// 228DC: control flows out of bounds to 23D99
// 2231D: variable 'v1' is possibly undefined
// 2247E: variable 'v9' is possibly undefined
// 225CF: variable 'v10' is possibly undefined
// 225F3: variable 'v12' is possibly undefined
// 22628: variable 'v13' is possibly undefined
// 2265C: variable 'v14' is possibly undefined
// 22678: variable 'v15' is possibly undefined
// 22694: variable 'v16' is possibly undefined
// 226E1: variable 'v17' is possibly undefined
// 2278E: variable 'v22' is possibly undefined
// 227C7: variable 'v23' is possibly undefined
// 22919: variable 'v28' is possibly undefined
// 22A44: variable 'v33' is possibly undefined
// 22AF3: variable 'v35' is possibly undefined
// 22B41: variable 'v38' is possibly undefined
// 22C01: variable 'v43' is possibly undefined
// 22C2C: variable 'v44' is possibly undefined
// 22CF1: variable 'v50' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 192FD8: using guessed type int dword_192FD8;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 197F98: using guessed type int dword_197F98;
// 199BDE: using guessed type char byte_199BDE;
// 199CB0: using guessed type char byte_199CB0;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19ABA7: using guessed type int16_t word_19ABA7;
// 19ABA9: using guessed type int16_t word_19ABA9;
// 19ABAB: using guessed type int16_t word_19ABAB;
// 19AC35: using guessed type char byte_19AC35;
// 19AC37: using guessed type int16_t word_19AC37;
// 19AC3E: using guessed type char byte_19AC3E;
// 19AC40: using guessed type int16_t word_19AC40;
// 19ACBC: using guessed type char byte_19ACBC;
// 19ACC0: using guessed type int16_t word_19ACC0;
// 19ACE8: using guessed type int dword_19ACE8;
// 19ACEC: using guessed type int16_t word_19ACEC;


//----- (00022D57) --------------------------------------------------------
void __fastcall sub_22D57( int a1)
{
  int16_t v1; // bx
  int v2; // edx
  int v3; // eax
  int16_t m; // cx
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int16_t v8; // cx
  int n; // edx
  int v10; // esi
  int16_t v11; // dx
  int16_t v12; // bx
  int v13; // eax
  uint16_t v14; // si
  int16_t ii; // dx
  int v16; // eax
  uint16_t v17; // si
  int16_t i; // cx
  int v19; // eax
  int v20; // edx
  int16_t v21; // di
  int j; // edx
  int v23; // eax
  int16_t v24; // si
  int v25; // eax
  uint16_t v26; // dx
  int16_t k; // si
  int v28; // ecx
  int64_t v29; // rax
  uint16_t v30[16]; // [esp+0h] [ebp-28h] BYREF
  int v31; // [esp+20h] [ebp-8h]
  char v32; // [esp+24h] [ebp-4h]

  v32 = a1;
  v1 = 0;
  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    v30[v3] = 0;
    v30[v3 + 8] = -1;
  }
  while ( (int16_t)v2 < 8 );
  if ( v32 )
  {
    for ( i = 0; i < word_199998; ++i )
    {
      v19 = 3753 * i + dword_197F98;
      if ( !*(_BYTE *)(v19 + 36) )
      {
        v20 = v1;
        v30[v1++ + 8] = i;
        v30[v20] = *(_WORD *)(v19 + 166);
      }
    }
    v21 = 0;
    for ( j = 0; (int16_t)j < v1; ++j )
    {
      v23 = dword_197F98 + 3753 * (int16_t)v30[(int16_t)j + 8];
      if ( v21 < *(int16_t *)(v23 + 166) )
      {
        v31 = j;
        v21 = *(_WORD *)(v23 + 166);
      }
    }
    v24 = v31;
    v12 = v1 - 1;
    while ( v24 < v12 )
    {
      v25 = v24;
      v30[v24 + 8] = v30[v24 + 9];
      v26 = v30[++v24];
      v30[v25] = v26;
    }
    for ( k = 0; k < v12; ++k )
    {
      v28 = k;
      v29 = v21 - v30[k];
      v30[v28] = ((WORD2(v29) ^ v29) - WORD2(v29)) * ((WORD2(v29) ^ v29) - WORD2(v29));
    }
  }
  else
  {
    for ( m = 0; m < word_199998; ++m )
    {
      v5 = 3753 * m;
      if ( !*(_BYTE *)(v5 + dword_197F98 + 36) && !(uint16_t)sub_230B6(m) )
      {
        v6 = v1;
        v7 = dword_197F98;
        v30[v1++ + 8] = m;
        v30[v6] = *(_WORD *)(v7 + v5 + 166);
      }
    }
    v8 = 32000;
    for ( n = 0; (int16_t)n < v1; ++n )
    {
      v10 = 3753 * (int16_t)v30[(int16_t)n + 8];
      if ( v8 > *(int16_t *)(v10 + dword_197F98 + 166) )
      {
        v31 = n;
        v8 = *(_WORD *)(v10 + dword_197F98 + 166);
      }
    }
    v11 = v31;
    v12 = v1 - 1;
    while ( v11 < v12 )
    {
      v13 = v11;
      v30[v11 + 8] = v30[v11 + 9];
      v14 = v30[++v11];
      v30[v13] = v14;
    }
    for ( ii = 0; ii < v12; ++ii )
    {
      v16 = ii;
      v17 = (v30[ii] - v8) * (v30[ii] - v8);
      v30[v16] = v17;
    }
  }
  sub_586D4(v30, v12);
  JUMPOUT(0x23D99);
}
// 22F43: control flows out of bounds to 23D99
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;


//----- (00022F5C) --------------------------------------------------------
void __usercall sub_22F5C( int a1)
{
  int16_t v1; // bx
  int v2; // edx
  int v3; // eax
  int16_t i; // si
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int16_t v9; // si
  int16_t j; // dx
  int v11; // eax
  int16_t v12; // dx
  int16_t v13; // bx
  int v14; // eax
  uint16_t v15; // cx
  int16_t k; // dx
  int v17; // eax
  uint16_t v18; // cx
  _WORD v19[8]; // [esp+0h] [ebp-20h]
  uint16_t v20[8]; // [esp+10h] [ebp-10h] BYREF

  v1 = 0;
  v2 = 0;
  do
  {
    v3 = (int16_t)v2++;
    v20[v3] = 0;
    v19[v3] = -1;
  }
  while ( (int16_t)v2 < 8 );
  for ( i = 0; i < word_199998; ++i )
  {
    v5 = 3753 * i + dword_197F98;
    if ( !*(_BYTE *)(v5 + 36) )
    {
      v19[v1] = i;
      LOWORD(v6) = *(_WORD *)(v5 + 166);
      if ( *(_BYTE *)(v5 + 40) == 100 )
      {
        switch ( byte_199CB0 )
        {
          case 0:
            v6 = (int16_t)v6;
            v7 = 10;
            goto LABEL_8;
          case 1:
            v6 = (int16_t)v6;
            v7 = 5;
LABEL_8:
            v6 /= v7;
            break;
          case 3:
            LOWORD(v6) = v6 + (int16_t)v6 / 2;
            break;
          case 4:
            LOWORD(v6) = 3 * v6;
            break;
          default:
            break;
        }
      }
      if ( *(_BYTE *)(3753 * i + dword_197F98 + 2233) == 1 )
        LOWORD(v6) = (int16_t)v6 / 3;
      v8 = v1++;
      v20[v8] = v6;
    }
  }
  v9 = 32000;
  for ( j = 0; j < v1; ++j )
  {
    v11 = dword_197F98 + 3753 * (int16_t)v19[j];
    if ( v9 > *(int16_t *)(v11 + 166) )
    {
      a1 = j;
      v9 = *(_WORD *)(v11 + 166);
    }
  }
  v12 = a1;
  v13 = v1 - 1;
  while ( v12 < v13 )
  {
    v14 = v12;
    v19[v12] = v19[v12 + 1];
    v15 = v20[++v12];
    v20[v14] = v15;
  }
  for ( k = 0; k < v13; ++k )
  {
    v17 = k;
    v18 = (v20[k] - v9) * (v20[k] - v9);
    v20[v17] = v18;
  }
  sub_586D4(v20, v13);
  JUMPOUT(0x23D99);
}
// 230B1: control flows out of bounds to 23D99
// 197F98: using guessed type int dword_197F98;
// 199998: using guessed type int16_t word_199998;
// 199CB0: using guessed type char byte_199CB0;


//----- (000230B6) --------------------------------------------------------
int __fastcall sub_230B6( int a1)
{
  int v1; // edx
  int16_t i; // si

  v1 = 0;
  for ( i = 0; i < 36 && !(_WORD)v1; ++i )
  {
    if ( byte_19ABA5[9 * i] && byte_19ABA5[9 * i] != 3 && byte_19ABA4[9 * i] == a1 && !byte_180E84[i] )
      v1 = 1;
  }
  return v1;
}


//----- (0002310C) --------------------------------------------------------
void __fastcall sub_2310C( int a1)
{
  int16_t v2; // dx
  int16_t i; // bx
  int16_t v4; // ax
  int16_t j; // bx
  char *v6; // eax

  v2 = -1;
  for ( i = 0; v2 == -1 && i < 200; ++i )
  {
    v4 = sub_23D44(a1);
    if ( v4 != -1 && *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * v4 + 2) + 8) < 8u )
      v2 = v4;
  }
  if ( v2 == -1 )
  {
    for ( j = 0; j < word_199996 && v2 == -1; ++j )
    {
      v6 = (char *)(dword_192B18 + 361 * j);
      if ( *v6 == a1 && *(_BYTE *)(17 * *((int16_t *)v6 + 1) + dword_1930D4 + 8) < 8u )
        v2 = j;
    }
  }
  JUMPOUT(0x23D9A);
}
// 231AF: control flows out of bounds to 23D9A
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199996: using guessed type int16_t word_199996;


//----- (000231B4) --------------------------------------------------------
void __fastcall sub_231B4( int a1)
{
  int16_t v2; // dx
  int16_t i; // bx
  int16_t v4; // ax
  int16_t j; // bx
  char *v6; // eax

  v2 = -1;
  for ( i = 0; v2 == -1 && i < 200; ++i )
  {
    sub_23DA0(a1);
    if ( v4 != -1 && *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * v4 + 2) + 8) > 1u )
      v2 = v4;
  }
  if ( v2 == -1 )
  {
    for ( j = 0; j < word_199996 && v2 == -1; ++j )
    {
      v6 = (char *)(dword_192B18 + 361 * j);
      if ( *v6 == a1 && *(_BYTE *)(17 * *((int16_t *)v6 + 1) + dword_1930D4 + 8) > 1u )
        v2 = j;
    }
  }
  JUMPOUT(0x231AD);
}
// 23259: control flows out of bounds to 231AD
// 231DB: variable 'v4' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 199996: using guessed type int16_t word_199996;


//----- (0002325E) --------------------------------------------------------
void __fastcall sub_2325E( int a1)
{
  int16_t v2; // dx
  int16_t i; // bx
  int16_t v4; // ax

  v2 = -1;
  for ( i = 0; v2 == -1 && i < 200; ++i )
  {
    sub_23DA0(a1);
    if ( v4 != -1 && *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * v4 + 2) + 10) > 3u )
      v2 = v4;
  }
  JUMPOUT(0x231AD);
}
// 23272: control flows out of bounds to 231AD
// 2328D: variable 'v4' is possibly undefined
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (000232BB) --------------------------------------------------------
void __fastcall sub_232BB( int a1)
{
  int16_t v2; // dx
  int16_t i; // bx
  int16_t v4; // ax

  v2 = -1;
  for ( i = 0; v2 == -1 && i < 200; ++i )
  {
    v4 = sub_23D44(a1);
    if ( v4 != -1 && *(_BYTE *)(dword_1930D4 + 17 * *(int16_t *)(dword_192B18 + 361 * v4 + 2) + 10) < 4u )
      v2 = v4;
  }
  JUMPOUT(0x231AD);
}
// 232CF: control flows out of bounds to 231AD
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;


//----- (0002332C) --------------------------------------------------------
int __fastcall sub_2332C(int a1, int a2, int a3)
{
  int16_t v4; // dx
  int result; // eax

  switch ( (int16_t)a1 )
  {
    case 10:
      v4 = 19;
      goto LABEL_7;
    case 11:
      v4 = 20;
      goto LABEL_7;
    case 12:
      v4 = 21;
      goto LABEL_7;
    case 13:
      v4 = 22;
      goto LABEL_7;
    case 14:
      v4 = 23;
LABEL_7:
      byte_19ABA4[9 * v4] = a3;
      if ( a2 == -1 )
      {
        *(int16_t *)((char *)&word_19ABA9 + 9 * v4) = a3;
        if ( a3 == -1 )
          byte_19ABA6[9 * v4] = 20;
      }
      else
      {
        *(int16_t *)((char *)&word_19ABA7 + 9 * v4) = a2;
      }
      result = 9 * v4;
      byte_19ABA5[result] = 4;
      break;
    default:
      result = a1 - 10;
      break;
  }
  return result;
}
// 19ABA7: using guessed type int16_t word_19ABA7;
// 19ABA9: using guessed type int16_t word_19ABA9;


//----- (000233AB) --------------------------------------------------------
char __fastcall sub_233AB( int result)
{
  byte_19ACAA = 1;
  byte_19ACA9 = result;
  return result;
}
// 19ACA9: using guessed type char byte_19ACA9;
// 19ACAA: using guessed type char byte_19ACAA;


//----- (000233B8) --------------------------------------------------------
char __fastcall sub_233B8( int result)
{
  byte_19ACC5 = 1;
  byte_19ACC4 = result;
  return result;
}
// 19ACC4: using guessed type char byte_19ACC4;
// 19ACC5: using guessed type char byte_19ACC5;


//----- (000233C5) --------------------------------------------------------
char __fastcall sub_233C5( int result)
{
  byte_19ACCE = 1;
  byte_19ACCD = result;
  return result;
}
// 19ACCD: using guessed type char byte_19ACCD;
// 19ACCE: using guessed type char byte_19ACCE;


//----- (000233D2) --------------------------------------------------------
char __fastcall sub_233D2( int result, int a2)
{
  byte_19ACD7 = 1;
  byte_19ACD6 = result;
  word_19ACD9 = a2;
  return result;
}
// 19ACD6: using guessed type char byte_19ACD6;
// 19ACD7: using guessed type char byte_19ACD7;
// 19ACD9: using guessed type int16_t word_19ACD9;


//----- (000233E6) --------------------------------------------------------
char __fastcall sub_233E6( int result, int a2)
{
  byte_19ACE0 = 1;
  byte_19ACDF = result;
  word_19ACE2 = a2;
  return result;
}
// 19ACDF: using guessed type char byte_19ACDF;
// 19ACE0: using guessed type char byte_19ACE0;
// 19ACE2: using guessed type int16_t word_19ACE2;


//----- (000233FA) --------------------------------------------------------
bool sub_233FA()
{
  return byte_19ABF6 == 2 || byte_19ABF6 == 4 || byte_19ABF6 == 6;
}
// 19ABF6: using guessed type char byte_19ABF6;


//----- (0002341E) --------------------------------------------------------
bool __fastcall sub_2341E( int a1)
{
  return (byte_19AC86 == 2 || byte_19AC86 == 4 || byte_19AC86 == 6)
      && *(uint8_t *)(dword_1930D4 + 17 * *(int16_t *)(361 * a1 + dword_192B18 + 2) + 2) == word_19AC88;
}
// 192B18: using guessed type int dword_192B18;
// 1930D4: using guessed type int dword_1930D4;
// 19AC86: using guessed type char byte_19AC86;
// 19AC88: using guessed type int16_t word_19AC88;


//----- (0002346E) --------------------------------------------------------
bool __fastcall sub_2346E( int a1)
{
  return (byte_19AC23 == 2 || byte_19AC23 == 4 || byte_19AC23 == 6)
      && (((int)*(uint8_t *)(dword_19306C + 113 * word_19AC25 + 56) >> a1) & 1) != 0;
}
// 19306C: using guessed type int dword_19306C;
// 19AC23: using guessed type char byte_19AC23;
// 19AC25: using guessed type int16_t word_19AC25;


//----- (000234B8) --------------------------------------------------------
bool __fastcall sub_234B8( int a1)
{
  return (byte_19AC35 == 2 || byte_19AC35 == 4 || byte_19AC35 == 6) && a1 == word_19AC37;
}
// 19AC35: using guessed type char byte_19AC35;
// 19AC37: using guessed type int16_t word_19AC37;


//----- (000234E5) --------------------------------------------------------
bool sub_234E5()
{
  return byte_19AC8F == 2 || byte_19AC8F == 4 || byte_19AC8F == 6;
}
// 19AC8F: using guessed type char byte_19AC8F;


//----- (00023509) --------------------------------------------------------
bool __fastcall sub_23509( int a1)
{
  return (byte_19AC3E == 2 || byte_19AC3E == 4 || byte_19AC3E == 6) && a1 == word_19AC40;
}
// 19AC3E: using guessed type char byte_19AC3E;
// 19AC40: using guessed type int16_t word_19AC40;


//----- (00023536) --------------------------------------------------------
bool __fastcall sub_23536( int a1)
{
  return (byte_19ABB7 == 2 || byte_19ABB7 == 4 || byte_19ABB7 == 6) && a1 == word_19ABB9;
}
// 19ABB7: using guessed type char byte_19ABB7;
// 19ABB9: using guessed type int16_t word_19ABB9;


//----- (00023563) --------------------------------------------------------
void sub_23563()
{
  int16_t v0; // di
  int v1; // eax
  int v2; // esi
  int16_t i; // bx
  uint8_t v4; // al
  int16_t v5; // ax
  int16_t k; // dx
  int v7; // ecx
  int v8; // ecx
  int16_t v9; // bx
  int16_t j; // dx
  int64_t v11; // rax
  _WORD v12[8]; // [esp+0h] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int16_t v15; // [esp+18h] [ebp-4h]

  if ( word_19ACB7 > 2 )
    goto LABEL_51;
  v0 = word_19999A / 2;
  v1 = 0;
  do
  {
    v2 = (int16_t)v1++;
    v12[v2] = 0;
  }
  while ( (int16_t)v1 < 8 );
  for ( i = 0; ; ++i )
  {
    if ( i >= word_19999A )
    {
      v9 = 0;
      for ( j = 0; j < word_199998; ++j )
      {
        if ( v9 < (int16_t)v12[j] )
        {
          v15 = j;
          v9 = v12[j];
        }
      }
      v11 = v0 * ((int16_t)(word_19ACB7 + 1) + 1);
      if ( v9 >= (int)(v11 - (__CFSHL__(HIDWORD(v11), 2) + 4 * HIDWORD(v11))) >> 2
        || word_19ACB7 == 2 && v9 >= v0 - 2 && v9 < v0 && !word_19A0E2 )
      {
        byte_19ACB3 = 6;
        ++word_19ACB7;
        word_19ACB5 = v9;
        byte_19ACB2 = v15;
      }
LABEL_51:
      JUMPOUT(0x23D99);
    }
    v4 = *(_BYTE *)(dword_19306C + 113 * i + 56);
    if ( v4 < 8u )
    {
      if ( v4 < 2u )
      {
        if ( v4 == 1 )
        {
          v5 = 0;
          goto LABEL_29;
        }
      }
      else
      {
        if ( v4 <= 2u )
        {
          v5 = 1;
          goto LABEL_29;
        }
        if ( v4 == 4 )
        {
          v5 = 2;
          goto LABEL_29;
        }
      }
    }
    else
    {
      if ( v4 <= 8u )
      {
        v5 = 3;
        goto LABEL_29;
      }
      if ( v4 < 0x20u )
      {
        if ( v4 == 16 )
        {
          v5 = 4;
          goto LABEL_29;
        }
      }
      else
      {
        if ( v4 <= 0x20u )
        {
          v5 = 5;
          goto LABEL_29;
        }
        if ( v4 >= 0x40u )
        {
          if ( v4 <= 0x40u )
          {
            v5 = 6;
            goto LABEL_29;
          }
          if ( v4 == 0x80 )
          {
            v5 = 7;
            goto LABEL_29;
          }
        }
      }
    }
    v5 = -1;
LABEL_29:
    if ( v5 != -1 )
    {
      v14 = 0;
      for ( k = 0; k < 5; ++k )
      {
        v13 = 113 * i + dword_19306C;
        v7 = *(int16_t *)(v13 + 2 * k + 74);
        if ( v7 != -1 )
        {
          v8 = *(int16_t *)(17 * v7 + dword_1930D4);
          if ( v8 != -1 && !*(_BYTE *)(361 * v8 + dword_192B18 + 6) )
            v14 = 1;
        }
      }
      if ( (_WORD)v14 == 1 )
        ++v12[v5];
    }
  }
}
// 2373A: control flows out of bounds to 23D99
// 192B18: using guessed type int dword_192B18;
// 19306C: using guessed type int dword_19306C;
// 1930D4: using guessed type int dword_1930D4;
// 199998: using guessed type int16_t word_199998;
// 19999A: using guessed type int16_t word_19999A;
// 19A0E2: using guessed type int16_t word_19A0E2;
// 19ACB2: using guessed type char byte_19ACB2;
// 19ACB3: using guessed type char byte_19ACB3;
// 19ACB5: using guessed type int16_t word_19ACB5;
// 19ACB7: using guessed type int16_t word_19ACB7;


