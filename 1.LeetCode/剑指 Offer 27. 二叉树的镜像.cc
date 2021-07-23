class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        doMirror(root);
        return root;
    }

private:
    void doMirror(TreeNode *node){
        if(node == nullptr) return;
        doMirror(node->left);
        doMirror(node->right);
        // Swap left and right tree
        swap(node->left,node->right);
    }
};
