// Pointers and references
//
// A pointer holds the address of a variable and can be used to perform any operation that could
// be directly done on the variable, such as accessing and modifying it.
//
// A reference is another name (an alias) for a pre-existing object and it does not have memory
// of its own.
//
// Unlinke pointers, references cannot be null and cannot
// be reassigned to another piece of memory.

#include <iostream>

int main()
{
    // Pointers
    int *p = new int;
    *p = 7;
    int *q = p;
    *p = 8;
    std::cout << *q << std::endl;

    // References
    int a = 5;
    int &b = a;
    b = 7;
    std::cout << a << std::endl;

    // Pointer arithmetic
    int *arr = new int[2];
    arr[0] = 0;
    arr[1] = 1;
    arr++;  // performing arr++ will skip ahead by sizeof(int) bytes, such that the code outputs 1
    std::cout << *arr << std::endl;

    return 0;
}
