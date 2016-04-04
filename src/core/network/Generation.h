//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_GENERATION_H
#define JAMAISVU_GENERATION_H

#include "Species.h"
#include <vector>

class Generation {
private:
    std::vector<Species> species;

    std::vector<Neuron> emptyNeuronVector;

    std::vector<Neuron> inputNeurons = emptyNeuronVector;
    std::vector<Neuron> outputNeurons = emptyNeuronVector;
public:
    Generation();
    Generation(unsigned int speciesPerGen, unsigned int genomesPerSpecies);     // Constructor for outer calls

    void setInputNeurons(std::vector<Neuron>& input);
    void setOutputNeurons(std::vector<Neuron>& output);

    std::vector<Neuron> getInputNeurons();
    std::vector<Neuron> getOutputNeurons();

    void evolve(double addRemoveMutation, double geneWeightMutation);
};


#endif //JAMAISVU_GENERATION_H
