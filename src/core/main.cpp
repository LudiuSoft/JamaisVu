#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"
#include "tui/TUI.h"
#include "util/randomUtil.h"
#include "network/Generation.h"
#include "util/toStr.h"
#include <csignal>
#include <chrono>
#include <thread>

TUI tui;

void end(int signum) {
    std::cout << "\033[?25h";
    tui.console.clearConsole();
    exit(signum);
}

void runNetworkTest1() {
    std::list<Neuron> inputNeurons, outputNeurons = std::list<Neuron>();
    inputNeurons.push_back(Neuron());   // Hunger
    inputNeurons.push_back(Neuron());   // Food that's there
    outputNeurons.push_back(Neuron());  // How many percent to eat
    const int speciesPerGen = 5;
    const int genomesPerSpecies = 15;
    Generation testGen = Generation(speciesPerGen, genomesPerSpecies, inputNeurons, outputNeurons);

    const double networkChangeFactor = 2.2;
    const Delta<double> totalGeneWeightDelta = 3.5;
    const Delta<double> totalNeuronThresholdDelta = 1.5;
    const Delta<double> totalNeuronSignalStrengthDelta = 0.5;

    while (testGen.generation != 100) {
        for (unsigned int a = 0; a < speciesPerGen; a++) {
            for (unsigned int b = 0; b < genomesPerSpecies; b++) {
                std::cout << "G" << toStr(testGen.generation);
                std::cout << "S" << toStr(a+1);
                std::cout << "G" << toStr(b+1) << ": \n";

                auto it1 = testGen.species.begin();
                std::advance(it1, a);
                auto it2 = (*it1).genomes.begin();
                std::advance(it2, b);
                // The lower the stronger
                double hunger = 2.0;
                // The lower the...less
                double food = 1.0;
                double foodFactor = 1.0;
                int* fitness = testGen.mutate(networkChangeFactor, totalGeneWeightDelta, totalNeuronThresholdDelta,
                                              totalNeuronSignalStrengthDelta, a, b);

                bool dead = false;
                int round = 0;
                const int maxRounds = 150;
                while (round<maxRounds && !dead) {
                    hunger -= 0.5;
                    food += 0.3 * foodFactor;
                    foodFactor *= 1.2;

                    auto it3 = (*it2).inputNeurons.begin();
                    it3->pulse(hunger);
                    std::advance(it3, 1);
                    it3->pulse(food);

                    double signal = (*it2).outputNeurons.begin()->getSendingSignalStrength();
                    if (signal != 0.0) {
                        hunger += signal;
                        if (signal>food) signal = food;
                        food -= signal;
                        foodFactor = 1.0;
                    }

                    if(hunger<0) dead = true;
                    round++;
                }
                *fitness = round;
                std::cout << toStr(*fitness) << std::endl;
            }
        }
        testGen.nextGen();
    }
}

int main()
{
    signal(SIGINT, end);
    std::cout << "\033[?25l" << std::endl;
    tui.drawFrames();

    std::cout << std::endl << "Starting networkTest1()..." << std::endl;
    runNetworkTest1();
    std::cout << "Finished successfully." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(15));
    end (0);
}
