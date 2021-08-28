#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    if (N == 0) {
      cout << 0 << endl;
      continue;
    }
    vector<int> num(N, 0);
    vector<int> max_value(N, 0);
    vector<int> min_value(N, 0);
    int sum = 0;
    for (int j = 0; j < N; j++) {
      cin >> num[j];
      sum += num[j];
    }
    // calc dp array
    max_value[0] = num[0];
    min_value[0] = min(0, num[0]);
    for (int j = 1; j < N; j++) {
      max_value[j] = max(num[j], max_value[j - 1] + num[j]);
      min_value[j] = min({0, num[j], min_value[j - 1] + num[j]});
    }
    int tmax = *max_element(max_value.begin(), max_value.end());
    int tmin = *min_element(min_value.begin(), min_value.end());
    cout << (tmax > sum - tmin ? tmax : sum - tmin) << endl;
  }

  return 0;
}