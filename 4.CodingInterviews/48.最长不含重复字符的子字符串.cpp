//
// Created by Raven on 2021/2/10.
//
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty()) return 0;
        int i = 0, j = 0;
        unordered_set<char> uset;
        uset.insert(s[j++]);
        int max_window_len = 1;
        while (j < s.size()) {
            if (uset.find(s[j]) != uset.end()) {  // 包含
                // move i
                while (s[i] != s[j]){
                    uset.erase(s[i]);
                    i++;
                }
                i++;
            } else {
                max_window_len = max(max_window_len, j - i + 1);
                uset.insert(s[j]);
            }
            j++;
        }
        return max_window_len;
    }
};

int main()
{
    Solution sol;
    {
        // 空
        cout << sol.lengthOfLongestSubstring("") << '\n';
        // example
        cout << sol.lengthOfLongestSubstring("abcd") << '\n';
        cout << sol.lengthOfLongestSubstring("abcabcbb") << '\n';
        cout << sol.lengthOfLongestSubstring("bbbb") << '\n';
        cout << sol.lengthOfLongestSubstring("pwwkew") << '\n';
        cout << sol.lengthOfLongestSubstring("tmmzuxt") << '\n';
    }
    return 0;
}
