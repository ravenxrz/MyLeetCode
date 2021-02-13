#include <iostream>
#include <vector>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // assert(root != NULL && p != NULL && q != NULL)
        vector<TreeNode *> path1;
        getPath(root, p, path1);
        vector<TreeNode *> path2;
        getPath(root, q, path2);
        return findLowestCommonParent(path1, path2);
    }

private:
    bool getPath(TreeNode *node, TreeNode *p, vector<TreeNode *> &path)
    {
        if (node == NULL) return false;
        path.push_back(node);
        if (node == p) return true;
        if (getPath(node->left, p, path)) {
            return true;
        }
        if (getPath(node->right, p, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

private:
    TreeNode *findLowestCommonParent(const vector<TreeNode *> &path1, const vector<TreeNode *> &path2)
    {
        if (path1.empty() || path2.empty()) return NULL;
        TreeNode *last = NULL;
        int i = 0;
        while (i < path1.size() && i < path2.size()) {
            if (path1[i] == path2[i]) {
                last = path1[i];
                i++;
            } else {
                return last;
            }
        }
        // 一定有公共祖先
        if (i != 0) {
            if (i == path1.size()) return path1.back();
            else return path2.back();
        }
        return NULL;
    }
};


int main()
{
    Solution sol;
    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        cout << sol.lowestCommonAncestor(root, root->left, root->right)->val << endl;
    }
    return 0;
}
