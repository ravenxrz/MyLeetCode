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
    void dfs(string &tmp, int effect_counter, int total_counter, int n)
    {
        if (total_counter == n && effect_counter == 0) {
            ans.push_back(tmp);
            return;
        }
        
        // put (
        if (total_counter < n) {
            tmp.append("(");
            dfs(tmp, effect_counter + 1, total_counter + 1, n);
            tmp.pop_back();
        }
        // put )
        if (effect_counter > 0) {
            tmp.append(")");
            dfs(tmp, effect_counter - 1, total_counter, n);
            tmp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return ans;
        string tmp;
        dfs(tmp, 0, 0, n);
        return ans;
    }
};
// @lc code=end

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        string str;
        dfs(str, n, n);
        return ans;
    }
    
    void dfs(string &str, int left, int right)
    {
        if (left > right) return;
        
        if (left < 0 || right < 0) return;
        
        if (left == 0 && right == 0) {
            ans.push_back(str);
            return;
        }
        
        // take left
        str.push_back('(');
        dfs(str, left - 1, right);
        str.pop_back();
        
        // take right
        str.push_back(')');
        dfs(str, left, right - 1);
        str.pop_back();
    }

private:
    vector<string> ans;
};



class Solution {
    vector<string> ans;

   public:
    vector<string> generateParenthesis(int n) {
        stack<char> stk;
        string tmp;
        dfs(stk, tmp, 2 * n, 0);
        return ans;
    }

   private:
    void dfs(stack<char>& stk, string& tmp, int n, int idx) {
        if (idx == n) {
            if (stk.empty()) {
                ans.push_back(tmp);
            }
            return;
        }

        // put (
        if (n - idx >= stk.size()) {
            stk.push('(');
            tmp.push_back('(');
            dfs(stk, tmp, n, idx + 1);
            stk.pop();
            tmp.pop_back();
        }
        // put )
        if (!stk.empty()) {
            stk.pop();
            tmp.push_back(')');
            dfs(stk, tmp, n, idx + 1);
            stk.push('(');
            tmp.pop_back();
        }
    }
};

int main() {
    Solution sol;
    for(const auto& str : sol.generateParenthesis(3)){
        cout << str << ' ';
    }
    cout << endl;
    return 0;
}