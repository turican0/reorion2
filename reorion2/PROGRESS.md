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

## Hotovo - vlna 04: oprava LNK2019/LNK2001 (fprintf/printf/sprintf/fscanf nevyresene)

**Muj chyba minule:** poslal jsem cely `reorion2.vcxproj` ze sve kopie, cimz
jsem prepsal tvoje rucne pridane SDL3 cesty (`third_party\SDL3\include`,
`third_party\SDL3\lib\x86`/`x64`) a `stdcpp17`. **Od tohoto bodu dal posilam
zmeny ve vcxproj jen jako diff/instrukci, ne cely soubor** - vzdy vychazim
z posledni verze, kterou mi poslete, ne ze sve stare kopie.

**Novy problem:** po odstraneni falesnych stubu `fprintf`/`printf`/`sprintf`/
`fscanf` z `link_stubs.c` (vlna 03) se objevily `LNK2019`/`LNK2001`
"unresolved external symbol" - misto duplicity ted symboly chybi uplne.

**Priciha:** protoze `hexrays_compat.h` zamerne NEobsahuje `<stdio.h>` (viz
vlna 03 - jinak by se rozbily `fopen`/`fseek`/`fgets` volane s jinym poctem
argumentu), kompiluje se `printf`/`fprintf`/`sprintf`/`fscanf` jako stara
implicitni (K&R) deklarace bez prototypu. Moderni Windows SDK/UCRT ale
"holy" `printf`/`sprintf`/`fprintf`/`fscanf` symboly (bez prototypu z
`<stdio.h>`) neexportuje primo z `ucrt.lib` - tyhle funkce jsou v UCRT
implementovany jako inline wrappery nad `__stdio_common_vfprintf` definovane
primo v hlavicce `<stdio.h>`. Kdyz se `<stdio.h>` nevlozi (jako u nas),
kompilator vygeneruje volani na "holy" jmeno symbolu, ktere ocekava STAROU
knihovnu `legacy_stdio_definitions.lib` - tu Microsoft prave pro tenhle
scenar (stary/K&R kod bez prototypu) do Windows SDK prida.

**Reseni:** pridano `legacy_stdio_definitions.lib` do `AdditionalDependencies`
ve vsech 4 konfiguracich (`Debug|Win32`, `Release|Win32`, `Debug|x64`,
`Release|x64`) v `reorion2.vcxproj`, hned za `SDL3.lib;`. Zadna jina zmena
v projektu - overeno diffem oproti tvemu nahranemu souboru.

**Dodatek (stale vlna 04):** po pridani `legacy_stdio_definitions.lib` se
objevilo jeste `LNK2005: vsprintf already defined in link_stubs.obj` -
presne stejna trida chyby, jen jsem `vsprintf` pri puvodnim gr epovani
prehledl (hledal jsem `[vf]?printf`/`[vf]?scanf`, ale ne uplny vsprintf tvar
zvlast). Odstranen i tenhle stub (opet: pouziva se genuinne, `orion_part_12.c`,
`orion_part_21.c`, `orion_part_24.c`). Kvuli tomuhle prehlednuti jsem navic
udelal siroky sken VSECH ~89 zbylych stubu v `link_stubs.c` proti seznamu
bezne CRT funkce (printf/scanf rodina, malloc/free, string.h, stdio soubory,
time.h, atd.) - zadny dalsi kolidujici nazev se nenasel; vse, co zbylo, je
bud DOS/Watcom specificke (`int386`, `dos_getvect`, `_DOS4G_hook_init`,
`memavl`, `nosound`...) nebo neoznacene `sub_XXXXX`/`nullsub_N` placeholdery,
ktere s modernim CRT/SDL3 kolidovat nemohou.

## Hotovo - vlna 05: oprava padu v `MarkCheatPatternFlag_F4FD5` (`sub_F4FD5`)

**Prvni pad (z obrazku v zadani):** stejny druh artefaktu jako u
`ParseCommandLine_107E6` ve vlne 02, jen jinde. Puvodni kod volal `strstr`
pres pretypovany ukazatel na funkci s JEDINYM parametrem:
```c
result = ((int (__fastcall *)(int))strstr)(a2 + 34);
```
`strstr` ale potrebuje DVA parametry. Puvodni Watcom kod spolehal na to, ze
vzor (`a1`) uz sedi ve spravnem registru z doby, kdy byla funkce zavolana -
zadna instrukce pro jeho predani nebyla treba. Po prekompilovani modernim
kompilatorem (jiny stack frame, jine registry) uz to neplati -> cteni z
nesmyslne adresy -> Access Violation presne podle obrazku.

**Druhy, hlubsi problem (proc to vubec padalo NA SPRAVNEM MISTE):** druhy
parametr (`a2 + 34`) byl pocitany v `ParseCommandLine_107E6` vyrazem
`&stackAnchor_v16 - 67` (viz puvodni DECOMP_TODO z vlny 02) - vyraz zavisly
na PRESNEM stack frame puvodniho Watcom prekladace. Po prekompilovani uz
tenhle vypocet vede do nesmyslne pameti bez ohledu na pocet parametru
`strstr`. Presny puvodni bytovy posun se neda bez binarky/disassembly
overit, ale funkcne je jednoznacne, ze `MarkCheatPatternFlag_F4FD5` ma -
stejne jako vsech pet sousednich `strstr(currentArg_v17, ...)` kontrol ve
stejne smycce v `ParseCommandLine_107E6` - hledat vzor v PRAVE ZPRACOVAVANEM
ARGUMENTU prikazove radky. Cela nebezpecna `cheatFlagsBuffer_v0`/
`stackAnchor_v16` konstrukce byla odstranena, vsech 13 volani
`MarkCheatPatternFlag_F4FD5` v `ParseCommandLine_107E6` ted primo predava
`currentArg_v17`.

**Treti problem, ktery by se projevil hned pri dalsi iteraci:** `JUMPOUT`
je v `hexrays_compat.h` definovany jako NO-OP (viz komentar tam - "Hex-Rays
nedokazal prevest control-flow, funkci je nutne dohledat rucne v IDA"). V
`ParseCommandLine_107E6` byl `JUMPOUT(0x103DF)` na miste, kam se ma skocit,
kdyz dojdou vsechny argumenty bez nalezeni `/saveset` - jako NO-OP kod bez
navratu SPADL DAL na `strcpy(currentArg_v17, argValues_a2[argIndex_v1])` s
indexem == `argc`, tedy `argv[argc]`, ktere je dle standardu vzdy `NULL` ->
`strcpy(dest, NULL)` je jisty pad. Puvodni komentar disassembly
("control flows out of bounds to 103DF") + fakt, ze cil lezi MIMO
rozpoznane telo funkce, odpovida tomu, ze to byl skok primo na
epilog/return teto (void) funkce. Nahrazeno primym `return;`.

**Ctvrty úklid (stejna vlna):** `goto LABEL_26;`/`LABEL_26:` pouzite jen na
jednom miste (kdyz argument obsahuje `aDate` vzor) nahrazeno primym
zavolanim `sub_126487(...)` + `return;` - stejne chovani, bez goto/navesti.
Vsechny zbyvajici `((int (__fastcall *)(char *, char *))strstr)(...)`
pretypovani v teto funkci nahrazena primym `strstr(...)` (bezpecne - na
rozdil od `MarkCheatPatternFlag_F4FD5` mely spravny pocet parametru,
pretypovani bylo jen dekompilacni sum).

**`MarkCheatPatternFlag_F4FD5` samotna:** odstraneno `__usercall`, parametry
prejmenovany a spravne otypovany na `char*`. Zapis priznakoveho bajtu hned
za koncem vzoru v pameti (viz DECOMP_TODO primo u funkce) ZUSTAL zachovany
1:1 - je to krehky trik zavisly na poradi globalnich promennych v pameti
(potvrzeno v `orion_data.c`, napr. za `aNowh` nasleduje samostatny
`byte_1783D3`), ktery moderni linker negarantuje, ale nahrazeni radnou
strukturou vyzaduje napred zjistit vyznam KAZDEHO takto ulozeneho priznaku
(zejmena tech uvnitr `GetGameFlagsTable_F4B81` tabulky na offsetech
610/621/712/721/732) - odlozeno na pozdejsi vlnu, kdyz uz to bude jasne.
Navratova hodnota zmenena z puvodniho "raw pointer truncated to int" na
explicitni `strstr(...) != NULL` (0/1) - na 64bit sestaveni by orezani
ukazatele na `int` bylo samo o sobe UB/nespolehlive; vsechna volajici mista
pouzivaji navratovou hodnotu jen jako pravda/nepravda, takze to nic nemeni.

`sub_F4B81` (getter spolecne tabulky nastaveni) prejmenovan na
`GetGameFlagsTable_F4B81` - na rozdil od drivejsi chyby se `sub_FE8BE`
(vlna 01) tady overilo, ze funkce je VSUDE volana konzistentne bez
parametru (24 volani v 5 souborech) - zadne zneklidnujici nesrovnalosti
jako u `sub_FE8BE`, takze prejmenovani je bezpecne.

Overeno `gcc -fsyntax-only` na celem `src/game/` - zadne nove chyby.

### DULEZITE - systemove riziko: `JUMPOUT` je VSUDE no-op

Jen v `orion_part_01.c` je JESTE 43 dalsich vyskytu `JUMPOUT(...)`, ktere
jsou VSECHNY momentalne no-op (viz `hexrays_compat.h`). Kazdy z nich je
potenacialni "tichy pad podobny tomu, co jsme prave opravili" - misto skoku
tam, kam mel puvodni kod skocit, kod proste spadne dal na dalsi radek. Napric
CELYM projektem (26 souboru) jich bude pravdepodobne mnohem vic. **Tohle
neni izolovany bug, je to systemovy vzor** - kazdy JUMPOUT je potreba projit
jednotlive (stejnym zpusobem jako ten v `ParseCommandLine_107E6`: zjistit,
kam cilova adresa smeruje vzhledem k rozpoznanemu telu funkce, a podle toho
usoudit, jestli jde o `return`, `break`, `continue` nebo neco jineho) - to
je prace na mnoho dalsich vln, ne neco, co jde udelat hromadne/automaticky.

## Hotovo - vlna 06: loc_63FFB, port_memory (malloc/free/nmalloc), port_file

### 1) `loc_63FFB` - overeno v asm, opraveno

Puvodni `(int)&loc_63FFB + 5` vypadalo jako smysluplna adresa. Podle
`Orion2_exe.asm` je `loc_63FFB` navesti UPROSTRED funkce `sub_63FF0`
(presne 5 bajtu za jejim zacatkem), a "+5" z toho vede jeste 5 bajtu dal -
doprostred operandu nasledujici instrukce, na posledni bajt 4bajtove
adresy `dword_192FD8`. To neni zadny smysluplny kod/data cil. Jde o
typicky IDA false-positive: puvodni C kod mel proste 32bit konstantu
`0x64000` (= `0x63FFB + 5`, overeno hex souctem), ale protoze tahle
hodnota nahodou padne do adresniho rozsahu programu, IDA ji automaticky
prevedla na "offset + delta" misto prosteho cisla. `PoolAlloc_110B89`
bere prvni parametr jako POCET BAJTU (overeno v jeho definici - pocita
`4*(a1>>2)+4`, alokuje `+12` bajtu hlavicky, uklada `a1` do hlavicky jako
velikost) - `0x64000` (400 KB, pekle kulate cislo) je smysluplna velikost
jednorazoveho pool bufferu. Uzivatelova drivejsi rucni oprava pouzivala
desitkove `64000` (misto hex `0x64000`, tedy ~6.4x mensi hodnotu) -
opraveno na spravnou hex konstantu.

Mimochodem take opraven vedlejsi pre-existujici problem: `int v3=0;`
(uzivatelova docasna oprava puvodne neinicializovane promenne) ponechano
funkcne, jen doplnen komentar, ze presny puvodni vyznam je porad
nedoreseny (viz "dalsi krok").

**Vedlejsi nalez (nesouvisi s dnesnim zadanim, nefixovano):** `sub_1AFA0`
(presne ta funkce z uplne prvniho screenshotu v teto konverzaci) ma
NESHODUJICI SE deklaraci vs definici - `orion_common.h` ji deklaruje s
JEDNIM parametrem, skutecna definice v `orion_part_01.c` ma DVA
(`__int16 a1, __int16 a2`). GCC to odhali jako "conflicting types" (MSVC
mozna ne, kvuli jine striktnosti) - potreba dohledat, ktera signatura
odpovida realnym volajicim mistum.

### 2) `port_memory` - malloc/calloc/realloc/free + nmalloc/nfree

**KRITICKY BUG NALEZEN A OPRAVEN:** `link_stubs.c` mel `int nfree;` -
OBYCEJNOU DATOVOU promennou se stejnym jmenem, jako ma FUNKCE `nfree`
deklarovana v `orion_common.h` (`extern int nfree(unsigned int);`).
**Zadna skutecna funkce `nfree` nikde v projektu neexistovala.** Vsech 39
volani `nfree(ptr)` v hernim kodu by se za behu linkovalo na adresu ctyr
nulovych bajtu - zavolani by skocilo doprostred dat a spadlo/poskodilo
pamet. Stejna trida zavaznosti jako drivejsi `sub_FE8BE`/`MarkCheatPatternFlag_F4FD5`
nalezy, jen tentokrat objevena preventivni analyzou, ne pri runtime padu.

**Reseni:**
- `port_memory.h/.cpp` rozsireno o C-linkage most (`PortMemory_Alloc/
  Calloc/Realloc/Free`) a `Port::Memory::Realloc` v C++ API - tenke
  obalky nad existujici `Alloc`/`Free` evidenci zivych alokaci.
- `hexrays_compat.h`: pridana makra `#define malloc/calloc/realloc/free`
  presmerovavajici VSECHNY takove volani v hernim kodu na `PortMemory_*`
  (overeno auditem poctu argumentu pred zavedenim - malloc/free/realloc
  se v hernim kodu vubec nevolaji primo, jen `nmalloc`/`nfree`).
- `link_stubs.c`: `nfree`/`nmalloc` jsou (a musi zustat) REALNE FUNKCE, ne
  makra - kdyby se makrem prejmenovaly, makro by expandovalo i jejich
  vlastni `extern` deklaraci v `orion_common.h` (jiny typ parametru -
  `unsigned int` misto `size_t`) a vytvorilo nesedici redeklaraci. Misto
  toho jejich TELO ted vola `PortMemory_Alloc`/`PortMemory_Free` primo.
  Oprava `nfree` bugu je soucasti tohoto same zasahu.
- `orion_part_23.c`: 3x `calloc()` melo jen JEDEN parametr (stejna trida
  Hex-Rays artefaktu jako u `fopen`/`fseek` nize). `calloc(259)` opraveno
  bezpecne a jednoznacne na `calloc(1, 259)` (celkovy pocet bajtu je jasny
  bez ohledu na rozdeleni count/size). **`calloc(1)` (2x, v `sub_15E0F0`
  a `sub_15E124`) je KRITICKY zavaznejsi:** vysledek se pouziva jako
  RETEZCOVY BUFFER (overeno v `orion_part_22.c` - `itoa`/`strcpy`/rucni
  konkatenace zapisujici desitky bajtu, prvni zapis uz prekracuje 1 bajt).
  Puvodni `1` byl temer jiste jen jedna ze dvou ztracenych hodnot, ne
  skutecny pozadavek na 1 bajt - 1bajtova alokace by zpusobovala
  poskozeni haldy. Docasne nastaveno na `calloc(1, 256)` jako bezpecny,
  ale NEOVERENY odhad - vyzaduje dohledani VSECH volajicich mist a
  zjisteni skutecne max. delky pred oznacenim za vyresene.

### 3) `port_file` - case-insensitive souborove I/O

Novy `src/port/port_file.h/.cpp`. Klicovy DESIGN DETAIL: dekompilovany kod
NIKDE nepouziva typ `FILE*` - vysledek `fopen()` vzdy uklada do `int`/
`_DWORD` promennych (napr. `dword_1BC338 = fopen(...)`). Kdyby
`PortFile_Open` vracel skutecny `FILE*` (8 bajtu na x64), ulozeni do
32bit promenne by ukazatel oriznul -> nasledne `fread`/`fclose` by
dostaly nesmyslnou adresu -> jisty pad. **`PortFile_Open` proto vraci
maly CELOCISELNY HANDLE** (index do interni tabulky otevrenych souboru, 0
= neplatny/selhani, stejna "falsy" semantika jako puvodni `NULL`) -
overeno funkcnim testem (skutecne zkompilovano a spusteno, ne jen
syntax-check), vcetne soubezneho otevreni vice souboru se ruznymi handly.

Case-insensitivita: na Windows se nic nedeje (NTFS/FAT uz jsou
case-insensitive samy o sobe). Na Linuxu/macOS `Port::File::
ResolveCaseInsensitivePath` prochazi cestu segment po segmentu, pro kazdy
segment otevre `opendir`/`readdir` a hleda `strcasecmp` shodu - vysledky
se cachuji (mutex-chranena mapa), cache se cisti po zapisu noveho
souboru. **Funkcne otestovano** (ne jen zkompilovano): vytvoren testovaci
soubor `DATA/Sound.LBX`, overeno otevreni pres `data/sound.lbx` i
`DATA/SOUND.lbx` - obojí funguje.

Presmerovano makry v `hexrays_compat.h`: `fopen`/`fclose`/`fread`/
`fwrite`/`fflush`/`access` - vsechna overena auditem poctu argumentu na
CELEM projektu pred zavedenim (fclose/fread/fwrite/fflush/access: 100%
spravny pocet argumentu ve vsech vyskytech; fopen: 52 spravne, 25
chybne).

**24 chybnych `fopen()` volani opraveno** (chybel mod parametr - stejna
trida Hex-Rays artefaktu jako drive u `fprintf`). Mod dopocitan
heuristikou: pokud se v okoli (az po odpovidajici `fclose`) najde
`fread`/`fwrite`/`fprintf` pouzivajici stejnou promennou, pouzije se
odpovidajici `"rb"`/`"wb"`/`"r+b"`; jinak bezpecny vychozi `"rb"` (nikdy
netvori/neniceni soubor jako vedlejsi ucinek). Vyjimka rucne opravena:
`aLownetLog` (2 mista v `orion_part_21.c`) je log soubor zapisovany pres
`fprintf` a hned znovu otevirany po kazdem zapisu - heuristika by dala
`"wb"` (coz by mazalo log pri KAZDEM zavolani), rucne opraveno na `"a"`
(text append, `aA` konstanta) po precteni kodu. Mista bez jasneho
cteni/zapisu v okoli (9 z 24) oznacena `DECOMP_TODO` jako needle nizsi
jistoty - defaultne `"rb"`.

Vsechny existujici mod-retezcove konstanty pouzity znovu (`aRb`, `aWb`,
`aA`) misto novych retezcovych literalu - konzistentni se zbytkem kodu.

### DULEZITY DLUH - fseek/ftell (25 mist, NEOPRAVENO)

Na rozdil od `fopen` (52 spravnych / 25 chybnych) je `fseek` **VSECH 23
volani chybnych** (ruzne - nekdy 0 parametru, nekdy 1 misto 3) a OBE
volani "`ftell`" jsou pravdepodobne ve skutecnosti PRESMEROVANA `fseek`
(volana se 3 parametry, `ftell(handle, 0, 2)` presne odpovida idiomu
`fseek(handle, 0, SEEK_END)` pro zjisteni velikosti souboru - moznda
zamena importniho poradi/thunku pri dekompilaci).

Na rozdil od `fopen`u (kde stacilo doplnit mod retezec, ktery temer vzdy
jde odvodit z okoli) fseek/ftell potrebuji SKUTECNY OFFSET a ORIGIN,
ktere jsou VYZNAMOVE, ne binarni volba - spatny odhad by zpusobil TICHE
cteni ze spatneho mista v souboru (mnohem zakeznejsi nez pad, protoze se
to nemusi hned projevit). Priklad overene rekonstrukce (viz
`orion_part_20.c:665`, puvodni `fseek();` s NULA parametry): tesne pred
volanim se pocita `v9 = *(_DWORD*)(...)` (offset) a `dword_1BC338` (soubor
handle z predchoziho `fopen`), nasledovane `fread(buf, 0x2000, 1,
dword_1BC338)` pouzivajicim STEJNY handle - silne to napovida
`fseek(dword_1BC338, v9, SEEK_SET)`, ale KAZDE z 25 mist potrebuje
takovouhle vlastni analyzu.

`fseek`/`ftell` proto ZUSTAVAJI zatim BEZ presmerovani na `port_file`
(zadna case-insensitive/handle-tracking vyhoda pro ne, ale take zadna
REGRESE - stejne chovani jako pred touto vlnou). Presny seznam v
`hexrays_compat.h` (komentar u makro-sekce) a v tomto zaznamu.

**Seznam vsech mist s fseek()/ftell() k dohledani pristi session:**
`orion_part_01.c` (~10x), `orion_part_18.c`, `orion_part_19.c`,
`orion_part_20.c` (nekolik), `orion_part_22.c` (2x "ftell", ve
skutecnosti fseek). Presny pocet a kontext ziskatelny znovu pres
`grep -n "fseek(\|ftell(" src/game/*.c`.

## Hotovo - vlna 07: fseek/ftell dluh z vlny 06 vyresen

Pokracovani vlny 06. Z 20 `fseek()` + 1 mylne pojmenovaneho `ftell()` (21
mist celkem) je ted **19 opraveno s vysokou jistotou** a **2 s nizkou
jistotou** (jasne oznaceno, potrebuje dalsi overeni) - vsech 21 uz ma
spravny 3parametrovy tvar a `fseek`/`ftell` jsou konecne presmerovane na
`port_file` stejne jako zbytek souborovych funkci.

### Klicovy postreh, ktery skoro zpusobil novy pad

Puvodni plan byl nechat `fseek`/`ftell` volat REALNOU CRT funkci (bez
presmerovani na `port_file`), protoze nebyly hned vyresitelne. Jenze
`fopen` uz vraci **maly celociselny handle** (kvuli 64bit bezpecnosti -
viz vlna 06), ne skutecny `FILE*` - kdyby `fseek`/`ftell` zustaly volat
realnou CRT verzi, dostaly by misto ukazatele cislo jako `1`, `2`, `3`...
a spadly by na dereferenci neplatne adresy. **`PortFile_Seek`/
`PortFile_Tell` proto musely pribyt do `port_file.h/.cpp` HNED, driv nez
se cokoliv z fseek/ftell mohlo opravit** - jinak by kazda oprava jen
presunula misto padu, nevyresila ho.

### Rozpoznany vzor (LBX archivni format)

Vetsina mist (orion_part_19.c, orion_part_20.c) sdili identicky,
jednoznacny vzor: nacte se 2048bajtovy header obsahujici tabulky
start/end offsetu zaznamu (`dword_1BBA74[]`/`dword_1BBA78[]` a analogicke
v jinych souborech), spocita se zacatecni offset zaznamu podle indexu, a
TESNE PRED tim spocitanym offsetem se vola `fseek()` (bez viditelnych
parametru) - jednoznacne `fseek(handle, vypocteny_offset, SEEK_SET)`.
Potvrzeno krizovou kontrolou pouziti stejnych tabulek napric 6 ruznymi
funkcemi (magic number `65197` = signature check, `dword_1BC26C`/
`dword_1BC338`/`dword_1BC310[idx]` jako souborove handly).

`orion_part_22.c` mel klasicky "zjisti velikost souboru" idiom rozdeleny
na 3 mista: `fseek()` (prazdne), `ftell(v6, 0, 2)` (3 parametry misto 1 -
zbytky z predchoziho fseek volani), `fseek()` (prazdne znovu) -
rekonstruovano jako standardni `fseek(f,0,SEEK_END); size=ftell(f);
fseek(f,0,SEEK_SET);`.

### 2 mista s NIZKOU jistotou (potrebuji dalsi overeni)

- `orion_part_19.c` (~radek 5913): seek po precteni dvou 2bajtovych poli
  (snimek pocet/velikost?) - pouzita hypoteza `v16 + 4 + a5*v19`
  (zacatek zaznamu + hlavicka + preskoceni `a5` snimku). Nejde o pad-
  riziko (spatna hodnota by cetla existujici, jen spatna data), ale
  vysledek (asi obrazova/animacni data) muze byt vizualne spatne.
- `orion_part_20.c` (~radek 7248, "Play_Sound"): tabulka VELIKOSTI
  zaznamu jasne na `v5[4*v7+8]`, ale zadna tabulka OFFSETU nebyla
  jednoznacne identifikovana - pouzita hypoteza prokladane tabulky
  `{offset,size}` DWORD paru (`v5[4*v7+6]` = offset o 4 bajty pred
  size). Riziko: spatny zvuk by se prehral, ne pad.

Oboje jasne oznaceno `DECOMP_TODO - NIZKA JISTOTA` primo v kodu.

### Zmeny v `port_file.h/.cpp`

Pridano `PortFile_Seek(handle, offset, origin)` a `PortFile_Tell(handle)`
- tenke obalky nad `std::fseek`/`std::ftell`, pouzivaji STEJNOU tabulku
  handlu jako Read/Write/Close (viz `PortFile_Resolve` helper). Overeno
  **funkcnim testem** (ne jen syntax-check): vytvoren testovaci soubor,
  overeno `fseek(SEEK_END)+ftell` = spravna velikost, seek na zacatek i
  na konkretni offset, vse pres case-insensitive handle.

`hexrays_compat.h`: pridana makra `#define fseek/ftell` + definice
`SEEK_SET`/`SEEK_CUR`/`SEEK_END` (normalne z `<stdio.h>`, ktere sem
zamerne nevkladame - hodnoty 0/1/2 jsou soucast C standardu, bezpecne
definovat primo).

Overeno `gcc -fsyntax-only` na celem `src/game/` - **zadne nove chyby**,
jen pre-existujici `sub_1AFA0` (viz vlna 06) a `exit()` (viz vlna 01).

## Hotovo - vlna 08: DOS FINDFIRST/FINDNEXT (unknown_libname_1/2)

Uzivatel poskytl asm-urovnovy pseudokod dvou Watcom v9.x DOS runtime
knihovnich funkci (`unknown_libname_1`/`unknown_libname_2` - IDA jim
nedokazala priradit vlastni citelnou adresu, byly "COLLAPSED FUNCTION" v
asm dumpu), ktere spojuji **INT 21h AH=1Ah (SET DTA)** + **AH=4Eh/4Fh
(FIND FIRST/NEXT ASCIZ)** do jednoho volani - klasicke DOS hledani
souboru podle wildcard vzoru (`*`, `?`).

### Layout DTA bufferu - overeno, ne odhadnuto

Volajici mista v `orion_part_18.c` pristupuji na pevne bytove offsety od
`unk_1AD828` (DTA buffer): `dword_1AD842` (+0x1A) se pouziva jako
velikost souboru, `word_1AD840` (+0x18) se dekoduje presne DOS
datumovym algoritmem (`((x>>9)+1980)` rok, atd.), `word_1AD83E` (+0x16)
DOS casovym algoritmem, `unk_1AD846` (+0x1E) je kopirovan jako nazev
souboru. Tyhle offsety **presne** odpovidaji standardnimu DOS DTA formatu
(reserved 21B + attr 1B + time 2B + date 2B + size 4B + name 13B = 43B) -
neni to hadani, je to primo vycteno z toho, jak hra na DTA pristupuje.

### Kam to patri - port_file, ne port_dos

Puvodni navrh (`PORT_LAYER_ARCHITECTURE.md`) mel FINDFIRST/FINDNEXT v
`port_dos.cpp` (vseobecne INT 21h sluzby). Uzivatel spravne navrhl presunout
to do `port_file.cpp` - **dava to vetsi smysl**, protoze FindFirst/FindNext
potrebuje PRESNE tu samou case-insensitive resolver logiku, jakou uz
`port_file.cpp` ma pro `fopen()` (adresarova cast cesty se resolvuje
stejnym `ResolveCaseInsensitivePath`). `port_dos.cpp` zustava pro
obecnejsi/terminalove DOS sluzby. Poznamka o tomhle rozhodnuti pridana do
`PORT_LAYER_ARCHITECTURE.md` i primo do `port_file.h`.

### Implementace - `Port::File::FindFirst`/`FindNext`

- `struct DosDta` v `port_file.h` (`#pragma pack(1)`, presne overene
  offsety, `static_assert(sizeof==43)` v C++ rezimu).
- Case-insensitive wildcard matcher (`*`/`?`) - vlastni implementace,
  zadna externi zavislost.
- Hledani pres `std::filesystem::directory_iterator` (portable, C++17) -
  adresarova cast cesty prochazi stejnym `ResolveCaseInsensitivePath`
  jako `fopen()`.
- Stav probihajiciho hledani (pro navazujici `FindNext`) se uklada do
  tabulky `g_findStates`, handle (index) se zapisuje primo do
  `DosDta::reserved` bajtu - **presne stejny princip**, jakym DOS sam
  nese svuj (u nej opaque) hledaci stav mezi FINDFIRST/FINDNEXT volanimi.
- `unknown_libname_1`/`unknown_libname_2` jsou tenke C-linkage obalky nad
  `Port::File::FindFirst`/`FindNext`.

### OPRAVA - spatne odhadnuta navratova konvence (nalezeno uzivatelem)

V puvodni verzi teto vlny jsem implementoval `unknown_libname_1/2` tak, aby
vracely **nenulovou** hodnotu pri nalezeni - zalozeno jen na JEDNOM
volajicim miste (`orion_part_08.c`), ktere jsem navic spatne precetl.
Uzivatel se zeptal "nebyly ty navratove hodnoty v DOSu jinak?" - spravna
otazka, spustila opravu. Krizova kontrola VSECH 4 volani v
`orion_part_18.c` ukazala jednoznacne OPACNOU konvenci:
- `sub_11181C`: `return unknown_libname_1(a1, 0, v2) == 0;` - explicitni
  test na 0 jako uspech.
- `sub_111610`/`sub_111660`: pri NENULOVE hodnote vraci selhani/0/NULL,
  pri NULE dekoduji prave vyplnenou DTA (= uspech).
- `FindMoxSetPath_1114D7`: pri nenulove `*a2=0; return 0` (nenalezeno),
  pri nule zkopiruje nalezene jmeno a `return 1` (nalezeno).

Skutecna DOS/Watcom konvence je klasicky "errno" styl: **0 = uspech
(nalezeno)**, nenulova = chyba/nenalezeno - presne obracene nez typicky
C bool. Opraveno v `port_file.cpp` (`unknown_libname_1/2` ted vraci
`0`/`1` obracene) - `Port::File::FindFirst`/`FindNext` (C++ vrstva) si
zachovaly prirozene `bool true=nalezeno`, konverze se deje jen v tenke
C-linkage obalce. Overeno znovu funkcnim testem (viz nize).

**Ponauceni (dalsi v rade behem tohoto projektu):** i u zdanlive
jednoduche "najdi/nenajdi" navratove hodnoty je nutne zkontrolovat VSECHNA
volajici mista, ne jen prvni nalezene - jedno misto muze byt samo o sobe
zavadejici (v tomto pripade "if (nalezeno) { pouzij vysledek }" vypadalo
rozumne, ale ve skutecnosti to bylo "if (NEnalezeno) { pouzij tuto
alternativu jako fallback }").

**Funkcne otestovano** (ne jen zkompilovano): vytvoreny testovaci soubory
`SAVE1.GAM`/`Save2.gam` (rozdilna velikost pismen), hledani vzorem
`data/*.GAM`, r==0 znamena nalezeno (2 shody), zaverecne r!=0 (dosli
zaznamy), negativni test (vzor bez shody) vraci r!=0.

**DECOMP_TODO ponechano:** DOS atributy (hidden/system/archive - jen
adresar/read-only se momentalne detekuji) nejsou plne mapovany, protoze
cross-platformni zjisteni FAT-stylovych atributu na Linuxu/macOS nema
primy ekvivalent - pokud je hra bude niekde skutecne testovat, bude
potreba dohledat konkretni pouziti.

Odstraneny stare no-op stuby (`int unknown_libname_1(void){return 0;}`) z
`link_stubs.c`. `hexrays_compat.h` ma DosDta + deklarace pro cisty C herni
kod (nemuze primo includovat `port_file.h` kvuli C++ `namespace`).
`reorion2.vcxproj` beze zmeny (`port_file.cpp/h` uz tam byly z vlny 06).

Overeno `gcc -fsyntax-only` na celem `src/game/` - zadne nove chyby.

## Hotovo - vlna 09: dos_getdiskfree + dos_getvect/dos_setvect -> port_dos

Tri posledni DOS/Watcom runtime stuby z `link_stubs.c` nahrazeny skutecnou
implementaci v `src/port/port_dos.cpp` (deklarace v `port_dos.h`, zrcadlene
pro cisty C herni kod v `hexrays_compat.h` - stejny vzor jako DosDta/vlna 08).

### dos_getdiskfree (Watcom `_dos_getdiskfree`, INT 21h AH=36h)

- Jediny volajici: `GetFreeDiskSpace_111763` (drive `sub_111763`,
  orion_part_18.c) - vraci volne misto na disku v bajtech, hra s nim na
  jedinem miste (orion_part_20.c, srovnani s `dword_1BF35C`) testuje,
  jestli se jeste vejde ulozena pozice.
- **Layout OVEREN z volajiciho**: buffer 4x `uint16_t` na ofsetech 0/2/4/6,
  volajici pocita `pole+6 * pole+4 * pole+2` - presne Watcom poradi
  `total/avail_clusters, sectors_per_cluster, bytes_per_sector`
  (avail*spc*bps = volne bajty). Vytknuta struktura `DosDiskFree`.
- Puvodni dekompilat mel misto struktury 4 NEZAVISLE 16bitove lokaly
  (`v1[2]`, `v2`, `v3`, `v4`) - v originale nahodou spravne za sebou na
  zasobniku, ale v prekompilovanem C by zapis 8 bajtu pres `v1` byl
  out-of-bounds a `v2..v4` by zustaly nevyplnene (kompilator lokaly
  NEMUSI pokladat za sebe). Vytknuti struktury tohle spravilo.
- Implementace meri REALNE volne misto (`std::filesystem::space` na
  aktualnim adresari) a koduje ho do 16bitovych DOS poli: pevne 512 B/sektor,
  64 sektoru/cluster (32KiB cluster, max bezna FAT16 hodnota), pocty
  clusteru zastropovane na 0xFFFF -> hlasene maximum ~2 GiB a soucin
  0x7FFF8000 se VZDY vejde do `int` nasobeni volajiciho bez preteceni.
- Navratova konvence 0=uspech (DOS "errno" styl - ponauceni z vlny 08
  aplikovano rovnou, volajici pri nenule vraci 0 volnych bajtu).

### dos_getvect/dos_setvect (Watcom `_dos_getvect/_dos_setvect`, INT 21h AH=35h/25h)

- Volajici: `InstallKeyboardIsr_12C420` (drive `sub_12C420`) mezi
  CLI/STI (`sub_144A46/48` = `_disable/_enable`) uklada puvodni INT 9
  (klavesnice) vektor a instaluje vlastni handler `KeyboardIsr_12C4D8`
  (plni 10slotovy kruhovy buffer `dword_1BC2AC`, indexy `byte_1BC2E2/E3`);
  `RestoreKeyboardIsr_12C493` (drive `sub_12C493`) ho pri exitu (atexit
  retez `sub_113DBD`) vraci zpet.
- **Vytknuta struktura `DosFarPointer`** (uint32 offset + uint16 segment,
  48bit DOS4GW far pointer) pro ulozeny vektor `savedKeyboardVector_1BC2DC`
  (drive `byte_1BC2DC`). NUTNE, ne jen kosmetika: IDA promennou mylne
  typovala jako ukazatel na funkci, takze puvodni dekompilovany vyraz
  `*(_DWORD *)byte_1BC2DC` pri obnove by v C DEREFERENCOVAL ulozenou
  hodnotu (s no-op stubem getvect = NULL -> jisty pad pri kazdem ukonceni
  hry) misto precteni ulozenych bajtu.
- **Artefakt dekompilace zdokumentovan primo v kodu**: `_dos_getvect`
  vracel 48bit far pointer v DX:EAX - segmentovou cast (DX) dekompiler
  ztotoznil s parametrem `a2` (`segment = a2` ponechano 1:1 dle originalu).
  Druhy parametr `dos_setvect(9, 9, ...)` je obdobny duplikat cisla
  vektoru v dalsim registru - signatura ponechana, aby sedela na
  dekompilovana volajici mista.
- Implementace: emulovana 256polozkova tabulka vektoru v `port_dos.cpp` -
  JEN uloziste, handler se nikdy nevykonava (klavesove udalosti dodava
  SDL3). Parova sekvence "uloz -> instaluj -> obnov" tak funguje presne
  jako v originale, bez vedlejsich ucinku.
- Pri instalaci se do `dword_1BC2D8/1BC2D4` ukladaji adresy 1050/1052 =
  **0x41A/0x41C, hlava/ocas klavesoveho bufferu v BIOS data area** - viz
  novy DECOMP_TODO nize (sub_12C3D3 je primo dereferencuje!).

### Prejmenovani (vsechna volajici mista prosla, viz konvence)

- `sub_111763` -> `GetFreeDiskSpace_111763`
- `sub_12C420` -> `InstallKeyboardIsr_12C420`
- `sub_12C493` -> `RestoreKeyboardIsr_12C493`
- `sub_12C4D8` -> `KeyboardIsr_12C4D8` (telo je zatim jen `_GETDS` stub -
  dekompilace ISR selhala, skutecne plneni kruhoveho bufferu chybi)
- `byte_1BC2DC` -> `savedKeyboardVector_1BC2DC` (typ `DosFarPointer`)

Struktury `DosDiskFree`/`DosFarPointer` jsou definovane v OBOU hlavickach
(`port_dos.h` pro port, `hexrays_compat.h` pro cisty C herni kod) pod
sdilenym guardem `REORION2_DOS_STRUCTS_DEFINED`, protoze `reorion2.cpp`
includuje obe najednou (u DosDta z vlny 08 se to neprojevilo jen proto,
ze `port_file.h` zadny .cpp spolu s `orion_common.h` neincluduje).

**Overeno plnym MSBuild buildem** (Debug x64, `reorion2.exe` slinkovan -
gcc na tomto stroji neni) a **funkcnim testem** (12 kontrol, vse OK):
realne volne misto > 0 a zastropovane pod `INT_MAX` soucin, NULL buffer =
chyba, presna herni sekvence uloz/instaluj/obnov INT 9 vektoru vcetne
segmentove casti, cteni/zapis mimo rozsah tabulky (vektor 9999) bezpecne
vraci 0 / nic nedela.

### DECOMP_TODO objevene pri teto vlne (zatim NEresene)

- `sub_12C3D3` porovnava `*(_WORD *)dword_1BC2D8 != *(_WORD *)dword_1BC2D4`,
  tj. dereferencuje surove adresy 0x41A/0x41C (BIOS "klavesa ceka ve
  fronte?") - na modernim behu jisty pad, az se ta funkce zacne volat.
  Patri do budouci klavesove vlny spolu s napojenim kruhoveho bufferu
  `dword_1BC2AC` na SDL3 udalosti (port_mouse/port_vga vrstva).
- `sub_12C2A0/sub_12C2C6` ctou `MEMORY[0x46C]` (BIOS timer tick) - dnes
  jde do `HEXRAYS_MEMORY_STUB`, takze cekaci smycka `sub_12C2C6` by se
  tocila donekonecna; potrebuje napojit na SDL_GetTicks ekvivalent.

## Hotovo - vlna 10: falesne "adresy" v alokacich sub_10CB5 + DUMPREGS testovaci body v DOSBox-X

### Problem

Alokace v `sub_10CB5` (orion_part_01.c) pouzivaly jako velikost ADRESY
symbolu: `PoolAlloc_110B89((int)&unk_1B5030, ...)`, `(int)&loc_16085 + 5`,
`(int)&loc_3E7FB + 5`, prah `v2 <= (int)&unk_1B5418` a odecet
`v2 -= (int)&loc_40F0D + 3`. Na modernim buildu (64bit adresy stub
promennych oriznutne do int) z toho vznikala nesmyslna obri/nahodna cisla.

### Overeni 1 - staticke (hodnoty a krizove reference)

Vsech 5 vyrazu prevedeno na cisla dava PRESNE kulate dekadicke hodnoty:
1790000 / 90250 / 1791000 / 256000 / 266000 - stejny IDA false-positive
jako 0x64000 ve vlne 06 (konstanta v rozsahu adres -> "offset symbol+delta").
Krizove dukazy: 90250 = 361*250 presne sedi na smycku v `sub_10E2F`
(cte 250 zaznamu po 361 B do tehoz bufferu `dword_192B18`, konec porovnava
s tymz "ukazatelem") i na `memset(dword_192B18, 0, ...)` tamtez;
`sub_110F89` vraci volnou pamet v KiB (`>>10`), takze
`1000*sub_110F89() <= 1791000` je porovnani bajtu s bajty (prah = hlavni
buffer 1790000 + rezerva); `sub_1279AF` hlasi "Not enough space" pod
226488 B.

### Overeni 2 - ZA BEHU originalu v upravenem DOSBox-X (testovaci body)

Do `src/engine/engine.cpp` v dosbox-x-remc2 pridano rozsireni **DUMPREGS**
(dokumentace v `genCompare/DOSBOX_CTL_PROTOCOL.md`, konfigurace behu
`genCompare/dosbox_ctl_alloc10CB5.cfg`):
- `DUMPREGS cond=eip:0xADDR` - dump vsech registru + `ret=[ESP]`
  (navratova adresa -> identifikace volajiciho) pri zasahu EIP,
- `DUMPREGS cond=eax:0xVAL` - hranovy trigger "EAX prave nabyl hodnotu" -
  NEZAVISLY na adresach (chyti uz `mov eax, imm` u volajiciho).

Prvni kolo (eip: watche na IDA adresach) nechytlo nic -> objeven a zmeren
**konstantni posun runtime EIP = IDA adresa + 0x224000** (kalibrace pres
znamou konstantu 0x64000 z GameMain + cela sekvence nize; sedi i s
`TURN_ADVANCE_EIP=0x232d2f` v puvodnim engine.cpp). Pozor: `engine_call`
(cond `call:`) vidi jen FAR volani, near volani ve flat segmentu ne -
proto na vstupy funkci pouzivat `DUMPREGS cond=eip:`.

Druhe kolo (hranove eax: watche) - hra Orion2.exe (C:\prenos\mastori2)
pri startu skutecne provedla presne sekvenci z dekompilatu, vsechna
volaci mista v tesnem sledu a spravnem poradi uvnitr sub_10CB5:

| runtime EIP | -0x224000 | EAX (velikost) | dekompilat |
|---|---|---|---|
| 0x2340AF | 0x100AF (GameMain) | 0x64000 | kotva z vlny 06 |
| 0x234CBB | 0x10CBB | 0x1B5030 = 1790000 | (int)&unk_1B5030 |
| 0x234CCA | 0x10CCA | 30000 | konstanta |
| 0x234CE8 | 0x10CE8 | 6120 | konstanta |
| 0x234D01 | 0x10D01 | 30024 | konstanta |
| 0x234D1A | 0x10D1A | 0x1608A = 90250 | (int)&loc_16085+5 |
| 0x234D6F | 0x10D6F | 0x3E800 = 256000 | (int)&loc_3E7FB+5 |

U alokace 256000 mel EDX (=v2) hodnotu 0x188AB70 (~25.7 MB pri
memsize=32) > 1791000 -> prosla presne ta vetev, kterou ukazuje dekompilat.
(Pozdejsi zasahy 0x174508/0x1B5418 na EIP 0x36DB86 = AIL timer aritmetika
1525*1000 / 1791*1000 v runtime knihovne - s alokacemi nesouvisi.)

### Oprava v reorion2

- `orion_part_01.c` (sub_10CB5): vsech 5 vyrazu nahrazeno overenymi
  konstantami (1790000 / 90250 / 1791000 / 256000 / 266000) + komentar
  s metodikou; stejne tak konec smycky a memset v `sub_10E2F`.
- Falesne symboly `unk_1B5030`, `unk_1B5418`, `loc_16085`, `loc_3E7FB`,
  `loc_40F0D` ODSTRANENY z orion_data.c i orion_common.h (nulove zbyvajici
  pouziti - aby je uz nikdo omylem nepouzil).
- Overeno plnym MSBuild buildem (Debug x64, reorion2.exe slinkovan).

### Infrastruktura pro dalsi srovnavani (pripraveno)

- DOSBox-X (Release x64) preložen s DUMPREGS, beh je plne automaticky:
  config ma `STOP cond=cycle_ge:120000000` (sub_10CB5 alokace probehnou
  ~83M cyklu po startu), takze se DOSBox sam ukonci a NEBEZI donekonecna.
- Vzorovy config: `genCompare/dosbox_ctl_alloc10CB5.cfg`; postup a zjisteny
  adresni posun zdokumentovan v `genCompare/DOSBOX_CTL_PROTOCOL.md`.
- Šablona `genCompare/engine.cpp` synchronizovana se `src/engine/engine.cpp`.

## Hotovo - vlna 11: zaseknuti v sub_110FE7 + emulovany rozpocet pameti + LARGEADDRESSAWARE:NO

### Nahlaseny problem: beh se zasekava v sub_110FE7

`sub_110FE7` ("Linear space remaining") je Watcom sonda volne pameti:
alokuje rostouci bloky, dokud nmalloc neselze. Vola se JEN z fatalniho
hlaseni `sub_110EC3` ("Insufficient Memory!"). Zaseknuti melo DVE pricin:
1. moderni malloc prakticky neselze -> sonda rostla donekonecna,
2. hra se do chybove vetve vubec nemela dostat - dostala se tam kvuli
   dalsim portovacim chybam (viz retez nize).

### Cely retez pricin (odhalen postupnou bisekci pres nove DIAG checkpointy)

1. **Ukazatele v 32bit intech (KRITICKE, reseni pro CELY projekt):**
   dekompilat uklada ukazatele do `int` (sub_110DFE vraci int, vsechna
   `dword_x = (int)PoolAlloc(...)`). x64 heap lezi bezne NAD 4 GB ->
   orez -> pad/NULL. Reseni: **`/LARGEADDRESSAWARE:NO`** v obou x64
   konfiguracich vcxproj - cely proces (heap/moduly/stack) zije pod 2 GB,
   kazdy ukazatel prezije pruchod pres int. Standardni trik decomp portu.
2. **memavl stub vracel 0** -> `sub_110F89` (volna pamet v KiB) vracela 0
   -> sub_10CB5 sel do nouzove vetve `sub_1279AF(1000*(0-50) = -50000)`
   -> nmalloc(zaporne=obri) selhal -> "Insufficient Memory!".
3. **sub_110E36 (DPMI 0x0100 ALLOCATE DOS MEMORY BLOCK)** cetl pres
   int386 stub NEINICIALIZOVANY vystupni buffer -> nahodne vracel bud
   falesne selhani, nebo nahodny "ukazatel" (pad v sub_113E08, ktery
   z adresy pocita real-mode segment adresa>>4).
4. **screenHeight_184538 (drive `_UNKNOWN unk_184538` = char!)** - vyska
   obrazovky; 480 se orezalo na signed char -32 -> plocha VGA bufferu
   `vyska*sirka` = -32*640 = **-20480** -> alokace -20420 B selhala ->
   znovu "Insufficient Memory!". (Nalezeno DIAG checkpointem primo na
   vypoctu; v puvodnich datech jde o 4bajtovou promennou 0x184538.)
5. **Pomalost sondy v Debug buildu**: i s funkcnim rozpoctem by sonda
   (8KiB kroky do 32 MiB) znamenala ~64 GB zapisu, protoze Debug CRT
   vyplnuje kazdou alokaci vzorem 0xCD - na DOSu nmalloc nevyplnoval nic,
   proto byl original okamzity. Sonda nahrazena primym `memavl()`
   (port zna volnou pamet presne; puvodni telo zachovano v komentari,
   vcetne DECOMP_TODO o podezrele druhe smycce, ktera roste NAD uz
   selhavsi velikost - nelze overit pasivnim behem originalu, vetev
   bezi jen pri skutecnem nedostatku pameti).

### Nova infrastruktura

- **Emulovany rozpocet pameti** v `port_memory` (32 MiB, prepsatelne env
  `REORION2_MEM_BUDGET`): Alloc/Realloc pri prekroceni vraci NULL - presne
  jako DOS nmalloc na plnem stroji. Referencni dosbox beh (memsize=32,
  vlna 10) hlasil DPMI+memavl ~26.3 MB volnych. `memavl()` = zbytek
  rozpoctu (realna implementace v port_memory.cpp, stub odstranen).
- **`PortDebug_Checkpoint(name, value)`** (port_dos.cpp, deklarace v
  hexrays_compat.h): env-gated diagnostika `REORION2_TRACE=1` -> radky
  "DIAG <jmeno> <hodnota>" na stderr (neubuffrovane, prezije pad).
  Checkpointy zustavaji osazene v init sekvenci (GameMain, RunGame,
  sub_1248AB, sub_110EC3) - bez env promenne jsou no-op.
- `sub_110E36` preveden na port alokaci (16-zarovnany blok kvuli
  segment prevodum; puvodni DPMI telo v komentari). POZOR: 16bit
  "segment" (word_1B0700) se pri adresach nad 1 MiB orizne - smi ho
  pouzivat jen real-mode sluzby, ktere v portu neexistuji.

### Vysledek (overeno behem z C:\prenos\mastori2)

Pred vlnou: beh visel v sub_110FE7. Po vlne prochazi cela init sekvence:
ParseCommandLine -> nacteni nastaveni -> PoolAlloc(0x64000) -> RunGame ->
sub_113E08 (8KiB DOS buffer) -> **cela VGA inicializace sub_1248AB**
(307200 = 640*480 spravne) -> InstallKeyboardIsr -> sub_117262 -> a konci
az v `sub_111F3E` = **inicializace zvuku AIL/Miles** ("Could not register
timer with AIL", sub_13F640/sub_1400A9/SOUND.LBX) - to je prirozeny dalsi
krok pro port_sound (viz nize). Zadne zaseknuti, cisty exit.

## Hotovo - vlna 12: "fonts.lbx could not be found" + prekryvove bloky + tichy zvuk

### Nahlaseny problem a jeho skutecne priciny (postupne odlupovane)

1. **"fonts.lbx [entry 0] could not be found."** = fopen selhal. Hra hleda
   VSECHNY soubory v aktualnim pracovnim adresari - pri spusteni odjinud
   (F5 z VS, dvojklik na exe) nenasla nic. Reseni dvojite:
   - `reorion2.vcxproj.user`: `LocalDebuggerWorkingDirectory = C:\prenos\mastori2`
     pro vsechny konfigurace (F5 z VS ted bezi primo v adresari hry).
   - `port_file.cpp`: fallback retez pro relativni cesty, kdyz soubor
     v cwd neni: `REORION2_DATA_DIR` (env) -> adresar exe (pokryva
     "nakopiroval jsem LBX k exe") -> `C:/prenos/mastori2` (posledni
     zachrana pro tento stroj). Aplikovano v PortFile_Open, PortFile_Access
     i Port::File::FindFirst (jinak by mox.set/savy nesly najit, zatimco
     fopen by je otevrel). Cwd ma VZDY prednost.
2. Po vyreseni cest se ukazalo, ze pres sub_111F3E (AIL init) se ze
   spravneho adresare vubec nedalo projit - pad v `sub_157570`
   (AIL_install_DIG_INI = instalace real-mode DOS zvukoveho driveru dle
   DIG.INI). **Instalace driveru preskocena** (sub_140979, DECOMP_TODO) -
   s `v1 = 0` placeholderem v sub_111F3E hra bezi TISE a preskakuje
   SOUND.LBX; napoji se az na port_sound (SDL3).
3. **"fonts.lbx [entry 0] is not an LBX file"** - dalsi vrstva: fread
   2048B LBX hlavicky pres `&unk_1BBA6C` nikdy nenaplnil ODDELENOU
   promennou `word_1BBA6E` (magic 0xFEAD) ani tabulku offsetu
   `dword_1BBA74/78`. IDA symboly jsou totiz PREKRYVY jednoho bloku.

### Nova technika: prekryvove bloky (overlay makra)

Kdyz dekompilat pristupuje k JEDNOMU souvislemu useku pameti pres nekolik
symbolu zaroven (fread/memset pres jeden + cteni poli pres jine, stridove
indexovani `dword_X[10*slot]`), oddelene C promenne rozbiji semantiku.
Reseni: jeden backing `uint8_t blok_ADRESA[N]` v orion_data.c + `#define`
makra v orion_common.h mapujici puvodni symboly na presne offsety - vsechny
dekompilovane vyrazy zustavaji beze zmeny. Zavedeno pro:
- `soundSlots_1AE0AC[1320]` - 33 zvukovych slotu po 40 B (dword_1AE0AC/
  B0/B4/C8/CC/D0 + byte_1AE0B8 + skalary D8/F8),
- `lbxHeader_1BBA6A[2050]` - cache LBX hlavicky (unk_1BBA6A/byte_1BBA6B/
  unk_1BBA6C/word_1BBA6E/dword_1BBA74/dword_1BBA78).

### Dalsi opravene sirky/konstanty (stejne tridy jako vlny 10/11)

- `unk_1AF620`: 1 bajt -> `uint8_t[4172]` (AIL struktura, memset 4172 =
  presne vzdalenost k dalsimu symbolu; prepisovala sousedni globaly).
- `unk_1BC270`: 1 bajt -> `char[16]` (jmeno otevreneho LBX, strcpy cile).
- `loc_F4240` = **konstanta 1000000** (0xF4240, AIL mikrosekundy) - IDA
  false-positive, 6 mist v orion_part_18/23.c; symbol odstranen.
- `dword_1AE0A4`: tentativni `int[]` nevytvarel definici (LNK2001 po
  odstraneni duplikatu z link_stubs.c) -> `int[1]` + DECOMP_TODO.
- Duplicitni stuby dword_1AE0xx a dword_1BBA74 odstranene z link_stubs.c
  (kolidovaly s prekryvovymi bloky).

### Vysledek (overeno behem)

Ze spravneho i spatneho cwd identicky: cely init vcetne AIL (ticheho),
fonts.lbx se najde, otevre a PROJDE magic kontrolou, hra pokracuje pres
hlavni vetev (`RunGame.after_mainloop`) a BEZI (ukoncena az 20s timeoutem
testu, zadny pad). Dalsi krok: overit, co se skutecne deje v bezici
smycce (sub_132AA4?) a napojit VGA vystup, aby bylo neco videt.

## Hotovo - vlna 13: sub_132AA4 nebyla nekonecna smycka - selhana dekompilace a kaskada uriznutych funkci

### Overeni v puvodnim ASM (nova technika: DUMPMEM)

Do DOSBox-X engine.cpp pridana akce **DUMPMEM** (`DUMPMEM cond=eip:0xA
addr=0xB size=N label=x`) - pri zasahu EIP vypise hex obsah pameti do
trace. Tim jde vytahnout PUVODNI STROJOVY KOD primo z bezici hry a
disassemblovat (capstone pres pip). Pri tom zmereno: **kod = IDA+0x224000,
DATA = IDA+0x216000** (ruzne baze segmentu!).

### Co sub_132AA4 skutecne je

Dekompilat: `while(1);` + __noreturn + varovani "could not find valid
save-restore pair" = SELHANA dekompilace. Skutecne telo (disassemblovano
z originalu): kalibrace rychlosti CPU - pockej na hranu BIOS ticku
(dword [0x46C]), spocitej busy-smycky behem jednoho ticku, vysledek v
TETO verzi binarky ZAHOZEN (prepsan mov edx,1500; obe vetve zapisuji
totez) a jediny efekt je `dword_1BC798 = 0`; pak `popal; ret` - funkce
se NORMALNE VRACI. Port: `CalibrateCpuTick_132AA4()` = jen ten zapis
(cekani na BIOS tick by v portu viselo - presne to bylo nahlasene
"zaseknuti"; MEMORY[0x46C] je stub).

### Kaskada skod ze spatneho __noreturn

1. IDA oznacila sub_132AA4 za noreturn -> **uriznut konec
   RunGameAndExit_113D47**: chybelo volani `sub_123491` (inicializace
   mysi, INT 33h "Mouse driver required") a normalni navrat. Doplneno
   dle disassemblingu (ref niz), __noreturn odebran z obou funkci.
2. RunGameAndExit noreturn -> **uriznut i konec GameMain_10057**: cely
   zbytek (~810 instrukci, 0x1010A..0x10CB5) IDA zahodila! Obsahuje mj.
   dosud zahadne volani `sub_10CB5` (vlna 10 - "nema volajiciho"),
   inicializacni sekvenci (sub_10A72, sub_11919E, sub_1205E6,
   sub_123E6C, sub_123387, sub_7A06C) a HLAVNI STAVOVY AUTOMAT hry.
   Kompletni anotovany disassembling ulozen do
   **`ref/GameMain_10057.orig.asm.txt`** - podklad pro rekonstrukci
   (nejcistsi cesta: v IDA zrusit noreturn u 132AA4/113D47 a nechat
   GameMain_10057 predekompilovat, pak preneset).

### Dalsi opravy teto vlny

- **int386 ma konecne emulaci** (port_dos.cpp `PortDos_Int386`, stub v
  link_stubs presmerovan): INT 33h (mys) -> Port::Mouse (fn 0 = driver
  nainstalovan, fn 3 = pozice+tlacitka pres SDL3), ostatni preruseni
  deterministicky vraci vstupni registry. PONAUCENI: vystupni REGS se
  zapisuje jen 24 B (6 GP registru, BEZ cflag na ofsetu 24) -
  dekompilovane lokaly maji casto `_BYTE v6[24]` a zapis cflag prepisoval
  Debug RTC guard za nimi ("zamrznuti" v assert dialogu).
- **Vsync cekani** sub_132B27/sub_132B41 (busy-wait na VGA portu 0x3DA,
  s hr_inbyte stubem nekonecne) -> `PortVga_WaitVsync()` =
  Port::Vga::Present() + SDL_Delay(14) - snimek se vykresli a smycka se
  taktuje na ~70 Hz jako puvodni VGA refresh. Telo overeno i v ASM.
- MouseInit (sub_123491) diky int386 emulaci prochazi.

### Stav po vlne

Zadne zaseknuti: beh projde kompletni inicializaci vcetne mysi a CISTE
se ukonci (leak-report Port::Memory na konci - 8 zivych bloku, herni
zdroje se u exitu neuvolnuji, na DOSu to resil zanik procesu). Hra se
misto vstupu do menu ukonci proto, ze menu zije v uriznutem tele
GameMain - rekonstrukce dle `ref/GameMain_10057.orig.asm.txt` je dalsi
velky krok.

## Hotovo - vlna 14: audit "neuvolnenych bloku" pri exitu - shoda s originalem

Otazka: 8 zivych bloku (1 096 113 B) v leak-reportu Port::Memory pri
ukonceni - je v portu neco jinak nez v originale, ze se neuvolni?

### Identifikace bloku (velikost = pozadavek zaokrouhleny na 4 + 12 B
### hlavicka PoolAlloc/sub_110C62)

| bajtu | alokace | co to je |
|---|---|---|
| 409612 | PoolAlloc(0x64000) v GameMain | buffer resource modulu (dword_19916C) |
| 307260 x2 | PoolAlloc(307246) | VGA stranky dword_1BB90C + dword_1BB8FC (640x480+46) |
| 1932 x2 | PoolAlloc(4*480) | radkove tabulky dword_1BB908 + dword_1BB8C0 |
| 8204 | sub_110C62(0x2000) v sub_113E08 | (puvodne DOS/real-mode) 8KiB buffer |
| 47257 | sub_126ABD v sub_120526 | nacteny obsah fonts.lbx (dword_184514) |
| 12656 | PoolAlloc(12644) v sub_120526 | metadata fontu (dword_1B3E78) |

### Zaver: ZADNA divergence

- V CELEM dekompilovanem dumpu neexistuje jedine `nfree` na tyto globaly
  (grep pres vsech 41 nfree volani; dword_19916C/1BB90C/1BB8FC/1BB908/
  1BB8C0/1B3E78/1B06F8 maji 0 zasahu).
- `dword_184514` (fonty) se uvolnuje JEN pri opakovanem volani
  sub_120526 (vymena fontu za behu), ne pri exitu.
- Exit retez sub_113DBD (sub_123DD9 = reset mysi, sub_124ACE = INT 10h
  mod 3, RestoreKeyboardIsr, sub_11215B = AIL shutdown, sub_139062) ani
  epilog puvodniho GameMain (ref/GameMain_10057.orig.asm.txt) nic
  z toho neuvolnuji.
- Original spolehal na zanik DOS procesu - presne jak predvidal komentar
  v port_memory.h uz od vlny 06. Windows pamet pri exitu vraci stejne.

Leak-report tedy pri ukonceni hry ukazuje OCEKAVANY stav; do vypisu
pridana vysvetlujici poznamka. Skutecnou hodnotu ma report pro bloky
pribyvajici BEHEM hrani (az pobezi herni smycka) - tam by kazdy novy
zaznam znamenal skutecny leak oproti originalu.

## Hotovo - vlna 15: rekonstrukce OCASU GameMain_10057 - proc hra "skoncila"

### Pricina (navazuje na vlnu 13)

Hra po startu hned skoncila (GameMain se vratil do main() -> shutdown).
Duvod: IDA zahodila CELY ocas GameMain_10057 za volanim
RunGameAndExit_113D47 jako nedosazitelny (spatny __noreturn na
CalibrateCpuTick_132AA4, viz vlna 13). V tom ocasu je ale intro
(sub_24ED3) a **hlavni menu/herni smycka sub_1049B** - bez nej hra nemela
co delat a vratila se.

### Rekonstrukce ocasu (ref/GameMain_10057.orig.asm.txt)

Kompletni ocas prelozen z disassemblingu bezici hry (nova DOSBox akce
DUMPMEM z vlny 13). Registrove argumenty ~15 volani OVERENY DUMPREGS
primo z originalu (eip = IDA+0x224000). Klice:
- default (bez argv) nastavi `word_199A08 = 10` -> menu stav sub_816F2
  (MAINMENU.LBX). sub_1049B je soberstacna smycka (bezi dokud
  word_199A08 != 7 = quit).
- sub_24ED3 dostava jako a1 navrat sub_10CB5 (buffer intra).
- konec: lokalizovane "Thanks for playing" (byte_199CAE=jazyk) + exit
  (sub_126487, noreturn). switche = lokalizovane hlasky ("Loading..." /
  "Thanks for playing"), obsah nacten DUMPMEM.
GameMain zustava spravne __noreturn (konci pres sub_126487->exit).

### Doprovodne opravy (nutne, aby ocas vubec bezel)

1. **BIOS tick** (`PortDos_BiosTick`, port_dos.cpp): MEMORY[0x46C] byl
   mrtvy stub -> cekaci smycky (intro, pacing sub_12C2C6, casovani
   orion_part_23) se tocily donekonecna. Ted odvozeno z realneho casu
   (SDL_GetTicks, ~18.2 Hz). sub_12C2C6 navic prubezne vykresluje.
2. **Nepresmerovane stdio** (port_file.cpp + hexrays_compat.h): fgets/
   fgetc/fputc/fputs/fscanf/fprintf/setbuf dostavaly INT handle (z
   PortFile_Open) misto FILE* -> pad hned pri cteni ORIONCD.INI v
   sub_10A72. Presmerovano na PortFile_Gets/Getc/Putc/Puts/Scanf/Printf/
   Setbuf (variadicka makra zahodi Hex-Rays zdvojeny stream argument).
   Vsechny fprintf smeruji na herni handle (AIL debug), nikdy stdout.
3. **Mis-sized buffery**: `unk_1B3E20` (1B -> char[84], filename buffer);
   `byte_1BB358` (nedokoncene pole -> char[1024], cil 1024B kopie v
   sub_1205E6; DECOMP_TODO: cely usek 0x1BB358..0x1BB758 je ve
   skutecnosti jeden buffer rozsekany IDA na ~19 symbolu - zatim
   standalone, palety necti pres aliasy).
4. **Uninit-return** `sub_2484F` (`int result;` -> `= 0`, Hex-Rays
   artefakt, Debug RTC jinak pada; stejna trida jako vlna 02).

### Stav: hra bezi VYRAZNE dal, ale jeste ne do menu

Overeno (REORION2_TRACE=1 checkpointy): po pridani ocasu hra prochazi
CELOU init sekvenci - sub_10A72 (ORIONCD.INI), sub_1205E6, sub_10CB5,
sub_2484F, sub_FE8BE, sub_124878, sub_124B65, sub_8E5C5, sub_120BB5,
sub_124D41 - az k **vykreslovani textu** (sub_1212B3 "Loading..." ->
sub_122309 render znaku), kde pada. Drive skoncila hned po
RunGameAndExit.

Zbyvajici pady jsou LATENTNI chyby (mis-sized buffery / uninit-return /
IDA-rozsekane regiony) v kodu, ktery se DRIVE NIKDY nespustil (font/
grafika render pipeline, pak menu). Jde o stejnou tridu jako vlny 11/12/
tato - resi se postupne. Ladici pomucky ponechany:
- `REORION2_TRACE=1` -> DIAG checkpointy (vc. jemnych "tail.*" v ocasu),
- `REORION2_SKIPINTRO=1` -> preskoci intro (sub_24ED3, nastavi byte_19A004),
  aby slo testovat menu cestu nezavisle na intru.

### Dalsi krok

Pokracovat v bisekci render pipeline od sub_122309 (font glyph render):
nejspis mis-sized font buffer nebo out-of-bounds glyph. Pak menu
(sub_816F2 -> MAINMENU.LBX). Az bude menu videt, doresit intro
(sub_24ED3) a nakonec vstup (SDL klavesnice -> ring buffer dword_1BC2AC /
INT 9 emulace, aby menu reagovalo - mys uz funguje pres int386/INT 33h).

## Hotovo - vlna 16: NULL render vtable (dword_1BB89C/1BB894/1BB88C...) -> video mod 5

### Pricina

Render backend hry je VTABLE funkcnich ukazatelu (dword_1BB89C = render
snimku, dword_1BB894, dword_1BB88C, dword_1BB898, dword_1BB8A0,
dword_1B920C/9208/9210, dword_1BB884/888/890...), kterou plni sub_125064
podle video modu `HIWORD(dword_1BBA52)` (switch case 0/1/2/3/5). Mod se
vybira v sub_1248AB:
- puvodne: VESA cesta (`HIWORD(dword_1BBA64)==4`) -> sub_1252C2() -> 5;
  jinak `HIWORD(dword_1BBA52) = word_1BBA68` (= a1 = 4).
- V portu VESA detekce (sub_145FD2 pres int386x VESA BIOS) je stub ->
  false, a SVGA priznak dword_1BBA64 taky neni -> mod skoncil na **4**.
- sub_125064 NEMA case 4 -> default -> vtable ZUSTALA NULL -> prvni
  vykresleni (dword_1BB89C() apod.) spadlo na NULL ukazatel.

### Oprava (port: SDL linearni framebuffer = VESA linearni mod 5)

Overeno DUMPMEM z originalu: `HIWORD(dword_1BBA52) == 5` (mod 5, VESA
linear). Port renderuje pres SDL do LINEARNIHO 640x480 bufferu
(Port::Vga) - presne VESA linearni mod. Proto:
- `sub_145FD2()` (VESA available?) v portu vraci **true** (misto
  stub-int386x false) - port VESA-linearni framebuffer poskytuje.
- `sub_1248AB` vzdy pouzije VESA cestu (sub_1252C2() -> 5), nezavisle na
  hardwarovem SVGA priznaku, ktery v portu neexistuje.
-> sub_125064 hit case 5 -> vtable naplnena (overeno checkpointem
   `1248AB.videoMode`==5 / dword_1BB89C != NULL).

Tim padly NULL-vtable pady. Intro (sub_24ED3) i menu render ted volaji
skutecne mode-5 render funkce (sub_1255DF, sub_146348, sub_138Cxx...).

### Stav

Vtable OK, hra pokracuje dal do mode-5 render funkci, kde narazi na dalsi
latentni chyby (intro sub_24ED3 interne; skipintro cesta font render
sub_1212B3/sub_122309). Stejna trida (mis-sized buffery / uninit), resi
se dal. Ladici: `1248AB.videoMode` (ma byt 5).

## Hotovo - vlna 17: KORENOVA pricina korupce render vtable (dword_1BB89C/894/88C -> dword_1B9210)

### Pricina (navazuje na vlnu 16)

Po naplneni vtable (vlna 16) padalo volani `dword_1B9210(v0)` v sub_124ECB
(v0 = nesmyslne cislo, napr. -387171584). Diagnostika checkpointy zjistila:
- vtable je SPRAVNE naplnena hned po sub_125064 (`dword_1B9210 == sub_12439D`),
- ale POZDEJI (v sub_124ECB) uz NE -> nekdo ji PREPSAL (memory corruption),
- korupce nastava PRESNE behem volani `dword_1B920C()` = **sub_144A91**
  (render kurzoru mysi, mode 5), mezi checkpointy before/after.

`v0` samotne je neskodne: sub_144A91 je `void` (IDA minula navrat), takze
"v0 = ...()" jen precte smeti z eax, a sub_12439D svuj argument ignoruje.
Nesmyslne cislo bylo jen SYMPTOM, ne pricina.

### Korenova pricina: mis-sized cursor buffery

sub_144A91 zapisuje obraz kurzoru (26x24 = **624 bajtu**) do bufferu
`dword_1BB8B0`, ktery MouseInit (sub_123491) nastavuje na `&unk_1B9E38`.
Jenze `unk_1B9E38` (a druhy buffer `unk_1BA0A8`) byly zdekompilovane jako
`_UNKNOWN` = **1 bajt**! Vzdalenost k dalsimu symbolu = 0x270 = 624 -
presne velikost kurzoroveho bufferu. Zapis 624 B do 1B globalu pretekl o
~623 B a KORUPTOVAL sousedni globaly vcetne render vtable (dword_1B920C/
1B9210) -> pad.

### Oprava

MouseInit ted alokuje oba 624B cursor buffery na HALDE
(`dword_1BB8B0/8B8 = (int)(intptr_t)nmalloc(624)`) misto 1B statickych
globalu. Zamerne NErozsiruji staticke globaly na char[624] - posunulo by
to BSS layout a rozbilo jine mis-sized buffery (overeno: takova zmena
zpusobila jiny pad). Halda = zadny posun layoutu, buffer spravne velky ->
sub_144A91 uz nepretika, vtable zustava intaktni.

Take opraven Hex-Rays uninit-return v `sub_12439D` (`int result = 0`).

### Poznamka k overeni / divergence

Muj lokalni build ma jeste JEDEN pad DRIV nez se sem dostane - v
`sub_128C32` (clear-rect) uvnitr intra (sub_24ED3), pravdepodobne
planarni (mode-X) adresace na plochem SDL framebufferu nebo dalsi
mis-sized/uninit video stav odhaleny mode-5 renderem (vlna 16). Uzivateluv
build se pres sub_128C32 dostane (dosahuje sub_124ECB) - stavy se
rozchazeji. Korekce vtable je ale analyticky prokazana (korupce zmerena
checkpointy) a je to prima oprava nahlaseneho padu dword_1BB89C/894/88C.

### Dalsi krok

Render pipeline v mode 5: sub_128C32 (clear-rect) - overit planarni vs
linearni adresaci na Port::Vga bufferu, clip bounds (dword_1BBA4A/4E/52,
word_1845D8) a screen pitch dword_184532 (stub 0 v link_stubs.c - meho by
mel byt 640/nasobek). Pak dalsi render funkce mode 5.

## Done - wave 18: extracted state/settings block 0x199BDC..0x199E05 into a struct

(From this wave on, PROGRESS.md entries are written in English, per the
updated prompt.md rule. Older Czech entries are kept as-is.)

Refactoring task (readability, not a bug fix), same spirit as
`TypeSaveSlotInfo_199699`: the 553-byte region `0x199BDC..0x199E05`
(byte_199E05 is the next symbol; 0x199E05-0x199BDC = 0x229 = 553) was a
long list of ~52 individual IDA globals (byte_/word_/dword_/algn_) with
gaps. Extracted into one packed struct **`TypeStateBlock_199BDC`** in
orion_common.h, with a single instance `stateBlock_199BDC` in orion_data.c.

- **Member names keep the absolute address** for future navigation:
  `b_199CAE` (language byte), `d_199BFC`, `w_199CBA`, arrays `b_199C2B[30]`
  etc. IDA gaps are `reserved_XXXXXX[N]`; the one alignment filler is
  `algn_m_199BFA[2]`.
- **Old symbol names stay valid** via `#define byte_199CAE
  stateBlock_199BDC.b_199CAE` (52 macros), so all existing decompiled code
  compiles unchanged - same overlay technique as waves 11/12/17.
- `#pragma pack(push,1)` guarantees the exact original layout; the 52
  `extern` declarations were removed from orion_common.h.

Safety checks before the change: no link_stubs.c duplicates, no
cross-symbol pointer arithmetic (`&byte_199... +/- N`), arrays only used
by address. Build is clean and runtime behavior is **identical** - the
game reaches the exact same point (sub_128C32 in the intro, wave 17), so
the extraction introduced no regression. Making the region contiguous
(as it was in the original binary) is also safer than separate globals
for any future raw-offset access.

DECOMP_TODO: the block mixes settings loaded from MOX.SET (language
b_199CAE, palette b_199CB0..b_199CB5, flags), so a good future step is to
rename members to their meaning once each is understood, keeping the
address suffix.

## Done - wave 19: int386 REGS-buffer overflow zeroed dword_1BB8C0 (crash in sub_138CEE)

### Symptom

Crash in `sub_138CEE` (per-row clip-span writer): it takes the
`dword_1BBA28 != 2` branch and writes to `v7 = dword_1BB8C0 + 4*a2`, but
**dword_1BB8C0 was 0 (NULL)** -> write to NULL -> crash. Both clip buffers
(dword_1BB908, dword_1BB8C0) are allocated only in `sub_12537D`.

### Diagnosis (checkpoints + DOSBox compare)

- Right after `sub_12537D` both pointers are valid (checkpoint).
- By `sub_138CEE` dword_1BB8C0 is 0 -> **memory corruption** zeroes it.
- DOSBox DUMPMEM confirmed the original keeps dword_1BB8C0 valid
  (0x00451054), so the port corrupts it - not a control-flow difference.
- Bisected the corruption to **MouseInit (sub_123491)**.

### Root cause

MouseInit calls `int386(51, &dword_1BB8E0, &dword_1BB8E0)` (INT 33h mouse)
~15 times. The port's `PortDos_Int386` (wave 13) writes the full register
set back - **24 bytes** - to the output buffer `&dword_1BB8E0`. In the
original, dword_1BB8E0 is the start of a Watcom `union REGS` (28 bytes:
eax/ebx/ecx/edx/esi/edi/cflag). IDA split it into separate 4-byte globals
(dword_1BB8E0/8E4/8E8/8EC/8F4) which the port packs consecutively, so the
24-byte write overflowed past them into neighbouring globals (dword_1BB8FC
framebuffer ptr, and - via the port's BSS layout - dword_1BB8C0).

### Fix (overlay, same technique as waves 11/12/17/18)

Replaced the 5 fragmented REGS globals with one contiguous
`int regsBlock_1BB8E0[7]` (28 bytes = 0x1BB8E0..0x1BB8FC), old names mapped
by macros (dword_1BB8E0 -> [0], ...E4 -> [1], ...E8 -> [2], ...EC -> [3],
...F4 -> [5]). Now `&dword_1BB8E0` is a 28-byte buffer and int386's 24-byte
write is fully contained. dword_1BB8FC (a separate framebuffer pointer) is
left as its own global just past the buffer.

Note: the other global REGS buffer passed to int386, `byte_1BB8C4`, is
already `char[28]` - big enough, no change needed.

### Result

dword_1BB8C0 now stays valid; **sub_138CEE runs and completes** (both
intro calls). The crash moved further into the intro render fill
(sub_128C32 -> sub_14759C, which uses screen pitch `dword_184532` - still a
stub 0 in link_stubs.c; should be the row stride). That is the next item.

## Done - wave 20: sub_14852C int64 argument fusion + qmemcpy stub + font block overlay

Reported symptom: access violation in `sub_14852C` with a nonsensical `a1`
(int64) and a read at address 0x2. Three independent root causes were found.

### 1. sub_14852C / sub_1485B3 - fake int64 parameter (the reported crash)

IDA typed both blitters as `int64_t __fastcall sub_14852C(int64_t a1, int a2)`.
The original register signature, **recovered from the running game**
(DUMPREGS at the entry point + disassembly of the function and of all four
call sites), is actually three separate register arguments:

```
eax = x, edx = y, ebx = pointer to the sprite data    (return value unused)
```

IDA fused eax:edx into one fake `int64` and then **lost the argument setup at
every call site** - the decompiled callers passed unrelated leftover locals
(`sub_14852C(v3, (int)v4)`, both "possibly undefined"), which is where the
garbage pointer came from. On x64 the fused form was broken anyway, because
`(char *)(a1 + ...)` keeps `y << 32` inside the 64-bit pointer (the original
32-bit code truncated it naturally into `edi`).

Fixed: both functions now take `(int x, int y, <data>)` and return `void`;
all 8 call sites were rewritten from the original asm
(`sub_12C7CC`/`sub_12D408`: x=0, y=0; `sub_129FF9`/`sub_12A478`: x=(int16)a1,
y=(int16)a2). Pointer arithmetic goes through `intptr_t`.

### 2. qmemcpy was a no-op stub

`int qmemcpy(void) { return 0; }` in link_stubs.c - but qmemcpy is just
Hex-Rays' name for `memcpy` (rep movsd/movsb), used at 100+ sites including
the RLE blitter above. Every one of those copies silently did nothing, so
even a fully fixed blitter would have drawn an empty screen. Now a real
`memcpy` wrapper.

### 3. Font data block 0x1B3E7C..0x1B61D8 (9052 bytes) - overlay

`sub_120526` loads a whole 9052-byte font record with
`sub_12779E(byte_1B3E7C, v4, 0x235C)`, but IDA had split that region into ~21
separately used globals and declared `byte_1B3E7C` as **`char[6]`**. The copy
therefore overflowed and wiped everything behind it - including
`dword_1B3E78` (the font sub-pool), which was then passed as NULL into
`sub_126AFD -> sub_126CEB -> sub_111188`, whose first statement is
`*(_DWORD *)(a1 - 12) = 0` -> write near address 0 -> crash.

Verified against DOSBox: the original keeps `dword_1B3E78 = 0x004EE05C`.
Fixed with one contiguous `char fontBlock_1B3E7C[9052]` plus offset macros for
all 21 old names (same technique as waves 18/19). Layout verified: every
symbol span matches its successor's address, total exactly 9052.

### Result

`dword_1B3E78` now survives (checked at allocation, after RunGameAndExit and
at the tail), `sub_1205E6` completes, and execution reaches the intro again -
back to the known frontier inside `sub_24ED3` (wave 17/19 territory), which is
the next item.

## Done - wave 21: mode-5 prezentace psala 300 KB pres 1B symbol loc_9FFFD

Symptom: "dword_1BB90C neni naplneno spravnymi hodnotami" v sub_1255DF. Skutecna
pricina byla na druhe strane kopie: `dword_1BB910[0] = &loc_9FFFD + 3` (=0xA0000,
VESA okno A000:0000), jenze loc_9FFFD je v portu 1bajtovy `_UNKNOWN` v BSS -
prezentacni funkce pres nej kopirovaly cely obraz a prepisovaly sousedni globaly.
K tomu dva dalsi IDA artefakty stejne tridy jako drive: konstanty 0x10000/0x20000
prelozene jako `sub_10000`/`loc_20000` (krok VESA banky, zdrojove offsety).

Reseni (linearni framebuffer misto bankovaneho okna):
- `port_vga` povysen na 640x480 (vynuceny VESA mod 5, vlna 16); novy pristup
  `Port::Vga::Framebuffer()` / `PortVga_Framebuffer()`. Zaloha 5x64 KiB
  (327680 B) - bankovane kopie smely adresovat cele posledni okno.
- OPRAVA (nasledny nalez): framebuffer NESMI byt staticke C++ pole! Ukazatel se
  uklada do 32bit intu (`dword_1BB910[0] = (int)PortVga_Framebuffer()`), ale
  staticke pole zije v datovem segmentu modulu (x64 image base ~0x140000000 =
  >2 GB) -> `(int)` cast ho oreze na 0 -> sub_138CE0 dostal `result=0` a
  kopiroval 300 KB na NULL. Fix: framebuffer z HALDY (`calloc`), ktera pod
  /LARGEADDRESSAWARE:NO lezi v dolnich 2 GB - stejne jako dword_1BB90C z
  PoolAlloc. Overeno: `1248AB.fb_ptr_as_int = 0x18398000` (nenulove, <2 GB).
  Toto je tretí vyskyt "32bit int drzi pointer" pravidla (viz LAA:NO v hlavicce).
- `dword_1BB910[0]` (sub_1248AB) ukazuje na tento framebuffer.
- Mode-5 prezentacni trojice prepsana linearne (bankovani dword_1BB8A4 je
  v portu no-op int10h stub, NELZE ho emulovat zmenou dword_1BB910 - funkce
  si ukazatel okna cachuji pred prepnutim banky):
  - `sub_1255DF` (cely obraz): 4x64+44 KiB pres banky -> jedno memcpy 307200 B
    (`sub_138CE0(dst,src,n)` kopiruje `n<<10` bajtu; 300<<10 = presne 640x480).
  - `sub_12567F` (spinave useky, tabulka dword_1BB8BC [skip,len]* v DWORDech):
    dst offset == src offset, wrap po 0x4000 DWORDech odpadl.
  - `sub_125814` (radkovy dirty-present, dword_1BB908 = min/max sloupec na
    radek): jednotna smycka pres 480 radku misto 5 rucne delenych bank.
- Smoke test: hra nyni projde inicializaci az do smycky hlavniho menu
  (tail.before_switch1) bez padu; predchozi pad v sub_128C32 zmizel (zapisy
  smerovaly do tehoz rozbitteho okna).

Zbyva ze stejne tridy: prime pouziti `&loc_9FFFD` a `sub_10000`-jako-0x10000
v orion_part_21.c (~3473-3740, cinematic/SMK prehravac, 16bit aritmetika nad
ukazateli) - potreba az pro intro bez REORION2_SKIPINTRO.

## Done - wave 22: sub_1276F0 bit-test returned 0 (pusha/popa artifact) + fb heap

Two fixes this session.

1. **Framebuffer must be heap, not a static array** (follow-up to wave 21):
   `dword_1BB910[0] = (int)PortVga_Framebuffer()` stores a pointer in a 32-bit
   int. A static `std::array` lives in the module data segment (x64 image base
   ~0x140000000 > 2 GB) so `(int)` truncated it -> sub_138CE0 got result=0 and
   memcpy'd 300 KB to NULL. Fixed: framebuffer via `calloc` (low heap under
   /LARGEADDRESSAWARE:NO, round-trips through int like every other port buffer).
   Verified `1248AB.fb_ptr_as_int = 0x18398000` (nonzero, < 2 GB).

2. **sub_1276F0 (bit test) returned 0 instead of the bit.** Original asm wraps
   the computation in pusha/popa, which restores eax, so the real function
   stashes the bit in a global (dword_1276EC) and reloads it into eax after
   popa. That global is a register-preservation artifact, read nowhere else.
   Hex-Rays mis-modeled it as `dword_1276EC = bit; return 0;` — so ALL ~30
   callers `(uint16_t)sub_1276F0(base, bit)` were silently reading 0 (every
   bit test in the game returned false). Fixed to `return (*(u8*)(a1 +
   (a2>>3)) >> (a2&7)) & 1;` per Orion2.exe.asm; dropped the artifact global
   dword_1276EC (orion_part_19.c, orion_data.c, orion_common.h).

3. **sub_1694B7 read its destination base from an uninitialized stack slot**
   (root of the user-reported `result=0xCCCCCCCC` in sub_1276BD). sub_1694B7 is
   a __usercall "thunk" with one caller, sub_125D4F (the dword_1BBA28==3 dirty-
   rect flush: copies dirty spans from back buffer dword_1BB8FC to the screen).
   Its body returned `*(a3-4) + 4*offset`; the caller passed `a3 = &savedregs`
   where `savedregs` is Hex-Rays' fake array at [ebp+0], so `*(a3-4)` = *(ebp-4)
   = an uninitialized local of sub_125D4F (debug fill 0xCCCCCCCC). That garbage
   became the destination pointer handed to sub_1276BD's qmemcpy. Fixed:
   sub_1694B7 now takes the base as an explicit parameter (dropped __usercall +
   the a3/savedregs scavenging). CONFIRMED against Orion2.exe.asm (that dump's
   data symbols are shifted -0x8000 vs the IDA/C build): sub_125D4F's prologue
   does `mov [ebp+var_8], dword_1B38FC` (source = dword_1BB8FC) and
   `mov [ebp+var_4], dword_1B390C` (dest base = dword_1BB90C). So the base is the
   PRIMARY back buffer dword_1BB90C, NOT the framebuffer — sub_125D4F composites
   the secondary buffer dword_1BB8FC into dword_1BB90C, which the mode-5 present
   sub_1255DF later blits to screen. My first guess (framebuffer dword_1BB910[0])
   was wrong and showed as result=0 in the user's build; corrected to dword_1BB90C.
   Lesson: when Hex-Rays hides a base behind `*(a3-4)`/savedregs, the real init
   (`mov [ebp+var_4], <global>`) is in the function prologue in the asm — read it
   there rather than guessing.

Note on 0xCC vs 0xCD: 0xCC = uninitialized STACK (Hex-Rays "possibly undefined"
local / fake savedregs BYREF), 0xCD = uninitialized heap. Both point at
mis-modeled data flow, not a real game bug.

My build still hangs earlier in the font renderer (sub_1212B3/sub_122309) and
never reaches sub_125D4F, so the 125D4F dump only fires on the user's build.

## Done - wave 22c: AIL_allocate_sample_handle wrapper dropped its return value

Access violation in sub_1579F0 (AIL_register_EOS_callback) writing *(a1+0x850)
with a1 = uninitialized stack garbage. Traced the handle back:
  sub_140C96 (AIL_allocate_file_sample trace wrapper)
   -> sub_1580A3 (impl): `sub_140BB1(a1); v5 = v4;`  <- v4 "possibly undefined"
   -> sub_140BB1 (AIL_allocate_sample_handle trace wrapper)
   -> sub_157610 (real allocator, returns int* sample slot or 0)
Root cause: sub_140BB1 was typed `void __cdecl` and its two JUMPOUTs (0x13FA33 /
0x13FCD2) hid the shared trace epilogue `dec dword_1C0E40; mov eax,esi; retn`
(Orion2.exe.asm) — so it never returned sub_157610's handle. sub_1580A3 then read
an unassigned v4 (eax leftover) as the sample handle and passed the garbage to
sub_141F1F -> sub_1579F0. Fixes: (1) sub_140BB1 now returns int (captures the
handle, `--dword_1C0E40` for the epilogue, JUMPOUTs removed); (2) sub_1580A3 does
`v4 = (int*)sub_140BB1(a1)`; (3) header decl void->int. Verified against asm;
other 3 callers ignore the return (fine). With sub_157610 returning 0 when the
driver is exhausted/invalid, sub_1579F0's `if(a1)` guard now safely no-ops
instead of writing through junk.

Class reminder: a wrapper typed `void` that ends in JUMPOUT to a shared epilogue
usually DID return a value (eax/esi) via that epilogue — check the asm epilogue
(`mov eax, <reg>; retn`) and restore the return type + value.

Follow-up (same wave): started retyping the AIL sample handle from `int` to a
real pointer. Extracted a rough `AilSample` struct (2196 bytes) in
orion_common.h with the fields identified so far (alloc_flag@+4,
eob_callback@+2124, eos_callback@+2128, and the +2164..+2188 fields set by
sub_1580A3); the rest is reserved padding, filled in progressively. Retyped the
self-contained accessors sub_1579D0 / sub_1579F0 (AIL_register_EOB/EOS_callback)
and the sample setup sub_1580A3 to use the struct (`*(_DWORD*)(h+2128)` ->
`sample->eos_callback`, `v5[547]` -> `v5->status_2188`, ...). Method (per the
user's guidance): when an `int` is clearly a pointer, retype it and pull out a
struct — exactly if the layout is evident, roughly otherwise, and keep adding
members as more access sites are decoded. Casts at the `int`-typed boundaries
(sub_140DFC/sub_157FB9/sub_157D3C helpers, the sub_140BB1 return) keep the rest
compiling until they too are retyped.

Current frontier (my build): hangs in sub_1212B3 -> sub_122309 glyph loop
(while(1) over string a3; runs forever if the string is not NUL-terminated or
the packed x/y cursor pair dword_1B61E8/dword_1B61E0 is wrong). Next: verify
loadingBuf/kLoadingMsg NUL-termination and the dword_1B61E8/1B61E0 word-pair
overlay (LOWORD=x cursor, HIWORD=y) in sub_122309.

## Done - wave 22d: stripped IDA calling-convention decorators

Removed all 16858 `__fastcall` / `__cdecl` / `__stdcall` / `__thiscall` /
`__usercall` / `__userpurge` tokens from the decompiled sources (orion_part_*.c,
orion_common.h, orion_data.c) via a scripted regex replace. Safe by two
independent reasons: (1) this is an x64 build where MSVC ignores all of these
conventions anyway, and (2) hexrays_compat.h already `#define`s them to nothing.
The #defines are kept as a safety net. Verified: 0 build errors, no runtime
regression, none remain outside the compat header. Signatures now read e.g.
`int sub_1579F0(int a1, int a2)` instead of `int __cdecl sub_1579F0(...)`.
Ongoing: keep new/edited functions decorator-free.

## Done - wave 22f: build divergence explained + framebuffer overlay fix

**Why my build diverged from the user's:** the user builds **x86 (Win32)** and
runs the exe **from `reorion2/reorion2/Debug/`** (where the 373 LBX data files
live). I had been building **x64** and running from a different data dir. On x86
pointers are natively 32-bit, so all the `int`-holds-a-pointer code works without
truncation — my x64-only truncation theories (e.g. the wave-21 static-array
framebuffer) did not apply to the user's build. Build `-p:Platform=x86` and run
from `Debug/`; without REORION2_SKIPINTRO the intro runs and reproduces the
user's crash exactly (segfault in the intro sprite blit).

**Real bug found and fixed — dword_1BB910/dword_1BB914 must be one array.**
The original 0x1BB910..0x1BBA13 is a contiguous 65-int table: [0] is the
screen/framebuffer pointer, and dword_1BB914 aliases &table[1].
`dword_1BB914[k] = dword_1BB910[k]` (orion_part_20.c ~4069) is really
`table[k+1] = table[k]` propagation. IDA split it into `int dword_1BB910[]`
(tentative -> int[1]) + `int dword_1BB914[64]`, non-adjacent in the port, so the
indexing ran out of bounds and corrupted neighbours — including zeroing the
framebuffer pointer in [0] between sub_1248AB (which set it) and the intro's
first present (which read 0 -> present to NULL). Fixed with an overlay:
`int screenPtrs_1BB910[65]` + `#define dword_1BB910 screenPtrs_1BB910` +
`#define dword_1BB914 (screenPtrs_1BB910 + 1)` (orion_common.h, orion_data.c).
Verified: the framebuffer pointer now survives into the intro
(1255DF.first_dst is non-zero, the NULL-present is gone).

**Remaining intro crash (still open):** after the framebuffer fix the segfault
moved into sub_14852C blitting a fullscreen intro frame. Ruled OUT the earlier
"data not loaded" theory: sub_12C7CC's fread of the frame works
(12C7CC.freadRet=1, firstDword=0 not 0xCD, handle 4 valid, frameSize 309864).
So the RLE data is valid; the crash is in the RLE decode walking past the
~307200-byte backbuffer over 480 rows — a sub_14852C reconstruction subtlety or
a dest-buffer-size issue. Next: row-by-row diagnostics in sub_14852C (dump v2,
rc, v6 per iteration) to find where v2 leaves the buffer, and check the
dword_1BB90C backbuffer allocation size in sub_12537D vs a full 640x480 frame.

## Dalsi rozumny krok (navrh pro pristi session)

0. **AIL/Miles zvuk (sub_111F3E a sub_13Fxxx/140xxx rodina)** - aktualni
   blocker behu (viz vlna 11): napojit na port_sound.cpp (SDL3 audio),
   minimalne tak, aby init "uspel" bez realneho AIL driveru a hra mohla
   pokracovat do menu. Pozor na `v5 = v0` s neinicializovanym v0
   (dekompilacni artefakt - ztracena navratova hodnota sub_1400A9).
1. **fseek/ftell dluh (25 mist)** - viz vyse, nejvyssi priorita, protoze
   tiche cteni ze spatneho ofsetu je zakeznejsi nez pad.
2. **calloc(1,256) verifikace** - dohledat vsechny volajici sub_15E0F0/
   sub_15E124 a zjistit skutecnou max. delku pouzivaneho retezce.
3. **Overit 2 nizko-jistotne fseek rekonstrukce** (viz vlna 07 vyse) -
   `orion_part_19.c` ~5913 a `orion_part_20.c` ~7248 (Play_Sound).
4. Analyzovat `sub_FE8BE` poradne - projit reprezentativni vzorek z 701
   volani, zjistit skutecny ucel, pak teprve prejmenovat. Soucasne overit
   hypotezu o `v3` v `GameMain_10057` (viz vyse).
5. `sub_1AFA0` deklarace vs. definice nesoulad (jeden parametr vs. dva) -
   dohledat spravnou signaturu z volajicich mist (viz vlna 06).
6. Pokracovat grafem volani z `RunGameAndExit_113D47` (hlavni smycka) a
   z volanych funkci uvnitr `ParseCommandLine_107E6` (`sub_10A0E`,
   `sub_10E2F`, `sub_11F11`, `sub_126487`) - to je prirozene pokracovani
   "shora dolu" od vstupniho bodu. `GetGameFlagsTable_F4B81` (vraci
   `&unk_1784DD`) je dobry kandidat na vytknuti struktury - pouziva se s
   fixnimi offsety (610, 621, 712, 721, 732), takze jde pravdepodobne o
   tabulku nastaveni/priznaku hry.
7. Az narazime na dalsi funkce odpovidajici VGA/zvuku/mysi/DOS sluzbam,
   napojit je na prislusny `port_*.cpp`. Totez pro `PoolAlloc_110B89` ->
   `port_memory` (zatim nezavisle vedle sebe, viz vlna 06).
