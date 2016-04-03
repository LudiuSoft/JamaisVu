//
// Created by IPat (Local) on 01.04.2016.
//

#ifndef JAMAISVU_GENOME_H
#define JAMAISVU_GENOME_H

#include <vector>
#include "Gene.h"
#include <stdlib.h>
#include <random>
#include <time.h>

// TODO: I think this causes the compiler error...
#include "Generation.h"

class Genome {
private:
    std::vector<Gene> genes;
    std::vector<Neuron> neurons;

    Generation* originalGeneration;
public:
    Genome() {};
    Genome(Generation* originalGeneration);

    int fitness;
    void mutate(double addRemoveMutation, double geneWeightMutation);

    bool operator > (const Genome& g1) const { return (fitness > g1.fitness); }
};


#endif //JAMAISVU_GENOME_H
