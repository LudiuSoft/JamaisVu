//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_SIMULATION_H
#define JAMAISVU_SIMULATION_H

#include <thread>
#include "Player.h"

class Simulation {
public:
    bool paused;
    bool isDay;
    int round = 0;
    double findFoodProbability;
    double findWaterProbability;
    std::thread thread;
    Player player;

    Simulation();
    void start();
    void pause();
    void resume();
    void endSimulationIfDead();
    void end();
    static void threadCode(Simulation* simulation);
};


#endif //JAMAISVU_SIMULATION_H
