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
