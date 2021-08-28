#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  // input nums
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    nums[i] = tmp;
  }

  sort(nums.begin(), nums.end());
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += std::abs(nums[i - 1] - i);
  }
  cout << cnt;
  return 0;
}