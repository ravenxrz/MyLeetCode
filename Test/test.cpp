#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    
    Node() {}
    
    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }
    
    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == NULL) return NULL;
        
        Node *tmp = NULL;
        convert(root, tmp);
        // find head and tail node
        Node *head = root;
        Node *tail = root;
        while (head->left != NULL) head = head->left;
        while (tail->right != NULL) tail = tail->right;
        head->left = tail;
        tail->right = head;
        return head;
    }

private:
    void convert(Node *node, Node *&lastNode)
    {
        if (node == NULL) return;
        
        convert(node->left, lastNode);
        node->left = lastNode;
        if (node->left != NULL) {
            node->left->right = node;
        }
        lastNode = node;
        convert(node->right, lastNode);
    }
};

int main()
{
    Solution sol;
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    Node *node = sol.treeToDoublyList(root);
    while (node) {
        cout << node->val << '\n';
        node = node->right;
    }
   
    return 0;
}