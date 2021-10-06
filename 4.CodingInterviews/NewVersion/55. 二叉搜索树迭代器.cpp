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
class BSTIterator {
   public:
    BSTIterator(TreeNode* root) {
        TreeNode* p = root;
        while (p) {
            stk.push(p);
            p = p->left;
        }
    }

    int next() {
        int ret = -1;
        if (stk.empty()) {
            cerr << "error happens\n";
        } else {
            ret = stk.top()->val;
            TreeNode* try_node = stk.top()->right;
            stk.pop();
            while (try_node) {
                stk.push(try_node);
                try_node = try_node->left;
            }
        }
		return ret;
    }

    bool hasNext() { return !stk.empty(); }

   private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
