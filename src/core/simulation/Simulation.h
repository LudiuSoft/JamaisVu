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
    double findFoodProbability;
    double findWaterProbability;
    std::thread thread;
    Player player;

    Simulation();
    ~Simulation();
    void start();
    void pause();
    void resume();
    void endSimulationIfDead();
    void end();
    static void loop();

};


#endif //JAMAISVU_SIMULATION_H
