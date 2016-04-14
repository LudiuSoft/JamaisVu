//
// Created by IPat (Local) on 28.03.2016.
//

#include "Species.h"

Species::Species(unsigned int limit, std::list<Neuron>& inputNeurons, std::list<Neuron>& outputNeurons)
{
    setGenomeLimit(limit);
    while (limit!=0)
    {
        genomes.push_back(Genome(inputNeurons, outputNeurons));
        limit--;
    }
}

Species::Species(std::vector<Genome> genomes)
{
    setGenomeLimit((unsigned int)genomes.size());
    this->genomes = genomes;
}

void Species::setGenomeLimit(unsigned int limit)
{
    this->maxGenomes = limit;
}

void Species::evolve(double networkChangeFactor, Delta<double> totalGeneWeightDelta, Delta<double> totalNeuronThresholdDelta, Delta<double> totalNeuronSignalStrengthDelta) {
    for (Genome genome : genomes)
    {
        genome.mutate(networkChangeFactor, totalGeneWeightDelta, totalNeuronThresholdDelta, totalNeuronSignalStrengthDelta);
    }
}

std::vector<Genome> Species::getBestGenomes(double percentage)
{
    return getBestGenomes((unsigned int)(genomes.size()*percentage));
}

std::vector<Genome> Species::getBestGenomes(unsigned int amount)
{
    std::vector<Genome> genomesCopy = genomes;
    std::sort(genomesCopy.begin(), genomesCopy.end(), std::greater<Genome>());    // Sorts descending dependent from fitness
    genomesCopy.resize(amount);
    return genomesCopy;
}

