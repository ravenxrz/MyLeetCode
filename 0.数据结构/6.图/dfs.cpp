/**
 * Created by raven on 2020/9/16.
 * 邻接矩阵dfs
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include "graph_common.h"
#include "../common.h"

using namespace std;

static int n;  /* graph node num */

#define DEBUG

/* 递归版本 */
void dfs(int idx, const vector<vector<int>> &graph, bool *visit) {
    for (int i = 0; i < n; i++) {
        if (!visit[i] && graph[idx][i] == 1) {
            cout << "visit " << i +1 << "\n";
            visit[i] = true;
            dfs(i,graph,visit);
        }
    }

}

/* 非递归版本，辅助数据结构 */
class dfs_stack_item {
public:
    int cur_node;            /* 当前节点 */
    int connect_node;        /* 扫描到哪个边,扫描方向由 第1个node---第n个node */
    dfs_stack_item(int cur_node, int connect_node) : cur_node(cur_node), connect_node(connect_node) {}
};

void _dfs(const vector<vector<int>> &graph, bool *visit, int idx)
{
    stack<dfs_stack_item *> sk;
    dfs_stack_item *np;
    int i;
    sk.push(new dfs_stack_item(idx,0));

    while(!sk.empty()){
        np = sk.top();
        /* 继续dfs寻找 */
        for(i = np->connect_node;i<n;i++){
            if(!visit[i] && graph[np->cur_node][i] == 1){
                visit[i] = true;
                cout << "visit "<<i +1 <<"\n";
                np->connect_node = i;
                sk.push(new dfs_stack_item(i,0));
                break;
            }
        }

        if(i == n){  /* 没有相邻边，回退 */
            sk.pop();
        }
    }
}

int dfs_with_stack(const vector<vector<int>> &graph)
{
    bool *visit = new bool[graph.size()];

    /* init stack with first node */
    for(int i = 0;i<n;i++){
        if(!visit[i]){
            visit[i] = true;
            cout << "visit "<< i+1 <<"\n";
            _dfs(graph,visit,i);
        }
    }
    return 0;
}

int main() {

    /* input graph */
    vector<vector<int>> &&graph = graph_common::create_graph("/home/raven/Projects/clion/MyLeetCode/0.数据结构/6.图/graph_input.txt");

    /* print graph */
    graph_common::print_graph(graph);

    n = graph.size();
    /* 递归版本 */
    bool *visit = new bool[n];
    memset(visit,false,sizeof(bool)*n);
    visit[0] = true;
    cout << "visit " << 1 << "\n";
    dfs(0,graph,visit);
    delete[] visit; visit = nullptr;

    /* 非递归版本 */
    cout << "=======\n";
    dfs_with_stack(graph);

    return 0;
}
