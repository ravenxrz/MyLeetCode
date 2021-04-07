#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty()) return 0;
        int not_hold = 0;
        int hold = -prices[0];
        for(int i = 1;i<prices.size();i++){
            int tmp_not_hold = max(not_hold, hold + prices[i]);
            int tmp_hold = max(hold, not_hold - prices[i]);
            not_hold = tmp_not_hold;
            hold = tmp_hold;
        }
        return not_hold;
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
        vector<int> nums{1,2,3,4,5};
        cout << sol.maxProfit(nums) << '\n';
    }
    
    
    {
        vector<int> nums{7, 6, 4, 3, 1};
        cout << sol.maxProfit(nums) << '\n';
    }
    return 0;
}
