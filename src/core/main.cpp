#include <iostream>

#include "network/Species.h"
#include "simulation/Simulation.h"
#include "tui/Console.h"

void testFunc()
{
    Player player;
    for (int i=0; i < 10; i++)
    {
        std::cout << "Forage " << i+1 << ":\n";
        player.forage(0.5, 0.5);
        std::cout << "------------\n";
    }
}

int main()
{
    //std::thread t1 (testFunc);
    //t1.join();
    Console console;

    std::cout << "\u0580";

    return 0;
}