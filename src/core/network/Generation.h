//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_GENERATION_H
#define JAMAISVU_GENERATION_H

#include "Species.h"
#include <vector>

class Generation {
private:
    std::vector<Species> species;
    int mutation;
public:
    Generation(int speciesAmount);      // Simple initiator for Network
    Generation(std::vector<Species>);   // Used for "nextGeneration" function

    Generation nextGeneration();        // Creates follow-up generation

    void setMutation(int);              // Redefines mutation value
};


#endif //JAMAISVU_GENERATION_H
