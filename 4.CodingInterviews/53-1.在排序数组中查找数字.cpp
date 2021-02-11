#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty()) return 0;
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        if (iter == nums.end() || *iter != target) return 0;
        int offset = iter - nums.begin();
        int ans = 1;
        int i = offset - 1, j = offset + 1;
        while (i >= 0 && nums[i++] == target) {
            ans++;
        }
        while (j < nums.size() && nums[j++] == target) {
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{2, 2};
        cout << sol.search(nums, 3) << '\n';
    }
    return 0;
}
