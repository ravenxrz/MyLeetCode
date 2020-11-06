/**
 * aoe�ؼ�·�����
 * ͼ�����ڽӾ����ʾ
 */
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include "graph_common.h"

using namespace std;

/**
 * @brief ��ʾһ���
 */
class activity {
public:
    activity(int time_cost, int src, int dest, int e, int l)
            : time_cost(time_cost), src(src), dest(dest), e(e), l(l) {}
    
    int time_cost; /* ��ʱ */
    int src;       /* Դ�� */
    int dest;      /*  �յ�*/
    int e;         /* ���翪ʼʱ�� */
    int l;         /* ����ʼʱ�� */
};

class event_node {
public:
    event_node() =default;
    
    event_node(int ve, int vl)
            : ve(ve),
              vl(vl)
    {
    }
    
    int ve; /* �¼����翪ʼʱ�� */
    int vl; /* �¼�����ʼʱ��*/
};

static vector<activity> activities;
static vector<event_node> event_nodes;
static void topo_calc(const vector<vector<int>>& graph)
{
	event_nodes.resize(graph.size());
	fill(event_nodes.begin(), event_nodes.end(), event_node(0, 0x7fffffff));
    
    stack<int> sk1;
    stack<int> reverse_topo_sk; /* ���������� */
    vector<int> indegree(graph.size(), 0);
    vector<bool> visited(graph.size(), false);
    
    /* ��ʼ��������� */
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            if (graph[i][j] != -1)
            {
                indegree[j]++;
            }
        }
    }
    
    /* �����������¼����翪ʼʱ��*/
    sk1.push(0);
    visited[0] = true;
    while (!sk1.empty())
    {
        int cur_node = sk1.top();
        sk1.pop();
        reverse_topo_sk.push(cur_node);
        
        /*
         * 1.�� cur_node ���ӵ�node��indegree-1
         * 2.�����¼��ڵ�����翪ʼʱ��
         */
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[cur_node][i] != -1)
            {
                indegree[i]--;
                event_nodes[i].ve = max(event_nodes[i].ve, graph[cur_node][i] + event_nodes[cur_node].ve);
            }
        }
        
        /* check indegree node = 0 */
        for (int i = 0; i < indegree.size(); ++i)
        {
            if (!visited[i] && indegree[i] == 0)
            {
                visited[i] = true;
                sk1.push(i);
            }
        }
    }
    if (reverse_topo_sk.size() != graph.size())
    {
        cerr << "circle exit\n";
        exit(-1);
    }
    cout << "�¼������翪ʼʱ��:\n";
    for (const auto& event_node : event_nodes)
    {
        cout << event_node.ve << " ";
    }
    cout << "\n";
    
    /* ���������� */
    int max_value = -1;
    for_each(event_nodes.begin(), event_nodes.end(), [&](const event_node& node)
    {
        max_value = max(max_value, node.ve);
    });
    for_each(event_nodes.begin(), event_nodes.end(), [&](event_node& node)
    {
        node.vl = max_value;
    });
    
    while (!reverse_topo_sk.empty())
    {
        int cur_node = reverse_topo_sk.top();
        reverse_topo_sk.pop();
        
        /**
         * ����event_node����ٿ�ʼʱ��
         */
        for (int j = 0; j < graph.size(); j++)
        {
            if (graph[j][cur_node] != -1)
            {
                event_nodes[j].vl = min(event_nodes[j].vl, event_nodes[cur_node].vl - graph[j][cur_node]);
            }
        }
    }
    cout << "�¼�������ʼʱ��:\n";
    for (const auto& event_node : event_nodes)
    {
        cout << event_node.vl << " ";
    }
    cout << "\n";
    
}

void activity_calc(const vector<vector<int>>& graph)
{
    for(int i = 0;i<graph.size();i++){
        for(int j = 0;j<graph.size();j++){
            if (graph[i][j] != -1)
            {
                activities.emplace_back(activity(
                        graph[i][j], i, j,
                        event_nodes[i].ve,
                        event_nodes[j].vl - graph[i][j]));
            }
        }
    }
}


void print_key_node()
{
    cout << "key path:\n";
    for(auto act : activities)
    {
        if(act.e == act.l)
        {
            cout << act.src+1 << "--" << act.dest+1 << "\n";
        }
    }
}


int main()
{
    /* init graph */
    vector<vector<int>>&& graph = graph_common::create_graph(
            "E:\\MyLeetCode\\0.DataStructure\\6.Graph\\aoe_key_path_input.txt");
    graph_common::print_graph(graph);
    
    /* �����¼��ڵ�����������ʼ�� */
    topo_calc(graph);
    
    /* ���ɻ�����������ʼʱ�� */
    activity_calc(graph);
    
    /* ��ӡ */
    print_key_node();
    
    return 0;
}

