/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> nums;
    
    int f(int start, int end)
    {
        if (end < start) return 0;
        if (start == end) return 1;
        
        if (nums[start-1][end-1] != -1) {
            return nums[start-1][end-1];
        }
        
        int sum = 0;
        for (int pos = start; pos <= end; pos++) {
            int sum1 = f(start, pos - 1);
            int sum2 = f(pos + 1, end);
            if (sum1 == 0 && sum2 != 0) {
                sum += sum2;
            } else if (sum2 == 0 && sum1 != 0) {
                sum += sum1;
            } else {
                sum += (sum1 * sum2);
            }
        }
        
        nums[start-1][end-1] = sum;
        return sum;
    }
    
    int numTrees(int n)
    {
        nums.resize(n, vector<int>(n , -1));
        return f(1, n);
    }
    
};
// @lc code=end

int main()
{
    Solution sol;
    cout << sol.numTrees(18);
    return 0;
}