// Ex. 16 - Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrarily long input lines, and as much 
// as possible of the text.

#include <stdio.h>
#define MAXLINE 1000    // Maximum input line size

int get_line(char line[], int maxline);
void copy(char to[], char from[]);


// Print longest input line
int main(void)
{
    int len;    // Current line length
    int max;    // Maximum length seen so far
    char line[MAXLINE]; // Current input line
    char longest[MAXLINE];  // Longest line saved here

    max = 0;
    while((len = get_line(line, MAXLINE)) > 0)
    {
        if(len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0)
    {
        printf("The longest line has: %d characters\n", max);
        printf("%s", longest);
    }

    return 0;
}


// getline: read a line into s, return length
int get_line(char line[], int maxline)
{
    int c;
    int i;

    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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


// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

