/*
 * 希尔排序
 */
#include "common.h"

using namespace std;

class ShellSorter : public Sorter {
private:
    void _sort(vector<int> &nums) override {
        vector<int> delta;
        for (int dlt = 1; dlt < nums.size(); dlt *= 2) {
            delta.push_back(dlt);
        }
        reverse(delta.begin(),delta.end());
        shell_sort(nums,delta);
    }
    /**
     * 希尔排序
     * @param nums 需要排序的元素
     * @param delta 增量数组，且最小元素一定是1，且为降序
     * 10k数据量 0.006 s
     * 100k数据量 0.153 s
     */
    void shell_sort(vector<int> &nums, const vector<int> &delta) {
        int cur, cmp, tmp;
        for (auto &dlt : delta) {
            for (cur = 1 + dlt; cur < nums.size(); cur++) {
                tmp = nums[cur];
                for (cmp = cur - dlt; cmp >= 0; cmp -= dlt) {
                    if (nums[cmp] > tmp) {
                        // move
                        nums[cmp + dlt] = nums[cmp];
                    } else {
                        // set
                        nums[cmp + dlt] = tmp;
                        break;
                    }
                }
                if (cmp < 0) {
                    nums[cmp + dlt] = tmp;
                }
            }
        }
    }
};

int main() {
    vector<int> nums = generateRandomNumbers(1000*100, 1, 1000 * 1000);
    Sorter *sorter = new ShellSorter();
    sorter->sort(nums);
    delete sorter;
    return 0;
}