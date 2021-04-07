#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k)
    {
        if (k == 0) return {};
        findKth(arr, 0, arr.size() - 1, k - 1);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

private:
    // k start from 0
    void findKth(vector<int> &arr, int start, int end, int k)
    {
        int idx = partition(arr, start, end);
        if (k == idx) return;
        else if (k < idx) {
            findKth(arr, start, idx, k);
        } else if (k > idx) {
            findKth(arr, idx + 1, end, k);
        }
    }
    
    
    int partition(vector<int> &arr, int start, int end)
    {
        int pivot = arr[start];
        int i = start;
        int j = end;
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

int main()
{
    Solution sol;
    {
        vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
        int k = 4;
        for (auto val : sol.smallestK(arr, k)) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}
