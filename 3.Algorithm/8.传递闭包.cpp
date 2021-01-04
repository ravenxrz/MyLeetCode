#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<bool>> graph{
            {0, 1, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 0, 0},
            {1, 0, 1, 0}
    };
    
    // warshall
    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                graph[i][j] = (graph[i][k] & graph[k][j]) | graph[i][j];
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
    cout << endl;
    return 0;
}
