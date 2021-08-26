#include "leetcode_base.h"

class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int m = matrix.size();
		// assert(m > 0 && !matrix[0].empty());
		int n = matrix[0].size();
		int i = 0;
		int j = n - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				j--;
			else if (matrix[i][j] < target)
				i++;
		}
		return false;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
	cout << sol.searchMatrix(matrix, 1000) << endl;
	return 0;
}