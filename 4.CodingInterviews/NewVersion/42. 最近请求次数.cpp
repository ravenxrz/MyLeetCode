#include "leetcode_base.h"

class RecentCounter {
   public:
    RecentCounter() {}

    int ping(int t) {
        dq_.push_back(t);
        int prev = max(0, t - 3000);
        auto iter = lower_bound(dq_.begin(), dq_.end(), prev);
        int ret = dq_.end() - iter;
        dq_.erase(dq_.begin(), iter);
        return ret;
    }

   private:
    deque<int> dq_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main(int argc, const char** argv) {
    RecentCounter recentCounter;
    cout << recentCounter.ping(1);  // requests = [1]，范围是 [-2999,1]，返回 1
    cout << recentCounter.ping(
        100);  // requests = [1, 100]，范围是 [-2900,100]，返回 2
    cout << recentCounter.ping(
        3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
    cout << recentCounter.ping(
        3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3
    return 0;
}