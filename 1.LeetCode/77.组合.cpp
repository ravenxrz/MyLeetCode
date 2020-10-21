/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void dfs1(int idx, int n, int k, vector<int> tmp){
        if(tmp.size() == k){
            ans.push_back(tmp);
            return;
        }

        if(idx > n){
            return;
        }

        // put
        tmp.push_back(idx);
        dfs1(idx + 1, n, k, tmp);
        // remove
        tmp.pop_back();
        dfs1(idx + 1, n, k, tmp);
    }

    vector<int> tset;
    void init_set(int  n){
        for (int i = 1; i <= n;i++){
            tset.push_back(i);
        }
    }

    void dfs2(int idx, int n, int k, vector<int> tmp){
        if(tmp.size() == k){
            vector<int> ret;
            ret.resize(tset.size() - k);
            set_difference(tset.begin(),tset.end(),tmp.begin(),tmp.end(),ret.begin());
            ans.push_back(ret);
            return;
        }

        if(idx > n){
            return;
        }

        // put
        tmp.push_back(idx);
        dfs2(idx + 1, n, k, tmp);
        // remove
        tmp.pop_back();
        dfs2(idx + 1, n, k, tmp);
    }


    vector<vector<int>> combine(int n, int k)
    {
        if(k < n/2){
            dfs1(1, n, k, {});
        }else{
            init_set(n);
            dfs2(1, n, n-k, {});
        }

        return ans;
    }
};
// @lc code=end

