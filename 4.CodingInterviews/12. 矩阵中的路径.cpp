/**
 *  请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 *  路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
 *  如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
 *  例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

    [["a","b","c","e"],
    ["s","f","c","s"],
    ["a","d","e","e"]]

    但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.empty() || board.empty() || board[0].empty()) return false;
        
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size()));
        // find the first character
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    visit[i][j] = true;
                    if (dfs(board, visit, word, 1, i, j)) {
                        return true;
                    }
                    visit[i][j] = false;
                }
            }
        }
        return false;
    }

private:
    static bool
    dfs(const vector<vector<char>> &board, vector<vector<bool>> &visit, const string &word, int idx, int cur_x,
        int cur_y)
    {
        const int m = board.size();
        const int n = board[0].size();
        
        if (idx >= word.size()) return true;
        char c = word[idx];
        
        for (int i = 0; i < 4; i++) {
            int tmp_x = cur_x;
            int tmp_y = cur_y;
            switch (i) {
                case 0: // up
                    tmp_x--;
                    break;
                case 1: // down
                    tmp_x++;
                    break;
                case 2: // left
                    tmp_y--;
                    break;
                case 3:
                    tmp_y++;
                    break;
            }
            if (tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n &&
                !visit[tmp_x][tmp_y] && board[tmp_x][tmp_y] == c) {
                visit[tmp_x][tmp_y] = true;
                if (dfs(board, visit, word, idx + 1, tmp_x, tmp_y)) {
                    return true;
                }
                visit[tmp_x][tmp_y] = false;
            }
        }
        return false;
    }
};


int main()
{
    Solution sol;
//    {
//        vector<vector<char>> board = {
//                {'a', 'b', 'c', 'e'},
//                {'s', 'f', 'c', 's'},
//                {'a', 'd', 'e', 'e'}
//        };
//        string word = "asfc";
//        cout << sol.exist(board, word) << endl;
//    }
//
//    {
//        vector<vector<char>> board = {
//                {'a'},
//                {'b'}
//        };
//        string word = "ab";
//        cout << sol.exist(board, word) << endl;
//    }
//
    
    {
        vector<vector<char>> board = {
                {'a', 'a'},
        };
        string word = "aaa";
        cout << sol.exist(board, word) << endl;
    }
    
    return 0;
}
