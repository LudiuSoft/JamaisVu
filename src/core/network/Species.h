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
    unsigned int maxGenomes;
public:
    Species() {};
    Species(unsigned int limit, std::vector<Neuron> (&)(), std::vector<Neuron> (&)());
    Species(std::vector<Genome> genomes);

    void setGenomeLimit(unsigned int limit);

    std::vector<Genome> getBestGenomes(unsigned int amount);
    std::vector<Genome> getBestGenomes(double percentage);

    void evolve(double addRemoveMutation, double geneWeightMutation);
};


#endif //JAMAISVU_SPECIES_H
