/**
 * aoe关键路径求解
 * 图采用邻接链表表示
 */
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include "graph_common.h"

using namespace std;

/**
 * @brief 表示一个活动
 */
class activity {
public:
	activity(int time_cost, int src, int dest, int e, int l)
		: time_cost(time_cost), src(src), dest(dest), e(e), l(l) {}

	int time_cost; /* 耗时 */
	int src;       /* 源点 */
	int dest;      /*  终点*/
	int e;         /* 最早开始时间 */
	int l;         /* 最晚开始时间 */
};

class event_node {
public:
	event_node(int ve, int vl)
		: ve(ve),
		vl(vl)
	{
	}

	int ve; /* 事件最早开始时间 */
	int vl; /* 事件最晚开始时间*/
};

static vector<event_node> nodes;
static vector<activity> activities;
static vector<event_node> event_nodes;
static void topo_calc(const vector<vector<int>>& graph)
{
	nodes.reserve(graph.size());
	nodes.clear();
//	event_nodes.reserve(graph.size());
//	fill(event_nodes.begin(), event_nodes.end(), event_node(0, 0x7fffffff));
    /* 这里如果采用reserve，回报错，目前原因未知 */
    for(int i = 0;i<graph.size();i++){
        event_nodes.push_back(event_node(0,0x7fffffff));
    }

	stack<int> sk1;
	stack<int> reverse_topo_sk; /* 逆拓扑排序 */
	vector<int> indegree(graph.size(), 0);
	vector<bool> visited(graph.size(), false);

	/* 初始化入度数组 */
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			if (graph[i][j] != -1)
			{
				indegree[j]++;
			}
		}
	}

	/* 拓扑排序，求事件最早开始时间*/
	sk1.push(0);
	visited[0] = true;
	while (!sk1.empty())
	{
		int cur_node = sk1.top();
		sk1.pop();
		reverse_topo_sk.push(cur_node);

		/*
		 * 1.与 cur_node 连接的node，indegree-1
		 * 2.更新事件节点的最早开始时间
		 */
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[cur_node][i] != -1)
			{
				indegree[i]--;
				event_nodes[i].ve = max(event_nodes[i].ve, graph[cur_node][i] + event_nodes[cur_node].ve);
			}
		}

		/* check indegree node = 0 */
		for (int i = 0; i < indegree.size(); ++i)
		{
			if (!visited[i] && indegree[i] == 0)
			{
				visited[i] = true;
				sk1.push(i);
			}
		}
	}
	if (reverse_topo_sk.size() != graph.size())
	{
		cerr << "circle exit\n";
		exit(-1);
	}
	cout << "事件的最早开始时间:\n";
	for (const auto& event_node : event_nodes)
	{
		cout << event_node.ve << " ";
	}
    cout << "\n";

	/* 逆拓扑排序 */
	int max_value = -1;
	for_each(event_nodes.begin(), event_nodes.end(), [&](const event_node& node)
		{
			max_value = max(max_value, node.ve);
		});
	for_each(event_nodes.begin(), event_nodes.end(), [&](event_node& node)
		{
			node.vl = max_value;
		});

	while (!reverse_topo_sk.empty())
	{
		int cur_node = reverse_topo_sk.top();
		reverse_topo_sk.pop();

		/**
		 * 更新event_node的最迟开始时间
		 */
		for (int j = 0; j < graph.size(); j++)
		{
			if (graph[j][cur_node] != -1)
			{
				event_nodes[j].vl = min(event_nodes[j].vl, event_nodes[cur_node].vl - graph[j][cur_node]);
			}
		}
	}
	cout << "事件的最晚开始时间:\n";
	for (const auto& event_node : event_nodes)
	{
		cout << event_node.vl << " ";
	}
	cout << "\n";

}

void activity_calc(const vector<vector<int>>& graph)
{
	queue<int> q;

	for(int i = 0;i<graph.size();i++){
	    for(int j = 0;j<graph.size();j++){
            if (graph[i][j] != -1)
            {
                activities.emplace_back(activity(
                        graph[i][j], i, j,
                        event_nodes[i].ve,
                        event_nodes[j].vl - graph[i][j]));
            }
	    }
	}
}


void print_key_node()
{
	cout << "key path:\n";
	for(auto act : activities)
	{
		if(act.e == act.l)
		{
			cout << act.src+1 << "--" << act.dest+1 << "\n";
		}
	}
}


int main()
{
	/* init graph */
	vector<vector<int>>&& graph = graph_common::create_graph(
		"/home/raven/Projects/Clion/MyLeetCode/0.数据结构/6.图/aoe_key_path_input.txt");
	graph_common::print_graph(graph);

	/* 计算事件节点的最早和最晚开始间 */
	topo_calc(graph);

	/* 生成活动的最早和最晚开始时间 */
	activity_calc(graph);

	/* 打印 */
	print_key_node();
	
	return 0;
}

