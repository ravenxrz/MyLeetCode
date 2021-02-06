//
// Created by Raven on 2021/2/5.
//
#include <vector>
#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        if (pushed.size() != popped.size()) return false;
        if (pushed.empty()) return true;
        
        stack<int> stk;
        
        int i = 0, j = 0;
        for (; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while (j < popped.size() && !stk.empty() && stk.top() == popped[j]) {
                j++;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main()
{
    Solution sol;
    {
        vector<int> pushed{1,0};
        vector<int> popped{1,0};
        cout << sol.validateStackSequences(pushed,popped) << '\n';
    }
    
    return 0;
}
