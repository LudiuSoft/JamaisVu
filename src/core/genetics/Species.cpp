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

    /* TODO
     * LINE a1:
     *
     * In java, size() would return the amount of elements. If that's the case, we'd have a
     * random memory access at the LINE a2 when it reaches the point beyond the last element,
     * because of the <= operator in a1. Change it to < if I'm right, I didn't do it since I'm unsure...
     *
     * EXAMPLE: Vector ( 0, 1, 2 ) has 3 elements
     * size() = 3;              This line is what I'm unsure about
     * i=0 <= size() : true
     * i=1 <= size() : true
     * i=2 <= size() : true
     * i=3 <= size() : TRUE     (should be false, will return random memory)
     */

    for (unsigned int i = 0; i<=genomes.size(); i++)    // a1
    {
        totalFitness += genomes.at(i).fitness;          // a2
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
