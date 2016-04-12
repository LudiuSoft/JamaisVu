//
// Created by chemicalchems on 4/04/16.
//

#ifndef JAMAISVU_DELTA_H
#define JAMAISVU_DELTA_H

#include <sstream>

template <typename T>
class Delta
{
private:
    T value;
public:
    Delta() {};
    Delta(T value) {this->value = value;}

    bool operator == (const T& obj) const {return obj == this->value;}
    bool operator != (const T& obj) const {return !obj == *this;}
    bool operator >= (const T& obj) const {return obj >= this->value;}
    bool operator <= (const T& obj) const {return obj <= this->value;}
    bool operator >  (const T& obj) const {return obj >  this->value;}
    bool operator <  (const T& obj) const {return obj <  this->value;}

    T operator + (const T& obj) const {return obj + this->value;}
    T operator - (const T& obj) const {return obj - this->value;}
    T operator * (const T& obj) const {return obj * this->value;}
    T operator / (const T& obj) const {return obj / this->value;}

    void operator += (const T& obj) {this->value += obj;}
    void operator -= (const T& obj) {this->value -= obj;}
    void operator *= (const T& obj) {this->value *= obj;}
    void operator /= (const T& obj) {this->value /= obj;}

    void operator = (const T& obj) {this->value = obj;}
    operator T() const {return this->value;}
    friend std::ostream& operator << (std::ostream& out, const Delta<T>& obj) {return (out << obj.value);}
    friend void operator >> (std::istream& in, Delta<T>& obj) {in >> obj.value;}
};

#endif //JAMAISVU_DELTA_H
