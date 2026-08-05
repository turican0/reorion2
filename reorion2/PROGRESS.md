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

**Intro crash FIXED — sub_12C7CC fseek was missing the LBX record base.**
sub_12C7CC loads an animation frame from the .LBX and blits it. The frame's
file position is `dword_1BC328 + table[frameIndex]`: dword_1BC328 is the record's
base offset in the archive (set from the LBX directory), table[frameIndex] is the
frame offset relative to the record. The wave-07 fseek reconstruction used only
`*v0` (= table[frameIndex]) and DROPPED the `dword_1BC328 +` base
(Orion2.exe.asm sub_12C7CC: `mov eax, dword_1B4328; add eax, [edx]`). So every
frame was read from the wrong file position -> garbage RLE -> sub_14852C decoded
it and ran ~4 MB past the backbuffer -> segfault. Fixed:
`fseek(dword_1BC338, dword_1BC328 + *v0, SEEK_SET)`. Verified: base 2048 + rel
1048 now seeks to 3096, the loaded frame header/RLE is sane (first RLE word = 640
= row width), and the intro runs to the 30 s timeout with zero segfaults. This is
one instance of the known fseek/ftell debt — check the other ~24 for the same
dropped-base pattern.

**HOW TO REPRODUCE/TEST (critical):** build `-p:Platform=x86`, run from `Debug/`,
no REORION2_SKIPINTRO. GOTCHA: a segfaulting reorion2.exe can linger and hold a
file lock so MSBuild silently does NOT relink (exe timestamp stays old, stale
binary runs). Always `Stop-Process -Name reorion2 -Force` before rebuilding, and
check the exe timestamp is newer than the sources.

## Done - wave 22g: sub_132AF8 palette upload (int64 fusion + DAC port redirect)

Crash `v2 = 0xCCCCCCCC` in sub_132AF8 (VGA DAC palette set). Two problems, both
as the user guessed: (1) `int64_t a1` was IDA's fusion of two register args, and
(2) the hardware port writes went nowhere. Recovered the real signature from
Orion2.exe.asm (`mov esi,eax; mov ecx,ebx; mov ebx,edx`): eax = palette data
pointer, ebx = count, edx = start index. The single caller sub_131F7B never set
the fused low half (the pointer), so it read 0xCCCCCCCC. Fixes:
- sub_132AF8 signature -> `void sub_132AF8(unsigned int *paletteData, int count,
  int startIndex)`; body replaced the 0x3C6/0x3C8/0x3C9 DAC I/O (hr_outbyte is a
  no-op stub) with PortVga_SetPaletteEntry, scaling the 6-bit DAC values to 8-bit
  ((v<<2)|(v>>4)). Entry layout: dword [flag, R, G, B].
- new C bridge PortVga_SetPaletteEntry in port_vga.cpp (-> Port::Vga::SetPaletteEntry).
- caller sub_131F7B: pass `&byte_1BB358[4*index], count, index` (from the asm);
  its fused `int64_t v1` counter cleaned up to a plain `int index`.
Verified vs asm; builds; the palette crash is gone and the intro now presents
(the palette actually reaches the SDL framebuffer for the first time).

**New crash after this (open):** with the palette set, the intro renders a few
frames (multiple sub_138CE0 300 KB presents + sub_125814) and then segfaults in
the present path — a fresh issue further along, no longer in sub_132AF8. Next:
strip the now-noisy wave-21/22 present diagnostics (1248AB.fb_ptr, 1255DF.*,
138CE0.*, 125814.*) for a clean trace, then bisect the present loop.

## Done - wave 22h: three more fseek dropped-base bugs (sub_12A914 crash)

Crash in sub_12A914 (`v13 = 0xffffd382`, a negative word index into a3). Verified
sub_12A914's decode is FAITHFUL to Orion2.exe.asm (stride = HIDWORD(qword_184530)
= 640, else-branch *640, `v13 += (v18+1)/2` with signed v18, v18/v4 reads all
match). So the decode was fine; v13 only goes negative when v18 (a signed run
length read from a3) is garbage -> the frame data a3 was wrong. Same class as
the sub_12C7CC fseek-base bug. Traced a3 to its loaders and fixed three more
dropped-base fseeks (all verified against asm):
- sub_12CAD6: `fseek(dword_1BC310[a1], dword_1BC348[a1] + *v2, ...)` (per-file
  base array dword_1BC348[a1], multi-file animation).
- sub_12CD2D: `fseek(dword_1BC338, dword_1BC328 + *v0, ...)` (single base, like
  sub_12C7CC).
- sub_12D408: `fseek(dword_1BC310[a1], dword_1BC348[a1] + *v2, ...)` (twin of
  sub_12CAD6).
(Checked but CORRECT as-is: orion_part_20.c:1029 seeks to the record base v9 to
read the 2730-byte record header — no relative frame offset there.)
Result: the intro animation now runs the full timeout with ZERO segfaults (it was
crashing on the very first frames). This is the biggest milestone yet — the intro
plays. Note: dropped-base fseek is now fixed in FOUR functions
(sub_12C7CC/12CAD6/12CD2D/12D408); the remaining fseek/ftell-debt sites use other
handles (dword_1BC26C in orion_part_19) and still need per-site asm checks.

Graphics-shift question (user): the shift was almost certainly the garbage frame
data from the wrong fseek; with the base fixed the decode gets the real frames.
Can't confirm visually from the headless build here — needs an eyes-on run.

## Done - wave 22i: intro no longer hangs (Miles timer sub_149A20)

The intro hung at the end in sub_149A20's `while(1)`. It is the Miles Sound
System timer install: the original probed for a Windows sound VxD via `int 2Fh`
(AX=1684h); if found (ES:DI != 0) it took loc_149A77 — record the timer callback
in dword_18A5AC and return; otherwise it installed a raw DOS PIT timer ISR
(out 0x43/0x40) and spun in `while(1)` until that interrupt fired. In the port
int 2Fh is a stub, so byte_1C3C22 stayed 0 -> the DOS path -> infinite spin (no
PIT, no ISR ever fires). Fixed: take the "VxD present" path unconditionally
(`dword_18A5AC = sub_149B10; return;`) — a modern OS owns timing. The hang is
gone; execution now proceeds past the intro (and hits the next present-path crash
below). Sound timing itself is still not wired up (see port_sound) — that's issue
#3 and expected for now.

Open issues from the eyes-on run (user, wave 22i):
- #1 graphics is shifted, and #2 animation frames are not smooth / some seem to
  be missing. Both are rendering-correctness, most likely in the wave-21 LINEAR
  present rewrites (sub_1255DF/12567F/125814 assume a flat 640x480 framebuffer;
  the original was VESA-banked) or a decode stride. Needs a focused review of the
  present path against the asm, with an eyes-on run.
- New crash after the intro, again in the present path (last checkpoints
  138CE0/125814). Next: strip the noisy wave-21/22 present diagnostics
  (1248AB.fb_ptr, 1255DF.*, 138CE0.*, 125814.*, 12567F.*) for a clean trace,
  then bisect.

## Done - wave 22j: sub_1694D9 clamped to the wrong (VGA-segment) address

Found while chasing the post-hang intro crash / the graphics shift. sub_1694D9
is the clamped dword-copy used by sub_125814 (the row/dirty-span present). The
original clamped writes to the 0xA0000..0xBFFFC VGA window: an out-of-range dest
was snapped to `&loc_BFFF4 + 8` (= 0xBFFFC, the last valid VGA address) and the
length forced to 1. In the port the framebuffer is a heap buffer FAR above
0xBFFFC, so `a1 >= 0xBFFFC` was ALWAYS true -> every sub_125814 dirty-span write
went to the 1-byte BSS symbol loc_BFFF4 instead of the screen. Effect: the
incremental (dirty-span) frame updates were silently dropped and loc_BFFF4's
neighbours got corrupted -> exactly the user's #1 shifted / #2 missing-frames
symptoms. Fixed: clamp against the real framebuffer [PortVga_Framebuffer(),
+640*480) instead of the hardcoded VGA window; out-of-range dest is dropped,
length clamped to the framebuffer end. Verified sub_125814 now runs to
completion (was implicitly crashing/corrupting before). This is the same family
as sub_1694B7 (wave 22b) — VGA-segment helpers with hardcoded 0xA0000/0xBFFFC
limits that must be re-based onto the port framebuffer.

Status after this: the intro renders the first frame's presents cleanly and
sub_125814 completes; a segfault still follows LATER (after the first frame, no
checkpoint there — likely a subsequent frame or the intro loop sub_24ED3 body).
Eyes-on check recommended: with the dirty-span present now hitting the real
framebuffer, the shift/missing-frames (#1/#2) should look markedly better.
Next: put a frame counter inside the intro loop sub_24ED3 (not sub_12CAD6 —
that's never called on this path) to localise the remaining crash.

## Done - wave 22k: memset32 was a no-op stub (root of the top-row garbage)

Used the dosbox-x DUMPMEM harness (genCompare/, runtime = IDA + 0x224000 code /
+ 0x216000 data) to compare the first-frame state. Original backbuffer top rows =
0x00000000, dirty table = 0x009F0000; the port had 0xCDCDCDCD backbuffer and
0x009FCF0D dirty table. Cause: **`memset32` was a no-op stub in link_stubs.c**
(`int memset32(void){return 0;}`), so every buffer the game clears via sub_127678
(backbuffers, dirty tables, palette fills, VESA blocks) stayed at the debug-heap
fill 0xCDCDCDCD -> garbage top rows (the "extra line"), wrong dirty spans, and the
earlier intro crashes. Implemented it for real (fill count dwords with val).

Making memset32 real exposed a cascade of latent bugs it had been masking, all
now fixed:
1. int386x register block (sub_145FD2/1460C1/1461F0): IDA split one ~50-byte
   stack block into a short `char v1[]` + separate locals v2/v3/... which are
   really FIELDS at v1+20/+24/+28/+34. The 0x32 (50-byte) memset overflowed the
   undersized array -> MSVC /RTC stack-check blocked (looked like a hang).
   Modeled as `Int386xRegs` struct (orion_common.h) so the fields sit at their
   true offsets and the memset stays in bounds.
2. VESA mode values: int386/int386x are no-op stubs, so the mode-info block stays
   zeroed and sub_1460C1/sub_1461F0 returned 512/0 instead of the mode-5 values.
   The 0 caused `word_1BBA5C = 64 / word_1BBA56` to divide by zero (exit 127).
   Hardcoded the correct forced-mode-5 returns (2048 / 64), verified via dosbox
   DUMPMEM (word_1BBA62 = 0x800, word_1BBA56 = 0x40). Consistent with wave 16.
Result: the intro runs to timeout with ZERO crashes and the backbuffer is now
correctly zeroed (verified: backbuf_dw0 = 0, matching dosbox) -> the "extra line"
top garbage (#1) should be gone.

Residual (open): the dirty table still reads 0x009EFF00 vs dosbox 0x009F0000 (low
word 0xFF00 vs 0, high 158 vs 159) — a small dirty-span discrepancy that may still
show as the #2 top-jump on incremental (sub_125814) frames. The full-frame present
(sub_1255DF) is correct, so the first frame is right. Needs an eyes-on check now;
if the top-jump persists, chase the dirty-tracking (sub_138CEE) that fills
dword_1BB908.

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

## Done - wave 23: x86/x64 crash bisection through GameMain tail -> main menu entry

Ukol teto session: "zamer se na x64, testuj rozdily x86 vs x64 vs dosbox,
postupuj funkci po funkci od main()". Zjisteni #1 (dulezite): **x86 a x64
Debug build padaly na UPLNE STEJNEM miste** - vsechny nove nalezene bugy v teto
vlne jsou tedy spolecne oběma platformam, ne x64-specificke. x64 build sam o
sobe funguje (jen desitky tisic C4311/C4312 pointer-truncation warningu -
budouci prace, viz nize).

### Diagnosticka infrastruktura (nova, trvala)
- `src/reorion2.cpp`: `AddVectoredExceptionHandler` vypisujici pri neosetrene
  SEH vyjimce `SEH code=... addr=... av_read/write=... module=... rva=...` na
  stderr - drive jsme meli jen "exit code 3" bez jakekoliv diagnostiky.
  Definovano PRED `#include "game/orion_common.h"`, protoze
  `hexrays_compat.h` prepisuje `fflush`/`fprintf`/`__stdcall` na PortFile_*/
  prazdno (funkcni jen pro dekompilovany kod, ne pro tento nativní Win32 kod).
- `reorion2.vcxproj` (Debug|Win32): `<BasicRuntimeChecks>Default</BasicRuntimeChecks>`
  (vypnuty /RTC) + `<GenerateMapFile>true</GenerateMapFile>`. Duvod: /RTC na
  poskozeni zasobniku vola primo `abort()` (exit 3) BEZ SEH vyjimky a BEZ
  zpravy na stderr - naprosto nediagnostikovatelne. S /RTC vypnutym stejny bug
  projde dal a spadne jako normalni access violation, ktere uz nas handler
  zachyti a popise. Kompromis: /RTC dava lepsi ochranu pro finalni build, ale
  behem aktivniho hledani bugu je "tichy abort" horsi nez viditelny AV.
  Ponechano vypnute pro dalsi debugovani; zvazit znovu zapnout pred vydanim.
- Postup lokalizace pádu z `SEH ... addr=X module=reorion2.exe rva=Y`: `Y +
  0x400000` (preferovana base linkeru) se hleda v `Debug/reorion2.map` (sekce
  "Publics by Value") - najde se jmeno funkce a offset uvnitr ni. Pro presnou
  instrukci/radek: `dumpbin /disasm Debug/reorion2.exe` (POZOR: v Git Bash
  pouzit `MSYS2_ARG_CONV_EXCL="*"` pred prikazem, jinak MSYS prevede
  `/disasm` na cestu k souboru a selze to s LNK1181).

### Bug #1 - sub_121DEB/sub_121E85 (font glyph renderer): chybejici horni
### pulka int64 parametru + prohozene registrove argumenty

Prvni pad v teto vlne: `sub_1212B3` (vykresleni "Loading..." textu, volane z
`GameMain_10057` tail) -> `sub_1212EB` -> `sub_121DEB`/`sub_121E85` (font
plotter). Hex-Rays u obou uplne vynechala vypocet `HIDWORD(v5)` (zdrojovy
ukazatel do komprimovanych dat fontu) - `sub_1449CC`/`sub_144A06` maji
`int64_t a1`, ktery je ve skutecnosti EDX:EAX par (EAX=cil v backbufferu,
EDX=zdroj v datech fontu), ale volajici nastavovaly jen LODWORD. Overeno v
`Debug/diss/Orion2.exe.asm` (sub_121DEB @ 0x121DEB): `EAX = dword_1BB904
(backbuffer base) + destOffset`, `EDX = dword_1B3E74 (font base) +
dword_1B3FA8[a3]` (per-glyph offset tabulka). Bez toho byl zdrojovy ukazatel
nedefinovany smetí -> pad na prvnim vykreslenem znaku.

Druhy vrstevnaty bug ve stejnych funkcich: `sub_1449CC(int64_t a1, int a2, int
a3)` pouziva `a3` jako **citac x86 instrukce `loop`** (`--a3; while(a3)`) a
`a2` jako **tabulku barev** (`*(a2+run-1)`) - ale volajici mely tyto dva
parametry PROHOZENE (`&byte_1B3E7C` poslane jako pocitadlo smycky = miliardy
iteraci -> access violation na konci pameti). Overeno primo v asm prologu
`sub_1449CC` (`mov esi,edx; mov edi,eax; ... loop loc_1449D5` - ECX je
implicitni citac `loop`, coz odpovida `a3`; EBX pouzite v `[eax+ebx-1]`
odpovida `a2`). Opraveno v `orion_part_19.c`.

### Bug #2 - dalsi vlna "pole velikosti 1" (fontBlock-style truncation),
### tentokrat v tech-tree tabulkach `sub_5E1E3`

Po opravě #1 pad postoupil do `sub_13174` -> `sub_5E1E3` (inicializace
tech-tree kategorii, volana z GameMain tail pred hlavnim menu). Root cause:
**osm globalnich tabulek** (`word_17EB43`, `word_17EEE6`, `word_17F63E`,
`word_17F6A7`, `word_17F80D`, `word_17F819`, `word_17FDF2`, `word_17FE76`,
`word_17FFE8` - devet, oprava chyba v puvodnim poctu) deklarovanych jako
1-prvkove skalary/pole, pouzivanych pres `*(int16_t*)((char*)&word_X +
STRIDE*i)` s STRIDE 11-59 a i az do ~45 (byte-offset aritmetika, ne pole-index
- klasicky fontBlock/Int386xRegs vzor). Cteni za koncem vratilo smeti, ktere
se vynasobilo 13 a pouzilo jako index do `byte_17E085[]` (rovnez 1-bajtove
pole misto skutecne 13-bajtove-zaznamove tabulky, velikost overena v asm
gapem k `dword_176B2A` = 2725 bajtu) -> zapis daleko mimo pole -> pad uvnitr
CRT (ne primo v nasem kodu - proto prvni pokus s dumpbin na nas modul
neuspel, EIP byl jinde, az druhy pokus s cerstvym mapem ukazal spravne
`sub_5E1E3`). Opraveno: vsech 9 tabulek zvetseno na 1024 prvku (nulovano -
**datova mezera**: puvodni obsah tech tabulek jeste neni obnoven, jen
velikost je bezpecna) + `byte_17E085` na 2730 bajtu.

### Bug #3 - `dword_1A6578[368]` prilis male pole (potvrzeny skutecny limit
### v asm) a nesmyslna DOS-layout kontrola

`sub_CDF65` (nacitani lokalizovane string-tabulky estrings.lbx) pise index
0..0x32Bh (811) do pole deklarovaneho na 368 prvku - **v asm primo overeno**
(`cmp eax, 32Ch`), 368 byl jen gap k nahodnemu sousednimu BSS symbolu.
Zvetseno na 812. Soucasne `if (a3 > (char*)dword_1A6578) sub_126487(...)` je
nesmyslna v modernim portu: puvodne to byla adresova sanity-kontrola zavisla
na konkretnim DOS4GW pametovem rozlozeni (a3 = heap ukazatel z PoolAlloc,
dword_1A6578 = staticke pole - v nasem procesu heap adresy typicky VZDY vetsi
nez staticky segment, takze kontrola by falesne padala vzdy). Odstranena s
komentarem; skutecnou ochranu proti pretečeni ted da spravne velike pole.

### Bug #4 - `dword_1A6B38` pouzivan jako pointer, ale byl to jen `int`=0
### (NULL pointer write)

Dalsi krok v `sub_CDF65`: `v6 = (_DWORD*)dword_1A6B38; *v6 = ...` kopiruje
13-bajtove lokalizovane jmeno LBX souboru (napr. "MAINTEXT.LBX\0") do `*v6`.
`dword_1A6B38` byl ale jen `int` inicializovany na 0 a NIKDE v cele hre
nenastaveny na skutecnou adresu -> zapis na NULL. Reseni: `dword_1A6B38` neni
pointer na buffer nekde jinde - je to SAM buffer (potvrzeno: v cele hre se
nikde jinde necte, jediny XREF v asm je tato jedna zapisova instrukce) -
predefinovano jako `char dword_1A6B38[16]`.

### Vysledek vlny 23

Pad postoupil z `sub_1212B3` (font renderer, uplne na zacatku GameMain tail)
az do `sub_1171AB` volane z hlavniho menu (`sub_1049B`) - tj. cely usek
"font -> tech tabulky -> string tabulky -> pred menu" ted bezi bez padu.
Novy frontier: READ access violation v `sub_1171AB` (jeste neanalyzovano,
dalsi session). x86 i x64 potvrzeny na stejnem miste pred kazdou opravou.

Zpusob prace (na zadost uzivatele): pri kazdem nalezu nejdriv staticky
overit proti `Debug/diss/Orion2.exe.asm` (asm je "zive" ground truth primo z
originalu, netreba pokazde spoustet dosbox), pak az kdyz je potreba
RUNTIME hodnota (ne jen velikost/rozlozeni), pouzit dosbox-x DUMPMEM/DUMPREGS
dle `c:\prenos\dosbox-x-remc2\genCompare\DOSBOX_CTL_PROTOCOL.md`.

## Done - wave 23b: x64 branch is primary now - real x64-only bug found + fixed

Uzivatel pozadal pokracovat primarne na x64 vetvi (x86 uz jen jako pomocna
rychlejsi iterace). Pridano `GenerateMapFile`/`BasicRuntimeChecks=Default` i
do Debug|x64 (stejna diagnostika jako x86 z vlny 23).

**Prvni skutecne x64-specificky bug teto session:** `sub_1449CC`/`sub_144A06`
(RLE font-glyph dekoder, opraveny volajici v bug #1 vyse) na x64 padaly s
`av_read=0xFFFFFFFFFFFFFFFF`. Pricina: `int64_t a1` packing dvou 32bit
ukazatelu (dest v LODWORD, zdroj v HIDWORD) je trik, ktery funguje POUZE na
x86, kde skutecny ukazatel je 32bit - LODWORD/HIDWORD pulka `int64_t` presne
odpovida velikosti pointeru. Na x64 je ukazatel 64bit, takze `*(_BYTE*)v3`
(primy cast CELEHO 64bit `v3` na pointer) dereferencoval OBE slozene
32bit hodnoty najednou (zdroj<<32|cil) misto jen cilove adresy. Fix: cilovy
zapis explicitne `*(_BYTE *)(uintptr_t)LODWORD(v3) = ...` v obou funkcich -
vynuti oriznuti na spravnou pulku pred pointer-castem na obou platformach
(cteni pres `HIDWORD(v3)` uz bylo spravne, protoze HIDWORD makro vraci
obycejne `unsigned int`, ne reinterpretaci cele 64bit hodnoty). Overeno:
x64 build ted projde CELYM font rendererem (drivejsi x64 frontier byl
DRIV nez na x86 - `tail.before_switch1`, ted az za `tail.after_FE8BE2`).

**`sub_144A91`/`sub_144EAC`/`sub_14529D`** (mysi kurzor renderer, video mod 5,
`dword_1B920C` vtable, `sub_125064` case 5) pouzivaly stary VESA-bankovany
adresovaci model: `&loc_9FFFD` = falesna VGA-okno adresa 0x9FFFD (+3 =
0xA0000 vsude v kodu), stejna trida bugu jako drive opravene
`sub_1694D9`/`sub_1694B7` (vlna 22j/22b). Fix: vsech 21 vyskytu primeho
`(char*)&loc_9FFFD` prebazovano na `((char*)PortVga_Framebuffer() - 3)`
(sed nad orion_part_21.c). **Otevrene:** 12 vyskytu vzacneho bank-crossing
podvetve pouziva `(uint16_t)&loc_9FFFD` (16bit segment-offset trik bez
modernich ekvivalentu) - nedotcen, netrigroval se v aktualni bisekci.

**`sub_10000`/`loc_20000`** - DALSI instance "IDA spletla konstantu s
adresou" (jako drivejsi `0x64000`/`&loc_63FFB+5`). `sub_10000` byl v
orion_common.h deklarovany jako FUNKCE, ale v link_stubs.c jako `int
sub_10000;` (=0, typovy konflikt mezi TU!) - vsech ~90 pouziti v 10
souborech ho ale pouziva cisteji jako HODNOTU 0x10000 pres cast
(`(unsigned int)sub_10000`), nikdy nevolaji. Na x64 `(int)funkce` beztak
nedava 0x10000 (zavisi na linkerove adrese, ne na hodnote). Fix: predeklarovano
jako `extern const int sub_10000;` / `const int sub_10000 = 0x10000;` -
opravi VSECHNA pouziti najednou beze zmeny volajicich. `loc_20000` (jen 2
pouziti) opraveno primym nahrazenim `0x20000` literalem.

**`dword_1ACF14`/`dword_1ACF0C`/`dword_1ACF08`/`dword_1ACF04`/`dword_1ACEFC`/
`dword_1ACF00`/`dword_1ACF10`** (orion_part_17.c, text/edit-field parser
kontext) - `sub_104C31` uklada adresy SVYCH LOKALNICH bufferu (`&v19`, `v15`,
`v16`, `v18`, `&v17`) do techto 7 globalu deklarovanych jako `int`, ktere
pak destitky dalsich funkci v souboru cti pres byte-offset
(`*(WORD*)(dword_1ACF14+N)`). Na x86 to prezije (zasobnik pod LAA:NO limitem
podobne jako halda), na x64 zasobnik NENI omezen pod 4GB → truncate →
garbage. Fix: vsech 7 globalu → `intptr_t` (zachova vsechnu existujici
aritmetiku, jen 6 inicializacnich `(int)&x` → `(intptr_t)&x`).

**`sub_126F3B` (LBX loader, pouzivany pres `sub_126C37` mode=2) - DALSI
lost-return-value bug**, stejna trida jako drivejsi AIL wrapper (vlna 22c).
`case 0/1/2` konci `return result;` kde `result` NIKDY neni priразen
(nedefinovana hodnota - u x64 vysla konkretne -1, sign-extended na
0xFFFFFFFFFFFFFFFF). Overeno v asm (`sub_126F3B @ 0x126F3B`): VSECHNY CTYRI
case (0/1/2/3) jen ulozi pointer do `var_C` a skoci na SDILENY epilog
`def_127190` (fread + return) - **zadny early return v originale vubec
neexistuje**. Fix: `return result;`→`break;` u case 0/1/2 (spadnou do
spolecneho `fread(v17,...); return v17;` na konci), `result` smazano.
Tenhle bug byl skryty na x86 (nedefinovany int nekdy nahodou vysel jako
pouzitelna hodnota z predchoziho vypoctu), ale na x64 spolehlive -1 →
segfault v sub_12760B (atoi-like parser volany na vysledek).

**Novy frontier: `sub_12B726`** (jeste neanalyzovano). Pad postoupil skrz
cely `LoadLanguageSetting`-navazany text-parsing kod az sem.

## Rozpracovano - vlna 23c: intro se na konci zasekava (bez REORION2_SKIPINTRO)

Uzivatel nahlasil: "konec intra je zaseknuty, samo to nepokracuje". Bisekce
checkpointy v `sub_24ED3` (orion_part_02.c): **oba animacni while-loopy
(SimTex/MicroProse logo, pak LOGO.LBX) normalne DOBEHNOU** (loop1.exit,
loop2.exit obe s v8=1 = cisty exit). Cely ocas `sub_24ED3` (sub_1113CC,
sub_12D78E, sub_2518F, sub_FE8BE, sub_124D41, sub_128C32, sub_124DEC) take
probehne. **Zasek je uvnitr `sub_14DF7((int)aIntroLbx, 0, 1)`** (posledni
volani, nacita hlavni intro cinematic data) - "24ED3.after_14DF7" checkpoint
se nikdy nevypise. Tesne pred/pri vstupu se opakovane objevuje podezrely SEH
zaznam `code=0xC0000005 addr=0x00007FFE...1800` s **fault-adresa ==
data-adresa** (typicke pro EXECUTE-type access violation, ne read/write -
nas SEH handler to zatim chybne popisuje jako "write", protoze
`ExceptionInformation[0]` muze byt 8 (execute/DEP) ne jen 0/1) - naznacuje
**skok pres poskozeny/spatny funkcni ukazatel**, ne obycejnou nekonecnou
smycku.

Podezrele misto v `sub_14DF7` (orion_part_01.c:4105): `sub_1191CA((int)sub_150E5, 0);`
(radek 4132) - registruje `sub_150E5` jako callback, stejny vzor jako drive
opraveny Miles-timer hang (`sub_149A20`, vlna 22i) - pokud port timer/interrupt
substituce vola tenhle callback pres poskozeny/nespravne ulozeny ukazatel,
vysledkem by byl presne execute-AV. Take na radku 4141: `((unsigned int)&loc_100000 & a2)`
je DALSI instance "IDA spletla konstantu 0x100000 s adresou" (jako
sub_10000/loc_20000 vyse) - v aktualnim volani `a2=0` takze se netrigne, ale
stoji za opravu at nezpusobi problem pri jinych volani (sub_14DF7 se vola i
z orion_part_13.c s ruznymi a2).

**Dalsi krok:** rozebrat `sub_1191CA` (co presne registruje) a `sub_150E5`
(co ten callback dela) - pravdepodobne dalsi instalace "timer/interrupt"
mechanismu analogicka sub_149A20, potrebuje stejny typ fixu (vzit
"VxD/modern-OS-timing" vetev misto DOS interrupt spin).

## Done - wave 24: uzivatel udelal rozsahle vlastni opravy + nalezen masivni
## heap-corrupting buffer overflow (unk_1A1370)

Mezi sezenimi uzivatel sam prubezne opravoval ukazatele/nazvy napric skoro
vsemi soubory (`ServiceAudioTick_FE8BE` = prejmenovany `sub_FE8BE`,
`PoolMemHeader`/`PoolAlloc` opravy, argc/argv, goto cleanup - 20+ commitu).
Pri navratu do session bylo nutne re-synchronizovat: rebuild + cerstvy test
misto pokracovani na starych predpokladech.

**Nalezen a opraven kriticky bug: `unk_1A1370` (orion_part_13.c/orion_data.c)**
- 1-bajtovy `_UNKNOWN` (=`char`) placeholder pouzivany jako PRIMY cilovy
  buffer (zadna cerstva alokace) pro nacteni lokalizovane "estrings.lbx"
  (string tabulka) - vsech 6 volani (`sub_CDF65`, po jednom na jazyk) predava
  **21000** jako velikostni parametr, ale destinace mela jen 1 bajt.
  Klasicky "IDA nedokazala odhadnout velikost bufferu" bug, tentokrat ale s
  VELMI velkym dopadem (~21 KB prepis pres hranici, ne par bajtu jako drive).
- **Zpusob nalezu:** uzivatel nahlasil zaseknuti/pad za menu vstupem; misto
  hadani pridana rada `PortDebug_Checkpoint` volani sledujicich konkretni
  globalni promennou (`byte_19A005`) skrz cely GameMain tail, bisekcne
  zuzeno na jedno konkretni volani (`sub_CDF65`), pak dale na jednu radku
  (`sub_126C91(...&unk_1A1370...)`). Tenhle "sledovat konkretni globalni
  promennou pres radu checkpointu" postup je efektivni pro corruption bugy,
  kde primy crash-site backtrace nikam nevede (protoze padne uplne jina,
  nesouvisejici funkce, ktera jen NAHODOU cte poskozenou pamet pozdeji).
- Dusledek: prepis takhle velkeho rozsahu pravdepodobne poskozoval MNOHO
  dalsich globalu naraz (`byte_19A005`, pravdepodobne i `dword_1A6578`/
  `dword_1A6B38` hned za nim, ktere si `sub_CDF65` sam nastavuje IHNED PO
  tomto volani) - vysvetluje proc predchozi vlny nalezaly tolik zdanlive
  nesouvisejicich "undersized buffer" bugu v teto oblasti; tenhle byl
  pravdepodobne "matka" vsech.
- Fix: `unk_1A1370` -> `char[21000]` (velikost primo z volajicich mist).

**Pomocna diagnostika (trvala):** `PortDebug_CheckpointPtr(name, void*)` v
port_dos.cpp/decomp_compat.h - jako `PortDebug_Checkpoint`, ale pro cele
64bit ukazatele (napr. `_ReturnAddress()` pro zjisteni skutecneho volajiciho
mista bez nutnosti instrumentovat kazde z 100+ volani zvlast).

**Vysledek:** frontier po opravach = `sub_12B726` (write AV na adrese 0x4,
NULL+4 vzor) - **stejne misto jako predtim indikovany task #12** pred touto
odbockou, potvrzuje ze jde o genuinne dalsi bug v poradi, ne artefakt
predchoziho.

## Done - wave 24b: dalsi 2 bugy (unk_1B0848 window-slot pole, off_184480) +
## KRITICKY MILNIK - intro cinematic (Smacker video) konecne nacita data

**`unk_1B0848`/`off_184480`/`off_184484`** (orion_data.c/link_stubs.c) -
DALSI instance stejneho vzoru: `off_184480 = &unk_1B0848` kde `unk_1B0848`
byl jen `int` (4 bajty), ale je to ve skutecnosti **pole 250 "okenních"
zaznamu po 55 bajtech** (13750 bajtu celkem) - overeno primo v asm (gap k
dalsimu symbolu `unk_1ABDFC` = presne 0x35B4 = 13748 bajtu, + soused
`word_18447E = 250` potvrzuje pocet slotu). Pouzivano v `sub_11E718` (a
dalsich) jako `*(TYPE*)((char*)off_184480 + 55*slotIndex + fieldOffset)`.
Nalezeno stejnou `_ReturnAddress()` technikou jako u `sub_12A478` (viz
vlna 24 vyse) - **efektivni pro bugy s destikami moznych volacich mist**.
Fix: `unk_1B0848` -> `char[13750]`, `off_184480`/`off_184484` inicializovany
primo `unk_1B0848` (bez `&`, pole uz je pointer-compatible).

**Zbyvajici otevrene (defensive guard, ne root-cause fix):** i po opraveni
pole samotneho nekdy jednotlivy "okenni slot" ma sve `+44` (resource pointer)
pole na 0 - puvodni asm (`sub_12B726`/`sub_12A478`) NEMA null-check (spoleha
na to, ze slot je vzdy inicializovany pred pouzitim), takze presny root
cause (ktera init-cesta nastavuje `+44` a proc se nekdy neprovede) zustava
nenalezeny. Pridan defensive null-guard do obou funkci (`sub_12B726`,
`sub_12A478`) - preskoci prazdny slot misto padu, ale muze zpusobit
neúplne/spatne vykreslene UI prvky. Otevreny task pro pristi session.

**KRITICKY MILNIK: `sub_15C850` byl DALSI zahozeny `int 21h` (DECOMP_TODO
"inline asm") - OPEN DISK FILE WITH HANDLE (AH=3Dh).** Vratil jen
bit-manipulovany smetí misto skutecneho otevreni souboru. Toto byl SKUTECNY
duvod, proc "konec intra zaseknuty" bug (vlna 23c) prezival i po opraveni
`sub_15C8A9` (cteni souboru, AH=3Fh) - `sub_15C8A9` spravne volalo
`PortFile_Read`, ale s FALESNYM handle od `sub_15C850`, takze vzdy vratilo
0 bajtu. Overeno v asm (`sub_15C850 @ 0x15C850`): skutecne parametry a2=
jmeno souboru, a4=access mode (0=cteni/1=zapis/2=obojí); a1/a3 jsou DS
segment/artefakt, ignorovany. Fix: skutecne `PortFile_Open(jmeno, mod)`.

**Po opraveni OBOU (sub_15C8A9 + sub_15C850) spolecne:** `sub_14BC40`
(Smacker-video loader pro hlavni intro cinematic "INTRO.LBX") **konecne
uspesne cte a rozpozna "SMK2" magic header poprve v historii tohoto
portu** (`14BC40.magic = 843795795` = "SMK2" ASCII, potvrzeno). Frontier
se presunul HLOUBEJI - novy pad je uvnitr samotneho Smacker video
dekoderu/frame-processing kodu (zpracovava realna komprimovana data
poprve), zatim neanalyzovano - dalsi krok pro pristi session.

**Metodologicka poznamka pro pristi session:** kdyz `DECOMP_TODO("inline
asm")` funkce vraci hodnotu, ktera se pak POUZIJE jako handle/pointer v
DALSI `DECOMP_TODO` funkci, obе potrebuji opravit SPOLECNE - opraveni jen
jedne (jak se stalo ve vlne 23c se sub_15C8A9) muze vypadat spravne
(zadna dalsi chyba, spravny navratovy typ) ale zustane funkcne rozbite,
dokud navazujici stub take nedostane realnou implementaci.

**Presna pozice noveho frontieru:** `sub_164200` (orion_part_25.c ci
blizky soubor dle rozsahu - jeste neoveřeno, jen lokalizovano přes mapu),
write AV na vysoke heap adrese (0x18A42000) - vypada jako frame-buffer
decode prekroceni, ne NULL/negativni-index vzor. Dalsi krok: precist
sub_164200 a jeho volajici (nejspis Smacker frame-decode / bitstream
unpacking rutina), overit proti Debug/diss/Orion2.exe.asm.

## Done - wave 24c: sub_164200 - DALSI zahozena `retn` -> nekonecna smycka
## (Smacker "build big tree" Huffman dekoder)

Uzivatel poslal VS debugger screenshot: pad presne v `sub_164200` na
`*a2++ = v3;` (write AV, `a2` = nesmyslna adresa po mnoha iteracich).

**Root cause:** `sub_164200` je klasicky Smacker "build Huffman tree"
algoritmus (rozpoznatelny z verejne dokumentovaneho SMK kodeku / FFmpeg
`smacker.c`) - rekurzivni sestup binarnim stromem emulovany EXPLICITNIM
zasobnikem (x86 `push`/`pop`), kde:
- bit==1 = vnitrni uzel: rezervuje slot v `a2[]`, ulozi marker (pozici) na
  zasobnik pro pozdejsi "backpatch" (zapis vzdalenosti k pravemu potomkovi)
- bit==0 = list: precte bajtovou hodnotu, zapise ji, pak backpatchne
  predchozi rezervovany slot (pokud existuje)
- **zasobnik ma DVA druhy markeru**: `0xFFFFFFFE` (koren, zadny backpatch)
  a `0xFFFFFFFF` (uplne dno - kdyz se tohle vyskoci, funkce KONCI - `retn`)

Hex-Rays u teto (uz tak podezrele - vlastni komentare "conditional
instruction was optimized away because %0x4.4==FFFFFFFE" 3x) funkce
**uplne zahodila porovnani s 0xFFFFFFFF a nasledujici `retn`**, a nahradila
celou funkci `while(1)` bez zadneho zpusobu ukonceni - `a2` pak jen roste
donekonecna, dokud nenarazi mimo buffer (presne "write AV po X iteracich"
pozorovany v debuggeru).

Fix: presna rekonstrukce z `Debug/diss/Orion2.exe.asm` (sub_164200 @
0x164200) pomoci lokalniho pole jako nahrady za x86 zasobnik (`markerStack[]`,
push/pop indexem `sp`), zachovava presne stejnou logiku vcetne
backpatch-vypoctu (`*(unsigned int*)marker = (a2 - marker)`).

**Vysledek: sub_164200 uz nepada, frontier postoupil do `sub_1642A0`**
(sesterska "small tree" dekodovaci funkce, jina - jednodussi, neodrolovana
- struktura, zatim neanalyzovano) - read AV. Dalsi krok pro pristi session.

**Metodologicka poznamka:** kdyz dekompilovana funkce ma vlastni komentare
typu "conditional instruction was optimized away because X==CONST" NEBO
konci bez `retn`/`return` na vsech cestach (podezrele `while(1)` bez
break), je to silny signal na presne tenhle bug: Hex-Rays si spatne
odvodila, ze nejaka podminka je vzdy stejna (typicky kdyz podminka
zavisi na hodnote ulozene na stack/registru, kterou dataflow analyza
neumi sledovat pres vice urovni push/pop), a ZAHODILA tim i skutecny
navrat/ukonceni funkce.

Overeno: `sub_164200` po fixu zapisuje spravne (2044B / 2036B, oba pod
2048B rozpoctem pro `dword_18A68C`/`dword_18A690`) - fix je spravny,
neni to zdroj noveho pádu.

## Rozpracovano - vlna 24d: sub_1642A0 ma STEJNY bug potreti, ale INLINE
## (slozitejsi fix, otevreno pro pristi session)

Pad presunut do `sub_1642A0` (Smacker "small tree" dekoder), presne na
`for (i = *(_DWORD*)dword_18A68C; *v51>=0; i=*v51)` (radek ~213,
uzivatelem potvrzeno VS debuggerem: `v51 = 0x8165B513` - smeti).

**Zjisteni:** `dword_18A68C`/`dword_18A690` NEJSOU jen ctene pro traversal
- `sub_1642A0` je i SAMO STAVI (stejnym rekurzivnim zasobnikovym trikem
jako `sub_164200`, viz `Debug/diss/Orion2.exe.asm` @ 0x164457-0x164562:
`push 0xFFFFFFFF/0xFFFFFFFE`, `pop ecx; cmp ecx,0xFFFFFFFE/...FFFFFFFF`,
stejny backpatch vzor `[edx]=edi-ecx`). Rozdil oproti `sub_164200`: tady
NENI to samostatna funkce s vlastnim `retn` na konci - `cmp ecx,
0xFFFFFFFFh; jz loc_164562` SKACE do JINE CASTI TE SAME velke funkce
(pokracuje dalsi logikou - porovnavani s `word_1827E0/E2/E4` a
vyber/zapis do struct slotu na `edx+4/+8/+0Ch`), ne navrat.

Tenhle konkretni useк je INLINE ve velke, uz tak slozite `sub_1642A0`
(200+ radku, mnoho odrolovanych bit-decode retezcu v5-v48). Podezrele
misto v dekompilaci: `if (v59 == -2) v59 = -2;` (radek ~203) -
sebe-prirazeni, klasicky signal ztracene vetve, pravdepodobne SOUVISI s
timhle inline stromem (ne primo traversal loop na radku 213, ktera je jen
DUSLEDEK spatnych dat z INLINE stavby stromu vys - pokud se strom postavi
spatne/nekonecne, traversal pak cte smeti).

**Dalsi krok (pro pristi session, chce cas na peclive overeni):** precist
cely `sub_1642A0` (orion_part_25.c, cely rozsah radku ~1-260) soubezne s
`Debug/diss/Orion2.exe.asm` @ 0x1642A0-0x164600+, presne zmapovat KTERA
cast dekompilovaneho v5-v48 retezce odpovida asm useku 0x164430-0x164562
(inline tree-build), rekonstruovat spravne ukonceni/pokracovani (misto
`retn` tu je `jmp loc_164562` do zbytku funkce), a opravit i sebe-prirazeni
`v59`. NEDOPORUCUJI rychlou opravu bez peclive verifikace - tahle funkce
je hustsi/slozitejsi nez `sub_164200` a chyba v prevodu by se tezko
odhalovala (tise spatna data misto crashe).

## Vyresene - vlna 24e: sub_1642A0 opraveno (marker-stack + backpatch), PLUS
## skryta chyba v sub_164200 nalezena a opravena (chybejici sign-bit init)

Pred opravou samotnou provereno dle uzivatelova pozadavku: dosbox-x pass2
(`STOP cond=cycle_ge:3000000000`) potvrdil, ze originalni `sub_1642A0`
konci na `loc_164562` presne 4x, vzdy s `ecx=0xFFFFFFFF` (spravny
sentinel) - tedy original korektne terminuje, bug je vyhradne
v dekompilaci/prevodu, ne v pochopeni algoritmu.

**Fix `sub_1642A0`** (orion_part_25.c): stejna trida bugu jako
`sub_164200` (Hex-Rays zahodila `retn`/skok na spravne misto a zkolabovala
cely explicitni marker-zasobnik do jedne skalarni `v59`), navic zhorsena
tim, ze puvodni parametr `a2` (asm `edx`, nedotcena struktura po celou
dobu funkce - pouzita az na konci pro `[edx+4/8/0xC]`) byla dekompilatorem
znovu-prirazena k JINE veci (aktualni backpatch marker) - takze zavěrečný
kod uz nemel spravny ukazatel na vystupni strukturu.

Reseni: zaveden `outStruct = a2;` (uchovava puvodni ukazatel po celou
dobu, nikdy neprepsan), a skutecny `markerStack[]`/`sp` zasobnik
(stejny vzor jako u `sub_164200`), nahrazujici skalarni `v59`. Zbytek
funkce (oba traversal loopy na `dword_18A68C`/`dword_18A690`, vyber
struct slotu dle `word_18A7E0/E2/E4`) ponechan beze zmeny - nebyl
identifikovan jako chybny.

**Skryta druha chyba (bez tohoto zjisteni by fix `sub_1642A0` porad
padal):** po fixu `sub_1642A0` padalo pořad na stejnem miste
(`for (i = *(_DWORD*)dword_18A68C; *v51>=0; ...)` uvnitr `sub_1642A0`),
i kdyz `dword_18A68C`/`dword_18A690` byly overene platne ukazatele
(PortDebug_CheckpointPtr: `0x1834FFC0`/`0x183507C0`, presne 2048B od
sebe - odpovida `sub_1646A0`) a oba stromy byly na danem snimku skutecne
prestaveny (rebuild-bit=1 pro oba, overeno checkpointem). Zavada tedy
byla v OBSAHU stromu postaveneho `sub_164200`, ne v `sub_1642A0`.

Root cause v `sub_164200` (orion_part_24.c): original asm (`sub_164200`
@ 0x164200, prvni instrukce) dela `mov eax, 80000000h` JEDNOU pred celou
smyckou, a kazdy dalsi zapis listu upravuje uz jen `al`/`bl` (nizky byte)
- horni bity registru `eax` VCETNE ZNAMENKOVEHO BITU zustavaji po celou
dobu funkce `0x800000..`. Tenhle znamenkovy bit je presne to, co
`sub_1642A0`v traversal (`*v51 >= 0`) pouziva k rozliseni listu (negativni)
od vnitrniho uzlu (pozitivni distance). Dekompilovany kod ale deklaroval
`unsigned int v3` bez inicializace a jen zapisoval `LOBYTE(v3)` - horni
bity byly nedefinovane smeti, takze nahodne nektere listy vysly jako
"pozitivni" a traversal je zamenila za vnitrni uzly, coz vedlo k
prochazeni mimo buffer stromu (nedeterministicke - lisilo se run od
run, presne odpovida pozorovanym ruznym pádovym adresam). Oprava:
`unsigned int v3 = 0x80000000u;` pred smyckou (misto neinicializovane
deklarace), zbytek beze zmeny.

**Nova trvala diagnosticka infrastruktura:** `DebugVectoredHandler`
(src/reorion2.cpp) ted navic vypisuje cely call-stack (StackWalk64 +
SymFromAddr, `dbghelp.lib`) pri neosetrene SEH vyjimce - predtim davala
jen "module=X rva=Y" bez cesty k volajicimu, coz pro pad hluboko
v CRT/system DLL (napr. `memmove` volane s neplatnou velikosti) davalo
nulovou moznost dohledat, ktery herni kod volani zpusobil.

Po fixu pad zmizel ze VSECH tri drivejsich mist v `sub_1642A0`
(deterministicky, overeno vicero behy) a presunul se do UPLNE JINE,
predtim nedosazitelne funkce - viz nize.

## Nova hranice - vlna 25: sub_14CD50/sub_14BC40 (memcpy s podezrelou
## velikosti)

Novy pad (mimo Smacker tree-decode kod, uz downstream): AV uvnitr
`memmove` (VCRUNTIME140D.dll), `av_read=0xFFFFFFFFFFFFFFFF` (typicky
znak podtecene/obrovske unsigned velikosti predane do memcpy). Call
stack (diky nove diagnosticke infrastrukture):

```
memmove -> qmemcpy -> sub_14CD50+0x113 -> sub_14BC40+0x100c ->
sub_132646 -> sub_14DF7 -> sub_24ED3 -> GameMain_10057
```

Podezrely radek: `orion_part_22.c:3489`,
`qmemcpy(v28, *(void**)(a1+1076), v24)` uvnitr `sub_14CD50`, kde
`v24 = *(a1+1072) - *(a1+1076)` (zbyvajici bajty v bufferu), orezano
`v26`/`*(a1+1084)`. Pokud nektere z techto poli struktury `a1`
(offsety 1068-1092, souborovy/bufferovy stav) neni spravne
inicializovano pred timhle volanim, `v24` muze vyjit jako obrovske
unsigned cislo. Otevreno pro dalsi session - viz task #15.

## Vyresene - vlna 25: sub_14CD50/14BC40/14C740/14CAA0 - x64 sirka
## ukazatele (`_DWORD**`/`char**` na 32bit pole)

Diagnostickym vypisem primo pred padajicim `qmemcpy` (docasny,
odstranen po zjisteni) se ukazalo, ze `a1+1068/1072/1076/1084` maji
rozumne hodnoty (buffer 406388928, konec +331776, pozice=buffer,
avail=1024, pozadavek=13480→orezano na 1024) - kopie samotna vypadala
bezpecne. Skutecna pricina: `qmemcpy(v28, *(void **)(a1 + 1076), v24)`
cte pole `a1+1076` (jinde v CELE teto funkci dusledne pristupovane
jako `*(_DWORD*)(a1+1076)`, tedy 32bitove) jako **cely nativni
ukazatel** - na x86 `void*` je 4B takze bug se neprojevi, ale na x64
`void**` cte 8 bajtu a natahne SOUSEDNI 32bitove pole (`a1+1080`) jako
horni polovinu adresy → nesmyslny 64bit ukazatel → AV v memmove.

**Tato trida bugu byla rozsirena po celem souboru** (stejny SMK-reader
struct pouzity v `sub_14BC40`/`sub_14CD50`/`sub_14C740`/`sub_14CAA0`,
kazdy vyskyt krizove overen proti sousednim `_DWORD`-pristupum NA
STEJNEM offsetu v tomtez souboru pred opravou): opraveno 9 mist
(offsety 52, 56, 940×4, 944, 964, 992, 1028, 1076) na vzor
`(T*)(uintptr_t)*(_DWORD*)(...)` (precti 32bit hodnotu, pak teprve
rozsir na ukazatel) misto primeho `*(T**)(...)`. **Ponechano bez
opravy** (nedostatecne overeno, jiny/neprozkoumany struct): radek
~1048 (`sub_14A010` argumenty) a ~1708 (`v33 = *(char**)(v6+4)`) -
zkontrolovat pokud se ukazou byt na kriticke ceste.

**Vysledek:** `sub_14BC40` (cele nacteni SMK hlavicky + tabulek +
Huffman stromu pres jiz opravene `sub_164200`/`sub_1642A0`) ted PRVNE
KOMPLETNE USPEJE (`132646.after_14BC40` vraci platny nenulovy
ukazatel) - dosud nejhlubsi bod, kam se port SimTex/logo Smacker cesty
dostal. **Novy pad** hned potom: `av_write` na adresu
`0x7FFE5DCB1800`, `GetModuleHandleExA` pro ni NENASEL vlastnici modul
(tedy nejde o skutecnou systemovou DLL - vypada to na divoky/poskozeny
ukazatel, ktery jen nahodou vypada jako vysoka adresa), stack unwind
se zastavi hned po prvnim rámci (mozna poskozeny zásobník). Nejspis
dalsi vyskyt STEJNE tridy bugu (x64 sirka ukazatele) uvnitr skutecneho
per-snimkoveho block/pixel decode (`sub_132869`/`sub_14A090`/
`sub_138CEE`/`sub_14AA40`), zatim neprozkoumano - viz task #17.

**Stmivani (uzivateluv dotaz):** paletova pipeline pro SMK-embedded
paletove zmeny (`sub_132A11`→`byte_1BB358`→`sub_131F7B`→`sub_132AF8`→
`PortVga_SetPaletteEntry`) byla precte overena radek-po-radku proti
asm (`Debug/diss/Orion2.exe.asm`, offsety +0x68 a +0x8A v
`sub_132869`/`sub_132A11`) a je 1:1 verna - zadny chybejici/zahozeny
kod. Explicitni DAC-rampa (`sub_C5BB9`/`sub_C5C44`, `sub_132C80`) se
pro simtex.lbx volani (`sub_14DF7(aSimtexLbx,0,0)`, potvrzeno i v asm
`xor edx,edx`) **umyslne nevola** (a3=0) - shodne s originalem, NENI
to port bug.

**SKUTECNY ROOT CAUSE (nalezeno diky uzivatelove napovede "problem je
v sub_124ECB nebo pred ni"):** `dword_18A5AC` - casovaci/hodinova
funkce (Miles Sound System `AIL_ms_count()` ekvivalent), instalovana
`sub_149890`/`sub_149A20` (volano JESTE PRED prvnim snimkem, tedy
"pred sub_124ECB") a pouzivana po celem SMK readeru
(`orion_part_22.c`) pro realne casovani prehravani - jak formou
proste "precti aktualni tick" dotazu, tak formou busy-wait throttlu
(`do v=dword_18A5AC(v); while(v<target);`). Obe kandidatni
implementace (`sub_149B10`, `sub_149B30`, `link_stubs.c`) byly
`return 0;` pahyly - VZDY zastavene hodiny. Zadne casovani/throttling
se tak nikdy neuplatnilo a cele cinematicke intro (vcetne stmivani
zakodovaneho v palete pres desitky snimku v REALNEM CASE) se
dekodovalo a vykreslovalo tak rychle, jak stihne CPU - tedy prakticky
okamzite, misto za svou autorskou delku. Fix: `sub_149B10`/`sub_149B30`
nyni vraceji `SDL_GetTicks()` (skutecny monotonni ms citac); argument
se stejne jako u realneho `AIL_ms_count()` ignoruje.

Po fixu (a po fixu x64 sirky ukazatele vyse) video PRVNE uspesne
zavola `sub_132A11` (paleta aplikovana, checkpoint
`sub_132869.paletteApplied=1` potvrzen) a postoupi az do skutecneho
per-snimkoveho pixel/blok decoderu, kde spadne v `sub_14AA40` (volano
z `sub_132869`) - `av_write` na (tentokrat vyhlizejici jako realnou,
ne zjevne divokou) haldovou adresu. To uz je JINY, samostatny bug v
samotnem obrazovem dekodovani (ne v casovani/palete) - dalsi krok pro
pristi session.

## Vyresene - vlna 25b: DRUHY samostatny root cause - sub_132C80 psal
## do no-op VGA portu (hr_outbyte), ne do PortVga_SetPaletteEntry

Po nahlaseni "furt zadne stmivani" se ukazalo, ze uzivatel ve
skutecnosti vidi VETEV `logo.LBX` (sub_25259()==false v jeho prostredi),
ne SIMTEX Smacker cestu zkoumanou vyse - uplne jina, jednodussi
animace (staticke LBX snimky, ne video). Na zadost uzivatele
("nemuzes zachytit stav palety pres dosbox?") nastaven dosbox-x
trace (breakpointy na `sub_132C80`/`sub_C5BB9`/`sub_C5C44`) -
**potvrzeno, ze `sub_132C80` se v originalu vola OPAKOVANE (101x) s
klesajicim `a1` (100→0) z `sub_251EF`** (fade-in smycka volana z
`sub_24ED3` pred loop1, dekompilovana SPRAVNE a beze zmeny nutna).
`sub_132C80(a1)` skaluje ulozenou baseline paletu (`dword_1BB880`,
ktery je jen ALIAS na `byte_1BB358`) faktorem `(100-a1)/100` - tedy
klesajici `a1` produkuje NARUSTAJICI jas (spravny fade-in, 0%→100%).

Rizeni behu (`sub_251EF`, `sub_C5BB9`, `sub_C5C44`) bylo VZDY spravne
dekompilovano a spravne bezelo - problem byl, ze samotne
`sub_132C80` zapisovalo primo pres `hr_outbyte()` (VGA DAC porty
0x3C6/0x3C8/0x3C9), a **`hr_outbyte` je v tomto portu uplny no-op
stub** (`decomp_compat.h`) - na rozdil od sesterske funkce
`sub_132AF8` (uz drive prevedena na `PortVga_SetPaletteEntry`,
proto jsem ji drive oznacil za "overenou pipeline" - ale je to JINA
funkce nez `sub_132C80`!). Vysledek: fade smycka bezela spravnym
poctem kroku se spravnymi hodnotami, ale KAZDY zapis skoncil v
prazdnu - stmivani se nikdy nedostalo na obrazovku, ani in ani out.

Fix: `sub_132C80` prepsano na `PortVga_SetPaletteEntry` (stejny most
jako `sub_132AF8`), zachovan puvodni cteci vzor (presko flag bajt,
cti R/G/B ze 4-bajtoveho slotu, skaluj `(100-a1)/100`). Odstranena
rucni VGA-port DAC-index aritmetika (uz neni potreba - index se
predava primo).

**Pouceni:** "paleta se aplikuje" (sub_132A11→byte_1BB358→sub_131F7B
→sub_132AF8) a "paleta se STMIVA" (sub_132C80, volana sub_251EF/
sub_C5BB9/sub_C5C44) jsou DVE ROZDILNE cesty ke stejnemu vysledku
(SDL paleta) - overeni jedne NEZNAMENA overeni druhe. Vzdy zkontrolovat
KAZDOU funkci v retezci zvlast, ne predpokladat sdilenou infrastrukturu.

## Vyresene - vlna 25c: TRETI, skutecny root cause - chybejici Present()
## behem fade rampy (muj vlastni regresni bug z vlny 25b)

Po nahlaseni "vizualne porad bez fade" i po fixu 25b, uzivateluv trace
odhalil, ze `sub_24ED3` ve skutecnosti hraje OBE animace postupne
(LOGO.LBX pres `sub_251EF`/`sub_C5C44` fade, PAK SIMTEX Smacker cinematic
pres `sub_14DF7` - ne alternativy podle `sub_25259()`, jak jsem drive
mylne predpokladal - `if(sub_25259())` vola SIMTEX POZDEJI, `else`
LOGO.LBX napřed). Trace koncí spravne az v jiz znamem pádu task #17.

Skutecna pricina "porad bez fade": **muj vlastni fix z vlny 25b
omylem odstranil volani `sub_132B41()`/`sub_132B27()`** (povazoval
jsem je za bezvyznamny VGA-retrace pozustatek) - ale prave TYHLE
funkce jsou jediny zpusob, jak se v tomto portu vola
`Port::Vga::Present()` (pres `PortVga_WaitVsync`, viz port_vga.cpp).
`PortVga_SetPaletteEntry` sama o sobe pouze aktualizuje `g_palette[]`
v pameti - NEPREKRESLUJE obrazovku. Vysledek: vsech 101 kroku fade
rampy (`sub_251EF`) spravne zapisovalo spravne hodnoty do palety, ale
obrazovka se mezitim ANI JEDNOU nepřekreslila - viditelny byl az
DALSI, nesouvisejici Present() (napr. uvnitr `sub_124ECB`), ktery uz
ukazal FINALNI (100%) stav bez jakekoliv viditelne animace.

Fix: `sub_132B41()`/`sub_132B27()` vraceny zpet do `sub_132C80`
(pred/mezi dvema 128-polozkovymi pulkami zapisu, stejne jako original).
Kazde volani `sub_132C80` tak ted zpusobi 2 realne prekreslenych
snimky (~14ms SDL_Delay kazdy) - fade-in pres 101 kroku ~ 2.8s.

**Pouceni (dulezite pro dalsi praci s VGA/DAC kodem):** V tomto portu
neni "napis do palety" a "preresli obrazovku" jedna operace - jsou to
DVA KROKY (`PortVga_SetPaletteEntry` vs `Port::Vga::Present()`).
Kdykoliv se ve zdrojovem kodu odstranuje zdanlive "zbytecne" VGA
cekani-na-retrace volani (sub_132B27/sub_132B41/podobne), NUTNE
zkontrolovat, jestli to volani neni ve skutecnosti jediny zpusob, jak
se v teto vetvi kodu vubec nekdy zavola Present() - jinak zmena
sice zustane funkcne spravna (data se zapisou), ale VIZUALNE se
nikdy neprojevi.

## Vyresene - vlna 25d: CTVRTY bug - chybejici 6bit->8bit DAC skalovani
## v sub_132C80 (fade vypadal "pomaly a pak skokem")

Po fixu 25c uzivatel hlasil: fade uz NECO dela, ale roztmivani
pusobi moc pomale a pak jas "podivne skoci, jako by preteklo".
Root cause: `dword_1BB880` (alias `byte_1BB358`) uklada **6bitove**
VGA DAC hodnoty (0-63) - presne jak dokumentuje uz drive opravena
sesterska funkce `sub_132AF8` (`6-bit DAC values are scaled to 8 bits
for SDL: (v<<2)|(v>>4)`). Muj puvodni prepis `sub_132C80` (vlna 25b)
skaloval fade-procento primo na tyto 6bitove hodnoty a poslal vysledek
rovnou do `PortVga_SetPaletteEntry` OCEKAVAJICI 8bitovy (0-255) kanal
- kazdy krok fade tak vrcholil na 63 (~25 % skutecne svetlosti) misto
255, cimz cely prubeh vypadal slabe/pomale, a pak NASLEDNE, jakmile
neco jineho (sub_131F7B/sub_132AF8, ktere 6→8 skalovani DELAJI
spravne) paletu prepsalo doopravdy, jas "skocil" na skutecnou hodnotu.

Fix: aplikovano stejne `(v<<2)|(v>>4)` roztazeni jako v `sub_132AF8`,
AZ PO vynasobeni fade-procentem (tedy roztazeni vidi vzdy spravny
0-63 rozsah). Casovani (2 vsync-prekresleni na volani, 101 volani 
2.8s) ponechano beze zmeny - architekturalne odpovida puvodnimu
70Hz VGA hardwaru, domnenka je, ze vnimana "pomalost" byla vedlejsi
efekt slabeho jasu, ne skutecny casovaci bug.

**Pouceni:** VZDY kdyz kod cte z `byte_1BB358`/`dword_1BB880` (nebo
jakehokoliv jineho VGA DAC-puvodu bufferu) a posila vysledek do
`PortVga_SetPaletteEntry`, zkontrolovat 6→8bit skalovani - snadno se
zapomene, protoze compileru/testum to nespadne, jen to vizualne
vypada "spravne, ale slabe".

## Vyresene - vlna 25e: PATY bug - roztrzena (non-atomicka) aktualizace
## palety v sub_132C80 ("druhy fade divne pomrkava")

Po fixu 25d uzivatel: prvni fade (sub_251EF, 101 jemnych 1% kroku)
uz vypada dobre (a shoduje se s dosboxem vc. pocatecniho bleskoveho
rozsviceni pred prvnim stmivanim - NENI to bug, viz nize). Ale
"druhy fade" (na konci prechodu mezi fazemi LOGO.LBX) "divne
pomrkava". Bisekce: `sub_C5C44` (volana mezi loop1/loop2) je
POTVRZENE no-op i v originalu (dosbox: `byte_18319C=0` pri vstupu,
presne jako v portu - `if(byte_18319C)` guard nikdy neprojde).
Skutecny "druhy fade" je `sub_2518F` (volana `sub_24ED3` hned na
zacatku "if(!v1)" bloku) - PRESNE OVERENO proti asm (`add edx,0Ah`),
takze 11 HRUBYCH kroku po 10 % (0,10,...,100) je autenticke, ne
decompiler bug.

Root cause "pomrkavani": `sub_132C80` volalo `sub_132B41()`
(Present) PO zapisu prvni pulky (indexy 0-127) a PRED zapisem druhe
pulky (128-255) - takze kazdy Present() bud ukazal STAROU paletu
(pred zacatkem kroku), NEBO "roztrzenou" paletu (pulka uz na nove
hodnote, pulka jeste na stare)! Na skutecnem VGA hardwaru puvodni hra
zapisovala do DAC portu behem `_disable()`/`_enable()` (prerusenim
zakazano) a cekani na retrace davalo bezpecne okno mimo aktivni
scan - roztrzeny stav NIKDY nebyl VIDITELNY. V portu Present()
okamzite prekresli CELOU obrazovku bez ohledu na "scan pozici", takze
roztrzena paleta byla viditelna po dobu celeho snimku (~14ms). Skoro
neznatelne u 101 jemnych 1% kroku (`sub_251EF`), ale nápadné u 11
hrubych 10% kroku (`sub_2518F`) - presne to uzivatel popsal jako
"pomrkavani".

Fix: v `sub_132C80` presunuty OBA zapisy (vsech 256 polozek) PRED oba
`sub_132B41()`/`sub_132B27()` (Present) volani - kazdy viditelny
snimek tak vzdy ukazuje kompletne konzistentni paletu. Casovani
(2 prezentace na volani) zachovano beze zmeny.

**Pouceni:** kdyz port nahrazuje "cekani na hardwarovy retrace/blanking"
za "okamzite prekresleni obrazovky" (Present), MUSI se zkontrolovat,
jestli puvodni kod NEROZDELOVAL nejakou logicky ATOMICKOU zmenu (napr.
celou paletu) na vice davek prave proto, ze na hardwaru byl retrace-wait
mezi nimi NEVIDITELNY bezpecnostni bod - v portu bez teto vlastnosti
je treba vsechny davky spojit PRED prvnim Present() volanim.

## Vlna 25f: DUMPPAL nastroj v dosbox-x + sub_81547 fix + opravena
## vlastni chybna diagnoza "loop1/loop2 konci okamzite"

Na uzivateluv pozadavek ("nemuzes se podivat do kodu dosbox-x a pridat
funkci pro dump palety, porovnat s nasim portem?") pridan novy prikaz
**`DUMPPAL cond=eip:0xADDR start=N count=M label=x [repeat=always]`**
do `dosbox-x-remc2/src/engine/engine.cpp` - vypisuje SKUTECNE
vykreslovanou VGA DAC paletu (`vga.dac.rgb[]`, 6bitove hodnoty), ne
jen zdrojova data v pameti hry. Vsimnuto mimochodem: `DUMPMEM` vubec
neparsuje `repeat=` (dump jen jednou pri prvnim zasahu) - `DUMPPAL` to
ma opravene/podporovane. Zdokumentovano v
`genCompare/DOSBOX_CTL_PROTOCOL.md` (TODO: doplnit at commit).

**Vysledek trace (fade-in i fade-out, cely dosbox prubeh):** mezikrokove
rozestupy konzistentne ~86000-88500 cyklu, ZADNE anomalie/zaskobrtnuti -
original je hladky. Mezi fade-in a fade-out je ale mezera ~36M cyklu
(perioda, kdy `sub_132C80` vubec nevola - "loop1" jen sleduje/ceka).

**Bug nalezen a opraven:** `sub_81547` (orion_part_07.c, pouzivano v
`sub_24ED3` pro porovnani "zmenil se zobrazeny snimek") melo
`HIWORD(v3) = HIWORD(dword_1B06FC); LOWORD(v3) = *(WORD*)(dword_1B06FC+6);
return v3-1;` - VERIFIKOVANO 1:1 vuci asm (`mov eax,dword_1A86FC; mov
ax,[eax+6]; dec eax`), NENI to decompiler bug, je to autenticky puvodni
kod. Problem: `mov ax,...` prepise jen DOLNI 16 bitu EAX, horni pulka
zustava z PREDCHOZIHO nacteni CELEHO ukazatele - v DOS4GW s malymi
predikovatelnymi adresami to bylo nahodou nevyznamne (~0), ale v portu
s realnou haldou je horni pulka ukazatele velke nenulove cislo, takze
porovnani `sub_12D70B() == sub_81547(...)` v originale funkcni logice
(16bitova hodnota) je v portu prakticky VZDY FALSE (mimo nahodnou
shodu, jednou pozorovanou). Fix: vraceno cistych 16 bitu bez pointerove
primesi - dolnich 16 bitu vysledku `v3-1` je MATEMATICKY STEJNYCH bez
ohledu na to, jestli se odecte 1 od cele 32bit hodnoty nebo jen od
16bit hodnoty (vypujcka nikdy neovlivni uz spocitane nizsi bity), takze
fix nemeni chovani v puvodnim (funkcnim) pripade, jen odstranuje
zavislost na adrese haldy.

**DULEZITA OPRAVA VLASTNI CHYBNE DIAGNOZY:** puvodne jsem se domnival,
ze `loop1`/`loop2` v `sub_24ED3` konci "okamzite" (na zaklade toho, ze
se nikdy nezobrazil checkpoint `loop1.tick`, ktery tiskne kazdych 200
iteraci) - ale `loop1` ma jen 15 iteraci CELKEM (v7=15 countdown), takze
tenhle checkpoint NEMEL SANCI se zobrazit bez ohledu na skutecny
uplynuly cas! Zmereno realne (`time` prikaz): **cely beh (intro az po
znamy pad v sub_14AA40) trva ~9.4 sekundy realneho casu** - `sub_12C2C6`
(BIOS-tick-based pacing pres jiz drive opravenou `PortDos_BiosTick`)
FUNGUJE SPRAVNE a dava kazde iteraci loop1/loop2 realne tempo. Puvodni
hypoteza "loop1 konci bez cekani" byla tedy MYLNA - fix sub_81547 zustava
platny (je to skutecna portovaci chyba), ale NENI to hlavni pricina
zbyvajiciho lehkeho pomrkavani, ktere uzivatel hlasil. Skutecna pricina
zbyvajiciho pomrkavani zatim NENI jednoznacne identifikovana - kandidati
pro pristi session: (a) 11 hrubych 10% kroku fade-outu (`sub_2518F`)
proti 101 jemnym u fade-in - i po fixu atomicity muze byt vizualne
znatelnejsi/"schodovity", coz muze uzivatel vnimat jako "pomrkavani" i
kdyz technicky neni bug; (b) SDL_Delay(14) presnost/OS scheduling
jitter v ramci `PortVga_WaitVsync`; (c) neco specifickeho jeste
neprozkoumaneho v prechodu mezi fazemi. Dalsi krok: pockat na uzivateluv
vizualni test aktualniho buildu, pripadne pridat DUMPPAL analogii do
portu (port_vga.cpp) pro primo srovnatelny per-krok vypis nasi vlastni
`g_palette[]` a porovnat cyklus-za-cyklem s dosbox referenci.

## Vlna 25i: task #17 pokracovani (VS debugger repro) - 2 bugy nalezeny a
## opraveny, treti (hlubsi) jeste otevreny

Uzivatel poskytl presny VS-debugger repro: pad v `sub_14AA40` radek 1584
(`*v21 = 1;`), `v21 = *(_BYTE**)(a7+928)`.

**Bug #1 (opraveno):** stejna trida x64 sirky ukazatele jako drive v
teto session, tentokrat s `_BYTE**` (ne `_DWORD**`/`char**` jako drive -
proto unikl puvodnimu greppu). `a7+928` je jinde v souboru dusledne
`*(_DWORD*)` (32bit), takze `*(_BYTE**)` na x64 natahuje sousedni pametu
jako horni pulku adresy. Opraveno na vsech 3 mistech v souboru
(orion_part_22.c radky ~1575,1583,1750: `sub_14AA40` a sesterska funkce).
Po fixu pad postoupil dal (sub_167320, volana z sub_14B4D0).

**Bug #2 (opraveno):** `dword_18A610/614/618/61C/620/624/628/62C/630/
640/644/648/64C` (+ `unk_18A610`, alias STEJNE adresy pod jinym jmenem z
jineho dekompilacniho pruchodu) - 13 samostatnych 4bajtovych globalu,
ve skutecnosti JEDEN souvisly 64bajtovy (16-dword) blok v puvodnim
.data segmentu (OVERENO v asm: `dword_182610 dd 0`, kazdy dalsi symbol
presne 4 bajty za predchozim, az po `dword_182650` ktery je jiz jinou,
potvrzene nesouvisejici tabulkou funkcnich ukazatelu). C negarantuje
souvislé, mezerami neprerusene rozlozeni samostatne deklarovanych
globalu - `qmemcpy(cil, &dword_18A610, 0x40)` v `sub_1646A0`
(orion_part_25.c) tak kopirovalo smetí ze sousednich, nesouvisejicich
promennych. Fix: sloučeno do `uint32_t block18A610[16]`
(orion_data.c), VSECHNA volajici mista v orion_part_25.c/orion_part_26.c
prepsana na primou indexaci `block18A610[N]` (na uzivateluv vyslovny
pozadavek - ZADNE `#define` makro-preklady, primy zapis v kazdem
volacim miste).

**Bug #3 (OTEVRENO, dalsi session):** i po obou opravach pad v
`sub_167320` presetrvava - jen se posunul v ramci STEJNE
sebe-referencni fixup smycky (drive `*v10=v9`, ted `*v11=v9`, o jeden
zapis dal ve stejne skupine). To znamena: `block18A610` uz je spravne
velky a NEPRETEKA, ale DATA, ktera se do nej ctou/kopiruji (pres 4
volani `sub_164600` uvnitr `sub_1646A0`, orion_part_25.c radky
~447-466) porad nejsou platna. Podezreni: bud (a) `sub_164600`v
"maly strom" vetev (`a2[0]=0; a2[1..3]=result;`) se v tomto konkretnim
kontextu nebere spravne (bitova podminka cte spatna data kvuli
predchozimu, jeste nenalezenemu bugu), nebo (b) jedno z techto 4
volani NEOCEKAVANE bere "velky strom" vetev (`sub_164200`, az 2048B)
a i presto, ze block18A610 je nyni "spravne" 64B, PUVODNI KOD (a tedy
i port) by pak PRETEKAL DO SOUSEDNICH GLOBALU STEJNE JAKO PUVODNE (jen
uvnitr sveho vlastniho pole misto sousednich promennych) - coz by
znamenalo, ze i toto misto potrebuje overit vuci dosboxu, jestli se
"velka" vetev v teto casti kodu FAKTICKY nekdy neuplatnuje.

## Vlna 25j: Bug #3 nalezen a opraven - sub_167320 sebe-referencni smycka
## mela STEJNOU x64 sirku-ukazatele chybu jako cely zbytek session, jen
## skrytou v kurzoru smycky, ne ve struct poli

Pokracovani vlny 25i. Uzivatel poskytl DALSI presny VS-debugger repro na
stejnem miste (radek 1000 dekompilatu, `*v10 = v9;`), `v10 =
0xFFFFFFFFFFFFFFFF`.

**Root cause:** asm je proste `lodsd/stosd` kopirovaci smycka (4 skupiny
po 4 32bit dwordech) se sebe-referencni backpatch operaci (`mov
[eax],edx` - 2./3./4. dword kazde skupiny je ulozena 32bit hodnota,
ktera SOUCASNE slouzi jako adresa, kam se zapise skupinova "self"
hodnota). Dekompilator reprezentoval prochazejici kurzor jako `_DWORD
**v7` a cetl skrz nej pres `*v7++` - na x86 `sizeof(_DWORD*)==4`, takze
se to NAHODOU shodovalo se zamyslenym 4-bajtovym krokem A zamyslenym
32bit ctenim. Na x64 ale `sizeof(_DWORD**)==8`: `v7++` presouva o 8
bajtu misto 4 (rozhodi zarovnani KAZDEHO dalsiho cteni po prvnim) A
`*v7` cte 8 bajtu misto 4 (natahne sousedni nesouvisejici dword jako
horni pulku ukazatele). Tohle vysvetluje, proc se pad postupne
posouval mezi jednotlivymi zapisy skupiny (`*v10=v9` → `*v11=v9`) po
predchozich fixech - kazdy dalsi krok byl citelny jeste vic mimo
zarovnani.

Fix: prepsano na explicitni `uint32_t` indexaci (`v3[0..3]`), zadne
vice-urovnove ukazatelove typy pro prochazeni bufferu - presne
odpovida `lodsd` (vzdy presne 4 bajty). Ulozene 32bit hodnoty se na
ukazatel rozsiruji (`(uintptr_t)`) az v okamziku, kdy se SKUTECNE
pouzivaji jako backpatch adresa. Nepouzivane docasne promenne
(v6,v7,v8,v10,v11,v12 z puvodni dekompilace) odstraneny z deklaraci.

**Vysledek:** pad se presunul VYRAZNE dal (offset 0xE0 → 0x481 v ramci
`sub_167320`) - za celou opravenou sebe-referencni smycku A za stavbu
vyhledavaci tabulky (`dword_18A600`/604/608/60C, pres `sub_164590`),
nyni nekde uvnitr SKUTECNE dekodovaci logiky stromu (`v28 = *v27;` kde
`v27 = dword_18A6A4 + (v29>>8)`, `v29` z lookup tabulky `dword_18A600`).
`av_read` adresa ted vypada jako REALNA (ne zjevne "smeti"), coz
naznacuje bud (a) legitimni, jeste nenalezeny bug v `sub_164590`
(stavba `dword_18A600` tabulky) nebo drivejsich krocich, nebo (b) tahle
konkretni cesta jeste neni v puvodni hre za normalnich okolnosti
dosazena a jde o kumulaci drobnych chyb. Dalsi krok pro pristi session:
overit `dword_18A600` tabulku (a `sub_164590`) proti dosboxu na
konkretnich indexech, pripadne pokracovat v hledani dalsich `**)`
sirko-ukazatelovych bugu v okoli teto casti `sub_167320`
(`orion_part_26.c`, radky ~1220+ - funkce je velmi dlouha, tenhle konkretni
pad je jeste v prvni tretine).

## Vlna 25k: dalsi bug opraven (dword_18A69C volani pres 32bit hodnotu),
## a KONKRETNI dukaz pro bug #4 (jeste otevreny)

Uzivatel poskytl DALSI VS-debugger repro (jiny bod, radek 1150
dekompilatu): `dword_18A69C(v15);` - pad "Access violation v miste
provedeni" (volani pres neplatny ukazatel na funkci).

**Bug opraven:** `dword_18A69C = *(int (**)(_DWORD))(a3 + 4);`
(orion_part_26.c) - STEJNA trida x64 sirky-ukazatele bug jako cely
zbytek session, tentokrat na FUNKCNIM ukazateli. `a3+4` je jinde v
TEZE funkci (radek ~1071 puvodniho cislovani) dusledne `*(_DWORD*)`
(32bit), takze `*(int(**)(_DWORD))` na x64 cte 8 bajtu a natahne
sousedni `a3+8` jako horni pulku adresy → volani skrz smetovy
ukazatel. Opraveno: `(int(*)(_DWORD))(uintptr_t)*(_DWORD*)(a3+4)`.

**DULEZITE ZJISTENI - siroky rozsah tohoto bugu:** behem hledani
podobnych mist nalezeno PRES 50 vyskytu vzoru
`(*(TYPE(**)(...))(zaklad+offset))(...)` (volani "vtable"-stylem pres
ulozenou 32bit hodnotu) napric MNOHA soubory (orion_part_17/18/20/22/23/24/26
- ne jen Smacker kod!). Vsechny pravdepodobne trpi STEJNOU x64 chybou
(cteni 8 bajtu misto 4). Zatim opraveny jen ty na aktivni pádové ceste
(reaktivni pristup). **Otevrena otazka pro uzivatele: pokracovat
reaktivne (oprava jak se na pad narazi), nebo udelat proaktivni
komplexni sweep vsech vyskytu najednou?** Vzhledem k rozsahu (50+ mist)
by komplexni sweep mohl byt efektivnejsi, ale riskantnejsi bez
postupneho overovani kazdeho mista.

**Bug #4 (pokracovani vlny 25j, jeste OTEVRENY) - konkretni dukaz:**
Pridana docasna diagnostika primo pred pad v `sub_167320`
(orion_part_26.c ~1084/1097, `v27=*(_DWORD*)(dword_18A60C+4*(uint8_t)v13)`).
Vysledek: `v27 = -842150451` = **0xCDCDCDCD** presne - MSVC debug-heap
"cerstve alokovana, nikdy nezapsana pamet" marker! `dword_18A60C`
(= a2+28688, spravne vypocitana adresa, OVERENO) obsahuje na tomto
miste pamet, kterou NIKDY NIC NEZAPSALO.

Tato 256-polozkova tabulka se ma plnit v `sub_164590`, volane ZEVNITR
`sub_164600` POUZE pokud se bere "velka" vetev (`if(v5) {...
sub_164590(v10,a4)...}`) - pokud se bere "mala" vetev (`else {*a2=0;
a2[1..3]=result;}`), `sub_164590` se VUBEC NEVOLA a tabulka zustane
needefinovana! Ctvrte volani `sub_164600` v `sub_1646A0`
(orion_part_25.c ~461-466, `dword_18A6B4=256` pred timto volanim) tak
pravdepodobne bere "malou" vetev pro tenhle konkretni SMK soubor/snimek
- coz v puvodni high implementaci pravdepodobne znamena "znovu pouzij
tabulku z PREDCHOZIHO ramce/volani" (podobny vzor jako palette-reuse
bit u sub_132646 - "pokud bit neni nastaven, ponech soucasny obsah
bufferu"). Pokud PORT nekde predtim tuhle tabulku nikdy jednou spravne
NEPOSTAVIL (napr. kvuli poradi volani nebo diky drivejsimu pádu, ktery
znemoznil kompletni prvni-frame inicializaci), "znovu pouzij"
vetev by procesenim ctenim needefinovanou pamet.

**Dalsi krok pro pristi session:** zjistit, zda se VUBEC NEKDY (v
libovolnem ramci/volani) korektne zavola "velka" vetev pro tenhle
konkretni dword_18A60C/tree-slot (napr. pridat checkpoint na vstup
`sub_164590` a sledovat, kolikrat/kdy se zavola pro tuto konkretni
tabulku), nebo jestli "mala" vetev sama o sobe potrebuje odlisne
zpracovani (nastavit tabulku na rozumny vychozi stav namisto
spolehani na to, ze uz byla drive postavena).

Docasne diagnosticke checkpointy (`167320.branchA.*`) PONECHANY v kodu
pro pokracovani v pristi session - odstranit az po nalezeni root
cause.

## Vlna 25l: PROAKTIVNI KOMPLEXNI SWEEP - vsechny volani funkce pres
## ulozenou 32bit hodnotu (60+ mist, 9 souboru)

Na uzivateluv vyslovny pozadavek proveden kompletni sweep vzoru
`(*(RETTYPE (**)(ARGS))(zaklad+offset))(...)` ("vtable"-styl volani
pres 32bit ulozenou hodnotu, ktera na x64 spadne kvuli 8bajtovemu
cteni misto 4). Nalezeno a opraveno **60 vyskytu v 9 souborech**:

- **orion_part_22.c** (25) - vcetne `dword_18497C`-based AIL/modem
  ovladac dispatch (~15 mist) a `sub_14D1C2` wrapperu (1 definice,
  automaticky opravila 9 volajicich mist beze zmeny)
- **orion_part_23.c** (11) - vcetne `a1+2124/2128/2164` (COM port
  ovladac objekt)
- **orion_part_24.c** (10) - stejny COM port ovladac vzor
- **orion_part_17.c** (4) - `a1+30/34` (UI/text render objekt)
- **orion_part_20.c** (2) - `dword_18497C+35/39`
- **orion_part_18.c** (1)
- **orion_part_26.c** (1, `v1+10` - zbytek po drivejsim
  `dword_18A69C`/`a3+4` fixu ve stejnem souboru)
- **orion_part_01.c** (1) - `sub_107C2` definice (adresa lokalni
  promenne interpretovana jako 8bajtovy ukazatel), automaticky
  opravila 13 volajicich mist v 6 dalsich souborech beze zmeny

**Novy sdileny nastroj:** makro `VCALL(adresa, funkcni_typ)` pridano
do `decomp_compat.h` - prevadi `(*(RETTYPE (**)(ARGS))(EXPR))(args)`
na citelne `VCALL(EXPR, RETTYPE (*)(ARGS))(args)`, ktere spravne
precte 32bit hodnotu a rozsiri ji az pri pretypovani na ukazatel.
Pouzitelne pro budouci podobne nalezy bez rucniho opakovani vzoru.

Kazdy vyskyt pred opravou krizove overen proti sousednimu
`*(_DWORD*)(stejny_zaklad+stejny_offset)` cteni ve STEJNEM souboru,
kde to bylo mozne (potvrzuje, ze jde o 32bit ulozenou hodnotu, ne o
skutecny native-width ukazatel). Rebuild po kazde davce souboru (0
chyb pri kazdem kroku). Zaverecny regresni test: beh sekvence az po
jiz zdokumentovany bug #4 (`dword_18A60C` tabulka, task #17) beze
zmeny/bez novych padu - potvrzuje, ze sweep nic nerozbil.

**DALSI, VETSI a STRUKTURALNE JINY vzor nalezen, NEOPRAVOVAN:**
siroky pruzkum `\*\(\w+ \*\*\)` (obecnejsi vzor, ne jen volani funkci)
odhalil **251 vyskytu** napric projektem. Velka cast (namatkou
overeno orion_part_10.c) ma tvar `*(TYP **)((char*)&LOKALNI_PROMENNA
+ N)` - cteni KONKRETNICH BAJTU uvnitr LOKALNI (stack) promenne
(typicky Watcom "slouceny registrovy argument" artefakt, kde IDA
spojila vice registru do jedne fake velke promenne a dekompilator pak
cte konkretni podregiony pretypovanim). Tohle NENI stejna trida bugu
jako "ulozena 32bit adresa v globalu/struct poli, ktera potrebuje
rozsireni" - je to cteni bajtu z JIZ SPRAVNE (nativne) alokovane
lokalni promenne, takze slepy sweep stejnym vzorem jako vyse by byl
nespravny a rizikovy bez individualniho posouzeni KAZDEHO mista (jaky
je skutecny puvod/vyznam dat na danem bajtovem offsetu). **Ponechano
pro samostatnou, opatrnejsi analyzu v budouci session** - nejde o
mechanickou opravu.

## Vlna 25m: bug #4 - SKUTECNY root cause nalezen a z velke casti opraven -
## bitstreamovy kurzor se resetoval mezi volanimi sub_164600 (task #17
## pokracovani, na uzivateluv navrh "porovnej s dosboxem" a "pridej vic
## kontrolnich bodu pred timto mistem, najdi kde se to rozchazi")

Pokracovani vlny 25k (`dword_18A69C(v15)` pad - user poskytl DALSI presny
VS-debugger repro na stejnem funkcnim retezci).

**Skutecny root cause nalezen pres asm analyzu `sub_1646A0`:** bitstreamovy
kurzor (`a5` parametr napric `sub_164600`/`sub_164200`/`sub_1642A0`) se v
PUVODNIM asm predava IMPLICITNE pres registr ESI, ktery se nastavi JEDNOU
(`a1+4096`) hned po vypoctu `dword_18A68C`/`690`, a NIKDY se pred zadnym
ze 4 `call sub_164600` znovu nenacita - kurzor tak PRIROZENE prezije
(a postupuje) napric vsemi 4 volanimi, protoze ESI je STANDARDNE
callee-saved registr. Dekompilator tohle spatne zrekonstruoval jako
`(unsigned int*)(a1+4096)` PREPOCITAVANE identicky pri kazdem ze 4 volani -
tise RESETOVALO kurzor na zacatek pri kazdem volani, cimz se volani 2-4
citala uplne SPATNA DATA (misto pokracovani tam, kde skoncilo volani 1).

**Fix:** `sub_1646A0` ted drzi JEDNU lokalni promennou
`unsigned int *bitstreamCursor` a predava `&bitstreamCursor` do vsech 4
volani `sub_164600`. Signatury `sub_164600`/`sub_164200`/`sub_1642A0`
zmeneny z `unsigned int *a5` (hodnota) na `unsigned int **a5` (ukazatel na
volajiciho kurzor), vsechna interni `*a5++` prepsana na `*(*a5)++` (cte
soucasnou hodnotu, POSOUVA kurzor VOLAJICIHO). **Bonus nalez:** `sub_164200`
se navic vola z 9 dalsich mist uvnitr `sub_1676F0` (orion_part_26.c) se
SDILENOU lokalni promennou `v7` - i TAM byl potreba stejny fix
(`v7`→`&v7`), protoze funkce mezi jednotlivymi `sub_164200` volanimi sama
cte dalsi bity ze STEJNEHO `v7` a bez threadingu by take cetla ze
spatneho mista.

**Overeni (checkpointy + dosbox porovnani):** pred fixem port bral pro
4 volani `sub_164600` uvnitr JEDNE `sub_1646A0` vetve `1,0,0,0`
("velky strom" jen pro prvni, zbytek chybne "maly/reuse"). Dosbox
potvrdil original bere VZDY `1,1,1,1` (vsechna 4 vzdy stavi realny
strom). Po fixu kurzor spravne POSTUPUJE mezi volanimi (misto
zustavani na stejne hodnote) - delta pro cele volani #1
(pred-prvnim-volanim → pred-druhym-volanim) je nyni **68256 bajtu**,
dosbox potvrzuje original spotrebuje **68252 bajtu** - rozdil pouhe
**4 bajty (1 slovo)** z celkovych ~68 tisic!

**Zuzeno jeste dal (dosbox DUMPREGS na presnych asm adresach
loc_164666/loc_164676):** spotreba OBOU volani `sub_164200` (uvnitr
`sub_164600`, pro `dword_18A68C`/`690` stromy) SEDI PRESNE s originalem
(320 a 160 bajtu, bit-presne). Rozdil 4 bajty je tedy izolovan
VYHRADNE uvnitr `sub_1642A0` (drivejsi fix z vlny 24d) - nekde v
tamnim stavebnim cyklu se cte o jedno slovo bitstreamu navic oproti
originalu. **OTEVRENO pro pristi session** - dalsi krok: bit-presne
porovnat `sub_1642A0`v vnitrni smycku (preambule word_18A7E0/E2/E4 je
pevna/deterministicka, podezreni padá na strom-stavici smycku a jeji
ukoncovaci logiku).

Docasne diagnosticke checkpointy (`164600.entry.*`, `1646A0.cursor.*`,
`164600.big.cursor_*`, `167320.branchA.*`, `167320.a3*`,
`167320.dword_18A69C`) PONECHANY v kodu pro pokracovani v pristi
session.

## Vlna 25n (2026-07-27): DALSI cast stejne tridy bugu - bitovy akumulator take musel byt globalni

Pokracovani vlny 25m. Po fixu kurzoru (`a5`) `sub_1646A0` porad volalo
`sub_164600` s vysledkem vetev `1,0,0,0` (mel byt `1,1,1,1`) - potvrzeno
novym dosbox-nezavislym testem primo v portu (checkpointy
`1646A0.cursor.before2/3/4` se vubec nehnuly, `164600.entry.v5_branch`
bylo 0 pro volani 2-4).

**Root cause: DRUHA cast stejneho bit-readeru (aktualne nactene,
castecne spotrebovane slovo - "akumulator") byla take jen mistni
promenna/hodnotovy parametr, ne perzistentni registr.** `byte_18A6C0`
(pocet zbyvajicich bitu v akumulatoru) uz byl globalni a fungoval
spravne, ale samotna HODNOTA akumulatoru (`a1` v `sub_164200`, `a3` v
`sub_1642A0`/`sub_164600`) se pri kazdem volani/navratu funkce ztratila
- presne stejna trida bugu jako kurzor ve vlne 25m, jen druha polovina
te same dvojice registru.

**Fix:** novy globalni `unsigned int g_smkBitAccum` (orion_data.c,
extern v orion_common.h, vedle `byte_18A6C0`). Odstraneny parametry
nesouci akumulator ze signatur `sub_164200` (byl `a1`), `sub_1642A0`
(byl `a3`), `sub_164600` (byl `a3`) - vsechny ted primo ctou/zapisuji
`g_smkBitAccum`. `sub_1642A0` navic na konci publikuje sve zbyvajici
stav (`g_smkBitAccum = v43;`) pro navazujici volani. Opraveno i 9
volacich mist `sub_164200` v `sub_1676F0` (orion_part_26.c, per-snimkovy
dekoder) na stejny vzor (seed pred volanim, cist g_smkBitAccum po
volani misto zastaraleho mistniho kopie) - overeno jen mechanicky
(kompiluje, odpovida vzoru), NE jeste bit-presne proti dosboxu (tahle
cesta jeste neni v behu dosazena).

**Overeno primo v portu:** po fixu vsechny 4 volani `sub_164600` z
`sub_1646A0` ted berou vetev `1,1,1,1` (`164600.entry.v5_branch`=1
4x) a kurzor postupuje monotonne - PRESNE jako original. Tabulky
`block18A610[]`/`dword_18A60C` uz nejsou `0xCDCDCDCD` (neinicializovana
pamet), ale realna postavena data.

**NOVY, JINY bug odhalen az timhle fixem (drive skryty pod garbage
daty):** `sub_167320` porad pada na `dword_18A69C(v15)`, ale ted uz s
JINYM (realnym, ne nahodnym) parametrem. Kolem radku 1141 je
`/* __asm: jmp dword_18A650[ecx*4] */ DECOMP_TODO("inline asm");` -
Hex-Rays neprelozil vypocitany skok (jump table dispatch do jedne ze 4
funkci `sub_164A40`/`sub_164DA0`/`sub_167040`/`sub_1655B0`, nebo jejich
`loc_*` alternativ pri `dword_18A6AC==1`). V C kodu se misto skoku proste
PROPADNE do nasledujiciho kodu (`dword_18A69C = *(a3+4); ... volani
dword_18A69C(v15);`), coz je STRUKTURALNE SPATNE - original by mel
skocit jinam a nikdy se sem takhle propadnout. **Toto je novy, vetsi
ukol pro pristi session: rekonstruovat jump-table dispatch na radku
~1141 (sub_167320), ne dalsi drobny pointer-bug.**

## Vlna 25o (2026-07-27): rekonstrukce jump-table dispatche v sub_167320 - castecny uspech, novy bug objeven

Navazuje primo na 25n. `sub_167320`'s `jmp dword_18A650[ecx*4]` (radek ~1141,
puvodne `DECOMP_TODO("inline asm")`) je vstup do trampoliny sdilene s
`sub_1664F0`/`sub_166830`/`sub_167040`/`sub_167190` (a sesterska ctverice
`sub_164A40`/.../`sub_1655B0` pro jiny bitovy rezim) - kazda z nich po
zpracovani jednoho "bloku" dela `JUMPOUT(0x1675C0)` (skok ZPET do
sub_167320's block-type dekoderu na dalsi symbol) nebo `JUMPOUT(0x1676C0)`
(skok do sub_167320's epilogu - cely per-snimkovy decode hotovy).
`JUMPOUT` byl dosud no-op stub (decomp_compat.h) - tise se propadal na
prvni `return` za nim, takze `sub_1664F0` (uz driv dekompilovana, 260
radku) nikdy fakticky neucastnila dekodovaci smycky.

**Rekonstrukce (potvrzena dosbox-x DUMPREGS na loc_167694 vs sub_1664F0
entry - esi/ebp/edi jsou IDENTICKE pres jmp, jen eax/ecx/edx jsou
scratch):** 3 nove globalni promenne (`g_smkFrameAccum`=ebp, `g_smkFrameCursor`
=esi, `g_smkFrameOutput`=edi, orion_data.c) drzi stav sdileny napric CELOU
touhle tramponlinou - presne stejna trida bugu jako 25m/25n (perzistentni
registr, decompilator ho modeloval jako fresh hodnotu/parametr). Extrahovan
`Smk167320_DecodeBlockTypeAndDispatch()` (novy, orion_part_26.c) z
puvodniho LABEL_22 bloku - vraci `SmkFrameStatus` (`Continue`/`Done`)
misto jednosmerneho jmp; `sub_167320` ho ted vola ve `while` smycce.
`sub_1664F0` prepsana na bezparametrovou (krome `a1`) fci pouzivajici tyhle
3 globaly, `JUMPOUT(0x1675C0)`->`return SmkFrame_Continue`,
`JUMPOUT(0x1676C0)`->`return SmkFrame_Done`. Ostatnich 7 dispatch cilu
(166830/167040/167190/164A40-rodina/loc_ varianty pro `dword_1826AC==1`
rezim) jsou porad NEPORTOVANE (byly uz predtim no-op stuby v link_stubs.c)
- nahrazeny bezpecnym `SmkDispatch_NotImplemented()` (checkpoint + Done)
misto tichych `return 0;`, takze zasah je videt v trace misto tise
spatneho chovani.

**4. objevena instance stejne tridy bugu behem testovani:** dekodovany
block-type symbol (`v19`/eax) sam byl TAKY perzistentni pres cele volani
(kod dela jen `LOWORD(v19)=...`, horni slovo prezije z predchoziho stavu
registru) - po extrakci do samostatne funkce byl `v19` cerstva
neinicializovana lokalni promenna, takze horni bity byly smeti. Pridan
4. globe `g_smkBlockTypeSymbol`, seedovan spolu s ostatnimi v `sub_167320`.

**Vysledek testovani:** puvodni `dword_18A69C` crash v `sub_167320` UZ
NENASTAVA - dispatch spravne dojde do `sub_1664F0` (potvrzeno
`dispatch.index=0`). **Ale hned na 1. volani `sub_1664F0` pada s
`STATUS_HEAP_CORRUPTION` (0xC0000374)** - `dispatch.block_type_symbol`
vychazi extremne velke (~400 milionu), coz znamena `dword_18A7F4 += a1;`
v `sub_1664F0` pretece do gigantickeho cisla a nasledujici
`do {*v5++=1;} while(v5!=v6);` (byte-coverage marking smycka,
`dword_18A7F0`/`7F4`/`7F8`) zapisuje daleko mimo alokovany buffer -
crash se hlasi az v pozdejsim, nesouvisejicim heap volani (typicke pro
heap-corruption, ne prime AV na miste zapisu). **OTEVRENO pro pristi
session:** bud je hodnota `g_smkFrameAccum`/`g_smkFrameCursor` seedovana
spatne (v13/v14 z `sub_167320`'s vlastniho `a1` parametru - overit, ze
tohle `a1` (per-snimkova komprimovana bitova data) je na spravnem
miste/offsetu), nebo je chyba primo v prevzatem LABEL_22 dekodovacim
kodu (nikdy predtim netestovano, protoze se k nemu behem cele historie
portu nedostalo - mozna ma svou vlastni, jeste neobjevenou chybu).
Diagnosticke checkpointy `167320.seed.*`, `1664F0.write.g_smkFrameOutput`,
`dispatch.block_type_symbol/index` ponechany v kodu.

**Root cause nalezen a opraven (uzivatel: "pokracuj s dumpy z dosboxu"):**
dosbox-x DUMPREGS primo na `Debug/diss/Orion2.exe.asm` @ `loc_167694`
(0x167694) potvrdil presny asm:
```
mov edx, eax
mov ecx, eax
and edx, 0FCh
and ecx, 3
mov edx, dword_1826E0[edx]
mov dword_182664, edx      ; <- edx ulozeno do globalu PRED jmp
jmp dword_182650[ecx*4]     ; <- edx zustava live v registru PRI skoku
```
a `sub_1664F0`'s uplne prvni instrukce: `add dword_1827F4, edx` (NE eax!).
**Muj puvodni predpoklad byl spatny:** myslel jsem, ze dispatch cile
dostavaji jako "a1" cely dekodovany symbol (eax/`g_smkBlockTypeSymbol`),
ale ve skutecnosti je to EDX - presne ta HODNOTA, co se ulozila do
globalu `dword_18A664` tesne pred skokem. Fix: `sub_1664F0(dword_18A664)`
misto `sub_1664F0(g_smkBlockTypeSymbol)`. **Overeno primo v portu:**
dispatch smycka ted probehne uspesne 4800x (skutecny per-pixel decode,
`g_smkFrameOutput` se hezky posouva po 4 bajtech), zadny heap-corruption
pad. **Novy, mnohem vzdalenejsi crash frontier:** `sub_167F40`
(volana z `sub_14A2D0` <- `sub_132869` <- `sub_14DF7` <- `sub_24ED3`) -
ZCELA nove misto, nikdy predtim nedosazene. Task pro pristi session:
prozkoumat `sub_167F40`.

**Vlna 25p (2026-07-27): sub_167F40 pointer-width fix opraven, ale odhalil DALSI bug - nekonecna smycka.**
Uzivatel poslal screenshot pádu presne v `sub_167F40` radek 2040
(`if (*v2) goto LABEL_14;`, `v2 = 0xFFFFFFFFFFFFFFFF`). Root cause: stejna
trida x64 pointer-width bugu jako celym souborem - `v2 = *(_WORD**)(a1+52);`
cte 32bit ulozenou hodnotu jako 8B nativni ukazatel (potvrzeno souvisejicim
zapisem `*(_DWORD*)(a1+52)=v2;` o par radku niz - a1+52 je genuinne 32bit
slot). Fix: `v2 = (_WORD*)(uintptr_t)*(_DWORD*)(a1+52);`.

**Po opravě: zadny pad, ale NEKONECNA SMYCKA.** Test bezel pres 4 miliony
radku diagnostiky bez ukonceni (uzivatel: "už je to dlouho a nic se
nevypisuje" - proces jsem ukoncil). Analyza trace ukazala: `dispatch.
block_type_symbol` je VZDY presne stejna hodnota (405864448) po CELOU
dobu behu (1.47 milionu dispatch volani, 0 odlisnych hodnot), a
`1664F0.write.g_smkFrameOutput` cykli pres presne stejnych 4800 adres
dokola (presne odpovida poctu uspesnych dispatchu z predchozi vlny 25o,
nez to padalo v sub_167F40). **Zavěr: po fixu sub_167F40 uz nekrachuje,
ale neco zpusobuje, ze se cely 4800-dispatch blok/snimek dekoduje porad
dokola od zacatku, misto aby postoupil dal (dalsi snimek, nebo konec
dekodovani).** Podezreni: `sub_167F40`'s navratova hodnota/vedlejsi
efekty (asi "je dalsi radek/blok k dekodovani?" signal) nebo jeji
volajici (`sub_14A2D0`) spatne interpretuje stav a restartuje misto
postupu. **OTEVRENO pro pristi session:** analyzovat `sub_167F40` cely
(ne jen radek s pádem) + `sub_14A2D0` volajici logiku, dosbox porovnat
kolikrat se `sub_167F40`/`sub_14A2D0` maji volat na 1 snimek v originale.
Take zvazit odstraneni/ztlumeni verbose diagnostiky (`1664F0.write.*`,
`dispatch.*`) pred dalsim testem - miliony radku zpomaluji test na
neprakticke tempo.

**Aktualizace (uzivatel: "nahraj z dosboxu snimky obrazovky a porovnej"):**
misto register-trace pristupu pridan primy vizualni nastroj -
`Port::Vga::DumpFrameIfRequested()` (port_vga.cpp) pise skutecny
framebuffer+paletu (raw + human-viewable BMP) na N-ty `Present()` volani,
rizeno env `REORION2_DUMP_FRAME=N` / `REORION2_DUMP_DIR`. Ztlumena
verbose diagnostika (`1664F0.write.*` odstraneno, `dispatch.*` throttled
na kazde 5000. volani).

**VELKY milnik:** snimky 20/50/150 ukazuji SPRAVNE dekodovane logo SIMTEX
(cerne "S" na sedem pozadi) s plynulym fade-in (tmave->stredni->plne) -
vizualni potvrzeni, ze zakladni obrazova data + paletovy fade fungujic
spravne (pravdepodobne z drivejsi, jiz opravene casti pipeline - staticky
obraz + paleta, ne nutne primo z teto session).

**Ale hlubsi test odhalil: PRAVY nekonecny cyklus existuje.** Delsi beh
(90s, throttled diagnostika) ukazal: zpocatku `g_smkFrameOutput` (a
`g_smkFrameCursor`/`byte_18A6C0`/`g_smkFrameAccum`) SKUTECNE postupuji
(zdrave rostouci hodnoty, zadna stagnace) - ale po case se zacykli do
PRESNE 6 opakujicich se `g_smkFrameOutput` adres donekonecna
(1844C2EC, 18460D8C, 1845C82C, 18458AEC, 1845458C, 1845002C, dokola).
`dispatch.index` zustava po celou dobu 0 (sub_1664F0), zadny
`UNIMPLEMENTED_*` stub nebyl zasazen - tedy NENI to chybejici
dispatch cil, ale bug primo v `sub_1664F0`'s vlastni "radek/blok
hotov, pokracuj dal" logice (kandidati: `dword_18A670`/`dword_18A688`
"dalsi radek" vypocet, nebo `dword_18A668`/`dword_18A674` "block done"
reset - 6 opakujicich se adres napovida na malou strukturalni smycku,
ne na cely znovu-dekodovany snimek). **OTEVRENO pro pristi session:**
dosbox DUMPREGS/DUMPMEM primo na "radek dokoncen" vetve v sub_1664F0
(asm ekvivalent radku 872-883 v orion_part_26.c), porovnat kolikrat a
jak `dword_18A670` klesa v originale vs portu na stejnem miste.

**Vlna 25p - zpresneni pomoci "stejna udalost na obou stranach" metodiky
(na zadost uzivatele):** puvodni srovnani pocitalo Present() volani
(port) vs sub_125814 zasahy (dosbox) - NEEKVIVALENTNI udalosti (port
Present() se vola i pri busy-waitu bez zmeny obsahu). Opraveno:
1. **`PortVga_WaitVsyncSlow()`** (port_vga.cpp) - `sub_12C2C6` (cekani na
   N BIOS tiku) volalo plne `PortVga_WaitVsync()` (Present+14ms) v KAZDE
   iteraci smycky, ale 1 BIOS tik = ~55ms → ~4x zbytecnych Present()
   volani na kazdy skutecny tik cekani. Nova varianta ceka 50ms mezi
   Present() volanimi behem busy-waitu (`sub_12C2C6` prepnuto na ni),
   `PortVga_WaitVsync` (pouzivana pro SKUTECNE nove snimky) zustala
   nezmenena.
2. **Dedup na obou stranach** - `DumpFrameIfRequested`
   (REORION2_DUMP_FRAME_RANGE) i dosbox-x `DUMPFRAME` ted zapisuji soubor
   jen pri SKUTECNE zmene obsahu (framebuffer NEBO paleta), ne na kazdy
   zasah breakpointu - takze oba proudy meri stejnou udalost ("byl
   vykreslen novy/odlisny snimek"), ne casovy vzorek.

**Po opravach: 80 odlisnych snimku z kazde strany, srovnano.** Vizualne
potvrzeno (frame index 10): **originál uz je u animace MICRO PROSE**
(svisle pruhy skladajici pismena), **port je porad jen u sotva
rozsviceneho loga SIMTEX**. Tedy: i po odstraneni busy-wait redundance a
merenim "stejne udalosti", port stale generuje VYRAZNE VICE odlisnych
snimku na stejny usek obsahu nez original. **Zaver: existuje skutecny bug
- port pravdepodobne dekoduje/prezentuje nekolik lehce odlisnych
mezistavu tam, kde original postupuje cistě v jednom kroku.** Toto se
kryje s drive nalezenym "6 opakujicich se adres" pozorovanim (vlna 25p
drive) - nejspis STEJNA prevlekle-formulovana chyba v sub_1664F0/
sub_167320's "blok/radek hotov, pokracuj dal" logice, ne skutecna
nekonecna smycka, ale zdroj nadbytecnych temer-duplicitnich snimku.
**OTEVRENO pro pristi session:** najit presne misto v sub_1664F0, kde
vznikaji tyhle "skoro stejne" mezistavy (kandidati: `dword_18A670`
row-advance, `dword_18A668`/`674` block-reset) - pravdepodobne DALSI
instance "perzistentni registr vs fresh hodnota" bugu (5. tato session),
tentokrat v necem, co by melo drzet stav MEZI radky/bloky ale
neudrzuje ho spravne.

**Vlna 25p - PRULOMOVY vysledek (na zadost uzivatele, primy in-process
compare-and-abort misto externich nastroju):** pridana
`CompareAgainstReferenceIfChanged()` (port_vga.cpp) - nacte dosbox-x
DUMPFRAME referencni snimky (`REORION2_COMPARE_DIR`), a pro kazdy
odlisny port-snimek je porovna s AKTUALNI referencni pozici (kurzor,
NE 1:1 index - port muze generovat "extra" snimky navic, tolerovano az
do 300 za sebou nez se to prohlasi za skutecnou divergenci). Vysledek
behu (80 referencnich snimku, SIMTEX->MICRO PROSE usek):

- **Reference #0-2 (SIMTEX fade-in): port potreboval 116 "extra" snimku**
  nez dosahl obsahu odpovidajicim referenci #2.
- **Reference #3 az #41+ (SKUTECNA MICRO PROSE animace, pohybliva
  pismena): port sedi DOKONALE, 0 extra snimku pro KAZDOU jednu
  referenci, snimek za snimkem, presne v poradí.**

**Zaver: block/pixel decoder (cely fokus teto session, vlny 25n/25o/25p)
je SPRAVNY - overeno bit-presne pro realny pohyblivy obsah.** "6
opakujicich se adres"/"nadbytecne snimky" pozorovani z drivejsi casti
vlny 25p bylo ZAVADEJICI - nebyl to bug v sub_1664F0's radek/blok
logice, ale izolovany problem konkretne v SIMTEX fade-in useku (prvni
2-3 realne snimky). **Pristi krok: prozkoumat SIMTEX-specificky fade
mechanismus** (pravdepodobne opakovane volani PortVga_SetPaletteEntry
s malymi prirustky mezi kazdym Present(), misto primeho skoku na
cilovou barvu jako original) - kandidati: sub_132A11/byte_1BB358/
sub_131F7B/sub_132AF8 retez z vlny 25, NEBO mozna vubec neni chyba v
dekodovani, ale v tom, ze port generuje vic PRESENT udalosti behem
fade-in casti nez original (rozdil v tom, kolikrat se `Smk167320_
DecodeBlockTypeAndDispatch`/`sub_1664F0` zavola/vraci "continue" pro
tenhle konkretni typ snimku vs original). Nastroj (`REORION2_COMPARE_DIR`
+ `REORION2_COMPARE_SKIP`) je pripraven pro rychlou iteraci pri
dalsim ladeni - staci spustit port s novym dosbox dumpem.

**OPRAVA (uzivatel mel pravdu):** "116 extra snimku" byl artefakt
mereni, ne skutecny bug. `sub_125814` (dosbox trigger) reaguje VYHRADNE
na zmenu PIXELU (dirty-rect blit) - cisty paletovy DAC-ramp krok (fade)
zadnou takovou udalost nevyvola. Port ale povazoval JAKOUKOLI zmenu
(pixel NEBO paleta) za "novy snimek", takze behem SIMTEX fade-in (pixely
konstantni, jen paleta postupne jasni) generoval desitky falesnych
"extra" zaznamu, ktere dosbox strana vubec nezachytava. Fix: trigger
(`CompareAgainstReferenceIfChanged` i `DumpFrameIfRequested`) ted reaguje
JEN na zmenu framebufferu (pixelu), paleta se porovnava, ale negeneruje
novou "distinct frame" udalost sama o sobe.

**Po oprave: 116 extra snimku -> jen 4 (SIMTEX), a od reference #3
(skutecna MICRO PROSE animace) az po #48: 46 PO SOBE JDOUCICH
snimku s NULOVYM poctem extra snimku, presna shoda kazdy jeden.**
Zastaveni na referenci #49 = cerna obrazovka (fade-out konec MICRO
PROSE segmentu pred dalsi scenou) - pravdepodobne STEJNA trida
paleta/pixel hranicniho jevu jako SIMTEX fade-in, ne novy bug (dosbox
capture mel `maxcount=80`, konci prave v teto prechodove oblasti).

**ZAVER (potvrzeno): block/pixel decoder (vlny 25n/25o/25p) je SPRAVNY,
bit-presne overeno pro 46 po sobe jdoucich realnych snimku pohyblive
animace.** Zbyvajici "SIMTEX/fade-out" hranicni pripady jsou
pravdepodobne dalsi instance stejneho pixel-vs-paleta mereni artefaktu,
ne dekoder bug - overit stejnym pristupem (dalsi dosbox capture pokryvajici
vice snimku za cerny prechod) pokud bude potreba, ale jadro prace teto
session je hotove a overene.

**Vlna 25p - DALSI SKUTECNY BUG NALEZEN (uzivatel: "hledej dalsi rozdil"):**
rozsireny dosbox capture na 250 referencnich snimku (misto 80) potvrdil:
po referenci #48 (posledni presne sedici snimek) originál pokracuje
DALSIMI snimky - referencni snimek #49 je cerna (fade-out konec MICRO
PROSE), a kolem snimku #70 uz originál ukazuje UPLNE NOVOU scenu (vesmirne/
mlhovinove intro cinematics, letterboxovany format, hvezdy). **Port se
ale NA REFERENCI #49 SKUTECNE ZASEKNE** - dlouhy beh (300+ pokusu) ukazal
`palette_mismatches` USTALENE NA 734` (identicka hodnota desitky vzorku
za sebou) a `pixel_mismatches` kolisajici kolem ~306150-306560 (z 307200
celkem) BEZ KONVERGENCE k nule. Toto NENI mereni artefakt (pixel-only
trigger uz je opraveny) - port genuinne neprejde do cerne/dalsi sceny,
jak to dela original.

**Diagnoza (hypoteza, needle jeste overena dosboxem):** pravdepodobne
5. instance stejne tridy bugu jako cela tato session (25m/25n/25o) -
"blok/radek/snimek hotov, pokracuj dal" logika v sub_1664F0/sub_167320
se u TOHOTO KONKRETNIHO prechodu (konec jednoho SMK segmentu, zacatek
dalsiho/fade-out signal) nespravne zastavi/opakuje misto postupu -
podobne jako drivejsi "6 opakujicich se adres" pozorovani, ale tentokrat
skutecne bez zotaveni (predchozi pozorovani bylo z SIMTEX fade-in, kde
se ukazalo byt jen mereni artefakt - TOHLE uz je overeno spravnou
metodikou a je REALNE).

**OTEVRENO pro pristi session:** najit presne misto, kde se
end-of-segment/fade-out signal (pravdepodobne dword_18A670==0 nebo
podobny "vsechny bloky hotovy" test v sub_1664F0, nebo navratovy kod
z celeho sub_167320 volani zpet do sub_132869/sub_14A2D0) neprojevi
spravne - dosbox DUMPREGS na teto konkretni hranici (runtime adresa
kolem konce MICRO PROSE segmentu, cca dosbox cycle odpovidajici
referenci #48->#49 v `dosbox_frames4/frame_00048.raw`->`_00049.raw`)
prime porovnat s portem. Nastroj pripraven: `REORION2_COMPARE_DIR=
dosbox_frames4 REORION2_COMPARE_SKIP=2`, 250 referencnich snimku k
dispozici, staci upravit `kMaxExtraFrames` v `CompareAgainstReferenceIfChanged`
(port_vga.cpp) pokud treba vice/mene trpelivosti pred ohlasenim divergence.

**Vlna 25p pokracovani 2 (uzivatel: "analyzuj dumpy dalsich promennych,
najdi a oprav"):** VIZUALNE presne identifikovan bug. Cisty beh (bez
compare-overhead) dokonci CELE intro za 150s bez jedineho zasahu
UNIMPLEMENTED stubu (dispatch_index vzdy 0, cela session) - vyvraceno
podezreni na chybejici dispatch cile. Zachycen port frame batch
(`REORION2_DUMP_FRAME_RANGE=1:70`) presne pres prechod MICRO PROSE ->
cinematics: **frame #55 (prvni po MICRO PROSE) ukazuje spravny
letterboxovany obdelnik na spravnem miste, ale VYPLNENY PRAVIDELNOU
MRIZKOU/SACHOVNICI tecek** misto hladke vesmirne/mlhovinove sceny
(kterou dosbox ukazuje spravne, viz drivejsi `d4_70.png`). Frame #59
(o par snimku pozdeji) ukazuje stejny mrizkovy artefakt zesileny.

**Hypoteza 1 (vyvracena testem):** stridy `dword_18A660/668/66C/670/
674/684/688` (nastavovane v sub_167320 z `a3+8..a3+28` pri KAZDEM
volani) by mohly zustat spatne/zastarale pro novy typ obsahu. Pridana
diagnostika (`167320.strides.*`, throttled kazde volani) a testovano
pres 646 po sobe jdoucich volani sub_167320 (60s bez compare-overhead,
tedy hluboko do videa) - **VSECHNY stridy zustavaji NAPROSTO KONSTANTNI
(674=120, 670=40, 66C=1916, 684=1920, 660=640, 688=2080) po CELOU
zachycenou dobu.** Tato hypoteza je tedy vyvracena - stridy NEJSOU
priciny mrizkoveho artefaktu.

**OTEVRENO pro pristi session:** presne korelovat sub_167320 call-count
(diagnostika `167320.strides.n`) s vizualnim mrizkovym artefaktem
(kolem port frame #55 v pixel-only-triggered dump rezimu) - je potreba
bud pridat frame-dump PRIMO synchronizovany s "n" (aby se dalo rict
"artefakt se poprve objevi presne pri n=X"), a pak na TOM konkretnim
volani prozkoumat vsechny ostatni globaly (block18A610[], dword_18A664,
dword_18A678, funcs_164C45 tabulka, g_smkFrameAccum/Cursor) proti
dosbox DUMPMEM na odpovidajicim miste. Vzhledem k tomu, ze stridy jsou
konstantni, podezreni se presouva na: (a) samotna DEKODOVANA DATA
(spatne symboly/leaf hodnoty z Huffman stromu pro tento typ obsahu -
mozna je nektery z jeste neoverenych `block18A610[]` slotu spatne
sestaven), nebo (b) `funcs_164C45[]` lookup tabulka pouzita pri zapisu
pixelu (`((int16_t(*)(int,int))funcs_164C45[v18])(v18,v37)`) - tahle
tabulka NEBYLA v teto session vubec prozkoumana, muze byt zdrojem
"kazdy N-ty pixel spatne" vzoru presne odpovidajicimu pozorovane
mrizce.

**Vlna 25p pokracovani 3 - DALSI SKUTECNY BUG NALEZEN A OPRAVEN (ale
nebyl to hlavni vinik):** audit `funcs_164C45[256]` (256 generovanych
funkci volanych pri zapisu pixelu) - zadne JUMPOUT/DECOMP_TODO/pointer-
width markery, cisty kod, VYLOUCENO jako pricina. Analyza stride hodnot
(`dword_18A660=640, 18A66C=1916=3*640-4, ...`) ukazala, ze jsou VNITRNE
KONZISTENTNI se standardnim 4x4-blokovym zapisem pro 640px sirokou
obrazovku - TAKY vylouceno.

**Nalezen a opraven skutecny bug:** `dword_18A6E0` byl deklarovany jako
JEDNOTLIVY `int` (=1), ale kod ho cte jako POLE:
`*(int*)((char*)&dword_18A6E0 + (v19&0xFC))` (indexy 0-252 po 4 bajtech,
tedy az 64 prvku). **Primo potvrzeno v Debug/diss/Orion2.exe.asm** -
hned za `dword_1826E0 dd 1` nasleduji syrove bajty `db 2,0,0,0 / db
3,0,0,0 / db 4,0,0,0 ...` = citelna posloupnost 1,2,3,4,5... kterou IDA
nikdy neseskupila do pojmenovaneho pole (protoze se pristupuje jen
vypocitanym indexem, ne primym jmenem). Stejna trida bugu jako
opakovane v tomto projektu (IDA rozsekla souvislou pametovou oblast).
Fix: `int block18A6E0[64] = {1,2,...,64};` (orion_data.c), aktualizovana
deklarace (orion_common.h) a cteni (`block18A6E0[(sym&0xFC)>>2]`,
orion_part_26.c).

**Tenhle fix ale mrizkovy artefakt NEVYRESIL** (otestovano, vizualne
identicky vzor pretrval) - pravdepodobne index 0 (jedina hodnota, ktera
byla driv spravne, `=1`) byl uz drive dostatecny pro tenhle konkretni
obsah, takze fix je spravny a hodny zachovani (bude potreba pro JINY
obsah), ale NENI to hlavni pricina AKTUALNIHO problemu.

**Presnejsi charakterizace zbyvajiciho bugu (histogram bajtu):**
prohledana oblast pixelu v problematicke scene ukazuje: hodnota 0 =
62720x, hodnota 255 = 25280x, ostatni hodnoty (1, 180, 126) jen stovky-
tisice x. Tedy VETSINA dekodovanych pixelu spadne na EXTREMNI hodnoty
(0 nebo 255), jen RIDCE spravnou "stredni" hodnotu - typicky podpis
SELHANI PRUCHODU HUFFMAN STROMEM (`block18A610[]` - traversal `*v51>=0`
kdyz strom neni spravne postaveny/prochazeny, konci na okrajovych/
nedefinovanych hodnotach misto skutecneho leaf listu).

**OTEVRENO pro pristi session:** prozkoumat `block18A610[]` tree
traversal ve `Smk167320_DecodeBlockTypeAndDispatch`/`sub_1664F0` pro
TUTO KONKRETNI scenu - dosbox DUMPMEM primo na block18A610 (nebo
ekvivalentni runtime adresy tree tabulek `dword_18A600/604/608/60C`)
v okamziku, kdy se dekoduje tento snimek, porovnat bajt-po-bajtu s
portem (`PortDebug_CheckpointPtr` na stejnem miste). Alternativne
zkontrolovat, jestli 16-prvkove `block18A610[16]` neni pro tento typ
obsahu PRILIS MALE (podobna trida bugu jako prave opraveny
dword_18A6E0/64-prvkove pole).

**Vyvracena hypoteza "stromy se stavi znovu na scenu":** dosbox trace
(cyklovy rozsah 216M-300M, pokryvajici cely prechod) ukazuje, ze
`sub_1646A0` (tree-init, runtime 0x38A6A0) se VUBEC ZNOVU NEZAVOLA -
strom se stavi jen JEDNOU na zacatku celeho intra a original ho
uspesne pouziva pro VSECHNY nasledujici sceny (SIMTEX, MICRO PROSE,
cinematics). Port dela totez (taky nevola sub_1646A0 znovu) - takze
tohle NENI bug, sdileni stromu je spravne zamyslene chovani. Zajimavost:
`sub_15C850` (otevreni souboru, runtime 0x380850) SE zavola jednou
kolem cyklu 216375210 (pred cinematics prechodem) - pravdepodobne
nacitani noveho segmentu dat (ale ne noveho stromu).

**Shrnuti pro pristi session:** hlavni bug NENI v (a) stride konstantach,
(b) funcs_164C45 tabulce, (c) opakovanem stavu stromu mezi scenami -
vsechny vyvraceny primym overenim. JE to nekde v samotnem PRUCHODU
existujiciho stromu (`block18A610[]`/`dword_18A600/604/608/60C`) PRO
TENTO KONKRETNI OBSAH - histogram (0 a 255 dominantni, jen ridke stredni
hodnoty) ukazuje na traversal, ktery casto "vypadne" na okrajove/
nedefinovane hodnoty. Dalsi krok: primo porovnat dekodovany
`g_smkBlockTypeSymbol`/`dword_18A664` sekvenci s dosbox ekvivalentem
(EAX pri loc_167694, uz zname z drivejsiho vyzkumu teto session) PRO
TENTO KONKRETNI usek (kolem cyklu 290M-300M), ne jen pro logo useky
jak bylo overeno driv.

## Vlna 25p pokracovani 4 (uzivatel: "pokracuj, over si to v dosboxu")

Hluboka bisekce az na uroven jednotlivych dekodovanych bajtu:

1. **`funcs_164C45[256]` write-hodnoty (v18/v37/v38/v39) throttled
   checkpoint pres 3+ milionu zapisu pixelu:** VZDY presne 0, bez
   VYJIMKY, po celou dobu behu (logo i cinematics). Podezreni presunuto
   na tree-0 (`dword_18A600`) leaf hodnoty.
2. **Tree-0 leaf vysoke slovo (`v28>>16`) pres 3+ milionu ctení:**
   TAKY VZDY presne 0 - potvrzuje, ze KAZDY list v teto konkretni
   tabulce ma vysoke slovo nulove.
3. **Trasovano az do stavby stromu** (`sub_1642A0`, `v56` vypocet):
   nalezen mechanismus - kdyz dekodovany 16bit symbol (`v56`) odpovida
   jednomu ze 3 "escape" kodu (`word_18A7E0/E2/E4`), zapise se MISTO
   NEJ `v56=0` (list oznacen jako specialni, hodnota jde do
   `outStruct[1/2/3]`). Namereno: pro PRVNI stavemy strom (`word_18A7E0=0`)
   se toto "escape" chovani spusti u **98.4 %** vsech listu (90031 z
   91517) - takze temer VSECHNY listy v tomhle stromu skonci s
   ulozenou hodnotou `(0<<16)|1=1`, coz presne odpovida pozorovanemu
   "vzdy 0" vysokemu slovu pri cteni.
4. **PRIMO OVERENO DOSBOXEM (DUMPMEM na loc_164430, runtime 0x388430,
   ihned po preambuli prvniho stromu):** `word_18A7E0=0000,
   word_18A7E2=0000, word_18A7E4=0000` - **STEJNE JAKO V PORTU!**
   **Tato konkretni hypoteza je tedy VYVRACENA** - port se v tomhle
   bode SHODUJE s originalem bit-presne, "0,0,0" je SPRAVNA hodnota,
   ne bug.

**Dusledek:** pokud original MA TAKY `word_18A7E0=0` pro tenhle strom
(a tedy TAKY ~98% listu "escapovanych" na hodnotu 1), pak bud (a)
original NA TOHLE zjevne nezalezi, protoze skutecna barva/hodnota
prichazi JINOU cestou (mozna `v37`, ktere se z `v18` odvozuje jinak,
nez jsem predpokladal - `sub_165760(a1,a2)` bere `a2`=v37 jako VSTUP,
ne primo v18 - je mozne, ze jsem odvozeni `v37` z `v18` spatne
protrasoval), NEBO (b) tenhle konkretni symptom (v18/v28 vzdy 0) je
UPLNE V PORADKU a REALNY bug je jinde uplne (mozna v `dword_18A604`
tree, pouzitem PRED timhle, ktere dava `v10`/`a2`-parametr pro
`funcs_164C45` volani, a ktere jsem JESTE NEPROVERIL stejne dukladne).

**OTEVRENO pro pristi session (cerstva hlava doporucena, bisekce uz
je hluboka):**
- Znovu presne protrasovat `v37`'s odvozeni z `v18` (radky ~1028-1030
  orion_part_26.c: `HIWORD(v37)=HIWORD(v18); LOWORD(v37)=ROR4(v18,16);`)
  a overit, ze `sub_165760`/ostatnich 255 funkci VSTUP (`a2`=v37) je
  spravne interpretovan - je mozne, ze `funcs_164C45` funkce samy
  CTOU neco jineho nez jsem predpokladal.
- Prozkoumat `dword_18A604` tree (prvni decode v sub_1664F0, davajici
  `v10`) stejne dukladne jako `dword_18A600` - checkpoint na `v10`/`v13`
  hodnoty, overit proti dosboxu.
- Zvazit, ze `funcs_164C45[0]` (`sub_165760`, "replicate") NENI bug -
  overit, jestli original TAKY vola hlavne index 0 pro tuhle scenu
  (mozna dosbox EAX v obdobnem bode UKAZE, ze i original pouziva hlavne
  index 0 - coz by znamenalo, ze cely tenhle smer bisekce byl slepa
  ulicka a bug je uplne jinde, napr. v `dword_18A660`/vypoctu pozice
  zapisu, i kdyz stride KONSTANTY vysly spravne).
- Nastroje (`compare_frames.exe`, `REORION2_COMPARE_DIR`, checkpointy
  v `orion_part_25.c`/`26.c`) VSECHNY zustavaji funkcni a pripravene.

**ROZHODUJICI DUKAZ ZISKAN (primo z dosboxu, `loc_1666E4`, runtime
0x38A6E4 = misto `call funcs_164C45[eax*4]` uvnitr `sub_1664F0`):**
DUMPREGS na 3071 vzorcich ukazuje BOHATOU distribuci indexu v originale
(0 a 255 dohromady jen ~16.5 % vzorku - 257+250 z 3071; zbytek: 16, 1,
128, 8, 17, 32, 239, 64, 2, 127, 4, 207, 48, 247, 136, 51, 223, 12...
desitky ruznych hodnot). **Port ma NAPROTI TOMU index VZDY presne 0,
bez jedine vyjimky, pres 3+ miliony vzorku.** Tohle DEFINITIVNE
potvrzuje realny bug specificky v CTENI/PRUCHODU stromu `dword_18A600`
BEHEM PREHRAVANI (ne v jeho STAVBE, ktera byla primo overena jako
shodna s originalem).

**Rucni code-review traversal kodu** (radky ~915-1010 orion_part_26.c,
`sub_1664F0` prvni-tree-traversal `dword_18A604` vs druhy-tree-traversal
`dword_18A600`) nenasel ocividnou chybu - obe smycky jsou strukturalne
analogicke a interne konzistentni (spravne seedovani g_smkFrameAccum/
g_smkFrameCursor pred vstupem do do-while, spravny zapis zpet do
globalu behem refill). Rozdily (`&0x3FF` vs `&0x7FF`, `0xAu` vs `0xBu`
prahy) odpovidaji ocekavane RUZNE VELIKOSTI obou stromu (1024 vs 2048
zaznamu), nejsou podezrele.

## Vlna 25q (2026-07-28): *** BUG ROZLOUSKNUT *** - `loc_FFFF8` byla KONSTANTA, ne adresa

**Root cause nalezen a opraven.** Puvodni asm ma na 22 mistech
`and edx, offset loc_FFFF8` - to je AND s **konstantou 0xFFFF8**. IDA ale
tuhle immediate hodnotu zamenila za ADRESU stejnojmenneho navesti
`loc_FFFF8`, ktere v kodu skutecne existuje (uvnitr `sub_FFEEA` na
0xFFFF8) - proto dekompilat obsahuje `(unsigned int)&loc_FFFF8`.
V portu je `loc_FFFF8` deklarovana jako `_UNKNOWN loc_FFFF8;` (1bajtovy
BSS stub), takze ten vyraz vracel jeji **nahodnou runtime adresu**
misto masky. Presne stejna trida jako driv opravene `sub_10000`/
`loc_20000` (vlna 23b) - tenhle vyskyt se tehdy prehledl.

**Proc se to schovavalo tak dlouho:** maska se aplikuje VYHRADNE na
stromy, jejichz vnitrni uzly nesou `distance << 13` (tedy
`sub_1642A0`-stavene PREHRAVACI stromy), NIKDY na `sub_164200`-stavene
vnitrni bajtove stromy. Nahodna adresa ma nejake z bitu 3..19 nastavene,
takze **mělké stromy (2barevna loga SIMTEX / MICRO PROSE - male
vzdalenosti) prochazely spravne** a shodovaly se s originalem bit-presne
pres 46 snimku v rade, zatimco **hluboke stromy (bohata vesmirna scena -
velke vzdalenosti) mely vzdalenosti oriznute** → traversal vzdy skoncil
na stejnem spatnem listu. To presne vysvetluje VSECHNY pozorovane
symptomy: mrizkovy/sachovnicovy artefakt, histogram pixelu dominovany
hodnotami 0/255, i "funcs_164C45 index je vzdy 0".

**Jak byl nalezen (metodika, ktera zabrala):** primy bajtovy dump
OBSAHU STROMU z obou stran (dosbox `DUMPMEM` vs portovni checkpointy):
- vnitrni strom `dword_18A68C`: **bajt za bajtem IDENTICKY** ✓
- vnitrni strom `dword_18A690`: **bajt za bajtem IDENTICKY** ✓
- prehravaci strom `dword_18A600`: **1. polozka sedi, od 2. se rozchazi** ✗
  (port mel navic podezrely vzor - kazda licha polozka porad stejna
  `0x03197801`)
To okamzite zuzilo hledani na `sub_164590` (stavitel lookup tabulky) a
odtud na jediny podezrely vyraz - masku.

**POZOR - past pri overovani adres (stala me jedno cele kolo):** asm dump
ma datove symboly posunute o **-0x8000** vs C jmena, ale runtime adresa
se pocita z **C jmena**: `data_runtime = C_adresa + 0x216000`. Tedy
`word_18A7E0` → `0x3A07E0` (NE `0x3987E0`, coz je asm_jmeno+0x216000).
Prvni pokus cetl spatnou adresu a vratil nesmyslne nuly, coz me poslalo
za falesnou stopou. **Vzdy si mapovani over na zname hodnote** - napr.
`dword_18A690 - dword_18A68C` musi vyjit 0x800 (2048), jak to nastavuje
`sub_1646A0`.

**Fix:** vsech 6 vyskytu v C (`orion_part_25.c` 3x - `sub_164590`,
`sub_164A40`; `orion_part_26.c` 3x - `Smk167320_DecodeBlockTypeAndDispatch`,
`sub_1664F0`) prepsano z `(unsigned int)&loc_FFFF8 &` na `0xFFFF8u &`.

**Overeni po oprave:**
1. Prehravaci strom `dword_18A600` je ted **bajt za bajtem identicky** s
   originalem (vsech 16 dumpnutych polozek).
2. **45 ze 45 referencnich snimku z dosboxu (refs 0-44) port reprodukuje
   PIXEL-PRESNE** (timing-nezavisly test: pro kazdou referenci hledana
   shoda mezi vsemi portovnimi snimky).
3. Ověřeny par (ref #11 vs port frame 13) sedi **0 rozdilu v pixelech
   A 0 rozdilu v palete** (po korektnim 6→8bit prevodu).
4. Loga SIMTEX i MICRO PROSE se dal vykresluji spravne - zadna regrese.

**Bonus: 4 dalsi latentni bugy stejne tridy nalezeny a opraveny**
(vsechny overeny proti asm):
- `orion_part_21.c` `(unsigned int)&loc_100000 & v13` → `0x100000u & v13`
  (asm `test esi, offset loc_100000`)
- `orion_part_24.c` `v6 < (int)&loc_100000` → `v6 < 0x100000`
- `orion_part_16.c` `>= (unsigned int)&loc_80000` → `>= 0x80000u`
- `orion_part_03.c` `<= (unsigned int)&loc_30D40` → `<= 0x30D40u` (200000)

**POUCENI (nova polozka do kontrolniho seznamu):** kdykoli dekompilat
pouzije `&nejaky_symbol` v ARITMETICE (maska, porovnani velikosti,
test bitu) misto jako cil skoku/volani, je to skoro jiste IDA zamena
konstanty za adresu. Grep na `(unsigned int)&(loc|sub)_[0-9A-F]+` v
portu + `(and|or|add|cmp|test)\s+reg,\s+offset (loc|sub)_` v asm
odhali cely zbytek teto tridy najednou.

## Vlna 25q-2: *** DRUHY, JESTE VETSI ROOT CAUSE *** - `__ROL4__`/`__ROR4__` byly no-op pahyly

Po oprave masky `loc_FFFF8` loga sedela 45/45 pixel-presne, ale vesmirna
scena porad delala tecky. Bisekce pokracovala:
- vnitrni stromy `dword_18A68C`/`690`: bajt-identicke ✓
- prehravaci tabulka `dword_18A600`: bajt-identicka ✓ (po oprave masky)
- pocet postavenych listu: **91517 v originale i v portu - presna shoda** ✓
- hodnoty listu `i`/`j` z pruchodu vnitrnich stromu: **prvnich 12 paru
  IDENTICKYCH s originalem** (0x80000002/0x80000000, 0x80000011/0x80000003,
  0x800000D4/0x80000000, ...) ✓

**Rozpor, ktery to prozradil:** vstupy (`i`,`j`) byly PROKAZATELNE spravne
(pro 1. list davaji `v56 = 0x0002`), ale namerene `v56` bylo **0 pro
vsech 80 000 listu**. Vypocet mezi tim je jediny radek:
`v56 = __ROL4__(v53, 8);`

**Root cause:** v `link_stubs.c` bylo
```c
int __ROL4__(void) { return 0; }
int __ROR4__(void) { return 0; }
```
tedy **prazdne pahyly vracejici nulu**. Dekompilovany kod vola
`__ROR4__` **219x** a `__ROL4__` 1x - KAZDA 32bitova rotace v celem dumpu
tise vracela 0. Presne stejna trida jako `memset32` no-op pahyl z vlny 22k
("koren garbage grafiky").

**Proc to nikdo nezachytil:** `defs.h` definuje `__ROL4__`/`__ROR4__` jen
pro C++ build (sablona `template<class T> T __ROL__`); v C vetvi je jen
komentar *"For C, we just provide macros, they are not quite correct"* a
`__ROL4__` tam neni vubec. Herni .c soubory se prekladaji jako **C
(`/TC`)**, takze volani spadlo na implicitni deklaraci `int __ROL4__()`,
ktera se bez varovani slinkovala s temihle pahyly. `defs.h` navic neni
odnikud includovany.

**Fix:** skutecne implementace v `link_stubs.c` (x86 `rol`/`ror`
semantika, pocet modulo 32) + **prototypy v `decomp_compat.h`**, aby uz
nikdy nemohlo dojit k implicitni deklaraci.

**Overeni:** `v56` je ted nenulove u **99,99 %** listu (originál ma
99,86 % - 131 nul z 91517), misto predchozich **0 %**.

**POUCENI (kriticke, pridat do kontrolniho seznamu):** projit CELY
`link_stubs.c` a overit, ktere "pahyly" jsou ve skutecnosti nutne
funkce. Vzor `int NECO(void) { return 0; }` u ciste vypocetnich helperu
(rotace, memset/memcpy, bit operace) je tikajici bomba - kompiluje se,
linkuje se, nic nevarovi, a tise vrati nulu. Uz podruhe v tomto projektu
(memset32 vlna 22k, ted rotace). **Take: `/TC` (C) build + chybejici
prototyp = implicitni deklarace = zadna typova kontrola volani.**

## Vlna 25q-3: naportovana `sub_167040`; STAV NA KONCI SESSION

Po oprave rotaci se konecne LISI typy bloku - a tim se poprve vubec
zacaly volat neportovane handlery. Zmereno: `sub_167040` **641x**,
`sub_167190` 6x, `sub_166830` 6x (drive 0x, protoze index byl vzdy 0).
Ty jsou v `link_stubs.c` jako `return 0;` - nic nedekoduji a NESPOTREBUJI
bitstream, coz presne vysvetluje, proc cinematic scena porad neni v
poradku.

**Naportovana `sub_167040`** (z Debug/diss/Orion2.exe.asm, asm radky
549745-549858, 113 radku) do `orion_part_26.c`. Mapovani registru podle
uz portovane sesterske `sub_1664F0`: `edx`=a1 (delka behu z
`dword_18A664`), `edi`=`g_smkFrameOutput`, `JUMPOUT(0x1675C0)`→
`SmkFrame_Continue`, `JUMPOUT(0x1676C0)`→`SmkFrame_Done`. Pozor na dva
detaily overene proti asm: (1) coverage-marking smycka zapisuje **0**
(sesterska `sub_1664F0` zapisuje 1), (2) `*(_DWORD**)p` prepsano na
`(_DWORD*)(uintptr_t)*(uint32_t*)p` (x64 pointer-width trida).
Stub odstranen z `link_stubs.c`, deklarace opravena v `orion_common.h`,
dispatcher case 2 napojen. **Build cisty, smoke test: zasahy
`UNIMPLEMENTED_167040` zmizely (641 → 0), zadna nova regrese.**

### STAV K ZAVERU SESSION (2026-07-28)

**Vyreseno a overeno v teto session:**
1. `loc_FFFF8` konstanta vs adresa (6 mist) - prehravaci stromy ted
   bajt-identicke s originalem.
2. `__ROL4__`/`__ROR4__` no-op pahyly (219+1 volani) - `v56` ted nenulove
   u 99,99 % listu (original 99,86 %) misto 0 %.
3. 4 dalsi latentni bugy tridy "konstanta zamenena za adresu"
   (loc_100000 2x, loc_80000, loc_30D40).
4. `dword_18A6E0` deklarovan jako 1 int misto 64prvkoveho pole.
5. Naportovana `sub_167040`.
**Overeni:** 45/45 referencnich snimku z dosboxu (loga SIMTEX +
MICRO PROSE) reprodukovano PIXEL-PRESNE; titulni obrazovka i HLAVNI MENU
MOO2 se vykresluji spravne.

**Naportovany VSECHNY tri zbyvajici handlery (dokonceno):**
- `sub_167040` (asm 549745-549858, 113 r.) - 641 zasahu/beh
- `sub_167190` (asm 549868-550002, 134 r.) - solid-fill pres 4x `rep stosd`,
  fill = BYTE1(symbolu) replikovany 4x; 24 zasahu/beh
- `sub_166830` (asm 548962-549735, 773 r.) - **rozbalena smycka**: 4 skupiny
  po [dekoduj symbol -> move-to-front cache] x2 -> `mov [edi],eax` -> krok o
  radek; overeno spocitanim referenci (16x dword_182608 = 8 logickych
  pruchodu, 8x cache trojice, 4x store, 3x `add edi,dword_182660` +
  1x `sub edi,dword_18266C`). Prvni pruchod paru dela `mov eax,edx` (cely
  list), druhy `mov ax,dx` po ror (jen dolni slovo) - ulozeny dword je
  `(HIWORD(list1)<<16) | HIWORD(list2)`. Traversal vytknut do
  `Smk166830_DecodeSymbol()` (strom dword_18A608, prah 0x0C, maska 0xFFF)
  a `Smk166830_UpdateCache()` (block18A610[9..11]); 387 zasahu/beh.

**Vysledek:** `UNIMPLEMENTED` zasahy **0** (drive 653+387), a poprve se
realne pouzivaji VSECHNY ctyri typy bloku (namereno 36/11/28/3).
Refs 0-48 dal sedi **49/49 pixel-presne** - zadna regrese, build cisty.

**ALE cinematic (refs 49+) porad nesedi.** Vizualne: uz to nejsou
pravidelne tecky ani mrizka, ale fragmentovane cervene/zelene bloky se
strukturou - tedy blizko, ale ne spravne. Histogram typu bloku:
original (do cyklu 300M) **0:746, 1:60, 2:934, 3:13**; port (throttled
vzorek) zhruba 0:46%, 1:14%, 2:36%, 3:4% - tvar odpovida (0 a 2
dominantni), takze dekodovani SYMBOLU uz zhruba funguje, ale pomery
nesedi presne.

**Nejpravdepodobnejsi pricina zbytku: chyba v nekterem z mych TRECH
rucnich portu** (nejspis `sub_166830` - nejvetsi a nejsloziteji
strukturovana). **Dalsi krok pro pristi session:** overit je
per-blok proti originalu - dosbox `DUMPREGS` na vstupu kazdeho handleru
(runtime adresy: sub_166830=0x38A830, sub_167040=0x38B040,
sub_167190=0x38B190) + portovni checkpointy na stejnem miste, porovnat
SEKVENCI (edx/`dword_18A664`, `edi`/`g_smkFrameOutput`) volani po volani.
Prvni volani, kde se `edi` po navratu lisi, ukaze ktery handler a ktera
vetev je spatne.
- **Dalsi trida tichych nul k dodelani** (mimo video cestu, ale realne
  bugy): `link_stubs.c` ma `abs16`/`abs32` jako `return 0;` (33+48
  volani!), a `decomp_compat.h` ma `#define __CFSHL__(x,y) 0`
  (160 volani), `__CFADD__` (3), `__OFSUB__` (3), `__CFSHR__` (2).
  Rodina `SWORD1/3/4/5/6`, `SDWORD1/2`, `SBYTE4` (77+17+11+12+12+3+3+1
  volani) taky konci na `return 0;` pahylech - overeno, ze VSECHNA
  pouziti jsou rvalue nad prostymi promennymi, takze se daji bezpecne
  nahradit makry s IDA semantikou (`#define SWORDn(x,n)
  (*((int16_t*)&(x)+n))` atd.). `defs.h` tyhle definice ma, ale NENI
  odnikud includovany.

**Docasne diagnosticke checkpointy k odstraneni az bude hotovo:**
`1642A0.build.*`, `1642A0.innertree*`, `1664F0.pixel.*`, `1664F0.leaf.*`,
`167320.strides.*`, `167320.seed.*`, `167320.playtree*`, `1676F0.entry.*`,
`dispatch.*`.

**OTEVRENO (starsi poznamka, jiz vyresena vlnou 25q):** staticka analyza
kodu je vycerpana bez nalezeni bugu - potreba PRESNA, volani-po-volani
korelovana komparace (ne jen statisticky vzorek): pridat pocitadlo
volani `sub_1664F0`/druheho-traversalu NA OBOU STRANACH (port
checkpoint + dosbox DUMPREGS se stejnou `repeat=always` na
`loc_1666E4`), spustit OBA OD CISTEHO STARTU (ne v prubehu), a
porovnat EAX/v18 hodnotu PRO KAZDE N-te volani 1:1 (ne jen distribuci)
- to presne urci PRVNI volani, kde se port odchyluje od originalu, a
tim i PRESNY bod v bitstreamu/kodu, kde k chybe dochazi. Tohle uz
vyzaduje cerstvou, soustredenou session (hluboka bisekce, hodne
kontextu jiz nashromazdeno v teto session pro rychly start).

## Vlna 25p pokracovani: hromadny snimek+paleta diff nastroj (na zadost uzivatele)

Uzivatel pozadal o presun z register-trace metodiky na primy hromadny
diff vsech snimku+palet mezi originalem a portem. Postaveno:

1. **`DUMPFRAME` prikaz** v dosbox-x ctl protokolu (`engine.cpp`,
   `FrameWatch`/`ctl_load_dumpframe`/`ctl_check_dumpframe`) - na kazdy
   zasah EIP zapise `frame_NNNNN.raw` (768B RGB6 paleta + WxH indexovanych
   pixelu) do zadaneho adresare, az do `maxcount`. Zdokumentovat jeste
   treba do DOSBOX_CTL_PROTOCOL.md (TODO).
2. **Port strana** (`port_vga.cpp`): `DumpFrameIfRequested` rozsireno o
   `REORION2_DUMP_FRAME_RANGE=START:COUNT` (`REORION2_DUMP_DIR` spolecne) -
   dumpuje STEJNY format (`frame_NNNNN.raw`) pro primy binarni diff.
3. **`genCompare/compare_frames.c`** (kompilovano primo cl.exe, viz
   genCompare/compare_frames.exe) - cte dvojice frame_NNNNN.raw ze dvou
   adresaru, expanduje dosbox 6bit->8bit paletu stejnym vzorcem jako
   `PortVga_SetPaletteEntry` ((v<<2)|(v>>4)) a hlasi po snimcich pocet
   neshodnych paletovych kanalu + pocet/pozici neshodnych pixelu.

**Prvni test (30 snimku, breakpoint na `sub_132B41` @ 0x356B41, framebuf
0x452044, 640x480):** **VELMI POVZBUDIVY VYSLEDEK.** Pixelovy obsah
(dekodovana data) SEDI TEMER DOKONALE - 0.00% mismatch na 28 z 30
snimku! Jen snimek #1 ma 97.87% pixel mismatch (pravdepodobne
jednosnimkovy posun/zarovnani mezi tim, kdy port a original zapocitavaji
prvni Present() - ne obsahovy bug). **Paleta ale systematicky diverguje
rostoucim tempem** (worst-delta roste priblizne +4 kazdy snimek: 4, 8,
12, 16, 20, 24, 28, 32, 36, 37, 41...) - vypada to na SPATNOU RYCHLOST
fade rampy v portu (port fade bud postupuje jinym krokem, nebo je jeden
krok pozadu/napred kazdy snimek, kumulativne). Snimek #0 ma extremni
paletovy rozdil (648/768 kanalu, delta az 255) - pravdepodobne artefakt
startovniho zarovnani (jedna strana jeste nema paletu vubec nastavenou).

**ZAVER: skutecny video/blok decoder (waves 25n/25o/25p) je pravdepodobne
SPRAVNY** - shoda obsahu je silny dukaz. **Pristi krok: prozkoumat fade
rampu (sub_251EF/sub_132C80 rychlost/krok) - ne dale ladit sub_1664F0
dekoder.** Nastroj (`compare_frames.exe`) pripraven pro rychlou iteraci:
staci znovu zachytit dvojici dump (dosbox DUMPFRAME cfg + port
REORION2_DUMP_FRAME_RANGE) po kazde zmene a spustit
`compare_frames.exe dosbox_frames port_frames 640 480`.

## Vlna 25r: podezreni na artefakt merici metody (dedup asymetrie), ne na
skutecny bug ve fade rampe

Pred dalsim laděnim `sub_132C80` overeno, CO presne test v 25p meril.
Test breakpointoval `sub_132B41` (0x356B41) - tedy primo uvnitr fade-rampy,
kde se pixely v ramecku VUBEC NEMENI, jen paleta. dosbox-x strana pouziva
vlastni `DUMPFRAME` ctl prikaz (`engine.cpp` `FrameWatch`), jehoz dedup
zapisuje novy soubor pri ZMENE PIXELU **NEBO** PALETY. Portova strana
(`DumpFrameIfRequested`, batch-range rezim v `port_vga.cpp`) ale od vlny
25p (na uzivatelovu opravu pro SMACKER VIDEO test) dedupuje **jen podle
pixelu** - pro cistou paletovou fade (0 zmen pixelu) by to znamenalo, ze
port zapise jen UPLNE PRVNI snimek a pak uz zadny dalsi, dokud se pixely
nekde jinde nezmeni. To presne odpovida pozorovanemu vzorci ("worst-delta
roste priblizne +4 kazdy snimek") - je to pravdepodobne ARTEFAKT
NESOULADU DEDUP KRITERII mezi dosbox referenci (pixel-nebo-paleta) a
portovnim dumpem (jen pixel) pri INDEXOVEM porovnavani, ne nutne skutecny
bug v `sub_132C80`/rychlosti rampy.

**Oprava:** `DumpFrameIfRequested` (batch-range) i `CompareAgainstReferenceIfChanged`
v `port_vga.cpp` ted maji volitelny prepinac `REORION2_DUMP_INCLUDE_PALETTE=1`,
ktery dedup prepne na pixel-NEBO-paleta (odpovida DUMPFRAME chovani).
Bez teto env promenne je chovani nezmenene (pixel-only, jak bylo overeno
pro SMACKER video vlnou 25p) - takze zadna regrese tam, kde uz to bylo
overene spravne. Build (x64 Debug) cisty, jen predem znama C4312/C4311
varovani z existujiciho dekompilovaneho kodu.

**Pristi krok:** znovu zachytit dvojici dump pro fade test (dosbox
DUMPFRAME na sub_132B41 - nezmenene) + port (`REORION2_DUMP_FRAME_RANGE`
S:C **s `REORION2_DUMP_INCLUDE_PALETTE=1`**) a znovu spustit
`compare_frames.exe`. Pokud "rostouci delta" zmizi/vyrazne se zmensi,
byla to metodika, ne bug - dale uz neladit `sub_132C80`. Pokud delta
zustane, je to skutecny bug ve fade rychlosti/kroku a je treba ho hledat
primo v `sub_132C80`/`sub_251EF` (napr. porovnat pocet volani
`sub_132C80` mezi dvema po sobe jdoucimi dosbox-zachycenymi paletovymi
kroky vs portem - zda oba stepuji `a1` o 1 na jeden skutecny "krok").

Mimochodem: v `orion_part_26.c` (`Smk167320_DecodeBlockTypeAndDispatch`)
zustava pripravena (ale nepouzita, dokud se nenastavi
`REORION2_HANDLER_TRACE`) volani-po-volani trasovaci instrumentace pro
`sub_166830`/`167040`/`167190` (predchozi podezreni na bug v techto
hand-portovanych handlerech) - relevantni, POKUD by se fade-drift
artefakt vyvratil a vratili bychom se k rozlousknuti cinematicke sceny.

## Vlna 25r-2: *** BUG NALEZEN A OVERENY *** - `block18A6E0` mela spatnych
poslednich 5 polozek (run-length tabulka)

**Metodika (na vyslovny pokyn uzivatele): binarni zuzovani "posledni misto,
kde vsechny promenne sedi" vs "prvni misto, kde se lisi".**

1. **Snimky** (`compare_frames.exe` + `frame_stats.exe`, novy nastroj):
   overeno, ze fade rampa `sub_132C80`/`sub_251EF` je SPRAVNA - 27 po sobe
   jdoucich snimku bit-presne (paleta i pixely) po zarovnani o 1 snimek.
   Drivejsi "rostouci paletova drift +4/snimek" (vlna 25p pokracovani) byl
   ARTEFAKT MERENI: dosbox `DUMPFRAME` dedupuje pixel-NEBO-paleta, port jen
   pixel. Pridan prepinac `REORION2_DUMP_INCLUDE_PALETTE=1` (port_vga.cpp),
   ktery dedup srovna. **`sub_132C80` tedy uz neni potreba ladit.**
   POZOR na druhou stranu asymetrie: dosbox reference zachycena na blitu
   (`sub_125814`, eip 0x349814) NEobsahuje ciste paletove kroky (blit se
   behem fade nevola), zatimco port dumpuje na kazdy Present(). Pro
   blit-triggerovanou referenci je tedy spravny pixel-only gate.

2. **Bloky** (nova instrumentace): `Smk_TraceDispatchEntry` v
   `orion_part_26.c` loguje `cursor/accum/bits` na vstupu
   `Smk167320_DecodeBlockTypeAndDispatch` (= `loc_1675C0`) pro KAZDY blok
   (env `REORION2_DISPATCH_TRACE`), proti dosbox
   `DUMPREGS cond=eip:0x38B5C0 repeat=always` (ebp=akumulator, esi=kurzor,
   edi=vystup). **Prvni rozdil presne na bloku 7**: originalu tam skoci
   kurzor o -11982 B a edi o -100300 B (= konec snimku, zacina novy), port
   pokracuje (+2). Bloky 1-6 sedely bit-presne
   (442A07C8/00002215/00000008/000003AD/00002EE1/00000148).

3. **Zuzeno dovnitr**: `DUMPREGS` na vstupech vsech 4 handleru
   (0x38A4F0/0x38A830/0x38B040/0x38B190) potvrdil, ze mapovani indexu na
   handlery je SPRAVNE (original tez vola 6x `sub_167190`) a ze se lisi az
   `edx` = `a1` = `dword_18A664`.

**ROOT CAUSE:** `edx` na vstupu `sub_167190` mel v originale hodnoty
**2048, 2048, 512, 128, 59, 5** pro symboly s indexy 63, 63, 61, 59, 58, 4.
Moje `block18A6E0` z vlny 25p byla `{1..64}` - vznikla extrapolaci ZACATKU
asm dat (`dd 1` + raw `db 2,0,0,0 / 3,0,0,0 / ...`). Ale posledni petice
NENI 60..64: asm konci `... 3Ah, 3Bh, 80h, (0,1,0,0), (0,2,0,0), (0,4,0,0),
(0,8,0,0)` = **58, 59, 128, 256, 512, 1024, 2048** - standardni Smacker
`block_runs` tabulka. Opraveno v `orion_data.c`.

`dword_18A664` je DELKA BEHU bloku (kolik bloku handler vyplni, nez je
snimek hotovy). Orez na 64 misto az 2048 znamenal, ze snimek, ktery
original dokonci v 6 blocich, se v portu nikdy nedokoncil.

**OVERENO MERENIM (pred -> po):**
- shodnych bloku v rade proti originalu: **6 -> 1687** (= CELY zachyceny
  referencni usek, 1687/1687 bit-presne)
- dispatch bloku za beh: 1230592 -> 1009152 (original 1769 v oknu)
- snimkove porovnani proti 600 referencim: 49 shod pred i po
  (**zadna regrese**; beh utnul timeout, viz nize)

**POUCENI (nova varianta zname tridy):** kdyz IDA nerozpozna datovou
tabulku jako pole a rekonstruuje se z raw `db` bajtu, NESTACI precist
zacatek a extrapolovat - **vzdy dopocitat a precist i KONEC tabulky**.
Prvnich 59 polozek tady vypadalo jako cista rampa 1,2,3..., ale poslednich
5 skace na mocniny dvou. Levne overeni: `DUMPREGS` na vstupu funkce, ktera
vysledek prevzme jako parametr (tady edx u `sub_167190`).

**ZBYVA OTEVRENE (dominantni bug):** od bloku **1688** port donekonecna
opakuje tychz 6 bloku (`A5615831, 000A5615, 00000295, 0001369A, 0000004D,
00000001`) ~168000x - stejny snimek se dekoduje porad dokola misto postupu
na dalsi. Original tenhle snimek v bloku 1688 tez zacina (potvrzeno
`ebp=A5615831`), ale pokracuje dal. Je to TATAZ chyba, na kterou ukazovala
uz vlna 25p ("1.47M dispatch volani, vystupni ukazatel cykluje pres stejnych
4800 adres") - **postup mezi snimky**, ne dekoder bloku. Podezreli:
`sub_167F40` a jeji volajici `sub_14A2D0`/`sub_132869` (spatna interpretace
navratove hodnoty/stavu -> restart misto postupu). Nastroje pripravene:
`REORION2_DISPATCH_TRACE`, `REORION2_HANDLER_TRACE`,
`genCompare/frame_stats.exe`, `genCompare/compare_frames.exe`,
`REORION2_DUMP_INCLUDE_PALETTE`.

## Vlna 25r-3: *** DRUHY ROOT CAUSE *** - funcs_164C45[256] vracely DVE
hodnoty (EAX **a EBX**), IDA namodelovala jen jednu (a orezanou)

Pokracovani binarniho zuzovani z 25r-2. Postup a co se cestou VYVRATILO:

1. **Postup mezi snimky je SPRAVNY** (podezreni z 25r-2 vyvraceno merenim):
   `*(a5+992)` = per-frame ukazatel; port ma 361 ruznych hodnot a jejich
   rozdily sedi s originalem PRESNE (-0x2EC8, +0x11C, -0x98, -0xD0, -0x2D8,
   +0x210, +0x190 ...). "Nekonecna smycka 6 bloku" byly ve skutecnosti
   opakovane STATICKE snimky. Take overeno proti asm (`loc_14B562`), ze
   argumenty `sub_167320` jdou pres ZASOBNIK (push eax/edx/ebx,
   `add esp,0Ch`, cdecl zprava doleva) - volaci misto v portu je spravne.
   POZOR: registry v dosbox DUMPREGS na vstupu `sub_167320` jsou proto jen
   zbytky po pushich: eax=a3, edx=a2, **ebx=a1** (ne Watcom poradi!).

2. **Dekoder bloku je bit-presny**: po oprave `block18A6E0` (25r-2) sedi
   **197814 po sobe jdoucich bloku** (cely dlouhy referencni zaznam,
   dosbox `DUMPREGS cond=eip:0x38B5C0 repeat=always` vs portovni
   `REORION2_DISPATCH_TRACE`) - akumulator, kurzor I pohyb vystupniho
   ukazatele (delty 43552/43552/10368/2592/236 identicke; pred opravou
   256/2336/248/2320/236).

3. **Zbyval tedy jen ZAPIS hodnot.** Snimek portu ukazal video obdelnik na
   SPRAVNEM miste ((80,160)-(559,319) = 480x160, presne dle geometrie
   `18A668=120 dwordu`, `18A670=40 radku bloku`), ale s tečkovanym
   sachovnicovym vzorem a surovymi dwordy typu `0x06918DD0` (= UKAZATEL)
   mezi pixely.

**ROOT CAUSE:** volaci misto v asm (`loc_1666E4`):
```
call funcs_164C45[eax*4] / mov [edi],eax / add edi,stride
                         / mov [edi],ebx        <- DRUHA navratova hodnota
... a jeste jednou pro radky 2 a 3
```
Kazda z 256 generovanych funkci (sub_165760..sub_1664E4) vraci **DVE
32bitove hodnoty - EAX i EBX** = dva radky po 4 pixelech. IDA umi modelovat
jen jednu, takze v dekompilovane `sub_1664F0` vysly EBX radky jako `v22` -
zbytkovy `int *` z move-to-front cache updatu tesne nad tim - a EAX radky
byly orezane (95 z 256 funkci melo navratovy typ `int16_t` (59) nebo
`char` (36), tedy 2 resp. 3 ze 4 pixelu pryc). Odtud oba artefakty najednou.

**Semantika odvozena z asm a overena na indexech 0/1/2/3**
(sub_165760/16576C/165778/165784): volajici nastavi edx na HIWORD(v18)
zdvojeny do obou pulek, takze DL a DH jsou dve barvy bloku, a index tabulky
je bitova maska:
```
eax = pixely 0..3, ebx = pixely 4..7, pixel k = ((index>>k)&1) ? dh : dl
```
= standardni Smacker 2barevny ("mono") blok: BYTE0(v18)+BYTE1(v18) daji 16
bitu pro 16 pixelu jednoho 4x4 bloku, BYTE2/BYTE3(v18) dve barvy.
Nahrazeno jedinou funkci `Smk_ExpandMonoRows()` (orion_part_26.c); vsech
256 generovanych funkci je tim pro tuhle cestu mrtvy kod.

**OVERENO:** tečkovany/sachovnicovy artefakt ZMIZEL, cinematic scena je
poprve souvisly rozpoznatelny obraz (interier kokpitu s pristrojovymi
panely). `distinct_pix` v obdelniku 242 -> 113 (original 111).
Referencni shody 49 beze zmeny (zadna regrese).

**ZBYVA OTEVRENE:**
- **Paleta behem cinematicu.** Port ji meni (nonzero_pal 660, 667, 631,
  614, 671, 436 ...), original ma konstantnich **508**; `compare_frames`
  hlasi 740/768 neshodnych kanalu. Vypada to, ze port na scenu aplikuje
  fade, ktery original nedela (nebo ji zapisuje jinou cestou). **Tohle je
  ted hlavni zbyvajici rozdil** - resit stejnou metodikou (DUMPPAL
  `repeat=always` na obou stranach kolem prechodu).
- **Index pozadi 0 vs 255.** Original na prechodu vysledkuje pozadi index 0
  (ref#49 `distinct_pix=2, top_pix=0`), port ma 255. Vizualne NEPODSTATNE
  (obe paletove polozky jsou cerne - overeno), ale blokuje postup
  `CompareAgainstReferenceIfChanged` pres ref#49, takze automaticke
  porovnavani cinematicu se musi spoustet s `REORION2_COMPARE_SKIP=50`.

## Vlna 25r-4: paletova neshoda byla ZASE artefakt mereni; video uz sedi
snimek po snimku

**Podezreni z 25r-3 ("port aplikuje na cinematic fade, ktery original
nedela") se VYVRATILO** - byla to tretí instance stejne asymetrie mereni:

- dosbox `DUMPFRAME cond=eip:0x349814` vzorkuje **na blitu** (`sub_125814`).
- port `DumpFrameIfRequested`/`CompareAgainstReferenceIfChanged` vzorkovaly
  na **`Present()`**, ktery ma vlastni kadenci.

Zmereny pomer dekod:kopie:blit je pritom na OBOU stranach 1:1:1 (original
`DUMPREGS repeat=always` na 0x38B320/0x36EA40/0x349814 = 784/784/784, 864
blitu; port 1406/1401/1401), takze port cinematic REALNE prehraval cely -
jen Present()-triggerovany dump z nej videl jen ~8 stavu, coz vypadalo jako
"port preskoci 98 % snimku" a "meni paletu, kdyz original ne".

**Oprava mereni:** nova `PortVga_CaptureBlit()` (port_vga.cpp, env
`REORION2_BLIT_DUMP_DIR` + `REORION2_BLIT_DUMP_COUNT`) volana z konce
`sub_125814` - tedy PRESNE tam, kde vzorkuje dosbox. Stejny format i dedup.

**VYSLEDEK (600 snimku, blit vs blit):**
- **paleta: 0 neshod na VSECH 600 snimcich** (drive 740/768) - hodnoty
  nonzero_pal sleduji original presne: 508, 666, 666, 597, 597, 597, 597,
  597, 660, 667.
- `distinct_pix` se lisi presne o **+1** = index pozadi navic.
- snimky 0-48 **MATCH** (vcetne content_bbox a poctu pixelu).
- vizualne: scena je spravna (stejna mimozemska lod, modre svetlo, cerveny
  interier jako original) - viz FINAL_orig300.png / FINAL_port300.png.

**ZBYVA:**
1. **Index pozadi 0 vs 255.** Od blitu 49 ma original pozadi index 0, port
   255. **Vizualne NEPODSTATNE** - overeno, ze `palette[255]` je po celou
   scenu (28 vzorku mezi snimky 49-599) cerna, stejne jako `palette[0]`.
   Nevznika to pres `sub_128C32` - celoobrazovkove mazani se v portu deje
   na blitech 0, 15 a 81, na prechodu (blit 49) ZADNE neni (overeno
   citacem `g_blitCount`). Zdroj pozadi 0 v originalu zatim nenalezen.
2. **18-30 % pixelu uvnitr video obdelniku** (snimek 100: 15760/76800,
   300: 14000/76800, 500: 23184/76800) - projevuje se jako cerne blokove
   artefakty. Podezreni: pocatecni stav obdelniku. Na blitu 49 ma original
   v obdelniku JEDEN nenulovy index, port tam ma 0; typ 2 (`sub_167040`,
   52 % bloku) je "skip" (jen posune ukazatel, obsah nechá), takze rozdilny
   pocatecni obsah se propaguje dal. **Dalsi krok:** zjistit, cim original
   obdelnik pred prvnim snimkem cinematicu vyplni.

## Vlna 25r-5: zuzeni zbyvajiciho rozdilu (pozadi 0 vs 255 + bloky v obdelniku)

Systematicky VYLOUCENO porovnanim s dosboxem (vse zmereno, nic odvozeno):

| co | original | port | zaver |
|---|---|---|---|
| celoobrazovkove `sub_128C32(0,0,639,479,0)` | blity 0, 15, 15, 81, 81, 81, 81 | **totez** | neni to tim |
| `sub_138CEE` (dirty rect) pocet volani na blit 45-52 | 1034/1092/1173/1031/1189/1225/1102/1279 | **totez, bajt po bajtu** | neni to tim |
| nejvetsi dirty obdelnik na blitu 48/49 | (320,240)-(346,264) = kurzor | **totez** | neni to tim |
| `sub_127678` memsety kolem blitu 49 | jen reset dirty tabulky (dest=0x451054, size=1920, val=-1) | - | neni to tim |
| dekod:kopie:blit | 784:784:784 | 1406:1401:1401 (1:1:1) | OK |

Runtime adresy pouzite pri mereni: `sub_128C32`=0x34CC32, `sub_138CEE`=0x35CCEE,
`sub_127678`=0x34B678, `sub_125814`=0x349814, `sub_167320`=0x38B320,
`sub_14AA40`=0x36EA40, `sub_14B4D0`=0x36F4D0.

**ZAVER ZUZOVANI:** mazani i dirty-rect znackovani jsou v portu IDENTICKE s
originalem, takze se musi lisit **obsah ZDROJOVEHO bufferu**, ze ktereho
blit kopiruje. Na blitu 49 ma original v obdelniku uniformni index **10** a
vsude jinde **0**; port ma v obdelniku 0 a jinde 255 (zbytek predchozi
MICRO PROSE sceny). Blity 0-48 pritom sedi PRESNE.

**Nejpravdepodobnejsi pricina (jeste neoverena):** vystupni buffer noveho
videa. Dekoder zapisuje primo do 640x480 plochy na offsetu 102480
(= 160*640+80, origin video obdelniku - overeno: original edi=0x46B094,
framebuf=0x452044). Okoli obdelniku tedy neplni dekoder, ale musi byt
vynulovane pri OTEVRENI noveho videa. V portu se zrejme buffer recykluje
bez vynulovani, takze tam zustane 255 z predchozi sceny - a protoze typ 2
(`sub_167040`, 52 % bloku) je "skip" (obsah nechá), propaguje se rozdilny
pocatecni obsah dal a projevuje se i jako **cerne blokove artefakty uvnitr
obdelniku (18-30 % pixelu: snimek 100 = 15760/76800, 300 = 14000, 500 =
23184)**.

**Dalsi krok:** najit, kde se pri otevreni videa alokuje/nuluje vystupni
buffer (`sub_14BC40` a okoli, pole `*(a6+928)`/`*(a5+992)`), a porovnat s
originalem - stejnou metodikou (DUMPMEM na buffer hned po otevreni videa).

## Vlna 25r-6: *** TRETI ROOT CAUSE OPRAVEN *** - stride obrazovky se cetl
z 1bajtoveho `_UNKNOWN` placeholderu (54 mist)

**Nejdriv oprava vlastni chyby v korelaci:** referencni snimek #49 NENI blit
#49. dosbox `DUMPFRAME` dedupuje, takze index snimku != poradove cislo blitu.
Prechod MICRO PROSE -> cinematic je ve skutecnosti **blit 81**, ne 49. Cele
predchozi hledani "co se deje mezi blitem 48 a 49" bylo proto mimo.

**Novy nastroj:** `DUMPREGS cond=changed:0xADDR:W` v dosbox-x (engine.cpp) -
dumpne registry VCETNE EIP ve chvili, kdy se hodnota v pameti zmeni. Odpovi
tedy na "KTERY kod tuhle pamet prepsal", coz obecny `DUMP cond=changed:`
neumi (nema EIP). Presne tohle celou vec rozseklo.

**Retez, jak se nasel:**
1. `changed:0x452CC9:1` (pixel (5,5) v back bufferu) -> v originale se meni
   jen na blitech 0, 15, 15 a **81**; prechod FF->00 je na blitu 81, zapsany
   z eip 0x35CCEA = `rep movsd` uvnitr `sub_138CE0` (300 KB blokova kopie).
2. Sekvence originalu na blitu 81: `FILL` (ret uvnitr `sub_2518F`) vyplni
   **SEKUNDARNI** buffer nulou -> `sub_124E36` kopiruje sekundarni->primarni
   -> pixel FF->00 -> VESA bank present -> `sub_124DEC` kopiruje zpet.
3. Overeno, ze port dela VSECHNO stejne: vypln na blit 81 miri taky na
   sekundarni buffer (`dword_1BB904 == dword_1BB8FC`), `sub_124E36` i
   `sub_124DEC` se volaji na blitu 81, `sub_138CE0` dostane spravnych 300 KB.
   Presto pixel zustaval 255 -> chyba tedy musela byt v SAMOTNE VYPLNI.

**ROOT CAUSE:** `sub_1475BB` (dwordova vypln, jedine misto, ktere
celoobrazovkove mazani realne provadi) pocita krok mezi radky jako
`*(int *)((char *)&dword_184532 + 2)`. V originale je to
`mov edx, dword ptr qword_184530+4` (asm sub_1475BB), tedy HIDWORD souvisleho
`qword_184530` (= 0x0000028000000000, HIDWORD = **640** = radkovy stride).
IDA ale pojmenovala VNITREK toho qwordu jako samostatny symbol a v portu je
`dword_184532` deklarovany jako **`_UNKNOWN` (1 bajt)** - cetly se tedy
4 bajty CIZI pameti. Dusledek: `a2 += 4*v10 + v9` po prvnim radku odskocilo
mimo buffer, takze se vyplnil jen **JEDEN RADEK 640 px** (presne to sedelo
s drive namerenym "port ma navic presne 640 pixelu"). Stejny vyraz pouzivalo
**54 mist** ve 4 souborech (orion_part_10/19/20/21) - vsechna nahrazena za
`HIDWORD(qword_184530)`. Stejna trida jako drivejsi overlay bugy (vlna 8/12/
17/18/19) a jako `loc_9FFFD`/`unk_1A1370` placeholdery.

**OVERENO MERENIM (pred -> po):**
- pixel (5,5) v back bufferu po blitu 81: **255 (nikdy) -> 0** (jako original)
- neshoda pixelu na 600 snimcich: **245648 (79,96 %) -> 15888 (5,17 %)**
- prvni neshoda: (0,1) v pozadi -> **(116,160) uvnitr video obdelniku**
- snimky 0-48 dal MATCH, paleta dal 0 neshod na vsech 600 snimcich

**ZBYVA:** ~15760 pixelu (5,1 %) uvnitr video obdelniku, konstantne od
snimku 49 dal (nekonverguje -> propaguje se pres "skip" bloky typu 2).
Rozlozeni: dotcenych je 92 ze 160 radku, vzdy v celych ctverkach (block rows
0-16 souvisle, pak 18, 20, 29, 34, 37, 39), a rovnomerne ve vsech 4 radcich
bloku (3940 pixelu na kazdou `(y-160)%4` tridu) - jde tedy o cele CHYBNE
4x4 BLOKY, ne o paritu radku (mono-blok oprava z 25r-3 je v poradku).
Snimek 49 (prvni cinematicu) ma 32768 = presne 2^15 neshod. **Dalsi krok:**
overit prvni snimek cinematicu blok po bloku - podezreni na pocatecni obsah
obdelniku pred prvnim dekodem.

### Vlna 25r-7: zuzeni zbylych 5,1 % (rozpracovano)

Dalsi mereni k tem 15760 zbylym pixelum:

- **Vsech 32768 neshod na snimku 49 je `10 -> 0`** - original ma v obdelniku
  uniformni index 10, port tam ma 0 (tj. hodnotu po vymazani, NEZAPSANO).
- 32768 px = **2048 bloku** ze 4800 v obdelniku. Prvni snimek cinematicu je
  6 solid-fill bloku s behy **2048+2048+512+128+59+5 = 4800**; portu tedy
  chybi presne JEDEN beh 2048 - a to ten PRVNI (dotcene jsou souvisle
  blokove radky 0-16, tj. horni cast obdelniku).
- `sub_167190` overena radek po radku proti asm (loc_1671EA/1671FE/167240/
  16724E vcetne toho, ze `jnz` na loc_16724E testuje flagy ze `sub
  dword_182664, edx` pres dva `mov`y) - **shoduje se**.
- **Pohyb vystupniho ukazatele sedi pres VSECH 197813 bloku** referencniho
  zaznamu (dosbox `edi` delty vs portovni `out` delty) - dekoder tedy
  zapisuje na presne stejna mista jako original.
- Video dekoduje VZDY do PRIMARNIHO bufferu (1406/1406 volani,
  `g_smkFrameOutput - dword_1BB90C == 102480`), zadne prepnuti cile.
- **Prvni snimek cinematicu se dekoduje na TEMZE blitu (81), na kterem
  probiha vymazani obrazovky** (FILL sekundarniho + `sub_124E36` kopie
  sekundarni->primarni). Podezreni tedy je na PORADI: kdyby se cast snimku
  dekodovala pred tou kopii, kopie ji prepise. Nesedi ale, ze by slo o
  presne 2048 bloku (cela kopie je 300 KB) - k dovyresenie.

**Dalsi krok:** zachytit v dosboxu presne poradi na blitu 81 vcetne
`sub_167320` (`DUMPREGS cond=eip:0x38B320`) vedle FILL/COPY, a porovnat s
portem; pripadne pouzit `DUMPREGS cond=changed:` na pixel uvnitr obdelniku
(napr. 0x452044+102480) a zjistit, co ho v portu vraci na 0.

## Vlna 25r-7 (dokonceni): *** VIDEOSEKVENCE OPRAVENA - 600/600 SNIMKU ***

**Ctvrty root cause: `LOBYTE` misto plneho obnoveni EAX ve swap-cache
dispatche `sub_167320`.**

Postup (mereni, ne odvozovani):
1. Vsech 32768 neshod na snimku 49 je `10 -> 0`; 32768 px = 2048 bloku =
   presne PRVNI beh prvniho snimku cinematicu (6 solid-fill behu
   2048+2048+512+128+59+5 = 4800).
2. `DUMPREGS cond=changed:0x46C9A8:1` (pixel uvnitr obdelniku) na originalu:
   po vymazani jde 00 -> 0A z eip 0x38B21B = `sub_167190`. Poradi operaci na
   blitu 81 (FILL/COPY.../DECODE) je v portu IDENTICKE - takze poradi OK.
3. Portovni checkpoint primo v `sub_167190`: behy sedi (2048, 2048, 512, 128,
   59, 5), ale **`fillbyte` prvniho volani je 0 misto 10**.
4. `fillbyte = BYTE1(g_smkBlockTypeSymbol)`. Porovnani symbolu s originalem
   (`DUMPREGS cond=eip:0x38B694` = loc_167694):
   - original: 0x00460AFF, 0x0A0A0AFF, 0x0A0A0AF7, 0x0A0A0AEF, 0x0A0A0AEB,
     0x0A0A0A13
   - port:     0x000000FF, 0x00000AFF, 0x0AFF0AF7, 0x0AF70AEF, ...
   Dolni pulka sedi VSUDE krome prvniho volani (0x00FF vs 0x0AFF).

**ROOT CAUSE:** move-to-front swap v dispatchi. Asm uklada a pak
**cele** obnovuje EAX:
```
mov  dword_182678, eax      ; uloz
mov  eax, [ecx]             ; eax = stara cache[0]
...
mov  eax, dword_182678      ; OBNOV celych 32 bitu
```
Dekompilat mel `LOBYTE(g_smkBlockTypeSymbol) = dword_18A678;` - obnovil jen
DOLNI BAJT, takze hornich 24 bitu zustalo ze stare cache[0] zaparkovane v
eax behem swapu. `sub_167190` bere fill barvu z BYTE1 toho symbolu
(`mov al,ah`), takze KAZDY blok dekodovany pres swap cestu dostal spatnou
barvu. Oprava: `g_smkBlockTypeSymbol = dword_18A678;`.

**OVERENO MERENIM:**
- fillbyte vsech 6 volani: 0/10/10/10/10/10 -> **10/10/10/10/10/10**
- dolni pulky symbolu sedi s originalem 1:1
- **`compare_frames`: 600 snimku porovnano, `600 matched, 0 diverged`** -
  pixelove I paletove PRESNE, vcetne cele cinematicke sceny.
  (pred touto opravou 49 shod / 551 rozdilnych, prumer 13906 chybnych px)
- vizualne overeno na snimku 300: identicke s originalem, bez artefaktu.

**Souhrn celeho tahu (vlny 25r-2 az 25r-7), vse zmereno:**
| oprava | neshoda pixelu (600 snimku) |
|---|---|
| vychozi stav | 49 shod, zbytek ~100 % |
| `block18A6E0` = {1..59,128,256,512,1024,2048} (25r-2) | bloky 6 -> 1687 shodnych |
| `Smk_ExpandMonoRows` misto funcs_164C45 (25r-3) | tečkovany artefakt pryc |
| zachyt na blitu misto Present() (25r-4) | paleta 740/768 -> **0** neshod |
| `HIDWORD(qword_184530)` misto `_UNKNOWN` (25r-6) | 79,96 % -> **5,17 %** |
| plne obnoveni EAX ve swapu (25r-7) | 5,17 % -> **0 %** |

**Zbyva k uklidu:** docasne diagnosticke checkpointy (`167190.*`,
`167320.seed.*`, `128C32.*`, `138CE0.*`, `124DEC/124E36.*`, `125814.*`,
`dispatch.*`, `1642A0.*`) - vsechny jsou env-gated (REORION2_TRACE), takze
neskodi, ale az bude klid, smazat. Dale porad plati kontrolni seznam tichych
nul: `abs16`/`abs32`, `__CFSHL__`/`__CFADD__`/`__OFSUB__`/`__CFSHR__`,
rodina `SWORD1/3/4/5/6`+`SDWORD1/2`+`SBYTE4`.

**Pozn.:** port jeste nezapisuje zpet do `g_smkBlockTypeSymbol` to, co
handlery necha v EAX (`sub_167190` tam necha replikovany fill 0x0A0A0A0A,
proto ma original horni pulku 0x0A0A a port 0x1849). Na vysledek to nema
vliv (spotrebovava se jen dolni pulka, ktera se nastavuje znovu kazdy blok),
ale pro vernost by to slo doplnit.

## Vlna 25r-8: *** PATY ROOT CAUSE *** - port prezentoval vlastni plochu misto
herniho backbufferu (mod 5 = VESA linear)

**Uzivatel hlasil, ze druha animace je cerna, prestoze mereni hlasilo
600/600 shodu.** Mel pravdu: mereni vzorkovalo `dword_1BB90C` (backbuffer,
totez co dosbox `DUMPFRAME framebuf=0x452044`), zatimco uzivatel vidi
SDL plochu portu. Ta byla jina.

**Retez (vse zmereno, obe strany):**
1. Dump SDL plochy (Present-triggered) ukazal, ze cinematic scena probehne
   na obrazovce za ~9 snimku a je vetsinou prazdna/cerna, prestoze backbuffer
   ma 600 spravnych snimku.
2. `sub_138CEE` (dirty rect) behem cinematicu: video obdelnik
   (80,160)-(560,320) se oznaci **jen jednou** (blit 82), pak uz jen kurzor
   (320,240)-(346,264). **A originál dela PRESNE TOTEZ** (2 volani/blit,
   stejne obdelniky, `sub_167F40` 41 volani na blitu 82 a 1 na dalsich) -
   takze to neni chyba portu.
3. Plna kopie do VGA okna (`sub_138CE0 dst=0xA0000`) je v originale jen na
   4 blitech (0, 1, 15, 81) - take neprezentuje video.
4. **`DUMPMEM`: `dword_1BB904 == dword_1BB90C == 0x452044`**, a
   `dword_1BB910[0] == 0x000A0000`. Tedy: adresa, kterou dosbox vzorkuje, JE
   herni backbuffer, a `dword_1BB910[0]` je stare bankovane VGA okno, ktere
   se v modu 5 NEZOBRAZUJE.

**ROOT CAUSE:** v modu 5 (VESA linear) je zobrazovanou plochou primo herni
buffer `dword_1BB90C` - hra do nej kresli a CRT ho proste snima, zadny
"present" neexistuje a dirty-span blit `sub_125814` do `0xA0000` je v tomhle
rezimu mrtva cesta. Port ale zobrazuje SVOU vlastni `g_framebuffer`, do ktere
se pres `sub_125814` dostanou jen dirty spany - a ty behem videa pokryvaji
jen kurzor. Log scény fungovaly jen proto, ze si znackuji 1100+ obdelniku na
blit.

**Oprava:** `PortVga_BlitBackBuffer()` (port_vga.cpp, deklarace v
decomp_compat.h) - na konci `sub_125814` zrcadli cely backbuffer do
`g_framebuffer` a zavola `Port::Vga::Present()`. Druha cast je nutna, protoze
hra behem videa vubec neprochazi svymi vsync helpery
(`sub_132B27`/`sub_132B41`), ktere jsou jinak jedine misto, odkud se v portu
Present() vola - proto obrazovka zamrzla na poslednim snimku loga.

**OVERENO MERENIM:**
- snimku SDL plochy za beh: **110 -> 400**
- SDL plocha behem cinematicu: `nonzero_pal=508 distinct_pix=111 top_pix=0
  (75,0 %)` = **presne referencni hodnoty** (drive prazdno/cerno)
- `compare_frames` proti 600 referencim: **600 matched, 0 diverged**
  (zadna regrese oproti 25r-7)
- vizualne: cista, detailni scena (vesmirna stanice s lodemi), bez artefaktu

**POUCENI (uz poctvrte v tomhle tahu):** "port se shoduje s dosboxem" plati
jen pro to, co obe strany vzorkuji. dosbox `DUMPFRAME framebuf=` cte
konkretni ADRESU - je nutne vedet, CO na te adrese je (tady herni backbuffer,
ne zobrazovana plocha portu). Pri hlaseni uzivatele "vidim neco jineho" vzdy
nejdriv overit, ze merena plocha == zobrazovana plocha.

## Vlna 26: zvuk - nahradni AIL DIG_DRIVER + 4 ztracene navratove hodnoty

**Zadani:** podstrcit originalu falesny sound config, overit shodu zvukoveho
bufferu s dosboxem a chovani port_sound (hlasitost atd.).

**Proc zvuk vubec nebezel:** `sub_140979` (AIL_install_DIG_INI) mela od vlny
12 zakomentovanou skutecnou instalaci (`sub_157570` cte DIG.INI a real-mode
vola SB16.DIG - to v portu nejde). Vracela tedy nic, `dword_184388` zustalo 0
a cely blok v `sub_111F3E` (nacteni SOUND.LBX + alokace 16 sample handlu) se
TISE preskocil.

**1) Nahradni DIG_DRIVER (`PortSound_CreateDigDriver`, port_sound.cpp).**
Rozlozeni i hodnoty OPSANE Z ORIGINALU pres dosbox-x DUMPMEM
(`dword_184388` -> 0x003EC8D8, pak dump struktury):
`+16 = 2048` (DMA buffer), `+20 = 22050` (frekvence), `+68/72/76 =
2048/1024/8192`, `+92` = pole samplu, `+96 = 17`.
Sample ma 2196 B (= `AilSample`), `+4` je stav (1 = volny, hleda ho
`sub_157610`) a **`+0` je zpetny ukazatel na DIG_DRIVER** - bez nej padal
`sub_156400` na cteni z null+0x18 hned pri prvni alokaci. Overeno dumpem
originalniho samplu (0x004F2038: +0 = 0x003EC8D8, +4 = 2, +60 = 11025).
Handly `dword_1B0670[1..16]` v originale = 0x4F2038, 0x4F28CC, ... s krokem
0x894 = 2196 - presne sedi.

**2) Ctyri ztracene navratove hodnoty** (vsechny overene proti
Debug/diss/Orion2.exe.asm, stejna trida jako vlna 22c):
| funkce | asm | dusledek chyby |
|---|---|---|
| `sub_140979` | `call / mov dword_17C388, eax / cmp ..., 0 / jz` | zvuk se nikdy nezapnul |
| `sub_1400A9` | `call / mov [ebp+var_4], eax / cmp ..., -1` | test "Could not register timer" byl nahodny |
| `sub_140BB1` | `call / mov dword_1A8670[edx], eax` | sample handly se neukladaly |
| `sub_140E69` | `call / test eax, eax / jnz` | `if (!v1)` v `sub_1122C0` cetlo neinicializovanou promennou -> sample se nikdy nerozehral |

**3) Konfiguraky (na zadost uzivatele):** `aWdigIni` je slitina dvou retezcu -
`[0]` je fopen MOD `'w'` (ZAPIS) a `&[1]` je jmeno souboru, takze riziko
prepsani originalu bylo realne. Prejmenovano na `"wDIG_fake.INI"` /
`"rMDI_fake.INI"` (orion_data.c + orion_common.h), originalni DIG.INI a
MDI.INI v adresari hry se tim nemuzou dotknout.

**OVERENO MERENIM:** init zvuku poprve DOBEHNE bez padu -
`AIL.install_DIG_INI.driver` nenulovy, `111F3E.before_slots_memset`
dosazeno (= smycka alokace 16 handlu prosla), zadny novy SEH.

**ZBYVA:**
- `sub_1122C0` (prehraj zvukovy EFEKT) se behem intra **vubec nevola** -
  intro nema efekty, jeho zvuk je AUDIO STOPA SMK VIDEA: ring buffer v
  `sub_14B620` (+ `sub_1676F0` = dekomprese audia, ktera se dosud nevolala)
  a per-snimkove casovani v `sub_14B4D0` (`a5+1124/1128/1132`, audio track
  `a1[264]`). **Dalsi krok: overit obsah toho ring bufferu proti dosboxu**
  (DUMPMEM na `*(a5+...)` po nekolika snimcich) a teprve pak ho poslat do
  `Port::Sound::PlaySample`.
- `sub_1578A0` (AIL_start_sample) ma uz pripravenou diagnostiku; skutecne
  prehrani deleguje na real-mode driver pres `sub_13FBC8(driver, 1025, ...)`
  - tam bude odbocka do SDL. Hlasitost/panorama nastavuji `sub_14129D` /
  `sub_141313` z `byte_1843A4` / `byte_1843A5` (to je ta cast zadani o
  hlasitosti).

### Vlna 26 pokracovani: audio stopa videa - retez otevren, zatim nehraje

**Zjisteno, kde zvuk intra vlastne je:** NEJSOU to efekty (`sub_1122C0` se
behem intra nevola vubec), ale AUDIO STOPA SMK VIDEA. Brana je
`result[264]` v `sub_14B620` (index audio stopy, -1 = zadna) - v portu byla
**-1**, proto se `sub_1676F0` (dekomprese audia) nikdy nevolala.

**Proc byla -1:** `a1[264]` se nastavi az kdyz uspeje `dword_189164(...)`
(otevreni audio streamu). Tu vtable instaluje `sub_149890`, ale jen pokud je
`dword_18A5AC` jeste NULL - a nastavuje ho i `sub_15C730`. Zmereno: blok se
**provede** (`149890.install_block 1`) a `dword_189164` je nenulovy, takze
tohle v poradku je; otevreni streamu se poprve realne zavola.

**Retez pak pada v kodu, ktery nikdy nebezel** (stejny vzor jako u videa -
nova cesta, kaskada latentnich bugu). Postupne odkryto a posunuto:
1. `sub_156400` - cteni z null+0x18: **opraveno** doplnenim zpetneho
   ukazatele na driver do samplu (`+0`), viz vyse.
2. `sub_13259F` (zarovnavajici alokator) pri `a1 == -1` nechal `v2 = 0` a
   presto zapsal zarovnavaci bajt na adresu `16 + 0 - 1` = **15**. Pod
   DOS4GW neskodny skrabanec do nulte stranky, tady av_write na 0x0000000F.
   **Opraveno**: kdyz alokace neprobehla, vraci 0 (= "nelze alokovat", coz
   volajici uz osetruje).
3. **Aktualni frontier:** `sub_157780+0x5b` (av_write), cesta
   `sub_14BC40 -> sub_14C4C0 -> sub_149C80 -> sub_149E40 -> sub_140FF1 ->
   sub_157780`. Jeste neanalyzovano.

**Dalsi kroky:** dobrat tuhle kaskadu (stejnou metodikou - stack z SEH
handleru + porovnani promennych s dosboxem), pak teprve overit obsah
audio ring bufferu proti dosboxu a poslat ho do `Port::Sound::PlaySample`.
Pozn.: `sub_157690` ma zatim obranny early-out na neplatny handle - zatim
se ANI JEDNOU netrigrnul, takze nic nemaskuje.

### Vlna 26 pokracovani 2: *** ZVUK POPRVE HRAJE *** (zatim kratky sum)

**Kaskada dobrana, audio stopa videa je aktivni a PCM tece do SDL.**

Dalsi nalezene a opravene bugy v teto vetvi:
- `sub_149C80` (otevreni audio streamu): `sub_140BB1(dword_189140); a2[14] =
  v12;` - **ztracena navratova hodnota**, `v12` neinicializovana. Overeno v
  asm (`call sub_140BB1 / add esp,4 / mov [esi+38h], eax`, 0x38 = 56 =
  a2[14] = HANDLE SAMPLU audio stopy). Bez toho sla do
  `sub_140FF1`/`sub_157780` smet a padalo to na zapisu do `handle+52`.
- `sub_149E40`: `sub_140DFC(*(int **)(a1 + 56))` - 32bitove ulozeny ukazatel
  cteny jako 8bajtovy `int**` (x64 trida z vlny 25); o par radek niz se
  stejne pole cte spravne jako `*(_DWORD *)`. Opraveno.

**Napojeni na SDL (port_sound.cpp):**
- `PortSound_SetStreamFormat(milesSampleType, rateHz)` - volano ze
  `sub_149E40`, kde `v3` je presne ta hodnota, kterou dostava
  AIL_set_sample_type (bit0 = 16bit z a1+72, bit1 = stereo z a1+76).
- `PortSound_FeedStream(pcm, bytes)` - volano ze `sub_14B620` z mista, kde
  hra zapisuje do sveho audio ring bufferu. Zdroj je souvisly (`v6 + 1`,
  delka `v30`), takze se neresi zalamovani kruhoveho bufferu.
- `Port::Sound::FeedStream` otevre SDL zarizeni podle formatu (U8/S16,
  mono/stereo, dana frekvence) a pri zmene formatu ho znovu otevre.

**ZMERENO:** `14B620.audioTrack_264` = **0** (drive -1), format hlasen jako
**typ 2 = 8bit stereo, 11025 Hz**, zarizeni otevreno, jedna davka
**23748 B** PCM. Uzivatel potvrdil, ze je slyset zvuk (kratky sum).

**ZBYVA:**
1. **Davka je jen JEDNA** - proto je zvuk kratky. `sub_14B620` se vola
   1406x (na snimek), ale audio blok (`if (!v8)`) probehne jen jednou, tj.
   dalsi snimky uz zadna audio data nemaji. Zjistit, proc se per-snimkove
   audio nenacita (podezreni na cteni chunku ve SMK readeru, `v6 =
   *((_DWORD*)v5 + 241)`).
2. **Je to sum, ne zvuk** - overit format a offset dat PROTI DOSBOXU
   (uzivatelovo puvodni zadani: "zkontrolovat, zda sound buffer ma stejna
   data jako v dosboxu"). Konkretne: dumpnout obsah audio ring bufferu v
   originale (DUMPMEM) a bajt po bajtu porovnat s tim, co portu prijde do
   `PortSound_FeedStream`. Teprve pak ladit U8/S16 a mono/stereo.
3. Hlasitost/panorama (`sub_14129D`/`sub_141313`, `byte_1843A4/A5`) zatim
   nejsou napojene - PCM jde do SDL bez skalovani.

### Vlna 26 pokracovani 3: proc je zvuk kratky - hra ceka na odbaveni bufferu

**Mereni vysvetlilo i "obcas hraje, obcas ne":**
- Audio stopu ma az CINEMATIC video (otevira se kolem blitu 81/82), ne logo.
- V behu, kde se audio stopa otevrela (`audioTrack_264` = 0), mel trace jen
  **421 radku za 100 s** a konci na `125814.blit 82` / `14DF7.loop3.enter` -
  tedy hra se prakticky ZASTAVILA hned po otevreni audia.
- V behach, kde se neotevrela, mel trace **29229 radku** - video bezelo
  naplno.

**Zaver:** po otevreni audio stopy hra taktuje prehravani PODLE AUDIA -
`sub_14B5B0` se rozhoduje podle stavu audio bufferu (`dword_1C3C38` =
`sub_149ED0`, a `a1[264]`/`a1[265]` v `sub_14B620`). Port ale zvuk jen
"vysype" do SDL a nikdy nehlasi, ze se prehral, takze hra ceka a video
stoji. Odtud jak kratky sum (jedna davka), tak zastaveni.

**Dalsi krok (konkretni):** doplnit ucetnictvi prehraneho audia -
`sub_149ED0`/`dword_1C3C38` musi vracet, kolik uz je odbaveno (napr. z
`SDL_GetAudioStreamQueued`), aby `sub_14B5B0` pustil dalsi snimek a dalsi
audio davku. Teprve pak ma smysl ladit format (U8/S16, mono/stereo) proti
dosbox dumpu ring bufferu.

### Vlna 26 pokracovani 4: audio deterministicke, ale SMK reader dodava jen
prvni chunk -> audio videa docasne za prepinacem

**Odstranen nedeterminismus** ("audio jednou naskoci, jindy ne"):
`sub_149C80` volalo `sub_140A57(aSb16Dig, 0); dword_189140 = v3;` - **tri
ztracene navratove hodnoty** (v3/v4/v5, pro SB16/SBPRO/SBLASTER .DIG). Asm po
kazdem volani dela `add esp,8 / mov dword_181140, eax`. Bez toho dostaval
`dword_189140` SMETI ZE ZASOBNIKU: kdyz vyslo != 0 a != -1, audio se
otevrelo, kdyz 0, ne. `sub_140A57` (AIL_install_DIG_driver_file) navic v
portu nemuze nacist real-mode .DIG - vraci proto TENTYZ nahradni DIG_DRIVER
jako `sub_140979` (PortSound_CreateDigDriver si ho cachuje).

**Opraven vyber komprimovane vetve.** `sub_14B620` testovalo
`v29[v31 + 18] >= 0`, ale `v29` je `_DWORD *` (**unsigned**), takze to
platilo vzdy a port bral syrovou vetev. Asm dela
`test byte ptr [eax+4Bh], 80h` = bit 7 bajtu na +75 = horni bajt dwordu na
+72, tedy ZNAMENKOVY test. Overeno dumpem: original i port maji na +72
shodne **0xD0002B11** (dolni slovo 0x2B11 = 11025 Hz, horni bajt 0xD0 =
priznaky vcetne komprese). Opraveno na `(int)v29[v31 + 18] >= 0`; od te doby
se konecne vola `sub_1676F0` (dekomprese) - `komprese=1, dekomprese=1`
stabilne pres vsechny behy.

**Odesilani do SDL presunuto** ze zdrojoveho chunku na ring buffer az PO
zapisu (funguje pro obe vetve a je to hotove PCM): posila se usek
`[v19, v19+v30)` se zalomenim na `v21`/`*v10`. Drive se posilal zdroj
`v6 + 1`, coz obsahovalo jeste 4bajtovou delku (`C4 5C 00 00` = 23748).

**ZBYVA (proc to po chvili prestane):** SMK reader dodava audio chunk jen pro
PRVNI snimek - `v6 = *((_DWORD*)v5 + 241)` je dal prazdny, takze
`result[265]` (nastavuje se v sub_14B620 pri `result[256]`) zustane 0 a
`sub_14B5B0` napored vraci "preskoc snimek" -> video se zastavi na blitu 82
(uzivatel: cerna obrazovka misto druhe animace).

**Aby to uzivatele nebrzdilo, je audio VIDEA docasne za prepinacem:**
`sub_149C80` se bez `REORION2_VIDEO_AUDIO=1` hned vraci 0, tj. video bezi
jako pred vlnou 26. Zvukove EFEKTY tim dotcene nejsou (jdou pres
`dword_184388`, ne `dword_189140`).

**OVERENO:**
- vychozi (bez audia): max blit 84, 39104 radku trace = zdrave chovani
- `REORION2_VIDEO_AUDIO=1`: audio se otevre, 1 davka, stop na blitu 82
- **regrese videa zadna: `compare_frames` 600 snimku, 600 matched, 0 diverged**
  (i po zasahu do sdileneho `sub_13259F`)

### Vlna 26 pokracovani 5: zaseknuti presne lokalizovano (sub_14DF7 loop3)

Postupne VYLOUCENO merenim (ne odhadem):
- `sub_1676F0` (dekomprese audia) NEVISI: 1 vstup, **1 navrat**.
- `sub_14B5B0` (rozhodnuti "dekoduj vs cekej na audio") rika **DEKODUJ**:
  `ready_265 = 1`, `gate_256 = 7692`, `starved_68 = 0`,
  **`played = 0` < `threshold = 12721`**. Zavola se ale jen JEDNOU.
- Trace konci na `14DF7.loop3.enter 1407` -> hra se toci ve VNEJSI SMYCCE
  prehravani videa (`sub_14DF7`, loop3), ne v dekoderu ani v pacingu.

**Dalsi krok:** rozebrat `sub_14DF7` loop3 - na co ceka (podezreni na
podminku navazanou na audio buffer / `dword_189154` / stav samplu), a
porovnat tu podminku s originalem stejnou metodikou (DUMPREGS na vstupu
smycky + portovni checkpointy, pripadne `DUMPREGS cond=changed:` na
promennou, na ktere se ceka).

**Stav pro uzivatele:** audio videa zustava za `REORION2_VIDEO_AUDIO=1`
(vychozi = video bezi jako driv, ale je TICHO). Zapnute audio = slysitelna
prvni davka, ale video se zastavi. Je to tedy zatim volba mezi "hrajici
video bez zvuku" a "kousek zvuku a cerna obrazovka" - proto je vychozi to
prvni. Zvukove EFEKTY (mimo video) prepinac neovlivnuje.

### Vlna 26 pokracovani 6: zaseknuti odstraneno, audio se otevira spolehlive

**Nalezena pricina zaseknuti** (merenim, ne odhadem): `sub_132869` ma
`do { a1 = sub_14A090(...); } while (a1);` a namereno bylo **~2,5 miliardy
iteraci** (124904 zaznamu po 20000). `sub_14A090` obsluhuje dal, dokud je
prehrana pozice pod prahem:
`dword_1C3C38(track) >= *(track+32) >> 7` -> konec. Pozice ale byla porad 0.

Pozici pocita `sub_149ED0` z casoveho razitka `a1[27]` (= track+108). To se
nastavuje v `sub_149F20` na radku
`if ( !v8 || (sub_1413FF(...), v9 == 2) ) *(i+108) = v13;` - a **`v9` byla
neinicializovana**: DALSI ztracena navratova hodnota. Asm:
`call sub_1413FF / add esp,4 / cmp eax, 2 / jnz`. `sub_1413FF`
(AIL_sample_status) byla `void`, skutecnou praci dela `sub_157740`.
Opraveno; POZOR: volani musi zustat v DRUHEM operandu OR (zkracene
vyhodnoceni), jinak se vola i kdyz nema.

**VYSLEDEK (mereno):**
- nedeterminismus otevirani audia je PRYC - `audioTrack_264 = 0` stabilne
- nekonecna smycka je PRYC - trace z **429 radku vyrostl na ~175000**, hra
  bezi dal misto zamrznuti
- **regrese videa zadna: `compare_frames` 600/600 matched**

**ZBYVA:** s zapnutym audiem se video porad nedostane za blit 82 (byt uz
nezamrzne) a prehraje se jen JEDNA audio davka. Dalsi krok: proc SMK reader
nedodava audio chunky pro dalsi snimky (`v6 = *((_DWORD*)v5 + 241)`, plni se
v `sub_14C4C0`-cesty podle bitu 1 typoveho bajtu snimku `frameTypes[idx]` -
zkontrolovat `v29+956` a `v29+880` proti dosboxu).

### Vlna 26 pokracovani 7: retez predani driveru dohledan, stav zvuku

**Overeno merenim, ze cesta k audio stope videa je kompletni a stabilni:**
- typove bajty snimku jsou SPRAVNE: snimek 0 ma typ 3 (paleta+audio), dalsi
  typ 2 (audio stopa 0), index snimku roste 0,1,2,... -> audio chunky se
  prideluji kazdemu snimku, chyba tedy NENI ve SMK readeru (puvodni
  podezreni vyvraceno).
- `sub_149890(0x3C, dword_184388)` predava DIG_DRIVER do `dword_189140`,
  odkud ho `sub_149C80` bere pro otevreni audio stopy. Zmereno: `a2` je
  nenulovy driver, `dword_18913C` (bezici video) = 0, takze predani probehne.
- `dword_189144` (druha brana v sub_149C80) je v celem dekompilatu jen
  definovana na 0 a NIKDE se nenastavuje -> instalacni blok uvnitr
  `sub_149C80` se nikdy nespousti; audio se otevira dik `dword_189140`
  predanemu vyse. (Proto tam ty tri ztracene navratove hodnoty ve vysledku
  nic nemenily - byly ale stejne spravne opravit.)

**STAV ZVUKU (2 po sobe jdouci behy, stabilne):** `audioTrack_264 = 0`,
dekomprese probehne, prehraje se **1 audio davka**, video dojde na blit 82 a
dal uz nepokracuje (ale NEZAMRZA - trace ~150000 radku).

**ZBYVA:** proc se audio blok v `sub_14B620` provede jen jednou, kdyz chunky
jsou k dispozici pro kazdy snimek. Podminka je `v7 != 0`, kde
`v7 = (v5[75] >= 0) ? (*v6 - 4) : v6[1]` a `v5[75]` je horni bajt priznaku
(0xD0 -> zaporny -> bere se `v6[1]` = rozbalena delka). Dalsi krok: zmerit
`v6` a `v7` pri kazdem volani `sub_14B620` a porovnat s dosboxem (staci
DUMPREGS na vstupu smycky uvnitr sub_14B620).

### Vlna 26 pokracovani 8: nedeterminismus odstranen, retez do driveru
dokoncen, ale prehravani je stale prilis pomale

**Odstranen ZBYTKOVY nedeterminismus** (audio se ted otevre VZDY):
`sub_149C80` melo `sub_14197D(...); v8 += 3; ... a2[25] = v8;` - **dalsi
ztracena navratova hodnota** (AIL_minimum_sample_buffer_size). Asm:
`call sub_14197D / add eax, 3 / and al, 0FCh / mov [esi+64h], eax`
(0x64 = a2[25]). Bez toho slo do `a2[25]` smeti ze zasobniku, z nej se
pocitala velikost alokace `sub_13259F(2 * a2[15])`, ta pri velkem smeti
selhala a audio se neotevrelo.

**Dalsi dva x64 pointer-width bugy** v audio pumpe `sub_149F20` (stejna
trida jako vlna 25): `*(char **)i`, `*(char **)(i + 8)`,
`*(char **)(i + 4*v3 + 84)` v volani `sub_14A010` a `*(int **)(i + 56)` v
`sub_141B5B` - 32bitove ULOZENE ukazatele ctene jako 8bajtove. Padalo to v
qmemcpy/memmove (cteni z -1) a v `sub_157B00` (zapis na 0x00002000171D9CD8 -
typicky "prilepeny" horni kus).

**`sub_13FBC8` (AIL_call_driver) zastavena.** Je to skok do REALNEHO
real-mode .DIG driveru; nas nahradni DIG_DRIVER nema kodovy obraz, takze
`sub_15541F` cetla z null+8. Prehravani obstarava primo Port::Sound, takze
tady staci tiche "nic se nestalo" (sluzba se loguje pro pripad, ze by bylo
potreba nekterou emulovat - napr. 1025 = start prehravani).

**VYSLEDEK:** zadny pad, `audioTrack_264 = 0` VZDY, audio davky **1 -> 6**,
video se posune z blitu 81/82 na 84.

**ALE porad je to prakticky zaseknute na zacatku videa** (uzivatel: "nic
neslysim, vypada to zaseknute"). Zmereno v `sub_14A090`:
`startStamp_27 = 9256` (nastaveno OK), `played` roste (9834 -> 11355), ale
`threshold` je 11872 a smycka ceka, nez ho pozice dosahne - a spin je
~1,2 miliardy iteraci na 240 s pri pouhych 6 davkach. Prahovou hodnotu
(`*(track+32) >> 7`) drzi nahoru to, ze zastaveny driver buffer nikdy
"nespotrebuje", takze cekani se prodluzuje misto zkracovani.

**Dalsi krok:** dodelat ucetnictvi SPOTREBOVANEHO bufferu - `track+32`
(kolik je zafrontovano) musi po prehrani klesat. Nabizi se navazat ho na
`SDL_GetAudioStreamQueued()` v Port::Sound, nebo emulovat prislusne sluzby
`AIL_call_driver` (`a2` = cislo sluzby, uz se loguje).

**Vychozi stav ZUSTAVA bez audia** (`REORION2_VIDEO_AUDIO=1` ho zapne):
s audiem je video zatim nepouzitelne, bez nej bezi kompletne a spravne.

### Vlna 26 pokracovani 9: nalezen UZAVRENY KRUH v audio pacingu (nedoreseno)

Pridano ucetnictvi spotrebovaneho bufferu: `PortSound_QueuedBytes()`
(`SDL_GetAudioStreamQueued`) + v `sub_157740` (AIL_sample_status) se sample
ve stavu 4 (hraje) prepne na 2 (dohrano), jakmile je fronta SDL prazdna -
to je nahrada za preruseni real-mode driveru, ktere stav prepinalo.
Dusledek: **busy-wait smycka uz se netoci** (spin log prazdny misto
~1,2 miliardy iteraci).

**Ale prehravani se stejne zastavi.** Zmereno v `sub_14A090`:
`played = 16384` (ZAMRZLE), `threshold = 16960`, **`startStamp_27 = 0`**.

**Pricina - uzavreny kruh:**
1. `sub_149ED0` pocita pozici jako `(ted - a1[27]) * rate / 1000`, ale kdyz
   vysledek prekroci `a1[26]`, sama si **vynuluje `a1[27]`** a od te chvile
   vraci konstantu `a1[26] + a1[20]`.
2. `a1[27]` znovu nastavuje jen `sub_149F20` pri DOKONCENI bufferu, a ten
   blok se spusti jen kdyz jsou cekajici bajty (`i+16` > `i+100`).
3. Cekajici bajty prijdou jen z dalsi audio davky, ta ale prijde az kdyz se
   dekoduje dalsi snimek - a ten se dekoduje az kdyz pozice dozene prah.
=> pozice stoji, snimek se nedekoduje, audio nedojde, pozice stoji...

**Dalsi krok:** rozbit ten kruh na spravnem miste - overit proti dosboxu,
jak se v originale chova `a1[26]` (`+104`) a `a1[20]` (`+80`) v prubehu
prehravani (DUMPMEM na tyhle offsety track struktury behem videa) a jestli
se `a1[27]` v originale opravdu nuluje tak, jak to dela dekompilovana
`sub_149ED0` - tam muze byt dalsi decompiler artefakt.

**Stav:** vychozi bez audia = video kompletni a spravne
(**600/600 matched**, overeno i po vsech zmenach teto vlny).
S `REORION2_VIDEO_AUDIO=1` se audio otevre, prehraje 6 davek a zastavi se.

### Vlna 26 pokracovani 10: `sub_149ED0` OVERENA jako verna (podezreni
vyvraceno)

Podezreni z minuleho kola (ze vynulovani `a1[27]` je decompiler artefakt) je
**VYVRACENO**. Asm `sub_149ED0` odpovida dekompilatu radek po radku:
```
cmp dword ptr [esi+6Ch], 0    ; a1[27] (+108)
jnz loc_149EE6
mov eax, [esi+68h]            ; a1[26] (+104)
jmp loc_149EFF
loc_149EE6:
call dword_1825AC / mov ebx,[esi+6Ch] / mov eax,[esi+14h] (rate)
sub ecx,ebx / mul ecx / div 3E8h        ; (ted - stamp) * rate / 1000
loc_149EFF:
cmp eax, [esi+68h] / jbe loc_149F12
mov dword ptr [esi+6Ch], 0    ; ANO, opravdu se nuluje
mov ecx, [esi+68h]
loc_149F12:
mov eax, [esi+50h] / add eax, ecx       ; + a1[20] (+80)
```
Nulovani `a1[27]` je tedy AUTENTICKE chovani originalu, ne chyba prevodu.

**Kde tedy hledat dal:** kruh se musi rozpojit v `sub_149F20`, jehoz
dokoncovaci blok posouva `+80`/`+104`/`+108`. Jeho vstupni branou je
`v1 = *(i+16) > *(i+100)` (cekajici bajty nad spodni hranici). `+16` plni
audio davky (v `sub_14B620` je to `v10[4] = v30 + v18`) a pumpa ho ubira o
`v5`. **Dalsi krok: zmerit v portu `i+16` (cekajici) a `i+100` (hranice)
v case a porovnat s dosboxem** - jestli hranice nesedi (nebo `+16` neroste,
jak ma), je kruh prave tam.

### Vlna 26 pokracovani 11: *** NALEZEN KOREN CELEHO ZASEKNUTI *** -
AIL casovaci callback `sub_156680` v portu nikdy netika

**Merenim proti dosboxu dohledan cely retez.** `DUMPREGS cond=changed:` na
polich track/sample struktury originalu (track = 0x003ECD90, sample =
0x004FA978, ziskano pres ctx+1028 a track+56):

- `track+40` se meni 37x, ZAPISUJE HO SAMA HRA (eip 0x36F7FA = `sub_14B620`,
  `v10[10] += v30`) - kumulativni pocitadlo bajtu, roste 0 -> 0x5CC4 ->
  0x6364 -> ... To NENI index bufferu.
- **`sample+40` se prepina 0 <-> 1** (dvojity buffer), 8x, a zapisuje ho
  **eip 0x003861AF = IDA 0x1621AF = uvnitr `sub_162000`**.
- `sub_162000` vola `sub_156680`, a to je **AIL CASOVACI CALLBACK** -
  registruje se pres `sub_1400A9((int)sub_156680)` (orion_part_23.c:1286).
  Cte z driveru index prave prehravaneho bufferu
  (`v2 = **(int16_t **)(dword_1C95EC + 52)`), a kdyz se zmeni, projde vsechny
  samply se stavem 4 (hraje) a zavola na ne `sub_162000`.

**KOREN PROBLEMU:** retez je
`AIL timer -> sub_156680 -> sub_162000 -> prepne sample+40 -> sub_157B90
(buffer_ready) uz nevraci -1 -> pumpa sub_149F20 odesle dalsi buffer ->
posune se +80/+104/+108 -> pozice v sub_149ED0 roste -> sub_14A090 pusti
dalsi snimek -> prijde dalsi audio davka`.
V portu **ten casovac nikdy netika** (Miles PIT ISR je od vlny 22i zaslepeny,
viz sub_149A20), takze se retez nikdy nerozjede - odtud VSECHNY pozorovane
symptomy: jedna davka, zamrzla pozice, busy-wait, zastavene video.

**Dalsi krok (konkretni navrh):**
1. nahradnimu DIG_DRIVERu dat na `+52` ukazatel na 16bitove slovo, ktere
   port vlastni (= "ktery buffer hardware prave hraje"),
2. to slovo prepinat podle odbaveni SDL fronty (`PortSound_QueuedBytes`),
3. periodicky volat `sub_156680(dword_184388)` - napr. z Present()/vsync
   cesty, kde uz port ma pravidelny tik.
Tim se zachova PUVODNI logika hry (nic se neobchazi), jen se doda tep, ktery
v DOSu obstarval PIT.

**Pozn.:** zmereno taky, ze original ma `track+100` (spodni hranice) = 1280,
port 1024 - drobny rozdil k overeni pri dalsim kole.

### Vlna 26 pokracovani 12: mixerove tabulky opraveny, casovac potvrzen jako
### chybejici, "pad" odhalen jako cizi

**1) OPRAVENO: `off_1602F8` a `funcs_16213C` byly orizle na 2 a 4 polozky.**
Obe se indexuji priznakem `dword_18AD28`, ktery nabyva 0..0x7F, takze
puvodni pole se cetla DALEKO ZA KONCEM (sousedni globaly jako funkcni
ukazatele). V EXE zabiraji souvisly blok 0x1602F8..0x1606F8 = presne
**2x128 dwordu** (hned za nim uz zacina `sub_1606F8`), coz sedi i s
komentarem dekompilatu "1604F8: funcs_16213C". Obe tabulky prevzaty 1:1 z
asm dumpu (60 resp. 72 nenulovych polozek, zbytek jsou v originalu opravdu
nuly); vsech 132 cilovych funkci uz v portu existuje. Latentni pad, ktery by
nastal, jakmile se mixer rozbehne.

**2) POTVRZENO MERENIM: AIL casovaci callback v portu NETIKA.**
Do `sub_156680` pridan citac (`REORION2_TIMER_TRACE=1`): za 90 s behu
**0 volani**. Tim je primo overena hypoteza z minule vlny - retez
`AIL timer -> sub_156680 -> sub_162000 -> prepnuti sample+40` se nikdy
nerozjede, protoze port nema periodicky tik, ktery v DOSu delal PIT.

**3) "Pad" po 11. audio davce NENI audio bug.** SEH hlaseni rozsireno o
`ExceptionInformation[0]` a o dohledani navratovych adres na zasobniku:
`av_execute(info0=8)` (tedy skok do nespustitelne pameti, ne zapis - stary
vypis to hlasil jako "write") a na zasobniku uz jen
`BaseThreadInitThunk`/`RtlUserThreadStart`. Jde o VEDLEJSI VLAKNO. Tentyz
pad je i v behu BEZ audia - v tom samem, ktery da `compare_frames`
**600/600 matched**. Existoval tedy uz driv a s videem ani zvukem nesouvisi.

**4) Prah doplneni bufferu** (`sub_157740`) prepnut z `== 0` na
`< 2048 B` (= pul-buffer driveru, `driver+68`; laditelne
`REORION2_AUDIO_REFILL`). **Zmereno jako neutralni**: pri prazich 0, 512 i
2048 vyjde beh bit po bitu stejne (11 davek, stejne hloubky fronty), takze
trhani zvuku timhle NEZPUSOBENE. Ponechano, protoze to odpovida chovani
originalu.

**Namerena data audio cesty** (`REORION2_AUDIO_TRACE=1`):
format = 8bit **stereo 11025 Hz**, prvni davka 23748 B (same 0x80 = ticho),
pak davky po 1696 B; fronta se drzi na ~22 kB a zdrave se odbavuje
(zadne podteceni po prvni davce). Po 11. davce uz zadna dalsi neprijde =
~2 s zvuku, presne jak ceka bod 2.

**Dalsi krok** je nezmeneny a ted uz mericky podepreny: dodat portu tep,
ktery v DOSu delal PIT. K tomu je potreba domerit v dosboxu strukturu
DIG_DRIVERu originalu (chybi +28, +44, +48, +52, +84, +80) - dnesni pokusy
`DUMPMEM cond=eip:0x0036DF20 addr=0x003EC8D8 size=128` trace nevyprodukovaly
a beh se protahoval, takze to chce jiny spousteci bod.
Odhadovat ty hodnoty NEMA smysl - jsou to presne ty adresy bufferu, o ktere
cely mechanismus stoji.

**Pozn. k dosboxu:** instrumentace `cond=eip:` kontroluje EIP na kazdem
kroku, takze emulace znatelne zpomali a grafika se trha. Na spravnost dumpu
to vliv nema (ctou se presne hodnoty pameti), jen to prodluzuje beh.

### Vlna 26 pokracovani 13: tep pro AIL casovac + tri chyby sirky ukazatele

**Rozlozeni driveru dohledano BEZ dalsiho behu dosboxu.** Misto dlouheho
mereni staci precist, co do tech poli zapisuje sama inicializace driveru v
originalu (`orion_part_23.c` kolem r. 1265):
```
v3[17] = +68 = +16 / +64                 -> 2048
v3[18] = +72 = +16 / (+64 * +60)         -> 1024
v3[19] = +76 = 4 * (+16 / +64)           -> 8192   velikost mix bufferu
v3[20] = +80 = alloc(4 * (+16 / +64))    -> MIX BUFFER
```
a o kus vys (r. 1032) se z dvojice far-pointeru na `+8` linearizuji adresy
obou DMA pul-bufferu do `+44` / `+48`. Sedi to na vsechny drive namerene
hodnoty. **Nahradni driver mel `+80` = 0**, takze prvni `sub_162293` (memset
mix bufferu) by sahl na NULL - latentni pad.

**Doplneno do `PortSound_CreateDigDriver`:** mix buffer (8192 B), dva DMA
pul-buffery po 2048 B, pole ukazatelu na `+8`, `+44`/`+48`, `+84` = 1 a na
`+52` ukazatel na 16bitove slovo "kterou polovinu hraje hardware". To slovo
je JEDINE, co se z originalu opsat neda - v DOSu ho plnil real-mode driver
podle DMA; presne tuhle informaci musi port dodat sam.

**Pridan tep (`PortSound_ServiceTimer`)**, ktery v DOSu delal PIT: prepne
"hranou polovinu" vzdy po dobe odpovidajici jedne polovine bufferu a zavola
`sub_156680`. Visi na `PortVga_BlitBackBuffer` (behem videa jedina
spolehlive periodicka cesta). Cele rozsireni je za `REORION2_AUDIO_TIMER=1`.

**Cestou opraveny TRI skutecne chyby sirky ukazatele** (vsechny stejna
trida, vsechny odhalene z adresy v SEH hlaseni - horni pulka adresy vzdy
prozradila, ktere sousedni pole se prilepilo):
1. `sub_162293`: `*(char **)(a1 + 80)` -> nacetlo 8 B a jako horni pulku
   vzalo `+84` (= 1, "driver bezi") -> adresa `0x1_16CA7280`.
2. `sub_156680`: `**(int16_t **)(dword_1C95EC + 52)` -> horni pulka `+56`,
   do ktereho si tataz funkce o par radku niz uklada index -> az pri DRUHEM
   tiku adresa `0x1_16B000F0`.
3. `sub_162000`: `*(_DWORD **)a1` na `sample+0` -> horni pulka `sample+4` =
   stav samplu (4 = hraje) -> adresa `0x4_16D69A24`.
Take opraveno `SDL_calloc` -> CRT `calloc` pro tyhle buffery (SDL vracel
adresy kolem 4,6 GB, ktere se do 32bitovych poli hry nevejdou) + kontrola
`fits32`.

**Zmereno po opravach:** tep bezi, `sub_156680` dobehne, zavola mixer
`sub_162000` a ten se uz spravne rozskoci pres obnovenou 128polozkovou
tabulku `funcs_16213C` - cimz je oprava tabulek z pokr. 12 potvrzena i v
praxi. Dalsi hranice: **`sub_16177F+0x43`** cte z `0x2E0BF8FC`, tj. sample
jeste nema naplnene ukazatele na data (`sample+8` / `sample+24`), protoze
bookkeeping kolem `sub_141A76`/`sub_157B90` je porad zaslepeny.

**Regrese zadna:**
- video `compare_frames`: **600/600 matched, 0 diverged**
- vychozi audio cesta (bez `REORION2_AUDIO_TIMER`): porad 11 davek
Pozn.: pri prvnim pokusu byl gate omylem PRED inicializaci samplu, cimz se
preskocilo oznaceni volnych samplu a audio se vubec nerozjelo (0 davek);
opraveno, gate obaluje jen buffery.

### Vlna 26 pokracovani 14: mixer se rozjel, nalezena VLASTNI KONVENCE VOLANI

Postup po opravach z pokr. 13: tep bezi, `sub_156680` dobehne, mixer
`sub_162000` se rozskoci pres obnovenou tabulku - a pad se posunul do
`sub_16177F+0x43` (cteni z adresy ~2x vetsi nez adresa bufferu).

**1) Opraveno: `qword_18AD3C` a `dword_18AD44` nelezely za sebou.**
`sub_16177F` dela `a5 += *((_DWORD *)&qword_18AD3C + v5 + 1);` kde v5 je
prenos 0/1 - index 1 = horni pulka qwordu (krok), index 2 = `dword_18AD44`
(krok+1). V originale je to souvisly blok 0x18AD28..0x18AD48; IDA ho
rozdrobila na samostatne promenne a `int64_t` si navic vynuti 8bajtove
zarovnani. Slepeno do `MixStepBlock` (`#pragma pack(4)`) s makry, ktera
zachovavaji puvodni jmena. Nutne, ale pad to samo neodstranilo.

**2) NALEZENA SKUTECNA PRICINA - mixerove rutiny maji vlastni konvenci
volani (registry), IDA je otypovala jako cdecl.** Zmereno checkpointy:
- v `sub_162000` je VSECHNO spravne: driver 0x176E06C0, `+76` = 8192,
  `+80` = mix buffer, `dword_18AD34` = mix buffer,
  `dword_18AD38` = 18AD34 + 8192. Konzistentni.
- v `sub_16177F` ale dorazi `a4` = 0x0140A810 a `dword_18AD38` = 0x172104E0,
  tj. mez o ~370 MB dal, v uplne jine oblasti -> smycka zapisuje mimo
  buffer, dokud nenarazi.

Duvod je primo v kodu, staci porovnat obe strany:
```
int sub_16177F(int result, unsigned int a2, int a3, _DWORD *a4, _BYTE *a5)   // 5 parametru
((void (*)(int, _DWORD *, _BYTE *))funcs_16213C[dword_18AD28])(0, v9, src);  // predava 3
```
Cil (`v9`) a zdroj (`dword_18AD2C`) se trefi do 2. a 3. parametru misto 4. a
5.; `a4`/`a5` jsou zbytky v registrech. Obe IDA-ovske "pravdy" si tedy
primo protireci - jasny priznak toho, ze tyhle rutiny jsou rucne psany asm a
argumenty berou v REGISTRECH (EAX/EBX/ECX/EDI/ESI), ne po zasobniku.

**Dalsi krok:** z asm dumpu odecist skutecnou registrovou konvenci
`funcs_16213C` / `off_1602F8` (staci jedna rutina, budou stejne) a upravit
oba dispatchery tak, aby predavaly vsech 5 hodnot na spravne pozice:
pravdepodobne `(akumulator_L, faze, akumulator_R, cil, zdroj)`. Pozor taky
na to, ze `v9` se ve smycce `sub_162000` nikdy neposouva - vysledny posunuty
ukazatel nejspis chodi zpet v registru (dalsi ztracena navratova hodnota).

**Regrese zadna:** video `compare_frames` **600/600 matched, 0 diverged**,
vychozi audio cesta porad **11 davek**. Emulovany casovac zustava za
`REORION2_AUDIO_TIMER=1`, takze bezne spousteni je nedotcene.

### Vlna 26 pokracovani 15: registrova konvence mixeru OPRAVENA

**Z asm odectena skutecna konvence** (`sub_162000`, loc_16211D):
```
mov esi, dword_182D2C   ; ESI = zdroj          -> a5
lea edx, [ecx+48h]      ; EDX = &sample+0x48
mov eax, 0              ; EAX = akumulator L   -> result
mov ebx, 0              ; EBX = akumulator R   -> a3
mov ecx, 80000000h      ; ECX = faze           -> a2
call ds:funcs_16213C[ebp*4]
pop ebp
mov eax, esi            ; <- ESI se VRACI POSUNUTE
```
EDI (= `dword_182D34`) je cil. Dispatch tedy musi predat PET hodnot
`(0, 0x80000000, 0, cil, zdroj)`, ne tri - jinak se cil a zdroj trefi do
2. a 3. parametru a rutina sahne na zbytky v registrech.
Navic se posunuty zdroj (ESI) i cil (EDI) VRACI; IDA to zahodila, protoze
funkci otypovala jako cdecl vracejici jen EAX. Rutiny je proto ukladaji do
`g_mixSrcAfter` / `g_mixDstAfter` (globaly ZAMERNE az na konci
`orion_data.c`, aby se nerozbila souvislost bloku 0x18AD28..0x18AD48, ktery
`sub_1622BF` bere vcelku).

**Vysledek:** s `REORION2_AUDIO_TIMER=1` uz mixer NEPADA - 11 davek stejne
jako ve vychozi ceste, a jediny SEH je ten drive zdokumentovany pad
VEDLEJSIHO VLAKNA (0x7FFCDFA01800), ktery je i v behu bez audia.

**POUCENI (stalo cely jeden kruh):** inkrementalni MSBuild tady obcas
nerelinkuje a bezi stara binarka. Nejdriv to vypadalo, ze konvencni oprava
rozbila i vychozi cestu (0 davek, pad v `sub_145BB3` s poskozenym
zasobnikem), takze jsem ji revertoval - a po `-t:Rebuild` se ukazalo, ze
zdroj byl v poradku po celou dobu. **Pred vyhodnocenim regrese vzdy
`-t:Rebuild`.**

**Metodicka poznamka (vytka uzivatele, opravnena):** posledni dve vlny jsem
tahl skoro jen ctenim kodu a merenim na strane portu. Prave proto jsem
uveril falesnemu signalu ze zastaraleho buildu. Dalsi krok patri zpatky k
porovnani s dosboxem: mixer uz bezi, takze se da primo porovnat OBSAH
namixovaneho bufferu (driver+80, 8192 B) a stav samplu mezi originalem a
portem ve stejnem bode - `DUMPMEM cond=eip:` na navratu z `sub_162000`
(IDA 0x162000 -> runtime 0x386000) proti stejnym hodnotam v portu.

### Vlna 26 pokracovani 16: struktura SAMPLE pojmenovana, nalezen BOD ZLOMU

**Zdroj jmen (jen jmena a semantika, zadny kod):** verejna hlavicka Miles
Sound System (MSS.H, `struct SAMPLE`) -
https://github.com/domz1/SourceFlyFF (Program/_Common/mss.h). Vnitrek
`DIG_DRIVER` verejny NENI (to je kod ovladace slinkovany do hry), takze na
nej dal plati jen dosbox. Potvrzeno, ze stavove konstanty sedi presne:
`SMP_FREE 1 / SMP_DONE 2 / SMP_PLAYING 4 / SMP_STOPPED 8`.

`AilSample` v `orion_common.h` ma ted prvnich 48 bajtu pojmenovanych misto
`reserved_8[2116]`:
```
+0  driver      zpetny ukazatel na DIG_DRIVER (32bit)
+4  status      SMP_*
+8  buf_data[2] +12
+16 buf_len[2]  +20
+24 buf_pos[2]  +28
+32 buf_done[2] +36
+40 head        posouva MIXER (sub_162000), kdyz buffer dohraje
+44 tail        posouva AIL_sample_buffer_ready (sub_157B90)
+48 n_buffers   MSS default 2
```
Tim se zpetne potvrzuje vsechno, co bylo drive namerene "naslepo": `+40` a
`+44` jsou head/tail kruhu, `sub_157B90` je `AIL_sample_buffer_ready`.

**BOD ZLOMU (primo porovnano s dosboxem):**
- ORIGINAL: head (`sample+40` = 0x004FA9A0) se prepina 0<->1 **8x**
  (`DUMPREGS cond=changed:0x004FA9A0:4`, zapisuje eip 0x003861AF uvnitr
  `sub_162000`).
- PORT se zapnutym casovacem: **0 prepnuti**.

Head se v `sub_162000` posouva az ZA vetvi
`if ( v11 < dword_18AD30 ) break;`, tedy jen kdyz mixer zdrojovy buffer
DOJEL az na konec. V portu se tam nikdy nedojde -> zdrojovy ukazatel se
neposouva dost (nebo vubec). Podezreni: krok `qword_18AD3C` zustava 0,
protoze blok, ktery ho pocita, je za podminkou
`if ( (unsigned int)v6 > dword_1C9558 )`.

**Dalsi krok (uz konkretne mericky):** porovnat `qword_18AD3C` /
`dword_18AD44` a `dword_1C9558` mezi originalem a portem ve stejnem bode -
`DUMPMEM cond=eip:` na 0x386000 (= IDA 0x162000 + 0x224000) proti stejnym
hodnotam v portu. Kdyz krok sedi, jit dal na obsah namixovaneho bufferu
(driver+80, 8192 B).

**Regrese zadna:** vychozi cesta porad 11 davek. (Build POZOR: vzdy
`-t:Rebuild`, viz pokr. 15.)

### Vlna 26 pokracovani 17: PROC DOSBOX MERENI NIC NEVRACELA - instrumentace
### se vubec nespousti

**Tohle je duvod, proc jsem se posledni vlny motal v kruhu na strane portu.**

Zjisteni: `enginestep()` - a v nem `ctl_init_once()`, tedy nacteni celeho
`DOSBOX_CTL_FILE` - se vola **JEN z `CPU_Core_Normal_Run`**
(`src/cpu/core_normal.cpp:175`). V zadnem jinem jadru (dynrec, dyn_x86,
simple, full) neni:
```
$ grep -rln enginestep src/
src/cpu/core_normal.cpp
src/engine/engine.cpp
src/engine/engine.h
```
`dosbox_intro.conf` ma ale `core=auto` (+ `cycles=auto`), coz pro 32bitovou
chranenou hru vybere dynamicke jadro -> `enginestep()` se nezavola ani
jednou -> config se nenacte, zadny DUMP nefunguje a zadny STOP se
nevyhodnoti.

**DUKAZ (ne domnenka):** beh s `STOP cond=cycle_ge:20000000` bezel dal az do
timeoutu a dosboxuv vlastni log v te dobe ukazoval cyklus **33 657 191**,
tedy davno za prahem. Zaroven v celem logu neni ani jedna `[ctl]` radka
(engine.cpp je tiskne pri nacteni watchu) a nevznikl zadny trace soubor.

**Pozor:** prepnuti `core=normal` v konfiguraci samo o sobe NESTACILO -
chovani zustalo stejne. Takze bud dosbox-x pro chraneny rezim stejne
prepne jadro, nebo se uplatnuje jina konfigurace. **Tohle je ted hlavni
blokator** - dokud se nerozbehne, nema smysl delat zadne dalsi porovnavani
s originalem.

**Dalsi krok:** overit, ktere jadro se opravdu pouziva (dosbox-x umi vypsat
`core` za behu / lze pridat log do `CPU_Core_Normal_Run`), a bud vynutit
normal core i pro chraneny rezim, nebo - lepe - pridat volani `enginestep()`
i do ostatnich jader (dynrec/dyn_x86/simple), aby instrumentace fungovala
nezavisle na volbe jadra.

**Stav portu (nezmeneny, vse za prepinacem):**
- vychozi cesta: 11 davek, video 600/600
- s `REORION2_AUDIO_TIMER=1`: mixer bezi SPRAVNE (za jedno volani spotrebuje
  1024 B zdroje a naplni celych 8192 B cile, zbytek klesa 7168 -> 6144 ->
  5120), ale probehne jen 2-3x, takze head se neprepne ani jednou
  (original: 8x).
- Zjisteno pri tom, ze stara nahrada v `sub_157740` (falesne "dohrano" podle
  SDL fronty) si se skutecnym mixerem PRIMO PROTIRECI: `sub_156680` mixuje
  jen samply ve stavu 4 (SMP_PLAYING), takze predcasne prepnuti na 2
  (SMP_DONE) mixer umlci. Nahrada je proto nove aktivni jen kdyz casovac
  NEbezi. Samo o sobe to ale nestacilo (davky pak klesly na 0), takze
  spravne poradi je: nejdriv zprovoznit dosbox instrumentaci, zmerit, jak
  casto a s jakymi hodnotami bezi `sub_156680` v ORIGINALE, a teprve pak
  ladit tep v portu.

### Vlna 26 pokracovani 18: dosbox instrumentace ZPROVOZNENA + referencni
### hodnoty casovace z originalu

**PRICINA vsech prazdnych mereni: spousten byl STARY DEBUG BUILD dosboxu.**
```
bin/x64/Debug/dosbox-x.exe    28. unora    <- bez ctl instrumentace
bin/x64/Release/dosbox-x.exe  31. cervence 16:27  <- 2 min po zmene engine.cpp
```
Debug exe je mesice stary, jeste pred celym ctl protokolem - proto se
nenacetl config, netiskly se `[ctl]` radky a nefungoval ani STOP.
Domnenka z pokr. 17, ze je to volbou CPU jadra, byla **MYLNA** - `core=auto`
je v poradku, `enginestep()` v core_normal se vola normalne.
**VZDY POUZIVAT `bin/x64/Release/dosbox-x.exe`.**
(Pozn.: `[ctl] radek N: neznamy prikaz 'DUMPREGS'` je NEskodne varovani -
DUMPREGS ma vlastni loader `ctl_load_dumpregs`, ktery config cte zvlast.)

**REFERENCNI HODNOTY Z ORIGINALU** (`DUMPREGS cond=eip:` na 0x0037A680 =
`sub_156680` a 0x00386000 = `sub_162000`, beh do 400M cyklu):
- `sub_156680` (AIL casovaci obsluha): **1136 volani**, prvni uz v cyklu
  **81 410 015**, posledni 399 787 281. Rozestupy jsou velmi pravidelne:
  **~301 500 cyklu** (301517 / 301519 / 301499) = takt PIT.
- `eax = 003EC8D8` pri kazdem volani = ukazatel na DIG_DRIVER (potvrzeno).
- `ret = 00378E4E` -> IDA **0x154E4E** = volajici AIL dispatcher casovace.
- `sub_162000` (mixer): **106 volani**, prvni az v cyklu **277 571 832**
  (tedy dlouho po startu casovace - az kdyz skutecne hraje sample), dalsi
  po ~221 000 cyklech.

**POROVNANI S PORTEM:**
| | original | port |
|---|---|---|
| `sub_156680` | 1136 | ~0 (bez tepu) |
| `sub_162000` | 106  | 2-3 |
| prepnuti head | 8+ | 0 |

**ZAVER (uz podlozeny, ne odhad):** v originale casovac tika PRAVIDELNE a
NEZAVISLE na tom, co hra prave dela - od inicializace zvuku az do konce.
Port ho budi jen z `PortVga_BlitBackBuffer` (cesta videa) a z
`PortSound_QueuedBytes`; jakmile se audio zadrhne, obe cesty prestanou
chodit a tep umre. Proto mixer probehne 2-3x misto ~100x.

**Dalsi krok:** dat portu opravdu nezavisly tep s poctem tiku odpovidajicim
originalu (~301,5k cyklu odpovida pri dobovem taktovani radove stovkam Hz -
presnou frekvenci lze dopocitat z `sub_13FBB5`/AIL nastaveni, pripadne
zmerit `DUMPREGS` na AIL_set_timer_frequency). Az bude tep spravne, znovu
porovnat pocty volani a teprve pak obsah namixovaneho bufferu.

### Vlna 26 pokracovani 19: PROTOKOL MIXERU BEZI - head/tail se strida spravne

**Tep presunut do `sub_14A090`** (herni obsluzna funkce, kterou `sub_132869`
vola v cekaci smycce dokola). Predtim visel na `PortVga_BlitBackBuffer`,
tedy na cesteVIDEA - a ta pri zadrhnutem audiu prestala chodit, takze tep
umrel. Ted bezi i kdyz video stoji.

**VYSLEDEK (mereno):** spotreba zdrojoveho bufferu je presne podle ocekavani
```
zbyva 7168 -> 6144 -> 5120 -> 4096 -> 3072 -> 2048 -> 1024 -> 0   (8 volani)
pak se prehodi head a jede dalsi buffer: 8190 -> 7166 -> ...
```
- **prepnuti head: 80** (predtim 0; original v kratsim okne 8+)
- volani mixeru: >=10 (strop trace; original 106)
Mixer, protokol head/tail i stridani obou bufferu tedy funguji.

**ZBYVA POSLEDNI CLANEK:** `davky = 0`. Je to logicke - zvuk ted mixuje
SKUTECNY MIXER HRY do DMA pul-bufferu driveru (+44 / +48), zatimco stara
nahrada posilala do SDL herni ring buffer. Namixovana data vznikaji
spravne, jen je nikdo neodesila. Dalsi krok: po kazdem tiku vzit pul-buffer,
ktery `sub_162201` prave naplnil (`driver + 44 + 4*(index^1)`, velikost
`driver+68` = 2048 B), a poslat ho do SDL misto
`PortSound_FeedStream` z ring bufferu. Tim se cela cesta srovna s
originalem: hra mixuje, port jen predava hotovy buffer zarizeni.

**K PRERUSENI (dotaz uzivatele):** v DOSu to NENI samostatny proces - AIL si
zavesi INT 8 (PIT), tedy asynchronni PREEMPCE tehoz procesu. Vlastni vlakno
v portu by bylo nejblizsi analogie, ale sahalo by hre do stavu uprostred
operace (mixer i hra pracuji nad stejnymi strukturami bez zamku), takze tep
pumpujeme z mist, kde by v DOSu preruseni stejne nastalo.
**Co ale zlepsit:** tep ma vznikat TAM, KDE HO ZAKLADA DOS - ted je natvrdo
`sub_156680`, spravne se ma registrovat pres `sub_1400A9`
(AIL_register_timer, uklada callback do `dword_18986C[]` pres `sub_155542`)
a spoustet tim, cim ho spousti hra. Pak by port zrcadlil zivotni cyklus
originalu misto pevne zadrateneho volani.

### Vlna 26 pokracovani 20: cesta mixer -> SDL uzavrena

**Posledni clanek doplnen:** po kazdem tiku se bere HOTOVY DMA pul-buffer,
ktery `sub_162201` prave naplnila (`driver + 44 + 4*(idx^1)`, velikost
`driver+68`), a posila se do SDL. Format se cte z driveru (+20 frekvence,
+60 kanaly, +64 bajtu na vzorek) -> **U8 stereo 22050 Hz**. Stara nahrada
(`PortSound_FeedStream` z herniho ring bufferu) je pri bezicim mixeru
vypnuta, aby se dva zdroje nemichaly do jednoho streamu.
Tim je cesta srovnana s originalem: **mixuje hra, port jen preda hotovy
buffer zarizeni.**

**Opraveno "rozsekane techno" (hlaseni uzivatele):** interval tepu se
pocital z formatu VIDEO STREAMU (11025 Hz -> 2048 B = 92 ms), jenze driver
mixuje na 22050 Hz stereo, kde se tychz 2048 B prehraje za **46 ms**. Data
tedy chodila dvakrat pomaleji, nez je zarizeni spotrebovalo, a polovinu casu
bylo ticho. Interval se ted pocita z VYSTUPNIHO FORMATU DRIVERU.

**Stav:** head 80 prepnuti, zarizeni U8 stereo 22050 Hz, zadny pad mixeru
(jediny SEH je znamy pad vedlejsiho vlakna, je i bez audia).
Zbyva overit poslechem a pak porovnat OBSAH namixovaneho bufferu proti
originalu (`DUMPMEM` na driver+80 / pul-buffery) - ted uz je cim, viz
pokr. 18 (POUZIVAT `bin/x64/Release/dosbox-x.exe`).

### Vlna 26 pokracovani 21: struktura driveru porovnana s originalem

**Dumpnuta struktura DIG_DRIVERu originalu v okamziku mixovani**
(`DUMPMEM cond=eip:0x00386000 addr=0x003EC8D8 size=128`, Release build):
```
+0  003EC8A8   +4  000121EC   +8  000122DC   +12 00000004
+16 00000800   +20 00005622   +24 00000002   +28 00000000
+32 128F0000   +36 000001E8   +40 000128F0   +44 00013000
+48 00013800   +52 000122E4   +56 00000000   +60 00000002
+64 00000001   +68 00000800   +72 00000400   +76 00002000
+80 004EA038   +84 00000001   +88 00000000   +92 004F2038
+96 00000011   +100 00000000
```
Porovnani s nahradnim driverem portu: **vsechna formatova pole SEDI** -
+16=2048, +20=22050, +24=2, +28=0, +60=2 (kanaly), +64=1 (bajt na vzorek),
+68=2048, +72=1024, +76=8192, +84=1, +96=17. Take +44/+48 maji rozestup
0x800 = 2048, stejne jako nase dve poloviny. Bitova hloubka ani polarita se
tedy z techto poli kazit nemuze.
Jediny nalezeny rozdil: **+12 = 4** (port mel 0) - doplneno.
Nezname zustavaji +32/+36/+40 (0x128F0000 / 0x1E8 / 0x128F0) - vypadaji jako
real-mode adresy DMA bufferu, ktere v portu smysl nemaji.

**Dalsi krok (uz jen jeden a je primo mericky):** porovnat OBSAH namixovaneho
pul-bufferu. V originale je na **0x00013000** (velikost 2048 B), takze
`DUMPMEM cond=eip:0x00386000 addr=0x00013000 size=64` da referenci; v portu
totez z `driver + 44`. Kdyz se lisi rozlozeni hodnot (prumer kolem 128 =
zvuk vs. rozprostrene = sum), je jasne, jestli chyba vznika uz pri mixovani,
nebo az pri prevodu v `sub_162201`.

### Vlna 26 pokracovani 22: indexy mixeru sedi, ale HLASITOST NE

**Porovnani indexu `dword_18AD28` s originalem** (`DUMPREGS
cond=changed:0x003A0D28:4 repeat=always`, Release build, 181 zmen):
original cykluje `0x23 -> 0x50 -> 0x03 -> 0x23 -> 0x50 ...`
- **0x23 (35)** = index mixeru v `sub_162000` - **PORT POUZIVA STEJNY**, tedy
  mixovaci rutina je vybrana spravne.
- **0x50 (80)** vznika na eip 0x0038623E = IDA `0x16223E`, tj. uvnitr
  `sub_162201` = index PREVODNI rutiny. `0x50 = 0x10 | 0x40`, kde 0x40 se
  nastavi jen kdyz `driver+100` (pocet hrajicich samplu) neni nula.
  V portu zatim NEZMERENO - dalsi krok.
- Vedlejsi potvrzeni: `sample+64` = hlasitost (127 = max) a `sample+68` =
  panorama (64 = stred); kdyz nejsou na techto hodnotach, mixer jde vetvi
  0x40 (skalovanou). Original ma pri mixovani 0x23 (bez 0x40), takze
  sample+64 == 127 - shodne s portem.

**NALEZ - HLASITOST** (`DUMPREGS cond=changed:0x0039A3A4:1`, tj.
`byte_1843A4`):
```
cycle 12865618  00 -> 7F   (127, inicializace)
cycle 63643819  7F -> 3F   (63)  eip=003366FD = IDA 0x1126FD
                           ebx=00000064 (100), edx=00000032 (50)
```
**Original si pred intrem stahne hlavni hlasitost na 63 ze 127, tedy na
POLOVINU** (registry ukazuji prevod z procent: 100 -> 50 %). Port zadne
skalovani neaplikuje - PCM jde do SDL v plne urovni. Pri 8bitovem mixu to
znamena dvojnasobnou amplitudu, ktera orezava; presne to odpovida hlaseni
uzivatele "zasumene / zkreslene".

**Dalsi krok:** dohledat, kudy se `byte_1843A4` dostane k samplu
(`sub_14129D` = AIL_set_sample_volume -> `sample+64`) a zajistit, aby to v
portu probehlo stejne. Pozor: kdyz bude `sample+64 != 127`, mixer prejde na
vetev 0x40 - a to je zaroven kontrola, ze je to udelane spravne, protoze
original v te dobe mixuje s 0x23. Tedy: hlavni hlasitost 63 se NEaplikuje
na `sample+64`, ale nekde jinde v retezci - zjistit kde (IDA 0x1126FD je
misto, kde se 63 zapisuje).

### Vlna 26 pokracovani 23: OPRAVA zaveru o hlasitosti + index prevodni rutiny

**OPRAVA pokr. 22 - hlavni hlasitost 63 NENI pricinou zkresleni.**
Dohledano, kam ta hodnota jde:
```
v3 = 127 * a1 / 100;      // a1 = procenta; pro 50 % vyjde 63  (sedi s dosboxem)
byte_1843A4 = v2;
sub_14129D(dword_1B0670[v4], (uint8_t)byte_1843A4);   // handles 1..16
```
Jde pres `AIL_set_sample_volume` na `sample+64`, ale JEN na 16 kanalu
zvukovych EFEKTU (`dword_1B0670[]`). Sample videa mezi nimi neni. Potvrzuje
to i mereni: original mixuje s indexem `0x23`, coz vyzaduje
`sample+64 == 127`. Hlavni hlasitost se tedy na zvuk videa nevztahuje.

**Index prevodni rutiny (`sub_162201`):** port **16 (0x10)**, original
**80 (0x50)**; rozdil je bit `0x40`, ktery pochazi z `driver+100` (pocet
hrajicich samplu, nastavuje ho `sub_156680` tesne pred volanim
`sub_162201`).
**POZOR - zatim NEJDE o srovnatelna mista:** zachycene vzorky portu maji
`a2` = 0 a pak 1, coz jsou INICIALIZACNI volani
`sub_162293; sub_162201(drv,0); sub_162201(drv,1)` pri startu driveru, kdy
jeste nic nehraje (`driver+100` = 0 pravem). Original v te fazi ukazuje
`0x03`. Ustaleny stav portu zmeren neni.

**Dalsi krok:** v portu preskocit prvnich N volani `sub_162201` (nebo
logovat az kdyz `driver+100 != 0`) a teprve to porovnat s originalnimi
`0x50`. Kdyby port i v ustalenem stavu davall 0x10 misto 0x50, znamenalo by
to, ze se `driver+100` nenastavuje - a prevod by pak bezel rutinou bez
skalovani poctem hlasu, coz by presne odpovidalo zkreslenemu/prebuzenemu
zvuku.

### Vlna 26 pokracovani 24: VSECHNY parametry uz s originalem SEDI

Doplneno mereni ustaleneho stavu (logovat az kdyz `driver+100 != 0`, protoze
prvni volani `sub_162201` jsou inicializacni):

| velicina | original | port | |
|---|---|---|---|
| index mixeru (`sub_162000`) | 0x23 = 35 | 35 | OK |
| index prevodu (`sub_162201`) | 0x50 = 80 | **80** | OK |
| `driver+100` (hrajicich samplu) | != 0 | 1 | OK |
| `driver+24` / `+28` | 2 / 0 | 2 / 0 | OK |
| `+60` kanaly / `+64` bajtu na vzorek | 2 / 1 | 2 / 1 | OK |
| `+20` frekvence | 22050 | 22050 | OK |
| `+68`/`+72`/`+76` | 2048/1024/8192 | totez | OK |

**K poctu bitu (dotaz uzivatele):** nastavuje se pres `driver+64` (bajtu na
vzorek = 1) a `driver+60` (kanaly = 2), tedy **8bit stereo**, 22050 Hz.
Potvrzuje to i obsah bufferu: ticho je `0x80`, coz je 8bit UNSIGNED se
stredem 128 - a presne tak se zarizeni otevira (U8 stereo 22050). Bitova
hloubka tedy neni pricinou.

**Stav: vsechny parametry, ktere sly porovnat, uz sedi, a zvuk presto brumi
a sumi.** Uzivatel upozornuje, ze pred 1-2 vlnami znel spravne - tehdy ale
sel do SDL HERNI RING BUFFER (`PortSound_FeedStream`), zatimco ted jde
VYSTUP MIXERU. Rozdil uz tedy nebude v nastaveni, ale v DATECH.

**Dalsi krok - jedina zbyvajici neporovnana vec: OBSAH bufferu.**
V originale je DMA polovina na **0x00013000** (2048 B). Potreba vzorek z
doby, kdy uz zvuk HRAJE (prvni volani mixeru je jeste ticho, samé 0x80 - a
to portu sedi). `DUMPMEM` v tomhle buildu NECTI `repeat=always`, takze je
nutny pozdejsi spousteci bod - napr. `cond=eip:` na 0x0038623E
(= IDA 0x16223E, uvnitr `sub_162201`) v kombinaci s vyssim `STOP`, nebo
`DUMPREGS cond=changed:` na prvnich 4 bajtech bufferu. Pak totez vypsat v
portu z `driver+44` a porovnat rozlozeni hodnot (prumer kolem 128 = zvuk,
rozprostrene = sum).

### Vlna 26 pokracovani 25: PRICINA BRUMU ZMERENA - stejnosmerna slozka +37
### a orezavani na vystupu mixeru

Pridan prepinac zdroje zvuku pro A/B porovnani poslechem pri jinak uplne
stejnem behu: **`REORION2_AUDIO_SRC=ring|mix`** (vychozi `mix`).
K tomu statistika odesilaneho signalu (`REORION2_AUDIO_STATS=1`, kazda
40. davka).

**Namereno (a uzivatel obe varianty potvrdil poslechem):**
```
mix  (vystup mixeru):  min=95 max=255 prumer=165   <- brumi a sumi
mix                     min=73 max=255 prumer=164
ring (stara nahrada):  min=77 max=187 prumer=128   <- zni spravne
ring                    min=98 max=158 prumer=126
```
8bit unsigned PCM ma ticho na **128**. Vystup mixeru ma prumer **165**, tedy
**stejnosmernou slozku +37** (= slysitelny brum), a `max` je pripicnute na
**255**, tedy signal ORE ZAVA (= sum/zkresleni). Ring buffer je vycentrovany
na 128, jak ma byt.

**Tim je vylouceno, ze jde o nastaveni** - vsechny parametry uz s originalem
sedi (viz pokr. 24). Chyba je ve VYPOCTU, konkretne na ceste
akumulator -> 8bit unsigned.

Jak to ma fungovat: mixovaci rutina prevadi 8bit unsigned na signed 16bit
pres `BYTE1(result) = *a5; result ^= 0x8000` (ticho 0x80 -> 0x8000 -> 0),
akumuluje `*a4 += (int16_t)result`, a `sub_162201` (rutina `off_1602F8[80]`)
prevadi akumulator zpet na 8bit unsigned, tedy +128 a orez.

**Dalsi krok:** zkontrolovat prave rutinu `off_1602F8[80]` (prevod
akumulatoru na U8) a `sub_162293` (nulovani mix bufferu, `driver+80`,
velikost `driver+76` = 8192 B) - podezreni na chybejici/neuplne vynulovani
mezi tiky nebo na spatnou konstantu posunu v prevodu. Referenci lze vzit z
dosboxu: obsah DMA poloviny originalu na **0x00013000** by mel mit prumer
kolem 128.

### Vlna 26 pokracovani 26: *** BRUM ODSTRANEN - dve chyby dekompilatu v
### pravem kanalu mixeru ***

**Nalezeno v `sub_16177F` a overeno proti asm:**
```
cmp     esi, dword_182D30
mov     ah, [esi]        ; EAX bity 8..15 = BYTE1   (levy kanal)
mov     bh, [esi+1]      ; EBX bity 8..15 = BYTE1   (PRAVY kanal!)
xor     eax, 8000h
xor     ebx, 8000h
...
movsx   ebp, ax          ; orez na 16 bitu se znamenkem
add     [edi], ebp
movsx   ebp, bx          ; TOTEZ pro pravy kanal
add     [edi+4], ebp
```
IDA z toho udelala:
```c
HIBYTE(a3) = a5[1];   // HIBYTE u 32bit hodnoty = bity 24..31, ne 8..15 !
a4[1] += a3;          // chybi orez (int16_t) odpovidajici `movsx ebp, bx`
```
Pravy kanal tedy dostaval bajt o 16 bitu vys a pricital se neorezany ->
obrovske kladne vychylene hodnoty.

**Opraveno na `BYTE1(a3) = a5[1];` a `a4[1] += (int16_t)a3;`.**

**VYSLEDEK (mereno na signalu odchazejicim do SDL):**
```
pred:  min=95 max=255 prumer=165   (stejnosmerna slozka +37, orezavani)
po:    min=18 max=212 prumer=127   (vycentrovane, plna dynamika bez orezu)
       min=19 max=241 prumer=126
```
Uzivatel potvrdil poslechem: **zvuk hraje v poradku.**

**Stejna dvojice chyb opravena i v dalsich 7 rutinach tabulky**, u vsech
overeno v asm, ze maji identicky vzor (`mov ?h, [..]` pro OBA kanaly +
`movsx ebp, bx` pred pricitanim): `sub_1613A7`, `sub_161405`, `sub_1615A2`,
`sub_1615EA`, `sub_1617F9`, `sub_161A1C`, `sub_161A80`. Ty se pro tenhle
format nevolaji, ale uplatni se u jinych vzorkovacich frekvenci / mono
stop, takze by stejny brum zpusobily jinde.

**Overeno:**
- 3 behy po sobe: zvuk stabilne hraje, prumer 125-127, zacatek zvuku vzdy na
  stejne davce (determinismus v poradku)
- **regrese videa zadna: `compare_frames` 600/600 matched, 0 diverged**

**Pozn.:** `REORION2_AUDIO_SRC=ring|mix` zustava jako prepinac zdroje pro
pripadne dalsi A/B porovnani poslechem; vychozi je ted spravne `mix`.

### Vlna 26 pokracovani 27: audio ZAPNUTO VE VYCHOZIM STAVU + nova zavada:
### video bezi pomalu

**Prepinace otoceny na zapnuto** (uzivatel spustil Debug x64 z Visual Studia
a nemel zvuk - z VS se promenne prostredi nepredavaji):
- `REORION2_VIDEO_AUDIO` - default ZAP, vypina se `=0`
- `REORION2_AUDIO_TIMER` - default ZAP, vypina se `=0`
Overeno bez jakychkoli promennych: casovac ZAPNUT, zdroj `mix`, zarizeni
U8 stereo 22050, prumer davek 127 -> zvuk hraje.

**Pozn. k mereni:** beh, ze ktereho vyslo jen 106 snimku, byl ukoncen
PREDCASNE (proces byl zabit), takze z nej NEPLYNE, ze by video bezelo
pomalu - ten zaver byl chybny a je stazeny. Vsech 106 porovnanych snimku
sedelo (`106 matched, 0 diverged`). Plnou regresi 600/600 je potreba overit
behem, ktery se necha dobehnout.

### Vlna 26 pokracovani 28-32: vstup (klavesnice/mysh) a zaseknuti v menu

**HOTOVO A OVERENO:**
- **Preskoceni intra funguje.** Smycka loop3 (`orion_part_01.c`) testuje
  `sub_12C392()` (klavesa) a `sub_124075()` (mysh). `sub_12C392` cetla
  `byte_1BC2E4`, ktere v originale nastavuje INT 9 obsluha - a ta je v portu
  prazdna zaslepka (`KeyboardIsr_12C4D8`), takze vracela vzdy 0. Doplnena
  nahrada `PortInput_PollKeyPress()` (hranou, jako preruseni).
- **INT 33h doplneno o funkce 1, 2, 7, 8, 26, 27** (port umel jen 0 a 3).
  Klicove: hra si pres fn 7 nastavuje rozsah X na `2*(sirka-1)` = 0..1278
  (dobovy zvyk DOS ovladace), port vracel syrove pixely okna -> polovicni
  souradnice. Fn 27 (citlivost) port ignoroval, takze `sub_1233B4` ulozilo
  do `dword_1B91F0/F4/F8` nuly; **v originale zmereno 50/50/50**
  (`DUMPREGS cond=changed:0x003CF1F0:4`, eip 0034741C).
- **Fronta udalosti SDL se ted skutecne VYBIRA** (drive jen
  `SDL_PumpEvents()`, ktere zpravy neodebira -> okno "neodpovida").

**NEVYRESENO - zaseknuti v menu (cerna, pak seda obrazovka):**
Zmereno: `Present()` se po intru zavola jen ~100-200x a pak PRESTANE.
Uzivatel spravne pripomnel, ze **kurzor by pri chybne pozici byl videt
aspon na 0,0** - kdyz videt neni vubec, nekresli se NIC. Cerna obrazovka i
neviditelny kurzor maji tedy nejspis SPOLECNOU pricinu: hlavni vlakno se
zasekne ve smycce, ktera uz neprojde pres `Present()`.
Vyvraceno: hra si NEregistruje obsluznou rutinu myshi (fn 0x0C se nevola
vubec); pouziva jen 0x00, 0x03, 0x04, 0x07, 0x08, 0x1A, 0x1B.
Fn 4 (nastav pozici) byla zkusmo implementovana pres
`SDL_WarpMouseInWindow`, ale casove sedela na zcernani, takze je ZATIM
VYPNUTA s poznamkou.

**DALSI KROK (metodika, kterou uzivatel opakovane zada a ktera se osvedcila):
porovnat s dosboxem, ne hadat.**
1. Zjistit, KDE se hlavni vlakno toci - citac do menu smycky, stejne jako u
   `sub_132869`.
2. Porovnat s originalem, ktere funkce/podminky se v tom miste vyhodnocuji
   (`DUMPREGS cond=eip:` na kandidatech) a jake maji klicove promenne
   hodnoty.
3. Teprve podle toho rozhodnout, jestli chybi `Present()`, nebo jde o
   zacykleni v hernim kodu.
**Nezapomenout:** dosbox spoustet vzdy z `bin/x64/Release/` (Debug build je
z unora, bez ctl instrumentace - viz pokr. 18), a port prekladat
`-t:Rebuild` (viz pokr. 15).

### Vlna 26 pokracovani 33: ZAMRZNUTI V MENU ODSTRANENO - 16bitove parametry
### v kreslici rutine fontu

**Nalezeno porovnanim s asm** (`sub_1231B1`, orion_part_19.c): smycka
hledajici zarazku 128 ve fontovych datech
```c
for ( i = 0; a6 > i; ++i )
  while ( *(uint8_t *)((int16_t)v17 + dword_1B3E74) != 128 ) ++v17;
```
Asm ale cte pocty radku jako **16BITOVE**:
```
movsx   eax, word ptr [ebp+arg_4]     ; a6
cmp     eax, [ebp+var_50]
movsx   eax, word ptr [ebp+arg_8]     ; a7 (druha smycka)
```
IDA je otypovala jako `int` a porovnavala celych 32 bitu. **Zmereno v portu:
`a6` = 0x1E0000 = 1966080** pri stropu `word_1B3EA0` = 13 -> smycka by bezela
dva miliony krat -> hra zamrzla (cerna obrazovka, okno prestalo odpovidat).
Original tam vidi spodni slovo, tedy 0.
Pozn.: `(int16_t)v17` v te smycce je naopak SPRAVNE (asm ma
`movsx edx, word ptr [ebp+var_18]`) - to nebyla chyba.

**Opraveno na 2 mistech** (`a6 = (int16_t)a6; a7 = (int16_t)a7;`).

**VYSLEDEK (mereno):**
- `a6` = 0 misto 1966080
- **`Present()` vyskocil z ~200 na 2000+** - hra uz nebezi do zaseknuti
- zadny utek skenu fontu (pridana i pojistka, ktera by ho nahlasila)
- uzivatel potvrdil, ze se vykreslil text **"LOAD GAME"** - kreslic fontu
  funguje

**ZBYVA:** vetsina obrazovky zustava cerna a kurzor je porad systemovy.
To uz neni zamrznuti, ale otazka, co se do obrazu nedostane - dalsi krok je
porovnat s dosboxem, ktere kreslici funkce se v menu volaji (`DUMPREGS
cond=eip:` na kandidatech) a jestli port nektere preskakuje.

### Vlna 26 pokracovani 34-36: menu se vykresli CELE a hned se smaze

**Novy nastroj: HLIDAC ZAMRZNUTI** (`REORION2_WATCHDOG=<s>`, reorion2.cpp).
Na stroji neni cdb ani windbg, ale dbghelp uz linkujeme kvuli SEH vypisu -
hlidaci vlakno tedy pri delsim vypadku `Present()` pozastavi hlavni vlakno,
precte jeho kontext a vypise zasobnik i s cisly radku. Nahrazuje debugger.

**Nova metrika:** `Present()` vypisuje pocet nenulovych pixelu framebufferu
a pocet necernych barev palety (`REORION2_PRESENT_TRACE=1`). Diky ni jde
merit "co je na obrazovce" bez cizi pomoci.

**ZMERENO (bez jakehokoli vstupu, opakovane):**
```
nenulovych pixelu: 76800 -> 307200 -> 3421 -> 3421 -> 3421 ...
```
Menu se tedy vykresli **KOMPLETNI** (vsech 307200 pixelu) a teprve pak se
smaze na 3421 = samotny napis "LOAD GAME". `Present()` bezi dal (2400
volani), hlidac se nespustil, zadny SEH - hra normalne jede, jen ukazuje
smazanou obrazovku. **Neni to tedy chybejici vykresleni, ale mazani.**

**VYVRACENE HYPOTEZY (obe merenim):**
1. "Rozdil dela preskoceni klavesou vs. mysi" - stejny prubeh nastane i BEZ
   vstupu. (Drivejsi merení bylo znecistene tim, ze uzivatel behem nej
   mackal klavesy.)
2. "Falesny stisk z multimedialnich klaves" - po odfiltrovani na skutecne
   klavesy (+ ignorovani auto-repeat) je prubeh nezmeneny. Filtr je presto
   spravne, INT 9 v DOSu multimedialni klavesy nedostaval.

**VODITKO PRO DALSI KROK:** protoze kazdy dalsi snimek ukazuje STEJNYCH 3421
pixelu, hra zjevne kazdy snimek prekresluje jen text, ne pozadi. Pozadi se
nakresli jednou a pak uz ne. Hledat tedy: co v menu smycce maze
buffer/prekresluje pozadi a proc v portu podruhe neudela nic. Porovnat s
originalem (`DUMPREGS cond=eip:` na kreslicich funkcich menu), jestli se
tam vola totez.

**Dale opraveno:** klavesnice se emuluje spravne pres kruhovy buffer
`dword_1BC2AC[10]` (zapisovy index `byte_1BC2E2`, ctecí `byte_1BC2E3`,
priznak `byte_1BC2E4`) vcetne KODU klavesy - `sub_12C2E1` z nej cte, a
drive tam port nic nevkladal, takze hra cetla prazdny prvek.

---

## PRIRUCKA PRO DALSI AI (stav k 2026-08-01, konec vlny 26)

Tahle sekce je napsana pro nekoho, kdo prichazi bez kontextu. Prvni tri
kapitoly jsou o METODE - bez nich se tady da ztratit cely den, jak se mi
dnes dvakrat stalo. Ctvrta kapitola rika, kde jsme skoncili.

### 1. DOSBOX-X: jak z originalu ziskat referencni hodnoty

**PASTI, ktere me dnes staly cely kruh - prectete si je DRIV, nez neco
zmerite:**

1. **Spoustet VYHRADNE `bin/x64/Release/dosbox-x.exe`.**
   `bin/x64/Debug/dosbox-x.exe` je z UNORA, tedy z doby pred celym ctl
   protokolem. Tise se spusti, hra normalne bezi, ale **zadny config se
   nenacte, nevznikne trace soubor a nevyhodnoti se ani STOP**. Vypada to,
   jako by mereni "nefungovalo" nebo jako by byl problem ve volbe CPU
   jadra - neni. Kdyz v logu neni ani jedna radka `[ctl]`, je to skoro
   jiste tohle.
2. **Kontrolni test, jestli instrumentace vubec bezi:** dej do configu
   `STOP cond=cycle_ge:20000000`. Kdyz dosbox bezi dal a jeho vlastni log
   ukazuje vyssi cyklus, ctl NEBEZI.
3. Varovani `[ctl] radek N: neznamy prikaz DUMPREGS` je **neskodne** -
   DUMPREGS ma vlastni loader (`ctl_load_dumpregs`), ktery config cte
   zvlast. Neresit.
4. `core=auto` je v poradku, do jader nesahat (dynamicka jadra zahazuji
   instrukce kvuli rychlosti, mereni by nesedelo).

**Jak se to spousti:**

    cd /c/prenos/dosbox-x-remc2/bin/x64/Release
    DOSBOX_CTL_FILE="<cesta>/muj.cfg" ./dosbox-x.exe -conf "<cesta>/dosbox_intro.conf"

Trace soubor vznikne v CWD dosboxu (tedy v `bin/x64/Release/`).

**Format configu** (plna dokumentace: `genCompare/DOSBOX_CTL_PROTOCOL.md`):

    OUTPUT file=muj_trace.txt
    DUMPREGS cond=eip:0x0037A680 label=jmeno repeat=always
    DUMPREGS cond=changed:0x003A0D28:4 label=jmeno repeat=always
    DUMPMEM  cond=eip:0x00386000 addr=0x003EC8D8 size=128 label=jmeno
    STOP     cond=cycle_ge:400000000

- `DUMPMEM` umi JEN `cond=eip:` a v tomhle buildu **nectí `repeat=always`**
  (vypali jednou). Kdyz potrebujes pozdejsi vzorek, zvol jiny spousteci eip.
- `DUMPREGS` umi `eip:`, `changed:ADR:sirka`, `eq:`, `call:` a `repeat=always`
  funguje. **`changed:` je nejsilnejsi nastroj** - odpovi na otazku "kdo a
  kdy tuhle promennou meni", protoze vypise i EIP zapisujici instrukce.

**PREPOCET ADRES (naprosto zasadni, plete se to):**

    runtime KOD  = IDA adresa + 0x224000     (sub_162000 -> 0x386000)
    runtime DATA = IDA adresa + 0x216000     (dword_18AD28 -> 0x3A0D28)

Pozor: adresa se pocita z **C jmena** (`orion_common.h`), NE ze jmena v asm
dumpu - ten ma jina jmena (napr. `dword_182D28` = C `dword_18AD28`).

**Doba behu:** k videu se dosbox dostane kolem 80M cyklu, do menu pozdeji;
beh do 400M cyklu trva jednotky minut. Instrumentace (`cond=eip:` se
vyhodnocuje kazdy krok) emulaci znatelne zpomali a grafika se trha - to je
normalni a na spravnost dumpu to vliv nema.

### 2. JAK HLEDAT CHYBY (metoda, ktera tady funguje)

**Zlate pravidlo: MERIT, ne premyslet.** Kdykoliv jsem se dnes odchylil k
"tohle bude urcite tim", stalo to cas. Kdyz jsem misto toho zmeril obe
strany, chyba vypadla behem minut.

**Postup:**

1. Najdi MERITELNY priznak (pocet snimku, pocet volani, prumer vzorku,
   pocet nenulovych pixelu). Bez cisla se neda poznat zlepseni.
2. Zmer stejnou velicinu v ORIGINALE (dosbox) i v PORTU ve stejnem bode.
3. Rozdil zuzuj pulenim, dokud nezbyde jedna funkce/promenna.
4. **Nez neco "opravis", over si to v asm dumpu** (`Debug/diss/Orion2.exe.asm`).
   Dnes jsem dvakrat chtel opravit misto, ktere bylo SPRAVNE - a jednou
   naopak nasel chybu presne tam, kde dekompilat vypadal nevinne.

**Katalog opakujicich se chyb dekompilatoru** (kazda z nich se tu uz
vyskytla vicekrat, hledej je prednostne):

| Vzor | Jak vypada | Jak poznat |
|---|---|---|
| 16bitovy parametr jako `int` | `for (i = 0; a6 > i; ++i)` s a6 = 0x1E0000 | asm ma `movsx eax, word ptr [ebp+arg_N]` |
| Sirka ukazatele | `*(TYPE **)(x + N)` na x64 nacte 8 B misto 4 | horni pulka padove adresy = sousedni pole |
| Ztracena navratova hodnota | funkce je `void`, hodnota chodi pres `JUMPOUT` | asm ma `call` a vysledek se pouzije |
| Rozdrobeny souvisly blok | `*((_DWORD *)&x + 2)` cte sousedni global | v EXE jsou promenne za sebou, v portu ne |
| Orizla velikost pole | tabulka `[2]`, ale index az 0x7F | v EXE souvisly blok az k dalsi funkci |
| Vlastni (registrova) konvence | volani predava 3 argumenty, funkce ma 5 | asm plni EAX/EBX/ECX/ESI/EDI pred `call` |
| Konstanta jako navesti | `sub_10000` pouzite jako cislo | v asm je to `10000h` |

**Diagnosticky trik na horni pulku adresy:** kdyz pad hlasi adresu typu
`0x1_16CA7280` nebo `0x4_16D69A24`, dolni polovina je platny 32bitovy
ukazatel a **horni polovina rovnou rekne, ktere sousedni pole se prilepilo**
(1 = priznak vedle, 4 = stav samplu...). Tim se chyba najde behem minuty.

### 3. JAK PRACOVAT S PORTEM

- **Preklad VZDY pres `-t:Rebuild`:**

      MSBuild.exe reorion2.sln -t:Rebuild -p:Configuration=Debug -p:Platform=x64

  Inkrementalni build tu obcas NErelinkuje a bezi stara binarka. Dnes me to
  dostalo: vypadalo to, ze spravna oprava rozbila i vychozi cestu, revertoval
  jsem ji, a po Rebuildu se ukazalo, ze zdroj byl cely cas v poradku.
- **Kdyz linker hlasi "soubor se neda otevrit"**, bezi instance hry - zavrit.
- **Pri zasahu do dekompilatu overit, ze mirime do SPRAVNE funkce** - stejny
  vzor kodu byva ve vice funkcich a nahrazeni trefi prvni vyskyt. Dnes tak
  jedna oprava spadla vedle a vypadalo to, ze nefunguje.
- **Komentovat cesky a u kazde opravy uvest, CO bylo namereno** - komentare
  jsou tu hlavni pamet projektu.
- **cdb ani windbg na stroji NENI** (jsou tam jen dbghelp DLL). Misto nich
  slouzi vestaveny hlidac (viz `REORION2_WATCHDOG` nize) - umi pozastavit
  hlavni vlakno a vypsat jeho zasobnik i s cisly radku.

**Diagnosticke prepinace, ktere uz existuji:**

    REORION2_PRESENT_TRACE=1   pocet volani Present + pocet nenulovych pixelu
                               a necernych barev palety  (3421 = rozbite menu,
                               230887 = spravne vykreslene)
    REORION2_BLIT_STATS=1      kolik blitu se zahodi kvuli nulovemu zdroji,
                               kolik okennich slotu je prazdnych, kdo je vola
    REORION2_FAKE_MOUSE=1      kurzor sam krouzi po obrazovce (test bez cloveka)
    REORION2_FAKE_CLICK=1      k tomu drzi leve tlacitko
    REORION2_WATCHDOG=5        pri vypadku Present pozastavi hlavni vlakno a
                               vypise jeho ZASOBNIK i s cisly radku
    REORION2_MOUSE_TRACE=1     vypise vsechny volane funkce INT 33h
    REORION2_TRACE=1           zapina PortDebug_Checkpoint (vypis "DIAG ...")
    REORION2_AUDIO_STATS=1     min/max/prumer odesilanych vzorku (128 = ticho)
    REORION2_AUDIO_SRC=ring|mix  prepinac zdroje zvuku pro A/B porovnani
    REORION2_VIDEO_AUDIO=0     vypne zvuk videa (hodi se pri dumpu snimku)
    REORION2_AUDIO_TIMER=0     vypne emulovany AIL casovac
    REORION2_BLIT_DUMP_DIR=<d> + REORION2_BLIT_DUMP_COUNT=600
      + REORION2_DUMP_INCLUDE_PALETTE=1     ulozi snimky pro compare_frames

**Regresni test videa** (musi zustat 600/600, jinak je oprava spatne):

    genCompare/compare_frames.exe <dosbox_frames5> <port_frames> 640 480

Referencni snimky jsou ve scratchpadu (`dosbox_frames5`). Pri dumpu se
vyplati `REORION2_VIDEO_AUDIO=0`, at beh nezdrzuje zvuk.

### 4. KDE JSME SKONCILI

**HOTOVO A OVERENE:**

- **Video**: `compare_frames` 600/600 matched, 0 diverged.
- **Zvuk videa**: hraje spravne a je ZAPNUTY ve vychozim stavu. Bezi pres
  skutecny mixer hry (emulovany AIL casovac + DMA pul-buffery), signal ma
  prumer 127 (spravne vycentrovany; drive 165 = stejnosmerna slozka a orez).
- **Intro jde preskocit** klavesou i mysi.
- **Zamrznuti v menu odstraneno** (16bitove parametry v kreslici rutine
  fontu `sub_1231B1`), `Present()` z ~200 na 2000+.
- **Klavesnice** se emuluje pres skutecny kruhovy buffer `dword_1BC2AC[10]`
  vcetne kodu klavesy; multimedialni klavesy jsou odfiltrovane.
- **Mys**: INT 33h doplneno o fn 1, 2, 7, 8, 26, 27; souradnice se prepocitavaji
  z rozmeru OKNA (okno je ve dvojnasobku rezimu!) na rozsah, ktery si hra
  nastavuje pres fn 7/8 (X je 0..2*(sirka-1), dobovy zvyk DOS ovladace).
  Systemovy kurzor se skryva pri inicializaci obrazu (hra fn 1/2 nikdy nevola).

**NEVYRESENO - jedna spolecna pricina, tri projevy:**

1. Pozadi menu obcas zmizi (obraz spadne z 230887 na 3421 nenulovych pixelu,
   zustane jen napis "LOAD GAME"). **Nedeterministicke.**
2. **Softwarovy kurzor se nekresli vubec** - overeno `REORION2_FAKE_MOUSE=1`:
   pozice se meni, ale obraz zustane bit po bitu stejny.
3. Klikani nema efekt.

**Co je o tom zmereno:**

- Blity se tise zahazuji obranou `if (!a3) return 0;` v `sub_12A478`
  (`orion_part_19.c`, pochazi z vlny 24 s poznamkou "pricina se nenasla").
- Vsechny nulove blity maji **jednoho volajiciho**: `sub_11E718`
  (`orion_part_19.c:1862`) a souradnice **(0,0)** = celoobrazovkove pozadi.
- Zdroj se bere z okenni tabulky: `off_184480 + 55*i + 44`.
- **Zmereno: 9 oken, z toho 8 ma na +44 nulu** (pozdeji 7/6). Sloty se tedy
  neplni.
- Tabulka sama je v poradku (`unk_1B0848[13750]` = 250 slotu po 55 B).
- **Overeny negativni vysledek:** `sub_114DCA` (tvorba okna) vraci hodnotu,
  jejiz horni pulka je zbytek adresy - ale **ORIGINAL DELA TOTEZ**
  (`inc word_1ABE0E` / `mov ax, word_1ABE0E` / `dec eax`). Tam se sahat NEMA.
- Take opraveno: 191 vyskytu `*(int *)((char *)&dword_1B3E0A + 2) >> 16`
  nahrazeno primo `word_1B3E0E` (v originale ty globaly lezi za sebou, v
  portu to zaviselo na rozlozeni od prekladace). Samo o sobe to nestacilo.

**DALSI KROK (konkretne):**

Protoze callee je shodne s originalem, riziko je na strane VOLAJICICH:
funkce pro tvorbu oken je fakticky 16bitova (volajici si v originale berou
jen `AX`), ale IDA ji otypovala jako `int`. Overit u vsech volajicich
(mista s `++word_1B3E0E` v `orion_part_18.c`), jestli navratovou hodnotu
orezavaji na 16 bitu - kdyz ne, dostanou misto indexu okna obrovske cislo a
zapisuji sloty jinam, nez se ctou. To by vysvetlilo vsechny tri projevy
najednou, protoze kurzor i pozadi jdou stejnou kreslici cestou.

Paralelne se to da potvrdit z dosboxu: `DUMPMEM addr=0x3C6848` (sloty) a
`word_1B3E0E` na `0x3C9E0E` - kdyz ma original na +44 platne ukazatele tam,
kde port nuly, je to potvrzene.

---

## Vlna 26 pokracovani 41: MYS - obsluzna rutina, VESA banky a tabulky
## oblasti kurzoru (3 chyby, vsechny zmerene)

Vychozi stav: kurzor se nekreslil vubec, klikani nemelo ucinek. Predchozi
zaver "hra si NEregistruje obsluznou rutinu myshi (fn 0x0C se nevola)" byl
CHYBNY a je timto stazen - registrace jde pres `int386x`, ktery byl v
`link_stubs.c` prazdny stub `int int386x(void) { return 0; }`, takze port o
volani vubec nevedel (a `REORION2_MOUSE_TRACE` sledoval jen `int386`).

### Chyba 1: obsluzna rutina myshi se nikdy nezaregistrovala ani nezavolala

Zmereno v asm (`sub_1237F3`, `sub_12386C`, `sub_123926`): hra vola
`int386x` s EAX=0x33 a funkci **0x0C (maska 1)** resp. **0x14 (maska 0x2B)**,
rutina je `sub_1236D1`. V DOSu ji ovladac volal pri kazde udalosti a TEPRVE
ONA nastavuje pozici kurzoru (`dword_1BBA38` / `HIWORD(dword_1BBA34)`), stav
tlacitek (`word_1B921A`) a kurzor i kresli.

`sub_1236D1` navic IDA vubec nedekompilovala (zbyla jedna nesmyslna radka
`_GETDS(...)`) - prepsana rucne podle asm. Argumenty odpovidaji registrum
AX/BX/CX/DX; X chodi ve dvojnasobnem rozsahu a rutina ho deli dvema.
Prepinani SS:ESP na vlastni zasobnik je DOS specificke a v portu vynechane.

Doplneno:
- `PortDos_Int386x` (port_dos.cpp) - fn 0x0C/0x14 si pamatuji adresu rutiny
  a masku; ostatni preruseni se chovaji jako drivejsi stub (vraci 0).
- `PortDos_ServiceMouse()` - emuluje preruseni: prepocte pozici, spocita
  masku udalosti a rutinu zavola. Vola se z `Port::Vga::Present()`.
- Prepocet pozice vytknut do `ComputeVirtualMouse`, aby dotaz fn 3 i
  callback hlasily totez.

### Chyba 2: neprepinaly se VESA banky (kurzor fungoval jen v 1/5 obrazovky)

Nizkourovnove rutiny kurzoru (`sub_144A91` uloz pozadi, `sub_144EAC` obnov,
`sub_14529D` kresli) sahaji primo do VESA okna (v originale 0xA0000, 64 KB) a
mezi radky si prepinaji BANKU pres `sub_138C34`/`sub_138C58` (INT 10h
AX=4F05h, cislo banky v AX z `word_188D82`). Obe prepinaci rutiny byly v
portu prazdne stuby, takze cely obraz padal do banky 0.

**Zmereno uzivatelem:** kurzor sledoval mys jen v horni petine obrazovky -
64 KB / 640 B = 102 radku z 480, presne jedna banka.

Doplneno `PortVga_SetVideoWindow()` / `PortVga_VideoWindow()` (framebuffer
portu ma presne 5 bank, stejne jako jedna obrazova stranka originalu, proto
`bank % 5`), obe prepinaci rutiny je volaji a 21 mist v `orion_part_21.c`
bere zaklad z okna misto z `PortVga_Framebuffer()`.

### Chyba 3: tabulky oblasti kurzoru mely misto 12 bajtu jen 1

`sub_123EA7` hleda v tabulce (`dword_1B9204`, polozky po 12 B
`{tvar, 0, x0, y0, x1, y1}`) oblast, ve ktere kurzor lezi, a vezme z ni
CISLO TVARU; `sub_12439D` kresli jen kdyz je tvar > 0. IDA vsechny tyhle
tabulky (`unk_17CF00` a dalsich 20) udelala jako jednobajtove `_UNKNOWN`,
takze se cetly nuly -> tvar 0 -> kurzor se NIKDY nenakreslil. Misto nej se
jen posouval ulozeny kus pozadi (uloz + obnov bez kresli) - presne to, co
uzivatel popsal jako "kus pozadi misto kurzoru".

**Zmereno instrumentaci poradi operaci:** pri pohybu myshi se volalo
`kurzor.obnov` a `kurzor.uloz`, ale `kurzor.kresli` ANI JEDNOU. Po oprave
14x kresli / 15x uloz na stejnem useku behu.

Vsech 21 tabulek dostalo doslovna data z EXE (`Debug/diss/Orion2.exe.asm`);
`unk_17CF00` = `{1, 0, 0, 0, 639, 479}`. Zvlast `unk_184522`, ktera se plni
az za behu - jeji pole +8/+10 byla v dekompilatu samostatne promenne
`word_18452A`/`word_18452C` a v portu na sebe nemusely navazovat.

### Dale opraveno pri teze prilezitosti

- 8 mist typu `*(int *)((char *)&dword_1BBA34 + 2) >> 16` (cteni pres hranici
  sousedni globalni promenne - viz katalog "rozdrobeny souvisly blok")
  nahrazeno primym pristupem: `(int16_t)dword_1BBA38`, `word_1BBA3C`,
  `(int16_t)dword_1BBA42`.
- Doplnena chybejici globalni promenna `dword_18452E` - zabrana proti
  opakovanemu vstupu do obsluzne rutiny myshi (v asm `unk_17C52E`).

### Stav

Overeno merenim i uzivatelem: kurzor se kresli, sleduje mys po CELE
obrazovce. Zbyva overit klikani a dobehnout regresni test videa
(`compare_frames`, musi zustat 600/600).

### Vlna 26 pokracovani 42: duch grafiky na prechodu banky, plynulost kurzoru
### a co je se zvukem

**1) "Duch" - kus grafiky na spatnem miste (jen v urcitych bodech).**
Na 12 mistech v `orion_part_21.c` (obe vetve kurzoru pretinajici hranici
64 KB banky) stalo:
```c
LOWORD(v7) = dword_1BBA42 + (uint16_t)&loc_9FFFD + 3;
```
V asm je to ale `add si, word ptr dword_1BBA42`, tedy **16bitovy soucet do
zakladu VESA okna** (0xA0000, spodni slovo NULA) - vysledek je proste
"zaklad okna + x". Port ma okno na malloc adrese, ktera na 64 KB zarovnana
neni, takze zapis do spodnich 16 bitu ukazatel POSUNUL. Projevovalo se to
jen na prechodu banky - odtud "jen v urcitych bodech".
Opraveno na `v7 = (char *)PortVga_VideoWindow() + (uint16_t)dword_1BBA42;`
Uzivatel potvrdil: **duch je pryc**.

**2) Trhany kurzor - zmereno, ze to nebylo vykreslovanim.**
```
Present v menu:            ~23x/s
cena jednoho Present:      prevod palety 1.03 ms + zbytek 0.34 ms
callback myshi:            ~25x/s (presne s Presentem)
```
Pricina: `PortVga_WaitVsync`/`WaitVsyncSlow` se prospaly **14 resp. 50 ms
v jednom kuse** a Present zavolaly jen jednou za cele cekani. V DOSu kreslil
kurzor ovladac z PRERUSENI primo do videopameti, tedy nezavisle na herni
smycce; v portu je videt az po Presentu.
Reseni: `PortVga_WaitSliced()` - cekani se kraji na useky po 8 ms a v kazdem
se obraz obnovi. **Celkova doba cekani je stejna**, aby se nezmenilo
casovani hry.
```
po oprave: Present ~132x/s, callback myshi ~136x/s (100 volani za 733 ms)
```

**3) Zvuk.** Menu v portu zadny zvuk nema a nikdy nemelo:
- **MIDI/hudba** - napojena NENI. `AIL_install_MDI_driver_file` vede pres
  `sub_15A340` na real-mode ovladac (ADLIB.MDI), ktery port nespousti.
  Port ma jen digitalni vetev AIL (`DIG_DRIVER`).
- **Zvuk, ktery hral drive, je zvukova stopa INTRO VIDEA.** Behy s
  `REORION2_SKIPINTRO=1` (rychla iterace) nebo `REORION2_VIDEO_AUDIO=0`
  (dump snimku) proto tise - neni to regrese.

**4) Regresni test videa.** Prvni beh po opravach dal 536/600. Pricina se
NASLA a nebyla to chyba: kdyz kurzor lezi nad oknem, hra ho vykresli do
obrazu, zatimco referencni beh dosboxu mysi nehybal. Doplnen prepinac
**`REORION2_MOUSE_CALLBACK=0`** (vypne emulaci preruseni myshi) - s nim
`compare_frames` hlasi **600/600 matched, 0 diverged**. Pri dumpu snimku ho
od ted vzdy pouzivat.

**Pozn. k testovacimu prepinaci:** `REORION2_FAKE_CLICK=1` drzel tlacitko
TRVALE a `sub_124105` je smycka "cekej, dokud neni zadne tlacitko stisknute"
-> hra se zasekla uz v inicializaci myshi. Prepsano na cyklicke mackani a
`REORION2_FAKE_MOUSE` na PLYNULY pohyb (drive teleport mezi 4 rohy, coz se
nedalo pouzit na mereni plynulosti).

### Vlna 26 pokracovani 43: KLIKANI V MENU FUNGUJE - tri chyby na jedne ceste

**1) Podminka "je pripravena klavesa?" byla skoro vzdy splnena.**
`sub_11CEF5` (vyhodnoceni vstupu v menu) zacina:
```c
LOBYTE(v4) = sub_12C392();
if ( v4 ) { ...klavesnicova vetev... }
```
V asm ale `sub_12C392` vraci NULOVE ROZSIRENY EAX (`xor eax, eax` +
`mov al, [ebp+var_4]`) a volajici dela `test eax, eax`. Dekompilat plnil jen
spodni bajt a hornich 24 bitu nechal NEINICIALIZOVANYCH -> podminka vychazela
skoro vzdy jako splnena a hra se **nikdy nedostala k vyhodnoceni MYSI**.
**Zmereno:** test zasahu okna probehl za 30 s JEDNOU; po oprave bezi
prubezne a hlasi skutecne souradnice kurzoru. Opraveno na 11 mistech
(`v = (uint8_t)sub_12C392()`).

**2) Ztracena navratova hodnota `sub_11CEF5`.**
Asm: `call sub_11CEF5 / mov [ebp+var_C], eax`, uvnitr konci
`mov eax, [ebp+var_8]`. IDA z funkce udelala `void`, takze volajici
`sub_1171AB` cetl neinicializovanou promennou misto indexu polozky, na
kterou se kliklo. Doplneno: `v50` (= asm var_8) je navratovy slot, na konci
se plni z `v49` (= var_C).

**3) DTA pro FINDFIRST prepisovala sousedni globaly.**
Po opravach 1+2 zacala hra pri kliknuti PADAT ve `fread` uvnitr `sub_12C607`
(nacteni hlavicky LBX). Hlidac zabudovany do `PortDebug_Checkpoint` ukazal,
ze `dword_1B06FC` (buffer pro tu hlavicku) nekdo prepisuje - a zuzil to na
`FindMoxSetPath_1114D7` -> `unknown_libname_1` (DOS FINDFIRST).
Ten zapisuje celych **43 bajtu** (`struct DosDta`), ale `unk_1AD828` byl v
portu `_UNKNOWN`, tedy **1 bajt**. IDA navic jeho pole rozdrobila do
samostatnych promennych (`word_1AD83E` = +0x16 cas, `word_1AD840` = +0x18
datum, `dword_1AD842` = +0x1A velikost, `unk_1AD846` = +0x1E jmeno).
Kazde hledani souboru tak prepsalo 42 bajtu sousednich globalu.
Vytknuto do jedne `struct DosDta unk_1AD828` a pole se ctou z ni.

**VYSLEDEK (potvrdil uzivatel):** kliknuti na polozku menu (QUIT) **zabere**.

**ZBYVA (dalsi krok):** po kliknuti polozky menu "zhasnou" a nova obrazovka
se nevykresli; kurzor na miste kliknuti nechava problikavajiciho "ducha".
Tedy: akce se spusti, ale prekresleni nasledujici obrazovky ne.

### Poznamka k HUDBE (mereno, nedokonceno)

Do `sub_14234D` (AIL_install_MDI_INI), `sub_142425`
(AIL_install_MDI_driver_file), `sub_14257F` (AIL_allocate_sequence_handle),
`sub_1426D1` (AIL_init_sequence) ani `sub_1427CA` (AIL_start_sequence) se
hra v portu **VUBEC NEDOSTANE** - overeno docasnymi kontrolnimi body, ani
jeden se za cely beh v menu nezavolal. Instalace hudebniho ovladace se tedy
preskakuje jeste driv (obdoba toho, co ve vlne 26 resil DIG: `sub_111F3E`
plni jen DIGITALNI vetev - `sub_140979`/`PortSound_CreateDigDriver`).
**Dalsi krok podle zadani uzivatele:** udelat pro MDI totez co pro DIG -
podstrcit fake config a nahradni MDI_DRIVER, aby si hra myslela, ze hudebni
zarizeni existuje, a retez dosel az k `AIL_start_sequence`. Teprve pak resit
skutecne prehrani XMI.

### Vlna 26 pokracovani 44: HUDBA - nalezena pricina (chybi cely blok
### "nacti nastaveni / jinak vychozi hodnoty" v GameMain)

**Test originalu v dosboxu (provedl uzivatel):** hra nabehne, v animaci s
kosmickymi lodemi hraje zvuk; po SPACE nasleduje **animace otevirajiciho se
menu, TAKE SE ZVUKEM**. Port tuhle animaci/hudbu nema vubec.

**Zmereno v portu:** kontrolni body `tail.before_2484F` a `tail.after_2484F`
jsou v logu HNED ZA SEBOU - `sub_2484F` se okamzite vrati.

`sub_2484F` (orion_part_02.c) NENI animace, ale **spusteni hudby menu**
(`sub_1136EC(aStreamLbx)` = STREAM.LBX, pak `sub_113A20/113BAC/113AF2/
113CBD`). Cela je obalena `if ( byte_199BEF == 1 )` - a `byte_199BEF`
(= "hudba zapnuta") je v portu NULA.

**Kdo ho ma nastavit:** `sub_127E1` (orion_part_01.c:2080) = vychozi
nastaveni voleb, mimo jine `byte_199BED = 1` (zvuk), `byte_199BEE = 50`,
**`byte_199BEF = 1` (hudba)**, `byte_199BF0 = 50`.

**Rozdil proti originalu (overeno v asm):**
```
                test    eax, eax          ; nacetla se konfigurace?
                jz      short loc_100E1   ; NE -> vychozi hodnoty
                call    sub_11C39
                cmp     word_191CBE, 82h  ; sedi verze configu?
                jz      short loc_100E6
                call    sub_12227         ; NE -> prevod stareho configu
                jmp     short loc_100E6
loc_100E1:      call    sub_127E1         ; <<< VYCHOZI HODNOTY (hudba ZAP)
loc_100E6:      call    sub_10C2F
```
V portu **zadny z techto ctyr symbolu neexistuje** - `sub_127E1`, `sub_11C39`,
`sub_12227` ani `sub_10C2F` nema v `src/game/*.c` jedine volani (v asm ma
`sub_127E1` volani dve: z `main__0` a z `sub_12227`). Cely blok
"nacti nastaveni / jinak vychozi" tedy pri rekonstrukci `GameMain_10057`
vypadl a vsechny volby zustavaji na nulach.

**DALSI KROK:** doplnit ten blok do `GameMain_10057` podle asm (`main__0`
kolem `loc_100E1`). Tim se rozsviti nejen hudba, ale i ostatni vychozi volby
(hlasitosti, `byte_199BED`, `byte_199CAF`, `word_199CBE` = 130, ...), ktere
jsou dnes nulove.

**Pozn.:** drivejsi stopa pres MDI ovladac (`dword_18438C`) je timto
ODSUNUTA - ta promenna nema v originalnim EXE zadny zapis (jediny xref je
cteni v `sub_112D4F+17`), takze hudba menu evidentne nechodi pres
`sub_112DA6`, ale prave pres `sub_2484F`/STREAM.LBX (digitalni stopa, ne
MIDI - odpovida i tomu, ze uzivatel mluvi o "zvuku", ne o MIDI).

**Vyvracena hypoteza (merenim):** "jeden stisk SPACE se spotrebuje dvakrat"
(intro + animace menu). Zmereno pri jednom stisku: `klav.vlozeno` 1x,
`klav.ohlaseno` 1x, `klav.precteno` 1x (kod 0x2C20 = scancode mezerniku).
Klavesnicovy buffer je v poradku, animace menu se neprehrava z jineho
duvodu - viz vyse.

### Vlna 26 pokracovani 44 - OPRAVA PREDCHOZIHO ZAVERU (merenim)

Predchozi zaver "v portu chybi cely blok nacti nastaveni / jinak vychozi
hodnoty" byl **CHYBNY a timto se stahuje**. Blok v `GameMain_10057` JE -
hledal jsem ho podle puvodnich jmen (`sub_127E1`, `sub_11C39`, `sub_12227`,
`sub_10C2F`), zatimco v portu jsou uz prejmenovana:
`InitDefaultSettings_127E1`, `LoadSettingsFile_11C39`,
`LoadOrResetSettings_12227`, `LoadLanguageSetting_10C2F`.

**Zmereno (kontrolni body v GameMain):**
```
nastaveni.mox_set_nalezen 1     <- MOX.SET se najde
nastaveni.hudba_199BEF    1     <- po nacteni je HUDBA ZAPNUTA
nastaveni.zvuk_199BED     1
tail.before_2484F         1     <- i v okamziku volani sub_2484F
```
Blok nastaveni (`stateBlock_199BDC`) je uz spravne vytknuty do packed
struktury a `MOX.SET` ma na offsetu 19 hodnotu 1 - vse sedi.

Take neplati odvozeni "`sub_2484F` se okamzite vraci, protoze mezi
`tail.before_2484F` a `tail.after_2484F` neni v logu nic" - v tom useku
proste zadny jiny kontrolni bod NENI, takze z toho nic neplyne.
`sub_2484F` do hudebni vetve vstupuje.

**Kde tedy hudba mizi - dalsi krok:** druha podminka uvnitr
`if ( word_180EB4 != 1 && word_180EB4 != 2 && word_180EB4 != 3 )`
(= "uz nejaka skladba hraje"), a pak samotny retez
`sub_1136EC(aStreamLbx)` -> `sub_113A20` -> `sub_113BAC` -> `sub_113AF2` ->
`sub_113CBD(30)`. Je to DIGITALNI stopa (STREAM.LBX), ne MIDI - to sedi s
tim, ze uzivatel mluvi o "zvuku". Zmerit postupne: hodnotu `word_180EB4`
pri prvnim volani a pak jestli se `sub_1136EC`/`sub_113CBD` skutecne
provedou az do konce.

### Vlna 26 pokracovani 45: hudba se SPOUSTI (zmereno), zbyva zjistit proc
### neni slyset; a novy pad v kopii spinavych pruhu

**Zmereno uvnitr `sub_2484F`** (kontrolni body zustavaji v kodu, jsou
gatovane `REORION2_TRACE`):
```
hudba.2484F_vstup       -1   <- word_180EB4 pri prvnim volani (podminka projde)
hudba.2484F_spousti      1   <- vetev spousteni hudby SE PROVEDE
hudba.2484F_pred_113CBD  1   <- vybrana skladba 1, dojde az k sub_113CBD(30)
```
Cely retez `sub_1136EC(aStreamLbx)` -> `sub_113A20` -> `sub_113BAC` ->
`sub_113AF2` -> `sub_113CBD(30)` se tedy PROVEDE. Hudba presto neni slyset,
takze problem lezi az ZA nim - ve streamovani STREAM.LBX do zvukoveho
vystupu (digitalni stopa, stejna cesta jako zvuk videa: `Port::Sound`).
**Dalsi krok:** overit, jestli se do `PortSound_FeedStream` (nebo do mixeru
hry) z teto cesty vubec neco dostane - stejnym zpusobem, jakym se ve vlne 26
ladil zvuk videa (`REORION2_AUDIO_STATS=1`: prumer 128 = ticho).

**Novy pad (nesouvisi s hudbou, je na kreslici ceste):**
```
SEH 0xC0000005 av_read = 0x0000000_1_184F19A0
  #0 memmove  #1 qmemcpy  #2 sub_1276BD  #3 sub_125D4F  #4 sub_124ECB
  #5 sub_1077D  #6 sub_8F1C4  #7 sub_816F2
```
Horni pulka padove adresy je **1**, dolni (0x184F19A0) je platny 32bitovy
ukazatel - podle katalogu ("diagnosticky trik na horni pulku adresy") jde o
`*(TYPE **)(x + N)`, ktere na x64 nacetlo 8 B misto 4 a prilepilo sousedni
pole s hodnotou 1. Hledat v `sub_1276BD` / `sub_125D4F` (kopie spinavych
pruhu do obrazu). Je to pravdepodobne TENTYZ koren jako "obcas se
neprekresli pozadi" - obe veci sedi na stejnou kreslici cestu pres
`sub_124ECB`.

### Vlna 26 pokracovani 46: HUDBA MENU - retez opraven az k obsluze; ctyri
### opravy overene proti asm

**Metoda:** dosbox trace (`DUMPREGS cond=eip:` na `sub_2484F`, `sub_1136EC`,
`sub_113A20`, `sub_113AF2`, `sub_113CBD`) ukazal, ze ORIGINAL projde presne
toutez sekvenci jako port - rozdil tedy musel byt UVNITR. Pulenim
kontrolnich bodu v `sub_113765` vypadlo `hudba.113765_slot = 0`.

**1) `sub_125D4F` (kopie spinavych pruhu) - PAD i ROZBITE POZADI.**
Port volal `sub_1694B7`, ktere pri prekroceni rozsahu srazi offset na 0,
takze se pruh zkopiroval na ZACATEK obrazu. V asm zadne orezavani neni a
cil se pocita stejnym vyrazem jako zdroj (viz komentar u kodu). Byla to
ZATKA z vlny 24 s poznamkou "root cause not found" - a sama vyrobila druhy,
hur dohledatelny projev. **Ponauceni: u kazde takove zatky precist asm CELE
funkce, ne jen okoli padu.**

**2) `unk_1AD854` - 1 bajt misto 2048.** `sub_113765` do nej cte
`fread(&unk_1AD854, 2048, 1, ...)`. Velikost overena vzdalenosti k dalsimu
symbolu (`0x1AE054 - 0x1AD854 = 0x800`). Kazde spusteni hudby prepsalo 2047
bajtu sousednich globalu - stejna trida chyby jako DTA `unk_1AD828`.

**3) `sub_111AE2` - ztracena navratova hodnota (PRIMA pricina chybejici
hudby).**
```c
sub_1413FF(dword_1B0670[i]);   // asm: call sub_1413FF / cmp eax, 2
if ( v0 == 2 ) return i;       // v0 se NIKDE neprirazuje
```
Hledani volneho slotu vracelo 0 -> `sub_113765` skoncila hned na zacatku.
Zmereno: `hudba.113765_slot` 0 -> 1.

**4) `sub_113765` - druha ztracena navratova hodnota.** `sub_14197D`
(velikost bufferu) se zahazovala a nasobilo se neinicializovane `v2`.
asm: `call sub_14197D / add esp,0Ch / mov edx,[var_68] / imul edx, eax`.

**VYSLEDEK (zmereno):** cely retez uz probehne az do konce -
`hudba.113765_hledani 1` (STREAM.LBX nalezen), `_jmeno0 83` ('S'),
`_hotovo_handle` platny, a hlidka obsluhy hlasi `hudba.obsluha_437_42B
0x10001`, tedy **oba priznaky (`dword_184437`, `dword_18442B`) jsou
nastavene a streamovaci obsluha bezi**.

**ZBYVA (dalsi krok, uz je to vec PORT VRSTVY, ne dekompilatu):** SDL
zvukove zarizeni se otevira LINE az uvnitr `Port::Sound::FeedStream`
(port_sound.cpp), tedy az kdyz PCM tlaci cesta VIDEA. Pri behu se
`REORION2_SKIPINTRO=1` a hudbou v menu se `FeedStream` nezavola a v logu
chybi radek "Port::Sound: audio zarizeni otevreno" - zmereno. Je tedy treba
napojit vystup HERNIHO MIXERU (cesta `PortSound_ServiceTimer` ->
`dword_1BB90C`/mix buffer, stejna, jakou uz pouziva zvuk videa pres
`REORION2_AUDIO_SRC=mix`) i pro pripad, kdy zadne video nebezi.

### Vlna 26 pokracovani 47: tep casovace i mimo video + dalsi dve ztracene
### navratove hodnoty v obsluze streamu

**1) Tep emulovaneho AIL casovace visel jen na `PortVga_BlitBackBuffer`,**
ktere se vola POUZE pri prehravani videa. V menu se tedy herni mixer vubec
neroztocil. Doplneno volani `PortSound_ServiceTimer()` i do
`Port::Vga::Present()` (stejna uvaha jako u emulovaneho preruseni myshi -
Present je jedina spolehlive periodicka cesta portu, ~130x/s). Funkce si
sama hlida svuj interval i to, jestli je casovac zapnuty.

**2) `sub_1131F0`/obsluha streamu - dalsi dve ztracene navratove hodnoty:**
```c
sub_1413FF(dword_18442B);            // stav samplu
v11 = v2 == 2;                       // v2 NEINICIALIZOVANE
sub_141A76((_DWORD *)dword_18442B);  // index hotoveho bufferu
v10 = v3;                            // v3 NEINICIALIZOVANE
```
asm: `call sub_141A76 / add esp,4 / mov [ebp+var_8], eax /
cmp [ebp+var_8], 0FFFFFFFFh`. Obsluha skakala do nahodne vetve - zmereno,
ze po rozjeti hudby menu skoncila na fatalnim `sub_126487(aAilError, ...)`.
Po oprave uz "AIL error" v logu NENI a hra bezi dal.

**ZBYVA:** v logu z menu porad chybi radek "Port::Sound: audio zarizeni
otevreno", tedy SDL zarizeni se stale neotevre - vystup mixeru se do nej
nedostane. Dalsi krok: projit cestu `PortSound_ServiceTimer` ->
`sub_156680` -> `sub_162201` -> odeslani pul-bufferu a zjistit, ve kterem
kroku se to zastavi (stejnym pulenim kontrolnich bodu, jake dnes fungovalo
u `sub_113765`).

### Vlna 26 pokracovani 48: POZOR - hra po PLNEM REBUILDU hned skonci

**Stav ke konci sezeni: `-t:Rebuild` build je funkcni co do prekladu, ale
hra se po startu ukonci** (v logu jen dve radky, posledni
`PortSound_CreateDigDriver: ...`; zadny SEH, zadne "AIL error" - vypada to
na `sub_126487` = fatalni hlaska, ktera nekonci pres SEH).

**Jak se to stalo:** posledni buildy behem ladeni hudby byly INKREMENTALNI a
- presne jak varuje kapitola "JAK PRACOVAT S PORTEM" - zjevne NErelinkovaly.
Diagnostika pridana do `PortSound_ServiceTimer` se v logu neobjevila vubec,
i kdyz volani v `Present()` prokazatelne bylo. Teprve `-t:Rebuild` zmeny
skutecne zapojil a hra zacala koncit.

**Co je od posledniho ZNAME funkcniho plneho rebuildu (build36) zmeneno -
kandidati na bisekci, kazdy je nezavisly:**
1. `sub_125D4F` - zruseno orezavani pres `sub_1694B7` (cil = zdroj, dle asm)
2. `unk_1AD854` - 1 B -> 2048 B (ZMENA ROZLOZENI GLOBALU!)
3. `sub_111AE2` - `v0/v1 = sub_1413FF(...)`
4. `sub_113765` - `v2 = sub_14197D(...)`
5. `sub_1131F0`/obsluha streamu - `v2 = sub_1413FF(...)`, `v3 = sub_141A76(...)`
6. tep `PortSound_ServiceTimer()` v `Present()` - UZ ZAKOMENTOVAN (nepomohlo)

**Nejpravdepodobnejsi:** (2) meni rozlozeni globalu a v tomhle kodu uz
nekolikrat neco zaviselo na sousedstvi; nebo se hudba konecne rozjede a
spadne az v ni (kandidat 3-5) do `sub_126487`.

**PRVNI KROK PRISTE:** vzit build36 (nebo revertovat 1-5), overit plnym
rebuildem, ze hra bezi, a pak pridavat po jedne s `-t:Rebuild`. A DUSLEDNE
prekladat `-t:Rebuild` - dnesni mereni z inkrementalnich buildu mezi
build37 a build46 muze byt neplatne.

**Upresneni k pokr. 48 (zmereno):** ukonceni NENI `sub_126487`. Do te funkce
byl doplnen vypis "FATAL: <hlaska>" (stdout + `fflush(0)`; POZOR: `stderr`
neni v hernich .c deklarovane, decomp_compat.h zamerne nevklada <stdio.h>) -
a v logu se NEOBJEVI. Proces konci s **navratovym kodem 3**, coz je typicky
CRT `abort()` (debug assert / kontrola haldy), ne `exit(1)`.
Hledat tedy poruseni haldy nebo debug-assert, ne herni fatalni hlasku.
Prvni podezreli zustavaji zmeny 2-5 z predchoziho seznamu - zvlast (4)
`v2 = sub_14197D(...)`, protoze nove urcuje VELIKOSTI obou `nmalloc`
bufferu (`dword_184433`), do kterych se pak kopiruje audio.

### Vlna 26 pokracovani 49: BISEKCE HOTOVA - pad je uvnitr hudebni cesty,
### ostatni opravy jsou v poradku

Plnym rebuildem po jedne zmene (kazdy krok `-t:Rebuild`):
- pripnuti `v2 = 2048` v `sub_113765` (kandidat 4) ... **hra porad konci**
- navrat `sub_111AE2` na `return 0` (kandidat 3) ... **hra BEZI**

**Zaver:** zmeny 1, 2, 4, 5 jsou v poradku. Oprava (3) je podle asm SPRAVNA
(`call sub_1413FF / cmp eax, 2`), ale nove zpristupnuje hudebni cestu, ve
ktere je JESTE DALSI, doted maskovana chyba - proces konci s navratovym
kodem **3 = CRT abort** (ne `sub_126487`, ten by vypsal "FATAL:", a ne SEH).

**Reseni pro tuto chvili:** oprava zustava v kodu, ale hudebni cesta je za
prepinacem, aby build zustal pouzitelny:
```
REORION2_MUSIC=1   zapne hledani volneho slotu (a tim hudbu menu)
```
Bez nej se `sub_111AE2` chova jako driv (vraci 0) a hra bezi normalne -
overeno plnym rebuildem.

**DALSI KROK:** spustit s `REORION2_MUSIC=1` a najit, kde presne to
abortuje. Abort bez vypisu = debug CRT (poruseni haldy / assert), takze
prvni podezreni je zapis pres konec nektereho z bufferu hudebni cesty:
`dword_1AE0A4[0]` a `dword_1AE0A8` (obe `nmalloc(dword_184433)`),
`unk_1AD854` (uz opraveno na 2048 B) a `dword_1B06B4[dword_184447]` v
`sub_113CBD` - tam se indexuje polem o 17 prvcich hodnotou, ktera se nikde
nekontroluje (a soused `dword_1B06F8`/`dword_1B06FC` uz dnes jednou obeti
prepisu byl).

**Upresneni k pokr. 49 (zmereno):** podezreni na prekroceni pole
`dword_1B06B4[17]` v `sub_113CBD` je VYVRACENE - index je 1, tedy v rozsahu.
Cela pripravna cast hudby probehne (`hudba.113765_hotovo_handle` platny,
`hudba.obsluha_437_42B 0x10001`, `hudba.2484F_pred_113CBD 1`) a posledni
vypis pred abortem je uz `tail.after_2484F`. **Abort tedy nastava AZ ZA
spustenim hudby, v prubehu streamovaci obsluhy** (`sub_1131F0` / cesta
`sub_141A76` -> kopie do `dword_1AE0A4[0]`/`dword_1AE0A8` o velikosti
`dword_184433`). Tam hledat dal - napr. porovnat `dword_184433` a delku
kopirovanych dat s originalem pres `DUMPREGS cond=changed:`.

### Vlna 26 pokracovani 50: pul-buffery audio streamu byly JEDNO pole, ne
### pole + promenna; tichy abort je pryc, pad se posunul do mixeru

**Nalezeno:** `sub_1131F0` indexuje `dword_1AE0A4[v3]` / `[v10]`, kde v3/v10
je index pul-bufferu (0/1) vraceny z `sub_141A76`. V originale je to tedy
JEDNO DVOUPRVKOVE pole na 0x1AE0A4 (prvek [1] = 0x1AE0A8). Port mel pole o
JEDNOM prvku plus samostatnou promennou `dword_1AE0A8`, takze
`dword_1AE0A4[1]` sahalo MIMO pole a `fread` cetl do smeti -> poruseni haldy
a tichy `abort()` (kod 3). Poznamka z vlny 12 to u te promenne primo
predpovidala ("pouziva se i s indexem [v3]/[v10] ... presna sirka se doresi
az se zvukovou vlnou").
Opraveno na `int dword_1AE0A4[2]` + `#define dword_1AE0A8 dword_1AE0A4[1]`.

**Druha chyba na stejnem miste:** `sub_113475` zamenila POLE za UKAZATEL -
`memset(dword_1AE0A4, 0, ...)` a `fread(dword_1AE0A4, 1, 44, ...)` zapisovaly
do pameti, kde lezi samo pole, misto do bufferu, na ktery ukazuje prvek [0].
Sesterska `sub_113765` to ma spravne - podle ni opraveno.

**VYSLEDEK (zmereno):** tichy abort je PRYC, log z 6 radku na 145 - hudebni
cesta bezi mnohem dal. Pad se posunul do MIXERU:
```
SEH 0xC0000005 av_read = 0xFFFFFFFF80000008
  #0 sub_161C45+0x74   #1 sub_162000+0x4ca   #2 sub_156680+0x1cd
  #3 PortSound_ServiceTimer  #4 PortVga_BlitBackBuffer  #5 sub_125814
```
Tedy emulovany AIL casovac uz skutecne MIXUJE hudebni sample a mixovaci
rutina cte z neplatneho ukazatele `0x80000008` (sign-extended, nastaveny
horni bit - typicky "int -> pointer" ze zaporne hodnoty).
**Dalsi krok:** najit, odkud se do samplu dostane `0x80000008` - podezreni na
`sub_141B5B((int *)dword_18442B, v10, dword_1AE0A4[v10], v9)` (zarazeni
pul-bufferu do fronty) a na hodnoty, ktere mixer cte ze struktury samplu.

**Upresneni k pokr. 50 (zmereno):** zarazovani pul-bufferu do samplu je
V PORADKU - `hudba.zarad_index` 0 a 1, `hudba.zarad_buffer` 406713088 a
406745920 (dva platne ukazatele presne 32768 B od sebe),
`hudba.zarad_delka` 32768. Chyba tedy NENI na strane `sub_141B5B`/
`sub_157B00`, ale az v MIXERU.

Voditko: `sub_157B00` uklada ukazatel na pul-buffer do `a1[a2 + 2]`, tedy na
BAJTOVY OFFSET 8 struktury samplu - a padova adresa je `0x80000008`, tedy
"zaklad 0x80000000 + 8". Mixer si tedy jako zaklad samplu vzal hodnotu s
nastavenym hornim bitem (0x80000000). Hledat, odkud ji bere - pravdepodobne
priznakove pole/marker, ktery se v portu dostal tam, kde ma byt ukazatel
(fake DIG_DRIVER dava samplum na +0 zpetny ukazatel a na +4 stav; viz
PortSound_CreateDigDriver).

### Vlna 26 pokracovani 51: HUDBA MENU HRAJE - registrova konvence mixeru,
### chybejici seek na skladbu v STREAM.LBX a tempo tepu podle fronty

Vychozi stav: s `REORION2_MUSIC=1` padal mixer na ukazateli `0x80000008`
(pokr. 50). Vsechny tri chyby nize jsou zmerene, ne odhadnute.

**1) `funcs_16213C` - VLASTNI (registrova) konvence, 72 rutin naraz.**
Pad byl presne to, pred cim varoval komentar z pokr. 15. Volajici
`sub_162000` (loc_16211D) plni pred `call ds:funcs_16213C[ebp*4]` sest
registru:
```
mov     esi, dword_182D2C   ; ESI = zdroj
lea     edx, [ecx+48h]      ; EDX = &sample+0x48 = tabulka hlasitosti
mov     eax, 0              ; EAX = akumulator L
mov     ebx, 0              ; EBX = akumulator R
mov     ecx, 80000000h      ; ECX = faze pro prevzorkovani
                            ; EDI = cil (mix buffer)
```
Port ale volal jen s peti argumenty ve tvaru varianty `sub_16177F` (ta ECX
pouziva, EDX ne) - tedy tvaru, na kterem se ladil zvuk videa. U kazde jine
varianty sedly argumenty o jedno vedle. U hudby menu vysel index tabulky
0x43 = `sub_161C45` (ta ma EDX misto ECX), takze se do EDX dostala faze
`0x80000000` a rutina cetla `*(0x80000000 + 4*vzorek)` -> pad na
`0x80000008`.

IDA kazde rutine dala JEN ty parametry, ktere odpovidaji registrum, jez
prave ona pouziva (`__usercall f@<al>(int@<eax>, int@<edx>, ...)`), takze
kazda ma jinou aritu - a volani je pritom pro celou tabulku jedno. Vsech
**72 rutin** proto dostalo JEDNOTNY tvar parametru v poradi registru
**EAX, EDX, ECX, EBX, EDI, ESI** (nepouzite maji jmeno `mix_<reg>`), a
kazda na konci uklada posunuty zdroj/cil do `g_mixSrcAfter`/`g_mixDstAfter`
(v originale se vraceji v ESI/EDI - asm hned za `call` dela `mov eax, esi`).
Overeno, ze registrove seznamy vsech 72 jsou podmnozinou toho poradi.
Potvrzeni rozsahu tabulky hlasitosti: `0x48 + 2048 = 2120`, a `+2120` uz je
callback volany o par radek vys v teze funkci.

**2) `sub_113765` - DECOMP_TODO fseek z vlny 07 byl skutecna chyba.**
Zastupny `fseek(f, 0, SEEK_CUR)` (no-op) mel byt seek na offset SKLADBY:
```
mov     eax, [ebp+var_10]       ; cislo skladby
shl     eax, 2
mov     edx, dword_1A585C[eax]  ; 0x1A585C = unk_1A5854 + 8 -> offsety LBX
xor     ebx, ebx                ; SEEK_SET
call    fseek_
```
**Zmereno primo na datech** (STREAM.LBX, 29 231 344 B): 11 zaznamu, na
offsetu 2048 lezi zaznam 0 se znackou `cats` a na +40 hodnota **65536**;
skladba 1, kterou hra vybira, zacina na 2070 hlavickou `RIFF` s delkou
**5 011 968 B** (~113 s). Port tedy cetl vzdy od 2048, stream skoncil po
dvou pul-bufferech (2x 32768 B) a rozjel se znovu - v logu 4x
`hudba.113765_skladba` za 20 s. Po oprave 1x.
Pri teze prilezitosti: `sub_113475` mela STEJNOU ztracenou navratovou
hodnotu jako `sub_113765` z pokr. 46 (`call sub_14197D / shl eax, 5`).

**3) Tempo tepu - podle FRONTY zarizeni, ne podle hodin.**
Tep v `Present()` byl ve vlne 48 zakomentovan (podezreni z padu); bisekce
ve vlne 49 ale ukazala, ze pad byl v hudebni ceste. Po opravach 1+2 je zase
zapnuty. **Zmereno bez nej:** za 25 s behu jen ~121 davek po 2048 B = 5,6 s
zvuku (tep budil jen `PortSound_QueuedBytes` z hernich cekacich smycek,
~5-8x/s misto 21,7x/s) - to bylo to hlavni trhani.
Druha polovina: `PortSound_ServiceTimer` merila interval hodinami
(`if (now - s_lastFlip < halfMs) return; s_lastFlip = now;`). To zahazuje
kazde zpozdeni Presentu (diera ve fronte = prasknuti) a `halfMs` vychazelo
cele cislo 46 ms proti skutecnym 46,44 ms. Prepsano na tempo podle hloubky
SDL fronty (cilova zasoba `4 * driver+68` = 8192 B ~ 186 ms, strop 8 flipu
na volani) - v DOSu davalo tempo taky zarizeni (preruseni DMA po dohrani
poloviny bufferu), takze je to i vernejsi.
**Zmereno po oprave:** 520+ davek za 25 s = realny cas.

**STAV (potvrdil uzivatel poslechem):** hudba menu HRAJE, bez trhani,
zbyva jen drobny sum - zatim nevime, jestli ho nema i original; chce to
porovnat s dosboxem na datove urovni.
**Regresni test videa: `compare_frames` 600/600 matched, 0 diverged.**

**ZBYVA:** (a) po SPACE neni videt animace otevirajiciho se menu;
(b) po kliknuti na QUIT hra zamrzne; (c) datove porovnani zvuku menu
s dosboxem kvuli tomu sumu.

### Vlna 26 pokracovani 52: animace otevirajiciho se menu + QUIT uz nemrzne
### (obojí byla nedokoncena rekonstrukce control-flow, ne "chyba v logice")

**1) `sub_81395` mela PRAZDNE telo - proto po SPACE nebyla videt animace
otevirajiciho se menu.**
IDA z ni nechala jedinou radku `JUMPOUT(0x81389)`. V asm je to pritom
plnohodnotne dvojce `sub_81381` - obe skoci do stejneho spolecneho ocasu a
lisi se JEN zdrojovym obrazkem v EBX:
```
sub_81395:  push ebx / push edx / mov ebx, dword_194088 / jmp short loc_81389
sub_81381:  push ebx / push edx / mov ebx, dword_19408C
loc_81389:  xor edx, edx / xor eax, eax / call sub_12A478 / pop edx / pop ebx / retn
```
(datove symboly v asm dumpu jsou o -0x8000: `dword_194088` = C
`dword_19C088` = prave nactena MAINMENU.LBX ze zacatku `sub_816F2`.)
`sub_816F2` tuhle funkci predava jako KRESLICI CALLBACK do `sub_8F1C4`, a to
v jedine vetvi `if (byte_19A005)`, tedy pri PRVNIM vstupu do hlavniho menu.
`sub_8F1C4` kolem toho volani dela roztmivani palety - roztmivalo se tedy do
prazdna. Doplneno `sub_12A478(0, 0, dword_19C088)`.
(Pozn.: `byte_19A005` je tataz promenna, kterou ve vlne 24 prepisoval pretok
`unk_1A1370` - tehdejsi priznak "hlavni menu preskocilo svuj one-time init"
byl tenhle stejny kus kodu, jen z druhe strany.)

**2) `JUMPOUT(0x810C0)` uprostred smycky menu = ZAMRZNUTI PO QUIT.**
`JUMPOUT` je v `decomp_compat.h` **no-op stub**. V `sub_816F2` ale stoji
uprostred `while (1)`:
```c
if ( (_WORD)v17 ) { word_19994C = 0; byte_19C1A0 = 1; sub_119281();
                    JUMPOUT(0x810C0); }   /* <- nic neudela -> smycka bezi dal */
```
`locret_810C0` neni cizi kod: je to **SDILENY EPILOG funkce `sub_80DB4`**
(`leave / pop edi / pop esi / pop edx / pop ecx / pop ebx / retn`). Watcom ho
sdili mezi funkcemi se shodnym prologem - `sub_816F2` ma presne stejny
(`push ebx/ecx/edx/esi/edi` + `enter 4,0`) a jeji POSLEDNI instrukce je
`81AB9: jmp locret_810C0`. Skok tam tedy znamena proste **`return`**.
Opraveno; ve stejnem souboru je tentyz vzor jeste 4x (`0x810C0` 3x,
`0x810C1` 1x - ten je o instrukci dal, bez `leave`, protoze `sub_81ABE` nema
`enter`), tam ale stal az na konci tela, takze se no-op stub choval spravne.
Vsech 5 mist je ted vyslovne `return` s komentarem.

**Pravidlo (nova polozka do katalogu): `JUMPOUT(adr)` na adresu, ktera lezi
v CIZI funkci tesne pred jejim `retn`, je skoro vzdy Watcomuv SDILENY
EPILOG, tedy `return`. Poznas ho podle toho, ze cilova adresa ma v asm
navesti `locret_*` a ze prolog obou funkci je totozny. Protoze je JUMPOUT
no-op, projevi se to jen tam, kde nestoji na konci tela - a tam pak jako
zamrznuti.**

**OVERENO MERENIM:** kliknuti na QUIT (v okne na hernich souradnicich
~(490,295); polozky menu jsou x 415..567, y 172/195/217/240/262/285 - viz
`sub_813A4`) ted hru korektne ukonci: v logu
`Thanks for playing Master of Orion ][` a proces skonci. Drive se v tomhle
miste tocila smycka donekonecna.
Animaci menu je potreba overit okem (mereni na ni v portu neni).

**Pozn. k diagnostice:** vypis `FATAL: <hlaska>` doplneny do `sub_126487` ve
vlne 48 se objevi i pri NORMALNIM ukonceni hry ("Thanks for playing") - ta
funkce je zaroven bezny konec programu, ne jen fatalni chyba. Neni to
priznak problemu.

### Vlna 26 pokracovani 53: ANIMACE OTEVIRAJICIHO SE MENU - nalezena
### porovnanim s dosboxem; + novy nastroj SENDKEY v dosbox-x

Priznak (uzivatel): v originale po SPACE skonci animace s lodemi a spusti se
animace otevirajiciho se menu; v portu se menu objevi rovnou otevrene.
Uzivatelova hypoteza "engine reaguje na klavesu dvakrat" NEPLATI - vyvraceno
uz merenim ve vlne 44 (1x vlozeno / 1x ohlaseno / 1x precteno).

#### Novy nastroj: `SENDKEY` v dosbox-x (src/engine/engine.cpp)

Bez nej se automatizovany beh k tomuhle useku vubec nedostal (trace zustal
prazdny) - hra ceka na vstup hrace. Format:

    SENDKEY cond=cycle_ge:N key=space [hold=200000] [label=x]
    SENDKEY cond=eip:0xADDR    key=q     ...

Stiskne a po `hold` cyklech pusti klavesu pres `KEYBOARD_AddKey`, tedy pres
skutecny radic klavesnice (hra to vidi jako normalni scancode vcetne sve
ISR). Kazdy watch se spusti jen jednou. Klavesy jsou v `ctl_parse_key`.

#### Kde animace je

`sub_80DB4` (z `sub_816F2`, vetev `if (byte_19A005)` = PRVNI vstup do menu)
NENI dialog, ale PREHRAVAC ANIMACE: otevre zaznam 0 z MAINMENU.LBX
(`sub_12C607`), vezme z hlavicky pocet snimku
(`v20 = *(_WORD *)(dword_1B06FC + 6) - 1`) a ve smycce dekoduje snimek po
snimku (`sub_12C7CC`), se zvukem na snimcich 5 a 46 (`sub_147D7(53)` / `(54)`).
Konci dobehnutim snimku, nebo kdyz uzivatel klikne/zmackne klavesu.

**Zmereno (DUMPREGS cond=eip:0x002A4FA5 repeat=always = loc_80FA5):**

| | original | port pred | port po |
|---|---|---|---|
| pruchodu smyckou | 51 | **1** | 50 |
| pocet snimku (dolni slovo v20) | 49 | 49 | 49 |

(51 vs 50 neni rozdil - dosbox loguje i posledni pruchod hlavou smycky, kde
se z ni vyskakuje, port pocita az telo.)

#### Skutecna pricina: `sub_11CEF5` - dalsi "jen dolni pulka registru"

Zuzovano merenim: v portu `word_1B921A`=0 (zadne tlacitko),
`word_1B9228`/`word_1B9220`=0 (zadny zatrzeny klik), `sub_12C392()`=0
(zadna klavesa), `sub_124075()`=0, `word_1B3E0E`=9 oken - UPLNE STEJNE jako
v originale (`DUMPMEM addr=0x003C9E0A size=16`). A presto vratila 8.

```c
LOWORD(v18) = sub_123C48();   /* v18 je NEINICIALIZOVANY lokal */
if ( !v18 )                   /* -> skoro nikdy neplatilo */
```

V asm `sub_123C48` plni JEN AX (`mov ax, word_1B1228`), horni pulka EAX
prezije z predchoziho `call sub_124075`, a volajici testuje `test eax, eax`
(celych 32 bitu). Dekompilat z toho udelal prirazeni do dolni pulky
neinicializovaneho LOKALU, jehoz horni bity jsou nahodne smeti. Podminka
"nikdo neklikl" proto skoro nikdy neplatila, hra sla hledat okno pod
kurzorem - a celoobrazovkova oblast sedne vzdy.
**Overeno v originale** (`DUMPREGS cond=eip:0x00341B69` = presne to
`test eax, eax`): EAX je tam ve VSECH 33 zaznamech `0x00000000`.
Opraveno na `v18 = (uint16_t)sub_123C48();`; stejny vzor i v
`orion_part_18.c` (`sub_124075() || (LOWORD(v5) = sub_123C48(), v5)`).
Tataz trida jako `sub_12C392` ve vlne 43 - hledat dal:
`LOWORD(x) = f();` nad lokalem, ktery se pak testuje jako 32bitovy.

#### Co tim padlo

Klikani v menu drive "fungovalo" PRAVE DIKY teto chybe - jakakoli pozice
kurzoru se brala jako klik. Zaver vlny 43 i automaticky test QUITu z vlny 52
tedy prochazely pres chybu, ne pres skutecny klik. Uzivatel po oprave
potvrdil, ze animace i klikani funguji.

Pozn. k testovani: synteticky klik (`SetCursorPos` + `mouse_event`) se do hry
NEDOSTANE - s `REORION2_MOUSE_TRACE=1` nejsou v logu zadne radky
`INT33 callback`, jen registrace rutiny; SDL takto ovladanemu oknu nedava
vstupni fokus. Klikani se musi overit rukou.
Zmereno take: hra masku obsluhy stridave prepina mezi `0x0001` (jen pohyb) a
`0x002B` (pohyb + tlacitka) pres INT33x fn 0x14.

#### Metodicka poznamka (stalo to jeden soubor)

Skript upravujici `orion_part_07.c` spadl na `UnicodeEncodeError` pri zapisu
(do latin-1 textu se dostal cesky znak) UZ PO OTEVRENI SOUBORU PRO ZAPIS -
soubor tim zustal NULOVY. **Pri davkove uprave zdrojaku: psat obsah jen v
ASCII, nebo zapisovat pres docasny soubor a prejmenovat.** Obnoveno pres
`git show HEAD:<cesta> > <cesta>` + prevod na CRLF (`git show` dava LF).

### Vlna 26 pokracovani 54: hudba zapnuta ve vychozim stavu + ZVUKY
### animace menu (dve chyby, obe merene)

**1) Zatka `REORION2_MUSIC=1` zrusena.** Byla z vlny 49, kdy hudebni cesta
jeste padala. Obe pricine jsou opravene a overene (pokr. 50 - dvouprvkove
pole pul-bufferu `dword_1AE0A4`; pokr. 51 - registrova konvence 72 rutin
`funcs_16213C`). Hudba je proto ZAPNUTA VE VYCHOZIM STAVU jako v originale,
`REORION2_MUSIC=0` ji vypne. **Pozor: ten prepinac gatoval `sub_111AE2`
(hledani volneho slotu samplu), takze s `=0` nehraji ani ZVUKOVE EFEKTY.**

**2) Zvuky pri otevirani menu nehraly - DVE nezavisle chyby v `sub_112399`.**

(a) **`unk_1AE5D4` a `word_1AE5D4` jsou V ORIGINALE TENTYZ SYMBOL**, ale
v portu z toho vznikly dva ruzne objekty: `word_1AE5D4[2086]` (= 4172 B, do
nej se pres `sub_13AD33` nacita SOUND.LBX) a ctyrbajtovy stub `unk_1AE5D4`
v link_stubs.c. Vyhledani zvuku slo PRES TEN STUB
(`sub_13AFD2(&unk_1AE5D4, id)` = `*(_DWORD *)(base + 8*id + 16)`), takze
vracelo 0 a nehralo nic; `sub_13AE74(&unk_1AE5D4)` navic delal
`memset(base, 0, 4172)`, tedy prepisoval 4168 bajtu sousednich globalu.
Velikost potvrzena dvakrat: tim memsetem a vzdalenosti k dalsimu symbolu
(`0x1AF620 - 0x1AE5D4 = 0x104C = 4172`). Sesterska tabulka `unk_1AF620` uz
takhle opravena BYLA (vlna 12) - na tuhle se zapomnelo.
Reseno prekryvovym makrem `#define unk_1AE5D4 (*(uint8_t *)word_1AE5D4)`.
**Pravidlo: kdyz ma IDA na tomtez miste dve jmena (`unk_X` a `word_X`),
musi v portu ukazovat na TENTYZ objekt - jinak jedna cesta pise a druha
cte prazdno.**

(b) **Ztracena navratova hodnota `sub_140E69`** v teze funkci:
```c
sub_140E69((_DWORD *)dword_1B0670[v7], v6, -1);
if ( !v2 )   /* v2 se NIKDE neprirazuje */
```
asm (0x1125FB): `call sub_140E69 / add esp,0Ch / test eax,eax / jnz ...`.
Nahodne se tedy vracelo 0 JESTE PRED `sub_141073` (skutecne spusteni
prehravani). Cesta pres cache (LABEL_21) tuhle kontrolu nema - proto uz
jednou nacteny zvuk hral.

**Zmereno po opravach:** `zvuk.112399_spusteno 53` i `54` (pred opravou
`zvuk.112399_13AFD2_nenasel`). Uzivatel potvrdil poslechem.
**Regresni test videa po zmene rozlozeni globalu: 600/600 matched.**

Nove trvale kontrolni body (gatovane `REORION2_TRACE=1`):
`anim.iterace`, `anim.snimek_12D70B`, `zvuk.112399_*`.

### Vlna 26 pokracovani 55: ROLUJICI TITULKY V MENU - tri chyby opraveny,
### ctvrta (vykresleni glyfu) zustava otevrena

Priznak (uzivatel): v menu se nerolovaly titulky. Postupne meneno a opravovano;
po kazdem kroku uzivatel hlasil, jak to vypada.

**1) Dolni hrana orezoveho obdelniku vychazela -1 misto 422** -> `sub_12A478`
zahazovalo KAZDY blit titulku (zmereno: `blit.orez_dolni -1`, ostatni hrany
66/179/354 spravne). V `sub_128AB6`:
```c
if ( (int16_t)a4 >= *(int *)((char *)&dword_184536 + 2) )   /* smeti */
```
asm (loc_128B09): `movsx eax, word ptr [ebp+var_4] / cmp eax, dword ptr
unk_17C538 / mov ax, word ptr unk_17C538 / dec eax`. Cilem je symbol na
0x184538 = **vyska obrazovky**, kterou port uz ma vytknutou jako
`screenHeight_184538` (vlna 11). Dekompilatoruv zapis mel sice spravnou
ADRESU, ale jen v originale, kde ty globaly lezi za sebou; v portu je
`dword_184536` samostatny objekt, takze se cetlo smeti za nim. Stejny vzor
byl o dva radky vys u prave hrany - opraveno taky.

**2) Souradnice `sub_12A478` jsou 16bitove.** V asm se `a1`/`a2` pouzivaji
VYHRADNE pres dolni slovo (`cmp ax, ...` v orezu, `movsx edx, word ptr
[ebp+var_C]` na ~30 dalsich mistech). Rolovani titulku pritom predava
```c
v0 = (422 - dword_19C078) / 14;  LOWORD(v0) = dword_19C078;  v13 = v0;
```
tedy hodnotu, ktera ma po prvnich 14 odrolovanych pixelech nenulovou horni
pulku -> `a2 > clip` a blit se zahodil. Reseno orezem `a1 = (int16_t)a1;
a2 = (int16_t)a2;` hned na zacatku funkce (ekvivalent toho `movsx` pro celou
funkci naraz). Totez doplneno v `sub_14861D`.

**3) 37x vzor "cteni pres hranici dvou globalu"** u orezovych hran:
`*(int *)((char *)&dword_1BBA4A + 2) >> 16` -> `(int16_t)dword_1BBA4E` (prava)
a `*(int *)((char *)&dword_1BBA4E + 2) >> 16` -> `(int16_t)dword_1BBA52`
(dolni). Rozlozeni orezoveho obdelniku: 0x1BBA4C leva, 0x1BBA4E prava,
0x1BBA50 horni, 0x1BBA52 dolni. Opraveno hromadne v part_18/19/20/22.
Nejvic jich je v `sub_14861D` (orezany blit sprite typu 1) - a prave tudy
titulky jdou, protoze jejich radky pretinaji hranu okna; jinde v menu se ta
vetev skoro nepouziva, proto se to projevilo az tady.

**VYSLEDEK:** titulky se rolují (pixely v okne se meni, uzivatel potvrdil
"roluje to spravne" a "barvu to ma uz dobrou").

#### CO ZUSTAVA OTEVRENE (dalsi krok)

Glyfy se do radkoveho sprite porad nevykresluji spravne - v okne je misto
textu svisla cara na jednom x. **Zmereno**: `sub_12066F` (sirka textu) vraci
`149225554` pro 11znakovy retezec a `9371651` pro tecku.
Neni to chyba `sub_12066F` - ta je verna: asm dela `mov ax, word_1ABEA6` nad
EAX, ktery jeste drzi UKAZATEL na text, takze se ke kazdemu znaku pricte i
`(ukazatel >> 16) << 16`. **Dolnich 16 bitu ale zustava spravnych**, protoze
se pricitaji nasobky 0x10000, a original tu hodnotu vsude cte jen jako WORD.
V `sub_80C8A` uz opraveno (`sub_122A6E((int16_t)v10, ...)`, asm:
`movsx eax, word ptr [ebp+var_8]`), ale samo to nestacilo.

**Kde hledat dal:** `sub_122AAB` (pres `sub_122A6E`) ma tentyz vzor
`*(int *)((char *)&dword_1B3E82 + 2) >> 16` a dal vola `sub_122D8A` (vlastni
kresleni glyfu do sprite). Celkem je v `src/game/*.c` jeste **67 vyskytu**
toho vzoru u 15 symbolu:
```
19 dword_1BC28C   10 dword_1B3E10    8 off_1845D4     8 dword_1844C2
 4 dword_1B61E4    4 dword_1B3E82    3 dword_1844C6   2 dword_1BBA46
 2 dword_1BBA28    2 dword_1B61E0    1 dword_1BBA4A   1 dword_1BBA2C
 1 dword_1B3E0A    1 dword_1845DC    1 dword_18447A
```
Pravidlo pro prevod: `*(int *)((char *)&X + 2) >> 16` je 16bitove slovo na
adrese X+2, znamenkove rozsirene - najit v portu symbol, ktery na te adrese
skutecne lezi, a pouzit ho primo.

**Regresni test videa po vsech zmenach: 600/600 matched, 0 diverged.**

#### Vlna 55 pokracovani: dalsi dve chyby na ceste kresleni textu

**4) Vodorovny kurzor glyfu se cetl pres hranici dvou globalu.**
`sub_122D8A` predava X do `sub_123070` jako
`*(int *)((char *)&dword_1B61E4 + 2) >> 16`, coz je slovo na 0x1B61E8, tedy
`dword_1B61E8` - kurzor, ktery si tataz funkce o par radek niz posouva
(`LOWORD(dword_1B61E8) = word_1B3EA6 + byte_1B3EA8[v17] + dword_1B61E8`).
Overeno v asm: `mov eax, dword_1AE1E4+2 / sar eax, 10h`. V portu jsou
`dword_1B61E0/E4/E8` tri samostatne `int`, takze se cetlo smeti -> vsechny
glyfy padaly na jedno x (v okne byla svisla cara). Opraveno 6 mist
(`+ dword_1B61E4 + 2` -> `(int16_t)dword_1B61E8`, `+ dword_1B61E0 + 2` ->
`(int16_t)dword_1B61E4`). **Po teto oprave uzivatel potvrdil spravnou sirku
a rozestupy.**

**5) Barva pixelu glyfu.** `*((_BYTE *)&dword_1B3E78 + k + 3)` je podle asm
(`mov al, byte ptr (dword_1ABE78+3)[eax]`) adresa 0x1B3E7B + k, tedy
`byte_1B3E7C[k - 1]` = osmiprvkova tabulka barev fontu uvnitr prekryvoveho
bloku `fontBlock_1B3E7C`. `dword_1B3E78` lezi TESNE PRED tim blokem a je to
samostatny globál - vyraz fungoval jen dokud je prekladac polozil vedle sebe.
Prepsano na primy pristup (2 mista: kreslic do obrazovky i do sprite).

**STAV:** titulky roluji, maji spravnou sirku, rozestupy i barvu, ale znaky
jsou porad spatne ("jsou tam znaky, ale ne ty co tam maji byt, a jakoby
posunute"). **Dalsi krok:** overit vstupni data, ne kreslic - `sub_8156B`
nacita titulky z LBX stridavymi volanimi
`sub_126C37(v12, 0, dword_192ED4, v15, 1u, 127)` (v15 se zvysuje mezi levou
a pravou polovinou radku) do `dword_19C06C` po 254 B na radek. Porovnat
obsah toho bufferu s originalem (dosbox `DUMPMEM` na odpovidajici adrese) -
kdyz sedi, hledat dal v `sub_1231B1` (tabulka offsetu glyfu `dword_1B3FA8`,
sirky `byte_1B3EA8`, preskok radku `a6`).

**Regresni test videa po vsech zmenach vlny 55: 600/600 matched.**

**6) `sub_1231B1` - vsechny souradnicove parametry jsou 16bitove.** asm cte
`a1` (var_28), `a2` (var_24), `a4` (var_2C), `a5` (arg_0, deklarovan primo
jako `word ptr`), `a6` (arg_4) i `a7` (arg_8) vzdy pres `movsx ... word ptr`.
Volajici `sub_123070` pritom `v7` (= a4) i `v9` (= a6) plni jen pres
`LOWORD(...) = 0`, takze horni pulka zustava nedefinovana. Orezany uz byly
jen `a6`/`a7` (vlna 26 pokr. 33, tehdy kvuli zamrznuti) - doplneno pro
vsechny naraz na zacatku funkce.

**STAV NA KONCI VLNY 55:** titulky roluji, maji spravnou sirku, rozestupy,
barvu i pozici - ale jednotlive GLYFY jsou porad spatne.

Co je uz OVERENE a netreba znovu zkoumat:
- **vstupni data jsou v poradku** - vypis bufferu `dword_19C06C` dal
  radek 0 = `"Game Design"` / `"Steve Barcia"`, radek 1 pravy = `"Ken Burd"`
  (zbytek radku je vypln 0xCD, tedy nealokovana cast - v poradku);
- vyber fontu je v poradku: `word_19C094` = 3, `byte_19C09A` = 124,
  `byte_19C09E` = 1 (nastavuje default vetev "CREDITS.LBX");
- sprite radku je 289x14, priznaky 1, orez okna 66/179/354/422 - vse sedi;
- **vnitrni RLE smycka `sub_1231B1` byla porovnana radek po radku s asm a
  ODPOVIDA** (vcetne toho, ze `++v12` se dela i pro orezany pixel, ale ne
  pro preskocenou serii `k > 0x80`, a ze na konci radku `++v17; v14 += v15`).

**DALSI KROK (konkretne):** porovnat s originalem STAV FONTU v okamziku
kresleni glyfu titulku. V portu uz na to instrumentace JE
(`REORION2_FONT_TRACE=1` v `sub_1231B1` vypisuje `dword_1B3E74`,
`dword_1B3FA8`, `a3`, `v17`, `a6`, `word_1B3EA0`). Na strane originalu staci
`DUMPREGS cond=eip:0x003471B1 repeat=always` (= IDA 0x1231B1 + 0x224000) -
registrove argumenty daji `a1`(eax), `a2`(edx), `a3`(bl), `a4`(ecx) - a
`DUMPMEM` na tabulku offsetu glyfu (`dword_1B3FA8` = C 0x1B3FA8 -> runtime
0x3C9FA8 + ... pozor, prepocet DAT = IDA + 0x216000) a na sirky
`byte_1B3EA8`. Kdyz se lisi `v17` (offset do fontovych dat) nebo `a6`
(kolik radku glyfu se preskakuje), je chyba tam; kdyz sedi vse, hledat v
`sub_120705`/`sub_120BB5` (nastaveni fontu) nebo v samotnych fontovych
datech `dword_1B3E74`.

**Regresni test videa po vsech zmenach vlny 55: 600/600 matched, 0 diverged.**

### Vlna 26 pokracovani 56: TITULKY OPRAVENY - `sizeof()` nad prekryvovym
### makrem; + prepinac hudby/zvuku uplne odstranen

**1) `REORION2_MUSIC` ZRUSEN (zadani uzivatele).** Gatoval `sub_111AE2`, tedy
hledani volneho slotu samplu - a tim NEJEN hudbu, ale i ZVUKOVE EFEKTY.
Puvodni kontroly hry (`byte_199BED` zvuk, `byte_199BEF` hudba,
`dword_184380`, `dword_184453`) zustavaji netknute - odstranen byl jen
portovni prepinac.

**2) ROZSYPANE GLYFY TITULKU - `sizeof()` nad prekryvovym makrem.**
Postup byl cistě meritelny a stoji za zapamatovani:

- v dosboxu `DUMPREGS cond=eip:0x003471B1 repeat=always` (vstup `sub_1231B1`:
  eax=x, edx=y, bl=znak, ecx=a4). **Glyfy titulku poznas podle `edx == 0`** -
  kresli se do radkoveho sprite vzdy na y=0. Dekodovanim `bl` vypadlo
  `"Game DesignGame Design..."`, tedy presna reference;
- v portu totez pres `REORION2_FONT_TRACE=1` (gatovano navic na
  `a2 == 0 && *a8 == 289`, tedy sprite radku titulku);
- **vsechny vstupy sedely**: x = 1/10/17/28, znaky G/a/m/e, sirky 8/6/10/6,
  a4=0, a6=0, a7=13. Take vnitrni RLE smycka `sub_1231B1` odpovida asm
  radek po radku a textovy buffer obsahuje spravna data;
- rozdil vypadl az na OFFSETU GLYFU do fontovych dat. Druhy dosbox beh
  s `DUMPREGS cond=eip:0x00347243` (hned za `mov [ebp+var_18], eax`, takze
  EAX = ten offset) dal:

  | znak | original | port |
  |---|---|---|
  | G | 12418 | 4568 |
  | a | 14049 | 6460 |
  | m | 14639 | 7268 |
  | e | 14258 | 6728 |

  Rozdily nejsou konstantni -> neni to posun baze, ale UPLNE JINA TABULKA.

**Vinik** (`sub_120BB5`, vyber fontu):
```c
memcpy(byte_1B3EA8, &byte_1B43D8[256 * a1], 256);                      /* sirky - OK */
memcpy(dword_1B3FA8, &dword_1B49D8[256 * a1], sizeof(dword_1B3FA8));   /* offsety   */
```
`dword_1B3FA8` NENI pole, ale **prekryvove makro**
`((int *)(fontBlock_1B3E7C + 300))` - `sizeof` z nej je `sizeof(int *)`,
tedy **8 bajtu na x64** misto 1024. Zkopirovaly se dva offsety a zbytek
tabulky zustal z drive vybraneho fontu. Sirky se pritom kopirovaly natvrdo
256 B, proto vychazely spravne POZICE a rozestupy, ale spatne TVARY znaku.
asm: `mov ebx, 400h` = 1024. Opraveno na konstantu.

**PRAVIDLO (nova polozka do katalogu): po vytknuti symbolu do prekryvoveho
bloku PREKONTROLOVAT vsechna `sizeof(<ten symbol>)` v kodu** - z pole se
stal ukazatel a `sizeof` tise zmeni vyznam. Prohledano cele `src/game/*.c`:
`dword_1B3FA8` byl jediny takovy pripad (ostatni `sizeof` nad makry jsou
`char` cleny struktury `stateBlock_199BDC`, kde 1 B sedi).

**Pozn. k rozsahu:** `dword_1B49D8[256*a1]` + 1024 B se do bloku vejde pro
fonty 0..5 (2908 + 6*1024 = 9052 = presne konec bloku). `word_1B43A8` je
pritom `int16_t[8]`; pro font 6/7 by se cetlo za konec pole. V originale to
bylo neskodne (za blokem nasleduje dalsi pamet), v portu je to UB - zatim
nenastalo (hra pouziva fonty 0..5), ale je to zname riziko.

**VYSLEDEK: uzivatel potvrdil - titulky v menu jsou opravene.**

**3) Hlaska pri ukonceni.** `sub_126487` neni jen chybova cesta, ale JEDINY
konec programu - stejnou funkci vola i normalni ukonceni po QUIT
("Thanks for playing Master of Orion ]["). Diagnosticky prefix z vlny 48
proto uz nehlasi "FATAL:", ale neutralni "KONEC (sub_126487):".
Odpoved na dotaz uzivatele: **FATAL ve vetvi QUIT NEBYL problem, jen
matouci popisek.**

**Regresni test videa: 600/600 matched, 0 diverged.**

### Vlna 26 pokracovani 57: ZACATEK ladeni NEW GAME (rozpracovano)

Uzivatel spustil New Game; hra pada. Debugger (VS):
```
Vyjimka 0xC0000005: Poruseni pristupu V MISTE PROVEDENI 0x0000000012B1104
  #0 reorion2.exe!0x0000000012b1104()      <- divoka adresa
  #1 sub_CC81C()            radek 5314     (orion_part_13.c)
  #2 sub_CCA1C()            radek 5493
  #3 sub_CD435(short *a1)   radek 5846
  #4 sub_1049B(...)         radek 325
  #5 GameMain_10057         radek 224
```
**Poznamka k adrese:** modul ma bazi 0x00A00000 a velikost ~4,3 MB, takze
0x12B1104 (rva 0x8B1104) lezi UZ ZA OBRAZEM - je to skutecne divoky skok,
ne jen spatna datova adresa.

Co uz je zjisteno:

- `sub_CDF5C(a1)` je jen `return dword_1A6578[a1];` - PRIME volani takhle
  divoce skocit nemuze. Bud je poskozeny zasobnik nekde v retezu
  `sub_CD435 -> sub_CCA1C -> sub_CC81C`, nebo debugger rozvinul ramec spatne.
- **`sub_CC81C` je plna zname tridy "IDA slepila 16bitovy citac indexu do
  horni pulky int64"**: `int64_t v0/v3`, `WORD2(v0) = 0`, `LODWORD(v3) = v1`,
  `WORD2(v3) = v1 + 1`, `dword_1A124C[SWORD2(v3)]`. Pro anglictinu
  (`byte_199CAE == 0`) vyjdou indexy 1/2/3 a do `dword_1A124C[4]` se vejdou,
  ALE bity 48..63 obou promennych se nikdy neinicializuji. **Tuhle funkci je
  potreba cele overit proti asm** (IDA 0xCC81C -> runtime 0x2F081C).
- **OPRAVENO uz ted:** `unk_1A12A8` byl `_UNKNOWN` (1 bajt), pritom se do nej
  na trech mistech `sprintf`uji retezce ("Piccola", "Media", "%sen").
  Vzdalenost k dalsimu symbolu `0x1A12BC - 0x1A12A8 = 20` -> `char[20]`.
  (Projevi se jen u italstiny/francouzstiny, ale je to stejna trida chyby.)
- **PRVNI PODEZRELY pro dalsi session:** `dword_1A6578` - tabulka retezcu,
  ze ktere `sub_CDF5C` cte. Ve vlne 23 se jen ZVETSILA na [812]
  ("data zatim nulova, jen velikost opravena - OTEVRENY DEFICIT"), takze
  `sub_CDF5C` nejspis vraci nuly/smeti. Overit, jestli ji neco vubec plni,
  je nejlevnejsi prvni krok.

**Dalsi krok:** (1) zkontrolovat, jestli je `dword_1A6578` naplnena;
(2) `sub_CC81C` porovnat radek po radku s asm a rozbit fuzi int64 na skutecne
registry (stejny postup jako vlna 20 u sub_14852C).
