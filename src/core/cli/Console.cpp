//
// Created by chemicalchems on 1/04/16.
//

#include "Console.h"
#include <string>


void Console::print(std::string text, std::initializer_list<AnsiTextOption> options)
{
    std::string ansiSetString = "\033[0";
    std::string ansiResetString = "\033[0;39;49m";
    for (AnsiTextOption option : options)
    {
        ansiSetString += std::to_string(option);
        ansiSetString += ";";
    }
    ansiSetString.pop_back(); //Remove last semicolon, would interfere with ANSI
    ansiSetString += "m";

    std::cout << ansiSetString << text << ansiResetString;
}
