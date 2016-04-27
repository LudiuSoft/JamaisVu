//
// Created by chemicalchems on 29/03/16.
//

#include "Neuron.h"
#include "Gene.h"

void Neuron::receiveFrom(Gene* inputGene){
    inputGenes.push_back(inputGene);
}

void Neuron::sendTo(Gene* outputGene) {
    outputGenes.push_back(outputGene);
}

bool Neuron::deleteInputGene(Gene *gene) {
    auto it = std::find(inputGenes.begin(), inputGenes.end(), gene);
    if (it != inputGenes.end()) {
        inputGenes.erase(it);
        return true;
    } else
        return false;
}

bool Neuron::deleteOutputGene(Gene *gene) {
    auto it = std::find(outputGenes.begin(), outputGenes.end(), gene);
    if (it != outputGenes.end()) {
        outputGenes.erase(it);
        return true;
    } else
        return false;
}

bool Neuron::disconnectGene(Gene* gene) {
    return deleteInputGene(gene) || deleteOutputGene(gene);
}

Gene* Neuron::disconnectGene() {
    unsigned int pointer = (unsigned int) (randomValueFromInterval(double(0.0), double(1.0)) * getGeneAmount());
    Gene *toReturn;
    if (pointer < inputGenes.size()) {
        toReturn = inputGenes.at(pointer);
        inputGenes.erase(inputGenes.begin() + pointer);
    } else {
        toReturn = outputGenes.at(pointer - inputGenes.size());
        outputGenes.erase(outputGenes.begin() + (pointer - inputGenes.size()));
    }
    return toReturn;
}

unsigned long long int Neuron::getGeneAmount() {
    return inputGenes.size()+outputGenes.size();
}

void Neuron::destroy() {
    unsigned int size = (unsigned int)inputGenes.size();
    while (size!=0) {
        size--;
        inputGenes.at(size)->destroy();
    }
    size = (unsigned int)outputGenes.size();
    while (size!=0) {
        size--;
        outputGenes.at(size)->destroy();
    }
}
