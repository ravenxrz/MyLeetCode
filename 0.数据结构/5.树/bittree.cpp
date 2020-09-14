/**
 * Created by raven on 2020/9/14.
 */
#include <iostream>
#include <stack>

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

    /* 递归 */
    void preorder(node<T> *t) const;

    void inorder(node<T> *t) const;

    void postorder(node<T> *t) const;

    /* 非递归 */
    void preorder_stack() const;

    void inorder_stack() const;

    void postorder_stack() const;


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
//    preorder(root);
    preorder_stack();
    cout << "\n";
}

template<typename T>
void bittree<T>::inorder_traverse() const {
//    inorder(root);
    inorder_stack();
    cout << "\n";
}

template<typename T>
void bittree<T>::postorder_traverse() const {
//    postorder(root);
    postorder_stack();
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

template<typename T>
void bittree<T>::preorder_stack() const {
    stack<node<T> *> sk;
    node<T> *p = root;
    while(p != nullptr || !sk.empty()){
        if(p != nullptr){
            sk.push(p);
            cout << p->elem << " ";
            p = p->lchild;
        }else{
            p = sk.top();
            sk.pop();
            p = p->rchild;
        }
    }
}

template<typename T>
void bittree<T>::inorder_stack() const {
    stack<node<T> *> sk;
    node<T> *p = root;
    while(p != nullptr || !sk.empty()){
        if(p != nullptr){
            sk.push(p);
            p = p->lchild;
        }else{
            p = sk.top();
            sk.pop();
            cout << p->elem << " ";
            p = p->rchild;
        }
    }
}


/**
 * 后序非递归遍历相对较难。需要得到先序遍历和逆后序遍历的关系：
 * 如一颗树： A B # C # # D # #(先序创建，#为结束符号)
 * 先序遍历为: A B C D
 * 后序遍历为： C B A D
 * 逆后序遍历为: D A B C
 * 则可得逆后序遍历是树交换左右子树后的先序遍历结果。  （好好理解这句话，可以画个图来理解）
 * 所以，我们可以先得到树交换左右子树后的先绪遍历结果（即得到逆后序遍历），然后反转结果即为逆后序遍历。
 * @tparam T
 */
template<typename T>
void bittree<T>::postorder_stack() const {
    stack<node<T> *> sk;
    stack<node<T> *> result;
    node<T> *p = root;
    while(p!=nullptr || !sk.empty()){
        if(p!=nullptr){
            sk.push(p);
            result.push(p);
            p = p->rchild;
        }else{
            p = sk.top();
            sk.pop();
            p = p->lchild;
        }
    }

    /* print result */
    while(!result.empty()){
        p = result.top();
        result.pop();
        cout << p->elem << " ";
    }
}



