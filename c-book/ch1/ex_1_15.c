/* 
 * Ex. 15 - Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion
 *
 * Print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version
 */

#include <stdio.h>

float convert_far_to_celsius(float fahr);


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
        celsius = convert_far_to_celsius(fahr);

        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}


float convert_far_to_celsius(float fahr)
{
    return((5.0 / 9.0) * (fahr - 32.0));
}
