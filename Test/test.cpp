/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // 避免 ['z','a','b'],'z'的情况
        sort(letters.begin(),letters.end());
        // 二分查找
        int i = 0, j = letters.size() - 1;
        int mid = (i+j)/2;
        while(i<j){
            if(letters.at(mid) < target){
                i = mid + 1;
            }else if(letters.at(mid) > target){
                j = mid - 1;
            }else{  // 找到相等的
                while(letters.at((mid+1) % letters.size()) == letters.at(mid)){
                    mid = (mid+1) % letters.size();
                }
                return letters.at((mid + 1) % letters.size());
            }
            mid = (i + j) / 2;
        }
        //  i>=j， 说明没有目标值
        if(letters.at(mid) > target){
            return letters.at(mid);
        }else {
            return letters.at((i + 1) % letters.size());
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    //['e','e','e','e','e','e','n','n','n','n']
    //'n'
    vector<char> vec{'z','a','b'};
    cout << sol.nextGreatestLetter(vec,'z');
    return 0;
}