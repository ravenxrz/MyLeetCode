// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity),size(0)
    {
    }
    
    int get(int key)
    {
        auto iter = cache_index.find(key);
        if( iter == cache_index.end()){ /* not found */
            return -1;
        }
        cache_list.splice(cache_list.begin(),cache_list,iter->second);
        return iter->second->value;
    }
    
    void put(int key, int value){
        /* first check whether the key has already existed */
        auto index_iter = cache_index.find(key);
        if(index_iter != cache_index.end()){  /* found */
            auto kv_iter = index_iter->second;
            /* update value */
            kv_iter->value = value;
            /* move the kv pair to the beginning of this list  */
            cache_list.splice(cache_list.begin(),cache_list,kv_iter);
            cache_index[key] = cache_list.begin();
        }else{      /* not found */
            /* generate new node */
            Pair kv(key,value);
            if(size == capacity){
                /* execute eviction */
                int key = cache_list.back().key;
                cache_index.erase(key);
                cache_list.pop_back();
            }else{
                size++;
            }
            /* insert into cache */
            cache_list.push_front(kv);
            cache_index[key] = cache_list.begin();
        }
    }

private:
    /* structure declaration */
    struct Pair {
        int key;
        int value;
        Pair(int key, int value) : key(key), value(value){}
    };
private:
private:
    list<Pair> cache_list;      /* for quick put */
    map<int, list<Pair>::iterator> cache_index; /* for quick get */
    int capacity;
    int size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
