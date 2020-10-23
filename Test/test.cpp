/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> ans;

    void dfs(string &tmp, int effect_counter, int total_counter, int idx, int n){
        if(total_counter == n && effect_counter == 0){
            ans.push_back(tmp);
            return;
        }

        // put (
        if(total_counter < n){
            tmp.append("(");
            dfs(tmp, effect_counter + 1, total_counter+1, idx + 1, n);
            tmp.pop_back();
        }
        // put )
        if(effect_counter > 0){
            tmp.append(")");
            dfs(tmp, effect_counter - 1,total_counter, idx + 1, n);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return ans;
        string tmp;
        dfs(tmp, 0,0, 1, n);
        return ans;
    }
};
// @lc code=end


// @lc code=end

int main()
{
    Solution sol;
    const vector<string> &vector = sol.generateParenthesis(3);
    for(const string &str : vector){
        cout << str << endl;
    }
    return 0;
}