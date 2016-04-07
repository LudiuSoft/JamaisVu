#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"

int main()
{
    Console* console = new Console;
    std::cout << console->consoleSize.x<< "," << console->consoleSize.y;
    console->draw(
            {
                    "asdf",
                    "asdf"
            },
            {
                    {{fg_cyan}, {}, {fg_black}, {bg_cyan}},
                    {{bg_blue}, {bold, fg_cyan}, {fg_cyan}, {bg_darkgray}}
            });
    console->setCursorPosition(console->consoleSize);
    console->print("1");
    sleep(1);
    delete console;
    return 0;
}