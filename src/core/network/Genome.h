//
// Created by IPat (Local) on 01.04.2016.
//

#ifndef JAMAISVU_GENOME_H
#define JAMAISVU_GENOME_H

#include <list>
#include "Gene.h"
#include "../util/Delta.h"

class Genome {
private:
    std::list<Gene> genes;
    std::list<Neuron> neurons;

    std::list<Neuron> inputNeurons;
    std::list<Neuron> outputNeurons;
public:
    Genome() {};
    Genome(std::list<Neuron>& inputNeurons, std::list<Neuron>& outputNeurons);
    Genome(const Genome& obj);

    int fitness;
    void mutate(double addRemoveMutation, Delta<double> geneWeightMutation, Delta<double> totalNeuronThresholdDelta);

    bool operator > (const Genome& g1) const { return (fitness > g1.fitness); }
    Genome& operator = (Genome&& obj);
    Genome& operator = (const Genome& obj);

    unsigned int getRandomGeneIndex();
    unsigned int getRandomNeuronIndex();

    std::list<Neuron*> getReceivableNeurons();
    std::list<Neuron*> getSendableNeurons();
};


#endif //JAMAISVU_GENOME_H
