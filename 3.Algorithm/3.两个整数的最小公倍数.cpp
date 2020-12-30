#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n)
{
    if (n == 0) {
        return m;
    }
    return gcd(n, m % n);
}

int lcm(int m, int n)
{
    return (m * n) / gcd(m, n);
}


int main()
{
    cout << lcm(10, 1);
    return 0;
}

