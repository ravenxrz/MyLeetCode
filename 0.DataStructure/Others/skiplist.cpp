/**
 * Created by raven on 2020/9/9.
 * 自实现的跳表
 */
#include <iostream>
#include <cstring>
#include <cstdlib>


template<typename K, typename V>
class node {
public:
    node(K key, size_t max_len) : key(key)
    {
        forward = new node *[max_len];
        for(size_t i = 0;i<max_len;i++){
            forward[i] = nullptr;
        }
    }
    
    ~node()
    {
        delete[] forward;
    }

public:
    K key;
    V value;
    node **forward;      /* 表示每层的逻辑连接 */
};

template<typename K, typename V>
class skiplist {
public:
    explicit skiplist(size_t max_level);
    
    ~skiplist();
    
    node<K, V> *search(K key) const;
    
    bool insert(K key, V value, float p);
    
    bool remove(K key);
    
    void display() const;

private:
    size_t random_level(float p);

private:
    node<K, V> *head;
    size_t max_level{};       /* 能够接受的最大level */
    size_t level{};           /* 当前level */
};

template<typename K, typename V>
skiplist<K, V>::skiplist(size_t max_level)
{
    this->max_level = max_level;
    this->level = 0;
    head = new node<K, V>(-1, max_level);
}

template<typename K, typename V>
skiplist<K, V>::~skiplist()
{
    node<K, V> *nodep1;
    node<K, V> *nodep2 = head->forward[0];
    while (nodep2 != nullptr) {
        nodep1 = nodep2;
        nodep2 = nodep2->forward[0];
        delete nodep1;
    }
    delete head;
}


/**
 *
 * @tparam K
 * @tparam V
 * @param key
 * @return 成功，返回该节点地址，失败 nullptr
 */
template<typename K, typename V>
node<K, V> *skiplist<K, V>::search(K key) const
{
    /* update数组保留搜索路径中的节点 */
    node<K, V>** update = new node<K, V> * [max_level];
    node<K, V> *current{};
    memset(update,0,max_level);
    
    /* 从最上层遍历到最小层，得到搜索路径，更新update表 */
    for (int i = level; i >= 0; i--) {
        current = head;
        while (current->forward[i] != nullptr && key > current->forward[i]->key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current -> forward[0];
    if (current != nullptr && current->key == key) {
        return current;
    }
    return nullptr;
}


template<typename K, typename V>
bool skiplist<K, V>::insert(K key, V value, float p)
{
    /* update数组保留搜索路径中的节点 */
    node<K, V>** update = new node<K, V> * [max_level];
    node<K, V> *current{};
    node<K, V> *newnode{};
    size_t rlevel;
    memset(update,0,max_level*sizeof(node<K,V> *));
    
    /* 从最上层遍历到最小层，得到搜索路径，更新update表 */
    for (int i = level; i >= 0; i--) {
        current = head;
        while (current->forward[i] != nullptr && key > current->forward[i]->key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current->forward[0] ;
    if (current != nullptr && current->key == key) {      /* update */
        current->value = value;
    } else if (current == nullptr || current->key != key) {      /* 需要插入 */
        /* 生成新node */
        rlevel = random_level(p);
        if (rlevel > level) {
            for(size_t i = level+1; i<=rlevel;i++){
                update[i] = head;
            }
            level = rlevel;
        }
        
        newnode = new node<K, V>(key, rlevel);
        /* 执行插入 */
        for (int i = rlevel; i >= 0; i--) {
            newnode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newnode;
            std::cout << "key " <<  key <<  " update level " << i << " \n";
        }
    }
    return true;
}

template<typename K, typename V>
bool skiplist<K, V>::remove(K key)
{
    /* update数组保留搜索路径中的节点 */
    node<K, V> **update = new node<K, V>* [max_level];
    node<K, V> *current{};
    memset(update,0,max_level);
    
    /* 从最上层遍历到最小层，得到搜索路径，更新update表 */
    for (int i = level; i >= 0; i--) {
        current = head;
        while (current->forward[i] != nullptr && key > current->forward[i]->key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current -> forward[0];
    /* 是否可以删除 */
    if(current == nullptr || current->key != key){
        return false;
    }
    
    /* 执行删除 */
    for(int i = level; i>=0 ;i--){
        if(update[i]->forward[i] == current){
            update[i]->forward[i] = current->forward[i];
        }
    }
    delete current;
    
    /* 删除空level */
    while(level > 0 && head->forward[level] == nullptr){
        level--;
    }
    return true;
}

template<typename K, typename V>
void skiplist<K, V>::display() const
{
    node<K,V> *current;
   for(int i = level; i>= 0; i--) {
       std::cout << "level " << i << ":";
       current = head->forward[i];
       while(current != nullptr) {
           std::cout << current->key << " ";
           current = current->forward[i];
      }
       std::cout << "\n";
   }
}

template<typename K, typename V>
size_t skiplist<K, V>::random_level(float p)
{
    float r = (float)rand() / RAND_MAX;
    int rlevel = 0;
    while (r < p && rlevel < max_level - 1) {
        rlevel++;
        r = (float)rand() /RAND_MAX;
    }
    return rlevel;
}



