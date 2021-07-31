//
// Created by Raven on 2021/7/31.
//
#include "leetcode_base.h"

void do_fast_sort(vector<int> &nums, int start, int end) {
  if (start >= end)
    return;
  int i = start;
  int j = end;
  int pivot = nums[start];
  while (i < j) {
    while (i < j && nums[j] >= pivot)
      j--;
    nums[i] = nums[j];
    while (i < j && nums[i] <= pivot)
      i++;
    nums[j] = nums[i];
  }
  nums[i] = pivot;
  do_fast_sort(nums, start, i - 1);
  do_fast_sort(nums, i + 1, end);
}

void fast_sort(vector<int> &nums) { do_fast_sort(nums, 0, nums.size() - 1); }

int main()
{
  vector<int> nums = generateRandomNumbers<int>(100, 0, 1000);
  printNums(nums);
  fast_sort(nums);
  printNums(nums);
  return 0;
}
