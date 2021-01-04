#include <iostream>
#include <vector>

using namespace std;

struct Node {
    string name;
    double p;
    
    Node(string name, double p) : name(std::move(name)), p(p) {}
};

struct TreeNode {
    const Node *node;
    TreeNode *lchild, *rchild;
    
    explicit TreeNode(const Node *node) : node(node), lchild(nullptr), rchild(nullptr) {}
};

TreeNode *buildTree(const vector<Node> &nodes, vector<vector<int>> &root_table, int i, int j)
{
    if (i > j) return nullptr;
    int root_idx = root_table[i][j];
    TreeNode *root = new TreeNode(&nodes[root_idx]);
    root->lchild = buildTree(nodes, root_table, i, root_idx - 1);
    root->rchild = buildTree(nodes, root_table, root_idx + 1, j);
    return root;
}


TreeNode *buildTree(const vector<Node> &nodes)
{
    const int m = nodes.size();
    // dp表，dp[i][j] 表示 [i,j]范围内的元素的最小平均查找次数
    vector<vector<double>> dp(m, vector<double>(m, 0.0f));
    // root 表，用于辅助生成整棵树
    vector<vector<int>> root_table(m, vector<int>(m, -1));
    
    // 初始化dp表dp[i][i] = node.p        dp[i][j] = 0 if j < i
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                dp[i][j] = nodes[i].p;
                root_table[i][j] = i;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    // 计算dp表
    // 从下往上计算
    // 动态规划转移方程 dp[i][j] = min{dp[i][k-1] + dp[k+1][i]} + sum{i--j}{p} 其中k-[i,j]
    for (int i = m - 1; i >= 0; i--) {
        for (int j = i + 1; j < m; j++) {
            int min_k = -1;
            double min_value = INT32_MAX;
            double base_value = 0.0f;
            // 计算[i,j] 之间的权重和
            for (int idx = i; idx <= j; idx++) {
                base_value += nodes[idx].p;
            }
            // 计算结果
            for (int k = i; k <= j; k++) {
                double value = base_value;
                if (k == i) {
                    value += dp[k + 1][j];
                } else if (k == j) {
                    value += dp[i][k - 1];
                } else {
                    value += (dp[i][k - 1] + dp[k + 1][j]);
                }
                if (min_value > value) {
                    min_value = value;
                    min_k = k;
                }
            }
            dp[i][j] = min_value;
            root_table[i][j] = min_k;
        }
    }
    cout << "min average get cost:" << dp[0][m - 1] << endl;
    // build tree
    return buildTree(nodes, root_table, 0, m - 1);
}


void pre_order_traverse(TreeNode *node){
    if(node == nullptr) return;
    cout << node->node->name << ":" << node->node->p << endl;
    pre_order_traverse(node->lchild);
    pre_order_traverse(node->rchild);
}


int main()
{
    // 初始化节点
    vector<Node> nodes;
    nodes.emplace_back(Node("A", 0.1));
    nodes.emplace_back(Node("B", 0.2));
    nodes.emplace_back(Node("C", 0.4));
    nodes.emplace_back(Node("D", 0.3));
    
    TreeNode *root = buildTree(nodes);
    pre_order_traverse(root);
    
    // free resources
    return 0;
}
