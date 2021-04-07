//
// Created by Raven on 2021/3/13.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty()) return 0;
        // dp[k][s] 代表当前进行了k次交易，处于s状态下
        vector<vector<int>> dp(3, vector<int>(2, INT_MIN >> 1));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN >> 1;
        dp[1][0] = INT_MIN >> 1;
        dp[1][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            for (int k = 2; k >= 0; k--) {
                dp[k][0] = max(dp[k][0], dp[k][1] + prices[i]);
                dp[k][1] = max(dp[k][1], k == 0 ? INT_MIN : dp[k - 1][0] - prices[i]);
            }
        }
        return max({dp[0][0], dp[1][0], dp[2][0]});
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 3, 4, 5};
    cout << sol.maxProfit(nums) << endl;
    return 0;
}
