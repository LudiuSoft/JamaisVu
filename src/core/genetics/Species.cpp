//
// Created by IPat (Local) on 28.03.2016.
//

#include "Species.h"

Species::Species(std::string _name)
{
    this->name = _name;
}

double Species::getAverageFitness()
{
    int totalFitness = 0;
    for (Genome& genome : genomes)
    {
        totalFitness += genome.fitness;
    }
    return totalFitness/genomes.size();
}

void Species::setName(std::string _name)
{
    this->name = _name;
}

const std::string& Species::getName() const
{
    return this->name;
}
