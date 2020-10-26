//
// Created by a2855 on 2020/10/26.
// 线段树实现
// 可参考：https://www.bilibili.com/video/BV1cb411t7AM?from=search&seid=12820887691963946176
//
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class seg_tree{
private:
    struct attr{    // 线段树中能包含的属性
        int max_value;  // 最大值
        int sum_value;   // 最小值
        attr():max_value(-1),sum_value(-1){}
        attr(int maxValue, int sumVale) : max_value(maxValue), sum_value(sumVale) {}
    };

    struct tree_node{
        int left, right;
        struct attr attr;

        tree_node(): left(-1), right(-1){}
        tree_node(int left, int right) : left(left), right(right) {}
    };

public:
    explicit seg_tree(const vector<int> &arr){
        this->arr = arr;
        tree.resize(arr.size() * 4);
    }

    void build_tree(){
        _build_tree(0,0,this->arr.size()-1);
    }

    // 把arr[idx] = val
    void update(int idx, int val){
        assert(idx>=0 && idx < arr.size());
        arr[idx] = val;
        _update(idx,val,0);
    }


    int query_max(int left, int right){
        assert(0 <= left && left <= right && right < arr.size());
        return _query_max(0,left,right);

    }

    int query_sum(int left, int right){
        assert(0 <= left && left <= right && right < arr.size());
        return _query_sum(0,left,right);
    }


    // 层次遍历
    void print_tree(){
        for(auto &node : tree){
            if(node.left != -1 && node.right != -1){
                cout << "[" << node.left << "--" << node.right << "]: ";
                cout << "max_value:" << node.attr.max_value << ",";
                cout << "sum_vlaue:" << node.attr.sum_value << "\n";
            }
        }
    }

private:
    void _build_tree(int node, int left, int right){
        tree[node].left = left;
        tree[node].right = right;
        if(left == right){
            tree[node].attr.max_value = arr[left];
            tree[node].attr.sum_value = arr[left];
        }else{
            int mid = (left+right)/2;
            int lchild = node << 1 | 1;
            int rchild = (node +1) << 1;
            // build left
            _build_tree(lchild, left,mid);
            // build right
            _build_tree(rchild,mid+1,right);
            tree[node].attr.max_value = max(tree[lchild].attr.max_value,tree[rchild].attr.max_value);
            tree[node].attr.sum_value = tree[lchild].attr.sum_value + tree[rchild].attr.sum_value;
        }
    }

    void _update(int idx, int val, int node){
        int left = tree[node].left;
        int right = tree[node].right;
        if(left == right){
            tree[node].attr.max_value = val;
            tree[node].attr.sum_value = val;
        }else{
            int mid = (left+right)/2;
            int lchild = node << 1 | 1;
            int rchild = (node+1) << 1;
            if(idx <= mid){
                // 更新左分支
                _update(idx,val,lchild);
            }else{
                // 更新右分支
                _update(idx,val,rchild);
            }
            // 更新value
            tree[node].attr.max_value = max(tree[lchild].attr.max_value,tree[rchild].attr.max_value);
            tree[node].attr.sum_value = tree[lchild].attr.sum_value + tree[rchild].attr.sum_value;
        }
    }

    int _query_max(int node, int left, int right){
        if(tree[node].left == left && tree[node].right == right){
            return tree[node].attr.max_value;
        }

        int mid = tree[node].left + tree[node].right;
        int lchild = node << 1 | 1;
        int rchild = (node+1) << 1;
        if(right <= mid){
           return _query_max(lchild,left,right);
        }
        if(left > mid){
            return _query_max(rchild, left,right);
        }
        // 中间节点 left <= mid < right
        return max(_query_max(lchild,left,mid),_query_max(rchild,mid+1,right));
    }

    int _query_sum(int node, int left, int right){
        if(tree[node].left == left && tree[node].right == right){
            return tree[node].attr.sum_value;
        }

        int mid = (tree[node].left + tree[node].right)/2;
        int lchild = node << 1 | 1;
        int rchild = (node+1) << 1;
        if(right <= mid){
            return _query_sum(lchild,left,right);
        }
        if(left > mid){
            return _query_sum(rchild, left,right);
        }
        // 中间节点 left <= mid < right
        return _query_sum(lchild,left,mid) + _query_sum(rchild,mid+1,right);
    }

private:
    vector<int> arr;
    vector<tree_node> tree;
};

int main()
{
    vector<int> arr{1,3,5,7,9,10};
    seg_tree tree(arr);
    tree.build_tree();
    tree.print_tree();

    cout << endl;
    tree.update(0,100);
    tree.print_tree();

    cout << endl;
    cout << 0 << "--" << 5 << " max value: " << tree.query_max(0,5) << endl;
    cout << 2 << "--" << 5 << " sum value: " << tree.query_sum(2,5) << endl;

    return 0;
}