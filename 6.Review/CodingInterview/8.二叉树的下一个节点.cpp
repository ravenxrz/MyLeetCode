#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode* parent;
    TreeNode(int val) : val(val), lchild(nullptr), rchild(nullptr) {}
};

TreeNode* doBuild(TreeNode* parent) {
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;
    TreeNode* node = new TreeNode(val);
    node->parent = parent;
    node->lchild = doBuild(node);
    node->rchild = doBuild(node);
    return node;
}

TreeNode* buildTree() {
    return doBuild(nullptr);
}

void preOrderPrintTree(TreeNode* node) {
    if (node == nullptr)
        return;
    cout << node->val << ' ';
    preOrderPrintTree(node->lchild);
    preOrderPrintTree(node->rchild);
}

int main() {
    TreeNode* root = buildTree();
    preOrderPrintTree(root);
    return 0;
}