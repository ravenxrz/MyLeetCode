//
// Created by Raven on 2021/3/13.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        // init
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        
        int left = 0, right = 0;
        int valid = 0;
        int start = 0;
        int len = 0xffffff;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            
            // shrink
            while (valid == need.size()) {
                if (len > (right - left)) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if (window[d] == need[d]) {
                        valid--;
                    }
                }
                window[d]--;
            }
        }
        
        return len == 0xffffff ? "" : s.substr(start, len);
    }
};

int main()
{
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
