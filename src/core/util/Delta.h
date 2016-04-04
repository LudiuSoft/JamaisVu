//
// Created by chemicalchems on 4/04/16.
//

#ifndef JAMAISVU_DELTA_H
#define JAMAISVU_DELTA_H

#include <sstream>

template <typename T>
struct Delta
{
private:
    T value;
public:
    Delta() {};
    Delta(T value) {this->value = value;}

    bool operator == (const T& it) const {return it == this->value;}
    bool operator != (const T& it) const {return !it == *this;}
    bool operator >= (const T& it) const {return it >= this->value;}
    bool operator <= (const T& it) const {return it <= this->value;}
    bool operator >  (const T& it) const {return it >  this->value;}
    bool operator <  (const T& it) const {return it <  this->value;}

    T& operator + (const T& it) const {return it + this->value;}
    T& operator - (const T& it) const {return it - this->value;}
    T& operator * (const T& it) const {return it * this->value;}
    T& operator / (const T& it) const {return it / this->value;}

    void operator += (const T& it) {this->value += it;}
    void operator -= (const T& it) {this->value -= it;}
    void operator *= (const T& it) {this->value *= it;}
    void operator /= (const T& it) {this->value /= it;}


    void operator = (const T& it) {this->value = it;}
    operator T() const {return this->value;}
    friend std::ostream& operator << (std::ostream& out, const Delta<T>& obj) {return (out << obj.value);}
    friend void operator >> (std::istream& in, Delta<T>& obj) {in >> obj.value;}

};

#endif //JAMAISVU_DELTA_H
