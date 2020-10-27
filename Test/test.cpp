/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int idx, vector<int>& tmp, int target){
        if(target == 0){
            ans.push_back(tmp);
            return;
        }

        if(target < 0 || idx == candidates.size()){
            return;
        }

        int remain_num = target / candidates[idx];
        for (int i = 0; i <= remain_num;i++){
            // put
            // i代表当前数字put多少次
            for (int j = 0; j < i;j++){
                tmp.push_back(candidates[idx]);
            }
            dfs(candidates, idx + 1, tmp, target - i * candidates[idx]);
            // not put
            for (int j = 0; j < i;j++){
                tmp.pop_back();
            }
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 预处理
        sort(candidates.rbegin(),candidates.rend());
        vector<int> tmp;
        dfs(candidates, 0, tmp, target);
        return ans;
    }
};
// @lc code=end

int main()
{
//    Solution sol;
//    vector<int> candidates{2,3,6,7};
//    for(auto &vec :sol.combinationSum(candidates,7)){
//        for(auto val : vec){
//            cout << val << " ";
//        }
//        cout << endl;
//    }


    return 0;
}