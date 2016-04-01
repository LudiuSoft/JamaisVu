#include <iostream>

#include "network/Species.h"
#include "simulation/Simulation.h"
#include <vector>

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

void testVLA (std::vector<int> options)
{
    for (int lol : options)
    {
        std::cout << lol << std::endl;
    }
}

int main()
{
    //std::thread t1 (testFunc);
    //t1.join();
    std::vector<int> options (3,0);
    testVLA(options);
    char blue[] = { 0x1b, '[', '0', ';', '3', '4', ';', '4', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    std::cout << blue << "lol" << normal << std::endl;


    return 0;
}