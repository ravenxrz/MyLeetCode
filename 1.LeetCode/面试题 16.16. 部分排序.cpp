class Solution {
public:
    vector<int> subSort(vector<int> &array)
    {
        if (array.empty()) return {-1, -1};
        int left = 0;
        int right = array.size() - 1;
        
        // find the first value that is not satisfied increasing constant array from beginning
        while (left < array.size() - 1 && array[left] <= array[left + 1])
            ++left;
        if (left == array.size() - 1) return {-1, -1};
        
        // find the first value that is not satisfied decreasing constant array from end
        while (right >= 1 && array[right] >= array[right - 1])
            --right;
        
        // find maximum and minimum value in array[left -- right]
        int max_value = 0x80000000;
        int min_value = 0x7fffffff;
        for (int i = left; i <= right; ++i) {
            max_value = max(max_value, array[i]);
            min_value = min(min_value, array[i]);
        }
        // find the first value that is greater or equal than min_value
        int start = upper_bound(array.begin(), array.begin() + left, min_value) - array.begin();
        // find the first value that is less or equal than max_value
        int end = lower_bound(array.begin() + right + 1, array.end(), max_value) - array.begin() - 1;
        return {start, end};
    }
};

