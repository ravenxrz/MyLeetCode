#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=1367 lang=cpp
 *
 * [1367] 二叉树中的列表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  ListNode *head = nullptr;

public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    if(root == nullptr)
        return false;
    return traverse(root, head) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }

  bool traverse(TreeNode *tnode, ListNode *lnode) {
    if (lnode == nullptr) {
      return true;
    }
    if (tnode == nullptr) {
      return false;
    }

    if (tnode->val != lnode->val) {
      return false;
    }
    return traverse(tnode->left, lnode->next) ||
           traverse(tnode->right, lnode->next);
  }
};
// @lc code=end
