#include "leetcode_base.h"

class Solution {
public:
  string replaceSpace(string s) {
    // Scan the s to find the number of space
    int space_num = 0;
    for (char c : s) {
      if (c == ' ')
        space_num++;
    }
    
    int save_size = s.size();
    // Expand the size of s
    s.resize(save_size + space_num * 2);
    int cursor = s.size() - 1;
    // Do replace from back side
    for (int i = save_size - 1; i >= 0; i--) {
      if (s[i] == ' ') {
        s[cursor--] = '0';
        s[cursor--] = '2';
        s[cursor--] = '%';
      } else {
        s[cursor--] = s[i];
      }
    }
    return s;
  }
};

int main() {
  Solution sol;
  cout << sol.replaceSpace("We are happy.") << endl;
  return 0;
}
