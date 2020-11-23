/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // enum hack
    enum {
        dead = 0,
        alive = 1,
        alive_to_dead = 2,
        dead_to_alive = 3
    };
    
    bool isAlive(vector<vector<int>> &board, int row, int col)
    {
        int sum = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            if (i < 0 || i >= board.size()) /* 越界 */ continue;
            for (int j = col - 1; j <= col + 1; j++) {
                if (j < 0 || j >= board[0].size()) /* 越界 */ continue;
                if (i == row && j == col) /* 排除自己 */ continue;
                switch (board[i][j]) {
                    case dead:
                    case dead_to_alive:
                        break;
                    case alive:
                    case alive_to_dead:
                        sum += 1;
                        break;
                    default:
                        break;
                }
            }
        }
        if (board[row][col]) {    // alive
            if (sum < 2 || sum > 3) {
                return false;
            } else {
                return true;
            }
        } else {      // dead
            if (sum == 3) {
                return true;
            }
        }
        return false;
    }
    
    void gameOfLife(vector<vector<int>> &board)
    {
        const int m = board.size();
        if (m == 0) return;
        const int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isAlive(board, i, j)) { //to alive
                    if (!board[i][j]) board[i][j] = dead_to_alive;
                } else { // to dead
                    if (board[i][j]) board[i][j] = alive_to_dead;
                }
            }
        }
        // 替换回来
        for_each(board.begin(), board.end(), [&](vector<int> &line) {
            for (auto &v :line) {
                if (v == dead_to_alive) v = alive;
                else if (v == alive_to_dead) v = dead;
            }
        });
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> board = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
    };
    sol.gameOfLife(board);
    return 0;
}
