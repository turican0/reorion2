// reorion2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <iostream>
#include <string>
#include <cstdint>

#include "orion_common.h"

int main(int argc, char* argv[])
{
    // Kontrola, zda uživatel zadal dostatek parametrů v příkazové řádce
    if (argc < 4)
    {
        std::cerr << "Pouziti: " << argv[0] << " <parametr_a1> <parametr_a2> <parametr_a3>\n";
        return 1;
    }

    try
    {
        // Převod textových argumentů z příkazové řádky na čísla
        int a1 = std::stoi(argv[1]);
        int a2 = std::stoi(argv[2]);

        // Příprava ukazatele int16_t* pro třetí parametr
        int16_t val3 = static_cast<int16_t>(std::stoi(argv[3]));
        int16_t* a3 = &val3;

        // VOLÁNÍ VAŠÍ FUNKCE S PARAMETRY
        main__0(a1, a2, a3);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Chyba pri konverzi parametru: " << e.what() << "\n";
        return 1;
    }

    return 0;
    //std::cout << "Hello World!\n";
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
