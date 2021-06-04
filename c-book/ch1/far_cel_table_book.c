#include <stdio.h>


// Print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300; floating-point version
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // Lower limit of temperature table
    upper = 300;    // Upper limit
    step = 20;      // Step size

    fahr = lower;

    printf("Fahrenheit-Celsius Table\n\n");    // Ex 1.3 print a heading above the table
    printf("%3s\t%6s\n","°F", "°C");

    while(fahr <= upper) 
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

