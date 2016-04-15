//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_GENERATION_H
#define JAMAISVU_GENERATION_H

#include "Species.h"
#include "../util/Delta.h"
#include <list>

class Generation {
private:
    std::vector<Neuron>* inputNeurons;
    std::vector<Neuron>* outputNeurons;
public:
    int generation = 1;

    std::vector<Species> species;

    Generation();
    Generation(unsigned int speciesPerGen, unsigned int genomesPerSpecies, std::list<Neuron>& inputNeurons, std::list<Neuron>& outputNeurons);

    void setInputNeurons(std::vector<Neuron>& input);
    void setOutputNeurons(std::vector<Neuron>& output);

    std::vector<Neuron> getInputNeurons();
    std::vector<Neuron> getOutputNeurons();

    int* mutate(double networkChangeFactor, Delta<double> totalGeneWeightDelta, Delta<double> totalNeuronThresholdDelta,
               Delta<double> totalNeuronSignalStrengthDelta, unsigned int indexSpecies, unsigned int indexGenomes);

    void nextGen();
};


#endif //JAMAISVU_GENERATION_H
