#include "leetcode_base.h"

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return findInoderParent(root, nullptr, p);
    }

   private:
    TreeNode* findInoderParent(TreeNode* node,
                               TreeNode* parent,
                               TreeNode* target) {
        if (!node)
            return nullptr;
        if (node == target) {
            /* try to search the right subtree */
            if (node->right) {
                TreeNode* p = node->right;
                while (p->left) {
                    p = p->left;
                }
                return p;
            } else {
                /* right sub tree is nullptr, so check parent */
                return parent;
            }
        } else {
            /* keep searching */
            TreeNode* left = findInoderParent(node->left, node, target);
            if (left)
                return left;
            TreeNode* right = findInoderParent(node->right, parent, target);
            if (right)
                return right;
        }
        return nullptr;
    }
};

int main() {
    return 0;
}