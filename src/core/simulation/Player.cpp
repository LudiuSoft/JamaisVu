//
// Created by chemicalchems on 29/03/16.
//

#include "Player.h"

Player::Player() {
    rnd = std::mt19937(time(0));
    this->exhaustion=0.f;
    this->thirst=0.f;
    this->foodCount=0;
    this->hunger=0.f;
    this->waterCount=0;
}

void setThirst(Delta<double> deltaThirst)
{

}

void Player::forage(double findFoodProbability, double findWaterProbability) { //TODO: Make method capture args from the simulation the player is in
    std::uniform_real_distribution<double> foundSomethingDist (0,1);
    bool foundFood  = (foundSomethingDist(rnd) <= findFoodProbability);
    bool foundWater = (foundSomethingDist(rnd) <= findWaterProbability);

    if (foundFood) {this->foodCount++;}
    if (foundWater) {this->waterCount++;}

    this->exhaustion += 0.05;
    this->hunger += 0.075;
    this->thirst += 0.1;


}

void Player::drink() {
    if (waterCount = 0) { std::cout << "No water left, can't drink!";}
    else
    {

    }

}