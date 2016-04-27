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

Species::Species(std::list<Genome> genomes)
{
    setGenomeLimit((unsigned int)genomes.size());
    this->genomes = genomes;
}

void Species::setGenomeLimit(unsigned int limit)
{
    this->maxGenomes = limit;
}

int* Species::evolve(double networkChangeFactor, Delta<double> totalGeneWeightDelta, Delta<double> totalNeuronThresholdDelta,
                     Delta<double> totalNeuronSignalStrengthDelta, unsigned int indexGenome) {
    auto it = genomes.begin();
    std::advance(it, indexGenome);
    return (*it).mutate(networkChangeFactor, totalGeneWeightDelta, totalNeuronThresholdDelta, totalNeuronSignalStrengthDelta);
}

std::list<Genome> Species::getBestGenomes(double percentage)
{
    return getBestGenomes((unsigned int)(genomes.size()*percentage));
}

std::list<Genome> Species::getBestGenomes(unsigned int amount)
{
    std::list<Genome> genomesCopy = genomes;
    sortGenomeList(genomesCopy);
    genomesCopy.resize(amount);
    return genomesCopy;
}

double Species::getAverageFitness() {
    int allFitness = 0;
    int divisor = 0;
    for (Genome genome : genomes) {
        allFitness += genome.fitness;
        divisor++;
    }
    if (divisor==0) divisor++;
    return allFitness / divisor;
}

// 0 < bestOfPercentage < 0.5
void Species::nextGen(double bestOfPercentage) {
    sortGenomeList(genomes);
    int bestGenomesAmount = (int)(genomes.size() * bestOfPercentage);
    auto it = genomes.end();
    int originalSize = genomes.size();
    std::advance(it, -bestGenomesAmount);
    genomes.erase(it, genomes.end());
    it = genomes.begin();
    while (genomes.size() != 0 && genomes.size() != originalSize) {
        genomes.push_back(*it);
        std::advance(it, 1);
    }
}

void Species::sortGenomeList(std::list<Genome> &genomeList) {
    if (genomeList.size()==0 || genomeList.size() == 1) return;
    std::list<Genome>::iterator startIt = genomeList.begin();
    std::list<Genome>::iterator itIt;
    std::list<Genome>::iterator itItOF;
    while (startIt != genomeList.end())
    {
        itIt = startIt;
        itItOF = itIt;
        std::advance(itItOF, 1);
        while (itItOF != genomeList.end())
        {
            if ((*itIt).fitness < (*itItOF).fitness) std::swap((*itIt).fitness, (*itItOF).fitness);
            std::advance(itIt, 1);
            std::advance(itItOF, 1);
        }
        std::advance(startIt, 1);
    }
}
