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
#include <regex>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        // 去重
        regex pattern("/{2,}");
        path = regex_replace(path,pattern,"/");
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
            }else if(!token.empty()){
                stk.push(token);
            }
        }

        // 回到了根路径
        if(stk.empty())
            return "/";

        // 否则，还原真实路径
        token.clear();
        while(!stk.empty()){
            token.insert(0,"/"+stk.top());
            stk.pop();
        }
        return token;
    }
};// @lc code=end

int main()
{
    Solution sol;
    cout << sol.simplifyPath("/a//b////c/d//././/..");
    return 0;
}