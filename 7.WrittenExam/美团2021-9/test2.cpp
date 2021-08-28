#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> score(n, 0);
  for (int i = 0; i < n; i++) {
    scanf("%d", &score[i]);
  }
  sort(score.begin(), score.end());

  int target = score[n - x];
  auto  iter = std::lower_bound(score.begin(), score.end(), target);
  if(target != 0){
    cout <<  score.end() - iter ;
  }else{
    while(iter != score.end() && *iter == 0) {
      iter++;
    }
    cout << score.end() - iter;
  }
  return 0;
}
