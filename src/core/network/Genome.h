//
// Created by IPat (Local) on 01.04.2016.
//

#ifndef JAMAISVU_GENOME_H
#define JAMAISVU_GENOME_H

#include <vector>
#include "Gene.h"

class Genome {
private:
    std::vector<Gene> genes;
    std::vector<Neuron> neurons;
public:
    Genome() {};

    void mutate(unsigned double mutation);
};


#endif //JAMAISVU_GENOME_H
