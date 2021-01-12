/**
 * 题目：给定一棵二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？
 * 树中的节点除了有两个分别指向左、右子节点的指针，还有一个指向父节点的指针。
 */


#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *doBuild(TreeNode *parent);

TreeNode *buildTree()
{
    return doBuild(nullptr);
}

TreeNode *doBuild(TreeNode *parent)
{
    int val;
    cin >> val;
    if (val == -1) {  // -1 为end
        return nullptr;
    }
    TreeNode *node = new TreeNode(val);
    node->parent = parent;
    node->left = doBuild(node);
    node->right = doBuild(node);
    return node;
}

void pre_order_traverse(TreeNode *node)
{
    if (node == nullptr) {
        return;
    }
    cout << node->val << endl;
    pre_order_traverse(node->left);
    pre_order_traverse(node->right);
}


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
    TreeNode *next_node(TreeNode *root, TreeNode *node)
    {
        if (root == nullptr || node == nullptr) return nullptr;
        
        // 如果有右孩子
        if (node->right != nullptr) {
            // 找到右子树最左边叶子节点
            TreeNode *cur = node->right;
            while(!is_leaf(cur->left)){
                cur = cur->left;
            }
            return cur;
        }
        // 如果node是父亲节点的左孩子
        if (is_parent_left_child(node)) {
            return node->parent;
        }
        
        // 如果是父亲节点的右孩子
        if (is_parent_right_child(node)) {
            TreeNode *cur = node->parent;
            while (cur != root) {
                if (is_parent_left_child(cur)) {
                    return cur->parent;
                }
                cur = cur->parent;
            }
        }
        
        // else
        return nullptr;
    }

private:
    static bool is_leaf(TreeNode *node){
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }
    
    static bool is_parent_left_child(TreeNode *node)
    {
        assert(node != nullptr);
        if (node->parent == nullptr) return false;
        
        return node->parent->left == node;
    }
    
    static bool is_parent_right_child(TreeNode *node)
    {
        assert(node != nullptr);
        if (node->parent == nullptr) return false;
        
        return node->parent->right == node;
    }
};

void print_ans(TreeNode *node){
    if(node == nullptr){
        cout <<  "null\n";
    }else{
        cout << node->val << " \n";
    }
}


int main()
{
    Solution sol;
    
    TreeNode *root = buildTree();
    pre_order_traverse(root);
    
    // root node
    {
        print_ans(sol.next_node(root,root));
    }
    
    // leaf
    {
        print_ans(sol.next_node(root,root->left->left));
        print_ans(sol.next_node(root,root->left->right));
    }
    
    // mid
    {
        print_ans(sol.next_node(root,root->right));
    }
    return 0;
}

