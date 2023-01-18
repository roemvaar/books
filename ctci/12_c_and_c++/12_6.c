// 12.6 Volatile: What is the significance of the keyword "volatile" in C?
//
// The keyword volatile informs the compiler that the value of the variable it is
// applied to can change from the outside, without any update done by the code. This
// may be done by the operating system, the hardware, or another thread. Because
// the value can change unexpectedly, the compiler will therefore reload the value
// each time from memory.
//
// A volatile integer can be declared by either of the following statements:
// int volatile x;
// volatile int x;
//
// To declare a pointer to a volatile integer, we do the following:
// volatile int *x;
// int volatile *x;
//
// A volatile pointer to non-volatile data is rare, we do the following:
// int *volatile x;
//
// If you wanted to declare a volatile variable pointer for volatile memory (both
// pointer address and memory contained are volatile), you would do the following:
// int volatile *volatile x;
//
// Volatile variables are not optimized, which can be very useful.
//
// Volatile variables are also useful when multi-threaded programs have global
// variables and any thread can modify these shared variables. We may not want to
// There's a caveat to this last statement. Volatile variables are not a good
// practice in multi-threaded programs because they can lead to race conditions.
// You may use locks, semaphores, or atomic operations for managing multi-threaded
// operations. 

#include <stdio.h>

volatile int opt = 1;

void fn(void)
{
	start:
		if (opt == 1) {
			printf("1");
			goto start;
		}
		else return;
}

int main(void)
{
	fn();	

	return 0;
}

