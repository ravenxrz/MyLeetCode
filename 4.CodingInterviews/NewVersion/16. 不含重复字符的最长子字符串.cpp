#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l = 0;
        int r = 0;
        size_t max_len = 0;
        while (r < s.size()) {
            if (window.count(s[r])) {
                while (window.count(s[r])) {
                    window.erase(s[l++]);
                }
            }
            window.insert(s[r]);
            max_len = max(max_len, window.size());
            r++;
        }
        return max_len;
    }
};

int main() {
    return 0;
}