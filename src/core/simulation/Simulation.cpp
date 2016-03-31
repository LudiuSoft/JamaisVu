//
// Created by chemicalchems on 29/03/16.
//

#include "Simulation.h"
#include <iostream>

Simulation::Simulation()
{
    this->start();
}

Simulation::~Simulation()
{
    this->end();
}

void Simulation::start()
{
    this->thread = std::thread(Simulation::loop);
}

void Simulation::end()
{
    this->thread.join();
}

void Simulation::loop()
{
    std::cout << "lol\n";
}



