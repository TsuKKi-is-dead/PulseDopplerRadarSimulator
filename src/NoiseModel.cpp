#include "NoiseModel.h"
#include <random>
#include <cmath>
void NoiseModel::addNoise(CPIData& cpi, double snr_db) {
    std::mt19937 gen(std::random_device{}());
    double sigma = 1.0 / std::sqrt(std::pow(10.0, snr_db/20.0));
    std::normal_distribution<double> dist(0.0, sigma);
    for (auto& pulse : cpi)
        for (auto& s : pulse)
            s += Complex(dist(gen), dist(gen));
}
