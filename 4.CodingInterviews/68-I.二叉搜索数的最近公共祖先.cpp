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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int val1 = min(p->val, q->val);
        int val2 = max(p->val, q->val);
        return findNearestParent(root, val1, val2);
    }

private:
    // acquire val1 <= val2
    TreeNode *findNearestParent(TreeNode *node, int val1, int val2)
    {
        if (node == NULL) return NULL;
        if (node->val >= val1 && node->val <= val2) {
            return node;
        } else if (node->val < val1) {
            // right sub-tree
            return findNearestParent(node->right, val1, val2);
        } else {  // node->val > val2
            // left sub-tree
            return findNearestParent(node->left, val1, val2);
        }
    }
};

