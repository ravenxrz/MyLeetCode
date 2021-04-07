#include <bits/stdc++.h>
#include <cstdio>

using namespace std;


class Solution {
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int half_idx = nums.size() / 2;
        vector<int> tmp;
        tmp.reserve(nums.size());
        int i = 0;
        int j = half_idx;
        bool flag = true;
        while (i < half_idx && j < nums.size()) {
            if (flag) {
                tmp.push_back(nums[j++]);
            } else {
                tmp.push_back(nums[i++]);
            }
            flag = !flag;
        }
        if (i < half_idx) tmp.push_back(nums[i]);
        if (j < nums.size()) tmp.push_back(nums[j]);
        tmp.swap(nums);
    }
};

int main()
{
    Solution sol;
    vector<int> nums{3, 5, 2, 1, 6, 4};
    sol.wiggleSort(nums);
    for (auto val : nums) {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}
