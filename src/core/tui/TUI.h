//
// Created by chemicalchems on 5/04/16.
//

#ifndef JAMAISVU_TUI_H
#define JAMAISVU_TUI_H

#include "Console.h"
#include "../simulation/Simulation.h"

class TUI {
    Console console;
    std::vector<Simulation> simulations;

    void drawSimulation(Simulation simulation);
    void drawFrames();
};


#endif //JAMAISVU_TUI_H
