//
// Created by chemicalchems on 29/03/16.
//

#include "Neuron.h"
#include "Gene.h"

Neuron::Neuron() {
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
    unsigned int pointer = (unsigned int) (random0to1() * getGeneAmount());
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
    return inputGenes.size() + outputGenes.size();
}

void Neuron::destroy() {
    unsigned int size = (unsigned int) inputGenes.size();
    while (size != 0) {
        size--;
        inputGenes.at(size)->destroy();
    }
    size = (unsigned int) outputGenes.size();
    while (size != 0) {
        size--;
        outputGenes.at(size)->destroy();
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
