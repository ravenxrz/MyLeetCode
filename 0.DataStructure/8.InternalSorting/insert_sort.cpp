//
// Created by a2855 on 2020/11/17.
//

#include "common.h"
#include <chrono>

using namespace std;

/**
 * 插入排序器
 */
class InsertSorter {
public:
    static vector<int> &sort(vector<int> &nums) {
        auto before = clock();
//        normal_sort(nums);
        binary_insert_sort(nums);
        auto now = clock();
        cout << "time elapsed: " << (double)(now-before)/CLOCKS_PER_SEC << endl;
        return nums;
    }

private:
    /* 普通插入排序 */
    /* 测试结果：normal的insert sort 10*000数据量，0.205s  100*1000数据量。 20.52s */
    static vector<int> &normal_sort(vector<int> &nums) {
        int i, j;
        for (i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            for (j = i - 1; j >= 0; j--) {
                if (cur < nums[j]) {   // 升序排列
                    nums[j + 1] = nums[j];
                } else {
                    // 插入点
                    nums[j + 1] = cur;
                    break;
                }
            }
            if (j == -1)
                nums[0] = cur;
        }

        return nums;
    }

    /* 折半插入排序 */
    /* 测试结果：10*1000数据量0.152s 100*1000数据量 14.943s */
    static vector<int> &binary_insert_sort(vector<int> &nums) {
        int i, j;
        for(i = 1;i<nums.size();i++){
            int cur = nums[i];
            // binary search
            int left = 0, right = i-1;
            int mid = (left + right)/2;
            while(left < right){
                if(nums[mid] < cur){
                    left = mid+1;
                }else if(nums[mid] > cur){
                    right = mid -1;
                }else {
                    break;
                }
                mid = (left+right)/2;
            }
            if(nums[mid] < cur){
                mid++;
            }
            // move
            for(j = i;j>mid;j--){
                nums[j] = nums[j-1];
            }
            nums[mid] = cur;
        }
        return nums;
    }
};


int main() {
    vector<int> rnums = generateRandomNumbers(1000*100,1,1000*1000);
//    print_nums(rnums);

    InsertSorter::sort(rnums);
//    print_nums(rnums);
    return 0;
}