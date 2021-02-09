#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countDigitOne(int n)
    {
        int digital_nums = getDigitalNum(n);
        g_arr.resize(digital_nums + 1);
        // 设置g arr
        setGArr(n);
    }


private:
    // 取得n的位数
    int getDigitalNum(int n)
    {
        int cnt = 0;
        while (n) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }
    
    int setGArr(int i)
    {
        if (i == 0) {
            g_arr[i] = 0;
            return 0;
        }
        g_arr[i] = setGArr(i - 1) + pow(10, i - 1);
        return g_arr[i];
    }

private:
    vector<int> g_arr;          // g_arr[i] 代表的是0-999xx99 （i个9）一共有多少个1
};