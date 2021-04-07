//
// Created by Raven on 2021/2/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid)
    {
        const int m = grid.size();
        if (m == 0) return 0;
        const int n = grid[0].size();
        if (n == 0) return 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }

private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] != '1') return;
        grid[i][j] = '0';
        // up
        dfs(grid, i - 1, j);
        // down
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};