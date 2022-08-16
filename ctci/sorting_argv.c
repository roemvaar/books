#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This example sorts the arguments (argv) in ascending sequence,
 * based on the ASCII value of each character and string, and using
 * the comparison function compare() supplied in the example.
 * source:  https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-qsort-sort-array
 */

int compare(const void *arg1, const void *arg2);

int main(int argc, int *argv[])
{
    int i;
    argc--;
    argv++;
    qsort((char *)argv, argc, sizeof(char *), compare);
    for(i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}

int compare(const void *arg1, const void *arg2)
{
    return(strcmp(*(char **)arg1, *(char **)arg2));
}
