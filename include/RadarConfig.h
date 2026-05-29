#pragma once
#include <cstddef>

namespace RadarConfig {
    constexpr double C = 3.0e8;                    // Speed of light m/s
    constexpr double FC = 10.0e9;                  // 10 GHz X-band
    constexpr double PRF = 10000.0;                // Pulse Repetition Frequency
    constexpr double PRI = 1.0 / PRF;
    constexpr int NUM_PULSES = 64;                 // Coherent Processing Interval
    constexpr double FS = 2.0e6;                   // Sampling frequency
    constexpr int SAMPLES_PER_PULSE = 1024;
    
    constexpr double LAMBDA = C / FC;
    constexpr double RANGE_RES = C / (2 * FS);     // ~75 meters
    constexpr double MAX_RANGE = 50000.0;          // 50 km
}
