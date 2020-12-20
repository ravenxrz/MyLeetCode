#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    auto iter_1 = mylist.begin();
    cout << *iter_1 << endl;
    mylist.push_front(3);
    cout << *iter_1 << endl;
    return 0;
}