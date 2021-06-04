// Chapter 1 - Functions
// power(m, n)
// This function is not a practical exponentiation routine,
// since it handles only positive power of small integers, 
// but it's good for illustration.

#include <stdio.h>

int power(int m, int n);


int main(void)
{
    int i;
    
    for(i = 0; i < 10; ++i)
    {
        printf("%d %d\n", i, power(2,i));
    }

    return 0;
}


// power: raise base to n-th power; n >= 0
int power(int m, int n)
{
    int i, p;

    p = 1;
    for(i = 0; i <= n; ++i)
    {
        p = p * m;
    }
    
    return p;
}

