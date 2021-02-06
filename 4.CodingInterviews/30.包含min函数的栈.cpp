#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
    {
    
    }
    
    void push(int x)
    {
        data_stk.push(x);
        if (min_stk.empty() || min_stk.top() >= x) {
            min_stk.push(x);
        }
    }
    
    void pop()
    {
        if (data_stk.empty()) return;
        int t = data_stk.top();
        data_stk.pop();
        if (t == min_stk.top()) min_stk.pop();
    }
    
    int top()
    {
        if (data_stk.empty()) return 0;   // empty condition 如何处理？
        return data_stk.top();
    }
    
    int min()
    {
        if (min_stk.empty()) return 0;
        return min_stk.top();
    }

private:
    stack<int> data_stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
