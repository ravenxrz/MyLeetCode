/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();

        vector<int> ans;
        int i = 0, j = 0;
        ans.push_back(matrix[0][0]);
        bool up = true;
        while (i != m - 1 || j != n - 1) {
            if (up) {
                i--;
                j++;
                if (i >= 0 && j <= n - 1) {
                    ans.push_back(matrix[i][j]);
                } else if (i < 0) {
                    if (j <= n-1) j++;
                    else i++;
                    up = false;
                } else if (j > n - 1) {
                    i++;
                    up = false;
                }
            } else {  // down
                i++;
                j--;
                if (i <=m-1 && j >=0 ) {
                    ans.push_back(matrix[i][j]);
                } else if (i > m - 1) {
                    j++;
                    up = true;
                } else if (j <= 0) {
                    i++;
                    up = true;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
            {1,2},
            {3,4}
    };
    const vector<int> &vector = sol.findDiagonalOrder(matrix);

    return 0;
}