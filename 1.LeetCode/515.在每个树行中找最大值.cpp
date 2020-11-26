/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

#include <queue>
#include <map>
#include <vector>

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
    vector<int> largestValues(TreeNode *root)
    {
        if (root == nullptr) return {};
        
        vector<int> ans;
        queue<pair<int, TreeNode *>> q;
        map<int, int> max_values;
        
        q.push({0, root});
        while (!q.empty()) {
            if (max_values.find(q.front().first) == max_values.end()) {
                max_values[q.front().first] = q.front().second->val;
            } else {
                if (max_values[q.front().first] < q.front().second->val) {
                    max_values[q.front().first] = q.front().second->val;
                }
            }
            if(q.front().second->left != nullptr)
                q.push({q.front().first + 1, q.front().second->left});
            if(q.front().second->right != nullptr)
                q.push({q.front().first + 1, q.front().second->right});
            
            q.pop();
        }
        // get ans
        for(auto & max_value : max_values){
            ans.push_back(max_value.second);
        }
        return ans;
    }
};
// @lc code=end

