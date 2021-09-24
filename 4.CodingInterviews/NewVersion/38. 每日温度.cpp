#include "leetcode_base.h"

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty())
            return {};
        // init
        stack<int> stk;  // Store the idx of the temperatures arrary
        vector<int> ans;
        stk.push(temperatures.size() - 1);
        ans.push_back(0);

        for (int i = temperatures.size() - 2; i >= 0; i--) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(stk.top() - i);
            }
            stk.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    for (auto val : sol.dailyTemperatures(temperatures)) {
        cout << val << ' ';
    }
    return 0;
}