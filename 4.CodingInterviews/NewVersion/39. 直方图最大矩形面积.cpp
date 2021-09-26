#include "leetcode_base.h"

class Solution {
    struct Item {
        int idx;
        int extend_idx;
        Item() : idx(-1), extend_idx(-1) {}
        Item(int i, int ei) : idx(i), extend_idx(ei) {}
    };

   public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        vector<Item> stk;
        stk.push_back({0, 0});
        int max_value = heights[0];
        for (int i = 1; i < heights.size(); i++) {
            int extend_idx = i;
            while (!stk.empty() && heights[stk.back().idx] >= heights[i]) {
                max_value =
                    max(max_value, heights[i] * (i - stk.back().idx + 1));
                extend_idx = stk.back().extend_idx;
                stk.pop_back();
            }
            if (!stk.empty()) {
                for (int j = stk.size() - 1; j >= 0; j--) {
                    max_value = max(max_value, heights[stk[j].idx] *
                                                   (i - stk[j].extend_idx + 1));
                }
            }
            max_value = max(max_value, heights[i] * (i - extend_idx + 1));
            stk.push_back({i, extend_idx});
        }
        return max_value;
    }
};

int main() {
    Solution sol;
    /*     {
            vector<int> nums = {2, 1, 5, 6, 2, 3};
            cout << sol.largestRectangleArea(nums) << endl;
        }
        {
            vector<int> nums = {2, 4};
            cout << sol.largestRectangleArea(nums) << endl;
        }
        {
            vector<int> nums = {2, 1, 2};
            cout << sol.largestRectangleArea(nums) << endl;
        }
        {
            vector<int> nums = {3, 6, 5, 7, 4, 8, 1, 0};
            cout << sol.largestRectangleArea(nums) << endl;
        } */
    {
        vector<int> nums = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        cout << sol.largestRectangleArea(nums) << endl;
    }
    return 0;
}