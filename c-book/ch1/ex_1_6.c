/*
 * Exercise 1-6. Verify that the expression
 * getchar() != EOF is 0 or 1
 */

#include <stdio.h>


int main(void)
{
    if(getchar() != EOF) {
        putchar('0');
    }
    else {
        putchar('1');
    }

    return 0;
}
