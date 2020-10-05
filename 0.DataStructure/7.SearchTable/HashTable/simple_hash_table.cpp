/**
 * Created by a2855 on 2020/10/5.
 * hash函数， key mod 13
 * hash碰撞处理， 开放定址法--线性探测
 */
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename K, typename V>
class hash_table{
private:
    // 哈希表中的一项
    struct item{
        K key;
        V value;
    
        item(){}

        item(K key, V value) : key(key), value(std::move(value)) {}
    };
    
public:
    
    hash_table(): counter(0){
        table.resize(5,nullptr);
    }
    
    ~hash_table(){
        for(const auto & ptr: table){
            delete ptr;
        }
    }
    
    void put(K key, V value){
        int idx = -1;
        
        if(search(key,idx)){
            table[idx]->value = value;
        }else{
            item *kv = new item(key,value);
            table[idx] = kv;
            counter++;
        }
    }
    
    bool get(K key, V& value){
        int idx = -1;
        
        if(search(key,idx)){
            value = table[idx]->value;
            return true;
        }else{
            cerr<< "no such key in table\n";
            return false;
        }
    }
    
private:
    
    int hash(K key){
        return key % 13;        //TODO: 这里其实限制了key为可取余的类型，所以不算通用类型了
    }
    
    /* search 指定key，如果当前table中有key，return true, 并返回该key所在的idx
     * 如果当前table中没有该key，return false, 并返回一个空slot的idx
     */
    bool search(K key,int &idx){
        const int cur_len = table.size();
        int i = hash(key);
        const int flag = (i-1) % cur_len;

        /* 是否需要rehash */
        if((float)counter / table.size() >= load_factor){
             rehash();
        }

        /* 执行search */
        for (; i != flag;i = (i+1) % cur_len){
            if(table[i] == nullptr){
                idx = i;
                return false;
            }else if(table[i]->key == key){
                idx = i;
                return true;
            }
        }
        
        idx = -1;
        return false;
    }
    
    /* rehash */
    void rehash(){
        cout << "rehash"<<endl;
        assert((float)counter / table.size() >= load_factor);
        table.resize(table.size()<<1);
    }
    
private:
    static const float load_factor;
    int counter;  // 有效item个数
    vector<item*> table;    // table
};

// 静态变量初始化
template <typename K, typename V>
const float ::hash_table<K,V>::load_factor = 0.7f;



int main()
{
    hash_table<int,string> table;
    table.put(1,"zhang");
    table.put(2,"zhang");
    table.put(3,"zhang");
    table.put(4,"zhang");
    table.put(5,"xing");
    table.put(6,"xing");
    table.put(7,"xing");
    table.put(8,"rui");
    table.put(9,"rui");
    
    string value;
    for(int i = 1;i<=9;i++){
        table.get(i,value);
        cout << value << endl;
    }
    
    return 0;
}