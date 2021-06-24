/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
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
class Solution
{
public:
    vector<vector<vector<TreeNode *>>> tree_saver;

    vector<TreeNode *> connect_left(int val, const vector<TreeNode *> &lchild)
    {
        vector<TreeNode *> tmp(lchild.size(), nullptr);
        if (lchild.empty())
        {
            tmp.push_back(new TreeNode(val));
            return tmp;
        }
        for (int i = 0; i < lchild.size(); i++)
        {
            tmp[i] = new TreeNode(val);
            tmp[i]->left = lchild.at(i);
        }
        return tmp;
    }

    TreeNode *copy_tree(TreeNode *t)
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(t->val);
        node->left = copy_tree(t->left);
        node->right = copy_tree(t->right);
        return node;
    }

    vector<TreeNode *> connect_right(const vector<TreeNode *> &half_tree, const vector<TreeNode *> &right_tree)
    {
        if (right_tree.empty())
        {
            return half_tree;
        }
        vector<TreeNode *> tmp(half_tree.size() * right_tree.size(), nullptr);
        for (int i = 0; i < half_tree.size(); i++)
        {
            for (int j = 0; j < right_tree.size(); j++)
            {
                TreeNode *tmp_node = copy_tree(half_tree.at(i));
                tmp_node->right = right_tree[j];
                tmp[right_tree.size() * i + j] = tmp_node;
            }
        }
        return tmp;
    }

    vector<TreeNode *> f(int start, int end)
    {
        if (start > end)
        {
            return {};
        }

        if (!tree_saver[start][end].empty())
        {
            return tree_saver[start][end];
        }

        if (start == end)
        {
            tree_saver[start][end] = {new TreeNode(start)};
            return tree_saver[start][end];
        }

        vector<TreeNode *> tmp;
        for (int i = start; i <= end; i++)
        {
            // left sub-tree
            const vector<TreeNode *> lv = f(start, i - 1);
            // right sub-tree
            const vector<TreeNode *> &rv = f(i + 1, end);
            // 连接
            const vector<TreeNode *> &half_tree = connect_left(i, lv);
            vector<TreeNode *> tree = connect_right(half_tree, rv);
            tmp.insert(tmp.end(), tree.begin(), tree.end());
        }
        tree_saver[start][end] = tmp;
        return tmp;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        tree_saver.resize(n + 1, vector<vector<TreeNode *>>(n + 1));
        return f(1, n);
    }
};
// @lc code=end
