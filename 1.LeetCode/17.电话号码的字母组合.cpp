/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> ans;

    vector<string> strmapping = {
        "", // 占位符
        "", // 占位符
        "abc", //2
        "def", //3
        "ghi", //4
        "jkl", //5
        "mno", //6
        "pqrs", //7
        "tuv", //8
        "wxyz" //9
    };

    void dfs(string digits, string one, int didx, int oidx)
    {
        if (oidx == one.size()) {
            ans.push_back(one);
            return;
        }
        if(didx == digits.size()){  // 越界
            return;
        }

        int map_idx = digits[didx] - '0';
        for (int i = 0; i < strmapping[map_idx].size(); i++) {
            // put
            one[oidx] = strmapping[map_idx].at(i);
            dfs(digits, one, didx + 1, oidx + 1);
            // remove
            dfs(digits, one, didx + 1, oidx);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return ans;

        dfs(digits, digits, 0, 0);
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.letterCombinations("23");
    return 0;
}