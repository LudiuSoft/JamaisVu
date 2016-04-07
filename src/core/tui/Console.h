//
// Created by chemicalchems on 1/04/16.
//

#ifndef JAMAISVU_CONSOLE_H
#define JAMAISVU_CONSOLE_H

#include <iostream>
#include <vector>
#include "AnsiTextCode.h"
#include "../util/Vector2.h"

class Console {
public:
    void setTextFormat(std::initializer_list<AnsiTextCode> textCodes);
    void resetTextFormat();
    void setCursorPosition(const Vector2<int>& position);
    void setCursorPosition(const int& x, const int& y);
    void clearConsole();
    void print(const std::string& text);
    void draw (const std::vector<std::string>& chars,
               const std::vector<std::vector<std::initializer_list<AnsiTextCode>>>& formats);
    Vector2<int> getNativeConsoleSize();
    Vector2<int> consoleSize;

    Console();
    ~Console();
};


#endif //JAMAISVU_CONSOLE_H
