//
// Created by IPat (Local) on 28.03.2016.
//

#include "Species.h"

Species::Species(unsigned int limit)
{
    setGenomeLimit(limit);
    while (limit!=0)
    {
        genomes.push_back(Genome());
        limit--;
    }
}

Species::Species(std::vector<Genome> genomes)
{
    setGenomeLimit(genomes.size());
    this->genomes = genomes;
}

void Species::setGenomeLimit(unsigned int limit)
{
    this->maxGenomes = limit;
}

void Species::evolve(unsigned double mutation) {
    for (Genome genome : genomes)
    {
        genome.mutate(mutation);
    }
}

std::vector<Genome> Species::getBestGenomes(double percentage) { }

std::vector<Genome> Species::getBestGenomes(int amount) { }

