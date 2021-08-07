#include "leetcode_base.h"

class MaxQueue {
   public:
    MaxQueue() {}

    int max_value() {
        if (max_vec.empty()) {
            return -1;
        } else {
            return max_vec.front();
        }
    }

    void push_back(int value) {
        qe.push(value);
        while (!max_vec.empty() && max_vec.back() < value) {
            max_vec.pop_back();
        }
        max_vec.push_back(value);
    }

    int pop_front() {
        if (qe.empty()) {
            return -1;
        } else {
            int value = qe.front();
            qe.pop();
            assert(!max_vec.empty());
            if (max_vec.front() == value) {
                max_vec.pop_front();
            }
            return value;
        }
    }

   private:
    queue<int> qe;
    deque<int> max_vec;
};

/**
 * Your MaxQueue object will be instantiated and called as such
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {
	MaxQueue mq;
	mq.push_back(1);
	mq.push_back(3);
	mq.push_back(2);
	cout << mq.max_value() << endl;
	mq.push_back(4);
	cout << mq.max_value() << endl;

	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	cout << mq.max_value() << endl;

    return 0;
}