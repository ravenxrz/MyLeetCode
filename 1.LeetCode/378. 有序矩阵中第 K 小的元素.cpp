//
// Created by Raven on 2021/9/8.
//
class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    const int n = matrix[0].size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    
    while (left < right) {
      int mid = left + ((right - left) >> 1);
      if (cntNumbers(matrix, mid, k) >= k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

private:
  int cntNumbers(vector<vector<int>> &matrix, int mid, int k) {
    int num = 0;
    int i = matrix.size() - 1;
    int j = 0;
    while (i >= 0 && j < matrix[0].size()) {
      if (matrix[i][j] <= mid) {
        num += (i + 1);
        j++;
      } else {
        i--;
      }
    }
    return num;
  }
};
