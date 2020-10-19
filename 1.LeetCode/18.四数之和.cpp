/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {        
        vector<vector<int>> ans;

        // 排序
        sort(nums.begin(), nums.end());

        for (int idx1 = 0; idx1+3 < nums.size(); idx1++)
        {
            for (int idx2 = idx1 + 1; idx2+2 < nums.size(); idx2++)
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
                while (idx2+1 < nums.size() && nums[idx2 + 1] == nums[idx2])
                {
                    idx2++;
                }
                // 由for循环的idx2++,保证下一次nums[idx2]是不同值
            }

            // 跳过临近相同value
            while(idx1+1 < nums.size() && nums[idx1+1] == nums[idx1]){
                idx1++;
            }
        }

        return ans;
    }
};
// @lc code=end


int main()
{
    vector<int> v{1, 0, -1, 0, -2, 2};
    Solution sol;
    sol.fourSum(v,0);
    return 0;
}