/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid.at(0).size();

        // dp, 多申请一个第0行和第0列，方便计算
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));

        // 因为后续采用行扫描，所以这里需要提前填充 最后一列 mx1
        for (int i = m - 1; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 1) {
                break;
            }
            dp[m - i][1] = 1;
        }

        // dp 核心算法
        for (int i = 1; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                if (obstacleGrid[m - i][n - j] == 1) {
                    dp[i][j] = 0;
                    continue;
                } else {
                    // 行扫描
                    for (int k = 1; k <= i; k++) {
                        if (obstacleGrid[m - (i - k + 1)][n - j] == 1)
                            break;
                        if (obstacleGrid[m - (i - k + 1)][n - (j - 1)] == 1)
                            continue;
                        dp[i][j] += dp[i - k + 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

