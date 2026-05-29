# Pulse-Doppler Radar Signal Processing Simulator

**A realistic C++ implementation of a Pulse-Doppler radar processing pipeline** — built as a strong aerospace/defense portfolio project for learning and demonstration.

## ✨ Features

- Realistic IQ signal generation using physics (range delay + Doppler effect)
- Additive White Gaussian Noise (AWGN) simulation
- 2D Range-Doppler Map generation via FFT
- CA-CFAR target detection algorithm
- Kalman-style target tracking
- Beautiful animated visualization with Python + Matplotlib
- Performance benchmarking
- Real X-band radar parameters (10 GHz)

## 📁 Project Structure
PulseDopplerRadarSimulator/
├── main.cpp
├── CMakeLists.txt
├── README.md
├── plot_results.py              # Beautiful animated radar display
├── include/                     # Header files
├── src/                         # Source code implementations
├── data/                        # Output files (ignored)
├── docs/                        # Documentation
└── .gitignore
text## 🚀 How to Build & Run

```bash
# 1. Build the C++ simulator
mkdir -p build data
cd build
cmake ..
make -j4
./radar_sim

# 2. Launch beautiful animated visualization
cd ..
/opt/anaconda3/bin/python3 plot_results.py     # or python3 plot_results.py
🧠 Modules Overview


















































ModulePurposeKey ConceptsRadarConfigRadar parametersX-band, PRF, CPI, SamplingScenarioGeneratorCreate enemy targetsSimulation scenarioSignalGeneratorGenerate raw IQ radar echoesPhysics, Delay, Doppler, IQNoiseModelAdd realistic noiseGaussian Noise, SNRFFTProcessorRange-Doppler processingFFT, Frequency DomainCFARDetectorTarget detection in noiseCA-CFAR, Adaptive ThresholdKalmanTrackerTrack targets over timeState estimation, SmoothingVisualizerConsole output + animated plotVisualization
📚 Physics & Mathematics

Range: R = (c × τ) / 2
Doppler Shift: fd = 2v / λ
IQ Signal: s(t) = A × exp(j × 2π [fc(t-delay) + fd×t])
CA-CFAR: Adaptive threshold based on local noise cells

🎯 Learning Outcomes

Understanding modern radar signal processing chain
Digital Signal Processing (FFT, Complex Numbers, IQ data)
Detection theory (CFAR)
Target tracking algorithms
Professional C++ project architecture and documentation


Repository: PulseDopplerRadarSimulator
Made with ❤️ for Aerospace, Defense & Signal Processing enthusiasts.

Built as a B.Tech portfolio project.
