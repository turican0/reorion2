Potrebujeme ty funkce postupne prevest do citelneho kodu.
-zkus vzdy vytknout struktury, to znamena, zbavovat se obdobnych veci:   result = ((int (\_\_fastcall \*)(int))strstr)(a2 + 34); a misto nich pouzivat struktury
-kdyz ti bude jasne, ze int neni int, ale pointer, tak se to snaz pretypovat, idealne vytknout strukturu, pokud bude zrejma, nebo ji vytknout alespon zhruba, a postupne doplnovat
-kdyz to pujde zbavuj se JUMPOUT GOTO a podobne, ale tak aby kod fungoval identicky
-spravne pojmenovat promenne a funkce, ale nech tam cast oznacujisi adresu, takze to bude jmeno\_adresa promenne budou zacinat malymi pismeny funkce velkymi
-vsechny věci, které resi bios nebo dos, budou smerovat do novych souboru typu port\_sound.cpp port\_vga.cpp port\_mouse.cpp, kod bude inspirovany dosbox-x a remc2, zaklad bude SDL3, terminal budeme emulovat abychom mohli grafiku inicializovat hned na zacatku. Ale bude se to posilat i na standardni vystup, pokud bude.
-take je treba vyresit inicializacaci pameti, ta bude v port\_memory narozdil od dosu nebude treba hledat volny usek pameti ani resit offse,segment, bud to bude pomoci malloc/dispoze nebo new/free, pripadne nejaky modernejsi zpusob, ktery bude kompaktibilni ale odolny vuci memory leakum
-kdyz bude jasne pod jakou skupinu dany kod patri vyclen pro nej specielni soubor, aby se postupne tvořila rozumna struktura kodu
-z funkci odebirej \_\_usercall \_\_fastcall \_\_cdecl a podobne informace, ktere zjevne uz nejsou potreba
-vzdy porovnavej kod s puvodnim diassemblovanym, a tam, kde to neni kvuli kompaktibilite a kvuli cisteni kodu, se rid tim puvodnim kodem, tak porrovnavej c++ dissasemblovany kod s asm kodem, tam kde to neni jasne
-veskere komentare v souborech pis anglicky
-stejne tak vsechny .md soubory pis anglicky

\-take prubezne vytvarej a doplnuj README.md pro GITHUB, pridej tam informace o projektu, informace o postupu, s popisem i obrazky a datumy

