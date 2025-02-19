#include <algorithm>
#include <iostream>
#include <vector>

/* Quicksort
 *
 * 1. Selection of the pivot element
 * 2. Partitioning
 * 3. Recursive sort
 */
std::vector<int> quicksort(std::vector<int> nums)
{
    // Base case - an array with a single element is always "sorted"
    if (nums.size() <= 1) {
        return nums;
    } else {
        int n = nums.size();
        int pivot = nums[n / 2];
        std::vector<int> left;
        std::vector<int> middle;
        std::vector<int> right;

        for (auto num : nums) {
            if (num < pivot) left.push_back(num);
            else if (num == pivot) middle.push_back(num);
            else if (num > pivot) right.push_back(num);
        }

        // Recursively sort and concatenate the parts
        left = quicksort(left);
        right = quicksort(right);

        // Combine sorted left, middle, and right parts
        std::vector<int> result;
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), middle.begin(), middle.end());
        result.insert(result.end(), right.begin(), right.end());

        return result;
    }
}

int main()
{
    std::cout << "Quicksort implementation in C++" << std::endl;

    std::vector<int> nums = {-9, -3, 5, 2, 6, 8, -6, 1, 3};
    std::vector<int> nums2 = {-9, -3, 5, 2, 6, 8, -6, 1, 3};

    // Print unsorted array
    std::cout << "Unsorted array: ";
    for (auto num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    // Print sorted (std) array
    std::sort(nums.begin(), nums.end());
    std::cout << "Sorted (std) array: ";
    for (auto num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    // Print sorted array
    nums2 = quicksort(nums2);
    std::cout << "Sorted (quicksort) array: ";
    for (auto num : nums2) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
