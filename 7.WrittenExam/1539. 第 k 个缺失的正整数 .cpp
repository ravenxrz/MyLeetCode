#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int cur = 1;
        int missing_num = 0;
        for (int val : arr) {
            if (val == cur) {
                cur++;
            } else {
                while (cur != val) {
                    ++missing_num;
                    if (missing_num == k) {
                        return cur;
                    }
                    cur++;
                }
                cur++;
            }
        }
        
        return cur + (k - missing_num - 1);
    }
};

int main()
{
    Solution sol;
    {
        vector<int> test{2, 3, 4, 7, 11};
        cout << sol.findKthPositive(test, 5) << endl;
    }
    
    
    {
        vector<int> test{1, 2, 3, 4};
        cout << sol.findKthPositive(test, 2) << endl;
    }
    
    return 0;
}
