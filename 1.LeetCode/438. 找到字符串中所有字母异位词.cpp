//
// Created by Raven on 2021/3/13.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;
        
        int left = 0, right = 0;
        int valid = 0;
        vector<int> ans;
        
        while (right < s.size()) {
            char c = s[right];
            right++;
            
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) {
                    valid++;
                }
            }
            
            // shrink
            if (right - left == p.size()) {
                if (valid == need.size()) {
                    ans.push_back(left);
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    for (auto val :sol.findAnagrams("abab", "ab")) {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}
