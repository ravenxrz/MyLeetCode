/**
 * Created by raven on 2020/9/20.
 * 求解连通图的关键点
 * 书上讲解得不好
 * 讲解参考：https://www.cnblogs.com/nullzx/p/7968110.html
 * 输入： tarjan_input.txt 采用邻接链表表示
 */
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

void print_link_graph(const vector<vector<int>> &link_graph) {
    for (int i = 0; i < link_graph.size(); i++) {
        cout << i << " connect to ";
        for (int j = 0; j < link_graph[i].size(); j++) {
            cout << link_graph[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> create_link_graph() {
    const string path("/home/raven/Projects/Clion/MyLeetCode/0.数据结构/6.图/tarjan_input3.txt");
    ifstream fin(path);
    if (!fin.is_open()) exit(-1);

    int node_num;
    string line;
    fin >> node_num;
    vector<vector<int>> link_graph(node_num, vector<int>());

    while (getline(fin, line)) {
        size_t i = line.find_first_of(':');
        if (i == std::string::npos) continue;

        string num_str = line.substr(0, i); /* 序号 */
        string connect_node = line.substr(i + 1, line.size() - i);   /* 想连接的点 */
        stringstream sstream1(num_str);
        sstream1 >> i;
        stringstream sstream2(connect_node);

        /* 初始化与 i 相连的node */
        int temp;
        while (sstream2 >> temp) {
            link_graph[i].push_back(temp);
        }
    }

    return link_graph;
}

vector<bool> visited;
vector<int> dfn;         /*第一次访问到第idx个节点时的时间戳*/
vector<int> low;         /*第idx个节点及其子树能够回溯到的最小节点处的时间戳*/
vector<int> parent;      /*第idx个节点的父亲节点*/
set<int> joint_node;      /* 关节点 */

void dfs(const vector<vector<int>> &link_graph, int from_node, int to_node) {
    static int counter = 0;       /* 时间戳 */
    int cur_node = to_node;

    if (!visited[cur_node]) {     /* 深入到子树 */
        visited[cur_node] = true;
        dfn[cur_node] = ++counter;
        low[cur_node] = dfn[cur_node];
        parent[cur_node] = from_node;

        /* dfs from "cur_node" */
        for (auto connected_node: link_graph[cur_node]) {
            if (connected_node == parent[cur_node]) continue;    /* 去掉直接相邻parent回边 */

            dfs(link_graph, cur_node, connected_node);
            /* 从dfs回来后，已经求解到子树能够回溯到的最小节点 */
            if (low[connected_node] < dfn[cur_node] &&           /* 子树回边到的最小节点在本节点之上 */
                low[connected_node] != dfn[parent[cur_node]]) {  /* 保证子树回边到的最小节点不是本节点的parent节点 */
                low[cur_node] = min(low[cur_node],low[connected_node]);
            } else
                if (low[connected_node] > dfn[cur_node]) {
                joint_node.insert(cur_node);
            }
        }
    } else {          /* 回边 */
        if (cur_node != parent[from_node] && dfn[cur_node] < low[from_node]) {
            low[from_node] = dfn[cur_node];
        }
    }
}

int main() {
    /* create graph from the input file */
    vector<vector<int>> &&link_graph = create_link_graph();

    /* print result */
    print_link_graph(link_graph);

    /* initialize global vars */
    visited.resize(link_graph.size());
    dfn.reserve(link_graph.size());
    low.reserve(link_graph.size());
    parent.reserve(link_graph.size());

    /* tarjan algorithm */
    /* start from node 0 */
    visited[0] = true;
    dfn[0] = 0;
    low[0] = 0;
    parent[0] = -1;

    /* root node单独处理 */
    int child_num = 0;
    for (auto connected_node : link_graph[0]) {
        if(!visited[connected_node]){
            child_num++;
            dfs(link_graph, 0, connected_node);
        }
        if(child_num>=2){
            joint_node.insert(0);
        }
    }

    /* print answer */
    for(auto node : joint_node){
        cout << "joint node " << node << endl;
    }

    return 0;
}

