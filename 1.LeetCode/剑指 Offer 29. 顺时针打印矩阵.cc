//
// Created by Raven on 2021/7/24.
//
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty())
      return {};
    if (matrix[0].empty())
      return {};
    
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    vector<int> ans;
    ans.reserve(m * n);
    int i = 0;
    int j = 0;
    int direction = 0; // 0 for right, 1 for down, 2 for left, 3 for up
    
    while (true) {
      // 方向转换
      if (j == n || i == m || j < 0 || i < 0 || visit[i][j]) {
        // Change direction
        direction = (direction + 1) % 4;
        switch (direction) {
        case 0: // up --> right
          i++; j++;
          break;
        
        case 1: // right --> down
          j--; i++;
          break;
        
        case 2: // down --> left
          i--; j--;
          break;
        
        case 3: // left --> up
          i--; j++;
          break;
        }
        
        if (j == n || i == m || j < 0 || i < 0 || visit[i][j]) {
          break;
        }
      }
      
      // 前进
      visit[i][j] = true;
      ans.push_back(matrix[i][j]);
      // forward one step
      switch (direction) {
      case 0:
        j++; break;
      
      case 1:
        i++; break;
      
      case 2:
        j--; break;
      
      case 3:
        i--; break;
      }
    }
    return ans;
  }
};
