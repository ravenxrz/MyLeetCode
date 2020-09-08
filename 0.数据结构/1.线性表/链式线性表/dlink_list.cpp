/**
 * Created by raven on 2020/9/8.
 * dual link list
 */
#include "../../common.h"

/* list node */
template<typename T>
struct node {
    T data;
    struct node *prev;
    struct node *next;
};
#define node node<T>


template<typename T>
class dlinklist {
public:
    explicit dlinklist();
    
    dlinklist(const dlinklist<T> &list);
    
    ~dlinklist();
    
    /* operations */
    Status isempty();
    
    Status length();
    
    Status peek(size_t idx, T &elem);
    
    Status pop_front(T &elem);
    
    Status pop_back(T &elem);
    
    Status push_front(T elem);
    
    Status push_back(T elem);
    
    Status insert(size_t idx, T elem);
    
    Status remove(size_t idx, T &elem);

private:
    struct node *locate_prev_node(size_t idx);

private:
    struct node *head, *tail;
    struct node *next, *prev;
    size_t len;                 /* how many nodes in this list */
    
};


template<typename T>
dlinklist<T>::dlinklist()
{
    head = (struct node *) malloc(sizeof(struct node));
    if (!head) {
        std::cerr << "init dlink list failed: malloc failed\n";
        exit(ERROR);
    }
    tail = head;
    next = prev = nullptr;
    len = 0;
}

template<typename T>
dlinklist<T>::dlinklist(const dlinklist<T> &list)
{
    T temp;
    
    /* deep copy */
    head = (T *) malloc(sizeof(struct node));
    if (!head) {
        std::cerr << "init dlink list failed: malloc failed\n";
        exit(ERROR);
    }
    tail = head;
    next = prev = nullptr;
    len = 0;
    
    /* copy every element of list */
    for (size_t i = 0; i < list.len; i++) {
        list.peek(i, temp);
        this->insert(i, temp);
    }
}

template<typename T>
dlinklist<T>::~dlinklist()
{
    T temp;
    /* free resource */
    for (size_t i = 0; i < len; i++) {
        this->pop_front(temp);
    }
}

template<typename T>
Status dlinklist<T>::isempty()
{
    return len == 0 ? TRUE : FALSE;
}

template<typename T>
Status dlinklist<T>::length()
{
    return len;
}


/**
 * idx range [1,len]
 * @tparam T
 * @param idx
 * @param elem
 * @return
 */
template<typename T>
Status dlinklist<T>::peek(size_t idx, T &elem)
{
    struct node *p;
    size_t i;
    
    if (idx < 1 || idx > len) {
        std::cerr << "out of range \n";
        exit(ERROR);
    }
    
    /* find idx -1 pos */
    p = locate_prev_node(idx);
    
    elem = p->next->data;
    return OK;
}

template<typename T>
Status dlinklist<T>::pop_front(T &elem)
{
    return remove(1, elem);
}

template<typename T>
Status dlinklist<T>::pop_back(T &elem)
{
    return remove(len, elem);
}

template<typename T>
Status dlinklist<T>::push_front(T elem)
{
    return insert(1, elem);
}


template<typename T>
Status dlinklist<T>::push_back(T elem)
{
    return insert(len + 1, elem);
}

template<typename T>
Status dlinklist<T>::insert(size_t idx, T elem)
{
    struct node *p;
    struct node *new_node;
    
    if (idx < 1 || idx > len + 1) {
        std::cerr << "out of range\n";
        exit(ERROR);
    }
    
    /* find idx -1 pos */
    p = locate_prev_node(idx);
    
    /* generate node */
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = elem;
    
    /* insert */
    new_node->next = p->next;
    p->next = new_node;
    new_node->prev = p;
    if (new_node->next == nullptr) {
        /* update tail */
        tail = new_node;
    } else {
        new_node->next->prev = new_node;
    }
    
    len++;
    return OK;
}

template<typename T>
Status dlinklist<T>::remove(size_t idx, T &elem)
{
    struct node *p;
    struct node *q;
    
    if (idx < 1 || idx > len) {
        std::cerr << "out of range \n";
        exit(ERROR);
    }
    
    p = locate_prev_node(idx);
    q = p->next;
    if (p->next->next) {
        p->next->next->prev = p;
    } else {
        tail = p;
    }
    p->next = p->next->next;
    
    elem = q->data;
    free(q);
    
    len--;
    return OK;
}

template<typename T>
node *dlinklist<T>::locate_prev_node(size_t idx)
{
    struct node *p;
    int j;
    
    /* find idx-1 pos */
    if (idx <= len / 2) {
        /* front  to back */
        j = 1;
        p = head;
        while (p && j < idx) {
            p = p->next;
            j++;
        }
    } else {
        /* back to front */
        j = len;
        p = tail;
        while (p && j >= idx) {
            p = p->prev;
            j--;
        }
    }
    return p;
}



