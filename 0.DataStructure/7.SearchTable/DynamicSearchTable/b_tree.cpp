/**
 * Created by a2855 on 2020/9/29.
 * B tree
 * 实现说明：
 * 1.使用最小度 t 来定义一个node的key数量range
 * 2.在insert操作中，从root往下遍历时，发现有节点key数量过多时，就执行split，避免多次 IO（常规split可能造成级联的split）
 * 3.在delete操作中，从root往下遍历时，发现有节点key数量过少时，立即填充，避免多次IO（常规delete可能造成级联的merge）
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct node {
    vector<int> keys;       /* keys 数组 */
    vector<node *> children;        /* child 指针, 数量为keys的数量+1 */
    int t;                  /* 最小度定义法，用于维护节点的key number range */
    bool leaf;              /* 是否是孩子节点 */
    int n;                  /* 当前持有key的数量 */
    /* 实际上还应该包含一个value指针数组，不过要理解Btree，并不需要它 */
    
    node(int t, bool leaf) : t(t), leaf(leaf)
    {
        keys.resize(2 * t - 1, -1);
        children.resize(2 * t, nullptr);
        n = 0;
    }
};

class b_tree {
public:
    b_tree(int t) : t(t), root(nullptr)
    {
        assert(t >= 2);
    }
    
    void traverse()
    {
        _traverse(root);
    }
    
    struct node *search(int key)
    {
        return _search(root, key);
    }
    
    void insert(int key)
    {
        if (root == nullptr) {
            root = new node(t, true);
            root->keys[0] = key;
            root->n++;
        } else {
            if (root->n == root->t * 2 - 1) {     /* root is full */
                node *new_root = new node(t, false);
                split(new_root, 0, root);
                /* 更新root指针到新root */
                root = new_root;
            }
            insert_non_full(root, key);
        }
    }
    
    void remove(int key)
    {
        _remove(root, key);
    }

private:
    void _traverse(struct node *nd)
    {
        if (nd == nullptr) return;
        
        for (int i = 0; i < nd->n; i++) {
            if (!nd->leaf) {
                _traverse(nd->children[i]);
            }
            cout << nd->keys[i] << " ";
        }
        if (!nd->leaf) {   /* 最后的孩子节点 */
            _traverse(nd->children[nd->n]);
        }
    }
    
    struct node *_search(struct node *nd, int key)
    {
        int idx = 0;
        
        while (key < nd->keys[idx]) idx++;
        if (key == nd->keys[idx]) {
            return nd;
        } else {
            if (nd->leaf) return nullptr;
            else return _search(nd->children[idx], key);
        }
        
    }
    
    // 拆分 “fullchild”， 移动fullchild的中间元素到 "parent“ 的 "pidx"位置
    // Note: 需要"fullchild" key满时才能调用本函数
    void split(struct node *parent, int pidx, struct node *fullchild)
    {
        int t = fullchild->t;
        /* 准备拆分后的后半段 */
        /* 拆分后的后半段node */
        node *right_node = new node(fullchild->t, fullchild->leaf);
        /* 复制fullchild的后半段keys元素到 right_node中 */
        for (int i = 0; i < t - 1; i++) {
            right_node->keys[i] = fullchild->keys[i + t];
        }
        /* 复制fullchild的后半段children到right_node中 */
        for (int i = 0; i < t; i++) {
            right_node->children[i] = fullchild->children[i + t];
        }
        right_node->n = t - 1;
        
        /* 拆分后的前半段 */
        fullchild->n = t - 1;
        
        /* 将fullchild的中间节点移动到parent中 */
        /* parent节点空间预留-- keys搬动 */
        int i = 0;
        int mid_key = fullchild->keys[t - 1];
        while (i< parent->n && mid_key > parent->keys[i]) i++;
        for (int j = parent->n; j > i; j--) {
            parent->keys[j] = parent->keys[j - 1];
        }
        /* move */
        parent->keys[i] = mid_key;
        parent->n++;
        
        /* parent children搬动 */
        for (int j = parent->n + 1; j > i; j--) {
            parent->children[j] = parent->children[j - 1];
        }
        /* parent 链接 前半段和后半段 */
        parent->children[i] = fullchild;
        parent->children[i + 1] = right_node;
    }
    
    // 插入key的辅助函数
    // note: 调用本函数时，nd不能满
    void insert_non_full(struct node *nd, int key)
    {
        int i = nd->n - 1;
        if (nd->leaf) {        /* 叶子节点，执行插入 */
            /* 移动后半部分keys */
            while (i >= 0 && key < nd->keys[i]) {
                nd->keys[i + 1] = nd->keys[i];
                i--;
            }
            assert(i >= -1);
            nd->keys[i + 1] = key;
            nd->n++;
        } else {
            while (i >= 0 && key < nd->keys[i]) {
                i--;
            }
            assert(i >= -1);
            node *may_full_child = nd->children[i + 1];
            if (may_full_child->n == may_full_child->t * 2 - 1) {  /* child is full */
                split(nd, i + 1, may_full_child);
                if (key > nd->keys[i + 1]) {
                    i++;
                }
            }
            insert_non_full(nd->children[i + 1], key);
        }
    }
    
    
    // 在nd中找到第一个比key大或相等的key位置
    int find_key(struct node *nd, int key)
    {
        int i = 0;
        while (i < nd->n && key > nd->keys[i]) {
            i++;
        }
        return i;
    }
    
    void _remove(struct node *nd, int key)
    {
        int idx = find_key(nd, key);
        
        if (idx < nd->n && key == nd->keys[idx]) {        /* 匹配到key */
            if (nd->leaf) {
                remove_from_leaf(nd, idx);
            } else {
                remove_from_non_leaf(nd, idx);
            }
        } else {      /* key不在本节点中 */
            if (nd->leaf) {       /* 已经是叶节点，说明key不存在 */
                cerr << "key does not exit in this tree\n";
                return;
            } else {      /* 在子树中寻找 */
                bool last_child = idx == nd->n;
                
                if (nd->children[idx]->n < nd->children[idx]->t) {    /* 即将遍历的节点keys个数不足，现在进行填充 */
                    fill(nd, idx);       /* 注意填充可能更改当前nd的children数量 */
                }
                
                if (last_child && idx > nd->n) {      /* 说明最后一个节点已经和前一个节点合并，现在要在前一个节点中删除 */
                    _remove(nd->children[idx - 1], key);
                } else {  /* 正常情况 */
                    _remove(nd->children[idx], key);
                }
            }
        }
    }
    
    // nd为叶子节点，删除第idx个元素
    // Note: 调用本函数时， nd中的keys个数一定>= t
    void remove_from_leaf(struct node *nd, int idx)
    {
        for (int i = idx; i < nd->n - 1; i++) {
            nd->keys[i] = nd->keys[i + 1];
        }
        nd->n--;
    }
    
    // nd为非叶子节点，删除第idx个元素
    void remove_from_non_leaf(struct node *nd, int idx)
    {
        int key = nd->keys[idx];
        
        if (nd->children[idx]->n >= nd->children[idx]->t) {   /* 用前驱代替key */
            int pred = get_pred(nd, idx);
            nd->keys[idx] = pred;
            _remove(nd->children[idx], pred);
        } else if (nd->children[idx + 1]->n >= nd->children[idx + 1]->t) { /* 用后驱代替key */
            int succ = get_succ(nd, idx);
            nd->keys[idx] = succ;
            _remove(nd->children[idx], succ);
        } else {      /* 两个孩子都不够，选择合并 */
            merge(nd, idx);
            _remove(nd->children[idx], key);
        }
    }
    
    // 取得nd->keys[idx] 的前驱节点
    // Note：nd不能是叶子节点
    int get_pred(struct node *nd, int idx)
    {
        assert(!nd->leaf);
        struct node *cur = nd->children[idx];
        while (!cur->leaf) {
            cur = cur->children[cur->n];
        }
        return cur->keys[cur->n - 1];
    }
    
    
    // 取得nd->keys[idx]的后继节点
    // Note: nd不能是叶子节点
    int get_succ(struct node *nd, int idx)
    {
        assert(!nd->leaf);
        struct node *cur = nd->children[idx + 1];
        while (!cur->leaf) {
            cur = cur->children[0];
        }
        return cur->keys[0];
    }
    
    
    // 填充nd->children[idx]
    // Note: 调用此函数时，nd->children[idx]->n 应 <= t-1
    void fill(struct node *nd, int idx)
    {
        assert(nd->children[idx]->n <= nd->children[idx]->t - 1);
        if (idx != 0 && nd->children[idx - 1]->n >= t) { /* 向左兄弟节点借 */
            borrow_from_prev(nd, idx);
        } else if (idx != nd->n && nd->children[idx + 1]->n >= t) {      /* 向右兄弟借 */
            borrow_from_next(nd, idx);
        } else {      /* 两个兄弟都不够 */
            if (idx < nd->n) {
                merge(nd, idx);         /* 合并右兄弟 */
            } else {
                merge(nd, idx - 1);        /* 合并左兄弟 */
            }
        }
    }
    
    // 向nd->children[idx-1]借一个key，插入到nd->children[idx]中
    void borrow_from_prev(struct node *nd, int idx)
    {
        assert(idx > 0);
        struct node *child = nd->children[idx];
        struct node *sibling = nd->children[idx - 1];
        
        /* 移动"child"的所有keys，给从parent中的key留一个空间 */
        for (int i = child->n; i > 0; i--) {
            child->keys[i] = child->keys[i - 1];
        }
        /* 如果child不是叶子节点，则移动child的children指针 */
        if (!child->leaf) {
            for (int i = child->n + 1; i > 0; i--) {
                child->children[i] = child->children[i - 1];
            }
        }
        /* 插入从parent来的key */
        child->keys[0] = nd->keys[idx];
        
        /* 插入来自sibling的key到parent */
        nd->keys[idx] = sibling->keys[sibling->n - 1];
        
        /* 移动"child"的兄弟节点的最后一个孩子到"child->children[0]" */
        if (!child->leaf) {
            child->children[0] = sibling->children[sibling->n];
        }
        
        child->n++;
        sibling->n--;
    }
    
    // 向nd->children[idx+1]借一个key，插入到nd->children[idx]中
    void borrow_from_next(struct node *nd, int idx)
    {
        assert(idx + 1 <= nd->n);
        struct node *child = nd->children[idx];
        struct node *sibling = nd->children[idx + 1];
        
        /* 插入来自parent的key */
        child->keys[child->n] = nd->keys[idx];
        child->n++;
        
        /* 移动 sibling->children[0] 到 child的最后一个children */
        if (!child->leaf) {
            child->children[child->n] = sibling->children[0];
        }
        
        /* 插入兄弟节点的第一个key到parent */
        nd->keys[idx] = sibling->keys[0];
        
        /* 在兄弟节点中删除第一个key */
        for (int i = 0; i < sibling->n - 1; i++) {
            sibling->keys[i] = sibling->keys[i + 1];
        }
        /* 移动兄弟节点的children指针 */
        if (!sibling->leaf) {
            for (int i = 0; i < sibling->n; i++) {
                sibling->children[i] = sibling->children[i + 1];
            }
        }
        sibling->n--;
    }
    
    // 合并nd->children[idx]和nd->children[idx+1], 合并后，free nd->children[idx+1]
    void merge(struct node *nd, int idx)
    {
        assert(idx + 1 <= nd->n);
        struct node *child = nd->children[idx];
        struct node *sibling = nd->children[idx + 1];
        
        /* 下移parent的key到child中 */
        child->keys[child->n] = nd->keys[idx];
        child->n++;
        
        /* 在parent中删除下移了的key */
        for (int i = idx; i < nd->n - 1; i++) {
            nd->keys[i] = nd->keys[i + 1];
        }
        /* 在parent中删除sibling指针 */
        for (int i = idx+1 ; i < nd->n; i++) {
            nd->children[i] = nd->children[i + 1];
        }
        nd->n--;
        
        /* 移动sibling中的所有key到"child"中 */
        int offset = child->n;
        for (int i = 0; i < sibling->n; i++) {
            child->keys[i + offset] = sibling->keys[i];
        }
        child->n += sibling->n;
        
        /* 释放sibling空间 */
        delete sibling;
    }


private:
    struct node *root;
    int t;
};


int main()
{
    b_tree t(3); // A B-Tree with minium degree 3
    
    t.insert(1);
    t.insert(3);
    t.insert(7);
    t.insert(10);
    t.insert(11);
    t.insert(13);
    t.insert(14);
    t.insert(15);
    t.insert(4);
    t.insert(5);
    t.insert(20);
    t.insert(22);
    t.insert(2);
    t.insert(17);
    t.insert(12);
    t.insert(6);
    
    cout << "Traversal of tree constructed is\n";
    t.traverse();
    cout << endl;
    
    t.remove(6);
    cout << "Traversal of tree after removing 6\n";
    t.traverse();
    cout << endl;
    
    t.remove(13);
    cout << "Traversal of tree after removing 13\n";
    t.traverse();
    cout << endl;
    
    t.remove(7);
    cout << "Traversal of tree after removing 7\n";
    t.traverse();
    cout << endl;
    
    t.remove(4);
    cout << "Traversal of tree after removing 4\n";
    t.traverse();
    cout << endl;
    
    t.remove(2);
    cout << "Traversal of tree after removing 2\n";
    t.traverse();
    cout << endl;
    
    t.remove(16);
    cout << "Traversal of tree after removing 16\n";
    t.traverse();
    cout << endl;
    return 0;
}
