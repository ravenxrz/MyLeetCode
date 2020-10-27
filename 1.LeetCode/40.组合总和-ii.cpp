/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    // 暴力回溯1，每次dfs只放置一个元素
    /*void dfs(vector<int> &candidates, vector<int> &tmp, int idx, int target){
        if(target  == 0){
            if(find(ans.begin(),ans.end(),tmp) == ans.end())
                ans.push_back(tmp);
            return;
        }

        if(target < 0 || idx == candidates.size()){
            return ;
        }

        // put
        tmp.push_back(candidates[idx]);
        dfs(candidates, tmp, idx + 1, target - candidates[idx]);
        // not put
        tmp.pop_back();
        dfs(candidates, tmp, idx + 1, target);
    }*/

    // 暴力回溯2， 每次dfs可能放置多个元素
    void dfs(vector<int> &candidates,vector<int> &tmp,int idx, int target){
        if(target == 0){
            ans.push_back(tmp);
            return;
        }

        for (int i = idx; i < candidates.size();i++){
            if(candidates[i] <= target){
                if(i > idx && candidates[i]==candidates[i-1])   // 注意剪枝条件，在新的一轮计算中，如果当前节点和之前节点相同，则直接跳过，具体看笔记
                    continue;
                // put
                tmp.push_back(candidates[i]);
                dfs(candidates, tmp, i + 1, target - candidates[i]);
                // not put
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        dfs(candidates, tmp, 0, target);
        return ans;
    }
};
// @lc code=end

