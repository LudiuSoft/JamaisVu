#include <iostream>

#include "network/Species.h"
#include "simulation/Simulation.h"
#include "cli/Console.h"
#include "util/toStr.h"

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

    console.print("lol ", {fg_black, bg_green});
    console.print("we ", {bold, fg_red, bg_cyan});
    console.print("did ", {underlined, bold, fg_lightblue, bg_black});
    console.print("it!", {dim, inverted, bold, underlined, fg_cyan, bg_darkgray});
    std::cout << std::endl;
    std::cout << toStr(5);

    return 0;
}