//
// Created by chemicalchems on 29/03/16.
//

/* TODO: Fine-tune action hunger, thirst, and exhaustion deltas */

#ifndef JAMAISVU_PLAYER_H
#define JAMAISVU_PLAYER_H

class Simulation; //forward declaration of Simulation to solve circular dependency

#include <random>
#include <iostream>
#include "../util/Delta.h"

class Player {
public:
    float hunger;
    float thirst;
    float exhaustion;
    unsigned int foodCount;
    unsigned int waterCount;
    std::mt19937 rnd;
    Simulation& simulation;

    Player(Simulation& simulation);
    bool isAlive();
    void forage();
    void drink();
    void setThirst (Delta<double> deltaThrist);
    void eat();
    void setHunger (Delta<double> deltaHunger);
    void sleep();
    void setExhaustion (Delta<double> deltaExhaustion);
    void doNothing();
};


#endif //JAMAISVU_PLAYER_H
