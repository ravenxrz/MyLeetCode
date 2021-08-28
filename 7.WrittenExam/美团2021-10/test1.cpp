#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  // input
  cin >> n >> x >> y;
  vector<int> score(n, 0);

  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    score[i] = tmp;
  }

  sort(score.begin(), score.end());
  for (int k = x; k <= y; k++) {
    int tmp = n - k;
    if (tmp < x || tmp > y)
      continue;
    // 执行计算
    cout << score[k-1];
    return 0;
  }
  
  cout << -1;
  return 0;
}