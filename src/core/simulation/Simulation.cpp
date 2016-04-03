//
// Created by chemicalchems on 29/03/16.
//

#include "Simulation.h"
#include <iostream>

Simulation::Simulation(SimulationDifficulty difficulty) {
    setDifficulty(difficulty);
    this->start();
}

Simulation::~Simulation() {
    this->end();
}

void Simulation::start() {
    this->thread = std::thread(Simulation::loop);
}

void Simulation::end() {
    this->thread.join();
}

void Simulation::loop() {
    std::cout << "lol\n";
}

void Simulation::setDifficulty(SimulationDifficulty _difficulty) {
    this->difficulty = _difficulty;
    switch (_difficulty)
    {
        case noob:
            findFoodProbability = findWaterProbability = 0.9;
            break;
        case easy:
            findFoodProbability = findWaterProbability = 0.7;
            break;
        case medium:
            findFoodProbability = findWaterProbability = 0.5;
            break;
        case hard:
            findFoodProbability = findWaterProbability = 0.3;
            break;
        case insane:
            findFoodProbability = findWaterProbability = 0.1;
            break;
    }
}



