Pokracuj v reorion2 (port MOO2 do C++/SDL3), `C:\prenos\reorion2\reorion2`.

Nejdriv si prectiv `PROGRESS.md` sekci "PRIRUCKA PRO DALSI AI" a vlny 86-89k
(od rozbehnuti herni mapy az po opravu artefaktu v rohu mapy).

## Pravidla (plati beze zmeny)

* Preklad VZDY `MSBuild.exe reorion2.sln -t:Rebuild -p:Configuration=Debug -p:Platform=x64`,
  spoustet z `x64\Debug` (jsou tam i herni data).
  **NEPOUZIVAT `-m`.** Zabity paralelni build necha viset `cl.exe` /
  `MSBuild.exe` / `mspdbsrv.exe` a dalsi preklad pak hlasi
  `C1041: Nejde otevrit vc143.pdb`. Vypada to jako chyba ve zdrojich, ale neni -
  staci ty procesy ukoncit.
* ZLATE PRAVIDLO: merit, ne hadat. Overuj v `Debug/diss/Orion2.exe.asm`.
  Prevod adres: kod = IDA + 0x224000, data = IDA + 0x216000;
  asm jmeno dat = C jmeno - 0x8000. Adresa se pocita z C jmena, ne z asm jmena.
* Regresni brana `genCompare/compare_frames.exe <dosbox_frames5> <port_frames> 640 480`
  musi byt 600/600. V poslednich vlnach se na pokyn uzivatele nespoustela -
  pred commitem ji pust. Nikdy ji nepoustej, kdyz bezi dosbox.
* Dosbox VYHRADNE `C:\prenos\dosbox-x-remc2\bin\x64\Release\dosbox-x.exe`.
* Snimky dumpovat pres `REORION2_BLIT_DUMP_DIR`, ne screenshotem plochy.
* Pri davkove uprave skriptem psat jen ASCII.
* Hru mivam spustenou - proces `reorion2.exe` nezabijet, pockat nebo pozadat
  o zavreni (linker pak hlasi LNK1104).

## Testovani

`REORION2_SKIPINTRO=1 REORION2_STATE=13` nabehne rovnou na NEW GAME.
Souradnice v hernich pixelech 640x480, klik zadavej jako presun s `hold=0`
a klik o 2-3 s pozdeji (`REORION2_CLICK="x,y@ms:0;x,y@ms"`).

| obrazovka | prvek | x,y |
|---|---|---|
| NEW GAME | ACCEPT | 484,402 |
| SELECT RACE | rasy sl. 1 | 410, 113/160/207/255/302/350/398 |
| Enter Ruler Name | ACCEPT | 322,237 |
| SELECT BANNER COLOR | prvni vlajka | 135,190 |
| **Enter Home Star Name** | **ACCEPT** | **277,256** |
| spodni lista mapy | COLONIES | 48,446 |

Plna cesta az na mapu (klikani je ZAVISLE NA CASOVANI a obcas nevyjde -
kdyz se hra zasekne o obrazovku driv, posun casy o par sekund):

    484,402@8000:0;484,402@11000;410,350@15000:0;410,350@18000;
    322,237@22000:0;322,237@25000;322,237@28000;135,190@33000:0;135,190@36000

Snimky jsou 768 B palety (RGB) + 640x480 indexu; na prohlizeni si napis
kratky raw->PNG prevodnik a orezavac do scratchpadu.

## Nastroje (v tomhle poradi)

1. **Pad** -> port sam tiskne SEH se zasobnikem do stderr a **od vlny 89 i
   s cisly radku** (`sub_XXX+0xNN  (soubor.c:1234)`). Sahni po tom prvni.
2. **Zaseknuta smycka** -> `REORION2_WATCHDOG=6`. Pozastavi hlavni vlakno
   a vypise zasobnik vcetne cisel radku.
3. **`SAVE10.GAM` v `x64\Debug` = ULOZENA HRA ORIGINALU ze hvezdneho data
   3500.0 (prvni tah).** Nejlevnejsi reference, jakou tu mame - dosbox na
   porovnani dat vubec nepotrebujes. Rozvrzeni (odvozeno ze `sub_10011B`):

   | offset | obsah |
   |---|---|
   | 0 | 4 B magic + 37 B `TypeSaveSlotInfo_199699` |
   | 41 | dword_192FD8 (hvezdne datum, 0x88B8 = 35000) |
   | 605 | dword_192B18 - kolonie, 250 x 361 B |
   | 90857 | dword_1930D4 - planety, 360 x 17 B |
   | 96979 | dword_19306C - hvezdy, 72 x 113 B |
   | 109070 | dword_197F98 - hraci, 8 x 3753 B |
   | 139096 | dword_197F9C - lode, 129 B (pocet je 2 B pred tim) |

   Kontrola offsetu: na 109071 je jmeno vladce ("Tavua Preet"), na 109091
   rasa ("Alkari").
   **Galaxie je nahodna, takze neporovnavej konkretni zaznamy, ale ROZSAHY
   (min/max) jednotlivych poli** - tak se ve vlne 89i naslo, ze z 17 poli
   zaznamu planety sedi 15 a spatne jsou jen dve.
4. **Docasne mereni** -> `PortDebug_Checkpoint(jmeno, int)` /
   `PortDebug_CheckpointPtr` / `PortDebug_Symbolize(tag, _ReturnAddress())`
   (ten rovnou vypise jmeno funkce a radek). Zapina `REORION2_TRACE=1`.
   **`fprintf(stderr, ...)` primo v dekompilovanem `.c` NEFUNGUJE** -
   `decomp_compat.h` presmerovava `fflush` a spol. na `PortFile_*`.
5. `tools/csdata_scan.py` - tabulky ulozene v KODOVEM segmentu, ktere si
   funkce kopiruji `movsd`; hlasi, kde ma port objekt spatne velky.
   `tools/jumpout_scan.py` (NO-OP `JUMPOUT` vs. epilog),
   `tools/qsort_scan.py` (chybejici komparator). Vsechny znovu spust,
   cisla radku se posouvaji.
6. **Chybejici staticka data** -> `Debug/diss/Orion2.exe.lst` ma u kazdeho
   radku adresu. Z `Debug/diss/Orion2.exe` cist nejde (LE/DOS4GW, zabalene).

## Pasti, ktere me staly cas (nesahej na ne znovu)

* **Sonda s omezenym poctem vypisu**: filtruj co NEJUZEJI. Rozpocet
  `rep < 25` mi spotreboval opakovany blit ramu na (15,5) a vysledek
  vypadal jako "u rohu se nic nedeje", pritom se tam blitovalo.
* **Mazani docasne instrumentace**: vzdy presnym shodnym retezcem, NIKDY
  hledanim zaviraci zavorky - dvakrat mi to rozbilo soubor a musel jsem ho
  vracet pres `git checkout`.
* **Nedelej zavery z 3x zvetseneho vyrezu u tmaveho textu.** Precetl jsem
  "-50 BC" tam, kde bylo "50 BC" (to "minus" byl tmavy okraj sprite mince),
  a poslal jsem uzivatele hledat neexistujici chybu znamenka. Zvetsi na 10x
  a vic, nebo rovnou zmer hodnotu v kodu.

## Katalog chyb (hledej je prednostne)

* **spillnuty registrovy argument** - `enter N,0` nasledovane `push eax/edx/ebx/ecx`;
  IDA z nich udela NEINICIALIZOVANE lokalky. Poznas podle `// [esp+0h] [ebp-XXh]`
  bez prirazeni a podle poznamky `variable 'vN' is possibly undefined`.
  **Tohle byla ve vlnach 89-89k zdaleka nejcastejsi chyba.**
* **zahozena navratova hodnota** - `void` + NO-OP `JUMPOUT`, volajici testuje
  smeti; nebo `call X / mov reg, eax` a v portu `X(); v = <neinicializovane>`.
* **prazdny pahyl s `JUMPOUT`** - funkce, ktera jen skace do tela jine
  (`sub_77B42` -> `sub_77B28`, `sub_7927F` -> `loc_79279`).
* **IDA oriznuta velikost pole** - `byte_17D81C[8]`, pritom se indexuje 0..9.
* **rozsekany souvisly blok** + duplicitni skalar v `link_stubs.c`
  (ten soubor NEzahrnuje `orion_common.h`, takze se makra neuplatni).
* **sirka ukazatele** - 4bajtovy slot na x64; `int v = ptr` orizne adresu.
* **konstanta jako navesti** (`(int)&loc_1D4BC + 4` ma byt 0x1D4C0).
* **`(int (*)())(void*)sub_X` pretypovani volani** - umlci kontrolu poctu
  argumentu; zbyva pet takovych mist (viz vlna 89).
* artefakty z neprelozene oblasti `orion_part_26` (`sub_169245`, `sub_169410`) -
  over, jestli ta adresa v asm vubec existuje.

## Stav

Hra dobehne na herni mapu a **bezi bez padu**: hvezdy, mlhovina, jmena hvezd,
bocni panel, spodni lista, hvezdne datum 3500.0, dialog "Enter Home Star Name",
a po ACCEPT i obrazovka COLONIES s tabulkou.

Bocni panel uz ukazuje spravne hodnoty (overeno proti `SAVE10.GAM`):
pokladna `50 BC`, prijem `+16 BC`, nakladni lode `+5 (8)`, jidlo `+2`.
Zaznamy planet maji vsech 17 poli ve stejnem rozsahu jako original.
Pocet lodi po generovani je 17, stejne jako v originale (3 na hrace + 2 prisery).

## UKOL: duplicitni "3500" vpravo nahore

Vpravo nahore jsou hvezdna data DVAKRAT:

1. v ramecku pod hornim okrajem spravne `3500.0` (to je zamer, opraveno vlnou 88
   pres `word_192FDC`),
2. **nad nim, u samotneho horniho okraje obrazovky, jeste jednou jako
   `Stardate: 3500.0`** - tmave sede, castecne splyvajici s ramem. Tohle ma
   zmizet / vyresit.

Co uz je o tom zjisteno (neopakuj to):

* Kresli to `sub_84555` (orion_part_07.c, kolem radku 9400):

      if ( byte_199BDD ) {
        v12 = dword_192FD8 % 10; v11 = dword_192FD8 / 10;
        v14 = 0x0E0C0A00; v15 = 0x16141210;      // barevna rampa z dword_81C78
        v2 = sub_7A990(0xDAu);                    // retezec "Stardate: %d.%d"
        v3 = sprintf(v13, v2, v11, v12);
        sub_120BB5(1, (int)&v14);
        sub_1210B7(639, 0, (int)v13);             // vpravo zarovnano, y = 0
      }

  asm (0x845D8) to ma stejne: `mov eax, 27Fh / xor edx, edx / call sub_1210B7`.
* `byte_199BDD` (asm `byte_191BDD`) se nastavuje na 1 pri startu hry
  **i v originale** (orion_part_01.c:2296, asm 0x191BDD), je to prepinac
  (jinde `byte_199BDD = byte_199BDD == 0;`).
* Rampa `dword_81C78` = `dd 0E0C0A00h, 16141210h`, tedy same tmave indexy
  0x00..0x16 - text je tmavy zamerne (opraveno vlnou 86).
* **Par instrukci PRED tim se nastavuje orezovy obdelnik**
  `sub_128AB6(22, 22, 527, 421)` + `sub_12B634()` (ta jen nastavi
  `word_1845D8 = 1`), a bod (639, 0) lezi MIMO nej.
* ALE: overil jsem, ze **kreslic textu orezovy priznak vubec necte** -
  odkazy na `word_17C5D8` (C `word_1845D8`) v asm lezi VSECHNY mimo rozsah
  funkci `sub_1212EB` / `sub_121814` / `sub_121DEB` / `sub_121E85` /
  `sub_122309` (asm radky 429838-432098). `sub_121DEB` pise primo do
  framebufferu `dword_1BB904 + x + y * sirka` bez jakehokoliv orezu.

Z toho mi vyslo, ze **original ten text nejspis kresli taky** - ale neoveril
jsem to, a uzivatel to povazuje za chybu. Takze:

**Prvni krok je ROZHODNOUT to v dosboxu** (uzivatel ho pro tenhle ukol
vyslovne povolil): spustit original, dojit na herni mapu a podivat se, jestli
je vpravo nahore `Stardate: 3500.0` taky.

* Pokud ANO -> neni to chyba portu, zavri to a napis to do PROGRESS.md
  (vcetne toho, ze to bylo overeno v dosboxu, at to nikdo neresi potreti).
* Pokud NE -> najdi, cim to original potlacuje. Kandidati:
  - `byte_191BDD` v tu chvili neni 1 (zmer
    `DUMPREGS cond=changed:0x3AFBDD:1 repeat=always`; runtime adresa
    = 0x199BDD + 0x216000),
  - nebo se text prekryje necim, co se v originale kresli AZ POTOM
    (v portu muze byt jine poradi kresleni ramu/panelu),
  - nebo `sub_1210B7`/`sub_1212EB` v originale prece jen orezava a ja
    prehledl kudy (pak by to slo videt na `sub_138CEE` na konci `sub_1212EB` -
    prenos obdelniku mezi strankami, viz vlna 78).

## Backlog (mimo hlavni ukol)

* `sub_7927F` ma jeste **24 volani bez argumentu** (14x orion_part_07.c,
  8x orion_part_08.c, 2x orion_part_10.c) - vsechna zahazuji navratovou
  hodnotu a pak pouziji neinicializovanou lokalku. Recept: v asm najit
  `mov eax, <neco>` tesne pred `call sub_7927F` a `mov <reg>, eax` hned za nim.
  Je to tataz davkova prace jako u `sub_77B42` ve vlne 89.
* 19 souradnic typu `sub_1210B7(x, SWORD2(vN), text)` - horni pulka navratove
  hodnoty `sprintf` pouzita jako Y. Recept: v asm je `mov edx, NNh` tesne PRED
  `call sprintf_`; ta konstanta je hledana souradnice. Seznam se ziska grepem
  na `sub_1210B7|sub_1212B3|sub_1210FD|sub_1211F0` s `SWORD2|SHIWORD|HIWORD`.
* 5 volani pretypovanych na `(int (*)())(void*)sub_X` (sub_4E3B5, sub_A8197,
  sub_B6352, sub_103D53, sub_1131F0).
* 48 podezrelych z `tools/csdata_scan.py`.
* 25 zbylych `&ukazatel + 3`; 13 volajicich `sub_103915` s `SUB_103915_TODO`;
  22 `JUMPOUT` typu EPILOG v nevoid funkcich; 3 volani `qsort` bez komparatoru.
* `sub_CDF5C` vraci `int` misto `char *` (816 volani, 437 z nich do `int`).
  Zatim nevadi - zmereno, ze retezcovy pool lezi pod 2 GB - ale je to krehke.
* Uzivatel jednou videl pad na obrazovce "Enter Ruler Name"; nereprodukovano.

Nic neni commitnute az na to, co uzivatel commitnul sam - pred vetsimi zasahy
se podivej na `git status`.
