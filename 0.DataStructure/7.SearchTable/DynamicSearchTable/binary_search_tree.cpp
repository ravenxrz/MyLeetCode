/**
 * Created by a2855 on 2020/9/25.
 * 二叉search tree
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
using namespace std;

template<typename T>
class binary_search_tree{
private:
    struct node{
        T key;
        struct node *parent, *lchild, *rchild;
    
        node(T key) : key(key) {
            parent = lchild = rchild = nullptr;
        }
    };
public:
    binary_search_tree():root(nullptr){}
    
    ~binary_search_tree(){
        free_tree(root);
    }
    
    void create_tree(const vector<T> &keys){
        for(const auto &key : keys){
            insert(key);
        }
    }
    
    void insert(T key){
        _insert(nullptr,root,key);
    }
    
    void print_tree_pre_order(){
          if(root == nullptr) return;       /* empty tree */
        
          stack<node *> sk;
          struct node *p = root;
          while(p != nullptr || !sk.empty()){
                if(p == nullptr){
                    p = sk.top();
                    sk.pop();
                    p = p->rchild;
                }else{
                    cout << p->key << " ";
                    sk.push(p);
                    p = p->lchild;
                }
          }
          cout << "\n";
    }
    
    void print_tree_in_order(){
        if(root == nullptr) return;
        
        stack<node *> sk;
        struct node *p = root;
        
        while(p != nullptr || !sk.empty()){
            if(p == nullptr){
                p = sk.top(); sk.pop();
                cout << p->key << " ";
                p = p->rchild;
            }else{
                sk.push(p);
                p = p->lchild;
            }
        }
        cout << "\n";
    }
    
    bool search(T key){
        /* 非递归search */
        struct node *p = root;
        while(p != nullptr){
            if(key  == p->key) return true;
            else if(key < p->key ) p = p->lchild;
            else if(key > p->key) p = p->rchild;
        }
        return false;
    }
    
    void remove(T key){
        /* first, find the key */
        struct node *p = root;
        while(p != nullptr){
            if(key  == p->key) break;
            else if(key < p->key ) p = p->lchild;
            else if(key > p->key) p = p->rchild;
        }
        if(p == nullptr){
            cerr<<"no key found\n";
            return;
        }
        
        /* 判断是哪种case */
        if(p->lchild == nullptr && p->rchild == nullptr){   /* p 是 leaf node */
            remove_case1(p);
        }else if(p->lchild != nullptr && p->rchild != nullptr){ /* p是中间节点，左右孩子均不为nullptr */
            remove_case2(p);
        }else{      /* p是中间节点，左或右孩子不为nullptr */
            remove_case3(p);
        }
    }
    
private:
    // p是叶子节点
    void remove_case1(struct node *p){
        if(p == root){
            delete p;
            root = nullptr;
            return;
        }
        
        struct node *f = p->parent;
        if(f->lchild  == p){
            f->lchild = nullptr;
        }else if(f->rchild == p){
            f->rchild = nullptr;
        }
        delete p;
    }
    
    // p是中间节点，左右孩子均不为nullptr
    void remove_case2(struct node *p){
        /* 用前驱节点代替本节点 */
        struct node *pre = p->lchild;
        while(pre->rchild != nullptr) pre = pre->rchild;
        p->key = pre->key;
        
        if(pre->lchild == nullptr && pre->rchild == nullptr){
            remove_case1(pre);
        }else{
            remove_case3(pre);
        }
    }
    
    // p是中间节点，左或右孩子不为nullptr
    void remove_case3(struct node *p){
        struct node *child = p->lchild == nullptr ? p->rchild : p->lchild;
        if(p == root){
            root = child;
            free(p);
            return;
        }
        
        struct node *f = p->parent;
        if(f->lchild == p ){
            f->lchild = child;
        }else if(f->rchild  == p){
            f->rchild = child;
        }
        child->parent = f;
        delete p;
    }
    
    void _insert(struct node *f, struct node *&t, T key){
        if(t == nullptr){
            t = new node(key);
            t->parent = f;
            return;
        }
        
        if(key == t->key) return;
        else if(key < t->key) _insert(t, t->lchild,key);
        else if(key > t->key) _insert(t,t->rchild,key);
    }
    
    void free_tree(struct node * t){
        if(t == nullptr) return;
        free_tree(t->lchild);
        free_tree(t->rchild);
        assert(t != nullptr);
        delete t;
    }
    
private:
    struct node *root;
};

int main()
{
    vector<int> vec{10,5,4,15,14,16};
    binary_search_tree<int> tree;
    tree.create_tree(vec);
    tree.print_tree_pre_order();
    tree.print_tree_in_order();
    cout <<tree.search(10) << "\n";
    cout << tree.search(6) << "\n";
    
    tree.remove(10);
    tree.print_tree_in_order();
    tree.remove(15);
    tree.remove(5);
    tree.remove(4);
    tree.remove(14);
    tree.print_tree_in_order();
    
    
    return 0;
}

