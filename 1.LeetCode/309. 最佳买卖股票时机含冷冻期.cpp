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
        int dp0[2] = {0};    // 1 freeze or 0 not freeze. dp0代表当前没有持有股票
        int dp1 = -prices[0];       // dp1 代表当前持有股票
        for (int i = 1; i < prices.size(); i++) {
            int old_dp00 = dp0[0];
            dp0[0] = max(dp0[0], dp0[1]);       // not freeze 来自前一个not freeze或freeze
            dp0[1] = dp1 + prices[i];           // dp0 且 freeze 只会来自一次股票卖出
            dp1 = max(dp1, old_dp00 - prices[i]);   // dp1 来自上一次dp1或者来自一次not freeze状态下的购入
        }
        return max(dp0[0], dp0[1]);
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{1, 2, 4};
        cout << sol.maxProfit(nums) << endl;
    }
    return 0;
}
