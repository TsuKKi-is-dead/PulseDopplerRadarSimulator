# Pulse-Doppler Radar Signal Processing Simulator

**A realistic C++ implementation of a Pulse-Doppler radar processing pipeline** — built as a strong aerospace/defense portfolio project.

## Features
- Realistic IQ signal generation using physics (range delay + Doppler shift)
- Additive White Gaussian Noise (AWGN)
- 2D Range-Doppler Map via FFT
- CA-CFAR target detection
- Kalman Filter based tracking
- Professional visualization (console + Python matplotlib)
- Performance benchmarking
- Real X-band radar parameters (10 GHz)

## Project Structure
PulseDopplerRadarSimulator/
├── main.cpp
├── CMakeLists.txt
├── README.md
├── plot_results.py
├── include/          # Headers
├── src/              # Source files
├── data/             # Output CSV files
└── docs/
text## Modules Overview

| Module              | Purpose                                      | Key Concept                     |
|---------------------|----------------------------------------------|---------------------------------|
| RadarConfig         | Real radar parameters                        | X-band Pulse-Doppler            |
| ScenarioGenerator   | Creates enemy aircraft targets               | Simulation scenario             |
| SignalGenerator     | Generates raw IQ radar returns               | Physics (delay + Doppler)       |
| NoiseModel          | Adds realistic noise                         | Gaussian noise                  |
| FFTProcessor        | Range + Doppler processing                   | Digital Signal Processing       |
| CFARDetector        | Constant False Alarm Rate detection          | Target detection in noise       |
| KalmanTracker       | Multi-target tracking                        | State estimation                |
| Visualizer          | Console + CSV output                         | Visualization                   |
| Benchmark           | Performance measurement                      | Engineering metrics             |

## Physics & Mathematics
- **Range**: `R = (c × τ) / 2`
- **Doppler Shift**: `fd = 2v / λ`
- **IQ Signal**: `s(t) = A × exp(j × 2π(fc(t-delay) + fd×t))`
- **CA-CFAR**: Adaptive threshold based on local noise cells

## How to Build & Run

```bash
mkdir -p build data
cd build
cmake ..
make -j4
./radar_sim

# Visualization
cd ..
python3 plot_results.py
Learning Outcomes

Understanding of radar signal processing chain
C++ performance optimization
DSP concepts (FFT, complex numbers, noise)
Kalman filtering for tracking
Professional project structure & documentation

Built as a B.Tech portfolio project to demonstrate aerospace-grade signal processing knowledge.
Made with ❤️ for defense/aerospace enthusiasts.
