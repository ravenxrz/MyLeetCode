#include "leetcode_base.h"

class Solution {
    int dp[3][2][100010];  // dp[i][j][k]
                           // 代表第i次交易，手上有j张股票，第k天时的最大利益
                           // 规定卖出股票时，交易次数加1

   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        memset(dp, 0, sizeof(dp));
        // init
        for (int i = 0; i <= 2; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = -prices[0];
        }
        // dp
        for (int i = 0; i <= 2; i++) {
            for (int k = 1; k < prices.size(); k++) {
                dp[i][0][k] =
                    max({dp[i][0][k - 1],
                         i == 0 ? 0 : dp[i - 1][1][k - 1] + prices[k]});
                dp[i][1][k] =
                    max({dp[i][1][k - 1], dp[i][0][k - 1] - prices[k]});
            }
        }

        return max({dp[0][0][prices.size() - 1], dp[1][0][prices.size() - 1],
                    dp[2][0][prices.size() - 1]});
    }
};

int main() {
    Solution sol;
    {
        vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
        cout << sol.maxProfit(prices) << endl;
    }
    {
        vector<int> prices = {1, 2, 3, 4, 5};
        cout << sol.maxProfit(prices) << endl;
    }
    {
        vector<int> prices = {7, 6, 4, 3, 1};
        cout << sol.maxProfit(prices) << endl;
    }
    return 0;
}