//
// Created by raven on 2021/7/20.
//
class Solution {
    int ans;
    int _m;
    int _n;
    int _k;
public:
    int movingCount(int m, int n, int k)
    {
        ans = 0;
        _m = m;
        _n = n;
        _k = k;
        set <pair<int, int>> visit;
        visit.insert(pair<int, int>(0, 0));
        dfs(visit, 0, 0);
        return ans;
    }


private:
    int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };
    
    void dfs(set <pair<int, int>> &visit, int x, int y)
    {
        ans += 1;
        
        // move
        for (int i = 0; i < 4; i++) {
            int nx = x + dp[i][0];
            int ny = y + dp[i][1];
            if (nx < 0 || nx >= _m || ny < 0 || ny >= _n) {   // Bound check
                continue;
            }
            if (visit.count(pair<int, int>(nx, ny)) || calcSumDigits(nx, ny) > _k) {
                continue;
            }
            visit.insert(pair<int, int>(nx, ny));
            dfs(visit, nx, ny);
        }
    }
    
    int calcSumOneNumberDigits(int x)
    {
        int sum = 0;
        while (x) {
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }
    
    int calcSumDigits(int x, int y)
    {
        return calcSumOneNumberDigits(x) +
               calcSumOneNumberDigits(y);
    }
    
};