#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr) return 0;
        deque<pair<TreeNode *, int>> qe;
        // push first value
        qe.emplace_back(root, 1);
        int curLevel = 1;
        int nextLevel = 0;
        int maxWidth = 1;
        while (!qe.empty()) {
            auto cur = qe.front();
            qe.pop_front();
            curLevel--;
            if (cur.first->left) {
                qe.emplace_back(cur.first->left, cur.second << 1);
                nextLevel++;
            }
            if (cur.first->right) {
                qe.emplace_back(cur.first->right, cur.second << 1 | 1);
                nextLevel++;
            }
            if (curLevel == 0) {
                curLevel = nextLevel;
                nextLevel = 0;
                // 计算宽度
                if(qe.empty()) break;
                int width = qe.back().second - qe.front().second + 1;
                maxWidth = max(maxWidth, width);
            }
        }
        return maxWidth;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sol.widthOfBinaryTree(root);
    return 0;
}
