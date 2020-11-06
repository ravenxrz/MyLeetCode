/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if(m == 0) return;
        const int n = matrix[0].size();

        // 找到用来记录的行列，并且记录
        int rx = -1,ry = -1;
        bool first = true;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!first){
                    if(matrix[i][j] == 0){
                        matrix[rx][j] = 0;
                        matrix[i][ry] = 0;
                    }
                }else{
                    if(matrix[i][j] == 0){  // 找到记录坐标
                        first = false;
                        rx = i;
                        ry = j;
                    }
                }
            }
        }

        if(first){  // 没有0
            return;
        }

        // 置0
        for(int i = 0;i<m;i++){
            if(matrix[i][ry] == 0 && i != rx){
                // 本行置0
                fill(matrix[i].begin(),matrix[i].end(),0);
            }
        }
        for(int j = 0;j<n;j++){
            if(matrix[rx][j] == 0){
                // 本列置0
                for(int i = 0;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
        // rx 行 ry列置0
        fill(matrix[rx].begin(),matrix[rx].end(),0);
        for(int i = 0;i<m;i++){
            matrix[i][ry] = 0;
        }
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> matrix = {
            {0,1,2,0},
            {3,4,5,2},
            {1,3,1,5}
    };
    Solution sol;
    sol.setZeroes(matrix);
    for(auto &row : matrix){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}