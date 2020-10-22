/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        // 去重
        unique(path.begin(), path.end());
        // 去掉最后一个/
        if(path.at(path.size()-1) == '/'){
            path = path.substr(0, path.size() - 1);
        }
        stack<string> stk;
        // 按照 "/" 分割
        stringstream strstream(path);
        string token;
        while(getline(strstream,token,'/')){
            if(token == "."){
                continue;
            }else if(token == ".."){
                if(!stk.empty()){
                    stk.pop();
                }
            }else{
                stk.push(token);
            }
        }

        // 还原
        token.clear();
        while(!stk.empty()){
            token = "/" + stk.top() + token;
            stk.pop();
        }
        // 反序
        
        return token;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.simplifyPath("/home/");
    return 0;
}