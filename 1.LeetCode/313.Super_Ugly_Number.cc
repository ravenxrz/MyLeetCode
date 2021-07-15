//
// Created by raven on 2021/7/15.
//
#include "leetcode_base.h"

class Solution {
public:
    int nthSuperUglyNumber(int n, const vector<int> &primes)
    {
        if (n == 1) // 1 is a special prime number that does not use prime number in primes
            return 1;
        
        // Init variables
        vector<int> uglies(1, 1);
        vector<int> index(primes.size(), 0);
        int cur_idx = 1;
        
        while (cur_idx < n) {
            int min_value = INT32_MAX;
            // First loop confirms the min value
            for (int i = 0; i < index.size(); i++) {
                assert(index[i] < uglies.size());
                min_value = min(min_value, primes[i] * uglies[index[i]]);
            }
            uglies.push_back(min_value);
            // Second loop makes concrete index forward one step
            for (int i = 0; i < index.size(); i++) {
                assert(index[i] < uglies.size());
                if (min_value == primes[i] * uglies[index[i]]) {
                    index[i]++;
                }
            }
            cur_idx++;
        }
        
        return uglies.back();
    }
};

int main()
{
    Solution sol;
    cout << sol.nthSuperUglyNumber(12, {2, 7, 13, 19}) << endl;
    cout << sol.nthSuperUglyNumber(1, {2, 3, 5}) << endl;
    cout << sol.nthSuperUglyNumber(1e6, {2}) << endl;
}
