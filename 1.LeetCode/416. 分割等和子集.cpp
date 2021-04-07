#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        return knapsack(nums, sum >> 1);
    }

private:
    bool knapsack(const vector<int> &nums, int target)
    {
        if (target == 0) return true;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
        // base
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = true;
        }
        // core
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[nums.size()][target];
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{1, 2, 3, 5};
        cout << sol.canPartition(nums) << endl;
    }
    return 0;
}
