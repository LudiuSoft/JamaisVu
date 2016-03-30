//
// Created by chemicalchems on 29/03/16.
//

#include "Simulation.h"
#include <iostream>

Simulation::Simulation()
{
    t1 = std::thread(Simulation::loop);
}

void Simulation::loop()
{
    std::cout << "lol\n";
}