#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    
    typedef unsigned long long ull;
    ull num = 0;
    int i = 0;
    
    for (; i < n - 1; i += 2) {
        num += (arr[i] - arr[i + 1]);
    }
    if (i + 1 >= n) {
        num += arr[i];
    } else {
        num += (arr[i] - arr[i + 1]);
    }
    cout << num;
    return 0;
}
