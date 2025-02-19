#include <algorithm>
#include <iostream>
#include <vector>


std::vector<int> qsort(std::vector<int> nums)
{
    // Base case is a vector that has one element because it is always
    // sorted
    if (nums.size() <= 1) {
        return nums;
    } else {
        // 1. Select a pivot (it can be any element of nums)
        int n = nums.size();
        int pivot = nums[n / 2];

        // 2. Partition
        std::vector<int> left;
        std::vector<int> middle;
        std::vector<int> right;

        for (auto num : nums) {
            if (num < pivot) left.push_back(num);
            else if (num == pivot) middle.push_back(num);
            else if (num > pivot) right.push_back(num);
        }

        // 3. Sort left and right
        left = qsort(left);
        right = qsort(right);

        // Concate the three sorted arrays
        std::vector<int> result;
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), middle.begin(), middle.end());
        result.insert(result.end(), right.begin(), right.end());

        return result;
    }
}


int main()
{
    std::vector<int> nums = {3,6,8,10,1,2,1};

    nums = qsort(nums);
    for (auto num : nums) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
