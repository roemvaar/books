/* Sharing data: oh oh
 * $ gcc -pthread -o t1 t1.c -Wall
 */

#include <stdatomic.h>
#include <stdio.h>
#include <pthread.h>


// static volatile int counter = 0;
static atomic_int counter = 0;

/* my_thread
 *
 * Simply adds 1 to counter repeteadly, in a loop
 * No, this is not how you would add 10,000,000 to
 * a counter, but it shows the problem nicely.
 */
void *mythread(void *arg)
{
    printf("%s: begin\n", (char *)arg);

    for (int i = 0; i < 1e7; i++) {
        atomic_fetch_add(&counter, 1);
    }

    printf("%s: done\n", (char *)arg);

    return NULL;
}

/* main
 *
 * Just launches two threads (pthread_create)
 * and then waits for them (pthread_join)
 */
int main(int argc, char *argv[])
{
    pthread_t p1;
    pthread_t p2;

    printf("main: begin (counter = %d)\n", atomic_load(&counter));

    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");

    // join waits for the threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("main: done with both (counter = %d)\n", atomic_load(&counter));

    return 0;
}
