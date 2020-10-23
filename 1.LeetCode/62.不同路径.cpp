/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int counter = 0;

    // 暴力dfs 在 37/62时，会出现time exceeded
    void dfs(int cm, int cn, int m, int n){
        if(cm == m && cn == n){
            counter++;
            return ;
        }
        if(cm > m || cn > n){
            return;
        }

        // 向右
        dfs(cm, cn + 1, m, n);
        // 向下
        dfs(cm + 1, cn, m, n);
    }

    // 堆栈+循环
    struct point{
        int x, y;
        int direction = 0;  // 0向右，1向下
        point(int x, int y){
            this->x = x;
            this->y = y;
        }
    };

    int stack_loop(int m, int n){
        // dfs(1, 1, m, n);
        stack<point*> stk;
        // put the first point locating (1,1)
        stk.push(new point(1, 1));
        point* curp;

        while(!stk.empty()){
            curp = stk.top();

            if(curp->x == m && curp->y == n){
                counter++;
                delete stk.top();
                stk.pop();
                if(!stk.empty())
                    stk.top()->direction++;
                continue;
            }

            if(curp->direction == 0){         // 向右走
                if(curp->y+1 <= n){
                    stk.push(new point(curp->x, curp->y + 1));
                }else{
                    curp->direction = 1;     // 改为向下走
                }
            }else if(curp->direction == 1){  // 向下走
                if(curp->x+1 <= m){
                    stk.push(new point(curp->x + 1, curp->y));
                }else{
                    delete stk.top();
                    stk.pop();     // 回退
                    if(!stk.empty())
                        stk.top()->direction++;
                }
            }else if(curp->direction == 2){
                delete stk.top();
                stk.pop();         // 回退
                if(!stk.empty())
                    stk.top()->direction++;
            }
        }
        return counter;
    }

    // 动态规划解法
    int uniquePaths(int m, int n) {
        // 多申请一个0行，0列，方便计算
       vector<vector<int>> dp(m+1,vector<int>(n+1,0));
       // init 1th row, 1th col
       for(int i = 0;i<=m;i++){
           dp[i][0] = 0;
           dp[i][1] = 1;
       }
       for(int j = 0;j<=n;j++){
           dp[0][j] = 0;
           dp[1][j] = 1;
       }

       // 循环put
       for(int i = 2;i<=m;i++){
           for(int j = 2;j<=n;j++){
               for(int k = 1;k<=i;k++){ 
                   // 可以优化， 如dp[2][3] = dp[3][2] ， 只用计算一半的矩阵即可。
                   dp[i][j] += dp[i-k+1][j-1];
               }
           }
       }

        return dp[m][n];
    }
};
// @lc code=end

