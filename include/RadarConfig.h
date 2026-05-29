#pragma once
namespace RadarConfig {
    constexpr double C = 3.0e8;
    constexpr double FC = 10.0e9;
    constexpr double PRF = 10000.0;
    constexpr double PRI = 1.0 / PRF;
    constexpr int NUM_PULSES = 64;
    constexpr double FS = 2.0e6;
    constexpr int SAMPLES_PER_PULSE = 1024;
    constexpr double LAMBDA = C / FC;
    constexpr double RANGE_RES = C / (2 * FS);
}
