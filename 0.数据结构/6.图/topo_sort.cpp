//
// Created by raven on 9/20/20.
// 拓扑排序方法1: 若确定给定的有向图为无环有向图(dag)，则拓扑排序为
// dfs出点的逆序
// dfs出点: dfs遍历过程中，若点v无法再继续前进，则v为出点
//
#include "dag_check.cpp"
#include <stack>
#include <cstring>

class topo_sorter1{
public:
    ~topo_sorter1(){
        delete v;
    }

    int topo_sort(const vector<vector<int>> &link_graph)
    {
        /* dag check */
        if(dagChecker.circle_check(link_graph) != 0){
            cerr<<"circle exit\n";
            exit( -1);
        }

        v = new bool[link_graph.size()];
        memset(v,0,sizeof(bool)*link_graph.size());
        for(int i = 0;i<link_graph.size();i++){
            if(!v[i]){
                v[i] = true;
                _topo_sort(link_graph,i);
            }
        }
        return 0;
    }

    void print_result(){
        /* print answer */
        while(!topo_stack.empty()){
            cout << topo_stack.top()+1 << " ";
            topo_stack.pop();
        }

    }
private:
     void _topo_sort(const vector<vector<int>> &link_graph,int cur_node)
    {
        for(auto connected_node : link_graph[cur_node]){
            if(connected_node == -1) continue;
            if(!v[connected_node]){
                v[connected_node] = true;
                _topo_sort(link_graph,connected_node);
            }
        }
        topo_stack.push(cur_node);
    }

private:
    dag_checker dagChecker;
    stack<int> topo_stack;
    bool *v;
};


class topo_sorter2{
public:
    int topo_sort(const vector<vector<int>> &link_graph){
        int indegree[link_graph.size()];
        bool visited[link_graph.size()];
        memset(indegree,0,sizeof(int)*link_graph.size());
        memset(visited,false,sizeof(bool)*link_graph.size());
        stack<int> sk;
        /* 初始化各点的入度 */
        for(int i = 0;i<link_graph.size();i++){
            for(auto connected_node: link_graph[i]) {
                indegree[connected_node]++;
            }
        }
        for(int i = 0;i<link_graph.size();i++){
            if(indegree[i] == 0){
                sk.push(i);
                visited[i] = true;
            }
        }

        int counter = 0;
        while(!sk.empty()){
            int cur_node = sk.top();
            sk.pop();
            result.push_back(cur_node);
            counter++;
            /* 减少入度 */
            for(auto connected_node : link_graph[cur_node]){
                indegree[connected_node]--;
            }
            /* 0入度入stack */
            for(int i = 0;i<link_graph.size();i++){
                if(indegree[i] ==  0 && !visited[i]){
                    sk.push(i);
                    visited[i] = true;
                }
            }
        }

        if(counter != link_graph.size()){
            cerr<< "circle exit\n";
            return -1;
        }
        return 0;
    }

    void print_result(){
        for(auto r : result){
            cout << r+1 << " " ;
        }
        cout << endl;
    }
private:
    vector<int> result;
};



int main()
{
    vector<vector<int>> &&link_graph = graph_common::create_link_graph("/home/raven/Projects/clion/MyLeetCode/0.数据结构/6.图/topo_sort_input.txt");
    graph_common::print_link_graph(link_graph);

    topo_sorter1 topoSorter1;
    topoSorter1.topo_sort(link_graph);
    topoSorter1.print_result();

    cout << endl;

    topo_sorter2 topoSorter2;
    topoSorter2.topo_sort(link_graph);
    topoSorter2.print_result();

    return 0;
}