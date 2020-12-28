/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <bits/stdc++.h>

using namespace std;


// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int ans = 0;
        // dp[i][j] 代表以matrix[i][j]==1为右下角的正方形的最大边长
        vector<vector<int>> dp(m, vector<int>(n));
        // set first row and column
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            ans = max(dp[0][j],ans);
        }
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            ans = max(dp[i][0],ans);
        }
        // set dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ans = max(dp[i][j],ans);
                }
            }
        }
       return ans * ans; 
    }
};
// @lc code=end

