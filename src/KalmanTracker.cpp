#include "KalmanTracker.h"
std::vector<Track> KalmanTracker::update(const std::vector<Detection>& detections) {
    std::vector<Track> tracks; static int id=1;
    for (const auto& d : detections) tracks.push_back({id++, d.range, d.velocity});
    return tracks;
}
