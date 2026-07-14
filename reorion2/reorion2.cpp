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