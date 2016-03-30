//
// Created by IPat (Local) on 28.03.2016.
//

#include "Species.h"

Species::Species()
{

}

// Note: Rethink this process. Do I want the genes to have a fitness? The genes vary from species to species. They are independent.
// A gene also won't have a fitness, only a species for how far it came (or will a gene actually for how it influenced the overall fitness?)
// TODO: OVERTHINK, MAYBE I GOT A REVOLUTIONARY IDEA FOR A PUNISH AND EARN SYSTEM HERE

double Species::getAverageFitness()
{
    int totalFitness = 0;
    for (Gene& gene : genes)
    {
        totalFitness += gene.fitness;
    }

    return totalFitness/genes.size();
}