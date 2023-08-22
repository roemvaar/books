#include <stdio.h>

int main(void)
{
	int apple;
	int p = 5;

	apple = sizeof(int) * p;
	
	printf("apple = %d\n", apple);

	return 0;
}

