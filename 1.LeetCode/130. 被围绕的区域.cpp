#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board)
    {
        const int m = board.size();
        if (m == 0) return;
        const int n = board[0].size();
        if (n == 0) return;
        // 从边缘触发
        for (int j = 0; j < n; j++) {
            // 第一行
            // 最后一行
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 1; i < m - 1; i++) {
            // 第一列和最后一列
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        // 设置0 --> X
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        // 设置 "-" --> 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '-') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return;
        }
        if (board[i][j] != 'O') return;
        board[i][j] = '-';
        // 上
        dfs(board, i - 1, j);
        // 下
        dfs(board, i + 1, j);
        // 左
        dfs(board, i, j - 1);
        // 右
        dfs(board, i, j + 1);
    }
};