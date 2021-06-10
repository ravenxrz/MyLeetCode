#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        assert(!nums.empty());
        int left = 0;
        int right = nums.size() - 1;

        // Use binary search to find the minimum value
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (nums[left] <= nums[right])
            {
                return nums[left];
            }
            else if (nums[left] > nums[right])
            {
                if (nums[left] > nums[mid])
                {
                    right = mid;
                }
                else if (nums[left] <= nums[mid])
                {
                    left = mid + 1;
                }
            }
        }
        return nums[left];
    }
};
// @lc code=end

int main()
{
    Solution sol;
    // the times of Rotated < n
    {
        vector<int> arr = {6, 7, 1, 2, 3, 4, 5};
        cout << sol.findMin(arr);
    }
    // the times of Rotated == n
    {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
        cout << sol.findMin(arr);
    }
    return 0;
}