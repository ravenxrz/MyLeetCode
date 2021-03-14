#include <bits/stdc++.h>

using namespace std;

/**
 *
 * @param start  第一天吃是多少
 * @param n 一共有天
 * @return
 */
int sum(int start, int n)
{
    int day = 1;
    int base = start;
    int ans = 0;
    for (; day <= n; day++) {
        ans += base;
        base = (base + 1) >> 1;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // find right bound
    int left = 1;
    int right = m;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int base = sum(mid, n);
        if (base == m) {
            left = mid + 1;
        } else if (base < m) {
            left = mid + 1;
        } else if (base > m) {
            right = mid - 1;
        }
    }
    if (sum(right, n) > m) right--;
    cout << right;
    return 0;
}
