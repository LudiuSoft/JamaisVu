//
// Created by chemicalchems on 5/04/16.
//

#ifndef JAMAISVU_NETWORK_H
#define JAMAISVU_NETWORK_H

#include <vector>
#include "Neuron.h"
#include "Genome.h"

class Network {
    std::vector<Neuron> inputNeurons;
    std::vector<Neuron> intermediateNeurons;
    std::vector<Neuron> outputNeurons;

    Genome& genome;

    Network(Genome& genome);
};


#endif //JAMAISVU_NETWORK_H
