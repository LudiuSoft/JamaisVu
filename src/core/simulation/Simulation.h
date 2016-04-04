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
    ~Simulation();

    bool paused;
    double findFoodProbability;
    double findWaterProbability;
    std::thread thread;

    Player player;
    void start();
    void pause();
    void resume();
    void end();
    void updatePlayerStats(int deltaTime);
    static void loop();

};


#endif //JAMAISVU_SIMULATION_H
