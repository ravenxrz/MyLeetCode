#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        if (nums.empty()) return 0;
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if ((S + sum) & 1) return 0;
        if (sum < S) return 0;
        
        return knapsack_problem(nums, (S + sum) >> 1);
    }

private:
    static int knapsack_problem(const vector<int> &nums, int capacity)
    {
        vector<int> dp(capacity + 1, 0);
        // 取第1个物品，但是容量是0， 只有1种取法
        dp[0] = 1;
        
        // 计算
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = capacity; j >= 0; --j) {
                if (j >= nums[i - 1])
                    dp[j] = dp[j] + dp[j - nums[i - 1]];
                else
                    dp[j] = dp[j];
            }
        }
        return dp[capacity];
    }
};

int main()
{
    Solution sol;
    /**
     * [1,2,7,9,981]

     */
    vector<int> nums{1, 2, 7, 9, 981};
    cout << sol.findTargetSumWays(nums, 1000000000) << '\n';
    return 0;
}
