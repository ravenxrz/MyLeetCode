
/**
 * n sum 问题
 */

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr) return;
        flatten_core(root);
    }

private:
    TreeNode *flatten_core(TreeNode *node)
    {
        if (node->left == nullptr && node->right == nullptr) return node;
        
        TreeNode *last = nullptr;
        TreeNode *save_right = node->right;
        if (node->left) {
            last = flatten_core(node->left);
            last->right = save_right;
            node->right = node->left;
            node->left = nullptr;
        }
        if (save_right) {
            last = flatten_core(save_right);
        }
        return last;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    Solution sol;
    sol.flatten(root);
    return 0;
}

class Solution {
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr) return;
        flatten_core(root);
    }

private:
    void flatten_core(TreeNode *node)
    {
        if (node == nullptr) return;
        
        flatten_core(node->left);
        flatten_core(node->right);
        
        TreeNode *save_right = node->right;
        node->right = node->left;
        node->left = nullptr;
        // 找到原左子树的最后一个节点
        TreeNode *p = node;
        while (p->right) {
            p = p->right;
        }
        p->right = save_right;
    }
};

