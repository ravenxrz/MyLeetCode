//
// Created by Raven on 2021/3/17.
//


class Solution {
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || word.empty()) return false;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        // find first matching char
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (word[0] == board[i][j]) {
                    if (back_trace(board, visit, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }

private:
    bool
    back_trace(const vector<vector<char>> &board, vector<vector<bool>> &visit, int cur_x, int cur_y, const string &word,
               int idx)
    {
        if (idx == word.size()) return true;
        if (cur_x < 0 || cur_x >= board.size() || cur_y < 0 || cur_y >= board[0].size()) return false;
        if (visit[cur_x][cur_y] || word[idx] != board[cur_x][cur_y]) return false;
        
        // try traverse
        visit[cur_x][cur_y] = true;
        bool ret = back_trace(board, visit, cur_x + 1, cur_y, word, idx + 1) ||
                   back_trace(board, visit, cur_x - 1, cur_y, word, idx + 1) ||
                   back_trace(board, visit, cur_x, cur_y + 1, word, idx + 1) ||
                   back_trace(board, visit, cur_x, cur_y - 1, word, idx + 1);
        visit[cur_x][cur_y] = false;
        return ret;
    }
};
