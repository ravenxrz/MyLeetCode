#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;

  while (cin >> n ) {
    cin >> m >> a >> b;
    unordered_set<int> record;
    bool no = false;
    for (int i = 0; i < m; i++) {
      int cake;
      cin >> cake;
      if ((cake < a && cake < b) || (cake > a && cake > b)) {
        no = true;
      }
      if (cake == a)
        record.insert(a);
      if (cake == b)
        record.insert(b);
    }
    if(no){
      cout << "NO" << endl;
      continue;
    }
    if (n - m < 2 - record.size()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
