#include "leetcode_base.h"

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int window[26];
        memset(window, 0, sizeof(window));
        for (int i = 0; i < s.size(); i++) {
            window[s[i] - 'a']++;
            window[t[i] - 'a']--;
        }
        return all_of(window, window + 26, [](int val) { return val == 0; }) && s!= t;
    }
};

int main() {
    Solution sol;
    string s = "a", t = "a";
	cout << sol.isAnagram(s, t) << endl;
    return 0;
}