/**
 * Created by a2855 on 2020/9/23.
 */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

size_t seq_search(vector<int> &dict, int key)
{
    /* 设置哨兵，减少循环内的比较次数 */
    dict[0] = key;
    size_t i;
    for(i = dict.size()-1; dict.at(i) != key;i--);
    return i;
}

int main()
{
    vector<int> dict;
    vector<int> input;
    
    fstream fin("E:\\MyLeetCode\\0.DataStructure\\7.SearchTable\\StaticSearchTable\\seq_input.txt");
    if(!fin.is_open()) throw runtime_error("file not exit");
    
    /* read from file */
    int n;
    fin >> n;
    input.reserve(n);
    for(int i = 0;i<n;i++){
        int temp;
        fin >> temp;
        input.push_back(temp);
    }
    /* 保留第0位 */
    dict.resize(1);
    dict.insert(dict.begin()+1,input.begin(),input.end());
    for(int i = 1;i<dict.size()-1;i++){
        cout << dict.at(i) << " ";
    }
    cout << endl;
    
    /* search test */
    cout << seq_search(dict,312) << endl;
    
    return 0;
}