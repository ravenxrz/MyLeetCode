//
// Created by raven on 2021/7/20.
//

class Solution {
    int dp[60];
public:
    int cuttingRope(int n)
    {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        memset(dp, 0, sizeof(dp));
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max({dp[i],
                             j * (i - j),
                             dp[j] * dp[i - j],
                             dp[j] * (i - j),
                             (j) * dp[i - j]
                            });
            }
        }
        return dp[n];
    }
};

