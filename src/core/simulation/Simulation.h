//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_SIMULATION_H
#define JAMAISVU_SIMULATION_H

#include <thread>
#include "Player.h"

enum SimulationDifficulty {noob, easy, medium, hard, insane};

class Simulation {
public:
    Simulation(SimulationDifficulty difficulty);
    ~Simulation();

    bool paused;
    SimulationDifficulty difficulty;
    double findFoodProbability;
    double findWaterProbability;

    std::thread thread;

    void start();
    void pause();
    void resume();
    void end();
    void setDifficulty (SimulationDifficulty _difficulty);
    static void loop();

};


#endif //JAMAISVU_SIMULATION_H
