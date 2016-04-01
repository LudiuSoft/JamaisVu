//
// Created by IPat (Local) on 28.03.2016.
//

#include "Generation.h"

Generation::Generation(int speciesAmount)
{
    if (species.size()!=0)
        species = std::vector<Species>();
    while (speciesAmount!=0)
    {
        species.push_back(Species());
        speciesAmount--;
    }
}

Generation::Generation(std::vector<Species> species)
{
    this->species = species;
}

Generation Generation::nextGeneration() {
    return Generation();
}

void Generation::setMutation(int mutation)
{
    this->mutation = mutation;
}