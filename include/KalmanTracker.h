#pragma once
#include "Types.h"
class KalmanTracker { public: std::vector<Track> update(const std::vector<Detection>& detections); };
