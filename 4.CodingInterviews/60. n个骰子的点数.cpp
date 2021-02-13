#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        // dp
        vector<vector<double>> dp(n + 1);
        // init
        for (int i = 1; i <= n; i++)
        {
            dp[i] = vector<double>(6 * n + 1, 0);
            dp[i][i] = 1;
            dp[i][6 * i] = 1;
        }
        // init n == 1
        for (int i = 1; i <= 6; i++)
        {
            dp[1][i] = 1;
        }
        // calc
        for (int i = 2; i <= n; i++) // f(i) = ?
        {
            for (int j = i + 1; j < i * 6; j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        // print result
        for (int i = 0; i < dp[n].size(); i++)
        {
            cout << dp[n][i] << '\n';
        }
    }
};

int main()
{
    Solution sol;
    {
        sol.dicesProbability(1);
    } 
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        // dp
        vector<vector<double>> dp(n + 1);
        // init
        for (int i = 1; i <= n; i++)
        {
            dp[i] = vector<double>(6 * n + 1, 0);
            dp[i][i] = 1;
            dp[i][6 * i] = 1;
        }
        // init n == 1
        for (int i = 1; i <= 6; i++)
        {
            dp[1][i] = 1;
        }
        // calc
        for (int i = 2; i <= n; i++) // f(i) = ?
        {
            for (int j = i + 1; j < i * 6; j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    if (j - k >= 0)
                    {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }
        double total = pow(6, n);
        vector<double> ans(5 * n + 1);
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = dp[n][i + n] / total;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        for (double val : sol.dicesProbability(1))
        {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        // dp
        vector<vector<double>> dp(n + 1);
        // init
        for (int i = 1; i <= n; i++)
        {
            dp[i] = vector<double>(6 * n + 1, 0);
            dp[i][i] = 1;
            dp[i][6 * i] = 1;
        }
        // init n == 1
        for (int i = 1; i <= 6; i++)
        {
            dp[1][i] = 1;
        }
        // calc
        for (int i = 2; i <= n; i++) // f(i) = ?
        {
            for (int j = i + 1; j < i * 6; j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    if (j - k >= 0)
                    {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }
        double total = pow(6, n);
        vector<double> ans(5 * n + 1);
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = dp[n][i + n] / total;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        for (double val : sol.dicesProbability(1))
        {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}