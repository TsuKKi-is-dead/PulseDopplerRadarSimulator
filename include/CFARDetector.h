#pragma once
#include "Types.h"
class CFARDetector { public: std::vector<Detection> detect(const std::vector<std::vector<double>>& rdMap, double pfa = 1e-4); };
