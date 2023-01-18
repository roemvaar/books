// 12.2 Reverse String: Implement a function void reverse(char *str)
// in C or C++ which reverses a null-terminated string.

#include <stdio.h>
#include <string.h>

void reverse(char *str);
void swap(char *str, int a, int b);

void reverse(char *str)
{
	int left = 0;
	int right = strlen(str) - 1;

	while (left < right) {
		swap(str, left, right);
		left++;
		right--;
	}
}

void swap(char *str, int a, int b)
{
	char temp = str[a];	

	str[a] = str[b];
	str[b] = temp;
}

int main()
{
	//char str[] = "roberto";
	//char str[] = "";
	char str[] = "como tu";
	
	printf("Original str: %s\n", str);

	reverse(str);

	printf("Reverse str: %s\n", str);
	
	return 0;
}
