#include "leetcode_base.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int max_profit = 0;
        int min_value = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            max_profit = max(max_profit, prices[i] - min_value);
            min_value = min(min_value, prices[i]);
        }
        return max_profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 4};
    cout << sol.maxProfit(prices);
    return 0;
}