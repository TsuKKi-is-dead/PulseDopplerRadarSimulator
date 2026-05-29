#include "KalmanTracker.h"
#include <iostream>

std::vector<Track> KalmanTracker::update(const std::vector<Detection>& detections) {
    std::vector<Track> tracks;
    static int nextId = 1;

    for (const auto& det : detections) {
        Track t;
        t.id = nextId++;
        // Simple smoothing (real Kalman would use matrices)
        t.range = det.range * 0.9 + (det.range > 0 ? 100 : 0);  // slight bias for demo
        t.velocity = det.velocity;
        tracks.push_back(t);
    }
    return tracks;
}
