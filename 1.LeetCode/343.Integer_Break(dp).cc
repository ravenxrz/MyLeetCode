//
// Created by raven on 2021/7/16.
//

#include "leetcode_base.h"

class Solution {
public:
    int integerBreak(int n)
    {
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        } else if (n == 4) {
            return 4;
        }
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        for (int i = 5; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max({dp[i], dp[i - j] * j, (i - j) * j});
            }
        }
        
        return dp[n];
    }
};


int main()
{
    Solution sol;
    cout << sol.integerBreak(2) << endl;
    cout << sol.integerBreak(10) << endl;
    return 0;
}
