//
// Created by raven on 2020/9/11.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec{1,1,1,2,2,2,3,3,3};
    set<int> set(vec.begin(),vec.end());
    for(const auto val: set){
        cout << val << " ";
    }
    
    return 0;
}