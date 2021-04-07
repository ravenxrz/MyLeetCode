
/**
 * n sum 问题
 */

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> nSum(vector<int> &nums, int n, int target)
    {
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        return nSumCore(nums, n, 0, target);
    }

private:
    vector<vector<int>> nSumCore(vector<int> &nums, int n, int start, int target)
    {
        vector<vector<int>> ans;
        if (n == 1) {
            // binary search
            if (binary_search(nums.begin(), nums.end(), target)) {
                ans.push_back({target});
            }
            return ans;
        } else if (n == 2) {
            // double pointer
            int l = start;
            int r = nums.size() - 1;
            while (l < r) {
                int left = nums[l];
                int right = nums[r];
                if (left + right == target) {
                    ans.push_back({left, right});
                    while (l < r && nums[l] == left) ++l;
                    while (l < r && nums[r] == right) --r;
                } else if (left + right < target) {
                    while (l < r && nums[l] == left) ++l;
                } else if (left + right > target) {
                    while (l < r && nums[r] == right) --r;
                }
            }
            return ans;
        } else {
            // n >= 3
            for (int i = start; i < nums.size(); ++i) {
                auto tmp_ans = nSumCore(nums, n - 1, i + 1, target - nums[i]);
                if (!tmp_ans.empty()) {
                    for (auto &vec : tmp_ans) {
                        vec.push_back(nums[i]);
                        ans.push_back(vec);
                    }
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
            }
            return ans;
        }
    }
    
};// @lc code=end


int main()
{
    vector<int> input{1, 0, -1, 0, -2, 2};
    Solution sol;
    int n = 4;
    int target = 0;
    auto ans = sol.nSum(input, n, target);
    for (auto &vec : ans) {
        for (int val :vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}
