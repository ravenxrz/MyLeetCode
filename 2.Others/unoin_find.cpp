//
// Created by Raven on 2021/3/16.
//
#include <vector>
#include <cassert>
#include <iostream>

class UF {
public:
    UF(int size) : count(size)
    {
        parent.resize(size);
        // init
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
    
    int find_parent(int x)
    {
        assert(x < parent.size() && x >= 0);
        int root = x;
        while (parent[root] != root) {
            root = parent[root];
        }
        // 路径压缩
        while (parent[x] != root) {
            int save_p = parent[x];
            parent[x] = root;
            x = save_p;
        }
        return root;
    }
    
    bool is_same_set(int x, int y)
    {
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);
        return parent_x == parent_y;
    }
    
    void merge(int x, int y)
    {
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);
        if (parent_x == parent_y) return;
        parent[parent_y] = parent_x;
        --count;
    }
    
    int getCount() const
    {
        return count;
    }

private:
    std::vector<int> parent;
    int count;
};

