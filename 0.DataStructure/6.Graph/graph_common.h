//
// Created by raven on 9/20/20.
//

#ifndef MYLEETCODE_GRAPH_COMMON_H
#define MYLEETCODE_GRAPH_COMMON_H
#include <vector>
#include <string>
using namespace std;

class graph_common {
public:
  static vector<vector<int>> create_link_graph(const string &path);
  static void print_link_graph(const vector<vector<int>> &graph);

  static vector<vector<int>> create_graph(const string &path);
  static void print_graph(const vector<vector<int>> &graph);
};


#endif //MYLEETCODE_GRAPH_COMMON_H
