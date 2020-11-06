/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <vector>
#include <iostream>
using namespace std;


// @lc code=start
class Solution {
public:
#define INF 0X7fffffff

    struct point{
        int x;
        int y;

        point(int x, int y) : x(x), y(y) {}
    };

    // 节点结构
    struct node{
        vector<point> next_id;    // 连接的节点的id
    };

    // 将grid转换为一个邻接链表
    void convert(const vector<vector<int>> &grid, vector<vector<node>> &head){
        int m = grid.size();
        int n = grid[0].size();
        // 最后一行
        for(int col = 0;col<n-1;col++){
            head[m-1][col].next_id.emplace_back(m-1,col+1);
        }
        // 最后一列
        for(int row = 0;row<m-1;row++){
            head[row][n-1].next_id.emplace_back(row+1,n-1);
        }
        // 中间
        for(int i = 0;i<m-1;i++){
            for(int j = 0;j<n-1;j++){
                // 右连接点
                head[i][j].next_id.emplace_back(i,j+1);
                // 下连接点
                head[i][j].next_id.emplace_back(i+1,j);
            }
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        // step1: 将grid转换为一个邻接链表
        vector<vector<node>> head(m,vector<node>(n));
        convert(grid,head);

        // step2: 通过dijkstra算法求解
        const int node_nums = m*n;
        vector<vector<int>> D(m,vector<int>(n,INF));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        visited[0][0] = true;
        int added_node_num = 1;

        // 初始化D
        D[0][0] = grid[0][0];
        for(point conn_p : head[0][0].next_id){
            D[conn_p.x][conn_p.y] = grid[conn_p.x][conn_p.y] + D[0][0];
        }

        // Dijkstra算法
        while(added_node_num != node_nums){
            point cur_point = {0,0};
            int min_value = INF;
            /* 确定当前最短点 */
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(!visited[i][j] && min_value >= D[i][j]){
                        min_value = D[i][j]; cur_point = {i,j};
                    }
                }
            }
            visited[cur_point.x][cur_point.y] = true;
            added_node_num++;
            /* 根据当前点，更新其他点 */
            for(point conn_p : head[cur_point.x][cur_point.y].next_id){
                if(D[conn_p.x][conn_p.y] > D[cur_point.x][cur_point.y] + grid[conn_p.x][conn_p.y]){
                    D[conn_p.x][conn_p.y] = D[cur_point.x][cur_point.y] + grid[conn_p.x][conn_p.y];
                }
            }
        }

        return D[m-1][n-1];
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
//            {5,0,6,6,1,1,3,6,5,6,1,2,1,4,0,2,6,4,9,4,3,6,1,8,3,6,2,5,3,7,7,0,7,5,7,0,6,0,7,3,8,8,5,1,2,7,4,0,4,5,7,9,3,8,7,6,7,9,4,2,6,1,2,6,7,9,6,5,1,3,1,2,4,6,3,6,6,9,9,0,5,6,9,8,6,9,5,3,0,1,5,9,4,8,5,1,9,3,9,1,7,0,5,1,8,8,9,4,0,8,6,5,4,8,3,3,9,0,6,9,3,4,8,8,2,3,1,1,7,2,4,6,2,9,9,3,0,8,9,0,9,8,7,5,6,2,8,7,5,7,6,8,1,5,6,3,0,8,6,9,2,3,7,5,4,6,0,6,7,9,6,6,9,5,1,7,8,2,4,3,9,1,1,0,8,0,5,0,0,1,2,2,6,9,9,1,6,9,7,5}
            {1,2,3},
            {4,5,6}
    };
    cout << sol.minPathSum(grid);
    return 0;
}