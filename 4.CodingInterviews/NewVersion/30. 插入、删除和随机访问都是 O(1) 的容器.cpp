#include "leetcode_base.h"

class RandomizedSet {
   public:
    /** Initialize your data structure here. */
    RandomizedSet() : e(r()) {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (!umap.count(val)) {
            nums.push_back(val);
            umap[val] = nums.size() - 1;
            return true;
        } else {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (umap.count(val)) {
            int idx = umap[val];
            swap(nums[idx], nums.back());
			umap[nums[idx]] = idx;
            nums.pop_back();
            umap.erase(val);
            return true;
        } else {
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> uni(0, nums.size() - 1);
        return nums[uni(e)];
    }

   private:
    vector<int> nums;
    unordered_map<int, int> umap;
    random_device r;
    default_random_engine e;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet randomSet;  // 初始化一个空的集合
    randomSet.insert(1);  // 向集合中插入 1 ， 返回 true 表示 1 被成功地插入

    randomSet.remove(2);  // 返回 false，表示集合中不存在 2

    randomSet.insert(2);  // 向集合中插入 2 返回 true ，集合现在包含 [1,2]

    cout << randomSet.getRandom() << endl;  // getRandom 应随机返回 1 或 2

    randomSet.remove(1);  // 从集合中移除 1 返回 true 。集合现在包含 [2]

    randomSet.insert(2);  // 2 已在集合中，所以返回 false

    cout << randomSet.getRandom() << endl;;  // 由于 2 是集合中唯一的数字，getRandom 总是返回 2
}

