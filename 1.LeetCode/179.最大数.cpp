/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include <string>
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int> &nums)
    {
        // 按照数字转为字符串的字典序排列
        vector<string> strs;
        string ans;
        strs.reserve(nums.size());
        for (auto v : nums) {
            strs.push_back(to_string(v));
        }
        // sort
        sort(strs.begin(), strs.end(), compare);
        for (const string &v : strs) {
            ans.append(v);
        }
        // 去除前导0
        while (ans.size() >= 2 && ans.at(0) == '0') {
            ans.erase(0, 1);
        }
        return ans;
    }

private:
    static bool compare(const string &x, const string &y)
    {
        string tx{x + y};
        string ty{y + x};
        return tx > ty;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums{0, 0};
    cout << sol.largestNumber(nums);
    return 0;
}
