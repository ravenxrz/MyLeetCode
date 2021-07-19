#include "leetcode_base.h"

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // Find the start point
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word.front()) {
                    visit[i][j] = true;
                    if (dfs(board, visit, word, 1, i, j))
                        return true;
                    visit[i][j] = false;
                }
            }
        }
        return false;
        
    }

private:
    int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };
    
    bool dfs(const vector<vector<char>> &board, vector<vector<bool>> &visit, const string& target, int len, int x, int y)
    {
        if (target.size() == len) return true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dp[i][0];
            int ny = y + dp[i][1];
            if (nx >= board.size() || nx < 0
                || ny >= board[0].size() || ny < 0
                || visit[nx][ny]
                || board[nx][ny] != target[len]) {
                continue;
            }
            
            visit[nx][ny] = true;
            if (dfs(board, visit, target, len + 1, nx, ny)) {
                return true;
            }
            visit[nx][ny] = false;
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
            {'a', 'b'},
            {'c', 'd'}
    };
    Solution sol;
    cout << sol.exist(board, "abcd") << endl;
    return 0;
}
