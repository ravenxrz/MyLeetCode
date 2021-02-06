#include <iostream>
#include <vector>

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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if(root == NULL)   return {};
        preOrderTraverse(root,0,sum);
        return ans;
    }

private:
    void preOrderTraverse(TreeNode *node, int tmp_sum, int sum)
    {
        static vector<int> tmp;
        if (node == NULL) return;
        
        tmp_sum += node->val;
        tmp.push_back(node->val);
        if (tmp_sum == sum && (node->left == NULL && node->right == NULL)) {
            ans.push_back(tmp);
        }
        
        preOrderTraverse(node->left, tmp_sum, sum);
        preOrderTraverse(node->right, tmp_sum, sum);
        tmp.pop_back();
    }

private:
    vector<vector<int>> ans;
};

int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->right = new TreeNode(12);
        sol.pathSum(root,15);
    }
    return 0;
}
