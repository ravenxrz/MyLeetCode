//
// Created by a2855 on 2020/10/26.
// 线段树 求和  lazytag
//
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class seg_tree {
private:
    struct tree_node {
        int sum_value;
        int left, right;
        int lazy_tag{};

        tree_node() : left(-1), right(-1), sum_value(-1), lazy_tag(0) {}

        tree_node(int left, int right, int sum_value) : left(left), right(right), sum_value(sum_value), lazy_tag(0) {}
    };

public:
    seg_tree(const vector<int> &arr) {
        this->arr = arr;
        tree.resize(4 * arr.size());
        _build_tree(0, 0, arr.size()-1);
    }

    // 层次遍历
    void print_tree() {
        for(int i = 0;i<tree.size();i++){
            tree_node &node = tree[i];
            if (node.left != -1 && node.right != -1) {
                if(node.lazy_tag != 0){
                    push_down(i);
                }
                cout << i << ":" << " [" << node.left << "--" << node.right << "] sum: " << node.sum_value << "\n";
            }
        }
    }

    // 单点更新
    void update_point(int idx, int val){
        assert(0<=idx && idx < arr.size());
        arr[idx] = val;
        _update_point(0,idx,val);
    }

    int query_point(int idx){
        assert(0<=idx && idx < arr.size());
        return query_sum(idx,idx);
    }

    // 段相加
    void update_sum(int left, int right, int s) {
        assert(0 <= left && left <= right && right <= arr.size()-1);
        // arr modify
        for (int i = left; i <= right; i++) {
            arr[i] += s;
        }
        // tree modify
        _update_sum(0, left, right, s);
    }


    int query_sum(int left, int right) {
        assert(0 <= left && left <= right && right <= arr.size()-1);
        return _query_sum(0, left, right);
    }

private:
    void _build_tree(int node, int left, int right) {
        tree[node].left = left;
        tree[node].right = right;
        if (left == right) {  // 叶子节点
            tree[node].sum_value = arr[left];
            tree[node].lazy_tag = 0;
        } else {
            int mid = (left + right) / 2;
            _build_tree(node << 1 | 1, left, mid);
            _build_tree((node + 1) << 1, mid + 1, right);
            // push up ops
            push_up(node);
        }
    }


    void push_down(int node) {
        // 下发到下一层
        int lchild = node << 1 | 1;
        int rchild = (node + 1) << 1;
        tree[lchild].sum_value += (tree[lchild].right - tree[lchild].left + 1) * tree[node].lazy_tag;
        tree[rchild].sum_value += (tree[rchild].right - tree[rchild].left + 1) * tree[node].lazy_tag;
        tree[lchild].lazy_tag += tree[node].lazy_tag;
        tree[rchild].lazy_tag += tree[node].lazy_tag;
        tree[node].lazy_tag = 0;
    }

    void push_up(int node) {
        tree[node].sum_value = tree[node << 1 | 1].sum_value + tree[(node + 1) << 1].sum_value;
    }

    void _update_point(int node,int idx, int val){
        int left = tree[node].left;
        int right = tree[node].right;
        if(left == right){  // 根节点，不用管tag
            tree[node].sum_value = val;
            return;
        }else{
            if(tree[node].lazy_tag != 0){
                push_down(node);
            }
            int mid = (left + right)/2;
            int lchild = node << 1 | 1;
            int rchild = (node+1) << 1;
            if(idx <= mid){ // 左子树
                _update_point(lchild,idx,val);
            }else if(idx > mid){
                _update_point(rchild,idx,val);
            }
            // 下层更新完，需要push up
            push_up(node);
        }
    }

    void _update_sum(int node, int left, int right, int s) {
        // lazy tag
        if (left <= tree[node].left && right >= tree[node].right) {   // 如果当前要更新的区间，包含了树节点
            tree[node].sum_value += (tree[node].right - tree[node].left + 1) * s;
            tree[node].lazy_tag += s;
        } else { // 当前要更新的区间没有包含树结点
            // lazy tag push down
            if (tree[node].lazy_tag != 0)
                push_down(node);
            int mid = (tree[node].left + tree[node].right) / 2;
            int lchild = node << 1 | 1;
            int rchild = (node + 1) << 1;
            if (right <= mid) {  // 完全在左子树
                _update_sum(lchild, left, right, s);
            } else if (left > mid) { // 完全在右子树
                _update_sum(rchild, left, right, s);
            } else {
                // 拆分
                _update_sum(lchild, left, mid, s);
                _update_sum(rchild, mid + 1, right, s);
            }
            // push up
            push_up(node);
        }
    }

    int _query_sum(int node, int left, int right) {
        if (tree[node].left == left && tree[node].right == right) {
            return tree[node].sum_value;
        } else {
            // query 过程中，可能需要下发lazy tag
            if (tree[node].lazy_tag != 0) {
                push_down(node);
            }
            int mid = (tree[node].left + tree[node].right) / 2;
            int lchild = node << 1 | 1;
            int rchild = (node + 1) << 1;
            if (right <= mid) {     // 完全在左子树
                return _query_sum(lchild, left, right);
            } else if (left > mid) {   // 完全在右子树
                return _query_sum(rchild, left, right);
            } else {  // 中间
                return _query_sum(lchild, left, mid) + _query_sum(rchild, mid + 1, right);
            }
        }
    }


private:
    vector<int> arr;
    vector<tree_node> tree;

};


int main() {
    vector<int> arr{1, 3, 5, 7, 9};
    seg_tree tree(arr);
    tree.print_tree();

//    cout << endl;
//    tree.update_sum(1,2,10);
//    tree.print_tree();

    cout << endl;
    tree.update_sum(0,4,10);
    tree.print_tree();

    cout << endl;
    cout << tree.query_sum(0,4) << endl;

    cout << endl;
    tree.update_point(4,10);
    tree.print_tree();

    cout << endl;
    cout << tree.query_point(4) << endl;


    return 0;
}
