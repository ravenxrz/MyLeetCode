#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=1476 lang=cpp
 *
 * [1476] 子矩形查询
 */

// @lc code=start
class SubrectangleQueries {
public:
  SubrectangleQueries(vector<vector<int>> &rectangle) : rect_(rectangle) {}

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    assert(row1 <= row2 && col1 <= col2);
    for (int i = row1; i <= row2; i++) {
      for (int j = col1; j <= col2; j++) {
        rect_[i][j] = newValue;
      }
    }
  }

  int getValue(int row, int col) { return rect_[row][col]; }

private:
  vector<vector<int>> rect_;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end
