#include <stdio.h>

// Exercise 1.3 Modify the temperature conversion program to
// print a heading above the table.

int main(void)
{
    int far_temps[] = {-20, 0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300};
    int far_temps_size = sizeof(far_temps)/sizeof(far_temps[0]);
    
    printf("%3s\t%6s\n", "°F", "°C");

    for(int i = 0; i < far_temps_size; i++)
    {
        printf("%3d\t %6.2f\n", far_temps[i], ((5/9.0)* (far_temps[i] - 32.0)));
    }
    
    return 0;
}
