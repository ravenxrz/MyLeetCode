#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        // assert(target.size() >= 2)
        int start = 1, end = 2;
        vector<vector<int>> ans;
        int half_target = (target + 1) / 2;
        while (end <= half_target) {
            int tmp_target = (start + end) * (end - start + 1) / 2;
            if (tmp_target == target) {
                if (end - start + 1 >= 2) {
                    vector<int> tmp(end - start + 1, 0);
                    for (int i = start; i <= end; i++) {
                        tmp[i - start] = i;
                    }
                    ans.emplace_back(tmp);
                }
                start++;
                end++;
            } else if (tmp_target > target) {
                start++;
            } else {
                end++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        for (auto vec:sol.findContinuousSequence(5)) {
            for (auto val : vec) {
                cout << val << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
