/**
 * 题目：输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数999
 */
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    void print_n_number(int n)
    {
        // bound check
        if (n <= 0) return;
        string num(n, '0');  // 初始化为全0
        dfs(num, 0);
    }

private:
    void dfs(string &num, int index)
    {
        if (index == num.size()) {
            print(num);
            return;
        }
        
        for (char i = '0'; i <= '9'; i++) {
            num[index] = i;
            dfs(num, index + 1);
        }
    }
    
    void print(const string &num)
    {
        // 只有一位单独处理
        if (num.size() == 1) {
            cout << num << '\n';
            return;
        }
        
        // 不是一位，去掉前导0
        int start = 0;
        for (; start < num.size(); start++) {
            if (num[start] != '0'){
                break;
            }
        }
        if (start != num.size()) {
            cout << num.substr(start, num.size() - start)  << '\n';
        }
    }
    
};

int main()
{
    Solution sol;
    {
        sol.print_n_number(0);
        cout << endl;
        sol.print_n_number(1);
        cout << endl;
        sol.print_n_number(2);
        cout << endl;
        sol.print_n_number(3);
        cout << endl;
        sol.print_n_number(4);
        cout << endl;
        
        sol.print_n_number(10);
        cout << endl;
    }
    return 0;
}
