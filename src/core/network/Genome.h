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

class Genome {
private:
    std::vector<Gene> genes;
    std::vector<Neuron> neurons;

    std::vector<Neuron> emptyVector;
    std::vector<Neuron>& inputNeurons = emptyVector;
    std::vector<Neuron>& outputNeurons = emptyVector;
public:
    Genome() {};
    Genome(std::vector<Neuron>& inputNeurons, std::vector<Neuron>& outputNeurons);

    int fitness;
    void mutate(double addRemoveMutation, double geneWeightMutation);

    bool operator > (const Genome& g1) const { return (fitness > g1.fitness); }
};


#endif //JAMAISVU_GENOME_H
