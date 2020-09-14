/**
 * Created by raven on 2020/9/14.
 */
#include "../common.h"
#include <iostream>

using namespace std;

template<typename T>
class node {
public:
    T elem;
    node *lchild;
    node *rchild;
};

template<typename T>
class bittree {
public:
    bittree();

    ~bittree();

    /* 前序遍历create tree */
    void create_pre_order();

    void preorder_traverse() const;

    void inorder_traverse() const;

    void postorder_traverse() const;

private:
    void create_tree(node<T> *&t);

    /*  */
    void preorder(node<T> *t) const;

    void inorder(node<T> *t) const;

    void postorder(node<T> *t) const;

    void free_nodes(node<T> *t);

    node<T> *root;
};

template<typename T>
bittree<T>::bittree() {
}

template<typename T>
bittree<T>::~bittree() {
    free_nodes(root);
}

template<typename T>
void bittree<T>::free_nodes(node<T> *t) {
    if(t == nullptr)  return;
    else{
        free_nodes(t->lchild);
        free_nodes(t->rchild);
        delete t;
    }
}
template<typename T>
void bittree<T>::create_pre_order() {
    create_tree(root);
}

template<typename T>
void bittree<T>::create_tree(node<T> *&t) {
    T e;
    cin >> e;
    if (e == '#') return;
    else {
        t = new node<T>();
        t->elem = e;
        create_tree(t->lchild);
        create_tree(t->rchild);
    }
}

template<typename T>
void bittree<T>::preorder_traverse() const {
    preorder(root);
    cout << "\n";
}

template<typename T>
void bittree<T>::inorder_traverse() const {
    inorder(root);
    cout << "\n";
}

template<typename T>
void bittree<T>::postorder_traverse() const {
    postorder(root);
    cout << "\n";
}

template<typename T>
void bittree<T>::preorder(node<T> *t) const {
    if (t == nullptr) return;
    else {
        cout << t->elem << " ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

template<typename T>
void bittree<T>::inorder(node<T> *t) const {
    if (t == nullptr) return;
    else {
        inorder(t->lchild);
        cout << t->elem << " ";
        inorder(t->rchild);
    }
}

template<typename T>
void bittree<T>::postorder(node<T> *t) const {
    if (t == nullptr) return;
    else {
        postorder(t->lchild);
        postorder(t->rchild);
        cout << t->elem << " ";
    }
}



