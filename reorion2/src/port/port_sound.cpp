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

// Prehravani streamovaneho audia (audio stopa SMK videa). Format se muze
// lisit od toho, s jakym byl stream otevren pri Init(), takze se pri prvni
// davce (nebo pri zmene) zarizeni znovu otevre.
void FeedStream(const uint8_t* pcm, uint32_t bytes, int milesSampleType, int rateHz)
{
    if (!pcm || bytes == 0)
        return;

    static int s_type = -1;
    static int s_rate = 0;
    if (!g_initialized || s_type != milesSampleType || s_rate != rateHz) {
        if (g_stream) {
            SDL_DestroyAudioStream(g_stream);
            g_stream = nullptr;
        }
        if (!SDL_Init(SDL_INIT_AUDIO)) {
            SDL_Log("Port::Sound::FeedStream - SDL_Init selhalo: %s", SDL_GetError());
            return;
        }
        SDL_AudioSpec spec{};
        // Miles typ: bit0 = 16bit, bit1 = stereo. 8bitove PCM je u Sound
        // Blasteru bez znamenka (0..255), 16bitove se znamenkem.
        spec.format = (milesSampleType & 1) ? SDL_AUDIO_S16LE : SDL_AUDIO_U8;
        spec.channels = (milesSampleType & 2) ? 2 : 1;
        spec.freq = rateHz > 0 ? rateHz : 22050;
        g_stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, nullptr, nullptr);
        if (!g_stream) {
            SDL_Log("Port::Sound::FeedStream - SDL_OpenAudioDeviceStream selhalo: %s", SDL_GetError());
            return;
        }
        SDL_ResumeAudioStreamDevice(g_stream);
        g_initialized = true;
        s_type = milesSampleType;
        s_rate = rateHz;
        SDL_Log("Port::Sound: audio zarizeni otevreno (%s %s, %d Hz)",
                (milesSampleType & 1) ? "S16" : "U8",
                (milesSampleType & 2) ? "stereo" : "mono", spec.freq);
    }

    // Jednorazovy rozbor prvni davky - rozlozeni hodnot jednoznacne odlisi
    // 8bit unsigned PCM (stred kolem 128) od 8bit signed (kolem 0) i od
    // 16bit (sousedni bajty silne koreluji) a od negeneracniho smeti.
    static bool s_dumped = false;
    if (!s_dumped) {
        s_dumped = true;
        int mn = 255, mx = 0;
        long sum = 0;
        uint32_t n = bytes < 4096 ? bytes : 4096;
        for (uint32_t i = 0; i < n; ++i) {
            int v = pcm[i];
            if (v < mn) mn = v;
            if (v > mx) mx = v;
            sum += v;
        }
        char hex[16 * 3 + 1];
        for (int i = 0; i < 16; ++i)
            SDL_snprintf(hex + i * 3, 4, "%02X ", pcm[i]);
        SDL_Log("Port::Sound: prvni davka %u B, prvnich 16 bajtu: %s", bytes, hex);
        SDL_Log("Port::Sound: rozlozeni na %u B - min=%d max=%d prumer=%ld",
                n, mn, mx, n ? sum / static_cast<long>(n) : 0L);
    }

    SDL_PutAudioStreamData(g_stream, pcm, static_cast<int>(bytes));
}

int QueuedBytes()
{
    if (!g_initialized || !g_stream)
        return 0;
    int q = SDL_GetAudioStreamQueued(g_stream);
    return q > 0 ? q : 0;
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

// Format audio streamu videa. Miles "sample type": 0 = 8bit mono,
// 1 = 16bit mono, 2 = 8bit stereo, 3 = 16bit stereo (viz sub_149E40, ktera
// ho sklada z priznaku +72 = 16bit a +76 = stereo a posila do
// AIL_set_sample_type/sub_157780).
static int g_streamType = 0;
static int g_streamRate = 22050;

void PortSound_SetStreamFormat(int milesSampleType, int rateHz)
{
    g_streamType = milesSampleType;
    if (rateHz > 0)
        g_streamRate = rateHz;
    SDL_Log("PortSound: format audio streamu = typ %d (%s, %s), %d Hz",
            milesSampleType,
            (milesSampleType & 1) ? "16bit" : "8bit",
            (milesSampleType & 2) ? "stereo" : "mono",
            g_streamRate);
}

// Prijme kus PCM tak, jak ho hra prave zapsala do sveho audio ring bufferu
// (sub_14B620). Puvodne by ho odtud odebral real-mode DIG driver; tady jde
// rovnou do SDL streamu.
// Kolik PCM jeste ceka ve fronte zvukoveho zarizeni. Nahrazuje informaci,
// kterou by jinak dodal real-mode DIG driver svym prerusenim.
int PortSound_QueuedBytes(void)
{
    return Port::Sound::QueuedBytes();
}

// Prah pro "sample dohran" (viz sub_157740). Vychozi 2048 B = velikost
// pul-bufferu DIG driveru (driver+68), tedy okamzik, kdy original dostal od
// driveru preruseni - jeste kdyz druha polovina hrala. Pri prahu 0 se cekalo
// na uplne vyschnuti fronty a mezi davkami vznikaly slysitelne mezery.
int PortSound_RefillThreshold(void)
{
    static int s_threshold = -1;
    if (s_threshold < 0) {
        s_threshold = 2048;
        if (const char* env = SDL_getenv("REORION2_AUDIO_REFILL")) {
            int v = SDL_atoi(env);
            if (v >= 0)
                s_threshold = v;
        }
        SDL_Log("PortSound: prah doplneni = %d B", s_threshold);
    }
    return s_threshold;
}

void PortSound_FeedStream(const void* pcm, int bytes)
{
    if (!pcm || bytes <= 0)
        return;
    // Diagnostika trhani zvuku: hloubka fronty TESNE PRED dodanim dalsi davky.
    // Kdyz tu opakovane vidime 0, zarizeni mezi davkami vyschlo = slysitelna
    // mezera. Zapina se REORION2_AUDIO_TRACE=1.
    static int s_traceLeft = -1;
    if (s_traceLeft < 0) {
        const char* env = SDL_getenv("REORION2_AUDIO_TRACE");
        s_traceLeft = (env && SDL_atoi(env)) ? 400 : 0;
    }
    if (s_traceLeft > 0) {
        --s_traceLeft;
        static int s_n = 0, s_underruns = 0;
        int q = Port::Sound::QueuedBytes();
        if (q == 0)
            ++s_underruns;
        SDL_Log("PortSound: feed #%d  fronta_pred=%d B  davka=%d B  podteceni=%d",
                s_n++, q, bytes, s_underruns);
    }
    Port::Sound::FeedStream(static_cast<const uint8_t*>(pcm), static_cast<uint32_t>(bytes),
                            g_streamType, g_streamRate);
}

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
