#include "FFTProcessor.h"
#include "RadarConfig.h"
#include <cmath>
void FFTProcessor::fft(std::vector<Complex>& data) {
    int N = data.size(); std::vector<Complex> out(N, 0.0);
    for (int k = 0; k < N; ++k)
        for (int n = 0; n < N; ++n) {
            double ang = -2.0 * M_PI * k * n / N;
            out[k] += data[n] * Complex(std::cos(ang), std::sin(ang));
        }
    data = std::move(out);
}
void FFTProcessor::processRangeDoppler(const CPIData& cpi, std::vector<std::vector<double>>& rdMap) {
    int nr = RadarConfig::SAMPLES_PER_PULSE, nd = RadarConfig::NUM_PULSES;
    rdMap.assign(nd, std::vector<double>(nr, 0.0));
    for (int p = 0; p < nd; ++p) {
        auto pulse = cpi[p]; fft(pulse);
        for (int r = 0; r < nr; ++r) rdMap[p][r] = std::abs(pulse[r]);
    }
}
