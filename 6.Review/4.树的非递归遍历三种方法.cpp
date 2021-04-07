#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *lchild;
    TreeNode *rchild;
    
    TreeNode(int val) : val(val), lchild(nullptr), rchild(nullptr) {}
};

TreeNode *buildTree()
{
    int val;
    cin >> val;
    if (val == -1) return nullptr;
    TreeNode *node = new TreeNode(val);
    node->lchild = buildTree();
    node->rchild = buildTree();
    return node;
}

void printAns(const vector<int> &ans)
{
    for (auto val : ans) {
        cout << val << ' ';
    }
    cout << endl;
}

void preOrderTraverse(TreeNode *root)
{
    if (root == nullptr) return;
    
    stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *p = root;
    
    while (p || !stk.empty()) {
        if (p) {
            ans.push_back(p->val);
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    
    printAns(ans);
}

void inOrderTraverse(TreeNode *root)
{
    if (root == nullptr) return;
    
    stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *p = root;
    while (p || !stk.empty()) {
        if (p) {
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            ans.push_back(p->val);
            p = p->rchild;
        }
    }
    
    printAns(ans);
}

void postOrderTraverse(TreeNode *root)
{
    if (root == nullptr) return;
    
    stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *p = root;
    while (p || !stk.empty()) {
        if (p) {
            ans.push_back(p->val);
            stk.push(p);
            p = p->rchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->lchild;
        }
    }
    
    // reverse
    reverse(ans.begin(), ans.end());
    
    printAns(ans);
}


int main()
{
    TreeNode *root = buildTree();
    preOrderTraverse(root);
    inOrderTraverse(root);
    postOrderTraverse(root);
    return 0;
}
