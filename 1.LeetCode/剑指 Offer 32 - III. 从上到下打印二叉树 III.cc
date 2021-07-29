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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        ans.emplace_back();
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        bool flag = true;
        // init
        stk1.push(root);
        while(!stk1.empty() || !stk2.empty()) {
            if(flag){
                assert(!stk1.empty()) ;
                while(!stk1.empty()){
                    auto cur_node = stk1.top();
                    stk1.pop();
                    ans.back().push_back(cur_node->val);
                    // Push children to stk2
                    if(cur_node->left) stk2.push(cur_node->left);
                    if(cur_node->right) stk2.push(cur_node->right);
                }
            }else{
                assert(!stk2.empty()) ;
                while(!stk2.empty()){
                    auto cur_node = stk2.top();
                    stk2.pop();
                    ans.back().push_back(cur_node->val);
                    // Push children to stk2
                    if(cur_node->right) stk1.push(cur_node->right);
                    if(cur_node->left) stk1.push(cur_node->left);
                }
            }
            flag = !flag;
            ans.emplace_back();     // Checkout to next level
        }
        // Remove last redundant level
        ans.pop_back();
        return ans;
    }
};
