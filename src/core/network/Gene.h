//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_GENE_H
#define JAMAISVU_GENE_H

class Neuron;
class Gene {
private:
    // These neurons are pointers since the actual object is stored in the instance of the Genome.
    Neuron* input;
    Neuron* output;
public:
    Gene() {};
    Gene(Neuron& input, Neuron& output);

    bool invert;
    double weight;

    Neuron* getInputNeuron();
    Neuron* getOutputNeuron();

    void destroy();

    void pulse(double data);
};


#endif //JAMAISVU_GENE_H
