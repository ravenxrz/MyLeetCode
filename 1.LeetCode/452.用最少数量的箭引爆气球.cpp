/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;

        // 从左到右扫描
        // 左端点排序
        sort(points.begin(), points.end(), compare);

        int counter = 1;
        int start = points[0][0], end = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            const vector<int> &point = points.at(i);

            if (point[0] <= end)
            { // point[0] >= start 由排序保证
                start = max(point[0],start);
                end = min(point[1], end); 
            }
            else
            {
                // 需要用新弓箭
                counter++;
                start = point[0];
                end = point[1];
            }
        }

        return counter;
    }

    static bool compare(const vector<int> &p1, const vector<int> &p2)
    {
        return p1.at(0) < p2.at(0);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    //[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
    vector<vector<int>> input{
        {9, 12},
        {1, 10},
        {4, 11},
        {8, 12},
        {3, 9},
        {6, 9},
        {6, 7}};
    cout << sol.findMinArrowShots(input) << endl;

    return 0;
}