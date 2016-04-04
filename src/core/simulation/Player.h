//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_PLAYER_H
#define JAMAISVU_PLAYER_H

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

    Player();
    void forage(double findFoodProbability, double findWaterProbability); //TODO in src file Player.cpp
    void drink();
    void setThrist (Delta<double> deltaThrist);
    void eat();
    void setHunger (Delta<double> deltaHunger);
    void sleep();
    void setExhaustion (Delta<double> deltaExhaustion);
    void doNothing();
    void isAlive();
};


#endif //JAMAISVU_PLAYER_H
