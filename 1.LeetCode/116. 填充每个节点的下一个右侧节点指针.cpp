
/**
 * n sum 问题
 */

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node *connect(Node *root)
    {
        if (root == nullptr) return nullptr;
        connectTwoNodes(root->left, root->right);
        return root;
    }

private:
    void connectTwoNodes(Node *node1, Node *node2)
    {
        if (node1 == nullptr || node2 == nullptr) return;
        
        node1->next = node2;
        connectTwoNodes(node1->left, node1->right);
        connectTwoNodes(node2->left, node2->right);
        connectTwoNodes(node1->right, node2->left);
    }
};

int main()
{
    vector<int> input{1, 0, -1, 0, -2, 2};
    Solution sol;
    int n = 4;
    int target = 0;
    auto ans = sol.nSum(input, n, target);
    for (auto &vec : ans) {
        for (int val :vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}
