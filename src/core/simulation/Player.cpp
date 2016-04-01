//
// Created by chemicalchems on 29/03/16.
//

#include "Player.h"
#include "Simulation.h"

Player::Player()
{
    rnd = std::mt19937(time(0));
    this->exhaustion=0;
    this->thirst=0;
    this->foodCount=0;
    this->hunger=0;
    this->waterCount=0;
    this->alive=true;
}

void Player::forage(double findFoodProbability, double findWaterProbability) //TODO: Make method capture args from the simulation the player is in
{
    std::uniform_real_distribution<double> foundSomethingDist (0,1);
    bool foundFood  = (foundSomethingDist(rnd) <= findFoodProbability);
    bool foundWater = (foundSomethingDist(rnd) <= findWaterProbability);
    if (foundFood) { std::cout << "Found food\n";}
    if (foundWater){ std::cout << "Found water\n";}
    if (!foundFood && !foundWater) { std::cout << "Nothing found!\n";}
}