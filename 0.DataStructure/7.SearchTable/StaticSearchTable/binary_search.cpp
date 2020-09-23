/**
 * Created by a2855 on 2020/9/23.
 * 二分查找
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int my_binary_search(const vector<int> &dict,int key)
{
    int low  = 0, high = dict.size()-1;
    int mid;
    
    while(low < high){
        mid = (low+high)/2;
        if(key < dict[mid]){
            high = mid-1;
        }else if(key > dict[mid]){
            low = mid+1;
        }else{
            return mid;
        }
    }
    
    return -1;
}

int main()
{
    fstream fin("E:\\MyLeetCode\\0.DataStructure\\7.SearchTable\\StaticSearchTable\\binary_search_input.txt");
    if(!fin.is_open()){
        throw runtime_error("file not exit");
    }
    int n;
    fin >> n;
    vector<int> numbers;
    while(fin >> n) numbers.push_back(n);
    
    /* print input */
    for(const auto &v : numbers){
        cout << v << " ";
    }
    cout << "\n";
    
    /* sort */
    sort(numbers.begin(),numbers.end());
    /* print agian */
    for(const auto &v : numbers){
        cout << v << " ";
    }
    cout << "\n";
    
    /* binary search */
//    binary_search(numbers.begin(),numbers.end(),10);
    cout << my_binary_search(numbers, 85) << endl;
    
    return 0;
}

