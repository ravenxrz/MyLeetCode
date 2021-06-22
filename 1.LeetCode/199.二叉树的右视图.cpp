#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

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
    vector<int> ans;

public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        queue<TreeNode *> qe;
        qe.push(root);
        int curLevelNum = 1;
        int nextLevelNum = 0;

        while (!qe.empty())
        {
            TreeNode *curNode = qe.front();
            qe.pop();
            if (curLevelNum == 1)
                ans.push_back(curNode->val);
            curLevelNum--;

            // push next level nodes
            if (curNode->left)
            {
                qe.push(curNode->left);
                nextLevelNum++;
            }
            if (curNode->right)
            {
                qe.push(curNode->right);
                nextLevelNum++;
            }

            // See if we have reached the last node of this level of tree
            if (curLevelNum == 0)
            {
                curLevelNum = nextLevelNum;
                nextLevelNum = 0;
            }
        }
        return ans;
    }

private:
};
// @lc code=end

int main()
{
    Solution sol;
    {
        TreeNode *root = nullptr;
        createTree(&root);
        const vector<int> &vecAns = sol.rightSideView(root);
        for (auto val : vecAns)
        {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}