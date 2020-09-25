//
// Created by raven on 2020/9/11.
//
#include <iostream>
#include <vector>
using namespace std;

class A;
class B;

class A{
    friend B;
public:
private:
    int a;
};

class B{
    void print(const A &ca){
        cout << ca.a;
    }
private:
    int b;
};


int main(void)
{
    vector<int> vec1 ={1,2,3,4};
    vector<vector<int>> vec2(2,vector<int>(3,0));
    cout << "hello" << endl;


    return 0;
}