//
// Created by chemicalchems on 2/04/16.
//

#ifndef JAMAISVU_VECTOR2_H
#define JAMAISVU_VECTOR2_H

template <typename T>
struct Vector2
{
    T x;
    T y;

    Vector2(int x, int y) : x(x), y(y){};
    Vector2() {};
};

#endif //JAMAISVU_VECTOR2_H
