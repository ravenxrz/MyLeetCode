/**
 * Created by raven on 2020/9/16.
 */
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "graph_common.h"
#include <queue>
using namespace std;

static int n = 0;


void bfs(const vector<vector<int>> &graph)
{
    queue<int> q;
    bool *visit = new bool[graph.size()];
    memset(visit,false,sizeof(bool)*n);

    for(int i = 0;i<n;i++){
        if(!visit[i]){
            visit[i] = true;
            q.push(i);
            cout << "visit "<< i+1 << "\n";

            /* dfs core code */
            while(!q.empty()){
                int cur = q.front();
                int j;
                for(j = 0;j<n;j++){
                    if(!visit[j] && graph[cur][j] == 1){
                        visit[j] = true;
                        cout << "visit "<< j+1 << "\n";
                        q.push(j);
                    }
                }
                if(j == n){
                    q.pop();
                }
            }
        }
    }

    delete[]visit;
}

int main()
{
    vector<vector<int>> &&graph = graph_common::create_graph("/home/raven/Projects/clion/MyLeetCode/0.DataStructure/6.Graph/graph_input.txt");
    graph_common::print_graph(graph);

    n = graph.size();
    /* check 是否是无向图 */
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(graph[i][j] != graph[j][i]){
                cerr << "graph input error\n";
                return -1;
            }
        }
    }

    /* print graph */
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    bfs(graph);
    return 0;
}

