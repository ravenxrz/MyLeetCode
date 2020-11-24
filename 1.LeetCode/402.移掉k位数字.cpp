/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        
        stack<char> stk;
        int i = 1;
        stk.push(num[0]);
        while(i< num.size() && k>0){
          if(num[i] >= stk.top()){
              stk.push(num[i]);
          }else{
              do{
                  stk.pop(); k--;
              }while(k > 0 && !stk.empty() && num[i] < stk.top());
              if(k <= 0) break;
              stk.push(num[i]);
          }
          i++;
        }
        while(k>0){     // 序列后续都是增，则从后面移除剩余位
            stk.pop();k--;
        }
        
        // 得到结果
        string ans;
        while(!stk.empty()){
            ans += stk.top();stk.pop();
        }
        reverse(ans.begin(),ans.end());
        // 拼接后续没有遍历完的结果
        ans += num.substr(i,num.size()-i);
        
        // 去除前导0
        while(!ans.empty() && ans[0] == '0'){
            ans.erase(0,1);
        }
        if(ans.empty()){ // 避免多个0的情况
            ans = "0";
        }
        return ans;
    }
};
// @lc code=end




int main()
{
    Solution sol;
    cout << sol.removeKdigits("1432219"
                              ,3);
    return 0;
}