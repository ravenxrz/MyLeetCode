#include "leetcode_base.h"

class Solution
{
	int dp[101][101];
public:
	int findMaxForm(vector<string> &strs, int m, int n)
	{
		for (int i = 1; i <= strs.size(); i++)
		{
			int one_num = 0;
			int zero_num = 0;
			calc(strs[i - 1], one_num, zero_num);
			for (int j = m; j >= zero_num; j--)
			{
				for (int k = n; k >= one_num; k--)
				{
					dp[j][k] = max(dp[j][k], dp[j - zero_num][k - one_num] + 1);
				}
			}
		}
		return dp[m][n];
	}

private:
	void calc(const string &str, int &one_num, int &zero_num)
	{
		for (char c : str)
		{
			if (c == '1')
				one_num++;
			else if (c == '0')
				zero_num++;
		}
	}
};

int main()
{
	Solution sol;
	vector<string> strs = {"10", "0001", "111001", "1", "0"};
	cout << sol.findMaxForm(strs, 5, 3) << endl;
	return 0;
}
