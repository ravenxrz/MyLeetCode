#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.empty()) return 0;
        const int m = triangle.size();
        const int n = triangle[m - 1].size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < m; i++) {
            auto tmp = dp;
            // first one
            tmp[0] = dp[0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                tmp[j] = min(
                        dp[j],
                        dp[j - 1]
                ) + triangle[i][j];
            }
            // last one
            tmp[i] = dp[i - 1] + triangle[i][i];
            dp.swap(tmp);
        }
        // find min one
        return *min_element(dp.begin(),dp.end());
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> triangles = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    cout << sol.minimumTotal(triangles) << '\n';
    return 0;
}
