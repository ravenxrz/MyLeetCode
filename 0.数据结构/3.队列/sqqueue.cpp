/**
 * Created by raven on 2020/9/10.
 * 循环队列测试
 */

#include "../common.h"

template<typename T>
class sqqueue {
public:
    sqqueue(size_t max_size = 100);
    
    sqqueue(const sqqueue<T> &other);
    
    ~sqqueue();
    
    Status isempty() const;
    
    size_t length() const;
    
    Status get_front(T &e) const;
    
    Status push_back(T e);
    
    Status pop_front(T &e);

private:
    Status is_full() const;

private:
    T *base;
    size_t head;
    size_t tail;
    size_t max_size;
};

template<typename T>
sqqueue<T>::sqqueue(size_t max_size):max_size(max_size)
{
    base = new T[max_size];
    head = tail = 0;
}

template<typename T>
sqqueue<T>::sqqueue(const sqqueue<T> &other)
{
    this->max_size = other.max_size;
    base = new T[max_size];
    memcpy(base, other.base, max_size);
    this->head = other.head;
    this->tail = other.tail;
}

template<typename T>
sqqueue<T>::~sqqueue()
{
    delete[] base;
}

template<typename T>
Status sqqueue<T>::isempty() const
{
    return head == tail ? TRUE : FALSE;
}

template<typename T>
size_t sqqueue<T>::length() const
{
    return (tail - head + max_size) % max_size;
}

template<typename T>
Status sqqueue<T>::push_back(T e)
{
    if (is_full()) {
        std::cerr << "queue is full\n";
        return ERROR;
    }
    base[tail] = e;
    tail = (tail + 1) % max_size;
    return OK;
}

template<typename T>
Status sqqueue<T>::is_full() const
{
    return (tail + 1) % max_size == head;
}

template<typename T>
Status sqqueue<T>::pop_front(T &e)
{
    if (isempty()) {
        std::cerr << "queue is empty\n";
        return ERROR;
    }
    e = base[head];
    head = (head + 1) % max_size;
    return OK;
}

template<typename T>
Status sqqueue<T>::get_front(T &e) const
{
    if (isempty()) {
        std::cerr << "queue is empty\n";
        return ERROR;
    }
    e = base[head];
    return OK;
}


