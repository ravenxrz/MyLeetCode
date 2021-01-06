/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        const int row = matrix.size();
        const int column = matrix[0].size();
        return row_first_search(matrix, target);
        //        if (row <= column) {
        //            return row_first_search(matrix, target);
        //        } else {
        //            return column_first_search(matrix, target);
        //        }
    }

private:
    bool row_first_search(vector<vector<int>>& matrix, int target)
    {
        const int row = matrix.size();
        const int col = matrix[0].size();

        // 第一次二分查找，找到目标行
        int i = 0, j = row - 1;
        int mid = 0;
        int k = 0;
        while (i <= j) {
            mid = (i + j) >> 1;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                j = mid - 1;
            } else { // <
                i = mid + 1;
            }
        }

        // set k
        if (mid < i) {
            k = mid;
        } else if (j >= 0) {    // j < mid && j >= 0
            k = j;
        } else {            // j < 0
            return false;
        }

        // 找到目标行，第二次二分查找
        i = 0, j = col - 1;
        while (i <= j) {
            mid = (i + j) >> 1;
            if (matrix[k][mid] == target) {
                return true;
            } else if (matrix[k][mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return false;
    }

    bool column_first_search(vector<vector<int>>& matrix, int target)
    {
        return false;
    }
};
// @lc code=end
