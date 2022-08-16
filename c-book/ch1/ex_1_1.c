/* 
 * Exercise 1.1: When you don't specify a return type for the main function
 * A warning is thrown by gcc 9.3.0 "warning: return type defaults to 'int'
 * C90 used to accept main() but the C99 standard states that you should specify
 * a return a value, even if it's void.
 *
 * Exercise 1.1: When you don't have a main function (or when you misspell main, e.g ain),
 * the gnu linker (ld) shows the following message 'undefined reference to 'main'
 */

#include <stdio.h>


int main()
{
    //printf("hello, world\n");
    printf("Ohana means family\y"); // Unknown escape sequence
    
    return 0;
}
