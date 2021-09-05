/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int left = 0;
        int right = 0;
        unordered_set<int> window;
        size_t len = 0;
        while (right < s.size()) {
            char in = s[right++];

            while (window.count(in)) {  // 已存在， shrink the window
                int out = s[left++];
                window.erase(out);
            }
            window.insert(in);
            len = max(len, window.size());
        }
        return len;
    }
};