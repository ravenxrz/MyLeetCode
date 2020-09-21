/**
 * Created by raven on 2020/9/18.
 * prim 算法求解最小生成树
 * 特点：只和节点有关，时间复杂度为O(n^2)，适合求边稠密的图
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;


#define MAX_VALUE 0x7fffffff

vector<vector<int>> create_graph(const string &path) noexcept(false)
{
    int n;
    ifstream fin(path);
    if(!fin.is_open()) throw runtime_error("graph input file doesn't exit");
    fin >> n;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            fin>>graph[i][j];
            graph[i][j] = graph[i][j] == 0 ? INFINITY : graph[i][j];
        }
    }
    return graph;
}

void print_graph(const vector<vector<int>> &graph)
{
    for(int i = 0;i<graph.size();i++){
        for(int j = 0;j<graph.size();j++){
            cout << graph[i][j]<<" ";
        }
        cout << endl;
    }
}

/**
 * 用bfs检查graph是否是连通的
 * @param graph
 */
bool check(const vector<vector<int>> &graph)
{
    bool* visit = new bool[graph.size()];
    queue<int> q;
    int cur = 0;

    visit[cur] = true;
    q.push(cur);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i = 0;i<graph.size();i++){
            if(graph[cur][i] != 0 && !visit[i]){
                visit[i]  = true;
                q.push(i);
            }
        }
    }

    /* visit是否全为true */
    for(int i = 0;i<graph.size();i++){
        if(!visit[i]) return false;
    }

    return true;
}


void prim(const vector<vector<int>> &graph)
{
    vector<int> added_node;
    vector<int> remain_node;
    const int n = graph.size();
    int total_len = 0;

    /* 初始化remain_node */
    for(int i = 0;i<n;i++){
        remain_node.push_back(i);
    }

    /* 初始化added_node */
    int cur = 0;
    added_node.push_back(cur);
    remain_node.erase(find(remain_node.begin(),remain_node.end(),cur));
    cout << "start node:" << cur+1 << "\n";

    while(!remain_node.empty()){
        int min_node = remain_node.front();
        int min_value = MAX_VALUE;
        int min_connect_node = -1;

        for(const auto &from_node : remain_node){
            for(const auto &to_node : added_node){
                if(min_value > graph[from_node][to_node]){
                    min_value = graph[from_node][to_node];
                    min_node = from_node;
                    min_connect_node = to_node;
                }
            }
        }

        cout << "add node:" << min_node+1 << " (" <<min_node+1 << "," << min_connect_node+1 << ")"  " edge length:" << min_value << "\n";
        remain_node.erase(find(remain_node.begin(),remain_node.end(),min_node));
        added_node.push_back(min_node);
        total_len+=min_value;
    }
    cout << "total length:" << total_len <<"\n";
}

int main()
{
    vector<vector<int>> graph = create_graph("/home/raven/Projects/clion/MyLeetCode/0.DataStructure/6.Graph/min_span_tree_input.txt");
    if(!check(graph)){
        cerr << "graph 不是连通图，无法生成最小生成树\n";
        return -1;
    }

    prim(graph);
    return 0;
}

