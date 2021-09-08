// Function Template to find the largest number
//
// Program to display largest among two numbers
// using function templates.

#include <iostream>

using namespace std;

// Template function
template <class T>
T large(T n1, T n2)
{
    T res;

    if(n1 > n2)
        res = n1;
    else
        res = n2;

    return res;
}

int main()
{
    int i1;
    int i2;
    float f1;
    float f2;
    char c1;
    char c2;
    
    cout << "Enter two integers: \n";
    cin >> i1 >> i2;
    cout << large(i1, i2) << " is larger." << endl;

    cout << "\nEnter two floating-point numbers: \n";
    cin >> f1 >> f2;
    cout << large(f1, f2) << " is larger." << endl;

    cout << "\nEnter two characters:\n";
    cin >> c1 >> c2;
    cout << large(c1, c2) << " has larger ASCII value.";

    return 0; 
}
