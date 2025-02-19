// Selection sort

#include <stdio.h>

void print_array(int* nums, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d, ", nums[i]);
    }

    printf("\n");
}

void selection_sort(int* nums, int size)
{
    for (int i = 0; i < size; i++) {
        int smallest = i;
        int j;

        for (j = i + 1; j < size; j++) {
            if (nums[smallest] > nums[j]) {
                smallest = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[smallest];
        nums[smallest] = temp;
    }
}

int main()
{
    int nums[] = {25,45,85,98,15,21,33};

    printf("Unsorted array: ");
    print_array(nums, 7);

    selection_sort(nums, 7);

    printf("Sorted array: ");
    print_array(nums, 7);

    return 0;
}

