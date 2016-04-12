//
// Created by IPat (Local) on 01.04.2016.
//

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

void Genome::mutate(Delta<double> deltaMutation, double geneWeightMutation) {
    const float deltaDistribution = 0.6;

    // Destroy neurons or genes
    const double destroyNeuronProb = deltaMutation * 2 / 100;
    const double destroyGeneProb = deltaMutation * 15 / 100;

    if (chance(destroyNeuronProb)) {
        unsigned int neuronIndex = getRandomNeuronIndex();
        neurons.at(neuronIndex).destroy();
        neurons.erase(neurons.begin()+neuronIndex);
    }

    if (chance(destroyGeneProb)) {
        unsigned int geneIndex = getRandomGeneIndex();
        genes.at(geneIndex).destroy();
        genes.erase(genes.begin()+geneIndex);
    }

    // Create new neurons or genes
    const double createNeuronProb = deltaMutation * 5 / 100;
    const double createGeneProb = deltaMutation * 20 / 100;

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

unsigned int Genome::getRandomGeneIndex() {
    return (unsigned int)(random0to1()*genes.size());
}

unsigned int Genome::getRandomNeuronIndex() {
    return (unsigned int)(random0to1()*neurons.size());
}
