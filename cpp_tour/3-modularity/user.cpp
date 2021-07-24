// user.cpp
// g++ -o user Vector.cpp user.cpp

#include "Vector.h"     // get Vector's interface
#include <cmath>        // get the standard-library math function interface including sqrt()
#include <iostream>

using namespace std;   // make std members visible

double sqrt_sum(Vector& v)
{
    double sum = 0;

    for (int i = 0; i != v.size(); ++i)
        cin >> v[i];    // read into elements

    for(int i = 0; i != v.size(); ++i)
        sum += sqrt(v[i]);      // sum of square roots

    return sum;
}

int main()
{
    int sum;
    Vector v(6);
    
    sum = sqrt_sum(v);

    cout << "The sqrt_sum is: " << sum << endl;

    return 0;
}
