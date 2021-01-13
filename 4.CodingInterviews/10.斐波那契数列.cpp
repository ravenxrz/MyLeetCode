#include <iostream>

using namespace std;

typedef unsigned long long f_t;

int main()
{
    int n = 0;
    cin >> n;
    if (n < 0) return -1;
    if (n == 0) {
        cout << 0 << endl;
    } else if (n == 1) {
        cout << 1 << endl;
    } else {
        f_t a = 0;
        f_t b = 1;
        f_t ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        cout << ans;
    }
    return 0;
}
