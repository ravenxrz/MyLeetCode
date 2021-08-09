class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }

   private:
    TreeNode* LCA(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == p || cur == q || cur == nullptr) {
            return cur;
        }
        TreeNode* left = LCA(cur->left, p, q);
        TreeNode* right = LCA(cur->right, p, q);
        if (left && right) {
            return cur;
        } else if (left) {
            return left;
        } else {
            return right;
        }
    }
};