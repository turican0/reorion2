// port_memory.h - nahrada za puvodni DOS zpusob sprava pameti (hledani
// volneho useku v ramci segmentu, prace se segment:offset adresami pres
// vlastni zonovy alokator - viz PoolAlloc_110B89 a pribuzne funkce v
// src/game/orion_part_18.c). V modernim portu zadne segmenty ani rucni
// hledani volneho mista neresime - stara se o to operacni system pres
// malloc/free (resp. new/delete), tahle vrstva jen pridava:
//   1) jednotne misto, kam casem presmerujeme vsechny puvodni volani
//      PoolAlloc_110B89 & spol., az bude jasne, jak presne se pouzivaly,
//   2) jednoduchou evidenci zivych alokaci, aby leaky byly videt hned
//      (v puvodnim DOS kodu se casto nic needeallokovalo a spolehalo se
//      na to, ze cely proces skonci a OS/DOS vezme pamet zpet - to uz
//      v modernim behovem prostredi nechceme).
//
// DECOMP_TODO: az narazime na konkretni volani PoolAlloc_110B89 (a jeho
// protejsky pro uvolneni), presmerujeme je sem misto puvodni zonove logiky.
// Zatim je tahle vrstva nezavisla a pripravena k pouziti pro NOVY kod
// (napr. port_vga/port_sound bufery).
#ifndef PORT_MEMORY_H
#define PORT_MEMORY_H

#include <cstddef>

namespace Port::Memory {

// Volitelna inicializace/ukonceni - hlavne kvuli leak-reportu na konci behu.
// Neni to skutecny pool/arena (na to malloc/free dnes nepotrebuje pomoc),
// jen zapina/vypina evidenci alokaci.
void Init();
void Shutdown();

// Zakladni alokace/dealokace - tenka vrstva nad malloc/free, ktera si navic
// v debug rezimu pamatuje kazdy ziskany blok (adresa, velikost, misto volani)
// a pri Shutdown() nahlasi vse, co nebylo uvolneno.
void* Alloc(std::size_t size, const char* debugTag = nullptr);
void* Realloc(void* ptr, std::size_t newSize, const char* debugTag = nullptr);
void Free(void* ptr);

// Pohodlny sablonovy wrapper pro typovanou alokaci jednoho objektu -
// preferovana cesta pro VSECHEN novy (neportovany 1:1) kod, protoze RAII
// pres std::unique_ptr/std::vector je odolnejsi vuci leakum nez rucni
// Alloc/Free. Priklad: auto buf = Port::Memory::AllocArray<uint8_t>(1024);
template <typename T>
T* AllocArray(std::size_t count, const char* debugTag = nullptr)
{
    return static_cast<T*>(Alloc(sizeof(T) * count, debugTag));
}

// Kolik bajtu je aktualne alokovano touto vrstvou - uzitecne pro ladeni.
std::size_t GetLiveBytes();
std::size_t GetLiveAllocationCount();

} // namespace Port::Memory

// ---------------------------------------------------------------------
// C-linkage most pro dekompilovany herni kod (cisty C, src/game/*.c).
// Vlna 06: VSECHNY malloc/calloc/realloc/free (a Watcom "near heap"
// nmalloc/nfree) v dekompilovanem kodu se presmerovavaji sem pres makra
// v hexrays_compat.h - viz komentar tam. Tyhle funkce jsou jen tenke C
// obalky nad Port::Memory:: API vyse, aby je bylo mozne volat i z .c
// souboru (ktere nerozumi namespace/template).
#ifdef __cplusplus
extern "C" {
#endif

void* PortMemory_Alloc(size_t size);
void* PortMemory_Calloc(size_t count, size_t size);
void* PortMemory_Realloc(void* ptr, size_t size);
int   PortMemory_Free(void* ptr); // vraci 1 pri uspechu, 0 kdyz ptr byl NULL

#ifdef __cplusplus
}
#endif

#endif // PORT_MEMORY_H
