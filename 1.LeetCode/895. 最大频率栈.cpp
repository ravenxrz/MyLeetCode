#include <bits/stdc++.h>

using namespace std;

class FreqStack {
public:
    FreqStack()
    {
    
    }
    
    void push(int val)
    {
        vec.push_back(val);
        // first time be inserted into this stk
        if (value2freq.count(val) == 0) {
            value2freq[val] = 1;
            if (freq2values.count(1) == 0) {
                freq2values[1] = {val};
            } else {
                freq2values[1].insert(val);
            }
        } else {
            int old_freq = value2freq[val];
            freq2values[old_freq].erase(val);
            // update new data
            value2freq[val]++;
            freq2values[old_freq + 1].insert(val);
        }
        
    }
    
    int pop()
    {
        if (freq2values.empty()) return -1;
        int max_fre = freq2values.begin()->first;
        auto &max_values = freq2values.begin()->second;
        int ret = -1;
        // find the one which is the closest to stk top
        for (int i = vec.size() - 1; i >= 0; --i) {
            if (max_values.count(vec[i]) != 0) {
                ret = vec[i];
                vec.erase(vec.begin() + i);
                // update value2freq
                value2freq[ret]--;
                if (value2freq[ret] == 0) value2freq.erase(ret);
                // update freq2values
                // move from max_fre --> (max_fre-1)
                freq2values[max_fre].erase(ret);
                if(freq2values[max_fre].empty()) freq2values.erase(max_fre);
                if (max_fre != 0) freq2values[max_fre - 1].insert(ret);
                break;
            }
        }
        return ret;
    }

private:
    unordered_map<int, int> value2freq;
    // 可以优化，将unordered_set改用stack
    map<int, unordered_set<int>, std::greater<int>> freq2values;
    vector<int> vec;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main()
{
    FreqStack stk;
    stk.push(5);
    stk.push(7);
    stk.push(5);
    stk.push(7);
    stk.push(4);
    stk.push(5);
    
    cout << stk.pop() << '\n';
    cout << stk.pop() << '\n';
    cout << stk.pop() << '\n';
    cout << stk.pop() << '\n';
    
    return 0;
}
