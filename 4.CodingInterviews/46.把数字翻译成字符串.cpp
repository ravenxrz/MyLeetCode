//
// Created by Raven on 2021/2/10.
//
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int translateNum(int num)
    {
        ans = 0;
        // int to str
        char buf[100];
        sprintf(buf, "%d", num);
        string num_str = buf;
        backtrace(num_str, 0);
        return ans;
    }

private:
    void backtrace(const string &num, int idx)
    {
        if (idx >= num.size()) {
            ans++;
            return;
        }
        // 占一位
        backtrace(num, idx + 1);
        // 占两位，但是需要条件
        if (idx+1 < num.size() && num[idx] != '0' && num.substr(idx, 2) <= "25") {
            backtrace(num, idx + 2);
        }
    }

private:
    int ans;
};

int main(){
    Solution sol;
    {
        cout << sol.translateNum(11) << endl;
        cout << sol.translateNum(12258) << endl;
        cout << sol.translateNum(506) << endl;
    }
    return 0;
}
