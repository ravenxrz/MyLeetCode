#include "leetcode_base.h"


class Solution {
public:
    int minArray(const vector<int> &numbers)
    {
        assert(!numbers.empty());
        if (numbers.size() == 1) return numbers.back();
        
        // numbers.size() >= 2
        if (numbers.front() < numbers.back()) {
            return numbers.front();
        }
        
        // binary search
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (numbers[left] > numbers[right] && numbers[left] < numbers[mid]) {
                left = mid + 1;
            } else if (numbers[left] > numbers[right] && numbers[mid] < numbers[mid]) {
                if (mid - 1 >= 0 && numbers[mid - 1] > numbers[mid]) {
                    return numbers[mid];
                }
                right = mid - 1;
            } else {
                if (numbers[left] < numbers[right]) {
                    return numbers[left];
                }
                // scan sequentially
                return *min_element(numbers.begin(), numbers.end());
            }
        }
        return numbers[left];
    }
};


int main()
{
    Solution sol;
    cout << sol.minArray({3, 4, 5, 1, 2}) << endl;
    cout << sol.minArray({1, 2, 3, 4, 5}) << endl;
    cout << sol.minArray({2, 0, 1, 2, 2}) << endl;
    cout << sol.minArray({2, 2, 2, 0, 1}) << endl;
    cout << sol.minArray({4, 5, 6, 0, 1, 2}) << endl;
    return 0;
}
