#include <stdio.h>


// Exercise 1.8 Write a program that count blank, tabs, and newlines

int main(void)
{
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;
    char c;

    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case ' ': 
                blanks++;
                break;

            case '\t':
                tabs++;
                break;

            case '\n':
                newlines++;
                break;
        }
    }

    printf("\nBlanks = %d\n", blanks);
    printf("Tabs = %d\n", tabs);
    printf("Newlines = %d\n", newlines);

    return 0;
}

