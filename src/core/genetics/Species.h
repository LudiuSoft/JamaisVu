//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_SPECIES_H
#define JAMAISVU_SPECIES_H

#include "Genome.h"
#include <iostream>

class Species {
public:
    Species(std::string _name);

    std::string name;
    std::vector<Genome> genomes;

    double getAverageFitness();
    void setName(std::string _name);
    const std::string& getName() const;

};


#endif //JAMAISVU_SPECIES_H
