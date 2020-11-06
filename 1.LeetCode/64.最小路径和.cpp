/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <vector>
#include <iostream>
using namespace std;


// @lc code=start
class Solution {
public:
    // 动态规划
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[1][1] = grid[m-1][n-1];
        // 纵向扩展
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                int gx = m-i;
                int gy = n-j;
                if(i == 1){
                    dp[i][j] = grid[gx][gy] + dp[i][j-1];continue;
                }
                if(j == 1){
                    dp[i][j] = grid[gx][gy] + dp[i-1][j];continue;
                }
                dp[i][j] = min( dp[i][j-1] +  grid[gx][gy],  // 右走
                        dp[i-1][j] + grid[gx][gy]);         // 下走
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
            {1,2,3},
            {4,5,6}
    };
    cout << sol.minPathSum(grid);
    return 0;
}