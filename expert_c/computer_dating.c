/* 
 * computer_dating.c
 * 
 * When will the time_t's wrap around?
 * 
 * The definition of time_t vary between PCs and UNIX systems.
 * On my personal computer, time_t is just a typedef for long int.
 * 
 * time_t is defined as a long int, therefore it behaves as such
 * variable. But when it comes to using the gmtime / localtime
 * functions, if the time_t variable is too big (a time that's too
 * far in the future and whose year does not fit in the tm_year field)
 * then it will return a null pointer.
 * 
 * More info at: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=238547
 *
 */

#include <limits.h>
#include <stdio.h>
#include <time.h>


void convert_to_time(double seconds);


int main(int argc, char *argv[])
{
    time_t curr_time;
    time_t biggest;
    double diff;

    /* Test long int max values and overflow it */
    printf("Size of long int in bytes: %ld\n", sizeof(long int));
    long int test = 0x7FFFFFFFFFFFFFFC;
    // long int test = LONG_MAX - 3;
    printf("Test long int max value and overflow it:\n");
    for (int i = 0; i < 10; i++) {
        printf("%ld\n", test);
        test++;
    }

    /* Test time_t (long int) max values and overflow it - should behave exactly the same
     * as a regular long int variable (as above).
     */
    printf("Size of time_t (long int) in bytes: %ld\n", sizeof(time_t));
    time_t test_time = 0x7FFFFFFFFFFFFFFC;
    printf("Test time_t max value and overflow it:\n");
    for (int i = 0; i < 10; i++) {
        printf("%ld\n", test_time);
        test_time++;
    }

    /* Get current time and display it as a string */
    time(&curr_time);
    printf("\n\nCurrent time: %s\n", asctime(gmtime(&curr_time)));

    /* Place highest value into time_t */
    biggest = 0x7FFFFFFFFFFFFFFFll; // This is too big to be handled by gmtime
    //biggest = 0xFFFFFFFF;
    for(int i = 0; i < 10; i++) {
        printf("Max date for time_t: %s\n", asctime(gmtime(&biggest)));
        biggest++;
    }

    biggest = 0xEFFFFFFFFFFFFFLL;
    printf("Max date for time_t: %s\n", asctime(gmtime(&biggest)));

    /* Time until the mess come and haunts us,
        Y2K with a different hat */
    diff = difftime(biggest, curr_time);
    printf("Time until curse is over in seconds: %f\n", diff);
    convert_to_time(diff);

    return 0;
}


void convert_to_time(double seconds)
{
    long int years;
    long int months;
    long int weeks;
    long int days;
    long int hours;
    long int minutes;

    years = seconds / 31536000;
    months = seconds / 2628288; // seconds in a 30 day month
    weeks = seconds / 604800;
    days = seconds / 86400;
    hours = seconds / 3600;
    minutes = seconds / 60;

    printf("Time until curse is over in:\n");
    printf("Years: %ld\n", years);
    printf("Months: %ld\n", months);
    printf("Weeks: %ld\n", weeks);
    printf("Days: %ld\n", days);
    printf("Hours: %ld\n", hours);
    printf("Minutes: %ld\n", minutes);
}
