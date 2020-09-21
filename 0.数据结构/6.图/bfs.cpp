/**
 * Created by raven on 2020/9/16.
 */
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <queue>
using namespace std;

static int n;


void bfs(const vector<vector<int>>& graph)
{
	queue<int> q;
	bool* visit = new bool[graph.size()];
	memset(visit, false, sizeof(bool) * n);

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			q.push(i);
			cout << "visit " << i + 1 << "\n";

			/* dfs core code */
			while (!q.empty()) {
				int cur = q.front();
				int j;
				for (j = 0; j < n; j++) {
					if (!visit[j] && graph[cur][j] == 1) {
						visit[j] = true;
						cout << "visit " << j + 1 << "\n";
						q.push(j);
					}
				}
				if (j == n) {
					q.pop();
				}
			}
		}
	}

	delete[]visit;
}

int main()
{
	const string path("/home/raven/Projects/Clion/MyLeetCode/0.数据结构/6.图/graph_input.txt");
	ifstream fin(path);
	if (!fin.is_open()) return -1;

	fin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> graph[i][j];
		}
	}

	/* check 是否是无向图 */
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (graph[i][j] != graph[j][i]) {
				cerr << "graph input error\n";
				return -1;
			}
		}
	}

	/* print graph */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	bfs(graph);
	return 0;
}

