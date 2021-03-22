//
// Created by Raven on 2021/3/22.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
    int dp[210][210][2];
public:
    vector<int> findSquare(vector<vector<int>> &matrix)
    {
        memset(dp, 0, sizeof(dp));
        int start_row = 0, start_col = 0, max_len = 0;
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix.size(); ++j) {
                if (matrix[i - 1][j - 1] == 0) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                    // 方形变大
                    int len = min(dp[i][j][0], dp[i][j][1]);
                    while(len >0){
                        if (dp[i][j - len + 1][1] >= len && dp[i - len + 1][j][0] >= len) {
                            if (max_len < len) {
                                max_len = len;
                                start_row = i - len ;
                                start_col = j - len ;
                            }
                            break;
                        }
                        --len;
                    }
                }
            }
        }
        if (max_len == 0) return {};
        return {start_row, start_col, max_len};
    }
};

int main()
{
    Solution sol;
    {
        vector<vector<int>> matrix = {
                {1, 0, 1},
                {0, 0, 1},
                {0, 0, 1}
        };
        for (auto _ : sol.findSquare(matrix)) {
            cout << _ << ' ';
        }
        cout << endl;
    }
    {
        vector<vector<int>> matrix = {
                {0, 1, 1},
                {1, 0, 1},
                {1, 1, 0}
        };
        for (auto _ : sol.findSquare(matrix)) {
            cout << _ << ' ';
        }
        cout << endl;
    }
    {
        vector<vector<int>> matrix =
                {
                        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
                        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
                        {0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
                        {0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                        {1, 0, 1, 0, 1, 1, 0, 1, 1, 1},
                        {1, 1, 1, 0, 1, 0, 0, 1, 1, 1}
                };
        for (auto _ : sol.findSquare(matrix)) {
            cout << _ << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
