#include <stdio.h>
#include "libraries/libmath.h"


int main(void)
{
    int a;
    int b;
    int result;

    a = 5;
    b = 10;

    printf("Static libraries\n");

    result = addTwoNumbers(a, b);
    printf("%d + %d = %d\n", a, b, result);

    result = multiplyTwoNumbers(a, b);
    printf("%d * %d = %d\n", a, b, result);

    return 0;
}
