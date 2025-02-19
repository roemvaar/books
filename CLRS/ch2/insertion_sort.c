/**
 * Insertion sort implementation in C
 * 
 * Solves the sorting problem:
 *     * input: a sequence of n numbers (a1, a2,...,an)
 *     * output: a permutation (reordering) (a1', a2',...,an') of the input
 *       sequence such that a1' <= a2' <= ... <= an'
 * 
 * Efficient algorithm for sorting a small number of elements.
 * 
 * Insertion sort is a simple sorting algorithm that works by building a
 * a sorted array one item at a time. It is much like sorting a hand of
 * playing cards.
 * 
 * How it works:
 *  1. Divide the array: the array is virtually divided into sorted and unsorted
 *     part. Initially, the sorted part contains just the first element.
 *  2. Iterate through the unsorted part:
 *      * Pick the next element from the unsorted part
 *      * Compare the picked element with the elements in the sorted part
 *      * Shift all the elements greater than the picked element one position ahead
 *      * Insert the picked element into its correct position in the sorted part
 * 
 * Example:
 * Sort the array `numbers` [64,25,12,22,11,90], using insertion sort
 * 1 - sorted [64], unsorted [25,12,22,11,90], pick 25 and add it to sorted... 
 *      [64,25] -> [25,64]
 * 2 - sorted [25,64], unsorted [12,22,11,90], pick 12 and add it to sorted... 
 *      [25,64,12] -> [25,12,64] -> [12,25,64]
 * 3 - sorted [12,25,64], unsorted [22,11,90], pick 22 and add it to sorted... 
 *      [12,25,64,22] -> [12,25,22,64] -> [12,22,25,64]
 * 4 - sorted [12,22,25,64], unsorted [11,90], pick 11 and add it to sorted... 
 *      [12,22,25,64,11] -> [12,22,25,11,64] -> [12,22,11,25,64]
 *      -> [12,11,22,25,64] -> [11,12,22,25,64]
 * 5 - sorted [11,12,22,25,64], unsorted [90], pick 90 and add it to sorted... 
 *      [11,12,22,25,64,90]
 */

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, size_t size);


// void insertion_sort(int *array, size_t size)
// {
//     for (int i = 1; i < size; i++) {
//         int key = array[i];

//         // insert array[i] into sorted subarray array[0:i-1]
//         int j = i - 1;

//         while (j >= 0 && array[j] > key) {
//             array[j+1] = array[j];
//             j = j -1;
//         }

//         array[j+1] = key;
//     }
// }

void print_array(int *array, size_t size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int numbers[] = {64,25,12,22,11,90};
    print_array(numbers, 6);
    insertion_sort(numbers, 6);
    print_array(numbers, 6);

    int numbers_2[] = {42,17,-3,89,0,-15};
    print_array(numbers_2, 6);
    insertion_sort(numbers_2, 6);
    print_array(numbers_2, 6);

    int numbers_3[] = {31,41,59,26,41,58};
    print_array(numbers_3, 6);
    insertion_sort(numbers_3, 6);
    print_array(numbers_3, 6);

    return 0;
}


void insertion_sort(int *array, size_t size)
{
    for (int i = 1; i < size; i++) {
        int key = array[i];     // First element of unsorted sub-array

        // Insert key into sorted sub-array
        int j = i - 1;  // This is the right-most element of the sorted sub-array

        // This finds on which position key needs to be placed on the sorted sub-array
        // We need to find an element that is less or equal than key, and place key
        // to the right of this element
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j = j - 1;
        }

        // After we find the element that is less than or equal than key, then we place key
        // to the right of it
        array[j+1] = key;
    }
}
