#pragma once
#include "Types.h"
class SignalGenerator { public: CPIData generateRawSignal(const std::vector<Target>& targets); private: Complex generateEcho(double range, double velocity, double t, double amp); };
