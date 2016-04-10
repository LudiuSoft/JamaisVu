//
// Created by chemicalchems on 5/04/16.
//

#ifndef JAMAISVU_TUI_H
#define JAMAISVU_TUI_H

#include "Console.h"
#include "../simulation/Simulation.h"
#include "../util/Rect.h"

class TUI {
public:
    Console console;
    std::vector<Simulation> simulations;
    std::vector<Rect> simulationRects;

    TUI();
    void drawSimulation(Simulation simulation);
    void drawFrames();
};


#endif //JAMAISVU_TUI_H
