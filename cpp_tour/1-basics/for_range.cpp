#include <iostream>

using namespace std;

void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(auto x : v) // for every element of v, from the first to the last,
                    // place a copy in x and print it
        cout << x << "\n";

    for(auto& x : v)    // If we don't want to copy the values from v into variable
                        // x, but rather just have x refer to an element
        cout << x << "\n";
    
    for(auto x : {10, 21, 32, 43, 54, 65})
        cout << x << "\n";
}

int main()
{
    print();

    return 0;
}
