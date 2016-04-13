//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_NEURON_H
#define JAMAISVU_NEURON_H

#include "../util/randomUtil.h"
#include <vector>
#include <algorithm>

class Gene;     // Guess this works (?)
class Neuron {
private:
    std::vector<Gene*> inputGenes;
    std::vector<Gene*> outputGenes;

    bool deleteInputGene(Gene* gene);
    bool deleteOutputGene(Gene* gene);
public:
    Neuron() {};

    double threshold;

    unsigned long long int getGeneAmount();

    void receiveFrom(Gene* inputGene);
    void sendTo(Gene* to);

    void destroy();

    void pulse(double data);

    bool disconnectGene(Gene* gene);
    Gene* disconnectGene();             // Disconnects random gene
};


#endif //JAMAISVU_NEURON_H
