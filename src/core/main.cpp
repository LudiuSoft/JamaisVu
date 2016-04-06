#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"

int main()
{
    Console* console = new Console;
    Vector2<int> consoleSize = console->getNativeConsoleSize();
    std::cout << consoleSize.x<< "," << consoleSize.y;
    console->setCursorPosition(consoleSize.x,consoleSize.y);
    console->print("1");
    sleep(1);
    delete console;
    return 0;
}