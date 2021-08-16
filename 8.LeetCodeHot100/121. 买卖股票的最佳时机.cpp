#include "leetcode_base.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int min_value = prices[0];
        int max_value = 0;
        for (int i = 1; i < prices.size(); i++) {
            max_value = max({max_value, 0, prices[i] - min_value});
            min_value = min(min_value, prices[i]);
        }
        return max_value;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout <<  sol.maxProfit(prices) << endl;
    return 0;
}