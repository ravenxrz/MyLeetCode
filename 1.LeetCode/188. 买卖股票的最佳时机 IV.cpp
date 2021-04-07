//
// Created by Raven on 2021/3/13.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.empty() || k == 0) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(2, INT_MIN >> 1));
        // init base
        dp[0][0] = 0;
        dp[1][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            for (int j = k; j >= 0; j--) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], j == 0 ? INT_MIN >> 1 : dp[j - 1][0] - prices[i]);
            }
        }
        int max_value = 0;
        for (int i = 1; i <= k; i++) {
            max_value = max(max_value, dp[i][0]);
        }
        return max_value;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{2, 4, 1};
        cout << sol.maxProfit(2, nums) << endl;
    }
    return 0;
}
