/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ret=0;
        while(x){
            int t = (unsigned)ret*10;
            if(t/10!=ret)return 0;
            ret=t+x%10;
            x/=10;
        }
        return ret;
    }

    
};
// @lc code=end

int main(){
    int a = -1;
    int b = (unsigned)a;
    int c = b;
    return b;
}