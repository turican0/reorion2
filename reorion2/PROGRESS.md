# Orion - postupna konverze z dekompilace do citelneho kodu

## Rozsah projektu (dulezite pro planovani)

Puvodni dekompilace ma **~5098 funkci** v **302 053 radcich** rozdelenych do
26 souboru `orion_part_NN.c` + `orion_data.c`. To neni neco, co jde prevest
najednou - je to viceletova rucni prace i pro tym lidi. Tenhle dokument slouzi
jako pametova stopa mezi jednotlivymi sezenimi: co uz je hotovo, jaka je
konvence a co je dalsi rozumny krok.

Realisticky postup: brat to volani po volani od `GameMain_10057` (byvale
`main__0`) smerem dolu grafem volani, funkci po funkci, a prubezne
vyclenovat DOS/BIOS zavislosti do `src/port/`.

## Adresarova struktura

```
reorion2.vcxproj       - aktualizovano na novou strukturu (src/game, src/port)
src/
  reorion2.cpp          - novy vstupni bod, inicializuje port vrstvu, pak vola GameMain_10057
  game/                 - puvodni dekompilovane .c soubory (orion_part_NN.c, orion_data.c,
                           orion_common.h, defs.h, hexrays_compat.h, link_stubs.c)
                           Postupne prejmenovavane funkce/promenne, ale porad C, porad
                           jeden velky preklad - nerozdelujeme soubory, dokud neni jasne
                           kam funkce logicky patri (viz zadani).
  port/
    port_dos.h/.cpp      - terminal emulace + budouci DOS/BIOS int 21h nahrady
    port_vga.h/.cpp      - SDL3 video (VGA rezim 13h, 320x200x8bpp + paleta)
    port_sound.h/.cpp    - SDL3 audio (Sound Blaster / OPL nahrada)
    port_mouse.h/.cpp    - SDL3 mys (nahrada int 33h)
tools/
  rename_symbol.py       - hromadne bezpecne prejmenovani symbolu napric src/game/*.c/*.h
  renames_wave01.txt     - mapa prejmenovani pro aktualni vlnu (viz nize)
```

## Konvence pojmenovani (dle zadani)

- Funkce: `PascalCase_ADRESA`, napr. `sub_107E6` -> `ParseCommandLine_107E6`.
  Adresa (bez `0x`, velkymi hex znaky jak byla v puvodnim `sub_` jmenu) se
  necha jako soucast jmena - je to jedina spolehliva vazba na puvodni binarku
  a na Hex-Rays komentare `//----- (00010057) -----`.
- Promenne: `camelCase_ADRESA`, napr. `word_184374` -> `flagMemPoolReady_184374`.
  **Prejmenovavame jen promenne, jejichz vsechna pouziti uz jsme procetli** -
  globalni promenne pouzivane na desitkach mist napric cele hrou se
  prejmenuji az v ramci vlny, ktera je vsechny pokryje, jinak vznika riziko
  nekonzistentniho stavu.
- Nove soubory `port_*.cpp`: normalni citelny C++ styl bez adresove pripony -
  je to nova, ne dekompilovana logika.

## Pouziti `tools/rename_symbol.py`

Skript prejmenuje symbol **ve vsech** `.c`/`.h` v `src/game/` najednou (funkce
+ deklarace v `orion_common.h` + vsechna volani), takze se nikdy nerozjede
build kvuli zapomenutemu vyskytu:

```
python3 tools/rename_symbol.py sub_ABCDE NoveJmeno_ABCDE
# nebo hromadne z souboru se seznamem dvojic:
python3 tools/rename_symbol.py --map tools/renames_wave02.txt
```

Pred kazdym prejmenovanim je potreba si projit **vsechna** volani dane
funkce (ne jen prvni, ktere najdes) - viz ponauceni nize.

## DULEZITE PONAUCENI Z VLNY 01 - `sub_FE8BE`

Puvodne jsem `sub_FE8BE` pojmenoval `ProcessStartupArgs_FE8BE`, protoze v
tele `GameMain_10057` vypadala jako zpracovani argumentu prikazove radky.
Po prejmenovani se ale ukazalo, ze se stejna funkce vola **701x** po celem
projektu s uplne jinymi typy argumentu (retezcove konstanty, cisla, offsety
do bufferu) - takze jde o nejakou obecnou sdilenou pomocnou funkci (mozne
hypotezy: casovaci/tick handler, generic I/O primitivum), ne o nic
specifickeho pro start hry. Prejmenovani jsem vratil zpet na `sub_FE8BE`.

**Pravidlo do budoucna:** pred prejmenovanim vzdy zkontrolovat pocet a
kontext VSECH volani (`grep -n "\bjmeno(" src/game/*.c | wc -l` a par
namatkovych ukazek), ne jen misto, kde jsme funkci poprvé potkali. Pokud se
funkce vola desitky/stovky krat s nesourodymi argumenty, je to pravdepodobne
sdileny primitiv a zaslouzi si hlubsi analyzu pred pojmenovanim (nebo aspon
nazev s jasnym "generic"/"dispatch" charakterem misto konkretniho ucelu).

## Hotovo - vlna 01: `GameMain_10057` a jeho primo volane funkce

Prejmenovano konzistentne v celem `src/game/` (overeno `gcc -fsyntax-only`):

| Nove jmeno | Puvodni | Ucel (zjisteno z kodu) |
|---|---|---|
| `GameMain_10057` | `main__0` | Vstupni bod hry (`__noreturn`) |
| `ParseCommandLine_107E6` | `sub_107E6` | Zpracovava argv: `/nosaves=`, `/stats=`, `/net`, `/seed`, `/nolog`, `/quickstart`, `SAVESET`, `MAPS` |
| `MarkMemPoolReady_110B34` | `sub_110B34` | Nastavi `flagMemPoolReady_184374 = 1` |
| `IsMemPoolReady_110B5C` | `sub_110B5C` | Vrati `flagMemPoolReady_184374` |
| `PoolAlloc_110B89` | `sub_110B89` | Alokace ze zonoveho alokatoru (vlastni heap nad `nmalloc`) |
| `FindMoxSetPath_1114D7` | `sub_1114D7` | Hleda cestu ke config souboru (env promenna / vychozi) |
| `LoadSettingsFile_11C39` | `sub_11C39` | Nacte `MOX.SET` (553 bajtu nastaveni) |
| `LoadOrResetSettings_12227` | `sub_12227` | Zkusi nacist `MOX.SET`, pri selhani/spatne verzi zavola reset na vychozi |
| `InitDefaultSettings_127E1` | `sub_127E1` | Vychozi hodnoty nastaveni + nahodne session ID `"MOX-%d"` |
| `LoadLanguageSetting_10C2F` | `sub_10C2F` | Cte `language.ini`; pozn.: v kodu je zjevny bug/quirk - `byte_199CAE` se na konci vzdy prepise na 0, ponechano 1:1 jak v originalu |
| `GetFontsLbxName_7AA33` | `sub_7AA33` | Podle jazyka vybere `fonts{g,f,s,i}.lbx`, jinak vychozi `fonts.lbx` |
| `SelectResourceModule_111959` | `sub_111959` | Registruje aktivni resource modul (`dword_184398`/`dword_184394`) |
| `RunGameAndExit_113D47` | `sub_113D47` | `__noreturn` - realna hlavni smycka/ukonceni, registruje `atexit` |

`sub_FE8BE` zustava **nepremenovana** - viz ponauceni vyse, potrebuje vlastni
hlubsi analyznu vlnu (je volana z `GameMain_10057` i ze stovek jinych mist).

Take hotovo:
- `src/reorion2.cpp` prepsan tak, aby volal `GameMain_10057` a inicializoval
  port vrstvu (`Port::Dos`, `Port::Vga`, `Port::Sound`, `Port::Mouse`) driv,
  nez se hra spusti - presne v poradi, v jakem to cekal puvodni DOS/BIOS.
- `src/port/port_{dos,vga,sound,mouse}.{h,cpp}` - funkcni kostry na SDL3
  (video: framebuffer 320x200x8bpp + paleta jako rezim 13h; zvuk: audio
  stream; mys: SDL_GetMouseState; DOS: terminal emulace + zrcadleni na
  stdout). Zatim nejsou napojene na zadnou konkretni dekompilovanou funkci -
  to prijde, az v dalsich vlnach narazime na funkce, ktere primo sahaji na
  VGA pamet / porty zvukove karty / int 33h.
- `reorion2.vcxproj` prepsan na novou strukturu slozek + pridane `port_*`
  soubory. **SDL3 include/lib cesty jeste nejsou v projektu nastavene** -
  je potreba dodat SDL3 SDK a nastavit `AdditionalIncludeDirectories` /
  `AdditionalLibraryDirectories` / `AdditionalDependencies` (SDL3.lib) v
  `ItemDefinitionGroup`, to jsem nemenil, protoze nevim, kam SDL3 na tvem
  stroji umistis.

## Hotovo - vlna 02: oprava RTC chyby v `ParseCommandLine_107E6` + `port_memory`

### Oprava "Run-Time Check Failure #3" v `ParseCommandLine_107E6`

Puvodni `void sub_107E6()` pouzivala dve promenne (`v13`, `v14`), ktere nikde
nebyly nastaveny - Hex-Rays k nim psal komentar "possibly undefined" a MSVC
run-time check na to spadl (viz obrazek v zadani - `v14` pouzita bez
inicializace na radku 349). Skutecna prezina: klasicky Hex-Rays artefakt, kdy
volajici (`GameMain_10057`) preda `argc`/`argv` dal ve stejnych registrech, ve
kterych je sam prijal - zadna instrukce `MOV` neexistuje, takze to
dekompilator nerozpoznal jako parametr. Hodnoty tam ale realne jsou.

**Reseni:** `ParseCommandLine_107E6` ted ma explicitni signaturu
`(int argCount_a1, char** argValues_a2)` a volajici (`GameMain_10057`) ji
predava sve vlastni `a1`/`a2` (ktere jsou v tu chvili porad nedotcene
argc/argv). Chovani programu se nezmenilo - jen se zpristupnily hodnoty,
ktere v assembly vzdy byly, jen je pseudokod neuznaval za parametr.

Zaroven jsem v ramci teto funkce:
- prejmenoval vsechny lokalni promenne na logicke nazvy (`argIndex_v1`,
  `saveSlotNumber_v2`, `currentArg_v17`, `messageBuffer_v15`, ...),
- **slouceil zbytecne duplicity** beze zmeny chovani: `v11`+`v12` (dve
  identicka volani cisteho getteru `sub_F4B81()`) -> jedna promenna
  `gameFlagsTable_v11`; `v3`/`v4`/`v5` (tri kopie stejne hodnoty v ruznych
  sirkach) -> `saveSlotNumber_v2` s explicitnim `(int16_t)` castem tam, kde
  byl puvodne uzsi typ - vysledek je bit-identicky, jen bez nadbytecnych
  promennych,
- oznacil `DECOMP_TODO` komentari mista, kde jsem nazev/vyznam nemohl
  bezpecne overit (`cheatFlagsBuffer_v0` - ukazatel pocitany vyrazem mimo
  vsechny pojmenovane lokalni promenne; `logMessagePacked_v8` - HIDWORD/
  LODWORD trik simulujici 64bit navratovou hodnotu `sprintf`). U obojiho
  jsem **nemenil puvodni vypocet**, jen popsal, co se deje a proc.
- rozpoznal, ze jde o parsovani cheat/debug prepinacu prikazove radky hry
  **Master of Orion** (retezce `NOWH`, `NOBH`, `NOORION`, `GOODSTART`,
  `RICHSTART`, `NOSPLINT`, `PICKS=`, `PLANETS=`, `MONSTERS=`, `SAVESET=`
  atd.) - potvrzuje to i `ORIONCD.INI` v `sub_10A72` o kousek dal v souboru.

Overeno `gcc -fsyntax-only` na celem `src/game/` - zadne nove chyby oproti
puvodnimu stavu.

**POZOR - dalsi vyskyt stejne tridy chyby, zatim nereseno:** v `GameMain_10057`
je `int v3; // eax` pouzita v `sub_FE8BE(v3, a1, a2, a3)` bez predchoziho
nastaveni - stejny artefakt jako u `v13`/`v14`. Nejpravdepodobnejsi hypoteza:
`v3` je navratova hodnota `ParseCommandLine_107E6` (v assembly zjevne neco
vraci v EAX, i kdyz ji Hex-Rays oznacil jako `void`) - ale to je zatim jen
hypoteza a NENI overena. Necham to zaverne vyresit spolu s analyzou
`sub_FE8BE` (viz "Dalsi krok" nize), aby se nepredbihalo stejnou chybou jako
u prvniho pokusu o `sub_FE8BE` v prvni vlne.

### Novy `src/port/port_memory.{h,cpp}`

Podle upresneneho zadani - misto puvodniho DOS zpusobu (hledani volneho
useku pameti, prace se segment:offset adresami, zonovy alokator kolem
`PoolAlloc_110B89`) pouziva port vrstva bezne `malloc`/`free` (pres tenkou
`Port::Memory::Alloc/Free` obalku), ktera navic:
- eviduje vsechny zive alokace (adresa, velikost, volitelny popisek),
- pri `Shutdown()` nahlasi na stderr vse, co zustalo neuvolnene (jednoduchy
  leak-detektor bez zavislosti na externich nastrojich),
- nabizi sablonovy `AllocArray<T>()` a doporuceni pouzivat pro VESKEROU
  novou (neportovanou 1:1) logiku radeji `std::unique_ptr`/`std::vector`
  (RAII) - primy `Alloc`/`Free` je hlavne prechodovy most pro postupnou
  konverzi puvodni DOS pool-alokace.
- Napojeno na `reorion2.cpp` (`Port::Memory::Init()` se vola jako uplne prvni
  krok, `Shutdown()` na konci - i kdyz `GameMain_10057` je `__noreturn`, takze
  se tam beh realne nikdy nevrati; az najdeme, kudy hra doopravdy konci
  [pravdepodobne uvnitr `RunGameAndExit_113D47`], napojime tam radny
  leak-report misto spolehani na nedosazitelny kod).
- **Zatim NENI napojeno na `PoolAlloc_110B89`** - to je zamerne, vyzaduje to
  drivejsi pochopeni, jak presne se zonovy alokator v puvodnim kodu pouzival
  (kolik ruznych "poolu" existuje, jestli se nekde spolehalo na konkretni
  layout pameti), aby prepojeni na `malloc`/`free` nezmenilo chovani.
- `reorion2.vcxproj` aktualizovan o nove soubory.

## Hotovo - vlna 03: oprava LNK2005/LNK1169 (fprintf uz definovana dvakrat)

Po pridani SDL3 zavislosti (a diky `port_memory.cpp`, ktery pouziva
`<cstdio>`) se do projektu poprve realne slinkuje skutecna CRT knihovna.
`src/game/link_stubs.c` ale odjakziva obsahoval VLASTNI no-op nahrady pro
`fprintf`, `printf`, `sprintf` a `fscanf` (`int fprintf(void){return 0;}`
apod.) - puvodne vznikly jen proto, aby se dekompilovany kod vubec dal
slinkovat, kdyz zadna realna CRT knihovna jeste pripojena nebyla. Ve chvili,
kdy se realna CRT pripoji, vznikne "multiply defined symbol"
(LNK2005/LNK1169) presne podle chybove hlasky v zadani.

**Dulezite:** tyhle 4 funkce NEJSOU nepouzivane mrtve stuby - dekompilovany
kod je genuinne vola se skutecnymi argumenty na **1018 mistech** (napr. AIL
debug log v `orion_part_21.c` pres `fprintf(dword_1C0E50, ...)`, kde
`dword_1C0E50` je puvodni `FILE*` cachovane jako cislo). Puvodni no-op stub
tedy tyhle volani tise "spolykal" (vzdy vratil 0, nic nezapsal) - odstranenim
stubu se ted linkuje SKUTECNA CRT implementace, coz je blize puvodnimu chovani
hry, ne dal od nej.

**Reseni:** v `link_stubs.c` odstraneny ctyri kolidujici definice
(`fprintf`, `printf`, `sprintf`, `fscanf`), nahrazeny komentarem
vysvetlujicim proc. **Zkousel jsem** k tomu jeste pridat `#include <stdio.h>`
do `hexrays_compat.h`, aby mely spravny prototyp všude - ale to zpusobilo
NOVOU vlnu chyb (`fopen`/`fseek`/`fgets`/`fgetc`/`ftell` volane v
dekompilovanem kodu s jinym poctem argumentu, nez maji skutecne CRT
prototypy - stejna trida Hex-Rays artefaktu jako u `fprintf` v puvodni
signature, jen se to bez prototypu netestovalo). **Vraceno zpet** - tyhle
funkce zustavaji zamerne bez explicitniho prototypu (implicitni K&R
deklarace), protoze na cdecl ABI to funguje i s "spatnym" poctem argumentu
v deklaraci (viz komentar primo v `hexrays_compat.h`). Overeno
`gcc -fsyntax-only` na celem `src/game/` - stav chyb stejny jako pred touto
vlnou (jen puvodni pre-existujici `exit`/`calloc` nesrovnalosti).

**Ponauceni do budoucna:** kdykoliv `link_stubs.c` hlasi LNK2005 pro nejake
jmeno, prvni otazka je "je to skutecna standardni/CRT funkce, nebo DOS/Watcom
specificka vec (jako `nmalloc`, `memavl`, `int386`)?" - u prvniho pripadu
stub jen odstranit (a poznamkovat proc), u druheho nechat, protoze modernim
linkerem/CRT se stejne nikdy neuspokoji.

1. Analyzovat `sub_FE8BE` poradne - projit reprezentativni vzorek z 701
   volani, zjistit skutecny ucel, pak teprve prejmenovat. Soucasne overit
   hypotezu o `v3` v `GameMain_10057` (viz vyse).
2. Pokracovat grafem volani z `RunGameAndExit_113D47` (hlavni smycka) a
   z volanych funkci uvnitr `ParseCommandLine_107E6` (`sub_F4FD5`,
   `sub_F4B81`, `sub_10A0E`, `sub_10E2F`, `sub_11F11`, `sub_126487`) - to
   je prirozene pokracovani "shora dolu" od vstupniho bodu. `sub_F4B81`
   (vraci `&unk_1784DD`) je dobry kandidat na vytknuti struktury - pouziva
   se s fixnimi offsety (610, 621, 712, 721, 732), takze jde pravdepodobne
   o tabulku nastaveni/priznaku hry.
3. Az narazime na prvni funkci, ktera zjevne odpovida VGA/zvuku/mysi/DOS
   sluzbam, napojit ji na prislusny `port_*.cpp` a smazat puvodni primy
   pristup na porty/pamet. Totez pro `PoolAlloc_110B89` -> `port_memory`.
