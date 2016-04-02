//
// Created by chemicalchems on 1/04/16.
//

#include "Console.h"

void Console::print(std::string text, std::initializer_list<AnsiTextOption> options)
{
    std::string ansiSetString = "\033[0";
    std::string ansiResetString = "\033[0;39;49m";
    for (AnsiTextOption option : options)
    {
        ansiSetString += ";";
        ansiSetString += std::to_string(option);
    }
    ansiSetString += "m";

    std::cout << ansiSetString << text << ansiResetString;
}
