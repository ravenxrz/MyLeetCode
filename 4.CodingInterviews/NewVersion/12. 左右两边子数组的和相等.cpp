#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        // left-most point
        if (sum.back() - sum[1] == 0)
            return 0;

        for (int i = 1; i < sum.size() - 1; i++) {
            int left = sum[i - 1];
            int right = sum[sum.size() - 1] - sum[i];
            if (left == right)
                return i - 1;
        }

        // right-most point
        if (sum[sum.size() - 2] == 0)
            return nums.size() - 1;

        return -1;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {1, 7, 3, 6, 5, 6};
        cout << sol.pivotIndex(nums) << endl;
    }
    {
        vector<int> nums = {1, 2, 3};
        cout << sol.pivotIndex(nums) << endl;
    }
    {
        vector<int> nums = {2, 1, -1};
        cout << sol.pivotIndex(nums) << endl;
    }

    return 0;
}