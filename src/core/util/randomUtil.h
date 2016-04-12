//
// Created by IPat (Local) on 11.04.2016.
//

#ifndef JAMAISVU_RANDOMUTIL_H
#define JAMAISVU_RANDOMUTIL_H

#include <stdlib.h>
#include <random>

static std::random_device rnddev;

static const double random0to1() {
    std::uniform_real_distribution<double> distribution (0,1);

    return distribution(rnddev);
}

// PARAMETER SYNTAX
// AB.CDE%: percentage = 0.ABCDE
static bool chance(double percentage) {
    return random0to1() < percentage;
}

template<typename T> //TODO: Add support for integral types with std::uniform_int_distribution<T>
static T randomValueFromInterval (T lowerBound, T upperBound) {
    std::uniform_real_distribution<T>distribution;
    return distribution(rnddev);
}

#endif //JAMAISVU_RANDOMUTIL_H
