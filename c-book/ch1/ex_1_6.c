#include <stdio.h>

// Exercise 1-6. Verify that the expression
// getchar() != EOF is 0 or 1

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
