/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;


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
    
    void pre_order1(TreeNode* p, vector<int>& result){
        if(p == nullptr){
            result.push_back(-1);
            return ;
        }
        result.push_back(p->val);
        pre_order1(p->left,result);
        pre_order1(p->right,result);
    }
    
    bool pre_order2(TreeNode* p, vector<int>& old,int& idx){
        if(p == nullptr){
            return old[idx++] == -1;
        }
        
        if(p->val != old[idx++]) return false;
        if(!pre_order2(p->left,old,idx)){
            return false;
        }
        return pre_order2(p->right,old,idx);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> old;
        pre_order1(p,old);
        int i = 0;
        return pre_order2(q,old,i);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    cout << sol.isSameTree(root1,root2);
    return 0;
}