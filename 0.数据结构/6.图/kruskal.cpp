/**
 * Created by raven on 2020/9/20.
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
#include "union_find_set.cpp"

using namespace std;


vector<vector<int>> create_graph(const string& path) noexcept(false) {
	int n;
	ifstream fin(path);
	if (!fin.is_open()) throw runtime_error("graph input file doesn't exit");
	fin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> graph[i][j];
		}
	}
	return graph;
}

void print_graph(const vector<vector<int>>& graph) {
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

/**
 * 用bfs检查graph是否是连通的
 * @param graph
 */
bool check(const vector<vector<int>>& graph) {
	bool* visit = new bool[graph.size()];
	queue<int> q;
	int cur = 0;

	visit[cur] = true;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < graph.size(); i++) {
			if (graph[cur][i] != 0 && !visit[i]) {
				visit[i] = true;
				q.push(i);
			}
		}
	}

	/* visit是否全为true */
	for (int i = 0; i < graph.size(); i++) {
		if (!visit[i]) return false;
	}

	delete[] visit;
	return true;
}


void kruskal(const vector<vector<int>>& graph) {
	struct edge {
		int start;
		int end;
		int weight;

		edge(int start, int anEnd, int weight) : start(start), end(anEnd), weight(weight) {}

		bool operator<(const edge& other) const {
			return this->weight - other.weight < 0;
		}
	};

	/* 构造边 */
	const int node_num = graph.size();
	vector<edge> edges;
	for (int i = 0; i < node_num; i++) {
		for (int j = 0; j < node_num; j++) {  /* 为了考虑有向图,所以无向图就加入两条边 */
			if (graph[i][j] != 0) {
				edges.emplace_back(i, j, graph[i][j]);
			}
		}
	}
	sort(edges.begin(), edges.end());

	/* 构造并查集:（可以考虑只用数组来做) */
	union_find_set ufs(node_num);

	/* kruskal */
	int added_edge_count = 0;
	int offset = 0;
	while (added_edge_count != node_num - 1) {
		edge& cur_edge = edges[offset++];
		if (ufs.is_same_set(cur_edge.start, cur_edge.end)) {
			continue;
		}
		else {
			ufs.merge(cur_edge.start, cur_edge.end);
		}
		cout << "add " << cur_edge.start + 1 << "--" << cur_edge.end + 1 << " :" << cur_edge.weight << "\n";
		added_edge_count++;
	}

}


int main() {
	vector<vector<int>> graph = create_graph(
		"E:\\MyLeetCode\\0.数据结构\\6.图\\min_span_tree_input.txt");
	if (!check(graph)) {
		cerr << "graph 不是连通图，无法生成最小生成树\n";
		return -1;
	}
	kruskal(graph);
	return 0;
}