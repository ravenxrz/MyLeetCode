#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;

        int left = 0;
        int right = 0;
        int valid = 0;
        int start = -1;
        int len = INT32_MAX;
        while (right < s.size()) {
            int in = s[right++];
            // Expand window
            if (need.count(in)) {
                window[in]++;
                if (window[in] == need[in]) {
                    valid++;
                }
            }
            // Shrink window
            while (valid == need.size()) {
                if (len > right - left) {
                    len = right - left;
                    start = left;
                }
                int out = s[left++];
                if (need.count(out)) {
                    if (window[out] == need[out]) {
                        valid--;
                    }
                    window[out]--;
                }
            }
        }
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
	cout << sol.minWindow(s, t) << endl;
    return 0;
}
