//
// Created by Raven on 2021/3/14.
//

//
// Created by Raven on 2021/3/13.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        if (prices.empty()) return 0;
        int dp0 = 0;
        int dp1 = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp0 = max(dp0, dp1 + prices[i] - fee);
            dp1 = max(dp1, dp0 - prices[i]);
        }
        return dp0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 3, 2, 8, 4, 9};
    cout << sol.maxProfit(nums, 2) << endl;
    return 0;
}
