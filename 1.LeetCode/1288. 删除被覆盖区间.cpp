//
// Created by Raven on 2021/3/13.
//
/**
 * 给你一个数组，返回一个等长的数组，对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1。不好用语言解释清楚，直接上一个例子：
    给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。
    解释：第一个 2 后面比 2 大的数是 4; 1 后面比 1 大的数是 2；第二个 2 后面比 2 大的数是 4; 4 后面没有比 4 大的数，填 -1；3 后面没有比 3 大的数，填 -1。
 */
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0]) {
            return a[1] > b[1]; // 降序
        }
        return a[0] < b[0];
    }

public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        
        int left = intervals[0][0];
        int right = intervals[0][1];
        int ret = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            // 是否完全包含
            if (left <= intervals[i][0] && right >= intervals[i][1]) {
                ret++;
            } else if (left <= intervals[i][0] && right <= intervals[i][1]) {
                // 是否相交
                right = intervals[i][1];
            } else if (right <= intervals[i][0]) {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        
        return intervals.size() - ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {
            {1, 4},
            {3, 6},
            {2, 8}
    };
    cout << sol.removeCoveredIntervals(intervals) << endl;
    return 0;
}
