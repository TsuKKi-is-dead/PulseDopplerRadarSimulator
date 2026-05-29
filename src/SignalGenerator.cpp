#include "SignalGenerator.h"
#include "RadarConfig.h"
#include <cmath>
Complex SignalGenerator::generateEcho(double range, double velocity, double t, double amp) {
    double delay = 2.0 * range / RadarConfig::C;
    double doppler = 2.0 * velocity / RadarConfig::LAMBDA;
    double phase = 2 * M_PI * (RadarConfig::FC * (t - delay) + doppler * t);
    return amp * Complex(std::cos(phase), std::sin(phase));
}
CPIData SignalGenerator::generateRawSignal(const std::vector<Target>& targets) {
    CPIData cpi(RadarConfig::NUM_PULSES);
    for (int p = 0; p < RadarConfig::NUM_PULSES; ++p) {
        double slow_time = p * RadarConfig::PRI;
        IQData pulse(RadarConfig::SAMPLES_PER_PULSE, 0.0);
        for (const auto& tgt : targets) {
            for (int s = 0; s < RadarConfig::SAMPLES_PER_PULSE; ++s) {
                pulse[s] += generateEcho(tgt.range, tgt.velocity, slow_time + s/RadarConfig::FS, tgt.rcs);
            }
        }
        cpi[p] = std::move(pulse);
    }
    return cpi;
}
