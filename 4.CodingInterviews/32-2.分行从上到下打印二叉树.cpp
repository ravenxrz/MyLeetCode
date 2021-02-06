//
// Created by Raven on 2021/2/5.
//
#include <iostream>
#include <vector>
#include <queue>

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
private:
    struct Node {
        TreeNode *treeNode;
        size_t level;
    };
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL) return {};
        queue<Node> qu;
        qu.push({root, 1});
        vector<vector<int>> ans;
        
        while (!qu.empty()) {
            Node &node = qu.front();
            qu.pop();
            if (node.treeNode == NULL) continue;
            // get current node
            if (ans.size() != node.level) {
                ans.push_back({node.treeNode->val});
            } else {
                ans[node.level].push_back(node.treeNode->val);
            }
            // push children
            qu.push({node.treeNode->left, node.level + 1});
            qu.push({node.treeNode->right, node.level + 1});
        }
        return ans;
    }
};