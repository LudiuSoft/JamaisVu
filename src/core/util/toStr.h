//
// Created by chemicalchems on 2/04/16.
//

#ifndef JAMAISVU_TOSTR_H_H
#define JAMAISVU_TOSTR_H_H

#include <iostream>

template<typename T>
std::string toStr(T var) {
    return std::to_string(var);
}

#endif //JAMAISVU_TOSTR_H_H
