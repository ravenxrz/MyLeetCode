/**
 * Created by raven on 2020/9/24.
 * 静态次优查找树
 *
 * 设各关键字的权重为 w_i
 * 则构造一颗次优查找树的核心为, 选择第i个关键字，使得
 * P_{\delta} = abs(sum_{i+1}^{hight}w_j - sum_{low}^{i-1}) 最小
 * 然后递归的构造左子树和右子树
 */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct key_node{
    string key;
    int weight;

    key_node(): key(),weight(-1) {}
};

class second_optimal_search_tree{
private:
    struct node{
        struct key_node knode;
        struct node *lchild, *rchild;

        node() {
           lchild = rchild = nullptr;
        }
    };
public:
    second_optimal_search_tree()=default;

    bool create_search_tree(vector<key_node> &knodes){
        /* sort first */
        sort(knodes.begin(),knodes.end(),[](struct key_node &node1, struct key_node &node2){
            return node1.key.compare(node2.key) < 0;
        });

        /* 求累计权重和 */
        vector<int> sw(knodes.size(),0);
        sw[0] = knodes[0].weight;
        for(int i = 1;i<sw.size();i++){
            sw[i] = sw[i-1] + knodes[i].weight;
        }

        /* build tree */
        _create_tree(knodes,sw,0,knodes.size()-1,root);

        return true;
    }

    void print_tree(){
        _print_tree(root);
    }

    // if failed, return null
    const struct key_node *search(string key) const{
        struct node *cur = root;
        while(cur != nullptr && cur->knode.key != "#"){
            if(cur->knode.key.compare(key) < 0){
                cur = cur->rchild;
            }else if(cur->knode.key.compare(key) > 0){
                cur = cur->lchild;
            }else{
                return &cur->knode;
            }
        }
        return nullptr;
    }
private:

    void _print_tree(struct node *t){
        if(t == nullptr) return;
        cout << t->knode.key << " " << t->knode.weight << "\n";
        _print_tree(t->lchild);
        _print_tree(t->rchild);
    }

    void _create_tree(const vector<key_node> &knodes, const vector<int> &sw, int low, int high, struct node *&t){
        t = new node;
        if(low > high){
            return ;
        }
        else if(low == high){      /* 叶节点 */
            t->knode.key = knodes[low].key;
            t->knode.weight = knodes[low].weight;
            t->lchild = t->rchild = new node;       /* 下面3行不用写，这里是为了打印tree时更好的推断树的形状所以添加的 */
            t->lchild->knode.key = "#";
            t->rchild->knode.weight = -1;
        }
        else       /* 中间节点 */
        {
            int min_idx = low;
            int min_delta = abs(sw[high] - sw[low+1]);  /* 用low作root */
            /* 确定最小idx */
            for(int i = low+1;i<=high;i++){
                int rw = sw[high] - sw[i];
                int lw = sw[i-1] - sw[low] + knodes[low].weight;
                if(min_delta > abs(rw-lw)){
                    min_idx = i;
                    min_delta = rw - lw;
                }
            }

            t->knode.weight = knodes[min_idx].weight;
            t->knode.key = knodes[min_idx].key;
            /* 构造左子树和右子树 */
            _create_tree(knodes,sw,low,min_idx-1,t->lchild);
            _create_tree(knodes,sw,min_idx+1,high,t->rchild);
        }
    }


private:
    struct node *root;
};

int main()
{
    fstream fin("/home/raven/Projects/Clion/MyLeetCode/0.DataStructure/7.SearchTable/StaticSearchTable/second_optimal_search_tree_input.txt");
    int n;
    fin >> n;
    vector<key_node> knodes;
    while(!fin.eof()){
        struct key_node node;
        fin >> node.key >> node.weight;
        knodes.push_back(node);
    }

    second_optimal_search_tree tree{};
    tree.create_search_tree(knodes);
    tree.print_tree();

    const key_node *pNode = tree.search("A");
    if(pNode != nullptr){
        cout << pNode->key << " "<< pNode->weight << "\n";
    }else{
        cout << "A not found";
    }
    pNode = tree.search("K");
    if(pNode != nullptr){
        cout << pNode->key << " "<< pNode->weight << "\n";
    }else{
        cout << "K not found";
    }

    return 0;
}

