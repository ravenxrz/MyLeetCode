#include <algorithm>
#include <vector>
#include <functional>

using namespace std;


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() : total(0)
    {
    
    }
    
    void addNum(int num)
    {
        total++;
        if (total & 1) {      // odd
            tryAddToMaxHeap(num);
        } else {              // even
            tryAddToMinHeap(num);
        }
    }
    
    double findMedian()
    {
        double mid = 0.0f;
        if (total & 1) {      // odd
            int idx = total / 2 + 1;
            if (idx & 1) mid = max_heap.front();
            else mid = min_heap.front();
        } else {    // even
            mid = (min_heap.front() + max_heap.front()) / 2.0;
        }
        return mid;
    }

private:
    void tryAddToMinHeap(int num)
    {
        if (min_heap.empty()) {
            min_heap.push_back(num);
        } else {
            int replace_value = max_heap.front();
            if (num < replace_value) {
                max_heap.push_back(replace_value);
                push_heap(max_heap.begin(), max_heap.end(), std::less<int>());
                // update num
                num = max_heap.front();
                pop_heap(max_heap.begin(), max_heap.end(), std::less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            push_heap(min_heap.begin(), min_heap.end(), std::less<int>());
        }
    }
    
    void tryAddToMaxHeap(int num)
    {
        if (max_heap.empty()) {
            max_heap.push_back(num);
        } else {
            int replace_value = min_heap.front();
            if (num > replace_value) {       // 如果要插入到max heap的值比min heap最小值大
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
                
                // 取出最小值
                num = min_heap.front();
                pop_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
                min_heap.pop_back();
            }
            max_heap.push_back(num);
            push_heap(max_heap.begin(), max_heap.end(), std::less<int>());
        }
    }

private:
    vector<int> min_heap;
    vector<int> max_heap;
    int total;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */