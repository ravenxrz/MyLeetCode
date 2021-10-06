#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                bool left_move = false;
                bool right_move = false;
                if (nums[i] + nums[left] + nums[right] == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left_move = true;
                    right_move = true;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    // left idx Move forward
                    left_move = true;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    right_move = true;
                }
                if (left_move) {
                    while (left + 1 < right && nums[left + 1] == nums[left])
                        left++;
                    left++;
                }
                if (right_move) {
                    while (right - 1 > left && nums[right - 1] == nums[right])
                        right--;
                    right--;
                }
            }

            // Move forward i
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        cout << sol.threeSum(nums).size() << endl;
    }
    {
        vector<int> nums = {0, 0, 0};
        cout << sol.threeSum(nums).size() << endl;
    }

    return 0;
}