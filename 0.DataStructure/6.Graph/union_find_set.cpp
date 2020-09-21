/**
 * Created by raven on 2020/9/18.
 * 并查集
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class union_find_set{
public:
    explicit union_find_set(int len):len(len) {
        elem = new int[len+1];
        for(int i = 0;i<len+1;i++){
            elem[i] = i;
        }
    }

    ~union_find_set(){
        delete[] elem;
    }

    bool is_same_set(int e1, int e2){
        return find_father(e1) == find_father(e2);
    }

    void merge(int e1,  int e2){
        if(find_father(e1) == find_father(e2)) return;
        else
        {
            int root1 = find_father(e1);
            int idx2 = e2;

            while(idx2 != root1){
                int temp = elem[idx2];
                elem[idx2] = root1;
                idx2 = temp;
            }
        }
    }

    int size() const{
        return len;
    }

private:
    int find_father(int cur_idx){
        int root = cur_idx;
        /* find root */
        while(root != elem[root]){
            root = elem[root];
        }
        /* 路径压缩 */
        while(cur_idx != root){
            int temp = elem[cur_idx];
            elem[cur_idx] = root;
            cur_idx = temp;
        }
        return root;
    }

private:
    int *elem;
    int len;
};



/*int main()
{
    union_find_set ufs(10);
    cout << ufs.is_same_set(1,2) << endl;
    ufs.merge(1,2);
    cout << ufs.is_same_set(1,2) << endl;

    ufs.merge(1,3);
    cout << ufs.is_same_set(2,3) << endl;
    return 0;
}*/

