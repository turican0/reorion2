#include "port_sound.h"

#include <SDL3/SDL.h>

namespace Port::Sound {

namespace {
SDL_AudioStream* g_stream = nullptr;
bool g_initialized = false;
} // namespace

bool Init()
{
    if (g_initialized)
        return true;

    if (!SDL_Init(SDL_INIT_AUDIO)) {
        SDL_Log("Port::Sound::Init - SDL_Init selhalo: %s", SDL_GetError());
        return false;
    }

    SDL_AudioSpec spec{};
    spec.format = SDL_AUDIO_S16LE;
    spec.channels = 1;
    spec.freq = 22050; // typicka vzorkovaci frekvence dobovych PC her

    g_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, nullptr, nullptr);
    if (!g_stream) {
        SDL_Log("Port::Sound::Init - SDL_OpenAudioDeviceStream selhalo: %s", SDL_GetError());
        return false;
    }
    SDL_ResumeAudioStreamDevice(g_stream);

    g_initialized = true;
    return true;
}

void Shutdown()
{
    if (g_stream) {
        SDL_DestroyAudioStream(g_stream);
        g_stream = nullptr;
    }
    g_initialized = false;
}

void PlaySample(const uint8_t* pcmData, uint32_t lengthBytes, uint32_t sampleRateHz)
{
    // DECOMP_TODO: puvodni format vzorku (bitova hloubka, mono/stereo,
    // pripadne u-law/kompresni format pouzity ve hre) zjistime az z
    // konkretnich prevadenych funkci - ted jen predpokladame 8bit mono PCM,
    // coz byl nejcastejsi format Sound Blaster efektu v teto ere.
    if (!g_initialized || !pcmData || lengthBytes == 0)
        return;
    (void)sampleRateHz;
    SDL_PutAudioStreamData(g_stream, pcmData, static_cast<int>(lengthBytes));
}

void WriteOplRegister(uint8_t reg, uint8_t value)
{
    // DECOMP_TODO: zatim jen zaslepka - hudebni OPL emulace (napr. napojeni
    // na Nuked-OPL3, stejne jako pouziva dosbox-x) pribude az narazime na
    // konkretni funkce, ktere s temito registry pracuji.
    (void)reg;
    (void)value;
}

} // namespace Port::Sound

// ---------------------------------------------------------------------
extern "C" {

int PortSound_CreateDigDriver(void)
{
    // Popis rozlozeni a puvod hodnot viz port_sound.h.
    static constexpr int kSampleCount  = 17;
    static constexpr int kSampleStride = 2196; // AilSample, viz orion_common.h
    static constexpr int kFreeMarker   = 1;    // sub_157610 hleda *(s+4) == 1

    static int s_driver = 0;
    if (s_driver)
        return s_driver;

    // Halda (ne staticke pole) - dekompilat ukazatele uklada do 32bit intu.
    auto* drv = static_cast<uint8_t*>(SDL_calloc(1, 128));
    auto* samples = static_cast<uint8_t*>(SDL_calloc(1, static_cast<size_t>(kSampleCount) * kSampleStride));
    if (!drv || !samples) {
        SDL_free(drv);
        SDL_free(samples);
        SDL_Log("PortSound_CreateDigDriver: alokace selhala");
        return 0;
    }

    auto put = [drv](int offset, uint32_t value) {
        SDL_memcpy(drv + offset, &value, sizeof(value));
    };
    put(16, 2048);
    put(20, 22050);
    put(24, 2);
    put(60, 2);
    put(64, 1);
    put(68, 2048);
    put(72, 1024);
    put(76, 8192);
    put(92, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(samples)));
    put(96, kSampleCount);

    // Kazdy sample nese na +0 ZPETNY UKAZATEL na svuj DIG_DRIVER a na +4 stav
    // (1 = volny). Overeno dumpem originalu (sample[1] na 0x004F2038:
    // +0 = 0x003EC8D8 = presne DIG_DRIVER, +4 = 2 po inicializaci).
    // Bez toho +0 padal `sub_156400` na cteni z null+0x18 hned pri prvni
    // alokaci (sub_140BB1 -> sub_157610 -> sub_140DFC -> sub_157690).
    const uint32_t drvValue = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(drv));
    for (int i = 0; i < kSampleCount; ++i) {
        uint8_t* s = samples + static_cast<size_t>(i) * kSampleStride;
        uint32_t freeMark = kFreeMarker;
        SDL_memcpy(s + 0, &drvValue, sizeof(drvValue));
        SDL_memcpy(s + 4, &freeMark, sizeof(freeMark));
    }

    s_driver = static_cast<int>(reinterpret_cast<uintptr_t>(drv));
    SDL_Log("PortSound_CreateDigDriver: DIG_DRIVER=0x%08X, %d samplu po %d B na 0x%08X",
            s_driver, kSampleCount, kSampleStride,
            static_cast<unsigned>(reinterpret_cast<uintptr_t>(samples)));
    return s_driver;
}

} // extern "C"
