#pragma once
#include <string>
#include <chrono>
class Benchmark { public: void start(const std::string& name); void stop(); private: std::chrono::high_resolution_clock::time_point start_time; std::string name; };
