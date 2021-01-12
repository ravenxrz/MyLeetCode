/**
 * 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如，输入前序遍历序列{1，2，4，7，3，5，6，8}和中序遍历序列{4，7，2，1，5，3，8，6}，则重建如图26所示的二叉树并输出它的头节点。
 */
#include <vector>
#include <algorithm>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // some checks
        if (preorder.empty() || inorder.empty()) return nullptr;
        if (preorder.size() != inorder.size()) return nullptr;
        
        int idx = 0;
        return _build(preorder, inorder, idx, 0, inorder.size());
    }

private:
    TreeNode *_build(const vector<int> &preorder, const vector<int> &inorder, int &idx,
                     int start, int end) // find range [start,end)
    {
        if (start >= end) return nullptr;
        // find root node in inorder
        int root_value = preorder[idx++];
        TreeNode *tmp_root = new TreeNode(root_value);
        int root_idx = find(inorder.begin() + start, inorder.begin() + end, root_value) - inorder.begin();
        tmp_root->left = _build(preorder, inorder, idx, start, root_idx);
        tmp_root->right = _build(preorder, inorder, idx, root_idx + 1, end);
        return tmp_root;
    }
};
