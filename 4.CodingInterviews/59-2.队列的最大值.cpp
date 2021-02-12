#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MaxQueue {
public:
    MaxQueue()
    {
    
    }
    
    int max_value()
    {
        if (max_val_vec.empty()) return -1;
        return max_val_vec.front();
    }
    
    void push_back(int value)
    {
        val_qu.push(value);
        if (max_val_vec.empty()) {
            max_val_vec.push_back(value);
        } else {
            int i = 0;
            while (i < max_val_vec.size() && max_val_vec[i] > value) {
                i++;
            }
            if (i == max_val_vec.size()) {
                max_val_vec.push_back(value);
            } else {
                max_val_vec[i] = value;
                max_val_vec.resize(i + 1);
            }
        }
    }
    
    int pop_front()
    {
        if (val_qu.empty()) return -1;
        int val = val_qu.front();
        val_qu.pop();
        if (val == max_val_vec.front()) {
            max_val_vec.erase(max_val_vec.begin());
        }
        return val;
    }

private:
    queue<int> val_qu;
    vector<int> max_val_vec;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
