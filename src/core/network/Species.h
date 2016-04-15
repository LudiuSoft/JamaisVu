//
// Created by IPat (Local) on 28.03.2016.
//

#ifndef JAMAISVU_SPECIES_H
#define JAMAISVU_SPECIES_H

#include "Genome.h"
#include "Gene.h"
#include "Neuron.h"
#include <list>

class Species {
private:
    unsigned int maxGenomes;
public:
    std::vector<Genome> genomes;

    Species() {};
    Species(unsigned int limit, std::list<Neuron>& inputNeurons, std::list<Neuron>& outputNeurons);
    Species(std::vector<Genome> genomes);

    void setGenomeLimit(unsigned int limit);

    std::vector<Genome> getBestGenomes(unsigned int amount);
    std::vector<Genome> getBestGenomes(double percentage);

    int* evolve(double networkChangeFactor, Delta<double> totalGeneWeightDelta, Delta<double> totalNeuronThresholdDelta,
                Delta<double> totalNeuronSignalStrengthDelta, unsigned int indexGenome);

    double getAverageFitness();

    void nextGen(double bestOfPercentage);     // This might sound confusing, but basically it's only the function that gets called when...well...it's ambigous imo.
};


#endif //JAMAISVU_SPECIES_H
