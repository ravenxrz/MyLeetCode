/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    
    ListNode(int x) : val(x), next(nullptr) {}
    
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
       int len = getListLen(head);
       TreeNode* node = nullptr;
       buildTree(node,head,0,len-1);
       return node;
    }

private:
    int getListLen(ListNode *head)
    {
        int len = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)len++;
        return len;
    }
    
    void buildTree(TreeNode*& treeNode, ListNode *&listNode, int start,int end){
        if(start > end) return;
        if(start == end){
            treeNode = new TreeNode(listNode->val);
            listNode = listNode->next;
            return;
        }
        // get mid node
        treeNode = new TreeNode(0);
        int mid = (start+end)/2;
        buildTree(treeNode->left,listNode,start,mid-1);
        treeNode->val = listNode->val; listNode = listNode->next;
        buildTree(treeNode->right,listNode,mid+1,end);
    }
};
// @lc code=end

