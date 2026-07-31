// port_sound.h - nahrada za primy pristup na zvukovou kartu (typicky Sound
// Blaster porty 220h-22Fh + IRQ/DMA, pripadne primy OPL2/OPL3 pres port
// 388h pro hudbu). Zaklad SDL3 audio, inspirace pristupem dosbox-x k
// namixovanym vystupnim streamum.
#ifndef PORT_SOUND_H
#define PORT_SOUND_H

#include <cstdint>

namespace Port::Sound {

bool Init();
void Shutdown();

// Nahrazuje puvodni prehravani digitalizovaneho PCM efektu (v dekompilaci
// typicky videt jako zapisy do DMA bufferu / volani nejasnych sub_* funkci
// kolem "Sound Blaster" retezcu). Az takove funkce najdeme, prepojime je
// sem misto primeho portovani DOS driveru.
void PlaySample(const uint8_t* pcmData, uint32_t lengthBytes, uint32_t sampleRateHz);

// Nahrazuje OPL2/OPL3 (AdLib/Sound Blaster FM) - zapis registru pro hudbu.
// DECOMP_TODO: potreba az najdeme funkce volajici port 388h/389h.
void WriteOplRegister(uint8_t reg, uint8_t value);

// Streamovane audio (audio stopa SMK videa) - viz PortSound_FeedStream.
void FeedStream(const uint8_t* pcm, uint32_t bytes, int milesSampleType, int rateHz);

} // namespace Port::Sound

// ---------------------------------------------------------------------
// C-linkage most pro dekompilovany herni kod (vlna 26).
extern "C" {

// Vyrobi nahradu za AIL (Miles) DIG_DRIVER, kterou by jinak postavil
// `sub_157570` nactenim DIG.INI a real-mode driveru SB16.DIG - ten v portu
// spustit nelze. Vraci ukazatel jako `int` (dekompilat ho tak uklada;
// pamet je z haldy, takze pod /LARGEADDRESSAWARE:NO round-tripuje).
//
// Rozlozeni a hodnoty jsou OPSANE Z ORIGINALU (dosbox-x DUMPMEM na
// dword_184388 -> 0x003EC8D8, pak dump te struktury):
//   +16 = 2048   velikost DMA bufferu
//   +20 = 22050  vzorkovaci frekvence
//   +68 = 2048, +72 = 1024, +76 = 8192
//   +92 = ukazatel na pole samplu, +96 = 17 polozek po 2196 B
// Volny sample pozna `sub_157610` (AIL_allocate_sample_handle) podle
// `*(int*)(sample+4) == 1`, takze pole se takhle inicializuje.
int PortSound_CreateDigDriver(void);

// Format audio streamu videa (Miles sample type 0-3) a jeho vzorkovaci
// frekvence; nastavuje se pri otevirani streamu v sub_149E40.
void PortSound_SetStreamFormat(int milesSampleType, int rateHz);

// Kus PCM tak, jak ho hra prave zapsala do sveho audio ring bufferu
// (sub_14B620) - puvodne by ho odtud odebral real-mode DIG driver.
void PortSound_FeedStream(const void* pcm, int bytes);

} // extern "C"

#endif // PORT_SOUND_H
