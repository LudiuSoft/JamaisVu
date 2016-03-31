//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_PLAYER_H
#define JAMAISVU_PLAYER_H

#include <random>
#include <functional>
#include <iostream>


class Player {
public:
    Player();

    bool alive;
    float hunger;
    float thirst;
    float exhaustion;
    unsigned int foodCount;
    unsigned int waterCount;
    std::mt19937 rnd;


    void updateStats(int deltaTime);
    void forage(double findFoodProbability, double findWaterProbability); //TODO in src file Player.cpp
    void drink();
    void eat();
    void sleep();
    void doNothing();
};


#endif //JAMAISVU_PLAYER_H
