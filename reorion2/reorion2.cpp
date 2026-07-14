#include <cstdint>

#include "code/code/orion_common.h"

int main(int argc, char* argv[])
{
    // Předáváme původní parametry programu i tehdy, když uživatel nezadal
    // žádný argument (argc je v takovém případě 1 a argv obsahuje cestu EXE).
    // Třetí parametr dekompilovaného vstupu není ve standardním main dostupný.
    main__0(argc, reinterpret_cast<intptr_t>(argv), nullptr);
    return 0;
}

/*
Potrebujeme ty funkce postupne prevest do citelneho kodu.
-zkus vzdy vytknout struktury.
-spravne pojmenovat promenne a funkce, ale nech tam cast oznacujisi adresu, takze to bude jmeno_adresa promenne budou zacinat malymi pismeny funkce velkymi
-vsechny věci, které resi bios nebo dos, budou smerovat do novych souboru typu port_sound.cpp port_vga.cpp port_mouse.cpp, kod bude inspirovany dosbox-x a remc2, zaklad bude SDL3, terminal budeme emulovat abychom mohli grafiku inicializovat hned na zacatku. Ale bude se to posilat i na standardni vystup, pokud bude.
-kdyz bude jasne pod jakou skupinu dany kod patri vyclen pro nej specielni soubor, aby se postupne tvořila rozumna struktura kodu
*/