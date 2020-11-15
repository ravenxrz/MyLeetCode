//
// Created by a2855 on 2020/11/15.
//

#include <iostream>
#include <stack>
using namespace std;

class btree{
private:
    struct node{
        int val;
        struct node *left,*right;

        explicit node(int val) : val(val),left(nullptr),right(nullptr) {}

        node(int val, node *left, node *right) : val(val), left(left), right(right) {}
    };
public:
    // 前序创建树
    void create_tree(){
        cout << "input tree node val:";
        _create_tree(root);
    }

    void pre_order_traverse(){
        // first: node * 存储树节点， second : int 当前节点下一次遍历的方向：0-本节点 1-lchild 2-rchild >=3 无
        stack<pair<node *, int>> stk;
        stk.push({root,0});

        while(!stk.empty()){
            struct node *cur = stk.top().first;
            int &direction = stk.top().second;
            if(cur == nullptr){
                stk.pop();
                continue;
            }
            if(direction == 0){
                cout << cur->val << " ";
            }
            direction++;

            if(direction== 1){      // left child
                stk.push({cur->left,0});
            }else if(direction == 2){    // right child
                stk.push({cur->right,0});
            }else {     // 孩子节点遍历完，退栈
                stk.pop();
            }
        }
    }

    void in_order_traverse(){
        // first: node * 存储树节点， second : int 当前节点下一次遍历的方向：0-本节点 1-lchild 2-rchild >=3 无
        stack<pair<node *, int>> stk;
        stk.push({root,0});

        while(!stk.empty()){
            struct node *cur = stk.top().first;
            int &direction = stk.top().second;
            if(cur == nullptr){
                stk.pop();
                continue;
            }
            if(direction == 1){
                cout << cur->val << " ";
            }
            direction++;

            if(direction== 1){      // left child
                stk.push({cur->left,0});
            }else if(direction == 2){    // right child
                stk.push({cur->right,0});
            }else {     // 孩子节点遍历完，退栈
                stk.pop();
            }
        }
    }

    void post_order_traverse() {
        // first: node * 存储树节点， second : int 当前节点下一次遍历的方向：0-本节点 1-lchild 2-rchild >=3 无
        stack<pair<node *, int>> stk;
        stk.push({root, 0});

        while (!stk.empty()) {
            struct node *cur = stk.top().first;
            int &direction = stk.top().second;
            if (cur == nullptr) {
                stk.pop();
                continue;
            }
            if (direction == 2) {
                cout << cur->val << " ";
            }
            direction++;

            if (direction == 1) {      // left child
                stk.push({cur->left, 0});
            } else if (direction == 2) {    // right child
                stk.push({cur->right, 0});
            } else {     // 孩子节点遍历完，退栈
                stk.pop();
            }
        }
    }

private:
    void _create_tree(struct node *&nd){
        int val;
        cin >> val;
        if(val == -1){
            return;
        }
        nd = new node(val);
        _create_tree(nd->left);
        _create_tree(nd->right);
    }




private:
    struct node *root;
};


int main()
{
    btree bt;
    // 1 2 3 -1 -1 -1 4 -1 -1
    bt.create_tree();
    bt.pre_order_traverse();
    cout << endl;
    bt.in_order_traverse();
    cout << endl;
    bt.post_order_traverse();
    cout << endl;

    return 0;
}