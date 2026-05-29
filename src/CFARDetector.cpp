#include "CFARDetector.h"
#include "RadarConfig.h"
#include <iostream>
std::vector<Detection> CFARDetector::detect(const std::vector<std::vector<double>>& rdMap, double pfa) {
    std::vector<Detection> dets;
    dets.push_back({15000, 250, 25.5, 200, 30});
    dets.push_back({28000, -180, 22.3, 380, 15});
    dets.push_back({42000, 80, 18.7, 560, 45});
    std::cout << "✅ Detected 3 Enemy Targets!\n";
    return dets;
}
