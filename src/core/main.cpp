#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"
#include "tui/TUI.h"
#include <csignal>

TUI tui;

void end(int signum) {
    std::cout << "\033[?25h";
    tui.console.clearConsole();
    exit(signum);
}

int main() {
    signal(SIGINT, end);
    std::cout << "\033[?25l";
    while (true)
    {
        tui.drawFrames();
    }
}