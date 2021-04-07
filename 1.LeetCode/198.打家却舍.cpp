#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        int b = 0;
        int c = nums[0];
        int next = 0;
        for (int i = 1; i < nums.size(); i++) {
            next = max(c, b + nums[i]);
            b = c;
            c = next;
        }
        return c;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{2,7,9,3,1};
        cout << sol.rob(nums) << '\n';
    }
    return 0;
}
