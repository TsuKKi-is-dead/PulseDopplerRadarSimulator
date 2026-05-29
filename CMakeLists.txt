cmake_minimum_required(VERSION 3.16)
project(PulseDopplerRadarSimulator CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(radar_sim 
    main.cpp
    src/ScenarioGenerator.cpp
    src/SignalGenerator.cpp
    src/NoiseModel.cpp
    src/FFTProcessor.cpp
    src/CFARDetector.cpp
    src/KalmanTracker.cpp
    src/Visualizer.cpp
    src/Benchmark.cpp
)

target_include_directories(radar_sim PRIVATE include)
