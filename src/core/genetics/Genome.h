//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_GENOME_H
#define JAMAISVU_GENOME_H

#include "Gene.h"
#include <vector>

class Genome {
public:
    std::vector<Gene> genes;
    int fitness;
};


#endif //JAMAISVU_GENOME_H
