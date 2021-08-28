#include <bits/stdc++.h>
using namespace std;

vector<unordered_map<int, int>> color;
vector<vector<int>> tree;
vector<unordered_map<int, bool>> color_set;
vector<bool> visit;

int calc(int node_id, int color_id) {
  if (color_set[node_id][color_id]) {
    return color[node_id][color_id];
  }
  int sum = 0;
  for (auto &connected_node : tree[node_id]) {
    if (!visit[connected_node]) {
      visit[connected_node] = true;
      sum += calc(connected_node, color_id);
    }
  }
  color[node_id][color_id] += sum;
  color_set[node_id][color_id] = true;
  return color[node_id][color_id];
}

int main() {
  int n;
  cin >> n;
  tree.resize(n + 1, vector<int>());
  color_set.resize(n + 1, unordered_map<int, bool>());
  // Build tree
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  // cut tree

  set<int> cset;
  color.resize(n + 1, unordered_map<int, int>());
  // init color
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    color[i][t] = 1;
    cset.insert(t);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int try_node;
    cin >> try_node;
    int max_num = 0;
    int max_color_id = -1;
    for (auto color_tmp : cset) {
      visit.clear();
      visit.resize(n + 1, false);
      visit[1] = true;
      int tmp_value = calc(try_node, color_tmp);
      if (max_num < tmp_value) {
        max_num = tmp_value;
        max_color_id = color_tmp;
      }
    }
    cout << max_color_id << '\n';
  }

  return 0;
}
