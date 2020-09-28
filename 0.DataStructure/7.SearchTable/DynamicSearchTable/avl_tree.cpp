/**
 * Created by a2855 on 2020/9/28.
 */
#include <iostream>
#include <vector>

using namespace std;

class avl_tree {
private:
    struct node {
        int key;
        struct node *lchild;
        struct node *rchild;
        int height;         /* 子树高度 */
        
        explicit node(int key) : key(key)
        {
            lchild = rchild = nullptr;
            height = 1;
        }
    };

private:
    void _post_order_print(struct node *t)
    {
        if (t == nullptr) return;
        _post_order_print(t->lchild);
        cout << t->key << " ";
        _post_order_print(t->rchild);
    }
    
    int height(struct node *t) const
    {
        return t == nullptr ? 0 : t->height;
    }
    
    // get balance factor of node t, assume 1 indicating the height of
    // left child tree is larger than the right, -1 vice versa.
    int get_balance(struct node *t) const
    {
        return height(t->lchild) - height(t->rchild);
    }
    
    // 以node t作为根右旋，返回右旋后的根节点
    struct node *right_rotate(struct node *t)
    {
        struct node *lc = t->lchild;
        t->lchild = lc->rchild;
        lc->rchild = t;
        
        t->height = 1 + max(height(t->lchild), height(t->rchild));
        lc->height = 1 + max(height(lc->lchild), height(lc->rchild));
        return lc;
    }
    
    // 以node t作为根左旋，返回左旋后的根节点
    struct node *left_rotate(struct node *t)
    {
        struct node *rc = t->rchild;
        t->rchild = rc->lchild;
        rc->lchild = t;
        
        t->height = 1 + max(height(t->lchild), height(t->rchild));
        rc->height = 1 + max(height(rc->lchild), height(rc->rchild));
        return rc;
    }
    
    // 插入key节点，返回插入修改后的root节点
    struct node *_insert(struct node *t, int key)
    {
        if (t == nullptr) {
            return new node(key);
        } else {
            /* 正常bst递归插入 */
            if (key < t->key) {
                t->lchild = _insert(t->lchild, key);
            } else if (key > t->key) {
                t->rchild = _insert(t->rchild, key);
            } else {
                return t;       /* 忽略已经有的key */
            }
            
            /* 插入后，更新当前节点的height */
            t->height = 1 + max(height(t->lchild), height(t->rchild));
            
            /* 获取平衡因子，查看是否需要旋转来保持avl特性 */
            int balance = get_balance(t);
            
            /* 根据balance来rotate */
            if (balance > 1 && key < t->lchild->key) {    /* 左左-- 单右旋即可 */
                return right_rotate(t);
            } else if (balance > 1 && key > t->lchild->key) {      /* 左右 -- 先左后右  */
                t->lchild = left_rotate(t->lchild);
                return right_rotate(t);
            } else if (balance < -1 && key > t->rchild->key) {  /* 右右--单左旋 */
                return left_rotate(t);
            } else if (balance < -1 && key < t->rchild->key) {  /* 右左--先右后左 */
                t->rchild = right_rotate(t->rchild);
                return left_rotate(t);
            }
            return t;
        }
    }
    
    // 中序后继节点
    struct node *in_order_successor(struct node *t)
    {
        struct node *succ = t->rchild;
        while (succ->lchild != nullptr) {
            succ = succ->lchild;
        }
        return succ;
    }
    
    // 删除key所在节点，返回修改后的子树root节点
    struct node *_remove(struct node *t, int key)
    {
        if (t == nullptr) return t;
        else {
            /* 执行bst的删除 */
            if (key < t->key) {
                t->lchild = _remove(t->lchild, key);
            } else if (key > t->key) {
                t->rchild = _remove(t->rchild, key);
            } else       /* key相等，需要删除 */
            {
                if (t->rchild == nullptr || t->lchild == nullptr) {   /* 叶子节点，或者单孩子节点 */
                    struct node *temp = t->lchild != nullptr ? t->lchild : t->rchild;
                    if (temp == nullptr) {    /* 叶子节点 */
                        temp = t;
                        t = nullptr;
                    } else {              /* 单孩子节点 */
                        t->key = temp->key;
                        if(t->lchild == temp) t->lchild = nullptr;
                        else t->rchild = nullptr;
                    }
                    free(temp);
                    return t;
                } else        /* 中间节点 */
                {
                    struct node *succ = in_order_successor(t);
                    t->key = succ->key;
                    t->rchild = _remove(t->rchild, succ->key);
                }
            }
            
            /* 更新height */
            t->height = 1 + max(height(t->lchild), height(t->rchild));
            
            /* 获取balance */
            int balance = get_balance(t);
            
            /* re-balance */
            /* 根据balance来rotate */
            /* get_balance(t->lchild) = 0 时，代表单右旋或先左后右均可 */
            if (balance > 1 && get_balance(t->lchild) >= 0) {        /* 左左-- 单右旋 */
                return right_rotate(t);
            } else if (balance > 1 && get_balance(t->lchild) < 0) {      /* 左右 -- 先左后右  */
                t->lchild = left_rotate(t->lchild);
                return right_rotate(t);
            } else if (balance < -1 && get_balance(t->rchild) <= 0) {  /* 右右--单左旋 */
                return left_rotate(t);
            } else if (balance < -1 && get_balance(t->rchild) > 0) {  /* 右左--先右后左 */
                t->rchild = right_rotate(t->rchild);
                return left_rotate(t);
            }
        }
        return t;
    }

public:
    avl_tree() : root(nullptr) {}
    
    void insert(int key)
    {
        if (root != nullptr) {
            root = _insert(root, key);
        } else {
            root = new node(key);
        }
    }
    
    void remove(int key)
    {
        root = _remove(root, key);
    }
    
    void post_order_print()
    {
        _post_order_print(root);
        cout << endl;
    }

private:
    struct node *root;
};


int main()
{
    avl_tree tree;
//    vector<int> vec{10,20,5,6,6516,276};
    vector<int> vec{6, 9, 8, 412, 1, 41, 439, 10, 5, 20, 246, 276, -1, 7};
//    vector<int> vec{10,20,5,6,15,30,25};
    
    for (int i = 0; i < vec.size(); i++) {
        tree.insert(vec[i]);
    }
    tree.post_order_print();
    
    tree.remove(5);
    tree.post_order_print();
    
    tree.remove(10);
    tree.post_order_print();
    
    tree.remove(439);
    tree.post_order_print();
    
    return 0;
}