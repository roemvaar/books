// Ch 1 - Ex 18. Write a program to remove trailing blanks and tabs
// from each line of input, and to delete entirely blank lines.

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);


int main(void)
{
    int len;
    char line[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0)
    {
        if(len > 1)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int get_line(char line[], int maxline)
{
    int c;
    int i;
    int j;

    i = 0;
    j = 0;
    
    while((c = getchar()) != EOF && c != '\n')
    {
        if(j < maxline)
        {
            line[j] = c;
            j++;
        }

        if(c != ' ' && c != '\t')
        {
            i = j;
        }
    }

    if(c == '\n' && i++ < maxline)
    {
        line[i - 1] = '\n';
    }

    line[(i < maxline) ? i : maxline - 1] = '\0';

    return i;
}

