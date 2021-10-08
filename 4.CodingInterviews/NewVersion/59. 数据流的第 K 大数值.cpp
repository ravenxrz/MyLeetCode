#include "leetcode_base.h"

class KthLargest {
   public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        int i = -1;
        for (i = 0; i < k && i < nums.size(); i++) {
            min_heap_.push(nums[i]);
        }
        while (i < nums.size()) {
            if (nums[i] > min_heap_.top()) {
                min_heap_.pop();
                min_heap_.push(nums[i]);
            }
			i++;
        }
    }

    int add(int val) {
        min_heap_.push(val);
        while (min_heap_.size() > k_) {
            min_heap_.pop();
        }
        return min_heap_.top();
    }

   private:
    const int k_;
    priority_queue<int, vector<int>, std::greater<int>> min_heap_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
