#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    // Calculate the prefix sum of nums
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] >= target)
        return 1;
      nums[i] += nums[i - 1];
    }
    int min_len = nums.size() + 1;
    int left = 0, right = 0;
    int base_sum = 0;
    while (left <= right && right < nums.size()) {
      int left_value = left - 1 < 0 ? 0 : nums[left - 1];
      base_sum = (nums[right] - left_value);
      if (base_sum >= target) {
        min_len = std::min(min_len, right - left + 1);
        left++;
      } else {
        right++;
      }
    }

    return min_len == nums.size() + 1 ? 0 : min_len;
  }
};
// @lc code=end

int main() {
  Solution sol;
  {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, nums) << endl;
  }
  {
    vector<int> nums = {1, 4, 4};
    cout << sol.minSubArrayLen(4, nums) << endl;
  }
  {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << sol.minSubArrayLen(11, nums) << endl;
  }
  return 0;
}
