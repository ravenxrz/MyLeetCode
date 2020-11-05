/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int max_len = 0;
    int max_i = 0, max_j = 0;

    bool check(const string &s, int start, int end){
        return equal(s.begin()+start,s.begin()+(start+end+1)/2,s.rbegin()+(s.size()-end-1));
    }

    /**
     * 暴力法
     * @param s
     * @return
     */
    string method1(const string &s){
        if(s.empty())
            return s;

        // O(n^2) 暴力判断
        for (int i = 0; i < s.length();i++){
            for (int j = i; j < s.length();j++){
                if(check(s,i,j)){
                    // pass
                    if(j-i+1>max_len){
                        max_i = i;
                        max_j = j;
                        max_len = j - i + 1;
                    }
                }
            }
        }
        return s.substr(max_i,max_j-max_i+1);
    }



    void inline dp_fill( vector<vector<bool>> &dp, int start, int end){
        for(int i = start;i<=end;i++){
            fill(dp[i].begin() + i, dp[i].begin() + end + 1, true);
        }
    }

    /**
     * @brief 动态规划
     * 
     * @param s 
     * @return string 
     */
    string method2(const string &s){
          if(s.empty())
            return s;

        const int s_len = s.length();
        vector<vector<bool>> dp(s_len,vector<bool>(s_len,false));

        // 初始化dp
        // 当出现连续字符时，该段一定为true
        {
            int start = 0,end = 0;
            while(1) {
                while(end + 1 < s_len && s.at(end + 1) == s.at(end)){
                    end++;
                }
                dp_fill(dp, start, end);
                if(max_len < end-start+1){
                    max_len = end-start+1;
                    max_i = start;
                    max_j = end;
                }

                if(end + 1 < s_len){
                    // 更新新段起始索引
                    end++;
                    start = end;
                }else{
                    break;
                }
            }
        }

        // dp核心代码
        for(int pos = 0;pos<s_len;pos++){
            // 状态转移方程  dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
            int i = pos-1;
            int j = pos+1;
            // 找到右端起点
            while(j<s_len && dp[pos][j] == dp[pos][j-1])
                j++;
            while(i >= 0 && j <s_len){
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                if(dp[i][j] && j-i+1 > max_len){
                    max_len = j-i+1;
                    max_i = i;
                    max_j = j;
                }
                i--;j++;
            }
        }

        return s.substr(max_i,max_len);
    }

    // 动态规划
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    cout << sol.longestPalindrome("cbbd");
    return 0;
}