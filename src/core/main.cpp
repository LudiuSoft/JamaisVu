#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"

int main()
{
    Console* console = new Console;
    std::cout << console->getNativeConsoleSize().x << "," << console->getNativeConsoleSize().y;
    console->setCursorPosition(143,41);
    console->print("1");
    sleep(1);
    delete console;
    return 0;
}