//
// Created by IPat (Local) on 01.04.2016.
//

#ifndef JAMAISVU_GENOME_H
#define JAMAISVU_GENOME_H

#include <list>
#include "Neuron.h"
#include "../util/Delta.h"

class Genome {
private:
public:
    std::list<Gene> genes;
    std::list<Neuron> neurons;
    Genome() {};
    Genome(std::list<Neuron> inputNeurons, std::list<Neuron> outputNeurons);
    Genome(const Genome& obj);

    std::list<Neuron> inputNeurons;
    std::list<Neuron> outputNeurons;

    int fitness = 0;
    void mutate(double addRemoveMutation, Delta<double> geneWeightMutation, Delta<double> totalNeuronThresholdDelta, Delta<double> totalNeuronSignalStrengthDelta);

    /*bool operator > (const Genome& g1) const { return (fitness > g1.fitness); }
    int operator- (const Genome& g1) const { return (fitness - g1.fitness); }
    Genome& operator = (Genome&& obj);
    Genome& operator = (const Genome& obj);*/

    unsigned int getRandomGeneIndex();
    unsigned int getRandomNeuronIndex();

    std::list<Neuron*> getReceivableNeurons();
    std::list<Neuron*> getSendableNeurons();

    void clearNetworkData();
};


#endif //JAMAISVU_GENOME_H
