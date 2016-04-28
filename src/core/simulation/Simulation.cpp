//
// Created by chemicalchems on 29/03/16.
//

#include "Simulation.h"
#include <iostream>

Simulation::Simulation() : player(*this) {
    this->start();
}

void Simulation::start() {
    this->thread = std::thread(Simulation::threadCode, this);
}

void Simulation::end() {
    this->thread.join();
}

void Simulation::threadCode(Simulation* simulation) {

}




