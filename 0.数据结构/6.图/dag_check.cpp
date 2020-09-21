//
// Created by raven on 9/21/20.
// 有向无环图的检测
// 给定一个有向图，检测其中是否存在环, 存在几个环
// 和无向图的检测方法类似，通过dfs检测回边（即访问到已访问过的点），若设从u访问到v，(u,v)构成回边，则只需检测
// v和u是否属于同一个遍历子树，若是同一个子树，则形成环，否则不是环。
//
#include<vector>
#include<iostream>
#include <fstream>

#include "graph_common.h"


using namespace std;

class dag_checker {
public:
	int circle_check(const vector<vector<int>>& link_graph)
	{
		visited.reserve(link_graph.size());
		parent.reserve(link_graph.size());
		fill(visited.begin(), visited.end(), false);
		fill(parent.begin(), parent.end(), -1);

		/* 开始dfs */
		visited[root_node] = true;
		parent[root_node] = -1;
		for (auto connected : link_graph[root_node]) {
			_circle_check(link_graph, root_node, connected);
		}
		return circle_counter;
	}
private:
	void _circle_check(const vector<vector<int>>& link_graph, int from_node, int to_node) {
		int cur_node = to_node;
		if (!visited[cur_node]) {
			visited[cur_node] = true;
			parent[cur_node] = from_node;
			for (auto connected_node : link_graph[cur_node]) {
				if (connected_node == -1) continue;
				_circle_check(link_graph, cur_node, connected_node);
			}
		}
		else {  /* 回边，检测 to_node 是否在 from_node 所在的访问树上 */
			int temp_node = from_node;
			while (temp_node != root_node && temp_node != to_node) {
				temp_node = parent[temp_node];
			}
			if (temp_node == to_node) {
				/* 在同一个子树上，形成回边 */
				cout << "circle exist\n";
				circle_counter++;
			}
		}
	}

private:
	vector<bool> visited;
	vector<int> parent;

	int root_node = 0;
	int circle_counter = 0;


};


int main() {
	vector<vector<int>> &&link_graph = graph_common::create_link_graph("/home/raven/Projects/clion/MyLeetCode/0.数据结构/6.图/dag_check_input2.txt");
	graph_common::print_link_graph(link_graph);

	dag_checker dagChecker;
	int circle_counter = dagChecker.circle_check(link_graph);
	cout << "circle number:"<< circle_counter<<"\n";
	return 0;
}
