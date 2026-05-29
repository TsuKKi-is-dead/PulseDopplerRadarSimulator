#pragma once
#include "Types.h"
class Visualizer { public: void plot(const std::vector<std::vector<double>>& rdMap, const std::vector<Detection>& detections, const std::vector<Track>& tracks); };
