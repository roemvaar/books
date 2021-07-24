#include <iostream>

using namespace std;

// We can construct a vector like this
struct Vector {
    int sz;         // number of elements
    double* elem;   // pointer to elements
};

void vector_init(Vector& v, int s)
{
    v.elem = new double[s]; // allocates an array of s doubles
    v.sz = s;
}

// read s integers from cin and return their sum; s is assumed to be positive
double read_and_sum(int s) 
{
    Vector v;
    vector_init(v, s);      // allocate s elements for v

    for(int i = 0; i != s; ++i)
        cin >> v.elem[i];   // read into elements

    double sum = 0;

    for (int i = 0; i != s; ++i)
        sum += v.elem[i];   // take the sum of the elements
    
    return sum;
}

int main()
{
    double sum;

    sum = read_and_sum(10);

    cout << "\nThe sum is: " << sum << endl;

    return 0;
}
