//
// Created by chemicalchems on 29/03/16.
//

#include "Neuron.h"

Neuron::Neuron() {
    inputGenes, outputGenes = std::list<Gene*>();

    data = 0.0;
    cleared = false;
    threshold = 1.0;
    signalStrength = 0.5;
}

void Neuron::receiveFrom(Gene* inputGene){
    inputGenes.push_back(inputGene);
}

void Neuron::sendTo(Gene* outputGene) {
    outputGenes.push_back(outputGene);
}

// TODO: READ TODO BELOW
bool Neuron::deleteInputGene(Gene* gene) {
    int size = inputGenes.size();
    auto test = inputGenes.begin();
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

// TODO (BUG): inputGenes and outputGenes try to get read at this point, somehow they get messed up somewhere
// The iterators of .begin() and end() are messed up, the list itself is filled with enormous amounts of data
bool Neuron::disconnectGene(Gene* gene) {
    return deleteInputGene(gene) || deleteOutputGene(gene);
}

unsigned long long int Neuron::getGeneAmount() {
    return inputGenes.size() + outputGenes.size();
}

void Neuron::destroy() {
    auto geneIterator = inputGenes.begin();
    while (inputGenes.size() != 0 && geneIterator != inputGenes.end()) {
        (*geneIterator)->destroy();
        std::advance(geneIterator, 1);
    }
    geneIterator = outputGenes.begin();
    while (outputGenes.size() != 0 && geneIterator != outputGenes.end()) {
        (*geneIterator)->destroy();
        std::advance(geneIterator, 1);
    }
}

bool Neuron::containsConnectionFrom(Neuron &inputNeuron) {
    for (Gene *gene : inputGenes) {
        if (gene->getInputNeuron() == &inputNeuron)
            return true;
    }
    return false;
}

bool Neuron::containsConnectionTo(Neuron &outputNeuron) {
    for (Gene *gene : outputGenes) {
        if (gene->getOutputNeuron() == &outputNeuron)
            return true;
    }
    return false;
}

void Neuron::pulse(double data) {
    if (cleared) cleared = false;
    if (data > threshold) return;   // Avoids circular network circles
    this->data += data;
    if (data > threshold) {         // Bigger than threshold, fires signal to all outputGenes
        for (Gene* gene : outputGenes) {
            gene->pulse(signalStrength);
        }
    }
}

void Neuron::resetData() {
    data = 0.0;
    cleared = true;
    for (Gene* gene : outputGenes) {
        if (!gene->getOutputNeuron()->cleared)
            gene->getOutputNeuron()->resetData();
    }
}

double Neuron::getSendingSignalStrength() {
    return data>threshold?signalStrength:0;
}
