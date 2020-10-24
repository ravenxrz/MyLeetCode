#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



void swap(string &str, int i, int j)
{
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
}

void _dfs(string &tmp, int idx)
{
    if(idx >= tmp.size())
        return;

    for(int i = idx;i<tmp.size();i++){
        // 交换
        swap(tmp,idx,i);
        if(idx != i)
            cout << tmp << endl;
        _dfs(tmp,idx+1);
        // 还原
        swap(tmp,idx,i);
    }
}


void dfs(string tmp)
{
    cout << tmp << endl;
    _dfs(tmp,0);
}

int main()
{

    dfs("123");
    return 0;
}