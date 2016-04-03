//
// Created by IPat (Local) on 01.04.2016.
//

#include "Genome.h"

Genome::Genome(std::vector<Neuron> (&getInputNeurons)(), std::vector<Neuron> (&getOutputNeurons)()) {
    this->getInputNeurons = getInputNeurons;
    this->getOutputNeurons = getOutputNeurons;
}

// For addRemoveMutation, the range is 0 - 5 (Recommended is 1 - 2)

// For geneWeightMutation, you may choose any value (It's good to keep the value constant and NOT gene amount dependent because
// that might create a big change of too many things or too strong weight change at multiple genes, potentially ruining a genome
// with one evolution) That is also the purpose of my custom mutation distribution system.

// In fact, the addRemoveMutation could be made dependent from the amount of genes, since there should be less changes
// to the amount of genes if there are many, making the more weight change possibilities (due to more genes and neurons)
// ready for experiments.

void Genome::mutate(double addRemoveMutation, double geneWeightMutation) {
    const float deltaMutation = 0.6;
    std::mt19937 rnd;
    std::uniform_real_distribution<double> randomPreDivisionMutationDist;

    // Destroy neurons or genes
    const double destroyNeuronProb = addRemoveMutation*2/100;
    const double destroyGeneProb = addRemoveMutation*8/100;

    // Create new neurons or genes
    const double createNeuronProb = addRemoveMutation*5/100;
    const double createGeneProb = addRemoveMutation*20/100;

    // Modify gene weights

    int geneAmount = (int)genes.size();
    while (geneAmount != 0)
    {
        const double lowerLimit = geneWeightMutation *(1-deltaMutation);
        const double upperLimit = geneWeightMutation *(1+deltaMutation);

        rnd = std::mt19937((unsigned int)time(0));
        randomPreDivisionMutationDist = std::uniform_real_distribution<double>(lowerLimit,upperLimit);
        const double result = randomPreDivisionMutationDist(rnd)/geneAmount;

        geneAmount--;
        geneWeightMutation -= result;
        // Apply result
    }
}
