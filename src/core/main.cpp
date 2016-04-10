#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"
#include "tui/TUI.h"
#include <csignal>

TUI tui;

void exit(int signum) {
    std::cout << "\033[?25h";
    exit(signum);
    tui.console.clearConsole();
}

int main() {
    signal(SIGINT, exit);
    std::cout << "\033[?25l";
    while (true) {
        tui.drawFrames();

    }

}