/*
 * Exercise 1.5 Modify the temperature conversion program to print the 
 * table in reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20


int main(void)
{
    float celsius;
    
    printf("%3s\t%6s\n", "°C", "°F");

    for(celsius = UPPER; celsius >= LOWER; celsius -= STEP)
    {
        printf("%3.0f\t%6.1f\n", celsius, (celsius * (9.0/5.0)) + 32);
    }

    return 0;
}
