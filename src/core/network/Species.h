//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_SPECIES_H
#define JAMAISVU_SPECIES_H

#include "Gene.h"
#include "Neuron.h"
#include <iostream>

class Species {
private:
    std::vector<Gene> genes;
    std::vector<Neuron> d;
public:
    Species();


    double getAverageFitness();
};


#endif //JAMAISVU_SPECIES_H
