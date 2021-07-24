// Vector.cpp

#include "Vector.h"     // get the interface

Vector::Vector(int s)   // initialize members
{
    if(s < 0)
        throw lenght_error{};

    elem = new double[s]};
    sz = s; 
}

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}
