#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S) return 0;
        if ((sum + S) & 1) return 0;
        return knapsack(nums, (sum + S) >> 1);
    }
    
    int knapsack(const vector<int> &nums, int target)
    {
        int m = nums.size();
        int n = target;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 0; --j) {        // 逆向遍历，   这里j=1结尾，是假设　w[i] > 0 ， 如果w[i]=0, 则j应该从0开始。 参考lc:494.目标和
                if (j >= nums[i - 1]) {
                    dp[j] = dp[j] + dp[j - nums[i - 1]];
                }
            }
        }
        
        return dp[n];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    cout << sol.knapsack(nums, 1) << endl;
    return 0;
}