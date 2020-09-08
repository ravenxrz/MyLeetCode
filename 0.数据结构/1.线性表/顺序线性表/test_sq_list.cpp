/**
 * Created by raven on 2020/9/8.
 */
#include "../../common.h"
#include "sq_list.cpp"


/**
 * union list a and list b , store result into list a
 * @tparam T
 * @param lista
 * @param listb
 */

template<typename T>
Status compare(T e1, T e2)
{
    return  e1 == e2 ? TRUE : FALSE;
}

template<typename T>
void union_list(sqlist<T> &lista, sqlist<T> listb)
{
    T temp;
    for (size_t i = 1; i <= listb.length(); i++) {
        listb.get(i, temp);
        if (!lista.locate_elem(temp,compare)) {
            lista.insert(lista.length()+1,temp);
        }
    }
}

template<typename T>
void merge_list(sqlist<T> la, sqlist<T> lb, sqlist<T> &lc)
{
    int i,j,k;
    int ai,bi;
    i = j = k = 1;
    
    while(i <= la.length() && j <= la.length()){
        la.get(i,ai) ;
        lb.get(j,bi);
        if(ai <= bi){
            i++;
            lc.insert(k,ai);
        }else{
            j++;
            lc.insert(k,bi);
        }
        k++;
    }
    
   while(i <= la.length()) {
       la.get(i++,ai);
       lc.insert(k++,ai);
   }
   
   while(j <= lb.length()){
       lb.get(j++,bi);
       lc.insert(k++,bi);
   }
}

void base_test()
{
    sqlist<int> list;
    int e;
    
    /* put value */
    for (size_t i = 1; i < 100; i++) {
        list.insert(i, i);
    }
    
    /* get value */
    for (size_t i = 1; i < 100; i++) {
        list.get(i, e);
        std::cout << "idx" << i << ":" << e << "\n";
    }
    std::cout << std::endl;
    
    /* remove value */
    list.remove(2, e);
    list.remove(4, e);
    list.remove(80, e);
    
    /* get value again*/
    for (size_t i = 1; i < 100; i++) {
        list.get(i, e);
        std::cout << "idx" << i << ":" << e << "\n";
    }
}

void test_union()
{
    int temp;
    sqlist<int> lista;
    sqlist<int> listb;
    /* put value into lista */
    for (size_t i = 1; i <= 10; i++) {
        lista.insert(i, i);
        listb.insert(i, i + 8);
    }
    
    /* union */
    union_list(lista, listb);
    
    /* print info */
    for (size_t i = 1; i <= lista.length(); i++) {
        lista.get(i,temp);
        std::cout << temp << "\n";
    }
    std::cout << "\n";
    
    for (size_t i = 1; i <= listb.length(); i++) {
        listb.get(i,temp);
        std::cout << temp << "\n";
    }
    std::cout << std::endl;
}

void test_merge_list(){
    sqlist<int> lista;
    sqlist<int> listb;
    sqlist<int> listc;
    int temp;
    
    /* put value into lista */
    for (size_t i = 1; i <= 10; i++) {
        lista.insert(i, i);
        listb.insert(i, i + 8);
    }
    
    merge_list(lista,listb,listc);
    
    /* print info */
    std::cout << "lista:\n";
    for(size_t i = 1; i<= lista.length();i++){
        lista.get(i,temp);
        std::cout << temp << "\n";
    }
    
    std::cout << "listb:\n";
    for(size_t i = 1; i<= listb.length();i++){
        listb.get(i,temp);
        std::cout << temp << "\n";
    }
    
    std::cout << "listc:\n";
    for(size_t i = 1;i<= listc.length();i++){
        listc.get(i,temp);
        std::cout << temp << "\n";
    }
}

int main(int argc, char *argv[])
{
    test_merge_list();
    return 0;
}