#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left, right};
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {1, 2, 4, 6, 10};
        for (auto val : sol.twoSum(nums, 8)) {
            cout << val << ' ';
        }
    }
    return 0;
}