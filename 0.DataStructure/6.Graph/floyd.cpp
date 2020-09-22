/**
 * Created by a2855 on 2020/9/22.
 * floyd最短路径算法，O(n^3)
 */
#include "graph_common.h"
#include <iostream>
#include <vector>

using namespace std;

#define INF 0x7ffff

void prepare(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] == -1) graph[i][j] = INF;
        }
    }
}

void floyd(const vector<vector<int>> &graph)
{
    vector<vector<int>> min_dist(graph);
    vector<vector<int>> path(graph.size(), vector<int>(graph.size(), -1));
    
    /* 初始化path */
    for (int i = 0; i < path.size(); i++) {
        for (int j = 0; j < path.size(); j++) {
            if (i == j || min_dist[i][j] == INF) path[i][j] = -1;
            else path[i][j] = j;
        }
    }
    
    for (int k = 0; k < min_dist.size(); k++) {
        for (int i = 0; i < min_dist.size(); i++) {
            for (int j = 0; j < min_dist.size(); j++) {
                if (min_dist[i][j] > min_dist[i][k] + min_dist[k][j]) {
                    min_dist[i][j] = min_dist[i][k] + min_dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    
    /* print answer */
    cout << "path value matrix:\n";
    for (int i = 0; i < min_dist.size(); i++) {
        for (int j = 0; j < min_dist.size(); j++) {
            cout << min_dist[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "path:\n";
    for (int i = 0; i < min_dist.size(); i++) {
        for (int j = 0; j < min_dist.size(); j++) {
            cout << i << "-->" << j << ":" << i;
            int cur_point = path[i][j];
            while (cur_point != -1 && cur_point != j) {
                cout << "," << cur_point;
                cur_point = path[cur_point][j];
            }
            cout << "," << cur_point << "\n";
        }
    }
}

int main()
{
    vector<vector<int>> &&graph = graph_common::create_graph(
            "E:\\MyLeetCode\\0.DataStructure\\6.Graph\\floyd_input.txt");
    graph_common::print_graph(graph);
    prepare(graph);
    floyd(graph);
    return 0;
}
