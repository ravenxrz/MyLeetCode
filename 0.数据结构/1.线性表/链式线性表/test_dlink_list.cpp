/**
 * Created by raven on 2020/9/8.
 */
#include "dlink_list.cpp"

void base_test()
{
    dlinklist<int> list;
    int e;
    
    /* put value */
    for (size_t i = 1; i <= 200; i++) {
        list.push_front(i);
        list.push_back(200-i);
    }
    
    /* get value */
    for (size_t i = 1; i <= list.length(); i++) {
        list.peek(i, e);
        std::cout << "idx" << i << ":" << e << "\n";
    }
    std::cout << std::endl;
    
////    /* remove value */
//    list.remove(2, e);
//    list.remove(4, e);
//    list.remove(80, e);

    /* get value again*/
//    for (size_t i = 1; i <= list.length(); i++) {
//        list.peek(i, e);
//        std::cout << "idx" << i << ":" << e << "\n";
//    }
//    std::cout << std::endl;
    
    /* pop value */
    while(!list.isempty()){
        list.pop_back(e);
        std::cout  << e << "\n";
        list.pop_front(e);
        std::cout  << e << "\n";
    }
    std::cout << std::endl;
    
}

int main(int argc, char *argv[])
{
   base_test();
    return 0;
}