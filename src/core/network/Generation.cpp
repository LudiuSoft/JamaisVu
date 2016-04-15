//
// Created by IPat (Local) on 28.03.2016.
//

#include <iostream>
#include "Generation.h"
#include "../util/toStr.h"

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

int* Generation::mutate(double networkChangeFactor, Delta<double> totalGeneWeightDelta,
                        Delta<double> totalNeuronThresholdDelta, Delta<double> totalNeuronSignalStrengthDelta,
                        unsigned int indexSpecies, unsigned int indexGenomes) {

    return species.at(indexSpecies).evolve(networkChangeFactor, totalGeneWeightDelta, totalNeuronThresholdDelta, totalNeuronSignalStrengthDelta, indexGenomes);
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

void Generation::nextGen() {
    std::cout << "GENERATION " << toStr(generation) << ":" << std::endl << std::endl;
    for (unsigned int a = 0; a < species.size(); a++) {
        std::cout << "Species " << toStr(a + 1) << ": " << toStr(species.at(a).getAverageFitness()) << std::endl;
        species.at(a).nextGen(0.2);
    }
    generation++;
}
