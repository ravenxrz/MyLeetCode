
#include "leetcode_base.h"

class Solution {
public:
    char firstUniqChar(string s) {
      unordered_map<char, int> umap;
      for(char c : s){
        umap[c]++;
      }
      for(char c : s){
        if(umap[c] == 1) return c;
      }
      return ' ';
    }
};

int main()
{
  Solution sol;
  cout << sol.firstUniqChar("loveleetcode") << endl;
  return 0;
}
