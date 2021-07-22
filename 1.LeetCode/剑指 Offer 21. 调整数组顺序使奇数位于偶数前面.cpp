#include "leetcode_base.h"

class Solution {
   public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;

        // Exec
        while (i < j) {
            while (i < j && !(nums[j] & 1)) {
                j--;
            }
            while (i < j && nums[i] & 1) {
                i++;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;

    {
        // All numbers are odd
        vector<int> nums = {1, 3, 5};
        for (auto val : sol.exchange(nums)) {
            cout << val << ' ';
        }
        cout << endl;
    }

    {
        // All numbers are even
        vector<int> nums = {2, 4, 6};
        for (auto val : sol.exchange(nums)) {
            cout << val << ' ';
        }
        cout << endl;
    }

    {
        // All numbers are even
        vector<int> nums = {12, 3, 4, 5};
        for (auto val : sol.exchange(nums)) {
            cout << val << ' ';
        }
        cout << endl;
    }

    return 0;
}