//
// Created by raven on 5/11/21.
//











// DFS 解法，不太好
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int ig_1, ig_2; // The node number that needs to be ignored
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    // Build graph from the edges
    unordered_map<int, vector<int>> graph;
    int num = 0;
    for (const auto &edge : edges) {
      if (graph.count(edge[0]) == 0) {
        graph[edge[0]] = {edge[1]};
        num++;
      } else {
        graph[edge[0]].push_back(edge[1]);
      }
      if (graph.count(edge[1]) == 0) {
        graph[edge[1]] = {edge[0]};
        num++;
      } else {
        graph[edge[1]].push_back(edge[0]);
      }
    }
    vector<bool> visit_origin(num + 1, false);
    // Try to remove edge in reverse order, and use dfs to check whether it's
    // fully traversed or not
    for (auto it = edges.rbegin(); it != edges.rend(); it++) {
      ig_1 = it->at(0);
      ig_2 = it->at(1);
      vector<bool> visit(visit_origin.begin(), visit_origin.end());
      visit[1] = true;
      int count = 1;
      dfs(graph, visit, count, 1);
      if (count == num)
        return {ig_1, ig_2};
    }
    return {};
  }

private:
  bool isIgnoringEdge(int a, int b) const {
    assert(ig_1 < ig_2);
    if (a > b)
      swap(a, b);
    return ig_1 == a && ig_2 == b;
  }
  
  void dfs(const unordered_map<int, vector<int>> &graph, vector<bool> &visit,
           int &count, int idx) {
    for (int next : graph.at(idx)) {
      if (!visit[next] && !isIgnoringEdge(idx, next)) {
        visit[next] = true;
        ++count;
        dfs(graph, visit, count, next);
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  for (auto val : sol.findRedundantConnection(edges)) {
    cout << val << ' ';
  }
  cout << endl;
  return 0;
}
