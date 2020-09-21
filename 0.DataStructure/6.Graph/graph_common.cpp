//
// Created by raven on 9/20/20.
//

#include "graph_common.h"
#include <fstream>
#include <sstream>
#include <iostream>

#define INF 0x7fffffff

vector<vector<int>> graph_common::create_link_graph(const string &path) {
    ifstream fin(path);
    if (!fin.is_open()) {
        cerr << "input file does not exit\n";
        exit(-1);
    }

    int node_num;
    string line;
    fin >> node_num;
    vector<vector<int>> link_graph(node_num, vector<int>());

    while (getline(fin, line)) {
        unsigned long i = line.find_first_of(':');
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

void graph_common::print_link_graph(const vector<vector<int>> &graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " connect to ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> graph_common::create_graph(const string &path) {
    ifstream fin(path);
    if (!fin.is_open()){
        cerr<<"input file not exit\n";
        exit(-1);
    }

    int n;
    fin >> n;
    /* input graph */
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> graph[i][j];
            if (graph[i][j] == 0) graph[i][j] = -1;
        }
    }
    fin.close();
    return graph;

}

void graph_common::print_graph(const vector<vector<int>> &graph) {
    for(int i = 0;i<graph.size();i++){
        for(int j = 0;j<graph[i].size();j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

#undef INF


