/* computer_dating - when will the time_t's wrap around?
 */

#include <limits.h>
#include <stdio.h>
#include <time.h>

double convert_seconds_to(double seconds, char option);

int main(int argc, char *argv[])
{
    time_t curr_time;
    time_t biggest;
    double diff;

    /* Get current time and display it as a string */
    time(&curr_time);
    printf("Current time: %s\n", asctime(gmtime(&curr_time)));

    /* Place highest value into time_t */
    biggest = 0x7FFFFFFF; 
    printf("Max date for time_t: %s\n", asctime(gmtime(&biggest)));

    /* Time until the mess come and haunts us,
        Y2K with a different hat */
    diff = difftime(biggest, curr_time);
    printf("Time until curse is over: %f\n", diff);

    return 0;
}
