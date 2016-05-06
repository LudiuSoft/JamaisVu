#include <iostream>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"
#include "tui/TUI.h"
#include "network/Generation.h"
#include "util/toStr.h"
#include <csignal>
#include <SDL.h>
#include <SDL_image.h>

TUI tui;

void end(int signum) {
    std::cout << "\033[?25h";
    tui.console.clearConsole();
    exit(signum);
}

void runNetworkTest1() {
    std::list<Neuron> inputNeurons, outputNeurons;
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
        for (unsigned int i = 0; i < speciesPerGen; i++) {
            for (unsigned int j = 0; j < genomesPerSpecies; j++) {
                std::cout << "G" << toStr(testGen.generation);
                std::cout << "S" << toStr(i+1);
                std::cout << "G" << toStr(j+1) << ": \n";

                auto speciesIterator = testGen.species.begin();
                std::advance(speciesIterator, i);
                auto genomeIterator = (*speciesIterator).genomes.begin();
                std::advance(genomeIterator, j);
                // The lower the stronger
                double hunger = 2.0;
                // The lower the...less
                double food = 1.0;
                double foodFactor = 1.0;
                int fitness = testGen.mutate(networkChangeFactor, totalGeneWeightDelta, totalNeuronThresholdDelta,
                                             totalNeuronSignalStrengthDelta, i, j);

                bool dead = false;
                int roundNumber = 0;
                const int maxRounds = 1000000;
                while (roundNumber < maxRounds && !dead) {
                    hunger -= 0.5;
                    food += 0.3 * foodFactor;
                    foodFactor *= 1.2;

                    auto neuronIterator = (*genomeIterator).inputNeurons.begin();
                    neuronIterator->pulse(hunger);
                    std::advance(neuronIterator, 1);
                    neuronIterator->pulse(food);

                    double signal = (*genomeIterator).outputNeurons.begin()->getSendingSignalStrength();
                    if (signal != 0.0) {
                        hunger += signal;
                        if (signal>food) signal = food;
                        food -= signal;
                        foodFactor = 1.0;
                    }

                    if(hunger<0) dead = true;
                    roundNumber++;
                }
                genomeIterator->fitness = roundNumber;
                std::cout << toStr(genomeIterator->fitness) << std::endl;
            }
        }
        testGen.nextGen();
    }
}

int main(int argc, char *argv[])
{
    SDL_Window* window = SDL_CreateWindow("Jamais Vu", 0, 0, 1080, 720, SDL_WINDOW_RESIZABLE);
    SDL_Surface* windowSurface;
    SDL_Event event;
    signal(SIGINT, end);
    bool running = true;

    while (running)
    {
        windowSurface = SDL_GetWindowSurface(window);
        SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0x00, 0x00, 0x00));
        SDL_UpdateWindowSurface(window);

        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    SDL_DestroyWindow(window);
                    running = false;
                    break;
            }
        }
    }

    std::cout << std::endl << "Starting networkTest1()..." << std::endl;
    runNetworkTest1();
    std::cout << "Finished successfully." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(15));
    end (0);
}
