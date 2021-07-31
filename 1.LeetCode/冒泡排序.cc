#include "leetcode_base.h"

void bubble_sort(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums.size() - i; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
      }
    }
  }
}

int main() {
  vector<int> nums = generateRandomNumbers<int>(100, 0, 100);
  printNums(nums);
  bubble_sort(nums);
  printNums(nums);
  return 0;
}
