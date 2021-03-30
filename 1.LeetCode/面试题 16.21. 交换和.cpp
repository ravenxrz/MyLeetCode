//
// Created by Raven on 2021/3/30.
//


class Solution {
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2)
    {
        // pre sort
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        
        // get sum of array1 and array2
        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        int delta = sum1 - sum2;
        
        for (auto x : array1) {
            // use binary search to get ans
            int i = 0;
            int j = array2.size() - 1;
            while (i <= j) {
                int mid = i + (j - i) / 2;
                int y = array2[mid];
                int tmp = 2 * x - 2 * y;
                if (tmp == delta) {
                    return {x, y};
                } else if (tmp < delta) {
                    j = mid - 1;
                } else if (tmp > delta) {
                    i = mid + 1;
                }
            }
        }
        return {};
    }
};

