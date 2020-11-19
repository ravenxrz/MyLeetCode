/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 拓扑排序
     * 采用邻接链表 + 是否有环，有环则false，无环则true
     * @param numCourses
     * @param prerequisites
     * @return
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0) return false;
        /* stack 辅助dfs遍历，pair->first 存储遍历点, pair->second 存储遍历点的下一个相邻点 */
        stack<pair<int,int>> stk;
        vector<vector<int>> head(numCourses,vector<int>());
        vector<bool> visit(numCourses,false);
        vector<int> parent(numCourses,-1);
        int cur, next, next_idx;
        
        /* 得到邻接矩阵 */
        for(const auto& line : prerequisites){
            for(int i = 1;i<line.size();i++){
                head[line[i]].push_back(line[0]);
            }
        }
        
        /* dfs 环形检测 */
        for(int i = 0;i<numCourses;i++){
            if(!visit[i]){
                /* 遍历树，用于环检测 */
                fill(parent.begin(),parent.end(),-1);
                /* dfs */
                stk.push({i,0});    // push first point
                parent[i] = i;
                visit[i] = true;
                while(!stk.empty()){
                    cur = stk.top().first;
                    next_idx = stk.top().second;
                    while(next_idx < head[cur].size()){
                         next =head[cur][next_idx];
                        if(visit[next]){
                            /* 检测是否有环 */
                            int back = cur;
                            /* case 1：直接相连*/
                            if(find(head[next].begin(),head[next].end(),back) != head[next].end())
                                return false;
                            /* case 2: 在同一棵遍历树 */
                            while(back != parent[back]){
                                back = parent[back];
                                if(back == next) return false;
                            }
                            next_idx++;
                        }else{
                            break;
                        }
                    }
                    if(next_idx >= head[cur].size()){
                        stk.pop();
                    }else{
                        stk.top().second = next_idx+1;
                        next = head[cur][next_idx];
                        stk.push({next,0});
                        visit[next] = true;
                        /* 设置遍历树 */
                        parent[next] = cur;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> test{{1, 0}, {0, 2},{2,1}};
    cout << sol.canFinish(3, test );
    return 0;
}