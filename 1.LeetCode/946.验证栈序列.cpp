/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        if (pushed.empty()) return true;
        
        int i = 0, j = 0;
        vector<int> stk;
        stk.push_back(pushed[i++]);
        
        while (j < popped.size()) {
            while (i< pushed.size() && stk.back() != popped[j]) {
                stk.push_back(pushed[i++]);
            }
            if(stk.back() != popped[j] && i == pushed.size()){
                return false;
            }
            j++;
            stk.pop_back();
        }
        return true;
    }
};
// @lc code=end
int main()
{
    vector<int> pushed{1,0};
    vector<int> popped{1,0};
    Solution sol;
    cout << sol.validateStackSequences(pushed,popped);
    return 0;
}

