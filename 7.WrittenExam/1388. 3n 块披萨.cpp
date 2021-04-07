#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxSizeSlices(vector<int> &slices)
    {
        // 0--slices.size()-1
        vector<int> slice1(slices.begin(), slices.end() - 1);
        vector<int> slice2(slices.begin() + 1, slices.end());
        return max(calc_max(slice1), calc_max(slice2));
    }

private:
    int calc_max(vector<int> &slices)
    {
        const int num = (slices.size() + 1) / 3;
        // use 2-dim bound
        vector<vector<int>> dp(slices.size() + 1, vector<int>(num+1, 0));
        // core algorithm
        // set i = 1
        dp[1][1] = slices[0];
        for (int i = 2; i < dp.size(); i++) {
            for (int j = 1; j <= num; j++) {
                dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i - 2][j - 1] + slices[i - 1]);
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};

int main()
{
    Solution sol;
    {
        vector<int> slices{1,2,3,4,5,6};
        cout << sol.maxSizeSlices(slices) << '\n';
    }
    return 0;
}
