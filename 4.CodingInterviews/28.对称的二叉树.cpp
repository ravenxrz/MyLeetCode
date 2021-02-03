//
// Created by Raven on 2021/2/3.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL) { // 空树是对称还是不对称？
            return true;
        }
        // 单根节点
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        // 正常check
        return checkSymmetric(root->left, root->right);
    }

private:
    bool checkSymmetric(TreeNode *node1, TreeNode *node2)
    {
        // 都为空
        if (node1 == NULL && node2 == NULL) return true;
        // 有且只有其中一个节点为NULL
        if (!(node1 != NULL && node2 != NULL)) return false;
        // 正常check
        if (node1->val != node2->val) return false;
        // 递归check
        return checkSymmetric(node1->left, node2->right) &&
               checkSymmetric(node1->right, node2->left);
    }
};


int main()
{
    Solution sol;
    {
        // empty tree
        TreeNode *root = NULL;
        cout << sol.isSymmetric(root) << '\n';
    }
    {
        // single root node
        TreeNode *root = new TreeNode(1);
        cout << sol.isSymmetric(root) << '\n';
    }
    {
        // single leaf node
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        cout << sol.isSymmetric(root) << '\n';
    }
    {
        // single leaf node
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);
        cout << sol.isSymmetric(root) << '\n';
    }
    {
        // usual case check
        TreeNode *root = new TreeNode(8);
        root->left = new TreeNode(6);
        root->right = new TreeNode(6);
        cout << sol.isSymmetric(root) << '\n';
    }
    return 0;
}
