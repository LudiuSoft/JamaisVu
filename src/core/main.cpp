#include <iostream>
#include <zconf.h>
#include <mutex>

#include "simulation/Simulation.h"
#include "tui/Console.h"
#include "tui/TUI.h"
#include "util/randomUtil.h"
#include <csignal>
#include <chrono>
#include <thread>

TUI tui;

void end(int signum) {
    std::cout << "\033[?25h";
    tui.console.clearConsole();
    exit(signum);
}

int main()
{
    signal(SIGINT, end);
    std::cout << "\033[?25l" << std::endl;
    tui.drawFrames();
    randomValueFromInterval(1,2);
    end (0);
}