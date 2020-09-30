/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        set<int> set(nums.begin(), nums.end());
        long long sum1 = 0, sum2 = 0;
        
        for(const auto &val : set){
            sum1 += val;
        }
        sum1 = 3 * sum1;

        for(const auto &val : nums){
            sum2 += val;
        }
        return (sum1 - sum2) / 2;
    }
};
// @lc code=end
