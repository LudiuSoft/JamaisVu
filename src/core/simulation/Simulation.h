//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_SIMULATION_H
#define JAMAISVU_SIMULATION_H

#include <thread>
#include "Player.h"

class Simulation {
public:
    Simulation();

    bool paused;

    void start();
    void pause();
    void resume();
    void end();
    static void loop();
    std::thread t1;

};


#endif //JAMAISVU_SIMULATION_H
