#include "leetcode_base.h"

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;

        vector<vector<int>> dp(triangle.size(),
                               vector<int>(triangle.back().size(), INT32_MAX));
        // Init the first column
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
        }

        // Calculate
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < triangle[i].size(); j++) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        // Find the  mininum value at last row
        int min_value = INT32_MAX;
        for (int j = 0; j < dp.back().size(); j++) {
            min_value = min(min_value, dp.back()[j]);
        }

        return min_value;
    }
};

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    cout << sol.minimumTotal(triangle);
    return 0;
}