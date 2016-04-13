//
// Created by IPat (Local) on 28.03.2016.
//

#include "Generation.h"

Generation::Generation() {

}

Generation::Generation(unsigned int speciesPerGen, unsigned int genomesPerSpecies, std::list<Neuron>& inputNeurons, std::list<Neuron>& outputNeurons)
{
    if (species.size()!=0)
        species = std::vector<Species>();
    while (speciesPerGen !=0)
    {
        species.push_back(Species(genomesPerSpecies, inputNeurons, outputNeurons));
        speciesPerGen--;
    }
}

void Generation::evolve(double networkChangeFactor, Delta<double> totalGeneWeightDelta, Delta<double> totalNeuronThresholdDelta)
{
    for (Species uniqueSpecies : species)
    {
        uniqueSpecies.evolve(networkChangeFactor, totalGeneWeightDelta, totalNeuronThresholdDelta);
    }
}

void Generation::setInputNeurons(std::vector<Neuron> &input) {
    inputNeurons = &input;
}

void Generation::setOutputNeurons(std::vector<Neuron> &output) {
    outputNeurons = &output;
}

std::vector<Neuron> Generation::getInputNeurons() {
    return *inputNeurons;
}

std::vector<Neuron> Generation::getOutputNeurons() {
    return *outputNeurons;
}
