#include <iostream>

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
    int kthLargest(TreeNode *root, int k)
    {
        count = 0;
        reverse_in_traverse(root, k);
        return ans;
    }

private:
    void reverse_in_traverse(TreeNode *node, int k)
    {
        if (node == NULL) return;
        reverse_in_traverse(node->right, k);
        count++;
        if (count == k) {
            ans = node->val;
            return;
        }
        reverse_in_traverse(node->left, k);
    }

private:
    int count;
    int ans;
};
