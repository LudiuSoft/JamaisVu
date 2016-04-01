//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_GENE_H
#define JAMAISVU_GENE_H

#include "Neuron.h"

class Gene {
private:
    double fitness;
/*
    Neuron& input;
    Neuron& output;*/

    bool invert;
    double weight;
public:
    Gene();
};


#endif //JAMAISVU_GENE_H
