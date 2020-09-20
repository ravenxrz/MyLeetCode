/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing_number = 0;
        for (int i = 0; i < nums.size();i++){
            missing_number = missing_number ^ nums.at(i) ^ (i + 1);
        }
         return missing_number;
    }
};
// @lc code=end

