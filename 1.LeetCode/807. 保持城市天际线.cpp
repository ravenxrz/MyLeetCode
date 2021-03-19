#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        if (grid.empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<int> row(m + 1, 0);
        vector<int> col(n + 1, 0);
        
        // calc max value
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += (min(row[i], col[j]) - grid[i][j]);
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
            {3, 0, 8, 4},
            {2, 4, 5, 7},
            {9, 2, 6, 3},
            {0, 3, 1, 0}
    };
    cout << sol.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}
