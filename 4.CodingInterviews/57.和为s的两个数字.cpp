#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        if (nums.size() < 2) return {};
        int i = 0, j = nums.size() - 1;
        int sum = 0;
        while (1) {
            sum = nums[i] + nums[j];
            if (sum == target) {
                break;
            } else if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            }
        }
        return {nums[i], nums[j]};
    }
};
