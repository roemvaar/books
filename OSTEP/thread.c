// gcc -pthread -o thread thread.c -Wall

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int counter = 0;
int loops;


void *worker(void *arg)
{
    int i;
    for(i = 0; i < loops; ++i) {
        counter++;
    }

    return NULL;
}

/* Note: this code is not SMP safe - it produces incorrect
 * output when you pass a big number as an argument. This occurs
 * because the loop at worker has three instructions that do not
 * execute atomically (all at once), strange things can happen
 */
int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "usage: threads <value>\n");
        exit(1);
    }

    loops = atoi(argv[1]);
    pthread_t p1;
    pthread_t p2;

    printf("Initial value: %d\n", counter);

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);     // tells main to wait until p1 is completed
    pthread_join(p2, NULL);

    printf("Final value: %d\n", counter);

    return 0;
}

