// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <float.h>
#include <limits.h>
#include <stdio.h>


int main(void)
{
    unsigned char a;
    signed char b;
    unsigned short c;
    signed short d;
    unsigned int e;
    signed int f;
    unsigned long g;
    signed long h;
    float i;
    double j;

    // Printing values from standard headers
    printf("Range of unsigned char: %d - %d\n", 0, UCHAR_MAX);
    printf("Range of signed char:  %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of unsigned short: %d - %d\n", 0, USHRT_MAX);
    printf("Range of signed short: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned int: %d - %d\n", 0, UINT_MAX);
    printf("Range of signed int: %d - %d\n", INT_MIN, INT_MAX);
    printf("Range of unsigned long: %d - %ld\n", 0, ULONG_MAX);
    printf("Range of signed long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of float %.5e - %.5e", FLT_MIN, FLT_MAX);
    printf("Range of double %.5e - %.5e", DBL_MIN, DBL_MAX);

    return 0;
}
 
