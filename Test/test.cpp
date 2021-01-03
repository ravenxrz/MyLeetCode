/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}// @lc code=start
};

// @lc code=start

class BSTIterator {
public:
    BSTIterator(TreeNode *root)
    {
        push(root);
    }
    
    int next()
    {
        TreeNode *node = stk.top();
        stk.pop();
        // push right
        if (node->right != NULL) {
            push(node->right);
        }
        return node->val;
    }
    
    void push(TreeNode *node)
    {
        while (node != NULL) {
            stk.push(node);
            node = node->left;
        }
    }
    
    bool hasNext()
    {
        return !stk.empty();
    }


private:
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    BSTIterator *iter = new BSTIterator(root);
    cout << iter->next() << endl;
    cout << iter->next() << endl;
    cout << iter->next() << endl;
    cout << iter->hasNext() << endl;
    
    delete iter;
    return 0;
}
