//
// Created by chemicalchems on 29/03/16.
//

#include "Player.h"
#include "Simulation.h"
#include <chrono>

Player::Player(Simulation& simulation) : simulation(simulation) {
    rnd = std::mt19937(time(0));
    this->exhaustion=0.f;
    this->thirst=0.f;
    this->foodCount=0;
    this->hunger=0.f;
    this->waterCount=0;
}

bool Player::isAlive() {
    if (thirst < 1 && hunger < 1 && exhaustion < 1) {return true;}
    else                                            {return false;}
}

void Player::setThirst(Delta<double> deltaThirst) {
    this->thirst += deltaThirst;
    if (thirst<0) {thirst = 0;}
}

void Player::setHunger(Delta<double> deltaHunger) {
    this->hunger += deltaHunger;
    if (hunger<0) {hunger = 0;}
}

void Player::setExhaustion(Delta<double> deltaExhaustion) {
    this->exhaustion += deltaExhaustion;
    if (exhaustion<0) {exhaustion = 0;}
}



void Player::forage(double findFoodProbability, double findWaterProbability) { //TODO: Make method capture args from the simulation the player is in
    std::uniform_real_distribution<double> foundSomethingDist (0,1);
    bool foundFood  = (foundSomethingDist(rnd) <= findFoodProbability);
    bool foundWater = (foundSomethingDist(rnd) <= findWaterProbability);

    if (foundFood) {this->foodCount++;}
    if (foundWater) {this->waterCount++;}

    this->setThirst(0.1);
    this->setHunger(0.1);
    this->setExhaustion(0.05);
}



void Player::drink() {
    if (waterCount == 0) { std::cout << "No water left, can't drink!";}
    else
    {
        waterCount--;
        this->setThirst(-0.25);
    }
}

void Player::eat() {
    if (foodCount == 0) { std::cout << "No food left, can't eat!";}
    else
    {
        foodCount--;
        this->setHunger(-0.25);
    }
}

void Player::sleep() {
    if (simulation.isDay)
    {
        this->setThirst(0.05);
        this->setHunger(0.05);
        this->setExhaustion(-0.25);
    }
}

void Player::doNothing() {
    this->setThirst(0.05);
    this->setHunger(0.05);
    this->setExhaustion(0.025);
}
