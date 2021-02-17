//
// Created by Raven on 2021/2/17.
//


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        const int len1 = text1.length();
        const int len2 = text2.length();
        // 还可以空间优化，因为dp[i][j] 只与 dp[i-1][j] 和 dp[i][j-1]相关，所以用两个一维数组即可解决
        vector <vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // try to calculate
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
