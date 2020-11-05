/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:

    void center_expand(const string &s, vector<int> &len, int center, int left, int right){
        // 中心扩展
        while (left >= 0 && right < s.size()) {
            if (s.at(left) != s.at(right)) {
                len[center] = right - center -1 ; // 更新臂长
                break;
            }
            left--;
            right++;
        }
        if(left < 0 || right >= s.size()){
            len[center] = right - center -1;
        }
    }

    string longestPalindrome(string s) {
        if (s.empty())
            return s;

        // step1: 初始化
        // 首位，两两之间插入#
        string new_s(s.size() * 2 + 1, '#');
        for (int i = 0; i < s.size(); i++) {
            new_s[2 * i + 1] = s.at(i);
        }
        s = new_s;

        // step2: manacher算法
        vector<int> len(s.size(), 0);     // 臂长
        int max_pos = 0;    // 当前最长回文串的中心点
        for (int i = 0; i < s.size(); i++) {
            if (i >= max_pos + len[max_pos]) {     // 新点
                center_expand(s,len,i,i,i);
                // 更新最长中心点
                if (len[max_pos] + max_pos < i + len[i]) {
                    max_pos = i;
                }
            } else {      // 可能通过对称来计算
                int i_ = 2 * max_pos - i;
                // 分两种情况
                if (len[i_] + i < max_pos + len[max_pos]) {
                    // 情况1， 对称点所在回文串长度未能导致当前位置溢出臂长 即 len[i_] + i < len[max_pos]
                    len[i] = len[i_];
                } else {      //  len[i_] + i > len[max_pos]
                    // 情况2， 对称点所在回文串长度导致当前位置溢出臂长，即 len[i_] + i >= len[max_pos]
                    int right = max_pos + len[max_pos] + 1;
                    int left = 2 * i - right;
                    center_expand(s,len,i,left,right);
                    // 更新最长中心点
                    if (len[max_pos] + max_pos < i + len[i]) {
                        max_pos = i;
                    }
                }
            }
        }


        // step3: 求len中最长的元素
        string ans;
        auto center_iter = max_element(len.begin(),len.end());
        auto center_len = *center_iter;
        auto center_loc = center_iter - len.begin();
        auto left = center_loc - center_len;
        auto right = center_loc + center_len;
        while(left != right+1){
            if(s.at(left) != '#'){
                ans+=s.at(left);
            }
            left++;
        }

        return ans;
    }
};
// @lc code=end

int main() {
    Solution sol;
    cout << sol.longestPalindrome("abb");
    return 0;
}