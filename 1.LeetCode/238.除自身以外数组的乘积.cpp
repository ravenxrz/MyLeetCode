#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> L(length, 0);
        vector<int> R(length, 0);

        L[0] = 1;
        for (int i = 1; i < length; i++)
        {
            L[i] = nums[i - 1] * L[i - 1];
        }

        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--)
        {
            R[i] = nums[i + 1] * R[i + 1];
        }

        for (int i = 0; i < length; i++)
        {
            nums[i] = L[i] * R[i];
        }
        return nums;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    {
        vector<int> nums = {-1, 1, -3, 3};
        const vector<int> &ans = sol.productExceptSelf(nums);
        for (int val : ans)
        {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}