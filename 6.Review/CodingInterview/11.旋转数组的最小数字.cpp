#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minArray(const vector<int>& numbers) {
        if (numbers.empty())
            return 0;
        int start = 0;
        int end = numbers.size() - 1;
        int mid = start;
        while (numbers[start] >= numbers[end]) {
            if (start + 1 == end)
                return numbers[end];
            mid = (start + end) >> 1;
            if (numbers[mid] > numbers[start]) {
                start = mid;
            } else if (numbers[mid] < numbers[end]) {
                end = mid;
            } else {
                // if numbers[mid] == numbers[start] == numbers[end]
                for (int i = mid; i <= end - 1; i++) {
                    if (numbers[i] > numbers[i + 1]) {
                        return numbers[i + 1];
                    }
                }
                break;
            }
        }
        return numbers[mid];
    }
};

int main() {
    Solution sol;
    {
        vector<int> arr = {3, 4, 5, 0, 1};
        cout << sol.minArray(arr) << endl;
    }

    {
        vector<int> arr = {1, 1, 0, 1};
        cout << sol.minArray(arr) << endl;
    }

    return 0;
}