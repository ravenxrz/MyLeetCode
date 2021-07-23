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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr || B == nullptr) return false;
        return doFindHead(A, B);
    }

private:
    // Assert(rootB)
    bool doFindHead(TreeNode *nodeA, TreeNode *rootB)
    {
        if (nodeA == nullptr) return false;
        if (nodeA->val == rootB->val) {
            bool ret = doFind(nodeA, rootB);
            if (ret) return true;
        }
        return doFindHead(nodeA->left, rootB) ||
               doFindHead(nodeA->right, rootB);
    }
    
    bool doFind(TreeNode *nodeA, TreeNode *nodeB)
    {
        if (nodeB == nullptr) return true;
        else if (nodeA == nullptr) return false;
        if (nodeA->val != nodeB->val) return false;
        return doFind(nodeA->left, nodeB->left) &&
               doFind(nodeA->right, nodeB->right);
    }
};
