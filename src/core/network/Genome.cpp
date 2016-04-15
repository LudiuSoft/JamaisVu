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

Genome::Genome(std::list<Neuron> inputNeurons, std::list<Neuron> outputNeurons) {
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

int* Genome::mutate(double networkChangeFactor, Delta<double> totalGeneWeightDelta,
                    Delta<double> totalNeuronThresholdDelta, Delta<double> totalNeuronSignalStrengthDelta) {
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
    const double createGeneProb = networkChangeFactor * 25 / 100;

    if (chance(createNeuronProb)) neurons.push_back(Neuron());  // Neuron gets created

    std::list<Neuron *> receivableNeurons = getReceivableNeurons();   // Reason for early declaration: Gets used multiple times

    if (chance(createGeneProb)) {                               // Gene gets created
        std::list<Neuron*> sendableNeurons = getSendableNeurons();
        auto sndIt = sendableNeurons.begin();
        std::advance(sndIt, (unsigned int)(sendableNeurons.size()*random0to1()));

        auto rcvIt = receivableNeurons.begin();
        std::advance(rcvIt, (unsigned int)(receivableNeurons.size()*random0to1()));

        if (!((*sndIt)->containsConnectionFrom(**rcvIt) || (*rcvIt)->containsConnectionTo(**sndIt)))
            genes.push_back(Gene(**sndIt, **rcvIt));
    }

    // Modify gene weights
    int geneAmount = (unsigned int) genes.size();
    auto geneIt = genes.begin();
    while (geneAmount != 0)
    {
        const double lowerLimit = totalGeneWeightDelta * (1 - deltaDistribution);
        const double upperLimit = totalGeneWeightDelta * (1 + deltaDistribution);

        const double result = randomValueFromInterval(lowerLimit, upperLimit) / geneAmount;

        geneAmount--;
        totalGeneWeightDelta -= result;

        geneIt->weight += (chance(0.5)?-1:1)*result;    // 50% chance on subtraction / addition of result
        if (chance(0.1*networkChangeFactor)) geneIt->invert = !geneIt->invert; // Usually, it's unlikely a gene changes its inverting behaviour(5*ncF%).

        std::advance(geneIt, 1);      // Equal to geneIt++; Coding practice since iterators are not always optimized (Operator ++ not always overridden)
    }

    // Modify neuron threshold and signal values
    int mutatableNeuronAmount = (unsigned int) receivableNeurons.size();
    auto neuronIt = receivableNeurons.begin();
    while (mutatableNeuronAmount != 0) {
        const double lowerThreshholdDeltaLimit = totalNeuronThresholdDelta * (1 - deltaDistribution);
        const double upperThreshholdDeltaLimit = totalNeuronThresholdDelta * (1 + deltaDistribution);

        const double threshholdResult = randomValueFromInterval(lowerThreshholdDeltaLimit, upperThreshholdDeltaLimit) /
                                        mutatableNeuronAmount;

        const double lowerSignalStrengthDeltaLimit = totalNeuronSignalStrengthDelta * (1 - deltaDistribution);
        const double upperSignalStrengthDeltaLimit = totalNeuronSignalStrengthDelta * (1 + deltaDistribution);

        const double signalStrengthResult = randomValueFromInterval(lowerSignalStrengthDeltaLimit,
                                                                    upperSignalStrengthDeltaLimit) / mutatableNeuronAmount;

        mutatableNeuronAmount--;
        totalNeuronThresholdDelta -= threshholdResult;
        totalNeuronSignalStrengthDelta -= signalStrengthResult;

        (*neuronIt)->threshold += (chance(0.5) ? -1 : 1) * threshholdResult; // 50% chance on subtraction / addition of result
        (*neuronIt)->signalStrength += (chance(0.5) ? -1 : 1) * signalStrengthResult;

        std::advance(neuronIt, 1); // Equal to neuronIt++; Coding practice since iterators are not always optimized (Operator ++ not always overridden)
    }

    return &fitness;
}

Genome& Genome::operator=(Genome&& obj) {
    this->genes = std::move(obj.genes);
    this->neurons = std::move(obj.neurons);
    this->inputNeurons = std::move(obj.inputNeurons);
    this->outputNeurons = std::move(obj.outputNeurons);
    this->fitness = std::move(obj.fitness);
    return *this;
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

std::list<Neuron *> Genome::getReceivableNeurons() {
    std::list<Neuron*> resultContainer;

    auto rcvIt = outputNeurons.begin();
    while (rcvIt != outputNeurons.end())
    {
        resultContainer.push_back(&*rcvIt);  // Literally - Your assumption about what this line does is probably right.
        std::advance(rcvIt, 1);
    }

    rcvIt = neurons.begin();
    while (rcvIt != neurons.end())
    {
        resultContainer.push_back(&*rcvIt);
        std::advance(rcvIt, 1);
    }
    return resultContainer;
}

std::list<Neuron *> Genome::getSendableNeurons() {
    std::list<Neuron*> resultContainer;

    auto rcvIt = inputNeurons.begin();
    while (rcvIt != inputNeurons.end())
    {
        resultContainer.push_back(&*rcvIt);
        std::advance(rcvIt, 1);
    }

    rcvIt = neurons.begin();
    while (rcvIt != neurons.end())
    {
        resultContainer.push_back(&*rcvIt);
        std::advance(rcvIt, 1);
    }
    return resultContainer;
}

void Genome::clearNetworkData() {
    for (Neuron neuron : inputNeurons) {
        neuron.resetData();
    }
}