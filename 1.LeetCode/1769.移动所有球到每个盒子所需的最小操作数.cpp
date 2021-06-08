#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
public:
  vector<int> minOperations(string boxes) {
    vector<int> ans(boxes.size());
    for (int i = 0; i < ans.size(); i++) {
      int sum = 0;
      for (int j = 0; j < boxes.size(); j++) {
        if (i == j || boxes[j] == '0')
          continue;
        sum += std::abs(i - j);
      }
      ans[i] = sum;
    }
    return ans;
  }
};
// @lc code=end
