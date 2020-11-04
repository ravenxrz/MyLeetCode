/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;

        size_t max_length = 0;
        vector<char> selection;
        int j = 0;       // 区间下标
        while(j<s.length()){
            char target = s.at(j);
            auto vloc = find(selection.begin(),selection.end(),target);
            if( vloc != selection.end()){   // contain target
                max_length = max(max_length,selection.size());
                // 移除前段区间，直到target不在selection容器中为止
                selection.erase(selection.begin(),vloc+1);  // 移除 [begin, vloc]区间的所有元素
            }else{  // not contain
                selection.push_back(target);
                j++;
            }
        }
        return max_length > selection.size() ? max_length : selection.size();
    }
};
// @lc code=end

int main()
{
    return 0;
}