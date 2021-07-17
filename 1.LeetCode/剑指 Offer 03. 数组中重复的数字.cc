#include "leetcode_base.h"

class Solution {
public:
  int findRepeatNumber(const vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    for (int val : nums) {
      dp[val]++;
    }
    return (find_if(dp.begin(), dp.end(), [](int x) -> bool { return x > 1; }) -
            dp.begin());
  }
};

int main() {
  Solution sol;
  cout << sol.findRepeatNumber({2, 3, 1, 0, 2, 5, 3}) << endl;
  cout << sol.findRepeatNumber({1, 1, 1}) << endl;
  return 0;
}
