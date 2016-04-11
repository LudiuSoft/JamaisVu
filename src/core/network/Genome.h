//
// Created by IPat (Local) on 01.04.2016.
//

#ifndef JAMAISVU_GENOME_H
#define JAMAISVU_GENOME_H

#include <vector>
#include "Gene.h"

class Genome {
private:
    std::vector<Gene> genes;
    std::vector<Neuron> neurons;

    std::vector<Neuron> inputNeurons;
    std::vector<Neuron> outputNeurons;
public:
    Genome() {};
    Genome(std::vector<Neuron>& inputNeurons, std::vector<Neuron>& outputNeurons);
    Genome(const Genome& obj);

    int fitness;
    void mutate(double addRemoveMutation, double geneWeightMutation);

    bool operator > (const Genome& g1) const { return (fitness > g1.fitness); }
    Genome& operator = (Genome&& obj);
    Genome& operator = (const Genome& obj);
};


#endif //JAMAISVU_GENOME_H
