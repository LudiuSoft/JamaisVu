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
        species = std::list<Species>();
    while (speciesPerGen !=0)
    {
        species.push_back(Species(genomesPerSpecies, inputNeurons, outputNeurons));
        speciesPerGen--;
    }
}

void Generation::mutate(double networkChangeFactor, Delta<double> totalGeneWeightDelta,
                        Delta<double> totalNeuronThresholdDelta, Delta<double> totalNeuronSignalStrengthDelta,
                        unsigned int indexSpecies, unsigned int indexGenomes) {
    auto it = species.begin();
    std::advance(it, indexSpecies);
    (*it).evolve(networkChangeFactor, totalGeneWeightDelta, totalNeuronThresholdDelta, totalNeuronSignalStrengthDelta, indexGenomes);
}

void Generation::setInputNeurons(std::list<Neuron> &input) {
    inputNeurons = &input;
}

void Generation::setOutputNeurons(std::list<Neuron> &output) {
    outputNeurons = &output;
}

std::list<Neuron> Generation::getInputNeurons() {
    return *inputNeurons;
}

std::list<Neuron> Generation::getOutputNeurons() {
    return *outputNeurons;
}

void Generation::nextGen() {
    auto it = species.begin();
    int a = 0;
    while (species.size() != 0 && it != species.end()) {
        a++;
        std::cout << "Species " << toStr(a) << " Average Fitness: " << toStr((*it).getAverageFitness()) << std::endl;
        (*it).nextGen(0.2);
        std::advance(it, 1);
    }
    generation++;
}
