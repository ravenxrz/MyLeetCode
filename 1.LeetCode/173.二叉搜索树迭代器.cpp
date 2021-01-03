/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}// @lc code=start
};

// @lc code=start

class BSTIterator {
public:
    BSTIterator(TreeNode *root)
    {
        stk.push(new Node(root));
        if (root->left != NULL) {
            push(root->left);
        }
    }
    
    int next()
    {
        int value = -1;
        Node *cur = stk.top();
        stk.pop();
        if (cur->node->left == NULL) {
            value = cur->node->val;
            // push right
            push(cur->node->right);
            return value;
        }
        // left child is not null
        // push left
        push(cur->node->left);
        value = stk.top()->node->val;
        return value;
    }
    
    bool hasNext()
    {
        return !stk.empty();
    }

private:
    void push(TreeNode *node)
    {
        while (node != NULL) {
            stk.push(new Node(node));
            node = node->left;
        }
    }

private:
    class Node {
    public:
        explicit Node(TreeNode *node) : node(node) {}
    
    public:
        TreeNode *node;
    };

private:
    stack<Node *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

