/**
 *
 * dijkstra 求最短路径 O(n^2)的复杂度
 */
#include "graph_common.h"
#include <iostream>
#include <vector>
using namespace std;

#define INF 0x7fffff    // 只取3个字节
/**
 * 预处理，将graph中的不可连接点 -1 转为 inf
 * @param graph
 */
void prepare(vector<vector<int>> &graph)
{
    for(int i = 0;i<graph.size();i++){
        for(int j = 0;j<graph.size();j++){
            if(graph[i][j] == -1) graph[i][j] = INF;
        }
    }
}

void dijkstra(const vector<vector<int>> &graph, int src)
{
    /* 保存最短路径长度 */
    vector<int> D(graph.size());
    /* 保存访问路径 */
    vector<int> path(graph.size());
    /* 初始化 */
    for(int i = 0;i<D.size();i++){
        D[i] = graph[src][i];
        if(D[i] != INF){
            path[i] = src;
        }else{
            path[i] = -1;
        }
    }
    
    
    /* D 算法 */
    vector<bool> visited(graph.size());
    int added_counter = 1;
    visited[src] = true;
    while(added_counter != graph.size()){
        int cur_point = -1;
        int min_value = INF;
        /* 确定当前最短点 */
        for(int i = 0;i<D.size();i++){
            if(!visited[i] && min_value >= D[i]){
                min_value = D[i]; cur_point = i;
            }
        }
        visited[cur_point] = true;
        added_counter++;
        /* 根据当前点，更新其他点 */
        for(int i = 0;i<graph.size();i++){
            if(D[i] > graph[cur_point][i] + D[cur_point]){
                D[i] = graph[cur_point][i] + D[cur_point];
                path[i]  = cur_point;
            }
        }
    }
    
    /* print answer */

    cout << endl;
    /* print path */
    for(int i = 0;i<D.size();i++){
        int cur_point = i;
        if(cur_point == src || path[cur_point] == -1) continue;
        
        cout << " length " << D[cur_point] << " : ";
        cout << cur_point;
        while(cur_point != -1 && cur_point != 0){
            cur_point = path[cur_point];
            cout << "<--" << cur_point ;
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> &&graph = graph_common::create_graph("E:\\MyLeetCode\\0.DataStructure\\6.Graph\\dijjkstra_input.txt");
    graph_common::print_graph(graph);
    
    prepare(graph);
    dijkstra(graph,0);
    return 0;
}