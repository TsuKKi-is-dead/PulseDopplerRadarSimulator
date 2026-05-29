#include "Visualizer.h"
#include "RadarConfig.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void Visualizer::plot(const std::vector<std::vector<double>>& rdMap,
                      const std::vector<Detection>& detections,
                      const std::vector<Track>& tracks) {
    
    std::cout << "\n=== Detected Targets ===\n";
    for (const auto& d : detections) {
        std::cout << "Enemy Aircraft -> Range: " << std::fixed << std::setprecision(1)
                  << d.range / 1000 << " km | Velocity: " << d.velocity << " m/s | SNR: " << d.snr << "\n";
    }

    std::cout << "\n=== Tracked Targets ===\n";
    for (const auto& t : tracks) {
        std::cout << "Track " << t.id << " -> Range: " << t.range / 1000 
                  << " km | Velocity: " << t.velocity << " m/s\n";
    }

    // Export Range-Doppler map for Python
    std::ofstream csv("data/range_doppler.csv");
    if (csv.is_open()) {
        for (const auto& row : rdMap) {
            for (size_t i = 0; i < row.size(); ++i) {
                csv << row[i];
                if (i < row.size() - 1) csv << ",";
            }
            csv << "\n";
        }
        csv.close();
        std::cout << "✅ Range-Doppler map saved to data/range_doppler.csv\n";
    }
}
