/**
 * Created by raven on 2020/9/8.
 * sqlist 顺序线性表
 * Note: operation idx range start from 1 (not start at 0)
 * example:
 * insert element at 1
 * list.insert(1,elem)
 *
 */
#include "../../common.h"



/* sqlist  */
template<typename T>
class sqlist {
public:
    explicit sqlist(size_t initial_size = 100, size_t increment_size = 100);
    
    /* copy constructor */
    sqlist(const sqlist &list);
    
    ~sqlist();
    
    /* insert e element in idx */
    Status insert(size_t idx, T e);
    
    /* remove element and put the element into e */
    Status remove(size_t idx, T &e);
    
    Status get(size_t idx, T &e);
    
    Status locate_elem(T e, Status (*compare)(T e1, T e2));
    
    size_t length()
    {
        return this->len;
    }


private:
    T *elem;                /* base address */
    size_t len;          /* current inserted elements size */
    size_t list_size;      /* list size  */
    size_t increment_size;  /* increment size */
    
};

template<typename T>
sqlist<T>::sqlist(size_t initial_size, size_t increment_size)
{
    this->increment_size = increment_size;
    this->elem = (T *) malloc(initial_size * sizeof(T));
    this->list_size = initial_size;
    this->len = 0;   /*empty list*/
}


template<typename T>
sqlist<T>::~sqlist()
{
    /* free resource */
    free(this->elem);
}

/**
 * idx range [1,length+1]
 * @tparam T
 * @param idx
 * @param e
 * @return
 */
template<typename T>
Status sqlist<T>::insert(size_t idx, T e)
{
    /* boundary check */
    if (idx < 1 || idx > this->len + 1) {
        std::cerr << "idx out of bound\n";
        exit(OVERFLOW);
    }
    
    /* length check */
    if (this->len + 1 == this->list_size) {
        /* realloc */
        T *p = this->elem;
        this->elem = (T *) malloc(sizeof(T) * (this->list_size + this->increment_size));
        memcpy(this->elem, p, this->list_size);
        free(p);
        
        this->list_size += this->increment_size;
    }
    
    /* find insert position*/
    T *p = &this->elem[this->len];    /*  pointer points to the last element + 1 */
    T *q = &this->elem[idx - 1];       /* pointer points to the position which needs to be inserted */
    for (; p != q; p--) {
        *p = *(p - 1);
    }
    
    /* now insert*/
    *q = e;
    this->len++;
    return OK;
}


/**
 * idx range [1, length]
 * remove value and put the value into
 * @tparam T
 * @param idx
 * @param e
 * @return
 */
template<typename T>
Status sqlist<T>::remove(size_t idx, T &e)
{
    /* boundary check */
    if (idx < 1 || idx > this->len) {
        std::cerr << "out of range\n";
        exit(OVERFLOW);
    }
    
    /* remove value */
    T *p = &this->elem[idx - 1];
    T *last = &this->elem[this->len - 1];
    e = *p;
    for (; p != last; p++) {
        *(p) = *(p + 1);
    }
    
    this->len--;
    return OK;
}

/**
 * idx range [1, length]
 * @tparam T
 * @param idx
 * @return
 */
template<typename T>
Status sqlist<T>::get(size_t idx, T &e)
{
    if (idx < 1 || idx > this->len) {
        std::cerr << "out of range\n";
        exit(OVERFLOW);
    }
    e = this->elem[idx - 1];
    return OK;
}


/**
 *
 * @tparam T
 * @param e
 * @param compare sucess 1 , failed 0
 * @return
 */
template<typename T>
Status sqlist<T>::locate_elem(T e, Status (*compare)(T, T))
{
    for (size_t i = 0; i < this->len; i++) {
        /* if (compare(e, this->elem[i])) {
             return TRUE;
         }*/
        if (e == this->elem[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * implements deep copy
 * @tparam T
 * @param list
 */
template<typename T>
sqlist<T>::sqlist(const sqlist &list):list_size(list.list_size), len(list.len), increment_size(list.increment_size)
{
    this->elem = (T *) malloc(sizeof(T) * list.list_size);
    memcpy(this->elem,list.elem,list.list_size);
}

