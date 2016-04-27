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

static double randomValueFromInterval (double lowerBound, double upperBound) {
    return std::uniform_real_distribution<double>(lowerBound, upperBound)(rnddev);
}

static int randomValueFromInterval (int lowerBound, int upperBound) {
    return std::uniform_int_distribution<int>(lowerBound, upperBound)(rnddev);
}


static bool chance(double percentage) {
    double randomResult = randomValueFromInterval((double(0.0)), (double)1.0);
    return randomResult < percentage;
}

#endif //JAMAISVU_RANDOMUTIL_H
