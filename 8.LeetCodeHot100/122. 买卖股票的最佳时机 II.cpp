#include "leetcode_base.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        // init
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
        }
        return dp[0][prices.size() - 1];
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}