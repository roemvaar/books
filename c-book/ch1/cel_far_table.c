#include <stdio.h>

// Program that prints the Celsius temperatures and their Fahrenheit equivalents
// Formula used °F = ((9/5)°C)+32

int main(void)
{
    float celsius, fahr;
    int lower, upper, step;

    lower = -60;
    upper = 300;
    step = 20;
    
    printf("Celsius-Fahrenheit Table\n");
    printf("%3s\t%6s\n", "°C", "°F");

    for(celsius = lower; celsius <= upper; celsius += step)
    {
        fahr = ((9.0/5.0) * celsius) + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
    }

    return 0;
}

