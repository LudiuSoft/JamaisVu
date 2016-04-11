//
// Created by IPat (Local) on 11.04.2016.
//

#ifndef JAMAISVU_RANDOMUTIL_H
#define JAMAISVU_RANDOMUTIL_H

#include <stdlib.h>

const double random0to1() {
    return ((double)rand() / (RAND_MAX + 1));
}

// PARAMETER SYNTAX
// AB.CDE%: percentage = 0.ABCDE
bool chance(double percentage) {
    return random0to1() < percentage;
}

double randDouble(double lowerRange, double upperBound) {
    return lowerRange + random0to1() * (upperBound - lowerRange);
}

#endif //JAMAISVU_RANDOMUTIL_H
