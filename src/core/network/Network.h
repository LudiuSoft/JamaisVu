//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_NETWORK_H
#define JAMAISVU_NETWORK_H

#include <iostream>
#include "Generation.h"

class Network {
public:
    Network(Generation);
    Generation currentGeneration = nullptr;     // Necessary, otherwise it'd use the default constructor (Unnecessary performance waste)
};

#endif //JAMAISVU_NETWORK_H
