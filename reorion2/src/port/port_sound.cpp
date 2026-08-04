#include "port_sound.h"

#include <SDL3/SDL.h>
#include <cstdlib>

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

    // Statistika odesilaneho signalu (kazda 40. davka). 8bit unsigned PCM ma
    // ticho na 128; prumer daleko od 128 = stejnosmerna slozka (brum),
    // min/max na krajich = orezavani.
    static int s_batch = 0;
    if ((s_batch++ % 40) == 0 && SDL_getenv("REORION2_AUDIO_STATS")) {
        int mn = 255, mx = 0; long sum = 0;
        uint32_t n = bytes < 2048 ? bytes : 2048;
        for (uint32_t i = 0; i < n; ++i) {
            int v = pcm[i];
            if (v < mn) mn = v;
            if (v > mx) mx = v;
            sum += v;
        }
        SDL_Log("PortSound: davka #%d  %u B  min=%d max=%d prumer=%ld",
                s_batch - 1, bytes, mn, mx, n ? sum / (long)n : 0L);
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
    // PORT (vlna 26 pokr. 17): tep i odsud. Puvodne visel JEN na
    // PortVga_BlitBackBuffer, jenze to je cesta videa - a video ceka na audio,
    // ktere ceka na tep. Uzavreny kruh: zmereno, ze mixer probehl jen 3x, i
    // kdyz na prepnuti head je potreba 8 volani. V DOSu PIT tikal nezavisle
    // na tom, co hra delala; tohle je nejbliz - hra tuhle funkci pouziva ve
    // svych cekacich smyckach (sub_157740).
    PortSound_ServiceTimer();
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

static bool PortSound_UseRingSource();

void PortSound_FeedStream(const void* pcm, int bytes)
{
    if (!pcm || bytes <= 0)
        return;
    // Kdyz bezi skutecny mixer hry, zvuk do SDL posila PortSound_ServiceTimer
    // z hotoveho DMA pul-bufferu. Tahle stara nahrada (herni ring buffer) by
    // se s nim michala - dva zdroje do jednoho streamu.
    if (PortSound_TimerEnabled() && !PortSound_UseRingSource())
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

// Adresa slova "kterou polovinu DMA hraje hardware" a driveru - naplni je
// PortSound_CreateDigDriver, pouziva PortSound_ServiceTimer.
static int16_t* g_playingHalf = nullptr;
static int g_digDriver = 0;

// AIL casovaci callback hry (registruje se pres sub_1400A9). V DOSu ho budil
// PIT; v portu zadny takovy tik neni - zmereno, ze se za 90 s behu nezavolal
// ANI JEDNOU, cimz se cely retez prehravani zastavi.
extern "C" void sub_156680(int a1);

// Tep, ktery v DOSu delal PIT. Prepne "hranou polovinu" DMA vzdy, kdyz od
// posledniho prepnuti ubehla doba odpovidajici jedne polovine bufferu, a
// zavola obsluhu hry - ta si sama vsimne zmeny indexu (`**(driver+52)`),
// premixuje samply a posune jejich stav. Vola se z Present cesty.
// Zdroj zvuku pro SDL: "mix" = vystup herniho mixeru z DMA pul-bufferu
// (verne originalu), "ring" = stara nahrada z herniho ring bufferu (znela
// spravne, ale prehravani se po chvili zastavilo). Prepinac je tu proto, aby
// se dalo A/B porovnat POSLECHEM pri jinak uplne stejnem behu.
// REORION2_AUDIO_SRC=ring|mix   (vychozi: mix)
static bool PortSound_UseRingSource()
{
    static int s_ring = -1;
    if (s_ring < 0) {
        const char* env = SDL_getenv("REORION2_AUDIO_SRC");
        s_ring = (env && SDL_strcmp(env, "ring") == 0) ? 1 : 0;
        SDL_Log("PortSound: zdroj zvuku = %s", s_ring ? "ring (stara nahrada)"
                                                      : "mix (vystup mixeru hry)");
    }
    return s_ring != 0;
}

extern "C" int PortSound_TimerEnabled(void)
{
    static int s_on = -1;
    if (s_on < 0) {
        // Vlna 26 pokr. 27: ZAPNUTO VE VYCHOZIM STAVU - emulovany AIL
        // casovac je overeny (mixer hry bezi, zvuk hraje). Vypnuti
        // `REORION2_AUDIO_TIMER=0` nechava starou nahradu z ring bufferu.
        const char* env = SDL_getenv("REORION2_AUDIO_TIMER");
        s_on = (env && SDL_strcmp(env, "0") == 0) ? 0 : 1;
        SDL_Log("PortSound: emulovany AIL casovac %s", s_on ? "ZAPNUT" : "vypnut");
    }
    return s_on;
}

extern "C" void PortSound_ServiceTimer(void)
{
    {   // PORT (docasne mereni): proc se v menu neotevre zvukove zarizeni
        static int s_on = -1, s_n = 0;
        if (s_on < 0) s_on = SDL_getenv("REORION2_AUDIO_STATS") ? 1 : 0;
        if (s_on && (s_n++ % 200) == 0)
            SDL_Log("ServiceTimer: casovac=%d driver=%d half=%p",
                    PortSound_TimerEnabled(), g_digDriver, (void*)g_playingHalf);
    }
    if (!PortSound_TimerEnabled() || !g_digDriver || !g_playingHalf)
        return;
    // Ochrana proti rekurzi: sub_156680 -> mixer -> ... -> PortSound_QueuedBytes,
    // ktery tep taky budi (viz nize).
    static bool s_inside = false;
    if (s_inside)
        return;

    // Interval tepu = jak dlouho se prehrava jedna polovina DMA bufferu.
    // POZOR: pocita se z VYSTUPNIHO formatu DRIVERU (+20 frekvence,
    // +60 kanaly, +64 bajtu na vzorek), NE z formatu video streamu. Ten je
    // 11025 Hz, kdezto driver mixuje na 22050 Hz stereo - pri pocitani z
    // video streamu vysel interval 92 ms, ale zarizeni tech 2048 B spotrebuje
    // za 46 ms, takze polovina casu bylo ticho a zvuk zn�l "rozsekane".
    const uint8_t* drvFmt = reinterpret_cast<const uint8_t*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(g_digDriver)));
    uint32_t fRate = 0, fChannels = 0, fBps = 0, fHalf = 0;
    SDL_memcpy(&fRate,     drvFmt + 20, sizeof(fRate));
    SDL_memcpy(&fChannels, drvFmt + 60, sizeof(fChannels));
    SDL_memcpy(&fBps,      drvFmt + 64, sizeof(fBps));
    SDL_memcpy(&fHalf,     drvFmt + 68, sizeof(fHalf));
    if (!fRate)     fRate = 22050;
    if (!fChannels) fChannels = 2;
    if (!fBps)      fBps = 1;
    if (!fHalf)     fHalf = 2048;

    // PORT (vlna 26 pokr. 51): tep se NEODMERUJE hodinami, ale HLOUBKOU FRONTY
    // zvukoveho zarizeni. Puvodne tu bylo `if (now - s_lastFlip < halfMs)
    // return; s_lastFlip = now;`, coz ma dve vady:
    //   - `s_lastFlip = now` (misto `+= halfMs`) zahodi kazde zpozdeni, takze
    //     po kazdem zadrhnuti Presentu vznikne ve fronte diera = prasknuti;
    //   - halfMs vychazelo cele cislo 46 ms, kdezto 2048 B na 22050 Hz stereo
    //     trva 46,44 ms - drobny, ale trvaly rozjezd obou casovych os.
    // V DOSu davalo tempo samo zarizeni (preruseni DMA po dohrani poloviny
    // bufferu). Nejblizsi ekvivalent je mixovat prave tehdy, kdyz ma SDL
    // fronta min nez `cilova zasoba` - tim se tempo dlouhodobe rovna presne
    // rychlosti prehravani a kratkodobe vykyvy Presentu se pohlti zasobou.
    const uint32_t targetQueue = fHalf * 4;   // ~186 ms zasoba
    const int      maxFlips    = 8;           // strop na jedno volani (dohnani vypadku)

    for (int flips = 0; flips < maxFlips; ++flips)
    {
    if (Port::Sound::QueuedBytes() >= (int)targetQueue)
        return;

    const int idx = *g_playingHalf ^ 1;
    *g_playingHalf = (int16_t)idx;
    s_inside = true;
    sub_156680(g_digDriver);
    s_inside = false;

    // Odeslani HOTOVEHO pul-bufferu do SDL. `sub_156680` na konci vola
    // `sub_162201(driver, idx ^ 1)`, ktera prevede namixovana data do DMA
    // pul-bufferu ulozeneho na `driver + 44 + 4*(idx^1)`; jeho velikost je
    // `driver+68` (= 2048 B). Tohle je ta SPRAVNA cesta: mixuje hra, port uz
    // jen preda hotovy buffer zarizeni - narozdil od stare nahrady, ktera do
    // SDL posilala herni ring buffer (`PortSound_FeedStream`).
    const uint8_t* drv = reinterpret_cast<const uint8_t*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(g_digDriver)));
    uint32_t bufAddr = 0, halfSize = 0;
    SDL_memcpy(&bufAddr,  drv + 44 + 4 * (idx ^ 1), sizeof(bufAddr));
    SDL_memcpy(&halfSize, drv + 68, sizeof(halfSize));
    {   static int s_on = -1, s_n = 0;
        if (s_on < 0) s_on = SDL_getenv("REORION2_AUDIO_STATS") ? 1 : 0;
        if (s_on && (s_n++ % 100) == 0)
            SDL_Log("ServiceTimer: buf=0x%08X half=%u ring=%d",
                    bufAddr, halfSize, PortSound_UseRingSource());
    }
    if (bufAddr && halfSize && !PortSound_UseRingSource()) {
        // Vystupni format driveru: +20 = frekvence, +60 = kanaly,
        // +64 = bajtu na vzorek. Miles typ: bit0 = 16bit, bit1 = stereo.
        uint32_t rate = 0, channels = 0, bytesPerSample = 0;
        SDL_memcpy(&rate,           drv + 20, sizeof(rate));
        SDL_memcpy(&channels,       drv + 60, sizeof(channels));
        SDL_memcpy(&bytesPerSample, drv + 64, sizeof(bytesPerSample));
        const int milesType = ((bytesPerSample == 2) ? 1 : 0) | ((channels == 2) ? 2 : 0);
        Port::Sound::FeedStream(
            reinterpret_cast<const uint8_t*>(static_cast<uintptr_t>(bufAddr)),
            halfSize, milesType, (int)rate);
    }
    }   // konec smycky "dopln frontu na cilovou zasobu"
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
    // +12 = 4: zmereno z originalu (dosbox DUMPMEM na 0x003EC8D8 v okamziku
    // mixovani). Nahradni driver tu mel 0. Vsechna ostatni formatova pole
    // (+16/+20/+24/+28/+60/+64/+68/+72/+76/+84/+96) uz s originalem sedi.
    put(12, 4);
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

    // --- DMA a mixovaci buffery (vlna 26 pokr. 13) ---------------------
    // Rozlozeni NEODHADNUTE, ale odectene primo z inicializace driveru v
    // originalu (orion_part_23.c kolem r. 1265):
    //     v3[17] = +68 = +16 / +64                 -> 2048
    //     v3[18] = +72 = +16 / (+64 * +60)         -> 1024
    //     v3[19] = +76 = 4 * (+16 / +64)           -> 8192  velikost mixu
    //     v3[20] = +80 = alloc(4 * (+16 / +64))    -> MIX BUFFER
    // a o kus dal (r. 1032) se ze dvojice far-pointeru na +8 linearizuji
    // adresy obou DMA pul-bufferu:
    //     *(a2+44) = lin(ptr[0]);  *(a2+48) = lin(ptr[1]);
    // Nahradni driver mel dosud +80 = 0, takze prvni `sub_162293` (memset
    // mix bufferu) by sahnul na NULL - latentni pad, jakmile se mixer
    // rozbehne.
    // Cele tohle rozsireni je za stejnym prepinacem jako tep (viz
    // PortSound_ServiceTimer). Duvod: nastavenim +84 = 1 ("driver bezi") a
    // dodanim bufferu se hra pusti do kodovych cest, ktere dosud preskakovala,
    // a bez doladeneho tepu z toho zatim padala. Vychozi chovani musi zustat
    // nedotcene.
    // POZOR: gate obaluje JEN buffery. Inicializace samplu nize musi probehnout
    // vzdy - kdyz se preskocila, zadny sample nebyl oznaceny jako volny a
    // audio se vubec nerozjelo (zmereno: 0 davek misto 11).
    if (PortSound_TimerEnabled()) {
        const uint32_t kHalfSize = 2048;  // = +16, velikost jedne poloviny DMA
        // Alokuje se CRT `calloc`, ne SDL_calloc: dekompilat ty ukazatele
        // uklada do 32bitovych poli, takze musi lezet pod 4 GB. SDL ma vlastni
        // alokator a vracel adresy kolem 0x1_16E37B80 (~4,6 GB) - po orezu na
        // 32 bitu z toho byl divoky ukazatel a pad ve VCRUNTIME memcpy.
        // Pod /LARGEADDRESSAWARE:NO drzi CRT halda adresy pod 2 GB.
        auto* mixBuf  = static_cast<uint8_t*>(std::calloc(1, 8192));
        auto* dmaBuf  = static_cast<uint8_t*>(std::calloc(2, kHalfSize));
        auto* bufPtrs = static_cast<uint32_t*>(std::calloc(2, sizeof(uint32_t)));
        // +52 ukazuje na 16bitove slovo "kterou polovinu zrovna hraje
        // hardware". Tohle JEDINE se z originalu opsat neda - v DOSu to slovo
        // plnil real-mode driver podle DMA. Presne tu informaci musi dodat
        // port sam (viz PortSound_ServiceTimer vyse).
        auto* playingHalf = static_cast<int16_t*>(std::calloc(1, sizeof(int16_t)));
        if (!mixBuf || !dmaBuf || !bufPtrs || !playingHalf) {
            SDL_Log("PortSound_CreateDigDriver: alokace bufferu selhala");
            return 0;
        }
        auto fits32 = [](const void* p) {
            return (reinterpret_cast<uintptr_t>(p) >> 32) == 0;
        };
        if (!fits32(mixBuf) || !fits32(dmaBuf) || !fits32(bufPtrs) || !fits32(playingHalf)) {
            SDL_Log("PortSound_CreateDigDriver: buffer nad 4 GB, 32bitova pole hry "
                    "by ho neunesla - emulovany casovac se nezapina");
        } else {
            bufPtrs[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(dmaBuf));
            bufPtrs[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(dmaBuf + kHalfSize));
            put(8,  static_cast<uint32_t>(reinterpret_cast<uintptr_t>(bufPtrs)));
            put(44, bufPtrs[0]);
            put(48, bufPtrs[1]);
            put(52, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(playingHalf)));
            put(80, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(mixBuf)));
            put(84, 1); // driver bezi (v originalu se nastavi po uspesnem startu)
            g_playingHalf = playingHalf;
        }
    }

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

    g_digDriver = static_cast<int>(reinterpret_cast<uintptr_t>(drv));
    s_driver = static_cast<int>(reinterpret_cast<uintptr_t>(drv));
    SDL_Log("PortSound_CreateDigDriver: DIG_DRIVER=0x%08X, %d samplu po %d B na 0x%08X",
            s_driver, kSampleCount, kSampleStride,
            static_cast<unsigned>(reinterpret_cast<uintptr_t>(samples)));
    return s_driver;
}

} // extern "C"
