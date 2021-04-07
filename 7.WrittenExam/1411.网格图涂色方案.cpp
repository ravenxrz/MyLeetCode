
#include <iostream>

using namespace std;


class Solution {
public:
    int numOfWays(int n)
    {
        if (n == 1) return 12;
        typedef long long ll;
        ll a0 = 6;
        ll b0 = 6;
        ll a1 = 0;
        ll b1 = 0;
        static ll mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            a1 = (2 * a0 + 2 * b0) % mod;
            b1 = (2 * a0 + 3 * b0) % mod;
            a0 = a1;
            b0 = b1;
        }
        return (a0 + b0) % mod;
    }
};

int main()
{
    Solution sol;
    {
        cout << sol.numOfWays(2) << endl;
    }
    return 0;
}
