Potrebujeme ty funkce postupne prevest do citelneho kodu.
-zkus vzdy vytknout struktury, to znamena, zbavovat se obdobnych veci:   result = ((int (__fastcall *)(int))strstr)(a2 + 34); a misto nich pouzivat struktury
-kdyz to pujde zbavuj se JUMPOUT GOTO a podobne, ale tak aby kod fungoval identicky
-spravne pojmenovat promenne a funkce, ale nech tam cast oznacujisi adresu, takze to bude jmeno_adresa promenne budou zacinat malymi pismeny funkce velkymi
-vsechny věci, které resi bios nebo dos, budou smerovat do novych souboru typu port_sound.cpp port_vga.cpp port_mouse.cpp, kod bude inspirovany dosbox-x a remc2, zaklad bude SDL3, terminal budeme emulovat abychom mohli grafiku inicializovat hned na zacatku. Ale bude se to posilat i na standardni vystup, pokud bude.
-take je treba vyresit inicializacaci pameti, ta bude v port_memory narozdil od dosu nebude treba hledat volny usek pameti ani resit offse,segment, bud to bude pomoci malloc/dispoze nebo new/free, pripadne nejaky modernejsi zpusob, ktery bude kompaktibilni ale odolny vuci memory leakum
-kdyz bude jasne pod jakou skupinu dany kod patri vyclen pro nej specielni soubor, aby se postupne tvořila rozumna struktura kodu
-z funkci odebirej __usercall __fastcall a podobne informace, ktere zjevne uz nejsou potreba
