//
// Created by IPat (Local) on 28.03.2016.
//

#include "Gene.h"

Gene::Gene(Neuron& input, Neuron& output)
{
    this->input = &input;
    this->output = &output;
    invert = true;
    weight = 0.7;
}

void Gene::destroy() {
    input->disconnectGene(this);
    output->disconnectGene(this);
}
