#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int findNthDigit(int n)
    {
        if (n < 10) {
            return n;
        }
        int start = 0, numPass = 0, digital = 1;
        getRange(n, start, numPass, digital);
        
        n = n - numPass;
        int step = n / digital;
        // 定位到最后这个数字
        int finalNum = start + step;
        int cnt = digital - n % digital - 1;
        // 在finalNum中查找第n位
        while (cnt) {
            finalNum /= 10;
            cnt--;
        }
        finalNum = finalNum % 10;
        return finalNum;
    }

private:
    /**
     * 处理n > 10 的情况
     * @param n
     * @param start 开始处理的区间段
     * @param numPass  已经走过了多少数字
     */
    void getRange(int n, int &start, int &numPass, int &digital)
    {
        long long base = 90;
        int cnt = 2;
        long long acc_sum = 10;
        while (acc_sum <= n) {
            acc_sum += base * cnt;
            cnt++;
            base *= 10;
        }
        // 多计算了一轮，去掉这一轮
        cnt--;
        base /= 10;
        start = ceil(pow(10, cnt - 1));
        numPass = (acc_sum - base * cnt);
        digital = cnt;
    }
};

int main()
{
    Solution sol;
    cout << sol.findNthDigit(1) << '\n';
    cout << sol.findNthDigit(10) << '\n';
    cout << sol.findNthDigit(11) << '\n';
    cout << sol.findNthDigit(12) << '\n';
    cout << sol.findNthDigit(13) << '\n';
    cout << sol.findNthDigit(14) << '\n';
    cout << sol.findNthDigit(15) << '\n';
    cout << sol.findNthDigit(2890) << '\n';
    return 0;
}
