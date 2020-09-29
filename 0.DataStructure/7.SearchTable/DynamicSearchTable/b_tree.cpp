/**
 * Created by a2855 on 2020/9/29.
 * B tree
 * 实现说明：
 * 使用最小度 t 来定义一个node的key数量range
 * 使用提前split来执行插入，避免多次 IO（常规split可能造成级联的split）
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

struct node{
    vector<int> keys;       /* keys 数组 */
    vector<node *> children;        /* child 指针, 数量为keys的数量+1 */
    int t;                  /* 最小度定义法，用于维护节点的key number range */
    bool leaf;              /* 是否是孩子节点 */
    int n;                  /* 当前持有key的数量 */
    /* 实际上还应该包含一个value指针数组，不过要理解Btree，并不需要它 */
    
    node(int t, bool leaf) : t(t), leaf(leaf) {
        keys.resize(2*t -1,-1);
        children.resize(2*t,nullptr);
        n = 0;
    }
};

class b_tree{
public:
    b_tree(int t) : t(t),root(nullptr) {
        assert(t>=2);
    }
    
    void traverse(){
        _traverse(root);
    }
    
    struct node * search(int key){
        return _search(root,key);
    }
    
    void insert(int key){
        if(root == nullptr){
            root = new node(t,true);
            root->keys[0] = key;
            root->n ++;
        }else{
           if(root->n == root->t *2 -1){     /* root is full */
               node *new_root = new node(t,false);
               split(new_root,0,root);
               /* 更新root指针到新root */
               root = new_root;
           }
           insert_non_full(root,key);
        }
    }
    
private:
    void _traverse(struct node *nd){
        if(nd == nullptr) return;
        
        for(int i = 0;i<nd->n;i++){
            if(!nd->leaf){
                _traverse(nd->children[i]);
            }
            cout << nd->keys[i]<<" ";
        }
        if(!nd->leaf){   /* 最后的孩子节点 */
            _traverse(nd->children[nd->n]);
        }
    }
    
    struct node *_search(struct node *nd, int key){
        int idx = 0;
        
        while(key < nd->keys[idx]) idx++;
        if(key == nd->keys[idx]){
            return nd;
        }else{
            if(nd->leaf) return nullptr;
            else return _search(nd->children[idx], key);
        }
        
    }
    
    // 拆分 “fullchild”， 移动fullchild的中间元素到 "parent“ 的 "pidx"位置
    // Note: 需要"fullchild" key满时才能调用本函数
    void split(struct node *parent, int pidx, struct node *fullchild){
        int t = fullchild->t;
        /* 准备拆分后的后半段 */
        /* 拆分后的后半段node */
        node *right_node = new node(fullchild->t,fullchild->leaf);
        /* 复制fullchild的后半段keys元素到 right_node中 */
        for(int i = 0;i<t-1;i++){
            right_node->keys[i] = fullchild->keys[i+t];
        }
        /* 复制fullchild的后半段children到right_node中 */
        for(int i = 0;i<t;i++){
            right_node->children[i] = fullchild->children[i+t];
        }
        right_node->n = t-1;
        
        /* 拆分后的前半段 */
        fullchild->n = t-1;
        
        /* 将fullchild的中间节点移动到parent中 */
        /* parent节点空间预留-- keys搬动 */
        int i = 0;
        int mid_key = fullchild->keys[t-1];
        while(mid_key < parent->keys[i]) i++;
        for(int j = parent->n;j>i;j--){
            parent->keys[j] = parent->keys[j-1];
        }
        /* move */
        parent->keys[i] = mid_key;
        parent->n++;
        
        /* parent children搬动 */
        for(int j = parent->n+1;j>i;j--){
            parent->children[j] = parent->children[j-1];
        }
        /* parent 链接 前半段和后半段 */
        parent->children[i] = fullchild;
        parent->children[i+1] = right_node;
    }
    
    // 插入key的辅助函数
    // note: 调用本函数时，t不能满
    void insert_non_full(struct node *nd, int key){
        int i = nd->n - 1;
        if(nd->leaf){        /* 叶子节点，执行插入 */
            /* 移动后半部分keys */
            while(i>=0 && key < nd->keys[i]){
                nd->keys[i + 1] = nd->keys[i];
                i--;
            }
            assert(i>=-1);
            nd->keys[i + 1] = key;
            nd->n++;
        }else{
            while(i>=0 && key < nd->keys[i]){
                i--;
            }
            assert(i>=-1);
            node *may_full_child = nd->children[i+1];
            if(may_full_child->n == may_full_child->t*2 -1){  /* child is full */
                split(nd,i+1,may_full_child);
                if(key > nd->keys[i+1]){
                    i++;
                }
            }
            insert_non_full(nd->children[i+1],key);
        }
    }
    
private:
    struct node *root;
    int t;
};


int main()
{
    b_tree tree(3);
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    
    cout << "Traversal of the constucted tree is ";
    tree.traverse();
    
    int k = 6;
    (tree.search(k) != nullptr)? cout << "\nPresent" : cout << "\nNot Present";
    
    k = 15;
    (tree.search(k) != nullptr)? cout << "\nPresent" : cout << "\nNot Present";
    
    return 0;
    
    return 0;
}
