// Exercise 1-19 Write a function reverse(s) that reverses the character string s.
// Use it to write a program that reverses its inpute a line at a time.

#include <stdio.h>
#include <string.h>


void reverse(char* s, int size);


int main(void)
{
    char s[100] = "Gustavo Nicolas Montenegro Covarrubias";
       
    reverse(s, sizeof(s)/sizeof(char));
    
    return 0;
}

void reverse(char* s, int size)
{
    int i;

    for(i = size - 1; i >= 0; i--)
    {
        printf("%c", s[i]);
    }

    printf("\n");
}

