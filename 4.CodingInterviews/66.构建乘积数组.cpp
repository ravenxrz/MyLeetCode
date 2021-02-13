#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int> &a)
    {
        vector<int> b(a.size(), 1);
        // 计算上三角
        int tmp = 1;
        for (int i = a.size() - 1; i > 0; i--) {
            tmp *= a[i - 1];
            b[i - 1] = tmp;
        }
        // 计算下三角
        tmp = 1;
        for (int i = 1; i <= a.size() - 1; i++) {
            tmp *= a[i - 1];
            b[i] *= tmp;
        }
        return b;
    }
};

