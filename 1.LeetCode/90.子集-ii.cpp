/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

#include <vector>
#include <map>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<vector<int>> ans;

    void dfs(map<int,int>::iterator cur_iter, const map<int,int>:: iterator &end_iter, vector<int> tmp){
        if(cur_iter == end_iter){
            ans.push_back(tmp);
            return;
        }

        const int num = cur_iter->second;
        for(int i = 0;i<=num;i++){
            cur_iter++;
            dfs(cur_iter,end_iter,tmp);
            cur_iter--;
            tmp.push_back(cur_iter->first);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> mymap;
        for(auto &val : nums){
            mymap[val]++;
        }
        dfs(mymap.begin(),mymap.end(),{});
        return ans;
    }
};
// @lc code=end

int main()
{
    vector<int> nums{1,2,2};
    Solution sol;
    sol.subsetsWithDup(nums);
    return 0;
}
