#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), 0);
        
        // for nums[1--nums.size()-1]
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1],
                        dp[i - 2] + nums[i]);
        }
        int max_value1 = dp[nums.size() - 1];
        
        // for nums[0--nums.size()-2]
        dp[1] = nums[0];
        for (int i = 2; i < nums.size() ; i++) {
            dp[i] = max(
                    dp[i - 1],
                    dp[i - 2] + nums[i - 1]);
            
        }
        
        return max(max_value1, dp[dp.size() - 1]);
    }
};

int main()
{
    Solution sol;
    {
        cout << "1:";
        vector<int> nums{1, 2, 3, 1};
        cout << sol.rob(nums) << '\n';
    }
    
    {
        cout << "2:";
        vector<int> nums{2, 7, 9, 3, 1};
        cout << sol.rob(nums) << '\n';
    }
    
    {
        cout << "3:";
        vector<int>nums{2,3,2};
        cout << sol.rob(nums) << '\n';
    }
    return 0;
}
