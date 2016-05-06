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
    std::list<Neuron>* inputNeurons;
    std::list<Neuron>* outputNeurons;
public:
    int generation = 1;

    std::list<Species> species;

    Generation();
    Generation(unsigned int speciesPerGen, unsigned int genomesPerSpecies, std::list<Neuron>& inputNeurons, std::list<Neuron>& outputNeurons);

    void setInputNeurons(std::list<Neuron>& input);
    void setOutputNeurons(std::list<Neuron>& output);

    std::list<Neuron> getInputNeurons();
    std::list<Neuron> getOutputNeurons();

    void mutate(double networkChangeFactor, Delta<double> totalGeneWeightDelta, Delta<double> totalNeuronThresholdDelta,
               Delta<double> totalNeuronSignalStrengthDelta, unsigned int indexSpecies, unsigned int indexGenomes);

    void nextGen();
};


#endif //JAMAISVU_GENERATION_H
