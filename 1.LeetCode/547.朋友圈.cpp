/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    /* ans */
    int counter = 0;
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty())
            return 0;
        vector<bool> visit(M.size(), false);
        for(int i = 0;i<M.size();i++){
            if(!visit[i]){
                visit[i] = true;
                counter++;
                _dfs(M,visit,  i);
            }
        }
        return counter;
    }
private:
    void _dfs(const vector<vector<int>>& M, vector<bool>& visit,int idx){
        for(int i = 0;i<M.size();i++){
            if(!visit[i] && M[idx][i] == 1 && idx != i){
                /* 标志visit */
                visit[i] = true;
                _dfs(M,visit,i);
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> M  = {
            {1,1,0},
            {1,1,0},
            {0,0,1}
    };
    cout << sol.findCircleNum(M);
    return 0;
}
