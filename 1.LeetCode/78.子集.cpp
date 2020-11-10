/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int idx, const vector<int> &nums, vector<int> &tmp){
        if(idx == nums.size()){
            ans.push_back(tmp);
            return;
        }

        // not put
        dfs(idx+1,nums,tmp);
        
        // put
        tmp.push_back(nums.at(idx));
        dfs(idx+1,nums,tmp);
        tmp.pop_back();
      
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        dfs(0,nums,tmp);
        return ans;
    }
};
// @lc code=end

