/**
 * huffman编码
 * note:huffman编码的结果可能不止一种，但是最终的路径权重和肯定是一样的
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T>
class node {
public:
    node(float weight, T data) : weight(weight), data(data)
    {
        lchild = nullptr;
        rchild = nullptr;
    }

public:
    float weight;
    T data;
    node<T> *parent, *lchild, *rchild;
};

template<typename T>
class huffman_tree {
public:
    huffman_tree()
    {
        root = nullptr;
    }
    
    void create_huffman_tree(const string &path)
    {
        char c;
        float weight;
        node<T> *p;
        /* 输入 */
        string line;
        ifstream fin(path);
        if (!fin) return;
        while (1) {
            fin >> c >> weight;
            if (c == '#') break;
            
            p = new node<char>(weight, c);
            const auto &iter = find_if(node_vec.begin(), node_vec.end(), [&](node<char> *np) {
                return np->weight <= p->weight;
            });
            node_vec.insert(iter, p);
        }
        
        /* print input */
        for(const auto &v : node_vec){
            cout << v->data << " "<< v->weight << " ";
        }
        cout<< "\n";
        
        /* create tree */
        node<T> *node1, *node2;
        while (node_vec.size() != 1) {
            node1 = node_vec[node_vec.size() - 1];      /* 最小 */
            node2 = node_vec[node_vec.size() - 2];      /* 次小 */
            node_vec.erase(node_vec.end() - 1);
            node_vec.erase(node_vec.end() - 1);
            
            p = new node<T>(node1->weight + node2->weight, '#');
            p->lchild = node1;
            p->rchild = node2;
            node1->parent = p;
            node2->parent = p;
            /* 插入到合适的位置 */
            const auto &iter = find_if(node_vec.begin(), node_vec.end(), [&](node<T> *np) {
                return np->weight < p->weight;
            });
            node_vec.insert(iter, p);
        }
        root = node_vec.front();
    }
    
    void print_encode()
    {
        if (root != nullptr) _print_code(root, "");
    }
    
    void print_decode(const string &code)
    {
        const int len = code.length();
        int idx = -1;
        if (root == nullptr) return;
        
        while (idx != len - 1) {
            idx = _print_decode(root, code, idx);
            if (idx == -1) {
                cout << "decode error\n";
                break;
            }
        }
    }

private:
    void _print_code(node<T> *np, string code)
    {
        if (np->lchild == nullptr || np->rchild == nullptr) {
            cout << "code:" << code << " " << np->data << " " << np->weight << "\n";
            return;
        } else {
            _print_code(np->lchild, code + "0");
            _print_code(np->rchild, code + "1");
        }
    }
    
    int _print_decode(node<T> *np, const string &code, int idx)
    {
        if (np->lchild == nullptr || np->rchild == nullptr) {
            cout << np->data << "\n";
            return idx;
        }
        
        /* 边界检查 */
        if (idx + 1 >= code.length()) return -1;
        
        if (code[idx + 1] == '0') {
            return _print_decode(np->lchild, code, idx + 1);
        } else if (code[idx + 1] == '1') {
            return _print_decode(np->rchild, code, idx + 1);
        }
        return -1;
    }

private:
    vector<node<T> *> node_vec;
    node<T> *root;
};


int main()
{
    huffman_tree<char> tree;
    tree.create_huffman_tree("E:\\MyLeetCode\\huffman_input.txt");
    tree.print_encode();
    tree.print_decode("1011011100111");
    tree.print_decode("11");
    return 0;
}
