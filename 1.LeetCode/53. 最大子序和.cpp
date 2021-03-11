#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_value = nums[0];
        int pre = nums[0];
        int cur = 0;
        for(int i = 1;i<nums.size();i++){
            if(pre < 0){
                cur = nums[i];
            }else{
                cur = nums[i]+ pre;
            }
            max_value = max(max_value,cur);
            pre = cur;
        }
        return max_value;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums);
    return 0;
}
