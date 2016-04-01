//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_SPECIES_H
#define JAMAISVU_SPECIES_H

#include "Genome.h"
#include "Gene.h"
#include "Neuron.h"
#include <vector>

class Species {
private:
    std::vector<Genome> genomes;
public:
    Species();

    std::vector<Gene> getBestGenes(int amount);
    std::vector<Gene> getBestGenes(double percentage);
};


#endif //JAMAISVU_SPECIES_H
