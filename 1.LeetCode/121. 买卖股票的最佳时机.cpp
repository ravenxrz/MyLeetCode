#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty()) return 0;
        int min_value = prices[0];
        int max_value = 0;
        for (int i = 1; i < prices.size(); i++) {
            min_value = min(min_value, prices[i]);
            max_value = max(max_value, prices[i] - min_value);
        }
        return max_value;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{7, 1, 5, 3, 6, 4};
        cout << sol.maxProfit(nums) << '\n';
    }
    {
        vector<int> nums{7, 6, 4, 3, 1};
        cout << sol.maxProfit(nums) << '\n';
    }
    return 0;
}
