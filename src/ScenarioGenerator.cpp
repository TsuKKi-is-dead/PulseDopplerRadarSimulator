#include "ScenarioGenerator.h"
#include "RadarConfig.h"
#include <random>
#include <iostream>

std::vector<Target> ScenarioGenerator::generateScenario() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Random number of targets: 1 to 5
    std::uniform_int_distribution<int> num_targets_dist(1, 5);
    int num_targets = num_targets_dist(gen);
    
    std::uniform_real_distribution<double> range_dist(5000.0, 48000.0);   // 5km to 48km
    std::uniform_real_distribution<double> vel_dist(-400.0, 400.0);       // -400 to +400 m/s
    std::uniform_real_distribution<double> rcs_dist(0.5, 1.3);
    
    std::vector<Target> targets;
    
    std::cout << "=== Generated " << num_targets << " Enemy Target(s) ===\n";
    
    for (int i = 0; i < num_targets; ++i) {
        double range = range_dist(gen);
        double velocity = vel_dist(gen);
        double rcs = rcs_dist(gen);
        
        targets.push_back({range, velocity, rcs});
        
        std::cout << "Enemy " << (i+1) 
                  << " → Range: " << range/1000.0 << " km | "
                  << "Velocity: " << velocity << " m/s | "
                  << "Strength: " << rcs << "\n";
    }
    
    std::cout << "\n";
    return targets;
}
