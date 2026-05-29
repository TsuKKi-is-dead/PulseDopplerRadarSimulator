#include "ScenarioGenerator.h"
#include "SignalGenerator.h"
#include "NoiseModel.h"
#include "FFTProcessor.h"
#include "CFARDetector.h"
#include "KalmanTracker.h"
#include "Visualizer.h"
#include "Benchmark.h"
#include <iostream>

int main() {
    std::cout << "=== Pulse-Doppler Radar Simulator Starting ===\n\n";

    Benchmark bench;
    bench.start("Full Pipeline");

    auto targets = ScenarioGenerator().generateScenario();
    std::cout << "Generated " << targets.size() << " enemy targets\n";

    auto cpi = SignalGenerator().generateRawSignal(targets);
    NoiseModel().addNoise(cpi, 18.0);

    std::vector<std::vector<double>> rdMap;
    FFTProcessor().processRangeDoppler(cpi, rdMap);

    auto detections = CFARDetector().detect(rdMap, 1e-4);
    auto tracks = KalmanTracker().update(detections);

    Visualizer().plot(rdMap, detections, tracks);

    bench.stop();
    std::cout << "\n✅ Simulation Completed Successfully!\n";
    return 0;
}
