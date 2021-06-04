// Ex. 1.13 Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal;
// a vertical orientation is more challenging.


#include <stdio.h>


#define IN 1    // Inside a word
#define OUT 0   // Outside a word
#define MAXWORD 15  // Counts up to this individual words


int main(void)
{
    int c;  // Current character
    int nc; // Character count
    int wc; // Word count
    int words[MAXWORD]; // Character count for each individual word
    int state;

    nc = wc = 0;
    state = OUT;
    
    // Initialize individual word character counter in 0
    for(int i = 0; i < MAXWORD; i++)
    {
        words[i] = 0;
    }
   
    // Counts characters for each individual word
    while((c = getchar()) != EOF && wc < MAXWORD)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            words[wc] = nc;
            nc = 0;
            wc++;
        }
        else if(state == OUT)
        {
            state = IN;
            nc++;
        }
        else
        {
            nc++;
        }
    }
      
    // Prints character counter for each individual word
    for(int i = 0; i < MAXWORD; i++)
    {
        //printf("words[%d] = %d\n", i, words[i]);
        for(int j = 0; j < words[i]; j++)
        {
            printf("*");    
        }
        
        printf("\n");
    }

    return 0;
}

