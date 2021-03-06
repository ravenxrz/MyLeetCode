//
// Created by Raven on 2021/2/10.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    // assert (!grid.empty()) 题目中说了grid不可能为空
    int maxValue(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化dp
        dp[0][0] = grid[0][0];
        // row initialize
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        // column initialize
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        // others
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution sol;
    {
        vector<vector<int>> grid = {
                {1,2,5},
                {3,2,1}
        };
        cout << sol.maxValue(grid) << '\n';
    }
    return 0;
}
