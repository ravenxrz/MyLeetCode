//
// Created by Raven on 2021/1/22.
//
#include <stack>

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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        // nullptr node check
        if (A == nullptr || B == nullptr) return false;
        
        // non-recursive tree traverse
        stack<pair<TreeNode *, int>> stk;
        int target = B->val;
        stk.push({A, 0});
        while (!stk.empty()) {
            auto &cur_pair = stk.top();
            if (cur_pair.first == nullptr) {
                // pop instantly
                stk.pop();
                continue;
            }
            
            // print condition
            if (cur_pair.second == 0) {
                if (cur_pair.first->val == target) {
                    // check
                    bool ret = check(cur_pair.first, B);
                    if (ret) return true;
                }
            }
            
            // push children condition
            cur_pair.second++;
            if (cur_pair.second == 1) {
                // push left child
                stk.push({cur_pair.first->left, 0});
            } else if (cur_pair.second == 2) {
                // push right child
                stk.push({cur_pair.first->right, 0});
            } else {
                stk.pop();
            }
        }
        return false;
    }


private:
    bool check(TreeNode *Anode, TreeNode *Bnode)
    {
        if (Bnode == nullptr) return true;
        else if (Anode == nullptr) return false;
        
        // pre order check
        if (Anode->val != Bnode->val) return false;
        
        return check(Anode->left, Bnode->left) &&
               check(Anode->right, Bnode->right);
    }
};
