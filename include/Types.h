#pragma once
#include <complex>
#include <vector>
using Complex = std::complex<double>;
using IQData = std::vector<Complex>;
using CPIData = std::vector<IQData>;

struct Target { double range, velocity, rcs = 1.0; };
struct Detection { double range, velocity, snr; int range_bin, doppler_bin; };
struct Track { int id; double range, velocity; };
