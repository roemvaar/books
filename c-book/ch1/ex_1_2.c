/* 
 * Exercise 1.2: When printf's argument string contains an unknown escape sequence, e.g. \c
 * the following message is shown at compilation time "warning: unknown escape sequence: \c"
 */

#include <stdio.h>


int main()
{
    printf("hello, world\n");
    printf("Ohana means family\c"); // Unknown escape sequence
    
    return 0;
}
