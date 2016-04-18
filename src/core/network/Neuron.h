//
// Created by chemicalchems on 29/03/16.
//

#ifndef JAMAISVU_NEURON_H
#define JAMAISVU_NEURON_H

#include "../util/randomUtil.h"
#include "Gene.h"
#include <list>
#include <algorithm>

class Neuron {
private:
    double data;    // Temporary for each "round" a genome has to live through
    bool cleared;

    std::list<Gene*> inputGenes;
    std::list<Gene*> outputGenes;

    bool deleteInputGene(Gene* gene);
    bool deleteOutputGene(Gene* gene);
public:
    void resetData();

    /*
     * HOW TO PROPERLY USE THE NEURON CLASS FOR INPUT OR OUTPUT:
     *
     * 1. Initialize Neuron object in a custom, local scope
     *
     * 2a. INPUT NEURON
     * 2a.1 Call pulse() method to fire data into the connected genes
     *
     * IMPORTANT: REPEAT FOR ALL INPUT NEURONS, AND OPTIMIZE SENT DATA FOR THAT:
     * For example:
     * If the hunger is at 60% send a signal of 0.6, and f.e. 0.4 for the thirst
     *
     * Try to NOT do: (Example)
     * If the hunger falls above 50%, send a constant signal of 1
     *
     * Always try to send actual raw values, not if-statements
     *
     * 2b. OUTPUT NEURON
     * 2b.1 Call getSendingSignalStrength() method to retrieve data at final output neurons
     *
     * You may work with if-statements. For example:
     * if (getSendingSignalStrength()<1.5) etc...
     *
     * Recommended however is to work with the values directly, as that has better influence on the learning curve.
     * For example:
     *
     * If the hunger falls above 70%, eat two times
     * => eatTimes = getSendingSignalStrength()
     *
     * In this example, the network might figure out a way to set the gene weight to around 3 at some point, because the
     * incoming hunger: 0.7 * 3 = 1.8 = ~2; 0.7 being an INPUT VALUE given to an INPUT NEURON, 3 being an over time mutated
     * value / data by the network and 1.8 being the product of the data and weight.
     *
     * The possible combinations are mathematically being paid attention to by giving bigger networks tinier mutation values
     * to each piece to give them the possibility to try around the tiniest changes in the network before messing it up
     * (A network with 400 genes has many possibilities it has to test through mutationwise, a network with 3 genes doesn't!)
     *
     *
     * DO STEP 2 EVERYTIME YOU EXPECT AN ACTION FROM THE NEURAL NETWORK AND ONLY WHEN YOU CAN FEED ALL INPUT NEURONS
     * WITH INFORMATION
     */

    Neuron();

    double threshold;
    double signalStrength;

    unsigned long long int getGeneAmount();

    void receiveFrom(Gene* inputGene);
    void sendTo(Gene* to);

    bool containsConnectionFrom(Neuron &inputNeuron);
    bool containsConnectionTo(Neuron &outputNeuron);
    void destroy();

    void pulse(double data);

    bool disconnectGene(Gene* gene);

    double getSendingSignalStrength();
};


#endif //JAMAISVU_NEURON_H
