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

## Dalsi rozumny krok (navrh pro pristi session)

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
