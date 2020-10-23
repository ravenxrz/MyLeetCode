/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    struct point{
        char c;
        int row;
        int col;

        point(char c, int row, int col){
            this->c = c ;
            this->row = row;
            this->col = col;
        }
    };

    static bool compare(const point *p1, const point *p2){
        if(p1->row < p2->row){
            return true;
        }else if(p1->row > p2->row){
            return false;
        }else{  // p1.row == p2.row
            return p1->col < p2->col;
        }
    }

    string convert(string s, int numRows) {
        if(numRows == 1)    // numRows = 1时，无需处理
            return s;

        int direction = 0;  // 0 down, 1 up
        int idx = 0;
        int i = 1, j = 1;
        vector<point *> vec;

        while(idx != s.size()){
            if(direction == 0){
                vec.push_back(new point(s.at(idx), i, j));
                idx++;
                i++;
                if(i == numRows+1){ // 走到下尽头
                    j++;
                    i = numRows - 1;
                    direction = 1;  // 转向
                }
            }else {
                vec.push_back(new point(s.at(idx), i, j));
                idx++;
                i--;
                j++;
                if (i == 0) { // 走到上尽头
                    i = 2;
                    direction = 0;  // 转向
                }
            }
        }

        // 排序
        sort(vec.begin(), vec.end(),compare);

        // 拼接最终结果
        string ans(vec.size(),' ');
        for (int i = 0; i < vec.size();i++){
            ans[i] = vec.at(i)->c;
        }

        return ans;
    }
};
// @lc code=end

