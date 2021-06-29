#include "leetcode_base.h"

class Solution {
  vector<string> ans;

public:
  vector<string> restoreIpAddresses(string s) {
    ans.clear();
    solve(s, 0, "");
    return ans;
  }

private:
  void solve(const string &s, int idx, string tmp_ans) {
    if (!check(s, idx, tmp_ans)) {
      return;
    }
    if (idx == s.size()) {
      // last seg num check
      ans.push_back(tmp_ans);
      return;
    }
    // Append current "char" to "tmp_ans" to form, but not form a new segment
    tmp_ans.append(1, s[idx]);
    solve(s, idx + 1, tmp_ans);
    // Form a new segment
    solve(s, idx + 1, tmp_ans + ".");
  }
  
  bool check(const string &s, int idx, const string &tmp_ans) {
    if (idx > s.size()) {
      return false;
    }
    // The number of dots should be [0,3]
    int dot_cnt = 0;
    for (int i = 0; i < tmp_ans.size(); i++) {
      if (tmp_ans[i] == '.') {
        dot_cnt++;
      }
    }
    if (dot_cnt > 3) {
      return false;
    }
    if (idx == s.size())
      return dot_cnt == 3 && tmp_ans.back() != '.'; // 一定要有4段
    
    // Find a sub ip segment
    int end = tmp_ans.size();
    int start = end;
    while (start > 0 && tmp_ans[start] != '.') {
      start--;
    }
    // start = 0 && tmp_ans[start] ='.'`
    if (tmp_ans[start] == '.') {
      start++;
    }
    if (start == end) { // 当前是.后的第一个数字
      return true;
    }
    
    const string &sub_str = tmp_ans.substr(start, end - start);
    int old_value = atoi(sub_str.c_str());
    // leading zero check
    if (old_value == 0) {
      return false;
    }
    // number range check [0,255]
    int new_value = old_value * 10 + s[idx] - '0';
    if (new_value < 0 || new_value > 255) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  {
    const vector<string> &ans = sol.restoreIpAddresses("25525511135");
    for (const string &ip : ans) {
      cout << ip << endl;
    }
    cout << endl;
  }
  {
    const vector<string> &ans = sol.restoreIpAddresses("0000");
    for (const string &ip : ans) {
      cout << ip << endl;
    }
    cout << endl;
  }
  {
    const vector<string> &ans = sol.restoreIpAddresses("1111");
    for (const string &ip : ans) {
      cout << ip << endl;
    }
    cout << endl;
  }
  {
    const vector<string> &ans = sol.restoreIpAddresses("010010");
    for (const string &ip : ans) {
      cout << ip << endl;
    }
    cout << endl;
  }
  {
    const vector<string> &ans = sol.restoreIpAddresses("101023");
    for (const string &ip : ans) {
      cout << ip << endl;
    }
    cout << endl;
  }
  return 0;
}
