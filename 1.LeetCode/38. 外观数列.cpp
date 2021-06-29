#include "leetcode_base.h"

class Solution {
  string memo[32];

  struct MapItem {
    char c;
    size_t times;
  };

public:
  string countAndSay(int n) {
    for (int i = 0; i < 32; i++) {
      memo[i].clear();
    }
    return solve(n);
  }

private:
  string solve(int n) {
    if (n == 1) {
      return "1";
    }
    // Try to get answer from memo
    if (!memo[n].empty()) {
      return memo[n];
    }
    // Generate current answer from previous number string
    vector<MapItem> cur_vec;
    const string &pre_str = solve(n - 1);
    split(pre_str, &cur_vec);
    return concat(cur_vec);
  }

  void split(const string &str, vector<MapItem> *ans) {
    assert(!str.empty());
    char current_char = str[0];
    int cnt = 1;
    int idx = 1;

    while (idx < str.size()) {
      if (str[idx] == current_char) {
        cnt++;
      } else {
        // Generate new item
        MapItem item;
        item.c = current_char;
        item.times = cnt;
        ans->push_back(item);
        // Move to next character
        current_char = str[idx];
        cnt = 1;
      }
      idx++;
    }
    // Process the last group of characters
    MapItem item;
    item.c = current_char;
    item.times = cnt;
    ans->push_back(item);
  }

  string concat(const vector<MapItem> &items) {
    string ans;
    char buf[1024];
    for (const MapItem &item : items) {
      snprintf(buf, sizeof(buf), "%lu%c", item.times, item.c);
      ans.append(buf);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  for (int i = 1; i <= 30; i++) {
    cout << "num: " << i << " : " << sol.countAndSay(i) << endl;
  }
  return 0;
}
