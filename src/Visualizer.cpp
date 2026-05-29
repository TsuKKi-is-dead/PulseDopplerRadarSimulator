#include "Visualizer.h"
#include <iostream>
#include <iomanip>
void Visualizer::plot(const std::vector<std::vector<double>>&, const std::vector<Detection>& detections, const std::vector<Track>& tracks) {
    std::cout << "\n=== Detected Targets ===\n";
    for(const auto& d : detections) {
        std::cout << "Enemy Aircraft -> Range: " << std::fixed << std::setprecision(1) 
                  << d.range/1000 << " km | Velocity: " << d.velocity << " m/s\n";
    }
    std::cout << "\n=== Tracked Targets ===\n";
    for(const auto& t : tracks) {
        std::cout << "Track " << t.id << " -> Range: " << t.range/1000 
                  << " km | Velocity: " << t.velocity << " m/s\n";
    }
}
