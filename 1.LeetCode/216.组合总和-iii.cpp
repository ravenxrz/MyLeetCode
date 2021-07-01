#include "leetcode_base.h"

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
  vector<vector<int>> ans;

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    ans.clear();
    vector<int> tmp_ans;
    dfs(tmp_ans, 1, k, n);
    return ans;
  }

private:
  void dfs(vector<int> &tmp_ans, int next_start, int k, int n) {
    if (tmp_ans.size() == k) {
      int sum = accumulate(tmp_ans.begin(), tmp_ans.end(), 0);
      if (sum == n) {
        ans.push_back(tmp_ans);
      }
      return;
    }

    if (accumulate(tmp_ans.begin(), tmp_ans.end(), 0) > n) {
      return;
    }

    for (int i = next_start; i <= 9; i++) {
      tmp_ans.push_back(i);
      dfs(tmp_ans, i + 1, k, n);
      tmp_ans.pop_back();
    }
  }
};
// @lc code=end

int main() {
  Solution sol;
  {
    const vector<vector<int>> &ans = sol.combinationSum3(3, 7);
    for (const vector<int> &one_ans : ans) {
      // print
      for (int val : one_ans) {
        cout << val << ' ';
      }
      cout << endl;
    }
  }
  {
    const vector<vector<int>> &ans = sol.combinationSum3(3, 9);
    for (const vector<int> &one_ans : ans) {
      // print
      for (int val : one_ans) {
        cout << val << ' ';
      }
      cout << endl;
    }
  }
  {
    const vector<vector<int>> &ans = sol.combinationSum3(4, 1);
    for (const vector<int> &one_ans : ans) {
      // print
      for (int val : one_ans) {
        cout << val << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}
