//
// Created by Raven on 2021/4/6.
//


#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
        int dp[101];
        dp[s.size()] = 1;
        dp[s.size() + 1] = 0;     // 保留，防止越界计算
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') dp[i] = 0;
            if (s[i] >= '3') dp[i] = dp[i + 1];
            else if (s[i] == '2') {
                dp[i] = dp[i + 1];
                if (i + 1 < s.size() && s[i + 1] <= '6') dp[i] += dp[i + 2];
            } else if (s[i] == '1') {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution sol;
    cout << sol.numDecodings("06") << '\n';
    cout << sol.numDecodings("226") << '\n';
//    cout << sol.numDecodings("111111111111111111111111111111111111111111111") << '\n';
    return 0;
}


class Solution {
public:
    int numDecodings(string s)
    {
        return count(s, 0);
    }
    
    int count(const string &str, int idx)
    {
        if (idx == str.size()) return 1;
        else if (idx > str.size()) return 0;
        
        // exclude "0"
        if (str[idx] == '0') return 0;
        
        // current char is greater than 3
        if (str[idx] >= '3') {
            return count(str, idx + 1);
        }
        
        // 1
        if (str[idx] == '1') {
            return count(str, idx + 1) + count(str, idx + 2);
        }
        
        // 2
        if (str[idx] == '2') {
            int cnt = count(str, idx + 1);
            if (idx + 1 < str.size() && str[idx + 1] <= '6') cnt += count(str, idx + 2);
            return cnt;
        }
        
        return 0;
    }
};

