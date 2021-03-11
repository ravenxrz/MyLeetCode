#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        int max_value = nums[0];
        
        int dp_max = nums[0];
        int dp_min = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int tmp_max = dp_max;
            int tmp_min = dp_min;
            
            tmp_max = max({dp_max * nums[i], nums[i], dp_min * nums[i]});
            tmp_min = min({dp_min * nums[i], nums[i], dp_max * nums[i]});
            
            dp_max = tmp_max;
            dp_min = tmp_min;
            
            max_value = max(max_value, dp_max);
        }
        
        return max_value;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{2, 3, -2, 4};
        cout << sol.maxProduct(nums) << '\n';
    }
    return 0;
}
