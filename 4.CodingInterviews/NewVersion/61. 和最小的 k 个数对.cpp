#include "leetcode_base.h"

class Solution {
    struct Item {
        int n1;
        int n2;
        bool operator<(const Item& rhs) const { return n1 + n2 < rhs.n1 + rhs.n2; }

        Item(int _n1, int _n2) : n1(_n1), n2(_n2) {}
    };

   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {
        priority_queue<Item> max_heap_;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                max_heap_.push(Item(nums1[i], nums2[j]));
				if(max_heap_.size() > k) max_heap_.pop();
            }
        }
		vector<vector<int>> ans;
		while(!max_heap_.empty()){
			ans.push_back({max_heap_.top().n1, max_heap_.top().n2});
			max_heap_.pop();
		}
		return ans;
    }
};

int main() {

    return 0;
}