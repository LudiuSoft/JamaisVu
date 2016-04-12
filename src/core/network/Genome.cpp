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

Genome::Genome(std::list<Neuron>& inputNeurons, std::list<Neuron>& outputNeurons) {
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

void Genome::mutate(double networkChangeFactor, Delta<double> totalGeneWeightDelta) {
    const float deltaDistribution = 0.6;

    // Destroy neurons or genes
    const double destroyNeuronProb = networkChangeFactor * 2 / 100;
    const double destroyGeneProb = networkChangeFactor * 15 / 100;

    if (chance(destroyNeuronProb)) {
        unsigned int neuronIndex = getRandomNeuronIndex();
        auto neuronsIterator = neurons.begin();
        std::advance(neuronsIterator, neuronIndex);

        neuronsIterator->destroy();
        neurons.erase(neuronsIterator);
    }

    if (chance(destroyGeneProb)) {
        unsigned int geneIndex = getRandomGeneIndex();
        auto genesIterator = genes.begin();
        std::advance(genesIterator, geneIndex);

        genesIterator->destroy();
        genes.erase(genesIterator);
    }

    // Create new neurons or genes
    const double createNeuronProb = networkChangeFactor * 5 / 100;
    const double createGeneProb = networkChangeFactor * 20 / 100;

    if (chance(createNeuronProb)) neurons.push_back(Neuron());

    if (chance(createGeneProb)) {
        // TODO: Modify Gene class so it receives input and output neuron in constructor
        genes.push_back(Gene());
    }

    // Modify gene weights

    int geneAmount = (int) genes.size();
    while (geneAmount != 0) {
        const double lowerLimit = totalGeneWeightDelta * (1 - deltaDistribution);
        const double upperLimit = totalGeneWeightDelta * (1 + deltaDistribution);

        const double result = randomValueFromInterval(lowerLimit, upperLimit) / geneAmount;

        geneAmount--;
        totalGeneWeightDelta -= result;
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
