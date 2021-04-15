#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int delta = INT_MAX;
        int ans;
        for (int k = 0; k < nums.size();) {
            int i = 0;
            int j = nums.size() - 1;
            while (i < j) {
                if (i == k) {
                    i++;
                    continue;
                }
                if (j == k) {
                    j--;
                    continue;
                }
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == target) {
                    return target;
                }
                if (delta > std::abs(tmp - target)) {
                    delta = std::abs(tmp - target);
                    ans = tmp;
                }
                if (tmp < target) {
                    i++;
                    while (i < j && nums[i] == nums[i - 1]) i++;
                } else if (tmp > target) {
                    j--;
                    while (i < j && nums[j + 1] == nums[j]) j--;
                }
            }
            k++;
            while (k < nums.size() && nums[k] == nums[k - 1]) k++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{-1,0,1,1,55};
    cout << sol.threeSumClosest(nums,3) << endl;
    return 0;
}
