#include "leetcode_base.h"

class Solution {
   private:
    unordered_map<char, vector<int>> table = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

    vector<string> vec_ans;

   public:
    vector<string> letterCombinations(string digits) {
		if(digits.empty()) return {};
		vec_ans.clear();
        string ans = "";
        dfs(digits, ans, 0);
        return vec_ans;
    }

   private:
    void dfs(const string& str, string& ans, int i) {
        if (i == str.size()) {
            vec_ans.push_back(ans);
            return;
        }
        const vector<int>& pattern = table[str[i]];
        for (char c : pattern) {
            ans.push_back(c);
            dfs(str, ans, i + 1);
            ans.pop_back();
        }
    }
};

int main() {
    Solution sol;
    {
        string digits = "23";
        for (const auto& str : sol.letterCombinations(digits)) {
            cout << str << endl;
        }
    }

    {
        string digits = "";
        for (const auto& str : sol.letterCombinations(digits)) {
            cout << str << endl;
        }
    }

    {
        string digits = "2";
        for (const auto& str : sol.letterCombinations(digits)) {
            cout << str << endl;
        }
    }

    return 0;
}
