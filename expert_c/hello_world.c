#include <stdio.h>

int numbers[1000] = {1};

int main()
{
	printf("Hello World!\n");

	for (int i = 0; i < 1000; i++) {
		numbers[i] = i + i;
	}

	return 0;
}

