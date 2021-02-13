#include <iostream>

using namespace std;

struct TreeNode
{
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
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        ans = true;
        height(root);
        return ans;
    }

private:
    int height(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int compare = leftHeight - rightHeight;
        if (compare > 1 || compare < -1)
        {
            ans = false;
        }
        return max(leftHeight, rightHeight) + 1;
    }

private:
    bool ans;
};
