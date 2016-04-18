//
// Created by IPat (Local) on 28.03.2016.
//

#include "Gene.h"
#include "Neuron.h"

Gene::Gene(Neuron& input, Neuron& output)
{
    input.sendTo(this);
    output.receiveFrom(this);
    this->input = &input;
    this->output = &output;
    invert = false;
    weight = 0.7;
}

void Gene::destroy() {
    input->disconnectGene(this);
    output->disconnectGene(this);
}

Neuron *Gene::getInputNeuron() {
    return input;
}

Neuron *Gene::getOutputNeuron() {
    return output;
}

void Gene::pulse(double data) {
    output->pulse((invert ? -1 : 1) * data * weight);
}
