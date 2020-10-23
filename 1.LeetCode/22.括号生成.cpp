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

    /**
     * @brief 
     * 
     * @param tmp 临时保存每一个计算中间结果
     * @param effect_counter 当前有效的"(" 个数，  当"(" 遇上")"时， effect_counter--
     * @param total_counter   当前总共的 "(" 个数
     * @param idx 当前位置
     * @param n 总共需要生成的括号对数
     */
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

