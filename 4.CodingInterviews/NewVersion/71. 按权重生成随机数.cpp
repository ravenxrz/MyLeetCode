#include "leetcode_base.h"

class Solution {
   public:
    Solution(vector<int>& w) : random_eg_(rd_()), real_dis(0, 1) {
        nums_ = w;
        ranges_.reserve(w.size());
        for (auto val : w) {
            ranges_.push_back(static_cast<double>(val));
        }

        double sum = accumulate(ranges_.begin(), ranges_.end(), 0.f);
        for_each(ranges_.begin(), ranges_.end(),
                 [=](double& x) { x = x / sum; });
        for (int i = 1; i < ranges_.size(); i++) {
            ranges_[i] += ranges_[i - 1];
        }
    }

    int pickIndex() {
        double num = real_dis(random_eg_);
		return std::lower_bound(ranges_.begin(), ranges_.end(), num) - ranges_.begin();
    }

   private:
    vector<int> nums_;
    vector<double> ranges_;
    /* random number generator */
    random_device rd_;
    default_random_engine random_eg_;
    uniform_real_distribution<double> real_dis;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {
    vector<int> nums = {1, 3};
    Solution sol(nums);
    for (int i = 0; i < 4; i++) {
        cout << sol.pickIndex() << endl;
    }
    return 0;
}