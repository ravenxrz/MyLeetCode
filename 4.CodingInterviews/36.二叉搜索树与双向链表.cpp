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

