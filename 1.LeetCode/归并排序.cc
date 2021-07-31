#include "leetcode_base.h"

void merge(vector<int> &nums, int start, int mid, int end) {
  int s1 = start;
  int e1 = mid;
  int s2 = mid + 1;
  int e2 = end;
  int *aux = new int[e2 - s1 + 1]; // maybe not use a dynamic allocation
  int i = s1;
  int j = s2;
  int idx = 0;
  while (i <= e1 && j <= e2) {
    if (nums[i] <= nums[j]) {
      aux[idx++] = nums[i++];
    } else {
      aux[idx++] = nums[j++];
    }
  }
  while (i <= e1) {
    aux[idx++] = nums[i++];
  }
  while (j <= e2) {
    aux[idx++] = nums[j++];
  }
  // Copy aux back to nums
  for (idx = 0; idx < e2 - s1 + 1; idx++) {
    nums[idx + s1] = aux[idx];
  }
  delete[] aux;
}

void do_merge_sort(vector<int> &nums, int start, int end) {
  if (start >= end)
    return;
  int mid = (start + end) >> 1;
  do_merge_sort(nums, start, mid);
  do_merge_sort(nums, mid + 1, end);
  merge(nums, start, mid, end);
}

void merge_sort(vector<int> &nums) { do_merge_sort(nums, 0, nums.size() - 1); }

int main() {
  vector<int> nums = generateRandomNumbers<int>(100, 0, 100);
  printNums(nums);
  merge_sort(nums);
  printNums(nums);
  return 0;
}
