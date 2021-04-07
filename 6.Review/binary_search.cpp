//
// Created by Raven on 2021/3/13.
//
#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> &arr, int target)
{
    int left = 0;
    int right = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) {
            right = mid - 1;
        } else if (arr[mid] > target) {
            left = mid + 1;
        }
    }
    return -1;
}

int left_bound(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    if (left == nums.size() || nums[left] != target) return -1;
    return left;
}

int right_bound(vector<int> &nums, int target)
{
    int left = 0;
    int right= nums.size()-1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    if(left == nums.size() || nums[right] != target) return -1;
    return right;
}


int main()
{
    vector<int> nums{1, 2, 2, 3, 4, 5, 6};
    cout << binary_search(nums, 2) << endl;
    cout << left_bound(nums, 2) << endl;
    cout << right_bound(nums, 2) << endl;
    return 0;
}
