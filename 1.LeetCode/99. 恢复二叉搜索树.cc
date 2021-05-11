#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
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
class Solution {
   private:
    vector<TreeNode*> nodes;

   public:
    void recoverTree(TreeNode* root) {
        inOrderPut(root);
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i]->val > nodes[i + 1]->val) {
                bool finished = false;
                for (int j = i + 1; j < nodes.size() - 1; ++j) {
                    if (nodes[i]->val > nodes[j]->val) {
                        // Try to swap
                        swap(nodes[i]->val, nodes[j]->val);
                        if (nodes[j]->val >
                            nodes[j + 1]
                                ->val) {  // Continue to verify the subsequences
                            // Recover back to the original state
                            swap(nodes[i]->val, nodes[j]->val);
                        } else {
                            finished = true;
                            break;
                        }
                    }
                }
                if (finished) {
                    return;
                }
                // Swap the last node with current i node
                swap(nodes[i]->val, nodes.back()->val);
                break;
            }
        }
    }

    void inOrderPut(TreeNode* node) {
        if (node == nullptr)
            return;
        inOrderPut(node->left);
        nodes.push_back(node);
        inOrderPut(node->right);
    }
};

int main() {
    return 0;
}
