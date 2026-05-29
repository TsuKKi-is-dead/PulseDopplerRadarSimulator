#include "Benchmark.h"
#include <iostream>
void Benchmark::start(const std::string& n) { name = n; start_time = std::chrono::high_resolution_clock::now(); }
void Benchmark::stop() {
    auto end = std::chrono::high_resolution_clock::now();
    double ms = std::chrono::duration<double,std::milli>(end-start_time).count();
    std::cout << name << " took " << ms << " ms\n";
}
