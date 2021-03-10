#include <cassert>
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

// 找到中序遍历的下一个节点
bool isMyParentLeftChild(TreeNode* node) {
    assert(node != nullptr);
    if (node->parent == nullptr)
        return false;
    if (node->parent->lchild == node)
        return true;
    return false;
}

bool isMyParentRightChild(TreeNode* node) {
    assert(node != nullptr);
    if (node->parent == nullptr)
        return false;
    if (node->parent->rchild == node)
        return true;
    return false;
}

bool isRootNode(TreeNode* node) {
    assert(node != nullptr);
    return node->parent == nullptr;
}

TreeNode* findNextNode(TreeNode* node) {
    if (node == nullptr)
        return nullptr;
    // 如果有右子树
    if (node->rchild != nullptr) {
        TreeNode* p = node->rchild;
        while (p->lchild)
            p = p->lchild;
        return p;
    }
    // 无右子树
    // 如果当前节点是父亲节点的左孩子
    if (isMyParentLeftChild(node)) {
        return node->parent;
    }
    // 如果当前节点是父亲节点的右孩子
    if (isMyParentRightChild(node)) {
        TreeNode* p = node->parent;
        while (!isRootNode(p) && isMyParentRightChild(p)) {
            p = p->parent;
        }
        // 找到当前节点为其父亲节点的左孩子，或者当前节点已经是root节点
        return p->parent;
    }
    return nullptr;
}

int main() {
    TreeNode* root = buildTree();
    preOrderPrintTree(root);
    cout << endl;
    cout << findNextNode(root)->val << endl;
    cout << findNextNode(root->lchild)->val << endl;
    TreeNode* node = findNextNode(root->rchild);
    if (node == nullptr) {
        cout << "no next node exists" << '\n';
    } else {
        cout << node->val << endl;
    }
    return 0;
}
