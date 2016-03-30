//
// Created by IPat (Local) on 28.03.2016.
//

#include "Generation.h"

Generation::Generation(int speciesAmount)
{
    if (species.size()!=0)
        species = std::vector<Species>();
    for (int a=0; a<speciesAmount; a++)
    {
        species.push_back(Species());
    }
}

Generation::Generation(std::vector<Species> species)
{
    this->species = species;
}

void Generation::setMutation(int mutation)
{
    this->mutation = mutation;
}