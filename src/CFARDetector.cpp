#include "CFARDetector.h"
#include "RadarConfig.h"
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<Detection> CFARDetector::detect(const std::vector<std::vector<double>>& rdMap, double pfa) {
    std::vector<Detection> dets;
    if (rdMap.empty() || rdMap[0].empty()) return dets;

    int guard = 2;
    int train = 8;
    double alpha = train * (std::pow(pfa, -1.0 / train) - 1.0);

    for (size_t d = 0; d < rdMap.size(); ++d) {
        for (size_t r = train + guard; r < rdMap[0].size() - train - guard; ++r) {
            double cut = rdMap[d][r];
            double noise = 0.0;
            int count = 0;

            for (int i = -train - guard; i <= train + guard; ++i) {
                if (i == 0) continue;
                if (r + i >= 0 && r + i < rdMap[0].size()) {
                    noise += rdMap[d][r + i];
                    count++;
                }
            }

            if (count > 0) {
                double threshold = alpha * (noise / count);
                if (cut > threshold) {
                    double velocity = (static_cast<double>(d) - rdMap.size() / 2.0) * (RadarConfig::PRF / rdMap.size());
                    dets.push_back({
                        r * RadarConfig::RANGE_RES,
                        velocity,
                        cut,
                        static_cast<int>(r),
                        static_cast<int>(d)
                    });
                }
            }
        }
    }
    std::cout << "✅ Detected " << dets.size() << " targets using CA-CFAR\n";
    return dets;
}
