//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_PLAYER_H
#define JAMAISVU_PLAYER_H



class Player {
    Player();

    bool alive;
    float hunger;
    float thirst;
    float exhaustion;
    int foodCount;
    int waterCount;

    void forage();
    void drink();
    void eat();
    void sleep();
};


#endif //JAMAISVU_PLAYER_H
