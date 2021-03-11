#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n)
    {
        // dp[i][j] 表示i个鸡蛋，j层楼，最坏情况下最少需要测试的次数
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        // k = 1, 只有一个鸡蛋
        for (int j = 1; j < dp[1].size(); j++) {
            dp[1][j] = j;
        }
        // N = 1, 只有一层楼
        for (int i = 1; i < dp.size(); i++) {
            dp[i][1] = 1;
        }
        // core
        for (int i = 2; i < dp.size(); i++) {
            for (int j = 2; j < dp[0].size(); j++) {
                // 注意边界条件
                int left = 1;
                int right = j;
                int mid = 1;
                while (left + 1 < right) {
                    mid = (left + right) >> 1;
                    if (dp[i - 1][mid - 1] < dp[i][j - mid]) {       // T1 < T2
                        left = mid;
                    } else if (dp[i - 1][mid - 1] > dp[i][j - mid]) {
                        right = mid;
                    } else {
                        left = right = mid;
                    }
                }
                int tmp_ans = max({dp[i - 1][left - 1], dp[i][j - left],
                                   dp[i - 1][right-1], dp[i][j - right]})+1;
                dp[i][j] = tmp_ans;
            }
        }
        return dp[k][n];
    }
};

int main()
{
    Solution sol;
//    cout << sol.superEggDrop(1,2) << '\n';
    cout << sol.superEggDrop(2, 6) << '\n';
    cout << sol.superEggDrop(3, 14) << '\n';
    cout << sol.superEggDrop(2, 100) << '\n';
    
    return 0;
}
