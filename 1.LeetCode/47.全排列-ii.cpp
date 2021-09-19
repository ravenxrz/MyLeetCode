/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <vector>
#include <algorithm>
using namespace std;

// 交换法
class Solution {
    vector<vector<int>> ans;

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();
        calcAll(nums, 0);
        return ans;
    }

   private:
    void calcAll(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> swap_table;
        for (int i = idx; i < nums.size(); i++) {
            if (!swap_table.count(nums[i])) {
                swap(nums[idx], nums[i]);
                calcAll(nums, idx + 1);
                swap(nums[idx], nums[i]);
                swap_table.insert(nums[i]);
            }
        }
    }
};



// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int> &nums, vector<int> &tmp, int idx){
        static vector<bool> visit(nums.size(),false);
        if(idx == nums.size()){
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size();i++){
            if(visit[i])
                continue;
            // put
            visit[i] = true;
            int t_val = tmp[idx];
            tmp[idx] = nums[i];
            dfs(nums, tmp, idx + 1);
            // remove
            visit[i] = false;
            // 跳过所有和tmp[idx]相同的元素
            while(i < nums.size() && tmp[idx] == nums[i])
                i++;
            i--;        // 后面for循环会再+1，所以这里-1
            tmp[idx] = t_val;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*  sort(nums.begin(), nums.end());
         vector<vector<int>> ans;
         do{
             ans.push_back(nums);
         } while (next_permutation(nums.begin(), nums.end())); */
        sort(nums.begin(),nums.end());
        vector<int> tmp(nums.size(),0x7fffffff);
        dfs(nums, tmp, 0);
        return ans;
    }
};
// @lc code=end

