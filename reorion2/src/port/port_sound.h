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

} // namespace Port::Sound

#endif // PORT_SOUND_H
