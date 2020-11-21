/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// @lc code=start
class Solution {
public:
    
    // interval1是否完全落入interval2中
    inline bool check_case1(const vector<int> &interval1, const vector<int> &interval2)
    {
        return (interval1[0] >= interval2[0] && interval1[1] <= interval2[1]);
    }
    
    // interval1 与 interval 2 有相交关系
    inline bool check_case2(const vector<int> &interval1, const vector<int> &interval2)
    {
        return   interval1[0] < interval2[1] && interval1[1] >= interval2[1];
    }
    
    int find_pre_idx(const vector<bool>& removed_element,int start){
        int idx = start-1;
        while(idx>0){
            if(removed_element[idx] == false) return idx;
            idx--;
        }
        return idx;
    }
    
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1) return 0;
        int ans = 0;
        int pre_idx = -1;
        // sort
        sort(intervals.begin(), intervals.end(), sorter);
        vector<bool> removed_element(intervals.size(),false);
    
        for (int i = 1; i < intervals.size(); i++) {
            pre_idx = find_pre_idx(removed_element,i);
            if (check_case1(intervals[i], intervals[pre_idx])) {
                // 当前interval完全包含在前一个interval中
                removed_element[pre_idx] = true;
                ans++;
                } else if (check_case2(intervals[i], intervals[pre_idx])) {
                // 前一个interval完全包含在本interval中
                removed_element[i] = true;
                ans++;
            }
        }
        return ans;
    }
    
private:
    static bool sorter(const vector<int> &v1, const vector<int> &v2)
    {
        if (v1[0] != v2[0]) {
            return v1[0] < v2[0];
        } else {
            return v1[1] < v2[1];
        }
    }
};
// @lc code=end