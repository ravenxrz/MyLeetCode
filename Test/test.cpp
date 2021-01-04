//
// Created by a2855 on 2021/1/4.
//
#include <iostream>
#include <vector>

using namespace std;

#define INF 100000

int main()
{
    vector<vector<int>> graph = {
            {0, INF, 3,   INF},
            {2,   0, INF, INF},
            {INF, 7, 0,   1},
            {6, INF, INF, 0},
    };
    
    // floyd
    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    // print
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
           cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}

