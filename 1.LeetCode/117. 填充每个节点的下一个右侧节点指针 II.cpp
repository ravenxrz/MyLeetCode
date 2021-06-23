#include "leetcode_base.h"

class Node
{
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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        doConnect(root);
        return root;
    }

private:
    void doConnect(Node *node)
    {
        if (node == nullptr)
            return;
        Node *curLevel = node;
        Node *nextLevel = nullptr;
        Node *nextLevelMark = nullptr;

        // step1: find proper position of nextLevel
        while (curLevel)
        {
            if (curLevel->left)
            {
                nextLevel = curLevel->left;
                break;
            }
            if (curLevel->right)
            {
                nextLevel = curLevel->right;
                break;
            }
            curLevel = curLevel->next;
        }
        if (curLevel == nullptr) // We have reached the end of level but still not find correct position of next level
            return;
        nextLevelMark = nextLevel;

        // Connect current Node
        if (nextLevel == curLevel->left && curLevel->right)
        {
            nextLevel->next = curLevel->right;
            nextLevel = curLevel->right;
        }
        // Move to the next node
        curLevel = curLevel->next;

        // step2: do connect
        while (curLevel)
        {
            if (curLevel->left)
            {
                nextLevel->next = curLevel->left;
                nextLevel = curLevel->left;
            }
            if (curLevel->right)
            {
                nextLevel->next = curLevel->right;
                nextLevel = curLevel->right;
            }
            curLevel = curLevel->next;
        }

        // Step into next level connecting
        doConnect(nextLevelMark);
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    Solution sol;
    sol.connect(root);
    return 0;
}