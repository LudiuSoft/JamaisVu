//
// Created by IPat (Local) on 11.04.2016.
//

#ifndef JAMAISVU_RANDOMUTIL_H
#define JAMAISVU_RANDOMUTIL_H

#include <stdlib.h>
#include <random>

static std::random_device rnddev;

// PARAMETER SYNTAX
// AB.CDE%: percentage = 0.ABCDE

template<typename T> //TODO: Add support for integral types with std::uniform_int_distribution<T>
static T randomValueFromInterval (T lowerBound, T upperBound) {
    if (std::is_floating_point<T>::value)
    {
        return std::uniform_real_distribution<T>(lowerBound, upperBound)(rnddev);
    }
    else
    {
        return std::uniform_int_distribution<T>(lowerBound, upperBound)(rnddev);
    }
}

static bool chance(double percentage) {
    double randomResult = randomValueFromInterval((double(0.0)), (double)1.0);
    return randomResult < percentage;
}

#endif //JAMAISVU_RANDOMUTIL_H
