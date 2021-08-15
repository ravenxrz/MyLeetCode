#include "leetcode_base.h"

class Solution
{
	vector<string> ans;

public:
	vector<string> generateParenthesis(int n)
	{
		ans.clear();
		string cur_string;
		dfs(n, 0, 0, 0, cur_string);
		return ans;
	}

private:
	void dfs(int target_level, int cur_level, int zero_cnts, int one_cnts, string &cur_string)
	{
		if (cur_level == target_level && one_cnts == zero_cnts)
		{
			ans.push_back(cur_string);
			return;
		}
		if (zero_cnts < target_level)
		{
			cur_string.push_back('(');
			dfs(target_level, cur_level + 1, zero_cnts + 1, one_cnts, cur_string);
			cur_string.pop_back();
		}
		if (one_cnts < target_level)
		{
			cur_string.push_back(')');
			dfs(target_level, cur_level + 1, zero_cnts, one_cnts + 1, cur_string);
			cur_string.pop_back();
		}
	}
};

int main()
{
	Solution sol;
	for (auto &str : sol.generateParenthesis(3))
	{
		cout << str << endl;
	}
	return 0;
}
