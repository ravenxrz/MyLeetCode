/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:

    // 旋转 [start,end] 之间的数
    void _rotate(vector<vector<int>>& matrix, int start, int end)
    {
        vector<int> line(end-start+1);
        // 保存边1
        for(int i = 0;i<line.size();i++){
            line[i] = matrix[start][start+i];
        }
        //  ， 边2移动到边3. 边1移动到边2. 循环展开
        for(int i = 0;i<line.size()-1;i++){
            // 边4移动到边1
            matrix[start][start+i] = matrix[end-i][start];
            // 边3移动到边4
            matrix[end-i][start] = matrix[end][end-i];
            // 边2移动到边3
            matrix[end][end-i] = matrix[start+i][end];
            // 边1移动到边2
            matrix[start+i][end] = line[i];
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0;i<(matrix.size())/2;i++){
            _rotate(matrix,i,matrix.size()-i-1);
        }
    }
};
// @lc code=end

int main() {
    //
    Solution sol;
    vector<vector<int>> image
            {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(image);
    for(int i = 0;i<image.size();i++){
        for(int j = 0;j<image[i].size();j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}