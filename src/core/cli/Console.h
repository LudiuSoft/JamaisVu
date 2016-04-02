//
// Created by chemicalchems on 1/04/16.
//

#ifndef JAMAISVU_CONSOLE_H
#define JAMAISVU_CONSOLE_H

#include <iostream>
#include "AnsiText.h"

class Console {
public:
    void print(std::string text, std::initializer_list<AnsiTextOption> options);
    void print(std::string text);
};


#endif //JAMAISVU_CONSOLE_H
