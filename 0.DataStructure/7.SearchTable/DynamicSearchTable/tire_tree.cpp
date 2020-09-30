/**
 * Created by a2855 on 2020/9/30.
 * 26字母tire树实现
 */
#include <iostream>
#include <cassert>
using namespace std;

#define ALPHABET_SIZE 26

class tire_tree{
private:
    struct node{
        char c;
        struct node* children[ALPHABET_SIZE];
        bool is_end_of_word;
        int num;        /* 不为空的children数量 */
        /* 还可以有一个数据域，但是不影响tire tree实现,所以未加入 */
    
        node(char c, bool isEndOfWord) : c(c), is_end_of_word(isEndOfWord),num(0) {
            fill(begin(children),end(children),nullptr);
        }
    };
public:
    
    tire_tree(){
        root = new node('$', false);
    }
    
    void traverse(){
        _traverse(root);
        cout << "\n";
    }
    
    // success return that node, else nullptr
    struct node *search(const string &key){
        int i = 0;
        int j = key[i] - 'a';
        struct node *cur = root;
    
        while(i < key.size() -1 && cur->children[j] != nullptr){
            cur = cur->children[j];
            i++;
            j = key[i] - 'a';
        }
        
        if(i< key.size() -1){    /* 搜索中途tire树缺失对应字符 */
            return nullptr;
        }
        /* 搜索到key的倒数第二个字符，最后检测最后一个字符 */
        if(i == key.size()-1){               /* 检查最后一个字符 */
            j = key[i] - 'a';
            if(cur->children[j] != nullptr && cur->children[j]->is_end_of_word){
                return cur->children[j];
            }
        }
        /* 默认 */
        return nullptr;
    }
    
    void insert(const string &key){
        int i = 0;
        int j = key[i] - 'a';
        struct node *cur = root;
        
        while(i < key.size() - 1){
            if(cur->children[j] == nullptr){    /* 没有该字符 */
                cur->children[j] = new node(key.at(i),false);
                cur->num++;
            }
            cur = cur->children[j];
            j = key[++i] - 'a';
        }
        /* 最后一个字符打上 is_end_of_word标记 */
        if(cur->children[j] == nullptr){
            cur->children[j] = new node(key.at(i),true);
            cur->num++;
        }else{
            cur->children[i]->is_end_of_word = true;
        }
    }
    
    void remove(const string &key){
        /* 首先找到指定节点 */
        int i = 0;
        int j = key[i] - 'a';
        struct node *cur = root;
        struct node *p = cur;
        
        while(i<key.size()-1 && cur->children[j] != nullptr){
            p = cur;
            cur = cur->children[j];
            j = key[++i]-'a';
        }
        if(cur->children[j] == nullptr){
            cerr<<"no such key found\n";
            return;
        }
        if(i == key.size()-1){  /* 最后一个字符单独处理 */
            if(cur->children[j] != nullptr && cur->children[j]->is_end_of_word){
                /* 找到该key */
                p = cur;
                cur = cur->children[j];
            }
        }
        
        if(cur->num == 0){   /* 没有孩子节点 */
            assert(p->children[j] == cur);
            delete cur;
            p->children[j] = nullptr;
            p->num--;
        }else{              /* 还有孩子节点，说明是其他key的前缀 */
            cur->is_end_of_word = false;
        }
    }
    
private:
    void _traverse(struct node *nd){
        if(nd == nullptr){
            return;
        }else
        {
            cout << nd->c << " ";
            for(auto & i : nd->children){
                if(i != nullptr){
                    _traverse(i);
                }
            }
        }
    }
private:
    struct node *root;
};


// driver
int main()
{
    tire_tree tree;
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their" };
    
    int n = sizeof(keys)/sizeof(keys[0]);
    
    for(int i = 0;i<n;i++){
        tree.insert(keys[i]);
    }
    
    tree.traverse();
    
    for(int i = 0;i<n;i++){
        cout << (tree.search(keys[i]) != nullptr) << endl;
    }
    
    tree.remove("the");
    cout <<  (tree.search("the") != nullptr) << endl;
    tree.remove("there");
    cout <<  (tree.search("there") != nullptr) << endl;

    cout <<  (tree.search("their") != nullptr) << endl;
    return 0;
}

