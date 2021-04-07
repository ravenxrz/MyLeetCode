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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        
        // root1 != nullptr && root2 != nullptr
        TreeNode *root = nullptr;
        merge(root,root1,root2);
        return root;
    }
private:
    void merge(TreeNode *&node, TreeNode *node1, TreeNode *node2){
        if(node1 == nullptr && node2 == nullptr) {
            node = nullptr;
        } else if(node1 == nullptr && node2 != nullptr){
            node = new TreeNode(node2->val);
            merge(node->left,nullptr, node2->left);
            merge(node->right,nullptr,node2->right);
        }else if(node1 != nullptr && node2 == nullptr){
            node = new TreeNode(node1->val);
            merge(node->left,node1->left, nullptr);
            merge(node->right,node1->right,nullptr);
        }else { // node1 != nullptr && node2 != nullptr
            node = new TreeNode(node1->val + node2->val);
            merge(node->left, node1->left,node2->left);
            merge(node->right,node1->right,node2->right);
        }
    }
    
};
