/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        if(nums.size() == 0)
            return ans;

        // 预处理，对nums排序
        sort(nums.begin(), nums.end());

        int target = nums[0];
        for (int i = 1; i < nums.size();i++){    
            // 内循环转换为两数之和 , 找到两个数 使得 n1 + n2 + target == 0
            int l = i, r = nums.size() - 1;
            while(l < r){
                if(target + nums[l] + nums[r] < 0){
                    l++;
                }else if(target + nums[l] + nums[r] > 0){
                    r--;
                }else{
                    ans.push_back(vector<int> { target, nums[l], nums[r] });
                    l++;
                    r--;
                    // 优化
                    while(l < r && nums[l] == nums[l-1])
                        l++;
                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }
            }

            // 跳过所有和本次target相同的位置
            while(i < nums.size() && nums[i] == target){
                i++;
            }
            if(i < nums.size()){
                target = nums[i];
            }
            
        }
        return ans;
    }
};// @lc code=end


int main(){
    vector<int> input { -1, 0, 1, 2, -1, -4 };
    Solution sol;
    sol.threeSum(input);
    return 0;
}