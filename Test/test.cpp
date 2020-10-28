/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        if (m == 0) {
            return {};
        }
        int n = matrix[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        /**
         * 0 右走
         * 1 下走
         * 2 左走
         * 3 上走
         */
        int direction = 0;
        int level = 0; // 从外往里数，当前在第几层
        int end = n -1 - level; // end表明每个方向的终点
        int i = 0, j = 0;

        // 开始螺旋
        while (ans.size() != m * n) {
            switch (direction) {
                case 0: // 右走
                    if(j <= end){
                        ans.push_back(matrix[i][j]);
                        j++;
                    }else{
                        // 改方向
                        direction = 1;
                        // j多加了一个，还原
                        j = end;
                        i++;
                        // 改终点
                        end = m - 1 - level;
                    }
                    break;
                case 1:
                    if(i <= end){
                        ans.push_back(matrix[i][j]);
                        i++;
                    }else{
                        direction = 2;
                        i = end;
                        j--;
                        end = level;
                    }
                    break;
                case 2:
                    if(j>=end){
                        ans.push_back(matrix[i][j]);
                        j--;
                    }else{
                        direction = 3;
                        j = end;
                        i--;
                        end = level + 1;
                    }
                    break;
                case 3:
                    if(i>=end){
                        ans.push_back(matrix[i][j]);
                        i--;
                    }else{
                        direction = 0;
                        i = end;
                        j++;
                        // 一圈走完，level+1
                        level++;
                        end = n - 1 - level;
                    }
                    break;
            }
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> input = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    auto vec = sol.spiralOrder(input);
    for_each(vec.begin(),vec.end(),[](int val){
       cout << val <<" ";
    });
    return 0;
}