//
// Created by Raven on 2021/3/16.
//

/**
  * dp 解法
  */
class Solution {
public:
    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT16_MAX);
        // base
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[nums.size() - 1];
    }
};


/**
 * 贪心算法
 */
int jump(vector<int> &nums)
{
    int n = nums.size();
    int end = 0, farthest = 0;
    int jumps = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(nums[i] + i, farthest);
        if (end == i) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}