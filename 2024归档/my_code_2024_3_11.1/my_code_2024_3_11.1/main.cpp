#include <vector>
#include <iostream>

class Solution
{
public:
    int searchLeft(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while (left < right)
        {
            middle = (left + right) / 2;

            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] >= target)
            {
                right = middle;
            }
        }
        return right;
    }
    int searchRight(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while (left < right)
        {
            middle = (left + right + 1) / 2;

            if (nums[middle] <= target)
            {
                left = middle + 1;
            }
            else if (nums[middle] > target)
            {
                right = middle;
            }
        }
        return left;
    }
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        return { searchLeft(nums, target), searchRight(nums, target) };

    }
};

int main()
{
    Solution s;
    std::vector<int> v { 1, 3, 3, 3, 3, 3, 3, 5 };
    std::cout << s.searchRange(v, 3)[0] << std::endl;
    std::cout << s.searchRange(v, 3)[1] << std::endl;
    return 0;
}