// Chapter 1 - Longest-line program with line, longest, and max
// as external variables

#include <stdio.h>

#define MAXLINE 1000    // Maximum input line size

int max;    // Maximum length seen so far
char line[MAXLINE];     // Current input line
char longest[MAXLINE];  // Longest line saved here

int get_line(void);
void copy(void);


// Print longest input line; specialized version
int main(void)
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while((len = get_line()) >= 0)
    {
        if(len > max)
        {
            max = len;
            copy();
        }
    }

    if(max > 0) // There was a line
    {
        printf("%s\n", longest);
    }

    return 0;
}


// get_line: specialized version
int get_line(void)
{
    int c;
    int i;
    extern char line[];

    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if(c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;    
}


// copy: specialized version
void copy(void)
{
    int i;
    extern char line[];
    extern char longest[];
    
    i = 0;
    while((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}

