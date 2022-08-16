#include <stdio.h>
#include <stdlib.h>

/* The following piece of C code shows how to sort
 * a list of integers using qsort.
 * source: https://en.wikipedia.org/wiki/Qsort
 */

/* Comparison function. Receives two generic (void)
 * pointers to the items under comparison.
 */
int compare_ints_ascending(const void *p, const void *q)
{
    int x = *(const int *)p;
    int y = *(const int *)q;
    int ret;

    /* Ret Values meaning:
     * <0 element1 less than element 2
     *  0 element1 equal to element2
     * >0 element1 greater than element 2
     */

    /* Avoid return x - y, which can cause undefined
     * behaviour because of signed integer overflow.
     */
    if(x < y) {
        ret = -1;
    }
    else if(x > y) {
        ret = 1;
    }
    else {
        ret = 0;
    }

    return ret;
}

int compare_ints_descending(const void *p, const void *q)
{
    int x = *(const int *)p;
    int y = *(const int *)q;
    int ret;

    /* Avoid return x - y, which can cause undefined
     * behaviour because of signed integer overflow.
     */
    if(x < y) {
        ret = 1;
    }
    else if(x > y) {
        ret = -1;
    }
    else {
        ret = 0;
    }

    return ret;
}

/* Sort an array of n integers, pointed to by a.
 */
void sort_ints(int *a, size_t n, int order)
{
    if(order == 1) {
        qsort(a, n, sizeof(*a), compare_ints_descending);
    }
    else {
        qsort(a, n, sizeof(*a), compare_ints_ascending);
    }
}

void print_array(int *a, size_t n)
{
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); 
}

int main(void)
{
    int nums1[10] = {10, -15, 8, 87, 5123, 4, 0, 97, 324, -17};
    int nums2[5] = {26, 892, 2, 85, -8};

    print_array(nums1, 10);
    print_array(nums2, 5);

    printf("Sorted (Ascending) Arrays\n");

    sort_ints(nums1, 10, 0);
    sort_ints(nums2, 5, 0);

    print_array(nums1, 10);
    print_array(nums2, 5);

    printf("Sorted (Descending) Arrays\n");

    sort_ints(nums1, 10, 1);
    sort_ints(nums2, 5, 1);

    print_array(nums1, 10);
    print_array(nums2, 5);

    return 0;
}
