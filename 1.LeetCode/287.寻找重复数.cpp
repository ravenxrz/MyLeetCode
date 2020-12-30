/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0, j = 0;
        // first meet
        do {
            i = nums[i];
            j = nums[nums[j]];
        } while (i != j);
        // second meet
        i = 0;
        do {
            i = nums[i];
            j = nums[j];
        } while (i != j);
        return i;
    }
};
// @lc code=end

int main()
{
    vector<int> nums{1,2,3,5,4,2};
    Solution sol;
    cout << sol.findDuplicate(nums) << endl;
    return 0;
}

