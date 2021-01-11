/*
 * 题目： 二维数组中的查找
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * inputs:
 * [
      [1,   4,  7, 11, 15],
      [2,   5,  8, 12, 19],
      [3,   6,  9, 16, 22],
      [10, 13, 14, 17, 24],
      [18, 21, 23, 26, 30]
    ]
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    struct Pos {
        int x;
        int y;
        
        Pos(int x, int y) : x(x), y(y) {}
    };

public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        // check empty?
        if (matrix.empty()) return false;
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        Pos cur = {0, n - 1};
        
        // core algorithm
        while (cur.x < m && cur.y >= 0) {
            if (matrix[cur.x][cur.y] == target) {
                return true;
            } else if (matrix[cur.x][cur.y] < target) {    // remove cur row
                cur.x++;
            } else if (matrix[cur.x][cur.y] > target) {     // remove cur column
                cur.y--;
            }
        }
        return false;
    }
};


int main()
{
    return 0;
}
