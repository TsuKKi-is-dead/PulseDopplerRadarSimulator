#pragma once
#include "Types.h"
class FFTProcessor { public: void processRangeDoppler(const CPIData& cpi, std::vector<std::vector<double>>& rdMap); private: void fft(std::vector<Complex>& data); };
