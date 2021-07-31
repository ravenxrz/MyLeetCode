//
// Created by Raven on 2021/7/31.
//
class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if(k == 0) return {};
    transfer(arr, 0, arr.size() - 1, k - 1);
    return vector<int>(arr.begin(), arr.begin() + k);
  }

private:
  // k starts from "0"
  void transfer(vector<int> &arr, int start, int end, int k) {
    assert(start <= end);
    int idx = partition(arr, start, end);
    if (idx == k) {
      return;
    } else if (idx < k) {
      return transfer(arr, idx + 1, end, k);
    } else if (idx > k) {
      return transfer(arr, start, idx - 1, k);
    }
  }
  
  int partition(vector<int> &vec, int start, int end) {
    assert(start <= end);
    int i = start;
    int j = end;
    int pivot = vec[start];
    while (i < j) {
      while (i < j && vec[j] >= pivot)
        j--;
      vec[i] = vec[j];
      while (i < j && vec[i] <= pivot)
        i++;
      vec[j] = vec[i];
    }
    vec[i] = pivot;
    return i;
  }
};
