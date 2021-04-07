//
// Created by Raven on 2021/2/26.
//
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    struct Item {
        int height;
        int idx;
        
        Item(int height, int idx) : height(height), idx(idx) {}
    };

public:
    int trap(vector<int> &height)
    {
        if (height.empty()) return 0;
        // stk pair->first indicating height , pair->second indicating arr idx
        stack<Item> stk;
        // push first idx
        int ans = 0;
        stk.emplace(height[0], 0);
        for (int i = 1; i < height.size(); i++) {
            if (stk.empty() || height[i] < stk.top().height) {
                stk.emplace(height[i], i);
            } else if (height[i] == stk.top().height) {
                // pass
            } else if (height[i] > stk.top().height) {
                // needs to calc
                Item pre = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() <= height[i]) {
                    Item cur = stk.top();
                    stk.pop();
                    ans += (cur.height - pre.height) * (i - pre.idx - 1);
                    pre = cur;
                }
                // push current item
                stk.emplace(height[i], i);
            }
        }
        return ans;
    }
};


int main()
{
    
    
    return 0;
}