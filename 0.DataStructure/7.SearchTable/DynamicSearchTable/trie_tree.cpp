/**
 * Created by a2855 on 2020/9/30.
 * 26字母trie树实现
 */
#include <iostream>
#include <cassert>
using namespace std;

#define ALPHABET_SIZE 26

class trie_tree{
private:
    struct node{
        char c;
        struct node* children[ALPHABET_SIZE];
        bool is_end_of_word;
        int ref_num;        /* 当前node被多少node引用，孩子节点或 end of word node 会引用 */
        /* 还可以有一个数据域，但是不影响trie tree实现,所以未加入 */
    
        node(char c, bool isEndOfWord) : c(c), is_end_of_word(isEndOfWord),ref_num(0) {
            fill(begin(children),end(children),nullptr);
        }
    };
public:
    
    trie_tree(){
        root = new node('$', false);
    }
    
    void traverse(){
        _traverse(root);
        cout << "\n";
    }
    
    // success return founded node, else nullptr
    struct node *search(const string &key){
        struct node *cur = root;
        for(int i = 0;i<key.size();i++){
            int idx = key[i] - 'a';
            cur = cur->children[idx];
            if(cur == nullptr){
                return nullptr;
            }
        }
        
        if(cur ->is_end_of_word) return cur;
        else return nullptr;
    }
    
    void insert(const string &key){
        struct node *cur = root;
        for(int i = 0;i<key.size();i++){
            int idx = key[i] - 'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = new node(key[i],false);
                cur->ref_num++;
            }
            cur = cur->children[idx];
        }
        cur->is_end_of_word = true;
        cur->ref_num++;
    }
    
    void remove(const string &key){
        if(search(key) == nullptr)  // 没有该key，无法删除
            return;
        int idx = key[0] - 'a';
        _remove(key,root,root->children[idx],0);
        
    }
    
private:
    /**
     * 递归删除node， i是key的偏移量
     * @param key 要删除的key
     * @param p nd的父亲节点
     * @param nd 指向trie树中字符=key[i]的节点
     * @param i key的偏移量
     */
    void _remove(const string &key,struct node *p, struct node *nd, int i){
        assert(nd != nullptr);
        
        if(i == key.size() - 1){    /* key的末尾 */
            if(nd->is_end_of_word && nd->ref_num == 1){    /* 独立节点：end of word节点且只有自身引用 */
                p->ref_num--;
                p->children[key[i]-'a'] = nullptr;
                delete nd;
            }else if(nd->is_end_of_word){       /* 非独立节点 & end of word节点，但是存在孩子节点引用 */
                nd->ref_num--;
            }
            nd->is_end_of_word = false;
            return;
        }
        
        int idx = key[i+1] - 'a';
        _remove(key,nd,nd->children[idx],i+1);
        if(nd->ref_num == 0){    /* 删除本节点，父亲节点少一个孩子 */
            p->ref_num--;
            p->children[key[i]-'a'] = nullptr;
            delete nd;
        }
    }
    
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
    trie_tree tree;
    
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = { "the", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);
    
    // Construct trie
    for (int i = 0; i < n; i++)
        tree.insert(keys[i]);
    
    // Search for different keys
    tree.search("the") ? cout << "Yes\n" : cout << "No\n";
    tree.search("these") ? cout << "Yes\n" : cout << "No\n";
    
    tree.remove("heroplane");
    tree.search("hero") ? cout << "Yes\n" : cout << "No\n";
    
    tree.remove("hero");
    tree.search("hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}

