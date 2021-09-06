#include "leetcode_base.h"

// 路径压缩
class Solution {
    unsigned long long dp[101];

   public:
    int numMusicPlaylists(int N, int L, int K) {
        if (L == 0)
            return 0;
        memset(dp, 0, sizeof(dp));  // dp[i][j] 表示听了i首歌，
                                    // 一共有j首不同的歌曲, 有多少种方案
        dp[1] = N;
        for (int i = 2; i <= L; i++) {
            for (int j = N; j >= 1; j--) {
                dp[j] = (dp[j - 1] * (N - (j - 1)) + dp[j] * max(j - K, 0));
                dp[j] %= 1000000007;
            }
        }
        return dp[N] % 1000000007;
    }
};

// 未路径压缩
class Solution {
    unsigned long long dp[101][101];

   public:
    int numMusicPlaylists(int N, int L, int K) {
        if (L == 0)
            return 0;
        memset(dp, 0, sizeof(dp));  // dp[i][j] 表示听了i首歌，
                                    // 一共有j首不同的歌曲, 有多少种方案
        dp[1][1] = N;
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] += dp[i - 1][j - 1] * (N - (j - 1)) +
                            dp[i - 1][j] * max(j - K, 0);
                dp[i][j] %= 1000000007;
				cout << dp[i][j] << ' ';
            }
			cout << endl;
        }



        return dp[L][N] % 1000000007;
    }
};

int main() {
    Solution sol;
    {
        // cout << sol.numMusicPlaylists(3, 3, 1) << endl;
        cout << sol.numMusicPlaylists(2, 3, 0) << endl;
        // cout << sol.numMusicPlaylists(2, 3, 1) << endl;
    }

    return 0;
}