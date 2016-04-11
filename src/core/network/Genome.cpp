//
// Created by IPat (Local) on 01.04.2016.
//

#include "../util/randomUtil.h" // Don't like this line, but it fixes the problem (Try moving this to header if possible)
#include "Genome.h"

Genome::Genome(const Genome &obj) {
    this->fitness = obj.fitness;
    this->neurons = obj.neurons;
    this->genes = obj.genes;
    this->inputNeurons = obj.inputNeurons;
    this->outputNeurons = obj.outputNeurons;
}

Genome::Genome(std::vector<Neuron>& inputNeurons, std::vector<Neuron>& outputNeurons) {
    this->inputNeurons = inputNeurons;
    this->outputNeurons = outputNeurons;
}

// For addRemoveMutation, the range is 0 - 5 (Recommended is 1 - 2)

// For geneWeightMutation, you may choose any value (It's good to keep the value constant and NOT gene amount dependent because
// that might create a big change of too many things or too strong weight change at multiple genes, potentially ruining a genome
// with one evolution) That is also the purpose of my custom mutation distribution system.

// In fact, the addRemoveMutation could be made dependent from the amount of genes, since there should be less changes
// to the amount of genes if there are many, making the more weight change possibilities (due to more genes and neurons)
// ready for experiments.

void Genome::mutate(double addRemoveMutation, double geneWeightMutation) {
    const float deltaDistribution = 0.6;

    // Destroy neurons or genes
    const double destroyNeuronProb = addRemoveMutation * 3 / 100;
    const double destroyGeneProb = addRemoveMutation * 15 / 100;

    if (chance(destroyNeuronProb)) {
        // TODO: Destroy genes that are connected to Neuron
        neurons.erase(neurons.begin()+(int)(random0to1()*neurons.size()));
    }

    if (chance(destroyGeneProb)) {
        // TODO: Properly call a disconnect method to notify neurons about connection being gone
        genes.erase(genes.begin()+(int)(random0to1()*genes.size()));
    }

    // Create new neurons or genes
    const double createNeuronProb = addRemoveMutation * 5 / 100;
    const double createGeneProb = addRemoveMutation * 20 / 100;

    if (chance(createNeuronProb)) neurons.push_back(Neuron());

    if (chance(createGeneProb)) {
        // TODO: Modify Gene class so it receives input and output neuron in constructor
        genes.push_back(Gene());
    }

    // Modify gene weights

    int geneAmount = (int) genes.size();
    while (geneAmount != 0) {
        const double lowerLimit = geneWeightMutation * (1 - deltaDistribution);
        const double upperLimit = geneWeightMutation * (1 + deltaDistribution);

        const double result = randDouble(lowerLimit, upperLimit) / geneAmount;

        geneAmount--;
        geneWeightMutation -= result;
        // Apply result
    }
}

Genome& Genome::operator=(Genome&& obj) {
    this->genes = std::move(obj.genes);
    this->neurons = std::move(obj.neurons);
    this->inputNeurons = std::move(obj.inputNeurons);
    this->outputNeurons = std::move(obj.outputNeurons);
    this->fitness = std::move(obj.fitness);
}

Genome& Genome::operator=(const Genome& obj) {
    this->fitness = obj.fitness;
    this->neurons = obj.neurons;
    this->genes = obj.genes;
    this->inputNeurons = obj.inputNeurons;
    this->outputNeurons = obj.outputNeurons;
    return *this;
}
