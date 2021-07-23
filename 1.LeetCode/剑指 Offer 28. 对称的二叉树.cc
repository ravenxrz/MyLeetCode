class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr) return true;
        return Check(root->left, root->right);
    }

private:
    bool Check(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr) return true;
        if (!(left && right)) {
            return false;
        } else {
            if(left->val != right->val) return false;
            return Check(left->left, right->right) &&
                   Check(left->right, right->left);
        }
    }
};
