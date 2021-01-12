
/**
 * 题目：用两个栈实现一个队列。
 * 队列的声明如下，请实现它的两个函数 appendTail和 deletehead，分别完成在队列尾部插入节点和在队列头部删除节点的功能。
 */


#include <bits/stdc++.h>

using namespace std;

class CQueue {
public:
    CQueue()
    {
    
    }
    
    void appendTail(int value)
    {
        append_stk.push(value);
    }
    
    int deleteHead()
    {
        // 两个都空如何处理？
        if (delete_stk.empty() && append_stk.empty()) {
            return -1;
        }
        
        
        int value = 0;
        if (!delete_stk.empty()) {
            value = delete_stk.top();
            delete_stk.pop();
        } else {
            // pop append_stk into delete_stk
            while (!append_stk.empty()) {
                delete_stk.push(append_stk.top());
                append_stk.pop();
            }
            value = delete_stk.top();
            delete_stk.pop();
        }
        return value;
    }

private:
    stack<int> append_stk;
    stack<int> delete_stk;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
