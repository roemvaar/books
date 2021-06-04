// Exercise 1-17 Write a program to print all input lines that are
// longer than 80 characters

#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

int get_line(char line[], int maxline);


int main(void)
{
    int len;
    char line[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0)
    {
        // Check if the line is greater than 1000 characters
        if(line[len - 1] != '\n')
        {
            printf("The line is greater than 1000 characters:\n");
            printf("%s\n", line);
        }
        else if(len > MINLINE)
        {
            printf("%s\n", line);
        }
    }

    return 0;
}


int get_line(char line[], int maxline)
{
    int c;
    int i;

    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }

    if(c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}


