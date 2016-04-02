//
// Created by IPat (Local) on 28.03.2016.
//

#include "Generation.h"

Generation::Generation() {

}

Generation::Generation(unsigned int speciesPerGen, unsigned int genomesPerSpecies)
{
    if (species.size()!=0)
        species = std::vector<Species>();
    while (speciesPerGen !=0)
    {
        species.push_back(Species(genomesPerSpecies));
        speciesPerGen--;
    }
}

void Generation::evolve(unsigned double mutation)
{
    for (Species uniqueSpecies : species)
    {
        uniqueSpecies.evolve(mutation);
    }
}

void Generation::setInputNeurons(std::vector<Neuron> &input) {
    inputNeurons = input;
}

void Generation::setOutputNeurons(std::vector<Neuron> &output) {
    outputNeurons = output;
}

std::vector<Neuron> Generation::getInputNeurons() {
    return inputNeurons;
}

std::vector<Neuron> Generation::getOutputNeurons() {
    return outputNeurons;
}
