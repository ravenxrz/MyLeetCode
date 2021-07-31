//
// Created by Raven on 2021/7/31.
//

#include "leetcode_base.h"

void simple_select_sort(vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] > nums[j]) {
        swap(nums[i], nums[j]);
      }
    }
  }
}

int main() {
  vector<int> nums = generateRandomNumbers<int>(100, 0, 100);
  printNums(nums);
  simple_select_sort(nums);
  printNums(nums);
  return 0;
}
