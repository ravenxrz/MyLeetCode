//
// Created by Raven on 2021/3/14.
//

/**
 * 归并排序方法
 */
class Solution {
public:
    vector <vector<int>> intervalIntersection(vector <vector<int>> &firstList, vector <vector<int>> &secondList)
    {
        if (firstList.empty()) return {};
        if (secondList.empty()) return {};
        
        vector <vector<int>> ans;
        
        int i = 0;
        int j = 0;
        int left, right;
        if (firstList[i][0] <= secondList[j][0]) {
            left = firstList[i][0];
            right = firstList[i][1];
            ++i;
        } else {
            left = secondList[j][0];
            right = secondList[j][1];
            ++j;
        }
        
        while (i < firstList.size() && j < secondList.size()) {
            // take an interval
            int cur_left, cur_right;
            if (firstList[i][0] <= secondList[j][0]) {
                cur_left = firstList[i][0];
                cur_right = firstList[i][1];
                ++i;
            } else {
                cur_left = secondList[j][0];
                cur_right = secondList[j][1];
                ++j;
            }
            // check
            if (left <= cur_left && right >= cur_right) {
                ans.push_back({cur_left, cur_right});
            } else if (right >= cur_left && right <= cur_right) {
                ans.push_back({cur_left, right});
                right = cur_right;
            } else if (right < cur_left) {
                left = cur_left;
                right = cur_right;
            }
        }
        
        while (i < firstList.size()) {
            if (left <= firstList[i][0] && right >= firstList[i][1]) {
                ans.push_back({firstList[i][0], firstList[i][1]});
            } else if (right >= firstList[i][0] && right <= firstList[i][1]) {
                ans.push_back({firstList[i][0], right});
            }
            i++;
        }
        while (j < secondList.size()) {
            if (left <= secondList[j][0] && right >= secondList[j][1]) {
                ans.push_back({secondList[j][0], secondList[j][1]});
            } else if (right >= secondList[j][0] && right <= secondList[j][1]) {
                ans.push_back({secondList[j][0], right});
            }
            j++;
        }
        return ans;
    }
};

