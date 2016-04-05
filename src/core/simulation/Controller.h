//
// Created by chemicalchems on 5/04/16.
//

#ifndef JAMAISVU_CONTROLLER_H
#define JAMAISVU_CONTROLLER_H

#include "Player.h"
#include "Simulation.h"

class Controller {
    Controller (Simulation& simulation);
    Simulation& simulation;
    Player& player;
};


#endif //JAMAISVU_CONTROLLER_H
