#include <stdio.h>

// Copy input to output


int main(void)
{
    int c;

    while((c = getchar()) != EOF)
    {
        putchar(c);
    }

    return 0;
}

