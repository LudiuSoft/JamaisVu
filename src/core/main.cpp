#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"

int main()
{
    Console* console = new Console;
    console->draw({
                          {U"█\u2588"},
                          {U"sa"}
                  },
                  {
                          {{fg_magenta}, {fg_cyan}},
                          {{fg_blue}, {bold, underlined, fg_black, bg_cyan}}
                  });
    console->setCursorPosition(console->consoleSize);
    console->print("1");
    sleep(1);
    delete console;
    return 0;
}