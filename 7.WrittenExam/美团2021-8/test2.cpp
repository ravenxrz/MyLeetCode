//
// Created by Raven on 2021/8/28.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int n;
  cin >> n; // no use
  cin >> str;
  if (n == 0)
    return 0;
  vector<int> dp(n, 0);
  dp[0] = str[0] == 'E' ? 1 : 0;
  int max_diff = dp[0];
  for (int i = 1; i < n; i++) {
    int val = str[i] == 'E' ? 1 : -1;
    dp[i] = max({0, val, dp[i - 1] + val});
    max_diff = max(max_diff, dp[i]);
  }
  cout << max_diff ;
  return 0;
}
