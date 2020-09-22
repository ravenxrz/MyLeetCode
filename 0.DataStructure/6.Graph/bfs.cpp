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

void bfs(const vector<vector<int>> &graph)
{
    queue<int> q;
    bool *visit = new bool[graph.size()];
    memset(visit,false,sizeof(bool)*graph.size());

    for(int i = 0;i<graph.size();i++){
        if(!visit[i]){
            visit[i] = true;
            q.push(i);
            cout << "visit "<< i+1 << "\n";

            /* bfs core code */
            while(!q.empty()){
                int cur = q.front();
                int j;
                for(j = 0;j<graph.size();j++){
                    if(!visit[j] && graph[cur][j] == 1){
                        visit[j] = true;
                        cout << "visit "<< j+1 << "\n";
                        q.push(j);
                    }
                }
                if(j == graph.size()){
                    q.pop();
                }
            }
        }
    }
    delete[]visit;
}

int main()
{
    vector<vector<int>> &&graph = graph_common::create_graph("E:\\MyLeetCode\\0.DataStructure\\6.Graph\\graph_input.txt");
    graph_common::print_graph(graph);
    
    bfs(graph);
    return 0;
}

