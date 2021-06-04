// Ex. 1.14 Write a program to print a histogram of the frequencies of
// different characters in its inputi
// Solution from https://stackoverflow.com/questions/17607402/kr-exercise-1-14

#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15  // Max length of histogram
#define MAXCHAR 128 // Max different characters

int main()
{
    int c;
    int i;
    int len;         // Length of each bar
    int maxvalue;    // Maximum value of cc[]
    int cc[MAXCHAR]; // Char frequency counters
    int totalc;      // Total chars of input
    int whitec;      // Whitespaces chars
    int digitc;      // Numeric chars
    int upperc;      // Uppercase chars
    int lowerc;      // Lowercase chars
    int punctc;      // Punctuation marks

    totalc = whitec = digitc = upperc = lowerc = punctc = 0;

    // Initialize char frequency counters to 0
    for (int i = 0; i < MAXCHAR; i++)
    {
        cc[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if(c >= 0 && c < MAXCHAR) {
            ++cc[c];
            ++totalc;

            if (isspace(c)) ++whitec;
            else if (isdigit(c)) ++digitc;
            else if (isalpha(c))
            {
                if (isupper(c)) ++upperc;
                else ++lowerc;
            }
            else if (ispunct(c)) ++punctc;
        }
    }

    maxvalue = 0;
    for (i = 0; i < MAXCHAR; ++i)
    {
        if (cc[i] > maxvalue)
            maxvalue = cc[i];
    }

    printf("\n%s - %s - %s\n", "ASCII", "CH", "Freq");
    printf("~~~~~~~~~~~~~~~~~~~~\n");   
    for (i = 0; i < MAXCHAR; ++i)
    {
        if (cc[i] == 0)
            continue;
        if (isprint(i))
            printf("%5d - %2c - %5d : ", i, i, cc[i]);
        else
            printf("%5d -    - %5d : ", i, cc[i]);

        if (cc[i] > 0) 
        {
            if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        } else
            len = 0;

        while (len > 0) 
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }

    printf("\n*** Detailed report ***\n");
    printf("Total # of chars      : %4d\n"
           "Total # of whitespaces: %4d\n"
           "Total # of numbers    : %4d\n"
           "Total # of letters    : %4d (%d upper + %d lower)\n"
           "Total # of puncts     : %4d\n",
           totalc, whitec, digitc, 
           upperc + lowerc, upperc, lowerc,
           punctc);
}

