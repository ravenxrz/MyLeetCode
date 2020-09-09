/**
 * Created by raven on 2020/9/9.
 */
 #include "../../common.h"
 
template<typename T>
class sqstack{
public:
    explicit sqstack(size_t init_size = 2, size_t increment = 100);
    
    sqstack(const sqstack<T> &stack);
    
    ~sqstack();
    
    Status isempty() const;
    
    size_t length() const;
    
    Status gettop(T &e) const;
    
    Status push(T e);
    
    Status pop(T &e);
    
private:
    T *base;
    T *top;
    size_t stacksize;
    size_t incremental_size;
};

template<typename T>
sqstack<T>::sqstack(size_t init_size,size_t increment)
{
    base = (T *)malloc(sizeof(T)*init_size);
    if(!base){
        std::cerr << "malloc error\n";
        exit(ERROR);
    }
    top = base;
    stacksize = init_size;
    incremental_size = increment;
}

template<typename T>
sqstack<T>::sqstack(const sqstack<T> &stack)
{
    stacksize= stack.stacksize;
    incremental_size = stack.incremental_size;
    base = (T *)malloc(sizeof(stacksize));
    top = base + stacksize;
    memcpy(base,stack.base,stack.stacksize);
}


template<typename T>
sqstack<T>::~sqstack()
{
    free(base);
}

template<typename T>
Status sqstack<T>::gettop(T &e) const
{
    e = *(top-1);
    return OK;
}

template<typename T>
Status sqstack<T>::push(T e)
{
    if(length() == stacksize){
        /* realloc */
        T *tmp = base;
        base = (T *)malloc(sizeof(T) * (stacksize + incremental_size));
        top = base+stacksize;
        memcpy(base,tmp,stacksize*sizeof(T));
        
        stacksize+=incremental_size;
    }
    *top = e;
    top++;
    return OK;
}

template<typename T>
Status sqstack<T>::pop(T &e)
{
    if(isempty()) {
        std::cerr << "stack is empty now\n";
        exit(ERROR);
    }
    gettop(e);
    top--;
    return OK;
}

template<typename T>
Status sqstack<T>::isempty() const
{
    return  length() == 0 ? TRUE : FALSE;
}

template<typename T>
size_t sqstack<T>::length() const
{
    return top - base;
}

