//
// Created by Raven on 2021/3/13.
//
/**
 * 给你一个数组，返回一个等长的数组，对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1。不好用语言解释清楚，直接上一个例子：
    给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。
    解释：第一个 2 后面比 2 大的数是 4; 1 后面比 1 大的数是 2；第二个 2 后面比 2 大的数是 4; 4 后面没有比 4 大的数，填 -1；3 后面没有比 3 大的数，填 -1。
 */
#include <bits/stdc++.h>

using namespace std;


vector<int> next_greater_num(const vector<int> &nums)
{
    if (nums.empty()) return {};
    vector<int> ans(nums.size(), 0);
    stack<int> stk;
    const int n = nums.size();
    // 假装扩充条件
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= nums[i % n]) {
            stk.pop();
        }
        ans[i % n] = stk.empty() ? -1 : stk.top();
        stk.push(nums[i % n]);
    }
    return ans;
}


int main()
{
    vector<int> nums{2, 1, 2, 4, 3};
    auto output = next_greater_num(nums);
    for (auto val : output) {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}
