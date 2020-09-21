/**
 * Created by raven on 2020/9/9.
 */
#include "skiplist.cpp"
#include <malloc.h>


int main()
{// Seed random number generator
//    srand((unsigned) time(0));
    
    // create SkipList object with MAXLVL and P
    const float pi = 0.4;
    skiplist<int, int> lst(5);
    lst.insert(3, -1, pi);
    lst.insert(5, -1, pi);
    lst.insert(7, -1, pi);
    lst.insert(4, -1, pi);
    lst.insert(10, -1, pi);
    lst.insert(30, -1, pi);
    lst.insert(13, -1, pi);
    
    lst.display();
    
    node<int,int> *current = lst.search(10);
    std::cout << "find key " << current->key << "\n";
    
    lst.remove(5);
    lst.remove(30);
    lst.remove(10);
    
    lst.display();
    return 0;
}

