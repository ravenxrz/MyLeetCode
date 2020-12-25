/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int> &nums)
    {
        return f(nums, 0, nums.size() - 1);
    }

private:
    int f(const vector<int> &nums, int start, int end)
    {
        int mid = (start + end) / 2;
        if (mid == nums.size() - 1) return mid;
        
        if (nums[mid] > nums[mid + 1]) {
            if (mid == 0 || nums[mid] > nums[mid - 1]) return mid;
            else return f(nums, start, mid - 1);
        } else {
            return f(nums, mid + 1, end);
        }
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {1, 2};
    Solution sol;
    cout << sol.findPeakElement(nums) << endl;
    
    return 0;
}
