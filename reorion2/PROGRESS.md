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

## Dalsi rozumny krok (navrh pro pristi session)

1. Analyzovat `sub_FE8BE` poradne - projit reprezentativni vzorek z 701
   volani, zjistit skutecny ucel, pak teprve prejmenovat (vlna 02).
2. Pokracovat grafem volani z `RunGameAndExit_113D47` (hlavni smycka) a
   `ParseCommandLine_107E6` (jeho volane `sub_F4FD5`, `sub_10A0E` atd.) -
   to je prirozene pokracovani "shora dolu" od vstupniho bodu.
1. Az narazime na prvni funkci, ktera zjevne odpovida VGA/zvuku/mysi/DOS
   sluzbam, napojit ji na prislusny `port_*.cpp` a smazat puvodni primy
   pristup na porty/pamet.
