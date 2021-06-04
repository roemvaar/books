#include <stdio.h>


// Count lines in input

int main(void)
{
    int c, nl;

    nl = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            ++nl;
        }
    }

    printf("Lines counted: %d\n", nl);

    return 0;
}

