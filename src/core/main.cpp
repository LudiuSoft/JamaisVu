#include <iostream>
#include <zconf.h>

#include "simulation/Simulation.h"
#include "tui/Console.h"

int main()
{
    Console* console = new Console;
    console->draw(std::vector<std::string>
    {
            "████████████",
            "███████████████",
            "██████"
    });
    sleep(1);
    delete console;

    return 0;
}