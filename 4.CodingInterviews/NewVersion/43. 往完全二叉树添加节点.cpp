#include "leetcode_base.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class CBTInserter {
   public:
    CBTInserter(TreeNode* root) {
        assert(root);
        memset(tree_, 0, sizeof(tree_));
        // level traverse
        queue<TreeNode*> qe;
        qe.push(root);
        tree_[idx_++] = root;

        while (!qe.empty()) {
            auto node = qe.front();
            qe.pop();
            if (node->left) {
                qe.push(node->left);
                tree_[idx_++] = node->left;
            }
            if (node->right) {
                qe.push(node->right);
                tree_[idx_++] = node->right;
            }
        }
    }

    int insert(int v) {
        TreeNode* cur = new TreeNode(v);
        tree_[idx_++] = cur;
        TreeNode* parent = tree_[(idx_ >> 1) - 1];
        if (!(idx_ & 1)) { /* left sub tree */
            parent->left = cur;
        } else { /* right sub tree */
            parent->right = cur;
        }
        return parent->val;
    }

    TreeNode* get_root() {
        assert(idx_ > 0);
        return tree_[0];
    }

   private:
    TreeNode* tree_[2000];
    int idx_{0};
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */