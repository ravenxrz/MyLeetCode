/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

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

