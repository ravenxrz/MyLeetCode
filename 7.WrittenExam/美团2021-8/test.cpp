#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
//  vector<int> books(M + 1, 0);
//  vector<bool> lent(M + 1, false);
//  vector<bool> locks(N + 1, false);
    int books[10000];
    bool lent[10000];
    bool locks[10000];
    memset(books, 0, sizeof(books));
    memset(lent, 0, sizeof(lent));
    memset(locks, 0, sizeof(locks));

  int op1, op2, op3;
  while (Q--) {
    cin >> op1;
    if (op1 == 1) {
      cin >> op2 >> op3;
      if (lent[op2] || locks[op3] ||
          (books[op2] != 0 &&
           locks[books[op2]])) { // lent || 行已经上锁 || 已经放置，且上锁
        continue;
      }
      books[op2] = op3;
    } else {
      cin >> op2;
      if (op1 == 2) {
        locks[op2] = true;
      } else if (op1 == 3) {
        locks[op2] = false;
      } else if (op1 == 4) { // lent
        if (books[op2] == 0 || locks[books[op2]]) {
          cout << "-1" << endl;
          continue;
        }
        lent[op2] = true;
        cout << books[op2] << endl;
        books[op2] = 0;
      } else if (op1 == 5) {
        if (!lent[op2]) {
          continue;
        }
        lent[op2] = false;
      }
    }
  }
  return 0;
}
