/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> count(m, vector<int>(n, 0));
        int ans = 0;
        // set first row and column
        for (int j = 0; j < n; j++) {
            count[0][j] = matrix[0][j] == 1 ? 1 : 0;
            ans+=count[0][j];
        }
        for (int i = 0; i < m; i++) {
            count[i][0] = matrix[i][0] == 1 ? 1 : 0;
            ans+=count[i][0];
        }
        ans -= matrix[0][0];
        // set others
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    count[i][j] = min(count[i - 1][j - 1], min(count[i - 1][j], count[i][j - 1])) + 1;
                    ans+=count[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> matrix{
            {1,0,1},
            {1,1,0},
            {1,1,10}
    };
    Solution sol;
    cout << sol.countSquares(matrix) << endl;
    return 0;
}
