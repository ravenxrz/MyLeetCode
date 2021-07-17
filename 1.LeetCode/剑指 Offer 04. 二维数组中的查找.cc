#include "leetcode_base.h"

class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    // Find the target value in matrix by a way scanning from top-right to
    // bottom-left
    if (matrix.empty())
      return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n - 1;
    while (i < m && j >= 0) {
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] > target)
        j--;
      else if (matrix[i][j] < target)
        i++;
    }
    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  Solution sol;
  cout << sol.findNumberIn2DArray(matrix, 5) << endl;
  cout << sol.findNumberIn2DArray(matrix, 20) << endl;
  return 0;
}
