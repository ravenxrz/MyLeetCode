/**
 * Created by raven on 2020/9/10.
 */
#include "link_queue.cpp"
using namespace std;

int main()
{
    linkqueue<int> queue;
    int temp;
    
    for(size_t i = 1;i<=100;i++){
        queue.push_back(i);
    }
    
    queue.get_front(temp);
    cout << temp << endl;
    
    while(!queue.isempty()){
        queue.pop_front(temp);
        cout << temp << "\n";
    }
    return 0;
}

