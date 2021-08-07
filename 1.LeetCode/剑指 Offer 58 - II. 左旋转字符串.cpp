#include "leetcode_base.h"

class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        assert(n < s.size() && n >= 0);
        return s.substr(n) + s.substr(0, n);
    }
};

int main() {
    Solution sol;
    cout << sol.reverseLeftWords("lrloseumgh", 6) << endl;
    return 0;
}