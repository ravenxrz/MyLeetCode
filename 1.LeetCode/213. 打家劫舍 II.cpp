#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        else if (nums.size() == 1) return nums[0];
        int a = 0;
        int b = nums[0];
        int c = 0;
        // 0-nums.size()-2
        for (int i = 1; i < nums.size() - 1; i++) {
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        int max_value = b;
        
        // 1- nums.size()-1
        a = 0;
        b = nums[1];
        for(int i = 2;i<nums.size();i++){
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        return max(max_value,b);
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{2,3,2};
        cout << sol.rob(nums) << '\n';
    }
    return 0;
}
