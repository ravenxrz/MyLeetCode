#include <vector>

using namespace std;


class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (arr.empty() || k > arr.size()) return {};
        adjust(arr, 0, arr.size() - 1, k - 1);
        arr.resize(k);
        return arr;
    }

private:
    void adjust(vector<int> &arr, int start, int end, int k)
    {
        int idx = my_partition(arr, start, end);
        if (idx == k) {
            return;
        } else if (idx > k) {
            return adjust(arr, start, idx - 1, k);
        } else {
            return adjust(arr, idx + 1, end, k);
        }
    }
    
    int my_partition(vector<int> &arr, int start, int end)
    {
        const int pivot = arr[start];
        int i = start, j = end;
        while (i < j) {
            while (i < j && arr[j] >= pivot) j--;
            arr[i] = arr[j];
            while (i < j && arr[i] <= pivot) i++;
            arr[j] = arr[i];
        }
        arr[i] = pivot;
        return i;
    }
};
