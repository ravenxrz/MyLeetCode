//
// Created by Raven on 2021/3/16.
//

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        dfs(board, 0, 0);
    }
    
    bool dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i == board.size()) {
            return true;
        }
        
        if (j == 9) {
            // 换到下一行
            return dfs(board, i + 1, 0);
        }
        
        // 如果已经被填充
        if (board[i][j] != '.') {
            return dfs(board, i, j + 1);
        }
        
        // 填充当前
        for (int k = '1'; k <= '9'; ++k) {
            if (is_valid(board, i, j, k)) {
                board[i][j] = k;
                if (dfs(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    bool is_valid(const vector<vector<char>> &board, int i, int j, char ch)
    {
        for (int k = 0; k <= 8; k++) {
            // row check
            if (board[i][k] == ch) return false;
            // col check
            if (board[k][j] == ch) return false;
            // 方格check
            if (board[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3] == ch) return false;
        }
        return true;
    }
    
    
};

