#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> tree;

void dfs(const vector<unordered_set<int>> &tree, const vector<int> &color,
         int node, map<int, int> &ans) {
  ans[color[node]]++;
  for (auto connect : tree[node]) {
    dfs(tree, color, connect, ans);
  }
}
void fix_tree(int cur) {
  for (const auto &connect : tree[cur]) {
    tree[connect].erase(cur);
    fix_tree(connect);
  }
}

int main() {
  int n;
  cin >> n;
  tree.resize(n + 1, unordered_set<int>());
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    tree[x].insert(y);
    tree[y].insert(x);
  }
  
  // Fix tree
  fix_tree(1);
  
  vector<int> color;
  color.push_back(-1);
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    color.push_back(c);
  }
  
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    map<int, int> ans;
    dfs(tree, color, t, ans);
    int max_value = 0;
    int target_color = -1;
    for (const auto &kv : ans) {
      if (kv.second > max_value) {
        max_value = kv.second;
        target_color = kv.first;
      }
    }
    cout << target_color << '\n';
  }
  
  return 0;
}
