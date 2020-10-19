/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
反转
// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {        
        vector<vector<int>> ans;

        if(nums.size() == 0)
            return ans;

        // 排序
        sort(nums.begin(), nums.end());

        for (int idx1 = 0; idx1 < nums.size() - 3; idx1++)
        {
            for (int idx2 = idx1 + 1; idx2 < nums.size() - 2; idx2++)
            {
                int l = idx2 + 1, r = nums.size() - 1;
                while(l < r){
                    if(nums[idx1] + nums[idx2] + nums[l] + nums[r]<target){
                        l++;
                    }else if(nums[idx1] + nums[idx2] + nums[l] + nums[r]>target){
                        r--;
                    }else{
                        ans.push_back({nums[idx1], nums[idx2], nums[l], nums[r]});
                        l++;
                        r--;
                        // 跳过相同值
                        while (l< r && nums[l] == nums[l-1])
                            l++;
                        while(l < r && nums[r] == nums[r+1]){
                            r--;
                        }
                    }
                }
                
            
                // 跳过邻近相同的value
                while (nums[idx2 + 1] == nums[idx2])
                {
                    idx2++;
                }
                // 由for循环的idx2++,保证下一次nums[idx2]是不同值
            }
        }

        return ans;
    }
};
// @lc code=end


int main()
{
    vector<int> v{0,0,0,0};
    Solution sol;
    sol.fourSum(v,0);
    return 0;
}