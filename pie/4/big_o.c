// p. 35
// Both these functions correctly return the maximum value.
// Big-O Notation

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int compareToMax(int array[], int n);
int compareToAll(int array[], int n);


int main()
{
    int array[] = {1,5,4,76,4,7,8};
    int max;

    max = compareToMax(array, sizeof(array)/sizeof(array[0]));
    printf("compareToMax: %d\n", max);

    max = compareToAll(array, sizeof(array)/sizeof(array[0]));
    printf("compareToAll: %d\n", max);


    return 0;
}


// Returns the largest value in an array of n non-negative integers - O(n) linear time
int compareToMax(int array[], int n)
{
    int curMax, i;

    // Make sure that there is at leas one element in the array
    if (n <= 0)
        return -1;

    // Set the largest number so far to the first array value
    curMax = array[0];

    // Compare every number with the largest number so far
    for (i = 1; i < n; i++)
    {
        if (curMax < array[i])
            curMax = array[i];
    }
    
    return curMax;
}


// Returns the largest value in an array of n non-negative integers - O(n^2) 
int compareToAll(int array[], int n)
{
    int i, j;
    bool isMax;

    // Make sure that there is at least one element in the array
    if (n <= 0)
        return -1;

    for (i = 0; i < n; i++)
    {   
        isMax = true;
        for (j = 0; j < n; j++)
        {
            // See if any value is greater
            if (array[j] > array[i])
            {
                isMax = false;  // array[i] is not the largest value
                break;
            }
        }

        // If isMax is true, no longer value exists; array[i] is max
        if (isMax) break;
    }
    
    return array[i];
}

