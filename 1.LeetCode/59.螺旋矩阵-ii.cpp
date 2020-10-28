/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {};

        vector<vector<int>> ans(n,vector<int>(n,0));
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
        int value = 1;

        // 开始螺旋
        const int result = n * n + 1;
        while (value != result) {
            switch (direction) {
            case 0: // 右走
                if(j <= end){
                    ans[i][j] = value++;
                    j++;
                }else{
                    // 改方向
                    direction = 1;
                    // j多加了一个，还原
                    j = end;
                    i++;
                    // 改终点
                    end = n - 1 - level;
                }
                break;
            case 1:
                if(i <= end){
                    ans[i][j] = value++;
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
                   ans[i][j] = value++;
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
                    ans[i][j] = value++;
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

