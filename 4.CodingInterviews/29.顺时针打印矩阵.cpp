//
// Created by Raven on 2021/2/3.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    class Point {
    public:
        int x;
        int y;
        
        Point(int x, int y) : x(x), y(y) {}
        
        bool operator==(const Point &rhs)
        {
            return this->x == rhs.x && this->y == rhs.y;
        }
        
        bool operator!=(const Point &rhs)
        {
            return !operator==(rhs);
        }
    };

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // empty check
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};
        
        // ans vector
        vector<int> ans;
        ans.reserve(m * n);
        
        printRectangle(ans, matrix, {0, 0}, {m - 1, n - 1});
        return ans;
    }

private:
    void printRectangle(vector<int> &ans, const vector<vector<int>> &matrix, const Point &leftTop, const Point &rightBt)
    {
        // 边界检查
        if (leftTop.x > rightBt.x || leftTop.y > rightBt.y) return;
        
        // 计算4个边界点
        const Point rightTop(leftTop.x, rightBt.y);
        const Point leftBt(rightBt.x, leftTop.y);
        
        Point cur = leftTop;
        // single row
        if (leftTop.x == rightBt.x) {
            // go to right
            while (cur != rightBt) {
                ans.push_back(matrix[cur.x][cur.y]);
                cur.x++;
            }
            return;
        }
        // single column
        if (leftTop.y == rightBt.y) {
            // go to bottom
            while (cur != rightBt) {
                ans.push_back(matrix[cur.x][cur.y]);
                cur.y++;
            }
            return;
        }
        // normal rectangle
        // right
        while (cur != rightTop) {
            ans.push_back(matrix[cur.x][cur.y]);
            cur.x++;
        }
        ans.push_back(matrix[cur.x][cur.y]);
        cur.y++;
        
        // down
        while (cur != rightBt) {
            ans.push_back(matrix[cur.x][cur.y]);
            cur.y++;
        }
        ans.push_back(matrix[cur.x][cur.y]);
        cur.y--;
        
        // left
        while (cur != leftBt) {
            ans.push_back(matrix[cur.x][cur.y]);
            cur.y--;
        }
        ans.push_back(matrix[cur.x][cur.y]);
        cur.x--;
        
        while (cur != leftTop) {
            ans.push_back(matrix[cur.x][cur.y]);
            cur.x--;
        }
        
        // 递归add
        printRectangle(ans, matrix,
                       {leftTop.x + 1, leftTop.y + 1},
                       {rightBt.x - 1, rightBt.y - 1});
    }
};

void printResult(const vector<int> &result)
{
    for (auto val : result) {
        cout << val << ' ';
    }
    cout << endl;
}

int main()
{
    Solution sol;
    {
        // empty check
        vector<vector<int>> matrix;
        printResult(sol.spiralOrder(matrix));
    }
    
    {
        // single point
        vector<vector<int>> matrix(1, vector<int>(1, 0));
        printResult(sol.spiralOrder(matrix));
    }
    
    {
        // single row
        vector<vector<int>> matrix =
                {
                        {1, 2, 3, 4, 5}
                };
        printResult(sol.spiralOrder(matrix));
    }
    
    {
        // single column
        vector<vector<int>> matrix =
                {
                        {1},
                        {2},
                        {3},
                        {4},
                        {5}
                };
        printResult(sol.spiralOrder(matrix));
    }
    
    {
        // normal matrix check
        vector<vector<int>> matrix = {
                {1, 2, 3, 4},
                {5, 6, 7, 8}
        };
        printResult(sol.spiralOrder(matrix));
    }
    return 0;
}