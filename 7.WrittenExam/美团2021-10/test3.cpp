//
// Created by Raven on 2021/8/28.
//
#include <bits/stdc++.h>
using namespace std;

void handle_one() {
  int N;
  string tables;
  int num;
  string gender;
  //  scanf("%d%s%d%s",&N)
  cin >> N >> tables >> num >> gender;
  unordered_map<char, set<int>> umap;
  for (int i = 0; i < tables.size(); i++) {
    umap[tables[i]].insert(i);
  }

  for (auto g : gender) {
    if (g == 'F') {
      if (!umap['0'].empty()) {
        cout << *umap['0'].begin() + 1 << '\n';
        umap['1'].insert(*umap['0'].begin());
        umap['0'].erase(umap['0'].begin());
      } else {
        cout << *umap['1'].begin() + 1 << '\n';
        umap['2'].insert(*umap['1'].begin());
        umap['1'].erase(umap['1'].begin());
      }
    } else if (g == 'M') {
      if (!umap['1'].empty()) {
        cout << *umap['1'].begin() + 1 << '\n';
        umap['2'].insert(*umap['1'].begin());
        umap['1'].erase(umap['1'].begin());
      } else {
        cout << *umap['0'].begin() + 1 << '\n';
        umap['1'].insert(*umap['0'].begin());
        umap['0'].erase(umap['0'].begin());
      }
    }
  }

  //  for (auto g : gender) {
  //    if (g == 'M') {
  //      bool found = false;
  //      int first_zero = -1;
  //      for (int i = 0; i < tables.size(); i++) {
  //        if (tables[i] == '2')
  //          continue;
  //        if (tables[i] == '1') {
  //          found = true;
  //          tables[i] = '2';
  //          cout << i + 1 << '\n';
  //          break;
  //        }
  //        if (first_zero == -1 && tables[i] == '0') {
  //          first_zero = i;
  //        }
  //      }
  //      if (!found) {
  //        assert(first_zero != -1);
  //        tables[first_zero] = '1';
  //        cout << first_zero + 1 << '\n';
  //      }
  //    } else if (g == 'F') {
  //      bool found = false;
  //      int first_one = -1;
  //      for (int i = 0; i < tables.size(); i++) {
  //        if (tables[i] == '2')
  //          continue;
  //        if (tables[i] == '0') {
  //          found = true;
  //          tables[i] = '1';
  //          cout << i + 1 << '\n';
  //          break;
  //        }
  //        if (first_one == -1 && tables[i] == '1') {
  //          first_one = i;
  //        }
  //      }
  //      if (!found) {
  //        assert(first_one != -1);
  //        tables[first_one] = '2';
  //        cout << first_one + 1 << '\n';
  //      }
  //    }
  //  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    handle_one();
  }
  return 0;
}
